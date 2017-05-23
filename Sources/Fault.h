                             
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : Fault.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2016.6.7
//* Description        : 故障定义
//----------------------------------------------------------------------------------------------------

extern unsigned int g_errorCounter;
//extern unsigned char ACCOverTime;//交流充电机通信故障
extern unsigned char CutDischaTo0;    //放电电流到0
extern unsigned char CutDischaTo50;   //放电电流到50%
extern unsigned char CutFebchaTo0;    //回馈电流到0
extern unsigned char CutFebchaTo50;   //回馈电流到50%

///////////////////最大允许放电电流//////////////////////
typedef union{
	unsigned int word;
	struct {	
		word F0_TotalVolUnderVol4:1;     //总电压欠压4级，放电电流降为0
		word F1_InterComFault:1;         //内部通信故障,充放电电流降为0
		word F2_DisChaOverCur4:1;	       //放电过流4级，放电电流降为0
		word F3_CurSenFault:1;	         //电流传感器故障，放电电流降为0
		word F4_CellUnderVol4:1;	         //单体欠压4级，放电电流降为0
		word F5_TempSenFault:1;         //温度传感器故障，放电电流降为0
		word F6_CellVolUnbal4:1;         //单体电压不均衡4级，放电电流降为0
		word F7_CellTempUnbal4:1;       //温度不均衡4级，放电电流降为0
		word F8_BatTempHigh4:1;         //电池温度过高4级，放电电流降为0 
   word F9_BatTempLow4:1;         //电池温度过低4级，放电电流降为0
   word F10_TotalVolUnderVol3:1;      //总电压欠压3级，放电电流降为0
   word F11_DisChaOverCur3:1;       //放电过流3级，放电电流降为0
  	word F12_CellUnderVol3:1;        //单体欠压3级，放电电流降为0
		word F13_CellTempUnbal3:1;       //温度不均衡3级，放电电流降为0
		word F14_BatTempHigh3:1;        //电池温度过高3级，放电电流降为0 
   word F15_WithEVCUComFault:1;	    //与EVCU通信故障，放电电流降为0  
	}Bit;
}CUTDISCURT0;
extern CUTDISCURT0 CutDisCurt0; 



typedef union{
	unsigned int word;
	struct {
	
		word F0_TotalVolUnderVol2:1;     //总电压欠压2级，放电电流降为50%
		word F1_DischaOverCur2:1;	      //放电过流2级，放电电流降为50%
		word F2_CellUnderVol2:1;        //单体欠压2级，放电电流降为50%
		word F3_CellVolUnbal2:1;        //单体电压不均衡2级，放电电流降为50%
		word F4_CellTempUnbal2:1;      //温度不均衡2级，放电电流降为50% 
		word F5_BatTempLow2:1;        //电池温度过低2级，放电电流降为50% 
		word F6_SOCLow2:1;	         //SOC过低2级，放电电流降为50% 
		word F7_BatTempHigh2:1;        //电池温度过高2级，放电电流降为50% 
		word F8_15_Reser:8;     	        		       
	}Bit;
}CUTDISCURT50;
extern CUTDISCURT50 CutDisCurt50;
///////////////////最大允许放电电流//////////////////////


///////////////////充电电流(回馈)//////////////////////
typedef union{
	unsigned int word;
	struct {		
    word F0_TotalVolOverVol3:1;    //总电压过压3级，回充电流降为0
    word F1_TotalVolOverVol4:1;    //总电压过压4级，回充电流降为0
    word F2_InterComFault:1;       //内部通信故障,充放电电流降为0
    word F3_ChaOverCur4:1;       //充电过流4级，回充电流降为0
    word F4_CellOverVol3:1;       //单体过压3级，回充电流降为0
    word F5_CellOverVol4:1;	       //单体过压4级，回充电流降为0
    word F6_CurSenFault:1;	       //电流传感器故障，回充电流降为0
    word F7_TempSenFault:1;      //温度传感器故障，回充电流降为0
    word F8_WithEVCUComFault:1;  //与EVCU通信故障，回充电流降为0 
    word F9_CellTempUnbal4:1;    //单体温度不均衡4级，回充电流降为0 
    word F10_BatTempHigh4:1;     //电池温度过高4级，回充电流降为0 
    word F11_BatTempLow4:1;     //电池温度过低4级，回充电流降为0 
    word F12_SOCHigh4:1;	        //SOC过高4级，回充电流降为0 
    word F13_ChaOverCur3:1;      //充电过流3级，回充电流降为0
    word F14_CellTempUnbal3:1;     //温度不均衡3级，回充电流降为0
    word F15_BatTempHigh3:1;	     //电池温度过高3级，回充电流降为0    		       
	}Bit;
}CUTCHACURT0;
extern CUTCHACURT0 CutChaCurt0;



typedef union{
	unsigned int word;
	struct {
	
    word F0_TotalVolOverVol2:1;      //总电压过压2级，回充电流降为50%
    word F1_ChaOverCur2:1;         //充电过流2级，回充电流降为50%
    word F2_CellOverVol2:1;         //单体过压2级，回充电流降为50%
    word F3_CellVolUnbal2:1;         //单体电压不均衡2级，回充电流降为50%
    word F4_CellTempUnbal2:1;       //单体温度不均衡2级，回充电流降为50%	
    word F5_BatTempLow2:1;        //电池温度过低2级，回充电流降为50%	
    word F6_SOCHigh2:1;	          //SOC过高2级，回充电流降为50%	
    word F7_BatTempHigh2:1;	       //电池温度过高2级，回充电流降为50%	
    word F8_15_Reser: 8;
	}Bit;
}CUTCHACURT50;
extern CUTCHACURT50 CutChaCurt50;
///////////////////充电电流（回馈）//////////////////////



