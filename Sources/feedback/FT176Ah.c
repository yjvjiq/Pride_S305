/*
 * File: FT176Ah.c
 *
 * Code generated for Simulink model 'FT176Ah'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 20 17:38:21 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FT176Ah.h"
#include "FT176Ah_private.h"

/* Exported block signals */
real32_T out2;                         /* '<Root>/Model' */
real32_T out3;                         /* '<Root>/Model1' */

/* External inputs (root inport signals with auto storage) */
ExtU_FT176Ah_T FT176Ah_U;

/* Real-time model */
RT_MODEL_FT176Ah_T FT176Ah_M_;
RT_MODEL_FT176Ah_T *const FT176Ah_M = &FT176Ah_M_;

/* Model step function */
void FT176Ah_step(void)
{
  /* ModelReference: '<Root>/Model' */
  out2 = SOF176Ah_step(FT176Ah_U.In3, FT176Ah_U.In4);

  /* ModelReference: '<Root>/Model1' */
  out3 = Feedback176Ah_step(FT176Ah_U.In5, FT176Ah_U.In6);
}

/* Model initialize function */
void FT176Ah_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FT176Ah_M, (NULL));

  /* block I/O */

  /* exported global signals */
  out2 = 0.0F;
  out3 = 0.0F;

  /* external inputs */
  (void) memset((void *)&FT176Ah_U, 0,
                sizeof(ExtU_FT176Ah_T));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model' */
  SOF176Ah_b_initialize(rtmGetErrorStatusPointer(FT176Ah_M));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model1' */
  Feedback176Ah_k_initialize(rtmGetErrorStatusPointer(FT176Ah_M));
}

/* Model terminate function */
void FT176Ah_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
