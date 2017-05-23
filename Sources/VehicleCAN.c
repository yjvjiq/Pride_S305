//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : VehicleCAN.c
//* Author             : Clark/陈文洋
//* Version            : V1.0.0
//* Start Date         : 2016.10.25
//* Description        : 该文件根据项目通信协议发送相关的报文到整车或交流充电机
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
BMS1_BYTE5  BMS1_Byte5;            //单体电压过高过低，SOC高低，充放电过流，温度过高，电池不匹配
BMS5_BYTE2  BMS5_Byte2;            //第1-8箱连接故障
BMS5_BYTE3  BMS5_Byte3;            //第9-16箱连接故障
BMS5_BYTE4  BMS5_Byte4;            //故障处理开关请求
BMS5_BYTE5  BMS5_Byte5;            //第17-24箱连接故障  应保留置0
BMS7_BYTE0  BMS7_Byte0;            //总电压欠压过压，与充电机，LECU通信报警
BMS7_BYTE1  BMS7_Byte1;            //充电过流放电过流
BMS7_BYTE2  BMS7_Byte2;            //单体过压欠压，电流，温度传感器故障
BMS7_BYTE3  BMS7_Byte3;            //温度不均衡，电压不均衡报警
BMS7_BYTE4  BMS7_Byte4;          //电池低温高温报警
BMS7_BYTE5  BMS7_Byte5;          //SOC低
BMS7_BYTE6  BMS7_Byte6;          //高压互锁报警
BMS7_BYTE7  BMS7_Byte7;          //电池状态，加热故障

BMS6_BYTE0 BMS6_Byte0;        //13~16箱   
BMS6_BYTE1 BMS6_Byte1;        //9~12箱
BMS6_BYTE2 BMS6_Byte2;        //5~8箱
BMS6_BYTE3 BMS6_Byte3;        //1~4箱
BMS6_BYTE4 BMS6_Byte4;        //21~24箱
BMS6_BYTE5 BMS6_Byte5;        //17~20箱

BMS9_BYTE7 BMS9_Byte7;      //蜂鸣器报警输出，动力电池充电过压，过温，充电接触器粘连
//INFORMATION9_BYTE0 information9_Byte0;      //电池标识
//INFORMATION9_BYTE2 information9_Byte2;      //电池状态
//INSULATEDMODEL_BYTE6 insulatedmodel_Byte6;      //设备故障等级，绝缘等级
EVCU_BYTE0 EVCU_Byte0;      //EVCU整车控制器控制报文Byte1
EVCU_BYTE1 EVCU_Byte1;      //EVCU整车控制器控制报文Byte2

BMS1_BYTE6 BMS1_Byte6;         //总电压过高过低，电池电压温度不均衡，故障等级
BMS1_BYTE7 BMS1_Byte7;         //充放电状态，激活状态
BMS8_BYTE0 BMS8_Byte0;         //电池正极负极接触器状态
BMS8_BYTE1 BMS8_Byte1;         //充电正极负极接触器状态





