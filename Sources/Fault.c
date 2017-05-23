//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : Fault.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : 该文件 对系统的各级故障判断
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
//#include "Fault.h" 
///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
float errvalue[]=
{
    4.25,//1 cell voltage too high
    2.5,//1 cell voltage too low
    400.0,//1 Current too big
    75,//1 temperature too high
    12,//1 BMS CHG communication error
    
    4,//1 BMS internal communication fault
    4,//1 HV link fault
    4,//1 Heat component fault
    4,//1 HV Relay fault
    4,//1 BMS hardware fault
    
    408,//2 Total Voltage more higher
    253,//2 Total Voltage more lower
    4.2,//2 cell voltage more higher
    2.75,//2 cell voltage more lower
    320,//2 Current large charge or Feedback
    
    320,//2 Current large Discharge
    60, //2 Temperature more higher
    -25,//2 Temperature more lower
    20,//2 Temperature diff too large
    0.5,//2 Voltage diff too large
    
    40,//2 Rpn too low
    10,//2 BMS CHG communication fault
    2,//2 BMS internal Communicationfault
    2,//2 HV link fault
    2,//2 Heat component fault
    
    2,//2 HV Relay fault
    2,//2 BMS hardware fault
    377,//3 Total Voltage high
    285,//3 Total Voltage low
    4.1,//3 cell voltage high
    
    3.2,//3 cell voltage low
    180,//3 Current large charge or Feedback
    180,//3 Current large Discharge
    45, //3 Temperature more higher
    0,//3 Temperature more lower
    
    15,//3 Temperature diff too large
    0.1,//3 Voltage diff too large
    200,//3 Rpn low
    0.10//3 SOC low
};

//***********************************************************************************
//***********************************************************************************

unsigned int  g_errorCounter;
unsigned char  g_caution_Flag_1 =0;//BMS故障状态 FOR 上位机
unsigned char  g_caution_Flag_2 =0;
unsigned char  g_caution_Flag_3 =0;
unsigned char  g_caution_Flag_4 =0;

unsigned char CutDischaTo0;    //放电电流到0
unsigned char CutDischaTo50;   //放电电流到50%
unsigned char CutFebchaTo0;    //回馈电流到0
unsigned char CutFebchaTo50;   //回馈电流到50%
//放电电流
CUTDISCURT0  CutDisCurt0;      //放电电流降为0
CUTDISCURT50 CutDisCurt50;      //放电电流降为50%

//回馈电流
CUTCHACURT0 CutChaCurt0;      //回馈电流降为0
CUTCHACURT50 CutChaCurt50;     //回馈电流降为50%
//快充电流
CUTDCCHACURT0 CutDCChaCurt0;    //快充电流降为0
CUTDCCHACURT50 CutDCChaCurt50;   //快充电流降为50%
CUTDCCHACURT02 CutDCChaCurt02;   //快充电流降为0
unsigned char ChaCurDirAnly=0;//充电电流方向异常标志位
unsigned char g_FlagLevel=0;  //故障等级标志位
unsigned int WithEVCUComOverTime=0;   //与整车通信故障超时计时
unsigned int WithEVCUComOverTimeFlag=0;   //与整车通信故障超时标志位
unsigned char CarFaultFlag=1;  //行车故障标志位,1为故障1类型（多数），2为故障2类型(EVCU)
unsigned char g_DCChaPowerOffFlag=0;    //需要下电的快充模式非4级故障标志位
unsigned char g_PowerOffFlag=0; //下电标志位

