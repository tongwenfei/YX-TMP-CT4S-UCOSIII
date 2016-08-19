/*
*********************************************************************************************************                                              
* File        : PID.c
* By          : Wenfei Tong
* Version     : V1.0
* Date        : 03-08-2016
* Description :
* ---------------
*   PID���ƺ�������������PID���Ƶ��ں�����PWM����
*********************************************************************************************************
*/
#include "include.h"
/*
********************************************************************************
�������ƣ�void TEM_PID_ReSet(PID_STRUCT *pp)
�������ܣ�ʵ��PID�ģ��ռ�����
��ڲ�����PID�ṹ��
���ڲ�������
********************************************************************************
*/
void TEM_PID_ReSet(PID_STRUCT *pp) 
{ 
  memset(pp,0,sizeof(PID_STRUCT));     
}
/*
********************************************************************************
�������ƣ�void TEM_PID_Configuration(PID_STRUCT *pp,float goal,float P,float I,float D)
�������ܣ�ʵ��PID�ĳ�ʼ������
��ڲ�����PID�ṹ�壬goalĿ���¶ȣ�����P��I��D������ϵ��������ϵ��������ϵ����
���ڲ�������
********************************************************************************
*/
void TEM_PID_Configuration(PID_STRUCT *pp)
{
  pp->SetPoint = 20;			//��ʼ������ȫ��
  pp->Proportion = 10;      //���ñ���ϵ��0.05
  pp->Integral = 0.5;     //���û���ϵ��0.0003
  pp->Derivative = 0;     //���û���ϵ��0.00
}
/*
********************************************************************************
�������ƣ�float TEM_PID_Calculation(PID_STRUCT *pp,float NowTem)  
�������ܣ�ʵ��PID�ļ���
��ڲ�����PID�ṹ��,NowTem��ǰ�������¶�
���ڲ���������ռ�ձ�ϵ��0~1

����ʽPID�����㷨
m(t)=Kp*e(t-1)+Ki*[e(1)+e(2)+...+e(t)}+Kd{e(t-1)-e(t-2)]
Ki = Kp*T/Ti Ϊ����ϵ��		Kd = Kp*Td/T Ϊ΢��ϵ��
PID����Ҫ���ں��Ա�֤���ռ�ձ�ϵ��0-1
********************************************************************************
*/
float TEM_PID_Calculation(PID_STRUCT *pp,float NowTem) 
{ 
  //m(t)=Kp*e(n)+Ki*{e(1)+e(2)+...+e(n)}+Kd{e(n-1)-e(n-2)}
  float Error = 0; 
  Error = (pp->SetPoint - NowTem)*100;        //ƫ�� = �趨����-��ǰ����
  pp->Value=pp->Proportion *(Error-pp->LastError)\
           +pp->Integral * Error\
           +pp->Derivative *(Error-2*pp->LastError+pp->PrevError);
  pp->PrevError = pp->LastError;          //�ѵ�ǰƫ�����һ��ƫ��
  pp->LastError = Error;                  //��
  
  return (pp->Value);             
} 

/*
********************************************************************************
�������ƣ�void TEM_PWM_Init(void)
�������ܣ�ʵ��TIM1��CH1��PA8����CH2(PA9)ͨ�����PWM�������Ƽ�������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void TEM_PWM_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;             
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
   

  
   TIM_TimeBaseStructure.TIM_Prescaler = 71;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_Period = 999;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

  /* Channel 1, 2,3 and 4 Configuration in PWM mode */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;
  TIM_OC2Init(TIM1, &TIM_OCInitStructure);

  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC3Init(TIM1, &TIM_OCInitStructure);

 

  /* TIM1 counter enable */
  TIM_Cmd(TIM1, ENABLE);

  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM1, ENABLE);
  TEM_PID_Configuration(&TempPID_struct);
}
/*
********************************************************************************
�������ƣ�void TEM_SetDuty(uint8_t state,uint16_t duty)
�������ܣ�ʵ��PWM�����������ã����PID�����¶�
��ڲ�����state 0:Ĭ�ϼ��ȹ��ܣ� 1�����书��; duty:0~1000��Ӧ0�� ~ 1000��ռ�ձ�
���ڲ�������
********************************************************************************
*/
void TEM_SetDuty(uint8_t state,uint16_t duty)
{
  if(state)
  {
    TIM_SetCompare3(TIM1,0);
    TIM_SetCompare2(TIM1,duty);
  }
  else 
  {
    TIM_SetCompare2(TIM1,0);
    TIM_SetCompare3(TIM1,duty);
  }
}
/*
********************************************************************************
�������ƣ�void TEM_PWM_ReSet(void)
�������ܣ��ر��¶ȿ��ƹ���
��ڲ�������
���ڲ�������
********************************************************************************
*/
void TEM_PWM_ReSet(void)
{
  TIM_SetCompare2(TIM1,0);
  TIM_SetCompare3(TIM1,0);
}
/*
********************************************************************************
�������ƣ�void TEM_Compare(PID_STRUCT *pp,float NowTem)
�������ܣ��趨�¶ȺͲ����¶Ƚ��бȽϣ�Ȼ�󾭹�PID�����ת��ΪPWM������
��ڲ�����PID�ṹ�壬�����¶�
���ڲ�������
********************************************************************************
*/
void TEM_Compare(PID_STRUCT *pp,float NowTem)
{
  
  //static uint8_t pid_flag=0;
  if((pp->SetPoint-NowTem)>1)                                 //�����¶ȵ����趨�¶�7�����ϣ����ؼ���
  {
    TEM_SetDuty(HOT,1000);
  }
  else if((NowTem-pp->SetPoint)>1)                            //�����¶ȸ����趨�¶�7�����ϣ���������
  {
    TEM_SetDuty(COOL,1000);
  }
  else if(((pp->SetPoint-NowTem)<=1)&&\
           ((pp->SetPoint-NowTem)>=0.2)) //�����¶ȵ����趨�¶�1��~7�����ڣ�PID���ڼ���
  {
    TEM_PID_Calculation(pp,NowTem);
//   if(pp->Value>1)temp_data=1;
//    else if(pp->Value<0)temp_data=0;
//    else temp_data=pp->Value;
     TEM_SetDuty(HOT,(uint16_t)(250+250*pp->Value));
  }
  else if(((NowTem-pp->SetPoint)<=1)&&\
           ((NowTem-pp->SetPoint)>=0.2)) //�����¶ȸ����趨�¶�1��~7�����ڣ�PID��������
  {
    TEM_PID_Calculation(pp,NowTem);
//    if(pp->Value>1)temp_data=1;
//    else if(pp->Value<0)temp_data=0;
//    else temp_data=pp->Value;
     TEM_SetDuty(COOL,(uint16_t)(750+250*pp->Value));
  }
  else if(((NowTem-pp->SetPoint)<0.2)&&((NowTem-pp->SetPoint)>-0.2))   //�����¶ȸ��������¶�1���ں��¿��ƣ�����΢�����䣩
  {
    TEM_SetDuty(COOL,CONST_COOL);
  }
  else if(((pp->SetPoint-NowTem)<0.2)&&((pp->SetPoint-NowTem)>-0.2))   //�����¶ȵ��������¶�1���ں��¿��ƣ�����΢�����ȣ�
  {
    TEM_SetDuty(HOT,CONST_HOT);
  }
  else   TEM_PWM_ReSet();                                          //ֹͣ��������
    
}