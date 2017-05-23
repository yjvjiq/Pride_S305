/*
 * File: CellVoltageUnbalance.c
 *
 * Code generated for Simulink model 'CellVoltageUnbalance'.
 *
 * Model version                  : 1.126
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sun Dec 11 10:50:31 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CellVoltageUnbalance.h"
#include "CellVoltageUnbalance_private.h"

/* Block states (auto storage) */
DW_CellVoltageUnbalance_T CellVoltageUnbalance_DW;

/* Real-time model */
RT_MODEL_CellVoltageUnbalance_T CellVoltageUnbalance_M_;
RT_MODEL_CellVoltageUnbalance_T *const CellVoltageUnbalance_M =
  &CellVoltageUnbalance_M_;

/* Model step function */
uint8_T CellVoltageUnbalance_step(real32_T g_CellHighestVol, real32_T
  g_CellLowestVol)
{
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  uint8_T rtb_F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (CellVoltageUnbalance_DW.is_active_c1_CellVoltageUnbalan == 0U) {
    /* Entry: Chart1 */
    CellVoltageUnbalance_DW.is_active_c1_CellVoltageUnbalan = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:384' */
    /* Entry Internal 'F': '<S1>:279' */
    /* Entry Internal 'F_1': '<S1>:280' */
    /* Transition: '<S1>:556' */
    if (CellVoltageUnbalance_DW.F_1) {
      /* Transition: '<S1>:338' */
      /* Entry Internal 'F_1_false': '<S1>:300' */
      /* Transition: '<S1>:522' */
      CellVoltageUnbalance_DW.F_1 = true;
      if ((g_CellHighestVol - g_CellLowestVol <
           CellVoltageUnbalance_P.Chart1_ThresholdRecover_1) &&
          CellVoltageUnbalance_DW.F_1) {
        /* Transition: '<S1>:524' */
        tmp = CellVoltageUnbalance_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t11 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t11 >
            CellVoltageUnbalance_P.Chart1_Second_11) {
          /* Transition: '<S1>:520' */
          /* Transition: '<S1>:526' */
          CellVoltageUnbalance_DW.F_1 = false;
          CellVoltageUnbalance_DW.t11 = 0U;

          /* Transition: '<S1>:533' */
          /* Transition: '<S1>:525' */
        } else {
          guard9 = true;
        }
      } else {
        guard9 = true;
      }
    } else {
      /* Transition: '<S1>:383' */
      /* Entry Internal 'F_1_true': '<S1>:618' */
      /* Transition: '<S1>:626' */
      if (g_CellHighestVol - g_CellLowestVol >=
          CellVoltageUnbalance_P.Chart1_ThresholdFault_1) {
        /* Transition: '<S1>:628' */
        tmp = CellVoltageUnbalance_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t1 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t1 > CellVoltageUnbalance_P.Chart1_Second_1)
        {
          /* Transition: '<S1>:631' */
          /* Transition: '<S1>:633' */
          CellVoltageUnbalance_DW.F_1 = true;

          /* Transition: '<S1>:635' */
          /* Transition: '<S1>:634' */
        } else {
          guard10 = true;
        }
      } else {
        guard10 = true;
      }
    }

    if (guard10 && ((g_CellHighestVol - g_CellLowestVol <
                     CellVoltageUnbalance_P.Chart1_ThresholdFault_1) &&
                    (!CellVoltageUnbalance_DW.F_1))) {
      /* Transition: '<S1>:629' */
      /* Transition: '<S1>:632' */
      CellVoltageUnbalance_DW.t1 = 0U;

      /* Transition: '<S1>:634' */
    } else {
      /* Transition: '<S1>:630' */
    }

    if (guard9 && ((g_CellHighestVol - g_CellLowestVol >=
                    CellVoltageUnbalance_P.Chart1_ThresholdRecover_1) &&
                   CellVoltageUnbalance_DW.F_1)) {
      /* Transition: '<S1>:528' */
      /* Transition: '<S1>:531' */
      CellVoltageUnbalance_DW.t11 = 0U;

      /* Transition: '<S1>:525' */
    } else {
      /* Transition: '<S1>:523' */
    }

    /* Entry Internal 'F_2': '<S1>:277' */
    /* Transition: '<S1>:566' */
    guard9 = false;
    guard10 = false;
    if (!CellVoltageUnbalance_DW.F_2) {
      /* Transition: '<S1>:406' */
      /* Entry Internal 'F_2_true': '<S1>:385' */
      /* Transition: '<S1>:429' */
      CellVoltageUnbalance_DW.F_2 = false;
      if (g_CellHighestVol - g_CellLowestVol >=
          CellVoltageUnbalance_P.Chart1_ThresholdFault_2) {
        /* Transition: '<S1>:430' */
        tmp = CellVoltageUnbalance_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t2 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t2 > CellVoltageUnbalance_P.Chart1_Second_2)
        {
          /* Transition: '<S1>:432' */
          /* Transition: '<S1>:436' */
          CellVoltageUnbalance_DW.F_2 = true;
          CellVoltageUnbalance_DW.t2 = 0U;

          /* Transition: '<S1>:425' */
          /* Transition: '<S1>:433' */
        } else {
          guard9 = true;
        }
      } else {
        guard9 = true;
      }
    } else {
      /* Transition: '<S1>:276' */
      /* Entry Internal 'F_2_false': '<S1>:255' */
      /* Transition: '<S1>:494' */
      CellVoltageUnbalance_DW.F_2 = true;
      if ((g_CellHighestVol - g_CellLowestVol <
           CellVoltageUnbalance_P.Chart1_ThresholdRecover_2) &&
          CellVoltageUnbalance_DW.F_2) {
        /* Transition: '<S1>:495' */
        tmp = CellVoltageUnbalance_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t22 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t22 >
            CellVoltageUnbalance_P.Chart1_Second_22) {
          /* Transition: '<S1>:498' */
          /* Transition: '<S1>:500' */
          CellVoltageUnbalance_DW.F_2 = false;
          CellVoltageUnbalance_DW.t22 = 0U;

          /* Transition: '<S1>:502' */
          /* Transition: '<S1>:501' */
        } else {
          guard10 = true;
        }
      } else {
        guard10 = true;
      }
    }

    if (guard10 && ((g_CellHighestVol - g_CellLowestVol >=
                     CellVoltageUnbalance_P.Chart1_ThresholdRecover_2) &&
                    CellVoltageUnbalance_DW.F_2)) {
      /* Transition: '<S1>:496' */
      /* Transition: '<S1>:499' */
      CellVoltageUnbalance_DW.t22 = 0U;
      CellVoltageUnbalance_DW.t1 = 0U;

      /* Transition: '<S1>:501' */
    } else {
      /* Transition: '<S1>:497' */
    }

    if (guard9 && ((g_CellHighestVol - g_CellLowestVol <
                    CellVoltageUnbalance_P.Chart1_ThresholdFault_2) &&
                   (!CellVoltageUnbalance_DW.F_2))) {
      /* Transition: '<S1>:437' */
      /* Transition: '<S1>:427' */
      CellVoltageUnbalance_DW.t2 = 0U;

      /* Transition: '<S1>:433' */
    } else {
      /* Transition: '<S1>:426' */
    }

    /* Entry Internal 'F_0': '<S1>:599' */
    /* Entry Internal 'F_0_true': '<S1>:573' */
    /* Transition: '<S1>:584' */
    if (CellVoltageUnbalance_DW.F_2) {
      /* Transition: '<S1>:586' */
      /* Transition: '<S1>:591' */
      CellVoltageUnbalance_DW.F_1 = false;
      rtb_F_lev = 2U;

      /* Transition: '<S1>:598' */
      /* Transition: '<S1>:597' */
      /* Transition: '<S1>:596' */
      /* Transition: '<S1>:595' */
    } else if (CellVoltageUnbalance_DW.F_1) {
      /* Transition: '<S1>:587' */
      /* Transition: '<S1>:592' */
      rtb_F_lev = 1U;

      /* Transition: '<S1>:597' */
      /* Transition: '<S1>:596' */
      /* Transition: '<S1>:595' */
    } else {
      /* Transition: '<S1>:590' */
      rtb_F_lev = 0U;
    }
  } else {
    /* During 'F': '<S1>:279' */
    /* During 'F_1': '<S1>:280' */
    /* Transition: '<S1>:557' */
    if (CellVoltageUnbalance_DW.F_1) {
      /* Transition: '<S1>:338' */
      /* Exit Internal 'F_1': '<S1>:280' */
      /* Entry Internal 'F_1_false': '<S1>:300' */
      /* Transition: '<S1>:522' */
      CellVoltageUnbalance_DW.F_1 = true;
      if ((g_CellHighestVol - g_CellLowestVol <
           CellVoltageUnbalance_P.Chart1_ThresholdRecover_1) &&
          CellVoltageUnbalance_DW.F_1) {
        /* Transition: '<S1>:524' */
        tmp = CellVoltageUnbalance_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t11 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t11 >
            CellVoltageUnbalance_P.Chart1_Second_11) {
          /* Transition: '<S1>:520' */
          /* Transition: '<S1>:526' */
          CellVoltageUnbalance_DW.F_1 = false;
          CellVoltageUnbalance_DW.t11 = 0U;

          /* Transition: '<S1>:533' */
          /* Transition: '<S1>:525' */
        } else {
          guard9 = true;
        }
      } else {
        guard9 = true;
      }
    } else {
      /* Transition: '<S1>:383' */
      /* Exit Internal 'F_1': '<S1>:280' */
      /* Entry Internal 'F_1_true': '<S1>:618' */
      /* Transition: '<S1>:626' */
      if (g_CellHighestVol - g_CellLowestVol >=
          CellVoltageUnbalance_P.Chart1_ThresholdFault_1) {
        /* Transition: '<S1>:628' */
        tmp = CellVoltageUnbalance_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t1 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t1 > CellVoltageUnbalance_P.Chart1_Second_1)
        {
          /* Transition: '<S1>:631' */
          /* Transition: '<S1>:633' */
          CellVoltageUnbalance_DW.F_1 = true;

          /* Transition: '<S1>:635' */
          /* Transition: '<S1>:634' */
        } else {
          guard10 = true;
        }
      } else {
        guard10 = true;
      }
    }

    if (guard10 && ((g_CellHighestVol - g_CellLowestVol <
                     CellVoltageUnbalance_P.Chart1_ThresholdFault_1) &&
                    (!CellVoltageUnbalance_DW.F_1))) {
      /* Transition: '<S1>:629' */
      /* Transition: '<S1>:632' */
      CellVoltageUnbalance_DW.t1 = 0U;

      /* Transition: '<S1>:634' */
    } else {
      /* Transition: '<S1>:630' */
    }

    if (guard9 && ((g_CellHighestVol - g_CellLowestVol >=
                    CellVoltageUnbalance_P.Chart1_ThresholdRecover_1) &&
                   CellVoltageUnbalance_DW.F_1)) {
      /* Transition: '<S1>:528' */
      /* Transition: '<S1>:531' */
      CellVoltageUnbalance_DW.t11 = 0U;

      /* Transition: '<S1>:525' */
    } else {
      /* Transition: '<S1>:523' */
    }

    /* During 'F_2': '<S1>:277' */
    /* Transition: '<S1>:567' */
    guard9 = false;
    guard10 = false;
    if (!CellVoltageUnbalance_DW.F_2) {
      /* Transition: '<S1>:406' */
      /* Exit Internal 'F_2': '<S1>:277' */
      /* Entry Internal 'F_2_true': '<S1>:385' */
      /* Transition: '<S1>:429' */
      CellVoltageUnbalance_DW.F_2 = false;
      if (g_CellHighestVol - g_CellLowestVol >=
          CellVoltageUnbalance_P.Chart1_ThresholdFault_2) {
        /* Transition: '<S1>:430' */
        tmp = CellVoltageUnbalance_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t2 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t2 > CellVoltageUnbalance_P.Chart1_Second_2)
        {
          /* Transition: '<S1>:432' */
          /* Transition: '<S1>:436' */
          CellVoltageUnbalance_DW.F_2 = true;
          CellVoltageUnbalance_DW.t2 = 0U;

          /* Transition: '<S1>:425' */
          /* Transition: '<S1>:433' */
        } else {
          guard9 = true;
        }
      } else {
        guard9 = true;
      }
    } else {
      /* Transition: '<S1>:276' */
      /* Exit Internal 'F_2': '<S1>:277' */
      /* Entry Internal 'F_2_false': '<S1>:255' */
      /* Transition: '<S1>:494' */
      CellVoltageUnbalance_DW.F_2 = true;
      if ((g_CellHighestVol - g_CellLowestVol <
           CellVoltageUnbalance_P.Chart1_ThresholdRecover_2) &&
          CellVoltageUnbalance_DW.F_2) {
        /* Transition: '<S1>:495' */
        tmp = CellVoltageUnbalance_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellVoltageUnbalance_DW.t22 = (uint8_T)tmp;
        if (CellVoltageUnbalance_DW.t22 >
            CellVoltageUnbalance_P.Chart1_Second_22) {
          /* Transition: '<S1>:498' */
          /* Transition: '<S1>:500' */
          CellVoltageUnbalance_DW.F_2 = false;
          CellVoltageUnbalance_DW.t22 = 0U;

          /* Transition: '<S1>:502' */
          /* Transition: '<S1>:501' */
        } else {
          guard10 = true;
        }
      } else {
        guard10 = true;
      }
    }

    if (guard10 && ((g_CellHighestVol - g_CellLowestVol >=
                     CellVoltageUnbalance_P.Chart1_ThresholdRecover_2) &&
                    CellVoltageUnbalance_DW.F_2)) {
      /* Transition: '<S1>:496' */
      /* Transition: '<S1>:499' */
      CellVoltageUnbalance_DW.t22 = 0U;
      CellVoltageUnbalance_DW.t1 = 0U;

      /* Transition: '<S1>:501' */
    } else {
      /* Transition: '<S1>:497' */
    }

    if (guard9 && ((g_CellHighestVol - g_CellLowestVol <
                    CellVoltageUnbalance_P.Chart1_ThresholdFault_2) &&
                   (!CellVoltageUnbalance_DW.F_2))) {
      /* Transition: '<S1>:437' */
      /* Transition: '<S1>:427' */
      CellVoltageUnbalance_DW.t2 = 0U;

      /* Transition: '<S1>:433' */
    } else {
      /* Transition: '<S1>:426' */
    }

    /* During 'F_0': '<S1>:599' */
    /* Transition: '<S1>:572' */
    /* Exit Internal 'F_0': '<S1>:599' */
    /* Entry Internal 'F_0_true': '<S1>:573' */
    /* Transition: '<S1>:584' */
    if (CellVoltageUnbalance_DW.F_2) {
      /* Transition: '<S1>:586' */
      /* Transition: '<S1>:591' */
      CellVoltageUnbalance_DW.F_1 = false;
      rtb_F_lev = 2U;

      /* Transition: '<S1>:598' */
      /* Transition: '<S1>:597' */
      /* Transition: '<S1>:596' */
      /* Transition: '<S1>:595' */
    } else if (CellVoltageUnbalance_DW.F_1) {
      /* Transition: '<S1>:587' */
      /* Transition: '<S1>:592' */
      rtb_F_lev = 1U;

      /* Transition: '<S1>:597' */
      /* Transition: '<S1>:596' */
      /* Transition: '<S1>:595' */
    } else {
      /* Transition: '<S1>:590' */
      rtb_F_lev = 0U;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = rtb_F_lev;
  return F_level;
}

/* Model initialize function */
void CellVoltageUnbalance_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(CellVoltageUnbalance_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&CellVoltageUnbalance_DW, 0,
                sizeof(DW_CellVoltageUnbalance_T));

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  CellVoltageUnbalance_DW.is_active_c1_CellVoltageUnbalan = 0U;
  CellVoltageUnbalance_DW.t1 = 0U;
  CellVoltageUnbalance_DW.t2 = 0U;
  CellVoltageUnbalance_DW.t22 = 0U;
  CellVoltageUnbalance_DW.t11 = 0U;
  CellVoltageUnbalance_DW.F_1 = false;
  CellVoltageUnbalance_DW.F_2 = false;
}

/* Model terminate function */
void CellVoltageUnbalance_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
