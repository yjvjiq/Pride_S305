/*
 * File: TotalVoltageOverVoltage_cellnum.h
 *
 * Code generated for Simulink model 'TotalVoltageOverVoltage_cellnum'.
 *
 * Model version                  : 1.152
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Mar 08 09:29:31 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->HC(S)12
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TotalVoltageOverVoltage_cellnum_h_
#define RTW_HEADER_TotalVoltageOverVoltage_cellnum_h_
#include <stddef.h>
#include <string.h>
#ifndef TotalVoltageOverVoltage_cellnum_COMMON_INCLUDES_
# define TotalVoltageOverVoltage_cellnum_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* TotalVoltageOverVoltage_cellnum_COMMON_INCLUDES_ */

#include "TotalVoltageOverVoltage_cellnum_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T F_lev;
  real32_T Value_1[2];                 /* '<Root>/Chart1' */
  real32_T Value_2[2];                 /* '<Root>/Chart1' */
  real32_T Value_3[2];                 /* '<Root>/Chart1' */
  real32_T Value_4[2];                 /* '<Root>/Chart1' */
  real32_T Value_22[2];                /* '<Root>/Chart1' */
  real32_T Value_33[2];                /* '<Root>/Chart1' */
  real32_T Value_11[2];                /* '<Root>/Chart1' */
  real32_T ThresholdRecover_3;         /* '<Root>/Chart1' */
  real32_T ThresholdRecover_2;         /* '<Root>/Chart1' */
  real32_T ThresholdRecover_1;         /* '<Root>/Chart1' */
  real32_T ThresholdFault_4;           /* '<Root>/Chart1' */
  real32_T ThresholdFault_3;           /* '<Root>/Chart1' */
  real32_T ThresholdFault_2;           /* '<Root>/Chart1' */
  real32_T ThresholdFault_1;           /* '<Root>/Chart1' */
  uint8_T is_active_c1_TotalVoltageOverVo;/* '<Root>/Chart1' */
  uint8_T t1;                          /* '<Root>/Chart1' */
  uint8_T t2;                          /* '<Root>/Chart1' */
  uint8_T t3;                          /* '<Root>/Chart1' */
  uint8_T t22;                         /* '<Root>/Chart1' */
  uint8_T t33;                         /* '<Root>/Chart1' */
  uint8_T t11;                         /* '<Root>/Chart1' */
  uint8_T t4;                          /* '<Root>/Chart1' */
  boolean_T F_1;                       /* '<Root>/Chart1' */
  boolean_T F_2;                       /* '<Root>/Chart1' */
  boolean_T F_3;                       /* '<Root>/Chart1' */
  boolean_T F_4;                       /* '<Root>/Chart1' */
} DW_TotalVoltageOverVoltage_ce_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T V0_g;                       /* '<Root>/In1' */
  real32_T V3_i;                       /* '<Root>/In2' */
} ExtU_TotalVoltageOverVoltage__T;

/* Parameters (auto storage) */
struct P_TotalVoltageOverVoltage_cel_T_ {
  uint16_T Chart1_BatCellNumber;       /* Mask Parameter: Chart1_BatCellNumber
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_BatType;              /* Mask Parameter: Chart1_BatType
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_Second_1;             /* Mask Parameter: Chart1_Second_1
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_Second_11;            /* Mask Parameter: Chart1_Second_11
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_Second_2;             /* Mask Parameter: Chart1_Second_2
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_Second_22;            /* Mask Parameter: Chart1_Second_22
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_Second_3;             /* Mask Parameter: Chart1_Second_3
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_Second_33;            /* Mask Parameter: Chart1_Second_33
                                        * Referenced by: '<Root>/Chart1'
                                        */
  uint8_T Chart1_Second_4;             /* Mask Parameter: Chart1_Second_4
                                        * Referenced by: '<Root>/Chart1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TotalVoltageOverVolta_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_TotalVoltageOverVoltage_cel_T TotalVoltageOverVoltage_celln_P;

/* Block states (auto storage) */
extern DW_TotalVoltageOverVoltage_ce_T TotalVoltageOverVoltage_cell_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_TotalVoltageOverVoltage__T TotalVoltageOverVoltage_celln_U;

/* Model entry point functions */
extern void TotalVoltageOverVoltage_initialize(void);
extern void TotalVoltageOverVoltage_cellnum_terminate(void);

/* Customized model step function */
extern uint8_T TotalVoltageOverVoltage_step(real32_T V0, real32_T V3);

/* Real-time Model object */
extern RT_MODEL_TotalVoltageOverVolt_T *const TotalVoltageOverVoltage_cell_M;

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
 * '<Root>' : 'TotalVoltageOverVoltage_cellnum'
 * '<S1>'   : 'TotalVoltageOverVoltage_cellnum/Chart1'
 * '<S2>'   : 'TotalVoltageOverVoltage_cellnum/Model Info'
 */
#endif                                 /* RTW_HEADER_TotalVoltageOverVoltage_cellnum_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
