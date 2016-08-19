/*--------------------------PID.H----------------------*/
#ifndef 	__FLOW_PID_H__
#define 	__FLOW_PID_H__
#include "sys.h"
typedef struct 
{ 
    float SetPoint;            // �趨Ŀ�� Desired Value 
    float Proportion;          // �������� Proportional Const 
    float Integral;            // ���ֳ��� Integral Const 
    float Derivative;          // ΢�ֳ��� Derivative Const 
    float LastError;           // Error[-1] 
    float PrevError;           // Error[-2] 
    float SumError;            // Sums of Errors 
    float Flow_Value;          // �����������������������ֵ
    float Value;               // ������������ѹֵ
    float Clac_Value;          //PID������PWM����           
}PID_STRUCT; 
typedef enum 
{
  Flow_CH_None  =0,
  Flow_CH1      =1,
  Flow_CH2      =2,
  Flow_CH2_1    =3,
  Flow_CH3      =4,
  Flow_CH3_1    =5,
  Flow_CH3_2    =6,
  Flow_CH3_2_1  =7,
  Flow_CH4      =8,
  Flow_CH4_1    =9,
  Flow_CH4_2    =10,
  Flow_CH4_2_1  =11,
  Flow_CH4_3    =12,
  Flow_CH4_3_1  =13,
  Flow_CH4_3_2  =14,
  Flow_CH4_3_2_1=15
}FLOW_CHN;
typedef struct
{
  uint8_t NumFlow;
  FLOW_CHN Flow_CH;
  uint16_t Flow_Duty1;
  uint16_t Flow_Duty2;
  uint16_t Flow_Duty3;
  uint16_t Flow_Duty4;
}FLOW_STRUCT;
extern void Flow_PWM_Config(FLOW_STRUCT *FLOW);
extern void Flow_PID_Init(PID_STRUCT* FlowPID);
extern float	Flow_PID_Calculation(PID_STRUCT *pp,float NextPoint);
void Flow_PWM_Init(void);

#endif