/*futon Logistics use*/
//float g_SOH=1;                                //SOH
/*                                             
float g_MaxDischaCur = 0;              //最大允许放电电流
float g_MaxChaCur=0;                  //最大允许充电电流
float g_MaxFebCur  = 0;              //最大允许回馈电流
float BiggestDisCurtContinuous = 0;          //最大持续放电电流
float MaxCtousChaCur = 0;          //最大持续充电电流
float BiggestFeedbackCurtContinuous = 0;     //最大持续回馈电流

float MaxChaTotalVol=0;                //最大允许充电总电压,BMS3
float MaxChaTotalVol1=0;            //最大允许充电总电压,BMS4
float LowestDischaTotalVol=0;                 //最低允许放电总电压,BMS5

float MaxDischaPower = 0;              //最大放电功率
float MaxFebPower  = 0;              //最大回馈功率
//float BiggestDisPowerContinuous = 0;          //最大持续放电功率
//float BiggestFeedbackContinuous = 0;          //最大持续回馈功率

float ChaPCtorBatVol=0;                //充电正极接触器（电池侧）电压
float ChaPCtorChgerVol=0;               //充电正极接触器（充电机侧）电压
float ChaNCtorBatVol=0;                //充电负极接触器（电池侧）电压
float ChaNCtorChgerVol=0;               //充电负极接触器（充电机侧）电压

float ChaCtorBndVol1=0;                 //充电接触器 1 后端电压
float ChaCtorBndVol2=0;                 //充电接触器 2 后端电压
*/
unsigned int m_askpower = 0;                         //请求功率
unsigned int chargeRemainderTime = 0;          //剩余充电时间
/*
int ChaSketHighVolPTemp1=0;                   //充电插座 1 高压正极温度
int ChaSketHighVolNTemp1=0;                   //充电插座 1 高压负极温度
//int ChaSketHighVolPTemp2=0;                   //充电插座 2 高压正极温度
//int ChaSketHighVolNTemp2=0;                   //充电插座 2 高压负极温度

//unsigned char Enable_Charger_Output = 0;      //使能充电机输出
//unsigned char Enable_Charger_Sleep  = 0;      //使能充电机休眠

//unsigned char HighestChaCellVol=0;      //最高单体充电电压
//unsigned char HighestChaCellTemp=0;      //最高单体充电温度
unsigned char g_CellLowestVolBoxNum;    //最低单体电压所在箱号
unsigned char g_CellHighestVolBoxNum;   //最高单体电压所在箱号
unsigned char g_BatLowestTempBoxNum;    //最低温度所在箱号
unsigned char g_BatHighestTempBoxNum;   //最高温度所在箱号

unsigned char g_CellLowestVolBoxPosi;   //最低单体电压所在箱内位置
unsigned char g_CellHighestVolBoxPosi;  //最高单体电压所在箱内位置
unsigned char g_BatLowestTempBoxPosi;   //最低温度所在箱内位置
unsigned char g_BatHighestTempBoxPosi;  //最高温度所在箱内位置

//unsigned int YearBCD;                       //年 BCD 码
//unsigned int MonthBCD;                      //月 BCD 码
//unsigned int DayBCD;                        //日 BCD 码
//unsigned int HourBCD;                       // 时 BCD 码
//unsigned int MinuteBCD;                      //分 BCD 码
//float VersionNum;                     //版本号

//unsigned char BatFac;           //电池厂家
//unsigned char BatArea;             //电池地区
//unsigned char BatPackInfo;   //电池组信息

//float BatVolLowThold;            //电池电压低阀值（一级故障）
//float BatVolHighThold;            //电池电压高阀值（一级故障）
//int BatPackTempLowThold;      //电池组温度低阀值（一级故障）
//int BatPackTempHighThold;      //电池组温度高阀值（一级故障）


float BatRatedVol;                      //电池额定电压
float BatRatedEnergy;                  //电池额定能量  KWH
float BatRemainEnergy;                 //电池剩余能量  KWH



unsigned char BatTypeCode;         //电池类型代码
unsigned int Year;                   //电池生产日期-年
unsigned int Month;                  //电池生产日期-月
unsigned int Day;                    //电池生产日期-日
unsigned int SeralNum;               //流水号

unsigned char POnEarthInsuResi;       //正对地绝缘电阻
unsigned char NOnEarthInsuResi;       //负对地绝缘电阻
unsigned int InsLife;                  //绝缘模块 Life 值


unsigned int ChaBeginHourBCD;           // 时 BCD 码（充电开始时间）
unsigned int ChaBeginMinuteBCD;         // 分 BCD 码（充电开始时间）
unsigned int ChaBeginSecondBCD;        // 秒 BCD 码（充电开始时间）
unsigned int ChaEndHourBCD;            // 时 BCD 码（充电结束时间）
unsigned int ChaEndMinuteBCD;           // 分 BCD 码（充电结束时间）
unsigned int ChaEndSecondBCD;          // 秒 BCD 码（充电结束时间）
float ActalChaVol;                       // 充电电压（实时发送实际充电电压）

unsigned int ChaInHourBCD;           //时 BCD 码（充电枪插上时间）
unsigned int ChaInMinuteBCD;         //分 BCD 码（充电枪插上时间）
unsigned int ChaInSecondBCD;        //秒 BCD 码（充电枪插上时间）
unsigned int ChaOutHourBCD;          //秒 BCD 码（充电枪插上时间）
unsigned int ChaOutMinuteBCD;         //分 BCD 码（充电枪拔掉时间）
unsigned int ChaOutSecondBCD;        //秒 BCD 码（充电枪拔掉时间）
float ActalChaCur;                       //充电电流（实时发送实际充电电流）
*/
unsigned int InsulatedTest=0;          //绝缘检测标志  01为开启，00为关闭


