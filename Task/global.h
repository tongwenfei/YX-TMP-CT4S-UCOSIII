/*******************************************************************************
*CopyRight Reserved:	
*Filename��			Global.h
*Description��     	        ����ȫ�ֱ����ⲿʹ��
*Date:
*Author:		
*******************************************************************************/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__
#include "flowPID.h"

//
//#ifdef MAITASK_C
//#define MAINEXT 
//#else
//#define MAINEXT extern
//#endif

//�ṹ�嶨��
//���������¶Ƚṹ��
typedef struct 
{
  float p_temperature;
  
}SYSTEM_TEMP_RH;



//���������¶Ƚṹ��
typedef struct 
{
  // float pc0_adc10_power;           //PB0
  float pc1_adc11_batter;        //PC0
  float pc2_adc12_power;          //PB1
  
}SYSTEM_POWER;
typedef enum
{
  DISCHARGE=0,
  CHARGING=!DISCHARGE
}Charge_State;


/******************************��������洢******************************/
typedef struct
{
  uint8_t  Default_State;
  
  uint8_t  Instrument_Modle[16];
  uint8_t  Channel_N;
  uint16_t Flow_Range;
  uint16_t SW_Version;
  uint16_t HW_Version;
  uint16_t Storage;
  
  uint32_t Baud_Rate;
  uint8_t  Data_Bits;
  uint8_t  Parity_Bits;
  uint8_t  Stop_Bits;
  
  uint8_t  Sys_Year;
  uint8_t  Sys_Month;
  uint8_t  Sys_Data;
  uint8_t  Sys_Week;
  uint8_t  Sys_Hour;
  uint8_t  Sys_Minute;
  uint8_t  Sys_Second;
  float    Sys_RT_Flow[4][11];	
  uint8_t  Sys_PassWord[6];
}DEFAULT_STORAGE;
//����ͨѶ���õ�����洢��
#define     DEFAULT                  0x00

//�����ļ��洢��
#define     STORAGE_NUMBER      0x123             //�����ļ����Ѿ�ʹ���˵Ĵ洢����
#define     STORAGE_START       0x124            //�����ļ��洢��ʼλ��


#define ADVALUE_CNT	30			//ÿ����������С
#define ADCHANAL		2			//����������
#define ADBUFFLENGHT	ADVALUE_CNT*ADCHANAL	//������������С

extern uint8_t Change_Flag;
extern uint8_t Raw_Flag;
//extern OS_EVENT* TP_ValueMbox;		//��ѹ�¶�ֵ����
//extern OS_EVENT* TEMP_ValueMbox;	//�¶�ֵ����
//extern OS_EVENT* Vol_ValueMbox;	//�²������ֵ
//����180����������������ݽṹ,����Ҫ43���ֽڴ洢
typedef struct
{
  //�洢�����
  uint8_t number;                  
  
  //��ǰʱ��
  uint8_t now_year;                //�趨��ǰʱ��---��
  uint8_t now_month;               //�趨��ǰʱ��---��
  uint8_t now_day;                 //�趨��ǰʱ��---��
  uint8_t now_hour;                //�趨��ǰʱ��---ʱ
  uint8_t now_minute;              //�趨��ǰʱ��---��
  uint8_t now_second;              //�趨��ǰʱ��---��
  uint8_t now_week;                //�趨��ǰʱ��---����
  
  float pressure;                  //������ѹֵ
  
  //�¶�ֵ
  float heattemp;               //���ļ������¶�ֵ
  float now_temp;               //���Ļ����¶�ֵ
  float cool_temp;                 //��������Ƭ�¶�ֵ
  
  //�趨�Ĳɼ�ʱ��
  uint16_t sampling_set_minute[4];   			 //�趨4ͨ���Ĳɼ�ʱ��---��
  uint16_t sampling_set_volume[4];   			 //�趨4ͨ���Ĳɼ����---����
  uint16_t sampling_interval_minute[4];        //�趨4ͨ���ļ���ɼ�ʱ��---��
  uint16_t sampling_total_minute[4];           //4ͨ�����ۼƲɼ�ʱ��---��
  uint16_t sampling_total_volume[4];   		 //4ͨ�����ۼƲɼ����---����
  uint8_t  sampling_state[4]; 				 //4ͨ���Ĳɼ�״̬
  uint16_t sampling_set_flow[4];				 //����4ͨ���ɼ�����
  
  
  //����ֵ
  uint16_t  RT_flow[4];            //4ͨ��ʵʱ����ֵ
  
  //����������ֵ
  float standard_volume[4];      //4ͨ��������
  
}SYSTEM_STORAGE;

typedef enum
{
   Stop=0,
   Pause,
   Runing,
   Finish, 
}SAMPLING_STATE;
/******************************ȫ�ֱ����ⲿ����******************************/




extern SYSTEM_POWER System_Power;                        //�����ѹֵ��ȡ
extern uint8_t Power_flag;                            //�����ѹԴ�������־
extern uint8_t Batter_flag;                           //�����ص������־
extern uint8_t Batter_add;                            //�����س��ĳ���־
extern uint8_t Batter_add_flag0;                      //�����س��0�����־
extern uint8_t Batter_add_flag1;                      //�����س��1�����־
extern uint8_t Batter_add_flag2;                      //�����س��2�����־
extern uint8_t Batter_add_flag3;                      //�����س��3�����־
extern uint8_t Batter_add_flag4;                      //�����س��4�����־



extern volatile uint8_t Timer_second;                 //���嶨ʱ������ʱ��Ϊ�ָ������ȴ�


extern uint8_t g_Unfinish_Flag;                       //����δ��ɱ�־
//extern TXBUFF TxBuffer;			            //���ͻ�����
//extern RXBUFF RxBuffer;			            //���ջ�����
extern volatile float Ambience_Temp;                  //�����¶�
extern volatile float PT100_Temp[2];                        //PT100�¶�
extern volatile float      MS5611_Temp,MS5611_Press;           //������ѹ���¶�ֵ
extern uint8_t key_vaule,DispState_time;
extern uint8_t PassWd_num[3];

extern PID_STRUCT FlowPID_struct[4],TempPID_struct;


extern uint8_t PassWd_flag,HW_flag,Data_Flag,Info_flag,Channel_flag,Exit_flag,Main_flag;                            //�����������ñ�־
extern uint8_t PassWd_last[6],PassWd_old[6],PassWd_new[6],PassWd_rep[6]; //��������ֵ
extern uint8_t Time_flag,Uart_flag,Param_flag,Clean_flag,Factory_flag,Updata_flag,Help_flag;
extern uint32_t Definite_Count[4];
extern SYSTEM_STORAGE g_StorageData;
extern DEFAULT_STORAGE g_DefaultData;
extern SAMPLING_STATE Sampling_State[4];

/******************************ucos��ض���******************************/



#endif
