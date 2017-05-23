//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : Machine.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : 该文件用于项目的状态机策略处理
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h" 

//******************************************************************************
//******************************************************************************
//******************************************************************************

unsigned int tmr_p1 =0;
unsigned int tmr_p2 =0;
unsigned int tmr_p3 =0;
unsigned int tmr_p4 =0;
unsigned int tmr_p5 =0;
unsigned long Delay5s1 = 0;  //延时5s计时
unsigned long Delay5s2 = 0;  //延时5s计时
unsigned long Delay5s3 = 0;  //延时5s计时
unsigned long Delay10s = 0;  //延时10s计时
unsigned long Delay60s = 0;  //延时60s计时
unsigned char g_ACC_ON=0;              //ON档  1是ON，0是OFF
unsigned char g_MSDFault=0;                 //MSD故障

unsigned char g_ChaNRelayAdin=0;        //充电负极继电器粘连
unsigned char g_ChaNRelayDiscon=0;       //充电负极继电器断路

unsigned char g_DischaNRelayAdin=0;        //放电负极继电器粘连
unsigned char g_DischaNRelayDiscon=0;       //放电负极继电器断路

unsigned char g_PreChaRelayAdin=0;     //预充继电器粘连
unsigned char g_PRelayAdin=0;          //正极继电器粘连
unsigned char g_PreChaRelayDiscon=0;  //预充继电器断路
unsigned char PreChaResiDiscon=0;       //预充电阻断路
unsigned char g_PreChaFailed=0;             //预充电失败
//unsigned char SelfCheck = 0;              //BMS自检结果: 2,未通过;1通过(预充继电器是否成功断开)
unsigned char g_RelayPowerOffFault = 0;     //继电器下电故障 高低压互锁 0无 1有        

//******************************************************************************
//* Function name:   VehiclePowerOffLogic
//* Description:     BMS发生故障，下电
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void VehiclePowerOffLogic(void)  //S223项目没有使用
{
    static unsigned char OffFlag=0;
    static unsigned char count=0;
    
    TurnOff_INZK();//断开正极接触器 
    turnOffSW_Power();//关闭电源开关彻底断电
}
//******************************************************************************
//* Function name:   closeNegRelay
//* Description:     闭合主负继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void closeNegRelay(void) //闭合放电负
{
    TurnOn_INFK();                 //to pc
    
   
}
//******************************************************************************
//* Function name:   openNegRelay
//* Description:     断开主负继电器   
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void openNegRelay(void) 
{
    TurnOff_INFK();//断开放电负继电器
    
    //g_DischaNRelayDiscon=1;   //放电负已断开标志

}
//******************************************************************************
//* Function name:   openPosRelay
//* Description:     断开主正继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void openPosRelay(void) 
{
    TurnOff_INZK();//断开主正继电器
    delay(25000); //20ms
    TurnOff_INBK();//断开预充电继电器
    delay(25000); //20ms

}
 */
