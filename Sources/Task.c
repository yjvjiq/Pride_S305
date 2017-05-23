//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : Task.c
//* Author             : Judy
//* Version            : V1.0.0
//* Start Date         : 2014.5.7
//* Description        : 该文件将整个系统进行任务划分并整合所有过程
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include "derivative.h" /* include peripheral declarations */
#include "BMS20.h" 
//**************************************************************************************
//* Variable definition                            
//**************************************************************************************/
//任务列表
static TASK_COMPONENTS TaskComps[] = 
{ 
    {0, 1,    1,    TaskCurrentDetect},         //电流检测任务 1ms检测一次电流值 //0 标志位，1，
    {0, 700,  700,  TaskSocProcess},            //SOC处理
    {0, 297,   300,   TaskBmuProcess},            // BMU数据处理任务//以前60ms
    {0, 17,   20,   TaskVoltage},               // 总电压计算   .
    //{0, 297,  300,  TaskInsulation},            // 绝缘电阻计算 //该处时间最小600MS，不能太小  80ms
    {0, 97,  100,   TaskReport2PC},             //发送报文到上位机
    {0, 5,    5,    TaskStatusMachine},         //状态机处理
    {0, 997, 1000,  TaskFaultProcess},          //1s故障处理
    {0, 9,   10,    TaskRecordProcess},        //历史记录处理
      
};

//**************************************************************************************
//* FunctionName   : TaskRemarks()
//* Description    : 任务标志处理
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
void TaskRemarks(void)
{
    uchar i;

    for (i=0; i<TASKS_MAX; i++)          // 逐个任务时间处理
    {
         if (TaskComps[i].Timer)          // 时间不为0
        {
            TaskComps[i].Timer--;         // 减去一个节拍
            if (TaskComps[i].Timer == 0)       // 时间减完了
            {
                 TaskComps[i].Timer = TaskComps[i].ItvTime;       // 恢复计时器值，从新下一次
                 TaskComps[i].Run = 1;           // 任务可以运行
            }
        }
   }
}
//**************************************************************************************
//* FunctionName   : TaskProcess()
//* Description    : 任务处理
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
void TaskProcess(void)
{
    uchar i;

    for (i=0; i<TASKS_MAX; i++)           // 逐个任务时间处理
    {
        if (TaskComps[i].Run)           // 时间不为0
        {
             TaskComps[i].TaskHook();         // 运行任务
             TaskComps[i].Run = 0;          // 标志清0
        }
    }   
}
//************************************************************************
//* Function name:TaskCurrentDetect
//* Description:通过两个AD通道读取AD值，再经过公式转换成电流，根据范围取其中一个电流
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskCurrentDetect(void)//
{
    
    turnOnADC(); //打开ADC中断
	  delay(10);  
	  if((Int_Flag&0x01)==0x01) //采了32次AD值后才计算
        g_BatSysTotalCur = CurrentCalculation();

}  
//************************************************************************
//* Function name:TaskSocProcess
//* Description:每秒计算并保存SOC，每分钟保存一次历史记录
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskSocProcess(void)
{
    
    static float ahCharge1A=0;
    static float ahDischarge1A=0;
    static unsigned char DCfinish=0;
   
	  unsigned char i=0;
	  float ft=0;
	  	  	  
		I2CReadDate();  //读取系统时间
			         	
		if(CurrentTime[0]!=g_oldTime[0])   //每秒钟计算一次SOC的值
		{
				g_oldTime[0] = CurrentTime[0];//秒
			  SocIntegral();//计算积分得到的SOC值	   
			  g_energyOfUsed = 0;	    		
		    StoreSocRealvalue();//每秒保存SOC值
		    //if(g_errorRecordRead_flag==0)
		        //StoreSysVariable();//for test
		         		    
    } //end of 每秒钟
				
		if(CurrentTime[1]!=g_oldTime[1])// 每分钟SOC值赋给系统参数，作为保存或通信
	  {
			  g_oldTime[1] = CurrentTime[1];//分
			  
			  g_sysPara[PARA_SOC_VALUE] = g_socValue;
			  
			  if((g_BmsModeFlag == DISCHARGING)&&(StoreAHState==1))
			  {
			      ft=(StoreAHSOC-g_socValue)*C;//计算累积充放电AH容量
			      if(ft>1)
			      {			        
			          dischargeAH += (unsigned int)ft;
			          StoreAHSOC=First_g_socValue;
			      }
			  } 
			  else if((g_BmsModeFlag == FASTRECHARGING)&&((StoreAHState==1)))
			  {
			      ft=(g_socValue-StoreAHSOC)*C;//计算累积充放电AH容量
			      if(ft>1)
			      {			        
			          chargeAH += (unsigned int)ft;
			          StoreAHSOC=First_g_socValue;
			      }
			  }
			  
			   
			  //First_g_socValue=StoreAHSOC;      
			    
			   

			  //保存状态数据
			  if(g_errorRecordRead_flag==0)
		        StoreSysVariable();//每分钟保存故障记录信息
		    if(StoreAHState==1)    	
		        StoreChargeDischargeAH();//保存累积充放电总容量	  
		    sendBMSIDtoBMU(); //发送BMS版本ID号给BMU
			  sendRealtimeToBMU(); //发送BMS系统时间给BMU
			      
    }

}
//**********************************************************************
//* Function name:    TaskBmuProcess
//* Description:      BMU自检，如果长时间收不全BMU数据，则显示内部通信故障
//* EntryParameter : None
//* ReturnValue    : None
//**********************************************************************
void TaskBmuProcess(void) 
{
   static unsigned long t=0;
   
   unsigned char i=0,k=0x01,m=0x02;
   unsigned char ErrorState=0;
   float Value=0;
   unsigned long buff=0;
     
    if(!bmuProcess2()) //BMU自检   	        
    {        
        t++;
        _FEED_COP();   //2s内不喂内狗，则系统复位
    } 
    else 
    {            
        t=0;
        GetTavgProcess();
        //State_Box_Online=0x3f;        
       
    }          
    if(t>=100) //超时故障报告300ms*100=30s
    {
                 
        fault_pc552_Byte6.Bit.F0_InterComFault=1; //内部通讯故障 
                    
    
    }/////end of BMU通信判断
    
}

