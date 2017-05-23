
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : Machine.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2015.7.13
//* Description        : 该文件是对CAN发送的报文进行BIT定义
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
extern unsigned int tmr_p1;
extern unsigned int tmr_p2;
extern unsigned int tmr_p3;
extern unsigned int tmr_p4;
extern unsigned int tmr_p5;
extern unsigned long Delay5s1 ;  //延时5s计时
extern unsigned long Delay5s2 ;  //延时5s计时
extern unsigned long Delay5s3 ;  //延时5s计时
extern unsigned long Delay10s ;  //延时10s计时
extern unsigned long Delay60s ;  //延时60s计时
//extern unsigned char g_BMSSelfCheckCounter;
//extern unsigned char  prechargeFinished;    //预充电完成标志位



extern unsigned char  g_ACC_ON;
extern unsigned char g_MSDFault;                 //MSD故障
extern unsigned char g_ChaNRelayAdin;        //充电负极继电器粘连
extern unsigned char g_ChaNRelayDiscon;       //充电负极继电器断路

extern unsigned char g_DischaNRelayAdin;        //放电负极继电器粘连
extern unsigned char g_DischaNRelayDiscon;       //放电负极继电器断路
extern unsigned char g_PreChaRelayAdin;     //预充继电器粘连
extern unsigned char g_PRelayAdin;          //正极继电器粘连
extern unsigned char g_PreChaRelayDiscon;  //预充继电器断路
extern unsigned char PreChaResiDiscon;       //预充电阻断路
extern unsigned char g_PreChaFailed;             //预充电失败
extern unsigned char g_RelayPowerOffFault;       //继电器下电故障 
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
//extern void VehiclePowerOffLogic(void);
//extern void closeNegRelay(void);
//extern void openNegRelay(void);  
//extern void openPosRelay(void);
//extern void HighVoltDetectPart1(void);
//extern void HighVoltDetectPart2(void);
//extern void HighVoltDetectPart3(void);
//extern void DischaNRelayAdjoinTest(void);
//extern void ChaNRelayAdjoinTest(void);
//extern unsigned char GetTavg(unsigned char LowTem,unsigned char HighTem); 
extern void GetTavgProcess(void);
//**********************************************************
//***********************************************************
//***********************************************************
//**********************************************************
//***********************************************************
//***********************************************************