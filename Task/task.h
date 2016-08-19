/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			task.h
 *Description：     	        定义所有任务
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __TASK_H__
#define __TASK_H__
//开始任务  
#define START_TASK_PRIO	        	3
//任务堆栈大小	
#define START_STK_SIZE 		        64

//主任务
#define MAIN_TASK_PRIO		        7
//任务堆栈大小	
#define MAIN_STK_SIZE 		        64

//GUI任务
#define GUI_TASK_PRIO		        5
//任务堆栈大小	
#define GUI_STK_SIZE 		        256

#define USART_TASK_PRIO		        6
//任务堆栈大小	
#define USART_STK_SIZE 		        256

//RTC任务
#define RTC_TASK_PRIO		        8
//任务堆栈大小	
#define RTC_STK_SIZE 		        96

//电量检测任务
#define BATTER_TASK_PRIO		9
//任务堆栈大小	
#define BATTER_STK_SIZE 		64

//流量控制任务
#define FLOWCONTROL_TASK_PRIO		10
//任务堆栈大小	
#define FLOWCONTROL_STK_SIZE 		128

//温度检测任务
#define TEMP_TASK_PRIO		        11
//任务堆栈大小	
#define TEMP_STK_SIZE 		        64

//温度检测任务
#define  TEMPCONTROL_TASK_PRIO          12          
#define  TEMPCONTROL_STK_SIZE 	        128       

//按键检测任务
#define KEY_TASK_PRIO	        	4
//任务堆栈大小	
#define KEY_STK_SIZE 	        	96

//气压检测任务
#define TEMPPRESS_TASK_PRIO		14
//任务堆栈大小	
#define TEMPPRESS_STK_SIZE 		64
extern OS_Q KEY_Msg;	
extern OS_TMR	tmr1;	//定义一个定时器
void CreateMainTask(void);
void CreateTempTask(void);
void CreateGUITask(void);
void CreateTempPressTask(void);
void CreateRTCTask(void);
void CreateKeyTask(void);
void CreateBATTERTask(void);
void CreateFlowControlTask(void);
void CreateTempControlTask(void);
void CreateUsartTask(void);
void tmr1_callback(void *p_tmr,void *p_arg); //定时器1回调函数
#endif