/*
 * File: ChargeOverCurrent.c
 *
 * Code generated for Simulink model 'ChargeOverCurrent'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue May 23 17:08:52 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->HC(S)12
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ChargeOverCurrent.h"
#include "ChargeOverCurrent_private.h"

/* Named constants for Chart: '<Root>/Logic' */
#define ChargeOverCu_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ChargeOverCurrent_IN_Delay10   ((uint8_T)1U)
#define ChargeOverCurrent_IN_Delay11   ((uint8_T)2U)
#define ChargeOverCurrent_IN_Fault1    ((uint8_T)3U)
#define ChargeOverCurrent_IN_Fault10   ((uint8_T)4U)
#define ChargeOverCurrent_IN_Wait1     ((uint8_T)5U)

/* Block signals (auto storage) */
B_ChargeOverCurrent_T ChargeOverCurrent_B;

/* Block states (auto storage) */
DW_ChargeOverCurrent_T ChargeOverCurrent_DW;

/* Real-time model */
RT_MODEL_ChargeOverCurrent_T ChargeOverCurrent_M_;
RT_MODEL_ChargeOverCurrent_T *const ChargeOverCurrent_M = &ChargeOverCurrent_M_;

/* Model step function */
uint8_T ChargeOverCurrent_custom(real32_T cur, real32_T curM)
{
  /* specified return value */
  uint8_T F_lev;

  /* Chart: '<Root>/Logic' incorporates:
   *  Inport: '<Root>/cur'
   *  Inport: '<Root>/curM'
   */
  /* Gateway: Logic */
  if (ChargeOverCurrent_DW.temporalCounter_i1 < 15U) {
    ChargeOverCurrent_DW.temporalCounter_i1++;
  }

  /* During: Logic */
  if (ChargeOverCurrent_DW.is_active_c3_ChargeOverCurrent == 0U) {
    /* Entry: Logic */
    ChargeOverCurrent_DW.is_active_c3_ChargeOverCurrent = 1U;

    /* Entry Internal: Logic */
    /* Transition: '<S1>:104' */
    /* Entry Internal 'F': '<S1>:103' */
    /* Entry Internal 'F1': '<S1>:184' */
    /* Transition: '<S1>:182' */
    ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Wait1;
  } else {
    /* During 'F': '<S1>:103' */
    /* During 'F1': '<S1>:184' */
    switch (ChargeOverCurrent_DW.is_F1) {
     case ChargeOverCurrent_IN_Delay10:
      /* During 'Delay10': '<S1>:192' */
      if (!(cur > 1.2F * curM)) {
        /* Transition: '<S1>:185' */
        ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Wait1;
      } else {
        if (ChargeOverCurrent_DW.temporalCounter_i1 >= 10) {
          /* Transition: '<S1>:183' */
          ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Fault1;

          /* Entry 'Fault1': '<S1>:190' */
          ChargeOverCurrent_B.F_lev_i = 1U;
        }
      }
      break;

     case ChargeOverCurrent_IN_Delay11:
      /* During 'Delay11': '<S1>:188' */
      if (!(cur <= curM)) {
        /* Transition: '<S1>:191' */
        ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Fault1;

        /* Entry 'Fault1': '<S1>:190' */
        ChargeOverCurrent_B.F_lev_i = 1U;
      } else {
        if (ChargeOverCurrent_DW.temporalCounter_i1 >= 10) {
          /* Transition: '<S1>:181' */
          ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Fault10;

          /* Entry 'Fault10': '<S1>:187' */
          ChargeOverCurrent_B.F_lev_i = 0U;
        }
      }
      break;

     case ChargeOverCurrent_IN_Fault1:
      /* During 'Fault1': '<S1>:190' */
      if (cur <= curM) {
        /* Transition: '<S1>:189' */
        ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Delay11;
        ChargeOverCurrent_DW.temporalCounter_i1 = 0U;
      }
      break;

     case ChargeOverCurrent_IN_Fault10:
      /* During 'Fault10': '<S1>:187' */
      /* Transition: '<S1>:193' */
      ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Wait1;
      break;

     default:
      /* During 'Wait1': '<S1>:186' */
      if (cur > 1.2F * curM) {
        /* Transition: '<S1>:194' */
        ChargeOverCurrent_DW.is_F1 = ChargeOverCurrent_IN_Delay10;
        ChargeOverCurrent_DW.temporalCounter_i1 = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Logic' */

  /* Outport: '<Root>/F_lev' */
  F_lev = ChargeOverCurrent_B.F_lev_i;
  return F_lev;
}

/* Model initialize function */
void ChargeOverCurrent_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ChargeOverCurrent_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &ChargeOverCurrent_B), 0,
                sizeof(B_ChargeOverCurrent_T));

  /* states (dwork) */
  (void) memset((void *)&ChargeOverCurrent_DW, 0,
                sizeof(DW_ChargeOverCurrent_T));

  /* SystemInitialize for Chart: '<Root>/Logic' */
  ChargeOverCurrent_DW.is_F1 = ChargeOverCu_IN_NO_ACTIVE_CHILD;
  ChargeOverCurrent_DW.temporalCounter_i1 = 0U;
  ChargeOverCurrent_DW.is_active_c3_ChargeOverCurrent = 0U;
  ChargeOverCurrent_B.F_lev_i = 0U;
}

/* Model terminate function */
void ChargeOverCurrent_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
