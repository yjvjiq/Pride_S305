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
//* Description        : ���ļ� ��ϵͳ�ĸ��������ж�
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
unsigned char  g_caution_Flag_1 =0;//BMS����״̬ FOR ��λ��
unsigned char  g_caution_Flag_2 =0;
unsigned char  g_caution_Flag_3 =0;
unsigned char  g_caution_Flag_4 =0;

unsigned char CutDischaTo0;    //�ŵ������0
unsigned char CutDischaTo50;   //�ŵ������50%
unsigned char CutFebchaTo0;    //����������0
unsigned char CutFebchaTo50;   //����������50%
//�ŵ����
CUTDISCURT0  CutDisCurt0;      //�ŵ������Ϊ0
CUTDISCURT50 CutDisCurt50;      //�ŵ������Ϊ50%

//��������
CUTCHACURT0 CutChaCurt0;      //����������Ϊ0
CUTCHACURT50 CutChaCurt50;     //����������Ϊ50%
//������
CUTDCCHACURT0 CutDCChaCurt0;    //��������Ϊ0
CUTDCCHACURT50 CutDCChaCurt50;   //��������Ϊ50%
CUTDCCHACURT02 CutDCChaCurt02;   //��������Ϊ0
unsigned char ChaCurDirAnly=0;//�����������쳣��־λ
unsigned char g_FlagLevel=0;  //���ϵȼ���־λ
unsigned int WithEVCUComOverTime=0;   //������ͨ�Ź��ϳ�ʱ��ʱ
unsigned int WithEVCUComOverTimeFlag=0;   //������ͨ�Ź��ϳ�ʱ��־λ
unsigned char CarFaultFlag=1;  //�г����ϱ�־λ,1Ϊ����1���ͣ���������2Ϊ����2����(EVCU)
unsigned char g_DCChaPowerOffFlag=0;    //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ
unsigned char g_PowerOffFlag=0; //�µ��־λ

//******************************************************************************
//* Function name:    TotalVoltageOverVoltage
//* Description:      �ܵ�ѹ��ѹ���� ��1������΢��4��Ϊ�����ع��ϣ�
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
    if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
    {
        VolValue=g_BatSysTotalVolV3; 
    }
    //Level=Battery_MaxFaultLevel_step(g_BatHighestTemp,g_BatLowestTemp,g_CellHighestVol,(float)g_BatHighestTemp,(float)g_BatLowestTemp,g_CellLowestVol,curtValue,g_BatSysTotalCur,g_MaxDischaCur,g_SystemVoltageV0,g_BatSysTotalVolV3,g_BatSysTotalVolV2); //���ϵȼ�
    Level=TotalVoltageOverVoltage_step(g_SystemVoltageV0,VolValue);
    ///////////////////�ϱ����ϵȼ���/////////////////////////   
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm = Level; //i�����ϱ���  
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
    if(Level!=0) 
    {
      BMS1_Byte6.Bit.F0_TotalVolOverVol = 1; //i�����ϱ��� 
    } 
    else
      BMS1_Byte6.Bit.F0_TotalVolOverVol = 0; //i�����ϱ��� 

    //1������
    Can554Byte2.Bit.F2_TotalVolOverVol1=Error[1];   //�ڲ�CAN  

    //2������  
    Can554Byte0.Bit.F2_TotalVolOverVol2=Error[2] ; //�ڲ�CAN
    CutChaCurt50.Bit.F0_TotalVolOverVol2=Error[2] ;   //�س������Ϊ50%       
    CutDCChaCurt0.Bit.F15_TotalVolOverVol2=Error[2] ;  //��������Ϊ0
    if(2==Level) 
    {  //�ϱ�����           
        if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
        {            
            g_DCChaPowerOffFlag=1;      //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ
        }
    }
    //3������
    fault_pc552_Byte4.Bit.F2_TotalVolOverVol3 =Error[3];  //�ڲ�CAN
    CutChaCurt0.Bit.F0_TotalVolOverVol3=Error[3] ;   //�س������Ϊ0
    CutDCChaCurt0.Bit.F0_TotalVolOverVol3=Error[3] ;  //��������Ϊ0
    if(3==Level) 
    {   //�ϱ�����
        if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
        {
            g_DCChaPowerOffFlag=1;      //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ
        }
    }
    //4������
    fault_pc552_Byte4.Bit.F2_TotalVolOverVol3 =Error[4]; //�ڲ�CAN,4��Ҳ��3������
    CutChaCurt0.Bit.F1_TotalVolOverVol4=Error[4] ;   //�س������Ϊ0
    CutDCChaCurt0.Bit.F1_TotalVolOverVol4=Error[4] ;  //��������Ϊ0
    if(4==Level) 
    {   //�ϱ�����        
        if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
        {
            BMS9_Byte7.Bit.F4_BzerAlarm= Error[4] ;       //����������
            BMS9_Byte7.Bit.F3_BatChaOverVol= Error[4] ;   //������س���ѹ
            g_DCChaPowerOffFlag=1;      //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ
        }
    } 
               
}
//******************************************************************************
//* Function name:    TotalVoltageUnderVoltage
//* Description:      ��ذ��ܵ�ѹǷѹ���� 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void TotalVoltageUnderVoltage(void) //�ָ�,�ϱ�
{   
    unsigned char i;
    unsigned char Error[5]={0};
    unsigned char Level=0; 
    unsigned char LevelError=0;
    ///////////////////�ϱ����ϵȼ���/////////////////////////
    Level=TotalVoltageUnderVoltage_step(g_SystemVoltageV0,g_BatSysTotalVolV2);
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;   
    BMS7_Byte0.Bit.F2_4_TotalVolUnderVolAlarm = Level; //i�����ϱ��� 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ 
    if(Level!=0) 
    {
      BMS1_Byte6.Bit.F1_TotalVolUnderVol = 1; //i�����ϱ��� 
    } 
    else
      BMS1_Byte6.Bit.F1_TotalVolUnderVol = 0; //i�����ϱ��� 

    //1�����ϴ���
    Can554Byte2.Bit.F0_TotalVolUnderVol1=Error[1];  //�ڲ�CAN
    
    //2������
    Can554Byte0.Bit.F0_TotalVolUnderVol2=Error[2] ;  //�ڲ�CAN
    CutDisCurt50.Bit.F0_TotalVolUnderVol2=Error[2] ;   //�ŵ������Ϊ50%
    
    //3������
    fault_pc552_Byte4.Bit.F0_TotalVolUnderVol3 =Error[3];  //�ڲ�CAN
    CutDisCurt0.Bit.F10_TotalVolUnderVol3=Error[3] ;   //�ŵ������Ϊ0
    
    //4������
    fault_pc552_Byte4.Bit.F0_TotalVolUnderVol3 =Error[4];  //�ڲ�CAN,4��Ҳ��3������
    CutDisCurt0.Bit.F0_TotalVolUnderVol4=Error[4] ;   //�ŵ������Ϊ0
      
}
//******************************************************************************
//* Function name:    WithDCChargerCommunicationFault
//* Description:      ��ֱ������ͨ�Ź��ϣ�������ʱ���ϣ�
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************

