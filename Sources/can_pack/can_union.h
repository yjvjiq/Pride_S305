#include "mc9s12xep100.h"
//--- start signals here ---
typedef union{
unsigned char byte;
struct {
byte F0_CellOverVol:1;     //结构体引用//BMS1_Byte5.Bit.F0_CellOverVol
byte F1_CellUnderVol:1;     //结构体引用//BMS1_Byte5.Bit.F1_CellUnderVol
byte F2_SOCHigh:1;     //结构体引用//BMS1_Byte5.Bit.F2_SOCHigh
byte F3_SOCLow:1;     //结构体引用//BMS1_Byte5.Bit.F3_SOCLow
byte F4_ChaOverCur:1;     //结构体引用//BMS1_Byte5.Bit.F4_ChaOverCur
byte F5_DischaOverCur:1;     //结构体引用//BMS1_Byte5.Bit.F5_DischaOverCur
byte F6_BatTempHigh:1;     //结构体引用//BMS1_Byte5.Bit.F6_BatTempHigh
byte F7_BatNotMatch:1;     //结构体引用//BMS1_Byte5.Bit.F7_BatNotMatch
}Bit;
}BMS1_BYTE5;
extern BMS1_BYTE5 BMS1_Byte5;

typedef union{
unsigned char byte;
struct {
byte F0_TotalVolOverVol:1;     //结构体引用//BMS1_Byte6.Bit.F0_TotalVolOverVol
byte F1_TotalVolUnderVol:1;     //结构体引用//BMS1_Byte6.Bit.F1_TotalVolUnderVol
byte F2_CellVolUnbal:1;     //结构体引用//BMS1_Byte6.Bit.F2_CellVolUnbal
byte F3_CellTempUnbal:1;     //结构体引用//BMS1_Byte6.Bit.F3_CellTempUnbal
byte F4_6_BatFaultLevel:3;     //结构体引用//BMS1_Byte6.Bit.F4_6_BatFaultLevel
byte F7_Reser:1;     //结构体引用//BMS1_Byte6.Bit.F7_Reser
}Bit;
}BMS1_BYTE6;
extern BMS1_BYTE6 BMS1_Byte6;

typedef union{
unsigned char byte;
struct {
byte F0_5_Rever:6;     //结构体引用//BMS1_Byte7.Bit.F0_5_Rever
byte F6_BatBalAtvState:1;     //结构体引用//BMS1_Byte7.Bit.F6_BatBalAtvState
byte F7_ChaAndDischaState:1;     //结构体引用//BMS1_Byte7.Bit.F7_ChaAndDischaState
}Bit;
}BMS1_BYTE7;
extern BMS1_BYTE7 BMS1_Byte7;

typedef union{
unsigned char byte;
struct {
byte F4_7_CellLowestVolNum:4;     //结构体引用//BMS2_Byte1.Bit.F4_7_CellLowestVolNum
}Bit;
}BMS2_BYTE1;
extern BMS2_BYTE1 BMS2_Byte1;

typedef union{
unsigned char byte;
struct {
byte F4_7_CellHighestVolNum:4;     //结构体引用//BMS2_Byte3.Bit.F4_7_CellHighestVolNum
}Bit;
}BMS2_BYTE3;
extern BMS2_BYTE3 BMS2_Byte3;

typedef union{
unsigned char byte;
struct {
byte F4_7_CellHighestChaVolNum:4;     //结构体引用//BMS4_Byte6.Bit.F4_7_CellHighestChaVolNum
}Bit;
}BMS4_BYTE6;
extern BMS4_BYTE6 BMS4_Byte6;

typedef union{
unsigned char byte;
struct {
byte F0_ConFault1:1;     //结构体引用//BMS5_Byte2.Bit.F0_ConFault1
byte F1_ConFault2:1;     //结构体引用//BMS5_Byte2.Bit.F1_ConFault2
byte F2_ConFault3:1;     //结构体引用//BMS5_Byte2.Bit.F2_ConFault3
byte F3_ConFault4:1;     //结构体引用//BMS5_Byte2.Bit.F3_ConFault4
byte F4_ConFault5:1;     //结构体引用//BMS5_Byte2.Bit.F4_ConFault5
byte F5_ConFault6:1;     //结构体引用//BMS5_Byte2.Bit.F5_ConFault6
byte F6_ConFault7:1;     //结构体引用//BMS5_Byte2.Bit.F6_ConFault7
byte F7_ConFault8:1;     //结构体引用//BMS5_Byte2.Bit.F7_ConFault8
}Bit;
}BMS5_BYTE2;
extern BMS5_BYTE2 BMS5_Byte2;

