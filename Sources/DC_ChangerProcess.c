//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : DC_ChangerProcess.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : �������
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
unsigned char g_DC_CC2=0;             //CC2�����ź�
static unsigned char sendi1=0;               //��ȫ�ֱ���
static unsigned char sendi2=0;               //��ȫ�ֱ���
unsigned char	m_chmmode = CONSTANT_CURT_WORK;//ȫ�ֱ���
unsigned char fastendflag=0;                 //ȫ�ֱ���,��������־λ
float	g_AskDCVol=0;      //�������ѹ                  //���ݵ�ذ��������
float	g_AskDCCur=0;      //���������                  //ȫ�ֱ�����ֱ��������
/////////�����,BMSֹͣ����ԭ��////////////////
unsigned char  fastend1=0;                   //ȫ��
unsigned char  fastend2=0;
unsigned char  fastend3=0;
unsigned char  fastend4=0xf0;  
unsigned char  FastEndNormalFlag=0;   //���ǹ����µ��־λ

/////////����ã�����BSM����ص�ǰ״̬////////////////
unsigned char  fasterror11 =0;
unsigned char  fasterror12 =0x10;            //�����磬0 b 00 01 00 00

unsigned char BROStopState = 0;              //�յ�CRO��,���ٷ�BRO
unsigned int chargeTimes=0;                  //������

//////////��ʱʱ���־///////////////////////////////
unsigned int CRMOverTimeBefore60s = 0;//�ղ���CRO����60s��ϵͳ������
unsigned int CRMOverTimeBefore = 0;//�ղ���CRO����
unsigned int CRMOverTime = 0;//CRM��ʱ����0xaa��ʱ
unsigned int CROOverTime = 0;//5sδ�յ�CRO����
unsigned int CROOverTime60s = 0;//CRO��ʱ����0xaa��ʱ
unsigned int CCSOverTime=0;                 //CCS��ʱʱ��
unsigned int CSTOverTime=0;                 //CST��ʱʱ��
unsigned int CSDOverTime=0;                 //CSD��ʱʱ��
unsigned char OverTimeState=0;               //��ʱ��־

unsigned char CC2ResState = 0; //0λ��״̬ 1����״̬ 2����״̬
//float g_DCTemp1=0;//DC1�¶Ȳɼ�
//float g_DCTemp2=0;//DC2�¶Ȳɼ�
float CC2VOL = 0.0;
unsigned char DC_CC2Count = 0;
unsigned char BROErrorAA = 1;//BRO������0xaa
unsigned char DC_Vesion = 1;//DC���汾1���Ϲ���;2���¹���
unsigned char SelfState3 = 0;     //�Լ���������3��־
unsigned char BEMStop=0;


