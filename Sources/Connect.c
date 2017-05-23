//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : Connect.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : ���ļ������ж�ϵͳ��ǰ���ӵ��Ƿŵ磬���仹�ǿ��״̬
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
//******************************************************************************
//* Function name:   bmsModeAwake
//* Description:     �ϵ绽���ź��жϣ��ó�ϵͳ����ģʽ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void bmsModeAwake(void) 
{
    long timedelay = 6500000;
    if(input5_state()==0)//CC2״̬���,IN5==0,���;IN5==1,���ǹû�в� cc2=1
    {
        
        while(input6_state())    //1��ʾû��ChargerIN�ź�
            _FEED_COP();   //��charge_in�źţ����            
        while((CC2VOL>=CC2VOLHIGH)||(CC2VOL<=CC2VOLLOW))
        {
             _FEED_COP();   //��charge_in�źţ����                     
        } 
        g_BmsModeFlag = FASTRECHARGING; //���ģʽ   
        g_DC_CC2=1;
        stateCode=140;     
        BMS1_Byte7.Bit.F7_ChaAndDischaState=1;  //���ڳ������״̬ 
        BMS5_Byte4.Bit.F7_ChaPlugCon=1;//����ͷ����      
    } 
    else if(input4_state()==0)     //ON=1
        {
            g_BmsModeFlag = DISCHARGING;//�ŵ�ģʽ
            g_ACC_ON=1;   //ON�ź�
            stateCode=10; 
            BMS1_Byte7.Bit.F7_ChaAndDischaState=0;  //���ڷŵ�״̬
            BMS5_Byte4.Bit.F7_ChaPlugCon=0;//����ͷδ����
        }
    

}
//******************************************************************************
//* Function name:   SignalOnJudge
//* Description:     ������,�ж��Ƿ��в�ǹ�ź�
//* EntryParameter : None
//* ReturnValue    : None
//* ע��           : ������ֱ��ʱ�޷���ChangerIN�ж��ź�,ֱ����CC2Ϊ�ź�,�����ѱ���CC��״̬Ϊ�ź�;
//                 : ����⵽��ǹ�źź�(ֱ������),��Ҫ�ȴ�ChangerIN�źź�,���ܽ��г���ϵ�                      
//******************************************************************************
void SignalOnOffJudge(void) 
{
    static unsigned char KEY_Connect=0;    //Կ���ź���
    static unsigned char AC_ConnectIN=0;   //����ChangerIN�����ź���
    static unsigned char AC_Connect=0;     //�������ǹ�����ź���
    static unsigned char DC_Connect=0;     //ֱ�����ǹ�����ź���
    static unsigned char KEY_DisConnect=0; //Կ���ź���
    static unsigned char AC_DisConnectIN=0;//����ChangerIN�����ź���
    static unsigned char AC_DisConnect=0;  //�������ǹ�����ź���
    static unsigned char DC_DisConnect=0;  //ֱ�����ǹ�����ź���
    long timedelay = 6500000;
    static unsigned char begin=0,end=0;
    if( BootState == 1) //Boot
    {
        turnOffSW_Power();//close�ܵ�Դ����
        //state_group4.Bit.Mode_BMS_Run = 3;//Boot To VCU
    } 
    else //��boot
    {
      
      ////////////////////////////ֱ�����ǹ���////////////////////////
        if(input5_state()==0)//���ǹ����   CC2=1
        {
          ////////////////////ֱ�����ǹCC2��ǹ���/////////////////////
            DC_Connect++; //ֱ����ǹ��ʱ���,����������⵽200*5msʱ��ſ���
            DC_DisConnect = 0;
            if(DC_Connect>=100)
            {               
                g_DC_CC2=1;                
                DC_Connect=0;                      
                if(g_BmsModeFlag == DISCHARGING)//������г�ģʽ�³�磬���Ҳ����������������CC2��ֱ���µ�
                {
                    g_RelayPowerOffFault = 1;
                } 
                if(g_BmsModeFlag == FASTRECHARGING)
                {
                    if(begin==0) 
                    {
                      Time_CHG_PlugIn();//���ǹ����ʱ��  
                      begin=1;
                    }
                }
                
           }        
        }
        else //CC2���ź�    CC2=0
        {
         ////////////////////ֱ�����ǹCC2��ǹ���/////////////////////   
            DC_Connect=0;
            DC_DisConnect++;//ֱ����ǹ��ʱ���,����������⵽200*5msʱ��ſ���
            if(DC_DisConnect>=100)
            {
                g_DC_CC2=0;
                if(g_BmsModeFlag == FASTRECHARGING)
                {                  
                    fastendflag=1;
                    fastend2|=0x40;//�������������
                    if(end==0) 
                    {
                      Time_CHG_PullOut();//���ǹ�ε�ʱ�� 
                      end=1;
                    }
                }                
                DC_DisConnect=0;
            }        
            ////////////////////ACCԿ�׿���ON���/////////////////////  
            if(input4_state()==0)//���ACC���ź�,��On�ź���Ч  ON=1
            {
                KEY_Connect++;
                KEY_DisConnect = 0;
                if(KEY_Connect>=100)
                {                  
                    g_ACC_ON = 1;    //ON��
                    KEY_Connect = 0;
                } 
            }
            else
            {
            ////////////////////ACCԿ�׿���OFF���/////////////////////  ON=0
                KEY_Connect = 0;
                KEY_DisConnect++;
                if(KEY_DisConnect>=100)
                {
                    g_ACC_ON = 0;    //ON=0
                    KEY_DisConnect = 0;                
                }
            }
        }    
        ////////////////////ChangerIN���/////////////////////     
        if(input6_state()==1)     //  ChargerIn=0
        {
            AC_ConnectIN = 0;
            AC_DisConnectIN++;//������ǹ��ʱ���,����������⵽200*5msʱ��ſ���
            if(AC_DisConnectIN>=100)
            {
                ChangerINError = 1;
                AC_DisConnectIN = 0;
                
            }
                
        } 
        else            //  ChargerIn=1
        {
        
            AC_DisConnectIN = 0;
            AC_ConnectIN++;//������ǹ��ʱ���,����������⵽200*5msʱ��ſ���
            if(AC_ConnectIN>=100)
            {
                ChangerINError = 0;
                AC_ConnectIN = 0;
               
            }        
        
        }
    }
}

//*************************************************************************
//***************************************************************************
//*******************************************************************************
//**********************************************************************************
//************************************************************************************