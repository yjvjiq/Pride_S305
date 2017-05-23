//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : mc9s12Isr.c
//* Author             : Clark
//* Version            : V1.0.0
//* Start Date         : 2017.2.6
//* Description        : ���ļ�����ϵͳ���е��ж��ӳ��򣬰���RTI�жϡ�ADC�жϡ�CAN�����жϣ�3·��
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
//*******************************************
//*******************************************
unsigned char Flag_InsulationState = 3;//��Ե��־λ������ֵ���ȴ���Եģ�鷢������ֵ
unsigned char life_insulation = 0;     //��Եģ�������ź�
float ac[12];
float ax[12];
//
struct can_msg *msg;
unsigned long g_mboxID;
unsigned char g_mboxData[1][8];// CAN2���յ��ı������ݣ�ÿ������8���ֽ�
unsigned char DubugMode=1;
unsigned char CHMStep=0; //��䲽��
unsigned char g_CHMFlag=0; //��俪ʼ��־λ����Ϊ1ʱ�ſ��Խ�������
unsigned char Int_Flag =0;// 0x01:AD�ж� 0x02:can0�ж� 

unsigned char g_errorRecordRead_flag;//������Ϣ��ȡ��־

unsigned char TestState=0;//״̬�����뵽����״̬
//float Voltage_CHG_Out = 0;    //������ѹ���ֵ
//float Current_CHG_Out = 0;    //�����������ֵ

long Priority = 6;

unsigned char DC_Start=0;//���յ�0xaa��,��ʼ�պϸ����̵���

unsigned char BootState = 0;//boot����

unsigned char TurnOnChangerRelay = 1;//�պϳ��̵���
unsigned char FlagBRMSend = 0; //BMS��֡���ı�־λ,0������,1����   
//unsigned char FlagBRMSend = 1; //BMS��֡���ı�־λ,0������,1����   FOR TEST
unsigned char BRMStep = 0; //BRM�ѷ��ͱ�־λ,0δ���ͻ�����;1�ѷ���

unsigned char FlagBCPSend = 0;//����BCP��,�յ��������ص���Ϣ,��ʼ�������ݶ�
//unsigned char FlagBCPSend = 1;//����BCP��,�յ��������ص���Ϣ,��ʼ�������ݶ�  FOR TEST
unsigned char BCPStep = 0;    //BCP�еĲ���0:����BCP��ͷ;1:����BCP�����ݶ�

unsigned char FlagBCSSend = 0;//����BCS��,�յ��������ص���Ϣ,��ʼ�������ݶ�
//unsigned char FlagBCSSend = 1;//����BCS��,�յ��������ص���Ϣ,��ʼ�������ݶ�   FOR TEST
unsigned char BCSStep = 0;    //BCS�еĲ���0:����BCS��ͷ;1:����BCP�����ݶ�
//******************************************************************************
//* Function name:   SendMes
//* Description:     ��������CAN����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void SendMes(void)
{
    static unsigned char PIT_50ms_Counter0=2;       //50ms��ʱ������
   // static unsigned char PIT_70ms_Counter0=0;       //70ms��ʱ������
    static unsigned char PIT_100ms_Counter0=7;       //100ms��ʱ������
    static unsigned char PIT_100ms_Counter1=3;       //100ms��ʱ������    
    static unsigned char PIT_100ms_Counter2=5;       //100ms��ʱ������
    static unsigned char PIT_100ms_Counter3=0;       //100ms��ʱ������
    static unsigned char PIT_100ms_Counter4=1;       //100ms��ʱ������
    //static unsigned char PIT_100ms_Counter5=27;      //100ms��ʱ������
    
    static unsigned int PIT_500ms_Counter0=19;       //500ms��ʱ������
    static unsigned int PIT_500ms_Counter1=21;       //500ms��ʱ������
    
    static unsigned int PIT_1000ms_Counter0=11;       //1000ms��ʱ������
    static unsigned int PIT_1000ms_Counter1=13;       //1000ms��ʱ������
    static unsigned int PIT_1000ms_Counter2=15;       //1000ms��ʱ������
    static unsigned int PIT_1000ms_Counter3=9;       //1000ms��ʱ������
    static unsigned int PIT_1000ms_Counter4=17;       //1000ms��ʱ������
    
    static unsigned char VolNum=0,TempNum=0,CellNum=0;      
    PIT_50ms_Counter0++; //50ms    
    PIT_100ms_Counter0++;//100ms 
    PIT_100ms_Counter1++;//100ms 
    PIT_100ms_Counter2++; //100ms 
    PIT_100ms_Counter3++; //100ms 
    PIT_100ms_Counter4++; //100ms 
    //PIT_100ms_Counter5++;
    
    PIT_500ms_Counter0++; //500ms
    PIT_500ms_Counter1++; //500ms
   
    PIT_1000ms_Counter0++; //1000ms
    PIT_1000ms_Counter1++;//1000ms
    PIT_1000ms_Counter2++; //1000ms
    PIT_1000ms_Counter3++; //1000ms
    PIT_1000ms_Counter4++; //1000ms
    ///////////////////////50ms/////////////////////////// 
    if(PIT_50ms_Counter0 == 7) 
    {
        BMS8();
        PIT_50ms_Counter0=2;
    }
    ///////////////////////100ms/////////////////////////// 
    if(PIT_100ms_Counter0 == 10)
    {  
       // if(DubugMode==1)
       //  bmsToPcTestCar();     //����ģʽ���ģ�����״̬����Լ���������� 
       // else
         Charge_3();    
    }
    if(PIT_100ms_Counter0==11)
        BMS1();
    else if(PIT_100ms_Counter0==12)
    {
        BMS2();
        PIT_100ms_Counter0=1;
    }
   
    
    if(PIT_100ms_Counter1==12)
        BMS3();
    else if(PIT_100ms_Counter1==13)
    {
        BMS4();
    }
    else if(PIT_100ms_Counter1==14)
    {
        BMS5();
        PIT_100ms_Counter1 = 3;
    }
    
    if(PIT_100ms_Counter2==14)
        BMS6();
    else if(PIT_100ms_Counter2==15)
    {
        BMS7();
    }
    else if(PIT_100ms_Counter2==16)
    {
        BMS9();
        PIT_100ms_Counter2 = 5;
    }
    
    if(PIT_100ms_Counter3>=2) 
    {
      BMS_To_VCU_CellVoltage(VolNum);
        VolNum++;
        if(VolNum>=48)
            VolNum=0;
        PIT_100ms_Counter3=0;
    }
     if(PIT_100ms_Counter4>=25) 
    {
      if(TempNum>=4)
            TempNum=0;
      BMS_To_VCU_CellTemp(TempNum);
        TempNum++;
        
        PIT_100ms_Counter4=1;
    }       
    ///////////////////////500ms///////////////////////////
    if(PIT_500ms_Counter0==68)
    {
        BMS10();  
    } 
    if(PIT_500ms_Counter0==69)
    {
        BMS11(); 
        PIT_500ms_Counter0=19;   
    }
    
     if(PIT_500ms_Counter1==70)
    {
        Charge_1();
    }
    else if(PIT_500ms_Counter1==71)
    {
        Charge_2();
        PIT_500ms_Counter1=21;
    }
    
    ///////////////////////1000ms///////////////////////////
    if(PIT_1000ms_Counter0==110)
        Information_1();
    else if(PIT_1000ms_Counter0==111)
    {
        Information_2();
    }
    else if(PIT_1000ms_Counter0==112)
    {
        Information_3();
        PIT_1000ms_Counter0 = 11;
    }
   
   if(PIT_1000ms_Counter1==112)
        Information_4();
    else if(PIT_1000ms_Counter1==113)
    {
        Information_5();
    }
    else if(PIT_1000ms_Counter1==114)
    {
        //Information_6();
        PIT_1000ms_Counter1 = 13;
    }
    
    if(PIT_1000ms_Counter2==114)
        Information_7();
    else if(PIT_1000ms_Counter2==115)
    {
        ;//Information_12();
    }
    else if(PIT_1000ms_Counter2==116)
    {
        Information_9();
        PIT_1000ms_Counter2 = 15;
    } 
     if(PIT_1000ms_Counter4==117) 
    {
       Information_10();
       
       
    } else if(PIT_1000ms_Counter4==118)
    {
        Information_11();  
        PIT_1000ms_Counter4=17;
    }


    
}
//******************************************************************************
//* Function name:   PIT0_ISR
//* Description:     10ms��ʱ�ж��ӳ���,�ڴ���Ҫ���͸�������0x650����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
#pragma CODE_SEG NON_BANKED
interrupt void PIT0_ISR(void)   //10ms�ж�һ��
{   
    
    while (PITTF&0x01) 
        PITTF |= 0x01;        //д1 to clean timeout flag
    SendMes();
    if(BMUOK==1)
        TaskDC();//����ֱ���������     
   	
}
#pragma CODE_SEG DEFAULT
//******************************************************************************
//* Function name:   RTI_ISR
//* Description:     1ms��ʱ�ж��ӳ���,��������һЩʱ���־λ�Լ�����ʹ�õ������л���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
#pragma CODE_SEG NON_BANKED
interrupt void RTI_ISR(void)      //1ms�ж�һ��
{ 
    static unsigned char numberCounter=0; 
    static unsigned char ledFlag=0;

    //turnOnLED0(); 	     // for debug 
    TaskRemarks();  //******
    
    if(tmr_p1<=600)     //����״̬����ʱ        
        if((stateCode==11)||(stateCode==81)||(stateCode==141))
            tmr_p1++;   
    if(tmr_p2<=600)
        if((stateCode==12)||(stateCode==82)||(stateCode==142))
            tmr_p2++; 
    if(tmr_p3<=1070)
        if((stateCode ==17)||(stateCode==90)||(stateCode==142))  
            tmr_p3++;
    if(tmr_p4<600)        
        if((stateCode ==13)||(stateCode==83)||(stateCode==143))  
            tmr_p4++;
    if(tmr_p5<330)
        if((stateCode ==46)||(stateCode==126)||(stateCode==186))  
            tmr_p5++;   
    if(Delay5s1<5100)
        if((stateCode ==180))
            if((EVCU_Byte1.Bit.F5_7_ChaPCtorStateFeb1!=2)||(g_DC_CC2==0)||(ChangerINError==1))
                Delay5s1++;
    if(Delay5s3<5100)
        if((stateCode==30)||(stateCode==44))
            if((WithEVCUComOverTimeFlag==1)||(g_ACC_ON==0))
                Delay5s3++;    
    if(Delay5s2<5100)
        if((stateCode ==170))
            if((g_DC_CC2==0)||(ChangerINError==1)||(OffState==1)||(WithEVCUComOverTimeFlag==2))
                Delay5s2++;    
    if(Delay10s<10100)
        if((stateCode ==30))
            if(g_PowerOffFlag==1) //�µ�
                Delay10s++;
    if(Delay60s<60100)
        if((stateCode ==44))
            //if((g_BatSysTotalCur<30))     //���ϵͳ����С��30A
                Delay60s++;    
    if((g_BatSysTotalCur>-500)&&(g_BatSysTotalCur<500))  //��ֹ�������
        g_energyOfUsed =g_energyOfUsed+ g_BatSysTotalCur*0.0011+0.0000042;// // 1m�����һ��
    //turnOffLED0(); 	     // for debug 
    // clear RTIF bit 
    CRGFLG = 0x80; 
}
#pragma CODE_SEG DEFAULT
//******************************************************************************
//* Function name:   ADC0_ISR
//* Description:     ADC�ж��ӳ���,��ȡ2��ADͨ���ĵ���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
#pragma CODE_SEG NON_BANKED
interrupt void ADC0_ISR(void) 
{	
    static unsigned char ADcount=0;
    ac[ADcount]=(((float)ATD0DR1-ADCLC)*5.0/4096-2.5)*250;//CUR_AD���ڴ����ͨ��  CUR_AD1 DHAB/S24
	  ax[ADcount]=(((float)ATD0DR0-ADCLX)*5.0/4096-2.5)*37.45;//X_AD  //����Сͨ�� CUR_AD2 ����
	  
	  //ac[ADcount]=(((float)ATD0DR1-ADCLC)*5.0/4096-2.5)*175;//CUR_AD���ڴ����ͨ��  CUR_AD1 S18
	  //ax[ADcount]=(((float)ATD0DR0-ADCLX)*5.0/4096-2.5)*15;//X_AD  //����Сͨ�� CUR_AD2 ����
	  ATD0STAT0_SCF=1;	//���������ɱ�־	                                                                                  
	  ADcount++;	
	 
	  if(ADcount>=12)
	  {
		    ADcount =0;
	 	    Int_Flag |= 0x01;
		    turnOffADC();
	  }	

}
#pragma CODE_SEG DEFAULT
//******************************************************************************
//* Function name:   CAN0_RECEIVE_ISR
//* Description:     CAN0�����ж��ӳ���,�ڸ���Ŀ�����ڽ��ս������������ı���0x6d0
//*                  //���� /�ⲿCAN / 500bd  /��׼֡��ʽ
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
#pragma CODE_SEG NON_BANKED
interrupt void CAN0_RECEIVE_ISR(void)   //���� /�ⲿCAN / 500Hz
{
   unsigned char i,msgData[8];
   unsigned long msgCan0RxID;
   unsigned long pp=0;
   unsigned long pp1=0;
   unsigned int buffer = 0;
   unsigned int buffer1 = 0;
   unsigned int buffer2 = 0;
   unsigned long int buffer3 = 0;
   unsigned long int buffer4 = 0; 
   DisableInterrupts;   
   
   if(!(CAN0RFLG&0x01)) // Checks for received messages
        return ;
   //msgCan0RxID = (unsigned int)(CAN0RXIDR0<<3) |       //standard
   //         (unsigned char)(CAN0RXIDR1>>5); 
   pp = (unsigned long)CAN0RXIDR0<<15;  
   pp1 = (unsigned long)((CAN0RXIDR1>>5)&0x07)<<15;                              
   msgCan0RxID = ((unsigned long)pp<<6) | //expanded
              (pp1<<3) |
              ((unsigned long)(CAN0RXIDR1&0x07)<<15)|
              ((unsigned long)CAN0RXIDR2<<7) | 
              ((unsigned long)CAN0RXIDR3>>1);
   
    for(i=0;i<8;i++) 
        msgData[i] = *((&CAN0RXDSR0)+i);  
                     
    switch(msgCan0RxID) 
    {
           
        case 0x1830F3D0:
            WithEVCUComOverTime=0;//������ͨ�Ź��ϳ�ʱ����
            EVCU_Byte0.byte= msgData[0];
            EVCU_Byte1.byte= msgData[1];
            g_CHMFlag=1; //��俪ʼ��־λ
            
            break;
        case 0x18FF08F2:             //��Եģ�鷢����������
            buffer1 = msgData[1];
            buffer2 = msgData[4];
            buffer3 = msgData[2];
            buffer4 = msgData[5];
            life_insulation = msgData[7];
            //RP_GND = buffer3<<16|buffer1<<8|msgData[0];
            //RN_GND = buffer4<<16|buffer2<<8|msgData[3]; 
            if(((msgData[6]&0x0c)>>2 == 0)&&((msgData[6]&0x03)>>2 == 0)) //����λΪ 0����ʾ��Եģ��ľ������(��Եֵ���豸����)
            {             
                //information9_Byte2.Bit.F0_InsuState = 0;  //����CAN��Ե������־λ
                Flag_InsulationState = 1;                 //���CAN ����BRO_AA��־
            }
            //��ʾ��Եģ��������(��Եֵ���豸����)
            else if(((msgData[6]&0x0c)>>2 == 1)||((msgData[6]&0x0c)>>2 == 2)||((msgData[6]&0x03)>>2 == 1)||((msgData[6]&0x03)>>2 == 2)||((msgData[6]&0x03)>>2 == 3))
            {                
               // information9_Byte2.Bit.F0_InsuState = 1;   //��Ե��������־λ
                Flag_InsulationState = 0;                  //���CAN ����BRO_AA��־
              
            }
            break;
        case 0x18FFF2F4:
            //buffer = msgData[4];
            //buffer = buffer<<8;
            //OBC_Out_DC_Vol = buffer+msgData[3];
            //OBC_Out_DC_Vol = buffer*0.02; 
            //AC_ChangerWorkState.byte = msgData[5];//��������״̬
           // AC_ChangerState.byte=msgData[7];//����CC�ź� 
           // ACCOverTime = 0;//����   
            break;
        default:
            break;
    }
    CAN0RFLG = 0x01;   
    EnableInterrupts; 
}
#pragma CODE_SEG DEFAULT
//******************************************************************************
//* Function name:   CAN1_RECEIVE_ISR
//* Description:     CAN1�����ж��ӳ���,���ڿ��ͨ��  250bd /��չ֡ģʽ                
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
#pragma CODE_SEG NON_BANKED
interrupt void CAN1_RECEIVE_ISR(void)  //���
{
    unsigned long can1ReceiveID;
    unsigned char i,fChg2bmsbyte[8];
    unsigned long pp=0;
    unsigned long pp1=0;
    unsigned int VolLow=0;
    unsigned int VolHigh=0;
    unsigned long ChaVol=0;
    unsigned long ChaCur=0;
    if(!(CAN1RFLG&0x01))
    {
        CAN1RFLG = 0x01;     
        EnableInterrupts;
        return;
    }
    
    pp = (unsigned long)CAN1RXIDR0<<15;
    pp1 = (unsigned long)((CAN1RXIDR1>>5)&0x07)<<15; 
    
    can1ReceiveID =((unsigned long)pp<<6) | //expanded
              (pp1<<3) |
              ((unsigned long)(CAN1RXIDR1&0x07)<<15)|
              ((unsigned long)CAN1RXIDR2<<7) | 
              ((unsigned long)CAN1RXIDR3>>1);
    for(i=0;i<8;i++) 
        fChg2bmsbyte[i] = *((&CAN1RXDSR0)+i);
       
    switch(can1ReceiveID)
    {
        case 0x1826f456:
        //if((fChg2bmsbyte[0]==0x01)&&(fChg2bmsbyte[1]==0x01)&&(fChg2bmsbyte[2]==0))
        //{                    
            DCStartState=2;//�¹��꿪ʼ�ı�־ 
            DC_Vesion = 2; //�¹���
            if(g_CHMFlag ==1) 
            {
              if(CHMStep<=0x01)
                CHMStep=0x01;
            }
        //}
            
            break;
        case 0x1801f456:
            CRMOverTimeBefore60s = 0;
            if( fChg2bmsbyte[0]==0x00)
            {              
                DCStartState=1;//�Ϲ��꿪ʼ�ı�־                 
                CRMOverTimeBefore = 0;
                if(CHMStep<=0x01)                
                    CHMStep=0x01;
            }
            else if( fChg2bmsbyte[0]==0xaa)
            {
                CRMOverTime=0;
                
                if(CHMStep<=0x02)
                    CHMStep=0x02;
                //TurnOn_INA2K();
                //SelfState2=1;
                            
            }            
            break;
        case 0x101af456:           
            g_AskDCCur=0;//�������Ϊ0 
            if(((fChg2bmsbyte[0])&(0x40)) == 0)
            {
                fastend1 = 0x40;
            }
            CSTOverTime=0;
            if(CHMStep<=0x06)    
                CHMStep=0x06;
            break;
        case 0x1807f456:    
            //CHMStep=0x03;
            break; 
        case 0x1812f456:     //CCS
            
            ChaVol= fChg2bmsbyte[1];
            ChaVol = ChaVol<<8;
            ActalChaVol = (unsigned long)((ChaVol+fChg2bmsbyte[0])*0.1);
            //ActalChaVol = (((unsigned long)fChg2bmsbyte[1])<<8+fChg2bmsbyte[0]);
            ChaCur = fChg2bmsbyte[3];
            ChaCur = ChaCur<<8;
            ActalChaCur = -((ChaCur+fChg2bmsbyte[2])*0.1);
            //ActalChaCur = (((unsigned long)fChg2bmsbyte[3])<<8+fChg2bmsbyte[2]);
            CCSOverTime=0;
            if(CHMStep<=0x05)
                CHMStep=0x05;
            break;       
        case 0x1808f456:
            VolHigh = fChg2bmsbyte[1];
            VolHigh = VolHigh<<8;
            VolHigh = (VolHigh+fChg2bmsbyte[0]);

            VolLow = fChg2bmsbyte[3];
            VolLow = VolLow<<8;
            VolLow = (VolLow+fChg2bmsbyte[2]);
            if((VolLow>HIGHEST_VOL)||(VolHigh<LOWEST_VOL))
            {
                BROErrorAA=1;//������������            
            } 
            else
            {
                BROErrorAA=0;//����������
            }
            if(CHMStep<=0x03)   
                CHMStep=0x03;
            break;  
        case 0x100af456:
            CROOverTime = 0;//�յ�CRO������
            if( fChg2bmsbyte[0]==0xaa)
            {
                if(CHMStep<=0x04)
                    CHMStep=0x04;
                SelfState3=1;
                DC_Start = 1;
                CROOverTime60s = 0;//�յ�0xaa������           
            } 
            break; 

                  
       case 0x181df456:
            CSDOverTime=0;
            if(CHMStep<=0x07)     
                CHMStep=0x07;
            break;
       case 0x081ff456:
            BEMStop = 1;
            if(CHMStep<=0x07)     
                CHMStep=0x07;
            break;
       case 0x1cecf456:
           if((fChg2bmsbyte[0]==0x11)&&(fChg2bmsbyte[5]==0x00)&&(fChg2bmsbyte[6]==0x02)&&((fChg2bmsbyte[7]==0x00)))
               FlagBRMSend = 1; //��־λ��1,��ʼ���Ͷ�֡��֤,���Ҳ�����BRM
                //if((fChg2bmsbyte[0]==0x13)&&(fChg2bmsbyte[5]==0x00)&&(fChg2bmsbyte[6]==0x02)&&((fChg2bmsbyte[7]==0x00)))
                     //BRMStep = 0;//����־λ����,���Դ��·���BRM
                     
            if((fChg2bmsbyte[0]==0x11)&&(fChg2bmsbyte[5]==0x00)&&(fChg2bmsbyte[6]==0x06)&&((fChg2bmsbyte[7]==0x00)))
                 FlagBCPSend = 1;
            //if((fChg2bmsbyte[0]==0x13)&&(fChg2bmsbyte[5]==0x00)&&(fChg2bmsbyte[6]==0x06)&&((fChg2bmsbyte[7]==0x00)))
                 //BCPStep = 0;//����־λ����,���Դ��·���BRM
            
            if((fChg2bmsbyte[0]==0x11)&&(fChg2bmsbyte[5]==0x00)&&(fChg2bmsbyte[6]==0x11)&&((fChg2bmsbyte[7]==0x00)))
                 FlagBCSSend = 1;
            
            //if((fChg2bmsbyte[0]==0x13)&&(fChg2bmsbyte[5]==0x00)&&(fChg2bmsbyte[6]==0x11)&&((fChg2bmsbyte[7]==0x00)))
                 //BCSStep = 0;//����־λ����,���Դ��·���BRM
            
            break;
      default:
            break;
    }//end of swtich
    // Clear RXF flag (buffer ready to be read)
    CAN1RFLG = 0x01;        
}

