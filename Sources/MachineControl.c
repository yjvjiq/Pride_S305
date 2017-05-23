//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : MachineControl.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : 该文件用于状态转移判断
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h" 
unsigned char HighVolPowerOff = 0;//高压直接下电2.5s之后
unsigned char OffState=0;//发送高压下电请求

unsigned char ChangerINError = 2; //充电机ChanerIN信号突然没有:0:有ChanerIN信号;1:无ChangerIN信号;2：不确定
unsigned char State177End=0;//不停在177状态,

//******************************************************************************
//* Function name:   stateCodeTransfer
//* Description:     在系统工作期间时刻检测当前信号，若没信号了，需要下电,5ms调用一次
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void stateCodeTransfer(void) 
{
    S223_StateMachine_TaskControl();
    /*static unsigned int Delay30=0;
    static unsigned int DisChangerDelay=0;
    static unsigned int Delay110=0;
    static unsigned int Delay170=0;
    static unsigned int Delay126=0;
    static unsigned int Delay186=0;
    static unsigned int FiveTimes=0;
    if(State177End==1)//在177状态下将变量State177End置1
    {
        stateCode=179;//调试模式
        return;
    }
    else if(TestState==1)
    {
        stateCode=177;//关闭继电器状态
        return;
    }
    if(g_BmsModeFlag == DISCHARGING)//行车
    {
        if(stateCode==10)           //状态10
        {   
            if(g_RelayPowerOffFault == 0) //高低压互锁故障
            {
              stateCode=11;
            }
            else {
              stateCode=47;
            }
        }
        else if(stateCode==11)          //状态11
        {  
            if((g_FlagLevel==4)||(g_PowerOffFlag==1)||(g_ACC_ON==0))//如果继电器下电故障,4级故障，ON档为0
            {
                stateCode=47;
            }
            else 
            {
              stateCode=12;
            }
        }
        else if(stateCode==12)
        {      ////放电负、充电负极继电器粘连           或者MSD故障     4级故障      需要下电的非4级故障     ON档为0   
            if((g_DischaNRelayAdin==1)||(g_ChaNRelayAdin==1)||(g_MSDFault==1)||(g_FlagLevel==4)||(g_PowerOffFlag==1)||(g_ACC_ON==0)) 
            {
                stateCode=46; 
            }
            else if((g_BMSSelfCheckCounter==1)&&(g_ACC_ON==1)&&(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==1))//收到VCU发送的高压上电命令&&自检计数器==1&&ON==1
            {
                stateCode=14;
            }
        }
        else if(stateCode==14)
        {
            if((g_FlagLevel==4)||(g_ACC_ON==0)||(g_PowerOffFlag==1))//需要下电的故障||ON==0
            {
              stateCode=44;
            }
            else if(g_ACC_ON==1) 
            {
              stateCode=17;
            }
        }
        else if(stateCode==17)
        {
            if((g_DischaNRelayDiscon==1)||(g_FlagLevel==4)||(g_PowerOffFlag==1)||(g_ACC_ON==0) )//负极继电器断路，需要下电的故障||ON==0
            {
              stateCode=44; 
            }
            else if((g_BMSSelfCheckCounter==2)&&(g_ACC_ON==1)) 
            {
              stateCode=30; 
            }
        }
        else if(stateCode==30)
        {    
            
            else if((WithEVCUComOverTimeFlag==1)&&(Delay5s3>=5000)) 
            {
                stateCode=44; 
                Delay5s3=0;
            }
            else if(((Delay10s>=10000)&&(g_PowerOffFlag==1))||(g_ACC_ON==0)||(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==2))//需要下电的故障||ON==0 收到VCU发送的断开放电负命令
               {
                stateCode=44; 
                Delay10s=0;
               }
        }   
        else if(stateCode==44)//断开放电负极继电器
        { 
            if(BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb==2)  //负极继电器已断开
            {
              stateCode=46;
            }
        } 
        else if((stateCode==46))
        {
            if((g_DischaNRelayAdin==1)||(g_FlagLevel==4)||(g_RelayPowerOffFault==1)||(g_PowerOffFlag==1)||(g_ACC_ON==0)) //放电负极粘连或者满足因故障下电或者常电无)
            {
                stateCode=47;  
            } 
            else if((g_DC_CC2==1)) //若CC2=1
            {
                InitialSoc();//SOC计算方式变化
                g_BmsModeFlag = FASTRECHARGING;
                stateCode = 141;
            } 
            
            else if((g_ACC_ON==1)&&(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==1)) //ON=1且收到整车放电负闭合指令
            {
                if(FiveTimes>=5) 
                {
                    stateCode=47;
                } 
                else 
                {
                    stateCode=11;
                    FiveTimes++;
                }
            }
        } 
        else if(stateCode==47)
        {           
            stateCode=48; 
        }
    }
    
    else if(g_BmsModeFlag==FASTRECHARGING)//快充
    {
        if(stateCode==140)
        {   
            if(g_RelayPowerOffFault == 0)
            {              
                if(input6_state()==0) //高低压互锁故障  ChargerIN=1
                {
                  stateCode=141;
                }
            }
            else 
            {
              stateCode=187;
            }
        }
        else if(stateCode==141)
        {

            if((g_DischaNRelayAdin==1)||(g_ChaNRelayAdin==1)||(g_MSDFault==1)||(g_RelayPowerOffFault == 1) //正负继电器粘连，MSD故障，高低压互锁故障
            ||(g_FlagLevel==4)||(g_DCChaPowerOffFlag==1)||(g_DC_CC2==0)||(ChangerINError==1)//4级故障，其他下电故障，CC2=0,ChargerIN=0
            ) 
            {
              stateCode=187; 
            }
            else if((g_DC_CC2 == 1))   //自检计数器=1且CC2=1                    
               {
                stateCode=142; 
               }
        }
        else if(stateCode==142)
        {
            if((g_ChaNRelayAdin==1)||(g_MSDFault==1)||(g_ChaNRelayDiscon==1)||(g_FlagLevel==4)||(g_DCChaPowerOffFlag==1)||(g_DC_CC2==0)||(ChangerINError==1)
            ||(g_CellHighestVol>=HIGHEST_ALLOWED_CHARGE_CV)||(Tavg>=54+40))//4级故障，其他下电故障，CC2=0,ChargerIN=0
            {                  
                stateCode=184;
            }
            else if((g_BMSSelfCheckCounter==2)&&(g_DC_CC2==1)&&(ChangerINError==0))//自检计数器=2且CC2=1且ChangerIN=1
            {
                stateCode=144; 
            }
        } 
        else if(stateCode==144)
        {
            if((g_FlagLevel==4)||(g_DCChaPowerOffFlag==1)||(g_DC_CC2==0)||(ChangerINError==1))//4级故障，其他下电故障，CC2=0,ChargerIN=0)
            {
              Delay186++;
              if(Delay186>=180) 
              {
                  stateCode=180;
              }
            }
            else if((EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1==1)&&(g_DC_CC2==1)&&(ChangerINError==0)&&(DC_Start == 1))//收到充电正已经闭合&&CC2==1&&ChargeIN==1,CRM完成，握手准备完毕DC_Start = 1
            {
              stateCode=170;
            }
        }
        else if(stateCode==170)
        {
            if(FastEndNormalFlag==1) 
            {
                Delay170++;
                if(Delay170>400)  //延时大约6*400=2.4s
                {
                    stateCode=180;
                    Delay170=0; 
                }
            }
            if((g_DC_CC2==0)||(ChangerINError==1)||((OffState==1))&&(Delay5s2>5000))//4级故障，其他下电故障，CC2=0,ChargerIN=0)
            {                
                Delay5s2=0;
                stateCode=180;  
                if(WithEVCUComOverTimeFlag==2) 
                {
                    stateCode=184;
                }
            }   
        } 
        else if(stateCode==180)
        {
            if(FastEndNormalFlag==1) 
            {
                stateCode = 184;
            } 
            else if(((g_DC_CC2==0)||(ChangerINError==1))&&(Delay5s1 > 2500)) 
            {
                stateCode = 184;
                Delay5s1=0;
            }
            else if(EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1==2) //收到EVCU充电正断开指令
            {
                stateCode = 184;
            }
            else if((EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1!=2)&&(Delay5s1 > 5000) )
            {
                stateCode = 184;
                Delay5s1=0;
            }
        } 
        else if(stateCode==184)
        {
            if(BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1==2)//充电负状态反馈断开
            {
                stateCode=186;
            }
        } 
        else if(stateCode==186)
        {
            
            if((g_BMSSelfCheckCounter == 1)) 
            {                
                stateCode=187; 
            }
            else if(g_ChaNRelayAdin == 1)
            {   
                stateCode=187;
            }
        } 
        else if(stateCode==187)
        {
            stateCode=188; 
        }
   
    }  */
}

//*************************************************************************
//**************************the end *********************************************
//************************************************************************************
//******************************************************************************************