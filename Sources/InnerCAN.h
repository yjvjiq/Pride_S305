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
//* Description        : 该文件是对CAN发送的报文进行BIT定义
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
extern unsigned long int chargeAH ;   //实际充电总安时
extern unsigned long int dischargeAH ;//实际放电总安时
extern unsigned int Charge_Times;     //充电次数

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
		byte F0_TotalVolUnderVol2:1;      //电池包欠压2级 
		byte F1_CellUnderVol2:1;        //单体欠压2级      
		byte F2_TotalVolOverVol2:1;     //电池包过压2级         
		byte F3_CellOverVol2:1;        //单体电压过高2级
		byte F4_InsuLevelLow2:1;      //绝缘过低2级
		byte F5_BatTempHigh2:1;      //温度过高2级故障
		byte F6_BatTempLow2:1;      //温度过低2级
		byte F7_ChaOverCur2:1;      //充电过流2级
	}Bit;
}CAN554BYTE0;    
extern CAN554BYTE0      Can554Byte0;
//////////////////////////////////////////////////////////
typedef union{
	unsigned char byte;
	struct {
		byte F0_DischaOverCur2:1;      //放电过流2级 
		byte F1_SOCLow2:1;         //SOC低2级故障     
		byte F2_CellVolUnbal2:1;      //单体电压不均衡2级         
		byte F3_CellTempUnbal2:1;     //单体温度不均衡2级
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
		byte F0_TotalVolUnderVol1:1;          //电池包欠压1级
		byte F1_CellUnderVol1:1;            //单体欠压1级  
		byte F2_TotalVolOverVol1:1;          //电池包过压1级    
		byte F3_CellOverVol1:1;            //单体电压过高1级
		byte F4_InsuLevelLow1:1;           //绝缘过低1级
		byte F5_BatTempHigh1:1;           //温度过高1级故障
		byte F6_BatTempLow1:1;           //温度过低1级
		byte F7_ChaOverCur1:1;            //充电过流1级
	}Bit;
}CAN554BYTE2;    
extern CAN554BYTE2      Can554Byte2;
//////////////////////////////////////////////////////////
typedef union{
	unsigned char byte;
	struct {
		byte F0_DischaOverCur1:1;      //放电过流1级 
		byte F1_SOCLow1:1;         //SOC低1级故障     
		byte F2_CellVolUnbal1:1;      //单体电压不均衡1级         
		byte F3_CellTempUnbal1:1;     //单体温度不均衡1级
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
/***********************上位机故障和状态START************************/

typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_St_CC_16A_PC:1;	                               //CC_16状态
	  byte F1_St_CC_32A_PC:1;                                 //CC_32状态
	  byte F2_St_CP_PC:1;                                     //CP状态
	  byte F3_St_ACC_PC:1;                                    //ACC状态
	  byte F4_St_ChargeIN_PC:1;                               //ChargeIN状态
	  byte F5_St_CC2_PC:1;                                    //CC2
	  byte F6_Reserve_Bit25:1;	        		                  //预留
	  byte F7_Reserve_Bit26:1;	        		                  //预留
	  
	}Bit;
}STATE_PC552_BYTE0;
extern STATE_PC552_BYTE0   state_pc552_Byte0;


typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_St_N_Relay_PC:1;	                          //负极继电器状态
	  byte F1_St_P_Relay_PC:1;                           //正极继电器状态
	  byte F2_St_H_Relay_PC:1;                           //加热继电器状态
	  byte F3_St_Pre_Relay_PC:1;                         //预充继电器状态
	  byte F4_St_C_Relay_PC:1;                           //充电继电器状态
	  byte F5_Reserve_Bit22:1;                           //预留
	  byte F6_Reserve_Bit23:1;	        		              //预留
	  byte F7_Reserve_Bit24:1;	        		              //预留
	  
	}Bit;
}STATE_PC552_BYTE1; 
extern STATE_PC552_BYTE1   state_pc552_Byte1;


