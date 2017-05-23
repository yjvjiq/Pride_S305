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
//* Description        : ���ļ�������Ŀ��״̬�����Դ���
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
unsigned long Delay5s1 = 0;  //��ʱ5s��ʱ
unsigned long Delay5s2 = 0;  //��ʱ5s��ʱ
unsigned long Delay5s3 = 0;  //��ʱ5s��ʱ
unsigned long Delay10s = 0;  //��ʱ10s��ʱ
unsigned long Delay60s = 0;  //��ʱ60s��ʱ
unsigned char g_ACC_ON=0;              //ON��  1��ON��0��OFF
unsigned char g_MSDFault=0;                 //MSD����

unsigned char g_ChaNRelayAdin=0;        //��縺���̵���ճ��
unsigned char g_ChaNRelayDiscon=0;       //��縺���̵�����·

unsigned char g_DischaNRelayAdin=0;        //�ŵ縺���̵���ճ��
unsigned char g_DischaNRelayDiscon=0;       //�ŵ縺���̵�����·

unsigned char g_PreChaRelayAdin=0;     //Ԥ��̵���ճ��
unsigned char g_PRelayAdin=0;          //�����̵���ճ��
unsigned char g_PreChaRelayDiscon=0;  //Ԥ��̵�����·
unsigned char PreChaResiDiscon=0;       //Ԥ������·
unsigned char g_PreChaFailed=0;             //Ԥ���ʧ��
//unsigned char SelfCheck = 0;              //BMS�Լ���: 2,δͨ��;1ͨ��(Ԥ��̵����Ƿ�ɹ��Ͽ�)
unsigned char g_RelayPowerOffFault = 0;     //�̵����µ���� �ߵ�ѹ���� 0�� 1��        

//******************************************************************************
//* Function name:   VehiclePowerOffLogic
//* Description:     BMS�������ϣ��µ�
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void VehiclePowerOffLogic(void)  //S223��Ŀû��ʹ��
{
    static unsigned char OffFlag=0;
    static unsigned char count=0;
    
    TurnOff_INZK();//�Ͽ������Ӵ��� 
    turnOffSW_Power();//�رյ�Դ���س��׶ϵ�
}
//******************************************************************************
//* Function name:   closeNegRelay
//* Description:     �պ������̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void closeNegRelay(void) //�պϷŵ縺
{
    TurnOn_INFK();                 //to pc
    
   
}
//******************************************************************************
//* Function name:   openNegRelay
//* Description:     �Ͽ������̵���   
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void openNegRelay(void) 
{
    TurnOff_INFK();//�Ͽ��ŵ縺�̵���
    
    //g_DischaNRelayDiscon=1;   //�ŵ縺�ѶϿ���־

}
//******************************************************************************
//* Function name:   openPosRelay
//* Description:     �Ͽ������̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void openPosRelay(void) 
{
    TurnOff_INZK();//�Ͽ������̵���
    delay(25000); //20ms
    TurnOff_INBK();//�Ͽ�Ԥ���̵���
    delay(25000); //20ms

}
 */
