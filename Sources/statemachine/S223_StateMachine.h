/*
 * File: S223_StateMachine.h
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

#ifndef RTW_HEADER_S223_StateMachine_h_
#define RTW_HEADER_S223_StateMachine_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <stddef.h>
#include <string.h>
#ifndef S223_StateMachine_COMMON_INCLUDES_
# define S223_StateMachine_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* S223_StateMachine_COMMON_INCLUDES_ */



/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_S223_StateMachine_T RT_MODEL_S223_StateMachine_T;

/* user code (top of header file) */

#ifndef DEFINED_TYPEDEF_FOR_modeFlag_
#define DEFINED_TYPEDEF_FOR_modeFlag_

typedef enum {
  DISCHARGING = 0,                     /* Default value */
  FASTRECHARGING,
  RECHARGING
} modeFlag;

#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T SOC;                        /* '<Root>/TaskControl' */
  real32_T T;                          /* '<Root>/TaskControl' */
  real32_T SOC_l;                      /* '<Root>/TaskControl' */
  real32_T T_i;                        /* '<Root>/TaskControl' */
  real32_T Switch1;                    /* '<S4>/Switch1' */
  real32_T Switch1_n;                  /* '<S10>/Switch1' */
  uint8_T Normal2Zero_flg;             /* '<Root>/TaskControl' */
  uint8_T Normal2Half_flg;             /* '<Root>/TaskControl' */
  uint8_T Normal2Zero_flg_m;           /* '<Root>/TaskControl' */
  uint8_T Normal2Half_flg_g;           /* '<Root>/TaskControl' */
} B_S223_StateMachine_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S4>/UnitDelay1' */
  real_T UnitDelay1_DSTATE_f;          /* '<S10>/UnitDelay1' */
  uint32_T temporalCounter_i2;         /* '<Root>/TaskControl' */
  uint8_T is_active_c3_S223_StateMachine;/* '<Root>/TaskControl' */
  uint8_T is_c3_S223_StateMachine;     /* '<Root>/TaskControl' */
  uint8_T is_Nomal;                    /* '<Root>/TaskControl' */
  uint8_T is_LowVoltageSelfTest;       /* '<Root>/TaskControl' */
  uint8_T is_HighVoltageSelfTest;      /* '<Root>/TaskControl' */
  uint8_T is_CheckMSD;                 /* '<Root>/TaskControl' */
  uint8_T is_active_CheckMSD;          /* '<Root>/TaskControl' */
  uint8_T is_Fault;                    /* '<Root>/TaskControl' */
  uint8_T is_CheckNegRelay;            /* '<Root>/TaskControl' */
  uint8_T is_active_CheckNegRelay;     /* '<Root>/TaskControl' */
  uint8_T is_Discharge;                /* '<Root>/TaskControl' */
  uint8_T is_Fault_d;                  /* '<Root>/TaskControl' */
  uint8_T is_FastCharge;               /* '<Root>/TaskControl' */
  uint8_T is_Fault_f;                  /* '<Root>/TaskControl' */
  uint8_T is_HighVoltageDetectPart1;   /* '<Root>/TaskControl' */
  uint8_T is_InformStore;              /* '<Root>/TaskControl' */
  uint8_T is_DisChrg;                  /* '<Root>/TaskControl' */
  uint8_T is_HighVoltDetectPart2Test;  /* '<Root>/TaskControl' */
  uint8_T is_Fault1;                   /* '<Root>/TaskControl' */
  uint8_T is_NotFault;                 /* '<Root>/TaskControl' */
  uint8_T is_Dischrg_Normal;           /* '<Root>/TaskControl' */
  uint8_T is_CarFaultDone;             /* '<Root>/TaskControl' */
  uint8_T is_FaultCheck;               /* '<Root>/TaskControl' */
  uint8_T is_CloseDischrgNeg;          /* '<Root>/TaskControl' */
  uint8_T is_OpenDischrgNeg;           /* '<Root>/TaskControl' */
  uint8_T is_ACC_Off;                  /* '<Root>/TaskControl' */
  uint8_T is_SmallCurrent;             /* '<Root>/TaskControl' */
  uint8_T is_LossVCU;                  /* '<Root>/TaskControl' */
  uint8_T is_HighVoltagePowerOffDetection;/* '<Root>/TaskControl' */
  uint8_T is_Detect;                   /* '<Root>/TaskControl' */
  uint8_T is_Fault_a;                  /* '<Root>/TaskControl' */
  uint8_T is_FastChrg;                 /* '<Root>/TaskControl' */
  uint8_T is_HighVoltDetectPart2;      /* '<Root>/TaskControl' */
  uint8_T is_HighVoltDetectPart2Test_g;/* '<Root>/TaskControl' */
  uint8_T is_Fault1_p;                 /* '<Root>/TaskControl' */
  uint8_T is_NotFault_d;               /* '<Root>/TaskControl' */
  uint8_T is_CloseChrgNeg;             /* '<Root>/TaskControl' */
  uint8_T is_HeatAndCharge;            /* '<Root>/TaskControl' */
  uint8_T is_HeatandCharge;            /* '<Root>/TaskControl' */
  uint8_T is_HeatManage;               /* '<Root>/TaskControl' */
  uint8_T is_CloseMain;                /* '<Root>/TaskControl' */
  uint8_T is_CloseChrgPosRelay_Req;    /* '<Root>/TaskControl' */
  uint8_T is_OpenDischrgNeg_l;         /* '<Root>/TaskControl' */
  uint8_T is_Confirm1;                 /* '<Root>/TaskControl' */
  uint8_T is_HighVoltagePowerOffDetecti_m;/* '<Root>/TaskControl' */
  uint8_T is_Detect_a;                 /* '<Root>/TaskControl' */
  uint8_T is_Fault_j;                  /* '<Root>/TaskControl' */
  uint8_T is_OpenChrgPosRelay_Req;     /* '<Root>/TaskControl' */
  uint8_T is_Confirm;                  /* '<Root>/TaskControl' */
  uint8_T is_LowVoltOff;               /* '<Root>/TaskControl' */
  uint8_T is_Debugging;                /* '<Root>/TaskControl' */
  uint8_T is_Heat;                     /* '<Root>/TaskControl' */
  uint8_T STATE12_142[3];              /* '<Root>/TaskControl' */
  uint8_T STATE11_141[3];              /* '<Root>/TaskControl' */
  uint8_T STATE47_187[3];              /* '<Root>/TaskControl' */
  uint8_T STATE48_188[3];              /* '<Root>/TaskControl' */
  uint8_T STATE10_140[3];              /* '<Root>/TaskControl' */
  uint8_T temporalCounter_i1;          /* '<Root>/TaskControl' */
  uint8_T temporalCounter_i3;          /* '<Root>/TaskControl' */
  uint8_T temporalCounter_i4;          /* '<Root>/TaskControl' */
} DW_S223_StateMachine_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable3_maxIndex
   * Referenced by: '<S1>/2-D Lookup Table3'
   */
  uint32_T uDLookupTable3_maxIndex[2];

  /* Computed Parameter: linearizationSOF_maxIndex
   * Referenced by: '<S41>/linearizationSOF'
   */
  uint32_T linearizationSOF_maxIndex[2];

  /* Computed Parameter: linearizationSOF_maxIndex_a
   * Referenced by: '<S36>/linearizationSOF'
   */
  uint32_T linearizationSOF_maxIndex_a[2];

  /* Computed Parameter: uDLookupTable3_maxIndex_j
   * Referenced by: '<S6>/2-D Lookup Table3'
   */
  uint32_T uDLookupTable3_maxIndex_j[2];
} ConstP_S223_StateMachine_T;

