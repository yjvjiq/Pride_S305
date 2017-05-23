                             
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : Fault.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2016.6.7
//* Description        : ���϶���
//----------------------------------------------------------------------------------------------------

extern unsigned int g_errorCounter;
//extern unsigned char ACCOverTime;//��������ͨ�Ź���
extern unsigned char CutDischaTo0;    //�ŵ������0
extern unsigned char CutDischaTo50;   //�ŵ������50%
extern unsigned char CutFebchaTo0;    //����������0
extern unsigned char CutFebchaTo50;   //����������50%

///////////////////�������ŵ����//////////////////////
typedef union{
	unsigned int word;
	struct {	
		word F0_TotalVolUnderVol4:1;     //�ܵ�ѹǷѹ4�����ŵ������Ϊ0
		word F1_InterComFault:1;         //�ڲ�ͨ�Ź���,��ŵ������Ϊ0
		word F2_DisChaOverCur4:1;	       //�ŵ����4�����ŵ������Ϊ0
		word F3_CurSenFault:1;	         //�������������ϣ��ŵ������Ϊ0
		word F4_CellUnderVol4:1;	         //����Ƿѹ4�����ŵ������Ϊ0
		word F5_TempSenFault:1;         //�¶ȴ��������ϣ��ŵ������Ϊ0
		word F6_CellVolUnbal4:1;         //�����ѹ������4�����ŵ������Ϊ0
		word F7_CellTempUnbal4:1;       //�¶Ȳ�����4�����ŵ������Ϊ0
		word F8_BatTempHigh4:1;         //����¶ȹ���4�����ŵ������Ϊ0 
   word F9_BatTempLow4:1;         //����¶ȹ���4�����ŵ������Ϊ0
   word F10_TotalVolUnderVol3:1;      //�ܵ�ѹǷѹ3�����ŵ������Ϊ0
   word F11_DisChaOverCur3:1;       //�ŵ����3�����ŵ������Ϊ0
  	word F12_CellUnderVol3:1;        //����Ƿѹ3�����ŵ������Ϊ0
		word F13_CellTempUnbal3:1;       //�¶Ȳ�����3�����ŵ������Ϊ0
		word F14_BatTempHigh3:1;        //����¶ȹ���3�����ŵ������Ϊ0 
   word F15_WithEVCUComFault:1;	    //��EVCUͨ�Ź��ϣ��ŵ������Ϊ0  
	}Bit;
}CUTDISCURT0;
extern CUTDISCURT0 CutDisCurt0; 



typedef union{
	unsigned int word;
	struct {
	
		word F0_TotalVolUnderVol2:1;     //�ܵ�ѹǷѹ2�����ŵ������Ϊ50%
		word F1_DischaOverCur2:1;	      //�ŵ����2�����ŵ������Ϊ50%
		word F2_CellUnderVol2:1;        //����Ƿѹ2�����ŵ������Ϊ50%
		word F3_CellVolUnbal2:1;        //�����ѹ������2�����ŵ������Ϊ50%
		word F4_CellTempUnbal2:1;      //�¶Ȳ�����2�����ŵ������Ϊ50% 
		word F5_BatTempLow2:1;        //����¶ȹ���2�����ŵ������Ϊ50% 
		word F6_SOCLow2:1;	         //SOC����2�����ŵ������Ϊ50% 
		word F7_BatTempHigh2:1;        //����¶ȹ���2�����ŵ������Ϊ50% 
		word F8_15_Reser:8;     	        		       
	}Bit;
}CUTDISCURT50;
extern CUTDISCURT50 CutDisCurt50;
///////////////////�������ŵ����//////////////////////


///////////////////������(����)//////////////////////
typedef union{
	unsigned int word;
	struct {		
    word F0_TotalVolOverVol3:1;    //�ܵ�ѹ��ѹ3�����س������Ϊ0
    word F1_TotalVolOverVol4:1;    //�ܵ�ѹ��ѹ4�����س������Ϊ0
    word F2_InterComFault:1;       //�ڲ�ͨ�Ź���,��ŵ������Ϊ0
    word F3_ChaOverCur4:1;       //������4�����س������Ϊ0
    word F4_CellOverVol3:1;       //�����ѹ3�����س������Ϊ0
    word F5_CellOverVol4:1;	       //�����ѹ4�����س������Ϊ0
    word F6_CurSenFault:1;	       //�������������ϣ��س������Ϊ0
    word F7_TempSenFault:1;      //�¶ȴ��������ϣ��س������Ϊ0
    word F8_WithEVCUComFault:1;  //��EVCUͨ�Ź��ϣ��س������Ϊ0 
    word F9_CellTempUnbal4:1;    //�����¶Ȳ�����4�����س������Ϊ0 
    word F10_BatTempHigh4:1;     //����¶ȹ���4�����س������Ϊ0 
    word F11_BatTempLow4:1;     //����¶ȹ���4�����س������Ϊ0 
    word F12_SOCHigh4:1;	        //SOC����4�����س������Ϊ0 
    word F13_ChaOverCur3:1;      //������3�����س������Ϊ0
    word F14_CellTempUnbal3:1;     //�¶Ȳ�����3�����س������Ϊ0
    word F15_BatTempHigh3:1;	     //����¶ȹ���3�����س������Ϊ0    		       
	}Bit;
}CUTCHACURT0;
extern CUTCHACURT0 CutChaCurt0;