typedef union{
unsigned char byte;
struct {
byte F0_ConFault9:1;     //结构体引用//BMS5_Byte3.Bit.F0_ConFault9
byte F1_ConFault10:1;     //结构体引用//BMS5_Byte3.Bit.F1_ConFault10
byte F2_ConFault11:1;     //结构体引用//BMS5_Byte3.Bit.F2_ConFault11
byte F3_ConFault12:1;     //结构体引用//BMS5_Byte3.Bit.F3_ConFault12
byte F4_ConFault13:1;     //结构体引用//BMS5_Byte3.Bit.F4_ConFault13
byte F5_ConFault14:1;     //结构体引用//BMS5_Byte3.Bit.F5_ConFault14
byte F6_ConFault15:1;     //结构体引用//BMS5_Byte3.Bit.F6_ConFault15
byte F7_ConFault16:1;     //结构体引用//BMS5_Byte3.Bit.F7_ConFault16
}Bit;
}BMS5_BYTE3;
extern BMS5_BYTE3 BMS5_Byte3;

typedef union{
unsigned char byte;
struct {
byte F0_3_Rever:4;     //结构体引用//BMS5_Byte4.Bit.F0_3_Rever
byte F4_CutMainCtor:1;     //结构体引用//BMS5_Byte4.Bit.F4_CutMainCtor
byte F5_ForceStopMode:1;     //结构体引用//BMS5_Byte4.Bit.F5_ForceStopMode
byte F6_ForceDownPowerMode:1;     //结构体引用//BMS5_Byte4.Bit.F6_ForceDownPowerMode
byte F7_ChaPlugCon:1;     //结构体引用//BMS5_Byte4.Bit.F7_ChaPlugCon
}Bit;
}BMS5_BYTE4;
extern BMS5_BYTE4 BMS5_Byte4;

typedef union{
unsigned char byte;
struct {
byte F0_ConFault17:1;     //结构体引用//BMS5_Byte5.Bit.F0_ConFault17
byte F1_ConFault18:1;     //结构体引用//BMS5_Byte5.Bit.F1_ConFault18
byte F2_ConFault19:1;     //结构体引用//BMS5_Byte5.Bit.F2_ConFault19
byte F3_ConFault20:1;     //结构体引用//BMS5_Byte5.Bit.F3_ConFault20
byte F4_ConFault21:1;     //结构体引用//BMS5_Byte5.Bit.F4_ConFault21
byte F5_ConFault22:1;     //结构体引用//BMS5_Byte5.Bit.F5_ConFault22
byte F6_ConFault23:1;     //结构体引用//BMS5_Byte5.Bit.F6_ConFault23
byte F7_ConFault24:1;     //结构体引用//BMS5_Byte5.Bit.F7_ConFault24
}Bit;
}BMS5_BYTE5;
extern BMS5_BYTE5 BMS5_Byte5;

typedef union{
unsigned char byte;
struct {
byte F0_BoxHeatingState13:1;     //结构体引用//BMS6_Byte0.Bit.F0_BoxHeatingState13
byte F1_BoxCoolingState13:1;     //结构体引用//BMS6_Byte0.Bit.F1_BoxCoolingState13
byte F2_BoxHeatingState14:1;     //结构体引用//BMS6_Byte0.Bit.F2_BoxHeatingState14
byte F3_BoxCoolingState14:1;     //结构体引用//BMS6_Byte0.Bit.F3_BoxCoolingState14
byte F4_BoxHeatingState15:1;     //结构体引用//BMS6_Byte0.Bit.F4_BoxHeatingState15
byte F5_BoxCoolingState15:1;     //结构体引用//BMS6_Byte0.Bit.F5_BoxCoolingState15
byte F6_BoxHeatingState16:1;     //结构体引用//BMS6_Byte0.Bit.F6_BoxHeatingState16
byte F7_BoxCoolingState16:1;     //结构体引用//BMS6_Byte0.Bit.F7_BoxCoolingState16
}Bit;
}BMS6_BYTE0;
extern BMS6_BYTE0 BMS6_Byte0;

