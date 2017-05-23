/*-------------------------------------------------------------------------
File name: Process.c
Writen by Judy
Date: ,2010
Discription:
*/
#include "derivative.h" /* include peripheral declarations */
#include "BMS20.h" 
#include "mscan.h"
#include "bmn.h"
#include "dflash.h" 


unsigned char socadjflag=0;
char mbackcout=0;
char mbackcout1=0;
char mbackcout2=0;
unsigned char  flagf5; //�¶�<0��
unsigned char  flag7; //�¶�0-15��
unsigned char  flag25;//�¶�15-35��
unsigned char  flag45;//�¶�35-50��
unsigned char  flag60;//�¶�>50��
unsigned char  tempflag;//�¶������ж�
unsigned char  feedflag=0; //�¶�0-15�����־λ
unsigned char  feedflag1=0; //�¶�15-35�����־λ
unsigned char  feedflag2=0;//�¶�35-50�����־λ
unsigned char  imflag=0; //�¶�0-15�������ֵ�����־
unsigned char  imflag1=0; //�¶�15-35�������ֵ�����־
unsigned char  imflag2=0;//�¶�35-50�������ֵ�����־
unsigned int  icount=0; //�¶�0-15��������
unsigned int  scount=0; //�¶�0-15����S����
unsigned int  icount1=0; //�¶�15-35��������
unsigned int  scount1=0; //�¶�15-35����S����
unsigned int  icount2=0; //�¶�35-50��������
unsigned int  scount2=0; //�¶�35-50����S����
unsigned char fastendflag=0;
unsigned char sendi1=0;
unsigned char sendi2=0;
unsigned char cellsendcount=0;
unsigned char cellsenddelay=0;
unsigned char imcount=1;
unsigned char imcount1=1;
unsigned char imcount2=1;


float g_socValue=0;  //ʵ��SOC
float g_displaySocValue = 0;//��SOCֵ������ʾ���͸����������������SOC
float g_energyOfUsed=0; //���õ������
float g_leftEnergy=0;    //ʣ��������
float g_usefulCapacity;//���õ������
//unsigned int g_isolution = 1000; //��Ե����ֵ
unsigned int g_isolationP_high;
unsigned int g_Rp=1000;
unsigned int g_Rn=1000;
unsigned int g_isolationP_low;
unsigned int g_isolationN_high;
unsigned int g_isolationN_low;
unsigned char g_isolationLever ;


unsigned char g_chargeStateFlag = 0; //0:��� 1:�ŵ�
unsigned char g_bmubalance = 0; //0:��� 1:�ŵ�
//unsigned char g_rechargerState;  // 0: ready  1:recharging 2: end recharge 3:recharge error
unsigned int g_chargerCurrent=0; //������ǰ������
unsigned int g_chargerVoltage=0; //������ǰ����ѹ
float g_uppestRechargeCurrent =0;//������������
float g_uppestDischargeCurrent =0;//�������ŵ����
float g_feedbackChargeCurrent;//�������ŵ����

/////
unsigned int g_isrTimes = 0; //�жϴ���
unsigned long g_BMU_CIRCLE_FLAG =0; //��������BMU����
//
float g_systemCurrent=0;
float	g_highVoltageV1=0;
float g_highVoltageV2=0; //Ԥ���̵�����Ԥ�����֮��ĵ�ѹ
float g_highVoltageV3 =0;//Ԥ���̵�����һ�ߵĵ�ѹ

//**********M30�����͹���****************
unsigned int tmr_p2 =0;
unsigned int tmr_p3 =0;
unsigned char innerVoltFault =0;
unsigned char outVoltFault =0;
unsigned char currenFault =0;
unsigned char insulationFault =0;
unsigned char innerCanFault = 0;

unsigned char msdFault =0; //MSD���ϱ�־
unsigned char relayNconnected =0; //�����̵���ճ��
unsigned char relayNdisconnected =0;// �����̵����Ͽ�����
unsigned char relayPrechargeConnected =0; //Ԥ��̵���ճ��
unsigned char  prechargeFinished =0;    //Ԥ�����ɱ�־λ
unsigned char  bcuSelfcheckCounter =0; //BCU�Լ������
//*********************************************
unsigned char  fastend1=0;
unsigned char  fastend2=0;
unsigned char  fastend3=0;
unsigned char  fastend4=0;
unsigned char  fasterror11 =0;
unsigned char  fasterror12 =0;

unsigned char ChgeStat=0;//���״̬
unsigned char Htr2ChgeDly=0;  //���ȵ����ת��ʱ����
unsigned char ChgeAmpReq=0; //������ֵ
unsigned int counter_500ms=0;
unsigned char counter_500ms1=0;
unsigned char counter_50ms=0;
unsigned char counter_250ms=0;

unsigned long chargerID;
unsigned long vehicleID;

unsigned long g_mboxID; //CAN2 ���յ��ı���ID�ţ�Ҳ����BMU�ı���ID
unsigned char g_mboxData[1][8];// CAN2���յ��ı������ݣ�ÿ������8���ֽ�
unsigned char can2receiveIsReady;//can2����������

unsigned int g_ParaEndFlag=0;
unsigned int g_endPowerOffFlag=0;

unsigned long sumAhCharge=0;
unsigned long sumAhDischarge=0;

unsigned long sumAhChargeOnce=0;
unsigned long sumAhDischargeOnce=0;

//************************************************************************
//************************************************************************
static void delay(unsigned int t) 
{ 
    while(t--); 
}

