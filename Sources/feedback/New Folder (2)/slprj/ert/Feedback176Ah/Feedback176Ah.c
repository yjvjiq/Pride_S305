/*
 * File: Feedback176Ah.c
 *
 * Code generated for Simulink model 'Feedback176Ah'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 20 17:38:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Feedback176Ah.h"
#include "Feedback176Ah_private.h"

MdlrefDW_Feedback176Ah_T Feedback176Ah_MdlrefDW;

/* Output and update for referenced model: 'Feedback176Ah' */
real32_T Feedback176Ah_step(real32_T M240Ah_FeedBack_Soc, real32_T
  M240Ah_FeedBack_T)
{
  /* specified return value */
  real32_T M240Ah_FeedBack;

  /* Lookup_n-D: '<Root>/2-D Lookup Table2' */
  M240Ah_FeedBack = look2_iflf_linlcapw(M240Ah_FeedBack_Soc, M240Ah_FeedBack_T,
    rtCP_uDLookupTable2_bp01Data, rtCP_uDLookupTable2_bp02Data,
    rtCP_uDLookupTable2_tableData, rtCP_uDLookupTable2_maxIndex, 12U);
  return M240Ah_FeedBack;
}

/* Model initialize function */
void Feedback176Ah_k_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_Feedback176Ah_T *const Feedback176Ah_M = &(Feedback176Ah_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(Feedback176Ah_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
