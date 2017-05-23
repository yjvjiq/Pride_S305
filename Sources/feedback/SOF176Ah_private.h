/*
 * File: SOF176Ah_private.h
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

#ifndef RTW_HEADER_SOF176Ah_private_h_
#define RTW_HEADER_SOF176Ah_private_h_
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

extern const real32_T rtCP_pooled_LDhncdChhYk9[132];
extern const real32_T rtCP_pooled_zMu0UDf9lQLD[11];
extern const real32_T rtCP_pooled_6PjX7Bg51ULI[12];
extern const uint32_T rtCP_pooled_8QW5W8jtrmAR[2];

#define rtCP_uDLookupTable1_tableData  rtCP_pooled_LDhncdChhYk9  /* Computed Parameter: uDLookupTable1_tableData
                                                                  * Referenced by: '<Root>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp01Data   rtCP_pooled_zMu0UDf9lQLD  /* Computed Parameter: uDLookupTable1_bp01Data
                                                                  * Referenced by: '<Root>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp02Data   rtCP_pooled_6PjX7Bg51ULI  /* Computed Parameter: uDLookupTable1_bp02Data
                                                                  * Referenced by: '<Root>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_maxIndex   rtCP_pooled_8QW5W8jtrmAR  /* Computed Parameter: uDLookupTable1_maxIndex
                                                                  * Referenced by: '<Root>/2-D Lookup Table1'
                                                                  */
#endif                                 /* RTW_HEADER_SOF176Ah_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
