/*
 * File: TotalVoltageOverVoltage_cellnum.c
 *
 * Code generated for Simulink model 'TotalVoltageOverVoltage_cellnum'.
 *
 * Model version                  : 1.152
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Mar 08 09:29:31 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->HC(S)12
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TotalVoltageOverVoltage_cellnum.h"
#include "TotalVoltageOverVoltage_cellnum_private.h"

/* Block states (auto storage) */
DW_TotalVoltageOverVoltage_ce_T TotalVoltageOverVoltage_cell_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_TotalVoltageOverVoltage__T TotalVoltageOverVoltage_celln_U;

/* Real-time model */
RT_MODEL_TotalVoltageOverVolt_T TotalVoltageOverVoltage_cell_M_;
RT_MODEL_TotalVoltageOverVolt_T *const TotalVoltageOverVoltage_cell_M =
  &TotalVoltageOverVoltage_cell_M_;

/* Forward declaration for local functions */
static void TotalVol_inner_default_F_0_true(uint8_T *F_lev);
static void TotalVoltageOverVoltage_celln_F(uint8_T *F_lev);
static real32_T TotalVoltageOverVoltag_ValueSet(const real32_T Value[2]);

/* Function for Chart: '<Root>/Chart1' */
static void TotalVol_inner_default_F_0_true(uint8_T *F_lev)
{
  /* Transition: '<S1>:530' */
  if (TotalVoltageOverVoltage_cell_DW.F_4) {
    /* Transition: '<S1>:532' */
    /* Transition: '<S1>:537' */
    TotalVoltageOverVoltage_cell_DW.F_2 = false;
    TotalVoltageOverVoltage_cell_DW.F_3 = false;
    TotalVoltageOverVoltage_cell_DW.F_1 = false;
    *F_lev = 4U;

    /* Transition: '<S1>:544' */
    /* Transition: '<S1>:543' */
    /* Transition: '<S1>:542' */
    /* Transition: '<S1>:541' */
  } else if (TotalVoltageOverVoltage_cell_DW.F_3) {
    /* Transition: '<S1>:533' */
    /* Transition: '<S1>:538' */
    TotalVoltageOverVoltage_cell_DW.F_2 = false;
    TotalVoltageOverVoltage_cell_DW.F_1 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:543' */
    /* Transition: '<S1>:542' */
    /* Transition: '<S1>:541' */
  } else if (TotalVoltageOverVoltage_cell_DW.F_2) {
    /* Transition: '<S1>:534' */
    /* Transition: '<S1>:539' */
    TotalVoltageOverVoltage_cell_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:542' */
    /* Transition: '<S1>:541' */
  } else if (TotalVoltageOverVoltage_cell_DW.F_1) {
    /* Transition: '<S1>:535' */
    /* Transition: '<S1>:540' */
    *F_lev = 1U;

    /* Transition: '<S1>:541' */
  } else {
    /* Transition: '<S1>:536' */
    *F_lev = 0U;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void TotalVoltageOverVoltage_celln_F(uint8_T *F_lev)
{
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  int16_T tmp;

  /* During 'F': '<S1>:263' */
  /* During 'F_1': '<S1>:288' */
  /* Transition: '<S1>:506' */
  if (!TotalVoltageOverVoltage_cell_DW.F_1) {
    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    /* Transition: '<S1>:242' */
    /* Exit Internal 'F_1': '<S1>:288' */
    /* Entry Internal 'F_1_true': '<S1>:564' */
    /* Transition: '<S1>:572' */
    if ((TotalVoltageOverVoltage_celln_U.V0_g >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
        (TotalVoltageOverVoltage_celln_U.V3_i >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
      /* Transition: '<S1>:574' */
      tmp = TotalVoltageOverVoltage_cell_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      TotalVoltageOverVoltage_cell_DW.t1 = (uint8_T)tmp;
      if (TotalVoltageOverVoltage_cell_DW.t1 >
          TotalVoltageOverVoltage_celln_P.Chart1_Second_1) {
        /* Transition: '<S1>:577' */
        /* Transition: '<S1>:579' */
        TotalVoltageOverVoltage_cell_DW.F_1 = true;

        /* Transition: '<S1>:581' */
        /* Transition: '<S1>:580' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:203' */
    /* Exit Internal 'F_1': '<S1>:288' */
    /* Entry Internal 'F_1_false': '<S1>:246' */
    /* Transition: '<S1>:472' */
    TotalVoltageOverVoltage_cell_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((TotalVoltageOverVoltage_celln_U.V0_g <=
         TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
        (TotalVoltageOverVoltage_celln_U.V3_i <=
         TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
        TotalVoltageOverVoltage_cell_DW.F_1) {
      /* Transition: '<S1>:471' */
      tmp = TotalVoltageOverVoltage_cell_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      TotalVoltageOverVoltage_cell_DW.t11 = (uint8_T)tmp;
      if (TotalVoltageOverVoltage_cell_DW.t11 >
          TotalVoltageOverVoltage_celln_P.Chart1_Second_11) {
        /* Transition: '<S1>:474' */
        /* Transition: '<S1>:468' */
        TotalVoltageOverVoltage_cell_DW.F_1 = false;
        TotalVoltageOverVoltage_cell_DW.t11 = 0U;

        /* Transition: '<S1>:476' */
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
  if (guard11 && (((TotalVoltageOverVoltage_celln_U.V0_g >
                    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 *
                    (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
                   (TotalVoltageOverVoltage_celln_U.V3_i >
                    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 *
                    (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) &&
                  TotalVoltageOverVoltage_cell_DW.F_1)) {
    /* Transition: '<S1>:477' */
    /* Transition: '<S1>:478' */
    TotalVoltageOverVoltage_cell_DW.t11 = 0U;

    /* Transition: '<S1>:480' */
  } else {
    /* Transition: '<S1>:473' */
  }

  if (guard10 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (TotalVoltageOverVoltage_celln_U.V3_i <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (!TotalVoltageOverVoltage_cell_DW.F_1))) {
    /* Transition: '<S1>:575' */
    /* Transition: '<S1>:578' */
    TotalVoltageOverVoltage_cell_DW.t1 = 0U;

    /* Transition: '<S1>:580' */
  } else {
    /* Transition: '<S1>:576' */
  }

  /* During 'F_2': '<S1>:245' */
  /* Transition: '<S1>:508' */
  guard10 = false;
  guard11 = false;
  if (!TotalVoltageOverVoltage_cell_DW.F_2) {
    /* Transition: '<S1>:287' */
    /* Exit Internal 'F_2': '<S1>:245' */
    /* Entry Internal 'F_2_true': '<S1>:289' */
    /* Transition: '<S1>:376' */
    TotalVoltageOverVoltage_cell_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((TotalVoltageOverVoltage_celln_U.V0_g >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
        (TotalVoltageOverVoltage_celln_U.V3_i >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
      /* Transition: '<S1>:377' */
      tmp = TotalVoltageOverVoltage_cell_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      TotalVoltageOverVoltage_cell_DW.t2 = (uint8_T)tmp;
      if (TotalVoltageOverVoltage_cell_DW.t2 >
          TotalVoltageOverVoltage_celln_P.Chart1_Second_2) {
        /* Transition: '<S1>:380' */
        /* Transition: '<S1>:382' */
        TotalVoltageOverVoltage_cell_DW.F_2 = true;
        TotalVoltageOverVoltage_cell_DW.t2 = 0U;

        /* Transition: '<S1>:384' */
        /* Transition: '<S1>:383' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:310' */
    /* Exit Internal 'F_2': '<S1>:245' */
    /* Entry Internal 'F_2_false': '<S1>:265' */
    /* Transition: '<S1>:425' */
    TotalVoltageOverVoltage_cell_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((TotalVoltageOverVoltage_celln_U.V0_g <=
         TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
        (TotalVoltageOverVoltage_celln_U.V3_i <=
         TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
        TotalVoltageOverVoltage_cell_DW.F_2) {
      /* Transition: '<S1>:417' */
      tmp = TotalVoltageOverVoltage_cell_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      TotalVoltageOverVoltage_cell_DW.t22 = (uint8_T)tmp;
      if (TotalVoltageOverVoltage_cell_DW.t22 >
          TotalVoltageOverVoltage_celln_P.Chart1_Second_22) {
        /* Transition: '<S1>:428' */
        /* Transition: '<S1>:420' */
        TotalVoltageOverVoltage_cell_DW.F_2 = false;
        TotalVoltageOverVoltage_cell_DW.t22 = 0U;

        /* Transition: '<S1>:427' */
        /* Transition: '<S1>:426' */
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
  if (guard11 && (((TotalVoltageOverVoltage_celln_U.V0_g >
                    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 *
                    (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
                   (TotalVoltageOverVoltage_celln_U.V3_i >
                    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 *
                    (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) &&
                  TotalVoltageOverVoltage_cell_DW.F_2)) {
    /* Transition: '<S1>:430' */
    /* Transition: '<S1>:422' */
    TotalVoltageOverVoltage_cell_DW.t22 = 0U;
    TotalVoltageOverVoltage_cell_DW.t1 = 0U;

    /* Transition: '<S1>:426' */
  } else {
    /* Transition: '<S1>:419' */
  }

  if (guard10 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (TotalVoltageOverVoltage_celln_U.V3_i <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (!TotalVoltageOverVoltage_cell_DW.F_2))) {
    /* Transition: '<S1>:378' */
    /* Transition: '<S1>:381' */
    TotalVoltageOverVoltage_cell_DW.t2 = 0U;

    /* Transition: '<S1>:383' */
  } else {
    /* Transition: '<S1>:379' */
  }

  /* During 'F_3': '<S1>:286' */
  /* Transition: '<S1>:507' */
  guard10 = false;
  guard11 = false;
  if (!TotalVoltageOverVoltage_cell_DW.F_3) {
    /* Transition: '<S1>:244' */
    /* Exit Internal 'F_3': '<S1>:286' */
    /* Entry Internal 'F_3_true': '<S1>:332' */
    /* Transition: '<S1>:392' */
    TotalVoltageOverVoltage_cell_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((TotalVoltageOverVoltage_celln_U.V0_g >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
        (TotalVoltageOverVoltage_celln_U.V3_i >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
      /* Transition: '<S1>:393' */
      tmp = TotalVoltageOverVoltage_cell_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      TotalVoltageOverVoltage_cell_DW.t3 = (uint8_T)tmp;
      if (TotalVoltageOverVoltage_cell_DW.t3 >
          TotalVoltageOverVoltage_celln_P.Chart1_Second_3) {
        /* Transition: '<S1>:396' */
        /* Transition: '<S1>:398' */
        TotalVoltageOverVoltage_cell_DW.F_3 = true;
        TotalVoltageOverVoltage_cell_DW.t3 = 0U;

        /* Transition: '<S1>:400' */
        /* Transition: '<S1>:399' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:243' */
    /* Exit Internal 'F_3': '<S1>:286' */
    /* Entry Internal 'F_3_false': '<S1>:311' */
    /* Transition: '<S1>:439' */
    TotalVoltageOverVoltage_cell_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((TotalVoltageOverVoltage_celln_U.V0_g <=
         TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
        (TotalVoltageOverVoltage_celln_U.V3_i <=
         TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
        TotalVoltageOverVoltage_cell_DW.F_3) {
      /* Transition: '<S1>:437' */
      tmp = TotalVoltageOverVoltage_cell_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      TotalVoltageOverVoltage_cell_DW.t33 = (uint8_T)tmp;
      if (TotalVoltageOverVoltage_cell_DW.t33 >
          TotalVoltageOverVoltage_celln_P.Chart1_Second_33) {
        /* Transition: '<S1>:440' */
        /* Transition: '<S1>:446' */
        TotalVoltageOverVoltage_cell_DW.F_3 = false;
        TotalVoltageOverVoltage_cell_DW.t33 = 0U;

        /* Transition: '<S1>:444' */
        /* Transition: '<S1>:445' */
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
  if (guard11 && (((TotalVoltageOverVoltage_celln_U.V0_g >
                    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 *
                    (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
                   (TotalVoltageOverVoltage_celln_U.V3_i >
                    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 *
                    (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) &&
                  TotalVoltageOverVoltage_cell_DW.F_3)) {
    /* Transition: '<S1>:435' */
    /* Transition: '<S1>:447' */
    TotalVoltageOverVoltage_cell_DW.t33 = 0U;
    TotalVoltageOverVoltage_cell_DW.t1 = 0U;
    TotalVoltageOverVoltage_cell_DW.t2 = 0U;

    /* Transition: '<S1>:445' */
  } else {
    /* Transition: '<S1>:434' */
  }

  if (guard10 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (TotalVoltageOverVoltage_celln_U.V3_i <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (!TotalVoltageOverVoltage_cell_DW.F_3))) {
    /* Transition: '<S1>:394' */
    /* Transition: '<S1>:397' */
    TotalVoltageOverVoltage_cell_DW.t3 = 0U;

    /* Transition: '<S1>:399' */
  } else {
    /* Transition: '<S1>:395' */
  }

  /* During 'F_4': '<S1>:201' */
  /* Transition: '<S1>:264' */
  /* Exit Internal 'F_4': '<S1>:201' */
  /* Entry Internal 'F_4_true': '<S1>:546' */
  /* Transition: '<S1>:554' */
  guard10 = false;

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if ((TotalVoltageOverVoltage_celln_U.V0_g >
       TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
       TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
      (TotalVoltageOverVoltage_celln_U.V3_i >
       TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
       TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
    /* Transition: '<S1>:555' */
    tmp = TotalVoltageOverVoltage_cell_DW.t4 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    TotalVoltageOverVoltage_cell_DW.t4 = (uint8_T)tmp;
    if (TotalVoltageOverVoltage_cell_DW.t4 >
        TotalVoltageOverVoltage_celln_P.Chart1_Second_4) {
      /* Transition: '<S1>:558' */
      /* Transition: '<S1>:560' */
      TotalVoltageOverVoltage_cell_DW.F_4 = true;

      /* Transition: '<S1>:562' */
      /* Transition: '<S1>:563' */
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (TotalVoltageOverVoltage_celln_U.V3_i <=
                   TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
                   TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                  (!TotalVoltageOverVoltage_cell_DW.F_4))) {
    /* Transition: '<S1>:557' */
    /* Transition: '<S1>:561' */
    TotalVoltageOverVoltage_cell_DW.t4 = 0U;

    /* Transition: '<S1>:563' */
  } else {
    /* Transition: '<S1>:559' */
  }

  /* During 'F_0': '<S1>:518' */
  /* Transition: '<S1>:517' */
  /* Exit Internal 'F_0': '<S1>:518' */
  /* Entry Internal 'F_0_true': '<S1>:519' */
  TotalVol_inner_default_F_0_true(F_lev);
}

/* Function for Chart: '<Root>/Chart1' */
static real32_T TotalVoltageOverVoltag_ValueSet(const real32_T Value[2])
{
  real32_T Threshold;
  uint8_T i;
  boolean_T guard1 = false;

  /* Graphical Function 'ValueSet': '<S1>:587' */
  Threshold = 0.0F;

  /* Chart: '<Root>/Chart1' */
  /* Transition: '<S1>:599' */
  if (TotalVoltageOverVoltage_celln_P.Chart1_BatType == 3) {
    /* Transition: '<S1>:600' */
    /* Á×ËáÌúï® */
    /* Transition: '<S1>:602' */
    i = 1U;

    /* Transition: '<S1>:609' */
    guard1 = true;
  } else {
    /* Transition: '<S1>:601' */
    if (TotalVoltageOverVoltage_celln_P.Chart1_BatType == 6) {
      /* Transition: '<S1>:603' */
      /* ÈýÔªï® */
      /* Transition: '<S1>:605' */
      i = 2U;
      guard1 = true;
    } else {
      /* Transition: '<S1>:614' */
    }
  }

  /* End of Chart: '<Root>/Chart1' */
  if (guard1) {
    /* Transition: '<S1>:610' */
    Threshold = Value[i - 1];
  }

  /* Transition: '<S1>:612' */
  return Threshold;
}

/* Model step function */
uint8_T TotalVoltageOverVoltage_step(real32_T V0, real32_T V3)
{
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  uint8_T F_lev;
  int16_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  TotalVoltageOverVoltage_celln_U.V0_g = V0;

  /* Copy value for root inport '<Root>/In2' since it is accessed globally */
  TotalVoltageOverVoltage_celln_U.V3_i = V3;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (TotalVoltageOverVoltage_cell_DW.is_active_c1_TotalVoltageOverVo == 0U) {
    /* Entry: Chart1 */
    TotalVoltageOverVoltage_cell_DW.is_active_c1_TotalVoltageOverVo = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:202' */
    /* Entry 'F': '<S1>:263' */
    TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 =
      TotalVoltageOverVoltag_ValueSet(TotalVoltageOverVoltage_cell_DW.Value_1);
    TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 =
      TotalVoltageOverVoltag_ValueSet(TotalVoltageOverVoltage_cell_DW.Value_2);
    TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 =
      TotalVoltageOverVoltag_ValueSet(TotalVoltageOverVoltage_cell_DW.Value_3);
    TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 =
      TotalVoltageOverVoltag_ValueSet(TotalVoltageOverVoltage_cell_DW.Value_4);
    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 =
      TotalVoltageOverVoltag_ValueSet(TotalVoltageOverVoltage_cell_DW.Value_11);
    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 =
      TotalVoltageOverVoltag_ValueSet(TotalVoltageOverVoltage_cell_DW.Value_22);
    TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 =
      TotalVoltageOverVoltag_ValueSet(TotalVoltageOverVoltage_cell_DW.Value_33);

    /* Entry Internal 'F': '<S1>:263' */
    /* Entry Internal 'F_1': '<S1>:288' */
    /* Transition: '<S1>:505' */
    if (!TotalVoltageOverVoltage_cell_DW.F_1) {
      /* Transition: '<S1>:242' */
      /* Entry Internal 'F_1_true': '<S1>:564' */
      /* Transition: '<S1>:572' */
      if ((TotalVoltageOverVoltage_celln_U.V0_g >
           TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
          (TotalVoltageOverVoltage_celln_U.V3_i >
           TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
        /* Transition: '<S1>:574' */
        tmp = TotalVoltageOverVoltage_cell_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        TotalVoltageOverVoltage_cell_DW.t1 = (uint8_T)tmp;
        if (TotalVoltageOverVoltage_cell_DW.t1 >
            TotalVoltageOverVoltage_celln_P.Chart1_Second_1) {
          /* Transition: '<S1>:577' */
          /* Transition: '<S1>:579' */
          TotalVoltageOverVoltage_cell_DW.F_1 = true;

          /* Transition: '<S1>:581' */
          /* Transition: '<S1>:580' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:203' */
      /* Entry Internal 'F_1_false': '<S1>:246' */
      /* Transition: '<S1>:472' */
      TotalVoltageOverVoltage_cell_DW.F_1 = true;
      if ((TotalVoltageOverVoltage_celln_U.V0_g <=
           TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
          (TotalVoltageOverVoltage_celln_U.V3_i <=
           TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
          TotalVoltageOverVoltage_cell_DW.F_1) {
        /* Transition: '<S1>:471' */
        tmp = TotalVoltageOverVoltage_cell_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        TotalVoltageOverVoltage_cell_DW.t11 = (uint8_T)tmp;
        if (TotalVoltageOverVoltage_cell_DW.t11 >
            TotalVoltageOverVoltage_celln_P.Chart1_Second_11) {
          /* Transition: '<S1>:474' */
          /* Transition: '<S1>:468' */
          TotalVoltageOverVoltage_cell_DW.F_1 = false;
          TotalVoltageOverVoltage_cell_DW.t11 = 0U;

          /* Transition: '<S1>:476' */
          /* Transition: '<S1>:480' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && (((TotalVoltageOverVoltage_celln_U.V0_g >
                     TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 *
                     (real32_T)
                     TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
                    (TotalVoltageOverVoltage_celln_U.V3_i >
                     TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 *
                     (real32_T)
                     TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) &&
                   TotalVoltageOverVoltage_cell_DW.F_1)) {
      /* Transition: '<S1>:477' */
      /* Transition: '<S1>:478' */
      TotalVoltageOverVoltage_cell_DW.t11 = 0U;

      /* Transition: '<S1>:480' */
    } else {
      /* Transition: '<S1>:473' */
    }

    if (guard6 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (TotalVoltageOverVoltage_celln_U.V3_i <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (!TotalVoltageOverVoltage_cell_DW.F_1))) {
      /* Transition: '<S1>:575' */
      /* Transition: '<S1>:578' */
      TotalVoltageOverVoltage_cell_DW.t1 = 0U;

      /* Transition: '<S1>:580' */
    } else {
      /* Transition: '<S1>:576' */
    }

    /* Entry Internal 'F_2': '<S1>:245' */
    /* Transition: '<S1>:503' */
    guard6 = false;
    guard7 = false;
    if (!TotalVoltageOverVoltage_cell_DW.F_2) {
      /* Transition: '<S1>:287' */
      /* Entry Internal 'F_2_true': '<S1>:289' */
      /* Transition: '<S1>:376' */
      TotalVoltageOverVoltage_cell_DW.F_2 = false;
      if ((TotalVoltageOverVoltage_celln_U.V0_g >
           TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
          (TotalVoltageOverVoltage_celln_U.V3_i >
           TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
        /* Transition: '<S1>:377' */
        tmp = TotalVoltageOverVoltage_cell_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        TotalVoltageOverVoltage_cell_DW.t2 = (uint8_T)tmp;
        if (TotalVoltageOverVoltage_cell_DW.t2 >
            TotalVoltageOverVoltage_celln_P.Chart1_Second_2) {
          /* Transition: '<S1>:380' */
          /* Transition: '<S1>:382' */
          TotalVoltageOverVoltage_cell_DW.F_2 = true;
          TotalVoltageOverVoltage_cell_DW.t2 = 0U;

          /* Transition: '<S1>:384' */
          /* Transition: '<S1>:383' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:310' */
      /* Entry Internal 'F_2_false': '<S1>:265' */
      /* Transition: '<S1>:425' */
      TotalVoltageOverVoltage_cell_DW.F_2 = true;
      if ((TotalVoltageOverVoltage_celln_U.V0_g <=
           TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
          (TotalVoltageOverVoltage_celln_U.V3_i <=
           TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
          TotalVoltageOverVoltage_cell_DW.F_2) {
        /* Transition: '<S1>:417' */
        tmp = TotalVoltageOverVoltage_cell_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        TotalVoltageOverVoltage_cell_DW.t22 = (uint8_T)tmp;
        if (TotalVoltageOverVoltage_cell_DW.t22 >
            TotalVoltageOverVoltage_celln_P.Chart1_Second_22) {
          /* Transition: '<S1>:428' */
          /* Transition: '<S1>:420' */
          TotalVoltageOverVoltage_cell_DW.F_2 = false;
          TotalVoltageOverVoltage_cell_DW.t22 = 0U;

          /* Transition: '<S1>:427' */
          /* Transition: '<S1>:426' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && (((TotalVoltageOverVoltage_celln_U.V0_g >
                     TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 *
                     (real32_T)
                     TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
                    (TotalVoltageOverVoltage_celln_U.V3_i >
                     TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 *
                     (real32_T)
                     TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) &&
                   TotalVoltageOverVoltage_cell_DW.F_2)) {
      /* Transition: '<S1>:430' */
      /* Transition: '<S1>:422' */
      TotalVoltageOverVoltage_cell_DW.t22 = 0U;
      TotalVoltageOverVoltage_cell_DW.t1 = 0U;

      /* Transition: '<S1>:426' */
    } else {
      /* Transition: '<S1>:419' */
    }

    if (guard6 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (TotalVoltageOverVoltage_celln_U.V3_i <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (!TotalVoltageOverVoltage_cell_DW.F_2))) {
      /* Transition: '<S1>:378' */
      /* Transition: '<S1>:381' */
      TotalVoltageOverVoltage_cell_DW.t2 = 0U;

      /* Transition: '<S1>:383' */
    } else {
      /* Transition: '<S1>:379' */
    }

    /* Entry Internal 'F_3': '<S1>:286' */
    /* Transition: '<S1>:504' */
    guard6 = false;
    guard7 = false;
    if (!TotalVoltageOverVoltage_cell_DW.F_3) {
      /* Transition: '<S1>:244' */
      /* Entry Internal 'F_3_true': '<S1>:332' */
      /* Transition: '<S1>:392' */
      TotalVoltageOverVoltage_cell_DW.F_3 = false;
      if ((TotalVoltageOverVoltage_celln_U.V0_g >
           TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
          (TotalVoltageOverVoltage_celln_U.V3_i >
           TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
        /* Transition: '<S1>:393' */
        tmp = TotalVoltageOverVoltage_cell_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        TotalVoltageOverVoltage_cell_DW.t3 = (uint8_T)tmp;
        if (TotalVoltageOverVoltage_cell_DW.t3 >
            TotalVoltageOverVoltage_celln_P.Chart1_Second_3) {
          /* Transition: '<S1>:396' */
          /* Transition: '<S1>:398' */
          TotalVoltageOverVoltage_cell_DW.F_3 = true;
          TotalVoltageOverVoltage_cell_DW.t3 = 0U;

          /* Transition: '<S1>:400' */
          /* Transition: '<S1>:399' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:243' */
      /* Entry Internal 'F_3_false': '<S1>:311' */
      /* Transition: '<S1>:439' */
      TotalVoltageOverVoltage_cell_DW.F_3 = true;
      if ((TotalVoltageOverVoltage_celln_U.V0_g <=
           TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
          (TotalVoltageOverVoltage_celln_U.V3_i <=
           TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 * (real32_T)
           TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
          TotalVoltageOverVoltage_cell_DW.F_3) {
        /* Transition: '<S1>:437' */
        tmp = TotalVoltageOverVoltage_cell_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        TotalVoltageOverVoltage_cell_DW.t33 = (uint8_T)tmp;
        if (TotalVoltageOverVoltage_cell_DW.t33 >
            TotalVoltageOverVoltage_celln_P.Chart1_Second_33) {
          /* Transition: '<S1>:440' */
          /* Transition: '<S1>:446' */
          TotalVoltageOverVoltage_cell_DW.F_3 = false;
          TotalVoltageOverVoltage_cell_DW.t33 = 0U;

          /* Transition: '<S1>:444' */
          /* Transition: '<S1>:445' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && (((TotalVoltageOverVoltage_celln_U.V0_g >
                     TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 *
                     (real32_T)
                     TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
                    (TotalVoltageOverVoltage_celln_U.V3_i >
                     TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 *
                     (real32_T)
                     TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) &&
                   TotalVoltageOverVoltage_cell_DW.F_3)) {
      /* Transition: '<S1>:435' */
      /* Transition: '<S1>:447' */
      TotalVoltageOverVoltage_cell_DW.t33 = 0U;
      TotalVoltageOverVoltage_cell_DW.t1 = 0U;
      TotalVoltageOverVoltage_cell_DW.t2 = 0U;

      /* Transition: '<S1>:445' */
    } else {
      /* Transition: '<S1>:434' */
    }

    if (guard6 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (TotalVoltageOverVoltage_celln_U.V3_i <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (!TotalVoltageOverVoltage_cell_DW.F_3))) {
      /* Transition: '<S1>:394' */
      /* Transition: '<S1>:397' */
      TotalVoltageOverVoltage_cell_DW.t3 = 0U;

      /* Transition: '<S1>:399' */
    } else {
      /* Transition: '<S1>:395' */
    }

    /* Entry Internal 'F_4': '<S1>:201' */
    /* Entry Internal 'F_4_true': '<S1>:546' */
    /* Transition: '<S1>:554' */
    guard6 = false;
    if ((TotalVoltageOverVoltage_celln_U.V0_g >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) ||
        (TotalVoltageOverVoltage_celln_U.V3_i >
         TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
         TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber)) {
      /* Transition: '<S1>:555' */
      tmp = TotalVoltageOverVoltage_cell_DW.t4 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      TotalVoltageOverVoltage_cell_DW.t4 = (uint8_T)tmp;
      if (TotalVoltageOverVoltage_cell_DW.t4 >
          TotalVoltageOverVoltage_celln_P.Chart1_Second_4) {
        /* Transition: '<S1>:558' */
        /* Transition: '<S1>:560' */
        TotalVoltageOverVoltage_cell_DW.F_4 = true;

        /* Transition: '<S1>:562' */
        /* Transition: '<S1>:563' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((TotalVoltageOverVoltage_celln_U.V0_g <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (TotalVoltageOverVoltage_celln_U.V3_i <=
                    TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 * (real32_T)
                    TotalVoltageOverVoltage_celln_P.Chart1_BatCellNumber) &&
                   (!TotalVoltageOverVoltage_cell_DW.F_4))) {
      /* Transition: '<S1>:557' */
      /* Transition: '<S1>:561' */
      TotalVoltageOverVoltage_cell_DW.t4 = 0U;

      /* Transition: '<S1>:563' */
    } else {
      /* Transition: '<S1>:559' */
    }

    /* Entry Internal 'F_0': '<S1>:518' */
    /* Entry Internal 'F_0_true': '<S1>:519' */
    TotalVol_inner_default_F_0_true(&F_lev);
  } else {
    TotalVoltageOverVoltage_celln_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void TotalVoltageOverVoltage_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(TotalVoltageOverVoltage_cell_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&TotalVoltageOverVoltage_cell_DW, 0,
                sizeof(DW_TotalVoltageOverVoltage_ce_T));

  /* external inputs */
  (void) memset((void *)&TotalVoltageOverVoltage_celln_U, 0,
                sizeof(ExtU_TotalVoltageOverVoltage__T));

  /* Machine initializer */
  TotalVoltageOverVoltage_cell_DW.F_lev = 0.0;

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  TotalVoltageOverVoltage_cell_DW.is_active_c1_TotalVoltageOverVo = 0U;
  TotalVoltageOverVoltage_cell_DW.t1 = 0U;
  TotalVoltageOverVoltage_cell_DW.t2 = 0U;
  TotalVoltageOverVoltage_cell_DW.t3 = 0U;
  TotalVoltageOverVoltage_cell_DW.t22 = 0U;
  TotalVoltageOverVoltage_cell_DW.t33 = 0U;
  TotalVoltageOverVoltage_cell_DW.t11 = 0U;
  TotalVoltageOverVoltage_cell_DW.t4 = 0U;
  TotalVoltageOverVoltage_cell_DW.F_1 = false;
  TotalVoltageOverVoltage_cell_DW.F_2 = false;
  TotalVoltageOverVoltage_cell_DW.F_3 = false;
  TotalVoltageOverVoltage_cell_DW.F_4 = false;
  TotalVoltageOverVoltage_cell_DW.ThresholdRecover_3 = 0.0F;
  TotalVoltageOverVoltage_cell_DW.ThresholdRecover_2 = 0.0F;
  TotalVoltageOverVoltage_cell_DW.ThresholdRecover_1 = 0.0F;
  TotalVoltageOverVoltage_cell_DW.ThresholdFault_4 = 0.0F;
  TotalVoltageOverVoltage_cell_DW.ThresholdFault_3 = 0.0F;
  TotalVoltageOverVoltage_cell_DW.ThresholdFault_2 = 0.0F;
  TotalVoltageOverVoltage_cell_DW.ThresholdFault_1 = 0.0F;
  TotalVoltageOverVoltage_cell_DW.Value_1[0] = 3.65F;
  TotalVoltageOverVoltage_cell_DW.Value_1[1] = 4.15F;
  TotalVoltageOverVoltage_cell_DW.Value_2[0] = 3.675F;
  TotalVoltageOverVoltage_cell_DW.Value_2[1] = 4.2F;
  TotalVoltageOverVoltage_cell_DW.Value_3[0] = 3.7F;
  TotalVoltageOverVoltage_cell_DW.Value_3[1] = 4.25F;
  TotalVoltageOverVoltage_cell_DW.Value_4[0] = 3.75F;
  TotalVoltageOverVoltage_cell_DW.Value_4[1] = 4.3F;
  TotalVoltageOverVoltage_cell_DW.Value_22[0] = 3.65F;
  TotalVoltageOverVoltage_cell_DW.Value_22[1] = 4.15F;
  TotalVoltageOverVoltage_cell_DW.Value_33[0] = 3.675F;
  TotalVoltageOverVoltage_cell_DW.Value_33[1] = 4.2F;
  TotalVoltageOverVoltage_cell_DW.Value_11[0] = 3.6F;
  TotalVoltageOverVoltage_cell_DW.Value_11[1] = 4.1F;
}

/* Model terminate function */
void TotalVoltageOverVoltage_cellnum_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
