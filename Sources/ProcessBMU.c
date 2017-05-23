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
//* Description        : 该文件专门用于处理接收到的BMU数据，从而得出单体极值和单体值
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "derivative.h" /* include peripheral declarations */
#include "BMS20.h" 

unsigned char InBoxMaxV[BMU_NUMBER]={0};
unsigned char InBoxMinV[BMU_NUMBER]={0};


unsigned char g_group;  //BMU1 组号， 从0~15
unsigned int g_singleCellVoltage[BMU_NUMBER][SIX802_NUMBER][CELL_NUMBER];  //BMU1号, 6802（组）号, 单体电池号
unsigned char g_singleCellTemperature[BMU_NUMBER][SIX802_NUMBER][Tem_NUMBER];//BMU1号, 6802（组）号, 单体电池号

//float g_CellHighestVol=0; //单体最高电压
//float g_CellLowestVol=0;  //单体最低电压
float g_averageVoltage;       //平均单体电压
//float g_SystemVoltageV0;      //系统电压=单体电压累加总电压
//unsigned char g_BatHighestTemp=0; //单体最高温度
//unsigned char g_BatLowestTemp=0;  //单体最低温度
unsigned char g_averageTemperature; //单体平均温度
unsigned char Tavg; //电芯平均温度
unsigned char LowVolNum=1;
unsigned char HighVolNum=1;
unsigned char HighTemNum=1;
unsigned char LowTemNum=1;
unsigned char BoxOverFlag=0;

unsigned char g_bmu2_number_v[BMU_NUMBER];
unsigned char g_cell_number_v[BMU_NUMBER][5];
unsigned char g_bmu2_number_t[BMU_NUMBER];
unsigned char g_cell_number_t[BMU_NUMBER][5];

//unsigned long recogBMUtoBMSmessage;//BMS BMU通信辨识信息
unsigned char recogBMStoBMUflag = 0;//BMS与BMU辨识成功标志
unsigned int g_CellVol[48][4];             //单体电压
unsigned int g_CellTemp[4][8];            //单体温度
unsigned char BatBoxHighestTemp[BMU_NUMBER];         //每箱最高温度
unsigned char BatBoxLowestTemp[BMU_NUMBER];         //每箱最低温度
	
//************************************************************************
//************************************************************************
//************************************************************************
//************************************************************************
unsigned long g_circleFlag = 0; //一个循环完成的标志
unsigned long g_configFlag = 0;//收到配置信息标志，用于判断BMU个数，6805组数和单体个数 

