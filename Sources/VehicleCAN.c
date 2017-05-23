//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : VehicleCAN.c
//* Author             : Clark/������
//* Version            : V1.0.0
//* Start Date         : 2016.10.25
//* Description        : ���ļ�������Ŀͨ��Э�鷢����صı��ĵ�������������
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
BMS1_BYTE5  BMS1_Byte5;            //�����ѹ���߹��ͣ�SOC�ߵͣ���ŵ�������¶ȹ��ߣ���ز�ƥ��
BMS5_BYTE2  BMS5_Byte2;            //��1-8�����ӹ���
BMS5_BYTE3  BMS5_Byte3;            //��9-16�����ӹ���
BMS5_BYTE4  BMS5_Byte4;            //���ϴ���������
BMS5_BYTE5  BMS5_Byte5;            //��17-24�����ӹ���  Ӧ������0
BMS7_BYTE0  BMS7_Byte0;            //�ܵ�ѹǷѹ��ѹ���������LECUͨ�ű���
BMS7_BYTE1  BMS7_Byte1;            //�������ŵ����
BMS7_BYTE2  BMS7_Byte2;            //�����ѹǷѹ���������¶ȴ���������
BMS7_BYTE3  BMS7_Byte3;            //�¶Ȳ����⣬��ѹ�����ⱨ��
BMS7_BYTE4  BMS7_Byte4;          //��ص��¸��±���
BMS7_BYTE5  BMS7_Byte5;          //SOC��
BMS7_BYTE6  BMS7_Byte6;          //��ѹ��������
BMS7_BYTE7  BMS7_Byte7;          //���״̬�����ȹ���

BMS6_BYTE0 BMS6_Byte0;        //13~16��   
BMS6_BYTE1 BMS6_Byte1;        //9~12��
BMS6_BYTE2 BMS6_Byte2;        //5~8��
BMS6_BYTE3 BMS6_Byte3;        //1~4��
BMS6_BYTE4 BMS6_Byte4;        //21~24��
BMS6_BYTE5 BMS6_Byte5;        //17~20��

BMS9_BYTE7 BMS9_Byte7;      //���������������������س���ѹ�����£����Ӵ���ճ��
//INFORMATION9_BYTE0 information9_Byte0;      //��ر�ʶ
//INFORMATION9_BYTE2 information9_Byte2;      //���״̬
//INSULATEDMODEL_BYTE6 insulatedmodel_Byte6;      //�豸���ϵȼ�����Ե�ȼ�
EVCU_BYTE0 EVCU_Byte0;      //EVCU�������������Ʊ���Byte1
EVCU_BYTE1 EVCU_Byte1;      //EVCU�������������Ʊ���Byte2

BMS1_BYTE6 BMS1_Byte6;         //�ܵ�ѹ���߹��ͣ���ص�ѹ�¶Ȳ����⣬���ϵȼ�
BMS1_BYTE7 BMS1_Byte7;         //��ŵ�״̬������״̬
BMS8_BYTE0 BMS8_Byte0;         //������������Ӵ���״̬
BMS8_BYTE1 BMS8_Byte1;         //������������Ӵ���״̬





