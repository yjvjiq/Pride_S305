//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : �ڶ����ƶ���糵
//* File Name          : Charging.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2014.5.7
//* Description        : ϵͳֱ�����ͽ���������
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h" 
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

static unsigned char sendi1=0;     //��ȫ�ֱ���
static unsigned char sendi2=0;      //��ȫ�ֱ���

unsigned char	m_chmmode=0x02; //ȫ�ֱ���
unsigned char fastendflag=0;  //ȫ�ֱ���


float	m_askvoltage=HIGHEST_ALLOWED_CHARGE_V;     //���ݵ�ذ��������
float	m_askcurrent=20.0;      //ȫ�ֱ�����ֱ��������
float	big_askcurrent=150.0;      //ȫ�ֱ�����ֱ�����������
float HeatCurt;
float	m_allowmaxvoltage=3.65;   //ȫ�ֱ��� ,Ŀǰû�õ�


/////////�����,BMSֹͣ����ԭ��////////////////
unsigned char  fastend1=0;    //ȫ��
unsigned char  fastend2=0;
unsigned char  fastend3=0;
unsigned char  fastend4=0;
/////////�����,BMSֹͣ����ԭ��////////////////
unsigned char  ACEndState=0;//����ֹͣ��־λ
/////////����ת�����,BMSֹͣ����ԭ��////////////////
unsigned char  BMSToVCU655_1=0;    //ȫ��
unsigned char  BMSToVCU655_2=0;    //ȫ��
unsigned char  BMSToVCU655_3=0;    //ȫ��
/////////����ת�����,BMSֹͣ����ԭ��////////////////

/////////����ã�����BSM����ص�ǰ״̬////////////////
unsigned char  fasterror11 =0;
unsigned char  fasterror12 =0x10;//�����磬0 b 00 01 00 00
/////////����ã�����BSM����ص�ǰ״̬////////////////
///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
float ChgeAmpReq=0; //����������ֵȫ��
unsigned char slowRechargeFinished=0;     //���������־
unsigned char ReqCtlToCHG =1;   //�������״̬
 /////////////////////////////////////////////////////////////////
///////C11//////

unsigned char SelfState2 = 0;     //�Լ���������2��־
unsigned char SelfState3 = 0;     //�Լ���������3��־,�յ���,���ٷ�BRO
///////C11//////

unsigned int chargeTimes=0;   //������
unsigned int chargeRemainderTime=65535;///s���ʣ��ʱ��

////��ʱʱ���־//////
unsigned char CCSOverTime=0;//CCS��ʱʱ��
unsigned char CSTOverTime=0; //CST��ʱʱ��
unsigned char CSDOverTime=0; //CSD��ʱʱ��

////��ʱʱ���־//////

////��ʱ��־λ////////
unsigned char OverTimeState=0;//��ʱ��־

