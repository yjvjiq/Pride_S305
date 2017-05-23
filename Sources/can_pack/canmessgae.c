/*
 * File: canmessgaeV1_0.c
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

#include "canmessgae.h"

/* Exported block signals */
real32_T g_SystemVoltageV0;            /* '<Root>/g_SystemVoltageV0' */
real32_T g_BatSysTotalCur;             /* '<Root>/g_BatSysTotalCur' */
real32_T g_SysSOC;                     /* '<Root>/g_SysSOC' */
real32_T g_CellLowestVol;              /* '<Root>/g_CellLowestVol' */
real32_T g_CellHighestVol;             /* '<Root>/g_CellHighestVol' */
int8_T g_BatLowestTemp;                /* '<Root>/g_BatLowestTemp' */
int8_T g_BatHighestTemp;               /* '<Root>/g_BatHighestTemp' */
uint8_T s_life;                        /* '<Root>/s_life' */
uint8_T YearBCD;                       /* '<Root>/YearBCD' */
uint8_T MonthBCD;                      /* '<Root>/MonthBCD' */
uint8_T DayBCD;                        /* '<Root>/DayBCD' */
uint8_T HourBCD;                       /* '<Root>/HourBCD' */
uint8_T MinuteBCD;                     /* '<Root>/MinuteBCD' */
real32_T VersionNum;                   /* '<Root>/VersionNum' */
real32_T g_MaxDischaCur;               /* '<Root>/g_MaxDischaCur' */
real32_T g_MaxChaCur;                  /* '<Root>/g_MaxChaCur' */
real32_T MaxCtousChaCur;               /* '<Root>/MaxCtousChaCur' */
real32_T MaxChaTotalVol;               /* '<Root>/MaxChaTotalVol' */
real32_T MaxChaTotalVol1;              /* '<Root>/MaxChaTotalVol1' */
real32_T g_MaxFebCur;                  /* '<Root>/g_MaxFebCur' */
real32_T HighestChaCellVol;            /* '<Root>/HighestChaCellVol' */
int8_T HighestChaCellTemp;             /* '<Root>/HighestChaCellTemp' */
real32_T LowestDischaTotalVol;         /* '<Root>/LowestDischaTotalVol' */
uint8_T ChaBeginHourBCD;               /* '<Root>/ChaBeginHourBCD' */
uint8_T ChaBeginMinuteBCD;             /* '<Root>/ChaBeginMinuteBCD' */
uint8_T ChaBeginSecondBCD;             /* '<Root>/ChaBeginSecondBCD' */
uint8_T ChaEndHourBCD;                 /* '<Root>/ChaEndHourBCD' */
uint8_T ChaEndMinuteBCD;               /* '<Root>/ChaEndMinuteBCD' */
uint8_T ChaEndSecondBCD;               /* '<Root>/ChaEndSecondBCD' */
real32_T ActalChaVol;                  /* '<Root>/ActalChaVol' */
uint8_T ChaInHourBCD;                  /* '<Root>/ChaInHourBCD' */
uint8_T ChaInMinuteBCD;                /* '<Root>/ChaInMinuteBCD' */
uint8_T ChaInSecondBCD;                /* '<Root>/ChaInSecondBCD' */
uint8_T ChaOutHourBCD;                 /* '<Root>/ChaOutHourBCD' */
uint8_T ChaOutMinuteBCD;               /* '<Root>/ChaOutMinuteBCD' */
uint8_T ChaOutSecondBCD;               /* '<Root>/ChaOutSecondBCD' */
real32_T ActalChaCur;                  /* '<Root>/ActalChaCur' */
uint8_T Charge_3_Byte1;                /* '<Root>/Charge_3_Byte1' */
real32_T ChaPCtorBatVol;               /* '<Root>/ChaPCtorBatVol' */
real32_T ChaPCtorChgerVol;             /* '<Root>/ChaPCtorChgerVol' */
real32_T ChaNCtorBatVol;               /* '<Root>/ChaNCtorBatVol' */
real32_T ChaNCtorChgerVol;             /* '<Root>/ChaNCtorChgerVol' */
uint8_T g_CellHighestVolBoxNum;        /* '<Root>/g_CellHighestVolBoxNum' */
uint8_T g_CellHighestVolBoxPosi;       /* '<Root>/g_CellHighestVolBoxPosi' */
uint8_T g_CellLowestVolBoxNum;         /* '<Root>/g_CellLowestVolBoxNum' */
uint8_T g_CellLowestVolBoxPosi;        /* '<Root>/g_CellLowestVolBoxPosi' */
uint8_T g_BatHighestTempBoxNum;        /* '<Root>/g_BatHighestTempBoxNum' */
uint8_T g_BatHighestTempBoxPosi;       /* '<Root>/g_BatHighestTempBoxPosi' */
uint8_T g_BatLowestTempBoxNum;         /* '<Root>/g_BatLowestTempBoxNum' */
uint8_T g_BatLowestTempBoxPosi;        /* '<Root>/g_BatLowestTempBoxPosi' */
uint16_T BatFac;                       /* '<Root>/BatFac' */
uint16_T BatArea;                      /* '<Root>/BatArea' */
uint32_T BatPackInfo;                  /* '<Root>/BatPackInfo' */
real32_T BatVolLowThold;               /* '<Root>/BatVolLowThold' */
real32_T BatVolHighThold;              /* '<Root>/BatVolHighThold' */
int8_T BatPackTempLowThold;            /* '<Root>/BatPackTempLowThold' */
int8_T BatPackTempHighThold;           /* '<Root>/BatPackTempHighThold' */
uint8_T BatBoxNum;                     /* '<Root>/BatBoxNum' */
uint8_T BatFrameNum;                   /* '<Root>/BatFrameNum' */
uint8_T BatTempNum;                    /* '<Root>/BatTempNum' */
uint8_T BatFrameNum2;                  /* '<Root>/BatFrameNum2' */
real32_T BatRatedVol;                  /* '<Root>/BatRatedVol' */
real32_T BatRatedEnergy;               /* '<Root>/BatRatedEnergy' */
real32_T BatRemainEnergy;              /* '<Root>/BatRemainEnergy' */
uint8_T BoxCellNum1;                   /* '<Root>/BoxCellNum1' */
uint8_T BoxCellNum2;                   /* '<Root>/BoxCellNum2' */
uint8_T BoxCellNum3;                   /* '<Root>/BoxCellNum3' */
uint8_T BoxCellNum4;                   /* '<Root>/BoxCellNum4' */
uint8_T BoxCellNum5;                   /* '<Root>/BoxCellNum5' */
uint8_T BoxCellNum6;                   /* '<Root>/BoxCellNum6' */
uint8_T BoxCellNum7;                   /* '<Root>/BoxCellNum7' */
uint8_T BoxCellNum8;                   /* '<Root>/BoxCellNum8' */
uint8_T BoxCellNum9;                   /* '<Root>/BoxCellNum9' */
uint8_T BoxCellNum10;                  /* '<Root>/BoxCellNum10' */
uint8_T BoxCellNum11;                  /* '<Root>/BoxCellNum11' */
uint8_T BoxTempNum1;                   /* '<Root>/BoxTempNum1' */
uint8_T BoxTempNum2;                   /* '<Root>/BoxTempNum2' */
uint8_T BoxTempNum3;                   /* '<Root>/BoxTempNum3' */
uint8_T BoxTempNum4;                   /* '<Root>/BoxTempNum4' */
uint8_T BoxTempNum5;                   /* '<Root>/BoxTempNum5' */
uint8_T BoxTempNum6;                   /* '<Root>/BoxTempNum6' */
uint8_T BoxTempNum7;                   /* '<Root>/BoxTempNum7' */
uint8_T BoxTempNum8;                   /* '<Root>/BoxTempNum8' */
uint8_T BoxTempNum9;                   /* '<Root>/BoxTempNum9' */
uint8_T BoxTempNum10;                  /* '<Root>/BoxTempNum10' */
uint8_T BoxTempNum11;                  /* '<Root>/BoxTempNum11' */
real32_T BatRemainEnergy2;             /* '<Root>/BatRemainEnergy2' */
real32_T BatRatedEnergy2;              /* '<Root>/BatRatedEnergy2' */
uint16_T FacCode;                      /* '<Root>/FacCode' */
uint8_T BatTypeCode;                   /* '<Root>/BatTypeCode' */
uint8_T Year;                          /* '<Root>/Year' */
uint8_T Month;                         /* '<Root>/Month' */
uint8_T Day;                           /* '<Root>/Day' */
uint16_T SeralNum;                     /* '<Root>/SeralNum' */
real32_T ChaCtorBndVol1;               /* '<Root>/ChaCtorBndVol1' */
real32_T ChaCtorBndVol2;               /* '<Root>/ChaCtorBndVol2' */
int8_T BatBoxHighestTemp1;             /* '<Root>/BatBoxHighestTemp1' */
int8_T BatBoxLowestTemp1;              /* '<Root>/BatBoxLowestTemp1' */
int8_T BatBoxHighestTemp2;             /* '<Root>/BatBoxHighestTemp2' */
int8_T BatBoxLowestTemp2;              /* '<Root>/BatBoxLowestTemp2' */
int8_T BatBoxHighestTemp3;             /* '<Root>/BatBoxHighestTemp3' */
int8_T BatBoxLowestTemp3;              /* '<Root>/BatBoxLowestTemp3' */
int8_T BatBoxHighestTemp4;             /* '<Root>/BatBoxHighestTemp4' */
int8_T BatBoxLowestTemp4;              /* '<Root>/BatBoxLowestTemp4' */
uint32_T InsulatedModel_Byte1_3;       /* '<Root>/InsulatedModel_Byte1_3' */
uint32_T InsulatedModel_Byte4_6;       /* '<Root>/InsulatedModel_Byte4_6' */
uint8_T InsulatedModel_Byte8;          /* '<Root>/InsulatedModel_Byte8' */
real32_T g_DCTemp1;                    /* '<Root>/g_DCTemp1' */
real32_T g_DCTemp2;                    /* '<Root>/g_DCTemp2' */
int8_T ChaSketHighVolPTemp2;           /* '<Root>/ChaSketHighVolPTemp2' */
int8_T ChaSketHighVolNTemp2;           /* '<Root>/ChaSketHighVolNTemp2' */
uint8_T g_BMSSelfCheckCounter;         /* '<Root>/g_BMSSelfCheckCounter' */
uint8_T stateCode;                     /* '<Root>/stateCode' */
int8_T BatBoxHighestTemp5;             /* '<Root>/BatBoxHighestTemp5' */
int8_T BatBoxLowestTemp5;              /* '<Root>/BatBoxLowestTemp5' */
int8_T BatBoxHighestTemp6;             /* '<Root>/BatBoxHighestTemp6' */
int8_T BatBoxLowestTemp6;              /* '<Root>/BatBoxLowestTemp6' */
uint8_T ChaPCtorBatVol2;               /* '<Root>/ChaPCtorBatVol2' */
uint8_T ChaPCtorChgerVol2;             /* '<Root>/ChaPCtorChgerVol2' */
CAN_DATATYPE Model_InsulatedModel;     /* '<S28>/CAN Pack81' */
CAN_DATATYPE Model_Information_9;      /* '<S27>/CAN Pack78' */
CAN_DATATYPE Model_Information_8;      /* '<S26>/CAN Pack77' */
CAN_DATATYPE Model_Information_7;      /* '<S25>/CAN Pack76' */
CAN_DATATYPE Model_Information_6;      /* '<S24>/CAN Pack75' */
CAN_DATATYPE Model_Information_5;      /* '<S23>/CAN Pack74' */
CAN_DATATYPE Model_Information_4;      /* '<S22>/CAN Pack73' */
CAN_DATATYPE Model_Information_3;      /* '<S21>/CAN Pack72' */
CAN_DATATYPE Model_Information_2;      /* '<S20>/CAN Pack71' */
CAN_DATATYPE Model_Information_12;     /* '<S19>/CAN Pack' */
CAN_DATATYPE Model_Information_11;     /* '<S18>/CAN Pack80' */
CAN_DATATYPE Model_Information_10;     /* '<S17>/CAN Pack79' */
CAN_DATATYPE Model_Information_1;      /* '<S16>/CAN Pack70' */
CAN_DATATYPE Model_EVCU;               /* '<S15>/CAN Pack1' */
CAN_DATATYPE Model_Charge_3;           /* '<S14>/CAN Pack69' */
CAN_DATATYPE Model_Charge_2;           /* '<S13>/CAN Pack68' */
CAN_DATATYPE Model_Charge_1;           /* '<S12>/CAN Pack67' */
CAN_DATATYPE Model_BMS9;               /* '<S11>/CAN Pack8' */
CAN_DATATYPE Model_BMS8;               /* '<S10>/CAN Pack7' */
CAN_DATATYPE Model_BMS7;               /* '<S9>/CAN Pack6' */
CAN_DATATYPE Model_BMS6;               /* '<S8>/CAN Pack5' */
CAN_DATATYPE Model_BMS5;               /* '<S7>/CAN Pack4' */
CAN_DATATYPE Model_BMS4;               /* '<S6>/CAN Pack3' */
CAN_DATATYPE Model_BMS3;               /* '<S5>/CAN Pack2' */
CAN_DATATYPE Model_BMS2;               /* '<S4>/CAN Pack1' */
CAN_DATATYPE Model_BMS11;              /* '<S3>/CAN Pack10' */
CAN_DATATYPE Model_BMS10;              /* '<S2>/CAN Pack9' */
CAN_DATATYPE Model_BMS1;               /* '<S1>/CAN Pack' */