///////////////////DC快充充电电流//////////////////////

typedef union{
	unsigned int word;
	struct {
	
		word F0_TotalVolOverVol3:1;     //总电压过压3级，充电电流降为0
		word F1_TotalVolOverVol4:1;     //总电压过压4级，充电电流降为0
		word F2_InterComFault:1;        //内部通信故障,充放电电流降为0
		word F3_WithChgerComFault:1;   //与充电机通信故障,充电电流降为0
		word F4_ChaOverCur4:1;        //充电过流4级，充电电流降为0
		word F5_CellOverVol1:1;	        //单体过压1级，充电电流降为0
		word F6_CellOverVol2:1;	        //单体过压2级，充电电流降为0
		word F7_CellOverVol3:1;         //单体过压3级，充电电流降为0
		word F8_CellOverVol4:1;         //单体过压4级，充电电流降为0
		word F9_CurSenFault:1;	        //电流传感器故障，充电电流降为0
		word F10_TempSenFault:1;       //温度传感器故障，充电电流降为0
		word F11_CellVolUnbal3:1;       //单体电压不均衡3级，充电电流降为0
		word F12_CellTempUnbal3:1;     //单体温度不均衡3级，充电电流降为0
   word F13_BatTempHigh4:1;       //电池温度过高4级，充电电流降为0
		word F14_BatTempLow4:1;       //电池温度过低4级，充电电流降为0
		word F15_TotalVolOverVol2:1;	     //总电压过压2级，充电电流降为0  		       
	}Bit;
}CUTDCCHACURT0;
extern CUTDCCHACURT0 CutDCChaCurt0;

typedef union{
	unsigned int word;
	struct {
	
		word F0_ChaOverCur3:1;       //充电过流3级，充电电流降为0
		word F1_BatTempHigh3:1;      //电池温度过高3级，充电电流降为0
 		word F2_WithEVCUComFault:1;    //与EVCU通信故障，充电电流降为0
 		word F3_ChaCurDirAno:1;       //充电电流方向异常，充电电流降为0
 		word F4_15_Reser:12;       
	}Bit;
}CUTDCCHACURT02;
extern CUTDCCHACURT02 CutDCChaCurt02;


typedef union{
	unsigned int word;
	struct {
		
    word F0_TotalVolOverVol2:1;     //总电压过压2级，充电电流降为50%
    word F1_ChaOverCur2:1;        //充电过流2级， 充电电流降为50%
    word F2_CellVolUnbal2:1;        //单体电压不均衡2级，充电电流降为50%
    word F3_CellTempUnbal2:1;      //单体温度不均衡2级，充电电流降为50%	 
    word F4_BatTempHigh2:1;        //电池温度过高2级，充电电流降为50%	    
    word F5_BatTempLow2:1;        //电池温度过低2级，充电电流降为50%	    
    word F6_SOCHigh2:1;	          //SOC过高2级，充电电流降为50%	 
    word F7_15_Reser:9;      
	}Bit;
}CUTDCCHACURT50;
extern CUTDCCHACURT50 CutDCChaCurt50;

///////////////////DC快充充电电流//////////////////////



///////////////////AC慢充充电电流//////////////////////

typedef union{
	unsigned int word;
	struct {
	
		word F0_Bat_Over_Vol2:1;     
		word F1_Bat_Over_Vol3:1; 
		word F2_Cha_Over_Cur2:1;
		word F3_Cha_Over_Cur3:1;
		word F4_Low_Isolation2:1;	
		word F5_Cell_Over_Vol2:1;
		word F6_Cell_Over_Vol3:1;
		word F7_Over_Temp2:1;	
		word F8_Under_Temp1:1;
		word F9_Cha_Count:1;
		word F10_MSD:1;
	  word F11_Com_With_Chger:1;
	  word F12_Inter_Com:1;                       
		word F1315_Rever:3;		       		       
	}Bit;
}CUTACCHACURT0;
extern CUTACCHACURT0 CutACChaCurt0;

typedef union{
	unsigned int word;
	struct {
		word F0_Bat_Over_Vol1:1;
		word F1_Cha_Over_Cur1:1;
	  word F2_Over_Temp1:1;
	    word F315_Rever:13;    	        		       
	}Bit;
}CUTACCHACURT50;
extern CUTACCHACURT50 CutACChaCurt50;

///////////////////AC慢充充电电流//////////////////////
extern unsigned char g_FlagLevel;  //故障等级标志位
extern unsigned char g_DCChaPowerOffFlag;    //需要下电的快充模式非4级故障标志位
extern Bool CurrentSensorFault(void);
//extern Bool TemperatureSensorFault(void); 
extern unsigned char TaskFaultProcess(void);
extern void CarFaultDone(void);
extern unsigned char ChaCurDirAnly;//充电电流方向异常标志位
extern unsigned char g_PowerOffFlag; //下电标志位
extern unsigned int WithEVCUComOverTime;   //与整车通信故障120s标志位
extern unsigned int WithEVCUComOverTimeFlag;   //与整车通信故障超时标志位