/*
 * File: CellOverVoltage.c
 *
 * Code generated for Simulink model 'CellOverVoltage'.
 *
 * Model version                  : 1.204
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 09 10:09:13 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CellOverVoltage.h"
#include "CellOverVoltage_private.h"

/* Block states (auto storage) */
DW_CellOverVoltage_T CellOverVoltage_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_CellOverVoltage_T CellOverVoltage_U;

/* Real-time model */
RT_MODEL_CellOverVoltage_T CellOverVoltage_M_;
RT_MODEL_CellOverVoltage_T *const CellOverVoltage_M = &CellOverVoltage_M_;

/* Forward declaration for local functions */
static void CellOver_inner_default_F_0_true(uint8_T *F_lev);
static void CellOverVoltage_F(uint8_T *F_lev);

/* Function for Chart: '<Root>/Chart1' */
static void CellOver_inner_default_F_0_true(uint8_T *F_lev)
{
  /* Transition: '<S1>:965' */
  if (CellOverVoltage_DW.F_4) {
    /* Transition: '<S1>:967' */
    /* Transition: '<S1>:972' */
    CellOverVoltage_DW.F_2 = false;
    CellOverVoltage_DW.F_3 = false;
    CellOverVoltage_DW.F_1 = false;
    *F_lev = 4U;

    /* Transition: '<S1>:979' */
    /* Transition: '<S1>:978' */
    /* Transition: '<S1>:977' */
    /* Transition: '<S1>:976' */
  } else if (CellOverVoltage_DW.F_3) {
    /* Transition: '<S1>:968' */
    /* Transition: '<S1>:973' */
    CellOverVoltage_DW.F_1 = false;
    CellOverVoltage_DW.F_2 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:978' */
    /* Transition: '<S1>:977' */
    /* Transition: '<S1>:976' */
  } else if (CellOverVoltage_DW.F_2) {
    /* Transition: '<S1>:969' */
    /* Transition: '<S1>:974' */
    CellOverVoltage_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:977' */
    /* Transition: '<S1>:976' */
  } else if (CellOverVoltage_DW.F_1) {
    /* Transition: '<S1>:970' */
    /* Transition: '<S1>:975' */
    *F_lev = 1U;

    /* Transition: '<S1>:976' */
  } else {
    /* Transition: '<S1>:971' */
    *F_lev = 0U;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void CellOverVoltage_F(uint8_T *F_lev)
{
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  int32_T tmp;

  /* During 'F': '<S1>:352' */
  /* During 'F_1': '<S1>:326' */
  /* Transition: '<S1>:946' */
  if (!CellOverVoltage_DW.F_1) {
    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    /* Transition: '<S1>:344' */
    /* Exit Internal 'F_1': '<S1>:326' */
    /* Entry Internal 'F_1_true': '<S1>:1005' */
    /* Transition: '<S1>:1013' */
    if (CellOverVoltage_U.g_CellHighestVol_g >
        CellOverVoltage_P.Chart1_ThresholdFault_1) {
      /* Transition: '<S1>:1015' */
      tmp = CellOverVoltage_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellOverVoltage_DW.t1 = (uint8_T)tmp;
      if (CellOverVoltage_DW.t1 > CellOverVoltage_P.Chart1_Second_1) {
        /* Transition: '<S1>:1018' */
        /* Transition: '<S1>:1020' */
        CellOverVoltage_DW.F_1 = true;

        /* Transition: '<S1>:1022' */
        /* Transition: '<S1>:1021' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:523' */
    /* Exit Internal 'F_1': '<S1>:326' */
    /* Entry Internal 'F_1_false': '<S1>:270' */
    /* Transition: '<S1>:464' */
    CellOverVoltage_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((CellOverVoltage_U.g_CellHighestVol_g <=
         CellOverVoltage_P.Chart1_ThresholdRecover_1) && CellOverVoltage_DW.F_1)
    {
      /* Transition: '<S1>:453' */
      tmp = CellOverVoltage_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellOverVoltage_DW.t11 = (uint8_T)tmp;
      if (CellOverVoltage_DW.t11 > CellOverVoltage_P.Chart1_Second_11) {
        /* Transition: '<S1>:466' */
        /* Transition: '<S1>:461' */
        CellOverVoltage_DW.F_1 = false;
        CellOverVoltage_DW.t11 = 0U;

        /* Transition: '<S1>:456' */
        /* Transition: '<S1>:459' */
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
  if (guard11 && ((CellOverVoltage_U.g_CellHighestVol_g >
                   CellOverVoltage_P.Chart1_ThresholdRecover_1) &&
                  CellOverVoltage_DW.F_1)) {
    /* Transition: '<S1>:468' */
    /* Transition: '<S1>:465' */
    CellOverVoltage_DW.t11 = 0U;

    /* Transition: '<S1>:459' */
  } else {
    /* Transition: '<S1>:460' */
  }

  if (guard10 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                   CellOverVoltage_P.Chart1_ThresholdFault_1) &&
                  (!CellOverVoltage_DW.F_1))) {
    /* Transition: '<S1>:1016' */
    /* Transition: '<S1>:1019' */
    CellOverVoltage_DW.t1 = 0U;

    /* Transition: '<S1>:1021' */
  } else {
    /* Transition: '<S1>:1017' */
  }

  /* During 'F_2': '<S1>:250' */
  /* Transition: '<S1>:945' */
  guard10 = false;
  guard11 = false;
  if (!CellOverVoltage_DW.F_2) {
    /* Transition: '<S1>:268' */
    /* Exit Internal 'F_2': '<S1>:250' */
    /* Entry Internal 'F_2_true': '<S1>:251' */
    /* Transition: '<S1>:361' */
    CellOverVoltage_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (CellOverVoltage_U.g_CellHighestVol_g >
        CellOverVoltage_P.Chart1_ThresholdFault_2) {
      /* Transition: '<S1>:363' */
      tmp = CellOverVoltage_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellOverVoltage_DW.t2 = (uint8_T)tmp;
      if (CellOverVoltage_DW.t2 > CellOverVoltage_P.Chart1_Second_2) {
        /* Transition: '<S1>:360' */
        /* Transition: '<S1>:355' */
        CellOverVoltage_DW.F_2 = true;
        CellOverVoltage_DW.t2 = 0U;

        /* Transition: '<S1>:358' */
        /* Transition: '<S1>:356' */
        /* Transition: '<S1>:357' */
        /* Transition: '<S1>:354' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:521' */
    /* Exit Internal 'F_2': '<S1>:250' */
    /* Entry Internal 'F_2_false': '<S1>:232' */
    /* Transition: '<S1>:421' */
    CellOverVoltage_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((CellOverVoltage_U.g_CellHighestVol_g <=
         CellOverVoltage_P.Chart1_ThresholdRecover_2) && CellOverVoltage_DW.F_2)
    {
      /* Transition: '<S1>:413' */
      tmp = CellOverVoltage_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellOverVoltage_DW.t22 = (uint8_T)tmp;
      if (CellOverVoltage_DW.t22 > CellOverVoltage_P.Chart1_Second_22) {
        /* Transition: '<S1>:414' */
        /* Transition: '<S1>:429' */
        CellOverVoltage_DW.F_2 = false;
        CellOverVoltage_DW.t22 = 0U;

        /* Transition: '<S1>:425' */
        /* Transition: '<S1>:427' */
        /* Transition: '<S1>:418' */
        /* Transition: '<S1>:422' */
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
  if (guard11 && ((CellOverVoltage_U.g_CellHighestVol_g >
                   CellOverVoltage_P.Chart1_ThresholdRecover_2) &&
                  CellOverVoltage_DW.F_2)) {
    /* Transition: '<S1>:415' */
    /* Transition: '<S1>:419' */
    CellOverVoltage_DW.t22 = 0U;
    CellOverVoltage_DW.t1 = 0U;

    /* Transition: '<S1>:427' */
    /* Transition: '<S1>:418' */
    /* Transition: '<S1>:422' */
  } else {
    /* Transition: '<S1>:416' */
  }

  if (guard10 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                   CellOverVoltage_P.Chart1_ThresholdFault_2) &&
                  (!CellOverVoltage_DW.F_2))) {
    /* Transition: '<S1>:362' */
    /* Transition: '<S1>:353' */
    CellOverVoltage_DW.t2 = 0U;

    /* Transition: '<S1>:356' */
    /* Transition: '<S1>:357' */
    /* Transition: '<S1>:354' */
  } else {
    /* Transition: '<S1>:359' */
  }

  /* During 'F_3': '<S1>:307' */
  /* Transition: '<S1>:947' */
  guard10 = false;
  guard11 = false;
  if (!CellOverVoltage_DW.F_3) {
    /* Transition: '<S1>:325' */
    /* Exit Internal 'F_3': '<S1>:307' */
    /* Entry Internal 'F_3_true': '<S1>:308' */
    /* Transition: '<S1>:388' */
    CellOverVoltage_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (CellOverVoltage_U.g_CellHighestVol_g >
        CellOverVoltage_P.Chart1_ThresholdFault_3) {
      /* Transition: '<S1>:389' */
      tmp = CellOverVoltage_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellOverVoltage_DW.t3 = (uint8_T)tmp;
      if (CellOverVoltage_DW.t3 > CellOverVoltage_P.Chart1_Second_3) {
        /* Transition: '<S1>:386' */
        /* Transition: '<S1>:387' */
        CellOverVoltage_DW.F_3 = true;
        CellOverVoltage_DW.t3 = 0U;

        /* Transition: '<S1>:380' */
        /* Transition: '<S1>:384' */
        /* Transition: '<S1>:383' */
        /* Transition: '<S1>:381' */
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    /* Transition: '<S1>:522' */
    /* Exit Internal 'F_3': '<S1>:307' */
    /* Entry Internal 'F_3_false': '<S1>:289' */
    /* Transition: '<S1>:451' */
    CellOverVoltage_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((CellOverVoltage_U.g_CellHighestVol_g <=
         CellOverVoltage_P.Chart1_ThresholdRecover_3) && CellOverVoltage_DW.F_3)
    {
      /* Transition: '<S1>:435' */
      tmp = CellOverVoltage_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellOverVoltage_DW.t33 = (uint8_T)tmp;
      if (CellOverVoltage_DW.t33 > CellOverVoltage_P.Chart1_Second_33) {
        /* Transition: '<S1>:444' */
        /* Transition: '<S1>:446' */
        CellOverVoltage_DW.F_3 = false;
        CellOverVoltage_DW.t33 = 0U;

        /* Transition: '<S1>:450' */
        /* Transition: '<S1>:449' */
        /* Transition: '<S1>:445' */
        /* Transition: '<S1>:448' */
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
  if (guard11 && ((CellOverVoltage_U.g_CellHighestVol_g >
                   CellOverVoltage_P.Chart1_ThresholdRecover_3) &&
                  CellOverVoltage_DW.F_3)) {
    /* Transition: '<S1>:441' */
    /* Transition: '<S1>:447' */
    CellOverVoltage_DW.t33 = 0U;
    CellOverVoltage_DW.t1 = 0U;
    CellOverVoltage_DW.t2 = 0U;

    /* Transition: '<S1>:449' */
    /* Transition: '<S1>:445' */
    /* Transition: '<S1>:448' */
  } else {
    /* Transition: '<S1>:443' */
  }

  if (guard10 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                   CellOverVoltage_P.Chart1_ThresholdFault_3) &&
                  (!CellOverVoltage_DW.F_3))) {
    /* Transition: '<S1>:382' */
    /* Transition: '<S1>:379' */
    CellOverVoltage_DW.t3 = 0U;

    /* Transition: '<S1>:384' */
    /* Transition: '<S1>:383' */
    /* Transition: '<S1>:381' */
  } else {
    /* Transition: '<S1>:385' */
  }

  /* During 'F_44': '<S1>:568' */
  /* Transition: '<S1>:576' */
  /* Exit Internal 'F_44': '<S1>:568' */
  /* Entry Internal 'F_4_true': '<S1>:983' */
  /* Transition: '<S1>:993' */
  guard10 = false;

  /* Inport: '<Root>/In1' incorporates:
   *  Chart: '<Root>/Chart1'
   */
  if (CellOverVoltage_U.g_CellHighestVol_g >
      CellOverVoltage_P.Chart1_ThresholdFault_4) {
    /* Transition: '<S1>:994' */
    tmp = CellOverVoltage_DW.t4 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    CellOverVoltage_DW.t4 = (uint8_T)tmp;
    if (CellOverVoltage_DW.t4 > CellOverVoltage_P.Chart1_Second_4) {
      /* Transition: '<S1>:998' */
      /* Transition: '<S1>:1000' */
      CellOverVoltage_DW.F_4 = true;

      /* Transition: '<S1>:1004' */
      /* Transition: '<S1>:1003' */
      /* Transition: '<S1>:1002' */
      /* Transition: '<S1>:1001' */
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                   CellOverVoltage_P.Chart1_ThresholdFault_4) &&
                  (!CellOverVoltage_DW.F_4))) {
    /* Transition: '<S1>:996' */
    /* Transition: '<S1>:999' */
    CellOverVoltage_DW.t4 = 0U;

    /* Transition: '<S1>:1003' */
    /* Transition: '<S1>:1002' */
    /* Transition: '<S1>:1001' */
  } else {
    /* Transition: '<S1>:997' */
  }

  /* During 'F_0': '<S1>:980' */
  /* Transition: '<S1>:981' */
  /* Exit Internal 'F_0': '<S1>:980' */
  /* Entry Internal 'F_0_true': '<S1>:954' */
  CellOver_inner_default_F_0_true(F_lev);
}

/* Model step function */
uint8_T CellOverVoltage_step(real32_T g_CellHighestVol)
{
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  uint8_T F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  CellOverVoltage_U.g_CellHighestVol_g = g_CellHighestVol;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (CellOverVoltage_DW.is_active_c1_CellOverVoltage == 0U) {
    /* Entry: Chart1 */
    CellOverVoltage_DW.is_active_c1_CellOverVoltage = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:469' */
    /* Entry Internal 'F': '<S1>:352' */
    /* Entry Internal 'F_1': '<S1>:326' */
    /* Transition: '<S1>:532' */
    if (!CellOverVoltage_DW.F_1) {
      /* Transition: '<S1>:344' */
      /* Entry Internal 'F_1_true': '<S1>:1005' */
      /* Transition: '<S1>:1013' */
      if (CellOverVoltage_U.g_CellHighestVol_g >
          CellOverVoltage_P.Chart1_ThresholdFault_1) {
        /* Transition: '<S1>:1015' */
        tmp = CellOverVoltage_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellOverVoltage_DW.t1 = (uint8_T)tmp;
        if (CellOverVoltage_DW.t1 > CellOverVoltage_P.Chart1_Second_1) {
          /* Transition: '<S1>:1018' */
          /* Transition: '<S1>:1020' */
          CellOverVoltage_DW.F_1 = true;

          /* Transition: '<S1>:1022' */
          /* Transition: '<S1>:1021' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:523' */
      /* Entry Internal 'F_1_false': '<S1>:270' */
      /* Transition: '<S1>:464' */
      CellOverVoltage_DW.F_1 = true;
      if ((CellOverVoltage_U.g_CellHighestVol_g <=
           CellOverVoltage_P.Chart1_ThresholdRecover_1) &&
          CellOverVoltage_DW.F_1) {
        /* Transition: '<S1>:453' */
        tmp = CellOverVoltage_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellOverVoltage_DW.t11 = (uint8_T)tmp;
        if (CellOverVoltage_DW.t11 > CellOverVoltage_P.Chart1_Second_11) {
          /* Transition: '<S1>:466' */
          /* Transition: '<S1>:461' */
          CellOverVoltage_DW.F_1 = false;
          CellOverVoltage_DW.t11 = 0U;

          /* Transition: '<S1>:456' */
          /* Transition: '<S1>:459' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((CellOverVoltage_U.g_CellHighestVol_g >
                    CellOverVoltage_P.Chart1_ThresholdRecover_1) &&
                   CellOverVoltage_DW.F_1)) {
      /* Transition: '<S1>:468' */
      /* Transition: '<S1>:465' */
      CellOverVoltage_DW.t11 = 0U;

      /* Transition: '<S1>:459' */
    } else {
      /* Transition: '<S1>:460' */
    }

    if (guard6 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                    CellOverVoltage_P.Chart1_ThresholdFault_1) &&
                   (!CellOverVoltage_DW.F_1))) {
      /* Transition: '<S1>:1016' */
      /* Transition: '<S1>:1019' */
      CellOverVoltage_DW.t1 = 0U;

      /* Transition: '<S1>:1021' */
    } else {
      /* Transition: '<S1>:1017' */
    }

    /* Entry Internal 'F_2': '<S1>:250' */
    /* Transition: '<S1>:528' */
    guard6 = false;
    guard7 = false;
    if (!CellOverVoltage_DW.F_2) {
      /* Transition: '<S1>:268' */
      /* Entry Internal 'F_2_true': '<S1>:251' */
      /* Transition: '<S1>:361' */
      CellOverVoltage_DW.F_2 = false;
      if (CellOverVoltage_U.g_CellHighestVol_g >
          CellOverVoltage_P.Chart1_ThresholdFault_2) {
        /* Transition: '<S1>:363' */
        tmp = CellOverVoltage_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellOverVoltage_DW.t2 = (uint8_T)tmp;
        if (CellOverVoltage_DW.t2 > CellOverVoltage_P.Chart1_Second_2) {
          /* Transition: '<S1>:360' */
          /* Transition: '<S1>:355' */
          CellOverVoltage_DW.F_2 = true;
          CellOverVoltage_DW.t2 = 0U;

          /* Transition: '<S1>:358' */
          /* Transition: '<S1>:356' */
          /* Transition: '<S1>:357' */
          /* Transition: '<S1>:354' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:521' */
      /* Entry Internal 'F_2_false': '<S1>:232' */
      /* Transition: '<S1>:421' */
      CellOverVoltage_DW.F_2 = true;
      if ((CellOverVoltage_U.g_CellHighestVol_g <=
           CellOverVoltage_P.Chart1_ThresholdRecover_2) &&
          CellOverVoltage_DW.F_2) {
        /* Transition: '<S1>:413' */
        tmp = CellOverVoltage_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellOverVoltage_DW.t22 = (uint8_T)tmp;
        if (CellOverVoltage_DW.t22 > CellOverVoltage_P.Chart1_Second_22) {
          /* Transition: '<S1>:414' */
          /* Transition: '<S1>:429' */
          CellOverVoltage_DW.F_2 = false;
          CellOverVoltage_DW.t22 = 0U;

          /* Transition: '<S1>:425' */
          /* Transition: '<S1>:427' */
          /* Transition: '<S1>:418' */
          /* Transition: '<S1>:422' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((CellOverVoltage_U.g_CellHighestVol_g >
                    CellOverVoltage_P.Chart1_ThresholdRecover_2) &&
                   CellOverVoltage_DW.F_2)) {
      /* Transition: '<S1>:415' */
      /* Transition: '<S1>:419' */
      CellOverVoltage_DW.t22 = 0U;
      CellOverVoltage_DW.t1 = 0U;

      /* Transition: '<S1>:427' */
      /* Transition: '<S1>:418' */
      /* Transition: '<S1>:422' */
    } else {
      /* Transition: '<S1>:416' */
    }

    if (guard6 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                    CellOverVoltage_P.Chart1_ThresholdFault_2) &&
                   (!CellOverVoltage_DW.F_2))) {
      /* Transition: '<S1>:362' */
      /* Transition: '<S1>:353' */
      CellOverVoltage_DW.t2 = 0U;

      /* Transition: '<S1>:356' */
      /* Transition: '<S1>:357' */
      /* Transition: '<S1>:354' */
    } else {
      /* Transition: '<S1>:359' */
    }

    /* Entry Internal 'F_3': '<S1>:307' */
    /* Transition: '<S1>:530' */
    guard6 = false;
    guard7 = false;
    if (!CellOverVoltage_DW.F_3) {
      /* Transition: '<S1>:325' */
      /* Entry Internal 'F_3_true': '<S1>:308' */
      /* Transition: '<S1>:388' */
      CellOverVoltage_DW.F_3 = false;
      if (CellOverVoltage_U.g_CellHighestVol_g >
          CellOverVoltage_P.Chart1_ThresholdFault_3) {
        /* Transition: '<S1>:389' */
        tmp = CellOverVoltage_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellOverVoltage_DW.t3 = (uint8_T)tmp;
        if (CellOverVoltage_DW.t3 > CellOverVoltage_P.Chart1_Second_3) {
          /* Transition: '<S1>:386' */
          /* Transition: '<S1>:387' */
          CellOverVoltage_DW.F_3 = true;
          CellOverVoltage_DW.t3 = 0U;

          /* Transition: '<S1>:380' */
          /* Transition: '<S1>:384' */
          /* Transition: '<S1>:383' */
          /* Transition: '<S1>:381' */
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      /* Transition: '<S1>:522' */
      /* Entry Internal 'F_3_false': '<S1>:289' */
      /* Transition: '<S1>:451' */
      CellOverVoltage_DW.F_3 = true;
      if ((CellOverVoltage_U.g_CellHighestVol_g <=
           CellOverVoltage_P.Chart1_ThresholdRecover_3) &&
          CellOverVoltage_DW.F_3) {
        /* Transition: '<S1>:435' */
        tmp = CellOverVoltage_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellOverVoltage_DW.t33 = (uint8_T)tmp;
        if (CellOverVoltage_DW.t33 > CellOverVoltage_P.Chart1_Second_33) {
          /* Transition: '<S1>:444' */
          /* Transition: '<S1>:446' */
          CellOverVoltage_DW.F_3 = false;
          CellOverVoltage_DW.t33 = 0U;

          /* Transition: '<S1>:450' */
          /* Transition: '<S1>:449' */
          /* Transition: '<S1>:445' */
          /* Transition: '<S1>:448' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((CellOverVoltage_U.g_CellHighestVol_g >
                    CellOverVoltage_P.Chart1_ThresholdRecover_3) &&
                   CellOverVoltage_DW.F_3)) {
      /* Transition: '<S1>:441' */
      /* Transition: '<S1>:447' */
      CellOverVoltage_DW.t33 = 0U;
      CellOverVoltage_DW.t1 = 0U;
      CellOverVoltage_DW.t2 = 0U;

      /* Transition: '<S1>:449' */
      /* Transition: '<S1>:445' */
      /* Transition: '<S1>:448' */
    } else {
      /* Transition: '<S1>:443' */
    }

    if (guard6 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                    CellOverVoltage_P.Chart1_ThresholdFault_3) &&
                   (!CellOverVoltage_DW.F_3))) {
      /* Transition: '<S1>:382' */
      /* Transition: '<S1>:379' */
      CellOverVoltage_DW.t3 = 0U;

      /* Transition: '<S1>:384' */
      /* Transition: '<S1>:383' */
      /* Transition: '<S1>:381' */
    } else {
      /* Transition: '<S1>:385' */
    }

    /* Entry Internal 'F_44': '<S1>:568' */
    /* Entry Internal 'F_4_true': '<S1>:983' */
    /* Transition: '<S1>:993' */
    guard6 = false;
    if (CellOverVoltage_U.g_CellHighestVol_g >
        CellOverVoltage_P.Chart1_ThresholdFault_4) {
      /* Transition: '<S1>:994' */
      tmp = CellOverVoltage_DW.t4 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellOverVoltage_DW.t4 = (uint8_T)tmp;
      if (CellOverVoltage_DW.t4 > CellOverVoltage_P.Chart1_Second_4) {
        /* Transition: '<S1>:998' */
        /* Transition: '<S1>:1000' */
        CellOverVoltage_DW.F_4 = true;

        /* Transition: '<S1>:1004' */
        /* Transition: '<S1>:1003' */
        /* Transition: '<S1>:1002' */
        /* Transition: '<S1>:1001' */
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 && ((CellOverVoltage_U.g_CellHighestVol_g <=
                    CellOverVoltage_P.Chart1_ThresholdFault_4) &&
                   (!CellOverVoltage_DW.F_4))) {
      /* Transition: '<S1>:996' */
      /* Transition: '<S1>:999' */
      CellOverVoltage_DW.t4 = 0U;

      /* Transition: '<S1>:1003' */
      /* Transition: '<S1>:1002' */
      /* Transition: '<S1>:1001' */
    } else {
      /* Transition: '<S1>:997' */
    }

    /* Entry Internal 'F_0': '<S1>:980' */
    /* Entry Internal 'F_0_true': '<S1>:954' */
    CellOver_inner_default_F_0_true(&F_lev);
  } else {
    CellOverVoltage_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void CellOverVoltage_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(CellOverVoltage_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&CellOverVoltage_DW, 0,
                sizeof(DW_CellOverVoltage_T));

  /* external inputs */
  CellOverVoltage_U.g_CellHighestVol_g = 0.0F;

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  CellOverVoltage_DW.is_active_c1_CellOverVoltage = 0U;
  CellOverVoltage_DW.t1 = 0U;
  CellOverVoltage_DW.t2 = 0U;
  CellOverVoltage_DW.t3 = 0U;
  CellOverVoltage_DW.t22 = 0U;
  CellOverVoltage_DW.t33 = 0U;
  CellOverVoltage_DW.t11 = 0U;
  CellOverVoltage_DW.t4 = 0U;
  CellOverVoltage_DW.F_1 = false;
  CellOverVoltage_DW.F_2 = false;
  CellOverVoltage_DW.F_3 = false;
  CellOverVoltage_DW.F_4 = false;
}

/* Model terminate function */
void CellOverVoltage_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
