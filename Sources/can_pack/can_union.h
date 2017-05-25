#include "mc9s12xep100.h"
//--- start signals here ---
typedef union{
unsigned char byte;
struct {
byte InnerCANErr:1;     //结构体引用//BMSFault_Byte0.Bit.InnerCANErr
byte ExternCANErr:1;     //结构体引用//BMSFault_Byte0.Bit.ExternCANErr
byte DischaOverCur:1;     //结构体引用//BMSFault_Byte0.Bit.DischaOverCur
byte ChaOverCur:1;     //结构体引用//BMSFault_Byte0.Bit.ChaOverCur
byte PreChaFalse:1;     //结构体引用//BMSFault_Byte0.Bit.PreChaFalse
byte BatOpenCir:1;     //结构体引用//BMSFault_Byte0.Bit.BatOpenCir
byte F6_7_Reser_1:2;     //结构体引用//BMSFault_Byte0.Bit.F6_7_Reser_1
}Bit;
}BMSFault_BYTE0;
extern BMSFault_BYTE0 BMSFault_Byte0;

typedef union{
unsigned char byte;
struct {
byte CellOverVolAlarm:4;     //结构体引用//BMSFault_Byte1.Bit.CellOverVolAlarm
byte CellUnderVolAlarm:4;     //结构体引用//BMSFault_Byte1.Bit.CellUnderVolAlarm
}Bit;
}BMSFault_BYTE1;
extern BMSFault_BYTE1 BMSFault_Byte1;

typedef union{
unsigned char byte;
struct {
byte OverTempAlarm:4;     //结构体引用//BMSFault_Byte2.Bit.OverTempAlarm
byte LowTempAlarm:4;     //结构体引用//BMSFault_Byte2.Bit.LowTempAlarm
}Bit;
}BMSFault_BYTE2;
extern BMSFault_BYTE2 BMSFault_Byte2;

typedef union{
unsigned char byte;
struct {
byte CellVolDiffAlarm:1;     //结构体引用//BMSFault_Byte3.Bit.CellVolDiffAlarm
byte CellTempDiffAlarm:1;     //结构体引用//BMSFault_Byte3.Bit.CellTempDiffAlarm
byte FuseFault:1;     //结构体引用//BMSFault_Byte3.Bit.FuseFault
byte PosCtorAdin:1;     //结构体引用//BMSFault_Byte3.Bit.PosCtorAdin
byte NegCtorAdin:1;     //结构体引用//BMSFault_Byte3.Bit.NegCtorAdin
byte F5_6_Reser:2;     //结构体引用//BMSFault_Byte3.Bit.F5_6_Reser
byte InsuAlarm:1;     //结构体引用//BMSFault_Byte3.Bit.InsuAlarm
}Bit;
}BMSFault_BYTE3;
extern BMSFault_BYTE3 BMSFault_Byte3;

typedef union{
unsigned char byte;
struct {
byte SOCLow:4;     //结构体引用//BMSFault_Byte4.Bit.SOCLow
byte TotalVolOverVol:4;     //结构体引用//BMSFault_Byte4.Bit.TotalVolOverVol
}Bit;
}BMSFault_BYTE4;
extern BMSFault_BYTE4 BMSFault_Byte4;

typedef union{
unsigned char byte;
struct {
byte TotalVolUnderVol:4;     //结构体引用//BMSFault_Byte5.Bit.TotalVolUnderVol
byte SOCHigh:4;     //结构体引用//BMSFault_Byte5.Bit.SOCHigh
}Bit;
}BMSFault_BYTE5;
extern BMSFault_BYTE5 BMSFault_Byte5;

typedef union{
unsigned char byte;
struct {
byte SOCSal:4;     //结构体引用//BMSFault_Byte6.Bit.SOCSal
byte F4_7_Reser_2:4;     //结构体引用//BMSFault_Byte6.Bit.F4_7_Reser_2
}Bit;
}BMSFault_BYTE6;
extern BMSFault_BYTE6 BMSFault_Byte6;

typedef union{
unsigned char byte;
struct {
byte BatState:4;     //结构体引用//BMU_Byte0.Bit.BatState
byte EmncyCha:2;     //结构体引用//BMU_Byte0.Bit.EmncyCha
byte F6_7_Reser:2;     //结构体引用//BMU_Byte0.Bit.F6_7_Reser
}Bit;
}BMU_BYTE0;
extern BMU_BYTE0 BMU_Byte0;

typedef union{
unsigned char byte;
struct {
byte FaultState:4;     //结构体引用//BMU_Byte1.Bit.FaultState
byte F4_7_Reser:4;     //结构体引用//BMU_Byte1.Bit.F4_7_Reser
}Bit;
}BMU_BYTE1;
extern BMU_BYTE1 BMU_Byte1;

typedef union{
unsigned char byte;
struct {
byte MsgCounter:4;     //结构体引用//BMU_Byte7.Bit.MsgCounter
byte F4_7_Reser_1:4;     //结构体引用//BMU_Byte7.Bit.F4_7_Reser_1
}Bit;
}BMU_BYTE7;
extern BMU_BYTE7 BMU_Byte7;

typedef union{
unsigned char byte;
struct {
byte HeatSysState:2;     //结构体引用//CellTemp_Byte7.Bit.HeatSysState
byte F2_7_Reser:6;     //结构体引用//CellTemp_Byte7.Bit.F2_7_Reser
}Bit;
}CellTemp_BYTE7;
extern CellTemp_BYTE7 CellTemp_Byte7;

typedef union{
unsigned char byte;
struct {
byte HVSupplyCtorReq:2;     //结构体引用//VCUReqBMS_Byte0.Bit.HVSupplyCtorReq
byte E2_7_Reser:6;     //结构体引用//VCUReqBMS_Byte0.Bit.E2_7_Reser
}Bit;
}VCUReqBMS_BYTE0;
extern VCUReqBMS_BYTE0 VCUReqBMS_Byte0;

typedef union{
unsigned char byte;
struct {
byte ChaState:2;     //结构体引用//VCUReqBMS_Byte1.Bit.ChaState
byte E2_7_Reser_1:6;     //结构体引用//VCUReqBMS_Byte1.Bit.E2_7_Reser_1
}Bit;
}VCUReqBMS_BYTE1;
extern VCUReqBMS_BYTE1 VCUReqBMS_Byte1;

typedef union{
unsigned char byte;
struct {
byte MessageCounter:4;     //结构体引用//VCUReqBMS_Byte7.Bit.MessageCounter
byte E4_7_Reser:4;     //结构体引用//VCUReqBMS_Byte7.Bit.E4_7_Reser
}Bit;
}VCUReqBMS_BYTE7;
extern VCUReqBMS_BYTE7 VCUReqBMS_Byte7;

