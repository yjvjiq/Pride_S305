/*
 * File: SOF176Ah.c
 *
 * Code generated for Simulink model 'SOF176Ah'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 20 17:38:14 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SOF176Ah.h"
#include "SOF176Ah_private.h"

MdlrefDW_SOF176Ah_T SOF176Ah_MdlrefDW;

/* Output and update for referenced model: 'SOF176Ah' */
real32_T SOF176Ah_step(real32_T M176Ah_SOF_Soc, real32_T M176Ah_SOF_T)
{
  /* specified return value */
  real32_T M176Ah_SOF;

  /* Lookup_n-D: '<Root>/2-D Lookup Table1' */
  M176Ah_SOF = look2_iflf_linlcapw(M176Ah_SOF_Soc, M176Ah_SOF_T,
    rtCP_uDLookupTable1_bp01Data, rtCP_uDLookupTable1_bp02Data,
    rtCP_uDLookupTable1_tableData, rtCP_uDLookupTable1_maxIndex, 11U);
  return M176Ah_SOF;
}

/* Model initialize function */
void SOF176Ah_b_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_SOF176Ah_T *const SOF176Ah_M = &(SOF176Ah_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(SOF176Ah_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
