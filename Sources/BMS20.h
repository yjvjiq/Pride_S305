//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : BMS.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2011,05,26
//* Description        : ���ļ���Ϊϵͳͷ�ļ����Ը���Ŀ��ϵͳ�������ж���Ͷ�����ȫ�ֱ�������ȫ������
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------ÿ����Ŀ����Ҫ�޸ĵĲ���---------------------------------------------------------
//----------------------------------------------------------------------------------------------------

///////////////////////////////////ϵͳ����//////////////////////////////////
#define StoreAHState 0            //�����Ƿ���Դ洢
#define BMU_NUMBER 5              // BMU����
#define G_BMU_CIRCLE_FLAG 0x11111    //BMU����
#define C      176               //��籶��
//#define DubugMode      1          //����״̬������

//////////////////////////////////ֱ�����//////////////////////////////////
#define HIGHEST_ALLOWED_CHARGE_CV 3.65    //��������絥���ѹ V
#define HIGHEST_ALLOWED_CHARGE_V BATTERYCELLNUMBER*HIGHEST_ALLOWED_CHARGE_CV      //����������ܵ�ѹ V   3.65*192
#define BATTERYCELLNUMBER   189           //��ص��崮��
#define HIGHEST_ALLOWED_CHARGE_T 54       //����������¶�   54
#define LOWEST_ALLOWED_CHARGE_T -20       //����������¶�   -20
#define CHARGE_CUTDOWN_CV1 3.55           //��һ�ν�����ѹ
#define CHARGE_CUTDOWN_CV2 3.65           //�ڶ��ν�����ѹ
#define HIGHEST_ALLOWED_CHARGE_A  176.0   //ֱ�������������� A
#define SYS_NOMINAL_AH 176                //ϵͳ����� AH
#define SYS_NOMINAL_V  3.2*BATTERYCELLNUMBER                //ϵͳ���ѹ V//3.2*192
#define SYS_KWH        3.2*C*BATTERYCELLNUMBER/1000               //ϵͳ����  //240*3.2*192
#define LOWEST_ALLOWED_DISCHARGE_V  2.5*BATTERYCELLNUMBER  //��С�������ܵ�ѹ V   2.5*192
#define CONSTANT_VOL_WORK 1               //��ѹ����
#define CONSTANT_CURT_WORK 2              //��������
#define CELL_TYPE 3                       //01Ǧ����;02������;03:�������;04:�������;
                                          //05:�����;06:��Ԫ;07:�ۺ���;08:�����;FFH:����
                                          
#define HIGHEST_VOL 6900 //CML�������:���������� 
#define LOWEST_VOL 4725 //CML�������:��С�������

#define CC2VOLHIGH 6.8  //CC2������Χ��
#define CC2VOLLOW  4.5 //CC2������Χ��
////////////////////////���Ȳ�������//////////////////////////////////////////////
#define HIGHEST_ALLOWED_HEAT_CHARGE_V BATTERYCELLNUMBER*HIGHEST_ALLOWED_CHARGE_CV      //���������ȳ���ܵ�ѹ V   3.65*192
#define HIGHEST_ALLOWED_HEAT_CHARGE_C 2.13     //���������ȳ����� A
#define START_ALLOWED_PreHEAT_CHARGE_TEM 0   //����Ԥ���ȷ�ֵ
#define STOP_ALLOWED_PreHEAT_CHARGE_TEM 5    //�ر�Ԥ���ȷ�ֵ  
#define START_ALLOWED_HEAT_CHARGE_TEM 10        //�������ȷ�ֵ
#define STOP_ALLOWED_HEAT_CHARGE_TEM  15       //�رռ��ȷ�ֵ 


///////////////////////BMS��󱣻��ķ�ֵ///////////////////////
#define LOWEST_CELL_VOL  2.5       //�ŵ���С�����ѹ
#define HIGHEST_CELL_VOL 3.9      //��絥��������ѹ
#define HIGHEST_BATT_VOL BATTERYCELLNUMBER*HIGHEST_ALLOWED_CHARGE_CV       //����ܵ�ѹ3.65*192 
#define HIGHEST_TEM 54             //����¶�54

//////////////////////BMS���ʱ仯�ٶ�//////////////////////////
#define POWERSPEED  0.5       //���ʵı仯�ٶ�

//////////////////////��ѹ�ȼ�:BMS��Ե�����������ֵ//////////////////////////
#define RESVALUE  0.2       //��������Ϊ0.2K