typedef union{
	unsigned char byte;
	struct {
	
		byte F0_TotalVolUnderVol3:1;          //电池包欠压3级
		byte F1_CellUnderVol3:1;            //单体欠压3级  
		byte F2_TotalVolOverVol3:1;          //电池包过压3级    
		byte F3_CellOverVol3:1;            //单体电压过高3级
		byte F4_InsuLevelLow3:1;           //绝缘过低3级
		byte F5_BatTempHigh3:1;           //温度过高3级故障
		byte F6_BatTempLow3:1;           //温度过低3级
		byte F7_ChaOverCur3:1;           //充电过流3级

	}Bit;
}FAULT_PC552_BYTE4;
extern FAULT_PC552_BYTE4   fault_pc552_Byte4;

typedef union{
	unsigned char byte;
	struct {
	
		byte F0_DischaOverCur3:1;      //放电过流3级 
		byte F1_SOCLow3:1;         //SOC低3级故障     
		byte F2_CellVolUnbal3:1;      //单体电压不均衡3级         
		byte F3_CellTempUnbal3:1;     //单体温度不均衡3级	  
		byte F4_WithChgerComFault:1;	    //与车载充电机通信故障
	  byte F5_Reserve_Bit0:1;                               //保留
	  byte F6_Reserve_Bit1:1;                               //保留
	  byte F7_Reserve_Bit2:1;                               //保留

	}Bit;
}FAULT_PC552_BYTE5;
extern FAULT_PC552_BYTE5   fault_pc552_Byte5;

typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_InterComFault:1;	                //内部通信故障
	  byte F1_CurSenFault:1;                  //电流传感器故障
	  byte F2_TempSenFault:1;                 //温度传感器故障
	  byte F3_VolSenFault:1;                   //电压传感器故障
	  byte F4_M95EEPROMFault:1;               //M95EEPROM故障
    byte F5_F24C64EEPROMFault:1;            //24C64EEPROM故障
	  byte F6_ChaRelayAdinFault:1;                 //充电继电器粘连故障
	  byte F7_ChaRelayDisconFault:1;                //充电继电器断路故障
  		        		       
	}Bit;
}FAULT_PC552_BYTE6;
extern FAULT_PC552_BYTE6   fault_pc552_Byte6;

typedef union{
	unsigned char byte;
	struct {
	  byte F0_MSDDisconFault:1;                      //MSD断路故障
	  byte F1_NRelayAdinFault:1;                      //负极继电器粘连故障
	  byte F2_NRelayDisconFault:1;                    //负极继电器断路故障
	  byte F3_PreResiDisconFault:1;                    //预充电阻断路故障
	  byte F4_PreRelayOrPRelayAdinFault:1;               //预充继电器或正极继电器粘连
	  byte F5_PreRelayDisconFault:1;                    //预充继电器断路故障
	  byte F6_PRelayDisconFault:1;                      //正极继电器断路故障
	  byte F7_PreChaFailedFault:1;                      //预充电失败故障	        		       
	}Bit;
}FAULT_PC552_BYTE7;   
extern FAULT_PC552_BYTE7   fault_pc552_Byte7;

typedef union{
	unsigned char byte;
	struct {
	
	  byte F0_1_LockAction:2;	    //车辆插座电子锁控制
	  byte F2_3_ErrorStateDone:2;  //电子锁失败状态解除
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
extern void sendRealtimeToBMU(void); //给BMU发送BMS当前实时时间
extern void sendBMSSFVersionToPC(void); //给BMU发送BMS当前实时时间


extern void RecordSystem(void);      //历史故障
extern void RecordFaultTemperture(void);
extern void RecordRealtime(void);
extern void RecordExtremCellVoltage(void);
extern void RecordInsulation(void);//
extern void RecordVoltKB(void);
extern void RecordCellVoltage(unsigned char number);
extern void RecordEndFlag(void);//表示发送完成
extern void ReadAHRecord(void);
extern void InTestToPC(void);
//****************************************************
//*****************************************************8
//*******************************************************8