/* Block signals (auto storage) */
B_canmessgaeV1_0_T canmessgaeV1_0_B;

/* Block states (auto storage) */
DW_canmessgaeV1_0_T canmessgaeV1_0_DW;

/* Real-time model */
RT_MODEL_canmessgaeV1_0_T canmessgaeV1_0_M_;
RT_MODEL_canmessgaeV1_0_T *const canmessgaeV1_0_M = &canmessgaeV1_0_M_;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern void S223_BMS1(void);
extern void S223_BMS10(void);
extern void S223_BMS11(void);
extern void S223_BMS2(void);
extern void S223_BMS3(void);
extern void S223_BMS4(void);
extern void S223_BMS5(void);
extern void S223_BMS6(void);
extern void S223_BMS7(void);
extern void S223_BMS8(void);
extern void S223_BMS9(void);
extern void S223_Charge_1(void);
extern void S223_Charge_2(void);
extern void S223_Charge_3(void);
extern void S223_EVCU(void);
extern void S223_Information_1(void);
extern void S223_Information_10(void);
extern void S223_Information_11(void);
extern void S223_Information_12(void);
extern void S223_Information_2(void);
extern void S223_Information_3(void);
extern void S223_Information_4(void);
extern void S223_Information_5(void);
extern void S223_Information_6(void);
extern void S223_Information_7(void);
extern void S223_Information_8(void);
extern void S223_Information_9(void);
extern void S223_InsulatedS223(void);

/* Output and update for atomic system: '<Root>/S223_BMS1' */
void S223_BMS1(void)
{
  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/g_SysSOC'
   */
  canmessgaeV1_0_B.Gain = 100.0F * g_SysSOC;

  /* S-Function (scanpack): '<S1>/CAN Pack' */
  Model_BMS1.ID = 404279539U;
  Model_BMS1.Length = 8U;
  Model_BMS1.Extended = 1U;
  Model_BMS1.Remote = 0;
  Model_BMS1.Data[0] = 0;
  Model_BMS1.Data[1] = 0;
  Model_BMS1.Data[2] = 0;
  Model_BMS1.Data[3] = 0;
  Model_BMS1.Data[4] = 0;
  Model_BMS1.Data[5] = 0;
  Model_BMS1.Data[6] = 0;
  Model_BMS1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 56
     *  length                  = 6
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte7.Bit.F0_5_Rever;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(63)) {
              packedValue = (uint8_T) 63;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 40
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F0_CellOverVol;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 48
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte6.Bit.F0_TotalVolOverVol;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 41
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F1_CellUnderVol;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 49
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte6.Bit.F1_TotalVolUnderVol;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 50
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte6.Bit.F2_CellVolUnbal;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 42
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F2_SOCHigh;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 51
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte6.Bit.F3_CellTempUnbal;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 43
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F3_SOCLow;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 52
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte6.Bit.F4_6_BatFaultLevel;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }

              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  5);
              }

              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 44
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F4_ChaOverCur;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 11 ------------------
     *  startBit                = 45
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F5_DischaOverCur;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 12 ------------------
     *  startBit                = 62
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte7.Bit.F6_BatBalAtvState;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 13 ------------------
     *  startBit                = 46
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F6_BatTempHigh;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 14 ------------------
     *  startBit                = 47
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte5.Bit.F7_BatNotMatch;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[5] = Model_BMS1.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 15 ------------------
     *  startBit                = 63
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte7.Bit.F7_ChaAndDischaState;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[7] = Model_BMS1.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 16 ------------------
     *  startBit                = 55
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS1_Byte6.Bit.F7_Reser;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[6] = Model_BMS1.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 17 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -3200.0
     *  minimum                 = -3200.0
     *  maximum                 = 3353.5
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_BatSysTotalCur;

          /* full scaling operation */
          result = (result - -3200.0F) / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS1.Data[2] = Model_BMS1.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS1.Data[3] = Model_BMS1.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 18 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.4
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = canmessgaeV1_0_B.Gain;
          if (result > 100.0F) {
            /* upper saturation */
            result = 100.0F;
          }

          /* no offset to apply */
          result = result / 0.4F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS1.Data[4] = Model_BMS1.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 19 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_SystemVoltageV0;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS1.Data[0] = Model_BMS1.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS1.Data[1] = Model_BMS1.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS10' */