/*futon Logistics use*/
//float g_SOH=1;                                //SOH
/*                                             
float g_MaxDischaCur = 0;              //�������ŵ����
float g_MaxChaCur=0;                  //������������
float g_MaxFebCur  = 0;              //��������������
float BiggestDisCurtContinuous = 0;          //�������ŵ����
float MaxCtousChaCur = 0;          //������������
float BiggestFeedbackCurtContinuous = 0;     //��������������

float MaxChaTotalVol=0;                //����������ܵ�ѹ,BMS3
float MaxChaTotalVol1=0;            //����������ܵ�ѹ,BMS4
float LowestDischaTotalVol=0;                 //�������ŵ��ܵ�ѹ,BMS5

float MaxDischaPower = 0;              //���ŵ繦��
float MaxFebPower  = 0;              //����������
//float BiggestDisPowerContinuous = 0;          //�������ŵ繦��
//float BiggestFeedbackContinuous = 0;          //��������������

float ChaPCtorBatVol=0;                //��������Ӵ�������زࣩ��ѹ
float ChaPCtorChgerVol=0;               //��������Ӵ����������ࣩ��ѹ
float ChaNCtorBatVol=0;                //��縺���Ӵ�������زࣩ��ѹ
float ChaNCtorChgerVol=0;               //��縺���Ӵ����������ࣩ��ѹ

float ChaCtorBndVol1=0;                 //���Ӵ��� 1 ��˵�ѹ
float ChaCtorBndVol2=0;                 //���Ӵ��� 2 ��˵�ѹ
*/
unsigned int m_askpower = 0;                         //������
unsigned int chargeRemainderTime = 0;          //ʣ����ʱ��
/*
int ChaSketHighVolPTemp1=0;                   //������ 1 ��ѹ�����¶�
int ChaSketHighVolNTemp1=0;                   //������ 1 ��ѹ�����¶�
//int ChaSketHighVolPTemp2=0;                   //������ 2 ��ѹ�����¶�
//int ChaSketHighVolNTemp2=0;                   //������ 2 ��ѹ�����¶�

//unsigned char Enable_Charger_Output = 0;      //ʹ�ܳ������
//unsigned char Enable_Charger_Sleep  = 0;      //ʹ�ܳ�������

//unsigned char HighestChaCellVol=0;      //��ߵ������ѹ
//unsigned char HighestChaCellTemp=0;      //��ߵ������¶�
unsigned char g_CellLowestVolBoxNum;    //��͵����ѹ�������
unsigned char g_CellHighestVolBoxNum;   //��ߵ����ѹ�������
unsigned char g_BatLowestTempBoxNum;    //����¶��������
unsigned char g_BatHighestTempBoxNum;   //����¶��������

unsigned char g_CellLowestVolBoxPosi;   //��͵����ѹ��������λ��
unsigned char g_CellHighestVolBoxPosi;  //��ߵ����ѹ��������λ��
unsigned char g_BatLowestTempBoxPosi;   //����¶���������λ��
unsigned char g_BatHighestTempBoxPosi;  //����¶���������λ��

//unsigned int YearBCD;                       //�� BCD ��
//unsigned int MonthBCD;                      //�� BCD ��
//unsigned int DayBCD;                        //�� BCD ��
//unsigned int HourBCD;                       // ʱ BCD ��
//unsigned int MinuteBCD;                      //�� BCD ��
//float VersionNum;                     //�汾��

//unsigned char BatFac;           //��س���
//unsigned char BatArea;             //��ص���
//unsigned char BatPackInfo;   //�������Ϣ

//float BatVolLowThold;            //��ص�ѹ�ͷ�ֵ��һ�����ϣ�
//float BatVolHighThold;            //��ص�ѹ�߷�ֵ��һ�����ϣ�
//int BatPackTempLowThold;      //������¶ȵͷ�ֵ��һ�����ϣ�
//int BatPackTempHighThold;      //������¶ȸ߷�ֵ��һ�����ϣ�


float BatRatedVol;                      //��ض��ѹ
float BatRatedEnergy;                  //��ض����  KWH
float BatRemainEnergy;                 //���ʣ������  KWH



unsigned char BatTypeCode;         //������ʹ���
unsigned int Year;                   //�����������-��
unsigned int Month;                  //�����������-��
unsigned int Day;                    //�����������-��
unsigned int SeralNum;               //��ˮ��

unsigned char POnEarthInsuResi;       //���Եؾ�Ե����
unsigned char NOnEarthInsuResi;       //���Եؾ�Ե����
unsigned int InsLife;                  //��Եģ�� Life ֵ


unsigned int ChaBeginHourBCD;           // ʱ BCD �루��翪ʼʱ�䣩
unsigned int ChaBeginMinuteBCD;         // �� BCD �루��翪ʼʱ�䣩
unsigned int ChaBeginSecondBCD;        // �� BCD �루��翪ʼʱ�䣩
unsigned int ChaEndHourBCD;            // ʱ BCD �루������ʱ�䣩
unsigned int ChaEndMinuteBCD;           // �� BCD �루������ʱ�䣩
unsigned int ChaEndSecondBCD;          // �� BCD �루������ʱ�䣩
float ActalChaVol;                       // ����ѹ��ʵʱ����ʵ�ʳ���ѹ��

unsigned int ChaInHourBCD;           //ʱ BCD �루���ǹ����ʱ�䣩
unsigned int ChaInMinuteBCD;         //�� BCD �루���ǹ����ʱ�䣩
unsigned int ChaInSecondBCD;        //�� BCD �루���ǹ����ʱ�䣩
unsigned int ChaOutHourBCD;          //�� BCD �루���ǹ����ʱ�䣩
unsigned int ChaOutMinuteBCD;         //�� BCD �루���ǹ�ε�ʱ�䣩
unsigned int ChaOutSecondBCD;        //�� BCD �루���ǹ�ε�ʱ�䣩
float ActalChaCur;                       //��������ʵʱ����ʵ�ʳ�������
*/
unsigned int InsulatedTest=0;          //��Ե����־  01Ϊ������00Ϊ�ر�


//*************************************************************************************
//*************************************************************************************
//*****************************������BMS��VCU����Ϣ�ӳ���******************************
//*************************************************************************************
//*************************************************************************************
void Transfer( CAN_DATATYPE mess)
{
    struct can_msg mg;
    //struct CAN_DATATYPE mess;
    int i=0;
    unsigned char tt=100;

    mg.RTR= FALSE;  
    mg.len = mess.Length;
    mg.prty = 0;
    mg.id = mess.ID;
    
    for(i=0;i<8;i++) 
    {
        mg.data[i]=mess.Data[i];
    }
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
    
}
void BMS1(void) 
{    
    S223_BMS1();
    Transfer(Model_BMS1);   
} 
void BMS2(void) 
{
    s_life++;
    if(s_life>254)
        s_life = 0;
    S223_BMS2();
    Transfer(Model_BMS2);   
}
void BMS3(void) 
{
    S223_BMS3();
    Transfer(Model_BMS3);   
} 
void BMS4(void) 
{    
    unsigned int buff;    
    S223_BMS4();
    buff = (unsigned int)(HIGHEST_ALLOWED_CHARGE_CV*100);   // HighestChaCellVol��������絥���ѹ
    Model_BMS4.Data[5] = buff;
    Model_BMS4.Data[6] =((g_CellHighestVolBoxNum<<4)|(buff>>8));               
    Model_BMS4.Data[7] = (unsigned int)(HIGHEST_TEM+40);    //HighestChaCellTemp��������絥�����¶�
    
    Transfer(Model_BMS4);   
} 
void BMS5(void) 
{
    LowestDischaTotalVol=LOWEST_ALLOWED_DISCHARGE_V;
    S223_BMS5();
    Transfer(Model_BMS5);   
} 
void BMS6(void) 
{
    S223_BMS6();
    
    //Model_BMS6.Data[6]=0;
    //Model_BMS6.Data[7]=0; 
    Transfer(Model_BMS6);  
} 
void BMS7(void) 
{
    S223_BMS7();
    Transfer(Model_BMS7);   
} 
void BMS8(void) 
{
    S223_BMS8();
    if(stateCode==170) 
    {
        Model_BMS8.Data[3] =(unsigned int)(ActalChaVol/4); //��������Ӵ����������ࣩ��ѹ
    }
    Model_BMS8.Data[2] =(unsigned int)(g_SystemVoltageV0/4); //��������Ӵ�������زࣩ��ѹ ChaPCtorBatVol
    if((stateCode>142)&&(stateCode<180)) 
    {
        Model_BMS8.Data[5] = (unsigned int)(g_BatSysTotalVolV3/4); //��縺���Ӵ����������ࣩ��ѹ
    }
    Model_BMS8.Data[4] = (unsigned int)(g_SystemVoltageV0/4); //��縺���Ӵ�������زࣩ��ѹ ChaNCtorBatVol
    Transfer(Model_BMS8);   
} 
void BMS9(void) 
{
    unsigned int buff;    
    S223_BMS9();
    buff=(unsigned int)(g_BatSysTotalVolV3*10);     //���Ӵ��� 1 ��˵�ѹ ChaCtorBndVol1
    Model_BMS9.Data[0] = buff;                                //���ֽ�
    Model_BMS9.Data[1] = buff>>8;                             //���ֽ�
  
    Transfer(Model_BMS9);   
} 
    
