/*
 * File: CurrentSencerError.c
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

#include "CurrentSencerError.h"
#include "CurrentSencerError_private.h"

/* Block signals (auto storage) */
B_CurrentSencerError_T CurrentSencerError_B;

/* Block states (auto storage) */
DW_CurrentSencerError_T CurrentSencerError_DW;

/* Real-time model */
RT_MODEL_CurrentSencerError_T CurrentSencerError_M_;
RT_MODEL_CurrentSencerError_T *const CurrentSencerError_M =
  &CurrentSencerError_M_;

/* Model step function */
boolean_T CurrentSencerError_step(real32_T g_systemCurrent)
{
  boolean_T guard1 = false;
  int32_T tmp;

  /* specified return value */
  boolean_T error;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  /* Entry Internal: Chart1 */
  /* Transition: '<S1>:91' */
  if ((g_systemCurrent > 533.0F) || (g_systemCurrent < -533.0F)) {
    /* Transition: '<S1>:31' */
    tmp = CurrentSencerError_DW.t1 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    CurrentSencerError_DW.t1 = (uint8_T)tmp;
    if (CurrentSencerError_DW.t1 > 15) {
      /* Transition: '<S1>:33' */
      /* Transition: '<S1>:89' */
      CurrentSencerError_B.F_1 = true;
      CurrentSencerError_DW.t1 = 15U;

      /* Transition: '<S1>:94' */
      /* Transition: '<S1>:75' */
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 && ((g_systemCurrent < 533.0F) && (g_systemCurrent > -533.0F) &&
                 (!CurrentSencerError_B.F_1))) {
    /* Transition: '<S1>:92' */
    /* Transition: '<S1>:93' */
    CurrentSencerError_DW.t1 = 0U;

    /* Transition: '<S1>:75' */
  } else {
    /* Transition: '<S1>:74' */
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  error = CurrentSencerError_B.F_1;
  return error;
}

/* Model initialize function */
void CurrentSencerError_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(CurrentSencerError_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &CurrentSencerError_B), 0,
                sizeof(B_CurrentSencerError_T));

  /* states (dwork) */
  (void) memset((void *)&CurrentSencerError_DW, 0,
                sizeof(DW_CurrentSencerError_T));

  /* InitializeConditions for Chart: '<Root>/Chart1' */
  CurrentSencerError_DW.t1 = 0U;
  CurrentSencerError_B.F_1 = false;
}

/* Model terminate function */
void CurrentSencerError_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
