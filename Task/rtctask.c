/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			rtctask.c
 *Description��     	        ʵʱʱ������
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

//������ƿ�
OS_TCB RTCTaskTCB;
//�����ջ	
 CPU_STK RTC_TASK_STK[RTC_STK_SIZE];
//������
void RTCTask(void *p_arg);
/*
********************************************************************************
�������ƣ�void RTCTask(void *pdata)
�������ܣ�RTC������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void RTCTask(void *pdata)
{
   OS_ERR err;
    pdata=pdata;
    while(1)
    {
       // g_RTCTime = PCF8563_Read_Time(); 
      Ds1302_Read_Time();//��ȡʱ��
      OSTimeDlyHMSM(0,0,0,200,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ500ms
    }
}

/*
********************************************************************************
�������ƣ�void CreateRTCTask(void)
�������ܣ������¶���ѹ������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void CreateRTCTask(void)
{
     OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&RTCTaskTCB,		//������ƿ�
               (CPU_CHAR  *)"RTC Task", 		//��������
               (OS_TASK_PTR)RTCTask, 			//������
               (void      *)0,					//���ݸ��������Ĳ���
               (OS_PRIO     )RTC_TASK_PRIO,     //�������ȼ�
               (CPU_STK   * )&RTC_TASK_STK[0],	//�����ջ����ַ
               (CPU_STK_SIZE)RTC_STK_SIZE/10,	//�����ջ�����λ
               (CPU_STK_SIZE)RTC_STK_SIZE,		//�����ջ��С
               (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
               (OS_TICK	    )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
               (void      *)0,					//�û�����Ĵ洢��
               (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
               (OS_ERR     *)&err);	

}