#pragma CODE_SEG DEFAULT
//******************************************************************************
//* Function name:   CAN2_RECEIVE_ISR
//* Description:     CAN2�����ж��ӳ���,������BMU����λ�������ڲ�����ͨ��
//*                  �ڲ�/ 250Bd /��չ֡ 
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
#pragma CODE_SEG NON_BANKED
interrupt void CAN2_RECEIVE_ISR(void)   //�ڲ�  BMU   250Hz
{
    unsigned char i,j;
    unsigned int temper;
    unsigned long pp=0;
    unsigned long pp1=0;
    unsigned long DBuffer[1];
    unsigned int DBuffer1[1]; 
    //unsigned long int DBuffer[1];
    // Checks for received messages
    if(!(CAN2RFLG&0x01))
    {
        CAN2RFLG = 0x01;     
        EnableInterrupts;
        return;
    }  
    
    
    pp = (unsigned long)CAN2RXIDR0<<15;  
    pp1 = (unsigned long)((CAN2RXIDR1>>5)&0x07)<<15;                              
    g_mboxID = ((unsigned long)pp<<6) | //expanded
               (pp1<<3) |
               ((unsigned long)(CAN2RXIDR1&0x07)<<15)|
               ((unsigned long)CAN2RXIDR2<<7) | 
               ((unsigned long)CAN2RXIDR3>>1);
   
    for(i=0;i<8;i++)
        g_mboxData[0][i]= *((&CAN2RXDSR0)+i);
  
    switch(g_mboxID)//
    {
        ///////
        case 0xC06D0:
           // ACTem1 = g_mboxData[0][3];
           // ACTem2 = g_mboxData[0][4];
            break;
        case 0xC01EE3F:
            if((g_mboxData[0][0]==0x55)&&(g_mboxData[0][1]==0xAA))
            {
                TestState=1;//���Ա�־λ��1,�������״̬��177
                g_BmsModeFlag = TESTSTATE;//����ģʽ
            }
            InTestToPC();
            break;
        case 0xC01EE27: //���µ����
            if(g_mboxData[0][2]==0x55)//�����̵����պ�
            {
                //�պ�����    
        	      TurnOn_INZK();//���������Ӵ���
        	      //state_group1.Bit.St_P_Relay=1;//to vcu
        	      
            }              
            if(g_mboxData[0][2]==0xaa)  
            { 
                TurnOff_INZK();//�Ͽ������Ӵ���
                //state_group1.Bit.St_P_Relay=1;//to vcu  
                                          
            }
            bmsToPcInfo552(); //���ͼ̵���״̬����ɣ�BMS���ֵ�ǰ״̬  
            break;
        
        case 0xC01EE3a: //Ԥ��
            if(g_mboxData[0][2]==0X55) 
            {
                   
        	      TurnOn_INBK();//����Ԥ��Ӵ���
        	       
        	      
            }
            if(g_mboxData[0][2]==0xAA)  
            { 
                TurnOff_INBK();//�Ͽ�Ԥ��Ӵ���
                
            }        
            break;
        case 0xC01EE3b://����
            if(g_mboxData[0][2]==0x55) 
            {   
        	      TurnOn_INHK();//���ϼ��ȽӴ���        	      
        	      
            }
            if(g_mboxData[0][2]==0xAA)  
            { 
                TurnOff_INHK();//�Ͽ����ȽӴ���
                
            } 
            break;
        case 0xC01EE3d: //���
            if(g_mboxData[0][2]==0x55) 
            {   
        	      TurnOn_INA2K();//���ϳ��Ӵ���
        	      
        	      
            }
            if(g_mboxData[0][2]==0xAA)  
            { 
                TurnOff_INA2K();//�Ͽ����Ӵ���
                
            } 
            break;        
        case 0xC01EE3e: //�����̵�������0xC01EE3a         
            if(g_mboxData[0][2]==0x55) 
            {
                //�պ��ܸ�    
        	      TurnOn_INFK();//���ϸ����Ӵ���
        	      //state_group1.Bit.St_N_Relay=1;//to vcu 
        	      
            }
            if(g_mboxData[0][2]==0xaa)  
            { 
                TurnOff_INFK();//�Ͽ������Ӵ���
                //state_group1.Bit.St_N_Relay=0;//to vcu
                
            }
            break;
        
        case 0xC0777: //�����ŵ�����
            DBuffer[0]=0;
            DBuffer1[0]=0;
            DisableInterrupts;
            Write24c64_Byte(AH_CHARGE_ADDR,(unsigned char* )DBuffer,4);
            Write24c64_Byte(AH_DISCHARGE_ADDR,(unsigned char* )DBuffer,4);
            Write24c64_Byte(ChangerTime_ADDR,(unsigned char* )DBuffer1,2);
            DisableInterrupts;
            break;
       case 0xC0888:
       
            ReadChargeDischargeAH();//��ȡ����
            //StoreChargeTime();
            ReadAHRecord();//��������0xC0AAA
                       
            break;
            
        case 0xC0999:
            //StoreChargeTime();
            break;
        case 0x18FF0A00:         
            BMNVPNflag.Bit.flag0=1;
            if(g_mboxData[0][0]==25) 
            { 
                g_mboxData[0][0]=0;
                BMNVPNflag.Bit.flag4=1;
            }
            if(g_mboxData[0][0]==35) 
            { 
                g_mboxData[0][0]=0;
                BMNVPNflag.Bit.flag6=1;
            } 
            Task13_Vpn_Value_Calibrate();       //У׼�ܵ�ѹ       
            break;
        case  0x18FF0A01:
            Vpn_K1 = (((unsigned int)g_mboxData[0][0]&0x00ff)<<8) | g_mboxData[0][1];
            Vpn_B1 = (((unsigned int)g_mboxData[0][2]&0x00ff)<<8) | g_mboxData[0][3];
            KB_DATA_SAVE();
            break;
        case  0x18FF0A02:
            Vpn_K2 = (((unsigned int)g_mboxData[0][0]&0x00ff)<<8) | g_mboxData[0][1];
            Vpn_B2 = (((unsigned int)g_mboxData[0][2]&0x00ff)<<8) | g_mboxData[0][3];
            KB_DATA_SAVE();
            break;
        case  0x18FF0A03:
            Vpn_K3 = (((unsigned int)g_mboxData[0][0]&0x00ff)<<8) | g_mboxData[0][1];
            Vpn_B3 = (((unsigned int)g_mboxData[0][2]&0x00ff)<<8) | g_mboxData[0][3];
            KB_DATA_SAVE();
            break;
        
        case 0x18ff6200:  //�յ���ȡ������Ϣ������
            g_errorRecordRead_flag=1;  
            break;
        case 0x18ff6201: //������й�����Ϣ
            g_errorCounter=0;
            temper = g_errorCounter;
            Write24c64_Byte(ERROR_COUNT_ADDR,(unsigned char *)&temper,2);//���¹��ϼ����� 
            temper = 0;
            Read24c64_Byte(ERROR_COUNT_ADDR,(unsigned char *)&temper,2);
            g_errorCounter = temper;
            break;
        
        case 0x0a0218fb://����BOOT����
            DFlash_Erase_Sector(0x0000); //�����Ȳ���
            DataBuffer[0] = 0xaaaa;
            DFlash_Write_Word(0x0000);//д��boot��־0xaaaa,��boot������������־����ִ��bootloader���س��򣬷�֮����ִ��Ӧ�ó���                 
            COPCTL = 0x07;        //enable watchdog
            ARMCOP = 0x00;        //feed 0 to watch dog for reset 
            BootState = 1;
            break;
        case 0x0c14ee00:      //��ȡʱ��
        case 0xc01ee14:       //����ʱ��
        case 0xC01ee15:       //SOC����
        case 0xC01ef15:       //������ʾSOC
        case 0xC01ee16:       //ʣ������
        case 0xC01ee17:        //BMU����
        case 0xC01ee18:        //����汾��
        case 0xC01EE28:         //����ϵͳ����������Ϣfrom ��λ��
        case 0xC01EE29:         //����ϵͳ����������Ϣfrom ��λ��
        case 0xC01EE2a:         //����ϵͳ����������Ϣfrom ��λ��
        case 0xC01EE2b:         //����ϵͳ����������Ϣfrom ��λ��
        case 0xC01EE26:
        case 0xC01EE8F: 
        case 0xC01EE9F:
            ParameterSetting();
            break;
        default:
            Int_Flag |= 0x08;
            BMU_Processure();
            break;  
    }//end of switch      	 		
    // Clear RXF flag (buffer ready to be read)
    CAN2RFLG = 0x01;       
  
}
#pragma CODE_SEG DEFAULT

//*******************************************
//*******************************************