void WithDCChargerCommunicationFault(void)
{
    if(OverTimeState==1)   //��䳬ʱ
    {
        fault_pc552_Byte5.Bit.F4_WithChgerComFault=1;     //�ڲ�CAN
        CutDCChaCurt0.Bit.F3_WithChgerComFault = 1;  //�������϶�������
        BMS7_Byte0.Bit.F1_WithChgerComAlarm=1;   //1������ 
        BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //����������
        g_FlagLevel=(g_FlagLevel>1?g_FlagLevel:1);   //���ϵȼ���־λ 
        g_DCChaPowerOffFlag=1;      //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ

    }
    
}
//******************************************************************************
//* Function name:    InternalCommunicationFault
//* Description:      �ڲ�ͨѶ����  4��
//* EntryParameter : None
//* ReturnValue    : Bool���� 0-�ޣ�1-��
//******************************************************************************
void InternalCommunicationFault(void) 
{ 
    if(fault_pc552_Byte6.Bit.F0_InterComFault==1) //�ڲ�ͨѶ����
    {
        if(g_BmsModeFlag == DISCHARGING)        //������г�ģʽ   
        {
            CutDisCurt0.Bit.F1_InterComFault=1;         //���϶��������ŵ罵Ϊ0
            CutChaCurt0.Bit.F2_InterComFault=1;        //�س併Ϊ0
        }
        if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
        {
            CutDCChaCurt0.Bit.F2_InterComFault=1;      //��併Ϊ0
            BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //����������
        }
        g_FlagLevel=4;                         //���ϵȼ���־λ
        BMS7_Byte0.Bit.F0_WithLECUComAlarm=1;    //4������ 
        
     } 

}
//******************************************************************************
//* Function name:    WithEVCUCommunicationFault
//* Description:      EVCUͨѶ����  4��
//* EntryParameter : None
//* ReturnValue    : Bool���� 0-�ޣ�1-��
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
    if((WithEVCUComOverTimeFlag==2)&&(g_BmsModeFlag == FASTRECHARGING))   //EVCU���ģʽ��ʱ
    {
        CutDCChaCurt02.Bit.F2_WithEVCUComFault=1;   //��罵Ϊ0
        g_FlagLevel=4;                         //���ϵȼ���־λ
        BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //����������         
        WithEVCUComOverTime=11;         
    } 
    else if((WithEVCUComOverTimeFlag==1)&&(g_BmsModeFlag == DISCHARGING))   //EVCU�г�ģʽ��ʱ
    {
        CutDisCurt0.Bit.F15_WithEVCUComFault=1;   //�ŵ������Ϊ0  
        CutChaCurt0.Bit.F8_WithEVCUComFault=1;    //�س������Ϊ0
        g_FlagLevel=4;                       //���ϵȼ���־λ        
        WithEVCUComOverTime=121;   
    }
}
//******************************************************************************
//* Function name:    DischargeOverCurrent
//* Description:      �ŵ��������  4��������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void DischargeOverCurrent(void) //�ŵ����
{
    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0; 
    unsigned char LevelError=0;
    float curtValue=0.0;

   
    curtValue = g_MaxDischaCur;
    
    ////////////////////////�ϱ����ϵȼ�////////////////////////
    Level=DischargeOverCurrent_step(g_BatSysTotalCur,curtValue);  
    for(i=1;i<5;i++) 
            if(i==Level) 
                Error[i]=1;
    BMS7_Byte1.Bit.F5_7_DisChaOverCurAlarm = Level; //i�����ϱ���         
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ        
    if(Level!=0) 
    {
      BMS1_Byte5.Bit.F5_DischaOverCur = 1; //i�����ϱ��� 
    } 
    else
      BMS1_Byte5.Bit.F5_DischaOverCur = 0; //i�����ϱ��� 

     //1������
    Can554Byte3.Bit.F0_DischaOverCur1=Error[1];  //�ڲ�CAN
    //2������  
    Can554Byte1.Bit.F0_DischaOverCur2=Error[2] ;  //�ڲ�CAN
    CutDisCurt50.Bit.F1_DischaOverCur2=Error[2] ;   //�ŵ������Ϊ50%        
            
     //3������
    fault_pc552_Byte5.Bit.F0_DischaOverCur3 =Error[3];   //�ڲ�CAN
    CutDisCurt0.Bit.F11_DisChaOverCur3=Error[3] ;   //�ŵ������Ϊ0        
    
    //4������
    fault_pc552_Byte5.Bit.F0_DischaOverCur3 =Error[4];   //�ڲ�CAN,4��Ҳ��3������
    CutDisCurt0.Bit.F2_DisChaOverCur4=Error[4] ;   //�ŵ������Ϊ0   
        
}
//******************************************************************************
//* Function name:    ChargeOverCurrent
//* Description:      ���������� 
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
    
    if(g_BmsModeFlag == DISCHARGING)//�ŵ�ģʽ
    {
        curtValue=g_MaxFebCur; //��������Ϊ��ֵ
    }
    else if((g_BmsModeFlag == FASTRECHARGING)) //���ģʽ
    {
        curtValue=g_AskDCCur;
    } 
    ///////////////////�ϱ����ϵȼ���/////////////////////////    
    Level=ChargeOverCurrent_step(-(g_BatSysTotalCur),curtValue);    
    for(i=1;i<5;i++) 
            if(i==Level) 
                Error[i]=1;
    BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm = Level; //i�����ϱ���         
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F4_ChaOverCur = 1; //i�����ϱ��� 
    } 
    else
        BMS1_Byte5.Bit.F4_ChaOverCur = 0; //i�����ϱ��� 
    //1������
    Can554Byte2.Bit.F7_ChaOverCur1=Error[1];     //�ڲ�CAN

    //2������  
    Can554Byte0.Bit.F7_ChaOverCur2=Error[2] ;      //�ڲ�CAN
    CutChaCurt50.Bit.F1_ChaOverCur2=Error[2] ;   //����������Ϊ50%
    CutDCChaCurt50.Bit.F1_ChaOverCur2=Error[2] ;  //��������Ϊ50%
            
     //3������
    fault_pc552_Byte4.Bit.F7_ChaOverCur3 =Error[3];  //�ڲ�CAN
    CutChaCurt0.Bit.F13_ChaOverCur3=Error[3] ;   //����������Ϊ0
    CutDCChaCurt02.Bit.F0_ChaOverCur3=Error[3] ;  //��������Ϊ0
    
    //4������
    fault_pc552_Byte4.Bit.F7_ChaOverCur3 =Error[4];  //�ڲ�CAN,4��Ҳ��3������
    CutChaCurt0.Bit.F3_ChaOverCur4=Error[4] ;   //����������Ϊ0
    CutDCChaCurt0.Bit.F4_ChaOverCur4=Error[4] ;  //��������Ϊ0        
}
//******************************************************************************
//* Function name:    CellOverVoltage
//* Description:      �����ѹ����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void CellOverVoltage(void)
{

    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0; 
    unsigned char LevelError=0;
    //�ϱ����ϵȼ��ȼ��� 
    Level=CellOverVoltage_step(g_CellHighestVol); 
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    BMS7_Byte2.Bit.F5_7_CellOverVolAlarm = Level; //i�����ϱ��� 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F0_CellOverVol = 1; //i�����ϱ���
        g_DCChaPowerOffFlag=1;      //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ 
    } 
    else
        BMS1_Byte5.Bit.F0_CellOverVol = 0; //i�����ϱ��� 
        
    //1������   
    Can554Byte2.Bit.F3_CellOverVol1=Error[1];     //�ڲ�CAN
    CutDCChaCurt0.Bit.F5_CellOverVol1=Error[1] ;  //��������Ϊ0
    //2������
    Can554Byte0.Bit.F3_CellOverVol2=Error[2] ;      //�ڲ�CAN
    CutChaCurt50.Bit.F2_CellOverVol2=Error[2] ;   //����������Ϊ50%
    CutDCChaCurt0.Bit.F6_CellOverVol2=Error[2] ;  //��������Ϊ0        
     //3������
    fault_pc552_Byte4.Bit.F3_CellOverVol3 =Error[3];  //�ڲ�CAN
    CutChaCurt0.Bit.F4_CellOverVol3=Error[3] ;   //����������Ϊ0
    CutDCChaCurt0.Bit.F7_CellOverVol3=Error[3] ;  //��������Ϊ0
    //4������
    fault_pc552_Byte4.Bit.F3_CellOverVol3 =Error[4];    //�ڲ�CAN,4��Ҳ��3������
    CutChaCurt0.Bit.F5_CellOverVol4=Error[4] ;   //����������Ϊ0
    CutDCChaCurt0.Bit.F8_CellOverVol4=Error[3] ;  //��������Ϊ0            
}
//******************************************************************************
//* Function name:   CellUnderVoltage
//* Description:     �����ѹǷѹ����  
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void CellUnderVoltage(void)//�ϱ�������,��粻�ϱ�,�ָ�
{

    
    unsigned char i;
    unsigned char Error[5]={0};
    unsigned char Level=0; 
    unsigned char LevelError=0;

    Level=CellUnderVoltage_step(g_CellLowestVol);
    for(i=1;i<5;i++)
      if(i==Level)
        Error[i]=1;
    BMS7_Byte2.Bit.F2_4_CellUnderVolAlarm = Level; //i�����ϱ��� 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F1_CellUnderVol = 1; //i�����ϱ���
    } 
    else
        BMS1_Byte5.Bit.F1_CellUnderVol = 0; //i�����ϱ��� 
        
    //1������
    Can554Byte2.Bit.F1_CellUnderVol1=Error[1];     //�ڲ�CAN

    //2������  
    Can554Byte0.Bit.F1_CellUnderVol2=Error[2] ;      //�ڲ�CAN
    CutDisCurt50.Bit.F2_CellUnderVol2=Error[2] ;   //�ŵ������Ϊ50%
            
     //3������
    fault_pc552_Byte4.Bit.F1_CellUnderVol3 =Error[3];  //�ڲ�CAN
    CutDisCurt0.Bit.F12_CellUnderVol3=Error[3] ;   //�ŵ������Ϊ0
    
    //4������
    fault_pc552_Byte4.Bit.F1_CellUnderVol3 =Error[4];    //�ڲ�CAN,4��Ҳ��3������
    CutDisCurt0.Bit.F4_CellUnderVol4=Error[4] ;   //�ŵ������Ϊ0
                     

}
//******************************************************************************
//* Function name:    CurrentSensorFault
//* Description:      �������������� 
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
            g_FlagLevel=(g_FlagLevel>1?g_FlagLevel:1);   //���ϵȼ���־λ 
            fault_pc552_Byte6.Bit.F1_CurSenFault=1;      //�ڲ�CAN    
            BMS7_Byte2.Bit.F1_CurSenFault=1;          //1������
            BMS5_Byte4.Bit.F5_ForceStopMode=1;       //ǿ��ͣ��ģʽ
            if(g_BmsModeFlag == DISCHARGING)        //������г�ģʽ  
            {
              CutDisCurt0.Bit.F3_CurSenFault=1 ;         //�ŵ������Ϊ0
              CutChaCurt0.Bit.F6_CurSenFault=1 ;        //����������Ϊ0
            }
            if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
            {
              CutDCChaCurt0.Bit.F9_CurSenFault=1 ;      //��������Ϊ0
              g_DCChaPowerOffFlag=1;      //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ
            }
            jj = 15;
     } 

  return 0;  
}

