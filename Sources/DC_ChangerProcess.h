
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : DC_ChangerProcess.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2015.7.13
//* Description        : 该文件是对CAN发送的报文进行BIT定义
//----------------------------------------------------------------------------------------------------

extern unsigned char  g_DC_CC2;
extern float  PowerVOL; //电源电压
extern unsigned char	m_chmmode;
extern unsigned char fastendflag;
extern void GetDCTem ();
extern float	g_AskDCVol;
extern float	g_AskDCCur;
extern float AskChaCur;





extern unsigned char  fastend1;
extern unsigned char  fastend2;
extern unsigned char  fastend3;
extern unsigned char  fastend4;
extern unsigned char  fasterror11;
extern unsigned char  fasterror12;
extern unsigned char  FastEndNormalFlag;   //快充非故障下电标志位


extern unsigned char BROStopState;     //BRO接收到CRO后停止发送

extern unsigned int  chargeTimes;
extern unsigned int CRMOverTimeBefore60s;//收不到CRO报文60s，系统开机后
extern unsigned int CRMOverTimeBefore;//接收不到CRM超时
extern unsigned int CRMOverTime;//CRM超时
extern unsigned int CROOverTime; //5s未收到CRO 
extern unsigned int CROOverTime60s;//60sCRO超时发送0xaa超时
extern unsigned int CCSOverTime;      //快充超时判断
extern unsigned int CSTOverTime;
extern unsigned int CSDOverTime;      //CSD超时时间
extern unsigned char OverTimeState;

extern unsigned char CC2ResState;
extern float g_DCTemp1;
extern float g_DCTemp2;
extern float CC2VOL;
extern unsigned char DC_CC2Count;

extern unsigned char BROErrorAA;//BRO不发送0xaa
extern unsigned char DC_Vesion;//DC充电版本1：老国标;2：新国标

extern unsigned char DCStartState;
extern unsigned char SelfState3;     //自检计数器变成3标志
extern unsigned char BEMStop;
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
extern float GetRequestCurrentDC(void);
extern void TaskRechargeDC(void);
extern void GetDCTem (void);
extern void TaskDC(void);
extern void Time_CHG_PlugIn(void);
extern void Time_CHG_PullOut(void);
extern void Time_CHG_Start(void);
extern void Time_CHG_Stop(void);
//***************************************************************************