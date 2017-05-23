
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : Machine.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2015.7.13
//* Description        : ���ļ��Ƕ�CAN���͵ı��Ľ���BIT����
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
extern unsigned int tmr_p1;
extern unsigned int tmr_p2;
extern unsigned int tmr_p3;
extern unsigned int tmr_p4;
extern unsigned int tmr_p5;
extern unsigned long Delay5s1 ;  //��ʱ5s��ʱ
extern unsigned long Delay5s2 ;  //��ʱ5s��ʱ
extern unsigned long Delay5s3 ;  //��ʱ5s��ʱ
extern unsigned long Delay10s ;  //��ʱ10s��ʱ
extern unsigned long Delay60s ;  //��ʱ60s��ʱ
//extern unsigned char g_BMSSelfCheckCounter;
//extern unsigned char  prechargeFinished;    //Ԥ�����ɱ�־λ



extern unsigned char  g_ACC_ON;
extern unsigned char g_MSDFault;                 //MSD����
extern unsigned char g_ChaNRelayAdin;        //��縺���̵���ճ��
extern unsigned char g_ChaNRelayDiscon;       //��縺���̵�����·

extern unsigned char g_DischaNRelayAdin;        //�ŵ縺���̵���ճ��
extern unsigned char g_DischaNRelayDiscon;       //�ŵ縺���̵�����·
extern unsigned char g_PreChaRelayAdin;     //Ԥ��̵���ճ��
extern unsigned char g_PRelayAdin;          //�����̵���ճ��
extern unsigned char g_PreChaRelayDiscon;  //Ԥ��̵�����·
extern unsigned char PreChaResiDiscon;       //Ԥ������·
extern unsigned char g_PreChaFailed;             //Ԥ���ʧ��
extern unsigned char g_RelayPowerOffFault;       //�̵����µ���� 
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