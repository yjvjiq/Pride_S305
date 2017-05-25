/*
 * File: DisChargeOverCurrent.c
 *
 * Code generated for Simulink model 'DisChargeOverCurrent'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue May 23 17:08:05 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->HC(S)12
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DisChargeOverCurrent.h"
#include "DisChargeOverCurrent_private.h"

/* Named constants for Chart: '<Root>/Logic' */
#define DisChargeOve_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DisChargeOverCurrent_IN_Delay10 ((uint8_T)1U)
#define DisChargeOverCurrent_IN_Delay11 ((uint8_T)2U)
#define DisChargeOverCurrent_IN_Fault1 ((uint8_T)3U)
#define DisChargeOverCurrent_IN_Fault10 ((uint8_T)4U)
#define DisChargeOverCurrent_IN_Wait1  ((uint8_T)5U)

/* Block signals (auto storage) */
B_DisChargeOverCurrent_T DisChargeOverCurrent_B;

/* Block states (auto storage) */
DW_DisChargeOverCurrent_T DisChargeOverCurrent_DW;

/* Real-time model */
RT_MODEL_DisChargeOverCurrent_T DisChargeOverCurrent_M_;
RT_MODEL_DisChargeOverCurrent_T *const DisChargeOverCurrent_M =
  &DisChargeOverCurrent_M_;

/* Model step function */
uint8_T DisChargeOverCurrent_custom(real32_T cur, real32_T curM)
{
  /* specified return value */
  uint8_T F_lev;

  /* Chart: '<Root>/Logic' incorporates:
   *  Inport: '<Root>/cur'
   *  Inport: '<Root>/curM'
   */
  /* Gateway: Logic */
  if (DisChargeOverCurrent_DW.temporalCounter_i1 < 15U) {
    DisChargeOverCurrent_DW.temporalCounter_i1++;
  }

  /* During: Logic */
  if (DisChargeOverCurrent_DW.is_active_c3_DisChargeOverCurre == 0U) {
    /* Entry: Logic */
    DisChargeOverCurrent_DW.is_active_c3_DisChargeOverCurre = 1U;

    /* Entry Internal: Logic */
    /* Transition: '<S1>:104' */
    /* Entry Internal 'F': '<S1>:103' */
    /* Entry Internal 'F1': '<S1>:184' */
    /* Transition: '<S1>:182' */
    DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Wait1;
  } else {
    /* During 'F': '<S1>:103' */
    /* During 'F1': '<S1>:184' */
    switch (DisChargeOverCurrent_DW.is_F1) {
     case DisChargeOverCurrent_IN_Delay10:
      /* During 'Delay10': '<S1>:192' */
      if (!(cur > 1.2F * curM)) {
        /* Transition: '<S1>:185' */
        DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Wait1;
      } else {
        if (DisChargeOverCurrent_DW.temporalCounter_i1 >= 10) {
          /* Transition: '<S1>:183' */
          DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Fault1;

          /* Entry 'Fault1': '<S1>:190' */
          DisChargeOverCurrent_B.F_lev_i = 1U;
        }
      }
      break;

     case DisChargeOverCurrent_IN_Delay11:
      /* During 'Delay11': '<S1>:188' */
      if (!(cur <= curM)) {
        /* Transition: '<S1>:191' */
        DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Fault1;

        /* Entry 'Fault1': '<S1>:190' */
        DisChargeOverCurrent_B.F_lev_i = 1U;
      } else {
        if (DisChargeOverCurrent_DW.temporalCounter_i1 >= 10) {
          /* Transition: '<S1>:181' */
          DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Fault10;

          /* Entry 'Fault10': '<S1>:187' */
          DisChargeOverCurrent_B.F_lev_i = 0U;
        }
      }
      break;

     case DisChargeOverCurrent_IN_Fault1:
      /* During 'Fault1': '<S1>:190' */
      if (cur <= curM) {
        /* Transition: '<S1>:189' */
        DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Delay11;
        DisChargeOverCurrent_DW.temporalCounter_i1 = 0U;
      }
      break;

     case DisChargeOverCurrent_IN_Fault10:
      /* During 'Fault10': '<S1>:187' */
      /* Transition: '<S1>:193' */
      DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Wait1;
      break;

     default:
      /* During 'Wait1': '<S1>:186' */
      if (cur > 1.2F * curM) {
        /* Transition: '<S1>:194' */
        DisChargeOverCurrent_DW.is_F1 = DisChargeOverCurrent_IN_Delay10;
        DisChargeOverCurrent_DW.temporalCounter_i1 = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Logic' */

  /* Outport: '<Root>/F_lev' */
  F_lev = DisChargeOverCurrent_B.F_lev_i;
  return F_lev;
}

/* Model initialize function */
void DisChargeOverCurrent_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DisChargeOverCurrent_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &DisChargeOverCurrent_B), 0,
                sizeof(B_DisChargeOverCurrent_T));

  /* states (dwork) */
  (void) memset((void *)&DisChargeOverCurrent_DW, 0,
                sizeof(DW_DisChargeOverCurrent_T));

  /* SystemInitialize for Chart: '<Root>/Logic' */
  DisChargeOverCurrent_DW.is_F1 = DisChargeOve_IN_NO_ACTIVE_CHILD;
  DisChargeOverCurrent_DW.temporalCounter_i1 = 0U;
  DisChargeOverCurrent_DW.is_active_c3_DisChargeOverCurre = 0U;
  DisChargeOverCurrent_B.F_lev_i = 0U;
}

/* Model terminate function */
void DisChargeOverCurrent_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