//******************************************************************************
//* Function name:    TemperatureSensorFault
//* Description:      �¶ȴ��������� 
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
            g_FlagLevel=(g_FlagLevel>1?g_FlagLevel:1);   //���ϵȼ���־λ
            fault_pc552_Byte6.Bit.F2_TempSenFault=1;      //�ڲ�CAN    
            BMS7_Byte2.Bit.F0_TempSenFault=1;          //1������
            BMS5_Byte4.Bit.F5_ForceStopMode=1;       //ǿ��ͣ��ģʽ
            if(g_BmsModeFlag == DISCHARGING)        //������г�ģʽ  
            {
              CutDisCurt0.Bit.F5_TempSenFault=1 ;         //�ŵ������Ϊ0
              CutChaCurt0.Bit.F7_TempSenFault=1 ;        //����������Ϊ0
              g_PowerOffFlag=1;               //��Ҫ�µ�ķ�4�����ϱ�־λ
            }
            if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
            {
              CutDCChaCurt0.Bit.F10_TempSenFault=1 ;      //��������Ϊ0
              g_DCChaPowerOffFlag=1;      //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ
            }
            jj=15;
     }
   return 0;   
} */
//******************************************************************************
//* Function name:  CellVoltageUnbalance
//* Description:    �����ѹ��������� 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void CellVoltageUnbalance(void)
{
 
  
    unsigned char Error[5]={0};
    unsigned char i;
    unsigned char Level=0;

    //�ϱ����ϵȼ�
    Level=CellVoltageUnbalance_step(g_CellHighestVol,g_CellLowestVol);
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    BMS7_Byte3.Bit.F5_7_CellVolUnbalAlarm = Level; //i�����ϱ��� 
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
    if(Level!=0) 
    {
        BMS1_Byte6.Bit.F2_CellVolUnbal = 1; //i�����ϱ���
    } 
    else
        BMS1_Byte6.Bit.F2_CellVolUnbal = 0; //i�����ϱ���
     //1������
    Can554Byte3.Bit.F2_CellVolUnbal1=Error[1];     //�ڲ�CAN
        
    //2������  
    Can554Byte1.Bit.F2_CellVolUnbal2=Error[2] ;      //�ڲ�CAN
    CutDisCurt50.Bit.F3_CellVolUnbal2=Error[2] ;   //�ŵ������Ϊ50%
    CutChaCurt50.Bit.F3_CellVolUnbal2=Error[2];   //�س併Ϊ50%
    CutDCChaCurt50.Bit.F2_CellVolUnbal2=Error[2] ;   //��������Ϊ50%        
    
}

