/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			functiontask.C
 *Description��     	        ��ع�������
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/*
********************************************************************************
�������ƣ�void FUNTask(void *pdata)
�������ܣ�FUN������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void FUNTask(void *pdata)
{
    pdata=pdata;
    while(1)
    {  
        g_Power = ReadADCAverageValue();
        if(g_Power.pb0_adc8_power > 13)
        {
            Power_flag = 1;
            PD2_BATCON_OFF();         //�رյ�ع������ÿ���
        }
        else
        {
            Power_flag = 0;
            PD2_BATCON_ON();         //�򿪵�ع������ÿ���
        }
        Display_Power(Power_flag);
        OSTimeDly(1);
    }
}

/*
********************************************************************************
�������ƣ�void CreateFUNTask(void)
�������ܣ�����FUN������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void CreateFUNTask(void)
{
    OSTaskCreateExt(
                        FUNTask,
                        (void *)0,
                        &FUNTaskStk[TASK_FUN_STK_SIZE-1],
                        FUNTaskPrio,
                        0,
                        &FUNTaskStk[0],
                        TASK_FUN_STK_SIZE,
                        (void *)0,
                        OS_TASK_OPT_STK_CHK+OS_TASK_OPT_STK_CLR
                   );

}
