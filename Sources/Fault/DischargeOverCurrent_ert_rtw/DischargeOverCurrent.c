/*
 * File: DischargeOverCurrent.c
 *
 * Code generated for Simulink model 'DischargeOverCurrent'.
 *
 * Model version                  : 1.109
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 20 16:18:38 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DischargeOverCurrent.h"
#include "DischargeOverCurrent_private.h"

/* Block states (auto storage) */
DW_DischargeOverCurrent_T DischargeOverCurrent_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_DischargeOverCurrent_T DischargeOverCurrent_U;

/* Real-time model */
RT_MODEL_DischargeOverCurrent_T DischargeOverCurrent_M_;
RT_MODEL_DischargeOverCurrent_T *const DischargeOverCurrent_M =
  &DischargeOverCurrent_M_;

/* Forward declaration for local functions */
static void Discharg_inner_default_F_0_true(uint8_T *F_lev);
static void DischargeOverCurrent_F(uint8_T *F_lev);

/* Function for Chart: '<Root>/Chart1' */
static void Discharg_inner_default_F_0_true(uint8_T *F_lev)
{
  /* Transition: '<S1>:723' */
  if (DischargeOverCurrent_DW.F_4) {
    /* Transition: '<S1>:724' */
    /* Transition: '<S1>:729' */
    DischargeOverCurrent_DW.F_2 = false;
    DischargeOverCurrent_DW.F_3 = false;
    DischargeOverCurrent_DW.F_1 = false;
    *F_lev = 4U;

    /* Transition: '<S1>:737' */
    /* Transition: '<S1>:736' */
    /* Transition: '<S1>:735' */
    /* Transition: '<S1>:734' */
  } else if (DischargeOverCurrent_DW.F_3) {
    /* Transition: '<S1>:726' */
    /* Transition: '<S1>:731' */
    DischargeOverCurrent_DW.F_1 = false;
    DischargeOverCurrent_DW.F_2 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:736' */
    /* Transition: '<S1>:735' */
    /* Transition: '<S1>:734' */
  } else if (DischargeOverCurrent_DW.F_2) {
    /* Transition: '<S1>:727' */
    /* Transition: '<S1>:732' */
    DischargeOverCurrent_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:735' */
    /* Transition: '<S1>:734' */
  } else if (DischargeOverCurrent_DW.F_1) {
    /* Transition: '<S1>:728' */
    /* Transition: '<S1>:733' */
    *F_lev = 1U;

    /* Transition: '<S1>:734' */
  } else {
    /* Transition: '<S1>:730' */
    *F_lev = 0U;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void DischargeOverCurrent_F(uint8_T *F_lev)
{
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  int32_T tmp;

  /* During 'F': '<S1>:688' */
  /* During 'F_1': '<S1>:660' */
  /* Transition: '<S1>:687' */
  if (DischargeOverCurrent_DW.F_1) {
    /* Transition: '<S1>:711' */
    /* Exit Internal 'F_1': '<S1>:660' */
    /* Entry Internal 'F_1_false': '<S1>:740' */
    /* Transition: '<S1>:748' */
    DischargeOverCurrent_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
         DischargeOverCurrent_P.Chart1_ThresholdRecover_1 *
         DischargeOverCurrent_U.curtValue_e) && DischargeOverCurrent_DW.F_1) {
      /* Transition: '<S1>:749' */
      tmp = DischargeOverCurrent_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      DischargeOverCurrent_DW.t11 = (uint8_T)tmp;
      if (DischargeOverCurrent_DW.t11 > DischargeOverCurrent_P.Chart1_Second_11)
      {
        /* Transition: '<S1>:752' */
        /* Transition: '<S1>:755' */
        DischargeOverCurrent_DW.F_1 = false;
        DischargeOverCurrent_DW.t11 = 0U;

        /* Transition: '<S1>:757' */
        /* Transition: '<S1>:756' */
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
    /* Transition: '<S1>:619' */
    /* Exit Internal 'F_1': '<S1>:660' */
    /* Entry Internal 'F_1_true': '<S1>:758' */
    /* Transition: '<S1>:766' */
    if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
        DischargeOverCurrent_P.Chart1_ThresholdFault_1 *
        DischargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:768' */
      tmp = DischargeOverCurrent_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      DischargeOverCurrent_DW.t1 = (uint8_T)tmp;
      if (DischargeOverCurrent_DW.t1 > DischargeOverCurrent_P.Chart1_Second_1) {
        /* Transition: '<S1>:771' */
        /* Transition: '<S1>:773' */
        DischargeOverCurrent_DW.F_1 = true;

        /* Transition: '<S1>:775' */
        /* Transition: '<S1>:774' */
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
  if (guard11 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                   DischargeOverCurrent_P.Chart1_ThresholdFault_1 *
                   DischargeOverCurrent_U.curtValue_e) &&
                  (!DischargeOverCurrent_DW.F_1))) {
    /* Transition: '<S1>:769' */
    /* Transition: '<S1>:772' */
    DischargeOverCurrent_DW.t1 = 0U;

    /* Transition: '<S1>:774' */
  } else {
    /* Transition: '<S1>:770' */
  }

  if (guard10 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g >
                   DischargeOverCurrent_P.Chart1_ThresholdRecover_1 *
                   DischargeOverCurrent_U.curtValue_e) &&
                  DischargeOverCurrent_DW.F_1)) {
    /* Transition: '<S1>:751' */
    /* Transition: '<S1>:754' */
    DischargeOverCurrent_DW.t11 = 0U;

    /* Transition: '<S1>:756' */
  } else {
    /* Transition: '<S1>:753' */
  }

  /* During 'F_2': '<S1>:618' */
  /* Transition: '<S1>:658' */
  guard10 = false;
  guard11 = false;
  if (!DischargeOverCurrent_DW.F_2) {
    /* Transition: '<S1>:659' */
    /* Exit Internal 'F_2': '<S1>:618' */
    /* Entry Internal 'F_2_true': '<S1>:666' */
    /* Transition: '<S1>:674' */
    DischargeOverCurrent_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
        DischargeOverCurrent_P.Chart1_ThresholdFault_2 *
        DischargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:676' */
      tmp = DischargeOverCurrent_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      DischargeOverCurrent_DW.t2 = (uint8_T)tmp;
      if (DischargeOverCurrent_DW.t2 > DischargeOverCurrent_P.Chart1_Second_2) {
        /* Transition: '<S1>:679' */
        /* Transition: '<S1>:681' */
        DischargeOverCurrent_DW.F_2 = true;
        DischargeOverCurrent_DW.t2 = 0U;

        /* Transition: '<S1>:683' */
        /* Transition: '<S1>:682' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:664' */
    /* Exit Internal 'F_2': '<S1>:618' */
    /* Entry Internal 'F_2_false': '<S1>:621' */
    /* Transition: '<S1>:629' */
    DischargeOverCurrent_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
         DischargeOverCurrent_P.Chart1_ThresholdRecover_2 *
         DischargeOverCurrent_U.curtValue_e) && DischargeOverCurrent_DW.F_2) {
      /* Transition: '<S1>:631' */
      tmp = DischargeOverCurrent_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      DischargeOverCurrent_DW.t22 = (uint8_T)tmp;
      if (DischargeOverCurrent_DW.t22 > DischargeOverCurrent_P.Chart1_Second_22)
      {
        /* Transition: '<S1>:634' */
        /* Transition: '<S1>:636' */
        DischargeOverCurrent_DW.F_2 = false;
        DischargeOverCurrent_DW.t22 = 0U;

        /* Transition: '<S1>:638' */
        /* Transition: '<S1>:637' */
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
  if (guard11 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g >
                   DischargeOverCurrent_P.Chart1_ThresholdRecover_2 *
                   DischargeOverCurrent_U.curtValue_e) &&
                  DischargeOverCurrent_DW.F_2)) {
    /* Transition: '<S1>:632' */
    /* Transition: '<S1>:635' */
    DischargeOverCurrent_DW.t22 = 0U;
    DischargeOverCurrent_DW.t1 = 0U;

    /* Transition: '<S1>:637' */
  } else {
    /* Transition: '<S1>:633' */
  }

  if (guard10 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                   DischargeOverCurrent_P.Chart1_ThresholdFault_2 *
                   DischargeOverCurrent_U.curtValue_e) &&
                  (!DischargeOverCurrent_DW.F_2))) {
    /* Transition: '<S1>:677' */
    /* Transition: '<S1>:680' */
    DischargeOverCurrent_DW.t2 = 0U;

    /* Transition: '<S1>:682' */
  } else {
    /* Transition: '<S1>:678' */
  }

  /* During 'F_3': '<S1>:620' */
  /* Transition: '<S1>:661' */
  guard10 = false;
  guard11 = false;
  if (!DischargeOverCurrent_DW.F_3) {
    /* Transition: '<S1>:690' */
    /* Exit Internal 'F_3': '<S1>:620' */
    /* Entry Internal 'F_3_true': '<S1>:693' */
    /* Transition: '<S1>:701' */
    DischargeOverCurrent_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
        DischargeOverCurrent_P.Chart1_ThresholdFault_3 *
        DischargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:702' */
      tmp = DischargeOverCurrent_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      DischargeOverCurrent_DW.t3 = (uint8_T)tmp;
      if (DischargeOverCurrent_DW.t3 > DischargeOverCurrent_P.Chart1_Second_3) {
        /* Transition: '<S1>:706' */
        /* Transition: '<S1>:708' */
        DischargeOverCurrent_DW.F_3 = true;
        DischargeOverCurrent_DW.t3 = 0U;

        /* Transition: '<S1>:710' */
        /* Transition: '<S1>:709' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:689' */
    /* Exit Internal 'F_3': '<S1>:620' */
    /* Entry Internal 'F_3_false': '<S1>:639' */
    /* Transition: '<S1>:647' */
    DischargeOverCurrent_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
         DischargeOverCurrent_P.Chart1_ThresholdRecover_3 *
         DischargeOverCurrent_U.curtValue_e) && DischargeOverCurrent_DW.F_3) {
      /* Transition: '<S1>:648' */
      tmp = DischargeOverCurrent_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      DischargeOverCurrent_DW.t33 = (uint8_T)tmp;
      if (DischargeOverCurrent_DW.t33 > DischargeOverCurrent_P.Chart1_Second_33)
      {
        /* Transition: '<S1>:652' */
        /* Transition: '<S1>:654' */
        DischargeOverCurrent_DW.F_3 = false;
        DischargeOverCurrent_DW.t33 = 0U;

        /* Transition: '<S1>:656' */
        /* Transition: '<S1>:655' */
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
  if (guard11 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g >
                   DischargeOverCurrent_P.Chart1_ThresholdRecover_3 *
                   DischargeOverCurrent_U.curtValue_e) &&
                  DischargeOverCurrent_DW.F_3)) {
    /* Transition: '<S1>:650' */
    /* Transition: '<S1>:653' */
    DischargeOverCurrent_DW.t33 = 0U;
    DischargeOverCurrent_DW.t1 = 0U;
    DischargeOverCurrent_DW.t2 = 0U;

    /* Transition: '<S1>:655' */
  } else {
    /* Transition: '<S1>:651' */
  }

  if (guard10 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                   DischargeOverCurrent_P.Chart1_ThresholdFault_3 *
                   DischargeOverCurrent_U.curtValue_e) &&
                  (!DischargeOverCurrent_DW.F_3))) {
    /* Transition: '<S1>:704' */
    /* Transition: '<S1>:707' */
    DischargeOverCurrent_DW.t3 = 0U;

    /* Transition: '<S1>:709' */
  } else {
    /* Transition: '<S1>:705' */
  }

  /* During 'F_4': '<S1>:665' */
  /* Transition: '<S1>:657' */
  /* Exit Internal 'F_4': '<S1>:665' */
  /* Entry Internal 'F_4_true': '<S1>:776' */
  /* Transition: '<S1>:784' */
  guard10 = false;

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
      DischargeOverCurrent_P.Chart1_ThresholdFault_4 *
      DischargeOverCurrent_U.curtValue_e) {
    /* Transition: '<S1>:785' */
    tmp = DischargeOverCurrent_DW.t4 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    DischargeOverCurrent_DW.t4 = (uint8_T)tmp;
    if (DischargeOverCurrent_DW.t4 > DischargeOverCurrent_P.Chart1_Second_4) {
      /* Transition: '<S1>:789' */
      /* Transition: '<S1>:791' */
      DischargeOverCurrent_DW.F_4 = true;

      /* Transition: '<S1>:793' */
      /* Transition: '<S1>:792' */
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                   DischargeOverCurrent_P.Chart1_ThresholdFault_4 *
                   DischargeOverCurrent_U.curtValue_e) &&
                  (!DischargeOverCurrent_DW.F_4))) {
    /* Transition: '<S1>:787' */
    /* Transition: '<S1>:790' */
    DischargeOverCurrent_DW.t4 = 0U;

    /* Transition: '<S1>:792' */
  } else {
    /* Transition: '<S1>:788' */
  }

  /* During 'F_0': '<S1>:738' */
  /* Transition: '<S1>:663' */
  /* Exit Internal 'F_0': '<S1>:738' */
  /* Entry Internal 'F_0_true': '<S1>:712' */
  Discharg_inner_default_F_0_true(F_lev);
}

