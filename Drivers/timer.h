#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
#include "global.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   


void TIM6_Int_Init(u16 arr,u16 psc);
void TIM6_Start(void);
void TIM6_Pause(void);
void TIM6_Stop(void);
#endif
