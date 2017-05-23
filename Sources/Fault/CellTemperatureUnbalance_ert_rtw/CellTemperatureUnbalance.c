/*
 * File: CellTemperatureUnbalance.c
 *
 * Code generated for Simulink model 'CellTemperatureUnbalance'.
 *
 * Model version                  : 1.135
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sun Dec 11 10:47:30 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CellTemperatureUnbalance.h"
#include "CellTemperatureUnbalance_private.h"

/* Block states (auto storage) */
DW_CellTemperatureUnbalance_T CellTemperatureUnbalance_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_CellTemperatureUnbalance_T CellTemperatureUnbalance_U;

/* Real-time model */
RT_MODEL_CellTemperatureUnbal_T CellTemperatureUnbalance_M_;
RT_MODEL_CellTemperatureUnbal_T *const CellTemperatureUnbalance_M =
  &CellTemperatureUnbalance_M_;

/* Forward declaration for local functions */
static void CellTemperatureUnbalance_F(uint8_T *F_lev);

/* Function for Chart: '<Root>/Chart1' */
static void CellTemperatureUnbalance_F(uint8_T *F_lev)
{
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  int32_T tmp;

  /* During 'F': '<S1>:304' */
  /* During 'F_1': '<S1>:350' */
  /* Transition: '<S1>:552' */
  if (!CellTemperatureUnbalance_DW.F_1) {
    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    /* Transition: '<S1>:305' */
    /* Exit Internal 'F_1': '<S1>:350' */
    /* Entry Internal 'F_1_true': '<S1>:604' */
    /* Transition: '<S1>:612' */
    if (CellTemperatureUnbalance_U.Tmp_H_i - CellTemperatureUnbalance_U.Tmp_L_d >=
        CellTemperatureUnbalance_P.Chart1_ThresholdFault_1) {
      /* Transition: '<S1>:614' */
      tmp = CellTemperatureUnbalance_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellTemperatureUnbalance_DW.t1 = (uint8_T)tmp;
      if (CellTemperatureUnbalance_DW.t1 >
          CellTemperatureUnbalance_P.Chart1_Second_1) {
        /* Transition: '<S1>:617' */
        /* Transition: '<S1>:619' */
        CellTemperatureUnbalance_DW.F_1 = true;

        /* Transition: '<S1>:621' */
        /* Transition: '<S1>:620' */
      } else {
        guard9 = true;
      }
    } else {
      guard9 = true;
    }
  } else {
    /* Transition: '<S1>:302' */
    /* Exit Internal 'F_1': '<S1>:350' */
    /* Entry Internal 'F_1_false': '<S1>:391' */
    /* Transition: '<S1>:515' */
    CellTemperatureUnbalance_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((CellTemperatureUnbalance_U.Tmp_H_i - CellTemperatureUnbalance_U.Tmp_L_d
         < CellTemperatureUnbalance_P.Chart1_ThresholdRecover_1) &&
        CellTemperatureUnbalance_DW.F_1) {
      /* Transition: '<S1>:512' */
      tmp = CellTemperatureUnbalance_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellTemperatureUnbalance_DW.t11 = (uint8_T)tmp;
      if (CellTemperatureUnbalance_DW.t11 >
          CellTemperatureUnbalance_P.Chart1_Second_11) {
        /* Transition: '<S1>:505' */
        /* Transition: '<S1>:506' */
        CellTemperatureUnbalance_DW.F_1 = false;
        CellTemperatureUnbalance_DW.t11 = 0U;

        /* Transition: '<S1>:514' */
        /* Transition: '<S1>:518' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (guard10 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                   CellTemperatureUnbalance_U.Tmp_L_d >=
                   CellTemperatureUnbalance_P.Chart1_ThresholdRecover_1) &&
                  CellTemperatureUnbalance_DW.F_1)) {
    /* Transition: '<S1>:517' */
    /* Transition: '<S1>:508' */
    CellTemperatureUnbalance_DW.t11 = 0U;

    /* Transition: '<S1>:518' */
  } else {
    /* Transition: '<S1>:507' */
  }

  if (guard9 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                  CellTemperatureUnbalance_U.Tmp_L_d <
                  CellTemperatureUnbalance_P.Chart1_ThresholdFault_1) &&
                 (!CellTemperatureUnbalance_DW.F_1))) {
    /* Transition: '<S1>:615' */
    /* Transition: '<S1>:618' */
    CellTemperatureUnbalance_DW.t1 = 0U;

    /* Transition: '<S1>:620' */
  } else {
    /* Transition: '<S1>:616' */
  }

  /* During 'F_2': '<S1>:369' */
  /* Transition: '<S1>:544' */
  guard9 = false;
  guard10 = false;
  if (!CellTemperatureUnbalance_DW.F_2) {
    /* Transition: '<S1>:259' */
    /* Exit Internal 'F_2': '<S1>:369' */
    /* Entry Internal 'F_2_true': '<S1>:370' */
    /* Transition: '<S1>:435' */
    CellTemperatureUnbalance_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if (CellTemperatureUnbalance_U.Tmp_H_i - CellTemperatureUnbalance_U.Tmp_L_d >=
        CellTemperatureUnbalance_P.Chart1_ThresholdFault_2) {
      /* Transition: '<S1>:436' */
      tmp = CellTemperatureUnbalance_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellTemperatureUnbalance_DW.t2 = (uint8_T)tmp;
      if (CellTemperatureUnbalance_DW.t2 >
          CellTemperatureUnbalance_P.Chart1_Second_2) {
        /* Transition: '<S1>:439' */
        /* Transition: '<S1>:427' */
        CellTemperatureUnbalance_DW.F_2 = true;
        CellTemperatureUnbalance_DW.t2 = 0U;

        /* Transition: '<S1>:426' */
        /* Transition: '<S1>:425' */
      } else {
        guard9 = true;
      }
    } else {
      guard9 = true;
    }
  } else {
    /* Transition: '<S1>:258' */
    /* Exit Internal 'F_2': '<S1>:369' */
    /* Entry Internal 'F_2_false': '<S1>:306' */
    /* Transition: '<S1>:479' */
    CellTemperatureUnbalance_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((CellTemperatureUnbalance_U.Tmp_H_i - CellTemperatureUnbalance_U.Tmp_L_d
         < CellTemperatureUnbalance_P.Chart1_ThresholdRecover_2) &&
        CellTemperatureUnbalance_DW.F_2) {
      /* Transition: '<S1>:485' */
      tmp = CellTemperatureUnbalance_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellTemperatureUnbalance_DW.t22 = (uint8_T)tmp;
      if (CellTemperatureUnbalance_DW.t22 >
          CellTemperatureUnbalance_P.Chart1_Second_22) {
        /* Transition: '<S1>:478' */
        /* Transition: '<S1>:474' */
        CellTemperatureUnbalance_DW.F_2 = false;
        CellTemperatureUnbalance_DW.t22 = 0U;

        /* Transition: '<S1>:477' */
        /* Transition: '<S1>:488' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (guard10 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                   CellTemperatureUnbalance_U.Tmp_L_d >=
                   CellTemperatureUnbalance_P.Chart1_ThresholdRecover_2) &&
                  CellTemperatureUnbalance_DW.F_2)) {
    /* Transition: '<S1>:473' */
    /* Transition: '<S1>:475' */
    CellTemperatureUnbalance_DW.t22 = 0U;
    CellTemperatureUnbalance_DW.t1 = 0U;

    /* Transition: '<S1>:488' */
  } else {
    /* Transition: '<S1>:487' */
  }

  if (guard9 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                  CellTemperatureUnbalance_U.Tmp_L_d <
                  CellTemperatureUnbalance_P.Chart1_ThresholdFault_2) &&
                 (!CellTemperatureUnbalance_DW.F_2))) {
    /* Transition: '<S1>:438' */
    /* Transition: '<S1>:440' */
    CellTemperatureUnbalance_DW.t2 = 0U;

    /* Transition: '<S1>:425' */
  } else {
    /* Transition: '<S1>:437' */
  }

  /* During 'F_3': '<S1>:328' */
  /* Transition: '<S1>:549' */
  guard9 = false;
  guard10 = false;
  if (!CellTemperatureUnbalance_DW.F_3) {
    /* Transition: '<S1>:303' */
    /* Exit Internal 'F_3': '<S1>:328' */
    /* Entry Internal 'F_3_true': '<S1>:260' */
    /* Transition: '<S1>:448' */
    CellTemperatureUnbalance_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if (CellTemperatureUnbalance_U.Tmp_H_i - CellTemperatureUnbalance_U.Tmp_L_d >=
        CellTemperatureUnbalance_P.Chart1_ThresholdFault_3) {
      /* Transition: '<S1>:449' */
      tmp = CellTemperatureUnbalance_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellTemperatureUnbalance_DW.t3 = (uint8_T)tmp;
      if (CellTemperatureUnbalance_DW.t3 >
          CellTemperatureUnbalance_P.Chart1_Second_3) {
        /* Transition: '<S1>:452' */
        /* Transition: '<S1>:454' */
        CellTemperatureUnbalance_DW.F_3 = true;
        CellTemperatureUnbalance_DW.t3 = 0U;

        /* Transition: '<S1>:456' */
        /* Transition: '<S1>:455' */
      } else {
        guard9 = true;
      }
    } else {
      guard9 = true;
    }
  } else {
    /* Transition: '<S1>:351' */
    /* Exit Internal 'F_3': '<S1>:328' */
    /* Entry Internal 'F_3_false': '<S1>:281' */
    /* Transition: '<S1>:504' */
    CellTemperatureUnbalance_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     *  Inport: '<Root>/In2'
     */
    if ((CellTemperatureUnbalance_U.Tmp_H_i - CellTemperatureUnbalance_U.Tmp_L_d
         < CellTemperatureUnbalance_P.Chart1_ThresholdRecover_3) &&
        CellTemperatureUnbalance_DW.F_3) {
      /* Transition: '<S1>:490' */
      tmp = CellTemperatureUnbalance_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellTemperatureUnbalance_DW.t33 = (uint8_T)tmp;
      if (CellTemperatureUnbalance_DW.t33 >
          CellTemperatureUnbalance_P.Chart1_Second_33) {
        /* Transition: '<S1>:499' */
        /* Transition: '<S1>:494' */
        CellTemperatureUnbalance_DW.F_3 = false;
        CellTemperatureUnbalance_DW.t33 = 0U;

        /* Transition: '<S1>:501' */
        /* Transition: '<S1>:495' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  }

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   *  Inport: '<Root>/In2'
   */
  if (guard10 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                   CellTemperatureUnbalance_U.Tmp_L_d >=
                   CellTemperatureUnbalance_P.Chart1_ThresholdRecover_3) &&
                  CellTemperatureUnbalance_DW.F_3)) {
    /* Transition: '<S1>:493' */
    /* Transition: '<S1>:489' */
    CellTemperatureUnbalance_DW.t33 = 0U;
    CellTemperatureUnbalance_DW.t1 = 0U;
    CellTemperatureUnbalance_DW.t2 = 0U;

    /* Transition: '<S1>:495' */
  } else {
    /* Transition: '<S1>:500' */
  }

  if (guard9 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                  CellTemperatureUnbalance_U.Tmp_L_d <
                  CellTemperatureUnbalance_P.Chart1_ThresholdFault_3) &&
                 (!CellTemperatureUnbalance_DW.F_3))) {
    /* Transition: '<S1>:450' */
    /* Transition: '<S1>:453' */
    CellTemperatureUnbalance_DW.t3 = 0U;

    /* Transition: '<S1>:455' */
  } else {
    /* Transition: '<S1>:451' */
  }

  /* During 'F_0': '<S1>:583' */
  /* Transition: '<S1>:584' */
  /* Exit Internal 'F_0': '<S1>:583' */
  /* Entry Internal 'F_0_true': '<S1>:557' */
  /* Transition: '<S1>:568' */
  if (CellTemperatureUnbalance_DW.F_3) {
    /* Transition: '<S1>:570' */
    /* Transition: '<S1>:575' */
    CellTemperatureUnbalance_DW.F_2 = false;
    CellTemperatureUnbalance_DW.F_1 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:582' */
    /* Transition: '<S1>:581' */
    /* Transition: '<S1>:580' */
    /* Transition: '<S1>:579' */
  } else if (CellTemperatureUnbalance_DW.F_2) {
    /* Transition: '<S1>:571' */
    /* Transition: '<S1>:576' */
    CellTemperatureUnbalance_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:581' */
    /* Transition: '<S1>:580' */
    /* Transition: '<S1>:579' */
  } else if (CellTemperatureUnbalance_DW.F_1) {
    /* Transition: '<S1>:572' */
    /* Transition: '<S1>:577' */
    *F_lev = 1U;

    /* Transition: '<S1>:580' */
    /* Transition: '<S1>:579' */
  } else {
    /* Transition: '<S1>:574' */
    *F_lev = 0U;
  }
}

