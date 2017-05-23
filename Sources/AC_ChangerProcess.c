//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : 5T
//* File Name          : AC_ChangerProcess.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2011,05,26
//* Description        : ��������
//----------------------------------------------------------------------------------------------------



#include "BMS20.h"

unsigned char plug_AC_CP_Connect=0;   //�������ǹ�����ź�
unsigned char slowRechargeFinished=0; //���������־
unsigned char ACTem1=0;
unsigned char ACTem2=0;
unsigned int OBC_Out_DC_Vol = 0;//OBC���͵�ֱ������ѹ
AC_CHANGERSTATE AC_ChangerState;      //CC�źż��������ź�
AC_CHANGERWORKSTATE AC_ChangerWorkState;//��������״̬
//******************************************************************************
//* Function name:   GetRequestCurrentAC
//* Description:     ��������������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
float GetRequestCurrentAC(void) 
{
    float CurrentAValue;
    static unsigned char ChanceHappen1 = 0;//��ѹ����3.78�󲻻ָ�
    static unsigned char ChanceHappen2 = 0;//��ѹ����3.92�󲻻ָ�
    
    if(st_heating==1)//Ԥ����
    { 
        if(Tavg<=(STOP_ALLOWED_PreHEAT_CHARGE_TEM+40)) ///С�ڵ���-10��Ԥ����
        {
            m_askvoltage = HIGHEST_ALLOWED_HEAT_CHARGE_V ;//
            CurrentAValue=0;
        }
    }
    else
    {  
        m_askvoltage = HIGHEST_ALLOWED_CHARGE_V;
        if(((g_CellHighestVol>3.78)||(ChanceHappen1==1))&&(ChanceHappen2==0))
        {
            ChanceHappen1 = 1;
        }
        if((g_CellHighestVol>3.92)||(ChanceHappen2==1))
        {
            ChanceHappen1 = 2;
            ChanceHappen2 = 1;
        }
        
        if(Tavg>=(54+40))  //����¶ȴ��ڵ���55��[54,)
        {
            m_askvoltage=0;
            CurrentAValue=0;
        }
        else if(Tavg>(45+40))//����¶�45~54��(45,54)
        {
            if(ChanceHappen1<=1)
                CurrentAValue=0.5*C;////0.5c
            else
                CurrentAValue=0.33*C;////0.33c 
        }           
        else if(Tavg >(20+40)) //����¶�45~50��(20,45]
        {
            if(ChanceHappen1<=1)
                CurrentAValue=115;
            else
                CurrentAValue=0.33*C;////0.33c     
        }
        else if(Tavg >(15+40)) //����¶�(15,20]
        {
            if(ChanceHappen1==0)
                CurrentAValue=115;
            else if(ChanceHappen1==1)
                CurrentAValue=0.5*C;////0.33c
            else if(ChanceHappen1==2)
                CurrentAValue=0.33*C;////0.33c     
                 
        }
        else if(Tavg >(10+40)) //����¶�45~50��(10,15]
        {
            if(ChanceHappen1==0)
                CurrentAValue=0.6*C;
            else if(ChanceHappen1==1)
                CurrentAValue=0.5*C;////0.33c
            else if(ChanceHappen1==2)
                CurrentAValue=0.33*C;////0.33c 
        } 
        else if(Tavg >(5+40)) //����¶�25~30��(5,10]
        {
            if(ChanceHappen1==0)
                CurrentAValue=0.5*C;
            else if(ChanceHappen1==1)
                CurrentAValue=0.4*C;////0.4c
            else if(ChanceHappen1==2)
                CurrentAValue=0.3*C;////0.3c 
        }
        else if(Tavg >(0+40)) //����¶�10~25��(0,5]
        {
            if(ChanceHappen1==0)
                CurrentAValue=0.4*C;
            else if(ChanceHappen1==1)
                CurrentAValue=0.3*C;////0.3c
            else if(ChanceHappen1==2)
                CurrentAValue=0.2*C;////0.2c 
        }
        else if(Tavg >(-10+40))//����¶�5~10��(-10,0]
        {
            CurrentAValue=0.08*C;////0.08c
        }
        else if(Tavg >=(-15+40))//[-15~-10]
        {
            CurrentAValue=0.05*C;////0.5c 
        }
        else //����¶�С��0�ȣ��������ѹΪ0���������Ϊ0
        {
            m_askvoltage=0;
            CurrentAValue=0;
        }   
    }
    if(CurrentAValue>=40.95)
        CurrentAValue = 40.95;
    if(CutACChaCurt50.word!=0)
        CurrentAValue = 0.5*CurrentAValue;
    
    return CurrentAValue;         
}
//**********************************************************************
//* Function name:   ACFaultDone
//* Description:     ��������й��ϵĴ���
//* EntryParameter : None
//* ReturnValue    : �Ƿ��µ�0:���µ�;1:�µ�
//**********************************************************************
unsigned char ACFaultDone(void)
{
    unsigned char ReturnValue=0;
    //////////////////////////////*������*/////////////////////////////
   
    //////////////////////////////������/////////////////////////////
        

    //////////////////////////////�ϸ�ѹ/////////////////////////////
   if((Fault_Group1.Bit.F7_Bat_Over_V_2==1)||(BMS7_Byte1.Bit.F7_Bat_Over_V_3==1)|| //�ܵ�ѹ
       (BMS1_Byte6.Bit.F1_Cell_Over_V_2==1)||(BMS7_Byte1.Bit.F5_Cell_Over_V_3==1))//�����ѹ
    {
        
        OffState=1;//�����µ�
        ReturnValue = 1;
    }
    else if((BMS5_Byte5.Bit.F4_P_Ins_Err_2)||(BMS5_Byte5.Bit.F6_N_Ins_Err_2)||//��Ե2������
            (BMS5_Byte3.Bit.F3_Ch_Sustain_Over_I_2) || (BMS7_Byte2.Bit.F1_Ch_Sustain_Over_I_3)) //������2����3��
    {
        OffState=1;//�����µ�
        ReturnValue = 1;    
    }
    else if((ACTem1>(70+50))||(ACTem2>(70+50))||(ACCha_Flag_BST==1))//�������¶ȹ��󡢳��ʱ����Ϊ�� 
    {
        OffState=1;//�����µ�
        ReturnValue = 1;     
    }
    else if((BMS5_Byte3.Bit.F7_Temp_Over_2 == 1)||(BMS7_Byte2.Bit.F7_IN_CAN_Err == 1)//���ǳ���3���¶ȹ��߹��ϡ��ڲ�ͨ�Ź���
             ||(BMS7_Byte1.Bit.F3_Ch_CAN_Err==1))//��������ͨ�Ź���
    {
        OffState=1;//�����µ�
        ReturnValue = 1;
    } 
    return ReturnValue; 

}

