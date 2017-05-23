/*
 * File: BatteryTemperatureHigh.c
 *
 * Code generated for Simulink model 'BatteryTemperatureHigh'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 09 10:08:01 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BatteryTemperatureHigh.h"
#include "BatteryTemperatureHigh_private.h"

/* Block states (auto storage) */
DW_BatteryTemperatureHigh_T BatteryTemperatureHigh_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_BatteryTemperatureHigh_T BatteryTemperatureHigh_U;

/* Real-time model */
RT_MODEL_BatteryTemperatureHi_T BatteryTemperatureHigh_M_;
RT_MODEL_BatteryTemperatureHi_T *const BatteryTemperatureHigh_M =
  &BatteryTemperatureHigh_M_;

/* Forward declaration for local functions */
static void BatteryT_inner_default_F_0_true(uint8_T *F_lev);
static void BatteryTemperatureHigh_F(uint8_T *F_lev);

/* Function for Chart: '<Root>/Chart1' */
static void BatteryT_inner_default_F_0_true(uint8_T *F_lev)
{
  /* Transition: '<S1>:514' */
  if (BatteryTemperatureHigh_DW.F_4) {
    /* Transition: '<S1>:516' */
    /* Transition: '<S1>:521' */
    BatteryTemperatureHigh_DW.F_2 = false;
    BatteryTemperatureHigh_DW.F_3 = false;
    BatteryTemperatureHigh_DW.F_1 = false;
    *F_lev = 4U;

    /* Transition: '<S1>:528' */
    /* Transition: '<S1>:527' */
    /* Transition: '<S1>:526' */
    /* Transition: '<S1>:525' */
  } else if (BatteryTemperatureHigh_DW.F_3) {
    /* Transition: '<S1>:517' */
    /* Transition: '<S1>:522' */
    BatteryTemperatureHigh_DW.F_1 = false;
    BatteryTemperatureHigh_DW.F_2 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:527' */
    /* Transition: '<S1>:526' */
    /* Transition: '<S1>:525' */
  } else if (BatteryTemperatureHigh_DW.F_2) {
    /* Transition: '<S1>:518' */
    /* Transition: '<S1>:523' */
    BatteryTemperatureHigh_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:526' */
    /* Transition: '<S1>:525' */
  } else if (BatteryTemperatureHigh_DW.F_1) {
    /* Transition: '<S1>:519' */
    /* Transition: '<S1>:524' */
    *F_lev = 1U;

    /* Transition: '<S1>:525' */
  } else {
    /* Transition: '<S1>:520' */
    *F_lev = 0U;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void BatteryTemperatureHigh_F(uint8_T *F_lev)
{
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  int32_T tmp;

  /* During 'F': '<S1>:351' */
  /* During 'F_1': '<S1>:201' */
  /* Transition: '<S1>:486' */
  if (BatteryTemperatureHigh_DW.F_1) {
    /* Transition: '<S1>:283' */
    /* Exit Internal 'F_1': '<S1>:201' */
    /* Entry Internal 'F_1_false': '<S1>:266' */
    /* Transition: '<S1>:455' */
    BatteryTemperatureHigh_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
         BatteryTemperatureHigh_P.Chart1_ThresholdRecover_1) &&
        BatteryTemperatureHigh_DW.F_1) {
      /* Transition: '<S1>:449' */
      tmp = BatteryTemperatureHigh_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureHigh_DW.t11 = (uint8_T)tmp;
      if (BatteryTemperatureHigh_DW.t11 >
          BatteryTemperatureHigh_P.Chart1_Second_11) {
        /* Transition: '<S1>:456' */
        /* Transition: '<S1>:458' */
        BatteryTemperatureHigh_DW.F_1 = false;
        BatteryTemperatureHigh_DW.t11 = 0U;

        /* Transition: '<S1>:460' */
        /* Transition: '<S1>:459' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    /* Transition: '<S1>:265' */
    /* Exit Internal 'F_1': '<S1>:201' */
    /* Entry Internal 'F_1_true': '<S1>:549' */
    /* Transition: '<S1>:557' */
    if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
        BatteryTemperatureHigh_P.Chart1_ThresholdFault_1) {
      /* Transition: '<S1>:559' */
      tmp = BatteryTemperatureHigh_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureHigh_DW.t1 = (uint8_T)tmp;
      if (BatteryTemperatureHigh_DW.t1 >
          BatteryTemperatureHigh_P.Chart1_Second_1) {
        /* Transition: '<S1>:562' */
        /* Transition: '<S1>:564' */
        BatteryTemperatureHigh_DW.F_1 = true;

        /* Transition: '<S1>:566' */
        /* Transition: '<S1>:565' */
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
  if (guard11 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                   BatteryTemperatureHigh_P.Chart1_ThresholdFault_1) &&
                  (!BatteryTemperatureHigh_DW.F_1))) {
    /* Transition: '<S1>:560' */
    /* Transition: '<S1>:563' */
    BatteryTemperatureHigh_DW.t1 = 0U;

    /* Transition: '<S1>:565' */
  } else {
    /* Transition: '<S1>:561' */
  }

  if (guard10 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
                   BatteryTemperatureHigh_P.Chart1_ThresholdRecover_1) &&
                  BatteryTemperatureHigh_DW.F_1)) {
    /* Transition: '<S1>:452' */
    /* Transition: '<S1>:457' */
    BatteryTemperatureHigh_DW.t11 = 0U;

    /* Transition: '<S1>:459' */
  } else {
    /* Transition: '<S1>:453' */
  }

  /* During 'F_2': '<S1>:309' */
  /* Transition: '<S1>:497' */
  guard10 = false;
  guard11 = false;
  if (!BatteryTemperatureHigh_DW.F_2) {
    /* Transition: '<S1>:352' */
    /* Exit Internal 'F_2': '<S1>:309' */
    /* Entry Internal 'F_2_true': '<S1>:287' */
    /* Transition: '<S1>:369' */
    BatteryTemperatureHigh_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
        BatteryTemperatureHigh_P.Chart1_ThresholdFault_2) {
      /* Transition: '<S1>:381' */
      tmp = BatteryTemperatureHigh_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureHigh_DW.t2 = (uint8_T)tmp;
      if (BatteryTemperatureHigh_DW.t2 >
          BatteryTemperatureHigh_P.Chart1_Second_2) {
        /* Transition: '<S1>:373' */
        /* Transition: '<S1>:382' */
        BatteryTemperatureHigh_DW.F_2 = true;
        BatteryTemperatureHigh_DW.t2 = 0U;

        /* Transition: '<S1>:378' */
        /* Transition: '<S1>:384' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:286' */
    /* Exit Internal 'F_2': '<S1>:309' */
    /* Entry Internal 'F_2_false': '<S1>:312' */
    /* Transition: '<S1>:418' */
    BatteryTemperatureHigh_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
         BatteryTemperatureHigh_P.Chart1_ThresholdRecover_2) &&
        BatteryTemperatureHigh_DW.F_2) {
      /* Transition: '<S1>:422' */
      tmp = BatteryTemperatureHigh_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureHigh_DW.t22 = (uint8_T)tmp;
      if (BatteryTemperatureHigh_DW.t22 >
          BatteryTemperatureHigh_P.Chart1_Second_22) {
        /* Transition: '<S1>:420' */
        /* Transition: '<S1>:424' */
        BatteryTemperatureHigh_DW.F_2 = false;
        BatteryTemperatureHigh_DW.t22 = 0U;

        /* Transition: '<S1>:417' */
        /* Transition: '<S1>:421' */
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
  if (guard11 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
                   BatteryTemperatureHigh_P.Chart1_ThresholdRecover_2) &&
                  BatteryTemperatureHigh_DW.F_2)) {
    /* Transition: '<S1>:430' */
    /* Transition: '<S1>:432' */
    BatteryTemperatureHigh_DW.t22 = 0U;
    BatteryTemperatureHigh_DW.t1 = 0U;

    /* Transition: '<S1>:421' */
  } else {
    /* Transition: '<S1>:425' */
  }

  if (guard10 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                   BatteryTemperatureHigh_P.Chart1_ThresholdFault_2) &&
                  (!BatteryTemperatureHigh_DW.F_2))) {
    /* Transition: '<S1>:374' */
    /* Transition: '<S1>:379' */
    BatteryTemperatureHigh_DW.t2 = 0U;

    /* Transition: '<S1>:384' */
  } else {
    /* Transition: '<S1>:377' */
  }

  /* During 'F_3': '<S1>:310' */
  /* Transition: '<S1>:492' */
  guard10 = false;
  guard11 = false;
  if (!BatteryTemperatureHigh_DW.F_3) {
    /* Transition: '<S1>:284' */
    /* Exit Internal 'F_3': '<S1>:310' */
    /* Entry Internal 'F_3_true': '<S1>:223' */
    /* Transition: '<S1>:399' */
    BatteryTemperatureHigh_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
        BatteryTemperatureHigh_P.Chart1_ThresholdFault_3) {
      /* Transition: '<S1>:390' */
      tmp = BatteryTemperatureHigh_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureHigh_DW.t3 = (uint8_T)tmp;
      if (BatteryTemperatureHigh_DW.t3 >
          BatteryTemperatureHigh_P.Chart1_Second_3) {
        /* Transition: '<S1>:389' */
        /* Transition: '<S1>:391' */
        BatteryTemperatureHigh_DW.F_3 = true;
        BatteryTemperatureHigh_DW.t3 = 0U;

        /* Transition: '<S1>:396' */
        /* Transition: '<S1>:392' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:285' */
    /* Exit Internal 'F_3': '<S1>:310' */
    /* Entry Internal 'F_3_false': '<S1>:202' */
    /* Transition: '<S1>:444' */
    BatteryTemperatureHigh_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
         BatteryTemperatureHigh_P.Chart1_ThresholdRecover_3) &&
        BatteryTemperatureHigh_DW.F_3) {
      /* Transition: '<S1>:442' */
      tmp = BatteryTemperatureHigh_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureHigh_DW.t33 = (uint8_T)tmp;
      if (BatteryTemperatureHigh_DW.t33 >
          BatteryTemperatureHigh_P.Chart1_Second_33) {
        /* Transition: '<S1>:441' */
        /* Transition: '<S1>:443' */
        BatteryTemperatureHigh_DW.F_3 = false;
        BatteryTemperatureHigh_DW.t33 = 0U;

        /* Transition: '<S1>:448' */
        /* Transition: '<S1>:446' */
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
  if (guard11 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
                   BatteryTemperatureHigh_P.Chart1_ThresholdRecover_3) &&
                  BatteryTemperatureHigh_DW.F_3)) {
    /* Transition: '<S1>:439' */
    /* Transition: '<S1>:440' */
    BatteryTemperatureHigh_DW.t33 = 0U;
    BatteryTemperatureHigh_DW.t1 = 0U;
    BatteryTemperatureHigh_DW.t2 = 0U;

    /* Transition: '<S1>:446' */
  } else {
    /* Transition: '<S1>:447' */
  }

  if (guard10 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                   BatteryTemperatureHigh_P.Chart1_ThresholdFault_3) &&
                  (!BatteryTemperatureHigh_DW.F_3))) {
    /* Transition: '<S1>:394' */
    /* Transition: '<S1>:395' */
    BatteryTemperatureHigh_DW.t3 = 0U;

    /* Transition: '<S1>:392' */
  } else {
    /* Transition: '<S1>:393' */
  }

  /* During 'F_44': '<S1>:311' */
  /* Transition: '<S1>:308' */
  /* Exit Internal 'F_44': '<S1>:311' */
  /* Entry Internal 'F_4_true': '<S1>:531' */
  /* Transition: '<S1>:539' */
  guard10 = false;

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   */
  if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
      BatteryTemperatureHigh_P.Chart1_ThresholdFault_4) {
    /* Transition: '<S1>:540' */
    tmp = BatteryTemperatureHigh_DW.t4 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    BatteryTemperatureHigh_DW.t4 = (uint8_T)tmp;
    if (BatteryTemperatureHigh_DW.t4 > BatteryTemperatureHigh_P.Chart1_Second_4)
    {
      /* Transition: '<S1>:544' */
      /* Transition: '<S1>:546' */
      BatteryTemperatureHigh_DW.F_4 = true;

      /* Transition: '<S1>:548' */
      /* Transition: '<S1>:547' */
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                   BatteryTemperatureHigh_P.Chart1_ThresholdFault_4) &&
                  (!BatteryTemperatureHigh_DW.F_4))) {
    /* Transition: '<S1>:542' */
    /* Transition: '<S1>:545' */
    BatteryTemperatureHigh_DW.t4 = 0U;

    /* Transition: '<S1>:547' */
  } else {
    /* Transition: '<S1>:543' */
  }

  /* During 'F_0': '<S1>:529' */
  /* Transition: '<S1>:502' */
  /* Exit Internal 'F_0': '<S1>:529' */
  /* Entry Internal 'F_0_true': '<S1>:503' */
  BatteryT_inner_default_F_0_true(F_lev);
}