//******************************************************************************
//* Function name:    CellTemperatureUnbalance
//* Description:    �����¶Ȳ�������� 
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
    
    
    //�ϱ����ϵȼ�
    Level=CellTemperatureUnbalance_step(Tmp_H,Tmp_L);
    for(i=1;i<5;i++)
        if(i==Level)
            Error[i]=1;
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
    BMS7_Byte3.Bit.F2_4_CellTempUnbalAlarm = Level; //i�����ϱ��� 
    if(Level!=0) 
    {
        BMS1_Byte6.Bit.F3_CellTempUnbal = 1; //i�����ϱ���
    } 
    else
        BMS1_Byte6.Bit.F3_CellTempUnbal = 0; //i�����ϱ���
        
    //1������
    Can554Byte3.Bit.F3_CellTempUnbal1=Error[1];     //�ڲ�CAN

    //2������  
    Can554Byte1.Bit.F3_CellTempUnbal2=Error[2] ;  //�ڲ�CAN
    CutDisCurt50.Bit.F4_CellTempUnbal2=Error[2] ;   //�ŵ������Ϊ50%
    CutChaCurt50.Bit.F4_CellTempUnbal2=Error[2];   //�س併Ϊ50%
    CutDCChaCurt50.Bit.F3_CellTempUnbal2=Error[2] ;   //��������Ϊ50%        
     //3������
    fault_pc552_Byte5.Bit.F3_CellTempUnbal3 =Error[3];  //�ڲ�CAN
    CutDisCurt0.Bit.F13_CellTempUnbal3=Error[3] ;   //�ŵ������Ϊ0
    CutChaCurt0.Bit.F14_CellTempUnbal3=Error[3];   //�س併Ϊ0if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
    CutDCChaCurt0.Bit.F12_CellTempUnbal3=Error[3] ;   //��������Ϊ0
   
}

