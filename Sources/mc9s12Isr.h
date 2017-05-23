//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : 恩驰
//* File Name          : mc9s12Isr.h
//* Author             : Kxy
//* Version            : V1.0.0
//* Start Date         : 2016,07,12
//* Description        : 该文件作为系统头文件，对该项目的系统参数进行定义和对所有全局变量进行全局声明
//----------------------------------------------------------------------------------------------------

#define KC 0.024  //小电流调整系数
#define KX 0.054  //大电流调整系数
#define ADCLC (1)  //adc偏移量
#define ADCLX (1)
extern unsigned char Flag_InsulationState ;//绝缘标志位，任意值，等待绝缘模块发出正常值
extern float ac[12];
extern float ax[12];
extern struct can_msg *msg;
extern unsigned char CHMStep;
extern unsigned char g_CHMFlag; //快充开始标志位，当为1时才可以进入握手
extern unsigned char Int_Flag;  //0x01:AD中断 0x02:can0中断 

extern unsigned char g_errorRecordRead_flag;//故障信息读取标志

extern unsigned char TestState;//测试状态机标志位
extern unsigned char DubugMode;

extern long Priority;
extern unsigned char DC_Start;//接收到0xaa后,开始闭合负极继电器

extern unsigned char BootState ;//boot程序

extern unsigned char TurnOnChangerRelay;//闭合充电继电器

extern unsigned char FlagBRMSend;
extern unsigned char BRMStep; //BRM发送步骤


extern unsigned char FlagBCPSend;
extern unsigned char BCPStep;

extern unsigned char FlagBCSSend;
extern unsigned char BCSStep;

 
extern unsigned long g_mboxID;
extern unsigned char g_mboxData[1][8];// CAN2接收到的报文数据，每个报文8个字节
//extern float Voltage_CHG_Out;    //充电机电压输出值
//extern float Current_CHG_Out;    //充电机电流输出值