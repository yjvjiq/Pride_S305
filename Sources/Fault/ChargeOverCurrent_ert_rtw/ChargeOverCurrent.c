/*
 * File: ChargeOverCurrent.c
 *
 * Code generated for Simulink model 'ChargeOverCurrent'.
 *
 * Model version                  : 1.114
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 09 10:22:52 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ChargeOverCurrent.h"
#include "ChargeOverCurrent_private.h"

/* Block states (auto storage) */
DW_ChargeOverCurrent_T ChargeOverCurrent_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_ChargeOverCurrent_T ChargeOverCurrent_U;

/* Real-time model */
RT_MODEL_ChargeOverCurrent_T ChargeOverCurrent_M_;
RT_MODEL_ChargeOverCurrent_T *const ChargeOverCurrent_M = &ChargeOverCurrent_M_;

/* Forward declaration for local functions */
static void ChargeOv_inner_default_F_0_true(uint8_T *F_lev);
static void ChargeOverCurrent_F(uint8_T *F_lev);

/* Function for Chart: '<Root>/Chart1' */
static void ChargeOv_inner_default_F_0_true(uint8_T *F_lev)
{
  /* Transition: '<S1>:570' */
  if (ChargeOverCurrent_DW.F_4) {
    /* Transition: '<S1>:572' */
    /* Transition: '<S1>:577' */
    ChargeOverCurrent_DW.F_2 = false;
    ChargeOverCurrent_DW.F_3 = false;
    ChargeOverCurrent_DW.F_1 = false;
    *F_lev = 4U;

    /* Transition: '<S1>:584' */
    /* Transition: '<S1>:583' */
    /* Transition: '<S1>:582' */
    /* Transition: '<S1>:581' */
  } else if (ChargeOverCurrent_DW.F_3) {
    /* Transition: '<S1>:573' */
    /* Transition: '<S1>:578' */
    ChargeOverCurrent_DW.F_1 = false;
    ChargeOverCurrent_DW.F_2 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:583' */
    /* Transition: '<S1>:582' */
    /* Transition: '<S1>:581' */
  } else if (ChargeOverCurrent_DW.F_2) {
    /* Transition: '<S1>:574' */
    /* Transition: '<S1>:579' */
    ChargeOverCurrent_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:582' */
    /* Transition: '<S1>:581' */
  } else if (ChargeOverCurrent_DW.F_1) {
    /* Transition: '<S1>:575' */
    /* Transition: '<S1>:580' */
    *F_lev = 1U;

    /* Transition: '<S1>:581' */
  } else {
    /* Transition: '<S1>:576' */
    *F_lev = 0U;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void ChargeOverCurrent_F(uint8_T *F_lev)
{
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  int32_T tmp;

  /* During 'F': '<S1>:407' */
  /* During 'F_1': '<S1>:360' */
  /* Transition: '<S1>:544' */
  if (ChargeOverCurrent_DW.F_1) {
    /* Transition: '<S1>:338' */
    /* Exit Internal 'F_1': '<S1>:360' */
    /* Entry Internal 'F_1_false': '<S1>:320' */
    /* Transition: '<S1>:516' */
    ChargeOverCurrent_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
         ChargeOverCurrent_P.Chart1_ThresholdRecover_1 *
         ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_1) {
      /* Transition: '<S1>:508' */
      tmp = ChargeOverCurrent_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      ChargeOverCurrent_DW.t11 = (uint8_T)tmp;
      if (ChargeOverCurrent_DW.t11 > ChargeOverCurrent_P.Chart1_Second_11) {
        /* Transition: '<S1>:517' */
        /* Transition: '<S1>:519' */
        ChargeOverCurrent_DW.F_1 = false;
        ChargeOverCurrent_DW.t11 = 0U;

        /* Transition: '<S1>:521' */
        /* Transition: '<S1>:518' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    /* Transition: '<S1>:337' */
    /* Exit Internal 'F_1': '<S1>:360' */
    /* Entry Internal 'F_1_true': '<S1>:587' */
    /* Transition: '<S1>:595' */
    if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
        ChargeOverCurrent_P.Chart1_ThresholdFault_1 *
        ChargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:597' */
      tmp = ChargeOverCurrent_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      ChargeOverCurrent_DW.t1 = (uint8_T)tmp;
      if (ChargeOverCurrent_DW.t1 > ChargeOverCurrent_P.Chart1_Second_1) {
        /* Transition: '<S1>:600' */
        /* Transition: '<S1>:602' */
        ChargeOverCurrent_DW.F_1 = true;

        /* Transition: '<S1>:604' */
        /* Transition: '<S1>:603' */
      } else {
        guard11 = true;
      }
    } else {
      guard11 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (guard11 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                   ChargeOverCurrent_P.Chart1_ThresholdFault_1 *
                   ChargeOverCurrent_U.curtValue_e) &&
                  (!ChargeOverCurrent_DW.F_1))) {
    /* Transition: '<S1>:598' */
    /* Transition: '<S1>:601' */
    ChargeOverCurrent_DW.t1 = 0U;

    /* Transition: '<S1>:603' */
  } else {
    /* Transition: '<S1>:599' */
  }

  if (guard10 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g >
                   ChargeOverCurrent_P.Chart1_ThresholdRecover_1 *
                   ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_1))
  {
    /* Transition: '<S1>:511' */
    /* Transition: '<S1>:520' */
    ChargeOverCurrent_DW.t11 = 0U;

    /* Transition: '<S1>:518' */
  } else {
    /* Transition: '<S1>:512' */
  }

  /* During 'F_2': '<S1>:298' */
  /* Transition: '<S1>:554' */
  guard10 = false;
  guard11 = false;
  if (!ChargeOverCurrent_DW.F_2) {
    /* Transition: '<S1>:406' */
    /* Exit Internal 'F_2': '<S1>:298' */
    /* Entry Internal 'F_2_true': '<S1>:361' */
    /* Transition: '<S1>:439' */
    ChargeOverCurrent_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
        ChargeOverCurrent_P.Chart1_ThresholdFault_2 *
        ChargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:434' */
      tmp = ChargeOverCurrent_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      ChargeOverCurrent_DW.t2 = (uint8_T)tmp;
      if (ChargeOverCurrent_DW.t2 > ChargeOverCurrent_P.Chart1_Second_2) {
        /* Transition: '<S1>:438' */
        /* Transition: '<S1>:436' */
        ChargeOverCurrent_DW.F_2 = true;
        ChargeOverCurrent_DW.t2 = 0U;

        /* Transition: '<S1>:431' */
        /* Transition: '<S1>:441' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:404' */
    /* Exit Internal 'F_2': '<S1>:298' */
    /* Entry Internal 'F_2_false': '<S1>:277' */
    /* Transition: '<S1>:476' */
    ChargeOverCurrent_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
         ChargeOverCurrent_P.Chart1_ThresholdRecover_2 *
         ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_2) {
      /* Transition: '<S1>:483' */
      tmp = ChargeOverCurrent_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      ChargeOverCurrent_DW.t22 = (uint8_T)tmp;
      if (ChargeOverCurrent_DW.t22 > ChargeOverCurrent_P.Chart1_Second_22) {
        /* Transition: '<S1>:478' */
        /* Transition: '<S1>:487' */
        ChargeOverCurrent_DW.F_2 = false;
        ChargeOverCurrent_DW.t22 = 0U;

        /* Transition: '<S1>:475' */
        /* Transition: '<S1>:480' */
      } else {
        guard11 = true;
      }
    } else {
      guard11 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (guard11 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g >
                   ChargeOverCurrent_P.Chart1_ThresholdRecover_2 *
                   ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_2))
  {
    /* Transition: '<S1>:474' */
    /* Transition: '<S1>:488' */
    ChargeOverCurrent_DW.t22 = 0U;
    ChargeOverCurrent_DW.t1 = 0U;

    /* Transition: '<S1>:480' */
  } else {
    /* Transition: '<S1>:485' */
  }

  if (guard10 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                   ChargeOverCurrent_P.Chart1_ThresholdFault_2 *
                   ChargeOverCurrent_U.curtValue_e) &&
                  (!ChargeOverCurrent_DW.F_2))) {
    /* Transition: '<S1>:440' */
    /* Transition: '<S1>:437' */
    ChargeOverCurrent_DW.t2 = 0U;

    /* Transition: '<S1>:441' */
  } else {
    /* Transition: '<S1>:432' */
  }

  /* During 'F_3': '<S1>:259' */
  /* Transition: '<S1>:549' */
  guard10 = false;
  guard11 = false;
  if (!ChargeOverCurrent_DW.F_3) {
    /* Transition: '<S1>:405' */
    /* Exit Internal 'F_3': '<S1>:259' */
    /* Entry Internal 'F_3_true': '<S1>:339' */
    /* Transition: '<S1>:442' */
    ChargeOverCurrent_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
        ChargeOverCurrent_P.Chart1_ThresholdFault_3 *
        ChargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:445' */
      tmp = ChargeOverCurrent_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      ChargeOverCurrent_DW.t3 = (uint8_T)tmp;
      if (ChargeOverCurrent_DW.t3 > ChargeOverCurrent_P.Chart1_Second_3) {
        /* Transition: '<S1>:453' */
        /* Transition: '<S1>:455' */
        ChargeOverCurrent_DW.F_3 = true;
        ChargeOverCurrent_DW.t3 = 0U;

        /* Transition: '<S1>:457' */
        /* Transition: '<S1>:456' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:382' */
    /* Exit Internal 'F_3': '<S1>:259' */
    /* Entry Internal 'F_3_false': '<S1>:383' */
    /* Transition: '<S1>:497' */
    ChargeOverCurrent_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
         ChargeOverCurrent_P.Chart1_ThresholdRecover_3 *
         ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_3) {
      /* Transition: '<S1>:491' */
      tmp = ChargeOverCurrent_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      ChargeOverCurrent_DW.t33 = (uint8_T)tmp;
      if (ChargeOverCurrent_DW.t33 > ChargeOverCurrent_P.Chart1_Second_33) {
        /* Transition: '<S1>:502' */
        /* Transition: '<S1>:492' */
        ChargeOverCurrent_DW.F_3 = false;
        ChargeOverCurrent_DW.t33 = 0U;

        /* Transition: '<S1>:505' */
        /* Transition: '<S1>:501' */
      } else {
        guard11 = true;
      }
    } else {
      guard11 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (guard11 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g >
                   ChargeOverCurrent_P.Chart1_ThresholdRecover_3 *
                   ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_3))
  {
    /* Transition: '<S1>:500' */
    /* Transition: '<S1>:493' */
    ChargeOverCurrent_DW.t33 = 0U;
    ChargeOverCurrent_DW.t2 = 0U;
    ChargeOverCurrent_DW.t1 = 0U;

    /* Transition: '<S1>:501' */
  } else {
    /* Transition: '<S1>:499' */
  }

  if (guard10 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                   ChargeOverCurrent_P.Chart1_ThresholdFault_3 *
                   ChargeOverCurrent_U.curtValue_e) &&
                  (!ChargeOverCurrent_DW.F_3))) {
    /* Transition: '<S1>:447' */
    /* Transition: '<S1>:454' */
    ChargeOverCurrent_DW.t3 = 0U;

    /* Transition: '<S1>:456' */
  } else {
    /* Transition: '<S1>:452' */
  }

  /* During 'F_4': '<S1>:408' */
  /* Transition: '<S1>:258' */
  /* Exit Internal 'F_4': '<S1>:408' */
  /* Entry Internal 'F_4_true': '<S1>:605' */
  /* Transition: '<S1>:613' */
  guard10 = false;

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
      ChargeOverCurrent_P.Chart1_ThresholdFault_4 *
      ChargeOverCurrent_U.curtValue_e) {
    /* Transition: '<S1>:614' */
    tmp = ChargeOverCurrent_DW.t4 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    ChargeOverCurrent_DW.t4 = (uint8_T)tmp;
    if (ChargeOverCurrent_DW.t4 > ChargeOverCurrent_P.Chart1_Second_4) {
      /* Transition: '<S1>:618' */
      /* Transition: '<S1>:620' */
      ChargeOverCurrent_DW.F_4 = true;

      /* Transition: '<S1>:622' */
      /* Transition: '<S1>:621' */
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                   ChargeOverCurrent_P.Chart1_ThresholdFault_4 *
                   ChargeOverCurrent_U.curtValue_e) &&
                  (!ChargeOverCurrent_DW.F_4))) {
    /* Transition: '<S1>:616' */
    /* Transition: '<S1>:619' */
    ChargeOverCurrent_DW.t4 = 0U;

    /* Transition: '<S1>:621' */
  } else {
    /* Transition: '<S1>:617' */
  }

  /* During 'F_0': '<S1>:585' */
  /* Transition: '<S1>:558' */
  /* Exit Internal 'F_0': '<S1>:585' */
  /* Entry Internal 'F_0_true': '<S1>:559' */
  ChargeOv_inner_default_F_0_true(F_lev);
}

