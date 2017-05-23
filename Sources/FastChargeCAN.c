//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : FastChargeCAN.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2016.1.12
//* Description        : ���ļ�������ֱ�����CAN�����б�������
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "BMS20.h"
//********************************************************************************
//*******************************************************************************
unsigned char REQ_TurnON_Insulation = 0;  //��Ե��������
unsigned char Flag_TurnON_Insulation = 0; //��Ե����λ
unsigned char BEMError1=0;
unsigned char BEMError2=0;
unsigned char BEMError3=0;
unsigned char BEMError4=0xf0;
unsigned char PGN[3] = 0;
//**********************************************************************************
//**********************************************************************************
//*******�����Ϣ�ӳ���**********/////////
//*******���Ĺ���**********/////////
//**********************************************************************************
//**********************************************************************************
//******************************************************************************
//* Function name:   J1939_TP_CM_Abort
//* Description:     ��������
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void J1939_TP_CM_Abort(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
	  mg.data[0]=0xff;   
	  mg.data[1]=0xff; 
	  mg.data[2]=0xff;
	  mg.data[3]=0xff;
	  mg.data[4]=0xff;   
	  mg.data[5]=PGN[0]; 
	  mg.data[6]=PGN[1];
	  mg.data[7]=PGN[2];
	  
    mg.id= 0x1cec56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;   
	  //MSCAN1SendMsg(mg);
} 