typedef union{
unsigned char byte;
struct {
byte F0_BoxHeatingState9:1;     //结构体引用//BMS6_Byte1.Bit.F0_BoxHeatingState9
byte F1_BoxCoolingState9:1;     //结构体引用//BMS6_Byte1.Bit.F1_BoxCoolingState9
byte F2_BoxHeatingState10:1;     //结构体引用//BMS6_Byte1.Bit.F2_BoxHeatingState10
byte F3_BoxCoolingState10:1;     //结构体引用//BMS6_Byte1.Bit.F3_BoxCoolingState10
byte F4_BoxHeatingState11:1;     //结构体引用//BMS6_Byte1.Bit.F4_BoxHeatingState11
byte F5_BoxCoolingState11:1;     //结构体引用//BMS6_Byte1.Bit.F5_BoxCoolingState11
byte F6_BoxHeatingState12:1;     //结构体引用//BMS6_Byte1.Bit.F6_BoxHeatingState12
byte F7_BoxCoolingState12:1;     //结构体引用//BMS6_Byte1.Bit.F7_BoxCoolingState12
}Bit;
}BMS6_BYTE1;
extern BMS6_BYTE1 BMS6_Byte1;

typedef union{
unsigned char byte;
struct {
byte F0_BoxHeatingState5:1;     //结构体引用//BMS6_Byte2.Bit.F0_BoxHeatingState5
byte F1_BoxCoolingState5:1;     //结构体引用//BMS6_Byte2.Bit.F1_BoxCoolingState5
byte F2_BoxHeatingState6:1;     //结构体引用//BMS6_Byte2.Bit.F2_BoxHeatingState6
byte F3_BoxCoolingState6:1;     //结构体引用//BMS6_Byte2.Bit.F3_BoxCoolingState6
byte F4_BoxHeatingState7:1;     //结构体引用//BMS6_Byte2.Bit.F4_BoxHeatingState7
byte F5_BoxCoolingState7:1;     //结构体引用//BMS6_Byte2.Bit.F5_BoxCoolingState7
byte F6_BoxHeatingState8:1;     //结构体引用//BMS6_Byte2.Bit.F6_BoxHeatingState8
byte F7_BoxCoolingState8:1;     //结构体引用//BMS6_Byte2.Bit.F7_BoxCoolingState8
}Bit;
}BMS6_BYTE2;
extern BMS6_BYTE2 BMS6_Byte2;

typedef union{
unsigned char byte;
struct {
byte F0_BoxHeatingState1:1;     //结构体引用//BMS6_Byte3.Bit.F0_BoxHeatingState1
byte F1_BoxCoolingState1:1;     //结构体引用//BMS6_Byte3.Bit.F1_BoxCoolingState1
byte F2_BoxHeatingState2:1;     //结构体引用//BMS6_Byte3.Bit.F2_BoxHeatingState2
byte F3_BoxCoolingState2:1;     //结构体引用//BMS6_Byte3.Bit.F3_BoxCoolingState2
byte F4_BoxHeatingState3:1;     //结构体引用//BMS6_Byte3.Bit.F4_BoxHeatingState3
byte F5_BoxCoolingState3:1;     //结构体引用//BMS6_Byte3.Bit.F5_BoxCoolingState3
byte F6_BoxHeatingState4:1;     //结构体引用//BMS6_Byte3.Bit.F6_BoxHeatingState4
byte F7_BoxCoolingState4:1;     //结构体引用//BMS6_Byte3.Bit.F7_BoxCoolingState4
}Bit;
}BMS6_BYTE3;
extern BMS6_BYTE3 BMS6_Byte3;

typedef union{
unsigned char byte;
struct {
byte F0_BoxHeatingState21:1;     //结构体引用//BMS6_Byte4.Bit.F0_BoxHeatingState21
byte F1_BoxCoolingState21:1;     //结构体引用//BMS6_Byte4.Bit.F1_BoxCoolingState21
byte F2_BoxHeatingState22:1;     //结构体引用//BMS6_Byte4.Bit.F2_BoxHeatingState22
byte F3_BoxCoolingState22:1;     //结构体引用//BMS6_Byte4.Bit.F3_BoxCoolingState22
byte F4_BoxHeatingState23:1;     //结构体引用//BMS6_Byte4.Bit.F4_BoxHeatingState23
byte F5_BoxCoolingState23:1;     //结构体引用//BMS6_Byte4.Bit.F5_BoxCoolingState23
byte F6_BoxHeatingState24:1;     //结构体引用//BMS6_Byte4.Bit.F6_BoxHeatingState24
byte F7_BoxCoolingState24:1;     //结构体引用//BMS6_Byte4.Bit.F7_BoxCoolingState24
}Bit;
}BMS6_BYTE4;
extern BMS6_BYTE4 BMS6_Byte4;

