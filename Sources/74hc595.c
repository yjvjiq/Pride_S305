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
//* Description        : ���ļ����ڽ�һ����������595оƬ��һ��unchar�����ݰ�λ�����595����Ӧ������
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
#define Hc595_Sck_Bit     8          //����һ��8λ������Ҫ���ٸ�����

#define Hc595_Sck_1     PORTA |=0x04
#define Hc595_Sck_0     PORTA &=0xfb

#define  Hc595_Rck_1   PORTA |=0x08
#define  Hc595_Rck_0   PORTA &=0xf7

#define  Hc595_Data_1  PORTA |=0x10
#define  Hc595_Data_0  PORTA &=0xef
/***********����ȫ�ֱ���*********/
unsigned char Relay_State=0;
/***********HC595************
*data��Ҫ���͵�����
*
*****************************/
//**********************************************************************
//**********************************************************************
//* Function name:   delay10usHc595
//* Description:     ��ʱ
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
//* Description:     HC595��ʼ��
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void InitialHc595(void) 
{
    DDRA |= 0x1c;  //����PA2,PA3Ϊ�����        
}
//******************************************************
//* Function name:   Write_Hc595
//* Description:     HC595��ʼ��
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void Write_Hc595(unsigned char data)
{
	  unsigned char i;
	  static unsigned int hi;

    Hc595_Rck_0;//595�������źţ���EXP_STCP��Ϊ��
    delay10usHc595();
    //hi = (0xff00&(data<<8))|(0x00ff&(data>>8));
    hi =  data;
	  for(i=1;i<=8;i++)
	  {
        if(hi & 0x80)	//����1bit���ݣ�ʹ��EXP_DATA����߱��
    			Hc595_Data_1;
    		else
    			Hc595_Data_0;
    		Hc595_Sck_0;  //595��ʱ���źţ���EXP_SHCP��Ϊ��
        delay10usHc595();
    		Hc595_Sck_1;  //595��ʱ���źţ���EXP_SHCP��Ϊ��
        delay10usHc595();
        Hc595_Sck_0; // �����ֹ©�� 
    		hi = hi << 1;
	  }	
    delay10usHc595();
  	Hc595_Rck_1;//595�������źţ���EXP_STCP��Ϊ�� 
    delay10usHc595();
    Hc595_Rck_0;//595�������źţ���EXP_STCP��Ϊ��
 
}
//******************************************************
//* Function name:   TurnOff_ALL
//* Description:     �ر����м̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_ALL(void)    //�ر����м̵���
{
    Relay_State =0;
    Write_Hc595(Relay_State);

}
//******************************************************
//* Function name:   TurnOn_CC2
//* Description:     �պϺ�12V 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void  TurnOn_CC2(void)   //�պϺ�ı����,��Ϊ6V 
{
    Relay_State |= 0x02;
    Write_Hc595(Relay_State);
    delay10usHc595();
}
//******************************************************
//* Function name:   TurnOff_CC2
//* Description:     �Ͽ���24Vϵͳ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_CC2(void) //�Ͽ���ı����,��Ϊ9V 
{
    Relay_State &= 0xfd;
    Write_Hc595(Relay_State);
    delay10usHc595();
}
//******************************************************
//* Function name:   TurnOn_INA2K
//* Description:     �պ�A2�̵���//й�ż̵��� 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void  TurnOn_INA2K(void)   //��й�ż̵��� �պϳ�縺
{
    Relay_State |= 0x04;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x10;              //���̵���״̬  for pc
    BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=1;//��縺״̬�����պ�
}
//******************************************************
//* Function name:   TurnOff_INA2K   �Ͽ���縺
//* Description:     �Ͽ�A2�̵���//й�ż̵��� 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INA2K(void) 
{
    Relay_State &= 0xfb;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xEF;//���̵���״̬  for pc 
    BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1=2;//��縺״̬�����Ͽ�
    BMS8_Byte0.Bit.F2_3_BMSInterCtorState=1; //BMS�����Ͽ��ڲ������� 
}
//******************************************************
//* Function name:   TurnOn_INA1K
//* Description:     �պ�A2�̵���//���ȼ̵��� 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INA1K(void)      //�򿪷��ȼ̵���
{
    Relay_State |= 0x08;
    Write_Hc595(Relay_State);
    delay10usHc595();
}
//******************************************************
//* Function name:   TurnOff_INA1K
//* Description:     �Ͽ�A2�̵���//���ȼ̵��� 
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
//* Description:     �պϼ��ȼ̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INHK(void)      //���ȼ̵���--- ���ȷ����Ȳ�����
{
    Relay_State |= 0x10;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x04;//���ȼ̵���״̬  for pc
    BMS6_Byte3.byte=0x55;
}
//******************************************************
//* Function name:   TurnOff_INHK
//* Description:     �Ͽ����ȼ̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INHK(void) 
{
    Relay_State &= 0xef;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xfb;//���ȼ̵���״̬  for pc 
    BMS6_Byte3.byte=0;
}
//******************************************************
//* Function name:   TurnOn_INBK
//* Description:     �պ�Ԥ��̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INBK(void)     //Ԥ���̵���
{
    Relay_State |= 0x20;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x08;//Ԥ��̵���״̬�պ�
    //
}
//******************************************************
//* Function name:   TurnOn_INBK
//* Description:     �պ�Ԥ��̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INBK(void) 
{
    Relay_State &= 0xdf;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xf7;//Ԥ��Ӵ���״̬�Ͽ�
}
//******************************************************
//* Function name:   TurnOn_INFK
//* Description:     �պϸ����̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INFK(void)   //�պϷŵ縺���̵���
{
    Relay_State |= 0x40;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x01;//�����̵���״̬�պ�
    BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=1;//to����CAN  �ŵ縺���̵����պ�
}
//******************************************************
//* Function name:   TurnOff_INFK
//* Description:     �Ͽ������̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INFK(void) //�ŵ縺
{
    Relay_State &= 0xbf;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte &=0xFE;//�����Ӵ���״̬�Ͽ�
    BMS8_Byte0.Bit.F2_3_BMSInterCtorState=1; //BMS�����Ͽ��ڲ�������
    BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=2;//�ŵ縺�Ͽ����� 
}
//******************************************************
//* Function name:   TurnOn_INZK
//* Description:     �պ������̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOn_INZK(void)                       //�����̵���
{
    Relay_State |= 0x80;
    Write_Hc595(Relay_State);
    delay10usHc595();
    state_pc552_Byte1.byte |=0x02;//�����̵���״̬�պ�
}
//******************************************************
//* Function name:   TurnOff_INZK
//* Description:     �Ͽ������̵���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************
void TurnOff_INZK(void) 
{
    
    Relay_State &= 0x7f;
    Write_Hc595(Relay_State);
    delay10usHc595();
     state_pc552_Byte1.byte &=0xfd;//�����̵���״̬�Ͽ�

}
/************LCD******************************************
***********************************************************/