//*************************************************************************************
//*************************************************************************************
//*****************************以下是BMS给VCU发消息子程序******************************
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
    buff = (unsigned int)(HIGHEST_ALLOWED_CHARGE_CV*100);   // HighestChaCellVol最高允许充电单体电压
    Model_BMS4.Data[5] = buff;
    Model_BMS4.Data[6] =((g_CellHighestVolBoxNum<<4)|(buff>>8));               
    Model_BMS4.Data[7] = (unsigned int)(HIGHEST_TEM+40);    //HighestChaCellTemp最高允许充电单体电池温度
    
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
        Model_BMS8.Data[3] =(unsigned int)(ActalChaVol/4); //充电正极接触器（充电机侧）电压
    }
    Model_BMS8.Data[2] =(unsigned int)(g_SystemVoltageV0/4); //充电正极接触器（电池侧）电压 ChaPCtorBatVol
    if((stateCode>142)&&(stateCode<180)) 
    {
        Model_BMS8.Data[5] = (unsigned int)(g_BatSysTotalVolV3/4); //充电负极接触器（充电机侧）电压
    }
    Model_BMS8.Data[4] = (unsigned int)(g_SystemVoltageV0/4); //充电负极接触器（电池侧）电压 ChaNCtorBatVol
    Transfer(Model_BMS8);   
} 
void BMS9(void) 
{
    unsigned int buff;    
    S223_BMS9();
    buff=(unsigned int)(g_BatSysTotalVolV3*10);     //充电接触器 1 后端电压 ChaCtorBndVol1
    Model_BMS9.Data[0] = buff;                                //低字节
    Model_BMS9.Data[1] = buff>>8;                             //高字节
  
    Transfer(Model_BMS9);   
} 
    