void BMS10(void) 
{
    S223_BMS10();
    Transfer(Model_BMS10);   
}  
void BMS11(void) 
{
    I2CReadDate();  //��ȡϵͳʱ��	  
    YearBCD=CurrentTime[6];     //��
    MonthBCD=CurrentTime[5];    //��
    DayBCD=CurrentTime[4];     //��
    HourBCD=CurrentTime[2];     //ʱ
    MinuteBCD=CurrentTime[1];    //��
    VersionNum=1.0;
    S223_BMS11();
    Transfer(Model_BMS11);   
}
void Charge_1(void) 
{   
    unsigned int buff;    
    S223_Charge_1(); 
    buff=(unsigned int)(ActalChaVol*10);
    Model_Charge_1.Data[6] = buff;                       // ����ѹ��ʵʱ����ʵ�ʳ���ѹ)
    Model_Charge_1.Data[7] = buff>>8;                   //����ѹ��ʵʱ����ʵ�ʳ���ѹ)
    
    Transfer(Model_Charge_1);   
}
void Charge_2(void) 
{
    unsigned int buff;
    S223_Charge_2();  
    buff=(unsigned int)((ActalChaCur+3200)*10);      //��������ʵʱ����ʵ�ʳ�����)
    Model_Charge_2.Data[6] = buff;                       //��������ʵʱ����ʵ�ʳ�����)
    Model_Charge_2.Data[7] = buff>>8;                   //��������ʵʱ����ʵ�ʳ�����)
   
    Transfer(Model_Charge_2);   
} 
void Charge_3(void) 
{
    S223_Charge_3();
    Transfer(Model_Charge_3);   
}
void Information_1(void) 
{
    S223_Information_1();
    Transfer(Model_Information_1);   
} 
void Information_2(void) 
{
    S223_Information_2();
    Transfer(Model_Information_2);   
}
void Information_3(void) 
{
    
    BatPackTempHighThold=45;
    BatPackTempLowThold=-23;
    BatVolLowThold=2.8;
    BatVolHighThold=3.65;
    S223_Information_3();
    Transfer(Model_Information_3);   
}
void Information_4(void) 
{
    BatBoxNum=BMU_NUMBER;
    BatFrameNum=BATTERYCELLNUMBER;                             //����ܴ��� 1   
    BatTempNum=32;                           //������¶Ƚڵ���  
    BatRatedVol=(SYS_NOMINAL_V);                   //��ض��ѹBatRatedVol  
    BatRatedEnergy = (SYS_KWH);         //��ض���� BatRatedEnergy
    BatRemainEnergy= (SYS_KWH*(g_SysSOC));        //���ʣ������ BatRemainEnergy
    S223_Information_4();
    Transfer(Model_Information_4);   
}
void Information_5(void) 
{
    BoxCellNum1=48;     //��1�䵥������              
    BoxCellNum2=48;     //��2�䵥������
    BoxCellNum3=48;     //��3�䵥������
    BoxCellNum4=45;     //��4�䵥������
    //BoxCellNum5=33;     //��5�䵥������
    //BoxCellNum6=0x18;
    S223_Information_5();
    Transfer(Model_Information_5);   
}
void Information_6(void) 
{
    S223_Information_6();
    Transfer(Model_Information_6);   
}
void Information_7(void) 
{
    BoxTempNum1=0x08;    //��1���¶Ƚڵ�����
    BoxTempNum2=0x08;    //��2���¶Ƚڵ�����
    BoxTempNum3=0x08;    //��3���¶Ƚڵ�����
    BoxTempNum4=0x08;    //��4���¶Ƚڵ�����
    //BoxTempNum5=0x06;    //��5���¶Ƚڵ�����
    //BoxTempNum4=0x04;    //��6���¶Ƚڵ�����
    S223_Information_7();
    Transfer(Model_Information_7);   
}
void Information_8(void) 
{
    S223_Information_8();
    Transfer(Model_Information_8);   
}
void Information_9(void) 
{
    BatRemainEnergy2=(SYS_KWH*(g_SysSOC));
    BatRatedEnergy2 = (SYS_KWH);         //��ض���� BatRatedEnergy
    S223_Information_9();
    Transfer(Model_Information_9);   
}
void Information_10(void) 
{
    FacCode=0x03;
    BatTypeCode=0x01;
    Year=0x17;
    Month=0x03;
    Day=0x27;
    SeralNum=1;
    S223_Information_10();
    Transfer(Model_Information_10);   
}
/*void Information_11(void) 
{
    
    BatBoxHighestTemp1=BatBoxHighestTemp[0]-40;
    BatBoxLowestTemp1=BatBoxLowestTemp[0]-40;
    BatBoxHighestTemp2=BatBoxHighestTemp[1]-40;
    BatBoxLowestTemp2=BatBoxLowestTemp[1]-40;
    BatBoxHighestTemp3=BatBoxHighestTemp[2]-40;
    BatBoxLowestTemp3=BatBoxLowestTemp[2]-40;
    BatBoxHighestTemp4=BatBoxHighestTemp[3]-40;
    BatBoxLowestTemp4=BatBoxLowestTemp[3]-40;
    S223_Information_11();
    Transfer(Model_Information_11);   
}*/    
//*************************************************************************************
//* Function name  : BMS1(��ع���ϵͳ 1)
//* period         : 100ms
//* Description    : �ܵ�ѹ�ܵ���SOC��
//* EntryParameter : None
//* ReturnValue    : None
//*************************************************************************************
/*void BMS1(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
	  
	  buff = (unsigned int)(g_SystemVoltageV0*10);	      //��������ܵ�ѹ
	  mg.data[0] = buff;   //���ֽ� 
	  mg.data[1] = buff>>8;//���ֽ�    
	  
	  buff = (unsigned int)((g_BatSysTotalCur+3200)*10);	//��������ܵ���
	  mg.data[2] = buff;   //���ֽ� 
	  mg.data[3] = buff>>8;//���ֽ�     
    
    if(g_SysSOC>=0.995) 
        buff = 100*2.5;
    else 
        buff = (unsigned int)(g_SysSOC*100*2.5);    //ϵͳSOC
    mg.data[4] = buff;      //SOCֵ      
    
    mg.data[5] = BMS1_Byte5.byte;          //�����ѹ���߹��ͣ�SOC�ߵͣ���ŵ�������¶ȹ��ߣ���ز�ƥ��
    mg.data[6] = BMS1_Byte6.byte;           //�ܵ�ѹ���߹��ͣ���ص�ѹ�¶Ȳ����⣬���ϵȼ�
    mg.data[7] = BMS1_Byte7.byte;           //��ŵ�״̬������״̬
     
    mg.id= 0x1818D0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS2
//* period         : 100ms
//* Description    : ���������ߵ�ѹ������������¶ȣ�life
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS2(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    static unsigned char s_life=0;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    s_life++;
    if(s_life>254)
        s_life = 0;
    
    buff = (unsigned int)(g_CellLowestVol*100);   //������͵�ѹ
    mg.data[0] = buff; //���ֽ� 
    mg.data[1] = (g_CellLowestVolBoxNum<<4)|(buff>>8);  //���ֽ� 
    
    buff = (unsigned int)(g_CellHighestVol*100);   //������ߵ�ѹ
    mg.data[2] = buff;  //���ֽ� 
    mg.data[3] = (g_CellHighestVolBoxNum<<4)|(buff>>8);  //���ֽ� 
    
    
    mg.data[4] = g_BatLowestTemp;        //�������¶�
    mg.data[5] = g_BatHighestTemp;       //�������¶�
    mg.data[6] = 0;            
    mg.data[7] = s_life;                           //�����ź�
  
    mg.id= 0x1819D0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS3
//* period         : 100ms
//* Description    : �������ŵ������������������ѹ������������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS3(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    buff= (unsigned int)((g_MaxDischaCur+3200)*10);    //�������ŵ����
    mg.data[0] = buff;  //���ֽ� 
    mg.data[1] = buff>>8;    //���ֽ� 
    
    buff= (unsigned int)((g_MaxChaCur+3200)*10);       //������������
    mg.data[2] = buff;    //���ֽ� 
    mg.data[3] = buff>>8;     //���ֽ� 
    
    buff= (unsigned int)((MaxCtousChaCur+3200)*10);     //MaxCtousChaCur����������������
    mg.data[4] = buff;    //���ֽ� 
    mg.data[5] = buff>>8;     //���ֽ� 
    mg.data[6] = (unsigned int)(HIGHEST_ALLOWED_CHARGE_V/3);  //MaxChaTotalVol����������ܵ�ѹ
    mg.data[7] = 0;
  
    mg.id= 0x181AD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS4
//* period         : 100ms
//* Description    : ����������ܵ�ѹ�����������������ѹ���¶�
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS4(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
  
    mg.data[0] = 0;
    
    buff= (unsigned int)(MaxChaTotalVol1*10);       //MaxChaTotalVol1����������ܵ�ѹ
    mg.data[1] = buff; 
    mg.data[2] = buff>>8;
    
    buff= (unsigned int)((-g_MaxFebCur+3200)*10);      //��������������
    mg.data[3] = buff;   
    mg.data[4] = buff>>8;
    
   
    buff = (unsigned int)(HIGHEST_ALLOWED_CHARGE_CV*100);   // HighestChaCellVol��������絥���ѹ
    mg.data[5] = buff;
    mg.data[6] =((g_CellHighestVolBoxNum<<4)|(buff>>8));  
             
    mg.data[7] = (unsigned int)(HIGHEST_TEM+40);    //HighestChaCellTemp��������絥�����¶�
   
  
    mg.id= 0x181BD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS5
//* period         : 100ms
//* Description    : ��������ӹ���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS5(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    buff = (unsigned int)(LOWEST_ALLOWED_DISCHARGE_V*10);       //LowestDischaTotalVol�������ŵ��ܵ�ѹ
    mg.data[0] = buff;
    mg.data[1] = buff>>8;
      
    mg.data[2] = BMS5_Byte2.byte;           //��1-8�����ӹ���
    mg.data[3] = BMS5_Byte3.byte;           //��9-16�����ӹ���
  
    mg.data[4] = BMS5_Byte4.byte;          //���ϴ���������
    mg.data[5] = BMS5_Byte5.byte;           //��17-24�����ӹ���  Ӧ������0
    
    mg.data[6] = 0;
    mg.data[7] = 0;    
      
    mg.id= 0x181CD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}


//******************************************************************************
//* Function name  : BMS6
//* period         : 100ms
//* Description    : �������ȴ����״̬
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS6(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = BMS6_Byte0.byte;	  //13~16��   
    mg.data[1] = BMS6_Byte1.byte;   //9~12��
    mg.data[2] = BMS6_Byte2.byte;   //5~8��
    
    mg.data[3] = BMS6_Byte3.byte;     //1~4��
    mg.data[4] = BMS6_Byte4.byte;     //21~24��
    mg.data[5] = BMS6_Byte5.byte;     //17~20��
   
    mg.data[6] = g_BMSSelfCheckCounter;                     
    mg.data[7] = stateCode;  
     
    mg.id= 0x181DD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}


//******************************************************************************
//* Function name  : BMS7
//* period         : 100ms
//* Description    : ������ع��ϱ���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS7(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = BMS7_Byte0.byte;             //�ܵ�ѹǷѹ��ѹ���������LECUͨ�ű���
	  mg.data[1] = BMS7_Byte1.byte;	           //�������ŵ����
	  
	  mg.data[2] = BMS7_Byte2.byte;            //�����ѹǷѹ���������¶ȴ���������
	  mg.data[3] = BMS7_Byte3.byte; 	           //�¶Ȳ����⣬��ѹ�����ⱨ��
 	 
 	  mg.data[4] = BMS7_Byte4.byte;              //��ص��¸��±���
 	  mg.data[5] = BMS7_Byte5.byte;             //SOC��
	  
	  mg.data[6] = BMS7_Byte6.byte;            //��ѹ��������,SOC����                           //����
	  mg.data[7] = BMS7_Byte7.byte;             //���״̬�����ȹ���
	                                                 
    
    mg.id= 0x18F214F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}

//******************************************************************************
//* Function name  : BMS8
//* period         : 50ms
//* Description    : ������������Ӵ�������زࡢ�����ࣩ��ѹ���Ӵ���״̬
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS8(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    

    mg.data[0] = BMS8_Byte0.byte;            //������������Ӵ���״̬
    mg.data[1] = BMS8_Byte1.byte;            //������������Ӵ���״̬ 
    
    mg.data[2] =(unsigned int)(g_BatSysTotalVolV1/4); //��������Ӵ�������زࣩ��ѹ ChaPCtorBatVol
    mg.data[3] =(unsigned int)(ChaPCtorChgerVol/4); //��������Ӵ����������ࣩ��ѹ
    
    mg.data[4] = (unsigned int)(g_BatSysTotalVolV3/4); //��縺���Ӵ�������زࣩ��ѹ ChaNCtorBatVol
    mg.data[5] = (unsigned int)(ChaNCtorChgerVol/4); //��縺���Ӵ����������ࣩ��ѹ
    mg.data[6] = 0;           
    mg.data[7] = 0;
  
    mg.id= 0x1830D0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}

//******************************************************************************
//* Function name  : BMS9
//* period         : 100ms
//* Description    : ���Ӵ��� 1��2 ��˵�ѹ�Ͳ���Ӳ��������Ϣ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS9(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    buff=(unsigned int)(g_BatSysTotalVolV2*10);     //���Ӵ��� 1 ��˵�ѹ ChaCtorBndVol1
    mg.data[0] = buff;                                //���ֽ�
    mg.data[1] = buff>>8;                             //���ֽ�
    
    buff=(unsigned int)(g_BatSysTotalVolV3*10);     //���Ӵ��� 2 ��˵�ѹ   ChaCtorBndVol2
    mg.data[2] = buff;                                //���ֽ�
    mg.data[3] = buff>>8;                             //���ֽ�
    
    mg.data[4] = 0;
    mg.data[5] = 0;
    mg.data[6] = 0; 
    mg.data[7] = BMS9_Byte7.byte;         //���������������������س���ѹ�����£����Ӵ���ճ��
  
    mg.id= 0x181ED0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
} 

//******************************************************************************
//* Function name  : BMS10
//* period         : 500ms
//* Description    : ������ 1��2 ��ѹ�����������¶�
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS10(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] =(unsigned char)(g_DCTemp1 +40);           //������ 1 ��ѹ�����¶� ChaSketHighVolPTemp1
    mg.data[1] =(unsigned char)(g_DCTemp2 +40);           //������ 1 ��ѹ�����¶� ChaSketHighVolNTemp1
    
    mg.data[2] = ChaSketHighVolPTemp2+40;                      //������ 2 ��ѹ�����¶�
    mg.data[3] = ChaSketHighVolNTemp2+40;                      //������ 2 ��ѹ�����¶�
    
    mg.data[4] = 0;
    mg.data[5] = 0;
    mg.data[6] = 0; 
    mg.data[7] = 0;
  
    mg.id= 0x1840D0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS11
//* period         : 500ms
//* Description    : ��ع���ϵͳ����汾��Ϣ�ͳ���ʱ����Ϣ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS11(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = CurrentTime[6];                 //�� BCD �� YearBCD;  
    mg.data[1] = CurrentTime[5];                 //�� BCD �� MonthBCD
   
    mg.data[2] = CurrentTime[4];                 //�� BCD �� DayBCD
    mg.data[3] = CurrentTime[3];                 //ʱ BCD �� HourBCD
    
    mg.data[4] = CurrentTime[2];                 //�� BCD �� MinuteBCD
    mg.data[5] = 0;
    
    VersionNum=1.0;
    buff=(unsigned char)(VersionNum*10);
    mg.data[6] = buff;                                   //�汾��
    mg.data[7] = buff>>8;
  
    mg.id= 0x18F224F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/
//******************************************************************************
//* Function name:   BMS_To_VCU_CellVoltage1
//* Description:     �������е����ѹ   100ms
//* EntryParameter : number��Χ0---47
//* ReturnValue    : None
//******************************************************************************
void BMS_To_VCU_CellVoltage(unsigned char number)  
{
    struct can_msg mg;
    long  buff;
    unsigned char i,k=0;
    unsigned char tt=100;

    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
	
	  for(i=0;i<7;i=i+2)
  	{
  	    mg.data[i]= g_CellVol[number][k];       //4�䣬ÿ��48�������һ��45��
  	    mg.data[i+1]=g_CellVol[number][k]>>8;
  	    k++;
  	}
  	k=0;
 
	  buff = number*0x10000;
    mg.id=0x180028F4+buff;
 
      
	while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 

}  

//******************************************************************************
//* Function name  : BMS_To_VCU_CellTemp
//* period         : 100ms
//* Description    : �������е����¶�   
//* EntryParameter : number��Χ0---7
//* ReturnValue    : None
//******************************************************************************
void BMS_To_VCU_CellTemp(unsigned char number) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned char i;
    long buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    	for(i=0;i<8;i++)
	    mg.data[i]= g_CellTemp[number][i];//8N+i�ŵ�ص����¶�
	   
	  buff= number*0x10000; 
    mg.id= 0x180029F4+buff;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS_Information1
//* period         : 1000ms
//* Description    : �����͵�ѹ���¶ȣ����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void BMS_Information1(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = g_CellHighestVolBoxNum;        //������ߵ�ѹ���
    mg.data[1] = g_CellHighestVolBoxPosi;        //������ߵ�ѹ����λ��
    
    mg.data[2] = g_CellLowestVolBoxNum;         //������͵�ѹ���
    mg.data[3] = g_CellLowestVolBoxPosi;         //������͵�ѹ����λ��
    
    mg.data[4] = g_BatHighestTempBoxNum;      //�������¶����
    mg.data[5] = g_BatHighestTempBoxPosi;      //�������¶�����λ��
    mg.data[6] = g_BatLowestTempBoxNum;       //�������¶����
    mg.data[7] = g_BatLowestTempBoxPosi;       //�������¶�����λ��
  
    mg.id= 0x18FF2AF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS_Information2
//* period         : 1000ms
//* Description    : �����Ϣ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information2(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    buff=BatFac;                              //��س���
    mg.data[0] = buff;                                //���ֽ�
    mg.data[1] = buff>>8;                             //���ֽ�
    
    buff=BatArea;                                 //��ص���
    mg.data[2] = buff;                                //���ֽ�
    mg.data[3] = buff>>8;                             //���ֽ�
    
    buff=BatPackInfo;                         //�������Ϣ
    mg.data[4] = buff;                                 
    mg.data[5] = buff>>8;
    mg.data[6] = buff>>16; 
    mg.data[7] = buff>>24;
  
    mg.id= 0x18FF2BF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS_Information3
//* period         : 1000ms
//* Description    : ��ص�ѹ�ߵ���ֵ���¶ȸߵ���ֵ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information3(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;�BatVolLowThold
    mg.data[0] = buff;                                //���ֽ�
    mg.data[1] = buff>>8;                             //���ֽ�
    
    buff=(unsigned int)(3.65*100);     //��ص�ѹ�߷�ֵ��һ�����ϣ�BatVolHighThold
    mg.prty = 0;
    
    buff=(unsigned int)(2.8*100);     //��ص�ѹ�ͷ�ֵ��һ�����ϣ�BatVolLowThold
    mg.data[0] = buff;                                //���ֽ�
    mg.data[1] = buff>>8;                             //���ֽ�
    
    buff=(unsigned int)(3.65*100);     //��ص�ѹ�߷�ֵ��һ�����ϣ�BatVolHighThold
    mg.data[2] = buff;                                //���ֽ�
    mg.data[3] = buff>>8;                             //���ֽ�
    
    mg.data[4] = -23+40;      //������¶ȵͷ�ֵ��һ�����ϣ�   BatPackTempLowThold
    mg.data[5] = 45+40;      //������¶ȸ߷�ֵ��һ�����ϣ�   BatPackTempHighThold
    mg.data[6] = 0; 
    mg.data[7] = 0;
  
    mg.id= 0x18FF2CF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
  

//******************************************************************************
//* Function name  : BMS_Information4
//* period         : 1000ms
//* Description    : ������������������ڵ��������ѹ��������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information4(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = BatBoxNum;                                //���������
    mg.data[1] = BatFrameNum;                             //����ܴ��� 1
    
    mg.data[2] = BatTempNum;                           //������¶Ƚڵ���
    mg.data[3] = BatFrameNum2;                            //����ܴ��� 2
   
    buff=(unsigned int)(SYS_NOMINAL_V*10);                   //��ض��ѹBatRatedVol
    mg.data[4] = buff;                     //���ֽ�
    mg.data[5] = buff>>8;                  //���ֽ�
    
    mg.data[6] = (unsigned int)(SYS_KWH/1.5);         //��ض���� BatRatedEnergy
    mg.data[7] = (unsigned int)(SYS_KWH*(1-g_SysSOC)/1.5);        //���ʣ������
  
    mg.id= 0x18FF2DF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS_Information5
//* period         : 1000ms
//* Description    : �� i �䵥��������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information5(void)
{
     struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    unsigned char i;
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
 
    for (i=0;i<3;i++)
        mg.data[i] = 0x30;                      //�� i �䵥��������
    mg.data[3] = 0x2d;                      //�� i �䵥��������
    for (i=4;i<8;i++)
        mg.data[i] = 0x00;                      //�� i �䵥�������� 
           
    mg.id= 0x18FF2EF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : BMS_Information6
//* period         : 1000ms
//* Description    : �� i �䵥��������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information6(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    unsigned char i; 
       
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    

    for(i=0;i<8;i++)
      {
        mg.data[i] = 0;                      //��8+ i �䵥��������
      }
   
    mg.id= 0x18FF2FF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : BMS_Information7
//* period         : 1000ms
//* Description    : �� i �����¶Ƚڵ�����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information7(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    unsigned char i;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    for(i=0;i<4;i++)
      {
        mg.data[i] = 0x08;                      //�� i �䵥��������
      }
    for(i=4;i<8;i++)
      {
        mg.data[i] = 0;                      //�� i �䵥��������
      }
    mg.id= 0x18FF30F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}    

//******************************************************************************
//* Function name  : BMS_Information8
//* period         : 1000ms
//* Description    : ��8+ i �����¶Ƚڵ�����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information8(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    unsigned char i;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    

    for(i=0;i<8;i++)
      {
        mg.data[i] = 0;                      //0
      }      
     

    mg.id= 0x18FF31F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
} 

//******************************************************************************
//* Function name  : BMS_Information9
//* period         : 1000ms
//* Description    : ��صĻ���Ӳ����Ϣ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information9(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0;                    //��ر�ʶ
    mg.data[1] = 0;                           //��Ӧ�̴���
    
    mg.data[2] = 0;                    //���״̬
    
    buff=0;   
    mg.data[3] = buff;                      //����                            
    mg.data[4] = buff>>8;                   //���ֽ�
    
    mg.data[5] = 0;                  //���ֽ� 
   // mg.data[6] = (unsigned int)(BatRemainEnergy/1.5);       //ʵ������ KWH //���ʣ������ 
    //mg.data[7] = (unsigned int)(BatRatedEnergy/1.5);        //����� KWH //��ض����  
    mg.data[6] = (unsigned int)(SYS_KWH/1.5);         //ʵ������ KWH //���ʣ������ 
    mg.data[7] = (unsigned int)(SYS_KWH*(1-g_SysSOC)/1.5);        //����� KWH //��ض����  
   
    mg.id= 0x18F100F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : BMS_Information10
//* period         : 1000ms
//* Description    : ��ص��������̣�������ͣ��������ڣ���ˮ��
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information10(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    buff=0x03;                                      //�������̴���
    mg.data[0] = buff;                               //���ֽ�
    mg.data[1] = buff>>8;                            //���ֽ�
    
    mg.data[2] =0x01 ;                    //������� ������ʹ��� BatTypeCode

    mg.data[3] = Year;                      //�����������-��                         
    mg.data[4] = Month;                     //�����������-��
    mg.data[5] = Day;                     //�����������-��
    
    buff=SeralNum;                       //��ˮ��
    mg.data[6] = buff;                     //���ֽ�
    mg.data[7] = buff>>8;                  //���ֽ�
                       
    mg.id= 0x18FF32F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/
//******************************************************************************
//* Function name  : BMS_Information11
//* period         : 1000ms
//* Description    : �������е�������ߺ�����¶�
//* EntryParameter : 
//* ReturnValue    : None
//******************************************************************************
void Information_11(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    unsigned char i;
        
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    

    for(i=0;i<4;i++)
     {
      mg.data[2*i]=BatBoxHighestTemp[i];          //��i+1������¶�
      mg.data[2*i+1]=BatBoxLowestTemp[i];        //��i+1������¶�
     }
     
    
                  
    mg.id= 0x18FF33F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
//******************************************************************************
//* Function name  : BMS_Information12
//* period         : 1000ms
//* Description    : �������е�������ߺ�����¶�
//* EntryParameter : 
//* ReturnValue    : None
//******************************************************************************
/*void Information_12(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    unsigned char i;
        
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    

    for(i=0;i<1;i++)
     {
      mg.data[2*i]=BatBoxHighestTemp[i+4];          //��i+1������¶�
      mg.data[2*i+1]=BatBoxLowestTemp[i+4];        //��i+1������¶�
     }
    for(i=2;i<8;i++)
      mg.data[i]=40; 
    
                  
    mg.id= 0x18FF34F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/
//******************************************************************************
//* Function name  : InsulatedModel
//* period         : 500mS
//* Description    : ��Եģ��
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void InsulatedModel(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    buff=POnEarthInsuResi;                 //���Եؾ�Ե����
    mg.data[0] = buff;                    //���Եؾ�Ե����
    mg.data[1] = buff>>8;                 //���Եؾ�Ե����
    mg.data[2] = buff>>16;                //���Եؾ�Ե����
    
    buff=NOnEarthInsuResi;                 //���Եؾ�Ե����
    mg.data[3] = buff;                     //���Եؾ�Ե����                        
    mg.data[4] = buff>>8;                  //���Եؾ�Ե����
    mg.data[5] = buff>>16;                //���Եؾ�Ե����
    
    mg.data[6] = insulatedmodel_Byte6.byte;       //�豸���ϵȼ�����Ե�ȼ�
    mg.data[7] = InsLife;                    //��Եģ�� Life ֵ
                       
    mg.id= 0x18FF08F2;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/ 
//******************************************************************************
//* Function name  : EVCU
//* period         : 50mS
//* Description    : �������������Ʊ���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void EVCU(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = EVCU_Byte0.byte;               //��������������Ӵ�������ָ��
    mg.data[1] = EVCU_Byte1.byte;               //��������Ӵ��� 1-2 ״̬����
    
    mg.data[2] = ChaPCtorBatVol/4;                //��������Ӵ�������زࣩ��ѹ   
    mg.data[3] = ChaPCtorChgerVol/4;               //��������Ӵ����������ࣩ��ѹ  
                      
    mg.data[4] = 0;                 //����
    mg.data[5] = 0;                 //���� 
    mg.data[6] = 0;                 //����
    mg.data[7] = 0;                 //����
                       
    mg.id= 0x1830F3D0;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
 */

