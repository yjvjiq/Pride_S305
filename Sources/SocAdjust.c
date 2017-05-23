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
//* Description        : 该文件用于调整在不同情况下SOC值
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#include "BMS20.h"

//******************************************************************************
//* Function name:   SocRechargeAdjust
//* Description:     充电时SOC修正
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void SocRechargeAdjust(void)//充电末端SOC修正子程序
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
//* Description:     放电末端SOC修正    周期5ms
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void SocEndDischargeAdjust(void)//放电末端SOC修正子程序
{
    //float x1;//存储当前温度下修正SOC的单体电压
    static unsigned int time10S=0;
    static unsigned int counter5S1=0;
    static unsigned int counter5S2=0;
    static unsigned int counter5S3=0;
   
   if((g_BatLowestTemp>=45)&&(g_CellLowestVol!=0)) 
   {
        if((g_CellLowestVol<=2.6)&&(g_BatSysTotalCur<=0.5*C))//当Tmin≥5℃，Vmin≤2.6V，电流小于0.5C，持续5s，将SOC修正为0；
        {
            counter5S1++;
            if(counter5S1>=700)   //
            {
                counter5S1=707;
                g_SysSOC_Start=0;   //SOC修正为0
	              CanSocIntegral();
            }
        } 
        else if(g_CellLowestVol<=2.9) //当Tmin≥5℃，Vmin≤2.9V，持续10s，将SOC修正为10%；
        {
            time10S++;
            counter5S1=0;
            if((time10S>=1400)&&(g_SysSOC>0.1)) 
            {
                time10S=1400;
                g_SysSOC_Start=0.1;   //SOC修正为10%
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
        if((g_CellLowestVol<=2.5)&&(g_BatSysTotalCur<=0.5*C)) //当Tmin<5℃，Vmin≤2.5V，电流小于0.5C，持续5s，将SOC修正为0；
        {
            counter5S2++;
            if(counter5S2>=700)   
            {
                counter5S2=707;
                g_SysSOC_Start=0;    //SOC修正为0
	              CanSocIntegral();
            }
        } 
        else
            counter5S2=0;     
    }
    
    
}

//******************************************************************************
//* Function name:   SocOCVAdjust
//* Description:     根据当前单体电压状况调整当前的SOC
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
	  soceeprom=ReadOutSocStoreValue(); //SOC实际值，但不是显示值 
	  ReadOutErrorRecord(g_errorCounter);//为了得到上次下电时的时间
	  timenow=CurrentTime[4]*1440+CurrentTime[2]*60+CurrentTime[1];
	  timeold=g_storageSysVariableOut[SYS_REALTIME_DAY]*1440+g_storageSysVariableOut[SYS_REALTIME_HOUR]*60+g_storageSysVariableOut[SYS_REALTIME_MINUTE];
	  if(timenow<(timeold+delaytime)) //间隔时间没有超过间隔时间 
	  {
	      OCVState = 0;
	      return;
	  }
	  if((g_CellLowestVol==0)||(g_CellHighestVol>=5.0))//防止单体电压为0或者最高单体检测故障
	      return;
    if(g_CellLowestVol>=3.34)//当Vmin≥3.34V,〖SOC〗_EEPROM≤95%，将SOC修正为95%
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
	  else if(g_CellLowestVol<=2.9) // 当Vmin≤2.9V，将SOC修正为0%,并给g_ActalRatedCapty赋值为初始值
	  {	    
	      g_socValue=0;
    	  g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);	  
        g_energyOfUsed = 0;
        g_ActalRatedCapty=SYS_NOMINAL_AH;
        OCVState = 1;
	  }
	  else if(g_CellLowestVol<=3.1)//当Vmin≤3.1V，将SOC修正为5%
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