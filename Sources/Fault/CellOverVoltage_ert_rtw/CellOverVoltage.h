/*
 * File: CellOverVoltage.h
 *
 * Code generated for Simulink model 'CellOverVoltage'.
 *
 * Model version                  : 1.121
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue May 23 17:11:09 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->HC(S)12
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

/* Block signals (auto storage) */
typedef struct {
  uint8_T F_lev_i;                     /* '<Root>/Logic' */
} B_CellOverVoltage_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_CellOverVoltage;/* '<Root>/Logic' */
  uint8_T is_F1;                       /* '<Root>/Logic' */
  uint8_T is_F2;                       /* '<Root>/Logic' */
  uint8_T temporalCounter_i1;          /* '<Root>/Logic' */
  uint8_T temporalCounter_i2;          /* '<Root>/Logic' */
} DW_CellOverVoltage_T;

/* Real-time Model Data Structure */
struct tag_RTM_CellOverVoltage_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_CellOverVoltage_T CellOverVoltage_B;

/* Block states (auto storage) */
extern DW_CellOverVoltage_T CellOverVoltage_DW;

/* Model entry point functions */
extern void CellOverVoltage_initialize(void);
extern void CellOverVoltage_terminate(void);

/* Customized model step function */
extern uint8_T CellOverVoltage_custom(real32_T Vmax, uint8_T Modelflag);

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
 * '<S1>'   : 'CellOverVoltage/Logic'
 */
#endif                                 /* RTW_HEADER_CellOverVoltage_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
