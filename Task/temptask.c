/*
*********************************************************************************************************
*                                               
* File        : TemTask.c
* By          : Wenfei Tong
* Version     : V1.0
* Date        : 03-08-2016
* Description :
* ---------------
*   �¶ȿ���������,�¶ȷ�Χ(15��~30��)��PWM����
*********************************************************************************************************
*/
#include "include.h"


//������ƿ�
OS_TCB TempTaskTCB;
//�����ջ	
 CPU_STK TEMP_TASK_STK[TEMP_STK_SIZE];
//������
void TempTask(void *p_arg);
float curr_data;


void TempTask(void *pdata)
{
   OS_ERR err;
  pdata=pdata;
  uint16_t temp[30]={0};
  while(1)
  {
    Ambience_Temp=DS18B20_Get_Temp();//������ǰ�¶�
    
    //TEM_Compare(&TEMPID,TemNow);
    curr_data=(Get_AverageValue2(temp,3)-0x3000)*0.061279296875;
    OSTimeDlyHMSM(0,0,1,0,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ500ms
  }
}

void CreateTempTask(void)
{
   OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&TempTaskTCB,		//������ƿ�
               (CPU_CHAR  *)"Temp Task", 		//��������
               (OS_TASK_PTR)TempTask, 			//������
               (void      *)0,					//���ݸ��������Ĳ���
               (OS_PRIO     )TEMP_TASK_PRIO,     //�������ȼ�
               (CPU_STK   * )&TEMP_TASK_STK[0],	//�����ջ����ַ
               (CPU_STK_SIZE)TEMP_STK_SIZE/10,	//�����ջ�����λ
               (CPU_STK_SIZE)TEMP_STK_SIZE,		//�����ջ��С
               (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
               (OS_TICK	    )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
               (void      *)0,					//�û�����Ĵ洢��
               (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
               (OS_ERR     *)&err);				//��Ÿú�������ʱ�ķ���ֵ
}