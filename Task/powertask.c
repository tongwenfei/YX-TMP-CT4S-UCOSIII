/*******************************************************************************
*CopyRight Reserved:	
*Filename��			powertask.C
*Description��     	        ��Դ����
*Date:
*Author:		
*******************************************************************************/

#include "include.h"

/*
********************************************************************************
�������ƣ�void POWERTask(void *pdata)
�������ܣ�POWER������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void POWERTask(void *pdata)
{
  
  pdata=pdata;
  while(1)
  {  
    System_Power=ReadADCAverageValue();
    //�ж����޵�Դ
    if(System_Power.pc1_adc11_power > 14)
    {
      Power_flag = 1;           //��Դ���ڱ�־
    }
    else
    {
      Power_flag = 0;
    }
    if(System_Power.pc1_adc11_power > 11)Batter_flag=1;
    else Batter_flag=0;
    OSTimeDly(200);
    
  }
}

/*
********************************************************************************
�������ƣ�void CreatePOWERTask(void)
�������ܣ�����POWER������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void CreatePOWERTask(void)
{
  OSTaskCreateExt(
                  POWERTask,
                  (void *)0,
                  &POWERTaskStk[TASK_POWER_STK_SIZE-1],
                  POWERTaskPrio,
                  0,
                  &POWERTaskStk[0],
                  TASK_POWER_STK_SIZE,
                  (void *)0,
                  OS_TASK_OPT_STK_CHK+OS_TASK_OPT_STK_CLR
                    );
  
}
