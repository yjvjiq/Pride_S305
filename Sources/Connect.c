//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : Connect.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : 该文件用于判断系统当前连接的是放电，慢充还是快充状态
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
//******************************************************************************
//* Function name:   bmsModeAwake
//* Description:     上电唤醒信号判断，得出系统工作模式
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void bmsModeAwake(void) 
{
    long timedelay = 6500000;
    if(input5_state()==0)//CC2状态检测,IN5==0,快充;IN5==1,快充枪没有插 cc2=1
    {
        
        while(input6_state())    //1表示没有ChargerIN信号
            _FEED_COP();   //无charge_in信号，则等            
        while((CC2VOL>=CC2VOLHIGH)||(CC2VOL<=CC2VOLLOW))
        {
             _FEED_COP();   //无charge_in信号，则等                     
        } 
        g_BmsModeFlag = FASTRECHARGING; //快充模式   
        g_DC_CC2=1;
        stateCode=140;     
        BMS1_Byte7.Bit.F7_ChaAndDischaState=1;  //处于充电机充电状态 
        BMS5_Byte4.Bit.F7_ChaPlugCon=1;//充电插头连接      
    } 
    else if(input4_state()==0)     //ON=1
        {
            g_BmsModeFlag = DISCHARGING;//放电模式
            g_ACC_ON=1;   //ON信号
            stateCode=10; 
            BMS1_Byte7.Bit.F7_ChaAndDischaState=0;  //处于放电状态
            BMS5_Byte4.Bit.F7_ChaPlugCon=0;//充电插头未连接
        }
    

}
//******************************************************************************
//* Function name:   SignalOnJudge
//* Description:     过程中,判断是否有插枪信号
//* EntryParameter : None
//* ReturnValue    : None
//* 注意           : 交流与直流时无法以ChangerIN判断信号,直流已CC2为信号,交流已报文CC的状态为信号;
//                 : 当检测到插枪信号后(直流或交流),需要等待ChangerIN信号后,才能进行充电上电                      
//******************************************************************************
void SignalOnOffJudge(void) 
{
    static unsigned char KEY_Connect=0;    //钥匙信号有
    static unsigned char AC_ConnectIN=0;   //交流ChangerIN连接信号有
    static unsigned char AC_Connect=0;     //交流充电枪连接信号有
    static unsigned char DC_Connect=0;     //直流充电枪连接信号有
    static unsigned char KEY_DisConnect=0; //钥匙信号无
    static unsigned char AC_DisConnectIN=0;//交流ChangerIN连接信号无
    static unsigned char AC_DisConnect=0;  //交流充电枪连接信号无
    static unsigned char DC_DisConnect=0;  //直流充电枪连接信号无
    long timedelay = 6500000;
    static unsigned char begin=0,end=0;
    if( BootState == 1) //Boot
    {
        turnOffSW_Power();//close总电源开关
        //state_group4.Bit.Mode_BMS_Run = 3;//Boot To VCU
    } 
    else //非boot
    {
      
      ////////////////////////////直流充电枪检测////////////////////////
        if(input5_state()==0)//快充枪插上   CC2=1
        {
          ////////////////////直流充电枪CC2插枪检测/////////////////////
            DC_Connect++; //直流插枪延时检测,必须连续检测到200*5ms时间才可以
            DC_DisConnect = 0;
            if(DC_Connect>=100)
            {               
                g_DC_CC2=1;                
                DC_Connect=0;                      
                if(g_BmsModeFlag == DISCHARGING)//如果在行车模式下充电，并且不满足条件充电条件CC2，直接下电
                {
                    g_RelayPowerOffFault = 1;
                } 
                if(g_BmsModeFlag == FASTRECHARGING)
                {
                    if(begin==0) 
                    {
                      Time_CHG_PlugIn();//充电枪插上时间  
                      begin=1;
                    }
                }
                
           }        
        }
        else //CC2无信号    CC2=0
        {
         ////////////////////直流充电枪CC2拔枪检测/////////////////////   
            DC_Connect=0;
            DC_DisConnect++;//直流拔枪延时检测,必须连续检测到200*5ms时间才可以
            if(DC_DisConnect>=100)
            {
                g_DC_CC2=0;
                if(g_BmsModeFlag == FASTRECHARGING)
                {                  
                    fastendflag=1;
                    fastend2|=0x40;//充电连接器故障
                    if(end==0) 
                    {
                      Time_CHG_PullOut();//充电枪拔掉时间 
                      end=1;
                    }
                }                
                DC_DisConnect=0;
            }        
            ////////////////////ACC钥匙开关ON检测/////////////////////  
            if(input4_state()==0)//如果ACC有信号,则On信号有效  ON=1
            {
                KEY_Connect++;
                KEY_DisConnect = 0;
                if(KEY_Connect>=100)
                {                  
                    g_ACC_ON = 1;    //ON信
                    KEY_Connect = 0;
                } 
            }
            else
            {
            ////////////////////ACC钥匙开关OFF检测/////////////////////  ON=0
                KEY_Connect = 0;
                KEY_DisConnect++;
                if(KEY_DisConnect>=100)
                {
                    g_ACC_ON = 0;    //ON=0
                    KEY_DisConnect = 0;                
                }
            }
        }    
        ////////////////////ChangerIN检测/////////////////////     
        if(input6_state()==1)     //  ChargerIn=0
        {
            AC_ConnectIN = 0;
            AC_DisConnectIN++;//交流插枪延时检测,必须连续检测到200*5ms时间才可以
            if(AC_DisConnectIN>=100)
            {
                ChangerINError = 1;
                AC_DisConnectIN = 0;
                
            }
                
        } 
        else            //  ChargerIn=1
        {
        
            AC_DisConnectIN = 0;
            AC_ConnectIN++;//交流插枪延时检测,必须连续检测到200*5ms时间才可以
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