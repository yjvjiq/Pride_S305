//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : C50ES_FP
//* File Name          : ProcessBMU.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2014.5.7
//* Description        : ���ļ�ר�����ڴ�����յ���BMU���ݣ��Ӷ��ó����弫ֵ�͵���ֵ
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "derivative.h" /* include peripheral declarations */
#include "BMS20.h" 

unsigned char InBoxMaxV[BMU_NUMBER]={0};
unsigned char InBoxMinV[BMU_NUMBER]={0};


unsigned char g_group;  //BMU1 ��ţ� ��0~15
unsigned int g_singleCellVoltage[BMU_NUMBER][SIX802_NUMBER][CELL_NUMBER];  //BMU1��, 6802���飩��, �����غ�
unsigned char g_singleCellTemperature[BMU_NUMBER][SIX802_NUMBER][Tem_NUMBER];//BMU1��, 6802���飩��, �����غ�

//float g_CellHighestVol=0; //������ߵ�ѹ
//float g_CellLowestVol=0;  //������͵�ѹ
float g_averageVoltage;       //ƽ�������ѹ
//float g_SystemVoltageV0;      //ϵͳ��ѹ=�����ѹ�ۼ��ܵ�ѹ
//unsigned char g_BatHighestTemp=0; //��������¶�
//unsigned char g_BatLowestTemp=0;  //��������¶�
unsigned char g_averageTemperature; //����ƽ���¶�
unsigned char Tavg; //��оƽ���¶�
unsigned char LowVolNum=1;
unsigned char HighVolNum=1;
unsigned char HighTemNum=1;
unsigned char LowTemNum=1;
unsigned char BoxOverFlag=0;

unsigned char g_bmu2_number_v[BMU_NUMBER];
unsigned char g_cell_number_v[BMU_NUMBER][5];
unsigned char g_bmu2_number_t[BMU_NUMBER];
unsigned char g_cell_number_t[BMU_NUMBER][5];

//unsigned long recogBMUtoBMSmessage;//BMS BMUͨ�ű�ʶ��Ϣ
unsigned char recogBMStoBMUflag = 0;//BMS��BMU��ʶ�ɹ���־
unsigned int g_CellVol[48][4];             //�����ѹ
unsigned int g_CellTemp[4][8];            //�����¶�
unsigned char BatBoxHighestTemp[BMU_NUMBER];         //ÿ������¶�
unsigned char BatBoxLowestTemp[BMU_NUMBER];         //ÿ������¶�
	
//************************************************************************
//************************************************************************
//************************************************************************
//************************************************************************
unsigned long g_circleFlag = 0; //һ��ѭ����ɵı�־
unsigned long g_configFlag = 0;//�յ�������Ϣ��־�������ж�BMU������6805�����͵������ 