//******************************************************************************
//* Function name:    SOCLow
//* Description:      SOC���͹���  �г�
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
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ  
    BMS7_Byte5.Bit.F5_7_SOCLowAlarm = Level; //i�����ϱ��� 
    if(Level!=0) 
    {
        BMS1_Byte5.Bit.F3_SOCLow = 1; //i�����ϱ���
    } 
    else
        BMS1_Byte5.Bit.F3_SOCLow = 0; //i�����ϱ���
        
    Can554Byte3.Bit.F1_SOCLow1=Error[1];     //�ڲ�CAN
        
    //2������  
    Can554Byte1.Bit.F1_SOCLow2=Error[2] ;  //�ڲ�CAN
           
    //3������
    fault_pc552_Byte5.Bit.F1_SOCLow3 =Error[3];    //�ڲ�CAN
    
    
}


//******************************************************************************
//* Function name:    BatteryTemperatureHigh
//* Description:      ����¶ȹ��߹���   
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BatteryTemperatureHigh(void)//
{
    unsigned char i;
    unsigned char Error[5]={0}; 
    unsigned char Level=0; 
    unsigned char LevelError=0;
    
    
    
    //�ϱ����ϵȼ�
    Level=BatteryTemperatureHigh_step(g_BatHighestTemp);
    
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;    
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
    BMS7_Byte4.Bit.F5_7_BatTempHighAlarm=Level;     //i������  
    if(Level!=0) 
    {
      BMS1_Byte5.Bit.F6_BatTempHigh = 1; //i�����ϱ��� 
    } 
    else
      BMS1_Byte5.Bit.F6_BatTempHigh = 0; //i�����ϱ��� 

    //1������
    Can554Byte2.Bit.F5_BatTempHigh1=Error[1];     //�ڲ�CAN
      
    //2������  
    Can554Byte0.Bit.F5_BatTempHigh2=Error[2] ;  //�ڲ�CAN
    CutDisCurt50.Bit.F7_BatTempHigh2=Error[2] ;   //�ŵ������Ϊ50% 
    CutChaCurt50.Bit.F7_BatTempHigh2=Error[2];   //�س������Ϊ50%	
    CutDCChaCurt50.Bit.F4_BatTempHigh2=Error[2] ;   //��������Ϊ50%       
     //3������
    fault_pc552_Byte4.Bit.F5_BatTempHigh3 =Error[3];  //�ڲ�CAN
    CutDisCurt0.Bit.F14_BatTempHigh3=Error[3] ;   //�ŵ������Ϊ0
    CutChaCurt0.Bit.F15_BatTempHigh3=Error[3];   //�س併Ϊ0
    CutDCChaCurt02.Bit.F1_BatTempHigh3=Error[3] ;   //��������Ϊ0
    //4������
    fault_pc552_Byte4.Bit.F5_BatTempHigh3=Error[4];    //�ڲ�CAN,4��Ҳ��3������
    CutDisCurt0.Bit.F8_BatTempHigh4=Error[4] ;   //�ŵ������Ϊ0
    CutChaCurt0.Bit.F10_BatTempHigh4=Error[4];   //�س併Ϊ0
    CutDCChaCurt0.Bit.F13_BatTempHigh4=Error[4] ;   //��������Ϊ0
    if(4==Level) 
    {   //�ϱ�����
        if(g_BmsModeFlag == FASTRECHARGING)      //����ǿ��ģʽ
        {
            BMS9_Byte7.Bit.F2_BatChaOverTemp=Error[4] ;     //������
            BMS9_Byte7.Bit.F4_BzerAlarm= Error[4] ;       //����������
        }
    }            
  
}

