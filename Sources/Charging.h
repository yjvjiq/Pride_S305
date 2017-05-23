 
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : C50ES_FP
//* File Name          : Charging.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2015.7.13
//* Description        : ���ļ��Ƕ�CAN���͵ı��Ľ���BIT����
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//**************Charging.h**************************************************************
extern unsigned char slowRechargeFinished;
extern float	m_askvoltage;
extern float	m_askcurrent;
extern float  big_askcurrent;
extern float HeatCurt;
extern float	m_allowmaxvoltage;
extern unsigned char  fastend1;
extern unsigned char  fastend2;
extern unsigned char  fastend3;
extern unsigned char  fastend4;
extern unsigned char  ACEndState;//����ֹͣ��־λ
extern unsigned char fastendflag;
extern unsigned char  BMSToVCU655_1;    //ȫ��
extern unsigned char  BMSToVCU655_2;    //ȫ��
extern unsigned char  BMSToVCU655_3;    //ȫ��
extern unsigned char SelfState2;     //�Լ���������2��־
extern unsigned char SelfState3;     //�Լ���������3��־
extern unsigned char  fasterror11;
extern unsigned char  fasterror12;
extern unsigned int  chargeTimes;
extern unsigned int chargeRemainderTime;
extern unsigned char	m_chmmode;
extern unsigned char CCSOverTime;//��䳬ʱ�ж�
extern unsigned char CSTOverTime;
extern unsigned char CSDOverTime; //CSD��ʱʱ��
extern unsigned char OverTimeState;

extern float ChgeAmpReq;                //����������ֵȫ��
extern unsigned char  ReqCtlToCHG;      //������س������0������2����
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
extern float GetRequestCurrentDC(void);
extern void TaskRechargeDC(void);
extern float GetRequestCurrentAC(void);
extern void TaskRechargeAC(void);
//***************************************************************************
//****************************************************************************
//**************************************************************************
//*************************************************************************