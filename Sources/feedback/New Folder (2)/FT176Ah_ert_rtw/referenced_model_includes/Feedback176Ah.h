/*
 * File: Feedback176Ah.h
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

#ifndef RTW_HEADER_Feedback176Ah_h_
#define RTW_HEADER_Feedback176Ah_h_
#ifndef Feedback176Ah_COMMON_INCLUDES_
# define Feedback176Ah_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Feedback176Ah_COMMON_INCLUDES_ */

#include "Feedback176Ah_types.h"

/* Shared type includes */
#include "model_reference_types.h"
#include "look2_iflf_linlcapw.h"
#ifndef Feedback176Ah_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_Feedback176Ah_T {
  const char_T **errorStatus;
};

#endif                                 /*Feedback176Ah_MDLREF_HIDE_CHILD_*/

#ifndef Feedback176Ah_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_Feedback176Ah_T rtm;
} MdlrefDW_Feedback176Ah_T;

#endif                                 /*Feedback176Ah_MDLREF_HIDE_CHILD_*/

extern real32_T Feedback176Ah_step(real32_T M240Ah_FeedBack_Soc, real32_T
  M240Ah_FeedBack_T);

/* Model reference registration function */
extern void Feedback176Ah_k_initialize(const char_T **rt_errorStatus);

#ifndef Feedback176Ah_MDLREF_HIDE_CHILD_

extern MdlrefDW_Feedback176Ah_T Feedback176Ah_MdlrefDW;

#endif                                 /*Feedback176Ah_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Feedback176Ah'
 */
#endif                                 /* RTW_HEADER_Feedback176Ah_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
