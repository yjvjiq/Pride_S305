//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : Task.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2014.5.7
//* Description        : ���ļ�������ϵͳ�������񻮷ֲ��������й���
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "derivative.h" /* include peripheral declarations */
#include "BMS20.h" 
//**************************************************************************************
//* Variable definition                            
//**************************************************************************************/
//�����б�
static TASK_COMPONENTS TaskComps[] = 
{ 
    {0, 1,    1,    TaskCurrentDetect},         //����������� 1ms���һ�ε���ֵ //0 ��־λ��1��
    {0, 700,  700,  TaskSocProcess},            //SOC����
    {0, 297,   300,   TaskBmuProcess},            // BMU���ݴ�������//��ǰ60ms
    {0, 17,   20,   TaskVoltage},               // �ܵ�ѹ����   .
    //{0, 297,  300,  TaskInsulation},            // ��Ե������� //�ô�ʱ����С600MS������̫С  80ms
    {0, 97,  100,   TaskReport2PC},             //���ͱ��ĵ���λ��
    {0, 5,    5,    TaskStatusMachine},         //״̬������
    {0, 997, 1000,  TaskFaultProcess},          //1s���ϴ���
    {0, 9,   10,    TaskRecordProcess},        //��ʷ��¼����
      
};

//**************************************************************************************
//* FunctionName   : TaskRemarks()
//* Description    : �����־����
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
void TaskRemarks(void)
{
    uchar i;

    for (i=0; i<TASKS_MAX; i++)          // �������ʱ�䴦��
    {
         if (TaskComps[i].Timer)          // ʱ�䲻Ϊ0
        {
            TaskComps[i].Timer--;         // ��ȥһ������
            if (TaskComps[i].Timer == 0)       // ʱ�������
            {
                 TaskComps[i].Timer = TaskComps[i].ItvTime;       // �ָ���ʱ��ֵ��������һ��
                 TaskComps[i].Run = 1;           // �����������
            }
        }
   }
}
//**************************************************************************************
//* FunctionName   : TaskProcess()
//* Description    : ������
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
void TaskProcess(void)
{
    uchar i;

    for (i=0; i<TASKS_MAX; i++)           // �������ʱ�䴦��
    {
        if (TaskComps[i].Run)           // ʱ�䲻Ϊ0
        {
             TaskComps[i].TaskHook();         // ��������
             TaskComps[i].Run = 0;          // ��־��0
        }
    }   
}
//************************************************************************
//* Function name:TaskCurrentDetect
//* Description:ͨ������ADͨ����ȡADֵ���پ�����ʽת���ɵ��������ݷ�Χȡ����һ������
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskCurrentDetect(void)//
{
    
    turnOnADC(); //��ADC�ж�
	  delay(10);  
	  if((Int_Flag&0x01)==0x01) //����32��ADֵ��ż���
        g_BatSysTotalCur = CurrentCalculation();

}  
//************************************************************************
//* Function name:TaskSocProcess
//* Description:ÿ����㲢����SOC��ÿ���ӱ���һ����ʷ��¼
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskSocProcess(void)
{
    
    static float ahCharge1A=0;
    static float ahDischarge1A=0;
    static unsigned char DCfinish=0;
   
	  unsigned char i=0;
	  float ft=0;
	  	  	  
		I2CReadDate();  //��ȡϵͳʱ��
			         	
		if(CurrentTime[0]!=g_oldTime[0])   //ÿ���Ӽ���һ��SOC��ֵ
		{
				g_oldTime[0] = CurrentTime[0];//��
			  SocIntegral();//������ֵõ���SOCֵ	   
			  g_energyOfUsed = 0;	    		
		    StoreSocRealvalue();//ÿ�뱣��SOCֵ
		    //if(g_errorRecordRead_flag==0)
		        //StoreSysVariable();//for test
		         		    
    } //end of ÿ����
				
		if(CurrentTime[1]!=g_oldTime[1])// ÿ����SOCֵ����ϵͳ��������Ϊ�����ͨ��
	  {
			  g_oldTime[1] = CurrentTime[1];//��
			  
			  g_sysPara[PARA_SOC_VALUE] = g_socValue;
			  
			  if((g_BmsModeFlag == DISCHARGING)&&(StoreAHState==1))
			  {
			      ft=(StoreAHSOC-g_socValue)*C;//�����ۻ���ŵ�AH����
			      if(ft>1)
			      {			        
			          dischargeAH += (unsigned int)ft;
			          StoreAHSOC=First_g_socValue;
			      }
			  } 
			  else if((g_BmsModeFlag == FASTRECHARGING)&&((StoreAHState==1)))
			  {
			      ft=(g_socValue-StoreAHSOC)*C;//�����ۻ���ŵ�AH����
			      if(ft>1)
			      {			        
			          chargeAH += (unsigned int)ft;
			          StoreAHSOC=First_g_socValue;
			      }
			  }
			  
			   
			  //First_g_socValue=StoreAHSOC;      
			    
			   

			  //����״̬����
			  if(g_errorRecordRead_flag==0)
		        StoreSysVariable();//ÿ���ӱ�����ϼ�¼��Ϣ
		    if(StoreAHState==1)    	
		        StoreChargeDischargeAH();//�����ۻ���ŵ�������	  
		    sendBMSIDtoBMU(); //����BMS�汾ID�Ÿ�BMU
			  sendRealtimeToBMU(); //����BMSϵͳʱ���BMU
			      
    }

}
//**********************************************************************
//* Function name:    TaskBmuProcess
//* Description:      BMU�Լ죬�����ʱ���ղ�ȫBMU���ݣ�����ʾ�ڲ�ͨ�Ź���
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void TaskBmuProcess(void) 
{
   static unsigned long t=0;
   
   unsigned char i=0,k=0x01,m=0x02;
   unsigned char ErrorState=0;
   float Value=0;
   unsigned long buff=0;
     
    if(!bmuProcess2()) //BMU�Լ�   	        
    {        
        t++;
        _FEED_COP();   //2s�ڲ�ι�ڹ�����ϵͳ��λ
    } 
    else 
    {            
        t=0;
        GetTavgProcess();
        //State_Box_Online=0x3f;        
       
    }          
    if(t>=100) //��ʱ���ϱ���300ms*100=30s
    {
                 
        fault_pc552_Byte6.Bit.F0_InterComFault=1; //�ڲ�ͨѶ���� 
                    
    
    }/////end of BMUͨ���ж�
    
}

