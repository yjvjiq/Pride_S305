
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//---------------------- Pride Power------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//* Project Name       : S223
//* File Name          : SOF.c
//* Author             : judy
//* Version            : V1.0.0
//* Start Date         : 2016.2.14
//* Description        : ���ļ����ڲ�����SOF��ǰֵ
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//#include "BMS20.h" 

/*
float x;
unsigned char i,j;
float soc1,soc2;
float t1,t2;
unsigned int A1,A2,A3,A4;
float x1,x2;//�м����
*/

//******************************************************************************
//* Function name:   linearizationSOF
//* Description:     SOF���Թ�ϵ��ʽ����
//* EntryParameter : �¶�ֵ��SOCֵ��
//* ReturnValue    : ���ó��������������ŵ����
//******************************************************************************
/*float linearizationSOF(char tem,float soc) 
{
    unsigned int F[12][10]={{12,12,72,120,120,120,240,240,240,0},//soc 0% (0)
                        {12,12,72,120,120,120,240,240,240,0},//soc 10%(2)
                        {36,36,120,240,240,288,288,288,288,0},//soc 20%(3)
                        {36,36,120,240,240,288,288,288,288,0},//soc 30%(4)
                        {36,36,120,240,240,288,288,288,288,0},//soc 40%(5)
                        {72,72,192,360,360,480,480,480,480,0},//soc 50%(6)
                        {72,72,192,360,360,480,480,480,480,0},//soc 60%(7)
                        {72,72,192,360,360,480,480,480,480,0},//soc 70%(8)
                        {72,72,192,360,360,480,480,480,480,0},//soc 80%(9)
                        {72,72,192,360,360,480,480,480,480,0},//soc 90%(10)
                        {72,72,192,360,360,480,480,480,480,0}};//soc 100%(11)
             //temperature -30.-20,-10,0,10,20,30,40,50,55    
             //Tavg+40     10,20,30,4,5,60,70,80,90
             //���        0, 1, 2, 3, 4, 5, 6, 7, 8               
    float x;
    unsigned char i,j;
    float soc1,soc2;
    float t1,t2;
    unsigned int A1,A2,A3,A4;
    float x1,x2;//�м����
    static unsigned int Timer_30S;
    ////////���ƽ���¶�С��-20�Ȼ��ߴ���55��,��ŵ繦��Ϊ0///////
    if((tem<-30)||(tem>=55))//Tavg=��ʵ�¶�+40,С��-30���ߴ���50;
    {
        //x=0;
        return 0;
    
    }
    if((tem>=50)&&(tem<55)) 
    {
        t1=50;
        t2=55;
        j=9;
    } 
    else
    {
        j=(tem+30)/10+1;
        t1=(j-1)*10-30;
        t2=j*10-30; 
    }
    i=soc*100/10+1;
    soc1=(i-1)*0.1;
    soc2=i*0.1;
    
    A1=F[i-1][j-1];
    A2=F[i-1][j];
    A3=F[i][j-1];
    A4=F[i][j];
    x1=(A3-A1)/(soc2-soc1)*(soc-soc1)+A1;
    x2=(A4-A2)/(soc2-soc1)*(soc-soc1)+A2;
    x=(tem-t1)/(t2-t1)*(x2-x1)+x1;//
    //x=(tem-t1)/(t2-t1)*((A4-A2-A3+A1)/(soc2-soc1)*(soc-soc1)+A2-A1)+(A3-A1)/(soc2-soc1)*(soc-soc1)+A1;
    return x;   
}
*/
//******************************************************************************
//* Function name:   DischagerCurtCutOff
//* Description:     ���ϴ���,�й��Ϻ󽵵ͷŵ繦��
//* EntryParameter : void
//* ReturnValue    : ���ϵȼ���1 ��Ϊ0��2��Ϊ20%; 3��Ϊ50%
//******************************************************************************
/*unsigned char DischagerCurtCutOff(void)
{
    unsigned char ErrorLever=0;

    if(CutDisCurt0.word!=0)
    {
        ErrorLever=1;
        //state_group3.Bit.St_Power_Reduce = 1;//�����ʱ�־λ
    } 
    else if(CutDisCurt50.word!=0)
    {
        ErrorLever=3;
        //state_group3.Bit.St_Power_Reduce = 1;//�����ʱ�־λ
    } 
    else
    {
        ErrorLever=0;
        if((CutChaCurt0.word==0)&&(CutChaCurt50.word==0))
         ; //  state_group3.Bit.St_Power_Reduce = 0;//�����ʱ�־λ
    }  
    return ErrorLever; 
    

}
*/
//******************************************************************************
//* Function name:   DischagerCurtCutDone
//* Description:     ���ϴ���,�й��Ϻ󽵵ͷŵ繦��
//* EntryParameter : ���ϵȼ�,��������ĵ���ֵ,Mode=1or2(30s=1,5min=2);
//* ReturnValue    : ���ͺ�ĵ���ֵ
//*��ע��            CurrentValue����ǰSOC,Tem�²���ֵ;DischargeCurrentOn���ͺ��ֵ(CurrentValue*ϵ��)
//*��ע:             CurrentDisCurrent:��ǰ�ϱ�ֵ,���������(CurrentDisCurrent=MaxDischaPower)
//******************************************************************************
/*float DischagerCurtCutDone(unsigned char ErrorLever,float CurrentValue,unsigned char Mode)
{
    float DischargeCurrentOn=0;//������������
    float CurrentDisCurrent=0;//���������
    unsigned char ReturnDone=0;
    
    if(Mode==1)
        CurrentDisCurrent = g_MaxDischaCur;//��ֵ���������,��ʾ��ǰ�Ĺ���ֵ
    else if(Mode==2)
        CurrentDisCurrent = BiggestDisCurtContinuous;//��ֵ���������,��ʾ��ǰ�Ĺ���ֵ 
           
    if(ErrorLever==1)
    {      
        DischargeCurrentOn=0;
        ReturnDone=1;
    }
    else if(ErrorLever==2)
    {      
        DischargeCurrentOn=0.2*CurrentValue;
        ReturnDone=1;
    }
    else if(ErrorLever==3)
    {      
        DischargeCurrentOn=0.5*CurrentValue;
        
    }     
    if(CurrentDisCurrent<=DischargeCurrentOn)//����������ֵС�ڵ�ǰ���͹��ʺ��ֵ
    {
        CurrentDisCurrent=CurrentDisCurrent+POWERSPEED;
        if(CurrentDisCurrent>=DischargeCurrentOn)
        {              
            CurrentDisCurrent=DischargeCurrentOn;//�ŵ����Ϊ0.2,������ָ���ϸ�ѹ
        }
        return CurrentDisCurrent;
    }
        //return CurrentDisCurrent;
    else 
    {
        CurrentDisCurrent=CurrentDisCurrent-POWERSPEED;
        if(CurrentDisCurrent<=DischargeCurrentOn)
        {              
            CurrentDisCurrent=DischargeCurrentOn;//�ŵ����Ϊ0.2,������ָ���ϸ�ѹ
        }
        return CurrentDisCurrent;
    }
}
*/
//******************************************************************************
//* Function name:   BigDischargePowerAdjust
//* Description:     New SOF 
//* EntryParameter : �¶ȣ�SOC����ǰ��������ʻ����ֵ
//* ReturnValue    : bigPowerCurrent��ǰ�������ŵ繦�ʻ����
//******************************************************************************
/*float BigDischargePowerAdjust(char tem,float soc)
{
    static float power1=0; //�ŵ繦���ݴ�ֵ1
    static float power2=0; //�ŵ繦���ݴ�ֵ2
    static unsigned char counter=0;//2�λ������ʼ���
    static unsigned char changeFlag=0;//�������Ա仯ʱ��־λ
    static unsigned char FirstOn=0;
    unsigned char ReduceCurt=0;//���ϵȼ�1,2,3�ķ���ֵ
    float BigDisPower=0; //�������ŵ繦�ʵ��м��������ֹ���õ������ж�ֱ�ӷ���
    float BigDisPowerCutDown=0;//��ͬ������,�������͵�����
    float ReturnValue=0;
    static float pc=0;//�������ŵ繦��/���� ����ֵ
    float soff=(float)tem;
    
    
    BigDisPower =SOF176Ah_step(soc,soff);
    //if((BigDisPower*g_BatSysTotalVolV1/1000)>=100)
    //    BigDisPower=100000/g_BatSysTotalVolV1; 
    ReduceCurt=DischagerCurtCutOff();//�ж��Ƿ��н����ʵĹ���
    if(ReduceCurt!=0)//�й���
    {
        if(ReduceCurt==1)
            BigDisPowerCutDown=0;
        else if(ReduceCurt==2)
            BigDisPowerCutDown=0.2*BigDisPower;
        else if(ReduceCurt==3)
            BigDisPowerCutDown=0.5*BigDisPower;
        pc = BigDisPowerCutDown; 
        power1 = BigDisPowerCutDown; 
        FirstOn=1; 
        ReturnValue=DischagerCurtCutDone(ReduceCurt,BigDisPower,DISCURT30s);
        return ReturnValue; 
    
    }
    if(FirstOn==0) //��һ�ν���
    {
        pc=BigDisPower; 
        power1 = BigDisPower; 
        FirstOn=1;         
    } 
    else//�ٴν���
    {
        if(changeFlag==0)//ԭֵΪ0������power2Ϊ�ڶ��ν���ú���ʱ��ֵ
            power2=BigDisPower;
     
        if(power1!=power2) //������߲��ȣ�˵����һ��ڶ��β���
        {
            changeFlag=1;//���ñ仯��־λ
            if(power1>power2) 
            {
                pc=power1-POWERSPEED;// ÿ20ms�仯0.5kw,7ms����һ�Σ�21ms����0.51KW
                power1=pc;
                if(power1<=power2)
                {
                    
                    pc=power2;
                    changeFlag=0; 
                }
            }
            else if(power1<power2) 
            {
                pc=power1+POWERSPEED;// ÿ5ms�仯0.05kw
                power1=pc;
                if(power1>=power2) 
                {
                    
                    pc=power2;
                    changeFlag=0;
                }
            }
        } 
        else 
        {
            changeFlag=0; 
        }
    
    } 
 
    return pc; 
    
}
*/
//******************************************************************************
//* Function name:   BigDischargePowerContinuous
//* Description:     New SOF 
//* EntryParameter : �¶ȣ�SOC����ǰ��������ʻ����ֵ
//* ReturnValue    : bigPowerCurrent��ǰ�������ŵ繦�ʻ����
//******************************************************************************
/*float BigDischargePowerContinuous(char tem,float soc)
{
    static float power1=0; //�ŵ繦���ݴ�ֵ1
    static float power2=0; //�ŵ繦���ݴ�ֵ2
    static unsigned char counter=0;//2�λ������ʼ���
    static unsigned char changeFlag=0;//�������Ա仯ʱ��־λ
    static unsigned char FirstOn=0;
    unsigned char ReduceCurt=0;
    float BigDisPower=0; //�������ŵ繦�ʵ��м��������ֹ���õ������ж�ֱ�ӷ���
    float BigDisPowerCutDown=0;
    static float pc=0;//�������ŵ繦��/���� ����ֵ
    
    BigDisPower =SOF240Ah_step(soc,tem);
    if((BigDisPower*g_BatSysTotalVolV1/1000)>=70)
        BigDisPower=70000/g_BatSysTotalVolV1; 
    if(BigDisPower>=C)
    {
        BigDisPower=C;
    }
    ReduceCurt=DischagerCurtCutOff();
    if(ReduceCurt!=0)//�й���
    {
        if(ReduceCurt==1)
            BigDisPowerCutDown=0;
        else if(ReduceCurt==2)
            BigDisPowerCutDown=0.2*BigDisPower;
        else if(ReduceCurt==3)
            BigDisPowerCutDown=0.5*BigDisPower;
        pc = BigDisPowerCutDown;//���ϻָ���,���Ա仯���� 
        power1 = BigDisPowerCutDown; //���ϻָ���,���Ա仯���� 
        FirstOn=1; 
        BiggestDisCurtContinuous=DischagerCurtCutDone(ReduceCurt,BigDisPower,DISCURT5min);
        return BiggestDisCurtContinuous; 
    
    }
    if(FirstOn==0) //��һ�ν���
    {
        pc=BigDisPower; 
        power1 = BigDisPower; 
        FirstOn=1;         
    } 
    else//�ٴν���
    {
        if(changeFlag==0)//ԭֵΪ0������power2Ϊ�ڶ��ν���ú���ʱ��ֵ
            power2=BigDisPower;
     
        if(power1!=power2) //������߲��ȣ�˵����һ��ڶ��β���
        {
            changeFlag=1;//���ñ仯��־λ
            if(power1>power2) 
            {
                pc=power1-POWERSPEED;// ÿ20ms�仯0.5kw,7ms����һ�Σ�21ms����0.51KW
                power1=pc;
                if(power1<=power2)
                {
                    
                    pc=power2;
                    changeFlag=0; 
                }
            }
            else if(power1<power2) 
            {
                pc=power1+POWERSPEED;// ÿ5ms�仯0.05kw
                power1=pc;
                if(power1>=power2) 
                {
                    
                    pc=power2;
                    changeFlag=0;
                }
            }
        } 
        else 
        {
            changeFlag=0; 
        }
    
    } 
 
    return pc; 
    
}
*/
//***********************************************************************************************
//************************************************************************************************
//************************************the end*****************************************************
//************************************************************************************************
//***********************************************************************************************
//************************************************************************************************