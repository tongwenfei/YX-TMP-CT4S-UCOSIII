/*
*********************************************************************************************************
*                                               
* File        : TempControlTask.c
* By          : Wenfei Tong
* Version     : V1.0
* Date        : 03-08-2016
* Description :
* ---------------
*   �¶ȿ���������,�¶ȷ�Χ(15��~30��)��PWM����
*********************************************************************************************************
*/
#include "include.h"
OS_TCB TempControlTaskTCB;
//�����ջ	
CPU_STK TEMPCONTROL_TASK_STK[TEMPCONTROL_STK_SIZE];
void TempControlTask(void *pdata)
{
  OS_ERR err;
  pdata=pdata;
  while(1)
  {
   
     ADS1248_StartConvert();
     ADS1248_2_StartConvert();

     PT100_Temp[0]=ADS1248_ResToTemp(ADS1248_ReadADC()/ 24672.376470588235294117647058824);

     PT100_Temp[1]=ADS1248_2_ResToTemp(ADS1248_2_ReadADC()/ 24672.376470588235294117647058824);
     
    TEM_Compare(&TempPID_struct,PT100_Temp[0]);
    
   OSTimeDlyHMSM(0,0,0,500,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ500ms
  }
}

void CreateTempControlTask(void)
{
  OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&TempControlTaskTCB,		//������ƿ�
               (CPU_CHAR  *)"TempControl Task", 		//��������
               (OS_TASK_PTR)TempControlTask, 			//������
               (void      *)0,					//���ݸ��������Ĳ���
               (OS_PRIO     )TEMPCONTROL_TASK_PRIO,     //�������ȼ�
               (CPU_STK   * )&TEMPCONTROL_TASK_STK[0],	//�����ջ����ַ
               (CPU_STK_SIZE)TEMPCONTROL_STK_SIZE/10,	//�����ջ�����λ
               (CPU_STK_SIZE)TEMPCONTROL_STK_SIZE,		//�����ջ��С
               (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
               (OS_TICK	    )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
               (void      *)0,					//�û�����Ĵ洢��
               (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
               (OS_ERR     *)&err);	
}