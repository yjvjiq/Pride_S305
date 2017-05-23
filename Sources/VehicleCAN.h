//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : fotun_Logistics
//* File Name          : VehicleCAN.h
//* Author             : WsM
//* Version            : V1.0.0
//* Start Date         : 2016.7.8
//* Description        : ���ļ�������Ŀͨ��Э�鷢����صı��ĵ�������������
#include "mc9s12xep100.h"
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
/*
typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;             //bit0-1����
    byte F2_3_Reser:2;             //bit2-3����
    byte F4_5_BatPCtorCtrl:2;       //bit4-5������������Ӵ�������ָ��
    byte F6_7_BatNCtorCtrl:2;       //bit6-7������ظ����Ӵ�������ָ��
	}Bit;
}EVCU_BYTE0;                    //EVCU�������������Ʊ���Byte1
extern EVCU_BYTE0 EVCU_Byte0;      //EVCU�������������Ʊ���Byte1

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;                 //bit0-1����
    byte F2_4_ChaPCtorStateFeb2:3;       //bit2-4��������Ӵ��� 2 ״̬����
    byte F5_7_ChaPCtorStateFeb1:3;       //bit5-7��������Ӵ��� 1 ״̬����
	}Bit;
}EVCU_BYTE1;                          //EVCU�������������Ʊ���Byte2
extern EVCU_BYTE1 EVCU_Byte1;      //EVCU�������������Ʊ���Byte2 



typedef union{
	unsigned char byte;
	struct {
    byte F0_CellOverVol:1;   //�����ѹ
    byte F1_CellUnderVol:1;	  //����Ƿѹ
    byte F2_SOCHigh:1;    //SOC��
    byte F3_SOCLow:1;    //SOC��
    byte F4_ChaOverCur:1;     //������
    byte F5_DischaOverCur:1;   //�ŵ����
    byte F6_BatTempHigh:1;	   //������¶ȹ���
    byte F7_BatNotMatch:1;	    //��ز�ƥ�� 	        		       
	}Bit;
}BMS1_BYTE5;                //BMS1���ĵ� Byte5
extern BMS1_BYTE5  BMS1_Byte5;    //�����ѹ���߹��ͣ�SOC�ߵͣ���ŵ�������¶ȹ��ߣ���ز�ƥ��

typedef union{
	unsigned char byte;
	struct {
    byte F0_TotalVolOverVol :1;    //bit0     �ܵ�ѹ��ѹ
    byte F1_TotalVolUnderVol :1;	  //bit1      �ܵ�ѹǷѹ
    byte F2_CellVolUnbal :1;      //bit2     �����ѹ������
    byte F3_CellTempUnbal  :1;   //bit3     �¶Ȳ�����
    byte F4_6_BatFaultLevel :3;    //bit4~bit6   ��ع��ϵȼ�  
    byte F7_Reser :1;            //bit7   ����
	}Bit;
}BMS1_BYTE6;                  //BMS1�������Byte7
extern BMS1_BYTE6 BMS1_Byte6;         //�ܵ�ѹ���߹��ͣ���ص�ѹ�¶Ȳ����⣬���ϵȼ�

typedef union{
	unsigned char byte;
	struct {
    byte F0_5_Reser :6;            //bit0~bit5   ����
    byte F6_BatBalAtvState:1;	      //bit6   ������ؾ��⼤��״̬
    byte F7_ChaAndDischaState :1;	  //bit7  	��ŵ�״̬	       
	}Bit;
}BMS1_BYTE7;                //BMS1�������Byte8
extern BMS1_BYTE7 BMS1_Byte7;         //��ŵ�״̬������״̬




typedef union{
	unsigned char byte;
	struct {
    byte F0_ConFault1:1;    //bit0  ��1�����ӹ���
    byte F1_ConFault2:1;  	 //bit1  ��2�����ӹ���
    byte F2_ConFault3:1;    //bit2  ��3�����ӹ���
    byte F3_ConFault4:1;    //bit3  ��4�����ӹ���
    byte F4_ConFault5:1;    //bit4  ��5�����ӹ���
    byte F5_ConFault6:1;    //bit5  ��6�����ӹ���
    byte F6_ConFault7:1;	    //bit6  ��7�����ӹ���
    byte F7_ConFault8:1;	    //bit7  ��8�����ӹ���   
	}Bit;
}BMS5_BYTE2;             //BMS5�������Byte3
extern BMS5_BYTE2  BMS5_Byte2;            //��1-8�����ӹ���

typedef union{
	unsigned char byte;
	struct {
    byte F0_ConFault9:1;     //bit0  ��9�����ӹ���
    byte F1_ConFault10:1;  	  //bit1  ��10�����ӹ���
    byte F2_ConFault11:1;     //bit2  ��11�����ӹ���
    byte F3_ConFault12:1;     //bit3  ��12�����ӹ���
    byte F4_ConFault13:1;     //bit4  ��13�����ӹ���
    byte F5_ConFault14:1;     //bit5  ��14�����ӹ���
    byte F6_ConFault15:1;	    //bit6  ��15�����ӹ���
    byte F7_ConFault16:1;	    //bit7  ��16�����ӹ��� 
	}Bit;
}BMS5_BYTE3;                    //BMS5�������Byte4
extern BMS5_BYTE3  BMS5_Byte3;            //��9-16�����ӹ���


typedef union{
	unsigned char byte;
	struct {
    byte F0_3_Reser:4;             //bit0-4  ����
    byte F4_CutMainCtor :1;        //bit5 �����ж���������
    byte F5_ForceStopMode:1;       //bit6   ����ǿ��ͣ��ģʽ��
    byte F6_ForceDownPowerMode:1;  //bit7	����ǿ�ƽ�����ģʽ"
    byte F7_ChaPlugCon:1;         //����ͷ����
	}Bit;
}BMS5_BYTE4;                    //BMS5�������Byte5
extern BMS5_BYTE4  BMS5_Byte4;            //���ϴ���������

typedef union{
	unsigned char byte;
	struct {
    byte F0_ConFault17:1;     //bit0  ��17�����ӹ���
    byte F1_ConFault18:1;     //bit1  ��18�����ӹ���
    byte F2_ConFault19:1;     //bit2  ��19�����ӹ���
    byte F3_ConFault20:1;     //bit3  ��20�����ӹ���
    byte F4_ConFault21:1;     //bit4  ��21�����ӹ���
    byte F5_ConFault22:1;     //bit5  ��22�����ӹ���
    byte F6_ConFault23:1;	    //bit6  ��23�����ӹ���
    byte F7_ConFault24:1;	    //bit7  ��24�����ӹ���
   	}Bit;
}BMS5_BYTE5;              //BMS5�������Byte6
extern BMS5_BYTE5  BMS5_Byte5;            //��17-24�����ӹ���  Ӧ������0


typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState13:1;    //bit0  ��13�����״̬
    byte F1_BoxCoolingState13:1;  	 //bit1  ��13����ȴ״̬
    byte F2_BoxHeatingState14:1;    //bit2  ��14�����״̬
    byte F3_BoxCoolingState14:1;    //bit3  ��14����ȴ״̬
    byte F4_BoxHeatingState15:1;    //bit4  ��15�����״̬
    byte F5_BoxCoolingState15:1;    //bit5  ��15����ȴ״̬
    byte F6_BoxHeatingState16:1;    //bit6  ��16�����״̬
    byte F7_BoxCoolingState16:1;	    //bit7  ��16����ȴ״̬ 
	}Bit;
}BMS6_BYTE0;                   //BMS6�������Byte1
extern BMS6_BYTE0 BMS6_Byte0;        //13~16�� 
 
typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState9:1;     //bit0  ��9�����״̬
    byte F1_BoxCoolingState9:1;   	 //bit1  ��9����ȴ״̬
    byte F2_BoxHeatingState10:1;    //bit2  ��10�����״̬
    byte F3_BoxCoolingState10:1;    //bit3  ��10����ȴ״̬
    byte F4_BoxHeatingState11:1;    //bit4  ��11�����״̬
    byte F5_BoxCoolingState11:1;    //bit5  ��11����ȴ״̬
    byte F6_BoxHeatingState12:1;    //bit6  ��12�����״̬
    byte F7_BoxCoolingState12:1;	    //bit7  ��12����ȴ״̬ 
	}Bit;
}BMS6_BYTE1;                  //BMS6�������Byte2
extern BMS6_BYTE1 BMS6_Byte1;        //9~12��

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState5:1;    //bit0  ��5�����״̬
    byte F1_BoxCoolingState5:1;    //bit1  ��5����ȴ״̬
    byte F2_BoxHeatingState6:1;    //bit2  ��6�����״̬
    byte F3_BoxCoolingState6:1;    //bit3  ��6����ȴ״̬
    byte F4_BoxHeatingState7:1;    //bit4  ��7�����״̬
    byte F5_BoxCoolingState7:1;    //bit5  ��7����ȴ״̬
    byte F6_BoxHeatingState8:1;	   //bit6  ��8�����״̬
    byte F7_BoxCoolingState8:1;	   //bit7  ��8����ȴ״̬ 
	}Bit;
}BMS6_BYTE2;                  //BMS6�������Byte3
extern BMS6_BYTE2 BMS6_Byte2;        //5~8��

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState1:1;    //bit0  ��1�����״̬
    byte F1_BoxCoolingState1:1;    //bit1  ��1����ȴ״̬
    byte F2_BoxHeatingState2:1;    //bit2  ��2�����״̬
    byte F3_BoxCoolingState2:1;    //bit3  ��2����ȴ״̬
    byte F4_BoxHeatingState3:1;    //bit4  ��3�����״̬
    byte F5_BoxCoolingState3:1;    //bit5  ��3����ȴ״̬
    byte F6_BoxHeatingState4:1;	   //bit6  ��4�����״̬
    byte F7_BoxCoolingState4:1;	   //bit7  ��4����ȴ״̬ 
	}Bit;
}BMS6_BYTE3;                       //BMS6�������Byte4
extern BMS6_BYTE3 BMS6_Byte3;        //1~4��

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState21:1;    //bit0  ��21�����״̬
    byte F1_BoxCoolingState21:1;  	 //bit1  ��21����ȴ״̬
    byte F2_BoxHeatingState22:1;    //bit2  ��22�����״̬
    byte F3_BoxCoolingState22:1;    //bit3  ��22����ȴ״̬
    byte F4_BoxHeatingState23:1;    //bit4  ��23�����״̬
    byte F5_BoxCoolingState23:1;    //bit5  ��23����ȴ״̬
    byte F6_BoxHeatingState24:1;    //bit6  ��24�����״̬
    byte F7_BoxCoolingState24:1;	    //bit7  ��24����ȴ״̬ 
	}Bit;
}BMS6_BYTE4;                           //BMS6�������Byte5
extern BMS6_BYTE4 BMS6_Byte4;        //21~24��

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState17:1;    //bit0  ��17�����״̬
    byte F1_BoxCoolingState17:1;    //bit1  ��17����ȴ״̬
    byte F2_BoxHeatingState18:1;    //bit2  ��18�����״̬
    byte F3_BoxCoolingState18:1;    //bit3  ��18����ȴ״̬
    byte F4_BoxHeatingState19:1;    //bit4  ��19�����״̬
    byte F5_BoxCoolingState19:1;    //bit5  ��19����ȴ״̬
    byte F6_BoxHeatingState20:1;    //bit6  ��20�����״̬
    byte F7_BoxCoolingState20:1;	    //bit7  ��20����ȴ״̬ 
	}Bit;
}BMS6_BYTE5;                   //BMS6�������Byte6
extern BMS6_BYTE5 BMS6_Byte5;        //17~20��

typedef union{
	unsigned char byte;
	struct {
    byte F0_WithLECUComAlarm:1;  //bit0 �ڲ�ͨ�ű���
    byte F1_WithChgerComAlarm:1;  //bit1 �����ͨ�ű���
    byte F2_4_TotalVolUnderVolAlarm:3;     //bit2-4 �ܵ�ѹǷѹ����
    byte F5_7_TotalVolOverVolAlarm:3;      //bit5-7 �ܵ�ѹ��ѹ����
	}Bit;
}BMS7_BYTE0;                     //BMS7�������Byte1
extern BMS7_BYTE0  BMS7_Byte0;            //�ܵ�ѹǷѹ��ѹ���������LECUͨ�ű���

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;              //bit0      ����2λ
    byte F2_4_ChaOverCurAlarm:3;    //bit1     ����������
    byte F5_7_DisChaOverCurAlarm:3;  //bit2     �ŵ��������
	}Bit;
}BMS7_BYTE1;                     //BMS7�������Byte2
extern BMS7_BYTE1  BMS7_Byte1;            //�������ŵ����

typedef union{
	unsigned char byte;
	struct {
    byte F0_TempSenFault:1;     //bit0  �¶ȴ���������
    byte F1_CurSenFault:1;      //bit1  ��������������
    byte F2_4_CellUnderVolAlarm:3;    //bit2-4  ����Ƿѹ����
    byte F5_7_CellOverVolAlarm:3;     //bit5-7  �����ѹ����
	}Bit;
}BMS7_BYTE2;                      //BMS7�������Byte3
extern BMS7_BYTE2  BMS7_Byte2;            //�����ѹǷѹ���������¶ȴ���������

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;    //bit0-1  ����
    byte F2_4_CellTempUnbalAlarm:3;       //bit2-4 �����¶Ȳ����ⱨ��
    byte F5_7_CellVolUnbalAlarm:3;        //bit5-7  �����ѹ�����ⱨ��
	}Bit;
}BMS7_BYTE3;                      //BMS7�������Byte4
extern BMS7_BYTE3  BMS7_Byte3;            //�¶Ȳ����⣬��ѹ�����ⱨ��

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;    //bit0-1  ����
    byte F2_4_BatTempLowAlarm:3;      //bit2-4  ���Ƿ�±���
    byte F5_7_BatTempHighAlarm:3;      //bit5-7  ��ظ��±���
	}Bit;
}BMS7_BYTE4;                         //BMS7�������Byte5
extern BMS7_BYTE4  BMS7_Byte4;          //��ص��¸��±���

typedef union{
	unsigned char byte;
	struct {
    byte F0_2_Reser:3;           //bit0-4  ����
    byte F3_4_SOCSal:2;           //bit0-4  SOC����
    byte F5_7_SOCLowAlarm:3;      //bit2-4  SOC�ͱ���
	}Bit;
}BMS7_BYTE5;                    //BMS7�������Byte6
extern BMS7_BYTE5  BMS7_Byte5;          //SOC��

typedef union{
	unsigned char byte;
	struct {
    byte F0_5_Reser:6;           //bit0-4  ����
    byte F6_7_HighVolLock:2;   //bit2-4  ��ѹ��������
	}Bit;
}BMS7_BYTE6;                    //BMS7�������Byte6
extern BMS7_BYTE6  BMS7_Byte6;          //��ѹ��������

typedef union{
	unsigned char byte;
	struct {
		byte F0_BatState:1;          //bit0  �������״̬
		byte F1_2_BatHeatingFault:2;    //bit12    ������ؼ��ȹ���
		byte F3_7_Reser:5;           //����
	}Bit;
}BMS7_BYTE7;                 //BMS7�������Byte8
extern BMS7_BYTE7  BMS7_Byte7;          //���״̬�����ȹ���

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;               //bit0~bit1  ����
    byte F2_3_BMSInterCtorState:2;	    //bit2~bit3	 BMS �����Ͽ�����ڲ��Ӵ���״̬����
    byte F4_5_BatPCtorStateFeb:2;        //bit4~bit5 ������������Ӵ���״̬����
    byte F6_7_BatNCtorStateFeb:2;        //bit6-7   ������ظ����Ӵ���״̬����
	}Bit;
}BMS8_BYTE0;                      //BMS8�������Byte1
extern BMS8_BYTE0 BMS8_Byte0;         //������������Ӵ���״̬

typedef union{
	unsigned char byte;
	struct {	
    byte F0_2_ChaNCtorStateFeb2:3;   //bit0~bit2  ��縺���Ӵ��� 2 ״̬����
    byte F3_5_ChaNCtorStateFeb1:3;   //bit3~bit5  ��縺���Ӵ��� 1 ״̬����
    byte F6_7_ChaPCtorClose:2;       //bit6~bit7  ��������Ӵ����պ�ָ��
	}Bit;
}BMS8_BYTE1;                    // BMS8�������Byte2
extern BMS8_BYTE1 BMS8_Byte1;         //������������Ӵ���״̬

typedef union{
	unsigned char byte;
	struct {
    byte F0_ChaCtorAdin1:1;           //bit0���Ӵ��� 1 ճ��
    byte F1_ChaCtorAdin2:1;           //bit1���Ӵ��� 2 ճ��
    byte F2_BatChaOverTemp:1;        //������س�����
    byte F3_BatChaOverVol:1;         //������س���ѹ
    byte F4_BzerAlarm:1;              //�������������
    byte F5_7_Reser:3;                //����
	}Bit;
}BMS9_BYTE7;
extern BMS9_BYTE7 BMS9_Byte7;      //���������������������س���ѹ�����£����Ӵ���ճ��

 
typedef union{
	unsigned char byte;
	struct {
    byte F0_1_PalelCircuNum:2;       //bit0-1 ����·��
    byte F2_4_BMSTypeIDCode:3;    //bit2-4 ��ع���ϵͳ���ͱ�ʶ�룺
    byte F5_7_BatDeteUnitID:3;      //bit5~7 ��ؼ�ⵥԪ��ʶ	 
	}Bit;
}INFORMATION9_BYTE0;
extern INFORMATION9_BYTE0 information9_Byte0;      //��ر�ʶ

typedef union{
	unsigned char byte;
	struct {
    byte F0_InsuState:1;            //bit0��Ե״̬
    byte F1_HighVolConState:1;     //bit1��ѹ����״̬
    byte F2_WatdogStateBit:1;       //bit2���Ź�״̬
    byte F3_ChaCtrlBit:1;          //bit3������
    byte F4_6_BatType:3;          //bit4-6 ��������
    byte F7_OperaMode:1;          //bit7����ģʽ
	}Bit;
}INFORMATION9_BYTE2;
extern INFORMATION9_BYTE2 information9_Byte2;      //���״̬

typedef union{
	unsigned char byte;
	struct {
	  byte F0_1_DevFaultLevel:2;         //bit0-1�豸���ϵȼ�
	  byte F2_3_InsuLevel:2;             //bit2-3��Ե�ȼ�
	  byte F4_7_Reser:4;                //bit4-7����
	}Bit;
}INSULATEDMODEL_BYTE6;             //��Եģ��Byte7
extern INSULATEDMODEL_BYTE6 insulatedmodel_Byte6;      //�豸���ϵȼ�����Ե�ȼ�



 
*/ 
//******************************************************************************
//* �����������ⲿ�ı���
//******************************************************************************



 