//******************************************************************************
//* Function name:   cpuToCHMBRM
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBHM(void)
{
    struct can_msg mg;
    char tt=100;
    unsigned int buff;
    mg.RTR= FALSE;  
    mg.len = 2;
    mg.prty = 0;
    
    buff=HIGHEST_ALLOWED_CHARGE_V*10;
    
    mg.data[0] = buff;     //����������ѹ���ֽ�
    mg.data[1] = buff>>8;  //����������ѹ���ֽ�
	  
	  mg.id= 0x182756f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--; 
	  //MSCAN1SendMsg(mg);
}
//******************************************************************************
//* Function name:   cpuToCHMBRM
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRM(void)
{
    struct can_msg mg;
    char tt=100;
    unsigned char Num = 6;
    unsigned char ByteNum = 0x29;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    if(DC_Vesion==2)
    {
        Num = 7;
        ByteNum=0x31;
    }
    
    
    mg.data[0] = 0x10;  //�����֣�16
    mg.data[1] = ByteNum;  //������Ϣ��С,49byte
    mg.data[2] = 0x00;  //������Ϣ��С
    mg.data[3] = Num;  //ȫ�����ݰ�����Ŀ
    mg.data[4] = 0xff;//������SAE�趨ʹ�ã����ֽ�Ӧ��ΪFF
	  mg.data[5] = 0x00;//��װ�����ݵĲ���Ⱥ��� ����Ӧ��PGN�ţ�0x000200
    mg.data[6] = 0x02;//��װ�����ݵĲ���Ⱥ��� ����Ӧ��PGN�ţ�0x000200
	  mg.data[7] = 0x00;//��װ�����ݵĲ���Ⱥ��� ����Ӧ��PGN�ţ�0x000200
	  
	  mg.id= 0x1cec56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--; 
	  //MSCAN1SendMsg(mg);
} 
//******************************************************************************
//* Function name:   cpuToCHMBRMDATA1
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRMDATA1(void)
{
    struct can_msg mg;
    unsigned int buff;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x01;
    mg.data[1] = 0x01;
    mg.data[2] = 0x01;  //BMSͨ��Э��汾��
    mg.data[3] = 0x00;  
    mg.data[4] = CELL_TYPE;//������� 
    
    buff = (unsigned int)(C*10);//�������ϵͳ�����:120Ah
	  mg.data[5] = (unsigned char)buff;  
    mg.data[6] = buff>>8;
    
    buff = SYS_NOMINAL_V*10;//576V
	  mg.data[7] = (unsigned char)buff;//�������ϵͳ���ѹ
	  
	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
} 
//******************************************************************************
//* Function name:   cpuToCHMBRMDATA2
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRMDATA2(void)
{
    struct can_msg mg;
    unsigned int buff;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x02;
    
    buff = SYS_NOMINAL_V*10;//�������ϵͳ���ѹ 
    mg.data[1] = buff>>8;
    mg.data[2] = 0xff; 
    mg.data[3] = 0xff; 
    mg.data[4]= 0xff;
	  mg.data[5]= 0xff;
    mg.data[6]= 0xff;
	  mg.data[7]= 0xff;

	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
} 
//******************************************************************************
//* Function name:   cpuToCHMBRMDATA3
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRMDATA3(void)
{
    struct can_msg mg;
    char tt=100;
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x03;
    mg.data[1] = 0xff;
    mg.data[2] = 0xff; 
    mg.data[3] = 0xff; 
    mg.data[4]= 0xff;
	  mg.data[5]= 0xff;
    mg.data[6]= 0xff;
	  mg.data[7]= 0xff;

	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
} 
//******************************************************************************
//* Function name:   cpuToCHMBRMDATA4
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRMDATA4(void)
{
    struct can_msg mg;
    char tt=100;
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x04;
    mg.data[1] = 0xff;
    mg.data[2] = 0x01; 
    mg.data[3] = 0xff; 
    mg.data[4]= 0xff;
	  mg.data[5]= 0xff;
    mg.data[6]= 0xff;
	  mg.data[7]= 0xff;

	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
} 
//******************************************************************************
//* Function name:   cpuToCHMBRMDATA5
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRMDATA5(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x05;
    mg.data[1] = 0xff;
    mg.data[2] = 0xff; 
    mg.data[3] = 0xff; 
    mg.data[4]= 0xff;
	  mg.data[5]= 0xff;
    mg.data[6]= 0xff;
	  mg.data[7]= 0xff;

	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
} 
//******************************************************************************
//* Function name:   cpuToCHMBRMDATA6
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRMDATA6(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x06;
    mg.data[1] = 0xff;
    mg.data[2] = 0xff; 
    mg.data[3] = 0xff; 
    mg.data[4]= 0xff;
	  mg.data[5]= 0xff;
    mg.data[6]= 0xff;
	  mg.data[7]= 0xff;

	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
}
//******************************************************************************
//* Function name:   cpuToCHMBRMDATA7
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRMDATA7(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x07;
    mg.data[1] = 0xff;
    mg.data[2] = 0xff; 
    mg.data[3] = 0xff; 
    mg.data[4]= 0xff;
	  mg.data[5]= 0xff;
    mg.data[6]= 0xff;
	  mg.data[7]= 0xff;
	  
	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
}  
//******************************************************************************
//* Function name:   cpuToCHMBCP
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBCP(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x10;//CW
    mg.data[1]=  0x0d;//ByteL
	  mg.data[2]=  0x00;//ByteH
    mg.data[3]=  0x02;//Pack
	  mg.data[4]=  0xff;//Void
    mg.data[5]=  0x00;//PGN 
	  mg.data[6]=  0x06;//PGN
    mg.data[7]=  0x00;//PGN 

    mg.id= 0x1cec56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
 }
 //******************************************************************************
//* Function name:   cpuToCHMBCPDATA1
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
 void cpuToCHMBCPDATA1(void)
{
    struct can_msg mg;
    unsigned int buff;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x01;
    buff = (unsigned int)(HIGHEST_ALLOWED_CHARGE_CV*100);
    mg.data[1]= (unsigned char)buff;//��������������ѹ
	  mg.data[2]= buff>>8;//��������������ѹ
	  
	  buff = (unsigned int)((400-HIGHEST_ALLOWED_CHARGE_A)*10);//�Ѿ�����0.75��
    mg.data[3]= (unsigned char)buff;//�����������������ֽ�
	  mg.data[4]= buff>>8;//��������������������ֽ�
	  
    buff = SYS_KWH*10;
    mg.data[5]= (unsigned char)buff;//�������ϵͳ����� 
	  mg.data[6]= buff>>8;//�������ϵͳ�����
	  
	  buff = (unsigned int)(HIGHEST_ALLOWED_CHARGE_V*10);
    mg.data[7]= (unsigned char)buff;//������������ϵͳ �ܵ�ѹ���ֽ�

    mg.id= 0x1ceb56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
 }
 //******************************************************************************
