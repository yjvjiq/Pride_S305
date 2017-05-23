/*
 * File: BatteryTemperatureLow.c
 *
 * Code generated for Simulink model 'BatteryTemperatureLow'.
 *
 * Model version                  : 1.107
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 09 10:08:34 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BatteryTemperatureLow.h"
#include "BatteryTemperatureLow_private.h"

/* Block states (auto storage) */
DW_BatteryTemperatureLow_T BatteryTemperatureLow_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_BatteryTemperatureLow_T BatteryTemperatureLow_U;

/* Real-time model */
RT_MODEL_BatteryTemperatureLo_T BatteryTemperatureLow_M_;
RT_MODEL_BatteryTemperatureLo_T *const BatteryTemperatureLow_M =
  &BatteryTemperatureLow_M_;

/* Forward declaration for local functions */
static void BatteryT_inner_default_F_0_true(uint8_T *F_lev);
static void BatteryTemperatureLow_F(uint8_T *F_lev);

/* Function for Chart: '<Root>/Chart1' */
static void BatteryT_inner_default_F_0_true(uint8_T *F_lev)
{
  /* Transition: '<S1>:507' */
  if (BatteryTemperatureLow_DW.F_4) {
    /* Transition: '<S1>:509' */
    /* Transition: '<S1>:512' */
    BatteryTemperatureLow_DW.F_2 = false;
    BatteryTemperatureLow_DW.F_3 = false;
    BatteryTemperatureLow_DW.F_1 = false;
    *F_lev = 4U;

    /* Transition: '<S1>:516' */
    /* Transition: '<S1>:515' */
    /* Transition: '<S1>:540' */
    /* Transition: '<S1>:541' */
  } else if (BatteryTemperatureLow_DW.F_3) {
    /* Transition: '<S1>:510' */
    /* Transition: '<S1>:514' */
    BatteryTemperatureLow_DW.F_1 = false;
    BatteryTemperatureLow_DW.F_2 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:515' */
    /* Transition: '<S1>:540' */
    /* Transition: '<S1>:541' */
  } else if (BatteryTemperatureLow_DW.F_2) {
    /* Transition: '<S1>:511' */
    /* Transition: '<S1>:513' */
    BatteryTemperatureLow_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:540' */
    /* Transition: '<S1>:541' */
  } else if (BatteryTemperatureLow_DW.F_1) {
    /* Transition: '<S1>:537' */
    /* Transition: '<S1>:538' */
    *F_lev = 1U;

    /* Transition: '<S1>:541' */
  } else {
    /* Transition: '<S1>:539' */
    *F_lev = 0U;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void BatteryTemperatureLow_F(uint8_T *F_lev)
{
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  int32_T tmp;

  /* During 'F': '<S1>:234' */
  /* During 'F_1': '<S1>:256' */
  /* Transition: '<S1>:521' */
  if (!BatteryTemperatureLow_DW.F_1) {
    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    /* Transition: '<S1>:385' */
    /* Exit Internal 'F_1': '<S1>:256' */
    /* Entry Internal 'F_1_true': '<S1>:561' */
    /* Transition: '<S1>:569' */
    if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
        BatteryTemperatureLow_P.Chart1_ThresholdFault_1) {
      /* Transition: '<S1>:571' */
      tmp = BatteryTemperatureLow_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureLow_DW.t1 = (uint8_T)tmp;
      if (BatteryTemperatureLow_DW.t1 > BatteryTemperatureLow_P.Chart1_Second_1)
      {
        /* Transition: '<S1>:574' */
        /* Transition: '<S1>:576' */
        BatteryTemperatureLow_DW.F_1 = true;

        /* Transition: '<S1>:578' */
        /* Transition: '<S1>:577' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:344' */
    /* Exit Internal 'F_1': '<S1>:256' */
    /* Entry Internal 'F_1_false': '<S1>:346' */
    /* Transition: '<S1>:485' */
    BatteryTemperatureLow_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
         BatteryTemperatureLow_P.Chart1_ThresholdRecover_1) &&
        BatteryTemperatureLow_DW.F_1) {
      /* Transition: '<S1>:488' */
      tmp = BatteryTemperatureLow_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureLow_DW.t11 = (uint8_T)tmp;
      if (BatteryTemperatureLow_DW.t11 >
          BatteryTemperatureLow_P.Chart1_Second_11) {
        /* Transition: '<S1>:494' */
        /* Transition: '<S1>:491' */
        BatteryTemperatureLow_DW.F_1 = false;
        BatteryTemperatureLow_DW.t11 = 0U;

        /* Transition: '<S1>:482' */
        /* Transition: '<S1>:483' */
      } else {
        guard11 = true;
      }
    } else {
      guard11 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   */
  if (guard11 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g <
                   BatteryTemperatureLow_P.Chart1_ThresholdRecover_1) &&
                  BatteryTemperatureLow_DW.F_1)) {
    /* Transition: '<S1>:486' */
    /* Transition: '<S1>:492' */
    BatteryTemperatureLow_DW.t11 = 0U;

    /* Transition: '<S1>:483' */
  } else {
    /* Transition: '<S1>:487' */
  }

  if (guard10 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                   BatteryTemperatureLow_P.Chart1_ThresholdFault_1) &&
                  (!BatteryTemperatureLow_DW.F_1))) {
    /* Transition: '<S1>:572' */
    /* Transition: '<S1>:575' */
    BatteryTemperatureLow_DW.t1 = 0U;

    /* Transition: '<S1>:577' */
  } else {
    /* Transition: '<S1>:573' */
  }

  /* During 'F_2': '<S1>:340' */
  /* Transition: '<S1>:531' */
  guard10 = false;
  guard11 = false;
  if (!BatteryTemperatureLow_DW.F_2) {
    /* Transition: '<S1>:342' */
    /* Exit Internal 'F_2': '<S1>:340' */
    /* Entry Internal 'F_2_true': '<S1>:319' */
    /* Transition: '<S1>:417' */
    BatteryTemperatureLow_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
        BatteryTemperatureLow_P.Chart1_ThresholdFault_2) {
      /* Transition: '<S1>:410' */
      tmp = BatteryTemperatureLow_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureLow_DW.t2 = (uint8_T)tmp;
      if (BatteryTemperatureLow_DW.t2 > BatteryTemperatureLow_P.Chart1_Second_2)
      {
        /* Transition: '<S1>:407' */
        /* Transition: '<S1>:415' */
        BatteryTemperatureLow_DW.F_2 = true;
        BatteryTemperatureLow_DW.t2 = 0U;

        /* Transition: '<S1>:411' */
        /* Transition: '<S1>:408' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:258' */
    /* Exit Internal 'F_2': '<S1>:340' */
    /* Entry Internal 'F_2_false': '<S1>:363' */
    /* Transition: '<S1>:464' */
    BatteryTemperatureLow_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
         BatteryTemperatureLow_P.Chart1_ThresholdRecover_2) &&
        BatteryTemperatureLow_DW.F_2) {
      /* Transition: '<S1>:454' */
      tmp = BatteryTemperatureLow_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureLow_DW.t22 = (uint8_T)tmp;
      if (BatteryTemperatureLow_DW.t22 >
          BatteryTemperatureLow_P.Chart1_Second_22) {
        /* Transition: '<S1>:450' */
        /* Transition: '<S1>:461' */
        BatteryTemperatureLow_DW.F_2 = false;
        BatteryTemperatureLow_DW.t22 = 0U;

        /* Transition: '<S1>:453' */
        /* Transition: '<S1>:456' */
      } else {
        guard11 = true;
      }
    } else {
      guard11 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   */
  if (guard11 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g <
                   BatteryTemperatureLow_P.Chart1_ThresholdRecover_2) &&
                  BatteryTemperatureLow_DW.F_2)) {
    /* Transition: '<S1>:463' */
    /* Transition: '<S1>:465' */
    BatteryTemperatureLow_DW.t22 = 0U;
    BatteryTemperatureLow_DW.t1 = 0U;

    /* Transition: '<S1>:456' */
  } else {
    /* Transition: '<S1>:462' */
  }

  if (guard10 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                   BatteryTemperatureLow_P.Chart1_ThresholdFault_2) &&
                  (!BatteryTemperatureLow_DW.F_2))) {
    /* Transition: '<S1>:402' */
    /* Transition: '<S1>:409' */
    BatteryTemperatureLow_DW.t2 = 0U;

    /* Transition: '<S1>:408' */
  } else {
    /* Transition: '<S1>:413' */
  }

  /* During 'F_3': '<S1>:341' */
  /* Transition: '<S1>:526' */
  guard10 = false;
  guard11 = false;
  if (!BatteryTemperatureLow_DW.F_3) {
    /* Transition: '<S1>:384' */
    /* Exit Internal 'F_3': '<S1>:341' */
    /* Entry Internal 'F_3_true': '<S1>:235' */
    /* Transition: '<S1>:420' */
    BatteryTemperatureLow_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
        BatteryTemperatureLow_P.Chart1_ThresholdFault_3) {
      /* Transition: '<S1>:427' */
      tmp = BatteryTemperatureLow_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureLow_DW.t3 = (uint8_T)tmp;
      if (BatteryTemperatureLow_DW.t3 > BatteryTemperatureLow_P.Chart1_Second_3)
      {
        /* Transition: '<S1>:432' */
        /* Transition: '<S1>:429' */
        BatteryTemperatureLow_DW.F_3 = true;
        BatteryTemperatureLow_DW.t3 = 0U;

        /* Transition: '<S1>:430' */
        /* Transition: '<S1>:431' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:257' */
    /* Exit Internal 'F_3': '<S1>:341' */
    /* Entry Internal 'F_3_false': '<S1>:259' */
    /* Transition: '<S1>:474' */
    BatteryTemperatureLow_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
         BatteryTemperatureLow_P.Chart1_ThresholdRecover_3) &&
        BatteryTemperatureLow_DW.F_3) {
      /* Transition: '<S1>:472' */
      tmp = BatteryTemperatureLow_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureLow_DW.t33 = (uint8_T)tmp;
      if (BatteryTemperatureLow_DW.t33 >
          BatteryTemperatureLow_P.Chart1_Second_33) {
        /* Transition: '<S1>:473' */
        /* Transition: '<S1>:476' */
        BatteryTemperatureLow_DW.F_3 = false;
        BatteryTemperatureLow_DW.t33 = 0U;

        /* Transition: '<S1>:475' */
        /* Transition: '<S1>:471' */
      } else {
        guard11 = true;
      }
    } else {
      guard11 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   */
  if (guard11 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g <
                   BatteryTemperatureLow_P.Chart1_ThresholdRecover_3) &&
                  BatteryTemperatureLow_DW.F_3)) {
    /* Transition: '<S1>:470' */
    /* Transition: '<S1>:477' */
    BatteryTemperatureLow_DW.t33 = 0U;
    BatteryTemperatureLow_DW.t1 = 0U;
    BatteryTemperatureLow_DW.t2 = 0U;

    /* Transition: '<S1>:471' */
  } else {
    /* Transition: '<S1>:478' */
  }

  if (guard10 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                   BatteryTemperatureLow_P.Chart1_ThresholdFault_3) &&
                  (!BatteryTemperatureLow_DW.F_3))) {
    /* Transition: '<S1>:419' */
    /* Transition: '<S1>:428' */
    BatteryTemperatureLow_DW.t3 = 0U;

    /* Transition: '<S1>:431' */
  } else {
    /* Transition: '<S1>:433' */
  }

  /* During 'F_4': '<S1>:301' */
  /* Transition: '<S1>:343' */
  /* Exit Internal 'F_4': '<S1>:301' */
  /* Entry Internal 'F_4_true': '<S1>:543' */
  /* Transition: '<S1>:551' */
  guard10 = false;

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   */
  if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
      BatteryTemperatureLow_P.Chart1_ThresholdFault_4) {
    /* Transition: '<S1>:553' */
    tmp = BatteryTemperatureLow_DW.t4 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    BatteryTemperatureLow_DW.t4 = (uint8_T)tmp;
    if (BatteryTemperatureLow_DW.t4 > BatteryTemperatureLow_P.Chart1_Second_4) {
      /* Transition: '<S1>:556' */
      /* Transition: '<S1>:558' */
      BatteryTemperatureLow_DW.F_4 = true;

      /* Transition: '<S1>:560' */
      /* Transition: '<S1>:559' */
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                   BatteryTemperatureLow_P.Chart1_ThresholdFault_4) &&
                  (!BatteryTemperatureLow_DW.F_4))) {
    /* Transition: '<S1>:554' */
    /* Transition: '<S1>:557' */
    BatteryTemperatureLow_DW.t4 = 0U;

    /* Transition: '<S1>:559' */
  } else {
    /* Transition: '<S1>:555' */
  }

  /* During 'F_0': '<S1>:498' */
  /* Transition: '<S1>:517' */
  /* Exit Internal 'F_0': '<S1>:498' */
  /* Entry Internal 'F_0_true': '<S1>:499' */
  BatteryT_inner_default_F_0_true(F_lev);
}