//************************************************************************
//************************************************************************
void LoadParamter(void)
{	
  	Rd_Flash(ParaBaseAddr,(unsigned char* )g_sysPara,ParamNUMBER*4);  //�����������ϵͳ����
  	Rd_Flash(ParaBaseAddr,(unsigned char* )g_sysPara,ParamNUMBER*4);  
  	g_uppestRechargeCurrent = g_sysPara[PARA_HIGHEST_RECHARGE_CURRENT];  //������������
  	g_feedbackChargeCurrent = g_sysPara[PARA_HIGHEST_RECHARGE_CURRENT];
  	g_uppestDischargeCurrent = g_sysPara[PARA_HIGHEST_DISCHARGE_CURRENT];  //���ŵ���������
  	
    g_BMU_CIRCLE_FLAG = 0x0000011;	//4��BMU
	  /*
  	switch((unsigned int)g_sysPara[PARA_BMU_NUMBER])//����BMU�ĸ�����ȷ����Ӧ��������Ϣ���ܹ�֪���Ƿ����еĵ��������Ѿ�����һ��
  	{
  	  case 1:
  	    g_BMU_CIRCLE_FLAG = 0x0000001;
  	    break;
  	  case 2:
  	    g_BMU_CIRCLE_FLAG = 0x0000011;
  	    break; 
  	  case 3:
  	    g_BMU_CIRCLE_FLAG = 0x0000111;
  	    break;  
  	  case 4:
  	    g_BMU_CIRCLE_FLAG = 0x0001111;
  	    break; 
  	  case 5:
  	    g_BMU_CIRCLE_FLAG = 0x0011111;
  	    break;
  	  case 6:
  	    g_BMU_CIRCLE_FLAG = 0x0111111;
  	    break;  
  	  case 7:
  	    g_BMU_CIRCLE_FLAG = 0x1111111;
  	    break;      
  	  default:
  	    break;
    }  
    */

}
//************************************************************************
//************************************************************************
void StoreParameter(void)
{
	  //W25X_SectorErase(ParaBaseAddr);		
	  Wrt_Flash(ParaBaseAddr,(unsigned char* )g_sysPara,ParamNUMBER*4);  //����д��ϵͳ����
}
//************************************************************************
//************************************************************************
void StoreSocRealvalue(void)//
{
    g_sysPara[PARA_SOC_VALUE]=g_socValue;
    Wrt_Flash(ParaBaseAddr,(unsigned char* )g_sysPara,4);  //ֻ�����µ�SOCֵ�����ϵͳ����ֵ����
}
void StoreTotalAH(void)
{
     unsigned char AHbyte[8];
     
     //sumAhCharge =0;
     AHbyte[0]= (sumAhCharge&0xff000000)>>24;
     AHbyte[1]= (sumAhCharge&0x00ff0000)>>16;
     AHbyte[2]= (sumAhCharge&0x0000ff00)>>8;
     AHbyte[3]= sumAhCharge;
     //sumAhDischarge =0;
     AHbyte[4]= (sumAhDischarge&0xff000000)>>24;
     AHbyte[5]= (sumAhDischarge&0x00ff0000)>>16;
     AHbyte[6]= (sumAhDischarge&0x0000ff00)>>8;
     AHbyte[7]= sumAhDischarge;
     Wrt_Flash(SUM_AH_ADDRESS,AHbyte,8);  //�����ܵĳ�ŵ�������AD161�� ��λΪA
     
}
void LoadTotalAH(void) 
{
     unsigned char AHbyte[8];
     
     Rd_Flash(SUM_AH_ADDRESS,AHbyte,8);
     sumAhCharge = (AHbyte[0]&0x000000ff)<<24; 
     sumAhCharge |= (AHbyte[1]&0x000000ff)<<16; 
     sumAhCharge |= (AHbyte[2]&0x000000ff)<<8; 
     sumAhCharge |= AHbyte[3];
     sumAhDischarge =0;
     sumAhDischarge = (AHbyte[4]&0x000000ff)<<24; 
     sumAhDischarge |= (AHbyte[5]&0x000000ff)<<16; 
     sumAhDischarge |= (AHbyte[6]&0x000000ff)<<8; 
     sumAhDischarge |= AHbyte[7];

}