//******************************************************************************
//* Function name:    TotalVoltageOverVoltage
//* Description:      总电压过压故障 （1级最轻微，4级为最严重故障）
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void TotalVoltageOverVoltage(void) 
{
    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0; 
    unsigned char LevelError=0;
    float VolValue;
    if(g_BmsModeFlag == DISCHARGING) 
    {
        VolValue=g_BatSysTotalVolV2; 
    }
    if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
    {
        VolValue=g_BatSysTotalVolV3; 
    }
    //Level=Battery_MaxFaultLevel_step(g_BatHighestTemp,g_BatLowestTemp,g_CellHighestVol,(float)g_BatHighestTemp,(float)g_BatLowestTemp,g_CellLowestVol,curtValue,g_BatSysTotalCur,g_MaxDischaCur,g_SystemVoltageV0,g_BatSysTotalVolV3,g_BatSysTotalVolV2); //故障等级
    Level=TotalVoltageOverVoltage_step(g_SystemVoltageV0,VolValue);
    ///////////////////上报故障等级数/////////////////////////   
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm = Level; //i级故障报警  
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
    if(Level!=0) 
    {
      BMS1_Byte6.Bit.F0_TotalVolOverVol = 1; //i级故障报警 
    } 
    else
      BMS1_Byte6.Bit.F0_TotalVolOverVol = 0; //i级故障报警 

    //1级处理
    Can554Byte2.Bit.F2_TotalVolOverVol1=Error[1];   //内部CAN  

    //2级处理  
    Can554Byte0.Bit.F2_TotalVolOverVol2=Error[2] ; //内部CAN
    CutChaCurt50.Bit.F0_TotalVolOverVol2=Error[2] ;   //回充电流降为50%       
    CutDCChaCurt0.Bit.F15_TotalVolOverVol2=Error[2] ;  //快充电流降为0
    if(2==Level) 
    {  //上报故障           
        if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
        {            
            g_DCChaPowerOffFlag=1;      //需要下电的快充模式非4级故障标志位
        }
    }
    //3级处理
    fault_pc552_Byte4.Bit.F2_TotalVolOverVol3 =Error[3];  //内部CAN
    CutChaCurt0.Bit.F0_TotalVolOverVol3=Error[3] ;   //回充电流降为0
    CutDCChaCurt0.Bit.F0_TotalVolOverVol3=Error[3] ;  //快充电流降为0
    if(3==Level) 
    {   //上报故障
        if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
        {
            g_DCChaPowerOffFlag=1;      //需要下电的快充模式非4级故障标志位
        }
    }
    //4级处理
    fault_pc552_Byte4.Bit.F2_TotalVolOverVol3 =Error[4]; //内部CAN,4级也报3级故障
    CutChaCurt0.Bit.F1_TotalVolOverVol4=Error[4] ;   //回充电流降为0
    CutDCChaCurt0.Bit.F1_TotalVolOverVol4=Error[4] ;  //快充电流降为0
    if(4==Level) 
    {   //上报故障        
        if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
        {
            BMS9_Byte7.Bit.F4_BzerAlarm= Error[4] ;       //蜂鸣器报警
            BMS9_Byte7.Bit.F3_BatChaOverVol= Error[4] ;   //动力电池充电过压
            g_DCChaPowerOffFlag=1;      //需要下电的快充模式非4级故障标志位
        }
    } 
               
}
//******************************************************************************
//* Function name:    TotalVoltageUnderVoltage
//* Description:      电池包总电压欠压故障 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void TotalVoltageUnderVoltage(void) //恢复,上报
{   
    unsigned char i;
    unsigned char Error[5]={0};
    unsigned char Level=0; 
    unsigned char LevelError=0;
    ///////////////////上报故障等级数/////////////////////////
    Level=TotalVoltageUnderVoltage_step(g_SystemVoltageV0,g_BatSysTotalVolV2);
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;   
    BMS7_Byte0.Bit.F2_4_TotalVolUnderVolAlarm = Level; //i级故障报警 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位 
    if(Level!=0) 
    {
      BMS1_Byte6.Bit.F1_TotalVolUnderVol = 1; //i级故障报警 
    } 
    else
      BMS1_Byte6.Bit.F1_TotalVolUnderVol = 0; //i级故障报警 

    //1级故障处理
    Can554Byte2.Bit.F0_TotalVolUnderVol1=Error[1];  //内部CAN
    
    //2级处理
    Can554Byte0.Bit.F0_TotalVolUnderVol2=Error[2] ;  //内部CAN
    CutDisCurt50.Bit.F0_TotalVolUnderVol2=Error[2] ;   //放电电流降为50%
    
    //3级处理
    fault_pc552_Byte4.Bit.F0_TotalVolUnderVol3 =Error[3];  //内部CAN
    CutDisCurt0.Bit.F10_TotalVolUnderVol3=Error[3] ;   //放电电流降为0
    
    //4级处理
    fault_pc552_Byte4.Bit.F0_TotalVolUnderVol3 =Error[4];  //内部CAN,4级也报3级故障
    CutDisCurt0.Bit.F0_TotalVolUnderVol4=Error[4] ;   //放电电流降为0
      
}
//******************************************************************************
//* Function name:    WithDCChargerCommunicationFault
//* Description:      与直流充电机通信故障（包括超时故障）
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************