//***********************************************************************
//* Function name:   TaskReport2PC
//* Description:     ��BMS�������Ϣͨ���ڲ�����0x0c0450,0x0c0451,0x0c0452������λ�����
//*                  Ϊ��ֹ��֡�����Ա��ļ������
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskReport2PC(void) 
{
    static unsigned char ct=0;
    ct++;
    if(ct==1)
        bmsToPcInfo450();
    if(ct==2)
			  bmsToPcInfo451();
    if(ct==3)
			  bmsToPcInfo552();
    if(ct==4)
        bmsToPcInfo553();
    if(ct==5)
        bmsToPcInfo554();
    if(ct==6)
    {   
        if(g_BmsModeFlag == RECHARGING)
            bmsToPcInfo750();   
        ct=0;
    }

}



//***********************************************************************
//* Function name:   TaskGpioTest
//* Description:     Ӧ�ó�����뵽���Խ׶�ʱ,������A�ڵļ��
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskGpioTest(void) 
{
    static unsigned int TimerCP=0; 
    if((input2_state()==0)&&(input3_state()==1))   //16A 680R
        C0552_0 |= 0x01; 
    else
        C0552_0 &= 0xfe;
    
    if((input2_state()==0)&&(input3_state()==0))   //32A 220R
        C0552_0 |= 0x02; 
    else
        C0552_0 &= 0xfd;

    if(input6_state()==0)       //CP
    {
        C0552_0|=0x04;
        if(TimerCP>=500)      //10ms ��ʱ�� 2S
        {
            //TurnOn_CP();
            TimerCP=501;
        }
    }
    else 
    {
        C0552_0&=0xfb;
        //TurnOff_CP();
        TimerCP=0;
    }
    
    if(input4_state()==0)      //ACC
        C0552_0|=0x08; 
    else
        C0552_0&=0xf7;
    

    if(input6_state()==0)    //��練��     (�պϳ�練��ʱ,ACCҲ��)
        C0552_0|=0x10; 
    else
        C0552_0&=0xef;

    if(input5_state()==0)       //CC2
        C0552_0|=0x20; 
    else
        C0552_0&=0xdf;
    /*
    if(inputP_state()==0)       // ��������
        gpio_state|=0x20;  
    else
        gpio_state&=0xdf;

    if(inputN_state()==0)       // ��������
        gpio_state|=0x40;
    else
        gpio_state&=0xbf;

    if(inputH_state()==0)       ///INPUT1 �ߵ�ѹ����
        gpio_state|=0x80; 
    else
        gpio_state&=0x7f;  
    */


                
}