//////////////////////BMS�궨��ѹʱ�����õ�ѹ//////////////////////////
#define HIGHVOL_19    350       //����0x19ʱ��Ӧ�ĵ�ѹ
#define HIGHVOL_23    550      //����0x23ʱ��Ӧ�ĵ�ѹ


#include <hidef.h>      /* common defines and macros */
#include <string.h>
#include "derivative.h"      /* derivative-specific definitions */
//�ײ�ͷ�ļ�
#include  "mc9s12gpio.h"
#include  "74hc595.h"
#include  "adc.h"
#include  "bmn.h"
#include  "mscan.h"
#include  "RTI.h"
#include  "sd2405.h"
#include  "dflash.h"
#include  "ProcessBMU.h"
#include  "current.h"
#include  "SocAHintegral.h"
#include  "Record.h"
#include  "Storage.h"
#include  "M95M02.h"
#include  "Connect.h"
//Ӧ�ò�ͷ�ļ�
#include  "Machine.h"
#include  "VehicleCAN.h"
#include  "InnerCAN.h"
#include  "FastChargeCAN.h"
#include  "SOF.h"
#include  "feedBack.h"
#include  "SocAdjust.h"
#include  "Heat.h"
#include  "MachineControl.h"
//#include "BatteryOverVoltage1_types.h"
#include "Fault.h"

#include "24LC64.h"
#include "InitBMS.h"
#include "mc9s12Isr.h"
#include "ParameterSetting.h"
#include "Q1Q2calculate.h"
#include "Task.h"
#include "DC_ChangerProcess.h"
//#include "AC_ChangerProcess.h"
#include "ads1015.h"
#include "Temp2Resistor_lookup1D.h"

#include "CellTemperatureUnbalance.h"
#include "CellTemperatureUnbalance_private.h"  //�¶Ȳ�������ϼ�����Ҫ���뵽ͷ�ļ���
//#include "Battery_fault_level.h"

#include "Feedback176Ah.h"           //SOF��������õ�ģ��ҲҪ���뵽ͷ�ļ���
#include "Feedback176Ah_private.h"
#include "SOF176Ah.h"
#include "SOF176Ah_private.h"
#include "FT176Ah.h"
#include "FT176Ah_private.h"
#include "rtwtypes.h"
#include "look2_iflf_linlcapw.h"

#include "zhongche.h"
//#include "can_message.h"
//#include "can_union.h"

#include "S223_StateMachine.h"
#include "TotalVoltageOverVoltage_cellnum.h"
#include "TotalVoltageOverVoltage_cellnum_private.h"
#include "TotalVoltageUnderVoltage_cellnum.h"
#include "TotalVoltageUnderVoltage_cellnum_private.h"
//*******************************************
//*******************************************
#define  uchar unsigned char
#define  uint  unsigned int
#define  ulong unsigned long
#define  HIGH 0
#define  LOW 1

// ����ṹ
typedef struct _TASK_COMPONENTS
{
    uchar Run;                 // �������б�ǣ�0-�����У�1����
    uint Timer;                // ��ʱ��
    uint ItvTime;              // �������м��ʱ��
    void (*TaskHook)(void);    // Ҫ���е�������
} TASK_COMPONENTS;       // ������
/////////
//************************************************************************
//************************************************************************
// �����嵥
typedef enum _TASK_LIST
{
    TASK_CURRENT,
    TASK_SOC,
    TASK_BMU,            
    TASK_VOLTAGE,             
    //TASK_INSULATION,             
    TASK_REPORT2PC,
    TASK_STAT_MACHINE,
    TASK_FAULT,
    //TASK_DC_RECHARGE,
    TASK_RECORD,
    //GetTavgProcess()
    TASKS_MAX      // �ܵĿɹ�����Ķ�ʱ������Ŀ                                     
} TASK_LIST;
////////
enum slaveNumber
{
S0,
S1,
S2,
S3,
S4,
S5,
S6,
S7
};
//*******************************************
//*******************************************
enum parameter_list
{
    PARA_SOC_VALUE,    //SOCʵ��ֵ
    PARA_BATCELLNUMBER,//��������
    PARA_BATTYPE,  //������ͺ�
    PARA_WHOLE_CAPACITY,//�����������
    PARA_BMU_NUMBER,//  �������

    PARA_DIFFERENCE_SINGLE_V, // �����ѹ����ֵ
    PARA_DIFFERENCE_SINGLE_T, // ����¶Ⱦ���ֵ
    PARA_BALANCE_ON_VOLTAGE, //���⿪����ѹֵ
    PARA_BALANCE_OFF_VOLTAGE,//����رյ�ѹֵ
    PARA_O_SOC_VALUE,// soc��

    PARA_OO_SOC_VALUE,// soc����
    PARA_L_SOC_VALUE,//soc��
    PARA_LL_SOC_VALUE,//soc����
    PARA_O_WHOLE_VOLTAGE, // �ܵ�ѹֵ��
    PARA_OO_WHOLE_VOLTAGE, // �ܵ�ѹֵ����

    PARA_L_WHOLE_VOLTAGE, // �ܵ�ѹֵ��
    PARA_LL_WHOLE_VOLTAGE, // �ܵ�ѹֵ����
    PARA_O_CELL_VOLTAGE, // �����ѹ�ߣ���ѹֵ��
    PARA_OO_CELL_VOLTAGE, // �����ѹ����
    PARA_L_CELL_VOLTAGE,//  �����ѹ��(Ƿѹֵ)

    PARA_LL_CELL_VOLTAGE,//  �����ѹ����
    PARA_O_TEMPERATURE,//����
    PARA_OO_TEMPERATURE,//�¶ȼ���
    PARA_L_TEMPERATURE, // �¶ȵ�
    PARA_LL_TEMPERATURE, // �¶ȼ���

    PARA_O_CONSISTENCY_V, //��ѹһ���Բ�
    PARA_OO_CONSISTENCY_V,//��ѹһ���Լ���
    PARA_O_CONSISTENCY_T, //�¶�һ���Բ�
    PARA_OO_CONSISTENCY_T,//�¶�һ���Լ���
    PARA_CURRENT,//   ������ֵ

    PARA_HIGHEST_RECHARGE_VOLTAGE,//������߳��˵�ѹ
    PARA_HIGHEST_RECHARGE_CURRENT,//������������ 
    PARA_HIGHEST_RECHARGE_CURRENT_TIME,//������������ʱ��
    PARA_HIGHEST_DISCHARGE_CURRENT,//�������ŵ���� 
    PARA_HIGHEST_CHARGE_CURRENT_TIME,//����ŵ����������ʱ��

    PARA_L_ISOLATION_RESISTANCE, //  ��Ե�����ֵ
    PARA_LL_ISOLATION_RESISTANCE, //  ��Ե�������ֵ

    PARA_ENDFLAG
};
enum storage_list 
{
    INDEX,
    TOTAL_VOLTAGE,
    TOTAL_CURRENT,
    PARA_SOC_DISPLAY, // SOCֵ
    SYS_CONTACTORS_STATE,  //�����ܸ��̵���״̬

    PARA_ERROR_LEVER,//���ϵȼ�ֵ  1:1������  2:2������
    CAUTION_FLAG_1,
    CAUTION_FLAG_2,
    CAUTION_FLAG_3,
    CAUTION_FLAG_4,

    SYS_REALTIME_SECOND,
    SYS_REALTIME_MINUTE,
    SYS_REALTIME_HOUR,
    SYS_REALTIME_WEEK,
    SYS_REALTIME_DAY,

    SYS_REALTIME_MONTH,
    SYS_REALTIME_YEAR,
    CELL_MAX_TEM,
    CELL_MIN_TEM,
    CELL_AVERAGE_TEM,

    CELL_MAX_VOLTAGE,
    CELL_MIN_VOLTAGE,
    CELL_AVERAGE_VOLTAGE,
    SYS_INSULATION_P,
    SYS_INSULATION_N,
    
    VOLT_K1,
    VOLT_B1,
    VOLT_K2,
    VOLT_B2,
    VOLT_K3,
    
    VOLT_B3,
    VERIFICATION  //У��
};

enum storage_cell_vol_list 
{  
    CELL_VOLTAGE_0,
    CELL_VOLTAGE_1,
    CELL_VOLTAGE_2,
    CELL_VOLTAGE_3,
    CELL_VOLTAGE_4,
    CELL_VOLTAGE_5,
    CELL_VOLTAGE_6,
    CELL_VOLTAGE_7,
    CELL_VOLTAGE_8,
    CELL_VOLTAGE_9,