////��ʱ��־λ////////
/////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//* Function name:   GetRequestCurrentDC
//* Description:     ���������������� C=120A
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
float GetRequestCurrentDC(void) 
{
    float DCAmp;
    
    if(st_heating==1) ///С��0��Ԥ����,Ԥ����
    {
        if(Tavg<=(0+45))
        {    
            m_askvoltage=594;//3.3v * 180=594
            DCAmp=0;
        }
    } 
    else//�߳��߼�����ֻ��� 
    {
        m_askvoltage = HIGHEST_ALLOWED_CHARGE_V;
        if(Tavg>=(55+40))  //����¶ȴ��ڵ���55��[55,)
        {
            m_askvoltage=0;
            DCAmp=0;
        }
        else if(Tavg>=(50+40))//����¶�50~55��[50,55)
        {
            if(Can_g_socValue<0.8)
                DCAmp=0.2*C;////0.2c
            else
                DCAmp=0.1*C;////0.2c 
        }             
        else if(Tavg >=(45+40)) //����¶�45~50��[45,50)
        {
            if(Can_g_socValue<0.8)
                DCAmp=0.3*C;////0.2c
            else
                DCAmp=0.2*C;////0.2c
        }
        else if(Tavg >=(30+40)) //����¶�30~45��[30,45)
        {
            if(Can_g_socValue<0.8)
                DCAmp=0.6*C;////0.2c
            else
                DCAmp=0.3*C;////0.2c
        }
        else if(Tavg >=(20+40)) //����¶�20~30��[20,30)
        {
            if(Can_g_socValue<0.8)
                DCAmp=C;////0.2c
            else
                DCAmp=0.6*C;////0.2c
        }
        else if(Tavg >(15+40)) //����¶�15~20��(15,20)
        {
            if(Can_g_socValue<0.8)
                DCAmp=0.6*C;////0.2c
            else
                DCAmp=0.3*C;////0.2c
        }
        else if(Tavg >=(7+40))//����¶�7~15��[7,15]
        {
            if(Can_g_socValue<0.8)
                DCAmp=0.3*C;////0.2c
            else
                DCAmp=0.15*C;////0.2c
        }
        else if(Tavg >=(0+40))//[0~7)
            DCAmp=0.1*C;
        else //����¶�С��0�ȣ��������ѹΪ0���������Ϊ0
        {
            m_askvoltage=0;
            DCAmp=0;
        }   
    }
    return DCAmp;    
}
//**********************************************************************
//* Function name:   DCFaultDone
//* Description:     �������й��ϵĴ���
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void DCFaultDone(float Curt)
{
    
      
    if(CutDCChaCurt0.word!=0)
    {
        m_askcurrent=0; 
    }
    else if(CutDCChaCurt20.word!=0)
        m_askcurrent=0.2*Curt;
    else if(CutDCChaCurt50.word!=0)
        m_askcurrent=0.5*Curt;
    else
        m_askcurrent=Curt;    
    
    //////////////////////////////*�ϸ�ѹ*/////////////////////////////
    

    if((Fault_Group3.Bit.F_Cell_Over_Voltage!=0)||(Fault_Group1.Bit.F_Battery_Over_Voltage == 1)||(Fault_Group1.Bit.F_Battery_Over_Voltage == 2))
    {
        fastendflag=1;
        fastend4|=0x04;//��ѹ�쳣
        OffState=1;//�����µ�
    } 
    else if(Fault_Group6.Bit.F_Over_Temp== 1)//���ǳ���3���¶ȹ��߹���
    {
        fastendflag=1;
        fastend3|=0x01;//��ѹ�쳣
        OffState=1;//�����µ�
    } 
    else if((Fault_Group1.Bit.F_Inner_Communiction==1)||(CutDCChaCurt0.word!=0))//���ǳ���3���ڲ�ͨ�Ź���
    {
        fastendflag=1;
        fastend3|=0x40;//��������
        OffState=1;//�����µ�
    }  
    //////////////////////////////*�ϸ�ѹ*/////////////////////////////
}