extern float MaxCtousChaCur ;          //������������

extern float MaxDischaPower;                  //���˲ʱ�ŵ繦��
extern float MaxFebPower;                   //���˲ʱ��������

extern unsigned int chargeRemainderTime  ;          //ʣ����ʱ��


//******************************************************************************
//* �����������ⲿ�ĺ���
//******************************************************************************
extern void BMS1(void); 
extern void BMS2(void); 
extern void BMS3(void);
extern void BMS4(void);
extern void BMS5(void);
extern void BMS6(void);
extern void BMS7(void);
extern void BMS8(void); 
extern void BMS9(void);
extern void BMS10(void);
extern void BMS11(void);

extern void BMS_To_VCU_CellVoltage(unsigned char number);  
extern void BMS_To_VCU_CellTemp(unsigned char number); 

extern void Information_1(void) ;
extern void Information_2(void) ;
extern void Information_3(void) ;
extern void Information_4(void) ;
extern void Information_5(void) ;
extern void Information_6(void) ;
extern void Information_7(void) ;
extern void Information_8(void) ;
extern void Information_9(void) ;
extern void Information_10(void) ;
extern void Information_11(void)  ;
//extern void Information_12(void)  ;
extern void Charge_1(void);
extern void Charge_2(void);
extern void Charge_3(void); 
extern void bmsToPcTestCar(void);

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////end/////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////