unsigned char DCStartState=0;//��俪ʼ��־:1�յ�CRM,2�յ�CHM
float PowerVOL=0; //��Դ��ѹ
static unsigned char SetBSD = 0;//BSD�Ƿ��Ѿ�����
float AskChaCur=0;   //���������
//******************************************************************************
//* Function name:   CurValue
//* Description:     ����������������,���ݱ��������¶��²�ֵ֮��ĵ���ֵ C=176A
//* EntryParameter : (int temp1,int temp2, float cur)���¶�1���¶�2�����¶��µ��������1������2
//* ReturnValue    : ���¶��µĲ�ֵ����
//******************************************************************************
/*float CurValue(int temp1,int temp2,int temp3,float cur1,float cur2) 
{
    float Revalue= ((float)(temp1-temp2)/(float)temp3*(cur1-cur2)+cur2)*C;
    return Revalue;
}

//******************************************************************************
//* Function name:   GetRequestCurrentDC
//* Description:     ���������������� C=240A
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
float GetRequestCurrentDC(void) 
{
    float DCAmp;
  
    g_AskDCVol = HIGHEST_ALLOWED_CHARGE_V;  //3.65*189=689.85
    
    
    if(Tavg>=(54+40))  //����¶ȴ��ڵ���54��[54,)
    {
        g_AskDCVol=0;
        DCAmp=0;
    }
    else if(Tavg>(50+40))//����¶�50~54��(50,54)
    {
        DCAmp=CurValue(Tavg,50+40,4,0,0.3); //0.3c 
    }           
    else if(Tavg>(45+40))//����¶�45~50��(45,50]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,45+40,5,0.3,1.0); //1C
        else
            DCAmp=CurValue(Tavg,45+40,5,0.3,0.8); //0.8c 
    } 
    else if(Tavg>(25+40))//����¶�25~45��(25,45]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,25+40,20,1.0,1.0); //1C
        else
            DCAmp=CurValue(Tavg,25+40,20,0.8,0.8); //0.8c 
    }
    else if(Tavg >(20+40)) //����¶�20~25��(20,25]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,20+40,5,1.0,1.0); //1C
        else
            DCAmp=CurValue(Tavg,20+40,5,0.8,0.75); 
    }
    else if(Tavg >(15+40)) //����¶�(15,20]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,15+40,5,1.0,0.5); 
        else
            DCAmp=CurValue(Tavg,15+40,5,0.75,0.5); 
    }
    else if(Tavg >(12+40)) //����¶�12~15��(12,15]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,12+40,3,0.5,0.5); 
        else
            DCAmp=CurValue(Tavg,12+40,3,0.5,0.5); 
    }
    else if(Tavg >(10+40)) //����¶�10~12��(10,12]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,10+40,2,0.5,0.3);
        else
            DCAmp=CurValue(Tavg,10+40,2,0.5,0.3);
    }
    else if(Tavg >(7+40)) //����¶�7~10��(7,10]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,7+40,3,0.3,0.3);
        else
            DCAmp=CurValue(Tavg,7+40,3,0.3,0.3);
    }
    else if(Tavg >(5+40)) //����¶�5~7��(5,7]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,5+40,2,0.3,0.1);
        else
            DCAmp=CurValue(Tavg,5+40,2,0.3,0.1);
    } 
    else if(Tavg >(2+40)) //����¶�2~5��(2,5]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,2+40,3,0.1,0.1);
        else
            DCAmp=CurValue(Tavg,2+40,3,0.1,0.1);
    }
    else if(Tavg >(0+40)) //����¶�0~2��(0,2]
    {
        if(g_SysSOC<=0.8)
            DCAmp=CurValue(Tavg,0+40,2,0.1,0);
        else
            DCAmp=CurValue(Tavg,0+40,2,0.1,0);
    }
    
    else //����¶�С��0�ȣ��������ѹΪ0���������Ϊ0
    {
        g_AskDCVol=0;
        DCAmp=0;
    }   

    if(CutDCChaCurt50.word!=0)
        DCAmp=0.5*DCAmp;
    if((g_DCTemp1>120)||(g_DCTemp2>120))
        DCAmp=0.5*DCAmp;
    return DCAmp;    
}
*/
//**********************************************************************
//* Function name:   DCFaultDone  ��Լÿ10ms����һ�θú���
//* Description:     �������й��ϵĴ���
//* EntryParameter : None
//* ReturnValue    : 0:�޹���;1:�й���
//**********************************************************************
unsigned char DCFaultDone(void)
{
    static unsigned char DCFault = 0;//һ����ֵ,���ܸı�      
    if( ( BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm > 1)//�ܵ�ѹ��ѹ
    || (BMS7_Byte2.Bit.F5_7_CellOverVolAlarm > 0) )  //�����ѹ
    {
        
        fastendflag=1;   //��������־λ
        fastend4|=0x04;//��ѹ�쳣
        OffState=1; //�µ��־
        DCFault = 1;
    }
    /*else if((BMS5_Byte5.Bit.F4_P_Ins_Err_2==1)||(BMS5_Byte5.Bit.F6_N_Ins_Err_2==1))//��Ե2������
    {
        fastendflag=1;
        fastend2|=0x01;//��Ե�쳣
        OffState=1; //�µ��־
        DCFault = 1;    
    }*/
    else if(BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm==4) //������
    {
        fastendflag=1;
        fastend4|=0x01;//����������
        OffState=1; //�µ��־
        DCFault = 1;     
    } 
    else if((g_DCTemp1>180)||(g_DCTemp2>180))
    {
        fastendflag=1;
        fastend2|=0x40;//�������¶ȹ���
        OffState=1;//�����µ�
        DCFault = 1;     
    }   
    else if(BMS7_Byte4.Bit.F5_7_BatTempHighAlarm==4)//���ǳ���4���¶ȹ��߹���
    {
        fastendflag=1;
        fastend3|=0x01;//����¶ȹ���
        OffState=1; //�µ��־
        DCFault = 1;
    } 
    else if( (1 == BMS7_Byte0.Bit.F1_WithChgerComAlarm) //����ͨ�Ź��� 
         ||(1 == BMS7_Byte0.Bit.F0_WithLECUComAlarm)  //�ڲ�ͨ�Ź���
         ||(1 == BMS7_Byte2.Bit.F1_CurSenFault)        //��������������
         ||(4 == BMS7_Byte4.Bit.F2_4_BatTempLowAlarm)  //����¶ȵ�
         ||(1 == ChaCurDirAnly)             //�����������쳣 
         ||(WithEVCUComOverTimeFlag==2))    //��EVCUͨ�Ź���
         {
            fastendflag=1;
            fastend3|=0x40;//��������   
            OffState=1; //�µ��־     
            DCFault = 1;
         }

    return DCFault;  
      
    
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
    static unsigned char counter_250ms6_1=0;
    static unsigned char CHMStep6=0;
    
    static unsigned char counter_250ms7=0;
    
    static unsigned char  SetBST=0;
    static unsigned char DCFinish=0; //ֱ�����ʱֻ����Q1һ��
    static unsigned char timer1S=0;//�����ѹ�����,ֹͣ��������ж���ʱ
    static unsigned char timer2S=0;//��һ�ν�������ʱ
    static unsigned char timer3S=0;//�ڶ��ν�������ʱ
    static unsigned char ChanceCurt=0;//���ĩ��,�����仯�󲻻���,
    static unsigned char ChangeTimeState=0;//���������Խ���һ�μӷ�
    float curr=0;
    unsigned char ErrorState = 0;
    if(g_BmsModeFlag != FASTRECHARGING)
        return;
    if((g_BatHighestTemp>=(HIGHEST_ALLOWED_CHARGE_T+40))||(g_BatLowestTemp<(LOWEST_ALLOWED_CHARGE_T+40)))  //55
    {
        fastend3|=0x01; //Temperature����ֹ���
        fastendflag=1; //���ֹͣ����־  
        FastEndNormalFlag=1;   //���ǹ����µ��־λ 
    }    
    
    if(CutDCChaCurt50.word!=0)
        AskChaCur=0.5*AskChaCur;
    if((g_DCTemp1>120)||(g_DCTemp2>120))
        AskChaCur=0.5*AskChaCur; 
    ErrorState = DCFaultDone();
    if((ErrorState==1)||(CutDCChaCurt0.word!=0)||(CutDCChaCurt02.word!=0))//ֱ��������µ���ϴ���
    {
        g_AskDCCur = 0;     
    } 
    else 
    {
        g_AskDCCur = AskChaCur + HeatCurt;
       // if(g_AskDCCur>=115)
          //  g_AskDCCur = 115;
    }
    
  
    if((g_CellHighestVol>=CHARGE_CUTDOWN_CV1)||(ChanceCurt==1))//����Ϊ����������һ��
    {         
        timer2S++;
        if(timer2S>=100)//10*100=1000ms
        {    
            timer2S=101;                      
            if(g_AskDCCur>0.1*C)
                g_AskDCCur=0.1*C;
            //else if(g_AskDCCur==0)
            //    g_AskDCCur=0;
            ChanceCurt=1;
        }
    } 
    else 
    {
        timer2S=0;
    }
	  if(g_CellHighestVol>=HIGHEST_ALLOWED_CHARGE_CV)  //3.65Vֹͣ���
    {
        timer1S++;
        if(timer1S>=100)//10ms*100=1000ms
        {          
            if(DCFinish==0)
            {
                ChangerStopState = 1;
                SocRechargeAdjust(); //��SOC��Q1
        	      StoreParameter();
        	      DCFinish=1;
            }
            g_AskDCCur=0; 
            g_AskDCVol=0;  
            fastendflag=1;
            fastend1|=0x10;//�����ѹ�ﵽĿ��ֵ��������ֹ���
            FastEndNormalFlag=1;   //���ǹ����µ��־λ 
            timer1S=103; 
                      
        }
    } 
    else 
    {
        timer1S=0; 
    }        
    //////////////////////////////���ʱ���͹���///////////////////////////
   g_MaxChaCur = g_AskDCCur;//���ʱ������ 
    
    
    ///*******///////��䷢����Ϣ 
	  if(CHMStep)
		{     
    	  if(CHMStep==0x01)      //1801f456 00,��֡���ģ�����250ms�����ļ��10ms
    	  {

    	      counter_250ms1++;
    	      if(counter_250ms1>=25)
    	      {
        	      if(DCStartState==2)//�¹��꿪ʼ
        	      {
                    cpuToCHMBHM();
                    CRMOverTimeBefore++;
                    if(CRMOverTimeBefore>=120)//���30s���ղ���CRM��ʱ 
                    {
                        OverTimeState=1;//��ʱ��־λ��1                
                        CHMStep=0x07;
                        BEMError1|=0x01;//�ղ���CRM��30s����BEM
                        CRMOverTimeBefore = 0;
                    }
        	      }
        	      if(DCStartState==1)//���0xaa�Ƿ�ʱ
        	      {
        	          CRMOverTime++;
        			      if(CRMOverTime>=20)//�ղ���0xaa5s���ϱ�
        			      {
            			      CHMStep=0x07;
        			          OverTimeState=1;
        			          BEMError1|=0x04;
        			          CRMOverTime = 0; 
        			      } 
        	      }
    	          counter_250ms1=0;
    	          CHMStep1 = 0;
    	      }    
    	      if(CHMStep1==0)
    	      { 
    			      if(DCStartState==1)//����Ѿ����յ��ɹ��꿪ʼ
    			      {       			          
		      
        			      if(BRMStep == 0)//������Է���BRM,���������
        			      {
        			          BRMStep = 1;//�յ�CTS��,��������;������BRM����1
        			          cpuToCHMBRM();
        			          counter_250ms1=0;
        			          sendi1++;
        			      }
        			      else if((BRMStep == 1)&&(FlagBRMSend==1))
        			      {
    			              sendi1++; 
            			      if(sendi1==2)
            			          cpuToCHMBRMDATA1();
            			      else if(sendi1==3)
            			          cpuToCHMBRMDATA2();
            			      else if(sendi1==4)
            			          cpuToCHMBRMDATA3();
            			      else if(sendi1==5)
            			          cpuToCHMBRMDATA4();
            			      else if(sendi1==6)
            			          cpuToCHMBRMDATA5();
            			      else if(sendi1==7)
            			      {       			            
        			              cpuToCHMBRMDATA6();
        			              if(DC_Vesion==1)
        			              {        			                
            			              sendi1=0;
            			              FlagBRMSend = 0;
            			              //FlagBRMSend = 1;   //FOR TEST
            			              BRMStep = 0;//���յ�CRM��ʼ����BRM�Լ��´η���BRM��ʱ��
            			              CHMStep1=1;
        			              }
            			      }
            			      else if(sendi1==8)
            			      {  
            			          cpuToCHMBRMDATA7();
            			          sendi1=0;
            			          FlagBRMSend = 0;
            			          //FlagBRMSend = 1;   //FOR TEST
            			          BRMStep = 0;//���յ�CRM��ʼ����BRM�Լ��´η���BRM��ʱ��        			          
            			          CHMStep1=1;
            			      }
        			      }
        			  }
    	      }
    	  }
    		if(CHMStep==0x02)   //1801f456 aa
			  {
			      if(BRMStep == 1)//�Ѿ�������BRM��ͷ�ļ�
			      {
			          PGN[1] = 0x02;
			          J1939_TP_CM_Abort();
			          BRMStep = 0; 
			      }
			      counter_250ms2++;
			      if(counter_250ms2>=50)//500ms
			      {  
			          CHMStep2=0;
			          counter_250ms2=0;
			      }
			      if(CHMStep2==0)
			      { 
    			      if(BCPStep==0)
    			      {
    			          BCPStep = 1;
    			          sendi2++;
    			          cpuToCHMBCP();
    			          counter_250ms2=0;
    			      } 
    			      else if((FlagBCPSend)&&(BCPStep==1))
    			      {
        			      sendi2++;
        			      if(sendi2==2)
        			          cpuToCHMBCPDATA1();
        			      else if(sendi2==3)
        			      {
        			          sendi2=0;
        			          cpuToCHMBCPDATA2();
        			          CHMStep2=1;
        			          BCPStep = 0;
        			          FlagBCPSend = 0;
        			          //FlagBCPSend = 1; //FOR TEST
        			      }
    			      }
			      }
			  }
			  if(CHMStep==0x03)  //1808f456 aa 250ms
  		  {            
            
            if(BCPStep == 1)
            {
                PGN[1] = 0x06;
			          J1939_TP_CM_Abort();
                BCPStep = 0;
            }
            counter_250ms3++;
            if(CHMStep3==0)
            {
                CROOverTime++;
                if(SelfState3==0)
          			    cpuToCHMBRO();  //100956f4 aa
                if((CROOverTime>=21)||(CROOverTime60s>=240))//�յ�CRO,��û���յ�0xaa,5s��ʱ 
                {
                    OverTimeState=1;//��ʱ��־λ��1                
                    CHMStep=0x07;
                    BEMError2|=0x04;
                    CROOverTime = 0;
                    CROOverTime60s = 0;
                }
                if(BROErrorAA==1)//���׮������������
                {
                    CHMStep=0x07;
                    BEMError4|=0x04;//��������                
                } 
                else if(0==BROErrorAA)
                {
                    CROOverTime60s++;
                    TurnOnChangerRelay = 1;
                }
                   
                CHMStep3=1;
            }
            if(counter_250ms3>=25)//ȷ����һ֡���ݷ�������������ʱС��250ms
            {
              
  			        counter_250ms3=0;
  			        CHMStep3=0;
  			        
            }
  		  }
    	if((CHMStep==0x04)||(CHMStep==0x05)) //50ms����
        {
            CCSOverTime++;
            if(CCSOverTime>=100)//10ms*100=1S
            //if(CCSOverTime>=500)//10ms*500=5S//for test
            {
                OverTimeState=1;//��ʱ��־λ��1
                if(CHMStep<=0x07)                
                    CHMStep=0x07;
                BEMError3|=0x01;
                CCSOverTime = 0;    
            }
            
            if(SetBST)
                CCSOverTime = 0;      //��ֹ���ڹ��ϣ�����BST�󣬳������CCS��ʱ
            
            if(counter_50ms>=5)//50ms 
            {			            
                cpuToCHMBCL();    // voltage request and current request
                counter_50ms=0;
            }
            counter_50ms++;
  		      counter_250ms4++;      //250ms
  		      if(counter_250ms4>=25)
  		      {
  		        
  		          CHMStep4_5=0;
  		          counter_250ms4=0;
  		      }
  		      if(CHMStep4_5==0)
  		      {			        
    			      
    			      if(BCSStep==0)
    			      { 
    			          sendi1++;
    			          cpuToCHMBCS();
    			          BCSStep = 1;
    			          counter_250ms4 = 0;
    			      } 
    			      else if((BCSStep == 1)&&(FlagBCSSend==1))
    			      {
    			          sendi1++;
        			      if(sendi1==2)
        			      {
        			          cpuToCHMBCSDATA1();
        			      }
        			      else if(sendi1==3)
        			      {
        			          sendi1=0;
        			          cpuToCHMBCSDATA2();
        			          CHMStep4_5=1;
        			          BCSStep = 0;     //�ϸ�,����Ӧ�����յ�ֹͣ���ĺ�
        			          FlagBCSSend = 0; //�ϸ�,����Ӧ�����յ�ֹͣ���ĺ�
        			          //FlagBCSSend = 1; //FOR TEST
        			      }
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
                if(counter_250ms5>=25)//ȷ����һ֡���ݷ�������������ʱС��250ms
                {
                  
      			        counter_250ms5=0;
      			        CHMStep5=0;
      			        
                }
            }
  		  }
			  if((CHMStep==0x06)||((CHMStep==0x05)&&(fastendflag==1)))//10ms����һ��,��ʼ����ʱ��	
    		{
    			  //����յ������������ֹ���Ļ��ߵ����ѹ���ܵ�ѹ��������ֵ
			      if(BCSStep == 1)
    		      {
    		          PGN[1] = 0x11;
  	              J1939_TP_CM_Abort();
    		          BCSStep = 0;
    		      }
    			  if(OverTimeState==1)
    			  {
    			      if(counter_250ms6_1%25==0)
    			      {    			        
    			          counter_250ms6_1 = 0;
    			          cpuToCHMBEM();
    			      }
    			      counter_250ms6_1++;
    			  }
    			  if(SetBSD==0)//���BSD�Ѿ�����,��BST���ٷ���
    			  {   			    
    			      cpuToCHMBST();
    			      SetBST=1;
    			      g_AskDCCur=0;//�������Ϊ0
        			  CSTOverTime++;//10ms*200
    			      if(CSTOverTime>=500)//��ֹ�ղ���CST����5s��ʱ,10ms*500 
    			      {
        			      CHMStep=0x07;
        			      OverTimeState = 1;
        			      BEMError3|=0x04;
        			      CSTOverTime = 0;
    			      }
    			  }
        	if(CHMStep6==0)
                {   
                    cpuToCHMBSD();  // report BMS status: the highest and the lowest cell voltage, temperature and SOC.
                    SetBSD = 1;
                    CHMStep6=1;
                }
                counter_250ms6++;
    			      if(counter_250ms6>=25)
    			      {
      			        counter_250ms6=0;
      			        CHMStep6=0;			                       
    			      }
    			      CSDOverTime++;
    			      if(CSDOverTime>=1000)//���ղ�������ͳ�Ʊ���ʱ,��ʱ10s�µ�
    			      {
    			          CHMStep=0x07;
    			          OverTimeState = 1;
    			          BEMError4|=0x01;
    			          CSDOverTime = 0;     			          
    			      }    			      
    			      
    			  }
			  }       
			  if(CHMStep==0x07) //�������� 
			  {     
	          if(counter_250ms7%25==0)
	          {
	              if((OverTimeState==1)||(BROErrorAA==1))//����г�ʱ���ϲ��ϱ�,û�в��ϱ�
	              {	                
	                  if(BEMStop==0)
	                      cpuToCHMBEM();
	              }
	              counter_250ms7 = 0;
	          }
	          counter_250ms7++;
	          OffState=1;//״̬����170��ת40�ı�־λ               
			  }
												
		}/////////END��䷢����Ϣ

		

//******************************************************************************
//* Function name:   TaskDC
//* Description:     10ms�ж��е��øú���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void TaskDC(void)
{  
    if(FASTRECHARGING==g_BmsModeFlag)
    {
        if(DCStartState == 0)//�����յ�֮�󣬲��ټ�ʱ
            CRMOverTimeBefore60s++;        
        if(CRMOverTimeBefore60s>=6000)//10ms*6000
        {
            OverTimeState=1;//��ʱ��־λ��1                
            CHMStep=0x07;
            BEMError1|=0x01;//�ղ���CRM��30s����BEM
            CRMOverTimeBefore60s = 0;      
        }
        TaskRechargeDC();
    }
}
//******************************************************************************
//* Function name:   GetDCTem
//* Description:     ���ֱ�������¶�
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void GetDCTem (void)
{
    float getAD1=0;//ADֵ1
    float getAD2=0;//ADֵ2
    float VolValue1=0;//ת����ĵ�ѹֵ1
    float VolValue2=0;//ת����ĵ�ѹֵ2
    
    float R1=0;//�¸�ͷ1��ֵ
    float R2=0;//�¸�ͷ2��ֵ  
     
    getAD1 = readADC_Differential_0_1();
    getAD2 = readADC_Differential_2_3();
    //EnableInterrupts; //���жϣ�����״̬������ 
    VolValue1=4.096*getAD1/2048.0;
    VolValue2=4.096*getAD2/2048.0;
    
    R1=VolValue1/(5-VolValue1)*10;
    R2=VolValue2/(5-VolValue2)*10;
    
    g_DCTemp1=LookupTem(VolValue1);
    if(g_DCTemp1<0)
        g_DCTemp1=0;
    g_DCTemp2=LookupTem(VolValue2);
    if(g_DCTemp2<0)
        g_DCTemp2=0;


} */
//******************************************************************************
//* Function name:   GetDCTem
//* Description:     ���ֱ�������¶�
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************

void GetDCTem (void)
{
    float getTemAD1=0;//�¶�ADֵ1
    float getTemAD2=0;//�¶�ADֵ2
    
    
    float getPowerAD=0;//��ѹ��ѹADֵ2
    float getCC2AD=0;//CC2��ADֵ
        
    float Tem1VolValue1=0;//ת����ĵ�ѹֵ1
    float Tem2VolValue2=0;//ת����ĵ�ѹֵ2
    

    float GetVol1 = 0;
    float GetADVol2 = 0;
    
    float CC2VolValue = 0;// CC2��ѹ
    float PowerVolValue = 0;//��Դ��ѹ
    
    float R1=0;//�¸�ͷ1��ֵ
    float R2=0;//�¸�ͷ2��ֵ  
     
     
    getTemAD1 = readADC_SingleEnded(0); //DC1�¶�
    getTemAD2 = readADC_SingleEnded(3); //DC2�¶�
  
    
    Tem1VolValue1=4.096*getTemAD1/2048.0;
    Tem2VolValue2=4.096*getTemAD2/2048.0;
    
    
    //R1=VolValue1/(5-VolValue1)*10;
    //R2=VolValue2/(5-VolValue2)*10;
    
    g_DCTemp1=LookupTem(Tem1VolValue1);
    if(g_DCTemp1<0)
        g_DCTemp1=0;
    g_DCTemp2=LookupTem(Tem2VolValue2);
    if(g_DCTemp2<0)
        g_DCTemp2=0;
    
    
    
    getPowerAD = readADC_SingleEnded(2); //��Դ��Դ
    getCC2AD = readADC_SingleEnded(1); //CC2��ѹ
    
    CC2VolValue=4.096*getCC2AD/2048.0; //cc2
    PowerVolValue=4.096*getPowerAD/2048.0; //��Դ��ѹ
    
    CC2VOL = (75.0+12.0)*CC2VolValue/12.0; //CC2��ѹ
    
    PowerVOL = (75.0+12.0)*PowerVolValue/12.0; //��Դ��ѹ
        
    


}

//******************************************************************************
//* Function name  : Time_CHG_PlugIn
//* Description    : �����ǹ����ʱ��/CC2   
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void Time_CHG_PlugIn(void)
{
	  I2CReadDate();  //��ȡϵͳʱ��	  
    ChaInSecondBCD = CurrentTime[0];  //��
    ChaInMinuteBCD = CurrentTime[1];  //��
    ChaInHourBCD = CurrentTime[2];    //ʱ
}
//******************************************************************************
//* Function name  : Time_CHG_PullOut
//* Description    : �����ǹ�ε�ʱ��/CC2     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void Time_CHG_PullOut(void)
{
	  I2CReadDate();  //��ȡϵͳʱ��
	  ChaOutSecondBCD = CurrentTime[0];  //��
	  ChaOutMinuteBCD = CurrentTime[1];  //��
    ChaOutHourBCD = CurrentTime[2];    //ʱ

}

//******************************************************************************
//* Function name  : Time_CHG_Start
//* Description    : ��俪ʼʱ��   
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void Time_CHG_Start(void)
{
	  I2CReadDate();  //��ȡϵͳʱ��
	  ChaBeginSecondBCD= CurrentTime[0];  //��
	  ChaBeginMinuteBCD= CurrentTime[1];  //��
    ChaBeginHourBCD= CurrentTime[2];  //ʱ

}

//******************************************************************************
//* Function name  : Time_CHG_Stop
//* Description    : ������ʱ��   
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void Time_CHG_Stop(void)
{
	  I2CReadDate();  //��ȡϵͳʱ��
	  ChaEndSecondBCD = CurrentTime[0];  //��
	  ChaEndMinuteBCD = CurrentTime[1];  //��
    ChaEndHourBCD= CurrentTime[2];     //ʱ

}