void S223_BMS10(void)
{
  /* S-Function (scanpack): '<S2>/CAN Pack9' */
  Model_BMS10.ID = 406900979U;
  Model_BMS10.Length = 8U;
  Model_BMS10.Extended = 1U;
  Model_BMS10.Remote = 0;
  Model_BMS10.Data[0] = 0;
  Model_BMS10.Data[1] = 0;
  Model_BMS10.Data[2] = 0;
  Model_BMS10.Data[3] = 0;
  Model_BMS10.Data[4] = 0;
  Model_BMS10.Data[5] = 0;
  Model_BMS10.Data[6] = 0;
  Model_BMS10.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (ChaSketHighVolNTemp2);

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS10.Data[3] = Model_BMS10.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (ChaSketHighVolPTemp2);

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS10.Data[2] = Model_BMS10.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 215.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_DCTemp1;

          /* no factor to apply */
          result = result - -40.0F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS10.Data[0] = Model_BMS10.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 215.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_DCTemp2;

          /* no factor to apply */
          result = result - -40.0F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS10.Data[1] = Model_BMS10.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS11' */
void S223_BMS11(void)
{
  /* S-Function (scanpack): '<S3>/CAN Pack10' */
  Model_BMS11.ID = 418522355U;
  Model_BMS11.Length = 8U;
  Model_BMS11.Extended = 1U;
  Model_BMS11.Remote = 0;
  Model_BMS11.Data[0] = 0;
  Model_BMS11.Data[1] = 0;
  Model_BMS11.Data[2] = 0;
  Model_BMS11.Data[3] = 0;
  Model_BMS11.Data[4] = 0;
  Model_BMS11.Data[5] = 0;
  Model_BMS11.Data[6] = 0;
  Model_BMS11.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (DayBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS11.Data[2] = Model_BMS11.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (HourBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS11.Data[3] = Model_BMS11.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (MinuteBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS11.Data[4] = Model_BMS11.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (MonthBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS11.Data[1] = Model_BMS11.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 10.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = VersionNum;
          if (result > 10.0F) {
            /* upper saturation */
            result = 10.0F;
          }

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS11.Data[6] = Model_BMS11.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS11.Data[7] = Model_BMS11.Data[7] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (YearBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS11.Data[0] = Model_BMS11.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS2' */
void S223_BMS2(void)
{
  /* Sum: '<S4>/Subtract' incorporates:
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/g_BatHighestTemp'
   */
  canmessgaeV1_0_B.Subtract = (int8_T)(g_BatHighestTemp - 40);

  /* Sum: '<S4>/Subtract1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/g_BatLowestTemp'
   */
  canmessgaeV1_0_B.Subtract1 = (int8_T)(g_BatLowestTemp - 40);

  /* S-Function (scanpack): '<S4>/CAN Pack1' */
  Model_BMS2.ID = 404345075U;
  Model_BMS2.Length = 8U;
  Model_BMS2.Extended = 1U;
  Model_BMS2.Remote = 0;
  Model_BMS2.Data[0] = 0;
  Model_BMS2.Data[1] = 0;
  Model_BMS2.Data[2] = 0;
  Model_BMS2.Data[3] = 0;
  Model_BMS2.Data[4] = 0;
  Model_BMS2.Data[5] = 0;
  Model_BMS2.Data[6] = 0;
  Model_BMS2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 28
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS2_Byte3.Bit.F4_7_CellHighestVolNum;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(15)) {
              packedValue = (uint8_T) 15;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }

              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  5);
              }

              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  6);
              }

              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 12
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS2_Byte1.Bit.F4_7_CellLowestVolNum;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(15)) {
              packedValue = (uint8_T) 15;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }

              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  5);
              }

              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  6);
              }

              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (canmessgaeV1_0_B.Subtract);

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS2.Data[5] = Model_BMS2.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (canmessgaeV1_0_B.Subtract1);

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS2.Data[4] = Model_BMS2.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 16
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 40.95
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_CellHighestVol;

          /* no offset to apply */
          result = result / 0.01F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(4095)) {
              packedValue = (uint16_T) 4095;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS2.Data[2] = Model_BMS2.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS2.Data[3] = Model_BMS2.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 0
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 40.95
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_CellLowestVol;

          /* no offset to apply */
          result = result / 0.01F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(4095)) {
              packedValue = (uint16_T) 4095;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS2.Data[0] = Model_BMS2.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS2.Data[1] = Model_BMS2.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (s_life);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS2.Data[7] = Model_BMS2.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS3' */
void S223_BMS3(void)
{
  /* S-Function (scanpack): '<S5>/CAN Pack2' */
  Model_BMS3.ID = 404410611U;
  Model_BMS3.Length = 8U;
  Model_BMS3.Extended = 1U;
  Model_BMS3.Remote = 0;
  Model_BMS3.Data[0] = 0;
  Model_BMS3.Data[1] = 0;
  Model_BMS3.Data[2] = 0;
  Model_BMS3.Data[3] = 0;
  Model_BMS3.Data[4] = 0;
  Model_BMS3.Data[5] = 0;
  Model_BMS3.Data[6] = 0;
  Model_BMS3.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 3.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 765.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = MaxChaTotalVol;

          /* no offset to apply */
          result = result / 3.0F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS3.Data[6] = Model_BMS3.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -3200.0
     *  minimum                 = -3200.0
     *  maximum                 = 3353.5
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = MaxCtousChaCur;

          /* full scaling operation */
          result = (result - -3200.0F) / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS3.Data[4] = Model_BMS3.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS3.Data[5] = Model_BMS3.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -3200.0
     *  minimum                 = -3200.0
     *  maximum                 = 3353.5
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_MaxChaCur;

          /* full scaling operation */
          result = (result - -3200.0F) / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS3.Data[2] = Model_BMS3.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS3.Data[3] = Model_BMS3.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -3200.0
     *  minimum                 = -3200.0
     *  maximum                 = 3353.5
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_MaxDischaCur;

          /* full scaling operation */
          result = (result - -3200.0F) / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS3.Data[0] = Model_BMS3.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS3.Data[1] = Model_BMS3.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS4' */
void S223_BMS4(void)
{
  /* S-Function (scanpack): '<S6>/CAN Pack3' */
  Model_BMS4.ID = 404476147U;
  Model_BMS4.Length = 8U;
  Model_BMS4.Extended = 1U;
  Model_BMS4.Remote = 0;
  Model_BMS4.Data[0] = 0;
  Model_BMS4.Data[1] = 0;
  Model_BMS4.Data[2] = 0;
  Model_BMS4.Data[3] = 0;
  Model_BMS4.Data[4] = 0;
  Model_BMS4.Data[5] = 0;
  Model_BMS4.Data[6] = 0;
  Model_BMS4.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 52
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS4_Byte6.Bit.F4_7_CellHighestChaVolNum;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(15)) {
              packedValue = (uint8_T) 15;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }

              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  5);
              }

              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  6);
              }

              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (HighestChaCellTemp);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS4.Data[7] = Model_BMS4.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 40
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 40.95
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = HighestChaCellVol;

          /* no offset to apply */
          result = result / 0.01F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(4095)) {
              packedValue = (uint16_T) 4095;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS4.Data[5] = Model_BMS4.Data[5] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS4.Data[6] = Model_BMS4.Data[6] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 8
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 6553.5
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = MaxChaTotalVol1;

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS4.Data[1] = Model_BMS4.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS4.Data[2] = Model_BMS4.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 24
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -3200.0
     *  minimum                 = -3200.0
     *  maximum                 = 3200.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = g_MaxFebCur;
          if (result > 3200.0F) {
            /* upper saturation */
            result = 3200.0F;
          }

          /* full scaling operation */
          result = (result - -3200.0F) / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS4.Data[3] = Model_BMS4.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS4.Data[4] = Model_BMS4.Data[4] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS5' */
void S223_BMS5(void)
{
  /* S-Function (scanpack): '<S7>/CAN Pack4' */
  Model_BMS5.ID = 404541683U;
  Model_BMS5.Length = 6U;
  Model_BMS5.Extended = 1U;
  Model_BMS5.Remote = 0;
  Model_BMS5.Data[0] = 0;
  Model_BMS5.Data[1] = 0;
  Model_BMS5.Data[2] = 0;
  Model_BMS5.Data[3] = 0;
  Model_BMS5.Data[4] = 0;
  Model_BMS5.Data[5] = 0;
  Model_BMS5.Data[6] = 0;
  Model_BMS5.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 32
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte4.Bit.F0_3_Rever;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(15)) {
              packedValue = (uint8_T) 15;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F0_ConFault1;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 40
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F0_ConFault17;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 24
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F0_ConFault9;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 25
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F1_ConFault10;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 41
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F1_ConFault18;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 17
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F1_ConFault2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 26
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F2_ConFault11;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 42
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F2_ConFault19;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 18
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F2_ConFault3;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 27
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F3_ConFault12;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 11 ------------------
     *  startBit                = 43
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F3_ConFault20;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 12 ------------------
     *  startBit                = 19
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F3_ConFault4;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 13 ------------------
     *  startBit                = 28
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F4_ConFault13;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 14 ------------------
     *  startBit                = 44
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F4_ConFault21;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 15 ------------------
     *  startBit                = 20
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F4_ConFault5;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 16 ------------------
     *  startBit                = 36
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte4.Bit.F4_CutMainCtor;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 17 ------------------
     *  startBit                = 29
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F5_ConFault14;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 18 ------------------
     *  startBit                = 45
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F5_ConFault22;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 19 ------------------
     *  startBit                = 21
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F5_ConFault6;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 20 ------------------
     *  startBit                = 37
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte4.Bit.F5_ForceStopMode;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 21 ------------------
     *  startBit                = 30
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F6_ConFault15;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 22 ------------------
     *  startBit                = 46
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F6_ConFault23;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 23 ------------------
     *  startBit                = 22
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F6_ConFault7;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 24 ------------------
     *  startBit                = 38
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte4.Bit.F6_ForceDownPowerMode;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 25 ------------------
     *  startBit                = 39
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte4.Bit.F7_ChaPlugCon;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[4] = Model_BMS5.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 26 ------------------
     *  startBit                = 31
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte3.Bit.F7_ConFault16;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[3] = Model_BMS5.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 27 ------------------
     *  startBit                = 47
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte5.Bit.F7_ConFault24;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[5] = Model_BMS5.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 28 ------------------
     *  startBit                = 23
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS5_Byte2.Bit.F7_ConFault8;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[2] = Model_BMS5.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 29 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = LowestDischaTotalVol;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS5.Data[0] = Model_BMS5.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS5.Data[1] = Model_BMS5.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS6' */
void S223_BMS6(void)
{
  /* S-Function (scanpack): '<S8>/CAN Pack5' */
  Model_BMS6.ID = 404607219U;
  Model_BMS6.Length = 8U;
  Model_BMS6.Extended = 1U;
  Model_BMS6.Remote = 0;
  Model_BMS6.Data[0] = 0;
  Model_BMS6.Data[1] = 0;
  Model_BMS6.Data[2] = 0;
  Model_BMS6.Data[3] = 0;
  Model_BMS6.Data[4] = 0;
  Model_BMS6.Data[5] = 0;
  Model_BMS6.Data[6] = 0;
  Model_BMS6.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 24
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F0_BoxHeatingState1;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F0_BoxHeatingState13;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 40
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F0_BoxHeatingState17;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 32
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F0_BoxHeatingState21;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 16
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F0_BoxHeatingState5;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 8
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F0_BoxHeatingState9;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 25
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F1_BoxCoolingState1;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 1
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F1_BoxCoolingState13;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 41
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F1_BoxCoolingState17;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 33
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F1_BoxCoolingState21;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 17
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F1_BoxCoolingState5;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 11 ------------------
     *  startBit                = 9
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F1_BoxCoolingState9;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 12 ------------------
     *  startBit                = 10
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F2_BoxHeatingState10;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 13 ------------------
     *  startBit                = 2
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F2_BoxHeatingState14;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 14 ------------------
     *  startBit                = 42
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F2_BoxHeatingState18;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 15 ------------------
     *  startBit                = 26
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F2_BoxHeatingState2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 16 ------------------
     *  startBit                = 34
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F2_BoxHeatingState22;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 17 ------------------
     *  startBit                = 18
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F2_BoxHeatingState6;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 18 ------------------
     *  startBit                = 11
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F3_BoxCoolingState10;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 19 ------------------
     *  startBit                = 3
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F3_BoxCoolingState14;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 20 ------------------
     *  startBit                = 43
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F3_BoxCoolingState18;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 21 ------------------
     *  startBit                = 27
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F3_BoxCoolingState2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 22 ------------------
     *  startBit                = 35
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F3_BoxCoolingState22;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 23 ------------------
     *  startBit                = 19
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F3_BoxCoolingState6;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 24 ------------------
     *  startBit                = 12
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F4_BoxHeatingState11;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 25 ------------------
     *  startBit                = 4
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F4_BoxHeatingState15;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 26 ------------------
     *  startBit                = 44
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F4_BoxHeatingState19;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 27 ------------------
     *  startBit                = 36
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F4_BoxHeatingState23;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 28 ------------------
     *  startBit                = 28
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F4_BoxHeatingState3;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 29 ------------------
     *  startBit                = 20
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F4_BoxHeatingState7;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 30 ------------------
     *  startBit                = 13
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F5_BoxCoolingState11;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 31 ------------------
     *  startBit                = 5
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F5_BoxCoolingState15;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 32 ------------------
     *  startBit                = 45
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F5_BoxCoolingState19;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 33 ------------------
     *  startBit                = 37
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F5_BoxCoolingState23;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 34 ------------------
     *  startBit                = 29
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F5_BoxCoolingState3;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 35 ------------------
     *  startBit                = 21
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F5_BoxCoolingState7;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 36 ------------------
     *  startBit                = 14
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F6_BoxHeatingState12;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 37 ------------------
     *  startBit                = 6
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F6_BoxHeatingState16;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 38 ------------------
     *  startBit                = 46
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F6_BoxHeatingState20;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 39 ------------------
     *  startBit                = 38
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F6_BoxHeatingState24;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 40 ------------------
     *  startBit                = 30
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F6_BoxHeatingState4;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 41 ------------------
     *  startBit                = 22
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F6_BoxHeatingState8;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 42 ------------------
     *  startBit                = 15
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte1.Bit.F7_BoxCoolingState12;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[1] = Model_BMS6.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 43 ------------------
     *  startBit                = 7
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte0.Bit.F7_BoxCoolingState16;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[0] = Model_BMS6.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 44 ------------------
     *  startBit                = 47
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte5.Bit.F7_BoxCoolingState20;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[5] = Model_BMS6.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 45 ------------------
     *  startBit                = 39
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte4.Bit.F7_BoxCoolingState24;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[4] = Model_BMS6.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 46 ------------------
     *  startBit                = 31
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte3.Bit.F7_BoxCoolingState4;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[3] = Model_BMS6.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 47 ------------------
     *  startBit                = 23
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS6_Byte2.Bit.F7_BoxCoolingState8;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS6.Data[2] = Model_BMS6.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 48 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_BMSSelfCheckCounter);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS6.Data[6] = Model_BMS6.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 49 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (stateCode);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS6.Data[7] = Model_BMS6.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS7' */
void S223_BMS7(void)
{
  /* S-Function (scanpack): '<S9>/CAN Pack6' */
  Model_BMS7.ID = 418518259U;
  Model_BMS7.Length = 8U;
  Model_BMS7.Extended = 1U;
  Model_BMS7.Remote = 0;
  Model_BMS7.Data[0] = 0;
  Model_BMS7.Data[1] = 0;
  Model_BMS7.Data[2] = 0;
  Model_BMS7.Data[3] = 0;
  Model_BMS7.Data[4] = 0;
  Model_BMS7.Data[5] = 0;
  Model_BMS7.Data[6] = 0;
  Model_BMS7.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 8
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte1.Bit.F0_1_Rever;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 24
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte3.Bit.F0_1_Rever2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte4.Bit.F0_1_Rever3;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 40
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte5.Bit.F0_2_Rever2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
     *  length                  = 6
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte6.Bit.F0_5_Rever2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(63)) {
              packedValue = (uint8_T) 63;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 56
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte7.Bit.F0_BatState;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 16
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte2.Bit.F0_TempSenFault;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 0
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte0.Bit.F0_WithLECUComAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 57
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte7.Bit.F1_2_BatHeatingFault;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }

              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 17
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte2.Bit.F1_CurSenFault;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 1
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte0.Bit.F1_WithChgerComAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 11 ------------------
     *  startBit                = 34
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte4.Bit.F2_4_BatTempLowAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }

              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  3);
              }

              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 12 ------------------
     *  startBit                = 26
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte3.Bit.F2_4_CellTempUnbalAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }

              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  3);
              }

              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 13 ------------------
     *  startBit                = 18
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte2.Bit.F2_4_CellUnderVolAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }

              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  3);
              }

              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 14 ------------------
     *  startBit                = 10
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte1.Bit.F2_4_ChaOverCurAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }

              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  3);
              }

              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 15 ------------------
     *  startBit                = 2
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte0.Bit.F2_4_TotalVolUnderVolAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }

              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  3);
              }

              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 16 ------------------
     *  startBit                = 43
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte5.Bit.F3_4_SOCSal;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }

              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 17 ------------------
     *  startBit                = 59
     *  length                  = 5
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte7.Bit.F3_7_Rever;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(31)) {
              packedValue = (uint8_T) 31;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }

              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  4);
              }

              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  5);
              }

              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  6);
              }

              {
                Model_BMS7.Data[7] = Model_BMS7.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 18 ------------------
     *  startBit                = 37
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte4.Bit.F5_7_BatTempHighAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_BMS7.Data[4] = Model_BMS7.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 19 ------------------
     *  startBit                = 21
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte2.Bit.F5_7_CellOverVolAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_BMS7.Data[2] = Model_BMS7.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 20 ------------------
     *  startBit                = 29
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte3.Bit.F5_7_CellVolUnbalAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_BMS7.Data[3] = Model_BMS7.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 21 ------------------
     *  startBit                = 13
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte1.Bit.F5_7_DisChaOverCurAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_BMS7.Data[1] = Model_BMS7.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 22 ------------------
     *  startBit                = 45
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte5.Bit.F5_7_SOCLowAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_BMS7.Data[5] = Model_BMS7.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 23 ------------------
     *  startBit                = 5
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte0.Bit.F5_7_TotalVolOverVolAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_BMS7.Data[0] = Model_BMS7.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 24 ------------------
     *  startBit                = 54
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS7_Byte6.Bit.F6_7_HighVolLock;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }

              {
                Model_BMS7.Data[6] = Model_BMS7.Data[6] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS8' */
void S223_BMS8(void)
{
  /* S-Function (scanpack): '<S10>/CAN Pack7' */
  Model_BMS8.ID = 405852403U;
  Model_BMS8.Length = 6U;
  Model_BMS8.Extended = 1U;
  Model_BMS8.Remote = 0;
  Model_BMS8.Data[0] = 0;
  Model_BMS8.Data[1] = 0;
  Model_BMS8.Data[2] = 0;
  Model_BMS8.Data[3] = 0;
  Model_BMS8.Data[4] = 0;
  Model_BMS8.Data[5] = 0;
  Model_BMS8.Data[6] = 0;
  Model_BMS8.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 4.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ChaNCtorBatVol;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 4.0F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS8.Data[4] = Model_BMS8.Data[4] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 4.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ChaNCtorChgerVol;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 4.0F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS8.Data[5] = Model_BMS8.Data[5] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 4.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ChaPCtorBatVol;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 4.0F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS8.Data[2] = Model_BMS8.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 4.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ChaPCtorChgerVol;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 4.0F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_BMS8.Data[3] = Model_BMS8.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 0
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS8_Byte0.Bit.F0_1_Rever4;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 8
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS8_Byte1.Bit.F0_2_ChaNCtorStateFeb2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 2
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS8_Byte0.Bit.F2_3_BMSInterCtorState;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }

              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 11
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS8_Byte1.Bit.F3_5_ChaNCtorStateFeb1;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }

              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  4);
              }

              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 4
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS8_Byte0.Bit.F4_5_BatPCtorStateFeb;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }

              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 6
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }

              {
                Model_BMS8.Data[0] = Model_BMS8.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 14
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS8_Byte1.Bit.F6_7_ChaPCtorClose;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }

              {
                Model_BMS8.Data[1] = Model_BMS8.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_BMS9' */
void S223_BMS9(void)
{
  /* S-Function (scanpack): '<S11>/CAN Pack8' */
  Model_BMS9.ID = 404672755U;
  Model_BMS9.Length = 8U;
  Model_BMS9.Extended = 1U;
  Model_BMS9.Remote = 0;
  Model_BMS9.Data[0] = 0;
  Model_BMS9.Data[1] = 0;
  Model_BMS9.Data[2] = 0;
  Model_BMS9.Data[3] = 0;
  Model_BMS9.Data[4] = 0;
  Model_BMS9.Data[5] = 0;
  Model_BMS9.Data[6] = 0;
  Model_BMS9.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ChaCtorBndVol1;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS9.Data[0] = Model_BMS9.Data[0] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS9.Data[1] = Model_BMS9.Data[1] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ChaCtorBndVol2;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 0)) >>
                   0)<<0);
              }

              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 1)) >>
                   1)<<1);
              }

              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 2)) >>
                   2)<<2);
              }

              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 3)) >>
                   3)<<3);
              }

              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 4)) >>
                   4)<<4);
              }

              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 5)) >>
                   5)<<5);
              }

              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 6)) >>
                   6)<<6);
              }

              {
                Model_BMS9.Data[2] = Model_BMS9.Data[2] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 7)) >>
                   7)<<7);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 8)) >>
                   8)<<0);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 9)) >>
                   9)<<1);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 10)) >>
                   10)<<2);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 11)) >>
                   11)<<3);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 12)) >>
                   12)<<4);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 13)) >>
                   13)<<5);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 14)) >>
                   14)<<6);
              }

              {
                Model_BMS9.Data[3] = Model_BMS9.Data[3] | (uint8_T)((uint8_T)
                  ((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1)) << 15)) >>
                   15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 56
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS9_Byte7.Bit.F0_ChaCtorAdin1;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 57
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS9_Byte7.Bit.F1_ChaCtorAdin2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 58
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS9_Byte7.Bit.F2_BatChaOverTemp;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 59
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS9_Byte7.Bit.F3_BatChaOverVol;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 60
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS9_Byte7.Bit.F4_BzerAlarm;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 61
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = BMS9_Byte7.Bit.F5_7_Rever;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_BMS9.Data[7] = Model_BMS9.Data[7] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Charge_1' */
void S223_Charge_1(void)
{
  /* S-Function (scanpack): '<S12>/CAN Pack67' */
  Model_Charge_1.ID = 419385588U;
  Model_Charge_1.Length = 8U;
  Model_Charge_1.Extended = 1U;
  Model_Charge_1.Remote = 0;
  Model_Charge_1.Data[0] = 0;
  Model_Charge_1.Data[1] = 0;
  Model_Charge_1.Data[2] = 0;
  Model_Charge_1.Data[3] = 0;
  Model_Charge_1.Data[4] = 0;
  Model_Charge_1.Data[5] = 0;
  Model_Charge_1.Data[6] = 0;
  Model_Charge_1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ActalChaVol;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Model_Charge_1.Data[6] = Model_Charge_1.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Model_Charge_1.Data[7] = Model_Charge_1.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaBeginHourBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_1.Data[0] = Model_Charge_1.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaBeginMinuteBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_1.Data[1] = Model_Charge_1.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaBeginSecondBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_1.Data[2] = Model_Charge_1.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaEndHourBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_1.Data[3] = Model_Charge_1.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaEndMinuteBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_1.Data[4] = Model_Charge_1.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaEndSecondBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_1.Data[5] = Model_Charge_1.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Charge_2' */
void S223_Charge_2(void)
{
  /* S-Function (scanpack): '<S13>/CAN Pack68' */
  Model_Charge_2.ID = 419385844U;
  Model_Charge_2.Length = 8U;
  Model_Charge_2.Extended = 1U;
  Model_Charge_2.Remote = 0;
  Model_Charge_2.Data[0] = 0;
  Model_Charge_2.Data[1] = 0;
  Model_Charge_2.Data[2] = 0;
  Model_Charge_2.Data[3] = 0;
  Model_Charge_2.Data[4] = 0;
  Model_Charge_2.Data[5] = 0;
  Model_Charge_2.Data[6] = 0;
  Model_Charge_2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -3200.0
     *  minimum                 = -3200.0
     *  maximum                 = 3353.5
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = ActalChaCur;

          /* full scaling operation */
          result = (result - -3200.0F) / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Model_Charge_2.Data[6] = Model_Charge_2.Data[6] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Model_Charge_2.Data[7] = Model_Charge_2.Data[7] | (uint8_T)
                  ((uint8_T)((uint16_T)(packedValue & (uint16_T)(((uint16_T)(1))
                      << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaInHourBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_2.Data[0] = Model_Charge_2.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaInMinuteBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_2.Data[1] = Model_Charge_2.Data[1] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaInSecondBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_2.Data[2] = Model_Charge_2.Data[2] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaOutHourBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_2.Data[3] = Model_Charge_2.Data[3] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaOutMinuteBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_2.Data[4] = Model_Charge_2.Data[4] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaOutSecondBCD);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_2.Data[5] = Model_Charge_2.Data[5] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Charge_3' */
void S223_Charge_3(void)
{
  /* S-Function (scanpack): '<S14>/CAN Pack69' */
  Model_Charge_3.ID = 419427060U;
  Model_Charge_3.Length = 1U;
  Model_Charge_3.Extended = 1U;
  Model_Charge_3.Remote = 0;
  Model_Charge_3.Data[0] = 0;
  Model_Charge_3.Data[1] = 0;
  Model_Charge_3.Data[2] = 0;
  Model_Charge_3.Data[3] = 0;
  Model_Charge_3.Data[4] = 0;
  Model_Charge_3.Data[5] = 0;
  Model_Charge_3.Data[6] = 0;
  Model_Charge_3.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (Charge_3_Byte1);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }

              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      1)) >> 1)<<1);
              }

              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      2)) >> 2)<<2);
              }

              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      3)) >> 3)<<3);
              }

              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      4)) >> 4)<<4);
              }

              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      5)) >> 5)<<5);
              }

              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      6)) >> 6)<<6);
              }

              {
                Model_Charge_3.Data[0] = Model_Charge_3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_EVCU' */
void S223_EVCU(void)
{
  /* S-Function (scanpack): '<S15>/CAN Pack1' */
  Model_EVCU.ID = 405861328U;
  Model_EVCU.Length = 8U;
  Model_EVCU.Extended = 1U;
  Model_EVCU.Remote = 0;
  Model_EVCU.Data[0] = 0;
  Model_EVCU.Data[1] = 0;
  Model_EVCU.Data[2] = 0;
  Model_EVCU.Data[3] = 0;
  Model_EVCU.Data[4] = 0;
  Model_EVCU.Data[5] = 0;
  Model_EVCU.Data[6] = 0;
  Model_EVCU.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 4.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 255.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaPCtorBatVol2);
          if (result > (uint32_T) (255U) ) {
            /* upper saturation */
            result = (uint32_T) (255U);
          }

          /* no offset to apply */
          result = (uint32_T) (result / 4U);
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_EVCU.Data[2] = Model_EVCU.Data[2] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 4.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 255.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (ChaPCtorChgerVol2);
          if (result > (uint32_T) (255U) ) {
            /* upper saturation */
            result = (uint32_T) (255U);
          }

          /* no offset to apply */
          result = (uint32_T) (result / 4U);
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                Model_EVCU.Data[3] = Model_EVCU.Data[3] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 8
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = EVCU_Byte1.Bit.F0_1_Rever5;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 0
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = EVCU_Byte0.Bit.F0_3_Rever2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(15)) {
              packedValue = (uint8_T) 15;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 10
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = EVCU_Byte1.Bit.F2_4_ChaPCtorStateFeb2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  2);
              }

              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  3);
              }

              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  4);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 4
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = EVCU_Byte0.Bit.F4_5_BatPCtorCtrl;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  4);
              }

              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  5);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 13
     *  length                  = 3
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(7)) {
              packedValue = (uint8_T) 7;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  5);
              }

              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  6);
              }

              {
                Model_EVCU.Data[1] = Model_EVCU.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 6
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = EVCU_Byte0.Bit.F6_7_BatNCtorCtrl;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  6);
              }

              {
                Model_EVCU.Data[0] = Model_EVCU.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_1' */
void S223_Information_1(void)
{
  /* S-Function (scanpack): '<S16>/CAN Pack70' */
  Model_Information_1.ID = 419375860U;
  Model_Information_1.Length = 8U;
  Model_Information_1.Extended = 1U;
  Model_Information_1.Remote = 0;
  Model_Information_1.Data[0] = 0;
  Model_Information_1.Data[1] = 0;
  Model_Information_1.Data[2] = 0;
  Model_Information_1.Data[3] = 0;
  Model_Information_1.Data[4] = 0;
  Model_Information_1.Data[5] = 0;
  Model_Information_1.Data[6] = 0;
  Model_Information_1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 11.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_BatHighestTempBoxNum);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (11U) ) {
            /* upper saturation */
            result = (uint32_T) (11U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[4] = Model_Information_1.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 18.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_BatHighestTempBoxPosi);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (18U) ) {
            /* upper saturation */
            result = (uint32_T) (18U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[5] = Model_Information_1.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 11.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_BatLowestTempBoxNum);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (11U) ) {
            /* upper saturation */
            result = (uint32_T) (11U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[6] = Model_Information_1.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 18.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_BatLowestTempBoxPosi);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (18U) ) {
            /* upper saturation */
            result = (uint32_T) (18U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[7] = Model_Information_1.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 11.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_CellHighestVolBoxNum);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (11U) ) {
            /* upper saturation */
            result = (uint32_T) (11U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[0] = Model_Information_1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 18.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_CellHighestVolBoxPosi);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (18U) ) {
            /* upper saturation */
            result = (uint32_T) (18U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[1] = Model_Information_1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 11.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_CellLowestVolBoxNum);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (11U) ) {
            /* upper saturation */
            result = (uint32_T) (11U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[2] = Model_Information_1.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 18.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (g_CellLowestVolBoxPosi);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (18U) ) {
            /* upper saturation */
            result = (uint32_T) (18U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_1.Data[3] = Model_Information_1.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_10' */
void S223_Information_10(void)
{
  /* S-Function (scanpack): '<S17>/CAN Pack79' */
  Model_Information_10.ID = 419377908U;
  Model_Information_10.Length = 8U;
  Model_Information_10.Extended = 1U;
  Model_Information_10.Remote = 0;
  Model_Information_10.Data[0] = 0;
  Model_Information_10.Data[1] = 0;
  Model_Information_10.Data[2] = 0;
  Model_Information_10.Data[3] = 0;
  Model_Information_10.Data[4] = 0;
  Model_Information_10.Data[5] = 0;
  Model_Information_10.Data[6] = 0;
  Model_Information_10.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatTypeCode);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_10.Data[2] = Model_Information_10.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (Day);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_10.Data[5] = Model_Information_10.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (FacCode);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (packingValue > (uint16_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (packingValue < (uint16_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (packingValue);
            }

            {
              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_10.Data[0] = Model_Information_10.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_10.Data[1] = Model_Information_10.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (Month);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_10.Data[4] = Model_Information_10.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (SeralNum);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (packingValue > (uint16_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (packingValue < (uint16_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (packingValue);
            }

            {
              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_10.Data[6] = Model_Information_10.Data[6] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_10.Data[7] = Model_Information_10.Data[7] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (Year);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_10.Data[3] = Model_Information_10.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_11' */
void S223_Information_11(void)
{
  /* S-Function (scanpack): '<S18>/CAN Pack80' */
  Model_Information_11.ID = 419378164U;
  Model_Information_11.Length = 8U;
  Model_Information_11.Extended = 1U;
  Model_Information_11.Remote = 0;
  Model_Information_11.Data[0] = 0;
  Model_Information_11.Data[1] = 0;
  Model_Information_11.Data[2] = 0;
  Model_Information_11.Data[3] = 0;
  Model_Information_11.Data[4] = 0;
  Model_Information_11.Data[5] = 0;
  Model_Information_11.Data[6] = 0;
  Model_Information_11.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxHighestTemp1);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[0] = Model_Information_11.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxHighestTemp2);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[2] = Model_Information_11.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxHighestTemp3);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[4] = Model_Information_11.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxHighestTemp4);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[6] = Model_Information_11.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxLowestTemp1);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[1] = Model_Information_11.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxLowestTemp2);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[3] = Model_Information_11.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxLowestTemp3);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[5] = Model_Information_11.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxLowestTemp4);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_11.Data[7] = Model_Information_11.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_12' */
void S223_Information_12(void)
{
  /* S-Function (scanpack): '<S19>/CAN Pack' */
  Model_Information_12.ID = 419378420U;
  Model_Information_12.Length = 8U;
  Model_Information_12.Extended = 1U;
  Model_Information_12.Remote = 0;
  Model_Information_12.Data[0] = 0;
  Model_Information_12.Data[1] = 0;
  Model_Information_12.Data[2] = 0;
  Model_Information_12.Data[3] = 0;
  Model_Information_12.Data[4] = 0;
  Model_Information_12.Data[5] = 0;
  Model_Information_12.Data[6] = 0;
  Model_Information_12.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxHighestTemp5);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_12.Data[0] = Model_Information_12.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxHighestTemp6);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_12.Data[2] = Model_Information_12.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxLowestTemp5);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_12.Data[1] = Model_Information_12.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatBoxLowestTemp6);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_12.Data[3] = Model_Information_12.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_2' */
void S223_Information_2(void)
{
  /* S-Function (scanpack): '<S20>/CAN Pack71' */
  Model_Information_2.ID = 419376116U;
  Model_Information_2.Length = 8U;
  Model_Information_2.Extended = 1U;
  Model_Information_2.Remote = 0;
  Model_Information_2.Data[0] = 0;
  Model_Information_2.Data[1] = 0;
  Model_Information_2.Data[2] = 0;
  Model_Information_2.Data[3] = 0;
  Model_Information_2.Data[4] = 0;
  Model_Information_2.Data[5] = 0;
  Model_Information_2.Data[6] = 0;
  Model_Information_2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatArea);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (packingValue > (uint16_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (packingValue < (uint16_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (packingValue);
            }

            {
              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_2.Data[2] = Model_Information_2.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_2.Data[3] = Model_Information_2.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatFac);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (packingValue > (uint16_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (packingValue < (uint16_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (packingValue);
            }

            {
              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_2.Data[0] = Model_Information_2.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_2.Data[1] = Model_Information_2.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatPackInfo);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint32_T packedValue;
            if (packingValue > (uint32_T)(4294967295U)) {
              packedValue = (uint32_T) 4294967295U;
            } else if (packingValue < (uint32_T)(0)) {
              packedValue = (uint32_T) 0;
            } else {
              packedValue = (uint32_T) (packingValue);
            }

            {
              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_2.Data[4] = Model_Information_2.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_2.Data[5] = Model_Information_2.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 15)) >> 15)<<7);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 16)) >> 16)<<0);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 17)) >> 17)<<1);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 18)) >> 18)<<2);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 19)) >> 19)<<3);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 20)) >> 20)<<4);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 21)) >> 21)<<5);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 22)) >> 22)<<6);
              }

              {
                Model_Information_2.Data[6] = Model_Information_2.Data[6] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 23)) >> 23)<<7);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 24)) >> 24)<<0);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 25)) >> 25)<<1);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 26)) >> 26)<<2);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 27)) >> 27)<<3);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 28)) >> 28)<<4);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 29)) >> 29)<<5);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 30)) >> 30)<<6);
              }

              {
                Model_Information_2.Data[7] = Model_Information_2.Data[7] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 31)) >> 31)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_3' */