/* Real-time Model Data Structure */
struct tag_RTM_S223_StateMachine_T {
  const char_T *errorStatus;
};



/* Block signals (auto storage) */
extern B_S223_StateMachine_T S223_StateMachine_B;

/* Block states (auto storage) */
extern DW_S223_StateMachine_T S223_StateMachine_DW;

/* Constant parameters (auto storage) */
extern const ConstP_S223_StateMachine_T S223_StateMachine_ConstP;

/* Model entry point functions */
extern void S223_StateMachine_initialize(void);
extern void S223_StateMachine_step(void);
extern void S223_StateMachine_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern real32_T CAP_CONST_CAL;
extern real32_T DisChargeCurrentTable[132];/* maximum discharge current, row: SOC, collumn: T  */
extern real32_T Factor_ChargeEndSOCAjust[64];
extern real32_T Factor_PowerOnSOCAjust[8];
extern real32_T FastChargeCurrentTable[168];
extern real32_T FeedBackCurrentTable[108];/* maximum discharge current, row: SOC, collumn: T  */
extern real32_T SOC_Discharge[11];
extern real32_T SOC_FastCharge[12];
extern real32_T SOC_Feedback[12];      /* row for max dicharge current table */
extern real32_T T_ChargeEndSOCAjust[8];
extern real32_T T_Discharge[12];       /* collumn for max discharge current table */
extern real32_T T_Facdback[9];
extern real32_T T_FastCharge[14];
extern real32_T T_PowerOnSOCAjust[8];
extern real32_T V_CellLowest[8];