void BMS10(void) 
{
    S223_BMS10();
    Transfer(Model_BMS10);   
}  
void BMS11(void) 
{
    I2CReadDate();  //读取系统时间	  
    YearBCD=CurrentTime[6];     //年
    MonthBCD=CurrentTime[5];    //月
    DayBCD=CurrentTime[4];     //日
    HourBCD=CurrentTime[2];     //时
    MinuteBCD=CurrentTime[1];    //分
    VersionNum=1.0;
    S223_BMS11();
    Transfer(Model_BMS11);   
}
void Charge_1(void) 
{   
    unsigned int buff;    
    S223_Charge_1(); 
    buff=(unsigned int)(ActalChaVol*10);
    Model_Charge_1.Data[6] = buff;                       // 充电电压（实时发送实际充电电压)
    Model_Charge_1.Data[7] = buff>>8;                   //充电电压（实时发送实际充电电压)
    
    Transfer(Model_Charge_1);   
}
void Charge_2(void) 
{
    unsigned int buff;
    S223_Charge_2();  
    buff=(unsigned int)((ActalChaCur+3200)*10);      //充电电流（实时发送实际充电电流)
    Model_Charge_2.Data[6] = buff;                       //充电电流（实时发送实际充电电流)
    Model_Charge_2.Data[7] = buff>>8;                   //充电电流（实时发送实际充电电流)
   
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
    BatFrameNum=BATTERYCELLNUMBER;                             //电池总串数 1   
    BatTempNum=32;                           //电池总温度节点数  
    BatRatedVol=(SYS_NOMINAL_V);                   //电池额定电压BatRatedVol  
    BatRatedEnergy = (SYS_KWH);         //电池额定能量 BatRatedEnergy
    BatRemainEnergy= (SYS_KWH*(g_SysSOC));        //电池剩余能量 BatRemainEnergy
    S223_Information_4();
    Transfer(Model_Information_4);   
}
void Information_5(void) 
{
    BoxCellNum1=48;     //第1箱单体数量              
    BoxCellNum2=48;     //第2箱单体数量
    BoxCellNum3=48;     //第3箱单体数量
    BoxCellNum4=45;     //第4箱单体数量
    //BoxCellNum5=33;     //第5箱单体数量
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
    BoxTempNum1=0x08;    //第1箱温度节点数量
    BoxTempNum2=0x08;    //第2箱温度节点数量
    BoxTempNum3=0x08;    //第3箱温度节点数量
    BoxTempNum4=0x08;    //第4箱温度节点数量
    //BoxTempNum5=0x06;    //第5箱温度节点数量
    //BoxTempNum4=0x04;    //第6箱温度节点数量
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
    BatRatedEnergy2 = (SYS_KWH);         //电池额定能量 BatRatedEnergy
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
//* Function name  : BMS1(电池管理系统 1)
//* period         : 100ms
//* Description    : 总电压总电流SOC等
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
	  
	  buff = (unsigned int)(g_SystemVoltageV0*10);	      //动力电池总电压
	  mg.data[0] = buff;   //低字节 
	  mg.data[1] = buff>>8;//高字节    
	  
	  buff = (unsigned int)((g_BatSysTotalCur+3200)*10);	//动力电池总电流
	  mg.data[2] = buff;   //低字节 
	  mg.data[3] = buff>>8;//高字节     
    
    if(g_SysSOC>=0.995) 
        buff = 100*2.5;
    else 
        buff = (unsigned int)(g_SysSOC*100*2.5);    //系统SOC
    mg.data[4] = buff;      //SOC值      
    
    mg.data[5] = BMS1_Byte5.byte;          //单体电压过高过低，SOC高低，充放电过流，温度过高，电池不匹配
    mg.data[6] = BMS1_Byte6.byte;           //总电压过高过低，电池电压温度不均衡，故障等级
    mg.data[7] = BMS1_Byte7.byte;           //充放电状态，激活状态
     
    mg.id= 0x1818D0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS2
//* period         : 100ms
//* Description    : 单体最低最高电压，电池最低最高温度，life
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
    
    buff = (unsigned int)(g_CellLowestVol*100);   //单体最低电压
    mg.data[0] = buff; //低字节 
    mg.data[1] = (g_CellLowestVolBoxNum<<4)|(buff>>8);  //高字节 
    
    buff = (unsigned int)(g_CellHighestVol*100);   //单体最高电压
    mg.data[2] = buff;  //低字节 
    mg.data[3] = (g_CellHighestVolBoxNum<<4)|(buff>>8);  //高字节 
    
    
    mg.data[4] = g_BatLowestTemp;        //电池最低温度
    mg.data[5] = g_BatHighestTemp;       //电池最高温度
    mg.data[6] = 0;            
    mg.data[7] = s_life;                           //生命信号
  
    mg.id= 0x1819D0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS3
//* period         : 100ms
//* Description    : 最大允许放电电流，充电电流，充电电压，持续充电电流
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
    
    buff= (unsigned int)((g_MaxDischaCur+3200)*10);    //最大允许放电电流
    mg.data[0] = buff;  //低字节 
    mg.data[1] = buff>>8;    //高字节 
    
    buff= (unsigned int)((g_MaxChaCur+3200)*10);       //最大允许充电电流
    mg.data[2] = buff;    //低字节 
    mg.data[3] = buff>>8;     //高字节 
    
    buff= (unsigned int)((MaxCtousChaCur+3200)*10);     //MaxCtousChaCur最高允许持续充电电流
    mg.data[4] = buff;    //低字节 
    mg.data[5] = buff>>8;     //高字节 
    mg.data[6] = (unsigned int)(HIGHEST_ALLOWED_CHARGE_V/3);  //MaxChaTotalVol最高允许充电总电压
    mg.data[7] = 0;
  
    mg.id= 0x181AD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS4
//* period         : 100ms
//* Description    : 最高允许充电总电压，回馈电流，单体电压，温度
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
    
    buff= (unsigned int)(MaxChaTotalVol1*10);       //MaxChaTotalVol1最高允许充电总电压
    mg.data[1] = buff; 
    mg.data[2] = buff>>8;
    
    buff= (unsigned int)((-g_MaxFebCur+3200)*10);      //最大允许回馈电流
    mg.data[3] = buff;   
    mg.data[4] = buff>>8;
    
   
    buff = (unsigned int)(HIGHEST_ALLOWED_CHARGE_CV*100);   // HighestChaCellVol最高允许充电单体电压
    mg.data[5] = buff;
    mg.data[6] =((g_CellHighestVolBoxNum<<4)|(buff>>8));  
             
    mg.data[7] = (unsigned int)(HIGHEST_TEM+40);    //HighestChaCellTemp最高允许充电单体电池温度
   
  
    mg.id= 0x181BD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : BMS5
//* period         : 100ms
//* Description    : 电池箱连接故障
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
    
    buff = (unsigned int)(LOWEST_ALLOWED_DISCHARGE_V*10);       //LowestDischaTotalVol最低允许放电总电压
    mg.data[0] = buff;
    mg.data[1] = buff>>8;
      
    mg.data[2] = BMS5_Byte2.byte;           //第1-8箱连接故障
    mg.data[3] = BMS5_Byte3.byte;           //第9-16箱连接故障
  
    mg.data[4] = BMS5_Byte4.byte;          //故障处理开关请求
    mg.data[5] = BMS5_Byte5.byte;           //第17-24箱连接故障  应保留置0
    
    mg.data[6] = 0;
    mg.data[7] = 0;    
      
    mg.id= 0x181CD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}