//* Function name:   cpuToCHMBCPDATA2
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
 void cpuToCHMBCPDATA2(void)
{
    struct can_msg mg;
    unsigned int buff;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    mg.data[0] = 0x02;

    buff = (unsigned int)(HIGHEST_ALLOWED_CHARGE_V*10);
	  mg.data[1]= buff>>8;//������������ϵͳ �ܵ�ѹ���ֽ�
	  mg.data[2] = 105;// the allowed highest temperature = 105-50=55 C
	  
	  buff = (unsigned int)(g_SysSOC*1000); 
	  mg.data[3]= (unsigned char)buff;//SOC
	  mg.data[4]= buff>>8;
	  
	  buff = (unsigned int)(g_SystemVoltageV0*10);
	  mg.data[5]= (unsigned char)buff;//ϵͳ�ܵ�ѹ���ֽ�
	  mg.data[6]= buff>>8; //ϵͳ�ܵ�ѹ���ֽ�
	  mg.data[7]= 0xff;
	  
	  mg.id= 0x1ceb56f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--; 
	  //MSCAN1SendMsg(mg);
 }
//******************************************************************************
//* Function name:   cpuToCHMBRO
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBRO(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 1;
    mg.prty = 0;
    
    if((BROErrorAA==0)&&(Flag_InsulationState == 1))   //�Ҿ�Ե�������ٷ�AA
    //if(BROErrorAA==0)//for test
    {
        mg.data[0] = 0xaa;
        Flag_TurnON_Insulation = 1;//�ɹ��󣬽���Ե���Ͽ�
    }
    //else if(BROErrorAA==1)    //��û�о�Ե״̬���ſ�
    else    
        mg.data[0] = 0x00;
    
	  mg.id= 0x100956f4;
	  
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
}
//******************************************************************************
//* Function name:   cpuToCHMBCL
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBCL(void)
{
    struct can_msg mg;
    unsigned int buff;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 5;
    mg.prty = 0;
    
    buff = (unsigned int)(g_AskDCVol*10);
	  mg.data[0]= (unsigned char)buff;//��ѹ����
	  mg.data[1]= buff>>8;
	  
    buff = (unsigned int)((400-g_AskDCCur)*10);
	  mg.data[2]= (unsigned char)buff;//��������
	  mg.data[3]=  buff>>8;
    mg.data[4] = m_chmmode;//��������
	  
	  mg.id= 0x181056f4;
	  while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  

}
//******************************************************************************
//* Function name:   cpuToCHMBCS
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBCS(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
	  mg.data[0]= 0x10;//
	  mg.data[1]= 0x09;	
	  mg.data[2]= 0x00;//
  	mg.data[3]= 0x02;//  
	  mg.data[4]= 0xff;// 
	  mg.data[5]= 0x00;//
	  mg.data[6]= 0x11;	  
    mg.data[7]= 0x00;
    
    mg.id= 0x1cec56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
} 
//******************************************************************************
//* Function name:   cpuToCHMBCSDATA1
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBCSDATA1(void)
{
   struct can_msg mg;
    unsigned int buff;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    
    
	  mg.data[0]= 0x01;
	  buff = (unsigned int)(g_SystemVoltageV0*10);//����鵱ǰ��ѹ���ֽ� 
	  mg.data[1]= (unsigned char)buff;         //����鵱ǰ��ѹdi�ֽ� 
    mg.data[2]= buff>>8;//����鵱ǰ�������ֽ� 
    
	  buff = (unsigned int)((g_BatSysTotalCur+400)*10);
  	mg.data[3]= (unsigned char)buff;//����鵱ǰ�������ֽ� 
    mg.data[4]= buff>>8;//����鵱ǰ�������ֽ� 
    
	  buff = (unsigned int)(g_CellHighestVol*100);	   
	  mg.data[5]= (unsigned char)buff;//��ص�����ߵ�ѹ���ֽ�
	  mg.data[6]= buff>>8;//��ص�����ߵ�ѹ���ֽ�
	  
	  buff = (unsigned int)(g_SysSOC*100); 
	  mg.data[7]= (unsigned char)buff;//SOC at present

    mg.id= 0x1ceb56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
}
//******************************************************************************
//* Function name:   cpuToCHMBCSDATA2
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBCSDATA2(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 8;
    mg.prty = 0;
    if((g_BatSysTotalCur<=-5)&&(g_SysSOC<0.992))
        DCLeftTime=(unsigned int)((Q2*(1-g_SysSOC)*60)/(-g_BatSysTotalCur));
    else if(g_SysSOC>=0.992)
        chargeRemainderTime=2;
    chargeRemainderTime=DCLeftTime*60;
	  mg.data[0]= 0x2;//
	  mg.data[1]=(unsigned char)DCLeftTime;//	
	  mg.data[2]= DCLeftTime>>8;//
  	mg.data[3]= 0xff;//
	  mg.data[4]= 0xff;// 
	  mg.data[5]= 0xff;// 
	  mg.data[6]= 0xff;// 	  
    mg.data[7]= 0xff;//
    
    mg.id= 0x1ceb56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;

  

} 
//******************************************************************************
//* Function name:   cpuToCHMBSM
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBSM(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 7;
    mg.prty = 0;
   
	  mg.data[0]= 0x01;
	  mg.data[1]= g_BatHighestTemp+10;	
	  mg.data[2]= 0x01;
  	mg.data[3]= g_BatLowestTemp+10;	   
	  mg.data[4]= 0x01;
	  mg.data[5]= fasterror11;
	  mg.data[6]= fasterror12;
    mg.id= 0x181356f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
}
//******************************************************************************
//* Function name:   cpuToCHMBST
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
//void cpuToCHMBMV(void); //��ѡ������ѹ
//void cpuToCHMBMT(void); //��ѡ������¶�
//void cpuToCHMBSP(void); //��ѡ��¶�
void cpuToCHMBST(void)  
{    
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 4;
    mg.prty = 0;
    
	  mg.data[0]= fastend1;
	  mg.data[1]= fastend2;
	  mg.data[2]= fastend3;
	  mg.data[3]= fastend4;
	  
   
    mg.id= 0x101956f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
  
} 
//******************************************************************************
//* Function name:   cpuToCHMBSD
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBSD(void)
{
    struct can_msg mg;
    unsigned int buff;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 7;
    mg.prty = 0;
    
	  mg.data[0]= (unsigned char)(g_SysSOC*100);//soc

    buff = (unsigned int)(g_CellLowestVol*100);	   
	  mg.data[1]= (unsigned char)buff;//��ص�����ߵ�ѹ���ֽ�
	  mg.data[2]= buff>>8;//��ص�����ߵ�ѹ���ֽ�
	  
	  buff = (unsigned int)(g_CellHighestVol*100);	   
	  mg.data[3]= (unsigned char)buff;//��ص�����ߵ�ѹ���ֽ�
	  mg.data[4]= buff>>8;//��ص�����ߵ�ѹ���ֽ�
	  
	  mg.data[5]= g_BatLowestTemp+10;//�������¶�-40+50	  
	  mg.data[6]= g_BatHighestTemp+10;//�������¶� 
	  
    mg.id= 0x181c56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
} 
//******************************************************************************
//* Function name:   cpuToCHMBEM
//* Description:     
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void cpuToCHMBEM(void)
{
    struct can_msg mg;
    char tt=100;
    
    mg.RTR= FALSE;  
    mg.len = 4;
    mg.prty = 0;
    
	  mg.data[0]=BEMError1;   
	  mg.data[1]=BEMError2; 
	  mg.data[2]=BEMError3;
	  mg.data[3]=BEMError4;
	  
    mg.id= 0x081e56f4;
    while((!MSCAN1SendMsg(mg))&&(tt>0))
        tt--;  
	  //MSCAN1SendMsg(mg);
} 
//***********************************************************************
//************************************************************************
//*************************the end*************************************
//************************************************************************