//******************************************************************************
//* Function name  : ChargeInformation1
//* period         : 500mS
//* Description    : �����Ϣ 1
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
/*void ChargeInformation1(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = ChaBeginHourBCD;           // ʱ BCD �루��翪ʼʱ�䣩
    mg.data[1] = ChaBeginMinuteBCD;         // �� BCD �루��翪ʼʱ��) 
    mg.data[2] = ChaBeginSecondBCD;        // �� BCD �루��翪ʼʱ��)  
     
    mg.data[3] = ChaEndHourBCD;            // ʱ BCD �루������ʱ��)                      
    mg.data[4] = ChaEndMinuteBCD;           // �� BCD �루������ʱ��)
    mg.data[5] = ChaEndSecondBCD;          // �� BCD �루������ʱ��) 
    
    buff=(unsigned int)(ActalChaVol*10);
    mg.data[6] = buff;                       // ����ѹ��ʵʱ����ʵ�ʳ���ѹ)
    mg.data[7] = buff>>8;                   //����ѹ��ʵʱ����ʵ�ʳ���ѹ)
                       
    mg.id= 0x18FF50F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : ChargeInformation2
//* period         : 500mS
//* Description    : �����Ϣ 2
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void ChargeInformation2(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = ChaInHourBCD;           //ʱ BCD �루���ǹ����ʱ��)
    mg.data[1] =  ChaInMinuteBCD;         //�� BCD �루���ǹ����ʱ��)   
    mg.data[2] = ChaInSecondBCD;        //�� BCD �루���ǹ����ʱ��)
    
    mg.data[3] = ChaOutHourBCD;          //ʱ BCD �루���ǹ�ε�ʱ��)                    
    mg.data[4] = ChaOutMinuteBCD;         //�� BCD �루���ǹ�ε�ʱ��)
    mg.data[5] = ChaOutSecondBCD;        //�� BCD �루���ǹ�ε�ʱ��)
    
    buff=(unsigned int)((ActalChaCur+3200)*10);      //��������ʵʱ����ʵ�ʳ�����)
    mg.data[6] = buff;                       //��������ʵʱ����ʵ�ʳ�����)
    mg.data[7] = buff>>8;                   //��������ʵʱ����ʵ�ʳ�����)
                       
    mg.id= 0x18FF51F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : ChargeInformation3
//* period         : 100mS
//* Description    : �����Ϣ 3
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void ChargeInformation3(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0; 
    
    mg.data[0] =InsulatedTest;          //��Ե��� 
    mg.data[1] =0; 
    
    mg.data[2] =0; 
    mg.data[3] =0; 
                      
    mg.data[4] = 0;                 //����
    mg.data[5] = 0;                 //���� 
    mg.data[6] = 0;                 //����
    mg.data[7] = 0;                 //����
                       
    mg.id= 0x18FFF2F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/      
//******************************************************************************
//* Function name:   bmsToPcTestCar
//* Description:     BMS�������ģʽ
//* EntryParameter : 100ms
//* ReturnValue    : None
//******************************************************************************
void bmsToPcTestCar(void)
{
    struct can_msg mg;
    unsigned int buff;
    unsigned char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    	
	  mg.data[0]= 0xA0; 
  	mg.data[1]= 0;

	  mg.data[2]= stateCode; 
	  mg.data[3]= g_BMSSelfCheckCounter;      //BMS�Լ������
	  
	  mg.data[4]= 0;
	  mg.data[5]= 0;
	  
	  mg.data[6]= 0;
	  mg.data[7]= 0;

	  mg.id= 0x000c0453; 
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--;
	  
}   
//***********************************************************************
//************************************************************************
//*************************the end*************************************
//************************************************************************