void WithDCChargerCommunicationFault(void)
{
    if(OverTimeState==1)   //快充超时
    {
        fault_pc552_Byte5.Bit.F4_WithChgerComFault=1;     //内部CAN
        CutDCChaCurt0.Bit.F3_WithChgerComFault = 1;  //充电机故障动作处理
        BMS7_Byte0.Bit.F1_WithChgerComAlarm=1;   //1级报警 
        BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //蜂鸣器报警
        g_FlagLevel=(g_FlagLevel>1?g_FlagLevel:1);   //故障等级标志位 
        g_DCChaPowerOffFlag=1;      //需要下电的快充模式非4级故障标志位

    }
    
}
//******************************************************************************
//* Function name:    InternalCommunicationFault
//* Description:      内部通讯故障  4级
//* EntryParameter : None
//* ReturnValue    : Bool类型 0-无；1-有
//******************************************************************************
void InternalCommunicationFault(void) 
{ 
    if(fault_pc552_Byte6.Bit.F0_InterComFault==1) //内部通讯故障
    {
        if(g_BmsModeFlag == DISCHARGING)        //如果是行车模式   
        {
            CutDisCurt0.Bit.F1_InterComFault=1;         //故障动作处理，放电降为0
            CutChaCurt0.Bit.F2_InterComFault=1;        //回充降为0
        }
        if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
        {
            CutDCChaCurt0.Bit.F2_InterComFault=1;      //快充降为0
            BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //蜂鸣器报警
        }
        g_FlagLevel=4;                         //故障等级标志位
        BMS7_Byte0.Bit.F0_WithLECUComAlarm=1;    //4级报警 
        
     } 

}
//******************************************************************************
//* Function name:    WithEVCUCommunicationFault
//* Description:      EVCU通讯故障  4级
//* EntryParameter : None
//* ReturnValue    : Bool类型 0-无；1-有
//******************************************************************************
void WithEVCUCommunicationFault(void) 
{
    WithEVCUComOverTime++;  
    if((WithEVCUComOverTime>=115)&&(g_BmsModeFlag == DISCHARGING)) 
    {
        WithEVCUComOverTimeFlag=1;
        CarFaultFlag=2;
        g_PowerOffFlag=1;
    }
    else if((WithEVCUComOverTime>=10)&&(g_BmsModeFlag == FASTRECHARGING)) 
    {
        WithEVCUComOverTimeFlag=2;        
    }
    if((WithEVCUComOverTimeFlag==2)&&(g_BmsModeFlag == FASTRECHARGING))   //EVCU快充模式超时
    {
        CutDCChaCurt02.Bit.F2_WithEVCUComFault=1;   //充电降为0
        g_FlagLevel=4;                         //故障等级标志位
        BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //蜂鸣器报警         
        WithEVCUComOverTime=11;         
    } 
    else if((WithEVCUComOverTimeFlag==1)&&(g_BmsModeFlag == DISCHARGING))   //EVCU行车模式超时
    {
        CutDisCurt0.Bit.F15_WithEVCUComFault=1;   //放电电流降为0  
        CutChaCurt0.Bit.F8_WithEVCUComFault=1;    //回充电流降为0
        g_FlagLevel=4;                       //故障等级标志位        
        WithEVCUComOverTime=121;   
    }
}
//******************************************************************************
//* Function name:    DischargeOverCurrent
//* Description:      放电过流故障  4级最严重
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void DischargeOverCurrent(void) //放电过流
{
    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0; 
    unsigned char LevelError=0;
    float curtValue=0.0;

   
    curtValue = g_MaxDischaCur;
    
    ////////////////////////上报故障等级////////////////////////
    Level=DischargeOverCurrent_step(g_BatSysTotalCur,curtValue);  
    for(i=1;i<5;i++) 
            if(i==Level) 
                Error[i]=1;
    BMS7_Byte1.Bit.F5_7_DisChaOverCurAlarm = Level; //i级故障报警         
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位        
    if(Level!=0) 
    {
      BMS1_Byte5.Bit.F5_DischaOverCur = 1; //i级故障报警 
    } 
    else
      BMS1_Byte5.Bit.F5_DischaOverCur = 0; //i级故障报警 

     //1级处理
    Can554Byte3.Bit.F0_DischaOverCur1=Error[1];  //内部CAN
    //2级处理  
    Can554Byte1.Bit.F0_DischaOverCur2=Error[2] ;  //内部CAN
    CutDisCurt50.Bit.F1_DischaOverCur2=Error[2] ;   //放电电流降为50%        
            
     //3级处理
    fault_pc552_Byte5.Bit.F0_DischaOverCur3 =Error[3];   //内部CAN
    CutDisCurt0.Bit.F11_DisChaOverCur3=Error[3] ;   //放电电流降为0        
    
    //4级处理
    fault_pc552_Byte5.Bit.F0_DischaOverCur3 =Error[4];   //内部CAN,4级也报3级故障
    CutDisCurt0.Bit.F2_DisChaOverCur4=Error[4] ;   //放电电流降为0   
        
}
//******************************************************************************
//* Function name:    ChargeOverCurrent
//* Description:      充电过流故障 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void ChargeOverCurrent(void)
{

    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0; 
    unsigned char LevelError=0;
    float curtValue=0;
    
    if(g_BmsModeFlag == DISCHARGING)//放电模式
    {
        curtValue=g_MaxFebCur; //回馈电流为负值
    }
    else if((g_BmsModeFlag == FASTRECHARGING)) //快充模式
    {
        curtValue=g_AskDCCur;
    } 
    ///////////////////上报故障等级数/////////////////////////    
    Level=ChargeOverCurrent_step(-(g_BatSysTotalCur),curtValue);    
    for(i=1;i<5;i++) 
            if(i==Level) 
                Error[i]=1;
    BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm = Level; //i级故障报警         
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F4_ChaOverCur = 1; //i级故障报警 
    } 
    else
        BMS1_Byte5.Bit.F4_ChaOverCur = 0; //i级故障报警 
    //1级处理
    Can554Byte2.Bit.F7_ChaOverCur1=Error[1];     //内部CAN

    //2级处理  
    Can554Byte0.Bit.F7_ChaOverCur2=Error[2] ;      //内部CAN
    CutChaCurt50.Bit.F1_ChaOverCur2=Error[2] ;   //回馈电流降为50%
    CutDCChaCurt50.Bit.F1_ChaOverCur2=Error[2] ;  //快充电流降为50%
            
     //3级处理
    fault_pc552_Byte4.Bit.F7_ChaOverCur3 =Error[3];  //内部CAN
    CutChaCurt0.Bit.F13_ChaOverCur3=Error[3] ;   //回馈电流降为0
    CutDCChaCurt02.Bit.F0_ChaOverCur3=Error[3] ;  //快充电流降为0
    
    //4级处理
    fault_pc552_Byte4.Bit.F7_ChaOverCur3 =Error[4];  //内部CAN,4级也报3级故障
    CutChaCurt0.Bit.F3_ChaOverCur4=Error[4] ;   //回馈电流降为0
    CutDCChaCurt0.Bit.F4_ChaOverCur4=Error[4] ;  //快充电流降为0        
}
//******************************************************************************
//* Function name:    CellOverVoltage
//* Description:      单体过压故障
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void CellOverVoltage(void)
{

    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0; 
    unsigned char LevelError=0;
    //上报故障等级等级数 
    Level=CellOverVoltage_step(g_CellHighestVol); 
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    BMS7_Byte2.Bit.F5_7_CellOverVolAlarm = Level; //i级故障报警 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F0_CellOverVol = 1; //i级故障报警
        g_DCChaPowerOffFlag=1;      //需要下电的快充模式非4级故障标志位 
    } 
    else
        BMS1_Byte5.Bit.F0_CellOverVol = 0; //i级故障报警 
        
    //1级处理   
    Can554Byte2.Bit.F3_CellOverVol1=Error[1];     //内部CAN
    CutDCChaCurt0.Bit.F5_CellOverVol1=Error[1] ;  //快充电流降为0
    //2级处理
    Can554Byte0.Bit.F3_CellOverVol2=Error[2] ;      //内部CAN
    CutChaCurt50.Bit.F2_CellOverVol2=Error[2] ;   //回馈电流降为50%
    CutDCChaCurt0.Bit.F6_CellOverVol2=Error[2] ;  //快充电流降为0        
     //3级处理
    fault_pc552_Byte4.Bit.F3_CellOverVol3 =Error[3];  //内部CAN
    CutChaCurt0.Bit.F4_CellOverVol3=Error[3] ;   //回馈电流降为0
    CutDCChaCurt0.Bit.F7_CellOverVol3=Error[3] ;  //快充电流降为0
    //4级处理
    fault_pc552_Byte4.Bit.F3_CellOverVol3 =Error[4];    //内部CAN,4级也报3级故障
    CutChaCurt0.Bit.F5_CellOverVol4=Error[4] ;   //回馈电流降为0
    CutDCChaCurt0.Bit.F8_CellOverVol4=Error[3] ;  //快充电流降为0            
}
//******************************************************************************
//* Function name:   CellUnderVoltage
//* Description:     单体电压欠压故障  
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void CellUnderVoltage(void)//上报不处理,充电不上报,恢复
{

    
    unsigned char i;
    unsigned char Error[5]={0};
    unsigned char Level=0; 
    unsigned char LevelError=0;

    Level=CellUnderVoltage_step(g_CellLowestVol);
    for(i=1;i<5;i++)
      if(i==Level)
        Error[i]=1;
    BMS7_Byte2.Bit.F2_4_CellUnderVolAlarm = Level; //i级故障报警 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F1_CellUnderVol = 1; //i级故障报警
    } 
    else
        BMS1_Byte5.Bit.F1_CellUnderVol = 0; //i级故障报警 
        
    //1级处理
    Can554Byte2.Bit.F1_CellUnderVol1=Error[1];     //内部CAN

    //2级处理  
    Can554Byte0.Bit.F1_CellUnderVol2=Error[2] ;      //内部CAN
    CutDisCurt50.Bit.F2_CellUnderVol2=Error[2] ;   //放电电流降为50%
            
     //3级处理
    fault_pc552_Byte4.Bit.F1_CellUnderVol3 =Error[3];  //内部CAN
    CutDisCurt0.Bit.F12_CellUnderVol3=Error[3] ;   //放电电流降为0
    
    //4级处理
    fault_pc552_Byte4.Bit.F1_CellUnderVol3 =Error[4];    //内部CAN,4级也报3级故障
    CutDisCurt0.Bit.F4_CellUnderVol4=Error[4] ;   //放电电流降为0
                     

}
//******************************************************************************
//* Function name:    CurrentSensorFault
//* Description:      电流传感器故障 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
Bool CurrentSensorFault(void) 
{
   // unsigned char ii = 0;
    static unsigned char jj = 0;
    if((g_BatSysTotalCur>500)||(g_BatSysTotalCur<-500))
        {   
            jj++;    
        } 
    else 
        jj=0;
    if (jj>=14) 
    {
            g_FlagLevel=(g_FlagLevel>1?g_FlagLevel:1);   //故障等级标志位 
            fault_pc552_Byte6.Bit.F1_CurSenFault=1;      //内部CAN    
            BMS7_Byte2.Bit.F1_CurSenFault=1;          //1级报警
            BMS5_Byte4.Bit.F5_ForceStopMode=1;       //强制停车模式
            if(g_BmsModeFlag == DISCHARGING)        //如果是行车模式  
            {
              CutDisCurt0.Bit.F3_CurSenFault=1 ;         //放电电流降为0
              CutChaCurt0.Bit.F6_CurSenFault=1 ;        //回馈电流降为0
            }
            if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
            {
              CutDCChaCurt0.Bit.F9_CurSenFault=1 ;      //快充电流降为0
              g_DCChaPowerOffFlag=1;      //需要下电的快充模式非4级故障标志位
            }
            jj = 15;
     } 

  return 0;  
}

