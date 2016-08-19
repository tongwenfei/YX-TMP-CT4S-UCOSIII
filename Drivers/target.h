/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			target.c
 *Description：     	        实现目标板的初始化
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __TARGET_H__
#define __TARGET_H__


/**********************宏定义部分*****************************/
#define     WDOG_WDI	        GPIO_Pin_6
#define     WDI_H()		PEout(6)=1
#define     WDI_L()		PEout(6)=0

//运行灯
#define     PC13_LED	        GPIO_Pin_13
#define     LED_ON()		PCout(13)=0
#define     LED_OFF()		PCout(13)=1

#define     PUMP1_ON()		PEout(2)=1
#define     PUMP1_OFF()		PEout(2)=0

#define     PUMP2_ON()		PEout(3)=1
#define     PUMP2_OFF()		PEout(3)=0

#define     PUMP3_ON()		PEout(4)=1
#define     PUMP3_OFF()		PEout(4)=0

#define     PUMP4_ON()		PEout(5)=1
#define     PUMP4_OFF()		PEout(5)=0
#define nop() __no_operation()

/**********************函数部分*****************************/

extern void LED_Init(void);
extern void WDOG_Init(void);
extern void Feed_Dog(void);
extern void Target_Init(void);
extern void RCC_Config (void);
extern void Delay_Nus(uint32_t t);
extern void Delay10us(uint32_t m);
extern void Delayms(uint32_t m);
extern uint32_t OS_CPU_SysTickClkFreq(void);
void Pump_IOinit(void);
#endif
