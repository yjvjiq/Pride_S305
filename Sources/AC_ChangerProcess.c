//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : 5T
//* File Name          : AC_ChangerProcess.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2011,05,26
//* Description        : 慢充流程
//----------------------------------------------------------------------------------------------------



#include "BMS20.h"

unsigned char plug_AC_CP_Connect=0;   //交流充电枪连接信号
unsigned char slowRechargeFinished=0; //慢充结束标志
unsigned char ACTem1=0;
unsigned char ACTem2=0;
unsigned int OBC_Out_DC_Vol = 0;//OBC发送的直流充电电压
AC_CHANGERSTATE AC_ChangerState;      //CC信号及电子锁信号
AC_CHANGERWORKSTATE AC_ChangerWorkState;//充电机工作状态
//******************************************************************************
//* Function name:   GetRequestCurrentAC
//* Description:     充电请求电流计算
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
float GetRequestCurrentAC(void) 
{
    float CurrentAValue;
    static unsigned char ChanceHappen1 = 0;//电压高于3.78后不恢复
    static unsigned char ChanceHappen2 = 0;//电压高于3.92后不恢复
    
    if(st_heating==1)//预加热
    { 
        if(Tavg<=(STOP_ALLOWED_PreHEAT_CHARGE_TEM+40)) ///小于等于-10度预加热
        {
            m_askvoltage = HIGHEST_ALLOWED_HEAT_CHARGE_V ;//
            CurrentAValue=0;
        }
    }
    else
    {  
        m_askvoltage = HIGHEST_ALLOWED_CHARGE_V;
        if(((g_CellHighestVol>3.78)||(ChanceHappen1==1))&&(ChanceHappen2==0))
        {
            ChanceHappen1 = 1;
        }
        if((g_CellHighestVol>3.92)||(ChanceHappen2==1))
        {
            ChanceHappen1 = 2;
            ChanceHappen2 = 1;
        }
        
        if(Tavg>=(54+40))  //如果温度大于等于55度[54,)
        {
            m_askvoltage=0;
            CurrentAValue=0;
        }
        else if(Tavg>(45+40))//如果温度45~54度(45,54)
        {
            if(ChanceHappen1<=1)
                CurrentAValue=0.5*C;////0.5c
            else
                CurrentAValue=0.33*C;////0.33c 
        }           
        else if(Tavg >(20+40)) //如果温度45~50度(20,45]
        {
            if(ChanceHappen1<=1)
                CurrentAValue=115;
            else
                CurrentAValue=0.33*C;////0.33c     
        }
        else if(Tavg >(15+40)) //如果温度(15,20]
        {
            if(ChanceHappen1==0)
                CurrentAValue=115;
            else if(ChanceHappen1==1)
                CurrentAValue=0.5*C;////0.33c
            else if(ChanceHappen1==2)
                CurrentAValue=0.33*C;////0.33c     
                 
        }
        else if(Tavg >(10+40)) //如果温度45~50度(10,15]
        {
            if(ChanceHappen1==0)
                CurrentAValue=0.6*C;
            else if(ChanceHappen1==1)
                CurrentAValue=0.5*C;////0.33c
            else if(ChanceHappen1==2)
                CurrentAValue=0.33*C;////0.33c 
        } 
        else if(Tavg >(5+40)) //如果温度25~30度(5,10]
        {
            if(ChanceHappen1==0)
                CurrentAValue=0.5*C;
            else if(ChanceHappen1==1)
                CurrentAValue=0.4*C;////0.4c
            else if(ChanceHappen1==2)
                CurrentAValue=0.3*C;////0.3c 
        }
        else if(Tavg >(0+40)) //如果温度10~25度(0,5]
        {
            if(ChanceHappen1==0)
                CurrentAValue=0.4*C;
            else if(ChanceHappen1==1)
                CurrentAValue=0.3*C;////0.3c
            else if(ChanceHappen1==2)
                CurrentAValue=0.2*C;////0.2c 
        }
        else if(Tavg >(-10+40))//如果温度5~10度(-10,0]
        {
            CurrentAValue=0.08*C;////0.08c
        }
        else if(Tavg >=(-15+40))//[-15~-10]
        {
            CurrentAValue=0.05*C;////0.5c 
        }
        else //如果温度小于0度，则请求电压为0，请求电流为0
        {
            m_askvoltage=0;
            CurrentAValue=0;
        }   
    }
    if(CurrentAValue>=40.95)
        CurrentAValue = 40.95;
    if(CutACChaCurt50.word!=0)
        CurrentAValue = 0.5*CurrentAValue;
    
    return CurrentAValue;         
}
//**********************************************************************
//* Function name:   ACFaultDone
//* Description:     慢充过程中故障的处理
//* EntryParameter : None
//* ReturnValue    : 是否下电0:不下电;1:下电
//**********************************************************************
unsigned char ACFaultDone(void)
{
    unsigned char ReturnValue=0;
    //////////////////////////////*降电流*/////////////////////////////
   
    //////////////////////////////降电流/////////////////////////////
        

    //////////////////////////////断高压/////////////////////////////
   if((Fault_Group1.Bit.F7_Bat_Over_V_2==1)||(BMS7_Byte1.Bit.F7_Bat_Over_V_3==1)|| //总电压
       (BMS1_Byte6.Bit.F1_Cell_Over_V_2==1)||(BMS7_Byte1.Bit.F5_Cell_Over_V_3==1))//单体电压
    {
        
        OffState=1;//请求下电
        ReturnValue = 1;
    }
    else if((BMS5_Byte5.Bit.F4_P_Ins_Err_2)||(BMS5_Byte5.Bit.F6_N_Ins_Err_2)||//绝缘2级故障
            (BMS5_Byte3.Bit.F3_Ch_Sustain_Over_I_2) || (BMS7_Byte2.Bit.F1_Ch_Sustain_Over_I_3)) //充电电流2级、3级
    {
        OffState=1;//请求下电
        ReturnValue = 1;    
    }
    else if((ACTem1>(70+50))||(ACTem2>(70+50))||(ACCha_Flag_BST==1))//连接器温度过大、充电时电流为负 
    {
        OffState=1;//请求下电
        ReturnValue = 1;     
    }
    else if((BMS5_Byte3.Bit.F7_Temp_Over_2 == 1)||(BMS7_Byte2.Bit.F7_IN_CAN_Err == 1)//若是出现3级温度过高故障、内部通信故障
             ||(BMS7_Byte1.Bit.F3_Ch_CAN_Err==1))//交流充电机通信故障
    {
        OffState=1;//请求下电
        ReturnValue = 1;
    } 
    return ReturnValue; 

}