void S223_Information_3(void)
{
  /* S-Function (scanpack): '<S21>/CAN Pack72' */
  Model_Information_3.ID = 419376372U;
  Model_Information_3.Length = 8U;
  Model_Information_3.Extended = 1U;
  Model_Information_3.Remote = 0;
  Model_Information_3.Data[0] = 0;
  Model_Information_3.Data[1] = 0;
  Model_Information_3.Data[2] = 0;
  Model_Information_3.Data[3] = 0;
  Model_Information_3.Data[4] = 0;
  Model_Information_3.Data[5] = 0;
  Model_Information_3.Data[6] = 0;
  Model_Information_3.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatPackTempHighThold);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_3.Data[5] = Model_Information_3.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -40.0
     *  minimum                 = -40.0
     *  maximum                 = 127.0
     * -----------------------------------------------------------------------*/
    {
      {
        int32_T packingValue = 0;

        {
          int32_T result = (int32_T) (BatPackTempLowThold);
          if (result > (int32_T) (127.0) ) {
            /* upper saturation */
            result = (int32_T) (127.0);
          }

          /* no factor to apply */
          result = (int32_T) (result - -40.0);
          packingValue = result;
        }

        if (packingValue < 0) {
          packingValue = 0;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (int32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (int32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_3.Data[4] = Model_Information_3.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 15.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = BatVolHighThold;
          if (result > 15.0F) {
            /* upper saturation */
            result = 15.0F;
          }

          /* no offset to apply */
          result = result / 0.01F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_3.Data[2] = Model_Information_3.Data[2] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_3.Data[3] = Model_Information_3.Data[3] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 15.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = BatVolLowThold;
          if (result > 15.0F) {
            /* upper saturation */
            result = 15.0F;
          }

          /* no offset to apply */
          result = result / 0.01F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_3.Data[0] = Model_Information_3.Data[0] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_3.Data[1] = Model_Information_3.Data[1] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_4' */
void S223_Information_4(void)
{
  /* S-Function (scanpack): '<S22>/CAN Pack73' */
  Model_Information_4.ID = 419376628U;
  Model_Information_4.Length = 8U;
  Model_Information_4.Extended = 1U;
  Model_Information_4.Remote = 0;
  Model_Information_4.Data[0] = 0;
  Model_Information_4.Data[1] = 0;
  Model_Information_4.Data[2] = 0;
  Model_Information_4.Data[3] = 0;
  Model_Information_4.Data[4] = 0;
  Model_Information_4.Data[5] = 0;
  Model_Information_4.Data[6] = 0;
  Model_Information_4.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 11.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatBoxNum);
          if (result > (uint32_T) (11U) ) {
            /* upper saturation */
            result = (uint32_T) (11U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_4.Data[0] = Model_Information_4.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 192.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatFrameNum);
          if (result > (uint32_T) (192U) ) {
            /* upper saturation */
            result = (uint32_T) (192U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_4.Data[1] = Model_Information_4.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 192.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatFrameNum2);
          if (result > (uint32_T) (192U) ) {
            /* upper saturation */
            result = (uint32_T) (192U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_4.Data[3] = Model_Information_4.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 380.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = BatRatedEnergy;
          if (result > 380.0F) {
            /* upper saturation */
            result = 380.0F;
          }

          /* no offset to apply */
          result = result / 1.5F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_4.Data[6] = Model_Information_4.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = BatRatedVol;
          if (result > 1000.0F) {
            /* upper saturation */
            result = 1000.0F;
          }

          /* no offset to apply */
          result = result / 0.1F;
          outValue = result;
        }

        {
          {
            uint16_T packedValue;
            if (outValue > (real32_T)(65535)) {
              packedValue = (uint16_T) 65535;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint16_T) 0;
            } else {
              packedValue = (uint16_T) (outValue);
            }

            {
              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_4.Data[4] = Model_Information_4.Data[4] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_Information_4.Data[5] = Model_Information_4.Data[5] |
                  (uint8_T)((uint8_T)((uint16_T)(packedValue & (uint16_T)
                  (((uint16_T)(1)) << 15)) >> 15)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 380.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = BatRemainEnergy;
          if (result > 380.0F) {
            /* upper saturation */
            result = 380.0F;
          }

          /* no offset to apply */
          result = result / 1.5F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_4.Data[7] = Model_Information_4.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 1.0
     *  maximum                 = 64.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BatTempNum);
          if (result < (uint32_T) (1U) ) {
            /* lower saturation */
            result = (uint32_T) (1U);
          }

          if (result > (uint32_T) (64U) ) {
            /* upper saturation */
            result = (uint32_T) (64U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_4.Data[2] = Model_Information_4.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_5' */
void S223_Information_5(void)
{
  /* S-Function (scanpack): '<S23>/CAN Pack74' */
  Model_Information_5.ID = 419376884U;
  Model_Information_5.Length = 8U;
  Model_Information_5.Extended = 1U;
  Model_Information_5.Remote = 0;
  Model_Information_5.Data[0] = 0;
  Model_Information_5.Data[1] = 0;
  Model_Information_5.Data[2] = 0;
  Model_Information_5.Data[3] = 0;
  Model_Information_5.Data[4] = 0;
  Model_Information_5.Data[5] = 0;
  Model_Information_5.Data[6] = 0;
  Model_Information_5.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum1);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[0] = Model_Information_5.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum2);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[1] = Model_Information_5.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum3);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[2] = Model_Information_5.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum4);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[3] = Model_Information_5.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum5);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[4] = Model_Information_5.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum6);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[5] = Model_Information_5.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum7);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[6] = Model_Information_5.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum8);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_5.Data[7] = Model_Information_5.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_6' */
void S223_Information_6(void)
{
  /* S-Function (scanpack): '<S24>/CAN Pack75' */
  Model_Information_6.ID = 419377140U;
  Model_Information_6.Length = 8U;
  Model_Information_6.Extended = 1U;
  Model_Information_6.Remote = 0;
  Model_Information_6.Data[0] = 0;
  Model_Information_6.Data[1] = 0;
  Model_Information_6.Data[2] = 0;
  Model_Information_6.Data[3] = 0;
  Model_Information_6.Data[4] = 0;
  Model_Information_6.Data[5] = 0;
  Model_Information_6.Data[6] = 0;
  Model_Information_6.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum10);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_6.Data[1] = Model_Information_6.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum11);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_6.Data[2] = Model_Information_6.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxCellNum9);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_6.Data[0] = Model_Information_6.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_7' */
void S223_Information_7(void)
{
  /* S-Function (scanpack): '<S25>/CAN Pack76' */
  Model_Information_7.ID = 419377396U;
  Model_Information_7.Length = 8U;
  Model_Information_7.Extended = 1U;
  Model_Information_7.Remote = 0;
  Model_Information_7.Data[0] = 0;
  Model_Information_7.Data[1] = 0;
  Model_Information_7.Data[2] = 0;
  Model_Information_7.Data[3] = 0;
  Model_Information_7.Data[4] = 0;
  Model_Information_7.Data[5] = 0;
  Model_Information_7.Data[6] = 0;
  Model_Information_7.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum1);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[0] = Model_Information_7.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum2);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[1] = Model_Information_7.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum3);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[2] = Model_Information_7.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum4);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[3] = Model_Information_7.Data[3] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 32
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum5);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[4] = Model_Information_7.Data[4] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 40
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum6);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[5] = Model_Information_7.Data[5] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum7);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[6] = Model_Information_7.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum8);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_7.Data[7] = Model_Information_7.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_8' */
void S223_Information_8(void)
{
  /* S-Function (scanpack): '<S26>/CAN Pack77' */
  Model_Information_8.ID = 419377652U;
  Model_Information_8.Length = 8U;
  Model_Information_8.Extended = 1U;
  Model_Information_8.Remote = 0;
  Model_Information_8.Data[0] = 0;
  Model_Information_8.Data[1] = 0;
  Model_Information_8.Data[2] = 0;
  Model_Information_8.Data[3] = 0;
  Model_Information_8.Data[4] = 0;
  Model_Information_8.Data[5] = 0;
  Model_Information_8.Data[6] = 0;
  Model_Information_8.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum10);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_8.Data[1] = Model_Information_8.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum11);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_8.Data[2] = Model_Information_8.Data[2] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 100.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (BoxTempNum9);
          if (result > (uint32_T) (100U) ) {
            /* upper saturation */
            result = (uint32_T) (100U);
          }

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_8.Data[0] = Model_Information_8.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_Information_9' */
void S223_Information_9(void)
{
  /* S-Function (scanpack): '<S27>/CAN Pack78' */
  Model_Information_9.ID = 418447604U;
  Model_Information_9.Length = 8U;
  Model_Information_9.Extended = 1U;
  Model_Information_9.Remote = 0;
  Model_Information_9.Data[0] = 0;
  Model_Information_9.Data[1] = 0;
  Model_Information_9.Data[2] = 0;
  Model_Information_9.Data[3] = 0;
  Model_Information_9.Data[4] = 0;
  Model_Information_9.Data[5] = 0;
  Model_Information_9.Data[6] = 0;
  Model_Information_9.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 380.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = BatRatedEnergy2;
          if (result > 380.0F) {
            /* upper saturation */
            result = 380.0F;
          }

          /* no offset to apply */
          result = result / 1.5F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_9.Data[7] = Model_Information_9.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 48
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 380.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = BatRemainEnergy2;
          if (result > 380.0F) {
            /* upper saturation */
            result = 380.0F;
          }

          /* no offset to apply */
          result = result / 1.5F;
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real32_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (outValue < (real32_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_Information_9.Data[6] = Model_Information_9.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Output and update for atomic system: '<Root>/S223_InsulatedS223' */
void S223_InsulatedS223(void)
{
  /* S-Function (scanpack): '<S28>/CAN Pack81' */
  Model_InsulatedModel.ID = 419367154U;
  Model_InsulatedModel.Length = 8U;
  Model_InsulatedModel.Extended = 1U;
  Model_InsulatedModel.Remote = 0;
  Model_InsulatedModel.Data[0] = 0;
  Model_InsulatedModel.Data[1] = 0;
  Model_InsulatedModel.Data[2] = 0;
  Model_InsulatedModel.Data[3] = 0;
  Model_InsulatedModel.Data[4] = 0;
  Model_InsulatedModel.Data[5] = 0;
  Model_InsulatedModel.Data[6] = 0;
  Model_InsulatedModel.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 52
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = InsulatedModel_Byte6.Bit.F4_7_Rever;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(15)) {
              packedValue = (uint8_T) 15;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<4);
              }

              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<5);
              }

              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<6);
              }

              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 24
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (InsulatedModel_Byte1_3);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint32_T packedValue;
            if (packingValue > (uint32_T)(16777215)) {
              packedValue = (uint32_T) 16777215;
            } else if (packingValue < (uint32_T)(0)) {
              packedValue = (uint32_T) 0;
            } else {
              packedValue = (uint32_T) (packingValue);
            }

            {
              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_InsulatedModel.Data[0] = Model_InsulatedModel.Data[0] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_InsulatedModel.Data[1] = Model_InsulatedModel.Data[1] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 15)) >> 15)<<7);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 16)) >> 16)<<0);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 17)) >> 17)<<1);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 18)) >> 18)<<2);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 19)) >> 19)<<3);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 20)) >> 20)<<4);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 21)) >> 21)<<5);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 22)) >> 22)<<6);
              }

              {
                Model_InsulatedModel.Data[2] = Model_InsulatedModel.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 23)) >> 23)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 24
     *  length                  = 24
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (InsulatedModel_Byte4_6);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint32_T packedValue;
            if (packingValue > (uint32_T)(16777215)) {
              packedValue = (uint32_T) 16777215;
            } else if (packingValue < (uint32_T)(0)) {
              packedValue = (uint32_T) 0;
            } else {
              packedValue = (uint32_T) (packingValue);
            }

            {
              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_InsulatedModel.Data[3] = Model_InsulatedModel.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 7)) >> 7)<<7);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 8)) >> 8)<<0);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 9)) >> 9)<<1);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 10)) >> 10)<<2);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 11)) >> 11)<<3);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 12)) >> 12)<<4);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 13)) >> 13)<<5);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 14)) >> 14)<<6);
              }

              {
                Model_InsulatedModel.Data[4] = Model_InsulatedModel.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 15)) >> 15)<<7);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 16)) >> 16)<<0);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 17)) >> 17)<<1);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 18)) >> 18)<<2);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 19)) >> 19)<<3);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 20)) >> 20)<<4);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 21)) >> 21)<<5);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 22)) >> 22)<<6);
              }

              {
                Model_InsulatedModel.Data[5] = Model_InsulatedModel.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                  (((uint32_T)(1)) << 23)) >> 23)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = InsulatedModel_Byte6.Bit.InsulatedModel_Byte7_bit1_2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 50
     *  length                  = 2
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        real64_T outValue = 0;

        {
          real64_T result = InsulatedModel_Byte6.Bit.InsulatedModel_Byte7_bit3_4;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (outValue > (real64_T)(3)) {
              packedValue = (uint8_T) 3;
            } else if (outValue < (real64_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (outValue);
            }

            {
              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<2);
              }

              {
                Model_InsulatedModel.Data[6] = Model_InsulatedModel.Data[6] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<3);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 56
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (InsulatedModel_Byte8);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (uint8_T)(255)) {
              packedValue = (uint8_T) 255;
            } else if (packingValue < (uint8_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                Model_InsulatedModel.Data[7] = Model_InsulatedModel.Data[7] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
              }
            }
          }
        }
      }
    }
  }
}

