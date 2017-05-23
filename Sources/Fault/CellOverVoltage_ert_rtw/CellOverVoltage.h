/*
 * File: CellOverVoltage.h
 *
 * Code generated for Simulink model 'CellOverVoltage'.
 *
 * Model version                  : 1.204
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 09 10:09:13 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CellOverVoltage_h_
#define RTW_HEADER_CellOverVoltage_h_
#include <stddef.h>
#include <string.h>
#ifndef CellOverVoltage_COMMON_INCLUDES_
# define CellOverVoltage_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CellOverVoltage_COMMON_INCLUDES_ */

#include "CellOverVoltage_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c1_CellOverVoltage;/* '<Root>/Chart1' */
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
} DW_CellOverVoltage_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T g_CellHighestVol_g;         /* '<Root>/In1' */
} ExtU_CellOverVoltage_T;

/* Parameters (auto storage) */
struct P_CellOverVoltage_T_ {
  real32_T Chart1_ThresholdFault_1;    /* Mask Parameter: Chart1_ThresholdFault_1
                                        * Referenced by: '<Root>/Chart1'
                                        */
  real32_T Chart1_ThresholdFault_2;    /* Mask Parameter: Chart1_ThresholdFault_2
                                        * Referenced by: '<Root>/Chart1'
                                        */
  real32_T Chart1_ThresholdFault_3;    /* Mask Parameter: Chart1_ThresholdFault_3
                                        * Referenced by: '<Root>/Chart1'
                                        */
  real32_T Chart1_ThresholdFault_4;    /* Mask Parameter: Chart1_ThresholdFault_4
                                        * Referenced by: '<Root>/Chart1'
                                        */
  real32_T Chart1_ThresholdRecover_1;  /* Mask Parameter: Chart1_ThresholdRecover_1
                                        * Referenced by: '<Root>/Chart1'
                                        */
  real32_T Chart1_ThresholdRecover_2;  /* Mask Parameter: Chart1_ThresholdRecover_2
                                        * Referenced by: '<Root>/Chart1'
                                        */
  real32_T Chart1_ThresholdRecover_3;  /* Mask Parameter: Chart1_ThresholdRecover_3
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
struct tag_RTM_CellOverVoltage_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_CellOverVoltage_T CellOverVoltage_P;

/* Block states (auto storage) */
extern DW_CellOverVoltage_T CellOverVoltage_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_CellOverVoltage_T CellOverVoltage_U;

/* Model entry point functions */
extern void CellOverVoltage_initialize(void);
extern void CellOverVoltage_terminate(void);

/* Customized model step function */
extern uint8_T CellOverVoltage_step(real32_T g_CellHighestVol);

/* Real-time Model object */
extern RT_MODEL_CellOverVoltage_T *const CellOverVoltage_M;

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
 * '<Root>' : 'CellOverVoltage'
 * '<S1>'   : 'CellOverVoltage/Chart1'
 * '<S2>'   : 'CellOverVoltage/Model Info'
 */
#endif                                 /* RTW_HEADER_CellOverVoltage_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
