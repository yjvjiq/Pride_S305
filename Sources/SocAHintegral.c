//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : SocAHintegral.c
//* Author             : judy
//* Version            : V1.0.0
//* Start Date         : 2016.2.14
//* Description        : ���ļ����ڵ����ڲ�ͬ�����SOCֵ
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "SocAHintegral.h"
#include  "current.h"
#include  "sd2405.h"
#include  "BMS20.h"
//-------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//float g_socValue=0;  //ʵ��SOC
//float First_g_socValue=0;  //��һ���ϵ�ʱ��SOC


float g_socValue=0;  //ʵ��SOC
//float g_socValue_Start=0;  //ʵ��SOC�������ʼֵ
//float g_SysSOC=0;//�ϱ�SOC
float g_SysSOC_Start;//�ϱ���SOC��ʼֵ
float First_g_socValue=0;  //��һ���ϵ�ʱ��SOC
float StoreAHSOC=0;
//float First_g_SysSOC=0;  //��һ���ϵ�ʱ��SOC
float FactorA=1;//ϵ��(�¶�ϵ��*SOH)

float g_energyOfUsed=0; //���õ������
float g_leftEnergy=0;    //ʣ��������
//float g_usefulCapacity;//���õ������
float g_originalCapacity;//ԭʼ������Q0
float g_ActalRatedCapty=0;//ʵ�ʶ����Q1
float Q2=0;//��ʾSOC��Q2
unsigned char ChangerStopState=0;
//************************************************************************
//* Function name:TaskSocProcess
//* Description:ÿ����㲢�����ϱ�SOC��ÿ���ӱ���һ��
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void CanSocIntegral(void) 
{
    float CANSOC=0;
    if(g_BmsModeFlag == DISCHARGING)
    {
        if(First_g_socValue!=0)
            CANSOC= g_SysSOC_Start*g_socValue/First_g_socValue/FactorA+(1.0-1.0/FactorA)*g_SysSOC_Start; 
        else//���
        {          
            CANSOC=0;
        }
    }
    else if((g_BmsModeFlag == FASTRECHARGING)||(g_BmsModeFlag == RECHARGING))
    {
        if(First_g_socValue!=1) 
        {
          CANSOC = (1.0-g_SysSOC_Start)*(g_socValue-First_g_socValue)/(1.0-First_g_socValue)/FactorA+g_SysSOC_Start;   
          if(ChangerStopState==0)
            {
                if(CANSOC>=0.993)
                    CANSOC = 0.993;
            }
        } 
        else
        {
            CANSOC=1;
        }
    } 
    else if(g_BmsModeFlag == TESTSTATE)
    {
        CANSOC=g_socValue;
    }
    if(CANSOC<=0)
        CANSOC=0;
    else if(CANSOC>=1)
        CANSOC=1;
    g_SysSOC=CANSOC;
}
//************************************************************************
//* Function name:TaskSocProcess
//* Description:ÿ����㲢����SOC��ÿ���ӱ���һ����ʷ��¼
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void SocIntegral(void) 
{
    float ft=0;
       
    g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);  //ʣ������
				
		if(g_BatSysTotalCur<=0)// //���
		{
				if(g_leftEnergy<=g_ActalRatedCapty*3600)//�������δ��
				{ 
						ft = g_leftEnergy-g_energyOfUsed;					        
						g_socValue = ft/(g_ActalRatedCapty*3600);
						CanSocIntegral();
				}
		}
				
		if(g_BatSysTotalCur>0)// //�ŵ�
		{
				//if(g_leftEnergy>=1.0)
				if(g_leftEnergy>=0)
				{    
						ft = g_leftEnergy-g_energyOfUsed;
						g_socValue = ft/(g_ActalRatedCapty*3600);
						CanSocIntegral();					               				
				}
					      			      
		} //end of �ŵ�
						 			
		if(g_socValue>=1.0)	
  	{
				g_socValue = 1.0;
				g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);
				g_energyOfUsed=0;
				//g_SysSOC_Start=1;
				//CanSocIntegral();
					  
		}   
			
		if(g_socValue<=0)
		{								
				g_socValue = 0;
				g_leftEnergy = 0;
				g_energyOfUsed=0;
				//g_SysSOC_Start=0;
				//CanSocIntegral();			 
		}	
				

}


//******************************************************************************************
//******************************************************************************************
//******************************************************************************************
//*******************************************************************************************