//***********************************************************************
//* Function name:   TaskStatusMachine
//* Description:     BMS����������������״̬�����������Ӧ����  5ms����һ�� 
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskStatusMachine(void)//5ms����һ�� 
{
    SignalOnOffJudge(); 
    stateCodeTransfer();
   /* static unsigned char counter1_10ms=0;
    static unsigned char counter1_500ms=0;
    static unsigned char counter2_500ms=0;
    static unsigned char counter3_500ms=0;
    static unsigned char clearSelfCountAC=0;
    static unsigned char state46=0;
    static unsigned char TestDelay=0;//���뵽����ģʽ�µ�ʱ����ʱ
    float BiggestDisCurrent=0;
    float BiggestChaCurrent=0;
    
    //HeatManage();  
    
    //stateCode = 179;
    switch(stateCode) //״̬���ж�
    {

        //***********************�ϵ����*********************************

        case 11:
        case 141:   
            state46=0;
           
            break;
        //********************��ѹ�Լ�*************************************
        case 12:  
            HighVoltDetectPart1();//MSD�븺��ճ��
            tmr_p5=0;//146�޷�����
            delay(25000); //19ms           
            break;     
        case 142:
            if(g_BMSSelfCheckCounter==0)  //�Լ������=0
            {
                HighVoltDetectPart1();//MSD�븺��ճ��
                tmr_p5=0;//146�޷�����  
            }    
            if(g_BMSSelfCheckCounter==1)  //�Լ������=1
            {
                TurnOn_INA2K();     //�պϳ�縺�̵���            
                delay(25000); //19ms     
                HighVoltDetectPart2();//�����̵�����·
            }
            
            break;     
        case 14:  //***********************�պϷŵ縺************************************
            closeNegRelay();     //�պϷŵ縺�̵���
            delay(25000);   //19ms
            break;
        case 144: //***********************�պϳ�縺�̵���*******************************
            BMS8_Byte1.Bit.F6_7_ChaPCtorClose=1;  //���ͳ�����պ�ָ��            
            break; 
            
        case 17:   //***********************��ظ�ѹ���*****************************
            HighVoltDetectPart2();//�����̵�����·
            BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=1;  //���ͷŵ縺�պ�  to VCU
            BMS6();
            break;


        //****************��������********************************************
    
        case 30:    //*********************�г�״̬********************************
            turnOnSW_Power();//���������  
            g_MaxDischaCur = BigDischargePowerAdjust((Tavg-40),g_SysSOC);//SOF//30s
            g_MaxFebCur = PulseRechargePowerAdjust1(g_SysSOC,(Tavg-40)); //�ƶ���������30s 
            SocEndDischargeAdjust(); //�ŵ�ĩ��SOC����
            CarFaultDone();//�г����̹��ϴ���
            break;
        case 170:   //********************����� ***********************************
            turnOnSW_Power();//��������� 
            HeatManage();  
            REQ_TurnON_Insulation = 1;
            counter1_500ms++;
            if(counter1_500ms>=70)
            {
                counter1_500ms=0;
                HeatAndChargeControl();  //�����ȿ���
                GetDCTem();              
            }
            break;


        //*************************�µ����******************************
                        
        case 180:
            BMS8_Byte1.Bit.F6_7_ChaPCtorClose=2;  //����Ͽ������ 
            TurnOff_INHK();//�Ͽ����ȼ̵��� ��170״̬���ȼ̵�����Ҫ�ر�          
            delay(25000); //19ms            
            break;
        //********************�Ͽ�����******************************     
        case 44:                   //�Ͽ��ŵ縺
            if((g_DischaNRelayDiscon == 1)||(g_FlagLevel==4)||(g_RelayPowerOffFault==1)) 
            {
                BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=2;
            }
            else if((WithEVCUComOverTimeFlag==1))
            {                
                openNegRelay();           //�Ͽ��ŵ縺
            } 
            else if((g_ACC_ON==0)&&(Delay5s3>5000)) 
            {
                Delay5s3=0;
                openNegRelay();           //�Ͽ��ŵ縺                
            }
            else if(g_BatSysTotalCur>=30)        //���ϵͳ�������ڵ���30A
            {
                openNegRelay();           //�Ͽ��ŵ縺
            }
            else if((g_BatSysTotalCur<30))     //���ϵͳ����С��30A
            {              
                if(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==2)//���յ��������͵ĸ�ѹ�µ������BMSִ�жϿ��ŵ縺
                {
                    openNegRelay();           //�Ͽ��ŵ縺              
                }
                else if(Delay60s>=56000)      //��ʱ60s ,�ж���ʱ��׼
                {
                    openNegRelay();           //�Ͽ��ŵ縺
                    Delay60s=0;
                }                         
            } 
            
            break;
        case 184:                  //�Ͽ���縺
            TurnOff_INA2K();      //�Ͽ���縺
            delay(25000); //19ms
            break;  
            
        case 46:   //*****************��ѹ������*******************************
            DischaNRelayAdjoinTest();   //�ŵ縺ճ�����
            break;
        case 186:
            ChaNRelayAdjoinTest();            
            break;   
        case 47:  //******************BMS�ϵ�**************************************
        case 187:
            if(state46==0)
            {
              
                delay(25000); //20ms
                delay(25000); //20ms
                //TurnOff_INHK();//�رռ��ȼ̵��� 
                //preChargeON=0;
                tmr_p1=0;           
                tmr_p2=0;
                tmr_p3=0; 
                tmr_p4=0;
                g_BMSSelfCheckCounter=0;
               // TurnOff_INBK();//�Ͽ�Ԥ��,��ֹ״̬����12��ת��46ʱԤ��̵���û�жϿ�
                StoreSysVariable();//                
                StoreSocRealvalue();
                state46=1;
                SelfCheck = 0;//�Լ�����,��ֹ���ϵ����Լ�ʱ����������
            } 
            break;
        case 177://���Խ׶�

            openNegRelay();//�Ͽ������̵���
            delay(25000); //20ms
            
            _FEED_COP();   //2s�ڲ�ι�ڹ�����ϵͳ��λ
            
            TurnOff_INHK();//�Ͽ����ȼ̵���
            delay(25000); //19ms
            delay(25000); //19ms
            TurnOff_INA2K();//�Ͽ����̵���
            turnOffSW_Power();//close�ܵ�Դ���� 
            State177End=1;//��ת��179�ȴ�
            break;
        case 179://���Խ׶�
            TaskGpioTest();
            TestDelay++;
            if(TestDelay>100)//5*100=400
            {
               GetDCTem();
                TestDelay=0;
            }  
            break;    
        case 48:  //******************BMS�ϵ�**************************************
        case 188:   
            delay(25000); //20ms
            delay(25000); //20ms
            turnOffSW_Power();//close�ܵ�Դ����  
            break; 
        default:
            break;                        
    }
     */
}


//**************************************************************************************
//**************************************************************************************
//**************************************************************************************
//**************************************************************************************