//******************************************************************************
//* Function name:    TemperatureSensorFault
//* Description:      温度传感器故障 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*Bool TemperatureSensorFault(void) 
{
    //unsigned char ii = 0;
    unsigned char jj = 0;
    if((g_BatSysTotalCur>214)||(g_BatSysTotalCur<-35))
    {   
        jj++;    
    } 
    else 
        jj=0;
    if (jj>=14) 
    {
            g_FlagLevel=(g_FlagLevel>1?g_FlagLevel:1);   //故障等级标志位
            fault_pc552_Byte6.Bit.F2_TempSenFault=1;      //内部CAN    
            BMS7_Byte2.Bit.F0_TempSenFault=1;          //1级报警
            BMS5_Byte4.Bit.F5_ForceStopMode=1;       //强制停车模式
            if(g_BmsModeFlag == DISCHARGING)        //如果是行车模式  
            {
              CutDisCurt0.Bit.F5_TempSenFault=1 ;         //放电电流降为0
              CutChaCurt0.Bit.F7_TempSenFault=1 ;        //回馈电流降为0
              g_PowerOffFlag=1;               //需要下电的非4级故障标志位
            }
            if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
            {
              CutDCChaCurt0.Bit.F10_TempSenFault=1 ;      //快充电流降为0
              g_DCChaPowerOffFlag=1;      //需要下电的快充模式非4级故障标志位
            }
            jj=15;
     }
   return 0;   
} */
//******************************************************************************
//* Function name:  CellVoltageUnbalance
//* Description:    单体电压不均衡故障 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void CellVoltageUnbalance(void)
{
 
  
    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0;

    //上报故障等级
    Level=CellVoltageUnbalance_step(g_CellHighestVol,g_CellLowestVol);
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    BMS7_Byte3.Bit.F5_7_CellVolUnbalAlarm = Level; //i级故障报警 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
    if(Level!=0) 
    {
        BMS1_Byte6.Bit.F2_CellVolUnbal = 1; //i级故障报警
    } 
    else
        BMS1_Byte6.Bit.F2_CellVolUnbal = 0; //i级故障报警
     //1级处理
    Can554Byte3.Bit.F2_CellVolUnbal1=Error[1];     //内部CAN
        
    //2级处理  
    Can554Byte1.Bit.F2_CellVolUnbal2=Error[2] ;      //内部CAN
    CutDisCurt50.Bit.F3_CellVolUnbal2=Error[2] ;   //放电电流降为50%
    CutChaCurt50.Bit.F3_CellVolUnbal2=Error[2];   //回充降为50%
    CutDCChaCurt50.Bit.F2_CellVolUnbal2=Error[2] ;   //快充电流降为50%        
    
}