//******************************************************************************
//* Function name  : BMS6
//* period         : 100ms
//* Description    : 电池箱冷却加热状态
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
    
    mg.data[0] = BMS6_Byte0.byte;	  //13~16箱   
    mg.data[1] = BMS6_Byte1.byte;   //9~12箱
    mg.data[2] = BMS6_Byte2.byte;   //5~8箱
    
    mg.data[3] = BMS6_Byte3.byte;     //1~4箱
    mg.data[4] = BMS6_Byte4.byte;     //21~24箱
    mg.data[5] = BMS6_Byte5.byte;     //17~20箱
   
    mg.data[6] = g_BMSSelfCheckCounter;                     
    mg.data[7] = stateCode;  
     
    mg.id= 0x181DD0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}


//******************************************************************************
//* Function name  : BMS7
//* period         : 100ms
//* Description    : 动力电池故障报警
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
    
    mg.data[0] = BMS7_Byte0.byte;             //总电压欠压过压，与充电机，LECU通信报警
	  mg.data[1] = BMS7_Byte1.byte;	           //充电过流放电过流
	  
	  mg.data[2] = BMS7_Byte2.byte;            //单体过压欠压，电流，温度传感器故障
	  mg.data[3] = BMS7_Byte3.byte; 	           //温度不均衡，电压不均衡报警
 	 
 	  mg.data[4] = BMS7_Byte4.byte;              //电池低温高温报警
 	  mg.data[5] = BMS7_Byte5.byte;             //SOC低
	  
	  mg.data[6] = BMS7_Byte6.byte;            //高压互锁报警,SOC跳变                           //保留
	  mg.data[7] = BMS7_Byte7.byte;             //电池状态，加热故障
	                                                 
    
    mg.id= 0x18F214F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}

//******************************************************************************
//* Function name  : BMS8
//* period         : 50ms
//* Description    : 充电正极负极接触器（电池侧、充电机侧）电压，接触器状态
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
    

    mg.data[0] = BMS8_Byte0.byte;            //电池正极负极接触器状态
    mg.data[1] = BMS8_Byte1.byte;            //充电正极负极接触器状态 
    
    mg.data[2] =(unsigned int)(g_BatSysTotalVolV1/4); //充电正极接触器（电池侧）电压 ChaPCtorBatVol
    mg.data[3] =(unsigned int)(ChaPCtorChgerVol/4); //充电正极接触器（充电机侧）电压
    
    mg.data[4] = (unsigned int)(g_BatSysTotalVolV3/4); //充电负极接触器（电池侧）电压 ChaNCtorBatVol
    mg.data[5] = (unsigned int)(ChaNCtorChgerVol/4); //充电负极接触器（充电机侧）电压
    mg.data[6] = 0;           
    mg.data[7] = 0;
  
    mg.id= 0x1830D0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}

//******************************************************************************
//* Function name  : BMS9
//* period         : 100ms
//* Description    : 充电接触器 1，2 后端电压和部分硬件故障信息
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
    
    buff=(unsigned int)(g_BatSysTotalVolV2*10);     //充电接触器 1 后端电压 ChaCtorBndVol1
    mg.data[0] = buff;                                //低字节
    mg.data[1] = buff>>8;                             //高字节
    
    buff=(unsigned int)(g_BatSysTotalVolV3*10);     //充电接触器 2 后端电压   ChaCtorBndVol2
    mg.data[2] = buff;                                //低字节
    mg.data[3] = buff>>8;                             //高字节
    
    mg.data[4] = 0;
    mg.data[5] = 0;
    mg.data[6] = 0; 
    mg.data[7] = BMS9_Byte7.byte;         //蜂鸣器报警输出，动力电池充电过压，过温，充电接触器粘连
  
    mg.id= 0x181ED0F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
} 

