/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			battertask.C
 *Description��     	        �������
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"
#include "include.h"


//������ƿ�
OS_TCB BatterTaskTCB;
//�����ջ	
 CPU_STK BATTER_TASK_STK[BATTER_STK_SIZE];
//������
void BatterTask(void *pdata);
/*
********************************************************************************
�������ƣ�void BATTERTask(void *pdata)
�������ܣ�BATTER������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void BatterTask(void *pdata)
{
  OS_ERR err;
    pdata=pdata;
    while(1)
    {  
      System_Power=ReadADCAverageValue();
        if(Batter_flag == 1)
        {
            //�ж��Ƿ��е�Դ�������ǳ�绹�ǵ�ع���,������ʱ���ṩ���Ч����ʱ
            if(Power_flag == 1)
            {
                /***************�Ե�ؽ��г��,ĳһ����������Ž���һ�����Դ�10.6V��ʼ******************/
                if((Batter_add_flag1 == 0) && (Batter_add_flag2 == 0) && (Batter_add_flag3 == 0))
                {
                    //��һ����أ��յ���
                    if(System_Power.pc1_adc11_batter <= 10.6)    
                    {
                        Batter_add_flag0 = 1;
                    }
                    if(Batter_add_flag0 == 1)
                    {
                        Batter_add++;
                        if(Batter_add == 6)
                        {
                            Batter_add = 0;
                            Batter_add_flag0 = 0;
                        }
                    }
                }
                if((Batter_add_flag0 == 0) && (Batter_add_flag2 == 0) && (Batter_add_flag3 == 0))
                {
                    //�г���һ�����������ڶ�����
                    if((System_Power.pc1_adc11_batter > 10.6) && (System_Power.pc1_adc11_batter <= 11.2))   //ÿһ�����Ϊ0.6v
                    {
                        Batter_add_flag1 = 1;
                    }
                    if(Batter_add_flag1 == 1)
                    {
                        Batter_add++;
                        if(Batter_add == 5)
                        {
                            Batter_add = 0;
                            Batter_add_flag1 = 0;
                        }
                    }
                }
                if((Batter_add_flag0 == 0) && (Batter_add_flag1 == 0) && (Batter_add_flag3 == 0))
                {
                    //�г����������������������
                    if((System_Power.pc1_adc11_batter > 11.2) && (System_Power.pc1_adc11_batter <= 11.8))
                    {
                        Batter_add_flag2 = 1;
                    }
                    if(Batter_add_flag2 == 1)
                    {
                        Batter_add++;
                        if(Batter_add == 4)
                        {
                            Batter_add = 0;
                            Batter_add_flag2 = 0;
                        }
                    }
                }
                if((Batter_add_flag0 == 0) && (Batter_add_flag1 == 0) && (Batter_add_flag2 == 0))
                {
                    //�г������������������ĵ���
                    if((System_Power.pc1_adc11_batter > 11.8) && (System_Power.pc1_adc11_batter <= 12))
                    {
                        Batter_add_flag3 = 1;
                    }
                    if(Batter_add_flag3 == 1)
                    {
                        Batter_add++;
                        if(Batter_add == 3)
                        {
                            Batter_add = 0;
                            Batter_add_flag3 = 0;
                        }
                    }
                }
                if(System_Power.pc1_adc11_batter > 12)
                {
                    Batter_add_flag4 = 1;
                }
                else
                {
                    Batter_add_flag4 = 0;
                }
            }
            else
            {
                Batter_add = 0;
                Batter_add_flag0 = 0;
                Batter_add_flag1 = 0;
                Batter_add_flag2 = 0;
                Batter_add_flag3 = 0;
            }
        }
       OSTimeDlyHMSM(0,0,1,0,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ500ms
    }
}

/*
********************************************************************************
�������ƣ�void CreateBATTERTask(void)
�������ܣ�����BATTER������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void CreateBATTERTask(void)
{
    OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&BatterTaskTCB,		//������ƿ�
               (CPU_CHAR  *)"Batter Task", 		//��������
               (OS_TASK_PTR)BatterTask, 			//������
               (void      *)0,					//���ݸ��������Ĳ���
               (OS_PRIO     )BATTER_TASK_PRIO,     //�������ȼ�
               (CPU_STK   * )&BATTER_TASK_STK[0],	//�����ջ����ַ
               (CPU_STK_SIZE)BATTER_STK_SIZE/10,	//�����ջ�����λ
               (CPU_STK_SIZE)BATTER_STK_SIZE,		//�����ջ��С
               (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
               (OS_TICK	    )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
               (void      *)0,					//�û�����Ĵ洢��
               (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
               (OS_ERR     *)&err);	

}
