//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : InnnerCAN.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2016.2.14
//* Description        : ���ļ��Ƕ�CAN���͵ı��Ľ���BIT����
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
extern unsigned long int chargeAH ;   //ʵ�ʳ���ܰ�ʱ
extern unsigned long int dischargeAH ;//ʵ�ʷŵ��ܰ�ʱ
extern unsigned int Charge_Times;     //������

///////////////0x450////////////////////
typedef union{
	unsigned char byte;
	struct {
		byte F0_flag0:1;       
		byte F1_flag1:1;              
		byte F2_initFinished:1;              
		byte F3_flag3:1;
		byte F4_BmsCtlStat:1;
		byte F5_NegRelayState:1;
		byte F6_PrechargeRelayStat:1;
		byte F7_flag7:1;
	}Bit;
}CAN450BYTE0;    
extern CAN450BYTE0      Can450Byte0;

typedef union{
	unsigned char byte;
	struct {
		byte F0_flag0:1;       
		byte F1_flag1:1;              
		byte F2_flag2:1;              
		byte F3_BMSLowPowerOffRequest:1;
		byte F4_flag4:1;
		byte F5_ChgPowreOffReq:1;
		byte F6_7_bcuSelfcheckCounter:2;
	}Bit;
}CAN450BYTE7;    
extern CAN450BYTE7      Can450Byte7;
/////////////0x554///////////////////////////////////
typedef union{
	unsigned char byte;
	struct {
		byte F0_TotalVolUnderVol2:1;      //��ذ�Ƿѹ2�� 
		byte F1_CellUnderVol2:1;        //����Ƿѹ2��      
		byte F2_TotalVolOverVol2:1;     //��ذ���ѹ2��         
		byte F3_CellOverVol2:1;        //�����ѹ����2��
		byte F4_InsuLevelLow2:1;      //��Ե����2��
		byte F5_BatTempHigh2:1;      //�¶ȹ���2������
		byte F6_BatTempLow2:1;      //�¶ȹ���2��
		byte F7_ChaOverCur2:1;      //������2��
	}Bit;
}CAN554BYTE0;    
extern CAN554BYTE0      Can554Byte0;
//////////////////////////////////////////////////////////
typedef union{
	unsigned char byte;
	struct {
		byte F0_DischaOverCur2:1;      //�ŵ����2�� 
		byte F1_SOCLow2:1;         //SOC��2������     
		byte F2_CellVolUnbal2:1;      //�����ѹ������2��         
		byte F3_CellTempUnbal2:1;     //�����¶Ȳ�����2��
		byte F4_flag4:1;
		byte F5_flag5:2;
		byte F6_flag6:1;
		byte F7_flag7:1;
	}Bit;
}CAN554BYTE1;    
extern CAN554BYTE1      Can554Byte1;
//////////////////////////////////////////////////////////
typedef union{
	unsigned char byte;
	struct {
		byte F0_TotalVolUnderVol1:1;          //��ذ�Ƿѹ1��
		byte F1_CellUnderVol1:1;            //����Ƿѹ1��  
		byte F2_TotalVolOverVol1:1;          //��ذ���ѹ1��    
		byte F3_CellOverVol1:1;            //�����ѹ����1��
		byte F4_InsuLevelLow1:1;           //��Ե����1��
		byte F5_BatTempHigh1:1;           //�¶ȹ���1������
		byte F6_BatTempLow1:1;           //�¶ȹ���1��
		byte F7_ChaOverCur1:1;            //������1��
	}Bit;
}CAN554BYTE2;    
extern CAN554BYTE2      Can554Byte2;
//////////////////////////////////////////////////////////
typedef union{
	unsigned char byte;
	struct {
		byte F0_DischaOverCur1:1;      //�ŵ����1�� 
		byte F1_SOCLow1:1;         //SOC��1������     
		byte F2_CellVolUnbal1:1;      //�����ѹ������1��         
		byte F3_CellTempUnbal1:1;     //�����¶Ȳ�����1��
		byte F4_flag4:1;
		byte F5_flag5:2;
		byte F6_flag6:1;
		byte F7_flag7:1;
	}Bit;
}CAN554BYTE3;    
extern CAN554BYTE3      Can554Byte3;
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//************** mscan.c ********************
extern unsigned char  C0552_0;
extern unsigned char  C0552_1;
/***********************��λ�����Ϻ�״̬START************************/

typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_St_CC_16A_PC:1;	                               //CC_16״̬
	  byte F1_St_CC_32A_PC:1;                                 //CC_32״̬
	  byte F2_St_CP_PC:1;                                     //CP״̬
	  byte F3_St_ACC_PC:1;                                    //ACC״̬
	  byte F4_St_ChargeIN_PC:1;                               //ChargeIN״̬
	  byte F5_St_CC2_PC:1;                                    //CC2
	  byte F6_Reserve_Bit25:1;	        		                  //Ԥ��
	  byte F7_Reserve_Bit26:1;	        		                  //Ԥ��
	  
	}Bit;
}STATE_PC552_BYTE0;
extern STATE_PC552_BYTE0   state_pc552_Byte0;


typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_St_N_Relay_PC:1;	                          //�����̵���״̬
	  byte F1_St_P_Relay_PC:1;                           //�����̵���״̬
	  byte F2_St_H_Relay_PC:1;                           //���ȼ̵���״̬
	  byte F3_St_Pre_Relay_PC:1;                         //Ԥ��̵���״̬
	  byte F4_St_C_Relay_PC:1;                           //���̵���״̬
	  byte F5_Reserve_Bit22:1;                           //Ԥ��
	  byte F6_Reserve_Bit23:1;	        		              //Ԥ��
	  byte F7_Reserve_Bit24:1;	        		              //Ԥ��
	  
	}Bit;
}STATE_PC552_BYTE1; 
extern STATE_PC552_BYTE1   state_pc552_Byte1;


typedef union{
	unsigned char byte;
	struct {
	
		byte F0_TotalVolUnderVol3:1;          //��ذ�Ƿѹ3��
		byte F1_CellUnderVol3:1;            //����Ƿѹ3��  
		byte F2_TotalVolOverVol3:1;          //��ذ���ѹ3��    
		byte F3_CellOverVol3:1;            //�����ѹ����3��
		byte F4_InsuLevelLow3:1;           //��Ե����3��
		byte F5_BatTempHigh3:1;           //�¶ȹ���3������
		byte F6_BatTempLow3:1;           //�¶ȹ���3��
		byte F7_ChaOverCur3:1;           //������3��

	}Bit;
}FAULT_PC552_BYTE4;
extern FAULT_PC552_BYTE4   fault_pc552_Byte4;

typedef union{
	unsigned char byte;
	struct {
	
		byte F0_DischaOverCur3:1;      //�ŵ����3�� 
		byte F1_SOCLow3:1;         //SOC��3������     
		byte F2_CellVolUnbal3:1;      //�����ѹ������3��         
		byte F3_CellTempUnbal3:1;     //�����¶Ȳ�����3��	  
		byte F4_WithChgerComFault:1;	    //�복�س���ͨ�Ź���
	  byte F5_Reserve_Bit0:1;                               //����
	  byte F6_Reserve_Bit1:1;                               //����
	  byte F7_Reserve_Bit2:1;                               //����

	}Bit;
}FAULT_PC552_BYTE5;
extern FAULT_PC552_BYTE5   fault_pc552_Byte5;

typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_InterComFault:1;	                //�ڲ�ͨ�Ź���
	  byte F1_CurSenFault:1;                  //��������������
	  byte F2_TempSenFault:1;                 //�¶ȴ���������
	  byte F3_VolSenFault:1;                   //��ѹ����������
	  byte F4_M95EEPROMFault:1;               //M95EEPROM����
    byte F5_F24C64EEPROMFault:1;            //24C64EEPROM����
	  byte F6_ChaRelayAdinFault:1;                 //���̵���ճ������
	  byte F7_ChaRelayDisconFault:1;                //���̵�����·����
  		        		       
	}Bit;
}FAULT_PC552_BYTE6;
extern FAULT_PC552_BYTE6   fault_pc552_Byte6;

typedef union{
	unsigned char byte;
	struct {
	  byte F0_MSDDisconFault:1;                      //MSD��·����
	  byte F1_NRelayAdinFault:1;                      //�����̵���ճ������
	  byte F2_NRelayDisconFault:1;                    //�����̵�����·����
	  byte F3_PreResiDisconFault:1;                    //Ԥ������·����
	  byte F4_PreRelayOrPRelayAdinFault:1;               //Ԥ��̵����������̵���ճ��
	  byte F5_PreRelayDisconFault:1;                    //Ԥ��̵�����·����
	  byte F6_PRelayDisconFault:1;                      //�����̵�����·����
	  byte F7_PreChaFailedFault:1;                      //Ԥ���ʧ�ܹ���	        		       
	}Bit;
}FAULT_PC552_BYTE7;   
extern FAULT_PC552_BYTE7   fault_pc552_Byte7;

typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_1_LockAction:2;	    //������������������
	  byte F2_3_ErrorStateDone:2;  //������ʧ��״̬���
    byte F4_7_flag:4;  		        		       
	}Bit;
}PC750_GROUP;
extern PC750_GROUP pc750_group;





//extern unsigned char  BmsCtlStat0;

extern void bmsToPcInfo450(void);
extern void bmsToPcInfo451(void);
extern void bmsToPcInfo552(void);
extern void bmsToPcInfo553(void);
extern void bmsToPcInfo554(void);
extern void bmsToPcInfo750(void);

extern void sendBMSIDtoBMU(void);
extern void sendRealtimeToBMU(void); //��BMU����BMS��ǰʵʱʱ��
extern void sendBMSSFVersionToPC(void); //��BMU����BMS��ǰʵʱʱ��


extern void RecordSystem(void);      //��ʷ����
extern void RecordFaultTemperture(void);
extern void RecordRealtime(void);
extern void RecordExtremCellVoltage(void);
extern void RecordInsulation(void);//
extern void RecordVoltKB(void);
extern void RecordCellVoltage(unsigned char number);
extern void RecordEndFlag(void);//��ʾ�������
extern void ReadAHRecord(void);
extern void InTestToPC(void);
//****************************************************
//*****************************************************8
//*******************************************************8