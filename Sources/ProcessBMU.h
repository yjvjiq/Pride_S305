
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S133
//* File Name          : ProcessBMU.h
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2015.7.13
//* Description        : ���ļ���BMU������ͷ�ļ�
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define SIX802_NUMBER 5    // ÿ��BMU��Ӧ��6802����
#define CELL_NUMBER 12   //ÿ��6802��Ӧ�ĵ������
#define Tem_NUMBER 2   //ÿ��6802��Ӧ���¶ȸ���
#define SLAVE_NUMBER_BEIQI 8  //����Ҫ��ĴӰ����
///////////////////////////////////////////////////////////////////////////////////////////
//************ ProcessBMU.c ****************************************
extern unsigned char g_group;  //BMU1 ��ţ� ��0~15
extern unsigned int g_singleCellVoltage[BMU_NUMBER][SIX802_NUMBER][CELL_NUMBER];  //BMU1��, 6802���飩��, �����غ�
extern unsigned char g_singleCellTemperature[BMU_NUMBER][SIX802_NUMBER][Tem_NUMBER];// 2,5,2;
//extern float g_CellHighestVol;
//extern float g_CellLowestVol;
extern float g_averageVoltage; //ƽ�������ѹ
//extern float g_SystemVoltageV0;      //ϵͳ��ѹ=�����ѹ�ۼ��ܵ�ѹ
//extern unsigned char g_BatHighestTemp;
//extern unsigned char g_BatLowestTemp;
extern unsigned char g_averageTemperature;
extern unsigned char Tavg;
extern unsigned char BoxOverFlag;
extern void MoudleConfiguration(void);
extern unsigned char g_bmu2_number_v[BMU_NUMBER];
extern unsigned char g_cell_number_v[BMU_NUMBER][5];
extern unsigned char g_bmu2_number_t[BMU_NUMBER];
extern unsigned char g_cell_number_t[BMU_NUMBER][5];

extern unsigned int g_CellVol[48][4];
extern unsigned int g_CellTemp[4][8];
extern unsigned char BatBoxHighestTemp[BMU_NUMBER];         //ÿ������¶�
extern unsigned char BatBoxLowestTemp[BMU_NUMBER];         //ÿ������¶�

extern unsigned long g_circleFlag; //һ��ѭ����ɵı�־
extern unsigned long g_configFlag;//�յ�������Ϣ��־�������ж�BMU������6805�����͵������

extern unsigned char LowVolNum;
extern unsigned char HighVolNum;
extern unsigned char HighTemNum;
extern unsigned char LowTemNum;

extern unsigned char InBoxMaxV[BMU_NUMBER];
extern unsigned char InBoxMinV[BMU_NUMBER];

extern void BMU_initial(void);
extern void BMU_Processure(void);
extern unsigned char bmuProcess2(void);
//************************************************************************
//************************************************************************
//*************************the end****************************************
//************************************************************************
//************************************************************************