//******************************************************************************
//* Function name:   TaskRechargeAC
//* Description:     与车载充电机通讯，对电池进行慢充
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void TaskRechargeAC(void)
{
    static unsigned char Step = 0x00;
    static unsigned char time0=0;
    static unsigned char Changer_happen = 0;//已经充电,当由充电变为停止状态时,停止充电,防止一上电充电机上报"停止"  
    unsigned char ErrorState = 0;
    float curr=0;
    
    
    if((g_CellHighestVol>= (HIGHEST_ALLOWED_CHARGE_CV+0.05))&&(slowRechargeFinished==0)) //单体大于4.2且慢充未完成，不允许再充电。。防止反复在那充电
        Step=0xFF;
    if(st_heating!=1) //若是0表示温度大于10度；2表示温度大于0度，1是温度在0下
    {
        if(g_BatHighestTemp >= (HIGHEST_ALLOWED_CHARGE_T +40)||(g_BatLowestTemp < (LOWEST_ALLOWED_CHARGE_T +40))) //t>=55 or t<-20
            Step=0xFF;
    }
    else
    {
        if(g_BatHighestTemp >= (HIGHEST_ALLOWED_CHARGE_T+40)) //55度
            Step=0xFF;
    }
    
    if((plug_AC_CP_Connect==0)||(ChangerINError == 1))
    {
        Step = 0xff;
    }
    if((!slowRechargeFinished)&&(OBC_Request.Bit.OBCRequest==1)) //如果充电未完成
    {
        curr=GetRequestCurrentAC();        
        if((g_BatSysTotalCur<=-3)&&(g_SysSOC<0.992))
            chargeRemainderTime=(unsigned int)((Q2*(1-g_SysSOC)*60)/(-g_BatSysTotalCur));
        else if(g_SysSOC>=0.992)
            chargeRemainderTime=2;     
        chargeRemainderTime=chargeRemainderTime*60;  
    }
    ErrorState = ACFaultDone();
    if((ErrorState==1)||(CutACChaCurt0.word!=0))
    {
        m_askcurrent = 0;
        Step = 0xff;
    }
    else
    {
        m_askcurrent = curr+HeatCurt;
        if(m_askcurrent>=40.95)
            m_askcurrent = 40.95; 
    }

    if(AC_ChangerWorkState.Bit.F4_S_ChgWorkState==5)//如果已经处于充电状态
    {
        Changer_happen = 1;
        if(OBC_Out_DC_Vol>=100*50)
            pc750_group.Bit.LockAction = 2; //闭合电子锁
    } 
    else if(AC_ChangerWorkState.Bit.F4_S_ChgWorkState!=5)//由充电状态变为非充电状态
    {
      //Step = 0xFF;//先不下电
        if((OBC_Out_DC_Vol<100*50)&&(Changer_happen == 1))
        {
            pc750_group.Bit.LockAction = 1; //打开电子锁
            Changer_happen=0;
        }
    }    
            
    switch(Step)
    {
        
        case 0://初始
            OBC_Request.Bit.OBCRequest = 1;
            m_askcurrent = 0;
            m_askpower = m_askvoltage*m_askcurrent;
            
            Step = 1;
            
        case 1://Chge Step1
        
            OBC_Request.Bit.OBCRequest = 1;
            m_askpower = m_askvoltage*m_askcurrent;
            Step = 2;
            break;
            
        case 2://Chge Step2
            OBC_Request.Bit.OBCRequest = 1;
            m_askpower = m_askvoltage*m_askcurrent;
            if(g_CellHighestVol >= CHARGE_CUTDOWN_CV1)  //大于等于4.10开始降电流
                Step = 3;
            break;
            
        case 3://Chge Step3
            OBC_Request.Bit.OBCRequest = 1;
            m_askpower = m_askvoltage*m_askcurrent;
            if(g_CellHighestVol >= HIGHEST_ALLOWED_CHARGE_CV)//4.15V
            {
                time0++;
                m_askcurrent=0.5*curr;
                if(time0>=2) //延时1s后，当确实大于3.65后才下电
                {
                  
                    Step = 4;
                    m_askcurrent=0;
                    m_askpower = m_askvoltage*m_askcurrent;
                    time0=3;
                    break;  
                }
            } 
            else
            {
                time0 = 0;
                if(curr>=0.1*C)
                    m_askcurrent = 0.1*C;
                else
                    m_askcurrent = curr;
                m_askpower = m_askvoltage*m_askcurrent;
            }

            break;  
        case 4:
                SocRechargeAdjust();  ////修正SOC,只有充电充满之后才修正Q1   
                OBC_Request.Bit.OBCRequest = 0;
                m_askcurrent=0;
                m_askpower = m_askvoltage*m_askcurrent;
                Step = 0xFF;
                
            break;  
        case 0xFF://err or finish
                //pc750_group.Bit.LockAction = 1; //打开电子锁
                slowRechargeFinished=1;//交流充电完成
                m_askcurrent=0;//充电电流请求为0
                m_askpower = m_askvoltage*m_askcurrent;
                OBC_Request.Bit.OBCRequest = 0;
                state_group1.Bit.St_Charge_indicator = 3;//充电结束 To VCU
                state_group2.Bit.St_Charge_Achieve = 2;  //充电中   To VCU
                OffState=1;//状态机由110跳转40的标志位
            break;
        default:
          break;        
      }
      
}

//************************************************************************
//************************************************************************
//**************************the end******************************************
//************************************************************************