//***********************************************************************
//* Function name:   TaskReport2PC
//* Description:     将BMS的相关信息通过内部报文0x0c0450,0x0c0451,0x0c0452发给上位机软件
//*                  为防止丢帧，所以报文间隔发送
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskReport2PC(void) 
{
    static unsigned char ct=0;
    ct++;
    if(ct==1)
        bmsToPcInfo450();
    if(ct==2)
			  bmsToPcInfo451();
    if(ct==3)
			  bmsToPcInfo552();
    if(ct==4)
        bmsToPcInfo553();
    if(ct==5)
        bmsToPcInfo554();
    if(ct==6)
    {   
        if(g_BmsModeFlag == RECHARGING)
            bmsToPcInfo750();   
        ct=0;
    }

}



//***********************************************************************
//* Function name:   TaskGpioTest
//* Description:     应用程序进入到调试阶段时,对主板A口的检测
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskGpioTest(void) 
{
    static unsigned int TimerCP=0; 
    if((input2_state()==0)&&(input3_state()==1))   //16A 680R
        C0552_0 |= 0x01; 
    else
        C0552_0 &= 0xfe;
    
    if((input2_state()==0)&&(input3_state()==0))   //32A 220R
        C0552_0 |= 0x02; 
    else
        C0552_0 &= 0xfd;

    if(input6_state()==0)       //CP
    {
        C0552_0|=0x04;
        if(TimerCP>=500)      //10ms 定时器 2S
        {
            //TurnOn_CP();
            TimerCP=501;
        }
    }
    else 
    {
        C0552_0&=0xfb;
        //TurnOff_CP();
        TimerCP=0;
    }
    
    if(input4_state()==0)      //ACC
        C0552_0|=0x08; 
    else
        C0552_0&=0xf7;
    

    if(input6_state()==0)    //充电反馈     (闭合充电反馈时,ACC也亮)
        C0552_0|=0x10; 
    else
        C0552_0&=0xef;

    if(input5_state()==0)       //CC2
        C0552_0|=0x20; 
    else
        C0552_0&=0xdf;
    /*
    if(inputP_state()==0)       // 正极反馈
        gpio_state|=0x20;  
    else
        gpio_state&=0xdf;

    if(inputN_state()==0)       // 负极反馈
        gpio_state|=0x40;
    else
        gpio_state&=0xbf;

    if(inputH_state()==0)       ///INPUT1 高低压互锁
        gpio_state|=0x80; 
    else
        gpio_state&=0x7f;  
    */


                
}