/* Model step function */
uint8_T CellTemperatureUnbalance_step(uint8_T Tmp_H, uint8_T Tmp_L)
{
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  uint8_T F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  CellTemperatureUnbalance_U.Tmp_H_i = Tmp_H;

  /* Copy value for root inport '<Root>/In2' since it is accessed globally */
  CellTemperatureUnbalance_U.Tmp_L_d = Tmp_L;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (CellTemperatureUnbalance_DW.is_active_c1_CellTemperatureUnb == 0U) {
    /* Entry: Chart1 */
    CellTemperatureUnbalance_DW.is_active_c1_CellTemperatureUnb = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:408' */
    /* Entry Internal 'F': '<S1>:304' */
    /* Entry Internal 'F_1': '<S1>:350' */
    /* Transition: '<S1>:551' */
    if (!CellTemperatureUnbalance_DW.F_1) {
      /* Transition: '<S1>:305' */
      /* Entry Internal 'F_1_true': '<S1>:604' */
      /* Transition: '<S1>:612' */
      if (CellTemperatureUnbalance_U.Tmp_H_i -
          CellTemperatureUnbalance_U.Tmp_L_d >=
          CellTemperatureUnbalance_P.Chart1_ThresholdFault_1) {
        /* Transition: '<S1>:614' */
        tmp = CellTemperatureUnbalance_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellTemperatureUnbalance_DW.t1 = (uint8_T)tmp;
        if (CellTemperatureUnbalance_DW.t1 >
            CellTemperatureUnbalance_P.Chart1_Second_1) {
          /* Transition: '<S1>:617' */
          /* Transition: '<S1>:619' */
          CellTemperatureUnbalance_DW.F_1 = true;

          /* Transition: '<S1>:621' */
          /* Transition: '<S1>:620' */
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }
    } else {
      /* Transition: '<S1>:302' */
      /* Entry Internal 'F_1_false': '<S1>:391' */
      /* Transition: '<S1>:515' */
      CellTemperatureUnbalance_DW.F_1 = true;
      if ((CellTemperatureUnbalance_U.Tmp_H_i -
           CellTemperatureUnbalance_U.Tmp_L_d <
           CellTemperatureUnbalance_P.Chart1_ThresholdRecover_1) &&
          CellTemperatureUnbalance_DW.F_1) {
        /* Transition: '<S1>:512' */
        tmp = CellTemperatureUnbalance_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellTemperatureUnbalance_DW.t11 = (uint8_T)tmp;
        if (CellTemperatureUnbalance_DW.t11 >
            CellTemperatureUnbalance_P.Chart1_Second_11) {
          /* Transition: '<S1>:505' */
          /* Transition: '<S1>:506' */
          CellTemperatureUnbalance_DW.F_1 = false;
          CellTemperatureUnbalance_DW.t11 = 0U;

          /* Transition: '<S1>:514' */
          /* Transition: '<S1>:518' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    }

    if (guard6 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                    CellTemperatureUnbalance_U.Tmp_L_d >=
                    CellTemperatureUnbalance_P.Chart1_ThresholdRecover_1) &&
                   CellTemperatureUnbalance_DW.F_1)) {
      /* Transition: '<S1>:517' */
      /* Transition: '<S1>:508' */
      CellTemperatureUnbalance_DW.t11 = 0U;

      /* Transition: '<S1>:518' */
    } else {
      /* Transition: '<S1>:507' */
    }

    if (guard5 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                    CellTemperatureUnbalance_U.Tmp_L_d <
                    CellTemperatureUnbalance_P.Chart1_ThresholdFault_1) &&
                   (!CellTemperatureUnbalance_DW.F_1))) {
      /* Transition: '<S1>:615' */
      /* Transition: '<S1>:618' */
      CellTemperatureUnbalance_DW.t1 = 0U;

      /* Transition: '<S1>:620' */
    } else {
      /* Transition: '<S1>:616' */
    }

    /* Entry Internal 'F_2': '<S1>:369' */
    /* Transition: '<S1>:543' */
    guard5 = false;
    guard6 = false;
    if (!CellTemperatureUnbalance_DW.F_2) {
      /* Transition: '<S1>:259' */
      /* Entry Internal 'F_2_true': '<S1>:370' */
      /* Transition: '<S1>:435' */
      CellTemperatureUnbalance_DW.F_2 = false;
      if (CellTemperatureUnbalance_U.Tmp_H_i -
          CellTemperatureUnbalance_U.Tmp_L_d >=
          CellTemperatureUnbalance_P.Chart1_ThresholdFault_2) {
        /* Transition: '<S1>:436' */
        tmp = CellTemperatureUnbalance_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellTemperatureUnbalance_DW.t2 = (uint8_T)tmp;
        if (CellTemperatureUnbalance_DW.t2 >
            CellTemperatureUnbalance_P.Chart1_Second_2) {
          /* Transition: '<S1>:439' */
          /* Transition: '<S1>:427' */
          CellTemperatureUnbalance_DW.F_2 = true;
          CellTemperatureUnbalance_DW.t2 = 0U;

          /* Transition: '<S1>:426' */
          /* Transition: '<S1>:425' */
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }
    } else {
      /* Transition: '<S1>:258' */
      /* Entry Internal 'F_2_false': '<S1>:306' */
      /* Transition: '<S1>:479' */
      CellTemperatureUnbalance_DW.F_2 = true;
      if ((CellTemperatureUnbalance_U.Tmp_H_i -
           CellTemperatureUnbalance_U.Tmp_L_d <
           CellTemperatureUnbalance_P.Chart1_ThresholdRecover_2) &&
          CellTemperatureUnbalance_DW.F_2) {
        /* Transition: '<S1>:485' */
        tmp = CellTemperatureUnbalance_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellTemperatureUnbalance_DW.t22 = (uint8_T)tmp;
        if (CellTemperatureUnbalance_DW.t22 >
            CellTemperatureUnbalance_P.Chart1_Second_22) {
          /* Transition: '<S1>:478' */
          /* Transition: '<S1>:474' */
          CellTemperatureUnbalance_DW.F_2 = false;
          CellTemperatureUnbalance_DW.t22 = 0U;

          /* Transition: '<S1>:477' */
          /* Transition: '<S1>:488' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    }

    if (guard6 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                    CellTemperatureUnbalance_U.Tmp_L_d >=
                    CellTemperatureUnbalance_P.Chart1_ThresholdRecover_2) &&
                   CellTemperatureUnbalance_DW.F_2)) {
      /* Transition: '<S1>:473' */
      /* Transition: '<S1>:475' */
      CellTemperatureUnbalance_DW.t22 = 0U;
      CellTemperatureUnbalance_DW.t1 = 0U;

      /* Transition: '<S1>:488' */
    } else {
      /* Transition: '<S1>:487' */
    }

    if (guard5 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                    CellTemperatureUnbalance_U.Tmp_L_d <
                    CellTemperatureUnbalance_P.Chart1_ThresholdFault_2) &&
                   (!CellTemperatureUnbalance_DW.F_2))) {
      /* Transition: '<S1>:438' */
      /* Transition: '<S1>:440' */
      CellTemperatureUnbalance_DW.t2 = 0U;

      /* Transition: '<S1>:425' */
    } else {
      /* Transition: '<S1>:437' */
    }

    /* Entry Internal 'F_3': '<S1>:328' */
    /* Transition: '<S1>:548' */
    guard5 = false;
    guard6 = false;
    if (!CellTemperatureUnbalance_DW.F_3) {
      /* Transition: '<S1>:303' */
      /* Entry Internal 'F_3_true': '<S1>:260' */
      /* Transition: '<S1>:448' */
      CellTemperatureUnbalance_DW.F_3 = false;
      if (CellTemperatureUnbalance_U.Tmp_H_i -
          CellTemperatureUnbalance_U.Tmp_L_d >=
          CellTemperatureUnbalance_P.Chart1_ThresholdFault_3) {
        /* Transition: '<S1>:449' */
        tmp = CellTemperatureUnbalance_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellTemperatureUnbalance_DW.t3 = (uint8_T)tmp;
        if (CellTemperatureUnbalance_DW.t3 >
            CellTemperatureUnbalance_P.Chart1_Second_3) {
          /* Transition: '<S1>:452' */
          /* Transition: '<S1>:454' */
          CellTemperatureUnbalance_DW.F_3 = true;
          CellTemperatureUnbalance_DW.t3 = 0U;

          /* Transition: '<S1>:456' */
          /* Transition: '<S1>:455' */
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }
    } else {
      /* Transition: '<S1>:351' */
      /* Entry Internal 'F_3_false': '<S1>:281' */
      /* Transition: '<S1>:504' */
      CellTemperatureUnbalance_DW.F_3 = true;
      if ((CellTemperatureUnbalance_U.Tmp_H_i -
           CellTemperatureUnbalance_U.Tmp_L_d <
           CellTemperatureUnbalance_P.Chart1_ThresholdRecover_3) &&
          CellTemperatureUnbalance_DW.F_3) {
        /* Transition: '<S1>:490' */
        tmp = CellTemperatureUnbalance_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellTemperatureUnbalance_DW.t33 = (uint8_T)tmp;
        if (CellTemperatureUnbalance_DW.t33 >
            CellTemperatureUnbalance_P.Chart1_Second_33) {
          /* Transition: '<S1>:499' */
          /* Transition: '<S1>:494' */
          CellTemperatureUnbalance_DW.F_3 = false;
          CellTemperatureUnbalance_DW.t33 = 0U;

          /* Transition: '<S1>:501' */
          /* Transition: '<S1>:495' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    }

    if (guard6 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                    CellTemperatureUnbalance_U.Tmp_L_d >=
                    CellTemperatureUnbalance_P.Chart1_ThresholdRecover_3) &&
                   CellTemperatureUnbalance_DW.F_3)) {
      /* Transition: '<S1>:493' */
      /* Transition: '<S1>:489' */
      CellTemperatureUnbalance_DW.t33 = 0U;
      CellTemperatureUnbalance_DW.t1 = 0U;
      CellTemperatureUnbalance_DW.t2 = 0U;

      /* Transition: '<S1>:495' */
    } else {
      /* Transition: '<S1>:500' */
    }

    if (guard5 && ((CellTemperatureUnbalance_U.Tmp_H_i -
                    CellTemperatureUnbalance_U.Tmp_L_d <
                    CellTemperatureUnbalance_P.Chart1_ThresholdFault_3) &&
                   (!CellTemperatureUnbalance_DW.F_3))) {
      /* Transition: '<S1>:450' */
      /* Transition: '<S1>:453' */
      CellTemperatureUnbalance_DW.t3 = 0U;

      /* Transition: '<S1>:455' */
    } else {
      /* Transition: '<S1>:451' */
    }

    /* Entry Internal 'F_0': '<S1>:583' */
    /* Entry Internal 'F_0_true': '<S1>:557' */
    /* Transition: '<S1>:568' */
    if (CellTemperatureUnbalance_DW.F_3) {
      /* Transition: '<S1>:570' */
      /* Transition: '<S1>:575' */
      CellTemperatureUnbalance_DW.F_2 = false;
      CellTemperatureUnbalance_DW.F_1 = false;
      F_lev = 3U;

      /* Transition: '<S1>:582' */
      /* Transition: '<S1>:581' */
      /* Transition: '<S1>:580' */
      /* Transition: '<S1>:579' */
    } else if (CellTemperatureUnbalance_DW.F_2) {
      /* Transition: '<S1>:571' */
      /* Transition: '<S1>:576' */
      CellTemperatureUnbalance_DW.F_1 = false;
      F_lev = 2U;

      /* Transition: '<S1>:581' */
      /* Transition: '<S1>:580' */
      /* Transition: '<S1>:579' */
    } else if (CellTemperatureUnbalance_DW.F_1) {
      /* Transition: '<S1>:572' */
      /* Transition: '<S1>:577' */
      F_lev = 1U;

      /* Transition: '<S1>:580' */
      /* Transition: '<S1>:579' */
    } else {
      /* Transition: '<S1>:574' */
      F_lev = 0U;
    }
  } else {
    CellTemperatureUnbalance_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void CellTemperatureUnbalance_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(CellTemperatureUnbalance_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&CellTemperatureUnbalance_DW, 0,
                sizeof(DW_CellTemperatureUnbalance_T));

  /* external inputs */
  (void) memset((void *)&CellTemperatureUnbalance_U, 0,
                sizeof(ExtU_CellTemperatureUnbalance_T));

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  CellTemperatureUnbalance_DW.is_active_c1_CellTemperatureUnb = 0U;
  CellTemperatureUnbalance_DW.t1 = 0U;
  CellTemperatureUnbalance_DW.t2 = 0U;
  CellTemperatureUnbalance_DW.t3 = 0U;
  CellTemperatureUnbalance_DW.t22 = 0U;
  CellTemperatureUnbalance_DW.t33 = 0U;
  CellTemperatureUnbalance_DW.t11 = 0U;
  CellTemperatureUnbalance_DW.F_1 = false;
  CellTemperatureUnbalance_DW.F_2 = false;
  CellTemperatureUnbalance_DW.F_3 = false;
}

/* Model terminate function */
void CellTemperatureUnbalance_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