//******************************************************************************
//* Function name  : BMS10
//* period         : 500ms
//* Description    : 充电插座 1，2 高压正极，负极温度
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
    
    mg.data[0] =(unsigned char)(g_DCTemp1 +40);           //充电插座 1 高压正极温度 ChaSketHighVolPTemp1
    mg.data[1] =(unsigned char)(g_DCTemp2 +40);           //充电插座 1 高压负极温度 ChaSketHighVolNTemp1
    
    mg.data[2] = ChaSketHighVolPTemp2+40;                      //充电插座 2 高压正极温度
    mg.data[3] = ChaSketHighVolNTemp2+40;                      //充电插座 2 高压负极温度
    
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
//* Description    : 电池管理系统程序版本信息和程序时间信息
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
    
    mg.data[0] = CurrentTime[6];                 //年 BCD 码 YearBCD;  
    mg.data[1] = CurrentTime[5];                 //月 BCD 码 MonthBCD
   
    mg.data[2] = CurrentTime[4];                 //日 BCD 码 DayBCD
    mg.data[3] = CurrentTime[3];                 //时 BCD 码 HourBCD
    
    mg.data[4] = CurrentTime[2];                 //分 BCD 码 MinuteBCD
    mg.data[5] = 0;
    
    VersionNum=1.0;
    buff=(unsigned char)(VersionNum*10);
    mg.data[6] = buff;                                   //版本号
    mg.data[7] = buff>>8;
  
    mg.id= 0x18F224F3;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/
//******************************************************************************
//* Function name:   BMS_To_VCU_CellVoltage1
//* Description:     发送所有单体电压   100ms
//* EntryParameter : number范围0---47
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
  	    mg.data[i]= g_CellVol[number][k];       //4箱，每箱48个，最后一箱45个
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
//* Description    : 发送所有单体温度   
//* EntryParameter : number范围0---7
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
	    mg.data[i]= g_CellTemp[number][i];//8N+i号电池单体温度
	   
	  buff= number*0x10000; 
    mg.id= 0x180029F4+buff;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS_Information1
//* period         : 1000ms
//* Description    : 最高最低电压和温度，箱号
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
    
    mg.data[0] = g_CellHighestVolBoxNum;        //单体最高电压箱号
    mg.data[1] = g_CellHighestVolBoxPosi;        //单体最高电压箱内位置
    
    mg.data[2] = g_CellLowestVolBoxNum;         //单体最低电压箱号
    mg.data[3] = g_CellLowestVolBoxPosi;         //单体最低电压箱内位置
    
    mg.data[4] = g_BatHighestTempBoxNum;      //电池最高温度箱号
    mg.data[5] = g_BatHighestTempBoxPosi;      //电池最高温度箱内位置
    mg.data[6] = g_BatLowestTempBoxNum;       //电池最低温度箱号
    mg.data[7] = g_BatLowestTempBoxPosi;       //电池最低温度箱内位置
  
    mg.id= 0x18FF2AF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS_Information2
//* period         : 1000ms
//* Description    : 电池信息
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
    
    buff=BatFac;                              //电池厂家
    mg.data[0] = buff;                                //低字节
    mg.data[1] = buff>>8;                             //高字节
    
    buff=BatArea;                                 //电池地区
    mg.data[2] = buff;                                //低字节
    mg.data[3] = buff>>8;                             //高字节
    
    buff=BatPackInfo;                         //电池组信息
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
//* Description    : 电池电压高低阈值，温度高低阈值
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMS_Information3(void) 
{
    struct can_msg mg;
    unsigned char tt=100;
    unsigned int buff;
    
    mg.RTR= FALSE;  
    mg.len = 8;〣atVolLowThold
    mg.data[0] = buff;                                //低字节
    mg.data[1] = buff>>8;                             //高字节
    
    buff=(unsigned int)(3.65*100);     //电池电压高阀值（一级故障）BatVolHighThold
    mg.prty = 0;
    
    buff=(unsigned int)(2.8*100);     //电池电压低阀值（一级故障）BatVolLowThold
    mg.data[0] = buff;                                //低字节
    mg.data[1] = buff>>8;                             //高字节
    
    buff=(unsigned int)(3.65*100);     //电池电压高阀值（一级故障）BatVolHighThold
    mg.data[2] = buff;                                //低字节
    mg.data[3] = buff>>8;                             //高字节
    
    mg.data[4] = -23+40;      //电池组温度低阀值（一级故障）   BatPackTempLowThold
    mg.data[5] = 45+40;      //电池组温度高阀值（一级故障）   BatPackTempHighThold
    mg.data[6] = 0; 
    mg.data[7] = 0;
  
    mg.id= 0x18FF2CF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
  

//******************************************************************************
//* Function name  : BMS_Information4
//* period         : 1000ms
//* Description    : 电池总箱数，串数，节点数，额定电压，能量等
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
    
    mg.data[0] = BatBoxNum;                                //电池总箱数
    mg.data[1] = BatFrameNum;                             //电池总串数 1
    
    mg.data[2] = BatTempNum;                           //电池总温度节点数
    mg.data[3] = BatFrameNum2;                            //电池总串数 2
   
    buff=(unsigned int)(SYS_NOMINAL_V*10);                   //电池额定电压BatRatedVol
    mg.data[4] = buff;                     //低字节
    mg.data[5] = buff>>8;                  //高字节
    
    mg.data[6] = (unsigned int)(SYS_KWH/1.5);         //电池额定能量 BatRatedEnergy
    mg.data[7] = (unsigned int)(SYS_KWH*(1-g_SysSOC)/1.5);        //电池剩余能量
  
    mg.id= 0x18FF2DF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     


//******************************************************************************
//* Function name  : BMS_Information5
//* period         : 1000ms
//* Description    : 第 i 箱单体电池数量
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
        mg.data[i] = 0x30;                      //第 i 箱单体电池数量
    mg.data[3] = 0x2d;                      //第 i 箱单体电池数量
    for (i=4;i<8;i++)
        mg.data[i] = 0x00;                      //第 i 箱单体电池数量 
           
    mg.id= 0x18FF2EF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : BMS_Information6
//* period         : 1000ms
//* Description    : 第 i 箱单体电池数量
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
        mg.data[i] = 0;                      //第8+ i 箱单体电池数量
      }
   
    mg.id= 0x18FF2FF4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : BMS_Information7
