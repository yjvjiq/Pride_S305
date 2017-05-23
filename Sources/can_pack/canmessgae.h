/*
 * File: canmessgaeV1_0.h
 *
 * Code generated for Simulink model 'canmessgaeV1_0'.
 *
 * Model version                  : 1.602
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Mar 07 13:58:03 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->S12x
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_canmessgaeV1_0_h_
#define RTW_HEADER_canmessgaeV1_0_h_
#include <stddef.h>
#include <string.h>
#ifndef canmessgaeV1_0_COMMON_INCLUDES_
# define canmessgaeV1_0_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "can_message.h"
#include "can_union.h"
#endif                                 /* canmessgaeV1_0_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_canmessgaeV1_0_T RT_MODEL_canmessgaeV1_0_T;

/* user code (top of export header file) */
#include "can_message.h"

/* Block signals (auto storage) */
typedef struct {
  real32_T Gain;                       /* '<S1>/Gain' */
  int8_T Subtract;                     /* '<S4>/Subtract' */
  int8_T Subtract1;                    /* '<S4>/Subtract1' */
} B_canmessgaeV1_0_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int_T CANPack81_ModeSignalID;        /* '<S28>/CAN Pack81' */
  int_T CANPack78_ModeSignalID;        /* '<S27>/CAN Pack78' */
  int_T CANPack77_ModeSignalID;        /* '<S26>/CAN Pack77' */
  int_T CANPack76_ModeSignalID;        /* '<S25>/CAN Pack76' */
  int_T CANPack75_ModeSignalID;        /* '<S24>/CAN Pack75' */
  int_T CANPack74_ModeSignalID;        /* '<S23>/CAN Pack74' */
  int_T CANPack73_ModeSignalID;        /* '<S22>/CAN Pack73' */
  int_T CANPack72_ModeSignalID;        /* '<S21>/CAN Pack72' */
  int_T CANPack71_ModeSignalID;        /* '<S20>/CAN Pack71' */
  int_T CANPack_ModeSignalID;          /* '<S19>/CAN Pack' */
  int_T CANPack80_ModeSignalID;        /* '<S18>/CAN Pack80' */
  int_T CANPack79_ModeSignalID;        /* '<S17>/CAN Pack79' */
  int_T CANPack70_ModeSignalID;        /* '<S16>/CAN Pack70' */
  int_T CANPack1_ModeSignalID;         /* '<S15>/CAN Pack1' */
  int_T CANPack69_ModeSignalID;        /* '<S14>/CAN Pack69' */
  int_T CANPack68_ModeSignalID;        /* '<S13>/CAN Pack68' */
  int_T CANPack67_ModeSignalID;        /* '<S12>/CAN Pack67' */
  int_T CANPack8_ModeSignalID;         /* '<S11>/CAN Pack8' */
  int_T CANPack7_ModeSignalID;         /* '<S10>/CAN Pack7' */
  int_T CANPack6_ModeSignalID;         /* '<S9>/CAN Pack6' */
  int_T CANPack5_ModeSignalID;         /* '<S8>/CAN Pack5' */
  int_T CANPack4_ModeSignalID;         /* '<S7>/CAN Pack4' */
  int_T CANPack3_ModeSignalID;         /* '<S6>/CAN Pack3' */
  int_T CANPack2_ModeSignalID;         /* '<S5>/CAN Pack2' */
  int_T CANPack1_ModeSignalID_h;       /* '<S4>/CAN Pack1' */
  int_T CANPack10_ModeSignalID;        /* '<S3>/CAN Pack10' */
  int_T CANPack9_ModeSignalID;         /* '<S2>/CAN Pack9' */
  int_T CANPack_ModeSignalID_m;        /* '<S1>/CAN Pack' */
} DW_canmessgaeV1_0_T;

/* Real-time Model Data Structure */
struct tag_RTM_canmessgaeV1_0_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern B_canmessgaeV1_0_T canmessgaeV1_0_B;