//******************************************************************************
//* Function name:   BMU_initial
//* Description:     �ϵ����BMU�������ݣ�ȷ�������¶Ⱥ͵�ѹ��û����
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMU_initial(void) 
{
    unsigned int t=0;
    
    //***********BMU�Լ�*******************************************       
    while((!bmuProcess2())&&(t<65000))    	        
    {        
        t++;      
        if(t>=60000) //��ʱ���ϱ���
        {
            
            fault_pc552_Byte6.Bit.F0_InterComFault=1;
            //BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //���������� 
                     
        }/////end of BMUͨ���ж�  
        else 
        {            
            //BMS9_Byte7.Bit.F4_BzerAlarm = 0;
            fault_pc552_Byte6.Bit.F0_InterComFault=0; 
            
        }  
        _FEED_COP();   //2s�ڲ�ι�ڹ�����ϵͳ��λ 
    }

}
//******************************************************************************
//* Function name:   BMU_Processure
//* Description:     �Խ��յ���BMU�����ѹ���¶Ƚ��н���
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMU_Processure(void)
{
    unsigned long framID;
	  unsigned int i,boxNumber=0;
	   
	  if((Int_Flag&0x08)==0x08) //�����յ�1�����ݣ��������ݴ���
	  {
  		  Int_Flag &= 0xf7;//���жϱ�־		
  		  		  			  		
  	 	  g_group = 0;  		

  			framID = g_mboxID;      
  			g_group = framID&0x000000ff;
  			g_group--;

  			framID = framID>>4;
  			framID = framID & 0x03ffffff;

  			switch(framID)  //��������
  			{
  			    case 0x018FF110://BMU��ʶ��Ϣ��Ӳ���汾������汾��ͨѶЭ��汾�ȣ�0x18FF110x
  				 	    //if(recogBMUtoBMSmessage != bufL)
  					    //	recogBMStoBMUflag = 0; //��ʶʧ��
  					    //else
  						  recogBMStoBMUflag = 1; //��ʶ�ɹ�								
  					    break;	  
  				  case 0x018FF130://���������Ϣ1��6805�ĸ�������ز�ѹ����������������CC2
  				      switch(g_group) 
  				      {
      				      case 0:
      				          g_configFlag |= 0x00000001;
      				          break;
      				      case 1:
      				          g_configFlag |= 0x00000010;
      				          break;
      				      case 2:
      				          g_configFlag |= 0x00000100;
      				          break;
      				      case 3:
      				          g_configFlag |= 0x00001000;
      				          break;
      				      case 4:
      				          g_configFlag |= 0x00010000;
      				          break;
      				      case 5:
      				          g_configFlag |= 0x00100000;
      				          break;
      				      case 6:
      				          g_configFlag |= 0x01000000;
      				          break;
      				      case 7:
      				          g_configFlag |= 0x10000000;
      				          break;
      				          				  
  				      }
  					    g_bmu2_number_v[g_group] = g_mboxData[boxNumber][0]&0x07; //&0x07;//BMU1��6802�ĸ���
      					g_bmu2_number_t[g_group] = (g_mboxData[boxNumber][0]&0x70)>>4; //&0x07;
                
      					g_cell_number_v[g_group][0]=g_mboxData[boxNumber][1]&0x0f;
      					g_cell_number_t[g_group][0]=(g_mboxData[boxNumber][1]&0xf0)>>4;

      					g_cell_number_v[g_group][1]=g_mboxData[boxNumber][2]&0x0f;
      					g_cell_number_t[g_group][1]=(g_mboxData[boxNumber][2]&0xf0)>>4;

      					g_cell_number_v[g_group][2]=g_mboxData[boxNumber][3]&0x0f;
      					g_cell_number_t[g_group][2]=(g_mboxData[boxNumber][3]&0xf0)>>4;

      					g_cell_number_v[g_group][3]=g_mboxData[boxNumber][4]&0x0f;
      					g_cell_number_t[g_group][3]=(g_mboxData[boxNumber][4]&0xf0)>>4;

      					g_cell_number_v[g_group][4]=g_mboxData[boxNumber][5]&0x0f;	
      					g_cell_number_t[g_group][4]=(g_mboxData[boxNumber][5]&0xf0)>>4;	
      					
      																		
  					    break;
  				  case 0x018FF140://���������Ϣ3��6802�ĸ�������ز�ѹ����������������CC3
  					    break;
  			    case 0x018FF160:   //�ж������ź� �Ƿ������һ������
      			    switch(g_group) 
      				  {      				    
          			    case 0:
          			        g_circleFlag |= 0x00000001;
          			        break;
          			    case 1:
          			        g_circleFlag |= 0x00000010;
          			        break;
          			    case 2:
          			        g_circleFlag |= 0x00000100;
          			        break;
          			    case 3:
          			        g_circleFlag |= 0x00001000;
          			        break;
          			    case 4:
          			        g_circleFlag |= 0x00010000;
          			        break;
          			    case 5:
          			        g_circleFlag |= 0x00100000;
          			        break;
          			    case 6:
          			        g_circleFlag |= 0x01000000;
          			        break;
          			    case 7:
          			        g_circleFlag |= 0x10000000;
          			        break;
          			    default:
          			        break;      			  
      				  }
      				  //State_Box_Online=g_circleFlag;
  			        break;
  				  //******group#1*******
  				  //********************
  				  case 0x018FF210://��ţ�1����صĲ�ѹֵ��1���ɲɼ�4·��ѹ:
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][0][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF220://��ţ�1����صĲ�ѹֵ��2���ɲɼ�4·��ѹ:
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][0][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF230://��ţ�1����صĲ�ѹֵ��3���ɲɼ�4·��ѹ��  				  
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][0][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      } 
      					break;  			  		
  				  case 0x018FF370://��ţ�1����ص�Ƿѹ��ѹ��־
      					//g_groupUVflag[g_group][0] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][0] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;  				
  				  case 0x018FF410://��ţ�1����صĲ���ֵ��1����ɼ?·�¶ȣ�
      					for(i=0;i<2;i++)
      					    g_singleCellTemperature[g_group][0][i]= g_mboxData[boxNumber][i];
      					break; 	
  				  //******** group#2**********
  				  //**************************
  				  case 0x018FF240://��ţ�2����صĲ�ѹֵ��1���ɲɼ�4·��ѹ��
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][1][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF250://��ţ�2����صĲ�ѹֵ��2���ɲɼ�4·��ѹ��
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][1][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF260://��ţ�2����صĲ�ѹֵ��3���ɲɼ�4·��ѹ��
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][1][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;  					
  				  case 0x018FF380://��ţ�2����ص�Ƿѹ��ѹ��־
      					//g_groupUVflag[g_group][1] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][1] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;     			  
  				  case 0x018FF420://��ţ�2����صĲ���ֵ��1���ɲɼ�8·�¶ȣ�  				 
  				      for(i=0;i<2;i++)
  					        g_singleCellTemperature[g_group][1][i]= g_mboxData[boxNumber][i];
  					    break;
  				  //******group#3********
  				  //*********************
  				  case 0x018FF270://��ţ�3����صĲ�ѹֵ��1���ɲɼ�4·��ѹ��
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][2][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF280://��ţ�3����صĲ�ѹֵ��2���ɲɼ�4·��ѹ��
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][2][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF290://��ţ�3����صĲ�ѹֵ��3���ɲɼ�4·��ѹ��
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][2][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  					
  				  case 0x018FF390://��ţ�3����ص�Ƿѹ��ѹ��־
      					//g_groupUVflag[g_group][2] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][2] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break; 					
  				  case 0x018FF430://��ţ�3����صĲ���ֵ��1����ɼ?·�¶ȣ�  				
      					for(i=0;i<2;i++)
      					    g_singleCellTemperature[g_group][2][i]= g_mboxData[boxNumber][i];
      					break;  	
  				  //*******group#4*******
  				  //*********************
  				  case 0x018FF2a0://��ţ�4����صĲ�ѹֵ��1���ɲɼ�4·��ѹ��
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][3][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2b0://��ţ�4����صĲ�ѹֵ��2���ɲɼ�4·��ѹ��
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][3][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2c0://��ţ�4����صĲ�ѹֵ��3���ɲɼ�4·��ѹ�� 
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][3][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF3a0://��ţ�4����ص�Ƿѹ��ѹ��־  				  
      					//g_groupUVflag[g_group][3] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][3] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;  				
  				  case 0x018FF440://��ţ�4����صĲ���ֵ��1���ɲɼ�8·�¶�  				 
      				  for(i=0;i<2;i++)
      					    g_singleCellTemperature[g_group][3][i]= g_mboxData[boxNumber][i];
      					break;
  				  //******group#5********
  				  //*********************
  				  case 0x018FF2d0://��ţ�5����صĲ�ѹֵ��1���ɲɼ�4·��ѹ��	
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][4][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2e0://��ţ�5����صĲ�ѹֵ��2���ɲɼ�4·��ѹ��
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][4][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2f0://��ţ�5����صĲ�ѹֵ��3���ɲɼ�4·��ѹ��  
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][4][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }

      					break;  					
  				  case 0x018FF3b0://��ţ�5����ص�Ƿѹ��ѹ��־
      					//circleFlag |= 0x10000000;
      					//g_groupUVflag[g_group][4] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][4] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;  					
  				  case 0x018FF450://��ţ�5����صĲ���ֵ��1���ɲɼ�8·�¶ȣ�  			
      				  for(i=0;i<2;i++)
      					   g_singleCellTemperature[g_group][4][i]= g_mboxData[boxNumber][i];
      					break;		 
  				  default:
  					    break;
  			} // end switch(framID)  //��������
    }
}
//******************************************************************************
//* Function name:   HighGroup
//* Description:     ��ֵģ��λ��ȷ��
//* EntryParameter : None
//* ReturnValue    : 1���յ�������Ϣ��0��δ�յ�������Ϣ
//******************************************************************************
unsigned char ModelLocation(unsigned char Addr) 
{
    int i=0;
    for(i=0;i<BMU_NUMBER;i++) {
      if((Addr==i))
        return i+1;
    }
   
}
//******************************************************************************
//* Function name:   bmuProcess2
//* Description:     �յ����е�����Ϣ��������弫ֵ
//* EntryParameter : None
//* ReturnValue    : 1���յ�������Ϣ��0��δ�յ�������Ϣ
//******************************************************************************
unsigned char bmuProcess2(void)//
{
    unsigned int buf=0,tmpMax=0,tmpMin=0;
	  unsigned char tmperatMax=0,tmperatMin=0; 
	  unsigned int i,j,k,h,t,boxNumber=0,count=0;
	  unsigned long sum=0;
	  unsigned int cell[200];
	  unsigned char ti=0,ci=0;
	  unsigned char HighBMUAddr=0,HighBMUGroupNum=0,HighBMUNum=0;
	  unsigned char LowBMUAddr=0,LowBMUGroupNum=0,LowBMUNum=0;
	  static unsigned char ErrorBMUAddr=0;
	  static unsigned char ErrorBMUGroup=0;
	  static unsigned char ErrorBMULocation=0;
	  static unsigned char TemLossState=0;
	  static unsigned char TemLossTime=0;  
	  for(i=0;i<200;i++)
		{
			  cell[i]=0;
		}	

    if((g_circleFlag==G_BMU_CIRCLE_FLAG)&&(g_configFlag==G_BMU_CIRCLE_FLAG))//����յ����еı��ģ�����    
    {    
    		g_circleFlag=0; //������Ϣ1���Ӳŷ�һ�Σ����Բ�������������ı�־λ����� 		  
    		  
    	  //�����ص�����ߺ���͵�ѹ,�¶�
    		h=0;    		
    		sum = 0;
    		tmpMax = g_singleCellVoltage[0][0][0];
    		tmpMin = g_singleCellVoltage[0][0][0];
    		tmperatMax = g_singleCellTemperature[0][0][0];
    		tmperatMin = g_singleCellTemperature[0][0][0];
    			
    		for(i=0;i<BMU_NUMBER;i++)
    		    for(j=0;j<g_bmu2_number_v[i];j++)
    				    for(k=0;k<g_cell_number_v[i][j];k++)
    					  {    						      						     						    
    						    if(g_singleCellVoltage[i][j][k]>=tmpMax)
    						    {

    						        HighBMUAddr=i;
    						        HighBMUGroupNum=j;
    						        HighBMUNum=k;
    							      tmpMax = g_singleCellVoltage[i][j][k];
    						    }
    						    if(g_singleCellVoltage[i][j][k]<=tmpMin)
    						    {

    							      LowBMUAddr=i;
    						        LowBMUGroupNum=j;
    						        LowBMUNum=k;
    							      tmpMin = g_singleCellVoltage[i][j][k];
    						    }
    						    cell[h] = g_singleCellVoltage[i][j][k];
    						    h++;
    						    sum += 	(unsigned long)g_singleCellVoltage[i][j][k];
    					  }
        
        g_CellHighestVolBoxNum=ModelLocation(HighBMUAddr);
        g_CellHighestVolBoxPosi=HighBMUAddr*g_bmu2_number_v[HighBMUAddr]*12+12*HighBMUGroupNum+HighBMUNum+1;
        g_CellLowestVolBoxNum=ModelLocation(LowBMUAddr);
        g_CellLowestVolBoxPosi=LowBMUAddr*g_bmu2_number_v[LowBMUAddr]*12+12*LowBMUGroupNum+LowBMUNum+1;
        
        g_CellHighestVol = (float)tmpMax/10000;
    	  g_CellLowestVol = (float)tmpMin/10000;
    	    	  
    		g_SystemVoltageV0 = sum/10000;
    	  g_averageVoltage = ((float)sum/h/10000);
    		for(i=CELL_VOLTAGE_0;i<CELL_VOLTAGE_199+1;i++)
            g_storageSysVariableCell[i] = (unsigned int)(cell[i-CELL_VOLTAGE_0]);
              		
    		//***�¶Ȳ��ִ���***********************************************************************************		      	
    		t=0;
    		sum = 0;
    		count = 0;		
    		for(i=0;i<BMU_NUMBER;i++)
    				for(j=0;j<g_bmu2_number_t[i];j++)
    					  for(k=0;k<g_cell_number_t[i][j];k++)
    					  {    						
    						    if(((g_singleCellTemperature[i][j][k]&0x00ff) >5)&&((g_singleCellTemperature[i][j][k]&0x00ff)<240))//��ƽ���¶�ʱ ȥ����·���·��� 
    						    {    						  
    							      if((g_singleCellTemperature[i][j][k]&0x00ff) >= (tmperatMax&0x00ff))
    							      {

        								    HighBMUAddr=i;
        						        HighBMUGroupNum=j;
        						        HighBMUNum=k;
    								        tmperatMax = g_singleCellTemperature[i][j][k]&0x00ff;
    							      }
    							      if((g_singleCellTemperature[i][j][k]&0x00ff) <= (tmperatMin&0x00ff))
    							      {
 
        								    LowBMUAddr=i;
        						        LowBMUGroupNum=j;
        						        LowBMUNum=k;
    								        tmperatMin = g_singleCellTemperature[i][j][k]&0x00ff;
    							      }
    					          t++;
    					          sum += g_singleCellTemperature[i][j][k]&0x00ff;
    					      } 
    					      else
    					      {
    					      /*
    					      	  if(g_singleCellTemperature[i][j][k]<=5)
    					      	      g_singleCellTemperature[i][j][k] = 0;
    					      	  else if(g_singleCellTemperature[i][j][k]>=240)
    					      	      g_singleCellTemperature=240; 
    					     */ 	  
    					      	  
    					      	  if((i==ErrorBMUAddr)&&(j==ErrorBMUGroup)&&(k==ErrorBMULocation))
    					      	  {
    					      	      TemLossTime++;
    					      	  }
    					      	  if(TemLossTime>=50)
    					      	  {
    					      	      TemLossTime=57;
    					      	      TemLossState=1;
    					      	  }
    					      	  ErrorBMUAddr=i;
	                      ErrorBMUGroup=j;
	                      ErrorBMULocation=k;
	                       
    					      }
    						    g_storageSysVariableT[count]=g_singleCellTemperature[i][j][k]&0x00ff;
    						    count ++;    							
    					  }
    					  
				
        g_BatHighestTempBoxNum=ModelLocation(HighBMUAddr);
        g_BatHighestTempBoxPosi=HighBMUAddr*g_bmu2_number_v[HighBMUAddr]*2+2*HighBMUGroupNum+HighBMUNum+1;
        g_BatLowestTempBoxNum=ModelLocation(LowBMUAddr);
        g_BatLowestTempBoxPosi=LowBMUAddr*g_bmu2_number_v[LowBMUAddr]*2+2*LowBMUGroupNum+LowBMUNum+1;
        
        g_BatLowestTemp = tmperatMin;
    	  g_BatHighestTemp = tmperatMax;   //ע���¶���48��ƫ����
    		sum = sum- g_BatHighestTemp-g_BatLowestTemp;
    	  //g_averageTemperature = (unsigned char)(sum/(t-2));
    	  g_averageTemperature = Tavg;
    	    ////*******************������㼫ֵ*************************
    	  MoudleConfiguration();//�����������Ϊ�����е��嶼��ֵ�꣬��ֹ����0
  		  //  
    			//�������¶����·���4�顣
    			ti = 0;
    			for(i=0;i<4;i++)
    			{
    				for(j=0;j<8;j++)
    				{
    					if(ti<count)
    					    g_CellTemp[i][j] = (unsigned char)g_storageSysVariableT[ti];
    					else 
    					    g_CellTemp[i][j] = 0;
    					ti++;
    				}
    			}
    			
    			
    			//�������ѹ���·���
    			ci = 0;
    			for(i=0;i<48;i++)
    			{
    				for(j=0;j<4;j++)
    				{
    					if(ci<h)
    					{   
    					    //g_storageSysVariableCell[ci]=g_storageSysVariableCell[ci]/100;//�ֱ���Ϊ0.01,A*100/10000=A/100 					  
    					    g_CellVol[i][j] = g_storageSysVariableCell[ci]/100;
    					}
    					else
    					{    					  
    					    g_CellVol[i][j] = 0;
    					}
    					ci++;
    				}
    			}
    			
    			
  		  //************************************************************************************************
    		for(i=0;i<1;i++)  //��ս��ջ���
    	  {
    	      g_mboxID=0;
    	      for(j=0;j<8;j++)
    	          g_mboxData[0][j] = 0;
    	  }
    	  if((g_CellLowestVol==0)||(g_BatLowestTemp==0)||(TemLossState==1))              
    	      return 0;
    	  else 
    	      return 1;	 //ȫ�����ݴ������
          
  	} // end of circleflag	
	  return 0;
}
//******************************************************************************
//* Function name:   MoudleConfiguration
//* Description:     �յ����е�����Ϣ�����ÿ�䵥�弫ֵ
//* EntryParameter : None
//* ReturnValue    : 1���յ�������Ϣ��0��δ�յ�������Ϣ
//******************************************************************************
void MoudleConfiguration(void)//
{
    unsigned int tmpMax=0,tmpMin=0;
	  unsigned char tmperatMax=0,tmperatMin=0; 
	  unsigned int i,j,k,p=0;

	  static unsigned char InBoxBmuNum=0;//�������е�BMU��ʼ�� 
	  static unsigned char BoxNum=0;
	  //������ÿ����������ߺ���͵�ѹ,�¶�


		tmpMax = g_singleCellVoltage[InBoxBmuNum][0][0]; //�����⸳��ֵ��Ϊ�˼�����ĳ���Ӧ��BMU��
		tmpMin = g_singleCellVoltage[InBoxBmuNum][0][0];
		tmperatMax = g_singleCellTemperature[InBoxBmuNum][0][0];
		tmperatMin = g_singleCellTemperature[InBoxBmuNum][0][0];
		
	
		for(i=InBoxBmuNum;i<=InBoxBmuNum+1;i++)
		    for(j=0;j<g_bmu2_number_v[i];j++)
				    for(k=0;k<g_cell_number_v[i][j];k++)
					  {    						      						     						    
						    if(g_singleCellVoltage[i][j][k]>=tmpMax)
						    {
							      tmpMax=g_singleCellVoltage[i][j][k];
						    }
						    if(g_singleCellVoltage[i][j][k]<=tmpMin)
						    {
							     tmpMin=g_singleCellVoltage[i][j][k]; 
						    }
					  }
	   InBoxMaxV[BoxNum] = (float)tmpMax/10000;   //��i�䵥����ߵ�ѹ
	   InBoxMinV[BoxNum] = (float)tmpMin/10000;    //��i�䵥����͵�ѹ
	   
	   
		//***�¶ȼ�ֵ����***		      	
		for(i=InBoxBmuNum;i<=InBoxBmuNum;i++)
				for(j=0;j<g_bmu2_number_t[i];j++)
					  for(k=0;k<g_cell_number_t[i][j];k++)
					  {    						
						    if(((g_singleCellTemperature[i][j][k]&0x00ff) >5)&&((g_singleCellTemperature[i][j][k]&0x00ff)<240))//��ƽ���¶�ʱ ȥ����·���·��� 
						    {    						  
							      if((g_singleCellTemperature[i][j][k]&0x00ff) >= (tmperatMax&0x00ff))
							      {
								        
								        tmperatMax=g_singleCellTemperature[i][j][k]&0x00ff;
							      }
							      if((g_singleCellTemperature[i][j][k]&0x00ff) <= (tmperatMin&0x00ff))
							      {
								        
								        tmperatMin=g_singleCellTemperature[i][j][k]&0x00ff;
							      }
					      } 
					  }
					  
    BatBoxHighestTemp[BoxNum] = tmperatMax;    //��i�䵥������¶�
    BatBoxLowestTemp[BoxNum] = tmperatMin;     //��i�䵥������¶�

    BoxNum++;//������+�Ƿ�ֹһ�������ͼ���žʹ�1��ʼ�ˣ�ѭ����4���丳ֵ
    InBoxBmuNum++;//bmu�Ŵ�0��ʼ��ÿ��1��BMU
    if(BoxNum>=BMU_NUMBER)
    {
        BoxOverFlag=1;//�״ν������Ҫ������6����������ж��з��ͳ���ʼ���ã���Ȼ�ᷢ0
        BoxNum=0;
        InBoxBmuNum=0;
    }
} 
//**********************************************************************
//**********************************************************************


//**********************************************************************
//**********************************************************************