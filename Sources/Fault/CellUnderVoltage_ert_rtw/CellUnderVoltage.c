/*
 * File: CellUnderVoltage.c
 *
 * Code generated for Simulink model 'CellUnderVoltage'.
 *
 * Model version                  : 1.211
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Dec 12 10:46:31 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CellUnderVoltage.h"
#include "CellUnderVoltage_private.h"

/* Block states (auto storage) */
DW_CellUnderVoltage_T CellUnderVoltage_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_CellUnderVoltage_T CellUnderVoltage_U;

/* Real-time model */
RT_MODEL_CellUnderVoltage_T CellUnderVoltage_M_;
RT_MODEL_CellUnderVoltage_T *const CellUnderVoltage_M = &CellUnderVoltage_M_;

/* Forward declaration for local functions */
static void CellUnde_inner_default_F_0_true(uint8_T *F_lev);
static void CellUnderVoltage_F(uint8_T *F_lev);

/* Function for Chart: '<Root>/Chart1' */
static void CellUnde_inner_default_F_0_true(uint8_T *F_lev)
{
  /* Transition: '<S1>:965' */
  if (CellUnderVoltage_DW.F_4) {
    /* Transition: '<S1>:967' */
    /* Transition: '<S1>:972' */
    CellUnderVoltage_DW.F_2 = false;
    CellUnderVoltage_DW.F_3 = false;
    CellUnderVoltage_DW.F_1 = false;
    *F_lev = 4U;

    /* Transition: '<S1>:979' */
    /* Transition: '<S1>:978' */
    /* Transition: '<S1>:977' */
    /* Transition: '<S1>:976' */
  } else if (CellUnderVoltage_DW.F_3) {
    /* Transition: '<S1>:968' */
    /* Transition: '<S1>:973' */
    CellUnderVoltage_DW.F_1 = false;
    CellUnderVoltage_DW.F_2 = false;
    *F_lev = 3U;

    /* Transition: '<S1>:978' */
    /* Transition: '<S1>:977' */
    /* Transition: '<S1>:976' */
  } else if (CellUnderVoltage_DW.F_2) {
    /* Transition: '<S1>:969' */
    /* Transition: '<S1>:974' */
    CellUnderVoltage_DW.F_1 = false;
    *F_lev = 2U;

    /* Transition: '<S1>:977' */
    /* Transition: '<S1>:976' */
  } else if (CellUnderVoltage_DW.F_1) {
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
static void CellUnderVoltage_F(uint8_T *F_lev)
{
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  int32_T tmp;

  /* During 'F': '<S1>:352' */
  /* During 'F_1': '<S1>:326' */
  /* Transition: '<S1>:946' */
  if (!CellUnderVoltage_DW.F_1) {
    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    /* Transition: '<S1>:344' */
    /* Exit Internal 'F_1': '<S1>:326' */
    /* Entry Internal 'F_1_true': '<S1>:1005' */
    /* Transition: '<S1>:1013' */
    if (CellUnderVoltage_U.g_CellLowestVol_g <
        CellUnderVoltage_P.Chart1_ThresholdFault_1) {
      /* Transition: '<S1>:1015' */
      tmp = CellUnderVoltage_DW.t1 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellUnderVoltage_DW.t1 = (uint8_T)tmp;
      if (CellUnderVoltage_DW.t1 > CellUnderVoltage_P.Chart1_Second_1) {
        /* Transition: '<S1>:1018' */
        /* Transition: '<S1>:1020' */
        CellUnderVoltage_DW.F_1 = true;

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
    CellUnderVoltage_DW.F_1 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((CellUnderVoltage_U.g_CellLowestVol_g >=
         CellUnderVoltage_P.Chart1_ThresholdRecover_1) &&
        CellUnderVoltage_DW.F_1) {
      /* Transition: '<S1>:453' */
      tmp = CellUnderVoltage_DW.t11 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellUnderVoltage_DW.t11 = (uint8_T)tmp;
      if (CellUnderVoltage_DW.t11 > CellUnderVoltage_P.Chart1_Second_11) {
        /* Transition: '<S1>:466' */
        /* Transition: '<S1>:461' */
        CellUnderVoltage_DW.F_1 = false;
        CellUnderVoltage_DW.t11 = 0U;

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
  if (guard11 && ((CellUnderVoltage_U.g_CellLowestVol_g <
                   CellUnderVoltage_P.Chart1_ThresholdRecover_1) &&
                  CellUnderVoltage_DW.F_1)) {
    /* Transition: '<S1>:468' */
    /* Transition: '<S1>:465' */
    CellUnderVoltage_DW.t11 = 0U;

    /* Transition: '<S1>:459' */
  } else {
    /* Transition: '<S1>:460' */
  }

  if (guard10 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                   CellUnderVoltage_P.Chart1_ThresholdFault_1) &&
                  (!CellUnderVoltage_DW.F_1))) {
    /* Transition: '<S1>:1016' */
    /* Transition: '<S1>:1019' */
    CellUnderVoltage_DW.t1 = 0U;

    /* Transition: '<S1>:1021' */
  } else {
    /* Transition: '<S1>:1017' */
  }

  /* During 'F_2': '<S1>:250' */
  /* Transition: '<S1>:945' */
  guard10 = false;
  guard11 = false;
  if (!CellUnderVoltage_DW.F_2) {
    /* Transition: '<S1>:268' */
    /* Exit Internal 'F_2': '<S1>:250' */
    /* Entry Internal 'F_2_true': '<S1>:251' */
    /* Transition: '<S1>:361' */
    CellUnderVoltage_DW.F_2 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (CellUnderVoltage_U.g_CellLowestVol_g <
        CellUnderVoltage_P.Chart1_ThresholdFault_2) {
      /* Transition: '<S1>:363' */
      tmp = CellUnderVoltage_DW.t2 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellUnderVoltage_DW.t2 = (uint8_T)tmp;
      if (CellUnderVoltage_DW.t2 > CellUnderVoltage_P.Chart1_Second_2) {
        /* Transition: '<S1>:360' */
        /* Transition: '<S1>:355' */
        CellUnderVoltage_DW.F_2 = true;
        CellUnderVoltage_DW.t2 = 0U;

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
    CellUnderVoltage_DW.F_2 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((CellUnderVoltage_U.g_CellLowestVol_g >=
         CellUnderVoltage_P.Chart1_ThresholdRecover_2) &&
        CellUnderVoltage_DW.F_2) {
      /* Transition: '<S1>:413' */
      tmp = CellUnderVoltage_DW.t22 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellUnderVoltage_DW.t22 = (uint8_T)tmp;
      if (CellUnderVoltage_DW.t22 > CellUnderVoltage_P.Chart1_Second_22) {
        /* Transition: '<S1>:414' */
        /* Transition: '<S1>:429' */
        CellUnderVoltage_DW.F_2 = false;
        CellUnderVoltage_DW.t22 = 0U;

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
  if (guard11 && ((CellUnderVoltage_U.g_CellLowestVol_g <
                   CellUnderVoltage_P.Chart1_ThresholdRecover_2) &&
                  CellUnderVoltage_DW.F_2)) {
    /* Transition: '<S1>:415' */
    /* Transition: '<S1>:419' */
    CellUnderVoltage_DW.t22 = 0U;
    CellUnderVoltage_DW.t1 = 0U;

    /* Transition: '<S1>:427' */
    /* Transition: '<S1>:418' */
    /* Transition: '<S1>:422' */
  } else {
    /* Transition: '<S1>:416' */
  }

  if (guard10 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                   CellUnderVoltage_P.Chart1_ThresholdFault_2) &&
                  (!CellUnderVoltage_DW.F_2))) {
    /* Transition: '<S1>:362' */
    /* Transition: '<S1>:353' */
    CellUnderVoltage_DW.t2 = 0U;

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
  if (!CellUnderVoltage_DW.F_3) {
    /* Transition: '<S1>:325' */
    /* Exit Internal 'F_3': '<S1>:307' */
    /* Entry Internal 'F_3_true': '<S1>:308' */
    /* Transition: '<S1>:388' */
    CellUnderVoltage_DW.F_3 = false;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if (CellUnderVoltage_U.g_CellLowestVol_g <
        CellUnderVoltage_P.Chart1_ThresholdFault_3) {
      /* Transition: '<S1>:389' */
      tmp = CellUnderVoltage_DW.t3 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellUnderVoltage_DW.t3 = (uint8_T)tmp;
      if (CellUnderVoltage_DW.t3 > CellUnderVoltage_P.Chart1_Second_3) {
        /* Transition: '<S1>:386' */
        /* Transition: '<S1>:387' */
        CellUnderVoltage_DW.F_3 = true;
        CellUnderVoltage_DW.t3 = 0U;

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
    CellUnderVoltage_DW.F_3 = true;

    /* Inport: '<Root>/In1' incorporates:
     *  Chart: '<Root>/Chart1'
     */
    if ((CellUnderVoltage_U.g_CellLowestVol_g >=
         CellUnderVoltage_P.Chart1_ThresholdRecover_3) &&
        CellUnderVoltage_DW.F_3) {
      /* Transition: '<S1>:435' */
      tmp = CellUnderVoltage_DW.t33 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellUnderVoltage_DW.t33 = (uint8_T)tmp;
      if (CellUnderVoltage_DW.t33 > CellUnderVoltage_P.Chart1_Second_33) {
        /* Transition: '<S1>:444' */
        /* Transition: '<S1>:446' */
        CellUnderVoltage_DW.F_3 = false;
        CellUnderVoltage_DW.t33 = 0U;

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
  if (guard11 && ((CellUnderVoltage_U.g_CellLowestVol_g <
                   CellUnderVoltage_P.Chart1_ThresholdRecover_3) &&
                  CellUnderVoltage_DW.F_3)) {
    /* Transition: '<S1>:441' */
    /* Transition: '<S1>:447' */
    CellUnderVoltage_DW.t33 = 0U;
    CellUnderVoltage_DW.t1 = 0U;
    CellUnderVoltage_DW.t2 = 0U;

    /* Transition: '<S1>:449' */
    /* Transition: '<S1>:445' */
    /* Transition: '<S1>:448' */
  } else {
    /* Transition: '<S1>:443' */
  }

  if (guard10 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                   CellUnderVoltage_P.Chart1_ThresholdFault_3) &&
                  (!CellUnderVoltage_DW.F_3))) {
    /* Transition: '<S1>:382' */
    /* Transition: '<S1>:379' */
    CellUnderVoltage_DW.t3 = 0U;

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
  if (CellUnderVoltage_U.g_CellLowestVol_g <
      CellUnderVoltage_P.Chart1_ThresholdFault_4) {
    /* Transition: '<S1>:994' */
    tmp = CellUnderVoltage_DW.t4 + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    CellUnderVoltage_DW.t4 = (uint8_T)tmp;
    if (CellUnderVoltage_DW.t4 > CellUnderVoltage_P.Chart1_Second_4) {
      /* Transition: '<S1>:998' */
      /* Transition: '<S1>:1000' */
      CellUnderVoltage_DW.F_4 = true;

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

  if (guard10 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                   CellUnderVoltage_P.Chart1_ThresholdFault_4) &&
                  (!CellUnderVoltage_DW.F_4))) {
    /* Transition: '<S1>:996' */
    /* Transition: '<S1>:999' */
    CellUnderVoltage_DW.t4 = 0U;

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
  CellUnde_inner_default_F_0_true(F_lev);
}

/* Model step function */
uint8_T CellUnderVoltage_step(real32_T g_CellLowestVol)
{
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  uint8_T F_lev;
  int32_T tmp;

  /* specified return value */
  uint8_T F_level;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  CellUnderVoltage_U.g_CellLowestVol_g = g_CellLowestVol;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (CellUnderVoltage_DW.is_active_c1_CellUnderVoltage == 0U) {
    /* Entry: Chart1 */
    CellUnderVoltage_DW.is_active_c1_CellUnderVoltage = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:469' */
    /* Entry Internal 'F': '<S1>:352' */
    /* Entry Internal 'F_1': '<S1>:326' */
    /* Transition: '<S1>:532' */
    if (!CellUnderVoltage_DW.F_1) {
      /* Transition: '<S1>:344' */
      /* Entry Internal 'F_1_true': '<S1>:1005' */
      /* Transition: '<S1>:1013' */
      if (CellUnderVoltage_U.g_CellLowestVol_g <
          CellUnderVoltage_P.Chart1_ThresholdFault_1) {
        /* Transition: '<S1>:1015' */
        tmp = CellUnderVoltage_DW.t1 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellUnderVoltage_DW.t1 = (uint8_T)tmp;
        if (CellUnderVoltage_DW.t1 > CellUnderVoltage_P.Chart1_Second_1) {
          /* Transition: '<S1>:1018' */
          /* Transition: '<S1>:1020' */
          CellUnderVoltage_DW.F_1 = true;

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
      CellUnderVoltage_DW.F_1 = true;
      if ((CellUnderVoltage_U.g_CellLowestVol_g >=
           CellUnderVoltage_P.Chart1_ThresholdRecover_1) &&
          CellUnderVoltage_DW.F_1) {
        /* Transition: '<S1>:453' */
        tmp = CellUnderVoltage_DW.t11 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellUnderVoltage_DW.t11 = (uint8_T)tmp;
        if (CellUnderVoltage_DW.t11 > CellUnderVoltage_P.Chart1_Second_11) {
          /* Transition: '<S1>:466' */
          /* Transition: '<S1>:461' */
          CellUnderVoltage_DW.F_1 = false;
          CellUnderVoltage_DW.t11 = 0U;

          /* Transition: '<S1>:456' */
          /* Transition: '<S1>:459' */
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 && ((CellUnderVoltage_U.g_CellLowestVol_g <
                    CellUnderVoltage_P.Chart1_ThresholdRecover_1) &&
                   CellUnderVoltage_DW.F_1)) {
      /* Transition: '<S1>:468' */
      /* Transition: '<S1>:465' */
      CellUnderVoltage_DW.t11 = 0U;

      /* Transition: '<S1>:459' */
    } else {
      /* Transition: '<S1>:460' */
    }

    if (guard6 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                    CellUnderVoltage_P.Chart1_ThresholdFault_1) &&
                   (!CellUnderVoltage_DW.F_1))) {
      /* Transition: '<S1>:1016' */
      /* Transition: '<S1>:1019' */
      CellUnderVoltage_DW.t1 = 0U;

      /* Transition: '<S1>:1021' */
    } else {
      /* Transition: '<S1>:1017' */
    }

    /* Entry Internal 'F_2': '<S1>:250' */
    /* Transition: '<S1>:528' */
    guard6 = false;
    guard7 = false;
    if (!CellUnderVoltage_DW.F_2) {
      /* Transition: '<S1>:268' */
      /* Entry Internal 'F_2_true': '<S1>:251' */
      /* Transition: '<S1>:361' */
      CellUnderVoltage_DW.F_2 = false;
      if (CellUnderVoltage_U.g_CellLowestVol_g <
          CellUnderVoltage_P.Chart1_ThresholdFault_2) {
        /* Transition: '<S1>:363' */
        tmp = CellUnderVoltage_DW.t2 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellUnderVoltage_DW.t2 = (uint8_T)tmp;
        if (CellUnderVoltage_DW.t2 > CellUnderVoltage_P.Chart1_Second_2) {
          /* Transition: '<S1>:360' */
          /* Transition: '<S1>:355' */
          CellUnderVoltage_DW.F_2 = true;
          CellUnderVoltage_DW.t2 = 0U;

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
      CellUnderVoltage_DW.F_2 = true;
      if ((CellUnderVoltage_U.g_CellLowestVol_g >=
           CellUnderVoltage_P.Chart1_ThresholdRecover_2) &&
          CellUnderVoltage_DW.F_2) {
        /* Transition: '<S1>:413' */
        tmp = CellUnderVoltage_DW.t22 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellUnderVoltage_DW.t22 = (uint8_T)tmp;
        if (CellUnderVoltage_DW.t22 > CellUnderVoltage_P.Chart1_Second_22) {
          /* Transition: '<S1>:414' */
          /* Transition: '<S1>:429' */
          CellUnderVoltage_DW.F_2 = false;
          CellUnderVoltage_DW.t22 = 0U;

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

    if (guard7 && ((CellUnderVoltage_U.g_CellLowestVol_g <
                    CellUnderVoltage_P.Chart1_ThresholdRecover_2) &&
                   CellUnderVoltage_DW.F_2)) {
      /* Transition: '<S1>:415' */
      /* Transition: '<S1>:419' */
      CellUnderVoltage_DW.t22 = 0U;
      CellUnderVoltage_DW.t1 = 0U;

      /* Transition: '<S1>:427' */
      /* Transition: '<S1>:418' */
      /* Transition: '<S1>:422' */
    } else {
      /* Transition: '<S1>:416' */
    }

    if (guard6 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                    CellUnderVoltage_P.Chart1_ThresholdFault_2) &&
                   (!CellUnderVoltage_DW.F_2))) {
      /* Transition: '<S1>:362' */
      /* Transition: '<S1>:353' */
      CellUnderVoltage_DW.t2 = 0U;

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
    if (!CellUnderVoltage_DW.F_3) {
      /* Transition: '<S1>:325' */
      /* Entry Internal 'F_3_true': '<S1>:308' */
      /* Transition: '<S1>:388' */
      CellUnderVoltage_DW.F_3 = false;
      if (CellUnderVoltage_U.g_CellLowestVol_g <
          CellUnderVoltage_P.Chart1_ThresholdFault_3) {
        /* Transition: '<S1>:389' */
        tmp = CellUnderVoltage_DW.t3 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellUnderVoltage_DW.t3 = (uint8_T)tmp;
        if (CellUnderVoltage_DW.t3 > CellUnderVoltage_P.Chart1_Second_3) {
          /* Transition: '<S1>:386' */
          /* Transition: '<S1>:387' */
          CellUnderVoltage_DW.F_3 = true;
          CellUnderVoltage_DW.t3 = 0U;

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
      CellUnderVoltage_DW.F_3 = true;
      if ((CellUnderVoltage_U.g_CellLowestVol_g >=
           CellUnderVoltage_P.Chart1_ThresholdRecover_3) &&
          CellUnderVoltage_DW.F_3) {
        /* Transition: '<S1>:435' */
        tmp = CellUnderVoltage_DW.t33 + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        CellUnderVoltage_DW.t33 = (uint8_T)tmp;
        if (CellUnderVoltage_DW.t33 > CellUnderVoltage_P.Chart1_Second_33) {
          /* Transition: '<S1>:444' */
          /* Transition: '<S1>:446' */
          CellUnderVoltage_DW.F_3 = false;
          CellUnderVoltage_DW.t33 = 0U;

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

    if (guard7 && ((CellUnderVoltage_U.g_CellLowestVol_g <
                    CellUnderVoltage_P.Chart1_ThresholdRecover_3) &&
                   CellUnderVoltage_DW.F_3)) {
      /* Transition: '<S1>:441' */
      /* Transition: '<S1>:447' */
      CellUnderVoltage_DW.t33 = 0U;
      CellUnderVoltage_DW.t1 = 0U;
      CellUnderVoltage_DW.t2 = 0U;

      /* Transition: '<S1>:449' */
      /* Transition: '<S1>:445' */
      /* Transition: '<S1>:448' */
    } else {
      /* Transition: '<S1>:443' */
    }

    if (guard6 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                    CellUnderVoltage_P.Chart1_ThresholdFault_3) &&
                   (!CellUnderVoltage_DW.F_3))) {
      /* Transition: '<S1>:382' */
      /* Transition: '<S1>:379' */
      CellUnderVoltage_DW.t3 = 0U;

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
    if (CellUnderVoltage_U.g_CellLowestVol_g <
        CellUnderVoltage_P.Chart1_ThresholdFault_4) {
      /* Transition: '<S1>:994' */
      tmp = CellUnderVoltage_DW.t4 + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CellUnderVoltage_DW.t4 = (uint8_T)tmp;
      if (CellUnderVoltage_DW.t4 > CellUnderVoltage_P.Chart1_Second_4) {
        /* Transition: '<S1>:998' */
        /* Transition: '<S1>:1000' */
        CellUnderVoltage_DW.F_4 = true;

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

    if (guard6 && ((CellUnderVoltage_U.g_CellLowestVol_g >=
                    CellUnderVoltage_P.Chart1_ThresholdFault_4) &&
                   (!CellUnderVoltage_DW.F_4))) {
      /* Transition: '<S1>:996' */
      /* Transition: '<S1>:999' */
      CellUnderVoltage_DW.t4 = 0U;

      /* Transition: '<S1>:1003' */
      /* Transition: '<S1>:1002' */
      /* Transition: '<S1>:1001' */
    } else {
      /* Transition: '<S1>:997' */
    }

    /* Entry Internal 'F_0': '<S1>:980' */
    /* Entry Internal 'F_0_true': '<S1>:954' */
    CellUnde_inner_default_F_0_true(&F_lev);
  } else {
    CellUnderVoltage_F(&F_lev);
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Outport: '<Root>/Out1' */
  F_level = F_lev;
  return F_level;
}

/* Model initialize function */
void CellUnderVoltage_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(CellUnderVoltage_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&CellUnderVoltage_DW, 0,
                sizeof(DW_CellUnderVoltage_T));

  /* external inputs */
  CellUnderVoltage_U.g_CellLowestVol_g = 0.0F;

  /* SystemInitialize for Chart: '<Root>/Chart1' */
  CellUnderVoltage_DW.is_active_c1_CellUnderVoltage = 0U;
  CellUnderVoltage_DW.t1 = 0U;
  CellUnderVoltage_DW.t2 = 0U;
  CellUnderVoltage_DW.t3 = 0U;
  CellUnderVoltage_DW.t22 = 0U;
  CellUnderVoltage_DW.t33 = 0U;
  CellUnderVoltage_DW.t11 = 0U;
  CellUnderVoltage_DW.t4 = 0U;
  CellUnderVoltage_DW.F_1 = false;
  CellUnderVoltage_DW.F_2 = false;
  CellUnderVoltage_DW.F_3 = false;
  CellUnderVoltage_DW.F_4 = false;
}

/* Model terminate function */
void CellUnderVoltage_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