//**********************************************************************
//* Function name:   TaskRechargeDC
//* Description:     ������̣���Լÿ10ms����һ�θú���
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void TaskRechargeDC(void)
{
    static unsigned char counter_250ms1=0;
    static unsigned char CHMStep1=0;
    
    static unsigned char counter_250ms2=0;
    static unsigned char CHMStep2=0;
    
    static unsigned char counter_250ms3=0;
    static unsigned char CHMStep3=0;
    
    static unsigned char counter_250ms4=0;
    static unsigned char CHMStep4_5=0;
    static unsigned char counter_50ms=0;
    
    static unsigned char counter_250ms5=0;
    static unsigned char CHMStep5=0;
    
    static unsigned char counter_250ms6=0;
    static unsigned char CHMStep6=0;
    
    
    static unsigned char DCFinish=0;
    static unsigned char timer1S=0;//�����ѹ�����,ֹͣ��������ж���ʱ
    static unsigned char timer2S=0;//��һ�ν�������ʱ
    static unsigned char timer3S=0;//�ڶ��ν�������ʱ
    static unsigned char ChanceCurt=0;//���ĩ��,�����仯�󲻻���,
    static unsigned char ChangeTimeState=0;//���������Խ���һ�μӷ�
    float curr=0;
    ///////test//////////////
    if(g_BmsModeFlag != FASTRECHARGING)
        return;
    
    if(g_lowestTemperature == 0) //�¶ȼ��������ʱ���ܳ��
        return;
    if((g_highestTemperature>=95)||((g_lowestTemperature<40)&&(st_heating!=1)))//40+50��40+0
    {
        fastend3|=0x01; //Temperature����ֹ���
        BMSToVCU655_3|=0x01;
        fastendflag=1; //���ֹͣ����־  
    } 
    else 
    {     
        fastend3&=0xfe;
        BMSToVCU655_3 &= 0xfe;
    }    
   
    //if(st_heating==1)  //Ԥ���Ƚ׶�(ƽ���¶�С��0��)���¶ȴ���5�Ⱥ󣬲��ܽ��б߼��ȱ߳��
        //return;
  
    curr = GetRequestCurrentDC(); 
    curr= curr+HeatCurt; 
    DCFaultDone(curr);//ֱ�������ϴ���
    
    if(((g_highestCellVoltage>=3.5)&&(g_highestCellVoltage<3.55))||(ChanceCurt==1))//����Ϊ����������һ��
    {
        if(ChanceCurt!=2)
        {          
            timer2S++;
            if(timer2S>=80)//10*80=800ms
            {    
                timer2S=81;                      
                if(m_askcurrent>48)
                    m_askcurrent=48;
                else if(m_askcurrent==0)
                    m_askcurrent=0;
                ChanceCurt=1;
            }
        }
    } 
    else 
    {
        timer2S=0;
    }
    //////////////�����ֲ����Ƽ�SOC����,�����ѹ
    if((g_highestCellVoltage>=3.55)&&(g_highestCellVoltage<3.65)||(ChanceCurt==2))//����Ϊ����������һ��
    {
        timer3S++;
        if(timer3S>=80)//10*80=800ms
        {    
            timer3S=81;
            if(m_askcurrent==0)
                m_askcurrent=0;
            else if(m_askcurrent>=24)      
                m_askcurrent=24;
            ChanceCurt=2;
        }
    } 
    else
    {      
        timer3S=0;
    }

	  if(g_highestCellVoltage>=3.65)  //3.65Vֹͣ���
    {
        timer1S++;
        if(timer1S>=100)//10ms*100=1000ms
        {          
            if(DCFinish==0)
            {
              
                SocRechargeAdjust();
                AdjustQ1Value();
        	      StoreParameter();
        	      DCFinish=1;
    	      
            }   
            fastendflag=1;
            fastend1|=0x10;//�����ѹ�ﵽĿ��ֵ��������ֹ���
            timer1S=103; 
                      
        }
    } 
    else 
    {
        timer1S=0; 
    }


    

	  ///*******///////��䷢����Ϣ 
	  if(CHMStep)
		{     
    	  if(CHMStep==0x01)      //1801f456 00,��֡���ģ�����250ms�����ļ��10ms
    	  {

    	      counter_250ms1++;
    	      if(counter_250ms1>=23)
    	      {
        	      if(DCStartState==2)//�¹��꿪ʼ
                    cpuToCHMBHM();
    	          CHMStep1=0;
    	          counter_250ms1=0;
    	      }    
    	      if(CHMStep1==0)
    	      { 
    			      if(DCStartState==1)//����Ѿ����յ��ɹ��꿪ʼ
    			      {
        			      sendi1++;
        			      if(sendi1%7==1)
        			          cpuToCHMBRM();
        			      else if(sendi1%7==2)
        			          cpuToCHMBRMDATA1();
        			      else if(sendi1%7==3)
        			          cpuToCHMBRMDATA2();
        			      else if(sendi1%7==4)
        			          cpuToCHMBRMDATA3();
        			      else if(sendi1%7==5)
        			          cpuToCHMBRMDATA4();
        			      else if(sendi1%7==6)
        			          cpuToCHMBRMDATA5();
        			      else if(sendi1%7==0)
        			      {  
        			          sendi1=0;
        			          cpuToCHMBRMDATA6();
        			          CHMStep1=1;
        			      }
        			  }
    	      }
    	  }
    		if(CHMStep==0x02)   //1801f456 aa
			  {
			      counter_250ms2++;
			      if(counter_250ms2>50)//500ms
			      {
			        
			          CHMStep2=0;
			          counter_250ms2=0;
			      }
			      if(CHMStep2==0)
			      { 
    			      sendi2++;
    			      if(sendi2%3==1)
    			          cpuToCHMBCP();
    			      if(sendi2%3==2)
    			          cpuToCHMBCPDATA1();
    			      else if(sendi2%3==0)
    			      {
    			          sendi2=0;
    			          cpuToCHMBCPDATA2();
    			          CHMStep2=1;
    			      }
    			      sendi1=0;//�����һ�����
			      }
			  }
			  if(CHMStep==0x03)  //1808f456 aa 250ms
  		  {
           
            counter_250ms3++;
            if(CHMStep3==0)
            {
                if(SelfState3==0)
          			    cpuToCHMBRO();  //100956f4 aa
                CHMStep3=1;
            }
            if(counter_250ms3>19)//ȷ����һ֡���ݷ�������������ʱС��250ms
            {
              
  			        counter_250ms3=0;
  			        CHMStep3=0;
  			        
            }
  		  }
    		if((CHMStep==0x04)||(CHMStep==0x05)) //50ms����
        {
            CCSOverTime++;
            if(CCSOverTime>150)//10*150=1.5S
            {
                OverTimeState=1;//��ʱ��־λ��1                
                CHMStep=0x06;
                BEMError3|=0x01;
                
            }
            if(counter_50ms%4==0)//50ms 
            {			            
                cpuToCHMBCL();    // voltage request and current request
                counter_50ms=0;
            }
            counter_50ms++;
  		      counter_250ms4++;      //250ms
  		      if(counter_250ms4>19)
  		      {
  		        
  		          CHMStep4_5=0;
  		          counter_250ms4=0;
  		      }
  		      if(CHMStep4_5==0)
  		      {			        
    			      sendi1++;
    			      if(sendi1%3==1)
    			          cpuToCHMBCS();
    			      else if(sendi1%3==2)
    			      {
    			          cpuToCHMBCSDATA1();
    			      }
    			      else if(sendi1%3==0)
    			      {
    			          sendi1=0;
    			          cpuToCHMBCSDATA2();
    			          CHMStep4_5=1;
    			      }
  		      }
  		      if(CHMStep==0x05) 
  		      {
      		      counter_250ms5++;
                if(CHMStep5==0)
                {
                    cpuToCHMBSM();
                    CHMStep5=1;
                }
                if(counter_250ms5>19)//ȷ����һ֡���ݷ�������������ʱС��250ms
                {
                  
      			        counter_250ms5=0;
      			        CHMStep5=0;
      			        
                }
            }
  		  }	  
			  if((CHMStep==0x06)||((CHMStep==0x05)&&(fastendflag==1)))//10ms����һ��,��ʼ����ʱ��	
    		{
    			  //����յ������������ֹ���Ļ��ߵ����ѹ���ܵ�ѹ��������ֵ
			      cpuToCHMBST();
			      m_askcurrent=0;//�������Ϊ0
			      if((StoreAHState==1)&&(ChangeTimeState==0))//��¼������1��
			      {
                Charge_Times++;
                StoreChargeTime();//�洢������
                ChangeTimeState=1;
			      }
			      CSTOverTime++;//10ms*200
			      if(CSTOverTime>200)//��ֹ�ղ���CST���� 
			      {
    			      CHMStep=0x06;
    			      OverTimeState=1;
    			      BEMError3|=0x02;
    			      //Fault_Group6.Bit.F_Communication_With_Charger=1;
			      }			       							      			      			      			      			         		
        		if(CHMStep==0x06)   
    			  {
                SocRechargeAdjust();// SOC adjust
                if(CHMStep6==0)
                {                  
                    if(OverTimeState==1)
            			  {
            			      cpuToCHMBEM();
            			  }
                    cpuToCHMBSD();  // report BMS status: the highest and the lowest cell voltage, temperature and SOC.
                    CHMStep6=1;
                }
                counter_250ms6++;
    			      if(counter_250ms6>19)
    			      {
      			        counter_250ms6=0;
      			        CHMStep6=0;			                       
    			      }
    			      CSDOverTime++;
    			      if(CSDOverTime>=200)//���ղ�������ͳ�Ʊ���ʱ,��ʱ2s�µ�
    			      {
    			          CHMStep=0x07;
    			          OverTimeState=1;
    			          BEMError4|=0x01;    			          
    			      }    			      
    			      
    			  }
			  }        
			  if(CHMStep==0x07) //�������� 
			  {
			      if(OverTimeState==1)//�Ѿ���ʱ
			          cpuToCHMBEM();
            OffState=1;//״̬����170��ת40�ı�־λ
            DC_ChangeOver=1;//ֱ�������ɱ�־
           
			  }
												
		}/////////END��䷢����Ϣ
		
}
//******************************************************************************
//* Function name:   GetRequestCurrentAC
//* Description:     ��������������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
float GetRequestCurrentAC(void) 
{
    float CurrentAValue;
    
  
    if((Tavg<(0+45))&&(st_heating==1)) ///С��0��Ԥ����
    {
        m_askvoltage=376;//3.3v * 114
        CurrentAValue=0;
    } 
    else if(Tavg<(10+40)) //////���ڵ���0��С��10��
    {
        if(BCU_AC_CC_State==2) //220ŷ
            CurrentAValue = 12;// 0.1c  
        if(BCU_AC_CC_State==1) //680ŷ 
            CurrentAValue = 10;
        //m_askvoltage=417;
        m_askvoltage=403;
    }
        
    else if(Tavg<(55+40)) //////���ڵ���10��С�ڵ���50��
    {
        if(BCU_AC_CC_State==2) //220ŷ
            CurrentAValue = 20;// 0.1c
        if(BCU_AC_CC_State==1) //680ŷ 
            CurrentAValue = 10;
        //m_askvoltage=417;
        m_askvoltage=403;
    }       
    else
    {
        m_askvoltage=0;
        CurrentAValue=0;
    }
    
    return CurrentAValue;         
}
//**********************************************************************
//* Function name:   ACFaultDone
//* Description:     ��������й��ϵĴ���
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void ACFaultDone(float Curt)
{
    
    //////////////////////////////*������*/////////////////////////////
    /*
    if((Can08f0Byte0.Bit.F1_batteryOV == 1)||(Can08f0Byte3.Bit.F2_overTemp== 1))//���ǳ���1����ذ���ѹ����,2���¶ȹ��߹��ϣ��򽵵���
    {
        ChgeAmpReq =  Curt*0.5;      
    }
    else
    {
        ChgeAmpReq= Curt;
    }
  
    
    //////////////////////////////������/////////////////////////////
        
    
    //////////////////////////////�ϸ�ѹ/////////////////////////////
    /
    if(((Can08f0Byte0.byte&0x80)!=0)||((Can08f0Byte2.byte&0x84)!=0)||((Can08f0Byte4.byte&0x84)!=0)||((Can08f0Byte5.byte&0x21)!=0))
    {
        ACEndState=1;//����ֹͣ��־λ
        OffState=1;//�����µ�
    }
    */ 
    //////////////////////////////*�ϸ�ѹ*/////////////////////////////
}

