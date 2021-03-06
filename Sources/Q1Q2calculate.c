//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : PHEV.DJ
//* File Name          : Q1Q2calculate.c
//* Author             : Kxy
//* Version            : V1.0.0
//* Start Date         : 2016.7.12
//* Description        : 该文件用于项目的策略处理包括：系统高压上下电、SOF、回馈电流、SOC修正、电流计算等等
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h" 
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
float ChargeEndSOCAjustFactor;
float PowerOnSOCAjustFactor;


//******************************************************************************
//* Function name:   Q2nominalCalculate
//* Description:     额定容量计算 Q2_额定=Q_NEDC×k_温度×SOH×K_均衡,上电时候用,用于修正Q2
//* EntryParameter : ValueQ1
//* ReturnValue    : 额定容量
//******************************************************************************

float Q2nominalCalculate(float ValueQ1)
{
    unsigned int t=0;
    unsigned char m=0,i=0;
    float q=0;
    float kt=1;
    float soh=1;
    float kj=1;
    
    float Value=0;
    float Value1;//95AH,ValueQ1=190AH
     
    Value1 = ValueQ1;
    S223_StateMachi_PowerOnSOCAjust();
    kt=PowerOnSOCAjustFactor;
    if(kt>=1)
        kt=1;    
  
    FactorA=kt;
    if(g_BmsModeFlag == DISCHARGING)
    {   
        if((g_SysSOC==0)||(g_socValue==0))
            q = ValueQ1*kt*soh*kj;
        else
            q = ValueQ1*kt*soh*kj*g_socValue/g_SysSOC;
    } 
    else if((g_BmsModeFlag == FASTRECHARGING) || (g_BmsModeFlag == RECHARGING) )
    {   
        if((g_SysSOC==1)||(g_socValue==1))
            q = ValueQ1*kt*soh*kj;
        else
            q = ValueQ1*kt*soh*kj*(1-g_socValue)/(1-g_SysSOC);
    }
    return q;    
}



//******************************************************************************
//* Function name:   AdjustQ1Value
//* Description:     充电末端的Qmax与Qmin
//* EntryParameter : void
//* ReturnValue    : Void
//******************************************************************************
void AdjustQ1Value(void)
{
    
    S223_StateMac_ChargeEndSOCAjust();
    //y=ChargeEndadjustQ1(g_CellLowestVol,(Tavg-40)); //通过最低电压和温度，计算出和标准的系数
    g_ActalRatedCapty=ChargeEndSOCAjustFactor*C;
    StoreQ1value();


}


//************************************************************************
//************************************************************************
//************************************************************************
//************************************************************************