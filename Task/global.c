/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			Global.c
 *Description��     	        ����ȫ�ֱ���
 *Date:
 *Author:		
*******************************************************************************/


#include "global.h"
/******************************����ȫ�ֱ���******************************/



volatile SYSTEM_TEMP_RH g_TEMP_RH;          //����ȫ�ֱ����¶�
SYSTEM_STORAGE  g_StorageData;
DEFAULT_STORAGE g_DefaultData;
SYSTEM_POWER System_Power;                        //�����ѹֵ��ȡ
uint8_t Power_flag;                            //�����ѹԴ�������־
uint8_t Batter_flag;                           //�����ص������־
uint8_t Batter_add;                            //�����س��ĳ���־
uint8_t Batter_add_flag0;                      //�����س��0�����־
uint8_t Batter_add_flag1;                      //�����س��1�����־
uint8_t Batter_add_flag2;                      //�����س��2�����־
uint8_t Batter_add_flag3;                      //�����س��3�����־
uint8_t Batter_add_flag4;                      //�����س��4�����־


//TXBUFF TxBuffer;			     //���ͻ�����
//RXBUFF RxBuffer;			     //���ջ�����
volatile float Ambience_Temp;                 //���廷���¶�ֵ
volatile float PT100_Temp[2]={0};                   //��������PT100�¶�ֵ
volatile float MS5611_Temp,MS5611_Press;           //������ѹ���¶�ֵ
uint8_t PassWd_flag,HW_flag,Data_Flag,Info_flag,Channel_flag,Exit_flag,Main_flag;                            //�����������ñ�־
uint8_t PassWd_last[6],PassWd_old[6],PassWd_new[6],PassWd_rep[6]; //��������ֵ
uint8_t PassWd_num[3];
uint8_t key_vaule,DispState_time=0;
uint8_t Time_flag,Uart_flag,Param_flag,Clean_flag,Factory_flag,Updata_flag,Help_flag;


PID_STRUCT FlowPID_struct[4],TempPID_struct;
SAMPLING_STATE Sampling_State[4];

