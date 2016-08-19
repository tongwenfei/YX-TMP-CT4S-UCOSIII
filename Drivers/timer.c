#include "timer.h"

//������ʱ��6�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��6!
uint32_t Definite_Count[4]={0};
bool isPause=false;
uint16_t cnt_buf=0;
void TIM6_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE); //��ʱ��6ʱ��ʹ��
  
  TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //���÷�Ƶֵ��10khz�ļ���Ƶ��
  TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
  TIM_TimeBaseInitStructure.TIM_Period=arr;  //�Զ���װ��ֵ ������5000Ϊ500ms
  TIM_TimeBaseInitStructure.TIM_ClockDivision=0; //ʱ�ӷָ�:TDS=Tck_Tim
  TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitStructure);
  
  TIM_ITConfig(TIM6,TIM_IT_Update|TIM_IT_Trigger,ENABLE); //ʹ��TIM6�ĸ����ж�
  
  NVIC_InitStructure.NVIC_IRQChannel=TIM6_IRQn; //TIM6�ж�
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1; //��ռ���ȼ�1��
  NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;  //�����ȼ�3��
  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE; //ʹ��ͨ��
  NVIC_Init(&NVIC_InitStructure);
  
  TIM_Cmd(TIM6,DISABLE); //��ʱ��6ʹ��
  isPause=true;
  cnt_buf=0;
}


void TIM6_IRQHandler(void)
{
  if(TIM_GetITStatus(TIM6,TIM_IT_Update)!=RESET)
  {
    if(Sampling_State[0]==Runing)
    {
      Definite_Count[0]++;
    }
    if(Sampling_State[1]==Runing)
    {
      Definite_Count[1]++;
    }
    if(Sampling_State[2]==Runing)
    {
      Definite_Count[2]++;
    }
    if(Sampling_State[3]==Runing)
    {
      Definite_Count[3]++;
    }
    
  }
  TIM_ClearITPendingBit(TIM6,TIM_IT_Update); //����жϱ�־λ
}
void TIM6_Start(void)
{
  if(!((TIM6->CR1)&TIM_CR1_CEN))
  {
    if(isPause)
    {
      TIM_Cmd(TIM6,ENABLE); //��ʱ��6ʹ��
      TIM_SetCounter(TIM6,cnt_buf);
      isPause=false;
    }
    else
    {
      TIM_Cmd(TIM6,ENABLE); //��ʱ��6ʹ��
      TIM_SetCounter(TIM6,0);
      isPause=false;
    }
  }
  
}
void TIM6_Pause(void)
{
  if(((TIM6->CR1)&TIM_CR1_CEN))
  {
    TIM_Cmd(TIM6,DISABLE); //��ʱ��6ʹ��
    cnt_buf=TIM_GetCounter(TIM6);
    isPause=true;
  }
  
}
void TIM6_Stop(void)
{
  if(((TIM6->CR1)&TIM_CR1_CEN))
  {
    TIM_Cmd(TIM6,DISABLE); //��ʱ��6ʹ��
    TIM_SetCounter(TIM6,0);
    cnt_buf=0;
  }
}

void Start_Sampling(void)
{
  

}

void Pause_Sampling(void)
{
  
}
void Stop_Sampling(void)
{
  
}