//******************************************************************************
//* Function name:   TaskRechargeAC
//* Description:     �복�س���ͨѶ���Ե�ؽ�������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void TaskRechargeAC(void)
{
    static unsigned char Step = 0x00;
    static unsigned char time0=0,ChanceAC=0;
    static unsigned char chargeFinish=0;
    static unsigned char ii = 0;
    float curr=0;
    
    
    /*
    if(chargeFaultState!=0)// ��������״̬,chargeFaultState���ճ������͹����ĳ�������״̬ 
        Step=0xFF;
    */
    if(chargeWorkState==0x01)//��������״̬=�رգ���ֹͣ���
        Step=0xFF;
    
    if((g_highestCellVoltage>=3.70)&&(slowRechargeFinished==0)) //�������3.65������δ��ɣ��������ٳ�硣����ֹ�������ǳ��
        Step=0xFF;
    if(st_heating!=1) //����0��ʾ�¶ȴ���10�ȣ�2��ʾ�¶ȴ���0�ȣ�1���¶���0��
    {
      if(g_highestTemperature > (55+40)||(g_lowestTemperature < (0+40))) //t>=55 or t<=0
            Step=0xFF;
    }
    else
    {
        if(g_highestTemperature > (55+40))
            Step=0xFF;
    }
    
    if((!slowRechargeFinished)&&(ReqCtlToCHG==0x00)) //������δ���
    {

        curr=GetRequestCurrentAC();
        curr = curr+HeatCurt;
        if((g_systemCurrent<=-3)&&(g_socValue<0.992))
            chargeRemainderTime=(unsigned int)((g_realNominalCap*(1-g_socValue)*60)/(-g_systemCurrent));
        else if(g_socValue>=0.992)
            chargeRemainderTime=2;     
        chargeRemainderTime=chargeRemainderTime*60;
  
    }
    ACFaultDone(curr);
    if(ACEndState==1)//����ֹͣ��־λ
        Step = 0xff;    
    switch(Step)
    {
        
        case 0://��ʼ
            ReqCtlToCHG = 0x0;//void
            ChgeAmpReq = 0;
            Step = 1;
            
        case 1://Chge Step1
        
            ReqCtlToCHG = 0x0;//������ 
            Step = 2;
            break;
            
        case 2://Chge Step2
            ReqCtlToCHG = 0x0;//������
            if(g_highestCellVoltage >=3.55)  //���ڵ���3.55��ʼ������
            Step = 3;
            break;
            
        case 3://Chge Step3
            ReqCtlToCHG = 0x0;//������

            if(g_highestCellVoltage >=3.65)
            {
                time0++;
                ChgeAmpReq=0.5*curr;
                if(time0>=2) //��ʱ1s�󣬵�ȷʵ����3.65����µ�
                {
                  
                    Step = 4;
                    ChgeAmpReq=0;
                    time0=3;
                    break;  
                }
            } 
            else
            {
                time0 = 0;
                ChgeAmpReq=0.5*curr;//
            }

            break;  
        case 4://Chge Step4 
                
                chargeFinish=1;
                ReqCtlToCHG = 0x01;//ͣ��״̬
                ChgeAmpReq=0;
                Step = 0xFF;
                
            break;  
        case 0xFF://err or finish
        
                slowRechargeFinished=1;//����������
                SocRechargeAdjust();  ////����SOC
                ChgeAmpReq=0;//����������Ϊ0
                ReqCtlToCHG = 0x01;  //void 
                //stateCode=40;
                OffState=1;//״̬����110��ת40�ı�־λ
            break;
        default:
          break;        
      }//switch(Step)
      
}
//************************************************************************
//************************************************************************
//**************************the end******************************************
//************************************************************************