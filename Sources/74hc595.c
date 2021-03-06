//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : C50ES_FP
//* File Name          : 74HC595.C
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2015.7.13
//* Description        : 该文件用于将一个串行输入595芯片的一个unchar型数据按位输出到595的相应口线上
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#include "derivative.h" /* include peripheral declarations */
#include "BMS20.h"
//****************************************************************************
//////////////////////////////////////////////////////////////////////////
#define  THERMOSTAT_74hc595
/****************************************************************************/
#define Hc595_Sck_Bit     8          //传输一个8位数据需要多少个脉冲

#define Hc595_Sck_1     PORTA |=0x04
#define Hc595_Sck_0     PORTA &=0xfb

#define  Hc595_Rck_1   PORTA |=0x08
#define  Hc595_Rck_0   PORTA &=0xf7

#define  Hc595_Data_1  PORTA |=0x10
#define  Hc595_Data_0  PORTA &=0xef
/***********定义全局变量*********/
unsigned char Relay_State=0;
/***********HC595************
*data：要传送的数据
*
*****************************/
//**********************************************************************
//**********************************************************************
//* Function name:   delay10usHc595
//* Description:     延时
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void delay10usHc595(void) 
{
    unsigned int i;      
    for (i=0;i<100;i++);
}
//******************************************************
//* Function name:   InitialHc595
//* Description:     HC595初始化
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void InitialHc595(void) 
{
    DDRA |= 0x1c;  //设置PA2,PA3为输出口        
}
//******************************************************
//* Function name:   Write_Hc595
//* Description:     HC595初始化
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void Write_Hc595(unsigned char data)
{
	  unsigned char i;
	  static unsigned int hi;

    Hc595_Rck_0;//595的锁存信号，“EXP_STCP”为低
    delay10usHc595();
    //hi = (0xff00&(data<<8))|(0x00ff&(data>>8));
    hi =  data;
	  for(i=1;i<=8;i++)
	  {
        if(hi & 0x80)	//发送1bit数据，使“EXP_DATA”变高变低
    			Hc595_Data_1;
    		else
    			Hc595_Data_0;
    		Hc595_Sck_0;  //595的时钟信号，“EXP_SHCP”为低
        delay10usHc595();
    		Hc595_Sck_1;  //595的时钟信号，“EXP_SHCP”为高
        delay10usHc595();
        Hc595_Sck_0; // 给零防止漏电 
    		hi = hi << 1;
	  }	
    delay10usHc595();
  	Hc595_Rck_1;//595的锁存信号，“EXP_STCP”为高 
    delay10usHc595();
    Hc595_Rck_0;//595的锁存信号，“EXP_STCP”为低
 
}
//******************************************************
//* Function name:   TurnOff_ALL
//* Description:     关闭所有继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_ALL(void)    //关闭所有继电器
{
    Relay_State =0;
    Write_Hc595(Relay_State);

}
//******************************************************
//* Function name:   TurnOn_CC2
//* Description:     闭合后，12V 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void  TurnOn_CC2(void)   //闭合后改变电阻,变为6V 
{
    Relay_State |= 0x02;
    Write_Hc595(Relay_State);
    delay10usHc595();
}
//******************************************************
//* Function name:   TurnOff_CC2
//* Description:     断开后24V系统
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_CC2(void) //断开后改变电阻,变为9V 
{
    Relay_State &= 0xfd;
    Write_Hc595(Relay_State);
    delay10usHc595();
}
//******************************************************
//* Function name:   TurnOn_INA2K
//* Description:     闭合A2继电器//泄放继电器 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void  TurnOn_INA2K(void)   //打开泄放继电器 闭合充电负
{
    Relay_State |= 0x04;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x10;              //快充继电器状态  for pc
    BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=1;//充电负状态反馈闭合
}
//******************************************************
//* Function name:   TurnOff_INA2K   断开充电负
//* Description:     断开A2继电器//泄放继电器 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INA2K(void) 
{
    Relay_State &= 0xfb;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xEF;//快充继电器状态  for pc 
    BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=2;//充电负状态反馈断开
    BMS8_Byte0.Bit.F2_3_BMSInterCtorState=1; //BMS主动断开内部控制器 
}
//******************************************************
//* Function name:   TurnOn_INA1K
//* Description:     闭合A2继电器//风扇继电器 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INA1K(void)      //打开风扇继电器
{
    Relay_State |= 0x08;
    Write_Hc595(Relay_State);
    delay10usHc595();
}
//******************************************************
//* Function name:   TurnOff_INA1K
//* Description:     断开A2继电器//风扇继电器 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INA1K(void) 
{
    Relay_State &= 0xf7;
    Write_Hc595(Relay_State);
    delay10usHc595();
}
//******************************************************
//* Function name:   TurnOn_INHK
//* Description:     闭合加热继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INHK(void)      //加热继电器--- 加热反馈先不考虑
{
    Relay_State |= 0x10;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x04;//加热继电器状态  for pc
    BMS6_Byte3.byte=0x55;
}
//******************************************************
//* Function name:   TurnOff_INHK
//* Description:     断开加热继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INHK(void) 
{
    Relay_State &= 0xef;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xfb;//加热继电器状态  for pc 
    BMS6_Byte3.byte=0;
}
//******************************************************
//* Function name:   TurnOn_INBK
//* Description:     闭合预充继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INBK(void)     //预充电继电器
{
    Relay_State |= 0x20;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x08;//预充继电器状态闭合
    //
}
//******************************************************
//* Function name:   TurnOn_INBK
//* Description:     闭合预充继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INBK(void) 
{
    Relay_State &= 0xdf;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xf7;//预充接触器状态断开
}
//******************************************************
//* Function name:   TurnOn_INFK
//* Description:     闭合负极继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INFK(void)   //闭合放电负极继电器
{
    Relay_State |= 0x40;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x01;//负极继电器状态闭合
    BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=1;//to整车CAN  放电负极继电器闭合
}
//******************************************************
//* Function name:   TurnOff_INFK
//* Description:     断开负极继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INFK(void) //放电负
{
    Relay_State &= 0xbf;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xFE;//负极接触器状态断开
    BMS8_Byte0.Bit.F2_3_BMSInterCtorState=1; //BMS主动断开内部控制器
    BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=2;//放电负断开反馈 
}
//******************************************************
//* Function name:   TurnOn_INZK
//* Description:     闭合正极继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INZK(void)                       //正极继电器
{
    Relay_State |= 0x80;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x02;//正极继电器状态闭合
}
//******************************************************
//* Function name:   TurnOff_INZK
//* Description:     断开正极继电器
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INZK(void) 
{
    
    Relay_State &= 0x7f;
    Write_Hc595(Relay_State);
    delay10usHc595();
     state_pc552_Byte1.byte &=0xfd;//正极继电器状态断开

}
/************LCD******************************************
***********************************************************/