//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : C50ES_FP
//* File Name          : InitBMS.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2014.5.7
//* Description        : ���ļ�����������Ŀϵͳ��ʼ��������SOC��ʼ����������ʼ���������ж����ȼ�����
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h" 
//
float g_defaultSysParameters[ParamNUMBER] =
{
    0.7,//SOC ʵ��ֵ
    189.0,//��������
    3.0,//������ͺ� 
    37.0, //�����������  WHOLE_CAPACITY
    2.0,//BMU����BMU_NUMBER

    0.1,//�����ѹ����ֵDIFFERENCE_SINGLE_V
    15.0,//����¶Ⱦ���ֵDIFFERENCE_SINGLE_T
    3.2,//���⿪����ѹ
    4.3,//����رյ�ѹ
    0.95, //soc ��

    0.98, //soc ����
    0.15, //soc ��
    0.10,//SOC ����
    346.0,//�ܵ�ѹֵWHOLE_VOLTAGE
    355.0,//�ܵ�ѹ����

    259.0,   //�ܵ�ѹ��
    235.0,//�ܵ�ѹ����
    3.65,//�����ѹֵO_VOLTAGE
    3.7,//�����ѹ����
    2.75,//�����ѹֵ��L_VOLTAGE

    2.45, //�����ѹ����
    50.0,//����ֵO_TEMPERATURE
    55.0, //�¶ȼ���
    0.0,//�¶ȹ���ֵL_TEMPERATURE
    -25,  //�¶ȼ���

    0.25,  //��ѹһ���Բ�
    0.5, //��ѹһ���Լ���
    20.0,  //�¶�һ���Բ�
    25.0,//�¶�һ���Լ���
    320.0,//����ֵ����

    403,  //���������˵�ѹ
    120.0,//������������
    1000.0,//������������ʱ��  ��λmin
    120.0,//�������ŵ����
    1000.0, //���ŵ��������ʱ��  ��λmin

    40.0, //��Ե�������ֵ ��λMŷ
    200.0,// ��Ե�����ֵ ��λMŷ

    96.0// ���ܳ���100
};

