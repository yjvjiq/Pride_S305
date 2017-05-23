/*
 * File: SOCLow.c
 *
 * Code generated for Simulink model 'SOCLow'.
 *
 * Model version                  : 1.105
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 09 10:24:01 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SOCLow.h"
#include "SOCLow_private.h"

/* Block states (auto storage) */
DW_SOCLow_T SOCLow_DW;

/* Real-time model */
RT_MODEL_SOCLow_T SOCLow_M_;
RT_MODEL_SOCLow_T *const SOCLow_M = &SOCLow_M_;

/* Model step function */
uint8_T SOCLow_step(real32_T g_SysSOC)
{
  boolean_T guard6 = false;
  uint8_T rtb_F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (SOCLow_DW.is_active_c1_SOCLow == 0U) {
    /* Entry: Chart1 */
    SOCLow_DW.is_active_c1_SOCLow = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:193' */
    /* Entry Internal 'F': '<S1>:342' */
    /* Entry Internal 'F_1': '<S1>:296' */
    /* Entry Internal 'F_1_true': '<S1>:256' */
    /* Transition: '<S1>:380' */
    if (g_SysSOC < SOCLow_P.Chart1_ThresholdFault_1) {
      /* Transition: '<S1>:382' */
      tmp = SOCLow_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SOCLow_DW.t1 = (uint8_T)tmp;
      if (SOCLow_DW.t1 > SOCLow_P.Chart1_Second_1) {
        /* Transition: '<S1>:388' */
        /* Transition: '<S1>:389' */
        SOCLow_DW.F_1 = true;

        /* Transition: '<S1>:375' */
        /* Transition: '<S1>:381' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((g_SysSOC >= SOCLow_P.Chart1_ThresholdFault_1) &&
                   (!SOCLow_DW.F_1))) {
      /* Transition: '<S1>:384' */
      /* Transition: '<S1>:387' */
      SOCLow_DW.t1 = 0U;

      /* Transition: '<S1>:381' */
    } else {
      /* Transition: '<S1>:390' */
    }

    /* Entry Internal 'F_2': '<S1>:192' */
    /* Entry Internal 'F_2_true': '<S1>:321' */
    /* Transition: '<S1>:350' */
    guard6 = false;
    if (g_SysSOC < SOCLow_P.Chart1_ThresholdFault_2) {
      /* Transition: '<S1>:352' */
      tmp = SOCLow_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SOCLow_DW.t2 = (uint8_T)tmp;
      if (SOCLow_DW.t2 > SOCLow_P.Chart1_Second_2) {
        /* Transition: '<S1>:344' */
        /* Transition: '<S1>:348' */
        SOCLow_DW.F_2 = true;

        /* Transition: '<S1>:351' */
        /* Transition: '<S1>:343' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((g_SysSOC >= SOCLow_P.Chart1_ThresholdFault_2) &&
                   (!SOCLow_DW.F_2))) {
      /* Transition: '<S1>:353' */
      /* Transition: '<S1>:345' */
      SOCLow_DW.t2 = 0U;

      /* Transition: '<S1>:343' */
    } else {
      /* Transition: '<S1>:346' */
    }

    /* Entry Internal 'F_3': '<S1>:191' */
    /* Entry Internal 'F_3_true': '<S1>:235' */
    /* Transition: '<S1>:363' */
    guard6 = false;
    if (g_SysSOC < SOCLow_P.Chart1_ThresholdFault_3) {
      /* Transition: '<S1>:369' */
      tmp = SOCLow_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SOCLow_DW.t3 = (uint8_T)tmp;
      if (SOCLow_DW.t3 > SOCLow_P.Chart1_Second_3) {
        /* Transition: '<S1>:373' */
        /* Transition: '<S1>:359' */
        SOCLow_DW.F_3 = true;

        /* Transition: '<S1>:372' */
        /* Transition: '<S1>:365' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((g_SysSOC >= SOCLow_P.Chart1_ThresholdFault_3) &&
                   (!SOCLow_DW.F_3))) {
      /* Transition: '<S1>:367' */
      /* Transition: '<S1>:368' */
      SOCLow_DW.t3 = 0U;

      /* Transition: '<S1>:365' */
    } else {
      /* Transition: '<S1>:366' */
    }

    /* Entry Internal 'F_0': '<S1>:442' */
    /* Entry Internal 'F_0_true': '<S1>:416' */
    /* Transition: '<S1>:427' */
    if (SOCLow_DW.F_3) {
      /* Transition: '<S1>:429' */
      /* Transition: '<S1>:434' */
      SOCLow_DW.F_2 = false;
      SOCLow_DW.F_1 = false;
      rtb_F_lev = 3U;

      /* Transition: '<S1>:441' */
      /* Transition: '<S1>:440' */
      /* Transition: '<S1>:439' */
      /* Transition: '<S1>:438' */
    } else if (SOCLow_DW.F_2) {
      /* Transition: '<S1>:430' */
      /* Transition: '<S1>:435' */
      SOCLow_DW.F_1 = false;
      rtb_F_lev = 2U;

      /* Transition: '<S1>:440' */
      /* Transition: '<S1>:439' */
      /* Transition: '<S1>:438' */
    } else if (SOCLow_DW.F_1) {
      /* Transition: '<S1>:431' */
      /* Transition: '<S1>:436' */
      rtb_F_lev = 1U;

      /* Transition: '<S1>:439' */
      /* Transition: '<S1>:438' */
    } else {
      /* Transition: '<S1>:433' */
      rtb_F_lev = 0U;
    }
  } else {
    /* During 'F': '<S1>:342' */
    /* During 'F_1': '<S1>:296' */
    /* Transition: '<S1>:295' */
    /* Exit Internal 'F_1': '<S1>:296' */
    /* Entry Internal 'F_1_true': '<S1>:256' */
    /* Transition: '<S1>:380' */
    if (g_SysSOC < SOCLow_P.Chart1_ThresholdFault_1) {
      /* Transition: '<S1>:382' */
      tmp = SOCLow_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SOCLow_DW.t1 = (uint8_T)tmp;
      if (SOCLow_DW.t1 > SOCLow_P.Chart1_Second_1) {
        /* Transition: '<S1>:388' */
        /* Transition: '<S1>:389' */
        SOCLow_DW.F_1 = true;

        /* Transition: '<S1>:375' */
        /* Transition: '<S1>:381' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((g_SysSOC >= SOCLow_P.Chart1_ThresholdFault_1) &&
                   (!SOCLow_DW.F_1))) {
      /* Transition: '<S1>:384' */
      /* Transition: '<S1>:387' */
      SOCLow_DW.t1 = 0U;

      /* Transition: '<S1>:381' */
    } else {
      /* Transition: '<S1>:390' */
    }

    /* During 'F_2': '<S1>:192' */
    /* Transition: '<S1>:319' */
    /* Exit Internal 'F_2': '<S1>:192' */
    /* Entry Internal 'F_2_true': '<S1>:321' */
    /* Transition: '<S1>:350' */
    guard6 = false;
    if (g_SysSOC < SOCLow_P.Chart1_ThresholdFault_2) {
      /* Transition: '<S1>:352' */
      tmp = SOCLow_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SOCLow_DW.t2 = (uint8_T)tmp;
      if (SOCLow_DW.t2 > SOCLow_P.Chart1_Second_2) {
        /* Transition: '<S1>:344' */
        /* Transition: '<S1>:348' */
        SOCLow_DW.F_2 = true;

        /* Transition: '<S1>:351' */
        /* Transition: '<S1>:343' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((g_SysSOC >= SOCLow_P.Chart1_ThresholdFault_2) &&
                   (!SOCLow_DW.F_2))) {
      /* Transition: '<S1>:353' */
      /* Transition: '<S1>:345' */
      SOCLow_DW.t2 = 0U;

      /* Transition: '<S1>:343' */
    } else {
      /* Transition: '<S1>:346' */
    }

    /* During 'F_3': '<S1>:191' */
    /* Transition: '<S1>:277' */
    /* Exit Internal 'F_3': '<S1>:191' */
    /* Entry Internal 'F_3_true': '<S1>:235' */
    /* Transition: '<S1>:363' */
    guard6 = false;
    if (g_SysSOC < SOCLow_P.Chart1_ThresholdFault_3) {
      /* Transition: '<S1>:369' */
      tmp = SOCLow_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SOCLow_DW.t3 = (uint8_T)tmp;
      if (SOCLow_DW.t3 > SOCLow_P.Chart1_Second_3) {
        /* Transition: '<S1>:373' */
        /* Transition: '<S1>:359' */
        SOCLow_DW.F_3 = true;

        /* Transition: '<S1>:372' */
        /* Transition: '<S1>:365' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((g_SysSOC >= SOCLow_P.Chart1_ThresholdFault_3) &&
                   (!SOCLow_DW.F_3))) {
      /* Transition: '<S1>:367' */
      /* Transition: '<S1>:368' */
      SOCLow_DW.t3 = 0U;

      /* Transition: '<S1>:365' */
    } else {
      /* Transition: '<S1>:366' */
    }

    /* During 'F_0': '<S1>:442' */
    /* Transition: '<S1>:415' */
    /* Exit Internal 'F_0': '<S1>:442' */
    /* Entry Internal 'F_0_true': '<S1>:416' */
    /* Transition: '<S1>:427' */
    if (SOCLow_DW.F_3) {
      /* Transition: '<S1>:429' */
      /* Transition: '<S1>:434' */
      SOCLow_DW.F_2 = false;
      SOCLow_DW.F_1 = false;
      rtb_F_lev = 3U;

      /* Transition: '<S1>:441' */
      /* Transition: '<S1>:440' */
      /* Transition: '<S1>:439' */
      /* Transition: '<S1>:438' */
    } else if (SOCLow_DW.F_2) {
      /* Transition: '<S1>:430' */
      /* Transition: '<S1>:435' */
      SOCLow_DW.F_1 = false;
      rtb_F_lev = 2U;

      /* Transition: '<S1>:440' */
      /* Transition: '<S1>:439' */
      /* Transition: '<S1>:438' */
    } else if (SOCLow_DW.F_1) {
      /* Transition: '<S1>:431' */
      /* Transition: '<S1>:436' */
      rtb_F_lev = 1U;

      /* Transition: '<S1>:439' */
      /* Transition: '<S1>:438' */
    } else {
      /* Transition: '<S1>:433' */
      rtb_F_lev = 0U;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = rtb_F_lev;
  return F_level;
}

/* Model initialize function */
void SOCLow_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SOCLow_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&SOCLow_DW, 0,
                sizeof(DW_SOCLow_T));

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  SOCLow_DW.is_active_c1_SOCLow = 0U;
  SOCLow_DW.t2 = 0U;
  SOCLow_DW.t3 = 0U;
  SOCLow_DW.t1 = 0U;
  SOCLow_DW.F_1 = false;
  SOCLow_DW.F_2 = false;
  SOCLow_DW.F_3 = false;
}

/* Model terminate function */
void SOCLow_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