    CELL_VOLTAGE_10,
    CELL_VOLTAGE_11,
    CELL_VOLTAGE_12,
    CELL_VOLTAGE_13,
    CELL_VOLTAGE_14,
    CELL_VOLTAGE_15,
    CELL_VOLTAGE_16,
    CELL_VOLTAGE_17,
    CELL_VOLTAGE_18,
    CELL_VOLTAGE_19,

    CELL_VOLTAGE_20,
    CELL_VOLTAGE_21,
    CELL_VOLTAGE_22,
    CELL_VOLTAGE_23,
    CELL_VOLTAGE_24,
    CELL_VOLTAGE_25,
    CELL_VOLTAGE_26,
    CELL_VOLTAGE_27,
    CELL_VOLTAGE_28,
    CELL_VOLTAGE_29,

    CELL_VOLTAGE_30,
    CELL_VOLTAGE_31,
    CELL_VOLTAGE_32,
    CELL_VOLTAGE_33,
    CELL_VOLTAGE_34,
    CELL_VOLTAGE_35,
    CELL_VOLTAGE_36,
    CELL_VOLTAGE_37,
    CELL_VOLTAGE_38,
    CELL_VOLTAGE_39,

    CELL_VOLTAGE_40,
    CELL_VOLTAGE_41,
    CELL_VOLTAGE_42,
    CELL_VOLTAGE_43,
    CELL_VOLTAGE_44,
    CELL_VOLTAGE_45,
    CELL_VOLTAGE_46,
    CELL_VOLTAGE_47,
    CELL_VOLTAGE_48,
    CELL_VOLTAGE_49,

    CELL_VOLTAGE_50,
    CELL_VOLTAGE_51,
    CELL_VOLTAGE_52,
    CELL_VOLTAGE_53,
    CELL_VOLTAGE_54,
    CELL_VOLTAGE_55,
    CELL_VOLTAGE_56,
    CELL_VOLTAGE_57,
    CELL_VOLTAGE_58,
    CELL_VOLTAGE_59,

    CELL_VOLTAGE_60,
    CELL_VOLTAGE_61,
    CELL_VOLTAGE_62,
    CELL_VOLTAGE_63,
    CELL_VOLTAGE_64,
    CELL_VOLTAGE_65,
    CELL_VOLTAGE_66,
    CELL_VOLTAGE_67,
    CELL_VOLTAGE_68,
    CELL_VOLTAGE_69,

    CELL_VOLTAGE_70,
    CELL_VOLTAGE_71,
    CELL_VOLTAGE_72,
    CELL_VOLTAGE_73,
    CELL_VOLTAGE_74,
    CELL_VOLTAGE_75,
    CELL_VOLTAGE_76,
    CELL_VOLTAGE_77,
    CELL_VOLTAGE_78,
    CELL_VOLTAGE_79,

    CELL_VOLTAGE_80,
    CELL_VOLTAGE_81,
    CELL_VOLTAGE_82,
    CELL_VOLTAGE_83,
    CELL_VOLTAGE_84,
    CELL_VOLTAGE_85,
    CELL_VOLTAGE_86,
    CELL_VOLTAGE_87,
    CELL_VOLTAGE_88,
    CELL_VOLTAGE_89,

    CELL_VOLTAGE_90,
    CELL_VOLTAGE_91,
    CELL_VOLTAGE_92,
    CELL_VOLTAGE_93,
    CELL_VOLTAGE_94,
    CELL_VOLTAGE_95,
    CELL_VOLTAGE_96,
    CELL_VOLTAGE_97,
    CELL_VOLTAGE_98,
    CELL_VOLTAGE_99,

    CELL_VOLTAGE_100,
    CELL_VOLTAGE_101,
    CELL_VOLTAGE_102,
    CELL_VOLTAGE_103,
    CELL_VOLTAGE_104,
    CELL_VOLTAGE_105,
    CELL_VOLTAGE_106,
    CELL_VOLTAGE_107,
    CELL_VOLTAGE_108,
    CELL_VOLTAGE_109,

    CELL_VOLTAGE_110,
    CELL_VOLTAGE_111,
    CELL_VOLTAGE_112,
    CELL_VOLTAGE_113,
    CELL_VOLTAGE_114,
    CELL_VOLTAGE_115,
    CELL_VOLTAGE_116,
    CELL_VOLTAGE_117,
    CELL_VOLTAGE_118,
    CELL_VOLTAGE_119,
    
    
    CELL_VOLTAGE_120,
    CELL_VOLTAGE_121,
    CELL_VOLTAGE_122,
    CELL_VOLTAGE_123,
    CELL_VOLTAGE_124,
    CELL_VOLTAGE_125,
    CELL_VOLTAGE_126,
    CELL_VOLTAGE_127,
    CELL_VOLTAGE_128,
    CELL_VOLTAGE_129,
    