/* Model step function */
void canmessgaeV1_0_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS1' */
  S223_BMS1();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS1' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS2' */
  S223_BMS2();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS2' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS11' */
  S223_BMS11();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS11' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS3' */
  S223_BMS3();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS3' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS4' */
  S223_BMS4();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS4' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS5' */
  S223_BMS5();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS5' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS7' */
  S223_BMS7();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS7' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Charge_1' */
  S223_Charge_1();

  /* End of Outputs for SubSystem: '<Root>/S223_Charge_1' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Charge_2' */
  S223_Charge_2();

  /* End of Outputs for SubSystem: '<Root>/S223_Charge_2' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Charge_3' */
  S223_Charge_3();

  /* End of Outputs for SubSystem: '<Root>/S223_Charge_3' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS8' */
  S223_BMS8();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS8' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_1' */
  S223_Information_1();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_1' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_2' */
  S223_Information_2();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_2' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_3' */
  S223_Information_3();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_3' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_4' */
  S223_Information_4();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_4' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_5' */
  S223_Information_5();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_5' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_6' */
  S223_Information_6();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_6' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_7' */
  S223_Information_7();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_7' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_8' */
  S223_Information_8();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_8' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_9' */
  S223_Information_9();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_9' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_10' */
  S223_Information_10();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_10' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS9' */
  S223_BMS9();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS9' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_11' */
  S223_Information_11();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_11' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_InsulatedS223' */
  S223_InsulatedS223();

  /* End of Outputs for SubSystem: '<Root>/S223_InsulatedS223' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS10' */
  S223_BMS10();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS10' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_BMS6' */
  S223_BMS6();

  /* End of Outputs for SubSystem: '<Root>/S223_BMS6' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_Information_12' */
  S223_Information_12();

  /* End of Outputs for SubSystem: '<Root>/S223_Information_12' */

  /* Outputs for Atomic SubSystem: '<Root>/S223_EVCU' */
  S223_EVCU();

  /* End of Outputs for SubSystem: '<Root>/S223_EVCU' */
}