/* Real-time Model object */
extern RT_MODEL_S223_StateMachine_T *const S223_StateMachine_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'S223_StateMachine'
 * '<S1>'   : 'S223_StateMachine/ChargeEndSOCAjust'
 * '<S2>'   : 'S223_StateMachine/PowerOnSOCAjust'
 * '<S3>'   : 'S223_StateMachine/TaskControl'
 * '<S4>'   : 'S223_StateMachine/TaskControl/BigDischargePowerAdjust'
 * '<S5>'   : 'S223_StateMachine/TaskControl/ChargeEndSOCAjust'
 * '<S6>'   : 'S223_StateMachine/TaskControl/FastChrgPowerAjust'
 * '<S7>'   : 'S223_StateMachine/TaskControl/GetDCTem'
 * '<S8>'   : 'S223_StateMachine/TaskControl/HeatAndChargeControl'
 * '<S9>'   : 'S223_StateMachine/TaskControl/PowerOnSOCAjust'
 * '<S10>'  : 'S223_StateMachine/TaskControl/PulseRechargePowerAdjust'
 * '<S11>'  : 'S223_StateMachine/TaskControl/SocEndDischargeAdjust'
 * '<S12>'  : 'S223_StateMachine/TaskControl/StoreSocRealvalue'
 * '<S13>'  : 'S223_StateMachine/TaskControl/StoreSysVariable'
 * '<S14>'  : 'S223_StateMachine/TaskControl/TaskGpioTest'
 * '<S15>'  : 'S223_StateMachine/TaskControl/TaskInsulation'
 * '<S16>'  : 'S223_StateMachine/TaskControl/TaskRechargeAC'
 * '<S17>'  : 'S223_StateMachine/TaskControl/TaskRechargeDC'
 * '<S18>'  : 'S223_StateMachine/TaskControl/TurnOff_INA2K'
 * '<S19>'  : 'S223_StateMachine/TaskControl/TurnOff_INBK'
 * '<S20>'  : 'S223_StateMachine/TaskControl/TurnOff_INFK'
 * '<S21>'  : 'S223_StateMachine/TaskControl/TurnOff_INHK'
 * '<S22>'  : 'S223_StateMachine/TaskControl/TurnOff_INZK'
 * '<S23>'  : 'S223_StateMachine/TaskControl/TurnOn_INA2K'
 * '<S24>'  : 'S223_StateMachine/TaskControl/TurnOn_INBK'
 * '<S25>'  : 'S223_StateMachine/TaskControl/TurnOn_INFK'
 * '<S26>'  : 'S223_StateMachine/TaskControl/TurnOn_INHK'
 * '<S27>'  : 'S223_StateMachine/TaskControl/TurnOn_INZK'
 * '<S28>'  : 'S223_StateMachine/TaskControl/_FEED_COP'
 * '<S29>'  : 'S223_StateMachine/TaskControl/errorCurrSensorInitial'
 * '<S30>'  : 'S223_StateMachine/TaskControl/input6_state'
 * '<S31>'  : 'S223_StateMachine/TaskControl/inputH_state'
 * '<S32>'  : 'S223_StateMachine/TaskControl/turnOffSW_Power'
 * '<S33>'  : 'S223_StateMachine/TaskControl/turnOnSW_Power'
 * '<S34>'  : 'S223_StateMachine/TaskControl/BigDischargePowerAdjust/FailureMode2'
 * '<S35>'  : 'S223_StateMachine/TaskControl/BigDischargePowerAdjust/NormalMode'
 * '<S36>'  : 'S223_StateMachine/TaskControl/BigDischargePowerAdjust/linearizationSOF'
 * '<S37>'  : 'S223_StateMachine/TaskControl/BigDischargePowerAdjust/linearizationSOF/greaterEq'
 * '<S38>'  : 'S223_StateMachine/TaskControl/BigDischargePowerAdjust/linearizationSOF/lessEq'
 * '<S39>'  : 'S223_StateMachine/TaskControl/PulseRechargePowerAdjust/FailureMode2'
 * '<S40>'  : 'S223_StateMachine/TaskControl/PulseRechargePowerAdjust/NormalMode'
 * '<S41>'  : 'S223_StateMachine/TaskControl/PulseRechargePowerAdjust/linearizationSOF'
 * '<S42>'  : 'S223_StateMachine/TaskControl/PulseRechargePowerAdjust/linearizationSOF/greaterEq'
 * '<S43>'  : 'S223_StateMachine/TaskControl/PulseRechargePowerAdjust/linearizationSOF/lessEq'
 */
#endif                                 /* RTW_HEADER_S223_StateMachine_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
