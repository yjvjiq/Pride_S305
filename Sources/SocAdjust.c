//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : SocAdjust.c
//* Author             : judy
//* Version            : V1.0.0
//* Start Date         : 2016.2.14
//* Description        : ���ļ����ڵ����ڲ�ͬ�����SOCֵ
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#include "BMS20.h"

//******************************************************************************
//* Function name:   SocRechargeAdjust
//* Description:     ���ʱSOC����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void SocRechargeAdjust(void)//���ĩ��SOC�����ӳ���
{
    if((g_CellHighestVol >=HIGHEST_ALLOWED_CHARGE_CV)&&(g_CellHighestVol<=HIGHEST_CELL_VOL))
    {
        AdjustQ1Value();
        g_socValue=1;
        g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);	  
        g_energyOfUsed = 0;
    }
    
}

//******************************************************************************
//* Function name:   SocEndDischargeAdjust
//* Description:     �ŵ�ĩ��SOC����    ����5ms
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void SocEndDischargeAdjust(void)//�ŵ�ĩ��SOC�����ӳ���
{
    //float x1;//�洢��ǰ�¶�������SOC�ĵ����ѹ
    static unsigned int time10S=0;
    static unsigned int counter5S1=0;
    static unsigned int counter5S2=0;
    static unsigned int counter5S3=0;
   
   if((g_BatLowestTemp>=45)&&(g_CellLowestVol!=0)) 
   {
        if((g_CellLowestVol<=2.6)&&(g_BatSysTotalCur<=0.5*C))//��Tmin��5�棬Vmin��2.6V������С��0.5C������5s����SOC����Ϊ0��
        {
            counter5S1++;
            if(counter5S1>=700)   //
            {
                counter5S1=707;
                g_SysSOC_Start=0;   //SOC����Ϊ0
	              CanSocIntegral();
            }
        } 
        else if(g_CellLowestVol<=2.9) //��Tmin��5�棬Vmin��2.9V������10s����SOC����Ϊ10%��
        {
            time10S++;
            counter5S1=0;
            if((time10S>=1400)&&(g_SysSOC>0.1)) 
            {
                time10S=1400;
                g_SysSOC_Start=0.1;   //SOC����Ϊ10%
	              CanSocIntegral();
            }
        }
        else
        {          
            time10S=0;
            counter5S1=0;
        }
    } 
    else if((g_BatLowestTemp<45)&&(g_CellLowestVol!=0))     
    {
        if((g_CellLowestVol<=2.5)&&(g_BatSysTotalCur<=0.5*C)) //��Tmin<5�棬Vmin��2.5V������С��0.5C������5s����SOC����Ϊ0��
        {
            counter5S2++;
            if(counter5S2>=700)   
            {
                counter5S2=707;
                g_SysSOC_Start=0;    //SOC����Ϊ0
	              CanSocIntegral();
            }
        } 
        else
            counter5S2=0;     
    }
    
    
}

//******************************************************************************
//* Function name:   SocOCVAdjust
//* Description:     ���ݵ�ǰ�����ѹ״��������ǰ��SOC
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void SocOCVAdjust(unsigned int delaytime)
{
    float capMin=0;
    float capMax=0;
    float socOcv =0;
    long timenow=0;
    long timeold=0;
     float soceeprom;
    
    ////Read out the previous power-off time, compare it to the current time, 
    ////if the time is over 2 hours, then adjust the SOC 
	  soceeprom=ReadOutSocStoreValue(); //SOCʵ��ֵ����������ʾֵ 
	  ReadOutErrorRecord(g_errorCounter);//Ϊ�˵õ��ϴ��µ�ʱ��ʱ��
	  timenow=CurrentTime[4]*1440+CurrentTime[2]*60+CurrentTime[1];
	  timeold=g_storageSysVariableOut[SYS_REALTIME_DAY]*1440+g_storageSysVariableOut[SYS_REALTIME_HOUR]*60+g_storageSysVariableOut[SYS_REALTIME_MINUTE];
	  if(timenow<(timeold+delaytime)) //���ʱ��û�г������ʱ�� 
	  {
	      OCVState = 0;
	      return;
	  }
	  if((g_CellLowestVol==0)||(g_CellHighestVol>=5.0))//��ֹ�����ѹΪ0������ߵ��������
	      return;
    if(g_CellLowestVol>=3.34)//��Vmin��3.34V,��SOC��_EEPROM��95%����SOC����Ϊ95%
	  {
	      if(soceeprom<=0.95)
	      {	        
	          g_socValue=0.95;
	          g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);	  
	          g_energyOfUsed = 0; 
	          g_ActalRatedCapty=SYS_NOMINAL_AH;
	          OCVState = 1;
	      } 
	      
	  } 
	  else if(g_CellLowestVol<=2.9) // ��Vmin��2.9V����SOC����Ϊ0%,����g_ActalRatedCapty��ֵΪ��ʼֵ
	  {	    
	      g_socValue=0;
    	  g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);	  
        g_energyOfUsed = 0;
        g_ActalRatedCapty=SYS_NOMINAL_AH;
        OCVState = 1;
	  }
	  else if(g_CellLowestVol<=3.1)//��Vmin��3.1V����SOC����Ϊ5%
	  {	    
	      g_socValue=0.05;
     	  g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);	  
        g_energyOfUsed = 0;
        g_ActalRatedCapty=SYS_NOMINAL_AH;
        OCVState = 1;
	  }
}
//*******************************************************************************
//***********************the end**************************************************
//********************************************************************************
//********************************************************************************
//********************************************************************************