//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : ����
//* File Name          : mc9s12Isr.h
//* Author             : Kxy
//* Version            : V1.0.0
//* Start Date         : 2016,07,12
//* Description        : ���ļ���Ϊϵͳͷ�ļ����Ը���Ŀ��ϵͳ�������ж���Ͷ�����ȫ�ֱ�������ȫ������
//----------------------------------------------------------------------------------------------------

#define KC 0.024  //С��������ϵ��
#define KX 0.054  //���������ϵ��
#define ADCLC (1)  //adcƫ����
#define ADCLX (1)
extern unsigned char Flag_InsulationState ;//��Ե��־λ������ֵ���ȴ���Եģ�鷢������ֵ
extern float ac[12];
extern float ax[12];
extern struct can_msg *msg;
extern unsigned char CHMStep;
extern unsigned char g_CHMFlag; //��俪ʼ��־λ����Ϊ1ʱ�ſ��Խ�������
extern unsigned char Int_Flag;  //0x01:AD�ж� 0x02:can0�ж� 

extern unsigned char g_errorRecordRead_flag;//������Ϣ��ȡ��־

extern unsigned char TestState;//����״̬����־λ
extern unsigned char DubugMode;

extern long Priority;
extern unsigned char DC_Start;//���յ�0xaa��,��ʼ�պϸ����̵���

extern unsigned char BootState ;//boot����

extern unsigned char TurnOnChangerRelay;//�պϳ��̵���

extern unsigned char FlagBRMSend;
extern unsigned char BRMStep; //BRM���Ͳ���


extern unsigned char FlagBCPSend;
extern unsigned char BCPStep;

extern unsigned char FlagBCSSend;
extern unsigned char BCSStep;

 
extern unsigned long g_mboxID;
extern unsigned char g_mboxData[1][8];// CAN2���յ��ı������ݣ�ÿ������8���ֽ�
//extern float Voltage_CHG_Out;    //������ѹ���ֵ
//extern float Current_CHG_Out;    //�����������ֵ