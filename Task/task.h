/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			task.h
 *Description��     	        ������������
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __TASK_H__
#define __TASK_H__
//��ʼ����  
#define START_TASK_PRIO	        	3
//�����ջ��С	
#define START_STK_SIZE 		        64

//������
#define MAIN_TASK_PRIO		        7
//�����ջ��С	
#define MAIN_STK_SIZE 		        64

//GUI����
#define GUI_TASK_PRIO		        5
//�����ջ��С	
#define GUI_STK_SIZE 		        256

#define USART_TASK_PRIO		        6
//�����ջ��С	
#define USART_STK_SIZE 		        256

//RTC����
#define RTC_TASK_PRIO		        8
//�����ջ��С	
#define RTC_STK_SIZE 		        96

//�����������
#define BATTER_TASK_PRIO		9
//�����ջ��С	
#define BATTER_STK_SIZE 		64

//������������
#define FLOWCONTROL_TASK_PRIO		10
//�����ջ��С	
#define FLOWCONTROL_STK_SIZE 		128

//�¶ȼ������
#define TEMP_TASK_PRIO		        11
//�����ջ��С	
#define TEMP_STK_SIZE 		        64

//�¶ȼ������
#define  TEMPCONTROL_TASK_PRIO          12          
#define  TEMPCONTROL_STK_SIZE 	        128       

//�����������
#define KEY_TASK_PRIO	        	4
//�����ջ��С	
#define KEY_STK_SIZE 	        	96

//��ѹ�������
#define TEMPPRESS_TASK_PRIO		14
//�����ջ��С	
#define TEMPPRESS_STK_SIZE 		64
extern OS_Q KEY_Msg;	
extern OS_TMR	tmr1;	//����һ����ʱ��
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
void tmr1_callback(void *p_tmr,void *p_arg); //��ʱ��1�ص�����
#endif