typedef union{
	unsigned int word;
	struct {
	
    word F0_TotalVolOverVol2:1;      //�ܵ�ѹ��ѹ2�����س������Ϊ50%
    word F1_ChaOverCur2:1;         //������2�����س������Ϊ50%
    word F2_CellOverVol2:1;         //�����ѹ2�����س������Ϊ50%
    word F3_CellVolUnbal2:1;         //�����ѹ������2�����س������Ϊ50%
    word F4_CellTempUnbal2:1;       //�����¶Ȳ�����2�����س������Ϊ50%	
    word F5_BatTempLow2:1;        //����¶ȹ���2�����س������Ϊ50%	
    word F6_SOCHigh2:1;	          //SOC����2�����س������Ϊ50%	
    word F7_BatTempHigh2:1;	       //����¶ȹ���2�����س������Ϊ50%	
    word F8_15_Reser: 8;
	}Bit;
}CUTCHACURT50;
extern CUTCHACURT50 CutChaCurt50;
///////////////////��������������//////////////////////



///////////////////DC��������//////////////////////

typedef union{
	unsigned int word;
	struct {
	
		word F0_TotalVolOverVol3:1;     //�ܵ�ѹ��ѹ3������������Ϊ0
		word F1_TotalVolOverVol4:1;     //�ܵ�ѹ��ѹ4������������Ϊ0
		word F2_InterComFault:1;        //�ڲ�ͨ�Ź���,��ŵ������Ϊ0
		word F3_WithChgerComFault:1;   //�����ͨ�Ź���,��������Ϊ0
		word F4_ChaOverCur4:1;        //������4������������Ϊ0
		word F5_CellOverVol1:1;	        //�����ѹ1������������Ϊ0
		word F6_CellOverVol2:1;	        //�����ѹ2������������Ϊ0
		word F7_CellOverVol3:1;         //�����ѹ3������������Ϊ0
		word F8_CellOverVol4:1;         //�����ѹ4������������Ϊ0
		word F9_CurSenFault:1;	        //�������������ϣ���������Ϊ0
		word F10_TempSenFault:1;       //�¶ȴ��������ϣ���������Ϊ0
		word F11_CellVolUnbal3:1;       //�����ѹ������3������������Ϊ0
		word F12_CellTempUnbal3:1;     //�����¶Ȳ�����3������������Ϊ0
   word F13_BatTempHigh4:1;       //����¶ȹ���4������������Ϊ0
		word F14_BatTempLow4:1;       //����¶ȹ���4������������Ϊ0
		word F15_TotalVolOverVol2:1;	     //�ܵ�ѹ��ѹ2������������Ϊ0  		       
	}Bit;
}CUTDCCHACURT0;
extern CUTDCCHACURT0 CutDCChaCurt0;

typedef union{
	unsigned int word;
	struct {
	
		word F0_ChaOverCur3:1;       //������3������������Ϊ0
		word F1_BatTempHigh3:1;      //����¶ȹ���3������������Ϊ0
 		word F2_WithEVCUComFault:1;    //��EVCUͨ�Ź��ϣ���������Ϊ0
 		word F3_ChaCurDirAno:1;       //�����������쳣����������Ϊ0
 		word F4_15_Reser:12;       
	}Bit;
}CUTDCCHACURT02;
extern CUTDCCHACURT02 CutDCChaCurt02;


typedef union{
	unsigned int word;
	struct {
		
    word F0_TotalVolOverVol2:1;     //�ܵ�ѹ��ѹ2������������Ϊ50%
    word F1_ChaOverCur2:1;        //������2���� ��������Ϊ50%
    word F2_CellVolUnbal2:1;        //�����ѹ������2������������Ϊ50%
    word F3_CellTempUnbal2:1;      //�����¶Ȳ�����2������������Ϊ50%	 
    word F4_BatTempHigh2:1;        //����¶ȹ���2������������Ϊ50%	    
    word F5_BatTempLow2:1;        //����¶ȹ���2������������Ϊ50%	    
    word F6_SOCHigh2:1;	          //SOC����2������������Ϊ50%	 
    word F7_15_Reser:9;      
	}Bit;
}CUTDCCHACURT50;
extern CUTDCCHACURT50 CutDCChaCurt50;

///////////////////DC��������//////////////////////



///////////////////AC���������//////////////////////

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

///////////////////AC���������//////////////////////
extern unsigned char g_FlagLevel;  //���ϵȼ���־λ
extern unsigned char g_DCChaPowerOffFlag;    //��Ҫ�µ�Ŀ��ģʽ��4�����ϱ�־λ
extern Bool CurrentSensorFault(void);
//extern Bool TemperatureSensorFault(void); 
extern unsigned char TaskFaultProcess(void);
extern void CarFaultDone(void);
extern unsigned char ChaCurDirAnly;//�����������쳣��־λ
extern unsigned char g_PowerOffFlag; //�µ��־λ
extern unsigned int WithEVCUComOverTime;   //������ͨ�Ź���120s��־λ
extern unsigned int WithEVCUComOverTimeFlag;   //������ͨ�Ź��ϳ�ʱ��־λ