typedef union{
unsigned char byte;
struct {
byte F0_BoxHeatingState17:1;     //结构体引用//BMS6_Byte5.Bit.F0_BoxHeatingState17
byte F1_BoxCoolingState17:1;     //结构体引用//BMS6_Byte5.Bit.F1_BoxCoolingState17
byte F2_BoxHeatingState18:1;     //结构体引用//BMS6_Byte5.Bit.F2_BoxHeatingState18
byte F3_BoxCoolingState18:1;     //结构体引用//BMS6_Byte5.Bit.F3_BoxCoolingState18
byte F4_BoxHeatingState19:1;     //结构体引用//BMS6_Byte5.Bit.F4_BoxHeatingState19
byte F5_BoxCoolingState19:1;     //结构体引用//BMS6_Byte5.Bit.F5_BoxCoolingState19
byte F6_BoxHeatingState20:1;     //结构体引用//BMS6_Byte5.Bit.F6_BoxHeatingState20
byte F7_BoxCoolingState20:1;     //结构体引用//BMS6_Byte5.Bit.F7_BoxCoolingState20
}Bit;
}BMS6_BYTE5;
extern BMS6_BYTE5 BMS6_Byte5;

typedef union{
unsigned char byte;
struct {
byte F0_WithLECUComAlarm:1;     //结构体引用//BMS7_Byte0.Bit.F0_WithLECUComAlarm
byte F1_WithChgerComAlarm:1;     //结构体引用//BMS7_Byte0.Bit.F1_WithChgerComAlarm
byte F2_4_TotalVolUnderVolAlarm:3;     //结构体引用//BMS7_Byte0.Bit.F2_4_TotalVolUnderVolAlarm
byte F5_7_TotalVolOverVolAlarm:3;     //结构体引用//BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm
}Bit;
}BMS7_BYTE0;
extern BMS7_BYTE0 BMS7_Byte0;

typedef union{
unsigned char byte;
struct {
byte F0_1_Rever:2;     //结构体引用//BMS7_Byte1.Bit.F0_1_Rever
byte F2_4_ChaOverCurAlarm:3;     //结构体引用//BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm
byte F5_7_DisChaOverCurAlarm:3;     //结构体引用//BMS7_Byte1.Bit.F5_7_DisChaOverCurAlarm
}Bit;
}BMS7_BYTE1;
extern BMS7_BYTE1 BMS7_Byte1;

typedef union{
unsigned char byte;
struct {
byte F0_TempSenFault:1;     //结构体引用//BMS7_Byte2.Bit.F0_TempSenFault
byte F1_CurSenFault:1;     //结构体引用//BMS7_Byte2.Bit.F1_CurSenFault
byte F2_4_CellUnderVolAlarm:3;     //结构体引用//BMS7_Byte2.Bit.F2_4_CellUnderVolAlarm
byte F5_7_CellOverVolAlarm:3;     //结构体引用//BMS7_Byte2.Bit.F5_7_CellOverVolAlarm
}Bit;
}BMS7_BYTE2;
extern BMS7_BYTE2 BMS7_Byte2;

typedef union{
unsigned char byte;
struct {
byte F0_1_Rever2:2;     //结构体引用//BMS7_Byte3.Bit.F0_1_Rever2
byte F2_4_CellTempUnbalAlarm:3;     //结构体引用//BMS7_Byte3.Bit.F2_4_CellTempUnbalAlarm
byte F5_7_CellVolUnbalAlarm:3;     //结构体引用//BMS7_Byte3.Bit.F5_7_CellVolUnbalAlarm
}Bit;
}BMS7_BYTE3;
extern BMS7_BYTE3 BMS7_Byte3;

typedef union{
unsigned char byte;
struct {
byte F0_1_Rever3:2;     //结构体引用//BMS7_Byte4.Bit.F0_1_Rever3
byte F2_4_BatTempLowAlarm:3;     //结构体引用//BMS7_Byte4.Bit.F2_4_BatTempLowAlarm
byte F5_7_BatTempHighAlarm:3;     //结构体引用//BMS7_Byte4.Bit.F5_7_BatTempHighAlarm
}Bit;
}BMS7_BYTE4;
extern BMS7_BYTE4 BMS7_Byte4;

typedef union{
unsigned char byte;
struct {
byte F0_2_Rever2:3;     //结构体引用//BMS7_Byte5.Bit.F0_2_Rever2
byte F3_4_SOCSal:2;     //结构体引用//BMS7_Byte5.Bit.F3_4_SOCSal
byte F5_7_SOCLowAlarm:3;     //结构体引用//BMS7_Byte5.Bit.F5_7_SOCLowAlarm
}Bit;
}BMS7_BYTE5;
extern BMS7_BYTE5 BMS7_Byte5;