//************************************************************************
///////////����ƽ���¶ȵ���������������  ������
//************************************************************************
void BigRechargeCurrentAdjust(void) //
{
    g_uppestRechargeCurrent =  g_sysPara[PARA_HIGHEST_RECHARGE_CURRENT];
    if((g_averageTemperature-40)>=50) 
        g_uppestRechargeCurrent = 0;
    else if((g_averageTemperature-40)>=45)
        g_uppestRechargeCurrent = g_usefulCapacity*0.2;
    else if((g_averageTemperature-40)>=20)
        g_uppestRechargeCurrent = g_usefulCapacity*0.5;
    else if((g_averageTemperature-40)>=10)
        g_uppestRechargeCurrent = g_usefulCapacity*0.3;
    else if((g_averageTemperature-40)>=5)
        g_uppestRechargeCurrent = g_usefulCapacity*0.2;
    else if((g_averageTemperature-40)>=0)
        g_uppestRechargeCurrent = g_usefulCapacity*0.1;
    else
        g_uppestRechargeCurrent =0;
}
//*************************************************************************
void FeedbackCurrentAdjust(void)
{
    float m_ccurrent;
    
    //�ò��ִ���ԭ��Ϊ����ֹ�¶����ٽ�����ʱ���¶��������䣬����������������쳣���� 
    if(g_averageTemperature>=40) 
        flag7=1;
    else 
        flagf5=1;
    if(g_averageTemperature>=55) 
        flag25=1;
    if(g_averageTemperature>=75) 
        flag45=1;
    if(g_averageTemperature>=90) 
        flag60=1;
    //////�¶Ȼ�����������ܲ�����ָ�����	
	  if(g_averageTemperature<39)
	      flag7=0;
	  if(g_averageTemperature<54)
	      flag25=0;
	  if(g_averageTemperature<74)
	      flag45=0;
		
	  if(flag60==1) 
	  {
	      m_ccurrent=0;
	      tempflag=5;
	  }
	  else if(flag45==1) 
	  {
	      m_ccurrent=t45m;
	      tempflag=4;
	  }
	  else if(flag25==1) 
	  {
	      m_ccurrent=t25m;
	      tempflag=3;
	  }
	  else if(flag7==1) 
	  {
	      m_ccurrent=t7m;
	      tempflag=2;
	  }
	  else if(flagf5==1) 
	  {
	      m_ccurrent=0;
	      tempflag=1;
	  }

  	if(tempflag==2)   //����0-15������
	  {	
		    if(g_systemCurrent<=(0-t7l))//���ڳ�������ֵ10S
		    {
			      scount++;
			      if(scount <=99) 
			          feedflag=0; //10S=100ms*100
			      else if(scount >99) 
			          feedflag=1;//���������׼��1	
		    }
		    if(feedflag==0)//�޷��������׼
		    {
			      if(g_systemCurrent>(0-t7l))//�������������ֹ����ڵ�ǰ�¶��¿ɽ��ܵ���������������ʱ
			          scount=0;
		    }
		    if(g_systemCurrent<=(0-t7m))//�������ֵ2S
		    {
			      if(++mbackcout>=20) //2S=100ms*20	
			      {
				        imflag=1;//0-15������������ֵ��־
			      }
		    }
    }
	  else if(tempflag==3)  //����15-35������
	  {	
		    if(g_systemCurrent<=(0-t25l))//���ڳ�������ֵ30S
		    {
			      scount1++;
			      if(scount1<=280) 
			          feedflag1=0;
			      else if(scount1>280) 
			          feedflag1=1;	
		    }
		    if(feedflag1==0)
		    {
			      if(g_systemCurrent>(0-t25l))
			          scount1=0;
		    }

		    if(g_systemCurrent<=(0-t25m))//�������ֵ2S
		    {
			      if(++mbackcout1>=20)	
			      {
				        imflag1=1;
			      }
		    }
    }
	  else if(tempflag==4)
	  {	
		    if(g_systemCurrent<=(0-t45l))//���ڳ�������ֵ10S
		    {
			      scount2++;
			      if(scount2<=99) feedflag2=0;
			      else if(scount2>99) feedflag2=1;	
		    }
		    if(feedflag2==0)
		    {
			      if(g_systemCurrent>(0-t45l))
			      scount2=0;
		    }		
		    if(g_systemCurrent<=(0-t45m))//�������ֵ2S
		    {
			      if(++mbackcout2>=20)	
			      {
				        imflag2=1;
			      }
		    }
    }
    /////�����崦��
	  if(feedflag==1)//����Ѵ��ڷ���
	  {
		    icount++;
		    if(g_systemCurrent<-0.1)// �������ڷ�������
		    {
			      if(icount<=50) 
			          m_ccurrent=t7m-(t7m-t7l)*icount/50;
			      else  
			          m_ccurrent=t7l;
		    }
	  }
	  else if(feedflag1==1)  //ȷ����һ������������������ܿ�ʼ
	  {
		    icount1++;
		    if(g_systemCurrent<-0.1)
		    {
			      if(icount1<=50) 
			          m_ccurrent=t25m-(t25m-t25l)*icount1/50;
			      else  
			          m_ccurrent=t25l;
		    }
	  }
	  else if(feedflag2==1)  //ȷ����һ������������������ܿ�ʼ
	  {
		    icount2++;
		    if(g_systemCurrent<-0.1)
		    {
			      if(icount2<=50) 
			          m_ccurrent=t45m-(t45m-t45l)*icount2/50;
			      else  
			          m_ccurrent=t45l;
		    }
	  }
    /////END�����崦��
	  /////////////////�����ֵ���崦��
	  if(imflag==1)
	  {
		    m_ccurrent=t7m-imcount;
			  if(imcount++>30)
			      imcount=30;
			  if(m_ccurrent<t7l)
				    m_ccurrent=t7l;
	  } 
	  else if(imflag1==1)
	  {
			  m_ccurrent=t25m-imcount1*2.5;
			  if(imcount1++>30)
			      imcount1=30;
			  if(m_ccurrent<t25l)
				    m_ccurrent=t25l;
	  }
	  else if(imflag2==1)
	  {
			  m_ccurrent=t45m-imcount2*0.7;
			  if(imcount2++>30)
			      imcount2=30;
			  if(m_ccurrent<t45l)
				    m_ccurrent=t45l;	
	  } 
	  else
	  {
	      imcount=1;
	      imcount1=1;
	      imcount2=1;
	  }

    //////////END ���ֵ����
	  if(g_systemCurrent>=-0.1)//�޷��������󣬼��������㣬����δ����״̬��
	  {
  	    feedflag=0;	
  	    imflag=0;
  	    feedflag1=0;	
  	    imflag1=0;	    
  		  scount=0;
  		  icount=0;
  		  feedflag2=0;	
  		  imflag2=0;		  
  		  scount2=0;
  		  icount2=0;
  		  scount1=0;
  		  icount1=0;
  		  mbackcout2=0;
  		  mbackcout1=0; 
  		  mbackcout=0;
  		  
  		  imcount=1;
  		  imcount1=1;
  		  imcount2=1;
  		  if(tempflag==2) 
  		      m_ccurrent=t7m;
  		  else if(tempflag==3) 
  		      m_ccurrent=t25m;
  		  else if(tempflag==4) 
  		      m_ccurrent=t45m;
    }
    
    if((g_socValue>=0.9)||(g_highVoltageV1>=400)||(g_highestCellVoltage>=4.3)) //����SOC>=90%ʱ�����������������ȼ���ߡ�
	  {
    		m_ccurrent=0;
    		feedflag=0;	
    		imflag=0;
    		feedflag1=0;	
    		imflag1=0;
    		scount=0;
    		icount=0;
    		feedflag2=0;	
    		imflag2=0;
    		scount2=0;
    		icount2=0;
    		scount1=0;
    		icount1=0;
    		mbackcout2=0;
    		mbackcout1=0; 
    		mbackcout=0;
    		imcount=1;
    		imcount1=1;
    		imcount2=1;
	  }

    g_feedbackChargeCurrent=  m_ccurrent;
    //g_sysPara[PARA_HIGHEST_RECHARGE_CURRENT]=  m_ccurrent;
}
//************************************************************************
//************************************************************************
void BigDischargeCurrentAdjust(void)
{
    float tem =0;
    
    if(g_averageTemperature==0)
        return;
    
    if(g_socValue<0.1) 
    {
        g_uppestDischargeCurrent =10;
        return;
    }
    
    if(g_averageTemperature<40-30)
        g_uppestDischargeCurrent =0;
    
    if(40-30<=g_averageTemperature<40-20)
        g_uppestDischargeCurrent =10;    
    
    if(40-20<=g_averageTemperature<=40+45) 
    {
        if(g_socValue>=0.3) 
        {          
            g_uppestDischargeCurrent = 50+g_socValue*100 + 5*(float)(g_averageTemperature-40);
            if(g_uppestDischargeCurrent>=200)
                g_uppestDischargeCurrent = 200;            
            if(g_uppestDischargeCurrent<=40)
                g_uppestDischargeCurrent = 40;
        } 
        else //if(0.1<g_socValue<0.3)
        {
            tem = 80+ 5*(float)(g_averageTemperature-40);
            if(tem<204)
                g_uppestDischargeCurrent= tem - (30-g_socValue*100)*10;
            else
                g_uppestDischargeCurrent= 200 - (30-g_socValue*100)*10;
            if(g_uppestDischargeCurrent<40) 
                g_uppestDischargeCurrent=40;
        }            
    } 
    else if(40+45<g_averageTemperature<=40+50)
    {
         if(g_socValue>=0.3) 
         {
             g_uppestDischargeCurrent=200- ((float)g_averageTemperature-40-45)*4;
         }
         else //if(0.1<g_socValue<0.3)
         {
             g_uppestDischargeCurrent=200- ((float)g_averageTemperature-40-45)*4 - (30-g_socValue*100)*4;
         }
    }
    else if(40+50<g_averageTemperature<=40+55) 
    {
         if(g_socValue>=0.3) 
         {
             g_uppestDischargeCurrent= 180 - ((float)g_averageTemperature-40-50)*20;
         }
         else //if(0.1<g_socValue<0.3)
         {
             g_uppestDischargeCurrent= 180 - ((float)g_averageTemperature-40-50)*20 - (30-g_socValue*100)*4 ;
         }
         if(g_uppestDischargeCurrent<40) 
               g_uppestDischargeCurrent=40;
         
    } 
    else if(g_averageTemperature>40+55) 
    {
         g_uppestDischargeCurrent=10;
    }
    
}
//************************************************************************
///////////����ƽ���¶ȵ�����������������������  ��VCU
//************************************************************************
float PulseRechargeCurrentAdjust(void) 
{
   float current;
   
   current =  0;
   if(g_socValue>0.98)
       return current;
   if(g_averageTemperature<= 35) //-5��
       return current;   
   else if(g_averageTemperature<=40) 
       if((g_socValue>=0.75)&&(g_socValue<=0.85)) 
           current =  g_sysPara[PARA_WHOLE_CAPACITY]; // 1c/10s
   else if(g_averageTemperature<=50)
       if((g_socValue>=0.75)&&(g_socValue<=0.95)) 
           current =  g_sysPara[PARA_WHOLE_CAPACITY]; //1c/10s
   else if(g_averageTemperature<=63) //
   {    
       if((g_socValue>=0.75)&&(g_socValue<=0.85)) 
           current =  g_sysPara[PARA_WHOLE_CAPACITY]*1.5;  //1.5c
       if((g_socValue>0.85)&&(g_socValue<=0.98)) 
           current =  g_sysPara[PARA_WHOLE_CAPACITY]; //1c/10s
   } 
   else if(g_averageTemperature<=90) 
   {
       if((g_socValue>=0.75)&&(g_socValue<=0.85)) 
           current =  g_sysPara[PARA_WHOLE_CAPACITY]*2; // 2c
       if((g_socValue>0.85)&&(g_socValue<=0.95)) 
           current =  g_sysPara[PARA_WHOLE_CAPACITY]*1.5; //1.5
       if((g_socValue>0.95)&&(g_socValue<=0.98)) 
           current =  g_sysPara[PARA_WHOLE_CAPACITY];  //1c
   }
   
   return (current);
}