/* Model step function */
uint8_T BatteryTemperatureHigh_step(uint8_T g_BatHighestTemp)
{
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  uint8_T F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  BatteryTemperatureHigh_U.g_BatHighestTemp_g = g_BatHighestTemp;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (BatteryTemperatureHigh_DW.is_active_c1_BatteryTemperature == 0U) {
    /* Entry: Chart1 */
    BatteryTemperatureHigh_DW.is_active_c1_BatteryTemperature = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:333' */
    /* Entry Internal 'F': '<S1>:351' */
    /* Entry Internal 'F_1': '<S1>:201' */
    /* Transition: '<S1>:485' */
    if (BatteryTemperatureHigh_DW.F_1) {
      /* Transition: '<S1>:283' */
      /* Entry Internal 'F_1_false': '<S1>:266' */
      /* Transition: '<S1>:455' */
      BatteryTemperatureHigh_DW.F_1 = true;
      if ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
           BatteryTemperatureHigh_P.Chart1_ThresholdRecover_1) &&
          BatteryTemperatureHigh_DW.F_1) {
        /* Transition: '<S1>:449' */
        tmp = BatteryTemperatureHigh_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureHigh_DW.t11 = (uint8_T)tmp;
        if (BatteryTemperatureHigh_DW.t11 >
            BatteryTemperatureHigh_P.Chart1_Second_11) {
          /* Transition: '<S1>:456' */
          /* Transition: '<S1>:458' */
          BatteryTemperatureHigh_DW.F_1 = false;
          BatteryTemperatureHigh_DW.t11 = 0U;

          /* Transition: '<S1>:460' */
          /* Transition: '<S1>:459' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:265' */
      /* Entry Internal 'F_1_true': '<S1>:549' */
      /* Transition: '<S1>:557' */
      if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
          BatteryTemperatureHigh_P.Chart1_ThresholdFault_1) {
        /* Transition: '<S1>:559' */
        tmp = BatteryTemperatureHigh_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureHigh_DW.t1 = (uint8_T)tmp;
        if (BatteryTemperatureHigh_DW.t1 >
            BatteryTemperatureHigh_P.Chart1_Second_1) {
          /* Transition: '<S1>:562' */
          /* Transition: '<S1>:564' */
          BatteryTemperatureHigh_DW.F_1 = true;

          /* Transition: '<S1>:566' */
          /* Transition: '<S1>:565' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                    BatteryTemperatureHigh_P.Chart1_ThresholdFault_1) &&
                   (!BatteryTemperatureHigh_DW.F_1))) {
      /* Transition: '<S1>:560' */
      /* Transition: '<S1>:563' */
      BatteryTemperatureHigh_DW.t1 = 0U;

      /* Transition: '<S1>:565' */
    } else {
      /* Transition: '<S1>:561' */
    }

    if (guard6 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
                    BatteryTemperatureHigh_P.Chart1_ThresholdRecover_1) &&
                   BatteryTemperatureHigh_DW.F_1)) {
      /* Transition: '<S1>:452' */
      /* Transition: '<S1>:457' */
      BatteryTemperatureHigh_DW.t11 = 0U;

      /* Transition: '<S1>:459' */
    } else {
      /* Transition: '<S1>:453' */
    }

    /* Entry Internal 'F_2': '<S1>:309' */
    /* Transition: '<S1>:496' */
    guard6 = false;
    guard7 = false;
    if (!BatteryTemperatureHigh_DW.F_2) {
      /* Transition: '<S1>:352' */
      /* Entry Internal 'F_2_true': '<S1>:287' */
      /* Transition: '<S1>:369' */
      BatteryTemperatureHigh_DW.F_2 = false;
      if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
          BatteryTemperatureHigh_P.Chart1_ThresholdFault_2) {
        /* Transition: '<S1>:381' */
        tmp = BatteryTemperatureHigh_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureHigh_DW.t2 = (uint8_T)tmp;
        if (BatteryTemperatureHigh_DW.t2 >
            BatteryTemperatureHigh_P.Chart1_Second_2) {
          /* Transition: '<S1>:373' */
          /* Transition: '<S1>:382' */
          BatteryTemperatureHigh_DW.F_2 = true;
          BatteryTemperatureHigh_DW.t2 = 0U;

          /* Transition: '<S1>:378' */
          /* Transition: '<S1>:384' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:286' */
      /* Entry Internal 'F_2_false': '<S1>:312' */
      /* Transition: '<S1>:418' */
      BatteryTemperatureHigh_DW.F_2 = true;
      if ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
           BatteryTemperatureHigh_P.Chart1_ThresholdRecover_2) &&
          BatteryTemperatureHigh_DW.F_2) {
        /* Transition: '<S1>:422' */
        tmp = BatteryTemperatureHigh_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureHigh_DW.t22 = (uint8_T)tmp;
        if (BatteryTemperatureHigh_DW.t22 >
            BatteryTemperatureHigh_P.Chart1_Second_22) {
          /* Transition: '<S1>:420' */
          /* Transition: '<S1>:424' */
          BatteryTemperatureHigh_DW.F_2 = false;
          BatteryTemperatureHigh_DW.t22 = 0U;

          /* Transition: '<S1>:417' */
          /* Transition: '<S1>:421' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
                    BatteryTemperatureHigh_P.Chart1_ThresholdRecover_2) &&
                   BatteryTemperatureHigh_DW.F_2)) {
      /* Transition: '<S1>:430' */
      /* Transition: '<S1>:432' */
      BatteryTemperatureHigh_DW.t22 = 0U;
      BatteryTemperatureHigh_DW.t1 = 0U;

      /* Transition: '<S1>:421' */
    } else {
      /* Transition: '<S1>:425' */
    }

    if (guard6 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                    BatteryTemperatureHigh_P.Chart1_ThresholdFault_2) &&
                   (!BatteryTemperatureHigh_DW.F_2))) {
      /* Transition: '<S1>:374' */
      /* Transition: '<S1>:379' */
      BatteryTemperatureHigh_DW.t2 = 0U;

      /* Transition: '<S1>:384' */
    } else {
      /* Transition: '<S1>:377' */
    }

    /* Entry Internal 'F_3': '<S1>:310' */
    /* Transition: '<S1>:490' */
    guard6 = false;
    guard7 = false;
    if (!BatteryTemperatureHigh_DW.F_3) {
      /* Transition: '<S1>:284' */
      /* Entry Internal 'F_3_true': '<S1>:223' */
      /* Transition: '<S1>:399' */
      BatteryTemperatureHigh_DW.F_3 = false;
      if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
          BatteryTemperatureHigh_P.Chart1_ThresholdFault_3) {
        /* Transition: '<S1>:390' */
        tmp = BatteryTemperatureHigh_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureHigh_DW.t3 = (uint8_T)tmp;
        if (BatteryTemperatureHigh_DW.t3 >
            BatteryTemperatureHigh_P.Chart1_Second_3) {
          /* Transition: '<S1>:389' */
          /* Transition: '<S1>:391' */
          BatteryTemperatureHigh_DW.F_3 = true;
          BatteryTemperatureHigh_DW.t3 = 0U;

          /* Transition: '<S1>:396' */
          /* Transition: '<S1>:392' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:285' */
      /* Entry Internal 'F_3_false': '<S1>:202' */
      /* Transition: '<S1>:444' */
      BatteryTemperatureHigh_DW.F_3 = true;
      if ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
           BatteryTemperatureHigh_P.Chart1_ThresholdRecover_3) &&
          BatteryTemperatureHigh_DW.F_3) {
        /* Transition: '<S1>:442' */
        tmp = BatteryTemperatureHigh_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        BatteryTemperatureHigh_DW.t33 = (uint8_T)tmp;
        if (BatteryTemperatureHigh_DW.t33 >
            BatteryTemperatureHigh_P.Chart1_Second_33) {
          /* Transition: '<S1>:441' */
          /* Transition: '<S1>:443' */
          BatteryTemperatureHigh_DW.F_3 = false;
          BatteryTemperatureHigh_DW.t33 = 0U;

          /* Transition: '<S1>:448' */
          /* Transition: '<S1>:446' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
                    BatteryTemperatureHigh_P.Chart1_ThresholdRecover_3) &&
                   BatteryTemperatureHigh_DW.F_3)) {
      /* Transition: '<S1>:439' */
      /* Transition: '<S1>:440' */
      BatteryTemperatureHigh_DW.t33 = 0U;
      BatteryTemperatureHigh_DW.t1 = 0U;
      BatteryTemperatureHigh_DW.t2 = 0U;

      /* Transition: '<S1>:446' */
    } else {
      /* Transition: '<S1>:447' */
    }

    if (guard6 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                    BatteryTemperatureHigh_P.Chart1_ThresholdFault_3) &&
                   (!BatteryTemperatureHigh_DW.F_3))) {
      /* Transition: '<S1>:394' */
      /* Transition: '<S1>:395' */
      BatteryTemperatureHigh_DW.t3 = 0U;

      /* Transition: '<S1>:392' */
    } else {
      /* Transition: '<S1>:393' */
    }

    /* Entry Internal 'F_44': '<S1>:311' */
    /* Entry Internal 'F_4_true': '<S1>:531' */
    /* Transition: '<S1>:539' */
    guard6 = false;
    if (BatteryTemperatureHigh_U.g_BatHighestTemp_g >=
        BatteryTemperatureHigh_P.Chart1_ThresholdFault_4) {
      /* Transition: '<S1>:540' */
      tmp = BatteryTemperatureHigh_DW.t4 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      BatteryTemperatureHigh_DW.t4 = (uint8_T)tmp;
      if (BatteryTemperatureHigh_DW.t4 >
          BatteryTemperatureHigh_P.Chart1_Second_4) {
        /* Transition: '<S1>:544' */
        /* Transition: '<S1>:546' */
        BatteryTemperatureHigh_DW.F_4 = true;

        /* Transition: '<S1>:548' */
        /* Transition: '<S1>:547' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((BatteryTemperatureHigh_U.g_BatHighestTemp_g <
                    BatteryTemperatureHigh_P.Chart1_ThresholdFault_4) &&
                   (!BatteryTemperatureHigh_DW.F_4))) {
      /* Transition: '<S1>:542' */
      /* Transition: '<S1>:545' */
      BatteryTemperatureHigh_DW.t4 = 0U;

      /* Transition: '<S1>:547' */
    } else {
      /* Transition: '<S1>:543' */
    }

    /* Entry Internal 'F_0': '<S1>:529' */
    /* Entry Internal 'F_0_true': '<S1>:503' */
    BatteryT_inner_default_F_0_true(&F_lev);
  } else {
    BatteryTemperatureHigh_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void BatteryTemperatureHigh_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BatteryTemperatureHigh_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&BatteryTemperatureHigh_DW, 0,
                sizeof(DW_BatteryTemperatureHigh_T));

  /* external inputs */
  BatteryTemperatureHigh_U.g_BatHighestTemp_g = 0U;

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  BatteryTemperatureHigh_DW.is_active_c1_BatteryTemperature = 0U;
  BatteryTemperatureHigh_DW.t1 = 0U;
  BatteryTemperatureHigh_DW.t2 = 0U;
  BatteryTemperatureHigh_DW.t3 = 0U;
  BatteryTemperatureHigh_DW.t22 = 0U;
  BatteryTemperatureHigh_DW.t33 = 0U;
  BatteryTemperatureHigh_DW.t11 = 0U;
  BatteryTemperatureHigh_DW.t4 = 0U;
  BatteryTemperatureHigh_DW.F_1 = false;
  BatteryTemperatureHigh_DW.F_3 = false;
  BatteryTemperatureHigh_DW.F_2 = false;
  BatteryTemperatureHigh_DW.F_4 = false;
}

/* Model terminate function */
void BatteryTemperatureHigh_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