/* Block states (auto storage) */
extern DW_canmessgaeV1_0_T canmessgaeV1_0_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T g_SystemVoltageV0;     /* '<Root>/g_SystemVoltageV0' */
extern real32_T g_BatSysTotalCur;      /* '<Root>/g_BatSysTotalCur' */
extern real32_T g_SysSOC;              /* '<Root>/g_SysSOC' */
extern real32_T g_CellLowestVol;       /* '<Root>/g_CellLowestVol' */
extern real32_T g_CellHighestVol;      /* '<Root>/g_CellHighestVol' */
extern int8_T g_BatLowestTemp;         /* '<Root>/g_BatLowestTemp' */
extern int8_T g_BatHighestTemp;        /* '<Root>/g_BatHighestTemp' */
extern uint8_T s_life;                 /* '<Root>/s_life' */
extern uint8_T YearBCD;                /* '<Root>/YearBCD' */
extern uint8_T MonthBCD;               /* '<Root>/MonthBCD' */
extern uint8_T DayBCD;                 /* '<Root>/DayBCD' */
extern uint8_T HourBCD;                /* '<Root>/HourBCD' */
extern uint8_T MinuteBCD;              /* '<Root>/MinuteBCD' */
extern real32_T VersionNum;            /* '<Root>/VersionNum' */
extern real32_T g_MaxDischaCur;        /* '<Root>/g_MaxDischaCur' */
extern real32_T g_MaxChaCur;           /* '<Root>/g_MaxChaCur' */
extern real32_T MaxCtousChaCur;        /* '<Root>/MaxCtousChaCur' */
extern real32_T MaxChaTotalVol;        /* '<Root>/MaxChaTotalVol' */
extern real32_T MaxChaTotalVol1;       /* '<Root>/MaxChaTotalVol1' */
extern real32_T g_MaxFebCur;           /* '<Root>/g_MaxFebCur' */
extern real32_T HighestChaCellVol;     /* '<Root>/HighestChaCellVol' */
extern int8_T HighestChaCellTemp;      /* '<Root>/HighestChaCellTemp' */
extern real32_T LowestDischaTotalVol;  /* '<Root>/LowestDischaTotalVol' */
extern uint8_T ChaBeginHourBCD;        /* '<Root>/ChaBeginHourBCD' */
extern uint8_T ChaBeginMinuteBCD;      /* '<Root>/ChaBeginMinuteBCD' */
extern uint8_T ChaBeginSecondBCD;      /* '<Root>/ChaBeginSecondBCD' */
extern uint8_T ChaEndHourBCD;          /* '<Root>/ChaEndHourBCD' */
extern uint8_T ChaEndMinuteBCD;        /* '<Root>/ChaEndMinuteBCD' */
extern uint8_T ChaEndSecondBCD;        /* '<Root>/ChaEndSecondBCD' */
extern real32_T ActalChaVol;           /* '<Root>/ActalChaVol' */
extern uint8_T ChaInHourBCD;           /* '<Root>/ChaInHourBCD' */
extern uint8_T ChaInMinuteBCD;         /* '<Root>/ChaInMinuteBCD' */
extern uint8_T ChaInSecondBCD;         /* '<Root>/ChaInSecondBCD' */
extern uint8_T ChaOutHourBCD;          /* '<Root>/ChaOutHourBCD' */
extern uint8_T ChaOutMinuteBCD;        /* '<Root>/ChaOutMinuteBCD' */
extern uint8_T ChaOutSecondBCD;        /* '<Root>/ChaOutSecondBCD' */
extern real32_T ActalChaCur;           /* '<Root>/ActalChaCur' */
extern uint8_T Charge_3_Byte1;         /* '<Root>/Charge_3_Byte1' */
extern real32_T ChaPCtorBatVol;        /* '<Root>/ChaPCtorBatVol' */
extern real32_T ChaPCtorChgerVol;      /* '<Root>/ChaPCtorChgerVol' */
extern real32_T ChaNCtorBatVol;        /* '<Root>/ChaNCtorBatVol' */
extern real32_T ChaNCtorChgerVol;      /* '<Root>/ChaNCtorChgerVol' */
extern uint8_T g_CellHighestVolBoxNum; /* '<Root>/g_CellHighestVolBoxNum' */
extern uint8_T g_CellHighestVolBoxPosi;/* '<Root>/g_CellHighestVolBoxPosi' */
extern uint8_T g_CellLowestVolBoxNum;  /* '<Root>/g_CellLowestVolBoxNum' */
extern uint8_T g_CellLowestVolBoxPosi; /* '<Root>/g_CellLowestVolBoxPosi' */
extern uint8_T g_BatHighestTempBoxNum; /* '<Root>/g_BatHighestTempBoxNum' */
extern uint8_T g_BatHighestTempBoxPosi;/* '<Root>/g_BatHighestTempBoxPosi' */
extern uint8_T g_BatLowestTempBoxNum;  /* '<Root>/g_BatLowestTempBoxNum' */
extern uint8_T g_BatLowestTempBoxPosi; /* '<Root>/g_BatLowestTempBoxPosi' */
extern uint16_T BatFac;                /* '<Root>/BatFac' */
extern uint16_T BatArea;               /* '<Root>/BatArea' */
extern uint32_T BatPackInfo;           /* '<Root>/BatPackInfo' */
extern real32_T BatVolLowThold;        /* '<Root>/BatVolLowThold' */
extern real32_T BatVolHighThold;       /* '<Root>/BatVolHighThold' */
extern int8_T BatPackTempLowThold;     /* '<Root>/BatPackTempLowThold' */
extern int8_T BatPackTempHighThold;    /* '<Root>/BatPackTempHighThold' */
extern uint8_T BatBoxNum;              /* '<Root>/BatBoxNum' */
extern uint8_T BatFrameNum;            /* '<Root>/BatFrameNum' */
extern uint8_T BatTempNum;             /* '<Root>/BatTempNum' */
extern uint8_T BatFrameNum2;           /* '<Root>/BatFrameNum2' */
extern real32_T BatRatedVol;           /* '<Root>/BatRatedVol' */
extern real32_T BatRatedEnergy;        /* '<Root>/BatRatedEnergy' */
extern real32_T BatRemainEnergy;       /* '<Root>/BatRemainEnergy' */
extern uint8_T BoxCellNum1;            /* '<Root>/BoxCellNum1' */
extern uint8_T BoxCellNum2;            /* '<Root>/BoxCellNum2' */
extern uint8_T BoxCellNum3;            /* '<Root>/BoxCellNum3' */
extern uint8_T BoxCellNum4;            /* '<Root>/BoxCellNum4' */
extern uint8_T BoxCellNum5;            /* '<Root>/BoxCellNum5' */
extern uint8_T BoxCellNum6;            /* '<Root>/BoxCellNum6' */
extern uint8_T BoxCellNum7;            /* '<Root>/BoxCellNum7' */
extern uint8_T BoxCellNum8;            /* '<Root>/BoxCellNum8' */
extern uint8_T BoxCellNum9;            /* '<Root>/BoxCellNum9' */
extern uint8_T BoxCellNum10;           /* '<Root>/BoxCellNum10' */
extern uint8_T BoxCellNum11;           /* '<Root>/BoxCellNum11' */
extern uint8_T BoxTempNum1;            /* '<Root>/BoxTempNum1' */
extern uint8_T BoxTempNum2;            /* '<Root>/BoxTempNum2' */
extern uint8_T BoxTempNum3;            /* '<Root>/BoxTempNum3' */
extern uint8_T BoxTempNum4;            /* '<Root>/BoxTempNum4' */
extern uint8_T BoxTempNum5;            /* '<Root>/BoxTempNum5' */
extern uint8_T BoxTempNum6;            /* '<Root>/BoxTempNum6' */
extern uint8_T BoxTempNum7;            /* '<Root>/BoxTempNum7' */
extern uint8_T BoxTempNum8;            /* '<Root>/BoxTempNum8' */
extern uint8_T BoxTempNum9;            /* '<Root>/BoxTempNum9' */
extern uint8_T BoxTempNum10;           /* '<Root>/BoxTempNum10' */
extern uint8_T BoxTempNum11;           /* '<Root>/BoxTempNum11' */
extern real32_T BatRemainEnergy2;      /* '<Root>/BatRemainEnergy2' */
extern real32_T BatRatedEnergy2;       /* '<Root>/BatRatedEnergy2' */
extern uint16_T FacCode;               /* '<Root>/FacCode' */
extern uint8_T BatTypeCode;            /* '<Root>/BatTypeCode' */
extern uint8_T Year;                   /* '<Root>/Year' */
extern uint8_T Month;                  /* '<Root>/Month' */
extern uint8_T Day;                    /* '<Root>/Day' */
extern uint16_T SeralNum;              /* '<Root>/SeralNum' */
extern real32_T ChaCtorBndVol1;        /* '<Root>/ChaCtorBndVol1' */
extern real32_T ChaCtorBndVol2;        /* '<Root>/ChaCtorBndVol2' */
extern int8_T BatBoxHighestTemp1;      /* '<Root>/BatBoxHighestTemp1' */
extern int8_T BatBoxLowestTemp1;       /* '<Root>/BatBoxLowestTemp1' */
extern int8_T BatBoxHighestTemp2;      /* '<Root>/BatBoxHighestTemp2' */
extern int8_T BatBoxLowestTemp2;       /* '<Root>/BatBoxLowestTemp2' */
extern int8_T BatBoxHighestTemp3;      /* '<Root>/BatBoxHighestTemp3' */
extern int8_T BatBoxLowestTemp3;       /* '<Root>/BatBoxLowestTemp3' */
extern int8_T BatBoxHighestTemp4;      /* '<Root>/BatBoxHighestTemp4' */
extern int8_T BatBoxLowestTemp4;       /* '<Root>/BatBoxLowestTemp4' */
extern uint32_T InsulatedModel_Byte1_3;/* '<Root>/InsulatedModel_Byte1_3' */
extern uint32_T InsulatedModel_Byte4_6;/* '<Root>/InsulatedModel_Byte4_6' */
extern uint8_T InsulatedModel_Byte8;   /* '<Root>/InsulatedModel_Byte8' */
extern real32_T g_DCTemp1;             /* '<Root>/g_DCTemp1' */
extern real32_T g_DCTemp2;             /* '<Root>/g_DCTemp2' */
extern int8_T ChaSketHighVolPTemp2;    /* '<Root>/ChaSketHighVolPTemp2' */
extern int8_T ChaSketHighVolNTemp2;    /* '<Root>/ChaSketHighVolNTemp2' */
extern uint8_T g_BMSSelfCheckCounter;  /* '<Root>/g_BMSSelfCheckCounter' */
extern uint8_T stateCode;              /* '<Root>/stateCode' */
extern int8_T BatBoxHighestTemp5;      /* '<Root>/BatBoxHighestTemp5' */
extern int8_T BatBoxLowestTemp5;       /* '<Root>/BatBoxLowestTemp5' */
extern int8_T BatBoxHighestTemp6;      /* '<Root>/BatBoxHighestTemp6' */
extern int8_T BatBoxLowestTemp6;       /* '<Root>/BatBoxLowestTemp6' */
extern uint8_T ChaPCtorBatVol2;        /* '<Root>/ChaPCtorBatVol2' */
extern uint8_T ChaPCtorChgerVol2;      /* '<Root>/ChaPCtorChgerVol2' */
extern CAN_DATATYPE Model_InsulatedModel;/* '<S28>/CAN Pack81' */
extern CAN_DATATYPE Model_Information_9;/* '<S27>/CAN Pack78' */
extern CAN_DATATYPE Model_Information_8;/* '<S26>/CAN Pack77' */
extern CAN_DATATYPE Model_Information_7;/* '<S25>/CAN Pack76' */
extern CAN_DATATYPE Model_Information_6;/* '<S24>/CAN Pack75' */
extern CAN_DATATYPE Model_Information_5;/* '<S23>/CAN Pack74' */
extern CAN_DATATYPE Model_Information_4;/* '<S22>/CAN Pack73' */
extern CAN_DATATYPE Model_Information_3;/* '<S21>/CAN Pack72' */
extern CAN_DATATYPE Model_Information_2;/* '<S20>/CAN Pack71' */
extern CAN_DATATYPE Model_Information_12;/* '<S19>/CAN Pack' */
extern CAN_DATATYPE Model_Information_11;/* '<S18>/CAN Pack80' */
extern CAN_DATATYPE Model_Information_10;/* '<S17>/CAN Pack79' */
extern CAN_DATATYPE Model_Information_1;/* '<S16>/CAN Pack70' */
extern CAN_DATATYPE Model_EVCU;        /* '<S15>/CAN Pack1' */
extern CAN_DATATYPE Model_Charge_3;    /* '<S14>/CAN Pack69' */
extern CAN_DATATYPE Model_Charge_2;    /* '<S13>/CAN Pack68' */
extern CAN_DATATYPE Model_Charge_1;    /* '<S12>/CAN Pack67' */
extern CAN_DATATYPE Model_BMS9;        /* '<S11>/CAN Pack8' */
extern CAN_DATATYPE Model_BMS8;        /* '<S10>/CAN Pack7' */
extern CAN_DATATYPE Model_BMS7;        /* '<S9>/CAN Pack6' */
extern CAN_DATATYPE Model_BMS6;        /* '<S8>/CAN Pack5' */
extern CAN_DATATYPE Model_BMS5;        /* '<S7>/CAN Pack4' */
extern CAN_DATATYPE Model_BMS4;        /* '<S6>/CAN Pack3' */
extern CAN_DATATYPE Model_BMS3;        /* '<S5>/CAN Pack2' */
extern CAN_DATATYPE Model_BMS2;        /* '<S4>/CAN Pack1' */
extern CAN_DATATYPE Model_BMS11;       /* '<S3>/CAN Pack10' */
extern CAN_DATATYPE Model_BMS10;       /* '<S2>/CAN Pack9' */
extern CAN_DATATYPE Model_BMS1;        /* '<S1>/CAN Pack' */