//* period         : 1000ms
//* Description    : 第 i 箱电池温度节点数量
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
        mg.data[i] = 0x08;                      //第 i 箱单体电池数量
      }
    for(i=4;i<8;i++)
      {
        mg.data[i] = 0;                      //第 i 箱单体电池数量
      }
    mg.id= 0x18FF30F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}    

//******************************************************************************
//* Function name  : BMS_Information8
//* period         : 1000ms
//* Description    : 第8+ i 箱电池温度节点数量
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
//* Description    : 电池的基本硬件信息
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
    
    mg.data[0] = 0;                    //电池标识
    mg.data[1] = 0;                           //供应商代码
    
    mg.data[2] = 0;                    //电池状态
    
    buff=0;   
    mg.data[3] = buff;                      //车号                            
    mg.data[4] = buff>>8;                   //低字节
    
    mg.data[5] = 0;                  //高字节 
   // mg.data[6] = (unsigned int)(BatRemainEnergy/1.5);       //实际容量 KWH //电池剩余能量 
    //mg.data[7] = (unsigned int)(BatRatedEnergy/1.5);        //额定容量 KWH //电池额定能量  
    mg.data[6] = (unsigned int)(SYS_KWH/1.5);         //实际容量 KWH //电池剩余能量 
    mg.data[7] = (unsigned int)(SYS_KWH*(1-g_SysSOC)/1.5);        //额定容量 KWH //电池额定能量  
   
    mg.id= 0x18F100F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : BMS_Information10
//* period         : 1000ms
//* Description    : 电池的生产厂商，电池类型，生产日期，流水号
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
    
    buff=0x03;                                      //生产厂商代码
    mg.data[0] = buff;                               //低字节
    mg.data[1] = buff>>8;                            //高字节
    
    mg.data[2] =0x01 ;                    //磷酸铁锂 电池类型代码 BatTypeCode

    mg.data[3] = Year;                      //电池生产日期-年                         
    mg.data[4] = Month;                     //电池生产日期-月
    mg.data[5] = Day;                     //电池生产日期-日
    
    buff=SeralNum;                       //流水号
    mg.data[6] = buff;                     //低字节
    mg.data[7] = buff>>8;                  //高字节
                       
    mg.id= 0x18FF32F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/
//******************************************************************************
//* Function name  : BMS_Information11
//* period         : 1000ms
//* Description    : 发送所有电池箱的最高和最低温度
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
      mg.data[2*i]=BatBoxHighestTemp[i];          //第i+1箱最高温度
      mg.data[2*i+1]=BatBoxLowestTemp[i];        //第i+1箱最低温度
     }
     
    
                  
    mg.id= 0x18FF33F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
