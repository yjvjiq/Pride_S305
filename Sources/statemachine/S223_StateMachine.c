/*
 * File: S223_StateMachine.c
 *
 * Code generated for Simulink model 'S223_StateMachine'.
 *
 * Model version                  : 1.1083
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Apr 01 17:08:33 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->HC(S)12
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BMS20.h"

/* Named constants for Chart: '<Root>/TaskControl' */
#define IN_DischrgNegRelay_Malfunction ((uint8_T)2U)
#define IN_HighVoltagePowerOffDetection ((uint8_T)4U)
#define S223_IN_HighVoltDetectPart2Test ((uint8_T)3U)
#define S223_S_IN_CloseChrgPosRelay_Req ((uint8_T)1U)
#define S223_St_IN_OpenChrgPosRelay_Req ((uint8_T)5U)
#define S223_Sta_IN_HighVoltDetectPart2 ((uint8_T)3U)
#define S223_Sta_IN_HighVoltageSelfTest ((uint8_T)3U)
#define S223_Stat_IN_LowVoltageSelfTest ((uint8_T)6U)
#define S223_StateMa_IN_CloseDischrgNeg ((uint8_T)1U)
#define S223_StateMa_IN_HeatAndCharge_a ((uint8_T)3U)
#define S223_StateMa_IN_MSD_Malfunction ((uint8_T)2U)
#define S223_StateMa_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define S223_StateMac_IN_CloseMainPower ((uint8_T)1U)
#define S223_StateMac_IN_Dischrg_Normal ((uint8_T)2U)
#define S223_StateMac_IN_OpenDischrgNeg ((uint8_T)6U)
#define S223_StateMach_IN_ChrgNomalEnd1 ((uint8_T)2U)
#define S223_StateMach_IN_HeatAndCharge ((uint8_T)2U)
#define S223_StateMach_IN_HeatandCharge ((uint8_T)2U)
#define S223_StateMachi_IN_CarFaultDone ((uint8_T)1U)
#define S223_StateMachi_IN_CloseChrgNeg ((uint8_T)1U)
#define S223_StateMachi_IN_NomalEndWait ((uint8_T)3U)
#define S223_StateMachi_IN_OpenNegRelay ((uint8_T)3U)
#define S223_StateMachi_IN_SmallCurrent ((uint8_T)6U)
#define S223_StateMachin_IN_InformStore ((uint8_T)4U)
#define S223_StateMachin_IN_OverCurrent ((uint8_T)4U)
#define S223_StateMachine_IN_ACC_Off   ((uint8_T)1U)
#define S223_StateMachine_IN_Charge    ((uint8_T)1U)
#define S223_StateMachine_IN_Check     ((uint8_T)1U)
#define S223_StateMachine_IN_CloseMain ((uint8_T)1U)
#define S223_StateMachine_IN_CloseNeg  ((uint8_T)1U)
#define S223_StateMachine_IN_Confirm   ((uint8_T)1U)
#define S223_StateMachine_IN_Confirm1  ((uint8_T)1U)
#define S223_StateMachine_IN_Confirm_k ((uint8_T)2U)
#define S223_StateMachine_IN_Confirm_kq ((uint8_T)3U)
#define S223_StateMachine_IN_Debugging ((uint8_T)1U)
#define S223_StateMachine_IN_Delay     ((uint8_T)1U)
#define S223_StateMachine_IN_Detect    ((uint8_T)1U)
#define S223_StateMachine_IN_DisChrg   ((uint8_T)1U)
#define S223_StateMachine_IN_Discharge ((uint8_T)1U)
#define S223_StateMachine_IN_FastCharg ((uint8_T)2U)
#define S223_StateMachine_IN_FastCharge ((uint8_T)2U)
#define S223_StateMachine_IN_FastChrg  ((uint8_T)2U)
#define S223_StateMachine_IN_Fault     ((uint8_T)1U)
#define S223_StateMachine_IN_Fault1    ((uint8_T)1U)
#define S223_StateMachine_IN_Fault1_h  ((uint8_T)2U)
#define S223_StateMachine_IN_FaultCheck ((uint8_T)1U)
#define S223_StateMachine_IN_Fault_f   ((uint8_T)2U)
#define S223_StateMachine_IN_Heat      ((uint8_T)1U)
#define S223_StateMachine_IN_HeatManage ((uint8_T)1U)
#define S223_StateMachine_IN_Heat_o    ((uint8_T)2U)
#define S223_StateMachine_IN_LossVCU   ((uint8_T)5U)
#define S223_StateMachine_IN_LowVoltOff ((uint8_T)5U)
#define S223_StateMachine_IN_Nomal     ((uint8_T)2U)
#define S223_StateMachine_IN_Normal    ((uint8_T)2U)
#define S223_StateMachine_IN_Normal_a  ((uint8_T)3U)
#define S223_StateMachine_IN_NotFault  ((uint8_T)2U)
#define S223_StateMachine_IN_OpenHeater ((uint8_T)2U)
#define S223_StateMachine_IN_ReceiveVCU ((uint8_T)5U)
#define S223_StateMachine_IN_Wait      ((uint8_T)2U)
#define S223_StateMachine_IN_Wait_o    ((uint8_T)3U)
#define S223_StateMachine_IN_WakeUp    ((uint8_T)7U)
#define S223_StateMachine_IN_cc2off    ((uint8_T)7U)
#define S223_StateMachine_IN_delay     ((uint8_T)7U)
#define S223_StateMachine_IN_init      ((uint8_T)2U)
#define S223_StateMachine_IN_init_c    ((uint8_T)4U)
#define S223_StateMachine_IN_lossvcu   ((uint8_T)8U)
#define S223_StateMachine_IN_lossvcu1  ((uint8_T)9U)
#define S223_StateMachine_IN_normalend ((uint8_T)10U)
#define S223_StateMachine_IN_wait      ((uint8_T)8U)
#define S223_StateMachine_IN_wait_f    ((uint8_T)3U)
#define S223_StateMachine_IN_wait_fp   ((uint8_T)1U)
#define S223_StateMachine_IN_wait_fpw  ((uint8_T)2U)
#define S223__IN_HighVoltageDetectPart1 ((uint8_T)1U)
#define S22_IN_ChrgNegRelay_Malfunction ((uint8_T)1U)
#define S2_IN_HighVoltDetectPart2Test_o ((uint8_T)2U)
#define S_IN_HighVoltageDetectPart1Test ((uint8_T)2U)
#define NumBitsPerChar                 8U

/* Exported data definition */

/* Definition for custom storage class: Default */
real32_T CAP_CONST_CAL = 176.0F;
real32_T DisChargeCurrentTable[132] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.05F, 0.15F, 0.15F, 0.15F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F,
  0.3F, 0.0F, 0.3F, 0.5F, 0.5F, 0.5F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.0F,
  0.5F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.5F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.5F, 1.2F, 1.2F, 1.2F,
  1.2F, 1.2F, 1.2F, 1.2F, 1.2F, 1.2F, 0.0F, 1.0F, 1.2F, 1.2F, 1.2F, 1.5F, 1.5F,
  1.5F, 1.5F, 1.5F, 1.5F, 0.0F, 1.0F, 1.2F, 1.2F, 1.2F, 1.5F, 1.5F, 1.5F, 1.5F,
  1.5F, 1.5F, 0.0F, 1.0F, 1.2F, 1.2F, 1.2F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* maximum discharge current, row: SOC, collumn: T  */

real32_T Factor_ChargeEndSOCAjust[64] = { 0.5824F, 0.6191F, 0.6432F, 0.7792F,
  0.8784F, 0.9467F, 0.9898F, 0.9917F, 0.633F, 0.6692F, 0.7243F, 0.8698F, 0.9315F,
  0.9729F, 1.0F, 1.0F, 0.6816F, 0.8232F, 0.8797F, 0.9538F, 0.9822F, 1.0F, 1.0F,
  1.0F, 0.8277F, 0.925F, 0.9467F, 0.9843F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8987F,
  0.9606F, 0.9773F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.9548F, 0.9903F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 0.9932F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;

real32_T Factor_PowerOnSOCAjust[8] = { 0.6346F, 0.7105F, 0.7811F, 0.8448F,
  0.9066F, 0.9523F, 0.9887F, 1.0F } ;

real32_T FastChargeCurrentTable[168] = { 0.0F, 0.0F, 0.1F, 0.1F, 0.3F, 0.3F,
  0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.3F,
  0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.1F,
  0.3F, 0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F,
  0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F, 0.3F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 1.0F, 1.0F, 1.0F,
  0.3F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 0.75F, 0.8F,
  0.8F, 0.3F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F, 0.75F,
  0.8F, 0.8F, 0.3F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.3F, 0.3F, 0.5F, 0.5F,
  0.75F, 0.8F, 0.8F, 0.3F, 0.0F, 0.0F } ;

real32_T FeedBackCurrentTable[108] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  0.0F, 0.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 1.5F, 1.5F, 1.5F, 1.0F, 1.0F, 0.0F,
  0.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 1.5F, 1.5F, 1.5F, 1.0F, 1.0F, 0.0F, 0.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 1.5F, 1.5F, 1.5F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* maximum discharge current, row: SOC, collumn: T  */

real32_T SOC_Discharge[11] = { 0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F,
  0.8F, 0.9F, 1.0F } ;

real32_T SOC_FastCharge[12] = { 0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F,
  0.79F, 0.8F, 0.9F, 1.0F } ;

real32_T SOC_Feedback[12] = { 0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F,
  0.8F, 0.9F, 0.95F, 1.0F } ;          /* row for max dicharge current table */

real32_T T_ChargeEndSOCAjust[8] = { 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F,
  35.0F, 45.0F } ;

real32_T T_Discharge[12] = { -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 54.0F, 60.0F } ;/* collumn for max discharge current table */

real32_T T_Facdback[9] = { -10.0F, 0.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F,
  54.0F, 60.0F } ;

real32_T T_FastCharge[14] = { -10.0F, 0.0F, 2.0F, 5.0F, 7.0F, 10.0F, 12.0F,
  15.0F, 20.0F, 25.0F, 45.0F, 50.0F, 54.0F, 60.0F } ;

real32_T T_PowerOnSOCAjust[8] = { -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F,
  10.0F, 15.0F } ;

real32_T V_CellLowest[8] = { 3.389F, 3.399F, 3.405F, 3.422F, 3.44F, 3.475F,
  3.63F, 3.65F } ;

/* Constant parameters (auto storage) */
const ConstP_S223_StateMachine_T S223_StateMachine_ConstP = {
  /* Computed Parameter: uDLookupTable3_maxIndex
   * Referenced by: '<S1>/2-D Lookup Table3'
   */
  { 7U, 7U },

  /* Computed Parameter: linearizationSOF_maxIndex
   * Referenced by: '<S41>/linearizationSOF'
   */
  { 11U, 8U },

  /* Computed Parameter: linearizationSOF_maxIndex_a
   * Referenced by: '<S36>/linearizationSOF'
   */
  { 10U, 11U },

  /* Computed Parameter: uDLookupTable3_maxIndex_j
   * Referenced by: '<S6>/2-D Lookup Table3'
   */
  { 13U, 11U }
};

/* Block signals (auto storage) */
B_S223_StateMachine_T S223_StateMachine_B;

/* Block states (auto storage) */
DW_S223_StateMachine_T S223_StateMachine_DW;

/* Real-time model */
RT_MODEL_S223_StateMachine_T S223_StateMachine_M_;
RT_MODEL_S223_StateMachine_T *const S223_StateMachine_M = &S223_StateMachine_M_;
real32_T look2_iflf_linlcpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride);
real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex);
real32_T look2_iflf_binlxpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride);
real32_T look2_iflf_linlxpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride);
extern void S223_StateMachine_FailureMode2(real32_T rtu_BigDisPower, real32_T
  rtu_scale, real32_T *rty_pdff);
extern void S223_StateMac_ChargeEndSOCAjust(void);
extern void S223_StateMachi_PowerOnSOCAjust(void);
extern void PulseRechargePowerAdjust(void);
extern void BigDischargePowerAdjust(void);
extern void FastChrgPowerAjust(void);
extern void S223_StateMach_TaskControl_Init(void);
extern void S223_StateMachine_TaskControl(void);

/* Forward declaration for local functions */
static uint8_T S223_StateMachine_updateState(uint8_T Mode, const uint8_T stVar1
  [3]);
static void S_enter_internal_OpenDischrgNeg(void);
static void S223_StateMachine_delay(void);
static void S223_StateMachine_DisChrg(void);
static void S2_HighVoltagePowerOffDetection(void);
static void S223_State_OpenChrgPosRelay_Req(void);
static void S223_StateMachine_cc2off(void);
static void S223_StateMachine_lossvcu(void);
static void S223_StateMachine_lossvcu1(void);
static void S223_StateMachine_FastChrg(void);
static void exit_internal_HighVoltageSelfTe(void);
static void S2_enter_internal_CheckNegRelay(void);
static void S223_StateM_HighVoltageSelfTest(void);
static void S223_StateM_exit_internal_Nomal(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FFFFFFFU;
    tmpVal.bitVal.words.wordL = 0xFFFFFFFFU;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0x7FFFFFFFU;
  return nanF.wordL.wordLreal;
}

real32_T look2_iflf_linlcpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  real32_T frac;
  uint32_T bpIndices[2];
  real32_T fractions[2];
  real32_T yL_1d;
  uint32_T bpIdx;

  /* Lookup 2-D
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    bpIdx = 0UL;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0UL]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[0UL] >> 1UL; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1UL]) {
      bpIdx++;
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1UL] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex[0UL] - 1UL;
    frac = 1.0F;
  }

  fractions[0UL] = frac;
  bpIndices[0UL] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0UL]) {
    bpIdx = 0UL;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1UL]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[1UL] >> 1UL; u1 < bp1[bpIdx]; bpIdx--) {
    }

    while (u1 >= bp1[bpIdx + 1UL]) {
      bpIdx++;
    }

    frac = (u1 - bp1[bpIdx]) / (bp1[bpIdx + 1UL] - bp1[bpIdx]);
  } else {
    bpIdx = maxIndex[1UL] - 1UL;
    frac = 1.0F;
  }

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = bpIdx * stride + bpIndices[0UL];
  yL_1d = (table[bpIdx + 1UL] - table[bpIdx]) * fractions[0UL] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1UL] - table[bpIdx]) * fractions[0UL] + table[bpIdx])
          - yL_1d) * frac + yL_1d;
}

real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1UL] - table[iLeft]) * frac + table[iLeft];
}

real32_T look2_iflf_binlxpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  real32_T frac;
  uint32_T bpIndices[2];
  real32_T fractions[2];
  real32_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex[0UL]]) {
    /* Binary Search */
    bpIdx = maxIndex[0UL] >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex[0UL];
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0UL] - 1UL;
    frac = (u0 - bp0[maxIndex[0UL] - 1UL]) / (bp0[maxIndex[0UL]] - bp0[maxIndex
      [0UL] - 1UL]);
  }

  fractions[0UL] = frac;
  bpIndices[0UL] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0UL]) {
    iLeft = 0UL;
    frac = (u1 - bp1[0UL]) / (bp1[1UL] - bp1[0UL]);
  } else if (u1 < bp1[maxIndex[1UL]]) {
    /* Binary Search */
    bpIdx = maxIndex[1UL] >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex[1UL];
    while (iRght - iLeft > 1UL) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1UL] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1UL] - 1UL;
    frac = (u1 - bp1[maxIndex[1UL] - 1UL]) / (bp1[maxIndex[1UL]] - bp1[maxIndex
      [1UL] - 1UL]);
  }

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0UL];
  yL_1d = (table[bpIdx + 1UL] - table[bpIdx]) * fractions[0UL] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1UL] - table[bpIdx]) * fractions[0UL] + table[bpIdx])
          - yL_1d) * frac + yL_1d;
}

real32_T look2_iflf_linlxpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  real32_T frac;
  uint32_T bpIndices[2];
  real32_T fractions[2];
  real32_T yL_1d;
  uint32_T bpIdx;

  /* Lookup 2-D
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    bpIdx = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex[0UL]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[0UL] >> 1UL; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1UL]) {
      bpIdx++;
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1UL] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex[0UL] - 1UL;
    frac = (u0 - bp0[maxIndex[0UL] - 1UL]) / (bp0[maxIndex[0UL]] - bp0[maxIndex
      [0UL] - 1UL]);
  }

  fractions[0UL] = frac;
  bpIndices[0UL] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0UL]) {
    bpIdx = 0UL;
    frac = (u1 - bp1[0UL]) / (bp1[1UL] - bp1[0UL]);
  } else if (u1 < bp1[maxIndex[1UL]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[1UL] >> 1UL; u1 < bp1[bpIdx]; bpIdx--) {
    }

    while (u1 >= bp1[bpIdx + 1UL]) {
      bpIdx++;
    }

    frac = (u1 - bp1[bpIdx]) / (bp1[bpIdx + 1UL] - bp1[bpIdx]);
  } else {
    bpIdx = maxIndex[1UL] - 1UL;
    frac = (u1 - bp1[maxIndex[1UL] - 1UL]) / (bp1[maxIndex[1UL]] - bp1[maxIndex
      [1UL] - 1UL]);
  }

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = bpIdx * stride + bpIndices[0UL];
  yL_1d = (table[bpIdx + 1UL] - table[bpIdx]) * fractions[0UL] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1UL] - table[bpIdx]) * fractions[0UL] + table[bpIdx])
          - yL_1d) * frac + yL_1d;
}

/* Output and update for atomic system: '<Root>/ChargeEndSOCAjust' */
void S223_StateMac_ChargeEndSOCAjust(void)
{
  /* Lookup_n-D: '<S1>/2-D Lookup Table3' incorporates:
   *  Constant: '<S1>/Constant4'
   *  DataStoreRead: '<S1>/Data Store Read'
   *  Inport: '<Root>/g_CellLowestVol'
   *  Sum: '<S1>/Add'
   */
  ChargeEndSOCAjustFactor = look2_iflf_linlcpw(g_CellLowestVol, (real32_T)Tavg
    - 40.0F, (&(V_CellLowest[0])), (&(T_ChargeEndSOCAjust[0])),
    (&(Factor_ChargeEndSOCAjust[0])),
    S223_StateMachine_ConstP.uDLookupTable3_maxIndex, 8UL);
}

