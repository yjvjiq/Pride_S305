//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : MachineControl.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : ���ļ�����״̬ת���ж�
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h" 
unsigned char HighVolPowerOff = 0;//��ѹֱ���µ�2.5s֮��
unsigned char OffState=0;//���͸�ѹ�µ�����

unsigned char ChangerINError = 2; //����ChanerIN�ź�ͻȻû��:0:��ChanerIN�ź�;1:��ChangerIN�ź�;2����ȷ��
unsigned char State177End=0;//��ͣ��177״̬,

//******************************************************************************
//* Function name:   stateCodeTransfer
//* Description:     ��ϵͳ�����ڼ�ʱ�̼�⵱ǰ�źţ���û�ź��ˣ���Ҫ�µ�,5ms����һ��
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
    if(State177End==1)//��177״̬�½�����State177End��1
    {
        stateCode=179;//����ģʽ
        return;
    }
    else if(TestState==1)
    {
        stateCode=177;//�رռ̵���״̬
        return;
    }
    if(g_BmsModeFlag == DISCHARGING)//�г�
    {
        if(stateCode==10)           //״̬10
        {   
            if(g_RelayPowerOffFault == 0) //�ߵ�ѹ��������
            {
              stateCode=11;
            }
            else {
              stateCode=47;
            }
        }
        else if(stateCode==11)          //״̬11
        {  
            if((g_FlagLevel==4)||(g_PowerOffFlag==1)||(g_ACC_ON==0))//����̵����µ����,4�����ϣ�ON��Ϊ0
            {
                stateCode=47;
            }
            else 
            {
              stateCode=12;
            }
        }
        else if(stateCode==12)
        {      ////�ŵ縺����縺���̵���ճ��           ����MSD����     4������      ��Ҫ�µ�ķ�4������     ON��Ϊ0   
            if((g_DischaNRelayAdin==1)||(g_ChaNRelayAdin==1)||(g_MSDFault==1)||(g_FlagLevel==4)||(g_PowerOffFlag==1)||(g_ACC_ON==0)) 
            {
                stateCode=46; 
            }
            else if((g_BMSSelfCheckCounter==1)&&(g_ACC_ON==1)&&(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==1))//�յ�VCU���͵ĸ�ѹ�ϵ�����&&�Լ������==1&&ON==1
            {
                stateCode=14;
            }
        }
        else if(stateCode==14)
        {
            if((g_FlagLevel==4)||(g_ACC_ON==0)||(g_PowerOffFlag==1))//��Ҫ�µ�Ĺ���||ON==0
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
            if((g_DischaNRelayDiscon==1)||(g_FlagLevel==4)||(g_PowerOffFlag==1)||(g_ACC_ON==0) )//�����̵�����·����Ҫ�µ�Ĺ���||ON==0
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
            else if(((Delay10s>=10000)&&(g_PowerOffFlag==1))||(g_ACC_ON==0)||(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==2))//��Ҫ�µ�Ĺ���||ON==0 �յ�VCU���͵ĶϿ��ŵ縺����
               {
                stateCode=44; 
                Delay10s=0;
               }
        }   
        else if(stateCode==44)//�Ͽ��ŵ縺���̵���
        { 
            if(BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb==2)  //�����̵����ѶϿ�
            {
              stateCode=46;
            }
        } 
        else if((stateCode==46))
        {
            if((g_DischaNRelayAdin==1)||(g_FlagLevel==4)||(g_RelayPowerOffFault==1)||(g_PowerOffFlag==1)||(g_ACC_ON==0)) //�ŵ縺��ճ����������������µ���߳�����)
            {
                stateCode=47;  
            } 
            else if((g_DC_CC2==1)) //��CC2=1
            {
                InitialSoc();//SOC���㷽ʽ�仯
                g_BmsModeFlag = FASTRECHARGING;
                stateCode = 141;
            } 
            
            else if((g_ACC_ON==1)&&(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==1)) //ON=1���յ������ŵ縺�պ�ָ��
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
    
    else if(g_BmsModeFlag==FASTRECHARGING)//���
    {
        if(stateCode==140)
        {   
            if(g_RelayPowerOffFault == 0)
            {              
                if(input6_state()==0) //�ߵ�ѹ��������  ChargerIN=1
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

            if((g_DischaNRelayAdin==1)||(g_ChaNRelayAdin==1)||(g_MSDFault==1)||(g_RelayPowerOffFault == 1) //�����̵���ճ����MSD���ϣ��ߵ�ѹ��������
            ||(g_FlagLevel==4)||(g_DCChaPowerOffFlag==1)||(g_DC_CC2==0)||(ChangerINError==1)//4�����ϣ������µ���ϣ�CC2=0,ChargerIN=0
            ) 
            {
              stateCode=187; 
            }
            else if((g_DC_CC2 == 1))   //�Լ������=1��CC2=1                    
               {
                stateCode=142; 
               }
        }
        else if(stateCode==142)
        {
            if((g_ChaNRelayAdin==1)||(g_MSDFault==1)||(g_ChaNRelayDiscon==1)||(g_FlagLevel==4)||(g_DCChaPowerOffFlag==1)||(g_DC_CC2==0)||(ChangerINError==1)
            ||(g_CellHighestVol>=HIGHEST_ALLOWED_CHARGE_CV)||(Tavg>=54+40))//4�����ϣ������µ���ϣ�CC2=0,ChargerIN=0
            {                  
                stateCode=184;
            }
            else if((g_BMSSelfCheckCounter==2)&&(g_DC_CC2==1)&&(ChangerINError==0))//�Լ������=2��CC2=1��ChangerIN=1
            {
                stateCode=144; 
            }
        } 
        else if(stateCode==144)
        {
            if((g_FlagLevel==4)||(g_DCChaPowerOffFlag==1)||(g_DC_CC2==0)||(ChangerINError==1))//4�����ϣ������µ���ϣ�CC2=0,ChargerIN=0)
            {
              Delay186++;
              if(Delay186>=180) 
              {
                  stateCode=180;
              }
            }
            else if((EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1==1)&&(g_DC_CC2==1)&&(ChangerINError==0)&&(DC_Start == 1))//�յ�������Ѿ��պ�&&CC2==1&&ChargeIN==1,CRM��ɣ�����׼�����DC_Start = 1
            {
              stateCode=170;
            }
        }
        else if(stateCode==170)
        {
            if(FastEndNormalFlag==1) 
            {
                Delay170++;
                if(Delay170>400)  //��ʱ��Լ6*400=2.4s
                {
                    stateCode=180;
                    Delay170=0; 
                }
            }
            if((g_DC_CC2==0)||(ChangerINError==1)||((OffState==1))&&(Delay5s2>5000))//4�����ϣ������µ���ϣ�CC2=0,ChargerIN=0)
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
            else if(EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1==2) //�յ�EVCU������Ͽ�ָ��
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
            if(BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1==2)//��縺״̬�����Ͽ�
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