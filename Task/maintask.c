/*******************************************************************************
*CopyRight Reserved:	
*Filename��			maintask.c
*Description��     	        ������
*Date:
*Author:		
*******************************************************************************/
#define MAITASK_C
#include "include.h"

//�������ȼ�

//������ƿ�
OS_TCB MainTaskTCB;
//�����ջ	
 CPU_STK MAIN_TASK_STK[MAIN_STK_SIZE];
//������
void MainTask(void *p_arg);
/*
********************************************************************************
�������ƣ�void MainTask(void *pdata)
�������ܣ���������
��ڲ�������
���ڲ�������
********************************************************************************
*/



void MainTask(void *p_arg)
{
  OS_ERR err;
  
  p_arg = p_arg;
  
  
  //����ι��
  //  OS_CRITICAL_ENTER();	//�����ٽ���
  //  CreateRTCTask();
  //  CreateKeyTask();
  //  CreateTempControlTask();
  //  CreateTempPressTask();
  //  CreateTemTask();
  //  CreateGUITask();
  //  CreateADTask();
  //  CreatePOWERTask();
  //  OS_CRITICAL_EXIT();	//�����ٽ���
  //  Disp_SampWindow();
  //  Disp_Sys_Info();
  //  Disp_Data();
  //  Disp_DetailWindow();
  //  Disp_ConfigWindow();
  //  Disp_SetWindow();
  while(1)
  {
    
    LED_ON();
   
    //   
    Feed_Dog();                 //����ι��
    OSTimeDlyHMSM(0,0,0,500,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ500ms
    //    
//    test[0]=ADC1_GetValue(3);
//    test[1]=ADC2_GetValue(3);
    
    LED_OFF();
    
    Feed_Dog();                 //����ι��
    OSTimeDlyHMSM(0,0,0,500,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ500ms
  }
}

/*
********************************************************************************
�������ƣ�void CreateMainTask(void)
�������ܣ�����������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void CreateMainTask(void)
{
  OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&MainTaskTCB,		//������ƿ�
               (CPU_CHAR  *)"Main Task", 		//��������
               (OS_TASK_PTR)MainTask, 			//������
               (void      *)0,					//���ݸ��������Ĳ���
               (OS_PRIO     )MAIN_TASK_PRIO,     //�������ȼ�
               (CPU_STK   * )&MAIN_TASK_STK[0],	//�����ջ����ַ
               (CPU_STK_SIZE)MAIN_STK_SIZE/10,	//�����ջ�����λ
               (CPU_STK_SIZE)MAIN_STK_SIZE,		//�����ջ��С
               (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
               (OS_TICK	    )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
               (void      *)0,					//�û�����Ĵ洢��
               (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
               (OS_ERR     *)&err);				//��Ÿú�������ʱ�ķ���ֵ
  
}