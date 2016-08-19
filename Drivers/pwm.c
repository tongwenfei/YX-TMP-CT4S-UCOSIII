/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			pwm.c
 *Description��     	       ʵ�ֶԼ��ȵ�PWM����
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"


/*
********************************************************************************
�������ƣ�void PWM_Configuration(float pulse)
�������ܣ�PWMΪTIM4_CH3  PB8
��ڲ�����Ƶ��100HZ  pulse��0~1      ��Ӧ0% ~ 100%ռ�ձ�
���ڲ�������
********************************************************************************
*/
void PWM_Configuration(float pulse)
{
    uint16_t pu = 0;
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    
    if(pulse == 0)
    {
        pu = 7201;
    }
    else if(pulse == 1)
    {
        pu = 1;
    }
    else
    {
        pu = 7200-(uint16_t)(7200 * pulse);
    }

    //����ʹ�õ�PB8
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;             
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /*ʱ������*/
    TIM_TimeBaseStructure.TIM_Period = 7200-1;                      //1K
    TIM_TimeBaseStructure.TIM_Prescaler = 100-1;                    //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ100hz
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;                    //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;     //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);                 //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
    
    /*PWM����*/
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;               //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //�Ƚ����ʹ��
    TIM_OCInitStructure.TIM_Pulse = (pu-1);                         //���ô�װ�벶��ȽϼĴ���������ֵ������ռ�ձ�100%
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //�������:TIM����Ƚϼ��Ը�
    TIM_OC3Init(TIM4, &TIM_OCInitStructure);                        //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);               //ʹ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ���
    
    TIM_ARRPreloadConfig(TIM4, ENABLE);                             //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
    
    /*��ʱ��ʹ��*/
    TIM_Cmd(TIM4, ENABLE);                                          //ʹ��TIMx����
}

/*
********************************************************************************
�������ƣ�void PID_Init(PID *pp)
�������ܣ�ʵ��PID�ĳ�ʼ�����ռ�����
��ڲ�����PID�ṹ��
���ڲ�������
********************************************************************************
*/
void PID_Init(PID *pp) 
{ 
    uint8_t heat_temp = 0;
    memset(pp,0,sizeof(PID)); 
    FM24C64_READ_MUL(HEAT_TEMP,(uint8_t*)&heat_temp,1);
    //д��PID������
    Pid.SetPoint = heat_temp;
    pp->Proportion = 0.05;      //���ñ���ϵ��0.05
    pp->Integral = 0.0003;     //���û���ϵ��0.0003
    pp->Derivative = 0.00;     //����΢��ϵ��0.00
} 

/*
********************************************************************************
�������ƣ�uint16_t PID_Calculation(PID *pp,float NextPoint) 
�������ܣ�ʵ��PID�ļ���
��ڲ�����PID�ṹ�壬NextPoint��ǰ�¶�ֵ
���ڲ�������������ϵ��0~1
********************************************************************************
*/
float PID_Calculation(PID *pp,float NextPoint) 
{ 
    //m(t)=Kp*e(n)+Ki*{e(1)+e(2)+...+e(n)}+Kd{e(n-1)-e(n-2)}
    float dError = 0;
    float Error = 0; 
    Error = pp->SetPoint - NextPoint;       //ƫ�� = �����¶�ֵ - ��ǰ����¶�ֵ
    pp->SumError += Error;                  //��ƫ����л��ֵ���
    dError = pp->LastError - pp->PrevError; //΢�� = ��ǰƫ�-1�� - ��һ��ƫ�-2�� 
    pp->PrevError = pp->LastError;          //�ѵ�ǰƫ�����һ��ƫ��
    pp->LastError = Error;                  //��
    
    return (pp->Proportion * Error          //����
    + pp->Integral * pp->SumError           //������
    + pp->Derivative * dError);             //΢���� 
} 

/*
********************************************************************************
�������ƣ�void PID_Compare_Temperature(void)
�������ܣ�ʵ���¶ȵıȽϴ���
��ڲ�����PID�ṹ�壬NextPoint��ǰ�¶�ֵ
���ڲ�������
********************************************************************************
*/
void PID_Compare_Temperature(PID *pp,float NextPoint) 
{ 
    static uint8_t pid_flag = 0;
    /*����ֵ-����ֵ > 1*/
    if(NextPoint > 70)
    {
        pp->Value = 0;
        PWM_Configuration(pp->Value);               //PWMͨ��PIDֵ�����������
        pp->SumError = 0;
        pid_flag = 1;
    }
    if(NextPoint < 60)
    {
        pid_flag = 0;
    }
    if(pid_flag == 0)
    {
        if(pp->SetPoint - NextPoint > 8) 
        { 
            pp->Value = 1;
        } 
        else 
        { 
            pp->Value = PID_Calculation(pp,NextPoint);//PIDֵ����
            if(pp->Value > 1)
            {
                pp->Value = 1;
            }
            else if(pp->Value < 0)
            {
                pp->Value = 0;
            }
        } 
        PWM_Configuration(pp->Value);               //PWMͨ��PIDֵ�����������
    }
} 