//******************************************************************************
//* Function name:   GetTavg
//* Description:     ��ŵ繦�ʲο����¶�ȡֵ
//* EntryParameter : ����¶ȣ�����¶�
//* ReturnValue    : Tavg
//******************************************************************************
/*unsigned char GetTavg(unsigned char LowTem,unsigned char HighTem)  //S223��Ŀû��ʹ��
{
    unsigned char Tavg1;

    if((LowTem>10+40)&&(HighTem>=55+40))
        Tavg1=HighTem;
    
    else if((LowTem>10+40)&&(HighTem<55+40)) //��������Ҫ�ſ�
        Tavg1=g_averageTemperature;
    
    else if(LowTem<=10+40) 
        Tavg1=LowTem;
    
    return Tavg1;

}  */
//******************************************************************************
//* Function name:   GetTavgProcess
//* Description:     ��ŵ繦�ʲο����¶�ȡֵ
//* EntryParameter : ����¶ȣ�����¶�
//* ReturnValue    : Tavg
//******************************************************************************
void GetTavgProcess(void)  
{

    static unsigned char timer1,timer2; 
    if(g_BatHighestTemp>45+40)//��������¶ȴ���45�ȣ���ôƽ���¶�Ϊ����¶�
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
//* Description:     ����state�����ϵ粽��1��״̬������12/46 ,142/184 
//              MSD��·���ϼ��,�ŵ縺���̵���ճ�����
//* EntryParameter : None    �������5ms
//* ReturnValue    : None
//******************************************************************************
/*void HighVoltDetectPart1(void) 
{
    static unsigned char tt=0;
    static unsigned char pp=0;
    static unsigned char ww=0;
    static unsigned char state12=0;
    static unsigned char state142=0;
    
    if(tmr_p1<=350)//350ms�� ��ʱ����1ms�ж��������Ŀ������ʱ��׼ȷ�������������������������Ϊ��������Ӱ����ʱ��׼ȷ��
    {
        
        //��ѹ������⣻��Ϊ�ߵ�ƽ��˵����ѹ�����쳣,��ѹ����״̬=1
        if(inputH_state()) 
        {
            BMS7_Byte6.Bit.F6_7_HighVolLock=1;  //����CAN��ѹ��������
            g_FlagLevel=4;   //����CAN���ϵȼ�4������
            g_RelayPowerOffFault = 1;        //�й���
        } 
        else 
        {
            BMS7_Byte6.Bit.F6_7_HighVolLock=0;  //����CAN��ѹ��������
        }
        
        //**************���MSD*****************************
        if(g_BatSysTotalVolV1<100) 
        {                       
            tt++;   
            if(tt>=12)//60ms�����жϳ���
            {
                g_RelayPowerOffFault = 1;//�̵����µ����
                g_MSDFault = 1;       //MSD��·����
                fault_pc552_Byte7.Bit.F0_MSDDisconFault=1;//�ڲ�CAN  MSD��·����
                g_FlagLevel=4;   //����CAN���ϵȼ�4������
                tt=13;
            }
        } 
        else   
        {
            tt=0; 
            
        }
        if(g_BmsModeFlag == DISCHARGING)        //������г�ģʽ   
        {   
            if(g_BatSysTotalVolV2>300)//�ŵ縺��ճ��
            {
                ww++;
                if (ww>=12)//60ms�����жϳ���
                {
                    g_RelayPowerOffFault = 1;//�̵����µ����
                    fault_pc552_Byte7.Bit.F1_NRelayAdinFault=1; //�ڲ�CAN�ϱ��ŵ縺ճ��
                    BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=3;//����CAN  �ŵ縺ճ�� �պ�
                    g_FlagLevel=4;   //����CAN���ϵȼ�4������
                    BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //����������
                    g_DischaNRelayAdin = 1;   //�ŵ縺ճ��
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
                    g_BMSSelfCheckCounter=1;  //�Լ������  
                }
            }
        }
        
        //********����縺�̵���ճ�� ****************
        if(g_BmsModeFlag == FASTRECHARGING) 
        {

            if(g_BatSysTotalVolV3>=300) //(V2>=0.6*g_BatSysTotalVolV1))
            {
                pp++; 
                if(pp>=12)
                {
                    /////////////////��縺�̵���ճ��///////////////////
                    g_RelayPowerOffFault = 1;//�̵����µ����
                    fault_pc552_Byte7.Bit.F1_NRelayAdinFault=1;  //�ڲ�CAN�ϱ���縺ճ�� �պ�
                    BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=3;//����CAN  ��縺ճ�� �պ�
                    g_FlagLevel=4;   //����CAN���ϵȼ�1������
                    BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //����������
                    BMS9_Byte7.Bit.F0_ChaCtorAdin1=1;   //��縺ճ��
                    g_ChaNRelayAdin = 1;   //��縺ճ��
                    pp=13;
                    /////////////////��縺�̵���ճ��////////////////////
                }
            }
            else 
            {
                pp=0;
                g_BMSSelfCheckCounter=1;  //�Լ������  
                
            } 
        }
    }
    else  //��Ҫ350ms֮��
    {
      
        if((g_MSDFault==0)&&(g_DischaNRelayAdin==0)&&(g_ChaNRelayAdin==0))
        {
            g_BMSSelfCheckCounter=1; //����״̬ 
        } 
    }

}
//******************************************************************************
//* Function name:   HighVoltDetectPart2
//* Description:     ��ѹ��⣺״̬������17/44 142/184�����̵�����·��� 
//* EntryParameter : None
//* ReturnValue    : None                     
//******************************************************************************
void HighVoltDetectPart2(void)
{    
    
    static unsigned char PConnect_tt=0;
    static unsigned char ccc=0;
    static unsigned char state17=0;
    static unsigned char state142=0;

    if(g_BmsModeFlag == DISCHARGING)        //������г�ģʽ   
    {  
        if(tmr_p3<60)
            return ;
        if(g_BatSysTotalVolV2<100)  //V2��100V������60ms,�ŵ縺���̵�����·
        {
            PConnect_tt++;
            if (PConnect_tt>=12)//����60ms
            {
                g_RelayPowerOffFault = 1;//�̵����µ����
                fault_pc552_Byte7.Bit.F2_NRelayDisconFault=1;  //�ڲ�CAN�ϱ��ŵ縺���̵�����· �Ͽ�
                g_FlagLevel=4;   //����CAN���ϵȼ�1������
                g_DischaNRelayDiscon = 1;   //�ŵ縺���̵�����· 
                PConnect_tt = 13;
            }            
        }
        else//�޹���
        {
            state17++;
            PConnect_tt=0;
            if(state17>=12) 
            {
                state17=0;
                g_BMSSelfCheckCounter=2; //����״̬ 
                

            }            
            //delay(25000); //20ms
            
        }
    } 
    if(g_BmsModeFlag == FASTRECHARGING) 
    {
        if(tmr_p3<60)
            return ;
        if(g_BatSysTotalVolV3<100)    //��縺��·���
        {
            ccc++;
            if(ccc>=12) 
            {
                g_RelayPowerOffFault = 1;//�̵����µ����
                fault_pc552_Byte7.Bit.F2_NRelayDisconFault=1;  //�ڲ�CAN�ϱ��ŵ縺���̵�����· �Ͽ�
                g_ChaNRelayDiscon = 1;     //��縺���̵�����·
                g_FlagLevel=4;   //����CAN���ϵȼ�1������
               // state_pc552_Byte1.byte |=0x01;//��縺���̵���״̬�պ�    to pc
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
              g_BMSSelfCheckCounter=2;//û�й��ϣ��Լ������
              g_DischaNRelayDiscon=0; //�����̵�����·
            }
             
        }
  
    }
}
//******************************************************************************
//* Function name:   HighVoltDetectPart3
//* Description:     ����state�����ϵ粽��3��״̬������20/90
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void HighVoltDetectPart3(void) 
{      
    static unsigned char tt=0;
    static unsigned char tm=0;
    
    TurnOff_INHK();//�Ͽ����ȼ̵���,Ԥ��ǰ�رռ��ȼ̵���������Ӱ��Ԥ��
    if(preChargeON==0) 
    {
        preChargeON=1;
        TurnOn_INBK();//�պ�Ԥ��̵���
        //state_group1.Bit.St_Pre_Relay=1;  //Ԥ��̵���״̬  for VCU
        //state_group4.Bit.St_Precharge=1;  //Ԥ��������    for VCU
        delay(20000); //20ms
        tmr_p3=0;
        prechargeFinished=0;
        tt=0;
    }
    if(tmr_p3<=60)  //��ʱ60ms
       return;
    
    if(tmr_p3<=1000) 
    {
        if(prechargeFinished==0) 
        {
            
            if((g_BatSysTotalVolV3 <= 100)&&(g_BatSysTotalVolV2>=200))//��ֹ���ض�·��������ض�·��V3���С,���V2ҲС�����ⲿ��· 
            {            
                tt++;
                if(tt>=10)//�˲�50ms 
                {  
                    g_RelayPowerOffFault = 1;//�̵����µ����
                    tt=11;
                    state_group1.Bit.St_N_Relay=0;  //to vcu
                  //  g_caution_Flag_4 |=0x04;        //to PC
                    state_pc552_Byte1.byte &= 0xfe;            //�����̵���״̬   open    to pc                   
                    TurnOff_INBK();                 //�Ͽ�Ԥ���̵���
                    state_group1.Bit.St_Pre_Relay=0;  //Ԥ��̵���״̬  for VCU
                    delay(25000);                   //20ms��ΪʲôҪ��ʱ
                    g_DischaNRelayDiscon = 1;         //�����̵�����·
                }
                                         
            } 
            else 
            {   
                tt=0;
                if((g_BatSysTotalVolV3>g_BatSysTotalVolV1*0.95)&&(prechargeFinished==0))//û�й��� 
                {
                    TurnOn_INZK();//�պ������̵���
                    state_group1.Bit.St_P_Relay=1;//to vcu
                    delay(25000); //20ms
                    delay(25000); //20ms
                    TurnOff_INBK();//�Ͽ�Ԥ���̵���
                    state_group1.Bit.St_Pre_Relay=0;  //Ԥ��̵���״̬  for VCU                    
                    prechargeFinished =1;  //Ԥ����ɱ�־
                    state_group4.Bit.St_Precharge=2;  //Ԥ������    for VCU
                    g_BMSSelfCheckCounter=3; 
                   
                } 
                
            } 
        }
    } 
    else if(tmr_p3>1000) //��ʱ100ms //�ϵ�ɹ���100ms�ټ���ѹ�������ж������̵����Ƿ��ж�·��
    {
        if(prechargeFinished==0)//Ԥ���δ��� 
        {
            g_RelayPowerOffFault = 1;//�̵����µ����
            prechargeFinished =0;  //Ԥ���δ���
           // g_caution_Flag_4 |=0x80; //to PC
            TurnOff_INBK();//�Ͽ�Ԥ���̵���
            state_group1.Bit.St_Pre_Relay=0;  //Ԥ��̵���״̬  for VCU
            g_PreChaFailed = 1; //Ԥ���δ���
            tmr_p3 =1010; // ֻҪ����400����    
        }
    }
                   
}

//******************************************************************************
//* Function name:   PreRelayConnectTest
//* Description:     Ԥ��̵���ճ�����ϣ���State=13,83,143ʱ��⣬�Ͽ���,���Ƿ�ճ��
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
            g_RelayPowerOffFault = 1;//�̵����µ����
            g_PreChaRelayAdin = 1;
            //state_group1.Bit.St_Pre_Relay=1;  //Ԥ��̵���״̬  for VCU
            state_pc552_Byte1.byte |=0x08;//Ԥ��̵���״̬�պ�    to pc
           // g_caution_Flag_4 |=0x10; //to PCԤ�������ճ��
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
//* Description:     �ŵ縺ճ����⣺��State=46ʱ���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void DischaNRelayAdjoinTest(void)
{
    static unsigned char pd=0;    
    static unsigned char state46=0;
    if(tmr_p5<60)
        return; 
    if(g_BatSysTotalVolV2>300)//�ŵ縺��ճ��
    {
        pd++;
        if (pd>=12)//60ms�����жϳ���
        {
            g_RelayPowerOffFault = 1;//�̵����µ����
            state_pc552_Byte1.byte|=0x01; //�ڲ�CAN�ϱ��ŵ縺ճ��
            BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=3;//����CAN  �ŵ縺ճ�� �պ�
            g_FlagLevel=4;   //����CAN���ϵȼ�4������
            BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //����������
            g_DischaNRelayAdin = 1;   //�ŵ縺ճ��
            pd = 13;
         }            
    } 
    else//�޹���
    {
        delay(25000); //19ms
        pd=0;  
        state46++;
        if(state46>=12) 
        {
            state46=0;
            g_BMSSelfCheckCounter=1;  //�Լ������  
        }
        
    }
}
//******************************************************************************
//* Function name:   ChaNRelayAdjoinTest
//* Description:     ��縺ճ����⣺��State=186ʱ���
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
            /////////////////��縺�̵���ճ��///////////////////
            g_RelayPowerOffFault = 1;//�̵����µ����
            fault_pc552_Byte7.Bit.F1_NRelayAdinFault=1;  //�ڲ�CAN�ϱ���縺ճ�� �պ�
            BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=3;//����CAN  ��縺ճ�� �պ�
            g_FlagLevel=4;   //����CAN���ϵȼ�1������
            BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;       //����������
            BMS9_Byte7.Bit.F0_ChaCtorAdin1=1;   //��縺ճ��
            g_ChaNRelayAdin = 1;   //��縺ճ��
            cn=13;
            /////////////////��縺�̵���ճ��////////////////////
        }
     }          

    else//�޹���
    {
        
        g_BMSSelfCheckCounter=1;  //�Լ������  
        cn=0;  
    }
} 
*/
//***********************************************************************
//************************************************************************
//*************************the end*************************************
//************************************************************************