//************************************************************************
////////�ų������¶�����//////////////////////////////////////////////
//************************************************************************
float TemperatureAdjustForCap(float capacity,unsigned char tem) 
{
    float x,y;
    unsigned char t;        
    
    x= capacity;
    return x;
   /* 
    y=0;
    t= tem;
    
    if(t>17+40)
       y=x;
    else if(t>=12+40)
       y=0.986*x-0.083;
    else if(t>=7+40)
       y=0.949*x-0.039;
    else if(t>=3+40)
       y=0.912*x+0.133;
    else if(t>=37)
       y=0.869*x-0.849;
    else if(t>=32)
       y=0.833*x-2.3;
    else if(t>=27)
       y=0.761*x-3.273;
    else if(t>=22)
       y=0.651*x-2.772;
    else
       y=0.579*x-3.341;
    
    return y;
   */ 


}
//************************************************************************
// ����ƽ���¶ȡ�������ߵ�ѹ���������͵���ƽ����ѹ��SOC���е���
//************************************************************************
void SocRechargeAdjust(void)//���SOC�����ӳ���
{
      /*
      if(g_averageTemperature<40)  //���ƽ���¶�С��10���϶ȣ�����Ҫ������50��Ӧ10��
      //if(g_averageTemperature>=20+40)  //���ƽ���¶�С��20���϶ȣ�����Ҫ������
          return;
      
      //if(g_highestCellVoltage<=3.60)  //��������ѹС��3.6 ������
      if(g_highestCellVoltage<4.15)  //��������ѹС4.2 ������
          return;
      
      if(g_averageVoltage<3.95) //averageVoltage under 3.95V Don't need adjust
          return;
      else if((g_averageVoltage>=3.95)&&(g_averageVoltage<4.2))
      {
           if(socadjflag==0)
           {
               g_socValue=(148*g_averageVoltage-515+0.45*(g_averageTemperature-63))*0.01;
               socadjflag=1;
           }
           if(g_socValue>=1.0)
               g_socValue=0.99;
           g_leftEnergy = g_socValue*(g_usefulCapacity*3600);
           g_energyOfUsed =0; 
      }
     */   
      //if((-g_systemCurrent) >= g_sysPara[PARA_WHOLE_CAPACITY]*1)  //�������������1c,������  PARA_WHOLE_CAPACITY
      //  return;
  /*    
      if((-g_systemCurrent) >=g_sysPara[PARA_WHOLE_CAPACITY]*0.6)  //
      {
          if(g_averageVoltage>=3.50) 
          {
              if(g_socValue<0.99)
                  g_socValue=0.99;
              
          }           
          else if(g_averageVoltage>=3.45) 
          {
              if(g_socValue<0.98)
                  g_socValue=0.98;  
                      
          } 
          else if(g_averageVoltage>=3.40) 
          {
              if(g_socValue<0.8)
                  g_socValue=0.8; 
              else if(g_socValue>0.98)
                  g_socValue=0.98;               
                      
          } 
          else 
          {
               if(g_socValue>0.8)
                  g_socValue=0.8; 
                       
          }          
      }  // end if 0.6 ��1c 
      else if((-g_systemCurrent) >= g_sysPara[PARA_WHOLE_CAPACITY]*0.4)  //
      {
          if(g_averageVoltage>=3.50) 
          {
              if(g_socValue<0.99)
                  g_socValue=0.99;
              
          }           
          else if(g_averageVoltage>=3.45) 
          {
              if(g_socValue<0.98)
                  g_socValue=0.98;  
                       
          } 
          else if(g_averageVoltage>=3.40) 
          {
              if(g_socValue<0.9)
                  g_socValue=0.9; 
              else if(g_socValue>0.98)
                  g_socValue=0.98;               
                    
          } 
          else 
          {
               if(g_socValue>0.9)
                  g_socValue=0.9; 
                       
          } 
      
      } // end if 0.4 ��0.6c 
      else if((-g_systemCurrent) >= g_sysPara[PARA_WHOLE_CAPACITY]*0.2)  //
      {
          if(g_averageVoltage>=3.50) 
          {
              if(g_socValue<0.99)
                  g_socValue=0.99;
              
          }           
          else if(g_averageVoltage>=3.45) 
          {
              if(g_socValue<0.98)
                  g_socValue=0.98;  
                       
          } 
          else if(g_averageVoltage>=3.40) 
          {
              if(g_socValue<0.95)
                  g_socValue=0.95; 
              else if(g_socValue>0.98)
                  g_socValue=0.98;               
                      
          } 
          else 
          {
               if(g_socValue>0.95)
                  g_socValue=0.95; 
                     
          }       
      }  // end if 0.2 ��0.4c
      else//
      {
          if(g_averageVoltage>=3.45) 
          {
              if(g_socValue<0.99)
                  g_socValue=0.99;      
          } 
          else if(g_averageVoltage>=3.42) 
          {
              if(g_socValue<0.98)
                  g_socValue=0.98; 
              else if(g_socValue>0.99)
                  g_socValue=0.99;                         
          } 
          else if(g_averageVoltage>=3.40) 
          {
               if(g_socValue<0.96)
                  g_socValue=0.96; 
               else if(g_socValue>0.98)
                  g_socValue=0.98; 
               
          } 
          else  if(g_averageVoltage>=3.38) 
          {
                if(g_socValue<0.93)
                  g_socValue=0.93; 
               else if(g_socValue>0.96)
                  g_socValue=0.96; 
          } 
          else 
          {
              if(g_socValue>=0.93)
                 g_socValue>=0.93; 
          }
          
      } // end if 0 ��0.2C
      g_leftEnergy = g_socValue*(g_usefulCapacity*3600);
      g_energyOfUsed =0;
     */ 
}
//************************************************************************
//************************************************************************
float SocOCVAdjust(float vocv)
{
    float x=0;
    float y2=0;
    
    x=vocv;
    if(LITHIUM) 
    {
        if(x>=3.662)
            y2=-0.719*x*x+6.797*x-14.82;
        else if(x>=3.450)        
            y2=8.606*x*x-59.35*x+102.3;
        else
            y2=0;
        return(y2*100);
    }

    if(x>=3.669)
        y2=-104.29*x*x+926.07*x-1943.4;
    else if(x>=3.567)
        y2=920.89*x*x-6362.4*x+10997.2;
    else if(x>=3.378)
        y2=78.74*x-265.9;
    else
        y2=0;
    if(y2<0) 
        y2=0;
    else if(y2>100) 
        y2=100;
    return(y2) ;
}
//************************************************************************
//************************************************************************
void SocProcessure(void)
{
    
    static float ahCharge1A=0;
    static float ahDischarge1A=0;
    float ft=0,ca=0;
	  unsigned char i=0;
	  	  	
	  turnOnADC(); //��ADC�ж�
	  delay(100);
	  if((Int_Flag&0x01)==0x01)  
        ADC_Processure();
	  delay(100);
	
	  if(g_isrTimes>=750)  // 750ms ���һ��"��"λ�Ƿ��б仯��
	  {
   	    g_isrTimes = 0;
		
		    DisableInterrupts;
		    I2CReadDate();  //��ȡϵͳʱ��				
		    //ʵʱʱ�䱣��
		  
        //for(i=SYS_REALTIME_SECOND;i<SYS_REALTIME_YEAR+1;i++)
        //    g_storageSysVariable[i]= CurrentTime[i-10];          
        EnableInterrupts;
		
		    if(CurrentTime[0]!=g_oldTime[0])   //ÿ���Ӽ���һ��SOC��ֵ
		    {
				    g_oldTime[0] = CurrentTime[0];//��
				    isrTimer0count_100ms = 1;
				    //fast
				    //if((g_chargeStateFlag ==RECHARGING)||(g_chargeStateFlag ==FASTRECHARGING))//���(�����)
				    if(g_systemCurrent<=0)// //���
				    {
					      if(g_leftEnergy<=g_usefulCapacity*3600)//�������δ��
					      {
						        ft = g_leftEnergy-g_energyOfUsed;
						        g_socValue = ft/(g_usefulCapacity*3600);
						        g_displaySocValue = g_socValue;	
						        					        						        					
					      }					
					      if(g_highestCellVoltage>4.30) // ǿ�ƶϿ���ѹ
				        {					  
					          TurnOff_INZK();//�Ͽ������̵���
					          BmsCtlStat0 &=0xfd;//�����̵���״̬�Ͽ�
					          BmsCtlStat =0;//�����̵���״̬�Ͽ�
					          //�µ�
		                turnOffSW_Power();//�رյ�Դ���س��׶ϵ�
				        }	
				    }
				    //if(g_chargeStateFlag == DISCHARGING)//�ŵ�
				    if(g_systemCurrent>0)// //�ŵ�
				    {
					      if(g_leftEnergy>=1.0)
					      {
						        ft = g_leftEnergy-g_energyOfUsed;
						        g_displaySocValue= ft/(g_usefulCapacity*3600);
						        ca=TemperatureAdjustForCap(ft,g_averageTemperature);
						        g_socValue = ca/(g_usefulCapacity*3600);						        
						        				
					      }
					      //if((g_lowestCellVoltage<3.0)&&(error11&0x02==0x02))     // ǿ�ƶϿ���ѹ
					      if(g_lowestCellVoltage<2.5)     // ǿ�ƶϿ���ѹ
				        {					  
					          TurnOff_INZK();//�Ͽ������̵���	
					          BmsCtlStat0 &=0xfd;//�����̵���״̬�Ͽ�
					          BmsCtlStat =0;//�����̵���״̬�Ͽ�
					          //�µ�
		                turnOffSW_Power();//�رյ�Դ���س��׶ϵ�
				         }	
				     } //end of �ŵ�
						 			
				     if(g_socValue>1.0)	
				     {
					       g_socValue = 1.0;
					       g_leftEnergy = g_socValue*TemperatureAdjustForCap((g_usefulCapacity*3600),g_averageTemperature);
					       g_energyOfUsed =0;
				     }   
			
				     if(0>=g_socValue)
				     {								
					       g_socValue = 0;
				 	       g_leftEnergy = 0;
					       g_energyOfUsed =0;
				     }			
		         StoreSocRealvalue();//ÿ�뱣��SOCֵ
		         			    
        } //end of ÿ����
				
		    if(CurrentTime[1]!=g_oldTime[1])// ÿ����SOCֵ����ϵͳ��������Ϊ�����ͨ��
		    {
			      g_oldTime[1] = CurrentTime[1];//��
			      g_sysPara[PARA_SOC_VALUE] = g_socValue;
			      g_leftEnergy=g_leftEnergy-g_energyOfUsed;
			      if(g_systemCurrent<=0)// //���
			      {
			          //�����ܳ���AH��
						    ahCharge1A += g_energyOfUsed/3600;
				        if(ahCharge1A>=1.0) 
				        {
				            sumAhCharge += (unsigned int)ahCharge1A;
				            sumAhChargeOnce += (unsigned int)ahCharge1A;
						        ahCharge1A =0;
				        }		
			      
			      }
			      if(g_systemCurrent>0)// //�ŵ�
			      {
			          //�����ܷŵ�AH��
				        ahDischarge1A += g_energyOfUsed/3600;
				        if(ahDischarge1A>=1.0) 
				        {
				            sumAhDischarge += (unsigned int)ahDischarge1A;
				            sumAhDischargeOnce += (unsigned int)ahDischarge1A;
						        ahDischarge1A =0;
				        }
			      
			      }
			      
			      g_energyOfUsed =0;
			      //����״̬����
			      //if((CurrentTime[4]!=0)||(CurrentTime[5]!=0)) // ���ڶ�ȡ�����ٴ洢
			      StoreTotalAH();
		        StoreSysVariable();//ÿ���ӱ���SOCֵ�͹�����Ϣ		  
		        sendBMSIDtoBMU(); //����BMS�汾ID�Ÿ�BMU
			      sendRealtimeToBMU(); //����BMSϵͳʱ���BMU
        }
        
    }//end of ÿ750ms
    

}
//************************************************************************
//************************************************************************
void ADC_Processure(void)
{
    unsigned char i;
	  float tmp2=0,tmp3=0;
	  float sc=0,sx=0;
	
	  Int_Flag &= 0xfe;//���жϱ�־
	    
	  tmp2 = ac[0];
		tmp3 = ax[0];			
		for(i=0;i<11;i++)  //ȡ���ֵ
		{			
				if(tmp2<ac[i+1])
					  tmp2= ac[i+1];	
				if(tmp3<ax[i+1])
					  tmp3= ax[i+1];	
				sc += ac[i];
				sx += ax[i];								
	  }
    sc += ac[11];  //���ܺ�
	  sx += ax[11];
		sc = sc-tmp2; //ȥ��һ�����ֵ
		sx = sx-tmp3;
			
		tmp2 = ac[0];
		tmp3 = ax[0];			
		for(i=0;i<11;i++) //ȡ��Сֵ
		{			
			  if(tmp2>ac[i+1])
					  tmp2= ac[i+1];	
				if(tmp3>ax[i+1])
					  tmp3= ax[i+1];			
		}
	  sc = sc-tmp2;  //ȥ��һ����Сֵ
		sx = sx-tmp3;
		//
		sc = sc/10;//ȡƽ��ֵ
		sx = sx/10;
		//
		if((sc > 26.0)||(sc<-26.0))//��������26Aʱ���ô����ͨ�� �����������ͺţ�DHABs18
		{
			  g_systemCurrent = sc;					
		} 
		else
			  g_systemCurrent = sx;
			
		if(g_systemCurrent<-400)  //��ֹ�������
        g_systemCurrent = 0;			  
}
//************************************************************************************
//************************************************************************************
void ParameterSetting(void)//
{      
    unsigned char i=0;
    unsigned char SetTime[7];  
     
    switch(g_mboxID)//
    {            
        case 0x0c14ee00:
            sendRealtimeToBMU();
            break;
        case 0xC01ee18:
            sendBMSSFVersionToPC();
            break;
        case 0xc01ee14:         //�궨ϵͳʱ��
            //����ʱ��
		        for(i=0;i<7;i++)
		            SetTime[i]=*((&CAN2RXDSR0)+i);//��//��//ʱ//����//��//��//��
		        I2CWriteDate(SetTime);  //���ó�ʼʱ��
            break;
        case 0xC01ee15:
            g_sysPara[PARA_SOC_VALUE]= (float)(*((&CAN2RXDSR0)+2))/100;    // SOC
            g_socValue = g_sysPara[PARA_SOC_VALUE];
            g_leftEnergy = g_socValue*(g_usefulCapacity*3600);  //ʣ������
	          g_energyOfUsed = 0;                          //���ο�����������	                
	          StoreParameter();
	          //paraChangedFlag = 1;
            break;
        case 0xC01ee16:
            g_sysPara[PARA_WHOLE_CAPACITY]= *((&CAN2RXDSR0)+2);
	          g_usefulCapacity =  g_sysPara[PARA_WHOLE_CAPACITY];//����������ʼ��
	          StoreParameter();
	          //paraChangedFlag = 1;
            break;
        case 0xc01ee17:     //����BMU����
            g_sysPara[PARA_BMU_NUMBER]= *((&CAN2RXDSR0)+2);
            switch((unsigned int)g_sysPara[PARA_BMU_NUMBER])//����BMU�ĸ�����ȷ����Ӧ��������Ϣ���ܹ�֪���Ƿ����еĵ��������Ѿ�����һ��
            {
                case 1:
                  	g_BMU_CIRCLE_FLAG = 0x0000001;
                  	break;
                case 2:
                  	g_BMU_CIRCLE_FLAG = 0x0000011;
                  	break; 
                case 3:
                  	g_BMU_CIRCLE_FLAG = 0x0000111;
                  	break;  
                case 4:
                  	g_BMU_CIRCLE_FLAG = 0x0001111;
                  	break; 
                case 5:
                  	g_BMU_CIRCLE_FLAG = 0x0011111;
                  	break;
                case 6:
                  	g_BMU_CIRCLE_FLAG = 0x0111111;
                  	break;  
                case 7:
                  	g_BMU_CIRCLE_FLAG = 0x1111111;
                  	break;      
                default:
                  	break;
            }
            StoreParameter();
            //paraChangedFlag = 1;
            break;
        case 0xC01EE26://��ȡϵͳ�ڲ�����
            if(*((&CAN0RXDSR0)+0)==0x66)
                paraReadFlag=1;
            break;            
        case 0xC01EE28:         //����ϵͳ����������Ϣfrom ��λ��
            g_sysPara[PARA_O_WHOLE_VOLTAGE]=  (*((&CAN2RXDSR0)+0)&0x00ff)<<8 | (*((&CAN2RXDSR0)+1)&0x00ff);//�ܵ�ѹ������ֵ
            g_sysPara[PARA_L_WHOLE_VOLTAGE]=  (*((&CAN2RXDSR0)+2)&0x00ff)<<8 | (*((&CAN2RXDSR0)+3)&0x00ff);//�ܵ�ѹ������ֵ
            g_sysPara[PARA_O_CELL_VOLTAGE] = *((&CAN2RXDSR0)+4)*0.01-1.75;//��ѹֵ
            g_sysPara[PARA_L_CELL_VOLTAGE] = *((&CAN2RXDSR0)+5)*0.01-1.75;//Ƿѹֵ
            g_sysPara[PARA_O_TEMPERATURE] =  *((&CAN2RXDSR0)+6)-40; //����ֵ
            g_sysPara[PARA_L_TEMPERATURE] =  *((&CAN2RXDSR0)+7)-40; //�¶ȹ���ֵ                    
            StoreParameter();
            //paraChangedFlag = 1;
            break;
        case 0xC01EE29:         //����ϵͳ����������Ϣfrom ��λ��
            g_sysPara[PARA_HIGHEST_RECHARGE_CURRENT] =  *((&CAN2RXDSR0)+0);//������������ֵ  
            g_sysPara[PARA_O_SOC_VALUE] =  *((&CAN2RXDSR0)+4); //SOC����
            g_sysPara[PARA_L_SOC_VALUE] =  *((&CAN2RXDSR0)+5); //SOC����  
            g_sysPara[PARA_L_ISOLATION_RESISTANCE] =  *((&CAN2RXDSR0)+6); //��Ե�������ֵ
            g_sysPara[PARA_O_CONSISTENCY_V] =  *((&CAN2RXDSR0)+7);//��ѹһ���Բ� 
            StoreParameter();
            //paraChangedFlag = 1;
            break;
        case 0xC01EE2a:         //����ϵͳ����������Ϣfrom ��λ��
            g_sysPara[PARA_BALANCE_ON_VOLTAGE] = *((&CAN2RXDSR0)+0)*0.01-1.75;//���⿪����ѹ
            g_sysPara[PARA_BALANCE_OFF_VOLTAGE] = *((&CAN2RXDSR0)+1)*0.01-1.75;//�����ֹ��ѹ
            g_sysPara[PARA_DIFFERENCE_SINGLE_V] =  *((&CAN2RXDSR0)+2);//����ѹ��
            StoreParameter();
            //paraChangedFlag = 1;
            break;
        case 0xC01EE2b:         //����ϵͳ����������Ϣfrom ��λ��
            break;                      
        default:
            break;                  
      }//end of switch      

}
//**********************************************************************
//**********************************************************************
void FastRecharge_Processure(void)
{
 

}
//**********************************************************************
//**********************************************************************
void Recharge_Processure(void)
{
    
}
//************************************************************************
//************************************************************************
void VehiclePowerOnLogic(void)
{
    static unsigned char times=0;
    static unsigned char delaycounter =0;
    static unsigned char PowerOnFlag=0;
    static unsigned char closedPrecharge=0;
    static unsigned char openPrecharge=0;
    static unsigned char closedZKrelay=0; 
    static unsigned char closedFKrelay=0;  
      
    if((RelayReq == 0x03)||(RelayReq == 0x02)) //���Ѿ����ڱ��ֵ�ǰ״̬�����µ�״̬���򷵻�
        return;
      
    //�ȴ�212����
    if(times<=3) 
        RelayReq=0;     //ϵͳ��ʼ�Լ죬���� 00 �� VCU     id=452   //�ȷ�3��0x00  ��ʾ�Լ�                                                                      
    else 
    {      
        //RelayReq = 0x01;//�����ѹ�ϵ� ��0x01
        RelayReq = 0x00;//�����ѹ�ϵ� ��0x01
        RelayReq0 = 0x02;// for PC
    }
      
    times++;
    if(times>100)
        times=100; //ȷ��ֵ�������
    if((Vcu2bms_212_byte0==0x01)&&(PowerOnFlag==0)) //�յ���ѹ�ϵ�ָ��
    {                        	
    	  Vcu2bms_212_byte0=0;
    	  PowerOnFlag =1;
    	  RelayReq = 0x01;//�����ѹ�ϵ� ��0x01    	    
    	  TurnOn_INFK();//�պ��ܸ�      
        BmsCtlStat =1;//�����̵���״̬�պ� 
        BmsCtlStat0 |=0x02;// 
        closedFKrelay =1;          
    } 
    if(closedFKrelay)
    {
        delaycounter++;
        if(delaycounter>=15) //5*20ms=100ms  
        {
            delaycounter =0; 
            closedFKrelay =0;   	    
    	      TurnOn_INBK();//�պ�Ԥ���̵���
    	      PrechargeRelayStat =1;//Ԥ���̵���״̬��λ
    	      closedPrecharge =1;
        }
    }
    if(closedPrecharge)  //������˱պϼ̵����������ô��ʼ��ʱ��
    {        
        delaycounter++;
    	  if(delaycounter>=15) //5*20ms=100ms
    	  {    	             	    
            //g_highVoltageV2 = 250;
        	  if((g_highVoltageV1-g_highVoltageV2)>30) //92cell*2.7V=248.4  //��������ص�ѹ�ﵽҪ��
        	  {
        	      if(delaycounter>=100)  //���2���ڵ�ѹ���ﲻ��Ҫ�󣻻㱨����
        	      {
        	          delaycounter =0;
        	          TurnOff_INBK();//�Ͽ�Ԥ���̵���
                    PrechargeRelayStat =0;//Ԥ���̵���״̬
                    TurnOff_INFK();//�Ͽ������Ӵ���
                    BmsCtlStat &=0x0;//�����̵���״̬�Ͽ�
                    BmsCtlStat0 &=0xfd;//�����̵���״̬�Ͽ�
                    closedPrecharge =0;
                    return;        	                   	       
        	      }        	   
        	  } 
        	  else 
        	  {        	    
        	       delaycounter =0;
        	       closedPrecharge =0;
        	       TurnOn_INZK();//���������Ӵ���//�պ����� 
        	       BmsCtlStat |=1;//�����̵���״̬�պ�
        	       BmsCtlStat0 |=0x02;//�����̵���״̬�պ� 
        	       closedZKrelay =1;    
        	   }
    	   }
    }
    if(closedZKrelay)//����Ѿ��պ������� 
    {
        delaycounter++;
        if(delaycounter>=15) //5*20ms=100ms
        {
            delaycounter = 0;
            closedZKrelay =0;
            TurnOff_INBK();//�Ͽ�Ԥ���̵���
            PrechargeRelayStat =0;//Ԥ���̵���״̬
            openPrecharge=1;
        }  
        	  
    }  
    if(openPrecharge) 
    {
        delaycounter++;
    	  if(delaycounter>=15) //5*20ms=100ms
    	  {
    	      //g_highVoltageV2 = 230;
    	      if((g_highVoltageV1-g_highVoltageV2)>30) 
    	      {
        	      if(delaycounter>=100)  //���2���ڵ�ѹ���ﲻ��Ҫ�󣻻㱨����
        	      {
        	          TurnOff_INZK();//�Ͽ�������̵���
                    BmsCtlStat =0;//�����̵���״̬�Ͽ�
                    BmsCtlStat0 &=0xfe;//�����̵���״̬�Ͽ�                         
                    TurnOff_INFK();//�Ͽ������Ӵ���
                    BmsCtlStat &=0x0;//�����̵���״̬�Ͽ�
                    BmsCtlStat0 &=0xfd;//�����̵���״̬�Ͽ�                         
                    openPrecharge = 0;
                    delaycounter =0;
                        return;        	                   	       
        	      }    	         
    	      } 
    	      else 
    	      {    	            
        	      delaycounter = 0;
        	      openPrecharge = 0;
        	      PrechargeStat =1;
        	      RelayReq = 0x03;//���ֵ�ǰ״̬ 
        	      RelayReq0 = 0x03;//���ֵ�ǰ״̬ 
    	      }
    	  }//end of 100ms
    }
    	        
    /*
    if(inputP_state())  //�ӳ�400ms����̵����պ�״̬   
    {
        bmsToVcuInfo450();  //����BMS���ϴ���
    }	 
    else 
    {    	      
        BmsCtlStat =1;//�����̵���״̬�պ�
        BmsCtlStat0 |=0x02;//�����̵���״̬�պ� 
        RelayReq = 0x03;//���ֵ�ǰ״̬  
    }
    */      
} 
//************************************************************************
//************************************************************************
void VehiclePowerOffLogic(void) 
{
    if((Vcu2bms_212_byte0 == 0x02)&&(RelayReq==0x03)&&(!g_endPowerOffFlag)) //��ѹ�µ�
    {
        Vcu2bms_212_byte0 =0;         
        TurnOff_INZK();//�Ͽ������Ӵ���  
        BmsCtlStat =0;//�����̵���״̬�Ͽ�
        BmsCtlStat0 &=0xfe;//�����̵���״̬�Ͽ�
         
        delay(1000);
        TurnOff_INFK();//�Ͽ������Ӵ���
        BmsCtlStat &=0x0;//�����̵���״̬�Ͽ�
        BmsCtlStat0 &=0xfd;//�����̵���״̬�Ͽ�
                 
        RelayReq =0x03;//�����̵����Ѿ��Ͽ�
        //bmsToVcuInfo450(); //���ͼ̵���״̬����ɣ�BMS���ֵ�ǰ״̬
        g_endPowerOffFlag=1;
         
        //�µ�
		    turnOffSW_Power();//�رյ�Դ���س��׶ϵ�
      
    }

}
void HighVoltDetectPart1(void) 
{
    if(g_highVoltageV1==0) //���MSD   g_highVoltageV1=V1 ;   g_highVoltageV2=V2
    {      
        msdFault =1;
        return;
    }
    if(g_highVoltageV2 >= g_highVoltageV1*0.5) //�жϸ����̵���ճ��
    {
        relayNconnected =1;
        return;
    }
        
}
void HighVoltDetectPart2(void) 
{    
    unsigned char flag1,flag2;
    
    if(tmr_p2>=10 && tmr_p2<=80)
        if(g_highVoltageV2 <= g_highVoltageV1*0.4)
            flag1=1;
    if(tmr_p2 >= 120&& tmr_p2 <= 150)  
        if(g_highVoltageV2 >= g_highVoltageV1*0.8)
            flag2=1;       
    if((flag1+flag2) == 2) 
    {      
        relayPreState =2; //Ԥ��̵���ճ��
        return;
    }
    
    if(tmr_p2 >= 150) 
    {      
        if(g_highVoltageV2 <= g_highVoltageV1*0.2) 
        {
            relayNdisconnected =1; //�����̵����Ͽ�����
        } 
        else
            relayNdisconnected =0; //�����̵����޹���
        
        if((g_highVoltageV2 >= g_highVoltageV1*0.4) && (g_highVoltageV2 <= g_highVoltageV1*0.8))
            relayPreResState =1;  //Ԥ������Ͽ�����
    }
}
void HighVoltDetectPart3(void) 
{      
    static preChargeON =0;
    static tt=0;
    
    if(!preChargeON) 
    {
        preChargeON=1;
        TurnOn_INBK();//�պ�Ԥ���̵��� 
        delaysss(25000); //20ms
        PrechargeRelayStat =1;//Ԥ���̵���״̬��λ
    }
    while(tmr_p3<=20); 
    while((tmr_p3 >20)&&(tmr_p3<40))
        if(g_highVoltageV2 <= g_highVoltageV1*0.8 ) 
        {            
            tt++;
              if(tt==10) 
              {  
                   relayPreState =0; 
                   tt=11;
                   break;
              }
                                 
        } 
        else 
        {
            relayPreState =1;    //Ԥ���̵����Ͽ�����                         
        }
        
    if(relayPreState) 
    {
         TurnOff_INBK();//�Ͽ�Ԥ���̵���
         delay(25000); //20ms
         PrechargeRelayStat =0; //���Ԥ����־λ
         prechargeFinished =0;
    }

     delaysss(65000); //20ms
     delaysss(65000); //20ms
    //if((tmr_p3>80)&&(tmr_p3<=280)&&(!relayPreState))  
     if((tmr_p3>80)&&(tmr_p3<=380))
         if(relayPreState==0) 
            if(g_highVoltageV2 >= g_highVoltageV1*0.8) 
            {
                TurnOn_INZK();//�պ������̵���
                delay(25000); //20ms
                TurnOff_INBK();//�Ͽ�Ԥ���̵���
                BmsCtlStat =1;//�����̵���״̬�պϱ�־λ
                BmsCtlStat0 |=0x02;//�����̵���״̬�պ�    to pc 
                delay(25000); //20ms 
                PrechargeRelayStat =0; //���Ԥ����־λ
                prechargeFinished =1;
                tmr_p3 =381; //ֻ����һ��
            }
 
    if(tmr_p3>380)
        if(g_highVoltageV2 <= g_highVoltageV1*0.8) 
        {
            TurnOff_INBK();//�Ͽ�Ԥ���̵���
            PrechargeRelayStat =0; //���Ԥ����־λ
            prechargeFinished =0;
        }
   
}

//************************************************************************
//************************************************************************
//************************************************************************
//************************************************************************
/*-------------------------------------------------------
---------------------------------------------------------*/





