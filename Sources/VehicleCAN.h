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
//* Description        : 该文件根据项目通信协议发送相关的报文到整车或交流充电机
#include "mc9s12xep100.h"
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
/*
typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;             //bit0-1保留
    byte F2_3_Reser:2;             //bit2-3保留
    byte F4_5_BatPCtorCtrl:2;       //bit4-5动力电池正极接触器控制指令
    byte F6_7_BatNCtorCtrl:2;       //bit6-7动力电池负极接触器控制指令
	}Bit;
}EVCU_BYTE0;                    //EVCU整车控制器控制报文Byte1
extern EVCU_BYTE0 EVCU_Byte0;      //EVCU整车控制器控制报文Byte1

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;                 //bit0-1保留
    byte F2_4_ChaPCtorStateFeb2:3;       //bit2-4充电正极接触器 2 状态反馈
    byte F5_7_ChaPCtorStateFeb1:3;       //bit5-7充电正极接触器 1 状态反馈
	}Bit;
}EVCU_BYTE1;                          //EVCU整车控制器控制报文Byte2
extern EVCU_BYTE1 EVCU_Byte1;      //EVCU整车控制器控制报文Byte2 



typedef union{
	unsigned char byte;
	struct {
    byte F0_CellOverVol:1;   //单体过压
    byte F1_CellUnderVol:1;	  //单体欠压
    byte F2_SOCHigh:1;    //SOC高
    byte F3_SOCLow:1;    //SOC低
    byte F4_ChaOverCur:1;     //充电过流
    byte F5_DischaOverCur:1;   //放电过流
    byte F6_BatTempHigh:1;	   //电池组温度过高
    byte F7_BatNotMatch:1;	    //电池不匹配 	        		       
	}Bit;
}BMS1_BYTE5;                //BMS1报文的 Byte5
extern BMS1_BYTE5  BMS1_Byte5;    //单体电压过高过低，SOC高低，充放电过流，温度过高，电池不匹配

typedef union{
	unsigned char byte;
	struct {
    byte F0_TotalVolOverVol :1;    //bit0     总电压过压
    byte F1_TotalVolUnderVol :1;	  //bit1      总电压欠压
    byte F2_CellVolUnbal :1;      //bit2     单体电压不均衡
    byte F3_CellTempUnbal  :1;   //bit3     温度不均衡
    byte F4_6_BatFaultLevel :3;    //bit4~bit6   电池故障等级  
    byte F7_Reser :1;            //bit7   保留
	}Bit;
}BMS1_BYTE6;                  //BMS1报文里的Byte7
extern BMS1_BYTE6 BMS1_Byte6;         //总电压过高过低，电池电压温度不均衡，故障等级

typedef union{
	unsigned char byte;
	struct {
    byte F0_5_Reser :6;            //bit0~bit5   保留
    byte F6_BatBalAtvState:1;	      //bit6   动力电池均衡激活状态
    byte F7_ChaAndDischaState :1;	  //bit7  	充放电状态	       
	}Bit;
}BMS1_BYTE7;                //BMS1报文里的Byte8
extern BMS1_BYTE7 BMS1_Byte7;         //充放电状态，激活状态




typedef union{
	unsigned char byte;
	struct {
    byte F0_ConFault1:1;    //bit0  第1箱连接故障
    byte F1_ConFault2:1;  	 //bit1  第2箱连接故障
    byte F2_ConFault3:1;    //bit2  第3箱连接故障
    byte F3_ConFault4:1;    //bit3  第4箱连接故障
    byte F4_ConFault5:1;    //bit4  第5箱连接故障
    byte F5_ConFault6:1;    //bit5  第6箱连接故障
    byte F6_ConFault7:1;	    //bit6  第7箱连接故障
    byte F7_ConFault8:1;	    //bit7  第8箱连接故障   
	}Bit;
}BMS5_BYTE2;             //BMS5报文里的Byte3
extern BMS5_BYTE2  BMS5_Byte2;            //第1-8箱连接故障

typedef union{
	unsigned char byte;
	struct {
    byte F0_ConFault9:1;     //bit0  第9箱连接故障
    byte F1_ConFault10:1;  	  //bit1  第10箱连接故障
    byte F2_ConFault11:1;     //bit2  第11箱连接故障
    byte F3_ConFault12:1;     //bit3  第12箱连接故障
    byte F4_ConFault13:1;     //bit4  第13箱连接故障
    byte F5_ConFault14:1;     //bit5  第14箱连接故障
    byte F6_ConFault15:1;	    //bit6  第15箱连接故障
    byte F7_ConFault16:1;	    //bit7  第16箱连接故障 
	}Bit;
}BMS5_BYTE3;                    //BMS5报文里的Byte4
extern BMS5_BYTE3  BMS5_Byte3;            //第9-16箱连接故障


typedef union{
	unsigned char byte;
	struct {
    byte F0_3_Reser:4;             //bit0-4  保留
    byte F4_CutMainCtor :1;        //bit5 请求切断主控制器
    byte F5_ForceStopMode:1;       //bit6   请求“强制停车模式“
    byte F6_ForceDownPowerMode:1;  //bit7	请求“强制降功率模式"
    byte F7_ChaPlugCon:1;         //充电插头连接
	}Bit;
}BMS5_BYTE4;                    //BMS5报文里的Byte5
extern BMS5_BYTE4  BMS5_Byte4;            //故障处理开关请求

typedef union{
	unsigned char byte;
	struct {
    byte F0_ConFault17:1;     //bit0  第17箱连接故障
    byte F1_ConFault18:1;     //bit1  第18箱连接故障
    byte F2_ConFault19:1;     //bit2  第19箱连接故障
    byte F3_ConFault20:1;     //bit3  第20箱连接故障
    byte F4_ConFault21:1;     //bit4  第21箱连接故障
    byte F5_ConFault22:1;     //bit5  第22箱连接故障
    byte F6_ConFault23:1;	    //bit6  第23箱连接故障
    byte F7_ConFault24:1;	    //bit7  第24箱连接故障
   	}Bit;
}BMS5_BYTE5;              //BMS5报文里的Byte6
extern BMS5_BYTE5  BMS5_Byte5;            //第17-24箱连接故障  应保留置0


typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState13:1;    //bit0  第13箱加热状态
    byte F1_BoxCoolingState13:1;  	 //bit1  第13箱冷却状态
    byte F2_BoxHeatingState14:1;    //bit2  第14箱加热状态
    byte F3_BoxCoolingState14:1;    //bit3  第14箱冷却状态
    byte F4_BoxHeatingState15:1;    //bit4  第15箱加热状态
    byte F5_BoxCoolingState15:1;    //bit5  第15箱冷却状态
    byte F6_BoxHeatingState16:1;    //bit6  第16箱加热状态
    byte F7_BoxCoolingState16:1;	    //bit7  第16箱冷却状态 
	}Bit;
}BMS6_BYTE0;                   //BMS6报文里的Byte1
extern BMS6_BYTE0 BMS6_Byte0;        //13~16箱 
 
typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState9:1;     //bit0  第9箱加热状态
    byte F1_BoxCoolingState9:1;   	 //bit1  第9箱冷却状态
    byte F2_BoxHeatingState10:1;    //bit2  第10箱加热状态
    byte F3_BoxCoolingState10:1;    //bit3  第10箱冷却状态
    byte F4_BoxHeatingState11:1;    //bit4  第11箱加热状态
    byte F5_BoxCoolingState11:1;    //bit5  第11箱冷却状态
    byte F6_BoxHeatingState12:1;    //bit6  第12箱加热状态
    byte F7_BoxCoolingState12:1;	    //bit7  第12箱冷却状态 
	}Bit;
}BMS6_BYTE1;                  //BMS6报文里的Byte2
extern BMS6_BYTE1 BMS6_Byte1;        //9~12箱

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState5:1;    //bit0  第5箱加热状态
    byte F1_BoxCoolingState5:1;    //bit1  第5箱冷却状态
    byte F2_BoxHeatingState6:1;    //bit2  第6箱加热状态
    byte F3_BoxCoolingState6:1;    //bit3  第6箱冷却状态
    byte F4_BoxHeatingState7:1;    //bit4  第7箱加热状态
    byte F5_BoxCoolingState7:1;    //bit5  第7箱冷却状态
    byte F6_BoxHeatingState8:1;	   //bit6  第8箱加热状态
    byte F7_BoxCoolingState8:1;	   //bit7  第8箱冷却状态 
	}Bit;
}BMS6_BYTE2;                  //BMS6报文里的Byte3
extern BMS6_BYTE2 BMS6_Byte2;        //5~8箱

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState1:1;    //bit0  第1箱加热状态
    byte F1_BoxCoolingState1:1;    //bit1  第1箱冷却状态
    byte F2_BoxHeatingState2:1;    //bit2  第2箱加热状态
    byte F3_BoxCoolingState2:1;    //bit3  第2箱冷却状态
    byte F4_BoxHeatingState3:1;    //bit4  第3箱加热状态
    byte F5_BoxCoolingState3:1;    //bit5  第3箱冷却状态
    byte F6_BoxHeatingState4:1;	   //bit6  第4箱加热状态
    byte F7_BoxCoolingState4:1;	   //bit7  第4箱冷却状态 
	}Bit;
}BMS6_BYTE3;                       //BMS6报文里的Byte4
extern BMS6_BYTE3 BMS6_Byte3;        //1~4箱

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState21:1;    //bit0  第21箱加热状态
    byte F1_BoxCoolingState21:1;  	 //bit1  第21箱冷却状态
    byte F2_BoxHeatingState22:1;    //bit2  第22箱加热状态
    byte F3_BoxCoolingState22:1;    //bit3  第22箱冷却状态
    byte F4_BoxHeatingState23:1;    //bit4  第23箱加热状态
    byte F5_BoxCoolingState23:1;    //bit5  第23箱冷却状态
    byte F6_BoxHeatingState24:1;    //bit6  第24箱加热状态
    byte F7_BoxCoolingState24:1;	    //bit7  第24箱冷却状态 
	}Bit;
}BMS6_BYTE4;                           //BMS6报文里的Byte5
extern BMS6_BYTE4 BMS6_Byte4;        //21~24箱

typedef union{
	unsigned char byte;
	struct {
    byte F0_BoxHeatingState17:1;    //bit0  第17箱加热状态
    byte F1_BoxCoolingState17:1;    //bit1  第17箱冷却状态
    byte F2_BoxHeatingState18:1;    //bit2  第18箱加热状态
    byte F3_BoxCoolingState18:1;    //bit3  第18箱冷却状态
    byte F4_BoxHeatingState19:1;    //bit4  第19箱加热状态
    byte F5_BoxCoolingState19:1;    //bit5  第19箱冷却状态
    byte F6_BoxHeatingState20:1;    //bit6  第20箱加热状态
    byte F7_BoxCoolingState20:1;	    //bit7  第20箱冷却状态 
	}Bit;
}BMS6_BYTE5;                   //BMS6报文里的Byte6
extern BMS6_BYTE5 BMS6_Byte5;        //17~20箱

typedef union{
	unsigned char byte;
	struct {
    byte F0_WithLECUComAlarm:1;  //bit0 内部通信报警
    byte F1_WithChgerComAlarm:1;  //bit1 与充电机通信报警
    byte F2_4_TotalVolUnderVolAlarm:3;     //bit2-4 总电压欠压报警
    byte F5_7_TotalVolOverVolAlarm:3;      //bit5-7 总电压过压报警
	}Bit;
}BMS7_BYTE0;                     //BMS7报文里的Byte1
extern BMS7_BYTE0  BMS7_Byte0;            //总电压欠压过压，与充电机，LECU通信报警

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;              //bit0      保留2位
    byte F2_4_ChaOverCurAlarm:3;    //bit1     充电过流报警
    byte F5_7_DisChaOverCurAlarm:3;  //bit2     放电过流报警
	}Bit;
}BMS7_BYTE1;                     //BMS7报文里的Byte2
extern BMS7_BYTE1  BMS7_Byte1;            //充电过流放电过流

typedef union{
	unsigned char byte;
	struct {
    byte F0_TempSenFault:1;     //bit0  温度传感器故障
    byte F1_CurSenFault:1;      //bit1  电流传感器故障
    byte F2_4_CellUnderVolAlarm:3;    //bit2-4  单体欠压报警
    byte F5_7_CellOverVolAlarm:3;     //bit5-7  单体过压报警
	}Bit;
}BMS7_BYTE2;                      //BMS7报文里的Byte3
extern BMS7_BYTE2  BMS7_Byte2;            //单体过压欠压，电流，温度传感器故障

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;    //bit0-1  保留
    byte F2_4_CellTempUnbalAlarm:3;       //bit2-4 单体温度不均衡报警
    byte F5_7_CellVolUnbalAlarm:3;        //bit5-7  单体电压不均衡报警
	}Bit;
}BMS7_BYTE3;                      //BMS7报文里的Byte4
extern BMS7_BYTE3  BMS7_Byte3;            //温度不均衡，电压不均衡报警

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;    //bit0-1  保留
    byte F2_4_BatTempLowAlarm:3;      //bit2-4  电池欠温报警
    byte F5_7_BatTempHighAlarm:3;      //bit5-7  电池高温报警
	}Bit;
}BMS7_BYTE4;                         //BMS7报文里的Byte5
extern BMS7_BYTE4  BMS7_Byte4;          //电池低温高温报警

typedef union{
	unsigned char byte;
	struct {
    byte F0_2_Reser:3;           //bit0-4  保留
    byte F3_4_SOCSal:2;           //bit0-4  SOC跳变
    byte F5_7_SOCLowAlarm:3;      //bit2-4  SOC低报警
	}Bit;
}BMS7_BYTE5;                    //BMS7报文里的Byte6
extern BMS7_BYTE5  BMS7_Byte5;          //SOC低

typedef union{
	unsigned char byte;
	struct {
    byte F0_5_Reser:6;           //bit0-4  保留
    byte F6_7_HighVolLock:2;   //bit2-4  高压互锁报警
	}Bit;
}BMS7_BYTE6;                    //BMS7报文里的Byte6
extern BMS7_BYTE6  BMS7_Byte6;          //高压互锁报警

typedef union{
	unsigned char byte;
	struct {
		byte F0_BatState:1;          //bit0  动力电池状态
		byte F1_2_BatHeatingFault:2;    //bit12    动力电池加热故障
		byte F3_7_Reser:5;           //保留
	}Bit;
}BMS7_BYTE7;                 //BMS7报文里的Byte8
extern BMS7_BYTE7  BMS7_Byte7;          //电池状态，加热故障

typedef union{
	unsigned char byte;
	struct {
    byte F0_1_Reser:2;               //bit0~bit1  保留
    byte F2_3_BMSInterCtorState:2;	    //bit2~bit3	 BMS 主动断开电池内部接触器状态反馈
    byte F4_5_BatPCtorStateFeb:2;        //bit4~bit5 动力电池正极接触器状态反馈
    byte F6_7_BatNCtorStateFeb:2;        //bit6-7   动力电池负极接触器状态反馈
	}Bit;
}BMS8_BYTE0;                      //BMS8报文里的Byte1
extern BMS8_BYTE0 BMS8_Byte0;         //电池正极负极接触器状态

typedef union{
	unsigned char byte;
	struct {	
    byte F0_2_ChaNCtorStateFeb2:3;   //bit0~bit2  充电负极接触器 2 状态反馈
    byte F3_5_ChaNCtorStateFeb1:3;   //bit3~bit5  充电负极接触器 1 状态反馈
    byte F6_7_ChaPCtorClose:2;       //bit6~bit7  充电正极接触器闭合指令
	}Bit;
}BMS8_BYTE1;                    // BMS8报文里的Byte2
extern BMS8_BYTE1 BMS8_Byte1;         //充电正极负极接触器状态

typedef union{
	unsigned char byte;
	struct {
    byte F0_ChaCtorAdin1:1;           //bit0充电接触器 1 粘连
    byte F1_ChaCtorAdin2:1;           //bit1充电接触器 2 粘连
    byte F2_BatChaOverTemp:1;        //动力电池充电过温
    byte F3_BatChaOverVol:1;         //动力电池充电过压
    byte F4_BzerAlarm:1;              //蜂鸣器报警输出
    byte F5_7_Reser:3;                //保留
	}Bit;
}BMS9_BYTE7;
extern BMS9_BYTE7 BMS9_Byte7;      //蜂鸣器报警输出，动力电池充电过压，过温，充电接触器粘连

 
typedef union{
	unsigned char byte;
	struct {
    byte F0_1_PalelCircuNum:2;       //bit0-1 并联路数
    byte F2_4_BMSTypeIDCode:3;    //bit2-4 电池管理系统类型标识码：
    byte F5_7_BatDeteUnitID:3;      //bit5~7 电池检测单元标识	 
	}Bit;
}INFORMATION9_BYTE0;
extern INFORMATION9_BYTE0 information9_Byte0;      //电池标识

typedef union{
	unsigned char byte;
	struct {
    byte F0_InsuState:1;            //bit0绝缘状态
    byte F1_HighVolConState:1;     //bit1高压连接状态
    byte F2_WatdogStateBit:1;       //bit2看门狗状态
    byte F3_ChaCtrlBit:1;          //bit3充电控制
    byte F4_6_BatType:3;          //bit4-6 蓄电池类型
    byte F7_OperaMode:1;          //bit7操作模式
	}Bit;
}INFORMATION9_BYTE2;
extern INFORMATION9_BYTE2 information9_Byte2;      //电池状态

typedef union{
	unsigned char byte;
	struct {
	  byte F0_1_DevFaultLevel:2;         //bit0-1设备故障等级
	  byte F2_3_InsuLevel:2;             //bit2-3绝缘等级
	  byte F4_7_Reser:4;                //bit4-7保留
	}Bit;
}INSULATEDMODEL_BYTE6;             //绝缘模块Byte7
extern INSULATEDMODEL_BYTE6 insulatedmodel_Byte6;      //设备故障等级，绝缘等级



 
*/ 
//******************************************************************************
//* 以下是用于外部的变量
//******************************************************************************



 

extern float MaxCtousChaCur ;          //最大持续充电电流

extern float MaxDischaPower;                  //最大瞬时放电功率
extern float MaxFebPower;                   //最大瞬时回馈功率

extern unsigned int chargeRemainderTime  ;          //剩余充电时间


//******************************************************************************
//* 以下是用于外部的函数
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