//******************************************************************************
//* Function name:   TaskRechargeAC
//* Description:     �복�س���ͨѶ���Ե�ؽ�������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void TaskRechargeAC(void)
{
    static unsigned char Step = 0x00;
    static unsigned char time0=0;
    static unsigned char Changer_happen = 0;//�Ѿ����,���ɳ���Ϊֹͣ״̬ʱ,ֹͣ���,��ֹһ�ϵ�����ϱ�"ֹͣ"  
    unsigned char ErrorState = 0;
    float curr=0;
    
    
    if((g_CellHighestVol>= (HIGHEST_ALLOWED_CHARGE_CV+0.05))&&(slowRechargeFinished==0)) //�������4.2������δ��ɣ��������ٳ�硣����ֹ�������ǳ��
        Step=0xFF;
    if(st_heating!=1) //����0��ʾ�¶ȴ���10�ȣ�2��ʾ�¶ȴ���0�ȣ�1���¶���0��
    {
        if(g_BatHighestTemp >= (HIGHEST_ALLOWED_CHARGE_T +40)||(g_BatLowestTemp < (LOWEST_ALLOWED_CHARGE_T +40))) //t>=55 or t<-20
            Step=0xFF;
    }
    else
    {
        if(g_BatHighestTemp >= (HIGHEST_ALLOWED_CHARGE_T+40)) //55��
            Step=0xFF;
    }
    
    if((plug_AC_CP_Connect==0)||(ChangerINError == 1))
    {
        Step = 0xff;
    }
    if((!slowRechargeFinished)&&(OBC_Request.Bit.OBCRequest==1)) //������δ���
    {
        curr=GetRequestCurrentAC();        
        if((g_BatSysTotalCur<=-3)&&(g_SysSOC<0.992))
            chargeRemainderTime=(unsigned int)((Q2*(1-g_SysSOC)*60)/(-g_BatSysTotalCur));
        else if(g_SysSOC>=0.992)
            chargeRemainderTime=2;     
        chargeRemainderTime=chargeRemainderTime*60;  
    }
    ErrorState = ACFaultDone();
    if((ErrorState==1)||(CutACChaCurt0.word!=0))
    {
        m_askcurrent = 0;
        Step = 0xff;
    }
    else
    {
        m_askcurrent = curr+HeatCurt;
        if(m_askcurrent>=40.95)
            m_askcurrent = 40.95; 
    }

    if(AC_ChangerWorkState.Bit.F4_S_ChgWorkState==5)//����Ѿ����ڳ��״̬
    {
        Changer_happen = 1;
        if(OBC_Out_DC_Vol>=100*50)
            pc750_group.Bit.LockAction = 2; //�պϵ�����
    } 
    else if(AC_ChangerWorkState.Bit.F4_S_ChgWorkState!=5)//�ɳ��״̬��Ϊ�ǳ��״̬
    {
      //Step = 0xFF;//�Ȳ��µ�
        if((OBC_Out_DC_Vol<100*50)&&(Changer_happen == 1))
        {
            pc750_group.Bit.LockAction = 1; //�򿪵�����
            Changer_happen=0;
        }
    }    
            
    switch(Step)
    {
        
        case 0://��ʼ
            OBC_Request.Bit.OBCRequest = 1;
            m_askcurrent = 0;
            m_askpower = m_askvoltage*m_askcurrent;
            
            Step = 1;
            
        case 1://Chge Step1
        
            OBC_Request.Bit.OBCRequest = 1;
            m_askpower = m_askvoltage*m_askcurrent;
            Step = 2;
            break;
            
        case 2://Chge Step2
            OBC_Request.Bit.OBCRequest = 1;
            m_askpower = m_askvoltage*m_askcurrent;
            if(g_CellHighestVol >= CHARGE_CUTDOWN_CV1)  //���ڵ���4.10��ʼ������
                Step = 3;
            break;
            
        case 3://Chge Step3
            OBC_Request.Bit.OBCRequest = 1;
            m_askpower = m_askvoltage*m_askcurrent;
            if(g_CellHighestVol >= HIGHEST_ALLOWED_CHARGE_CV)//4.15V
            {
                time0++;
                m_askcurrent=0.5*curr;
                if(time0>=2) //��ʱ1s�󣬵�ȷʵ����3.65����µ�
                {
                  
                    Step = 4;
                    m_askcurrent=0;
                    m_askpower = m_askvoltage*m_askcurrent;
                    time0=3;
                    break;  
                }
            } 
            else
            {
                time0 = 0;
                if(curr>=0.1*C)
                    m_askcurrent = 0.1*C;
                else
                    m_askcurrent = curr;
                m_askpower = m_askvoltage*m_askcurrent;
            }

            break;  
        case 4:
                SocRechargeAdjust();  ////����SOC,ֻ�г�����֮�������Q1   
                OBC_Request.Bit.OBCRequest = 0;
                m_askcurrent=0;
                m_askpower = m_askvoltage*m_askcurrent;
                Step = 0xFF;
                
            break;  
        case 0xFF://err or finish
                //pc750_group.Bit.LockAction = 1; //�򿪵�����
                slowRechargeFinished=1;//����������
                m_askcurrent=0;//����������Ϊ0
                m_askpower = m_askvoltage*m_askcurrent;
                OBC_Request.Bit.OBCRequest = 0;
                state_group1.Bit.St_Charge_indicator = 3;//������ To VCU
                state_group2.Bit.St_Charge_Achieve = 2;  //�����   To VCU
                OffState=1;//״̬����110��ת40�ı�־λ
            break;
        default:
          break;        
      }
      
}

//************************************************************************
//************************************************************************
//**************************the end******************************************
//************************************************************************