/* Output and update for atomic system: '<Root>/PowerOnSOCAjust' */
void S223_StateMachi_PowerOnSOCAjust(void)
{
  /* Lookup_n-D: '<S2>/1-D Lookup Table' incorporates:
   *  Constant: '<S2>/Constant4'
   *  DataStoreRead: '<S2>/Data Store Read'
   *  Sum: '<S2>/Add'
   */
  PowerOnSOCAjustFactor = look1_iflf_binlxpw((real32_T)Tavg
    - 40.0F, (&(T_PowerOnSOCAjust[0])), (&(Factor_PowerOnSOCAjust[0])), 7UL);
}

/*
 * Output and update for atomic system:
 *    '<S10>/FailureMode2'
 *    '<S4>/FailureMode2'
 */
void S223_StateMachine_FailureMode2(real32_T rtu_BigDisPower, real32_T rtu_scale,
  real32_T *rty_pdff)
{
  /* Product: '<S39>/multiply' */
  *rty_pdff = rtu_BigDisPower
    * rtu_scale;
}

/* Output and update for function-call system: '<S3>/PulseRechargePowerAdjust' */
void PulseRechargePowerAdjust(void)
{
  real32_T rtb_Add_h;
  real32_T rtb_multiply;

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S10>/Constant4'
   *  Constant: '<S41>/zero'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Logic: '<S41>/and'
   *  RelationalOperator: '<S42>/Compare'
   *  RelationalOperator: '<S43>/Compare'
   *  Sum: '<S10>/Add'
   */
  if ((S223_StateMachine_B.T
       - 40.0F
       > -31.0F)
      && (S223_StateMachine_B.T
          - 40.0F
          < 54.0F)) {
    /* Lookup_n-D: '<S41>/linearizationSOF' */
    rtb_Add_h = look2_iflf_binlxpw(S223_StateMachine_B.SOC,
      S223_StateMachine_B.T
      - 40.0F, (&(SOC_Feedback[0])), (&(T_Facdback[0])),
      (&(FeedBackCurrentTable[0])),
      S223_StateMachine_ConstP.linearizationSOF_maxIndex, 12UL);
  } else {
    rtb_Add_h = 0.0F;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Gain: '<S10>/Gain' */
  rtb_Add_h
    *= CAP_CONST_CAL;

  /* Switch: '<S10>/Switch1' incorporates:
   *  UnitDelay: '<S10>/UnitDelay1'
   */
  if (S223_StateMachine_DW.UnitDelay1_DSTATE_f
      != 0.0) {
    /* Switch: '<S10>/Switch4' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Switch: '<S10>/Switch2'
     */
    if (S223_StateMachine_B.Normal2Zero_flg
        != 0) {
      rtb_Add_h = 0.0F;
    } else {
      if (S223_StateMachine_B.Normal2Half_flg
          != 0) {
        /* Outputs for Atomic SubSystem: '<S10>/FailureMode2' */

        /* Switch: '<S10>/Switch2' incorporates:
         *  Constant: '<S10>/Constant2'
         */
        S223_StateMachine_FailureMode2(rtb_Add_h, 0.5F, &rtb_multiply);

        /* End of Outputs for SubSystem: '<S10>/FailureMode2' */
        rtb_Add_h = rtb_multiply;
      }
    }

    /* End of Switch: '<S10>/Switch4' */

    /* Sum: '<S40>/subtract' incorporates:
     *  UnitDelay: '<S10>/UnitDelay'
     */
    rtb_multiply = rtb_Add_h
      - S223_StateMachine_B.Switch1_n;

    /* Switch: '<S40>/Switch1' */
    if (rtb_multiply
        != 0.0F) {
      /* Switch: '<S40>/Switch2' incorporates:
       *  Constant: '<S40>/kW'
       *  MinMax: '<S40>/max'
       *  Sum: '<S40>/decrease'
       *  UnitDelay: '<S10>/UnitDelay'
       */
      if (rtb_multiply
          > 0.0F) {
        /* MinMax: '<S40>/min' incorporates:
         *  Constant: '<S40>/kW'
         *  Sum: '<S40>/increase'
         *  UnitDelay: '<S10>/UnitDelay'
         */
        if ((rtb_Add_h <= 0.3F
             + S223_StateMachine_B.Switch1_n) || rtIsNaNF(0.3F
             + S223_StateMachine_B.Switch1_n)) {
          S223_StateMachine_B.Switch1_n = rtb_Add_h;
        } else {
          S223_StateMachine_B.Switch1_n
            += 0.3F;
        }

        /* End of MinMax: '<S40>/min' */
      } else if ((rtb_Add_h >= S223_StateMachine_B.Switch1_n
                  - 0.3F) || rtIsNaNF(S223_StateMachine_B.Switch1_n
                  - 0.3F)) {
        /* MinMax: '<S40>/max' */
        S223_StateMachine_B.Switch1_n = rtb_Add_h;
      } else {
        /* MinMax: '<S40>/max' incorporates:
         *  Constant: '<S40>/kW'
         *  Sum: '<S40>/decrease'
         *  UnitDelay: '<S10>/UnitDelay'
         */
        S223_StateMachine_B.Switch1_n
          -= 0.3F;
      }

      /* End of Switch: '<S40>/Switch2' */
    } else {
      S223_StateMachine_B.Switch1_n = rtb_Add_h;
    }

    /* End of Switch: '<S40>/Switch1' */
  } else {
    S223_StateMachine_B.Switch1_n = rtb_Add_h;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Update for UnitDelay: '<S10>/UnitDelay1' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  S223_StateMachine_DW.UnitDelay1_DSTATE_f = 1.0;
}

/* Output and update for function-call system: '<S3>/BigDischargePowerAdjust' */
void BigDischargePowerAdjust(void)
{
  real32_T rtb_Add_hc;
  real32_T rtb_multiply;

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/zero'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S4>/Constant4'
   *  Logic: '<S36>/and'
   *  RelationalOperator: '<S37>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   *  Sum: '<S4>/Add'
   */
  if ((S223_StateMachine_B.T_i
       - 40.0F
       > -31.0F)
      && (S223_StateMachine_B.T_i
          - 40.0F
          < 54.0F)) {
    /* Lookup_n-D: '<S36>/linearizationSOF' */
    rtb_Add_hc = look2_iflf_binlxpw(S223_StateMachine_B.SOC_l,
      S223_StateMachine_B.T_i
      - 40.0F, (&(SOC_Discharge[0])), (&(T_Discharge[0])),
      (&(DisChargeCurrentTable[0])),
      S223_StateMachine_ConstP.linearizationSOF_maxIndex_a, 11UL);
  } else {
    rtb_Add_hc = 0.0F;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Gain: '<S4>/Gain' */
  rtb_Add_hc
    *= CAP_CONST_CAL;

  /* Switch: '<S4>/Switch1' incorporates:
   *  UnitDelay: '<S4>/UnitDelay1'
   */
  if (S223_StateMachine_DW.UnitDelay1_DSTATE
      != 0.0) {
    /* Switch: '<S4>/Switch4' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Switch: '<S4>/Switch2'
     */
    if (S223_StateMachine_B.Normal2Zero_flg_m
        != 0) {
      rtb_Add_hc = 0.0F;
    } else {
      if (S223_StateMachine_B.Normal2Half_flg_g
          != 0) {
        /* Outputs for Atomic SubSystem: '<S4>/FailureMode2' */

        /* Switch: '<S4>/Switch2' incorporates:
         *  Constant: '<S4>/Constant2'
         */
        S223_StateMachine_FailureMode2(rtb_Add_hc, 0.5F, &rtb_multiply);

        /* End of Outputs for SubSystem: '<S4>/FailureMode2' */
        rtb_Add_hc = rtb_multiply;
      }
    }

    /* End of Switch: '<S4>/Switch4' */

    /* Sum: '<S35>/subtract' incorporates:
     *  UnitDelay: '<S4>/UnitDelay'
     */
    rtb_multiply = rtb_Add_hc
      - S223_StateMachine_B.Switch1;

    /* Switch: '<S35>/Switch1' */
    if (rtb_multiply
        != 0.0F) {
      /* Switch: '<S35>/Switch2' incorporates:
       *  Constant: '<S35>/kW'
       *  MinMax: '<S35>/max'
       *  Sum: '<S35>/decrease'
       *  UnitDelay: '<S4>/UnitDelay'
       */
      if (rtb_multiply
          > 0.0F) {
        /* MinMax: '<S35>/min' incorporates:
         *  Constant: '<S35>/kW'
         *  Sum: '<S35>/increase'
         *  UnitDelay: '<S4>/UnitDelay'
         */
        if ((rtb_Add_hc <= 0.3F
             + S223_StateMachine_B.Switch1) || rtIsNaNF(0.3F
             + S223_StateMachine_B.Switch1)) {
          S223_StateMachine_B.Switch1 = rtb_Add_hc;
        } else {
          S223_StateMachine_B.Switch1
            += 0.3F;
        }

        /* End of MinMax: '<S35>/min' */
      } else if ((rtb_Add_hc >= S223_StateMachine_B.Switch1
                  - 0.3F) || rtIsNaNF(S223_StateMachine_B.Switch1
                  - 0.3F)) {
        /* MinMax: '<S35>/max' */
        S223_StateMachine_B.Switch1 = rtb_Add_hc;
      } else {
        /* MinMax: '<S35>/max' incorporates:
         *  Constant: '<S35>/kW'
         *  Sum: '<S35>/decrease'
         *  UnitDelay: '<S4>/UnitDelay'
         */
        S223_StateMachine_B.Switch1
          -= 0.3F;
      }

      /* End of Switch: '<S35>/Switch2' */
    } else {
      S223_StateMachine_B.Switch1 = rtb_Add_hc;
    }

    /* End of Switch: '<S35>/Switch1' */
  } else {
    S223_StateMachine_B.Switch1 = rtb_Add_hc;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Update for UnitDelay: '<S4>/UnitDelay1' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  S223_StateMachine_DW.UnitDelay1_DSTATE = 1.0;
}

/* Output and update for function-call system: '<S3>/FastChrgPowerAjust' */
void FastChrgPowerAjust(void)
{
  real32_T rtb_uDLookupTable3;

  /* Lookup_n-D: '<S6>/2-D Lookup Table3' incorporates:
   *  Constant: '<S6>/Constant4'
   *  DataStoreRead: '<S6>/Data Store Read'
   *  DataStoreRead: '<S6>/Data Store Read1'
   *  Sum: '<S6>/Add'
   */
  rtb_uDLookupTable3 = look2_iflf_linlxpw((real32_T)Tavg
    - 40.0F, g_SysSOC, (&(T_FastCharge[0])), (&(SOC_FastCharge[0])),
    (&(FastChargeCurrentTable[0])),
    S223_StateMachine_ConstP.uDLookupTable3_maxIndex_j, 14UL);

  /* DataStoreWrite: '<S6>/Data Store Write' incorporates:
   *  Gain: '<S6>/Gain'
   */
  AskChaCur = CAP_CONST_CAL
    * rtb_uDLookupTable3;
}

/* Function for Chart: '<Root>/TaskControl' */
static uint8_T S223_StateMachine_updateState(uint8_T Mode, const uint8_T stVar1
  [3])
{
  uint8_T retState;
  uint8_T idx;
  boolean_T guard1 = false;

  /* Graphical Function 'updateState': '<S3>:2426' */
  /* Transition: '<S3>:2406' */
  retState = 99U;
  if (Mode == (int16_T)DISCHARGING) {
    /* Transition: '<S3>:2422' */
    /* Transition: '<S3>:2412' */
    idx = 1U;

    /* Transition: '<S3>:2418' */
    /* Transition: '<S3>:2416' */
    guard1 = true;
  } else {
    /* Transition: '<S3>:2407' */
    /* Transition: '<S3>:2414' */
    if (Mode == (int16_T)FASTRECHARGING) {
      /* Transition: '<S3>:2403' */
      /* Transition: '<S3>:2415' */
      idx = 3U;
      guard1 = true;
    } else {
      /* Transition: '<S3>:2404' */
    }
  }

  if (guard1) {
    /* Transition: '<S3>:2420' */
    retState = stVar1[idx - 1];
  }

  /* Transition: '<S3>:2421' */
  return retState;
}

/* Function for Chart: '<Root>/TaskControl' */
static void S_enter_internal_OpenDischrgNeg(void)
{
  /* Entry Internal 'OpenDischrgNeg': '<S3>:2996' */
  /* Transition: '<S3>:3834' */
  if ((g_DischaNRelayDiscon == 1) || (g_FlagLevel == 4) || (g_RelayPowerOffFault
       == 1)) {
    /* Transition: '<S3>:3830' */
    S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMach_IN_ChrgNomalEnd1;

    /* Entry 'ChrgNomalEnd1': '<S3>:3831' */
    BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 2U;
  } else {
    /* Inport: '<Root>/WithEVCUComOverTimeFlag' */
    /* Transition: '<S3>:3198' */
    if (WithEVCUComOverTimeFlag == 1) {
      /* Transition: '<S3>:3201' */
      S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_ReceiveVCU;
    } else {
      /* Inport: '<Root>/g_ACC_ON' */
      /* Transition: '<S3>:3204' */
      if (g_ACC_ON == 0) {
        /* Transition: '<S3>:3205' */
        S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_ACC_Off;

        /* Entry Internal 'ACC_Off': '<S3>:3203' */
        /* Transition: '<S3>:3207' */
        S223_StateMachine_DW.is_ACC_Off = S223_StateMachine_IN_wait_fp;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      } else {
        /* Inport: '<Root>/g_BatSysTotalCur' */
        /* Transition: '<S3>:3214' */
        if (g_BatSysTotalCur >= 30.0F) {
          /* Transition: '<S3>:3213' */
          S223_StateMachine_DW.is_OpenDischrgNeg =
            S223_StateMachin_IN_OverCurrent;
        } else {
          /* Transition: '<S3>:3218' */
          /* Transition: '<S3>:3219' */
          S223_StateMachine_DW.is_OpenDischrgNeg =
            S223_StateMachi_IN_SmallCurrent;

          /* Entry Internal 'SmallCurrent': '<S3>:3216' */
          /* Transition: '<S3>:3349' */
          S223_StateMachine_DW.is_SmallCurrent = S223_StateMachine_IN_wait_fp;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        }

        /* End of Inport: '<Root>/g_BatSysTotalCur' */
      }

      /* End of Inport: '<Root>/g_ACC_ON' */
    }

    /* End of Inport: '<Root>/WithEVCUComOverTimeFlag' */
  }
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateMachine_delay(void)
{
  /* During 'delay': '<S3>:3927' */
  if (S223_StateMachine_DW.temporalCounter_i2 >= 1400UL) {
    /* Transition: '<S3>:3928' */
    /* 10s */
    S223_StateMachine_DW.is_DisChrg = S223_StateMac_IN_OpenDischrgNeg;

    /* Entry 'OpenDischrgNeg': '<S3>:2996' */
    stateCode = 44U;

    /*  include state code: 44 ; */
    S_enter_internal_OpenDischrgNeg();
  }
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateMachine_DisChrg(void)
{
  boolean_T guard1 = false;

  /* During 'DisChrg': '<S3>:2749' */
  switch (S223_StateMachine_DW.is_DisChrg) {
   case S223_StateMa_IN_CloseDischrgNeg:
    /* Inport: '<Root>/g_ACC_ON' */
    /* During 'CloseDischrgNeg': '<S3>:2764' */
    if ((g_FlagLevel == 4) || (g_ACC_ON == 0) || (g_PowerOffFlag == 1)) {
      /* Transition: '<S3>:3252' */
      /* Transition: '<S3>:3253' */
      /* Exit Internal 'CloseDischrgNeg': '<S3>:2764' */
      S223_StateMachine_DW.is_CloseDischrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_DisChrg = S223_StateMac_IN_OpenDischrgNeg;

      /* Entry 'OpenDischrgNeg': '<S3>:2996' */
      stateCode = 44U;

      /*  include state code: 44 ; */
      S_enter_internal_OpenDischrgNeg();
    } else if (S223_StateMachine_DW.is_CloseDischrgNeg ==
               S223_StateMachine_IN_CloseNeg) {
      /* During 'CloseNeg': '<S3>:2765' */
      if (S223_StateMachine_DW.temporalCounter_i2 >= 4UL) {
        /* Transition: '<S3>:2865' */
        S223_StateMachine_DW.is_CloseDischrgNeg = S223_StateMachine_IN_Wait;
      }
    } else {
      /* During 'Wait': '<S3>:2864' */
      if (g_ACC_ON == 1) {
        /* Transition: '<S3>:2853' */
        S223_StateMachine_DW.is_CloseDischrgNeg =
          S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_DisChrg = S223_IN_HighVoltDetectPart2Test;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;

        /* Entry 'HighVoltDetectPart2Test': '<S3>:2814' */
        stateCode = 17U;

        /* Inport: '<Root>/g_BatSysTotalVolV2' */
        /* Entry Internal 'HighVoltDetectPart2Test': '<S3>:2814' */
        /* Transition: '<S3>:2848' */
        if (g_BatSysTotalVolV2 < 100.0F) {
          /* Transition: '<S3>:2850' */
          S223_StateMachine_DW.is_HighVoltDetectPart2Test =
            S223_StateMachine_IN_Fault1;

          /* Entry Internal 'Fault1': '<S3>:2815' */
          /* Transition: '<S3>:2820' */
          S223_StateMachine_DW.is_Fault1 = S223_StateMachine_IN_wait_f;
        } else {
          /* Transition: '<S3>:2849' */
          S223_StateMachine_DW.is_HighVoltDetectPart2Test =
            S223_StateMachine_IN_NotFault;

          /* Entry Internal 'NotFault': '<S3>:2816' */
          /* Transition: '<S3>:2874' */
          S223_StateMachine_DW.is_NotFault = S223_StateMachine_IN_wait_f;
        }
      }
    }
    break;

   case S223_StateMac_IN_Dischrg_Normal:
    /* Inport: '<Root>/WithEVCUComOverTimeFlag' incorporates:
     *  Inport: '<Root>/g_ACC_ON'
     */
    /* During 'Dischrg_Normal': '<S3>:2913' */
    /* Transition: '<S3>:3918' */
    /* Transition: '<S3>:3920' */
    if (WithEVCUComOverTimeFlag == 1) {
      /* Transition: '<S3>:3923' */
      /* Exit Internal 'Dischrg_Normal': '<S3>:2913' */
      /* Exit Internal 'CarFaultDone': '<S3>:2957' */
      /* Exit Internal 'FaultCheck': '<S3>:2958' */
      S223_StateMachine_DW.is_FaultCheck = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_CarFaultDone = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_Dischrg_Normal = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_DisChrg = S223_StateMachine_IN_LossVCU;

      /* Entry Internal 'LossVCU': '<S3>:3907' */
      /* Transition: '<S3>:3915' */
      S223_StateMachine_DW.is_LossVCU = S223_StateMachine_IN_Wait;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;
    } else if (g_PowerOffFlag == 1) {
      /* Transition: '<S3>:3095' */
      /* Exit Internal 'Dischrg_Normal': '<S3>:2913' */
      /* Exit Internal 'CarFaultDone': '<S3>:2957' */
      /* Exit Internal 'FaultCheck': '<S3>:2958' */
      S223_StateMachine_DW.is_FaultCheck = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_CarFaultDone = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_Dischrg_Normal = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_DisChrg = S223_StateMachine_IN_delay;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;
    } else if ((g_ACC_ON == 0) || (EVCU_Byte0.Bit.F6_7_BatNCtorCtrl == 2)) {
      /* Transition: '<S3>:3097' */
      /* Transition: '<S3>:3098' */
      /* Exit Internal 'Dischrg_Normal': '<S3>:2913' */
      /* Exit Internal 'CarFaultDone': '<S3>:2957' */
      /* Exit Internal 'FaultCheck': '<S3>:2958' */
      S223_StateMachine_DW.is_FaultCheck = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_CarFaultDone = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_Dischrg_Normal = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_DisChrg = S223_StateMac_IN_OpenDischrgNeg;

      /* Entry 'OpenDischrgNeg': '<S3>:2996' */
      stateCode = 44U;

      /*  include state code: 44 ; */
      S_enter_internal_OpenDischrgNeg();
    } else {
      stateCode = 30U;
      turnOnSW_Power();

      /* Simulink Function 'BigDischargePowerAdjust': '<S3>:1198' */
      S223_StateMachine_B.SOC_l = g_SysSOC;
      S223_StateMachine_B.T_i = Tavg;

      /* Inport: '<Root>/CutDischaTo0' */
      S223_StateMachine_B.Normal2Zero_flg_m = CutDischaTo0;

      /* Inport: '<Root>/CutDischaTo50' */
      S223_StateMachine_B.Normal2Half_flg_g = CutDischaTo50;

      /* Outputs for Function Call SubSystem: '<S3>/BigDischargePowerAdjust' */
      BigDischargePowerAdjust();

      /* End of Outputs for SubSystem: '<S3>/BigDischargePowerAdjust' */
      g_MaxDischaCur = S223_StateMachine_B.Switch1;

      /* Simulink Function 'PulseRechargePowerAdjust': '<S3>:873' */
      S223_StateMachine_B.SOC = g_SysSOC;
      S223_StateMachine_B.T = Tavg;

      /* Inport: '<Root>/CutFebchaTo0' */
      S223_StateMachine_B.Normal2Zero_flg = CutFebchaTo0;

      /* Inport: '<Root>/CutFebchaTo50' */
      S223_StateMachine_B.Normal2Half_flg = CutFebchaTo50;

      /* Outputs for Function Call SubSystem: '<S3>/PulseRechargePowerAdjust' */
      PulseRechargePowerAdjust();

      /* End of Outputs for SubSystem: '<S3>/PulseRechargePowerAdjust' */
      g_MaxFebCur = S223_StateMachine_B.Switch1_n;
      SocEndDischargeAdjust();

      /*  include state code: 30; */
      /* During 'CarFaultDone': '<S3>:2957' */
      /* During 'FaultCheck': '<S3>:2958' */
      if ((S223_StateMachine_DW.is_FaultCheck == S223_StateMachine_IN_Check) &&
          ((BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm == 4) ||
           (BMS7_Byte0.Bit.F2_4_TotalVolUnderVolAlarm == 4) ||
           (BMS7_Byte0.Bit.F0_WithLECUComAlarm == 1) ||
           (BMS7_Byte1.Bit.F5_7_DisChaOverCurAlarm == 4) ||
           (BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm == 4) ||
           (BMS7_Byte2.Bit.F5_7_CellOverVolAlarm == 4) ||
           (BMS7_Byte2.Bit.F2_4_CellUnderVolAlarm == 4) ||
           (BMS7_Byte2.Bit.F1_CurSenFault == 1) ||
           (BMS7_Byte4.Bit.F5_7_BatTempHighAlarm == 4) ||
           (BMS7_Byte4.Bit.F2_4_BatTempLowAlarm == 4))) {
        /* During 'Check': '<S3>:2962' */
        /*    */
        /* Transition: '<S3>:2965' */
        S223_StateMachine_DW.is_FaultCheck = S223_StateMachine_IN_Confirm_k;

        /* Entry 'Confirm': '<S3>:2963' */
        g_PowerOffFlag = 1U;
      } else {
        /* During 'Confirm': '<S3>:2963' */
      }
    }
    break;

   case S223_IN_HighVoltDetectPart2Test:
    /* During 'HighVoltDetectPart2Test': '<S3>:2814' */
    if (S223_StateMachine_DW.temporalCounter_i2 >= 16UL) {
      /* Inport: '<Root>/g_ACC_ON' */
      /* Transition: '<S3>:3337' */
      if ((g_DischaNRelayDiscon == 1) || (g_FlagLevel == 4) || (g_PowerOffFlag ==
           1) || (g_ACC_ON == 0)) {
        /* Transition: '<S3>:3001' */
        /* Exit Internal 'HighVoltDetectPart2Test': '<S3>:2814' */
        /* Exit Internal 'Fault1': '<S3>:2815' */
        S223_StateMachine_DW.is_Fault1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HighVoltDetectPart2Test =
          S223_StateMa_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'NotFault': '<S3>:2816' */
        S223_StateMachine_DW.is_NotFault = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_DisChrg = S223_StateMac_IN_OpenDischrgNeg;

        /* Entry 'OpenDischrgNeg': '<S3>:2996' */
        stateCode = 44U;

        /*  include state code: 44 ; */
        S_enter_internal_OpenDischrgNeg();
      } else if ((g_ACC_ON == 1) && (g_BMSSelfCheckCounter == 2)) {
        /* Transition: '<S3>:2914' */
        /* Exit Internal 'HighVoltDetectPart2Test': '<S3>:2814' */
        /* Exit Internal 'Fault1': '<S3>:2815' */
        S223_StateMachine_DW.is_Fault1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HighVoltDetectPart2Test =
          S223_StateMa_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'NotFault': '<S3>:2816' */
        S223_StateMachine_DW.is_NotFault = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_DisChrg = S223_StateMac_IN_Dischrg_Normal;

        /* Entry Internal 'Dischrg_Normal': '<S3>:2913' */
        /* Transition: '<S3>:2991' */
        S223_StateMachine_DW.is_Dischrg_Normal = S223_StateMachi_IN_CarFaultDone;

        /* Entry Internal 'CarFaultDone': '<S3>:2957' */
        /* Transition: '<S3>:2979' */
        S223_StateMachine_DW.is_CarFaultDone = S223_StateMachine_IN_FaultCheck;

        /* Entry Internal 'FaultCheck': '<S3>:2958' */
        /* Transition: '<S3>:2964' */
        S223_StateMachine_DW.is_FaultCheck = S223_StateMachine_IN_Check;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    break;

   case IN_HighVoltagePowerOffDetection:
    /* During 'HighVoltagePowerOffDetection': '<S3>:2791' */
    if (S223_StateMachine_DW.is_HighVoltagePowerOffDetection ==
        S223_StateMachine_IN_Detect) {
      /* During 'Detect': '<S3>:3248' */
      switch (S223_StateMachine_DW.is_Detect) {
       case S223_StateMachine_IN_Confirm:
        /* Inport: '<Root>/g_ACC_ON' */
        /* During 'Confirm': '<S3>:3350' */
        /* Transition: '<S3>:3357' */
        /* Transition: '<S3>:3358' */
        if ((g_DischaNRelayAdin == 1) || (g_FlagLevel == 4) ||
            (g_RelayPowerOffFault == 1) || (g_PowerOffFlag == 1) || (g_ACC_ON ==
             0)) {
          /* Transition: '<S3>:3788' */
          /* Transition: '<S3>:3246' */
          S223_StateMachine_DW.is_Detect = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_HighVoltagePowerOffDetection =
            S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_DisChrg = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_Nomal = S223_StateMachin_IN_InformStore;

          /* Inport: '<Root>/g_BmsModeFlag' */
          /* Entry 'InformStore': '<S3>:2561' */
          stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
            S223_StateMachine_DW.STATE47_187);

          /* StateCode=47;
             include state code: 47  187; */
          /* Entry Internal 'InformStore': '<S3>:2561' */
          /* Transition: '<S3>:2559' */
          S223_StateMachine_DW.is_InformStore = S223_StateMachine_IN_init;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        } else {
          /* Transition: '<S3>:3360' */
          S223_StateMachine_DW.is_Detect = S223_StateMa_IN_NO_ACTIVE_CHILD;

          /* Inport: '<Root>/g_BatSysTotalVolV2' */
          /* Entry Internal 'Detect': '<S3>:3248' */
          /* Transition: '<S3>:2802' */
          if (g_BatSysTotalVolV2 >= 300.0F) {
            /* Transition: '<S3>:2796' */
            S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Fault_f;

            /* Entry Internal 'Fault': '<S3>:2795' */
            /* Transition: '<S3>:2792' */
            S223_StateMachine_DW.is_Fault_a = S223_StateMachine_IN_Confirm;
            S223_StateMachine_DW.temporalCounter_i2 = 0UL;
          } else {
            /* Transition: '<S3>:2801' */
            S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Normal_a;

            /* Entry 'Normal': '<S3>:2793' */
            g_BMSSelfCheckCounter = 1U;
          }
        }
        break;

       case S223_StateMachine_IN_Fault_f:
        /* Inport: '<Root>/g_BatSysTotalVolV2' */
        /* During 'Fault': '<S3>:2795' */
        if (g_BatSysTotalVolV2 < 300.0F) {
          /* Transition: '<S3>:2794' */
          /* Exit Internal 'Fault': '<S3>:2795' */
          S223_StateMachine_DW.is_Fault_a = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Normal_a;

          /* Entry 'Normal': '<S3>:2793' */
          g_BMSSelfCheckCounter = 1U;
        } else if (S223_StateMachine_DW.is_Fault_a ==
                   S223_StateMachine_IN_Confirm) {
          /* During 'Confirm': '<S3>:2798' */
          if (S223_StateMachine_DW.temporalCounter_i2 >= 12UL) {
            /* Transition: '<S3>:2790' */
            S223_StateMachine_DW.is_Fault_a = IN_DischrgNegRelay_Malfunction;

            /* Entry 'DischrgNegRelay_Malfunction': '<S3>:2797' */
            g_RelayPowerOffFault = 1U;
            state_pc552_Byte1.Bit.F0_St_N_Relay_PC = 1U;
            BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 3U;
            g_FlagLevel = 4U;
            BMS9_Byte7.Bit.F4_BzerAlarm = 1U;
            g_DischaNRelayAdin = 1U;
          }
        } else {
          /* During 'DischrgNegRelay_Malfunction': '<S3>:2797' */
          /* Transition: '<S3>:3351' */
          S223_StateMachine_DW.is_Fault_a = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Confirm;
        }
        break;

       default:
        /* Inport: '<Root>/g_BatSysTotalVolV2' */
        /* During 'Normal': '<S3>:2793' */
        if (g_BatSysTotalVolV2 >= 300.0F) {
          /* Transition: '<S3>:2789' */
          S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Fault_f;

          /* Entry Internal 'Fault': '<S3>:2795' */
          /* Transition: '<S3>:2792' */
          S223_StateMachine_DW.is_Fault_a = S223_StateMachine_IN_Confirm;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        } else {
          /* Transition: '<S3>:3359' */
          S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Confirm;
        }
        break;
      }
    } else {
      /* During 'Wait': '<S3>:3247' */
      if (S223_StateMachine_DW.temporalCounter_i2 >= 12UL) {
        /* Transition: '<S3>:3249' */
        S223_StateMachine_DW.is_HighVoltagePowerOffDetection =
          S223_StateMachine_IN_Detect;

        /* Inport: '<Root>/g_BatSysTotalVolV2' */
        /* Entry Internal 'Detect': '<S3>:3248' */
        /* Transition: '<S3>:2802' */
        if (g_BatSysTotalVolV2 >= 300.0F) {
          /* Transition: '<S3>:2796' */
          S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Fault_f;

          /* Entry Internal 'Fault': '<S3>:2795' */
          /* Transition: '<S3>:2792' */
          S223_StateMachine_DW.is_Fault_a = S223_StateMachine_IN_Confirm;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        } else {
          /* Transition: '<S3>:2801' */
          S223_StateMachine_DW.is_Detect = S223_StateMachine_IN_Normal_a;

          /* Entry 'Normal': '<S3>:2793' */
          g_BMSSelfCheckCounter = 1U;
        }
      }
    }
    break;

   case S223_StateMachine_IN_LossVCU:
    /* During 'LossVCU': '<S3>:3907' */
    if (S223_StateMachine_DW.is_LossVCU == S223_StateMachine_IN_Confirm) {
      /* During 'Confirm': '<S3>:3914' */
      /* Transition: '<S3>:3925' */
      S223_StateMachine_DW.is_LossVCU = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_DisChrg = S223_StateMac_IN_OpenDischrgNeg;

      /* Entry 'OpenDischrgNeg': '<S3>:2996' */
      stateCode = 44U;

      /*  include state code: 44 ; */
      S_enter_internal_OpenDischrgNeg();
    } else {
      /* During 'Wait': '<S3>:3913' */
      if (S223_StateMachine_DW.temporalCounter_i2 >= 640UL) {
        /* Transition: '<S3>:3916' */
        /* 5s */
        S223_StateMachine_DW.is_LossVCU = S223_StateMachine_IN_Confirm;
      }
    }
    break;

   case S223_StateMac_IN_OpenDischrgNeg:
    /* During 'OpenDischrgNeg': '<S3>:2996' */
    switch (S223_StateMachine_DW.is_OpenDischrgNeg) {
     case S223_StateMachine_IN_ACC_Off:
      /* Inport: '<Root>/WithEVCUComOverTimeFlag' incorporates:
       *  Inport: '<Root>/g_BatSysTotalCur'
       */
      /* During 'ACC_Off': '<S3>:3203' */
      if (WithEVCUComOverTimeFlag == 1) {
        /* Transition: '<S3>:3210' */
        /* Exit Internal 'ACC_Off': '<S3>:3203' */
        S223_StateMachine_DW.is_ACC_Off = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_ReceiveVCU;
      } else if (g_BatSysTotalCur >= 30.0F) {
        /* Transition: '<S3>:3215' */
        /* Exit Internal 'ACC_Off': '<S3>:3203' */
        S223_StateMachine_DW.is_ACC_Off = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachin_IN_OverCurrent;
      } else {
        /* During 'wait': '<S3>:3206' */
        if (S223_StateMachine_DW.temporalCounter_i2 >= 640UL) {
          /* Transition: '<S3>:3209' */
          /* 5s */
          S223_StateMachine_DW.is_ACC_Off = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_OpenDischrgNeg =
            S223_StateMachine_IN_Confirm_kq;
        }
      }
      break;

     case S223_StateMach_IN_ChrgNomalEnd1:
      /* During 'ChrgNomalEnd1': '<S3>:3831' */
      /* Transition: '<S3>:3832' */
      S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_Confirm_kq;
      break;

     case S223_StateMachine_IN_Confirm_kq:
      /* During 'Confirm': '<S3>:3235' */
      /* Transition: '<S3>:3242' */
      /* Transition: '<S3>:3243' */
      S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_DisChrg = IN_HighVoltagePowerOffDetection;

      /* Entry 'HighVoltagePowerOffDetection': '<S3>:2791' */
      stateCode = 46U;

      /*  include state code: 46 */
      /* Entry Internal 'HighVoltagePowerOffDetection': '<S3>:2791' */
      /* Transition: '<S3>:3250' */
      S223_StateMachine_DW.is_HighVoltagePowerOffDetection =
        S223_StateMachine_IN_Wait;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;

      /* Entry 'Wait': '<S3>:3247' */
      TurnOff_INFK();
      BMS8_Byte0.Bit.F2_3_BMSInterCtorState = 1U;
      BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 2U;
      break;

     case S223_StateMachin_IN_OverCurrent:
      /* During 'OverCurrent': '<S3>:3211' */
      /* Transition: '<S3>:3238' */
      S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_Confirm_kq;
      break;

     case S223_StateMachine_IN_ReceiveVCU:
      /* During 'ReceiveVCU': '<S3>:3200' */
      /* Transition: '<S3>:3236' */
      S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_Confirm_kq;
      break;

     default:
      /* Inport: '<Root>/g_BatSysTotalCur' incorporates:
       *  Inport: '<Root>/WithEVCUComOverTimeFlag'
       *  Inport: '<Root>/g_ACC_ON'
       */
      /* During 'SmallCurrent': '<S3>:3216' */
      if (g_BatSysTotalCur >= 30.0F) {
        /* Transition: '<S3>:3225' */
        /* Exit Internal 'SmallCurrent': '<S3>:3216' */
        S223_StateMachine_DW.is_SmallCurrent = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachin_IN_OverCurrent;
      } else if (g_ACC_ON == 0) {
        /* Transition: '<S3>:3232' */
        /* Transition: '<S3>:3233' */
        /* Exit Internal 'SmallCurrent': '<S3>:3216' */
        S223_StateMachine_DW.is_SmallCurrent = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_ACC_Off;

        /* Entry Internal 'ACC_Off': '<S3>:3203' */
        /* Transition: '<S3>:3207' */
        S223_StateMachine_DW.is_ACC_Off = S223_StateMachine_IN_wait_fp;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      } else if (WithEVCUComOverTimeFlag == 1) {
        /* Transition: '<S3>:3227' */
        /* Exit Internal 'SmallCurrent': '<S3>:3216' */
        S223_StateMachine_DW.is_SmallCurrent = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMachine_IN_Confirm_kq;
      } else {
        /* During 'wait': '<S3>:3220' */
        if ((S223_StateMachine_DW.temporalCounter_i2 >= 10000UL) ||
            (EVCU_Byte0.Bit.F6_7_BatNCtorCtrl == 2)) {
          /* Transition: '<S3>:3223' */
          /* 60s */
          S223_StateMachine_DW.is_SmallCurrent = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_OpenDischrgNeg =
            S223_StateMachine_IN_Confirm_kq;
        }
      }
      break;
    }
    break;

   case S223_StateMachine_IN_delay:
    S223_StateMachine_delay();
    break;

   default:
    /* Inport: '<Root>/g_ACC_ON' */
    /* During 'wait': '<S3>:2809' */
    /* Transition: '<S3>:2810' */
    if ((g_BMSSelfCheckCounter == 1) && (g_ACC_ON == 1) &&
        (EVCU_Byte0.Bit.F6_7_BatNCtorCtrl == 1)) {
      /* Transition: '<S3>:2778' */
      S223_StateMachine_DW.is_DisChrg = S223_StateMa_IN_CloseDischrgNeg;

      /* Entry 'CloseDischrgNeg': '<S3>:2764' */
      stateCode = 14U;

      /*  include state code: 14 ; */
      /* Entry Internal 'CloseDischrgNeg': '<S3>:2764' */
      /* Transition: '<S3>:2769' */
      S223_StateMachine_DW.is_CloseDischrgNeg = S223_StateMachine_IN_CloseNeg;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;

      /* Entry 'CloseNeg': '<S3>:2765' */
      TurnOn_INFK();
    }
    break;
  }

  if (guard1) {
    /*  include state code: 17; */
    if (S223_StateMachine_DW.is_HighVoltDetectPart2Test ==
        S223_StateMachine_IN_Fault1) {
      /* Inport: '<Root>/g_BatSysTotalVolV2' */
      /* During 'Fault1': '<S3>:2815' */
      if (g_BatSysTotalVolV2 >= 100.0F) {
        /* Transition: '<S3>:2852' */
        /* Exit Internal 'Fault1': '<S3>:2815' */
        S223_StateMachine_DW.is_Fault1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HighVoltDetectPart2Test =
          S223_StateMachine_IN_NotFault;

        /* Entry Internal 'NotFault': '<S3>:2816' */
        /* Transition: '<S3>:2874' */
        S223_StateMachine_DW.is_NotFault = S223_StateMachine_IN_wait_f;
      } else {
        switch (S223_StateMachine_DW.is_Fault1) {
         case S223_StateMachine_IN_Confirm:
          /* During 'Confirm': '<S3>:2818' */
          if (S223_StateMachine_DW.temporalCounter_i1 >= 12) {
            /* Transition: '<S3>:2822' */
            S223_StateMachine_DW.is_Fault1 = S223_StateMachine_IN_Fault_f;

            /* Entry 'Fault': '<S3>:2819' */
            g_RelayPowerOffFault = 1U;
            fault_pc552_Byte7.Bit.F2_NRelayDisconFault = 1U;
            g_FlagLevel = 4U;
            g_DischaNRelayDiscon = 1U;
            BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 2U;
          }
          break;

         case S223_StateMachine_IN_Fault_f:
          /* During 'Fault': '<S3>:2819' */
          /* Transition: '<S3>:3339' */
          S223_StateMachine_DW.is_Fault1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_HighVoltDetectPart2Test =
            S223_StateMa_IN_NO_ACTIVE_CHILD;

          /* Entry Internal 'HighVoltDetectPart2Test': '<S3>:2814' */
          /* Transition: '<S3>:2848' */
          if (g_BatSysTotalVolV2 < 100.0F) {
            /* Transition: '<S3>:2850' */
            S223_StateMachine_DW.is_HighVoltDetectPart2Test =
              S223_StateMachine_IN_Fault1;

            /* Entry Internal 'Fault1': '<S3>:2815' */
            /* Transition: '<S3>:2820' */
            S223_StateMachine_DW.is_Fault1 = S223_StateMachine_IN_wait_f;
          } else {
            /* Transition: '<S3>:2849' */
            S223_StateMachine_DW.is_HighVoltDetectPart2Test =
              S223_StateMachine_IN_NotFault;

            /* Entry Internal 'NotFault': '<S3>:2816' */
            /* Transition: '<S3>:2874' */
            S223_StateMachine_DW.is_NotFault = S223_StateMachine_IN_wait_f;
          }
          break;

         default:
          /* During 'wait': '<S3>:2817' */
          if (g_BatSysTotalVolV2 < 100.0F) {
            /* Transition: '<S3>:2821' */
            S223_StateMachine_DW.is_Fault1 = S223_StateMachine_IN_Confirm;
            S223_StateMachine_DW.temporalCounter_i1 = 0U;
          }
          break;
        }
      }
    } else {
      /* Inport: '<Root>/g_BatSysTotalVolV2' */
      /* During 'NotFault': '<S3>:2816' */
      if (g_BatSysTotalVolV2 < 100.0F) {
        /* Transition: '<S3>:2851' */
        /* Exit Internal 'NotFault': '<S3>:2816' */
        S223_StateMachine_DW.is_NotFault = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HighVoltDetectPart2Test =
          S223_StateMachine_IN_Fault1;

        /* Entry Internal 'Fault1': '<S3>:2815' */
        /* Transition: '<S3>:2820' */
        S223_StateMachine_DW.is_Fault1 = S223_StateMachine_IN_wait_f;
      } else {
        switch (S223_StateMachine_DW.is_NotFault) {
         case S223_StateMachine_IN_Confirm:
          /* During 'Confirm': '<S3>:2870' */
          if (S223_StateMachine_DW.temporalCounter_i1 >= 10) {
            /* Transition: '<S3>:2873' */
            S223_StateMachine_DW.is_NotFault = S223_StateMachine_IN_Fault1_h;

            /* Entry 'Fault1': '<S3>:2872' */
            g_BMSSelfCheckCounter = 2U;
            BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 1U;
          }
          break;

         case S223_StateMachine_IN_Fault1_h:
          /* During 'Fault1': '<S3>:2872' */
          /* Transition: '<S3>:3340' */
          S223_StateMachine_DW.is_NotFault = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_HighVoltDetectPart2Test =
            S223_StateMa_IN_NO_ACTIVE_CHILD;

          /* Entry Internal 'HighVoltDetectPart2Test': '<S3>:2814' */
          /* Transition: '<S3>:2848' */
          if (g_BatSysTotalVolV2 < 100.0F) {
            /* Transition: '<S3>:2850' */
            S223_StateMachine_DW.is_HighVoltDetectPart2Test =
              S223_StateMachine_IN_Fault1;

            /* Entry Internal 'Fault1': '<S3>:2815' */
            /* Transition: '<S3>:2820' */
            S223_StateMachine_DW.is_Fault1 = S223_StateMachine_IN_wait_f;
          } else {
            /* Transition: '<S3>:2849' */
            S223_StateMachine_DW.is_HighVoltDetectPart2Test =
              S223_StateMachine_IN_NotFault;

            /* Entry Internal 'NotFault': '<S3>:2816' */
            /* Transition: '<S3>:2874' */
            S223_StateMachine_DW.is_NotFault = S223_StateMachine_IN_wait_f;
          }
          break;

         default:
          /* During 'wait': '<S3>:2871' */
          if (g_BatSysTotalVolV2 >= 100.0F) {
            /* Transition: '<S3>:2869' */
            S223_StateMachine_DW.is_NotFault = S223_StateMachine_IN_Confirm;
            S223_StateMachine_DW.temporalCounter_i1 = 0U;
          }
          break;
        }
      }
    }
  }
}

/* Function for Chart: '<Root>/TaskControl' */
static void S2_HighVoltagePowerOffDetection(void)
{
  /* During 'HighVoltagePowerOffDetection': '<S3>:3669' */
  if (S223_StateMachine_DW.is_HighVoltagePowerOffDetecti_m ==
      S223_StateMachine_IN_Detect) {
    /* During 'Detect': '<S3>:3673' */
    switch (S223_StateMachine_DW.is_Detect_a) {
     case S223_StateMachine_IN_Confirm:
      /* During 'Confirm': '<S3>:3678' */
      if ((g_BMSSelfCheckCounter == 1) || (g_ChaNRelayAdin == 1)) {
        /* Transition: '<S3>:3683' */
        /* Transition: '<S3>:3685' */
        /* Transition: '<S3>:3691' */
        S223_StateMachine_DW.is_Detect_a = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HighVoltagePowerOffDetecti_m =
          S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_FastChrg = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_Nomal = S223_StateMachin_IN_InformStore;

        /* Inport: '<Root>/g_BmsModeFlag' */
        /* Entry 'InformStore': '<S3>:2561' */
        stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
          S223_StateMachine_DW.STATE47_187);

        /* StateCode=47;
           include state code: 47  187; */
        /* Entry Internal 'InformStore': '<S3>:2561' */
        /* Transition: '<S3>:2559' */
        S223_StateMachine_DW.is_InformStore = S223_StateMachine_IN_init;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      } else {
        /* Transition: '<S3>:3679' */
        S223_StateMachine_DW.is_Detect_a = S223_StateMa_IN_NO_ACTIVE_CHILD;

        /* Inport: '<Root>/g_BatSysTotalVolV3' */
        /* Entry Internal 'Detect': '<S3>:3673' */
        /* Transition: '<S3>:3666' */
        if (g_BatSysTotalVolV3 >= 300.0F) {
          /* Transition: '<S3>:3670' */
          S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Fault_f;

          /* Entry Internal 'Fault': '<S3>:3672' */
          /* Transition: '<S3>:3671' */
          S223_StateMachine_DW.is_Fault_j = S223_StateMachine_IN_Confirm_k;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        } else {
          /* Transition: '<S3>:3674' */
          S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Normal_a;

          /* Entry 'Normal': '<S3>:3677' */
          g_BMSSelfCheckCounter = 1U;
        }
      }
      break;

     case S223_StateMachine_IN_Fault_f:
      /* Inport: '<Root>/g_BatSysTotalVolV3' */
      /* During 'Fault': '<S3>:3672' */
      if (g_BatSysTotalVolV3 < 300.0F) {
        /* Transition: '<S3>:3668' */
        /* Exit Internal 'Fault': '<S3>:3672' */
        S223_StateMachine_DW.is_Fault_j = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Normal_a;

        /* Entry 'Normal': '<S3>:3677' */
        g_BMSSelfCheckCounter = 1U;
      } else if (S223_StateMachine_DW.is_Fault_j ==
                 S22_IN_ChrgNegRelay_Malfunction) {
        /* During 'ChrgNegRelay_Malfunction': '<S3>:3663' */
        /* Transition: '<S3>:3662' */
        S223_StateMachine_DW.is_Fault_j = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Confirm;
      } else {
        /* During 'Confirm': '<S3>:3660' */
        if (S223_StateMachine_DW.temporalCounter_i2 >= 12UL) {
          /* Transition: '<S3>:3661' */
          S223_StateMachine_DW.is_Fault_j = S22_IN_ChrgNegRelay_Malfunction;

          /* Entry 'ChrgNegRelay_Malfunction': '<S3>:3663' */
          g_RelayPowerOffFault = 1U;
          fault_pc552_Byte7.Bit.F1_NRelayAdinFault = 1U;
          BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1 = 3U;
          g_FlagLevel = 4U;
          BMS9_Byte7.Bit.F4_BzerAlarm = 1U;
          BMS9_Byte7.Bit.F0_ChaCtorAdin1 = 1U;
          g_ChaNRelayAdin = 1U;
        }
      }
      break;

     default:
      /* Inport: '<Root>/g_BatSysTotalVolV3' */
      /* During 'Normal': '<S3>:3677' */
      if (g_BatSysTotalVolV3 >= 300.0F) {
        /* Transition: '<S3>:3665' */
        S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Fault_f;

        /* Entry Internal 'Fault': '<S3>:3672' */
        /* Transition: '<S3>:3671' */
        S223_StateMachine_DW.is_Fault_j = S223_StateMachine_IN_Confirm_k;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      } else {
        /* Transition: '<S3>:3680' */
        S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Confirm;
      }
      break;
    }
  } else {
    /* During 'Wait': '<S3>:3667' */
    if (S223_StateMachine_DW.temporalCounter_i2 >= 12UL) {
      /* Transition: '<S3>:3675' */
      S223_StateMachine_DW.is_HighVoltagePowerOffDetecti_m =
        S223_StateMachine_IN_Detect;

      /* Inport: '<Root>/g_BatSysTotalVolV3' */
      /* Entry Internal 'Detect': '<S3>:3673' */
      /* Transition: '<S3>:3666' */
      if (g_BatSysTotalVolV3 >= 300.0F) {
        /* Transition: '<S3>:3670' */
        S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Fault_f;

        /* Entry Internal 'Fault': '<S3>:3672' */
        /* Transition: '<S3>:3671' */
        S223_StateMachine_DW.is_Fault_j = S223_StateMachine_IN_Confirm_k;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      } else {
        /* Transition: '<S3>:3674' */
        S223_StateMachine_DW.is_Detect_a = S223_StateMachine_IN_Normal_a;

        /* Entry 'Normal': '<S3>:3677' */
        g_BMSSelfCheckCounter = 1U;
      }
    }
  }
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_State_OpenChrgPosRelay_Req(void)
{
  /* Inport: '<Root>/WithEVCUComOverTimeFlag' incorporates:
   *  Inport: '<Root>/ChangerINError'
   *  Inport: '<Root>/FastEndNormalFlag'
   *  Inport: '<Root>/g_DC_CC2'
   */
  /* During 'OpenChrgPosRelay_Req': '<S3>:3607' */
  if (WithEVCUComOverTimeFlag == 2) {
    /* Transition: '<S3>:3903' */
    /* Exit Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
    /* Exit Internal 'Confirm': '<S3>:3868' */
    S223_StateMachine_DW.is_Confirm = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
      S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_FastChrg = S223_StateMac_IN_OpenDischrgNeg;

    /* Entry 'OpenDischrgNeg': '<S3>:3615' */
    stateCode = 184U;

    /*  include state code: 184 ; */
    /* Entry Internal 'OpenDischrgNeg': '<S3>:3615' */
    S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMachine_IN_Confirm1;

    /* Entry 'Confirm1': '<S3>:3901' */
    TurnOff_INA2K();

    /* Entry Internal 'Confirm1': '<S3>:3901' */
    /* Transition: '<S3>:3898' */
    S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Wait;
    S223_StateMachine_DW.temporalCounter_i2 = 0UL;
  } else if (FastEndNormalFlag == 1) {
    /* Transition: '<S3>:3878' */
    /* Exit Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
    /* Exit Internal 'Confirm': '<S3>:3868' */
    S223_StateMachine_DW.is_Confirm = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
      S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_normalend;
  } else if ((g_DC_CC2 == 0) || (ChangerINError == 1)) {
    /* Transition: '<S3>:3880' */
    /* Exit Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
    /* Exit Internal 'Confirm': '<S3>:3868' */
    S223_StateMachine_DW.is_Confirm = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
      S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_cc2off;
    S223_StateMachine_DW.temporalCounter_i2 = 0UL;
  } else if (EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1 == 2) {
    /* Transition: '<S3>:3887' */
    /* Exit Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
    /* Exit Internal 'Confirm': '<S3>:3868' */
    S223_StateMachine_DW.is_Confirm = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
      S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_lossvcu;
  } else {
    /* Transition: '<S3>:3891' */
    /* Exit Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
    /* Exit Internal 'Confirm': '<S3>:3868' */
    S223_StateMachine_DW.is_Confirm = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
      S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_lossvcu1;
    S223_StateMachine_DW.temporalCounter_i2 = 0UL;
  }

  /* End of Inport: '<Root>/WithEVCUComOverTimeFlag' */
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateMachine_cc2off(void)
{
  /* Inport: '<Root>/FastEndNormalFlag' */
  /* During 'cc2off': '<S3>:3881' */
  if (FastEndNormalFlag == 1) {
    /* Transition: '<S3>:3885' */
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_normalend;
  } else if (EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1 == 2) {
    /* Transition: '<S3>:3889' */
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_lossvcu;
  } else {
    if (S223_StateMachine_DW.temporalCounter_i2 >= 360UL) {
      /* Transition: '<S3>:3882' */
      S223_StateMachine_DW.is_FastChrg = S223_StateMac_IN_OpenDischrgNeg;

      /* Entry 'OpenDischrgNeg': '<S3>:3615' */
      stateCode = 184U;

      /*  include state code: 184 ; */
      /* Entry Internal 'OpenDischrgNeg': '<S3>:3615' */
      S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMachine_IN_Confirm1;

      /* Entry 'Confirm1': '<S3>:3901' */
      TurnOff_INA2K();

      /* Entry Internal 'Confirm1': '<S3>:3901' */
      /* Transition: '<S3>:3898' */
      S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Wait;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;
    }
  }

  /* End of Inport: '<Root>/FastEndNormalFlag' */
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateMachine_lossvcu(void)
{
  /* During 'lossvcu': '<S3>:3886' */
  /* Transition: '<S3>:3888' */
  S223_StateMachine_DW.is_FastChrg = S223_StateMac_IN_OpenDischrgNeg;

  /* Entry 'OpenDischrgNeg': '<S3>:3615' */
  stateCode = 184U;

  /*  include state code: 184 ; */
  /* Entry Internal 'OpenDischrgNeg': '<S3>:3615' */
  S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMachine_IN_Confirm1;

  /* Entry 'Confirm1': '<S3>:3901' */
  TurnOff_INA2K();

  /* Entry Internal 'Confirm1': '<S3>:3901' */
  /* Transition: '<S3>:3898' */
  S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Wait;
  S223_StateMachine_DW.temporalCounter_i2 = 0UL;
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateMachine_lossvcu1(void)
{
  /* During 'lossvcu1': '<S3>:3890' */
  if (EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1 == 2) {
    /* Transition: '<S3>:3893' */
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_lossvcu;
  } else if (FastEndNormalFlag == 1) {
    /* Transition: '<S3>:3894' */
    S223_StateMachine_DW.is_FastChrg = S223_StateMachine_IN_normalend;
  } else {
    if (S223_StateMachine_DW.temporalCounter_i2 >= 640UL) {
      /* Transition: '<S3>:3892' */
      S223_StateMachine_DW.is_FastChrg = S223_StateMac_IN_OpenDischrgNeg;

      /* Entry 'OpenDischrgNeg': '<S3>:3615' */
      stateCode = 184U;

      /*  include state code: 184 ; */
      /* Entry Internal 'OpenDischrgNeg': '<S3>:3615' */
      S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMachine_IN_Confirm1;

      /* Entry 'Confirm1': '<S3>:3901' */
      TurnOff_INA2K();

      /* Entry Internal 'Confirm1': '<S3>:3901' */
      /* Transition: '<S3>:3898' */
      S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Wait;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;
    }
  }
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateMachine_FastChrg(void)
{
  /* During 'FastChrg': '<S3>:3365' */
  switch (S223_StateMachine_DW.is_FastChrg) {
   case S223_S_IN_CloseChrgPosRelay_Req:
    /* Inport: '<Root>/g_DC_CC2' incorporates:
     *  Inport: '<Root>/ChangerINError'
     *  Inport: '<Root>/DC_Start'
     */
    /* During 'CloseChrgPosRelay_Req': '<S3>:3551' */
    if ((EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1 == 1) && (g_DC_CC2 == 1) &&
        (ChangerINError == 0) && (DC_Start == 1)) {
      /* Transition: '<S3>:3558' */
      /* Exit Internal 'CloseChrgPosRelay_Req': '<S3>:3551' */
      S223_StateMachine_DW.is_CloseChrgPosRelay_Req =
        S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_FastChrg = S223_StateMach_IN_HeatAndCharge;

      /* Entry 'HeatAndCharge': '<S3>:3557' */
      stateCode = 170U;
      Time_CHG_Start();

      /* Entry Internal 'HeatAndCharge': '<S3>:3557' */
      /* Transition: '<S3>:3560' */
      S223_StateMachine_DW.is_HeatAndCharge = S223_StateMachine_IN_init_c;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;

      /* Entry 'init': '<S3>:3559' */
      turnOnSW_Power();
      REQ_TurnON_Insulation = 1U;

      /* 绝缘投切 */
    } else {
      switch (S223_StateMachine_DW.is_CloseChrgPosRelay_Req) {
       case S223_StateMachine_IN_Confirm:
        /* During 'Confirm': '<S3>:3710' */
        /* Transition: '<S3>:3712' */
        /* Transition: '<S3>:3718' */
        S223_StateMachine_DW.is_CloseChrgPosRelay_Req =
          S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_FastChrg = S223_St_IN_OpenChrgPosRelay_Req;

        /* Entry 'OpenChrgPosRelay_Req': '<S3>:3607' */
        stateCode = 180U;
        Time_CHG_Stop();
        BMS8_Byte1.Bit.F6_7_ChaPCtorClose = 2U;

        /* Entry Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
        S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
          S223_StateMachine_IN_Confirm;

        /* Entry 'Confirm': '<S3>:3868' */
        TurnOff_INHK();

        /* Entry Internal 'Confirm': '<S3>:3868' */
        /* Transition: '<S3>:3861' */
        S223_StateMachine_DW.is_Confirm = S223_StateMachine_IN_Wait;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        break;

       case S223_StateMachine_IN_Fault_f:
        /* During 'Fault': '<S3>:3708' */
        if (S223_StateMachine_DW.temporalCounter_i2 >= 200UL) {
          /* Transition: '<S3>:3711' */
          S223_StateMachine_DW.is_CloseChrgPosRelay_Req =
            S223_StateMachine_IN_Confirm;
        }
        break;

       default:
        /* Inport: '<Root>/g_DCChaPowerOffFlag' */
        /* During 'Wait': '<S3>:3706' */
        if ((g_FlagLevel == 4) || (g_DCChaPowerOffFlag == 1) || (g_DC_CC2 == 0) ||
            (ChangerINError == 1)) {
          /* Transition: '<S3>:3709' */
          S223_StateMachine_DW.is_CloseChrgPosRelay_Req =
            S223_StateMachine_IN_Fault_f;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        }
        break;
      }
    }
    break;

   case S223_StateMach_IN_HeatAndCharge:
    /* During 'HeatAndCharge': '<S3>:3557' */
    switch (S223_StateMachine_DW.is_HeatAndCharge) {
     case S223_StateMachine_IN_Delay:
      /* During 'Delay': '<S3>:3904' */
      if (S223_StateMachine_DW.temporalCounter_i2 >= 720UL) {
        /* Transition: '<S3>:3905' */
        S223_StateMachine_DW.is_HeatAndCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_FastChrg = S223_St_IN_OpenChrgPosRelay_Req;

        /* Entry 'OpenChrgPosRelay_Req': '<S3>:3607' */
        stateCode = 180U;
        Time_CHG_Stop();
        BMS8_Byte1.Bit.F6_7_ChaPCtorClose = 2U;

        /* Entry Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
        S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
          S223_StateMachine_IN_Confirm;

        /* Entry 'Confirm': '<S3>:3868' */
        TurnOff_INHK();

        /* Entry Internal 'Confirm': '<S3>:3868' */
        /* Transition: '<S3>:3861' */
        S223_StateMachine_DW.is_Confirm = S223_StateMachine_IN_Wait;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      }
      break;

     case S223_StateMach_IN_HeatandCharge:
      /* Inport: '<Root>/FastEndNormalFlag' incorporates:
       *  Inport: '<Root>/ChangerINError'
       *  Inport: '<Root>/OffState'
       *  Inport: '<Root>/g_DC_CC2'
       */
      /* During 'HeatandCharge': '<S3>:3564' */
      if (FastEndNormalFlag == 1) {
        /* Transition: '<S3>:3697' */
        /* Exit Internal 'HeatandCharge': '<S3>:3564' */
        /* Exit Internal 'HeatManage': '<S3>:3739' */
        /* Exit Internal 'Heat': '<S3>:3733' */
        S223_StateMachine_DW.is_CloseMain = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HeatManage = S223_StateMa_IN_NO_ACTIVE_CHILD;

        /* Exit 'HeatManage': '<S3>:3739' */
        TurnOff_INHK();
        S223_StateMachine_DW.is_HeatandCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HeatAndCharge = S223_StateMachi_IN_NomalEndWait;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      } else if ((g_DC_CC2 == 0) || (ChangerINError == 1) || (OffState == 1)) {
        /* Transition: '<S3>:3701' */
        /* Exit Internal 'HeatandCharge': '<S3>:3564' */
        /* Exit Internal 'HeatManage': '<S3>:3739' */
        /* Exit Internal 'Heat': '<S3>:3733' */
        S223_StateMachine_DW.is_CloseMain = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HeatManage = S223_StateMa_IN_NO_ACTIVE_CHILD;

        /* Exit 'HeatManage': '<S3>:3739' */
        TurnOff_INHK();
        S223_StateMachine_DW.is_HeatandCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HeatAndCharge = S223_StateMachine_IN_Delay;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      } else {
        GetDCTem();

        /* get temp of charge connector */
        /* During 'HeatManage': '<S3>:3739' */
        if (S223_StateMachine_DW.is_HeatManage == S223_StateMachine_IN_Heat) {
          /* Inport: '<Root>/g_CellHighestVol' */
          /* During 'Heat': '<S3>:3733' */
          if ((Tavg == 0) || (g_CellHighestVol > 3.65)) {
            /* Transition: '<S3>:3741' */
            /* Exit Internal 'Heat': '<S3>:3733' */
            S223_StateMachine_DW.is_CloseMain = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_HeatManage = S223_StateMachine_IN_wait_fpw;

            /* Entry 'wait': '<S3>:3731' */
            TurnOff_INHK();
          } else {
            switch (S223_StateMachine_DW.is_CloseMain) {
             case S223_StateMachine_IN_Charge:
              /* Outputs for Function Call SubSystem: '<S3>/FastChrgPowerAjust' */

              /* During 'Charge': '<S3>:3946' */
              /* Simulink Function 'FastChrgPowerAjust': '<S3>:3767' */
              FastChrgPowerAjust();

              /* End of Outputs for SubSystem: '<S3>/FastChrgPowerAjust' */
              TurnOff_INHK();
              HeatCurt = 0.0F;
              break;

             case S223_StateMachine_IN_Heat_o:
              /* During 'Heat': '<S3>:3937' */
              if ((Tavg > 45) && (Tavg <= 55)) {
                /* Transition: '<S3>:3952' */
                S223_StateMachine_DW.is_CloseMain =
                  S223_StateMa_IN_HeatAndCharge_a;
              } else {
                if (Tavg > 55) {
                  /* Transition: '<S3>:3953' */
                  S223_StateMachine_DW.is_CloseMain =
                    S223_StateMachine_IN_Charge;
                }
              }
              break;

             default:
              /* During 'HeatAndCharge': '<S3>:3942' */
              if (Tavg > 55) {
                /* Transition: '<S3>:3954' */
                S223_StateMachine_DW.is_CloseMain = S223_StateMachine_IN_Charge;
              } else if (Tavg <= 39) {
                /* Transition: '<S3>:3955' */
                S223_StateMachine_DW.is_CloseMain = S223_StateMachine_IN_Heat_o;

                /* Entry 'Heat': '<S3>:3937' */
                AskChaCur = 0.0F;
                TurnOn_INHK();
                HeatCurt = 2.13F;
              } else {
                /* Outputs for Function Call SubSystem: '<S3>/FastChrgPowerAjust' */

                /* Simulink Function 'FastChrgPowerAjust': '<S3>:3767' */
                FastChrgPowerAjust();

                /* End of Outputs for SubSystem: '<S3>/FastChrgPowerAjust' */
                TurnOn_INHK();
                HeatCurt = 2.13F;
              }
              break;
            }
          }
        } else {
          /* Inport: '<Root>/g_CellHighestVol' */
          /* During 'wait': '<S3>:3731' */
          if (~((Tavg == 0) || (g_CellHighestVol > 3.65)) != 0) {
            /* Transition: '<S3>:3734' */
            S223_StateMachine_DW.is_HeatManage = S223_StateMachine_IN_Heat;

            /* Inport: '<Root>/HeatFlag' */
            /* Entry Internal 'Heat': '<S3>:3733' */
            /* Transition: '<S3>:3940' */
            switch (HeatFlag) {
             case 1:
              /* Transition: '<S3>:3941' */
              S223_StateMachine_DW.is_CloseMain = S223_StateMachine_IN_Heat_o;

              /* Entry 'Heat': '<S3>:3937' */
              AskChaCur = 0.0F;
              TurnOn_INHK();
              HeatCurt = 2.13F;
              break;

             case 2:
              /* Transition: '<S3>:3944' */
              /* Transition: '<S3>:3945' */
              S223_StateMachine_DW.is_CloseMain =
                S223_StateMa_IN_HeatAndCharge_a;
              break;

             default:
              /* Transition: '<S3>:3948' */
              /* Transition: '<S3>:3949' */
              S223_StateMachine_DW.is_CloseMain = S223_StateMachine_IN_Charge;
              break;
            }

            /* End of Inport: '<Root>/HeatFlag' */
          }
        }
      }

      /* End of Inport: '<Root>/FastEndNormalFlag' */
      break;

     case S223_StateMachi_IN_NomalEndWait:
      /* During 'NomalEndWait': '<S3>:3696' */
      if (S223_StateMachine_DW.temporalCounter_i2 >= 300UL) {
        /* Transition: '<S3>:3698' */
        /* 2.4s */
        S223_StateMachine_DW.is_HeatAndCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_FastChrg = S223_St_IN_OpenChrgPosRelay_Req;

        /* Entry 'OpenChrgPosRelay_Req': '<S3>:3607' */
        stateCode = 180U;
        Time_CHG_Stop();
        BMS8_Byte1.Bit.F6_7_ChaPCtorClose = 2U;

        /* Entry Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
        S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
          S223_StateMachine_IN_Confirm;

        /* Entry 'Confirm': '<S3>:3868' */
        TurnOff_INHK();

        /* Entry Internal 'Confirm': '<S3>:3868' */
        /* Transition: '<S3>:3861' */
        S223_StateMachine_DW.is_Confirm = S223_StateMachine_IN_Wait;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
      }
      break;

     default:
      /* During 'init': '<S3>:3559' */
      if (S223_StateMachine_DW.temporalCounter_i2 >= 100UL) {
        /* Transition: '<S3>:3562' */
        S223_StateMachine_DW.is_HeatAndCharge = S223_StateMach_IN_HeatandCharge;

        /* Entry Internal 'HeatandCharge': '<S3>:3564' */
        /* Transition: '<S3>:3747' */
        S223_StateMachine_DW.is_HeatandCharge = S223_StateMachine_IN_HeatManage;

        /* Entry Internal 'HeatManage': '<S3>:3739' */
        /* Transition: '<S3>:3732' */
        S223_StateMachine_DW.is_HeatManage = S223_StateMachine_IN_wait_fpw;

        /* Entry 'wait': '<S3>:3731' */
        TurnOff_INHK();
      }
      break;
    }
    break;

   case S223_Sta_IN_HighVoltDetectPart2:
    /* Inport: '<Root>/g_DCChaPowerOffFlag' incorporates:
     *  Inport: '<Root>/ChangerINError'
     *  Inport: '<Root>/g_CellHighestVol'
     *  Inport: '<Root>/g_DC_CC2'
     */
    /* During 'HighVoltDetectPart2': '<S3>:3549' */
    /* //充电负极继电器粘连 */
    if ((g_ChaNRelayAdin == 1) || (g_MSDFault == 1) || (g_ChaNRelayDiscon == 1) ||
        (g_FlagLevel == 4) || (g_DCChaPowerOffFlag == 1) || (g_DC_CC2 == 0) ||
        (ChangerINError == 1) || (g_CellHighestVol >= 3.65) || (Tavg >= 94)) {
      /* Transition: '<S3>:3713' */
      /* Exit Internal 'HighVoltDetectPart2': '<S3>:3549' */
      /* Exit Internal 'CloseChrgNeg': '<S3>:3464' */
      S223_StateMachine_DW.is_CloseChrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_HighVoltDetectPart2 =
        S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'HighVoltDetectPart2Test': '<S3>:3405' */
      /* Exit Internal 'Fault1': '<S3>:3414' */
      S223_StateMachine_DW.is_Fault1_p = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
        S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'NotFault': '<S3>:3421' */
      S223_StateMachine_DW.is_NotFault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_FastChrg = S223_StateMac_IN_OpenDischrgNeg;

      /* Entry 'OpenDischrgNeg': '<S3>:3615' */
      stateCode = 184U;

      /*  include state code: 184 ; */
      /* Entry Internal 'OpenDischrgNeg': '<S3>:3615' */
      S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMachine_IN_Confirm1;

      /* Entry 'Confirm1': '<S3>:3901' */
      TurnOff_INA2K();

      /* Entry Internal 'Confirm1': '<S3>:3901' */
      /* Transition: '<S3>:3898' */
      S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Wait;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;
    } else {
      switch (S223_StateMachine_DW.is_HighVoltDetectPart2) {
       case S223_StateMachi_IN_CloseChrgNeg:
        /* During 'CloseChrgNeg': '<S3>:3464' */
        if (S223_StateMachine_DW.is_CloseChrgNeg ==
            S223_StateMachine_IN_CloseNeg) {
          /* During 'CloseNeg': '<S3>:3467' */
          if (S223_StateMachine_DW.temporalCounter_i2 >= 4UL) {
            /* Transition: '<S3>:3466' */
            S223_StateMachine_DW.is_CloseChrgNeg = S223_StateMachine_IN_Wait;
          }
        } else {
          /* During 'Wait': '<S3>:3468' */
          /* Transition: '<S3>:3547' */
          S223_StateMachine_DW.is_CloseChrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_HighVoltDetectPart2 =
            S2_IN_HighVoltDetectPart2Test_o;

          /* Inport: '<Root>/g_BatSysTotalVolV3' */
          /* Entry Internal 'HighVoltDetectPart2Test': '<S3>:3405' */
          /* Transition: '<S3>:3407' */
          if (g_BatSysTotalVolV3 < 100.0F) {
            /* Transition: '<S3>:3408' */
            S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
              S223_StateMachine_IN_Fault1;

            /* Entry Internal 'Fault1': '<S3>:3414' */
            /* Transition: '<S3>:3415' */
            S223_StateMachine_DW.is_Fault1_p = S223_StateMachine_IN_wait_f;
          } else {
            /* Transition: '<S3>:3409' */
            S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
              S223_StateMachine_IN_NotFault;

            /* Entry Internal 'NotFault': '<S3>:3421' */
            /* Transition: '<S3>:3422' */
            S223_StateMachine_DW.is_NotFault_d = S223_StateMachine_IN_wait_f;
          }
        }
        break;

       case S2_IN_HighVoltDetectPart2Test_o:
        /* During 'HighVoltDetectPart2Test': '<S3>:3405' */
        if (S223_StateMachine_DW.is_HighVoltDetectPart2Test_g ==
            S223_StateMachine_IN_Fault1) {
          /* Inport: '<Root>/g_BatSysTotalVolV3' */
          /* During 'Fault1': '<S3>:3414' */
          if (g_BatSysTotalVolV3 >= 100.0F) {
            /* Transition: '<S3>:3411' */
            /* Exit Internal 'Fault1': '<S3>:3414' */
            S223_StateMachine_DW.is_Fault1_p = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
              S223_StateMachine_IN_NotFault;

            /* Entry Internal 'NotFault': '<S3>:3421' */
            /* Transition: '<S3>:3422' */
            S223_StateMachine_DW.is_NotFault_d = S223_StateMachine_IN_wait_f;
          } else {
            switch (S223_StateMachine_DW.is_Fault1_p) {
             case S223_StateMachine_IN_Confirm:
              /* During 'Confirm': '<S3>:3419' */
              if (S223_StateMachine_DW.temporalCounter_i1 >= 12) {
                /* Transition: '<S3>:3417' */
                S223_StateMachine_DW.is_Fault1_p = S223_StateMachine_IN_Fault_f;

                /* Entry 'Fault': '<S3>:3420' */
                g_RelayPowerOffFault = 1U;
                fault_pc552_Byte7.Bit.F2_NRelayDisconFault = 1U;
                g_ChaNRelayDiscon = 1U;
                g_FlagLevel = 4U;
              }
              break;

             case S223_StateMachine_IN_Fault_f:
              /* During 'Fault': '<S3>:3420' */
              /* Transition: '<S3>:3410' */
              S223_StateMachine_DW.is_Fault1_p = S223_StateMa_IN_NO_ACTIVE_CHILD;
              S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
                S223_StateMa_IN_NO_ACTIVE_CHILD;

              /* Entry Internal 'HighVoltDetectPart2Test': '<S3>:3405' */
              /* Transition: '<S3>:3407' */
              if (g_BatSysTotalVolV3 < 100.0F) {
                /* Transition: '<S3>:3408' */
                S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
                  S223_StateMachine_IN_Fault1;

                /* Entry Internal 'Fault1': '<S3>:3414' */
                /* Transition: '<S3>:3415' */
                S223_StateMachine_DW.is_Fault1_p = S223_StateMachine_IN_wait_f;
              } else {
                /* Transition: '<S3>:3409' */
                S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
                  S223_StateMachine_IN_NotFault;

                /* Entry Internal 'NotFault': '<S3>:3421' */
                /* Transition: '<S3>:3422' */
                S223_StateMachine_DW.is_NotFault_d = S223_StateMachine_IN_wait_f;
              }
              break;

             default:
              /* During 'wait': '<S3>:3418' */
              if (g_BatSysTotalVolV3 < 100.0F) {
                /* Transition: '<S3>:3416' */
                S223_StateMachine_DW.is_Fault1_p = S223_StateMachine_IN_Confirm;
                S223_StateMachine_DW.temporalCounter_i1 = 0U;
              }
              break;
            }
          }
        } else {
          /* Inport: '<Root>/g_BatSysTotalVolV3' */
          /* During 'NotFault': '<S3>:3421' */
          if (g_BatSysTotalVolV3 < 100.0F) {
            /* Transition: '<S3>:3412' */
            /* Exit Internal 'NotFault': '<S3>:3421' */
            S223_StateMachine_DW.is_NotFault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
              S223_StateMachine_IN_Fault1;

            /* Entry Internal 'Fault1': '<S3>:3414' */
            /* Transition: '<S3>:3415' */
            S223_StateMachine_DW.is_Fault1_p = S223_StateMachine_IN_wait_f;
          } else {
            switch (S223_StateMachine_DW.is_NotFault_d) {
             case S223_StateMachine_IN_Confirm:
              /* During 'Confirm': '<S3>:3426' */
              if (S223_StateMachine_DW.temporalCounter_i1 >= 12) {
                /* Transition: '<S3>:3424' */
                S223_StateMachine_DW.is_NotFault_d =
                  S223_StateMachine_IN_Fault1_h;

                /* Entry 'Fault1': '<S3>:3427' */
                g_BMSSelfCheckCounter = 2U;

                /* 没有故障，自检计数器 */
                g_DischaNRelayDiscon = 0U;

                /* 负极继电器未断路 */
              }
              break;

             case S223_StateMachine_IN_Fault1_h:
              /* During 'Fault1': '<S3>:3427' */
              if ((g_DC_CC2 == 1) && (ChangerINError == 0)) {
                /* Transition: '<S3>:3552' */
                S223_StateMachine_DW.is_NotFault_d =
                  S223_StateMa_IN_NO_ACTIVE_CHILD;
                S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
                  S223_StateMa_IN_NO_ACTIVE_CHILD;
                S223_StateMachine_DW.is_HighVoltDetectPart2 =
                  S223_StateMa_IN_NO_ACTIVE_CHILD;
                S223_StateMachine_DW.is_FastChrg =
                  S223_S_IN_CloseChrgPosRelay_Req;

                /* Entry 'CloseChrgPosRelay_Req': '<S3>:3551' */
                stateCode = 144U;
                BMS8_Byte1.Bit.F6_7_ChaPCtorClose = 1U;

                /* Entry Internal 'CloseChrgPosRelay_Req': '<S3>:3551' */
                /* Transition: '<S3>:3707' */
                S223_StateMachine_DW.is_CloseChrgPosRelay_Req =
                  S223_StateMachine_IN_Wait_o;
              } else {
                /* Transition: '<S3>:3413' */
                S223_StateMachine_DW.is_NotFault_d =
                  S223_StateMa_IN_NO_ACTIVE_CHILD;
                S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
                  S223_StateMa_IN_NO_ACTIVE_CHILD;

                /* Entry Internal 'HighVoltDetectPart2Test': '<S3>:3405' */
                /* Transition: '<S3>:3407' */
                if (g_BatSysTotalVolV3 < 100.0F) {
                  /* Transition: '<S3>:3408' */
                  S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
                    S223_StateMachine_IN_Fault1;

                  /* Entry Internal 'Fault1': '<S3>:3414' */
                  /* Transition: '<S3>:3415' */
                  S223_StateMachine_DW.is_Fault1_p = S223_StateMachine_IN_wait_f;
                } else {
                  /* Transition: '<S3>:3409' */
                  S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
                    S223_StateMachine_IN_NotFault;

                  /* Entry Internal 'NotFault': '<S3>:3421' */
                  /* Transition: '<S3>:3422' */
                  S223_StateMachine_DW.is_NotFault_d =
                    S223_StateMachine_IN_wait_f;
                }
              }
              break;

             default:
              /* During 'wait': '<S3>:3425' */
              if (g_BatSysTotalVolV3 >= 100.0F) {
                /* Transition: '<S3>:3423' */
                S223_StateMachine_DW.is_NotFault_d =
                  S223_StateMachine_IN_Confirm;
                S223_StateMachine_DW.temporalCounter_i1 = 0U;
              }
              break;
            }
          }
        }
        break;

       default:
        /* During 'wait': '<S3>:3404' */
        /* Transition: '<S3>:3378' */
        /* Transition: '<S3>:3381' */
        S223_StateMachine_DW.is_HighVoltDetectPart2 =
          S223_StateMachi_IN_CloseChrgNeg;

        /* Entry 'CloseChrgNeg': '<S3>:3464' */
        TurnOn_INA2K();

        /* turn on charge negtive contactor */
        /* Entry Internal 'CloseChrgNeg': '<S3>:3464' */
        /* Transition: '<S3>:3465' */
        S223_StateMachine_DW.is_CloseChrgNeg = S223_StateMachine_IN_CloseNeg;
        S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        break;
      }
    }
    break;

   case IN_HighVoltagePowerOffDetection:
    S2_HighVoltagePowerOffDetection();
    break;

   case S223_St_IN_OpenChrgPosRelay_Req:
    S223_State_OpenChrgPosRelay_Req();
    break;

   case S223_StateMac_IN_OpenDischrgNeg:
    /* During 'OpenDischrgNeg': '<S3>:3615' */
    if (BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1 == 2) {
      /* Transition: '<S3>:3902' */
      /* Exit Internal 'OpenDischrgNeg': '<S3>:3615' */
      /* Exit Internal 'Confirm1': '<S3>:3901' */
      S223_StateMachine_DW.is_Confirm1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_FastChrg = IN_HighVoltagePowerOffDetection;

      /* Entry 'HighVoltagePowerOffDetection': '<S3>:3669' */
      stateCode = 186U;

      /*  include state code: 186 */
      /* Entry Internal 'HighVoltagePowerOffDetection': '<S3>:3669' */
      /* Transition: '<S3>:3664' */
      S223_StateMachine_DW.is_HighVoltagePowerOffDetecti_m =
        S223_StateMachine_IN_Wait;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;
    } else {
      /* During 'Confirm1': '<S3>:3901' */
      if ((S223_StateMachine_DW.is_Confirm1 != S223_StateMachine_IN_Confirm) &&
          (S223_StateMachine_DW.temporalCounter_i2 >= 4UL)) {
        /* During 'Wait': '<S3>:3900' */
        /* Transition: '<S3>:3899' */
        S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Confirm;
      } else {
        /* During 'Confirm': '<S3>:3897' */
      }
    }
    break;

   case S223_StateMachine_IN_cc2off:
    S223_StateMachine_cc2off();
    break;

   case S223_StateMachine_IN_lossvcu:
    S223_StateMachine_lossvcu();
    break;

   case S223_StateMachine_IN_lossvcu1:
    S223_StateMachine_lossvcu1();
    break;

   default:
    /* During 'normalend': '<S3>:3883' */
    /* Transition: '<S3>:3884' */
    S223_StateMachine_DW.is_FastChrg = S223_StateMac_IN_OpenDischrgNeg;

    /* Entry 'OpenDischrgNeg': '<S3>:3615' */
    stateCode = 184U;

    /*  include state code: 184 ; */
    /* Entry Internal 'OpenDischrgNeg': '<S3>:3615' */
    S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMachine_IN_Confirm1;

    /* Entry 'Confirm1': '<S3>:3901' */
    TurnOff_INA2K();

    /* Entry Internal 'Confirm1': '<S3>:3901' */
    /* Transition: '<S3>:3898' */
    S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Wait;
    S223_StateMachine_DW.temporalCounter_i2 = 0UL;
    break;
  }
}

/* Function for Chart: '<Root>/TaskControl' */
static void exit_internal_HighVoltageSelfTe(void)
{
  /* Exit Internal 'HighVoltageSelfTest': '<S3>:2524' */
  /* Exit Internal 'HighVoltageDetectPart1': '<S3>:2731' */
  S223_StateMachine_DW.is_HighVoltageDetectPart1 =
    S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HighVoltageSelfTest = S223_StateMa_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'HighVoltageDetectPart1Test': '<S3>:2654' */
  /* Exit Internal 'CheckNegRelay': '<S3>:2655' */
  /* Exit Internal 'Discharge': '<S3>:2684' */
  /* Exit Internal 'Fault': '<S3>:2657' */
  S223_StateMachine_DW.is_Fault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Discharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_CheckNegRelay = S223_StateMa_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'FastCharge': '<S3>:2697' */
  /* Exit Internal 'Fault': '<S3>:2696' */
  S223_StateMachine_DW.is_Fault_f = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_FastCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_active_CheckNegRelay = 0U;

  /* Exit Internal 'CheckMSD': '<S3>:2656' */
  /* Exit Internal 'Fault': '<S3>:2669' */
  S223_StateMachine_DW.is_Fault = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_CheckMSD = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_active_CheckMSD = 0U;
}

/* Function for Chart: '<Root>/TaskControl' */
static void S2_enter_internal_CheckNegRelay(void)
{
  /* Inport: '<Root>/g_BmsModeFlag' */
  /* Entry Internal 'CheckNegRelay': '<S3>:2655' */
  /* Transition: '<S3>:2700' */
  if (g_BmsModeFlag == (int16_T)FASTRECHARGING) {
    /* Transition: '<S3>:2703' */
    /* Transition: '<S3>:2702' */
    S223_StateMachine_DW.is_CheckNegRelay = S223_StateMachine_IN_FastCharge;

    /* Inport: '<Root>/g_BatSysTotalVolV3' */
    /* Entry Internal 'FastCharge': '<S3>:2697' */
    /* Transition: '<S3>:2688' */
    if (g_BatSysTotalVolV3 >= 300.0F) {
      /* Transition: '<S3>:2694' */
      S223_StateMachine_DW.is_FastCharge = S223_StateMachine_IN_Fault;

      /* Entry Internal 'Fault': '<S3>:2696' */
      /* Transition: '<S3>:2692' */
      S223_StateMachine_DW.is_Fault_f = S223_StateMachine_IN_Confirm_k;
      S223_StateMachine_DW.temporalCounter_i3 = 0U;
    } else {
      /* Transition: '<S3>:2686' */
      S223_StateMachine_DW.is_FastCharge = S223_StateMachine_IN_Normal;

      /* Entry 'Normal': '<S3>:2689' */
      g_BMSSelfCheckCounter = 1U;
    }

    /* End of Inport: '<Root>/g_BatSysTotalVolV3' */
  } else {
    /* Transition: '<S3>:2704' */
    S223_StateMachine_DW.is_CheckNegRelay = S223_StateMachine_IN_Discharge;

    /* Inport: '<Root>/g_BatSysTotalVolV2' */
    /* Entry Internal 'Discharge': '<S3>:2684' */
    /* Transition: '<S3>:2664' */
    if (g_BatSysTotalVolV2 >= 300.0F) {
      /* Transition: '<S3>:2665' */
      S223_StateMachine_DW.is_Discharge = S223_StateMachine_IN_Fault;

      /* Entry Internal 'Fault': '<S3>:2657' */
      /* Transition: '<S3>:2661' */
      S223_StateMachine_DW.is_Fault_d = S223_StateMachine_IN_Confirm;
      S223_StateMachine_DW.temporalCounter_i3 = 0U;
    } else {
      /* Transition: '<S3>:2666' */
      S223_StateMachine_DW.is_Discharge = S223_StateMachine_IN_Normal;

      /* Entry 'Normal': '<S3>:2658' */
      g_BMSSelfCheckCounter = 1U;
    }

    /* End of Inport: '<Root>/g_BatSysTotalVolV2' */
  }

  /* End of Inport: '<Root>/g_BmsModeFlag' */
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateM_HighVoltageSelfTest(void)
{
  /* Inport: '<Root>/g_DCChaPowerOffFlag' incorporates:
   *  Inport: '<Root>/ChangerINError'
   *  Inport: '<Root>/g_BmsModeFlag'
   *  Inport: '<Root>/g_CellHighestVol'
   *  Inport: '<Root>/g_DC_CC2'
   */
  /* During 'HighVoltageSelfTest': '<S3>:2524' */
  if (((g_ChaNRelayAdin == 1) || (g_MSDFault == 1) || (g_ChaNRelayDiscon == 1) ||
       (g_FlagLevel == 4) || (g_DCChaPowerOffFlag == 1) || (g_DC_CC2 == 0) ||
       (ChangerINError == 1) || (g_CellHighestVol >= 3.65) || (Tavg >= 94)) &&
      (g_BmsModeFlag == (int16_T)FASTRECHARGING)) {
    /* Transition: '<S3>:3725' */
    exit_internal_HighVoltageSelfTe();
    S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_FastChrg;
    S223_StateMachine_DW.is_FastChrg = S223_StateMac_IN_OpenDischrgNeg;

    /* Entry 'OpenDischrgNeg': '<S3>:3615' */
    stateCode = 184U;

    /*  include state code: 184 ; */
    /* Entry Internal 'OpenDischrgNeg': '<S3>:3615' */
    S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMachine_IN_Confirm1;

    /* Entry 'Confirm1': '<S3>:3901' */
    TurnOff_INA2K();

    /* Entry Internal 'Confirm1': '<S3>:3901' */
    /* Transition: '<S3>:3898' */
    S223_StateMachine_DW.is_Confirm1 = S223_StateMachine_IN_Wait;
    S223_StateMachine_DW.temporalCounter_i2 = 0UL;
  } else if (S223_StateMachine_DW.is_HighVoltageSelfTest ==
             S223__IN_HighVoltageDetectPart1) {
    /* Inport: '<Root>/g_ACC_ON' */
    /* During 'HighVoltageDetectPart1': '<S3>:2731' */
    if (((g_DischaNRelayAdin == 1) || (g_ChaNRelayAdin == 1) || (g_MSDFault == 1)
         || (g_FlagLevel == 4) || (g_PowerOffFlag == 1) || (g_ACC_ON == 0)) &&
        (g_BmsModeFlag == (int16_T)DISCHARGING)) {
      /* Transition: '<S3>:3259' */
      /* Transition: '<S3>:3254' */
      /* Exit Internal 'HighVoltageDetectPart1': '<S3>:2731' */
      S223_StateMachine_DW.is_HighVoltageDetectPart1 =
        S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_HighVoltageSelfTest =
        S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_DisChrg;
      S223_StateMachine_DW.is_DisChrg = IN_HighVoltagePowerOffDetection;

      /* Entry 'HighVoltagePowerOffDetection': '<S3>:2791' */
      stateCode = 46U;

      /*  include state code: 46 */
      /* Entry Internal 'HighVoltagePowerOffDetection': '<S3>:2791' */
      /* Transition: '<S3>:3250' */
      S223_StateMachine_DW.is_HighVoltagePowerOffDetection =
        S223_StateMachine_IN_Wait;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;

      /* Entry 'Wait': '<S3>:3247' */
      TurnOff_INFK();
      BMS8_Byte0.Bit.F2_3_BMSInterCtorState = 1U;
      BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 2U;
    } else if (S223_StateMachine_DW.is_HighVoltageDetectPart1 !=
               S223_StateMachine_IN_Fault) {
      /* During 'Normal': '<S3>:2732' */
      /* Transition: '<S3>:2757' */
      if (g_BmsModeFlag == (int16_T)FASTRECHARGING) {
        /* Transition: '<S3>:2774' */
        /* Transition: '<S3>:2775' */
        S223_StateMachine_DW.is_HighVoltageDetectPart1 =
          S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HighVoltageSelfTest =
          S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_FastChrg;

        /* Entry Internal 'FastChrg': '<S3>:3365' */
        /* Transition: '<S3>:3550' */
        S223_StateMachine_DW.is_FastChrg = S223_Sta_IN_HighVoltDetectPart2;

        /* Entry Internal 'HighVoltDetectPart2': '<S3>:3549' */
        /* Transition: '<S3>:3377' */
        S223_StateMachine_DW.is_HighVoltDetectPart2 =
          S223_StateMachine_IN_wait_f;
      } else {
        /* Transition: '<S3>:3234' */
        S223_StateMachine_DW.is_HighVoltageDetectPart1 =
          S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HighVoltageSelfTest =
          S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_DisChrg;

        /* Entry Internal 'DisChrg': '<S3>:2749' */
        /* Transition: '<S3>:2811' */
        S223_StateMachine_DW.is_DisChrg = S223_StateMachine_IN_wait;
      }
    } else {
      /* During 'Fault': '<S3>:2733' */
    }

    /* End of Inport: '<Root>/g_ACC_ON' */
  } else {
    /* During 'HighVoltageDetectPart1Test': '<S3>:2654' */
    if (S223_StateMachine_DW.temporalCounter_i4 >= 70U) {
      /* Transition: '<S3>:2738' */
      /* Exit Internal 'HighVoltageDetectPart1Test': '<S3>:2654' */
      /* Exit Internal 'CheckNegRelay': '<S3>:2655' */
      /* Exit Internal 'Discharge': '<S3>:2684' */
      /* Exit Internal 'Fault': '<S3>:2657' */
      S223_StateMachine_DW.is_Fault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_Discharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_CheckNegRelay = S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'FastCharge': '<S3>:2697' */
      /* Exit Internal 'Fault': '<S3>:2696' */
      S223_StateMachine_DW.is_Fault_f = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_FastCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_active_CheckNegRelay = 0U;

      /* Exit Internal 'CheckMSD': '<S3>:2656' */
      /* Exit Internal 'Fault': '<S3>:2669' */
      S223_StateMachine_DW.is_Fault = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_CheckMSD = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_active_CheckMSD = 0U;
      S223_StateMachine_DW.is_HighVoltageSelfTest =
        S223__IN_HighVoltageDetectPart1;

      /* Entry Internal 'HighVoltageDetectPart1': '<S3>:2731' */
      /* Transition: '<S3>:2735' */
      if ((g_MSDFault == 0) && (g_DischaNRelayAdin == 0) && (g_ChaNRelayAdin ==
           0)) {
        /* Transition: '<S3>:2736' */
        S223_StateMachine_DW.is_HighVoltageDetectPart1 =
          S223_StateMachine_IN_Normal;

        /* Entry 'Normal': '<S3>:2732' */
        g_BMSSelfCheckCounter = 1U;
      } else {
        /* Transition: '<S3>:2737' */
        S223_StateMachine_DW.is_HighVoltageDetectPart1 =
          S223_StateMachine_IN_Fault;
      }
    } else {
      /* During 'CheckMSD': '<S3>:2656' */
      if (S223_StateMachine_DW.is_CheckMSD == S223_StateMachine_IN_Fault) {
        /* Inport: '<Root>/g_BatSysTotalVolV1' */
        /* During 'Fault': '<S3>:2669' */
        if (g_BatSysTotalVolV1 >= 100.0F) {
          /* Transition: '<S3>:2680' */
          /* Exit Internal 'Fault': '<S3>:2669' */
          S223_StateMachine_DW.is_Fault = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Normal;
        } else if (S223_StateMachine_DW.is_Fault == S223_StateMachine_IN_Confirm)
        {
          /* During 'Confirm': '<S3>:2671' */
          if (S223_StateMachine_DW.temporalCounter_i2 >= 12UL) {
            /* Transition: '<S3>:2674' */
            S223_StateMachine_DW.is_Fault = S223_StateMa_IN_MSD_Malfunction;

            /* Entry 'MSD_Malfunction': '<S3>:2672' */
            g_RelayPowerOffFault = 1U;
            g_MSDFault = 1U;
            fault_pc552_Byte7.Bit.F0_MSDDisconFault = 1U;
            g_FlagLevel = 4U;
          }
        } else {
          /* During 'MSD_Malfunction': '<S3>:2672' */
          /* Transition: '<S3>:3328' */
          S223_StateMachine_DW.is_Fault = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_CheckMSD = S223_StateMa_IN_NO_ACTIVE_CHILD;

          /* Entry Internal 'CheckMSD': '<S3>:2656' */
          /* Transition: '<S3>:2676' */
          if (g_BatSysTotalVolV1 < 100.0F) {
            /* Transition: '<S3>:2677' */
            S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Fault;

            /* Entry Internal 'Fault': '<S3>:2669' */
            /* Transition: '<S3>:2673' */
            S223_StateMachine_DW.is_Fault = S223_StateMachine_IN_Confirm;
            S223_StateMachine_DW.temporalCounter_i2 = 0UL;
          } else {
            /* Transition: '<S3>:2678' */
            S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Normal;
          }
        }
      } else {
        /* Inport: '<Root>/g_BatSysTotalVolV1' */
        /* During 'Normal': '<S3>:2670' */
        if (g_BatSysTotalVolV1 < 100.0F) {
          /* Transition: '<S3>:2679' */
          S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Fault;

          /* Entry Internal 'Fault': '<S3>:2669' */
          /* Transition: '<S3>:2673' */
          S223_StateMachine_DW.is_Fault = S223_StateMachine_IN_Confirm;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        } else {
          /* Transition: '<S3>:3330' */
          S223_StateMachine_DW.is_CheckMSD = S223_StateMa_IN_NO_ACTIVE_CHILD;

          /* Entry Internal 'CheckMSD': '<S3>:2656' */
          /* Transition: '<S3>:2676' */
          if (g_BatSysTotalVolV1 < 100.0F) {
            /* Transition: '<S3>:2677' */
            S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Fault;

            /* Entry Internal 'Fault': '<S3>:2669' */
            /* Transition: '<S3>:2673' */
            S223_StateMachine_DW.is_Fault = S223_StateMachine_IN_Confirm;
            S223_StateMachine_DW.temporalCounter_i2 = 0UL;
          } else {
            /* Transition: '<S3>:2678' */
            S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Normal;
          }
        }
      }

      /* During 'CheckNegRelay': '<S3>:2655' */
      if (S223_StateMachine_DW.is_CheckNegRelay ==
          S223_StateMachine_IN_Discharge) {
        /* During 'Discharge': '<S3>:2684' */
        if (S223_StateMachine_DW.is_Discharge == S223_StateMachine_IN_Fault) {
          /* Inport: '<Root>/g_BatSysTotalVolV2' */
          /* During 'Fault': '<S3>:2657' */
          if (g_BatSysTotalVolV2 < 300.0F) {
            /* Transition: '<S3>:2668' */
            /* Exit Internal 'Fault': '<S3>:2657' */
            S223_StateMachine_DW.is_Fault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_Discharge = S223_StateMachine_IN_Normal;

            /* Entry 'Normal': '<S3>:2658' */
            g_BMSSelfCheckCounter = 1U;
          } else if (S223_StateMachine_DW.is_Fault_d ==
                     S223_StateMachine_IN_Confirm) {
            /* During 'Confirm': '<S3>:2659' */
            if (S223_StateMachine_DW.temporalCounter_i3 >= 12U) {
              /* Transition: '<S3>:2662' */
              S223_StateMachine_DW.is_Fault_d = IN_DischrgNegRelay_Malfunction;

              /* Entry 'DischrgNegRelay_Malfunction': '<S3>:2660' */
              g_RelayPowerOffFault = 1U;
              fault_pc552_Byte7.Bit.F1_NRelayAdinFault = 1U;
              BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 3U;
              g_FlagLevel = 4U;
              BMS9_Byte7.Bit.F4_BzerAlarm = 1U;
              g_DischaNRelayAdin = 1U;
            }
          } else {
            /* During 'DischrgNegRelay_Malfunction': '<S3>:2660' */
            /* Transition: '<S3>:3333' */
            S223_StateMachine_DW.is_Fault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_Discharge = S223_StateMa_IN_NO_ACTIVE_CHILD;

            /* Entry Internal 'Discharge': '<S3>:2684' */
            /* Transition: '<S3>:2664' */
            if (g_BatSysTotalVolV2 >= 300.0F) {
              /* Transition: '<S3>:2665' */
              S223_StateMachine_DW.is_Discharge = S223_StateMachine_IN_Fault;

              /* Entry Internal 'Fault': '<S3>:2657' */
              /* Transition: '<S3>:2661' */
              S223_StateMachine_DW.is_Fault_d = S223_StateMachine_IN_Confirm;
              S223_StateMachine_DW.temporalCounter_i3 = 0U;
            } else {
              /* Transition: '<S3>:2666' */
              S223_StateMachine_DW.is_Discharge = S223_StateMachine_IN_Normal;

              /* Entry 'Normal': '<S3>:2658' */
              g_BMSSelfCheckCounter = 1U;
            }
          }

          /* End of Inport: '<Root>/g_BatSysTotalVolV2' */
        } else {
          /* During 'Normal': '<S3>:2658' */
          /* Transition: '<S3>:3332' */
          S223_StateMachine_DW.is_Discharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_CheckNegRelay =
            S223_StateMa_IN_NO_ACTIVE_CHILD;
          S2_enter_internal_CheckNegRelay();
        }
      } else {
        /* During 'FastCharge': '<S3>:2697' */
        if (S223_StateMachine_DW.is_FastCharge == S223_StateMachine_IN_Fault) {
          /* Inport: '<Root>/g_BatSysTotalVolV3' */
          /* During 'Fault': '<S3>:2696' */
          if (g_BatSysTotalVolV3 < 300.0F) {
            /* Transition: '<S3>:2685' */
            /* Exit Internal 'Fault': '<S3>:2696' */
            S223_StateMachine_DW.is_Fault_f = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_FastCharge = S223_StateMachine_IN_Normal;

            /* Entry 'Normal': '<S3>:2689' */
            g_BMSSelfCheckCounter = 1U;
          } else if (S223_StateMachine_DW.is_Fault_f ==
                     S22_IN_ChrgNegRelay_Malfunction) {
            /* During 'ChrgNegRelay_Malfunction': '<S3>:2693' */
            /* Transition: '<S3>:3335' */
            S223_StateMachine_DW.is_Fault_f = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_FastCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_CheckNegRelay =
              S223_StateMa_IN_NO_ACTIVE_CHILD;
            S2_enter_internal_CheckNegRelay();
          } else {
            /* During 'Confirm': '<S3>:2695' */
            if (S223_StateMachine_DW.temporalCounter_i3 >= 12U) {
              /* Transition: '<S3>:2691' */
              S223_StateMachine_DW.is_Fault_f = S22_IN_ChrgNegRelay_Malfunction;

              /* Entry 'ChrgNegRelay_Malfunction': '<S3>:2693' */
              g_RelayPowerOffFault = 1U;
              fault_pc552_Byte7.Bit.F1_NRelayAdinFault = 1U;
              BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1 = 3U;
              g_FlagLevel = 4U;
              BMS9_Byte7.Bit.F4_BzerAlarm = 1U;
              BMS9_Byte7.Bit.F0_ChaCtorAdin1 = 1U;
              g_ChaNRelayAdin = 1U;
            }
          }

          /* End of Inport: '<Root>/g_BatSysTotalVolV3' */
        } else {
          /* During 'Normal': '<S3>:2689' */
          /* Transition: '<S3>:3721' */
          exit_internal_HighVoltageSelfTe();
          S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_FastChrg;

          /* Entry Internal 'FastChrg': '<S3>:3365' */
          /* Transition: '<S3>:3550' */
          S223_StateMachine_DW.is_FastChrg = S223_Sta_IN_HighVoltDetectPart2;

          /* Entry Internal 'HighVoltDetectPart2': '<S3>:3549' */
          /* Transition: '<S3>:3377' */
          S223_StateMachine_DW.is_HighVoltDetectPart2 =
            S223_StateMachine_IN_wait_f;
        }
      }
    }
  }

  /* End of Inport: '<Root>/g_DCChaPowerOffFlag' */
}

/* Function for Chart: '<Root>/TaskControl' */
static void S223_StateM_exit_internal_Nomal(void)
{
  /* Exit Internal 'Nomal': '<S3>:3796' */
  if (S223_StateMachine_DW.is_Nomal == S223_StateMachine_IN_FastChrg) {
    /* Exit Internal 'FastChrg': '<S3>:3365' */
    if (S223_StateMachine_DW.is_FastChrg == S223_StateMach_IN_HeatAndCharge) {
      /* Exit Internal 'HeatAndCharge': '<S3>:3557' */
      if (S223_StateMachine_DW.is_HeatAndCharge ==
          S223_StateMach_IN_HeatandCharge) {
        /* Exit Internal 'HeatandCharge': '<S3>:3564' */
        /* Exit Internal 'HeatManage': '<S3>:3739' */
        /* Exit Internal 'Heat': '<S3>:3733' */
        S223_StateMachine_DW.is_CloseMain = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HeatManage = S223_StateMa_IN_NO_ACTIVE_CHILD;

        /* Exit 'HeatManage': '<S3>:3739' */
        TurnOff_INHK();
        S223_StateMachine_DW.is_HeatandCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
        S223_StateMachine_DW.is_HeatAndCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
      } else {
        S223_StateMachine_DW.is_HeatAndCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
      }

      S223_StateMachine_DW.is_FastChrg = S223_StateMa_IN_NO_ACTIVE_CHILD;
    } else {
      /* Exit Internal 'CloseChrgPosRelay_Req': '<S3>:3551' */
      S223_StateMachine_DW.is_CloseChrgPosRelay_Req =
        S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_FastChrg = S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'HighVoltDetectPart2': '<S3>:3549' */
      /* Exit Internal 'CloseChrgNeg': '<S3>:3464' */
      S223_StateMachine_DW.is_CloseChrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_HighVoltDetectPart2 =
        S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'HighVoltDetectPart2Test': '<S3>:3405' */
      /* Exit Internal 'Fault1': '<S3>:3414' */
      S223_StateMachine_DW.is_Fault1_p = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
        S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'NotFault': '<S3>:3421' */
      S223_StateMachine_DW.is_NotFault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'HighVoltagePowerOffDetection': '<S3>:3669' */
      /* Exit Internal 'Detect': '<S3>:3673' */
      S223_StateMachine_DW.is_Detect_a = S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'Fault': '<S3>:3672' */
      S223_StateMachine_DW.is_Fault_j = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_HighVoltagePowerOffDetecti_m =
        S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'OpenChrgPosRelay_Req': '<S3>:3607' */
      /* Exit Internal 'Confirm': '<S3>:3868' */
      S223_StateMachine_DW.is_Confirm = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_OpenChrgPosRelay_Req =
        S223_StateMa_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'OpenDischrgNeg': '<S3>:3615' */
      /* Exit Internal 'Confirm1': '<S3>:3901' */
      S223_StateMachine_DW.is_Confirm1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMa_IN_NO_ACTIVE_CHILD;
    }

    S223_StateMachine_DW.is_Nomal = S223_StateMa_IN_NO_ACTIVE_CHILD;
  } else {
    /* Exit Internal 'DisChrg': '<S3>:2749' */
    /* Exit Internal 'CloseDischrgNeg': '<S3>:2764' */
    S223_StateMachine_DW.is_CloseDischrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_DisChrg = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Dischrg_Normal': '<S3>:2913' */
    /* Exit Internal 'CarFaultDone': '<S3>:2957' */
    /* Exit Internal 'FaultCheck': '<S3>:2958' */
    S223_StateMachine_DW.is_FaultCheck = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_CarFaultDone = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_Dischrg_Normal = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'HighVoltDetectPart2Test': '<S3>:2814' */
    /* Exit Internal 'Fault1': '<S3>:2815' */
    S223_StateMachine_DW.is_Fault1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_HighVoltDetectPart2Test =
      S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'NotFault': '<S3>:2816' */
    S223_StateMachine_DW.is_NotFault = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'HighVoltagePowerOffDetection': '<S3>:2791' */
    /* Exit Internal 'Detect': '<S3>:3248' */
    S223_StateMachine_DW.is_Detect = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Fault': '<S3>:2795' */
    S223_StateMachine_DW.is_Fault_a = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_HighVoltagePowerOffDetection =
      S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'LossVCU': '<S3>:3907' */
    S223_StateMachine_DW.is_LossVCU = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'OpenDischrgNeg': '<S3>:2996' */
    /* Exit Internal 'ACC_Off': '<S3>:3203' */
    S223_StateMachine_DW.is_ACC_Off = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'SmallCurrent': '<S3>:3216' */
    S223_StateMachine_DW.is_SmallCurrent = S223_StateMa_IN_NO_ACTIVE_CHILD;
    S223_StateMachine_DW.is_Nomal = S223_StateMa_IN_NO_ACTIVE_CHILD;
    exit_internal_HighVoltageSelfTe();

    /* Exit Internal 'InformStore': '<S3>:2561' */
    S223_StateMachine_DW.is_InformStore = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'LowVoltOff': '<S3>:3264' */
    S223_StateMachine_DW.is_LowVoltOff = S223_StateMa_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'LowVoltageSelfTest': '<S3>:2553' */
    S223_StateMachine_DW.is_LowVoltageSelfTest = S223_StateMa_IN_NO_ACTIVE_CHILD;
  }
}

/* System initialize for atomic system: '<Root>/TaskControl' */
void S223_StateMach_TaskControl_Init(void)
{
  S223_StateMachine_DW.is_Debugging = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Heat = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Nomal = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_DisChrg = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_CloseDischrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Dischrg_Normal = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_CarFaultDone = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_FaultCheck = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HighVoltDetectPart2Test =
    S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Fault1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_NotFault = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HighVoltagePowerOffDetection =
    S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Detect = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Fault_a = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_LossVCU = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_OpenDischrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_ACC_Off = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_SmallCurrent = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_FastChrg = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_CloseChrgPosRelay_Req =
    S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HeatAndCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HeatandCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HeatManage = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_CloseMain = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HighVoltDetectPart2 = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_CloseChrgNeg = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HighVoltDetectPart2Test_g =
    S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Fault1_p = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_NotFault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.temporalCounter_i1 = 0U;
  S223_StateMachine_DW.is_HighVoltagePowerOffDetecti_m =
    S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Detect_a = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Fault_j = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_OpenChrgPosRelay_Req = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Confirm = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_OpenDischrgNeg_l = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Confirm1 = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HighVoltageSelfTest = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_HighVoltageDetectPart1 =
    S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.temporalCounter_i4 = 0U;
  S223_StateMachine_DW.is_active_CheckMSD = 0U;
  S223_StateMachine_DW.is_CheckMSD = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Fault = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_active_CheckNegRelay = 0U;
  S223_StateMachine_DW.is_CheckNegRelay = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Discharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Fault_d = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_FastCharge = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_Fault_f = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.temporalCounter_i3 = 0U;
  S223_StateMachine_DW.is_InformStore = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_LowVoltOff = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.temporalCounter_i2 = 0UL;
  S223_StateMachine_DW.is_LowVoltageSelfTest = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.is_active_c3_S223_StateMachine = 0U;
  S223_StateMachine_DW.is_c3_S223_StateMachine = S223_StateMa_IN_NO_ACTIVE_CHILD;
  S223_StateMachine_DW.STATE12_142[0] = 12U;
  S223_StateMachine_DW.STATE12_142[1] = 12U;
  S223_StateMachine_DW.STATE12_142[2] = 142U;
  S223_StateMachine_DW.STATE11_141[0] = 11U;
  S223_StateMachine_DW.STATE11_141[1] = 11U;
  S223_StateMachine_DW.STATE11_141[2] = 141U;
  S223_StateMachine_DW.STATE47_187[0] = 47U;
  S223_StateMachine_DW.STATE47_187[1] = 47U;
  S223_StateMachine_DW.STATE47_187[2] = 187U;
  S223_StateMachine_DW.STATE48_188[0] = 48U;
  S223_StateMachine_DW.STATE48_188[1] = 48U;
  S223_StateMachine_DW.STATE48_188[2] = 188U;
  S223_StateMachine_DW.STATE10_140[0] = 10U;
  S223_StateMachine_DW.STATE10_140[1] = 10U;
  S223_StateMachine_DW.STATE10_140[2] = 140U;
  stateCode = 0U;
  g_BMSSelfCheckCounter = 0U;
  g_RelayPowerOffFault = 0U;
  g_DischaNRelayAdin = 0U;
  g_MSDFault = 0U;
  g_ChaNRelayAdin = 0U;
  g_DischaNRelayDiscon = 0U;
  g_MaxDischaCur = 0.0F;
  g_MaxFebCur = 0.0F;
  g_PowerOffFlag = 0U;
  g_ChaNRelayDiscon = 0U;
  HeatCurt = 0.0F;
  REQ_TurnON_Insulation = 0U;
}

/* Output and update for atomic system: '<Root>/TaskControl' */
void S223_StateMachine_TaskControl(void)
{
  if (S223_StateMachine_DW.temporalCounter_i2 < MAX_uint32_T) {
    S223_StateMachine_DW.temporalCounter_i2++;
  }

  if (S223_StateMachine_DW.temporalCounter_i3 < 15U) {
    S223_StateMachine_DW.temporalCounter_i3++;
  }

  if (S223_StateMachine_DW.temporalCounter_i4 < 127U) {
    S223_StateMachine_DW.temporalCounter_i4++;
  }

  /* Gateway: TaskControl */
  if (S223_StateMachine_DW.temporalCounter_i1 < 15U) {
    S223_StateMachine_DW.temporalCounter_i1++;
  }

  /* During: TaskControl */
  if (S223_StateMachine_DW.is_active_c3_S223_StateMachine == 0U) {
    /* Entry: TaskControl */
    S223_StateMachine_DW.is_active_c3_S223_StateMachine = 1U;

    /* Entry Internal: TaskControl */
    /* Transition: '<S3>:3797' */
    S223_StateMachine_DW.is_c3_S223_StateMachine = S223_StateMachine_IN_Nomal;

    /* Entry Internal 'Nomal': '<S3>:3796' */
    /* Transition: '<S3>:240' */
    S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_WakeUp;

    /* Inport: '<Root>/g_BmsModeFlag' */
    /* Entry 'WakeUp': '<S3>:322' */
    stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
      S223_StateMachine_DW.STATE10_140);

    /*  include state code: 10,140;
       StateCode=10; */
  } else if (S223_StateMachine_DW.is_c3_S223_StateMachine ==
             S223_StateMachine_IN_Debugging) {
    /* Inport: '<Root>/TestState' */
    /* During 'Debugging': '<S3>:300' */
    if (TestState == 0) {
      /* Transition: '<S3>:3799' */
      /* Exit Internal 'Debugging': '<S3>:300' */
      /* Exit Internal 'CloseMain': '<S3>:319' */
      S223_StateMachine_DW.is_Heat = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_Debugging = S223_StateMa_IN_NO_ACTIVE_CHILD;
      S223_StateMachine_DW.is_c3_S223_StateMachine = S223_StateMachine_IN_Nomal;

      /* Entry Internal 'Nomal': '<S3>:3796' */
      /* Transition: '<S3>:240' */
      S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_WakeUp;

      /* Inport: '<Root>/g_BmsModeFlag' */
      /* Entry 'WakeUp': '<S3>:322' */
      stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
        S223_StateMachine_DW.STATE10_140);

      /*  include state code: 10,140;
         StateCode=10; */
    } else {
      switch (S223_StateMachine_DW.is_Debugging) {
       case S223_StateMachine_IN_CloseMain:
        /* During 'CloseMain': '<S3>:319' */
        TaskGpioTest();

        /* During 'Delay': '<S3>:2493' */
        if (S223_StateMachine_DW.temporalCounter_i2 >= 80UL) {
          /* Transition: '<S3>:2495' */
          S223_StateMachine_DW.is_Heat = S223_StateMachine_IN_Delay;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;

          /* Entry 'Delay': '<S3>:2493' */
          GetDCTem();
        }
        break;

       case S223_StateMachine_IN_OpenHeater:
        /* During 'OpenHeater': '<S3>:315' */
        if (S223_StateMachine_DW.temporalCounter_i2 >= 8UL) {
          /* Transition: '<S3>:320' */
          S223_StateMachine_DW.is_Debugging = S223_StateMachine_IN_CloseMain;

          /* Entry 'CloseMain': '<S3>:319' */
          TurnOff_INA2K();
          turnOffSW_Power();

          /* Entry Internal 'CloseMain': '<S3>:319' */
          /* Transition: '<S3>:2494' */
          S223_StateMachine_DW.is_Heat = S223_StateMachine_IN_Delay;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;

          /* Entry 'Delay': '<S3>:2493' */
          GetDCTem();
        }
        break;

       default:
        /* During 'OpenNegRelay': '<S3>:313' */
        if (S223_StateMachine_DW.temporalCounter_i2 >= 4UL) {
          /* Transition: '<S3>:316' */
          S223_StateMachine_DW.is_Debugging = S223_StateMachine_IN_OpenHeater;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;

          /* Entry 'OpenHeater': '<S3>:315' */
          _FEED_COP();
          TurnOff_INHK();
        }
        break;
      }
    }
  } else {
    /* Inport: '<Root>/TestState' */
    /* During 'Nomal': '<S3>:3796' */
    if (TestState == 1) {
      /* Transition: '<S3>:3798' */
      S223_StateM_exit_internal_Nomal();
      S223_StateMachine_DW.is_c3_S223_StateMachine =
        S223_StateMachine_IN_Debugging;

      /* Entry 'Debugging': '<S3>:300' */
      stateCode = 179U;

      /* Entry Internal 'Debugging': '<S3>:300' */
      /* Transition: '<S3>:2500' */
      S223_StateMachine_DW.is_Debugging = S223_StateMachi_IN_OpenNegRelay;
      S223_StateMachine_DW.temporalCounter_i2 = 0UL;

      /* Entry 'OpenNegRelay': '<S3>:313' */
      BMS8_Byte0.Bit.F2_3_BMSInterCtorState = 1U;
      BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb = 2U;
    } else {
      switch (S223_StateMachine_DW.is_Nomal) {
       case S223_StateMachine_IN_DisChrg:
        S223_StateMachine_DisChrg();
        break;

       case S223_StateMachine_IN_FastChrg:
        S223_StateMachine_FastChrg();
        break;

       case S223_Sta_IN_HighVoltageSelfTest:
        S223_StateM_HighVoltageSelfTest();
        break;

       case S223_StateMachin_IN_InformStore:
        /* During 'InformStore': '<S3>:2561' */
        if (S223_StateMachine_DW.is_InformStore ==
            S223_StateMac_IN_CloseMainPower) {
          /* During 'CloseMainPower': '<S3>:2560' */
          /* Transition: '<S3>:3265' */
          S223_StateMachine_DW.is_InformStore = S223_StateMa_IN_NO_ACTIVE_CHILD;
          S223_StateMachine_DW.is_Nomal = S223_StateMachine_IN_LowVoltOff;

          /* Inport: '<Root>/g_BmsModeFlag' */
          /* Entry 'LowVoltOff': '<S3>:3264' */
          stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
            S223_StateMachine_DW.STATE48_188);

          /*  include state code: 48  188; */
          /* Entry Internal 'LowVoltOff': '<S3>:3264' */
          /* Transition: '<S3>:3263' */
          S223_StateMachine_DW.is_LowVoltOff = S223_StateMachine_IN_init;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        } else {
          /* During 'init': '<S3>:2557' */
          if (S223_StateMachine_DW.temporalCounter_i2 >= 8UL) {
            /* Transition: '<S3>:2558' */
            S223_StateMachine_DW.is_InformStore =
              S223_StateMac_IN_CloseMainPower;

            /* Entry 'CloseMainPower': '<S3>:2560' */
            g_BMSSelfCheckCounter = 0U;
            StoreSysVariable();
            StoreSocRealvalue();
          }
        }
        break;

       case S223_StateMachine_IN_LowVoltOff:
        /* During 'LowVoltOff': '<S3>:3264' */
        if ((S223_StateMachine_DW.is_LowVoltOff !=
             S223_StateMac_IN_CloseMainPower) &&
            (S223_StateMachine_DW.temporalCounter_i2 >= 8UL)) {
          /* During 'init': '<S3>:3261' */
          /* Transition: '<S3>:3260' */
          S223_StateMachine_DW.is_LowVoltOff = S223_StateMac_IN_CloseMainPower;

          /* Entry 'CloseMainPower': '<S3>:3262' */
          turnOffSW_Power();
        } else {
          /* During 'CloseMainPower': '<S3>:3262' */
        }
        break;

       case S223_Stat_IN_LowVoltageSelfTest:
        /* During 'LowVoltageSelfTest': '<S3>:2553' */
        if (S223_StateMachine_DW.is_LowVoltageSelfTest ==
            S223_StateMachine_IN_Discharge) {
          /* Inport: '<Root>/g_ACC_ON' */
          /* During 'Discharge': '<S3>:3308' */
          if ((g_FlagLevel == 4) || (g_PowerOffFlag == 1) || (g_ACC_ON == 0)) {
            /* Transition: '<S3>:2569' */
            /* Transition: '<S3>:2570' */
            S223_StateMachine_DW.is_LowVoltageSelfTest =
              S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_Nomal = S223_StateMachin_IN_InformStore;

            /* Inport: '<Root>/g_BmsModeFlag' */
            /* Entry 'InformStore': '<S3>:2561' */
            stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
              S223_StateMachine_DW.STATE47_187);

            /* StateCode=47;
               include state code: 47  187; */
            /* Entry Internal 'InformStore': '<S3>:2561' */
            /* Transition: '<S3>:2559' */
            S223_StateMachine_DW.is_InformStore = S223_StateMachine_IN_init;
            S223_StateMachine_DW.temporalCounter_i2 = 0UL;
          } else {
            /* Transition: '<S3>:3314' */
            S223_StateMachine_DW.is_LowVoltageSelfTest =
              S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_Nomal = S223_Sta_IN_HighVoltageSelfTest;

            /* Inport: '<Root>/g_BmsModeFlag' */
            /* Entry 'HighVoltageSelfTest': '<S3>:2524' */
            stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
              S223_StateMachine_DW.STATE12_142);

            /*  include state code: 12  142;
               StateCode=12; */
            /* Entry Internal 'HighVoltageSelfTest': '<S3>:2524' */
            /* Transition: '<S3>:3929' */
            S223_StateMachine_DW.is_HighVoltageSelfTest =
              S_IN_HighVoltageDetectPart1Test;
            S223_StateMachine_DW.temporalCounter_i4 = 0U;

            /* Entry Internal 'HighVoltageDetectPart1Test': '<S3>:2654' */
            S223_StateMachine_DW.is_active_CheckMSD = 1U;

            /* Inport: '<Root>/g_BatSysTotalVolV1' */
            /* Entry Internal 'CheckMSD': '<S3>:2656' */
            /* Transition: '<S3>:2676' */
            if (g_BatSysTotalVolV1 < 100.0F) {
              /* Transition: '<S3>:2677' */
              S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Fault;

              /* Entry Internal 'Fault': '<S3>:2669' */
              /* Transition: '<S3>:2673' */
              S223_StateMachine_DW.is_Fault = S223_StateMachine_IN_Confirm;
              S223_StateMachine_DW.temporalCounter_i2 = 0UL;
            } else {
              /* Transition: '<S3>:2678' */
              S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Normal;
            }

            S223_StateMachine_DW.is_active_CheckNegRelay = 1U;
            S2_enter_internal_CheckNegRelay();
          }

          /* End of Inport: '<Root>/g_ACC_ON' */
        } else {
          /* Inport: '<Root>/g_DCChaPowerOffFlag' incorporates:
           *  Inport: '<Root>/ChangerINError'
           *  Inport: '<Root>/g_DC_CC2'
           */
          /* During 'FastCharg': '<S3>:3309' */
          /* Transition: '<S3>:3816' */
          /*              */
          if ((g_DischaNRelayAdin == 1) || (g_ChaNRelayAdin == 1) || (g_MSDFault
               == 1) || (g_RelayPowerOffFault == 1) || (g_FlagLevel == 4) ||
              (g_DCChaPowerOffFlag == 1) || (g_DC_CC2 == 0) || (ChangerINError ==
               1)) {
            /* Transition: '<S3>:2610' */
            /* Transition: '<S3>:2611' */
            S223_StateMachine_DW.is_LowVoltageSelfTest =
              S223_StateMa_IN_NO_ACTIVE_CHILD;
            S223_StateMachine_DW.is_Nomal = S223_StateMachin_IN_InformStore;

            /* Inport: '<Root>/g_BmsModeFlag' */
            /* Entry 'InformStore': '<S3>:2561' */
            stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
              S223_StateMachine_DW.STATE47_187);

            /* StateCode=47;
               include state code: 47  187; */
            /* Entry Internal 'InformStore': '<S3>:2561' */
            /* Transition: '<S3>:2559' */
            S223_StateMachine_DW.is_InformStore = S223_StateMachine_IN_init;
            S223_StateMachine_DW.temporalCounter_i2 = 0UL;
          } else {
            /* Transition: '<S3>:3818' */
            if (g_DC_CC2 == 1) {
              /* Transition: '<S3>:3315' */
              S223_StateMachine_DW.is_LowVoltageSelfTest =
                S223_StateMa_IN_NO_ACTIVE_CHILD;
              S223_StateMachine_DW.is_Nomal = S223_Sta_IN_HighVoltageSelfTest;

              /* Inport: '<Root>/g_BmsModeFlag' */
              /* Entry 'HighVoltageSelfTest': '<S3>:2524' */
              stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
                S223_StateMachine_DW.STATE12_142);

              /*  include state code: 12  142;
                 StateCode=12; */
              /* Entry Internal 'HighVoltageSelfTest': '<S3>:2524' */
              /* Transition: '<S3>:3929' */
              S223_StateMachine_DW.is_HighVoltageSelfTest =
                S_IN_HighVoltageDetectPart1Test;
              S223_StateMachine_DW.temporalCounter_i4 = 0U;

              /* Entry Internal 'HighVoltageDetectPart1Test': '<S3>:2654' */
              S223_StateMachine_DW.is_active_CheckMSD = 1U;

              /* Inport: '<Root>/g_BatSysTotalVolV1' */
              /* Entry Internal 'CheckMSD': '<S3>:2656' */
              /* Transition: '<S3>:2676' */
              if (g_BatSysTotalVolV1 < 100.0F) {
                /* Transition: '<S3>:2677' */
                S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Fault;

                /* Entry Internal 'Fault': '<S3>:2669' */
                /* Transition: '<S3>:2673' */
                S223_StateMachine_DW.is_Fault = S223_StateMachine_IN_Confirm;
                S223_StateMachine_DW.temporalCounter_i2 = 0UL;
              } else {
                /* Transition: '<S3>:2678' */
                S223_StateMachine_DW.is_CheckMSD = S223_StateMachine_IN_Normal;
              }

              S223_StateMachine_DW.is_active_CheckNegRelay = 1U;
              S2_enter_internal_CheckNegRelay();
            }
          }

          /* End of Inport: '<Root>/g_DCChaPowerOffFlag' */
        }
        break;

       default:
        /* During 'WakeUp': '<S3>:322' */
        if (g_RelayPowerOffFault != 0) {
          /* Transition: '<S3>:2565' */
          /* negtive relay power off */
          /* Transition: '<S3>:2566' */
          S223_StateMachine_DW.is_Nomal = S223_StateMachin_IN_InformStore;

          /* Inport: '<Root>/g_BmsModeFlag' */
          /* Entry 'InformStore': '<S3>:2561' */
          stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
            S223_StateMachine_DW.STATE47_187);

          /* StateCode=47;
             include state code: 47  187; */
          /* Entry Internal 'InformStore': '<S3>:2561' */
          /* Transition: '<S3>:2559' */
          S223_StateMachine_DW.is_InformStore = S223_StateMachine_IN_init;
          S223_StateMachine_DW.temporalCounter_i2 = 0UL;
        } else {
          /* Transition: '<S3>:3930' */
          S223_StateMachine_DW.is_Nomal = S223_Stat_IN_LowVoltageSelfTest;

          /* Inport: '<Root>/g_BmsModeFlag' */
          /* Entry 'LowVoltageSelfTest': '<S3>:2553' */
          stateCode = S223_StateMachine_updateState(g_BmsModeFlag,
            S223_StateMachine_DW.STATE11_141);

          /*  include state code: 11,141;
             StateCode=11; */
          /* Entry Internal 'LowVoltageSelfTest': '<S3>:2553' */
          /* Transition: '<S3>:3306' */
          if (g_BmsModeFlag == (int16_T)DISCHARGING) {
            /* Transition: '<S3>:3310' */
            S223_StateMachine_DW.is_LowVoltageSelfTest =
              S223_StateMachine_IN_Discharge;
          } else {
            /* Transition: '<S3>:3312' */
            /* Transition: '<S3>:3311' */
            S223_StateMachine_DW.is_LowVoltageSelfTest =
              S223_StateMachine_IN_FastCharg;
          }
        }
        break;
      }
    }
  }
}

/* Model step function */
void S223_StateMachine_step(void)
{
  /* Chart: '<Root>/TaskControl' */
  S223_StateMachine_TaskControl();

  /* Outputs for Atomic SubSystem: '<Root>/PowerOnSOCAjust' */
  S223_StateMachi_PowerOnSOCAjust();

  /* End of Outputs for SubSystem: '<Root>/PowerOnSOCAjust' */

  /* Outputs for Atomic SubSystem: '<Root>/ChargeEndSOCAjust' */
  S223_StateMac_ChargeEndSOCAjust();

  /* End of Outputs for SubSystem: '<Root>/ChargeEndSOCAjust' */
}

/* Model initialize function */
void S223_StateMachine_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(S223_StateMachine_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &S223_StateMachine_B), 0,
                sizeof(B_S223_StateMachine_T));

  /* states (dwork) */
  (void) memset((void *)&S223_StateMachine_DW, 0,
                sizeof(DW_S223_StateMachine_T));

  /* SystemInitialize for Chart: '<Root>/TaskControl' */
  S223_StateMach_TaskControl_Init();
}

/* Model terminate function */
void S223_StateMachine_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
