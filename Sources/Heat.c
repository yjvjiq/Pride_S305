//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : Heat.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2016.2.14
//* Description        : ���ļ����ڼ��ȹ���,ֻ�ڿ��ģʽ������
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include  "BMS20.h"
//unsigned char st_heating=0;//������ؼ���״̬��0δ���ȣ�1Ԥ�����У�2�߳��߼�����
float HeatCurt;
//***********************************************************************
//* Function name:   HeatManage
//* Description:     ״̬��Ϊ170��ʱ������ȹ���
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
/*void HeatManage(void)
{
    static unsigned int tt=0;
    
    if(Tavg==0)      //�¶��쳣
    {
        st_heating=0;  
        return;
    }
    
    if(g_CellHighestVol>HIGHEST_ALLOWED_CHARGE_CV)
        return;
    //************δ���Ƚ׶�,�¶������Ǵ��ڵ���10��st_heating��Ϊ0
    if(st_heating==0)
    {
        //if(Tavg<40)//0+40,С��0�ȣ�����Ԥ���Ƚ׶�
        if(Tavg<(START_ALLOWED_PreHEAT_CHARGE_TEM+40))//С��0�ȣ�����Ԥ���Ƚ׶�
        {
            st_heating=1;    
            HeatCurt = HIGHEST_ALLOWED_HEAT_CHARGE_C;        
   
        } 
        else if(Tavg<=(START_ALLOWED_HEAT_CHARGE_TEM+40))//0-10�ȣ�����߼��ȱ߳��׶�
        {
            st_heating=2;
            HeatCurt=HIGHEST_ALLOWED_HEAT_CHARGE_C;  
        } 
        
    }
    //*************��Ԥ���Ƚ׶Σ�ֻ���ȣ��������ֻ������ȵ����������������
    if(st_heating==1)
    {
        if(Tavg>(STOP_ALLOWED_PreHEAT_CHARGE_TEM+40)) //����5�㣬Ԥ���Ƚ���
        {
            st_heating=2;
            HeatCurt=HIGHEST_ALLOWED_HEAT_CHARGE_C; 
        }
    }
    
    //*************�ڱ߼��ȱ߳��׶�   
    if(st_heating==2)
    {
        if((Tavg>(STOP_ALLOWED_HEAT_CHARGE_TEM+40))) //����15�㣬���ȱ߳��׶ν���
        {
            st_heating=0;
            HeatCurt=0;
        }
        if((Tavg<=(-1+40))) //����ڱ߳��߼��ȹ����У�����Tavg��-1�棬����ת��Ԥ����ģʽ��ֻ���Ȳ���磻
        {
            st_heating=1;
            HeatCurt = HIGHEST_ALLOWED_HEAT_CHARGE_C; 
        }
    }
    if((st_heating==1)||(st_heating==2)) 
    { 
        BMS6_Byte0.byte=0x55;
        BMS6_Byte1.byte=0x55;
        BMS6_Byte2.byte=0x55;
        BMS6_Byte3.byte=0x55;
        BMS6_Byte4.byte=0x55;
        BMS6_Byte5.byte=0x55;
    } 
    else
    { 
        BMS6_Byte0.byte=0;
        BMS6_Byte1.byte=0;
        BMS6_Byte2.byte=0;
        BMS6_Byte3.byte=0;
        BMS6_Byte4.byte=0;
        BMS6_Byte5.byte=0;
    }

}

//******************************************************************************
//* Function name:   HeatAndChargeControl
//* Description:     �߳��߼��ȼ��ȼ̵�������
//* EntryParameter : void
//* ReturnValue    : void
//******************************************************************************
void HeatAndChargeControl(void)
{
    static unsigned int time;
    if(st_heating==0) //
    {
        TurnOff_INHK();//�Ͽ����ȼ̵���
    } 
    else if(st_heating==1)  //����Ԥ����
    {
        TurnOn_INHK(); //�պϼ��ȼ̵��� 
    } 
    else
    {
        if(Tavg>(STOP_ALLOWED_HEAT_CHARGE_TEM+40)) //����¶ȴ���40+15�ȣ���Ͽ����ȼ̵���
        {
            TurnOff_INHK();   //�Ͽ����ȼ̵���
        }
        else if(Tavg<=(START_ALLOWED_HEAT_CHARGE_TEM+40))//����¶�С��40+10�ȣ���պϼ��ȼ̵���
        { 
            TurnOn_INHK();   //�պϼ��ȼ̵��� 
        }
        if((g_BatSysTotalCur>=2)&&(g_CellLowestVol<2.8))//��ֹ�õ�ؽ��м���
        {      
            time++;
            if(time>100)//250ms*100=25S
                TurnOff_INHK();      //�Ͽ����ȼ̵���   
        } 
        else
            time=0;
    }

}
*/
//***************************************************************************
//***************************************************************************
//***************************the end******************************************
//*******************************************************************************
//*********************************************************************************