//******************************************************************************
//* Function name  : BMS_Information12
//* period         : 1000ms
//* Description    : 发送所有电池箱的最高和最低温度
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
      mg.data[2*i]=BatBoxHighestTemp[i+4];          //第i+1箱最高温度
      mg.data[2*i+1]=BatBoxLowestTemp[i+4];        //第i+1箱最低温度
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
//* Description    : 绝缘模块
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
    
    buff=POnEarthInsuResi;                 //正对地绝缘电阻
    mg.data[0] = buff;                    //正对地绝缘电阻
    mg.data[1] = buff>>8;                 //正对地绝缘电阻
    mg.data[2] = buff>>16;                //正对地绝缘电阻
    
    buff=NOnEarthInsuResi;                 //负对地绝缘电阻
    mg.data[3] = buff;                     //负对地绝缘电阻                        
    mg.data[4] = buff>>8;                  //负对地绝缘电阻
    mg.data[5] = buff>>16;                //负对地绝缘电阻
    
    mg.data[6] = insulatedmodel_Byte6.byte;       //设备故障等级，绝缘等级
    mg.data[7] = InsLife;                    //绝缘模块 Life 值
                       
    mg.id= 0x18FF08F2;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/ 
//******************************************************************************
//* Function name  : EVCU
//* period         : 50mS
//* Description    : 整车控制器控制报文
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
    
    mg.data[0] = EVCU_Byte0.byte;               //动力电池正负极接触器控制指令
    mg.data[1] = EVCU_Byte1.byte;               //充电正极接触器 1-2 状态反馈
    
    mg.data[2] = ChaPCtorBatVol/4;                //充电正极接触器（电池侧）电压   
    mg.data[3] = ChaPCtorChgerVol/4;               //充电正极接触器（充电机侧）电压  
                      
    mg.data[4] = 0;                 //保留
    mg.data[5] = 0;                 //保留 
    mg.data[6] = 0;                 //保留
    mg.data[7] = 0;                 //保留
                       
    mg.id= 0x1830F3D0;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
 */

//******************************************************************************
//* Function name  : ChargeInformation1
//* period         : 500mS
//* Description    : 充电信息 1
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
    
    mg.data[0] = ChaBeginHourBCD;           // 时 BCD 码（充电开始时间）
    mg.data[1] = ChaBeginMinuteBCD;         // 分 BCD 码（充电开始时间) 
    mg.data[2] = ChaBeginSecondBCD;        // 秒 BCD 码（充电开始时间)  
     
    mg.data[3] = ChaEndHourBCD;            // 时 BCD 码（充电结束时间)                      
    mg.data[4] = ChaEndMinuteBCD;           // 分 BCD 码（充电结束时间)
    mg.data[5] = ChaEndSecondBCD;          // 秒 BCD 码（充电结束时间) 
    
    buff=(unsigned int)(ActalChaVol*10);
    mg.data[6] = buff;                       // 充电电压（实时发送实际充电电压)
    mg.data[7] = buff>>8;                   //充电电压（实时发送实际充电电压)
                       
    mg.id= 0x18FF50F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     

//******************************************************************************
//* Function name  : ChargeInformation2
//* period         : 500mS
//* Description    : 充电信息 2
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
    
    mg.data[0] = ChaInHourBCD;           //时 BCD 码（充电枪插上时间)
    mg.data[1] =  ChaInMinuteBCD;         //分 BCD 码（充电枪插上时间)   
    mg.data[2] = ChaInSecondBCD;        //秒 BCD 码（充电枪插上时间)
    
    mg.data[3] = ChaOutHourBCD;          //时 BCD 码（充电枪拔掉时间)                    
    mg.data[4] = ChaOutMinuteBCD;         //分 BCD 码（充电枪拔掉时间)
    mg.data[5] = ChaOutSecondBCD;        //秒 BCD 码（充电枪拔掉时间)
    
    buff=(unsigned int)((ActalChaCur+3200)*10);      //充电电流（实时发送实际充电电流)
    mg.data[6] = buff;                       //充电电流（实时发送实际充电电流)
    mg.data[7] = buff>>8;                   //充电电流（实时发送实际充电电流)
                       
    mg.id= 0x18FF51F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}
//******************************************************************************
//* Function name  : ChargeInformation3
//* period         : 100mS
//* Description    : 充电信息 3
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
    
    mg.data[0] =InsulatedTest;          //绝缘检测 
    mg.data[1] =0; 
    
    mg.data[2] =0; 
    mg.data[3] =0; 
                      
    mg.data[4] = 0;                 //保留
    mg.data[5] = 0;                 //保留 
    mg.data[6] = 0;                 //保留
    mg.data[7] = 0;                 //保留
                       
    mg.id= 0x18FFF2F4;
    while((!MSCAN0SendMsg(mg))&&(tt>0))
        tt--; 
}     
*/      
//******************************************************************************
//* Function name:   bmsToPcTestCar
//* Description:     BMS进入测试模式
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
	  mg.data[3]= g_BMSSelfCheckCounter;      //BMS自检计数器
	  
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