typedef union{
unsigned char byte;
struct {
byte F0_5_Rever2:6;     //结构体引用//BMS7_Byte6.Bit.F0_5_Rever2
byte F6_7_HighVolLock:2;     //结构体引用//BMS7_Byte6.Bit.F6_7_HighVolLock
}Bit;
}BMS7_BYTE6;
extern BMS7_BYTE6 BMS7_Byte6;

typedef union{
unsigned char byte;
struct {
byte F0_BatState:1;     //结构体引用//BMS7_Byte7.Bit.F0_BatState
byte F1_2_BatHeatingFault:2;     //结构体引用//BMS7_Byte7.Bit.F1_2_BatHeatingFault
byte F3_7_Rever:5;     //结构体引用//BMS7_Byte7.Bit.F3_7_Rever
}Bit;
}BMS7_BYTE7;
extern BMS7_BYTE7 BMS7_Byte7;

typedef union{
unsigned char byte;
struct {
byte F0_1_Rever4:2;     //结构体引用//BMS8_Byte0.Bit.F0_1_Rever4
byte F2_3_BMSInterCtorState:2;     //结构体引用//BMS8_Byte0.Bit.F2_3_BMSInterCtorState
byte F4_5_BatPCtorStateFeb:2;     //结构体引用//BMS8_Byte0.Bit.F4_5_BatPCtorStateFeb
byte F6_7_BatNCtorStateFeb:2;     //结构体引用//BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb
}Bit;
}BMS8_BYTE0;
extern BMS8_BYTE0 BMS8_Byte0;

typedef union{
unsigned char byte;
struct {
byte F0_2_ChaNCtorStateFeb2:3;     //结构体引用//BMS8_Byte1.Bit.F0_2_ChaNCtorStateFeb2
byte F3_5_ChaNCtorStateFeb1:3;     //结构体引用//BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1
byte F6_7_ChaPCtorClose:2;     //结构体引用//BMS8_Byte1.Bit.F6_7_ChaPCtorClose
}Bit;
}BMS8_BYTE1;
extern BMS8_BYTE1 BMS8_Byte1;

typedef union{
unsigned char byte;
struct {
byte F0_ChaCtorAdin1:1;     //结构体引用//BMS9_Byte7.Bit.F0_ChaCtorAdin1
byte F1_ChaCtorAdin2:1;     //结构体引用//BMS9_Byte7.Bit.F1_ChaCtorAdin2
byte F2_BatChaOverTemp:1;     //结构体引用//BMS9_Byte7.Bit.F2_BatChaOverTemp
byte F3_BatChaOverVol:1;     //结构体引用//BMS9_Byte7.Bit.F3_BatChaOverVol
byte F4_BzerAlarm:1;     //结构体引用//BMS9_Byte7.Bit.F4_BzerAlarm
byte F5_7_Rever:3;     //结构体引用//BMS9_Byte7.Bit.F5_7_Rever
}Bit;
}BMS9_BYTE7;
extern BMS9_BYTE7 BMS9_Byte7;

typedef union{
unsigned char byte;
struct {
byte InsulatedModel_Byte7_bit1_2:2;     //结构体引用//InsulatedModel_Byte6.Bit.InsulatedModel_Byte7_bit1_2
byte InsulatedModel_Byte7_bit3_4:2;     //结构体引用//InsulatedModel_Byte6.Bit.InsulatedModel_Byte7_bit3_4
byte F4_7_Rever:4;     //结构体引用//InsulatedModel_Byte6.Bit.F4_7_Rever
}Bit;
}InsulatedModel_BYTE6;
extern InsulatedModel_BYTE6 InsulatedModel_Byte6;
//--- start signals here ---
typedef union{
unsigned char byte;
struct {
byte F0_3_Rever2:4;     //结构体引用//EVCU_Byte0.Bit.F0_3_Rever2
byte F4_5_BatPCtorCtrl:2;     //结构体引用//EVCU_Byte0.Bit.F4_5_BatPCtorCtrl
byte F6_7_BatNCtorCtrl:2;     //结构体引用//EVCU_Byte0.Bit.F6_7_BatNCtorCtrl
}Bit;
}EVCU_BYTE0;
extern EVCU_BYTE0 EVCU_Byte0;

typedef union{
unsigned char byte;
struct {
byte F0_1_Rever5:2;     //结构体引用//EVCU_Byte1.Bit.F0_1_Rever5
byte F2_4_ChaPCtorStateFeb2:3;     //结构体引用//EVCU_Byte1.Bit.F2_4_ChaPCtorStateFeb2
byte F5_7_ChaPCtorStateFeb1:3;     //结构体引用//EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1
}Bit;
}EVCU_BYTE1;
extern EVCU_BYTE1 EVCU_Byte1;