/* Model entry point functions */
extern void canmessgaeV1_0_initialize(void);
extern void canmessgaeV1_0_step(void);
extern void canmessgaeV1_0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_canmessgaeV1_0_T *const canmessgaeV1_0_M;

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
 * '<Root>' : 'canmessgaeV1_0'
 * '<S1>'   : 'canmessgaeV1_0/S223_BMS1'
 * '<S2>'   : 'canmessgaeV1_0/S223_BMS10'
 * '<S3>'   : 'canmessgaeV1_0/S223_BMS11'
 * '<S4>'   : 'canmessgaeV1_0/S223_BMS2'
 * '<S5>'   : 'canmessgaeV1_0/S223_BMS3'
 * '<S6>'   : 'canmessgaeV1_0/S223_BMS4'
 * '<S7>'   : 'canmessgaeV1_0/S223_BMS5'
 * '<S8>'   : 'canmessgaeV1_0/S223_BMS6'
 * '<S9>'   : 'canmessgaeV1_0/S223_BMS7'
 * '<S10>'  : 'canmessgaeV1_0/S223_BMS8'
 * '<S11>'  : 'canmessgaeV1_0/S223_BMS9'
 * '<S12>'  : 'canmessgaeV1_0/S223_Charge_1'
 * '<S13>'  : 'canmessgaeV1_0/S223_Charge_2'
 * '<S14>'  : 'canmessgaeV1_0/S223_Charge_3'
 * '<S15>'  : 'canmessgaeV1_0/S223_EVCU'
 * '<S16>'  : 'canmessgaeV1_0/S223_Information_1'
 * '<S17>'  : 'canmessgaeV1_0/S223_Information_10'
 * '<S18>'  : 'canmessgaeV1_0/S223_Information_11'
 * '<S19>'  : 'canmessgaeV1_0/S223_Information_12'
 * '<S20>'  : 'canmessgaeV1_0/S223_Information_2'
 * '<S21>'  : 'canmessgaeV1_0/S223_Information_3'
 * '<S22>'  : 'canmessgaeV1_0/S223_Information_4'
 * '<S23>'  : 'canmessgaeV1_0/S223_Information_5'
 * '<S24>'  : 'canmessgaeV1_0/S223_Information_6'
 * '<S25>'  : 'canmessgaeV1_0/S223_Information_7'
 * '<S26>'  : 'canmessgaeV1_0/S223_Information_8'
 * '<S27>'  : 'canmessgaeV1_0/S223_Information_9'
 * '<S28>'  : 'canmessgaeV1_0/S223_InsulatedS223'
 */
#endif                                 /* RTW_HEADER_canmessgaeV1_0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