//******************************************************************************
//* Function name:   GetTavg
//* Description:     充放电功率参考的温度取值
//* EntryParameter : 最高温度，最低温度
//* ReturnValue    : Tavg
//******************************************************************************
/*unsigned char GetTavg(unsigned char LowTem,unsigned char HighTem)  //S223项目没有使用
{
    unsigned char Tavg1;

    if((LowTem>10+40)&&(HighTem>=55+40))
        Tavg1=HighTem;
    
    else if((LowTem>10+40)&&(HighTem<55+40)) //测试完需要放开
        Tavg1=g_averageTemperature;
    
    else if(LowTem<=10+40) 
        Tavg1=LowTem;
    
    return Tavg1;

}  */
//******************************************************************************
//* Function name:   GetTavgProcess
//* Description:     充放电功率参考的温度取值
//* EntryParameter : 最高温度，最低温度
//* ReturnValue    : Tavg
//******************************************************************************
void GetTavgProcess(void)  
{

    static unsigned char timer1,timer2; 
    if(g_BatHighestTemp>45+40)//若是最高温度大于45度，那么平均温度为最高温度
    {
      
        timer1++;
        timer2=0;
        if(timer1>7)//300ms*7=2100ms
        {
            Tavg=g_BatHighestTemp;
            timer1=0;
            
        }
    } 
    else if(g_BatHighestTemp<=45+40)
    {     
        timer2++;
        timer1=0;
        if(timer2>7) 
        {
            Tavg=g_BatLowestTemp;
            timer2=0;
        } 
    }
 

}
//******************************************************************************
//* Function name:   HighVoltDetectPart1
//* Description:     整车state机制上电步骤1：状态机编码12/46 ,142/184 
//              MSD断路故障检测,放电负极继电器粘连检测
//* EntryParameter : None    检测周期5ms
//* ReturnValue    : None
//******************************************************************************
/*void HighVoltDetectPart1(void) 
{
    static unsigned char tt=0;
    static unsigned char pp=0;
    static unsigned char ww=0;
    static unsigned char state12=0;
    static unsigned char state142=0;
    
    if(tmr_p1<=350)//350ms内 该时间在1ms中断里计数，目的是让时间准确，如果放在这里计数，则可能因为其它程序影响了时间准确性
    {
        
        //高压互锁检测；若为高电平，说明高压连接异常,高压互锁状态=1
        if(inputH_state()) 
        {
            BMS7_Byte6.Bit.F6_7_HighVolLock=1;  //整车CAN高压互锁报警
            g_FlagLevel=4;   //整车CAN故障等级4级报警
            g_RelayPowerOffFault = 1;        //有故障
        } 
        else 
        {
            BMS7_Byte6.Bit.F6_7_HighVolLock=0;  //整车CAN高压互锁报警
        }
        
        //**************检测MSD*****************************
        if(g_BatSysTotalVolV1<100) 
        {                       
            tt++;   
            if(tt>=12)//60ms才能判断出来
            {
                g_RelayPowerOffFault = 1;//继电器下电故障
                g_MSDFault = 1;       //MSD断路故障
                fault_pc552_Byte7.Bit.F0_MSDDisconFault=1;//内部CAN  MSD断路故障
                g_FlagLevel=4;   //整车CAN故障等级4级报警
                tt=13;
            }
        } 
        else   
        {
            tt=0; 
            
        }
        if(g_BmsModeFlag == DISCHARGING)        //如果是行车模式   
        {   
            if(g_BatSysTotalVolV2>300)//放电负极粘连
            {
                ww++;
                if (ww>=12)//60ms才能判断出来
                {
                    g_RelayPowerOffFault = 1;//继电器下电故障
                    fault_pc552_Byte7.Bit.F1_NRelayAdinFault=1; //内部CAN上报放电负粘连
                    BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=3;//整车CAN  放电负粘连 闭合
                    g_FlagLevel=4;   //整车CAN故障等级4级报警
                    BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //蜂鸣器报警
                    g_DischaNRelayAdin = 1;   //放电负粘连
                    ww = 13;
                }            
            } 
            else 
            {
                ww=0;
                state12++;
                if(state12>=12) 
                {
                    state12=0;
                    g_BMSSelfCheckCounter=1;  //自检计数器  
                }
            }
        }
        
        //********检测充电负继电器粘连 ****************
        if(g_BmsModeFlag == FASTRECHARGING) 
        {

            if(g_BatSysTotalVolV3>=300) //(V2>=0.6*g_BatSysTotalVolV1))
            {
                pp++; 
                if(pp>=12)
                {
                    /////////////////充电负继电器粘连///////////////////
                    g_RelayPowerOffFault = 1;//继电器下电故障
                    fault_pc552_Byte7.Bit.F1_NRelayAdinFault=1;  //内部CAN上报充电负粘连 闭合
                    BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=3;//整车CAN  充电负粘连 闭合
                    g_FlagLevel=4;   //整车CAN故障等级1级报警
                    BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //蜂鸣器报警
                    BMS9_Byte7.Bit.F0_ChaCtorAdin1=1;   //充电负粘连
                    g_ChaNRelayAdin = 1;   //充电负粘连
                    pp=13;
                    /////////////////充电负继电器粘连////////////////////
                }
            }
            else 
            {
                pp=0;
                g_BMSSelfCheckCounter=1;  //自检计数器  
                
            } 
        }
    }
    else  //需要350ms之后
    {
      
        if((g_MSDFault==0)&&(g_DischaNRelayAdin==0)&&(g_ChaNRelayAdin==0))
        {
            g_BMSSelfCheckCounter=1; //正常状态 
        } 
    }

}
//******************************************************************************
//* Function name:   HighVoltDetectPart2
//* Description:     高压检测：状态机编码17/44 142/184负极继电器断路检测 
//* EntryParameter : None
//* ReturnValue    : None                     
//******************************************************************************
void HighVoltDetectPart2(void)
{    
    
    static unsigned char PConnect_tt=0;
    static unsigned char ccc=0;
    static unsigned char state17=0;
    static unsigned char state142=0;

    if(g_BmsModeFlag == DISCHARGING)        //如果是行车模式   
    {  
        if(tmr_p3<60)
            return ;
        if(g_BatSysTotalVolV2<100)  //V2＜100V，持续60ms,放电负极继电器断路
        {
            PConnect_tt++;
            if (PConnect_tt>=12)//持续60ms
            {
                g_RelayPowerOffFault = 1;//继电器下电故障
                fault_pc552_Byte7.Bit.F2_NRelayDisconFault=1;  //内部CAN上报放电负极继电器断路 断开
                g_FlagLevel=4;   //整车CAN故障等级1级报警
                g_DischaNRelayDiscon = 1;   //放电负极继电器断路 
                PConnect_tt = 13;
            }            
        }
        else//无故障
        {
            state17++;
            PConnect_tt=0;
            if(state17>=12) 
            {
                state17=0;
                g_BMSSelfCheckCounter=2; //正常状态 
                

            }            
            //delay(25000); //20ms
            
        }
    } 
    if(g_BmsModeFlag == FASTRECHARGING) 
    {
        if(tmr_p3<60)
            return ;
        if(g_BatSysTotalVolV3<100)    //充电负断路检测
        {
            ccc++;
            if(ccc>=12) 
            {
                g_RelayPowerOffFault = 1;//继电器下电故障
                fault_pc552_Byte7.Bit.F2_NRelayDisconFault=1;  //内部CAN上报放电负极继电器断路 断开
                g_ChaNRelayDiscon = 1;     //充电负极继电器断路
                g_FlagLevel=4;   //整车CAN故障等级1级报警
               // state_pc552_Byte1.byte |=0x01;//充电负极继电器状态闭合    to pc
               ccc=13; 
                 
            }   
        }
        else
        {
            delay(25000); //20ms
            ccc=0; 
            state142++;
            if(state142>=12) 
            {
              state142=0;
              g_BMSSelfCheckCounter=2;//没有故障，自检计数器
              g_DischaNRelayDiscon=0; //负极继电器断路
            }
             
        }
  
    }
}
//******************************************************************************
//* Function name:   HighVoltDetectPart3
//* Description:     整车state机制上电步骤3：状态机编码20/90
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void HighVoltDetectPart3(void) 
{      
    static unsigned char tt=0;
    static unsigned char tm=0;
    
    TurnOff_INHK();//断开加热继电器,预充前关闭加热继电器，以免影响预充
    if(preChargeON==0) 
    {
        preChargeON=1;
        TurnOn_INBK();//闭合预充继电器
        //state_group1.Bit.St_Pre_Relay=1;  //预充继电器状态  for VCU
        //state_group4.Bit.St_Precharge=1;  //预充电过程中    for VCU
        delay(20000); //20ms
        tmr_p3=0;
        prechargeFinished=0;
        tt=0;
    }
    if(tmr_p3<=60)  //延时60ms
       return;
    
    if(tmr_p3<=1000) 
    {
        if(prechargeFinished==0) 
        {
            
            if((g_BatSysTotalVolV3 <= 100)&&(g_BatSysTotalVolV2>=200))//防止负载短路，如果负载短路，V3会很小,如果V2也小，则外部短路 
            {            
                tt++;
                if(tt>=10)//滤波50ms 
                {  
                    g_RelayPowerOffFault = 1;//继电器下电故障
                    tt=11;
                    state_group1.Bit.St_N_Relay=0;  //to vcu
                  //  g_caution_Flag_4 |=0x04;        //to PC
                    state_pc552_Byte1.byte &= 0xfe;            //负极继电器状态   open    to pc                   
                    TurnOff_INBK();                 //断开预充电继电器
                    state_group1.Bit.St_Pre_Relay=0;  //预充继电器状态  for VCU
                    delay(25000);                   //20ms？为什么要延时
                    g_DischaNRelayDiscon = 1;         //负极继电器断路
                }
                                         
            } 
            else 
            {   
                tt=0;
                if((g_BatSysTotalVolV3>g_BatSysTotalVolV1*0.95)&&(prechargeFinished==0))//没有故障 
                {
                    TurnOn_INZK();//闭合主正继电器
                    state_group1.Bit.St_P_Relay=1;//to vcu
                    delay(25000); //20ms
                    delay(25000); //20ms
                    TurnOff_INBK();//断开预充电继电器
                    state_group1.Bit.St_Pre_Relay=0;  //预充继电器状态  for VCU                    
                    prechargeFinished =1;  //预充完成标志
                    state_group4.Bit.St_Precharge=2;  //预充电完成    for VCU
                    g_BMSSelfCheckCounter=3; 
                   
                } 
                
            } 
        }
    } 
    else if(tmr_p3>1000) //延时100ms //上电成功后100ms再检测电压，用于判断总正继电器是否有断路。
    {
        if(prechargeFinished==0)//预充电未完成 
        {
            g_RelayPowerOffFault = 1;//继电器下电故障
            prechargeFinished =0;  //预充电未完成
           // g_caution_Flag_4 |=0x80; //to PC
            TurnOff_INBK();//断开预充电继电器
            state_group1.Bit.St_Pre_Relay=0;  //预充继电器状态  for VCU
            g_PreChaFailed = 1; //预充电未完成
            tmr_p3 =1010; // 只要大于400就行    
        }
    }
                   
}

//******************************************************************************
//* Function name:   PreRelayConnectTest
//* Description:     预充继电器粘连故障：在State=13,83,143时检测，断开后,开是否粘连
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void PreRelayConnectTest(void)
{
    static unsigned char pred=0;
    if(tmr_p4<60)
        return;
    
    if(g_BatSysTotalVolV2>=200) 
    {
        pred++;
        if(pred>=12) 
        {
            g_RelayPowerOffFault = 1;//继电器下电故障
            g_PreChaRelayAdin = 1;
            //state_group1.Bit.St_Pre_Relay=1;  //预充继电器状态  for VCU
            state_pc552_Byte1.byte |=0x08;//预充继电器状态闭合    to pc
           // g_caution_Flag_4 |=0x10; //to PC预充或正极粘连
            pred=13; 
            SelfCheck = 2; 
        }   
    }
    else
    {
        SelfCheck = 1;
        pred=0;  
    }
}

//******************************************************************************
//* Function name:   DischaNRelayAdjoinTest
//* Description:     放电负粘连检测：在State=46时检测
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void DischaNRelayAdjoinTest(void)
{
    static unsigned char pd=0;    
    static unsigned char state46=0;
    if(tmr_p5<60)
        return; 
    if(g_BatSysTotalVolV2>300)//放电负极粘连
    {
        pd++;
        if (pd>=12)//60ms才能判断出来
        {
            g_RelayPowerOffFault = 1;//继电器下电故障
            state_pc552_Byte1.byte|=0x01; //内部CAN上报放电负粘连
            BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=3;//整车CAN  放电负粘连 闭合
            g_FlagLevel=4;   //整车CAN故障等级4级报警
            BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //蜂鸣器报警
            g_DischaNRelayAdin = 1;   //放电负粘连
            pd = 13;
         }            
    } 
    else//无故障
    {
        delay(25000); //19ms
        pd=0;  
        state46++;
        if(state46>=12) 
        {
            state46=0;
            g_BMSSelfCheckCounter=1;  //自检计数器  
        }
        
    }
}
//******************************************************************************
//* Function name:   ChaNRelayAdjoinTest
//* Description:     充电负粘连检测：在State=186时检测
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void ChaNRelayAdjoinTest(void)
{
    static unsigned char cn=0;
    static unsigned char state142=0;

    
    if(g_BatSysTotalVolV3>=300) //(V2>=0.6*g_BatSysTotalVolV1))
    {
        cn++; 
        if(cn>=12)
        {
            /////////////////充电负继电器粘连///////////////////
            g_RelayPowerOffFault = 1;//继电器下电故障
            fault_pc552_Byte7.Bit.F1_NRelayAdinFault=1;  //内部CAN上报充电负粘连 闭合
            BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=3;//整车CAN  充电负粘连 闭合
            g_FlagLevel=4;   //整车CAN故障等级1级报警
            BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //蜂鸣器报警
            BMS9_Byte7.Bit.F0_ChaCtorAdin1=1;   //充电负粘连
            g_ChaNRelayAdin = 1;   //充电负粘连
            cn=13;
            /////////////////充电负继电器粘连////////////////////
        }
     }          

    else//无故障
    {
        
        g_BMSSelfCheckCounter=1;  //自检计数器  
        cn=0;  
    }
} 
*/
//***********************************************************************
//************************************************************************
//*************************the end*************************************
//************************************************************************