//******************************************************************************
//* Function name:    CellTemperatureUnbalance
//* Description:    单体温度不均衡故障 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void CellTemperatureUnbalance(void)//
{
    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level;
    float Tmp_H,Tmp_L;
    Tmp_H=(float)g_BatHighestTemp;
    Tmp_L=(float)g_BatLowestTemp;
    
    
    //上报故障等级
    Level=CellTemperatureUnbalance_step(Tmp_H,Tmp_L);
    for(i=1;i<5;i++)
        if(i==Level)
            Error[i]=1;
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
    BMS7_Byte3.Bit.F2_4_CellTempUnbalAlarm = Level; //i级故障报警 
    if(Level!=0) 
    {
        BMS1_Byte6.Bit.F3_CellTempUnbal = 1; //i级故障报警
    } 
    else
        BMS1_Byte6.Bit.F3_CellTempUnbal = 0; //i级故障报警
        
    //1级处理
    Can554Byte3.Bit.F3_CellTempUnbal1=Error[1];     //内部CAN

    //2级处理  
    Can554Byte1.Bit.F3_CellTempUnbal2=Error[2] ;  //内部CAN
    CutDisCurt50.Bit.F4_CellTempUnbal2=Error[2] ;   //放电电流降为50%
    CutChaCurt50.Bit.F4_CellTempUnbal2=Error[2];   //回充降为50%
    CutDCChaCurt50.Bit.F3_CellTempUnbal2=Error[2] ;   //快充电流降为50%        
     //3级处理
    fault_pc552_Byte5.Bit.F3_CellTempUnbal3 =Error[3];  //内部CAN
    CutDisCurt0.Bit.F13_CellTempUnbal3=Error[3] ;   //放电电流降为0
    CutChaCurt0.Bit.F14_CellTempUnbal3=Error[3];   //回充降为0if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
    CutDCChaCurt0.Bit.F12_CellTempUnbal3=Error[3] ;   //快充电流降为0
   
}

//******************************************************************************
//* Function name:    SOCLow
//* Description:      SOC过低故障  行车
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void SOCLow(void)
{
    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0;    
    Level=SOCLow_step(g_SysSOC);
    
    for(i=1;i<5;i++) 
        if(i==Level) 
            Error[i]=1;
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位  
    BMS7_Byte5.Bit.F5_7_SOCLowAlarm = Level; //i级故障报警 
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F3_SOCLow = 1; //i级故障报警
    } 
    else
        BMS1_Byte5.Bit.F3_SOCLow = 0; //i级故障报警
        
    Can554Byte3.Bit.F1_SOCLow1=Error[1];     //内部CAN
        
    //2级处理  
    Can554Byte1.Bit.F1_SOCLow2=Error[2] ;  //内部CAN
           
    //3级处理
    fault_pc552_Byte5.Bit.F1_SOCLow3 =Error[3];    //内部CAN
    
    
}


