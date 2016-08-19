/*
*********************************************************************************************************
*                                               
* File        : TempPressPressTask.c
* By          : Wenfei Tong
* Version     : V1.0
* Date        : 03-08-2016
* Description :
* ---------------
*   ��ȡMS5611����������ѹֵ���¶�ֵ
*********************************************************************************************************
*/
#include "include.h"

//������ƿ�
OS_TCB TempPressTaskTCB;
//�����ջ	
 CPU_STK TEMPPRESS_TASK_STK[TEMPPRESS_STK_SIZE];
//������
void TempPressTask(void *p_arg);
void TempPressTask(void *pdata)
{
  OS_ERR err;
  pdata=pdata;
  while(1)
  {
   
    MS5611_Temp=MS561101BA_Temperature_Read();  
    MS5611_Press=MS561101BA_Pressure_Read();
   
    
    
     OSTimeDlyHMSM(0,0,0,500,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ500ms
  }
}

void CreateTempPressTask(void)
{
  OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&TempPressTaskTCB,		//������ƿ�
               (CPU_CHAR  *)"TempPress Task", 		//��������
               (OS_TASK_PTR)TempPressTask, 			//������
               (void      *)0,					//���ݸ��������Ĳ���
               (OS_PRIO     )TEMPPRESS_TASK_PRIO,     //�������ȼ�
               (CPU_STK   * )&TEMPPRESS_TASK_STK[0],	//�����ջ����ַ
               (CPU_STK_SIZE)TEMPPRESS_STK_SIZE/10,	//�����ջ�����λ
               (CPU_STK_SIZE)TEMPPRESS_STK_SIZE,		//�����ջ��С
               (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
               (OS_TICK	    )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
               (void      *)0,					//�û�����Ĵ洢��
               (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
               (OS_ERR     *)&err);	
}