/* Model step function */
uint8_T DischargeOverCurrent_step(real32_T g_BatSysTotalCur, real32_T curtValue)
{
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  uint8_T F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  DischargeOverCurrent_U.g_BatSysTotalCur_g = g_BatSysTotalCur;

  /* Copy value for root inport '<Root>/In2' since it is accessed globally */
  DischargeOverCurrent_U.curtValue_e = curtValue;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (DischargeOverCurrent_DW.is_active_c1_DischargeOverCurre == 0U) {
    /* Entry: Chart1 */
    DischargeOverCurrent_DW.is_active_c1_DischargeOverCurre = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:685' */
    /* Entry Internal 'F': '<S1>:688' */
    /* Entry Internal 'F_1': '<S1>:660' */
    /* Transition: '<S1>:684' */
    if (DischargeOverCurrent_DW.F_1) {
      /* Transition: '<S1>:711' */
      /* Entry Internal 'F_1_false': '<S1>:740' */
      /* Transition: '<S1>:748' */
      DischargeOverCurrent_DW.F_1 = true;
      if ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
           DischargeOverCurrent_P.Chart1_ThresholdRecover_1 *
           DischargeOverCurrent_U.curtValue_e) && DischargeOverCurrent_DW.F_1) {
        /* Transition: '<S1>:749' */
        tmp = DischargeOverCurrent_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        DischargeOverCurrent_DW.t11 = (uint8_T)tmp;
        if (DischargeOverCurrent_DW.t11 >
            DischargeOverCurrent_P.Chart1_Second_11) {
          /* Transition: '<S1>:752' */
          /* Transition: '<S1>:755' */
          DischargeOverCurrent_DW.F_1 = false;
          DischargeOverCurrent_DW.t11 = 0U;

          /* Transition: '<S1>:757' */
          /* Transition: '<S1>:756' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:619' */
      /* Entry Internal 'F_1_true': '<S1>:758' */
      /* Transition: '<S1>:766' */
      if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
          DischargeOverCurrent_P.Chart1_ThresholdFault_1 *
          DischargeOverCurrent_U.curtValue_e) {
        /* Transition: '<S1>:768' */
        tmp = DischargeOverCurrent_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        DischargeOverCurrent_DW.t1 = (uint8_T)tmp;
        if (DischargeOverCurrent_DW.t1 > DischargeOverCurrent_P.Chart1_Second_1)
        {
          /* Transition: '<S1>:771' */
          /* Transition: '<S1>:773' */
          DischargeOverCurrent_DW.F_1 = true;

          /* Transition: '<S1>:775' */
          /* Transition: '<S1>:774' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                    DischargeOverCurrent_P.Chart1_ThresholdFault_1 *
                    DischargeOverCurrent_U.curtValue_e) &&
                   (!DischargeOverCurrent_DW.F_1))) {
      /* Transition: '<S1>:769' */
      /* Transition: '<S1>:772' */
      DischargeOverCurrent_DW.t1 = 0U;

      /* Transition: '<S1>:774' */
    } else {
      /* Transition: '<S1>:770' */
    }

    if (guard6 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g >
                    DischargeOverCurrent_P.Chart1_ThresholdRecover_1 *
                    DischargeOverCurrent_U.curtValue_e) &&
                   DischargeOverCurrent_DW.F_1)) {
      /* Transition: '<S1>:751' */
      /* Transition: '<S1>:754' */
      DischargeOverCurrent_DW.t11 = 0U;

      /* Transition: '<S1>:756' */
    } else {
      /* Transition: '<S1>:753' */
    }

    /* Entry Internal 'F_2': '<S1>:618' */
    /* Transition: '<S1>:691' */
    guard6 = false;
    guard7 = false;
    if (!DischargeOverCurrent_DW.F_2) {
      /* Transition: '<S1>:659' */
      /* Entry Internal 'F_2_true': '<S1>:666' */
      /* Transition: '<S1>:674' */
      DischargeOverCurrent_DW.F_2 = false;
      if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
          DischargeOverCurrent_P.Chart1_ThresholdFault_2 *
          DischargeOverCurrent_U.curtValue_e) {
        /* Transition: '<S1>:676' */
        tmp = DischargeOverCurrent_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        DischargeOverCurrent_DW.t2 = (uint8_T)tmp;
        if (DischargeOverCurrent_DW.t2 > DischargeOverCurrent_P.Chart1_Second_2)
        {
          /* Transition: '<S1>:679' */
          /* Transition: '<S1>:681' */
          DischargeOverCurrent_DW.F_2 = true;
          DischargeOverCurrent_DW.t2 = 0U;

          /* Transition: '<S1>:683' */
          /* Transition: '<S1>:682' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:664' */
      /* Entry Internal 'F_2_false': '<S1>:621' */
      /* Transition: '<S1>:629' */
      DischargeOverCurrent_DW.F_2 = true;
      if ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
           DischargeOverCurrent_P.Chart1_ThresholdRecover_2 *
           DischargeOverCurrent_U.curtValue_e) && DischargeOverCurrent_DW.F_2) {
        /* Transition: '<S1>:631' */
        tmp = DischargeOverCurrent_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        DischargeOverCurrent_DW.t22 = (uint8_T)tmp;
        if (DischargeOverCurrent_DW.t22 >
            DischargeOverCurrent_P.Chart1_Second_22) {
          /* Transition: '<S1>:634' */
          /* Transition: '<S1>:636' */
          DischargeOverCurrent_DW.F_2 = false;
          DischargeOverCurrent_DW.t22 = 0U;

          /* Transition: '<S1>:638' */
          /* Transition: '<S1>:637' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g >
                    DischargeOverCurrent_P.Chart1_ThresholdRecover_2 *
                    DischargeOverCurrent_U.curtValue_e) &&
                   DischargeOverCurrent_DW.F_2)) {
      /* Transition: '<S1>:632' */
      /* Transition: '<S1>:635' */
      DischargeOverCurrent_DW.t22 = 0U;
      DischargeOverCurrent_DW.t1 = 0U;

      /* Transition: '<S1>:637' */
    } else {
      /* Transition: '<S1>:633' */
    }

    if (guard6 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                    DischargeOverCurrent_P.Chart1_ThresholdFault_2 *
                    DischargeOverCurrent_U.curtValue_e) &&
                   (!DischargeOverCurrent_DW.F_2))) {
      /* Transition: '<S1>:677' */
      /* Transition: '<S1>:680' */
      DischargeOverCurrent_DW.t2 = 0U;

      /* Transition: '<S1>:682' */
    } else {
      /* Transition: '<S1>:678' */
    }

    /* Entry Internal 'F_3': '<S1>:620' */
    /* Transition: '<S1>:662' */
    guard6 = false;
    guard7 = false;
    if (!DischargeOverCurrent_DW.F_3) {
      /* Transition: '<S1>:690' */
      /* Entry Internal 'F_3_true': '<S1>:693' */
      /* Transition: '<S1>:701' */
      DischargeOverCurrent_DW.F_3 = false;
      if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
          DischargeOverCurrent_P.Chart1_ThresholdFault_3 *
          DischargeOverCurrent_U.curtValue_e) {
        /* Transition: '<S1>:702' */
        tmp = DischargeOverCurrent_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        DischargeOverCurrent_DW.t3 = (uint8_T)tmp;
        if (DischargeOverCurrent_DW.t3 > DischargeOverCurrent_P.Chart1_Second_3)
        {
          /* Transition: '<S1>:706' */
          /* Transition: '<S1>:708' */
          DischargeOverCurrent_DW.F_3 = true;
          DischargeOverCurrent_DW.t3 = 0U;

          /* Transition: '<S1>:710' */
          /* Transition: '<S1>:709' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:689' */
      /* Entry Internal 'F_3_false': '<S1>:639' */
      /* Transition: '<S1>:647' */
      DischargeOverCurrent_DW.F_3 = true;
      if ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
           DischargeOverCurrent_P.Chart1_ThresholdRecover_3 *
           DischargeOverCurrent_U.curtValue_e) && DischargeOverCurrent_DW.F_3) {
        /* Transition: '<S1>:648' */
        tmp = DischargeOverCurrent_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        DischargeOverCurrent_DW.t33 = (uint8_T)tmp;
        if (DischargeOverCurrent_DW.t33 >
            DischargeOverCurrent_P.Chart1_Second_33) {
          /* Transition: '<S1>:652' */
          /* Transition: '<S1>:654' */
          DischargeOverCurrent_DW.F_3 = false;
          DischargeOverCurrent_DW.t33 = 0U;

          /* Transition: '<S1>:656' */
          /* Transition: '<S1>:655' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g >
                    DischargeOverCurrent_P.Chart1_ThresholdRecover_3 *
                    DischargeOverCurrent_U.curtValue_e) &&
                   DischargeOverCurrent_DW.F_3)) {
      /* Transition: '<S1>:650' */
      /* Transition: '<S1>:653' */
      DischargeOverCurrent_DW.t33 = 0U;
      DischargeOverCurrent_DW.t1 = 0U;
      DischargeOverCurrent_DW.t2 = 0U;

      /* Transition: '<S1>:655' */
    } else {
      /* Transition: '<S1>:651' */
    }

    if (guard6 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                    DischargeOverCurrent_P.Chart1_ThresholdFault_3 *
                    DischargeOverCurrent_U.curtValue_e) &&
                   (!DischargeOverCurrent_DW.F_3))) {
      /* Transition: '<S1>:704' */
      /* Transition: '<S1>:707' */
      DischargeOverCurrent_DW.t3 = 0U;

      /* Transition: '<S1>:709' */
    } else {
      /* Transition: '<S1>:705' */
    }

    /* Entry Internal 'F_4': '<S1>:665' */
    /* Entry Internal 'F_4_true': '<S1>:776' */
    /* Transition: '<S1>:784' */
    guard6 = false;
    if (DischargeOverCurrent_U.g_BatSysTotalCur_g >
        DischargeOverCurrent_P.Chart1_ThresholdFault_4 *
        DischargeOverCurrent_U.curtValue_e) {
      /* Transition: '<S1>:785' */
      tmp = DischargeOverCurrent_DW.t4 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      DischargeOverCurrent_DW.t4 = (uint8_T)tmp;
      if (DischargeOverCurrent_DW.t4 > DischargeOverCurrent_P.Chart1_Second_4) {
        /* Transition: '<S1>:789' */
        /* Transition: '<S1>:791' */
        DischargeOverCurrent_DW.F_4 = true;

        /* Transition: '<S1>:793' */
        /* Transition: '<S1>:792' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((DischargeOverCurrent_U.g_BatSysTotalCur_g <=
                    DischargeOverCurrent_P.Chart1_ThresholdFault_4 *
                    DischargeOverCurrent_U.curtValue_e) &&
                   (!DischargeOverCurrent_DW.F_4))) {
      /* Transition: '<S1>:787' */
      /* Transition: '<S1>:790' */
      DischargeOverCurrent_DW.t4 = 0U;

      /* Transition: '<S1>:792' */
    } else {
      /* Transition: '<S1>:788' */
    }

    /* Entry Internal 'F_0': '<S1>:738' */
    /* Entry Internal 'F_0_true': '<S1>:712' */
    Discharg_inner_default_F_0_true(&F_lev);
  } else {
    DischargeOverCurrent_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void DischargeOverCurrent_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DischargeOverCurrent_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&DischargeOverCurrent_DW, 0,
                sizeof(DW_DischargeOverCurrent_T));

  /* external inputs */
  (void) memset((void *)&DischargeOverCurrent_U, 0,
                sizeof(ExtU_DischargeOverCurrent_T));

  /* Machine initializer */
  DischargeOverCurrent_DW.data = 0.0;

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  DischargeOverCurrent_DW.is_active_c1_DischargeOverCurre = 0U;
  DischargeOverCurrent_DW.t1 = 0U;
  DischargeOverCurrent_DW.t2 = 0U;
  DischargeOverCurrent_DW.t3 = 0U;
  DischargeOverCurrent_DW.t22 = 0U;
  DischargeOverCurrent_DW.t33 = 0U;
  DischargeOverCurrent_DW.t11 = 0U;
  DischargeOverCurrent_DW.t4 = 0U;
  DischargeOverCurrent_DW.F_1 = false;
  DischargeOverCurrent_DW.F_2 = false;
  DischargeOverCurrent_DW.F_3 = false;
  DischargeOverCurrent_DW.F_4 = false;
}

/* Model terminate function */
void DischargeOverCurrent_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