//******************************************************************************
//* Function name:    BatteryTemperatureHigh
//* Description:      电池温度过高故障   
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BatteryTemperatureHigh(void)//
{
    unsigned char i;
    unsigned char Error[5]={0}; 
    unsigned char Level=0; 
    unsigned char LevelError=0;
    
    
    
    //上报故障等级
    Level=BatteryTemperatureHigh_step(g_BatHighestTemp);
    
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;    
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
    BMS7_Byte4.Bit.F5_7_BatTempHighAlarm=Level;     //i级报警  
    if(Level!=0) 
    {
      BMS1_Byte5.Bit.F6_BatTempHigh = 1; //i级故障报警 
    } 
    else
      BMS1_Byte5.Bit.F6_BatTempHigh = 0; //i级故障报警 

    //1级处理
    Can554Byte2.Bit.F5_BatTempHigh1=Error[1];     //内部CAN
      
    //2级处理  
    Can554Byte0.Bit.F5_BatTempHigh2=Error[2] ;  //内部CAN
    CutDisCurt50.Bit.F7_BatTempHigh2=Error[2] ;   //放电电流降为50% 
    CutChaCurt50.Bit.F7_BatTempHigh2=Error[2];   //回充电流降为50%	
    CutDCChaCurt50.Bit.F4_BatTempHigh2=Error[2] ;   //快充电流降为50%       
     //3级处理
    fault_pc552_Byte4.Bit.F5_BatTempHigh3 =Error[3];  //内部CAN
    CutDisCurt0.Bit.F14_BatTempHigh3=Error[3] ;   //放电电流降为0
    CutChaCurt0.Bit.F15_BatTempHigh3=Error[3];   //回充降为0
    CutDCChaCurt02.Bit.F1_BatTempHigh3=Error[3] ;   //快充电流降为0
    //4级处理
    fault_pc552_Byte4.Bit.F5_BatTempHigh3=Error[4];    //内部CAN,4级也报3级故障
    CutDisCurt0.Bit.F8_BatTempHigh4=Error[4] ;   //放电电流降为0
    CutChaCurt0.Bit.F10_BatTempHigh4=Error[4];   //回充降为0
    CutDCChaCurt0.Bit.F13_BatTempHigh4=Error[4] ;   //快充电流降为0
    if(4==Level) 
    {   //上报故障
        if(g_BmsModeFlag == FASTRECHARGING)      //如果是快充模式
        {
            BMS9_Byte7.Bit.F2_BatChaOverTemp=Error[4] ;     //充电过温
            BMS9_Byte7.Bit.F4_BzerAlarm= Error[4] ;       //蜂鸣器报警
        }
    }            
  
}

//******************************************************************************
//* Function name:    BatteryTemperatureLow
//* Description:      电池温度过低故障 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BatteryTemperatureLow(void)//
{

    unsigned char i;
    unsigned char Error[5]={0}; 
    unsigned char Level=0;
    
    
    //上报故障等级
    Level=BatteryTemperatureLow_step(g_BatLowestTemp);
    BMS7_Byte4.Bit.F2_4_BatTempLowAlarm=Level;     //i级报警 
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //故障等级标志位
       
     //1级处理
    Can554Byte2.Bit.F6_BatTempLow1=Error[1];     //内部CAN
    
    
    //2级处理  
    Can554Byte0.Bit.F6_BatTempLow2=Error[2] ;  //内部CAN
           
    //3级处理
    fault_pc552_Byte4.Bit.F6_BatTempLow3 =Error[3];  //内部CAN
    
    //4级处理
    fault_pc552_Byte4.Bit.F6_BatTempLow3=Error[4];    //内部CAN,4级也报3级故障
    CutDisCurt0.Bit.F9_BatTempLow4=Error[4] ;   //放电电流降为0
    CutChaCurt0.Bit.F11_BatTempLow4=Error[4];   //回充降为0 
    CutDCChaCurt0.Bit.F14_BatTempLow4=Error[4] ;   //快充电流降为0            

}
//******************************************************************************
//* Function name:   SOCSaltus
//* Description:     SOC跳变
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void  SOCSaltus(void) 
{
    static unsigned char Delay5s=0;
    float SOCNow=0.0;
    float SOCDif=0.0;
    Delay5s++;
    if(Delay5s>=5) 
    {
        Delay5s=0;
        SOCNow=g_SysSOC;
    }
    SOCDif= SOCNow-SOCBefore;
    if((SOCDif>=0.3)||(SOCDif<=-0.3)) 
    {
        BMS7_Byte5.Bit.F3_4_SOCSal=1;   // SOC跳变报警
    } 
    SOCBefore=SOCNow;    
}