/* Model step function */
uint8_T ChargeOverCurrent_step(real32_T g_BatSysTotalCur, real32_T curtValue)
{
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  uint8_T F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  ChargeOverCurrent_U.g_BatSysTotalCur_g = g_BatSysTotalCur;

  /* Copy value for root inport '<Root>/In2' since it is accessed globally */
  ChargeOverCurrent_U.curtValue_e = curtValue;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (ChargeOverCurrent_DW.is_active_c1_ChargeOverCurrent == 0U) {
    /* Entry: Chart1 */
    ChargeOverCurrent_DW.is_active_c1_ChargeOverCurrent = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:409' */
    /* Entry Internal 'F': '<S1>:407' */
    /* Entry Internal 'F_1': '<S1>:360' */
    /* Transition: '<S1>:543' */
    if (ChargeOverCurrent_DW.F_1) {
      /* Transition: '<S1>:338' */
      /* Entry Internal 'F_1_false': '<S1>:320' */
      /* Transition: '<S1>:516' */
      ChargeOverCurrent_DW.F_1 = true;
      if ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
           ChargeOverCurrent_P.Chart1_ThresholdRecover_1 *
           ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_1) {
        /* Transition: '<S1>:508' */
        tmp = ChargeOverCurrent_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        ChargeOverCurrent_DW.t11 = (uint8_T)tmp;
        if (ChargeOverCurrent_DW.t11 > ChargeOverCurrent_P.Chart1_Second_11) {
          /* Transition: '<S1>:517' */
          /* Transition: '<S1>:519' */
          ChargeOverCurrent_DW.F_1 = false;
          ChargeOverCurrent_DW.t11 = 0U;

          /* Transition: '<S1>:521' */
          /* Transition: '<S1>:518' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:337' */
      /* Entry Internal 'F_1_true': '<S1>:587' */
      /* Transition: '<S1>:595' */
      if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
          ChargeOverCurrent_P.Chart1_ThresholdFault_1 *
          ChargeOverCurrent_U.curtValue_e) {
        /* Transition: '<S1>:597' */
        tmp = ChargeOverCurrent_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        ChargeOverCurrent_DW.t1 = (uint8_T)tmp;
        if (ChargeOverCurrent_DW.t1 > ChargeOverCurrent_P.Chart1_Second_1) {
          /* Transition: '<S1>:600' */
          /* Transition: '<S1>:602' */
          ChargeOverCurrent_DW.F_1 = true;

          /* Transition: '<S1>:604' */
          /* Transition: '<S1>:603' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                    ChargeOverCurrent_P.Chart1_ThresholdFault_1 *
                    ChargeOverCurrent_U.curtValue_e) &&
                   (!ChargeOverCurrent_DW.F_1))) {
      /* Transition: '<S1>:598' */
      /* Transition: '<S1>:601' */
      ChargeOverCurrent_DW.t1 = 0U;

      /* Transition: '<S1>:603' */
    } else {
      /* Transition: '<S1>:599' */
    }

    if (guard6 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g >
                    ChargeOverCurrent_P.Chart1_ThresholdRecover_1 *
                    ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_1))
    {
      /* Transition: '<S1>:511' */
      /* Transition: '<S1>:520' */
      ChargeOverCurrent_DW.t11 = 0U;

      /* Transition: '<S1>:518' */
    } else {
      /* Transition: '<S1>:512' */
    }

    /* Entry Internal 'F_2': '<S1>:298' */
    /* Transition: '<S1>:553' */
    guard6 = false;
    guard7 = false;
    if (!ChargeOverCurrent_DW.F_2) {
      /* Transition: '<S1>:406' */
      /* Entry Internal 'F_2_true': '<S1>:361' */
      /* Transition: '<S1>:439' */
      ChargeOverCurrent_DW.F_2 = false;
      if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
          ChargeOverCurrent_P.Chart1_ThresholdFault_2 *
          ChargeOverCurrent_U.curtValue_e) {
        /* Transition: '<S1>:434' */
        tmp = ChargeOverCurrent_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        ChargeOverCurrent_DW.t2 = (uint8_T)tmp;
        if (ChargeOverCurrent_DW.t2 > ChargeOverCurrent_P.Chart1_Second_2) {
          /* Transition: '<S1>:438' */
          /* Transition: '<S1>:436' */
          ChargeOverCurrent_DW.F_2 = true;
          ChargeOverCurrent_DW.t2 = 0U;

          /* Transition: '<S1>:431' */
          /* Transition: '<S1>:441' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:404' */
      /* Entry Internal 'F_2_false': '<S1>:277' */
      /* Transition: '<S1>:476' */
      ChargeOverCurrent_DW.F_2 = true;
      if ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
           ChargeOverCurrent_P.Chart1_ThresholdRecover_2 *
           ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_2) {
        /* Transition: '<S1>:483' */
        tmp = ChargeOverCurrent_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        ChargeOverCurrent_DW.t22 = (uint8_T)tmp;
        if (ChargeOverCurrent_DW.t22 > ChargeOverCurrent_P.Chart1_Second_22) {
          /* Transition: '<S1>:478' */
          /* Transition: '<S1>:487' */
          ChargeOverCurrent_DW.F_2 = false;
          ChargeOverCurrent_DW.t22 = 0U;

          /* Transition: '<S1>:475' */
          /* Transition: '<S1>:480' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g >
                    ChargeOverCurrent_P.Chart1_ThresholdRecover_2 *
                    ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_2))
    {
      /* Transition: '<S1>:474' */
      /* Transition: '<S1>:488' */
      ChargeOverCurrent_DW.t22 = 0U;
      ChargeOverCurrent_DW.t1 = 0U;

      /* Transition: '<S1>:480' */
    } else {
      /* Transition: '<S1>:485' */
    }

    if (guard6 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                    ChargeOverCurrent_P.Chart1_ThresholdFault_2 *
                    ChargeOverCurrent_U.curtValue_e) &&
                   (!ChargeOverCurrent_DW.F_2))) {
      /* Transition: '<S1>:440' */
      /* Transition: '<S1>:437' */
      ChargeOverCurrent_DW.t2 = 0U;

      /* Transition: '<S1>:441' */
    } else {
      /* Transition: '<S1>:432' */
    }

    /* Entry Internal 'F_3': '<S1>:259' */
    /* Transition: '<S1>:548' */
    guard6 = false;
    guard7 = false;
    if (!ChargeOverCurrent_DW.F_3) {
      /* Transition: '<S1>:405' */
      /* Entry Internal 'F_3_true': '<S1>:339' */
      /* Transition: '<S1>:442' */
      ChargeOverCurrent_DW.F_3 = false;
      if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
          ChargeOverCurrent_P.Chart1_ThresholdFault_3 *
          ChargeOverCurrent_U.curtValue_e) {
        /* Transition: '<S1>:445' */
        tmp = ChargeOverCurrent_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        ChargeOverCurrent_DW.t3 = (uint8_T)tmp;
        if (ChargeOverCurrent_DW.t3 > ChargeOverCurrent_P.Chart1_Second_3) {
          /* Transition: '<S1>:453' */
          /* Transition: '<S1>:455' */
          ChargeOverCurrent_DW.F_3 = true;
          ChargeOverCurrent_DW.t3 = 0U;

          /* Transition: '<S1>:457' */
          /* Transition: '<S1>:456' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:382' */
      /* Entry Internal 'F_3_false': '<S1>:383' */
      /* Transition: '<S1>:497' */
      ChargeOverCurrent_DW.F_3 = true;
      if ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
           ChargeOverCurrent_P.Chart1_ThresholdRecover_3 *
           ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_3) {
        /* Transition: '<S1>:491' */
        tmp = ChargeOverCurrent_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        ChargeOverCurrent_DW.t33 = (uint8_T)tmp;
        if (ChargeOverCurrent_DW.t33 > ChargeOverCurrent_P.Chart1_Second_33) {
          /* Transition: '<S1>:502' */
          /* Transition: '<S1>:492' */
          ChargeOverCurrent_DW.F_3 = false;
          ChargeOverCurrent_DW.t33 = 0U;

          /* Transition: '<S1>:505' */
          /* Transition: '<S1>:501' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g >
                    ChargeOverCurrent_P.Chart1_ThresholdRecover_3 *
                    ChargeOverCurrent_U.curtValue_e) && ChargeOverCurrent_DW.F_3))
    {
      /* Transition: '<S1>:500' */
      /* Transition: '<S1>:493' */
      ChargeOverCurrent_DW.t33 = 0U;
      ChargeOverCurrent_DW.t2 = 0U;
      ChargeOverCurrent_DW.t1 = 0U;

      /* Transition: '<S1>:501' */
    } else {
      /* Transition: '<S1>:499' */
    }

    if (guard6 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                    ChargeOverCurrent_P.Chart1_ThresholdFault_3 *
                    ChargeOverCurrent_U.curtValue_e) &&
                   (!ChargeOverCurrent_DW.F_3))) {
      /* Transition: '<S1>:447' */
      /* Transition: '<S1>:454' */
      ChargeOverCurrent_DW.t3 = 0U;

      /* Transition: '<S1>:456' */
    } else {
      /* Transition: '<S1>:452' */
    }

    /* Entry Internal 'F_4': '<S1>:408' */
    /* Entry Internal 'F_4_true': '<S1>:605' */
    /* Transition: '<S1>:613' */
    guard6 = false;
    if (ChargeOverCurrent_U.g_BatSysTotalCur_g >
        ChargeOverCurrent_P.Chart1_ThresholdFault_4 *
        ChargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:614' */
      tmp = ChargeOverCurrent_DW.t4 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      ChargeOverCurrent_DW.t4 = (uint8_T)tmp;
      if (ChargeOverCurrent_DW.t4 > ChargeOverCurrent_P.Chart1_Second_4) {
        /* Transition: '<S1>:618' */
        /* Transition: '<S1>:620' */
        ChargeOverCurrent_DW.F_4 = true;

        /* Transition: '<S1>:622' */
        /* Transition: '<S1>:621' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((ChargeOverCurrent_U.g_BatSysTotalCur_g <=
                    ChargeOverCurrent_P.Chart1_ThresholdFault_4 *
                    ChargeOverCurrent_U.curtValue_e) &&
                   (!ChargeOverCurrent_DW.F_4))) {
      /* Transition: '<S1>:616' */
      /* Transition: '<S1>:619' */
      ChargeOverCurrent_DW.t4 = 0U;

      /* Transition: '<S1>:621' */
    } else {
      /* Transition: '<S1>:617' */
    }

    /* Entry Internal 'F_0': '<S1>:585' */
    /* Entry Internal 'F_0_true': '<S1>:559' */
    ChargeOv_inner_default_F_0_true(&F_lev);
  } else {
    ChargeOverCurrent_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void ChargeOverCurrent_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ChargeOverCurrent_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&ChargeOverCurrent_DW, 0,
                sizeof(DW_ChargeOverCurrent_T));

  /* external inputs */
  (void) memset((void *)&ChargeOverCurrent_U, 0,
                sizeof(ExtU_ChargeOverCurrent_T));

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  ChargeOverCurrent_DW.is_active_c1_ChargeOverCurrent = 0U;
  ChargeOverCurrent_DW.t1 = 0U;
  ChargeOverCurrent_DW.t2 = 0U;
  ChargeOverCurrent_DW.t3 = 0U;
  ChargeOverCurrent_DW.t22 = 0U;
  ChargeOverCurrent_DW.t33 = 0U;
  ChargeOverCurrent_DW.t11 = 0U;
  ChargeOverCurrent_DW.t4 = 0U;
  ChargeOverCurrent_DW.F_1 = false;
  ChargeOverCurrent_DW.F_2 = false;
  ChargeOverCurrent_DW.F_3 = false;
  ChargeOverCurrent_DW.F_4 = false;
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