    CELL_VOLTAGE_130,
    CELL_VOLTAGE_131,
    CELL_VOLTAGE_132,
    CELL_VOLTAGE_133,
    CELL_VOLTAGE_134,
    CELL_VOLTAGE_135,
    CELL_VOLTAGE_136,
    CELL_VOLTAGE_137,
    CELL_VOLTAGE_138,
    CELL_VOLTAGE_139,
    
    CELL_VOLTAGE_140,
    CELL_VOLTAGE_141,
    CELL_VOLTAGE_142,
    CELL_VOLTAGE_143,
    CELL_VOLTAGE_144,
    CELL_VOLTAGE_145,
    CELL_VOLTAGE_146,
    CELL_VOLTAGE_147,
    CELL_VOLTAGE_148,
    CELL_VOLTAGE_149,
    
    CELL_VOLTAGE_150,
    CELL_VOLTAGE_151,
    CELL_VOLTAGE_152,
    CELL_VOLTAGE_153,
    CELL_VOLTAGE_154,
    CELL_VOLTAGE_155,
    CELL_VOLTAGE_156,
    CELL_VOLTAGE_157,
    CELL_VOLTAGE_158,
    CELL_VOLTAGE_159,
    
    CELL_VOLTAGE_160,
    CELL_VOLTAGE_161,
    CELL_VOLTAGE_162,
    CELL_VOLTAGE_163,
    CELL_VOLTAGE_164,
    CELL_VOLTAGE_165,
    CELL_VOLTAGE_166,
    CELL_VOLTAGE_167,
    CELL_VOLTAGE_168,
    CELL_VOLTAGE_169,
    
    CELL_VOLTAGE_170,
    CELL_VOLTAGE_171,
    CELL_VOLTAGE_172,
    CELL_VOLTAGE_173,
    CELL_VOLTAGE_174,
    CELL_VOLTAGE_175,
    CELL_VOLTAGE_176,
    CELL_VOLTAGE_177,
    CELL_VOLTAGE_178,
    CELL_VOLTAGE_179,
    
    CELL_VOLTAGE_180,
    CELL_VOLTAGE_181,
    CELL_VOLTAGE_182,
    CELL_VOLTAGE_183,
    CELL_VOLTAGE_184,
    CELL_VOLTAGE_185,
    CELL_VOLTAGE_186,
    CELL_VOLTAGE_187,
    CELL_VOLTAGE_188,
    CELL_VOLTAGE_189,
    
    CELL_VOLTAGE_190,
    CELL_VOLTAGE_191,
    CELL_VOLTAGE_192,
    CELL_VOLTAGE_193,
    CELL_VOLTAGE_194,
    CELL_VOLTAGE_195,
    CELL_VOLTAGE_196,
    CELL_VOLTAGE_197,
    CELL_VOLTAGE_198,
    CELL_VOLTAGE_199
    
};
//    
#define LITHIUM 1     //0:ATL���                                               
#define DEVICE_SERIAL_NUMBER 0x11    //	�������к� 1byte
#define HARDWARE_VERSION 0x01    //	Ӳ���汾 ��4λ��Ч   
#define SOFTWARE_VERSION 0x01   // 	����汾 ��4λ��Ч
#define COMMUNICATION_VERSION 0x01  // ͨѶЭ��汾 ��4λ��Ч
//
//
#define ENDFLAG 96

//
#define TURN_ON 0
#define TURN_OFF 1
//
#define DISCHARGING 0 //�ŵ�
#define RECHARGING 2  //���
#define FASTRECHARGING 1  //���
#define TESTSTATE 4  //����ģʽ
//************���ϵȼ�**************/
#define FOUR 4
#define THREE 3
#define TWO 2
#define ONE 1
//************ main.c ****************************************
extern unsigned char BMS_SW_Version[8];
extern unsigned char BMUOK;
//extern unsigned char BatCellNumber;
extern unsigned char BatType;
extern unsigned char HeatFlag; //�ϵ�ǰ�¶ȱ�־λ
 //***********************************************************************************
//*******************************the end**********************************************
//************************************************************************************
///////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////


