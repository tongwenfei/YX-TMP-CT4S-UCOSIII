/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			guitask.h
 *Description��     	        GUI��������
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/*
********************************************************************************
�������ƣ�void GUITask(void *pdata)
�������ܣ�GUI������
��ڲ�������
���ڲ�������
********************************************************************************
*/

//������ƿ�
OS_TCB GUITaskTCB;
//�����ջ	
 CPU_STK GUI_TASK_STK[GUI_STK_SIZE];
//������
void GUITask(void *p_arg);
void GUITask(void *pdata)
{
     OS_ERR err;
    pdata=pdata;
    while(1)
    {  

      if(state_disp)
      {
        DispState_time=0;
        Disp_State();
      }
      if(PassWd_flag)Change_PassWd();
      else if(Main_flag)Change_menu();
     else if(HW_flag)
      {
        Config_Select();
        Config_Enter();
      }
      else if(Data_Flag)Data_Select();
      else if(Channel_flag)Channel_Select();
      else if(Exit_flag)Samp_Select();
      else if(Info_flag)Sys_Exit();
      else if(Time_flag)ConfigSub_Select();
      else if(Help_flag)Exit_HelpWindows();
        OSTimeDlyHMSM(0,0,0,70,OS_OPT_TIME_HMSM_STRICT,&err); 
    }
}

/*
********************************************************************************
�������ƣ�void CreateGUITask(void)
�������ܣ�����GUI������
��ڲ�������
���ڲ�������
********************************************************************************
*/
void CreateGUITask(void)
{
    OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&GUITaskTCB,		//������ƿ�
               (CPU_CHAR  *)"GUI Task", 		//��������
               (OS_TASK_PTR)GUITask, 			//������
               (void      *)0,					//���ݸ��������Ĳ���
               (OS_PRIO     )GUI_TASK_PRIO,     //�������ȼ�
               (CPU_STK   * )&GUI_TASK_STK[0],	//�����ջ����ַ
               (CPU_STK_SIZE)GUI_STK_SIZE/10,	//�����ջ�����λ
               (CPU_STK_SIZE)GUI_STK_SIZE,		//�����ջ��С
               (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
               (OS_TICK	    )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
               (void      *)0,					//�û�����Ĵ洢��
               (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
               (OS_ERR     *)&err);	

}
