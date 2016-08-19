/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			pwm.c
 *Description：     	       实现对加热的PWM操作
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"


/*
********************************************************************************
函数名称：void PWM_Configuration(float pulse)
函数功能：PWM为TIM4_CH3  PB8
入口参数：频率100HZ  pulse：0~1      对应0% ~ 100%占空比
出口参数：无
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

    //配置使用的PB8
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;             
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /*时钟配置*/
    TIM_TimeBaseStructure.TIM_Period = 7200-1;                      //1K
    TIM_TimeBaseStructure.TIM_Prescaler = 100-1;                    //设置用来作为TIMx时钟频率除数的预分频值100hz
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;                    //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;     //TIM向上计数模式
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);                 //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
    
    /*PWM配置*/
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;               //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //比较输出使能
    TIM_OCInitStructure.TIM_Pulse = (pu-1);                         //设置待装入捕获比较寄存器的脉冲值，设置占空比100%
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //输出极性:TIM输出比较极性高
    TIM_OC3Init(TIM4, &TIM_OCInitStructure);                        //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);               //使能TIMx在CCR3上的预装载寄存器
    
    TIM_ARRPreloadConfig(TIM4, ENABLE);                             //使能TIMx在ARR上的预装载寄存器
    
    /*定时器使能*/
    TIM_Cmd(TIM4, ENABLE);                                          //使能TIMx外设
}

/*
********************************************************************************
函数名称：void PID_Init(PID *pp)
函数功能：实现PID的初始化，空间清零
入口参数：PID结构体
出口参数：无
********************************************************************************
*/
void PID_Init(PID *pp) 
{ 
    uint8_t heat_temp = 0;
    memset(pp,0,sizeof(PID)); 
    FM24C64_READ_MUL(HEAT_TEMP,(uint8_t*)&heat_temp,1);
    //写入PID设置中
    Pid.SetPoint = heat_temp;
    pp->Proportion = 0.05;      //设置比例系数0.05
    pp->Integral = 0.0003;     //设置积分系数0.0003
    pp->Derivative = 0.00;     //设置微分系数0.00
} 

/*
********************************************************************************
函数名称：uint16_t PID_Calculation(PID *pp,float NextPoint) 
函数功能：实现PID的计算
入口参数：PID结构体，NextPoint当前温度值
出口参数：返回脉宽系数0~1
********************************************************************************
*/
float PID_Calculation(PID *pp,float NextPoint) 
{ 
    //m(t)=Kp*e(n)+Ki*{e(1)+e(2)+...+e(n)}+Kd{e(n-1)-e(n-2)}
    float dError = 0;
    float Error = 0; 
    Error = pp->SetPoint - NextPoint;       //偏差 = 设置温度值 - 当前检测温度值
    pp->SumError += Error;                  //对偏差进行积分叠加
    dError = pp->LastError - pp->PrevError; //微分 = 当前偏差【-1】 - 上一次偏差【-2】 
    pp->PrevError = pp->LastError;          //把当前偏差赋给上一个偏差
    pp->LastError = Error;                  //把
    
    return (pp->Proportion * Error          //比例
    + pp->Integral * pp->SumError           //积分项
    + pp->Derivative * dError);             //微分项 
} 

/*
********************************************************************************
函数名称：void PID_Compare_Temperature(void)
函数功能：实现温度的比较处理
入口参数：PID结构体，NextPoint当前温度值
出口参数：无
********************************************************************************
*/
void PID_Compare_Temperature(PID *pp,float NextPoint) 
{ 
    static uint8_t pid_flag = 0;
    /*设置值-测量值 > 1*/
    if(NextPoint > 70)
    {
        pp->Value = 0;
        PWM_Configuration(pp->Value);               //PWM通过PID值进行脉宽调整
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
            pp->Value = PID_Calculation(pp,NextPoint);//PID值计算
            if(pp->Value > 1)
            {
                pp->Value = 1;
            }
            else if(pp->Value < 0)
            {
                pp->Value = 0;
            }
        } 
        PWM_Configuration(pp->Value);               //PWM通过PID值进行脉宽调整
    }
} 