//******************************************************************************
//* Function name:    BatteryTemperatureLow
//* Description:      ����¶ȹ��͹��� 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BatteryTemperatureLow(void)//
{

    unsigned char i;
    unsigned char Error[5]={0}; 
    unsigned char Level=0;
    
    
    //�ϱ����ϵȼ�
    Level=BatteryTemperatureLow_step(g_BatLowestTemp);
    BMS7_Byte4.Bit.F2_4_BatTempLowAlarm=Level;     //i������ 
    for(i=1;i<5;i++) 
       if(i==Level) 
           Error[i]=1;
    g_FlagLevel=(g_FlagLevel>Level?g_FlagLevel:Level);   //���ϵȼ���־λ
       
     //1������
    Can554Byte2.Bit.F6_BatTempLow1=Error[1];     //�ڲ�CAN
    
    
    //2������  
    Can554Byte0.Bit.F6_BatTempLow2=Error[2] ;  //�ڲ�CAN
           
    //3������
    fault_pc552_Byte4.Bit.F6_BatTempLow3 =Error[3];  //�ڲ�CAN
    
    //4������
    fault_pc552_Byte4.Bit.F6_BatTempLow3=Error[4];    //�ڲ�CAN,4��Ҳ��3������
    CutDisCurt0.Bit.F9_BatTempLow4=Error[4] ;   //�ŵ������Ϊ0
    CutChaCurt0.Bit.F11_BatTempLow4=Error[4];   //�س併Ϊ0 
    CutDCChaCurt0.Bit.F14_BatTempLow4=Error[4] ;   //��������Ϊ0            

}
//******************************************************************************
//* Function name:   SOCSaltus
//* Description:     SOC����
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
        BMS7_Byte5.Bit.F3_4_SOCSal=1;   // SOC���䱨��
    } 
    SOCBefore=SOCNow;    
}

