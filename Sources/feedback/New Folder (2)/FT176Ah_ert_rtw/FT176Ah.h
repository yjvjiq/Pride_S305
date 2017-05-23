/*
 * File: FT176Ah.h
 *
 * Code generated for Simulink model 'FT176Ah'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 20 17:38:21 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FT176Ah_h_
#define RTW_HEADER_FT176Ah_h_
#include <stddef.h>
#include <string.h>
#ifndef FT176Ah_COMMON_INCLUDES_
# define FT176Ah_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FT176Ah_COMMON_INCLUDES_ */

#include "FT176Ah_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Child system includes */
#define SOF176Ah_MDLREF_HIDE_CHILD_
#include "SOF176Ah.h"
#define Feedback176Ah_MDLREF_HIDE_CHILD_
#include "Feedback176Ah.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T In3;                        /* '<Root>/In3' */
  real32_T In4;                        /* '<Root>/In4' */
  real32_T In5;                        /* '<Root>/In5' */
  real32_T In6;                        /* '<Root>/In6' */
} ExtU_FT176Ah_T;

/* Real-time Model Data Structure */
struct tag_RTM_FT176Ah_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with auto storage) */
extern ExtU_FT176Ah_T FT176Ah_U;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T out2;                  /* '<Root>/Model' */
extern real32_T out3;                  /* '<Root>/Model1' */

/* Model entry point functions */
extern void FT176Ah_initialize(void);
extern void FT176Ah_step(void);
extern void FT176Ah_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FT176Ah_T *const FT176Ah_M;

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
 * '<Root>' : 'FT176Ah'
 */
#endif                                 /* RTW_HEADER_FT176Ah_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