//***********************************************************************
//* Function name:   TaskStatusMachine
//* Description:     BMS根据整车发过来的状态机编码进行相应动作  5ms调用一次 
//* EntryParameter : None
//* ReturnValue    : None
//************************************************************************
void TaskStatusMachine(void)//5ms调用一次 
{
    SignalOnOffJudge(); 
    stateCodeTransfer();
   /* static unsigned char counter1_10ms=0;
    static unsigned char counter1_500ms=0;
    static unsigned char counter2_500ms=0;
    static unsigned char counter3_500ms=0;
    static unsigned char clearSelfCountAC=0;
    static unsigned char state46=0;
    static unsigned char TestDelay=0;//进入到调试模式下的时间延时
    float BiggestDisCurrent=0;
    float BiggestChaCurrent=0;
    
    //HeatManage();  
    
    //stateCode = 179;
    switch(stateCode) //状态机判断
    {

        //***********************上电过程*********************************

        case 11:
        case 141:   
            state46=0;
           
            break;
        //********************低压自检*************************************
        case 12:  
            HighVoltDetectPart1();//MSD与负极粘连
            tmr_p5=0;//146无法清零
            delay(25000); //19ms           
            break;     
        case 142:
            if(g_BMSSelfCheckCounter==0)  //自检计数器=0
            {
                HighVoltDetectPart1();//MSD与负极粘连
                tmr_p5=0;//146无法清零  
            }    
            if(g_BMSSelfCheckCounter==1)  //自检计数器=1
            {
                TurnOn_INA2K();     //闭合充电负继电器            
                delay(25000); //19ms     
                HighVoltDetectPart2();//负极继电器断路
            }
            
            break;     
        case 14:  //***********************闭合放电负************************************
            closeNegRelay();     //闭合放电负继电器
            delay(25000);   //19ms
            break;
        case 144: //***********************闭合充电负继电器*******************************
            BMS8_Byte1.Bit.F6_7_ChaPCtorClose=1;  //发送充电正闭合指令            
            break; 
            
        case 17:   //***********************电池高压检测*****************************
            HighVoltDetectPart2();//负极继电器断路
            BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=1;  //发送放电负闭合  to VCU
            BMS6();
            break;


        //****************工作过程********************************************
    
        case 30:    //*********************行车状态********************************
            turnOnSW_Power();//打开软件开关  
            g_MaxDischaCur = BigDischargePowerAdjust((Tavg-40),g_SysSOC);//SOF//30s
            g_MaxFebCur = PulseRechargePowerAdjust1(g_SysSOC,(Tavg-40)); //制动能量回收30s 
            SocEndDischargeAdjust(); //放电末端SOC修正
            CarFaultDone();//行车过程故障处理
            break;
        case 170:   //********************快充充电 ***********************************
            turnOnSW_Power();//打开软件开关 
            HeatManage();  
            REQ_TurnON_Insulation = 1;
            counter1_500ms++;
            if(counter1_500ms>=70)
            {
                counter1_500ms=0;
                HeatAndChargeControl();  //充电加热控制
                GetDCTem();              
            }
            break;


        //*************************下电过程******************************
                        
        case 180:
            BMS8_Byte1.Bit.F6_7_ChaPCtorClose=2;  //请求断开充电正 
            TurnOff_INHK();//断开加热继电器 非170状态加热继电器都要关闭          
            delay(25000); //19ms            
            break;
        //********************断开主负******************************     
        case 44:                   //断开放电负
            if((g_DischaNRelayDiscon == 1)||(g_FlagLevel==4)||(g_RelayPowerOffFault==1)) 
            {
                BMS8_Byte0.Bit.F6_7_BatNCtorStateFeb=2;
            }
            else if((WithEVCUComOverTimeFlag==1))
            {                
                openNegRelay();           //断开放电负
            } 
            else if((g_ACC_ON==0)&&(Delay5s3>5000)) 
            {
                Delay5s3=0;
                openNegRelay();           //断开放电负                
            }
            else if(g_BatSysTotalCur>=30)        //如果系统电流大于等于30A
            {
                openNegRelay();           //断开放电负
            }
            else if((g_BatSysTotalCur<30))     //如果系统电流小于30A
            {              
                if(EVCU_Byte0.Bit.F6_7_BatNCtorCtrl==2)//若收到整车发送的高压下电命令，则BMS执行断开放电负
                {
                    openNegRelay();           //断开放电负              
                }
                else if(Delay60s>=56000)      //延时60s ,中断延时不准
                {
                    openNegRelay();           //断开放电负
                    Delay60s=0;
                }                         
            } 
            
            break;
        case 184:                  //断开充电负
            TurnOff_INA2K();      //断开充电负
            delay(25000); //19ms
            break;  
            
        case 46:   //*****************高压掉电检测*******************************
            DischaNRelayAdjoinTest();   //放电负粘连检测
            break;
        case 186:
            ChaNRelayAdjoinTest();            
            break;   
        case 47:  //******************BMS断电**************************************
        case 187:
            if(state46==0)
            {
              
                delay(25000); //20ms
                delay(25000); //20ms
                //TurnOff_INHK();//关闭加热继电器 
                //preChargeON=0;
                tmr_p1=0;           
                tmr_p2=0;
                tmr_p3=0; 
                tmr_p4=0;
                g_BMSSelfCheckCounter=0;
               // TurnOff_INBK();//断开预充,防止状态机由12跳转到46时预充继电器没有断开
                StoreSysVariable();//                
                StoreSocRealvalue();
                state46=1;
                SelfCheck = 0;//自检清零,防止不断电在自检时程序不起作用
            } 
            break;
        case 177://调试阶段

            openNegRelay();//断开负极继电器
            delay(25000); //20ms
            
            _FEED_COP();   //2s内不喂内狗，则系统复位
            
            TurnOff_INHK();//断开加热继电器
            delay(25000); //19ms
            delay(25000); //19ms
            TurnOff_INA2K();//断开快充继电器
            turnOffSW_Power();//close总电源开关 
            State177End=1;//跳转到179等待
            break;
        case 179://调试阶段
            TaskGpioTest();
            TestDelay++;
            if(TestDelay>100)//5*100=400
            {
               GetDCTem();
                TestDelay=0;
            }  
            break;    
        case 48:  //******************BMS断电**************************************
        case 188:   
            delay(25000); //20ms
            delay(25000); //20ms
            turnOffSW_Power();//close总电源开关  
            break; 
        default:
            break;                        
    }
     */
}


//**************************************************************************************
//**************************************************************************************
//**************************************************************************************
//**************************************************************************************