*/
//******************************************************************************
//* Function name:   ChargeCurrentDirectionAnomaly
//* Description:     �����������쳣
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
            CutDCChaCurt02.Bit.F3_ChaCurDirAno=1; //�����������쳣����������Ϊ0
            g_FlagLevel=4;                   //���ϵȼ���־λ
            ChaCurDirAnly=1;                //�����������쳣��־λ
            if(Check_Num>=250) //���������100�Σ����㷨Ҫ������µ硣
                Check_Num=100;
        }
    }
}

//**********************************************************************
//* Function name:   CarFaultDone
//* Description:     �г������й��ϵĴ���
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void CarFaultDone()
{
    if( (4 == BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm)//�ܵ�ѹ��ѹ
    || (4 == BMS7_Byte0.Bit.F2_4_TotalVolUnderVolAlarm) // �ܵ�ѹǷѹ
    || (1 == BMS7_Byte0.Bit.F0_WithLECUComAlarm)     //�ڲ�ͨ�Ź���
    || (4 == BMS7_Byte1.Bit.F5_7_DisChaOverCurAlarm)   //�ŵ����
    || (4 == BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm)     //������
    || (4 == BMS7_Byte2.Bit.F5_7_CellOverVolAlarm)     //�����ѹ
    || (4 == BMS7_Byte2.Bit.F2_4_CellUnderVolAlarm)    //����Ƿѹ
    || (1 == BMS7_Byte2.Bit.F1_CurSenFault)        //��������������
    || (4 == BMS7_Byte4.Bit.F5_7_BatTempHighAlarm)  //�¶ȹ���
    || (4 == BMS7_Byte4.Bit.F2_4_BatTempLowAlarm))  //�¶ȹ���
    {
        g_PowerOffFlag=1;      //�г�ģʽ����Ҫ�µ�Ĺ���
    } 
}

                
//******************************************************************************
//* Function name:   BMSProtect
//* Description:     BMS���ı���,����״̬�����ƣ�ǿ�ƶϸ�ѹ
//* EntryParameter : None
//* ReturnValue    : Bool���� 0-�ޣ�1-��
//******************************************************************************
void BMSProtect(void)//�з��գ����OffState�ж�ʧ��,�����ʵ�ʵ�ѹ�Ƚ�********** 
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
                TurnOff_INFK();//�Ͽ��ŵ縺�̵���
                delay(25000); //19ms
                TurnOff_INA2K();//��縺�Ͽ�
                
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
                TurnOff_INFK();//�Ͽ��ŵ縺�̵���
                delay(25000); //19ms
                TurnOff_INA2K();//��縺�Ͽ�
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
                TurnOff_INFK();//�Ͽ��ŵ縺�̵���
                delay(25000); //19ms
                TurnOff_INA2K();//���̵���
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
            TurnOff_INFK();//�Ͽ��ŵ縺�̵���
            delay(25000); //19ms
            TurnOff_INA2K();//���̵���
        }
    } 
    else
    {
        HTDelaytime=0;
    } 
  
}