unsigned int g_oldTime[7];
unsigned char g_BmsModeFlag; //3:�����2:������ 1:�ŵ�
unsigned char OCVState = 0;//0:OCVû�з���,1��OCV�Ѿ�����
//******************************************************************************
//* Function name:   delay
//* Description:     ��ʱ�ӳ���              
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void delay(unsigned int t) 
{ 
    while(t--); 
}
//******************************************************************************
//* Function name:   InitialBMS
//* Description:     BMSϵͳ�ϵ������ʼ��             
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void InitialBMS(void)
{
    unsigned char SetTime[7];
			
	  TurnOff_ALL();// Turn off all relays. then check their state.
	  
	  TurnOn_CC2();//12vϵͳ�򿪣�24V�ر�///////////////////////////////////////////////////////////////////////////////test///////////////////
	  
	  g_sysPara[PARA_BMU_NUMBER]=BMU_NUMBER;
	  g_sysPara[PARA_BATCELLNUMBER]=BATTERYCELLNUMBER;    //��������
	  g_sysPara[PARA_BATTYPE]=CELL_TYPE;       //�������
	  if(ENDFLAG!=ReadEndFlag())   //ENDFLAG=98 //�Ƿ�Ҫ���س���������
	  {
		    InitDefaultParam();
		    //����ʱ��
		    SetTime[0]=1;//��
		    SetTime[1]=21;//��
		    SetTime[2]=14;//ʱ
		
		    SetTime[3]=3;//����
		    SetTime[4]=18;//��
		    SetTime[5]=6;//��
		    SetTime[6]=12;//��
		    I2CWriteDate(SetTime);  //���ó�ʼʱ��
	  }
     
	  LoadParamter();   //ϵͳ������ʼ��
	  StoreParameter();
	  
	  KB_DATA_RECALL();//���þ�Ե����ϵ����Ϊ��Ե��׼����

	  g_errorCounter=ReadErrorIndex(); //������ǰ���ϼ�¼����
	  //g_errorCounter=0;
	    
	  parametersClean();  //һЩȫ�ֱ�������
	  
	  I2CReadDate();  //��ȡϵͳʱ��
	  g_oldTime[0] = CurrentTime[0];  //��
	  g_oldTime[1] = CurrentTime[1];  //��

    if(StoreAHState==1)
        ReadChargeDischargeAH();//�����ۻ���ŵ��AH����
   // state_group3.Bit.St_BMS_Operation = 1;//��ʼ��״̬
}
//******************************************************************************
//* Function name:   InitialSoc
//* Description:     SOC�ϵ��ʼ������ȡ������24c64�е�SOCֵ������ʣ������        
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void InitialSoc(void)
{		
    if(OCVState == 0)//���û�н���OCV����,�������һ�ε�ֵ
    {      
        g_socValue = ReadOutSocStoreValue(); //SOCʵ��ֵ����������ʾֵ    
        g_ActalRatedCapty= ReadOutQ1StoreValue();//��ȡQ1ֵ
    }
    //��OCVState==1,Q1:g_ActalRatedCapty��g_socValue��OCV�����и�ֵ
    g_SysSOC = ReadOutCanSocStoreValue();//SOC��ʾֵ
    First_g_socValue=g_socValue;
    StoreAHSOC=g_socValue;
    g_SysSOC_Start=g_SysSOC;
	  
	  if(g_socValue<0)
	      g_socValue = 0.22;	   
	  if(g_SysSOC<0)
	      g_SysSOC = 0.44;
	  
	  g_originalCapacity = SYS_NOMINAL_AH;
	  if(g_ActalRatedCapty>=g_originalCapacity)
	      g_ActalRatedCapty=g_originalCapacity;
	  Q2 = Q2nominalCalculate(g_ActalRatedCapty); //����������
	  if(Q2>=g_ActalRatedCapty)
	      Q2=g_ActalRatedCapty;
	  g_leftEnergy = g_socValue*(g_ActalRatedCapty*3600);  //ʣ������(�ϵ�ʱ������	  
	  g_energyOfUsed = 0;      
	 
}
//******************************************************************************
//* Function name:   ReadEndFlag
//* Description:     ��һ���ϵ��־λ��ȡ����     
//* EntryParameter : None
//* ReturnValue    : ����0xffff��ʾ��һ�Σ� !=0xffff,��ʾ�ǵ�һ��
//******************************************************************************
float ReadEndFlag(void)
{
		//float flag[1];
  	unsigned int	Endflag[2];
  	
    Read24c64_Byte(ENDFLAG_ADDR,(unsigned char* )Endflag,4); 
  	
  	if((Endflag[0]==0xffff)&&(Endflag[1]!=0xffff))
  	    Endflag[0] = Endflag[1];

  	return (Endflag[0]);
}
//******************************************************************************
//* Function name:   InitDefaultParam
//* Description:     ������Ĭ�ϲ���д��24c65  
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void InitDefaultParam(void)
{	
    DataBuffer[0] = ENDFLAG;
    DataBuffer[1] = ENDFLAG;
    Write24c64_Byte(ENDFLAG_ADDR,(unsigned char* )DataBuffer,4);//write the endflag into 24c64 at 0x0100 
  	g_defaultSysParameters[PARA_ENDFLAG]= ENDFLAG;	
  	Write24c64_Byte(ParaBaseAddr,(unsigned char* )g_defaultSysParameters,ParamNUMBER*4);//д���ʼ�������ռ�24c64 0x0000
}

//******************************************************************************
//* Function name:   Interrupt_Priority_Set
//* Description:     �ж����ȼ����ú���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void Interrupt_Priority_Set(void)
{     
    
    INT_CFADDR=0xA0;     
    INT_CFDATA5=0x03;     //CAN1
    
    INT_CFADDR=0xB0;     
    INT_CFDATA1=0x04;     //CAN0
    
    INT_CFADDR=0x70;     
    INT_CFDATA5=0x05;     //pit 
    
    INT_CFADDR=0xF0;     //RIT
    INT_CFDATA0=0x06;
         
    INT_CFADDR=0xD0;      //ad0
    INT_CFDATA1=0x07;
    
    
}

//************************************************************************
//************************************************************************
//************************************************************************
//************************************************************************