/*
 * File: Feedback176Ah_private.h
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

#ifndef RTW_HEADER_Feedback176Ah_private_h_
#define RTW_HEADER_Feedback176Ah_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real32_T rtCP_pooled_lvcecqVD6Ee3[108];
extern const real32_T rtCP_pooled_u7d3j3eveKY6[12];
extern const real32_T rtCP_pooled_3FF1WxfdfOZH[9];
extern const uint32_T rtCP_pooled_ufE3qmHrSVcK[2];

#define rtCP_uDLookupTable2_tableData  rtCP_pooled_lvcecqVD6Ee3  /* Computed Parameter: uDLookupTable2_tableData
                                                                  * Referenced by: '<Root>/2-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable2_bp01Data   rtCP_pooled_u7d3j3eveKY6  /* Computed Parameter: uDLookupTable2_bp01Data
                                                                  * Referenced by: '<Root>/2-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable2_bp02Data   rtCP_pooled_3FF1WxfdfOZH  /* Computed Parameter: uDLookupTable2_bp02Data
                                                                  * Referenced by: '<Root>/2-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable2_maxIndex   rtCP_pooled_ufE3qmHrSVcK  /* Computed Parameter: uDLookupTable2_maxIndex
                                                                  * Referenced by: '<Root>/2-D Lookup Table2'
                                                                  */
#endif                                 /* RTW_HEADER_Feedback176Ah_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