//******************************************************************************
//* Function name:   FaultLevelProcess
//* Description:     ���ϵȼ�����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void FaultLevelProcess(void)
{    
    if(g_FlagLevel!=0)
        BMS7_Byte7.Bit.F0_BatState=1;         //�������״̬����
    else 
        BMS7_Byte7.Bit.F0_BatState=0;         //�������״̬����

    if(g_FlagLevel==4)
    {      
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=4;      //��ع��ϵȼ�4�� 
        BMS5_Byte4.Bit.F4_CutMainCtor=1;         //���󡰶Ͽ����Ӵ�����
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=1;  //ǿ�ƽ�����
        BMS5_Byte4.Bit.F5_ForceStopMode=1;       //ǿ��ͣ��ģʽ 
        
        if(g_BmsModeFlag == FASTRECHARGING) 
        {
            g_DCChaPowerOffFlag=1;       //���ģʽ����Ҫ�µ�Ĺ���
            if(WithEVCUComOverTime==2)
            {
                g_DCChaPowerOffFlag=0;   //���ģʽ����EVCUͨ�Ź��ϵ����жϣ�ֻ�жϳ�ʱ��־λ
            }
        }
    } 
    else if(g_FlagLevel==3) 
    {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=3;      //��ع��ϵȼ�3��
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=1;  //ǿ�ƽ�����
        BMS5_Byte4.Bit.F5_ForceStopMode=1;       //ǿ��ͣ��ģʽ 
    }
     else if(g_FlagLevel==2) 
     {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=2;      //��ع��ϵȼ�2��
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=1;  //ǿ�ƽ�����
        BMS5_Byte4.Bit.F5_ForceStopMode=0;       //ǿ��ͣ��ģʽ 
     }
     else if(g_FlagLevel==1) 
     {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=1;      //��ع��ϵȼ�1��
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=0;  //ǿ�ƽ�����
        BMS5_Byte4.Bit.F5_ForceStopMode=0;       //ǿ��ͣ��ģʽ  
     }
     else if(g_FlagLevel==0) 
     {
        BMS1_Byte6.Bit.F4_6_BatFaultLevel=0;      //��ع��ϵȼ�0��
        BMS5_Byte4.Bit.F6_ForceDownPowerMode=0;  //ǿ�ƽ�����
        BMS5_Byte4.Bit.F5_ForceStopMode=0;       //ǿ��ͣ��ģʽ 
     }
     if(CutDisCurt0.word != 0) 
     { 
        CutDischaTo0 = 1;     //�ŵ�Ϊ0
     } 
     else 
     { 
        CutDischaTo0 = 0;     //�ŵ�Ϊ0
     }
     
     
     if(CutDisCurt50.word != 0) 
     { 
        CutDischaTo50 = 1;     //�ŵ�Ϊ50%
     } 
     else 
     { 
        CutDischaTo50 = 0;     //�ŵ�Ϊ50%
     }
     
     
     if(CutChaCurt0.word != 0) 
     { 
        CutFebchaTo0 = 1;    //����Ϊ0
     } 
     else 
     { 
        CutFebchaTo0 = 0;    //����Ϊ0
     }
     
     
     if(CutChaCurt50.word !=0 ) 
     { 
        CutFebchaTo50=1;    //����Ϊ50%
     } 
     else 
     {
        CutFebchaTo50=0;    //����Ϊ50%
     }
     if((g_RelayPowerOffFault==0)) //����̵���û�й���
        g_FlagLevel=0;       //����֮��ָ�Ϊ0
}


//******************************************************************************
//* Function name:    FaultProcess
//* Description:      �����ֹ���: ����4������Ϊ�����ع���
//* EntryParameter : None
//* ReturnValue    : ���޹��ϣ�0-�ޣ�1-��
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
      TotalVoltageOverVoltage();   //�ܵ�ѹ��ѹ
    }
    
    if(g_BmsModeFlag == DISCHARGING) 
    {
        if((stateCode>14)&&(stateCode<46)) 
        {
          TotalVoltageUnderVoltage(); //�ܵ�ѹǷѹ  
        }
        CellUnderVoltage();      //����Ƿѹ
        DischargeOverCurrent();   //�ŵ����
        SOCLow();            //SOC��
        
    }
    
    if(g_BmsModeFlag == FASTRECHARGING) 
    {
        WithDCChargerCommunicationFault(); //��ֱ������ͨ�Ź��ϣ�������ʱ���ϣ�
        ChargeCurrentDirectionAnomaly();//�����������쳣
        
    }
    
    WithDCChargerCommunicationFault(); //��ֱ������ͨ�Ź��ϣ�������ʱ���ϣ�
    InternalCommunicationFault();       //�ڲ�ͨ�Ź���    
    WithEVCUCommunicationFault();     //EVCUͨѶ����
    CurrentSensorFault();            //��������������
    
    ChargeOverCurrent();      //������
    CellOverVoltage();       //�����ѹ
    CellVoltageUnbalance();   //�����ѹ������
    CellTemperatureUnbalance();//�����¶Ȳ�����
    BatteryTemperatureHigh();  //�����¶ȹ���
    BatteryTemperatureLow();  //�����¶ȹ��� 
  
    //CarFaultDone();       //�г������й��ϵĴ���
    FaultLevelProcess();     //���ϵȼ�����  
    BMSProtect();     ////////BMS���ϼ̵���
    
    //*****************************************************************************************
    //******************************************************************************************
    ////////////��������֮ǰ��ȣ�û�б仯ʱ�������д洢��ֻ��1���ӲŴ洢������и��£��Ž��д洢
    if((caution1^g_caution_Flag_1)||(caution2^g_caution_Flag_2)||(caution3^g_caution_Flag_3)||(caution4^g_caution_Flag_4))
        StoreSysVariable();//����SOCֵ�͹�����Ϣ
    caution1 =  g_caution_Flag_1;
    caution2 =  g_caution_Flag_2;
    caution3 =  g_caution_Flag_3;
    caution4 =  g_caution_Flag_4;
    //////////////////////////////////////////////////////////////////
    ////Caution_Flag_4��Bit 0����ѹĸ�����ӹ��ϣ�Bit 1����������ϣ�    
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