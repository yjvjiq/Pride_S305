/*
 * File: CurrentSencerError.h
 *
 * Code generated for Simulink model 'CurrentSencerError'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Tue Jun 07 15:15:20 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CurrentSencerError_h_
#define RTW_HEADER_CurrentSencerError_h_
#include <stddef.h>
#include <string.h>
#ifndef CurrentSencerError_COMMON_INCLUDES_
# define CurrentSencerError_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CurrentSencerError_COMMON_INCLUDES_ */

#include "CurrentSencerError_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  boolean_T F_1;                       /* '<Root>/Chart1' */
} B_CurrentSencerError_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T t1;                          /* '<Root>/Chart1' */
} DW_CurrentSencerError_T;

/* Real-time Model Data Structure */
struct tag_RTM_CurrentSencerError_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_CurrentSencerError_T CurrentSencerError_B;

/* Block states (auto storage) */
extern DW_CurrentSencerError_T CurrentSencerError_DW;

/* Model entry point functions */
extern void CurrentSencerError_initialize(void);
extern void CurrentSencerError_terminate(void);

/* Customized model step function */
extern boolean_T CurrentSencerError_step(real32_T g_systemCurrent);

/* Real-time Model object */
extern RT_MODEL_CurrentSencerError_T *const CurrentSencerError_M;

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
 * '<Root>' : 'CurrentSencerError'
 * '<S1>'   : 'CurrentSencerError/Chart1'
 * '<S2>'   : 'CurrentSencerError/Model Info'
 */
#endif                                 /* RTW_HEADER_CurrentSencerError_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