/* Model initialize function */
void canmessgaeV1_0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(canmessgaeV1_0_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &canmessgaeV1_0_B), 0,
                sizeof(B_canmessgaeV1_0_T));

  /* exported global signals */
  Model_InsulatedModel = CAN_DATATYPE_GROUND;
  Model_Information_9 = CAN_DATATYPE_GROUND;
  Model_Information_8 = CAN_DATATYPE_GROUND;
  Model_Information_7 = CAN_DATATYPE_GROUND;
  Model_Information_6 = CAN_DATATYPE_GROUND;
  Model_Information_5 = CAN_DATATYPE_GROUND;
  Model_Information_4 = CAN_DATATYPE_GROUND;
  Model_Information_3 = CAN_DATATYPE_GROUND;
  Model_Information_2 = CAN_DATATYPE_GROUND;
  Model_Information_12 = CAN_DATATYPE_GROUND;
  Model_Information_11 = CAN_DATATYPE_GROUND;
  Model_Information_10 = CAN_DATATYPE_GROUND;
  Model_Information_1 = CAN_DATATYPE_GROUND;
  Model_EVCU = CAN_DATATYPE_GROUND;
  Model_Charge_3 = CAN_DATATYPE_GROUND;
  Model_Charge_2 = CAN_DATATYPE_GROUND;
  Model_Charge_1 = CAN_DATATYPE_GROUND;
  Model_BMS9 = CAN_DATATYPE_GROUND;
  Model_BMS8 = CAN_DATATYPE_GROUND;
  Model_BMS7 = CAN_DATATYPE_GROUND;
  Model_BMS6 = CAN_DATATYPE_GROUND;
  Model_BMS5 = CAN_DATATYPE_GROUND;
  Model_BMS4 = CAN_DATATYPE_GROUND;
  Model_BMS3 = CAN_DATATYPE_GROUND;
  Model_BMS2 = CAN_DATATYPE_GROUND;
  Model_BMS11 = CAN_DATATYPE_GROUND;
  Model_BMS10 = CAN_DATATYPE_GROUND;
  Model_BMS1 = CAN_DATATYPE_GROUND;

  /* states (dwork) */
  (void) memset((void *)&canmessgaeV1_0_DW, 0,
                sizeof(DW_canmessgaeV1_0_T));

  /* external inputs */
  g_SystemVoltageV0 = 0.0F;
  g_BatSysTotalCur = 0.0F;
  g_SysSOC = 0.0F;
  g_CellLowestVol = 0.0F;
  g_CellHighestVol = 0.0F;
  g_BatLowestTemp = 0;
  g_BatHighestTemp = 0;
  s_life = 0U;
  YearBCD = 0U;
  MonthBCD = 0U;
  DayBCD = 0U;
  HourBCD = 0U;
  MinuteBCD = 0U;
  VersionNum = 0.0F;
  g_MaxDischaCur = 0.0F;
  g_MaxChaCur = 0.0F;
  MaxCtousChaCur = 0.0F;
  MaxChaTotalVol = 0.0F;
  MaxChaTotalVol1 = 0.0F;
  g_MaxFebCur = 0.0F;
  HighestChaCellVol = 0.0F;
  HighestChaCellTemp = 0;
  LowestDischaTotalVol = 0.0F;
  ChaBeginHourBCD = 0U;
  ChaBeginMinuteBCD = 0U;
  ChaBeginSecondBCD = 0U;
  ChaEndHourBCD = 0U;
  ChaEndMinuteBCD = 0U;
  ChaEndSecondBCD = 0U;
  ActalChaVol = 0.0F;
  ChaInHourBCD = 0U;
  ChaInMinuteBCD = 0U;
  ChaInSecondBCD = 0U;
  ChaOutHourBCD = 0U;
  ChaOutMinuteBCD = 0U;
  ChaOutSecondBCD = 0U;
  ActalChaCur = 0.0F;
  Charge_3_Byte1 = 0U;
  ChaPCtorBatVol = 0.0F;
  ChaPCtorChgerVol = 0.0F;
  ChaNCtorBatVol = 0.0F;
  ChaNCtorChgerVol = 0.0F;
  g_CellHighestVolBoxNum = 0U;
  g_CellHighestVolBoxPosi = 0U;
  g_CellLowestVolBoxNum = 0U;
  g_CellLowestVolBoxPosi = 0U;
  g_BatHighestTempBoxNum = 0U;
  g_BatHighestTempBoxPosi = 0U;
  g_BatLowestTempBoxNum = 0U;
  g_BatLowestTempBoxPosi = 0U;
  BatFac = 0U;
  BatArea = 0U;
  BatPackInfo = 0U;
  BatVolLowThold = 0.0F;
  BatVolHighThold = 0.0F;
  BatPackTempLowThold = 0;
  BatPackTempHighThold = 0;
  BatBoxNum = 0U;
  BatFrameNum = 0U;
  BatTempNum = 0U;
  BatFrameNum2 = 0U;
  BatRatedVol = 0.0F;
  BatRatedEnergy = 0.0F;
  BatRemainEnergy = 0.0F;
  BoxCellNum1 = 0U;
  BoxCellNum2 = 0U;
  BoxCellNum3 = 0U;
  BoxCellNum4 = 0U;
  BoxCellNum5 = 0U;
  BoxCellNum6 = 0U;
  BoxCellNum7 = 0U;
  BoxCellNum8 = 0U;
  BoxCellNum9 = 0U;
  BoxCellNum10 = 0U;
  BoxCellNum11 = 0U;
  BoxTempNum1 = 0U;
  BoxTempNum2 = 0U;
  BoxTempNum3 = 0U;
  BoxTempNum4 = 0U;
  BoxTempNum5 = 0U;
  BoxTempNum6 = 0U;
  BoxTempNum7 = 0U;
  BoxTempNum8 = 0U;
  BoxTempNum9 = 0U;
  BoxTempNum10 = 0U;
  BoxTempNum11 = 0U;
  BatRemainEnergy2 = 0.0F;
  BatRatedEnergy2 = 0.0F;
  FacCode = 0U;
  BatTypeCode = 0U;
  Year = 0U;
  Month = 0U;
  Day = 0U;
  SeralNum = 0U;
  ChaCtorBndVol1 = 0.0F;
  ChaCtorBndVol2 = 0.0F;
  BatBoxHighestTemp1 = 0;
  BatBoxLowestTemp1 = 0;
  BatBoxHighestTemp2 = 0;
  BatBoxLowestTemp2 = 0;
  BatBoxHighestTemp3 = 0;
  BatBoxLowestTemp3 = 0;
  BatBoxHighestTemp4 = 0;
  BatBoxLowestTemp4 = 0;
  InsulatedModel_Byte1_3 = 0U;
  InsulatedModel_Byte4_6 = 0U;
  InsulatedModel_Byte8 = 0U;
  g_DCTemp1 = 0.0F;
  g_DCTemp2 = 0.0F;
  ChaSketHighVolPTemp2 = 0;
  ChaSketHighVolNTemp2 = 0;
  g_BMSSelfCheckCounter = 0U;
  stateCode = 0U;
  BatBoxHighestTemp5 = 0;
  BatBoxLowestTemp5 = 0;
  BatBoxHighestTemp6 = 0;
  BatBoxLowestTemp6 = 0;
  ChaPCtorBatVol2 = 0U;
  ChaPCtorChgerVol2 = 0U;
}

/* Model terminate function */
void canmessgaeV1_0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