*/
//******************************************************************************
//* Function name:   ChargeCurrentDirectionAnomaly
//* Description:     充电电流方向异常
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void ChargeCurrentDirectionAnomaly(void) 
{

    static unsigned char Check_Num=0;
    if(((g_BmsModeFlag == FASTRECHARGING))&&(g_BatSysTotalCur >= 2)) 
    {
        Check_Num++;
        if(Check_Num>=100) 
        {
            CutDCChaCurt02.Bit.F3_ChaCurDirAno=1; //充电电流方向异常，充电电流降为0
            g_FlagLevel=4;                   //故障等级标志位
            ChaCurDirAnly=1;                //充电电流方向异常标志位
            if(Check_Num>=250) //如果发生了100次，该算法要求必须下电。
                Check_Num=100;
        }
    }
}

//**********************************************************************
//* Function name:   CarFaultDone
//* Description:     行车过程中故障的处理
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void CarFaultDone()
{
    if( (4 == BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm)//总电压过压
    || (4 == BMS7_Byte0.Bit.F2_4_TotalVolUnderVolAlarm) // 总电压欠压
    || (1 == BMS7_Byte0.Bit.F0_WithLECUComAlarm)     //内部通信故障
    || (4 == BMS7_Byte1.Bit.F5_7_DisChaOverCurAlarm)   //放电过流
    || (4 == BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm)     //充电过流
    || (4 == BMS7_Byte2.Bit.F5_7_CellOverVolAlarm)     //单体过压
    || (4 == BMS7_Byte2.Bit.F2_4_CellUnderVolAlarm)    //单体欠压
    || (1 == BMS7_Byte2.Bit.F1_CurSenFault)        //电流传感器故障
    || (4 == BMS7_Byte4.Bit.F5_7_BatTempHighAlarm)  //温度过高
    || (4 == BMS7_Byte4.Bit.F2_4_BatTempLowAlarm))  //温度过低
    {
        g_PowerOffFlag=1;      //行车模式下需要下电的故障
    } 
}

                
//******************************************************************************
//* Function name:   BMSProtect
//* Description:     BMS最后的保护,不受状态机控制，强制断高压
//* EntryParameter : None
//* ReturnValue    : Bool类型 0-无；1-有
//******************************************************************************
void BMSProtect(void)//有风险，如果OffState判断失败,最好用实际电压比较********** 
{
    static unsigned char LCDelaytime=0;
    static unsigned char HCDelaytime=0;
    static unsigned char HTDelaytime=0;
    static unsigned char HBaDelaytime=0;
    if(g_BmsModeFlag == DISCHARGING)
    {      
        if((g_CellLowestVol<=LOWEST_CELL_VOL  )&&(g_CellLowestVol!=0))
        {
            LCDelaytime++;
            if(LCDelaytime>20)
            {
                LCDelaytime=27;
                TurnOff_INFK();//断开放电负继电器
                delay(25000); //19ms
                TurnOff_INA2K();//充电负断开
                
            }
        } 
        else
        {
            LCDelaytime=0;
        }
    }
    if((g_BmsModeFlag == FASTRECHARGING))
    {      
        if(g_CellHighestVol>=HIGHEST_CELL_VOL )//10s
        {
            HCDelaytime++;
            if(HCDelaytime>30)
            {
                HCDelaytime=37;
                TurnOff_INFK();//断开放电负继电器
                delay(25000); //19ms
                TurnOff_INA2K();//充电负断开
            }
        } 
        else
        {
            HCDelaytime=0;
        }
        if(g_SystemVoltageV0>=HIGHEST_BATT_VOL )//
        {
            HBaDelaytime++;
            if(HBaDelaytime>30)
            {
                HBaDelaytime=37;
                TurnOff_INFK();//断开放电负继电器
                delay(25000); //19ms
                TurnOff_INA2K();//快充继电器
            }
        } 
        else
        {
            HBaDelaytime=0;
        }
        
    }
    if(g_BatHighestTemp>(HIGHEST_TEM+40) )//10s
    {
        HTDelaytime++;
        if(HTDelaytime>85)
        {
            HTDelaytime=89;
            TurnOff_INFK();//断开放电负继电器
            delay(25000); //19ms
            TurnOff_INA2K();//快充继电器
        }
    } 
    else
    {
        HTDelaytime=0;
    } 
  
}