/* Model step function */
uint8_T BatteryTemperatureLow_step(uint8_T g_BatLowestTemp)
{
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  uint8_T F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  BatteryTemperatureLow_U.g_BatLowestTemp_g = g_BatLowestTemp;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (BatteryTemperatureLow_DW.is_active_c1_BatteryTemperature == 0U) {
    /* Entry: Chart1 */
    BatteryTemperatureLow_DW.is_active_c1_BatteryTemperature = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:345' */
    /* Entry Internal 'F': '<S1>:234' */
    /* Entry Internal 'F_1': '<S1>:256' */
    /* Transition: '<S1>:520' */
    if (!BatteryTemperatureLow_DW.F_1) {
      /* Transition: '<S1>:385' */
      /* Entry Internal 'F_1_true': '<S1>:561' */
      /* Transition: '<S1>:569' */
      if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
          BatteryTemperatureLow_P.Chart1_ThresholdFault_1) {
        /* Transition: '<S1>:571' */
        tmp = BatteryTemperatureLow_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureLow_DW.t1 = (uint8_T)tmp;
        if (BatteryTemperatureLow_DW.t1 >
            BatteryTemperatureLow_P.Chart1_Second_1) {
          /* Transition: '<S1>:574' */
          /* Transition: '<S1>:576' */
          BatteryTemperatureLow_DW.F_1 = true;

          /* Transition: '<S1>:578' */
          /* Transition: '<S1>:577' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:344' */
      /* Entry Internal 'F_1_false': '<S1>:346' */
      /* Transition: '<S1>:485' */
      BatteryTemperatureLow_DW.F_1 = true;
      if ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
           BatteryTemperatureLow_P.Chart1_ThresholdRecover_1) &&
          BatteryTemperatureLow_DW.F_1) {
        /* Transition: '<S1>:488' */
        tmp = BatteryTemperatureLow_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureLow_DW.t11 = (uint8_T)tmp;
        if (BatteryTemperatureLow_DW.t11 >
            BatteryTemperatureLow_P.Chart1_Second_11) {
          /* Transition: '<S1>:494' */
          /* Transition: '<S1>:491' */
          BatteryTemperatureLow_DW.F_1 = false;
          BatteryTemperatureLow_DW.t11 = 0U;

          /* Transition: '<S1>:482' */
          /* Transition: '<S1>:483' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g <
                    BatteryTemperatureLow_P.Chart1_ThresholdRecover_1) &&
                   BatteryTemperatureLow_DW.F_1)) {
      /* Transition: '<S1>:486' */
      /* Transition: '<S1>:492' */
      BatteryTemperatureLow_DW.t11 = 0U;

      /* Transition: '<S1>:483' */
    } else {
      /* Transition: '<S1>:487' */
    }

    if (guard6 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                    BatteryTemperatureLow_P.Chart1_ThresholdFault_1) &&
                   (!BatteryTemperatureLow_DW.F_1))) {
      /* Transition: '<S1>:572' */
      /* Transition: '<S1>:575' */
      BatteryTemperatureLow_DW.t1 = 0U;

      /* Transition: '<S1>:577' */
    } else {
      /* Transition: '<S1>:573' */
    }

    /* Entry Internal 'F_2': '<S1>:340' */
    /* Transition: '<S1>:530' */
    guard6 = false;
    guard7 = false;
    if (!BatteryTemperatureLow_DW.F_2) {
      /* Transition: '<S1>:342' */
      /* Entry Internal 'F_2_true': '<S1>:319' */
      /* Transition: '<S1>:417' */
      BatteryTemperatureLow_DW.F_2 = false;
      if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
          BatteryTemperatureLow_P.Chart1_ThresholdFault_2) {
        /* Transition: '<S1>:410' */
        tmp = BatteryTemperatureLow_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureLow_DW.t2 = (uint8_T)tmp;
        if (BatteryTemperatureLow_DW.t2 >
            BatteryTemperatureLow_P.Chart1_Second_2) {
          /* Transition: '<S1>:407' */
          /* Transition: '<S1>:415' */
          BatteryTemperatureLow_DW.F_2 = true;
          BatteryTemperatureLow_DW.t2 = 0U;

          /* Transition: '<S1>:411' */
          /* Transition: '<S1>:408' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:258' */
      /* Entry Internal 'F_2_false': '<S1>:363' */
      /* Transition: '<S1>:464' */
      BatteryTemperatureLow_DW.F_2 = true;
      if ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
           BatteryTemperatureLow_P.Chart1_ThresholdRecover_2) &&
          BatteryTemperatureLow_DW.F_2) {
        /* Transition: '<S1>:454' */
        tmp = BatteryTemperatureLow_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureLow_DW.t22 = (uint8_T)tmp;
        if (BatteryTemperatureLow_DW.t22 >
            BatteryTemperatureLow_P.Chart1_Second_22) {
          /* Transition: '<S1>:450' */
          /* Transition: '<S1>:461' */
          BatteryTemperatureLow_DW.F_2 = false;
          BatteryTemperatureLow_DW.t22 = 0U;

          /* Transition: '<S1>:453' */
          /* Transition: '<S1>:456' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g <
                    BatteryTemperatureLow_P.Chart1_ThresholdRecover_2) &&
                   BatteryTemperatureLow_DW.F_2)) {
      /* Transition: '<S1>:463' */
      /* Transition: '<S1>:465' */
      BatteryTemperatureLow_DW.t22 = 0U;
      BatteryTemperatureLow_DW.t1 = 0U;

      /* Transition: '<S1>:456' */
    } else {
      /* Transition: '<S1>:462' */
    }

    if (guard6 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                    BatteryTemperatureLow_P.Chart1_ThresholdFault_2) &&
                   (!BatteryTemperatureLow_DW.F_2))) {
      /* Transition: '<S1>:402' */
      /* Transition: '<S1>:409' */
      BatteryTemperatureLow_DW.t2 = 0U;

      /* Transition: '<S1>:408' */
    } else {
      /* Transition: '<S1>:413' */
    }

    /* Entry Internal 'F_3': '<S1>:341' */
    /* Transition: '<S1>:525' */
    guard6 = false;
    guard7 = false;
    if (!BatteryTemperatureLow_DW.F_3) {
      /* Transition: '<S1>:384' */
      /* Entry Internal 'F_3_true': '<S1>:235' */
      /* Transition: '<S1>:420' */
      BatteryTemperatureLow_DW.F_3 = false;
      if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
          BatteryTemperatureLow_P.Chart1_ThresholdFault_3) {
        /* Transition: '<S1>:427' */
        tmp = BatteryTemperatureLow_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureLow_DW.t3 = (uint8_T)tmp;
        if (BatteryTemperatureLow_DW.t3 >
            BatteryTemperatureLow_P.Chart1_Second_3) {
          /* Transition: '<S1>:432' */
          /* Transition: '<S1>:429' */
          BatteryTemperatureLow_DW.F_3 = true;
          BatteryTemperatureLow_DW.t3 = 0U;

          /* Transition: '<S1>:430' */
          /* Transition: '<S1>:431' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:257' */
      /* Entry Internal 'F_3_false': '<S1>:259' */
      /* Transition: '<S1>:474' */
      BatteryTemperatureLow_DW.F_3 = true;
      if ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
           BatteryTemperatureLow_P.Chart1_ThresholdRecover_3) &&
          BatteryTemperatureLow_DW.F_3) {
        /* Transition: '<S1>:472' */
        tmp = BatteryTemperatureLow_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureLow_DW.t33 = (uint8_T)tmp;
        if (BatteryTemperatureLow_DW.t33 >
            BatteryTemperatureLow_P.Chart1_Second_33) {
          /* Transition: '<S1>:473' */
          /* Transition: '<S1>:476' */
          BatteryTemperatureLow_DW.F_3 = false;
          BatteryTemperatureLow_DW.t33 = 0U;

          /* Transition: '<S1>:475' */
          /* Transition: '<S1>:471' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g <
                    BatteryTemperatureLow_P.Chart1_ThresholdRecover_3) &&
                   BatteryTemperatureLow_DW.F_3)) {
      /* Transition: '<S1>:470' */
      /* Transition: '<S1>:477' */
      BatteryTemperatureLow_DW.t33 = 0U;
      BatteryTemperatureLow_DW.t1 = 0U;
      BatteryTemperatureLow_DW.t2 = 0U;

      /* Transition: '<S1>:471' */
    } else {
      /* Transition: '<S1>:478' */
    }

    if (guard6 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                    BatteryTemperatureLow_P.Chart1_ThresholdFault_3) &&
                   (!BatteryTemperatureLow_DW.F_3))) {
      /* Transition: '<S1>:419' */
      /* Transition: '<S1>:428' */
      BatteryTemperatureLow_DW.t3 = 0U;

      /* Transition: '<S1>:431' */
    } else {
      /* Transition: '<S1>:433' */
    }

    /* Entry Internal 'F_4': '<S1>:301' */
    /* Entry Internal 'F_4_true': '<S1>:543' */
    /* Transition: '<S1>:551' */
    guard6 = false;
    if (BatteryTemperatureLow_U.g_BatLowestTemp_g <
        BatteryTemperatureLow_P.Chart1_ThresholdFault_4) {
      /* Transition: '<S1>:553' */
      tmp = BatteryTemperatureLow_DW.t4 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureLow_DW.t4 = (uint8_T)tmp;
      if (BatteryTemperatureLow_DW.t4 > BatteryTemperatureLow_P.Chart1_Second_4)
      {
        /* Transition: '<S1>:556' */
        /* Transition: '<S1>:558' */
        BatteryTemperatureLow_DW.F_4 = true;

        /* Transition: '<S1>:560' */
        /* Transition: '<S1>:559' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((BatteryTemperatureLow_U.g_BatLowestTemp_g >=
                    BatteryTemperatureLow_P.Chart1_ThresholdFault_4) &&
                   (!BatteryTemperatureLow_DW.F_4))) {
      /* Transition: '<S1>:554' */
      /* Transition: '<S1>:557' */
      BatteryTemperatureLow_DW.t4 = 0U;

      /* Transition: '<S1>:559' */
    } else {
      /* Transition: '<S1>:555' */
    }

    /* Entry Internal 'F_0': '<S1>:498' */
    /* Entry Internal 'F_0_true': '<S1>:499' */
    BatteryT_inner_default_F_0_true(&F_lev);
  } else {
    BatteryTemperatureLow_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void BatteryTemperatureLow_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BatteryTemperatureLow_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&BatteryTemperatureLow_DW, 0,
                sizeof(DW_BatteryTemperatureLow_T));

  /* external inputs */
  BatteryTemperatureLow_U.g_BatLowestTemp_g = 0U;

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  BatteryTemperatureLow_DW.is_active_c1_BatteryTemperature = 0U;
  BatteryTemperatureLow_DW.t1 = 0U;
  BatteryTemperatureLow_DW.t2 = 0U;
  BatteryTemperatureLow_DW.t3 = 0U;
  BatteryTemperatureLow_DW.t22 = 0U;
  BatteryTemperatureLow_DW.t33 = 0U;
  BatteryTemperatureLow_DW.t11 = 0U;
  BatteryTemperatureLow_DW.t4 = 0U;
  BatteryTemperatureLow_DW.F_1 = false;
  BatteryTemperatureLow_DW.F_2 = false;
  BatteryTemperatureLow_DW.F_3 = false;
  BatteryTemperatureLow_DW.F_4 = false;
}

/* Model terminate function */
void BatteryTemperatureLow_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