//******************************************************************************
//* Function name:   BMU_initial
//* Description:     上电接收BMU所有数据，确保单体温度和电压都没问题
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMU_initial(void) 
{
    unsigned int t=0;
    
    //***********BMU自检*******************************************       
    while((!bmuProcess2())&&(t<65000))    	        
    {        
        t++;      
        if(t>=60000) //超时故障报告
        {
            
            fault_pc552_Byte6.Bit.F0_InterComFault=1;
            //BMS9_Byte7.Bit.F4_BzerAlarm= 1 ;        //蜂鸣器报警 
                     
        }/////end of BMU通信判断  
        else 
        {            
            //BMS9_Byte7.Bit.F4_BzerAlarm = 0;
            fault_pc552_Byte6.Bit.F0_InterComFault=0; 
            
        }  
        _FEED_COP();   //2s内不喂内狗，则系统复位 
    }

}
//******************************************************************************
//* Function name:   BMU_Processure
//* Description:     对接收到的BMU单体电压和温度进行解析
//* EntryParameter : None
//* ReturnValue    : None
//******************************************************************************
void BMU_Processure(void)
{
    unsigned long framID;
	  unsigned int i,boxNumber=0;
	   
	  if((Int_Flag&0x08)==0x08) //若接收到1个数据，进行数据处理
	  {
  		  Int_Flag &= 0xf7;//清中断标志		
  		  		  			  		
  	 	  g_group = 0;  		

  			framID = g_mboxID;      
  			g_group = framID&0x000000ff;
  			g_group--;

  			framID = framID>>4;
  			framID = framID & 0x03ffffff;

  			switch(framID)  //解析数据
  			{
  			    case 0x018FF110://BMU标识信息；硬件版本、软件版本、通讯协议版本等；0x18FF110x
  				 	    //if(recogBMUtoBMSmessage != bufL)
  					    //	recogBMStoBMUflag = 0; //辨识失败
  					    //else
  						  recogBMStoBMUflag = 1; //辨识成功								
  					    break;	  
  				  case 0x018FF130://电池配置信息1，6805的个数、电池采压数量、采温数量；CC2
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
  					    g_bmu2_number_v[g_group] = g_mboxData[boxNumber][0]&0x07; //&0x07;//BMU1带6802的个数
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
  				  case 0x018FF140://电池配置信息3，6802的个数、电池采压数量、采温数量；CC3
  					    break;
  			    case 0x018FF160:   //判断生命信号 是否接收完一个周期
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
  				  case 0x018FF210://组号＃1，电池的采压值＃1，可采集4路电压:
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][0][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF220://组号＃1，电池的采压值＃2，可采集4路电压:
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][0][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF230://组号＃1，电池的采压值＃3，可采集4路电压；  				  
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][0][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      } 
      					break;  			  		
  				  case 0x018FF370://组号＃1，电池的欠压过压标志
      					//g_groupUVflag[g_group][0] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][0] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;  				
  				  case 0x018FF410://组号＃1，电池的采温值＃1，可杉?路温度；
      					for(i=0;i<2;i++)
      					    g_singleCellTemperature[g_group][0][i]= g_mboxData[boxNumber][i];
      					break; 	
  				  //******** group#2**********
  				  //**************************
  				  case 0x018FF240://组号＃2，电池的采压值＃1，可采集4路电压；
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][1][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF250://组号＃2，电池的采压值＃2，可采集4路电压；
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][1][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF260://组号＃2，电池的采压值＃3，可采集4路电压；
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][1][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;  					
  				  case 0x018FF380://组号＃2，电池的欠压过压标志
      					//g_groupUVflag[g_group][1] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][1] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;     			  
  				  case 0x018FF420://组号＃2，电池的采温值＃1，可采集8路温度；  				 
  				      for(i=0;i<2;i++)
  					        g_singleCellTemperature[g_group][1][i]= g_mboxData[boxNumber][i];
  					    break;
  				  //******group#3********
  				  //*********************
  				  case 0x018FF270://组号＃3，电池的采压值＃1，可采集4路电压；
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][2][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF280://组号＃3，电池的采压值＃2，可采集4路电压；
  				      for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][2][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF290://组号＃3，电池的采压值＃3，可采集4路电压；
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][2][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  					
  				  case 0x018FF390://组号＃3，电池的欠压过压标志
      					//g_groupUVflag[g_group][2] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][2] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break; 					
  				  case 0x018FF430://组号＃3，电池的采温值＃1，可杉?路温度；  				
      					for(i=0;i<2;i++)
      					    g_singleCellTemperature[g_group][2][i]= g_mboxData[boxNumber][i];
      					break;  	
  				  //*******group#4*******
  				  //*********************
  				  case 0x018FF2a0://组号＃4，电池的采压值＃1，可采集4路电压；
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][3][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2b0://组号＃4，电池的采压值＃2，可采集4路电压；
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][3][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2c0://组号＃4，电池的采压值＃3，可采集4路电压； 
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][3][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF3a0://组号＃4，电池的欠压过压标志  				  
      					//g_groupUVflag[g_group][3] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][3] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;  				
  				  case 0x018FF440://组号＃4，电池的采温值＃1，可采集8路温度  				 
      				  for(i=0;i<2;i++)
      					    g_singleCellTemperature[g_group][3][i]= g_mboxData[boxNumber][i];
      					break;
  				  //******group#5********
  				  //*********************
  				  case 0x018FF2d0://组号＃5，电池的采压值＃1，可采集4路电压；	
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][4][i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2e0://组号＃5，电池的采压值＃2，可采集4路电压；
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][4][4+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }
      					break;
  				  case 0x018FF2f0://组号＃5，电池的采压值＃3，可采集4路电压；  
  				    	for(i=0;i<4;i++)
  				      {
  				          g_singleCellVoltage[g_group][4][8+i]=g_mboxData[boxNumber][2*i+1]|(unsigned int)g_mboxData[boxNumber][2*i]<<8;
  				      
  				      }

      					break;  					
  				  case 0x018FF3b0://组号＃5，电池的欠压过压标志
      					//circleFlag |= 0x10000000;
      					//g_groupUVflag[g_group][4] = g_mboxData[boxNumber][1]|(unsigned int)g_mboxData[boxNumber][0]<<8;
      					//g_groupOVflag[g_group][4] = g_mboxData[boxNumber][3]|(unsigned int)g_mboxData[boxNumber][2]<<8;
      					break;  					
  				  case 0x018FF450://组号＃5，电池的采温值＃1，可采集8路温度；  			
      				  for(i=0;i<2;i++)
      					   g_singleCellTemperature[g_group][4][i]= g_mboxData[boxNumber][i];
      					break;		 
  				  default:
  					    break;
  			} // end switch(framID)  //解析数据
    }
}
//******************************************************************************
//* Function name:   HighGroup
//* Description:     最值模组位置确定
//* EntryParameter : None
//* ReturnValue    : 1，收到所有信息；0：未收到所有信息
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
//* Description:     收到所有单体信息后，算出单体极值
//* EntryParameter : None
//* ReturnValue    : 1，收到所有信息；0：未收到所有信息
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

    if((g_circleFlag==G_BMU_CIRCLE_FLAG)&&(g_configFlag==G_BMU_CIRCLE_FLAG))//如果收到所有的报文，则处理    
    {    
    		g_circleFlag=0; //配置信息1分钟才发一次，所以不能在这里把它的标志位清掉。 		  
    		  
    	  //计算电池单体最高和最低电压,温度
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
              		
    		//***温度部分处理***********************************************************************************		      	
    		t=0;
    		sum = 0;
    		count = 0;		
    		for(i=0;i<BMU_NUMBER;i++)
    				for(j=0;j<g_bmu2_number_t[i];j++)
    					  for(k=0;k<g_cell_number_t[i][j];k++)
    					  {    						
    						    if(((g_singleCellTemperature[i][j][k]&0x00ff) >5)&&((g_singleCellTemperature[i][j][k]&0x00ff)<240))//求平均温度时 去掉短路或断路情况 
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
    	  g_BatHighestTemp = tmperatMax;   //注意温度有48的偏移量
    		sum = sum- g_BatHighestTemp-g_BatLowestTemp;
    	  //g_averageTemperature = (unsigned char)(sum/(t-2));
    	  g_averageTemperature = Tavg;
    	    ////*******************箱体计算极值*************************
    	  MoudleConfiguration();//放在这调用是为了所有单体都赋值完，防止出现0
  		  //  
    			//将单体温度重新分组4组。
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
    			
    			
    			//将单体电压重新分组
    			ci = 0;
    			for(i=0;i<48;i++)
    			{
    				for(j=0;j<4;j++)
    				{
    					if(ci<h)
    					{   
    					    //g_storageSysVariableCell[ci]=g_storageSysVariableCell[ci]/100;//分辨率为0.01,A*100/10000=A/100 					  
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
    		for(i=0;i<1;i++)  //清空接收缓存
    	  {
    	      g_mboxID=0;
    	      for(j=0;j<8;j++)
    	          g_mboxData[0][j] = 0;
    	  }
    	  if((g_CellLowestVol==0)||(g_BatLowestTemp==0)||(TemLossState==1))              
    	      return 0;
    	  else 
    	      return 1;	 //全部数据处理完成
          
  	} // end of circleflag	
	  return 0;
}
//******************************************************************************
//* Function name:   MoudleConfiguration
//* Description:     收到所有单体信息后，算出每箱单体极值
//* EntryParameter : None
//* ReturnValue    : 1，收到所有信息；0：未收到所有信息
//******************************************************************************
void MoudleConfiguration(void)//
{
    unsigned int tmpMax=0,tmpMin=0;
	  unsigned char tmperatMax=0,tmperatMin=0; 
	  unsigned int i,j,k,p=0;

	  static unsigned char InBoxBmuNum=0;//在箱体中的BMU开始号 
	  static unsigned char BoxNum=0;
	  //计算电池每个箱体中最高和最低电压,温度


		tmpMax = g_singleCellVoltage[InBoxBmuNum][0][0]; //放在这赋初值是为了计算完某箱对应的BMU号
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
	   InBoxMaxV[BoxNum] = (float)tmpMax/10000;   //第i箱单体最高电压
	   InBoxMinV[BoxNum] = (float)tmpMin/10000;    //第i箱单体最低电压
	   
	   
		//***温度极值计算***		      	
		for(i=InBoxBmuNum;i<=InBoxBmuNum;i++)
				for(j=0;j<g_bmu2_number_t[i];j++)
					  for(k=0;k<g_cell_number_t[i][j];k++)
					  {    						
						    if(((g_singleCellTemperature[i][j][k]&0x00ff) >5)&&((g_singleCellTemperature[i][j][k]&0x00ff)<240))//求平均温度时 去掉短路或断路情况 
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
					  
    BatBoxHighestTemp[BoxNum] = tmperatMax;    //第i箱单体最高温度
    BatBoxLowestTemp[BoxNum] = tmperatMin;     //第i箱单体最低温度

    BoxNum++;//放在这+是防止一进入程序就加箱号就从1开始了，循环给4个箱赋值
    InBoxBmuNum++;//bmu号从0开始，每箱1个BMU
    if(BoxNum>=BMU_NUMBER)
    {
        BoxOverFlag=1;//首次进入程序要计算完6个箱才能让中断中发送程序开始调用，不然会发0
        BoxNum=0;
        InBoxBmuNum=0;
    }
} 
//**********************************************************************
//**********************************************************************


//**********************************************************************
//**********************************************************************