//******************************************************************************
//* Function name:   FaultLevelProcess
//* Description:     故障等级处理
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void FaultLevelProcess(void)
{    
    if(g_FlagLevel!=0)
        BMS7_Byte7.Bit.F0_BatState=1;         //动力电池状态报警
    else 
        BMS7_Byte7.Bit.F0_BatState=0;         //动力电池状态报警

    if(g_FlagLevel==4)
    {      
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=4;      //电池故障等级4级 
        BMS5_Byte4.Bit.F4_CutMainCtor=1;         //请求“断开主接触器”
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=1;  //强制降功率
        BMS5_Byte4.Bit.F5_ForceStopMode=1;       //强制停车模式 
        
        if(g_BmsModeFlag == FASTRECHARGING) 
        {
            g_DCChaPowerOffFlag=1;       //充电模式下需要下电的故障
            if(WithEVCUComOverTime==2)
            {
                g_DCChaPowerOffFlag=0;   //充电模式，与EVCU通信故障单独判断，只判断超时标志位
            }
        }
    } 
    else if(g_FlagLevel==3) 
    {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=3;      //电池故障等级3级
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=1;  //强制降功率
        BMS5_Byte4.Bit.F5_ForceStopMode=1;       //强制停车模式 
    }
     else if(g_FlagLevel==2) 
     {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=2;      //电池故障等级2级
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=1;  //强制降功率
        BMS5_Byte4.Bit.F5_ForceStopMode=0;       //强制停车模式 
     }
     else if(g_FlagLevel==1) 
     {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=1;      //电池故障等级1级
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=0;  //强制降功率
        BMS5_Byte4.Bit.F5_ForceStopMode=0;       //强制停车模式  
     }
     else if(g_FlagLevel==0) 
     {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=0;      //电池故障等级0级
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=0;  //强制降功率
        BMS5_Byte4.Bit.F5_ForceStopMode=0;       //强制停车模式 
     }
     if(CutDisCurt0.word != 0) 
     { 
        CutDischaTo0 = 1;     //放电为0
     } 
     else 
     { 
        CutDischaTo0 = 0;     //放电为0
     }
     
     
     if(CutDisCurt50.word != 0) 
     { 
        CutDischaTo50 = 1;     //放电为50%
     } 
     else 
     { 
        CutDischaTo50 = 0;     //放电为50%
     }
     
     
     if(CutChaCurt0.word != 0) 
     { 
        CutFebchaTo0 = 1;    //回馈为0
     } 
     else 
     { 
        CutFebchaTo0 = 0;    //回馈为0
     }
     
     
     if(CutChaCurt50.word !=0 ) 
     { 
        CutFebchaTo50=1;    //回馈为50%
     } 
     else 
     {
        CutFebchaTo50=0;    //回馈为50%
     }
     if((g_RelayPowerOffFault==0)) //如果继电器没有故障
        g_FlagLevel=0;       //报完之后恢复为0
}


//******************************************************************************
//* Function name:    FaultProcess
//* Description:      检测各种故障: 其中4级故障为最严重故障
//* EntryParameter : None
//* ReturnValue    : 有无故障：0-无；1-有
//******************************************************************************
unsigned char TaskFaultProcess(void) 
{ 
    unsigned char lever = 0;
    
    unsigned char i,j,k=0;
    static unsigned char caution1=0;
    static unsigned char caution2=0;
    static unsigned char caution3=0;
    static unsigned char caution4=0;
    if(((stateCode>14))||(stateCode>144)) 
    {
      TotalVoltageOverVoltage();   //总电压过压
    }
    
    if(g_BmsModeFlag == DISCHARGING) 
    {
        if((stateCode>14)&&(stateCode<46)) 
        {
          TotalVoltageUnderVoltage(); //总电压欠压  
        }
        CellUnderVoltage();      //单体欠压
        DischargeOverCurrent();   //放电过流
        SOCLow();            //SOC低
        
    }
    
    if(g_BmsModeFlag == FASTRECHARGING) 
    {
        WithDCChargerCommunicationFault(); //与直流充电机通信故障（包括超时故障）
        ChargeCurrentDirectionAnomaly();//充电电流方向异常
        
    }
    
    WithDCChargerCommunicationFault(); //与直流充电机通信故障（包括超时故障）
    InternalCommunicationFault();       //内部通信故障    
    WithEVCUCommunicationFault();     //EVCU通讯故障
    CurrentSensorFault();            //电流传感器故障
    
    ChargeOverCurrent();      //充电过流
    CellOverVoltage();       //单体过压
    CellVoltageUnbalance();   //单体电压不均衡
    CellTemperatureUnbalance();//单体温度不均衡
    BatteryTemperatureHigh();  //单体温度过高
    BatteryTemperatureLow();  //单体温度过低 
  
    //CarFaultDone();       //行车过程中故障的处理
    FaultLevelProcess();     //故障等级处理  
    BMSProtect();     ////////BMS最后断继电器
    
    //*****************************************************************************************
    //******************************************************************************************
    ////////////当故障与之前相比，没有变化时，不进行存储，只有1分钟才存储；如果有更新，才进行存储
    if((caution1^g_caution_Flag_1)||(caution2^g_caution_Flag_2)||(caution3^g_caution_Flag_3)||(caution4^g_caution_Flag_4))
        StoreSysVariable();//保存SOC值和故障信息
    caution1 =  g_caution_Flag_1;
    caution2 =  g_caution_Flag_2;
    caution3 =  g_caution_Flag_3;
    caution4 =  g_caution_Flag_4;
    //////////////////////////////////////////////////////////////////
    ////Caution_Flag_4：Bit 0：高压母线连接故障；Bit 1：烟雾检测故障；    
    ///////////////////  
    g_storageSysVariable[PARA_ERROR_LEVER] = lever;
    g_storageSysVariable[CAUTION_FLAG_1] = g_caution_Flag_1;	
    g_storageSysVariable[CAUTION_FLAG_2] = g_caution_Flag_2;	
    g_storageSysVariable[CAUTION_FLAG_3] = g_caution_Flag_3;	
    g_storageSysVariable[CAUTION_FLAG_4] = g_caution_Flag_4;	
  
	  return g_storageSysVariable[PARA_ERROR_LEVER];

} 
//********************************************************************************************
//***********************************the end*************************************************
//********************************************************************************************
//********************************************************************************************