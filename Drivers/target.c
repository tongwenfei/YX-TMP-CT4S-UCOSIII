/*******************************************************************************
*CopyRight Reserved:	
*Filename��			target.c
*Description��     	        ʵ��Ŀ���ĳ�ʼ��
*Date:
*Author:		
*******************************************************************************/

#include "include.h"
/*
********************************************************************************
�������ƣ�void BAT_STATE_Init(void)  
�������ܣ����״̬����ʼ��
��ڲ������� 
���ڲ�������
********************************************************************************
*/
void BAT_STATE_Init(void)
{ 
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = GPIO_Pin_8;	
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//������Ƶ��50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_IPU;  	//�������
  GPIO_Init(GPIOD, &gpio_init); 
  
}

Charge_State Charge_Detect(void)
{
  
  if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_8)==1)return DISCHARGE;
  else return CHARGING;
}









/*
********************************************************************************
�������ƣ�void LED_Init(void)  
�������ܣ�ʵ��LED�Ƶĳ�ʼ��
��ڲ������� 
���ڲ�������
********************************************************************************
*/
void LED_Init(void)
{ 
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = PC13_LED;	
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//������Ƶ��50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_Out_PP;  	//�������
  GPIO_Init(GPIOC, &gpio_init); 
  
}
/*
********************************************************************************
�������ƣ�void Pump_IOinit(void)  
�������ܣ�ʵ������IO�ĳ�ʼ��
��ڲ������� 
���ڲ�������
********************************************************************************
*/
void Pump_IOinit(void)
{
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;	
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//������Ƶ��50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_Out_PP;  	//�������
  GPIO_Init(GPIOE, &gpio_init); 
  GPIO_ResetBits(GPIOE,GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5);
}
/*
********************************************************************************
�������ƣ�void WDOG_Init(void)
�������ܣ�ʵ�ֿ��Ź��ĳ�ʼ��
��ڲ������� 
���ڲ�������
********************************************************************************
*/
void WDOG_Init(void)
{
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = WDOG_WDI;		
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//������Ƶ��50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_Out_PP;  	//�������
  GPIO_Init(GPIOE, &gpio_init);
}
/*
********************************************************************************
�������ƣ�void Feed_Dog(void)
�������ܣ�����ι������
��ڲ������� 
���ڲ�������
********************************************************************************
*/
void Feed_Dog(void)
{
  WDI_H();
  nop();
  nop();
  nop();
  nop();
  nop();
  nop();
  WDI_L();
}

/*
********************************************************************************
�������ƣ�void Target_Init(void)  
�������ܣ�ʵ��Ŀ����ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Target_Init(void)       
{
  
  const uint8_t char_buf[16]={"YX-TMP-CT4S"};
  const uint8_t password_buf[]={1,2,3,4,5,6}; 
  TimeValue.hour= 0;        //��ʼСʱʱ��12
  TimeValue.minute= 0;       //��ʼ����ʱ��00
  TimeValue.second= 0;       //��ʼ����ʱ��00
  
  
  TimeValue.year = 16;        //��ʼ���
  TimeValue.month = 1;       //��ʼ�·�
  TimeValue.date = 1;       //��ʼ����
  TimeValue.week=5;         //����
  
  g_DefaultData.Sys_Year=16;
  g_DefaultData.Sys_Month=1;
  g_DefaultData.Sys_Data=1;
  g_DefaultData.Sys_Week=5;
  
  g_DefaultData.Sys_Hour=0;
  g_DefaultData.Sys_Minute=0;
  g_DefaultData.Sys_Second=0;
  
  g_DefaultData.Default_State=0xA5;
  
  memcpy((char*)g_DefaultData.Instrument_Modle,char_buf,sizeof(char_buf)); 
  g_DefaultData.Channel_N=4;
  g_DefaultData.Flow_Range=1000;
  g_DefaultData.SW_Version=100;
  g_DefaultData.HW_Version=100;
  g_DefaultData.Storage=64;
  
  g_DefaultData.Baud_Rate=115200;
  g_DefaultData.Data_Bits=8;
  g_DefaultData.Parity_Bits=0;
  g_DefaultData.Stop_Bits=1;
  
  memcpy(g_DefaultData.Sys_PassWord,password_buf,sizeof(password_buf));
  
   Ds1302_Write((0xc0|0x3c),0xff) ;
  // Ds1302_Set_Time(&TimeValue); //ʱ������
  FM24C64_WRITE_MUL(DEFAULT, (uint8_t*)&g_DefaultData, sizeof(g_DefaultData));
  //  memset(&g_DefaultData,0,sizeof(g_DefaultData));
  //  FM24C64_READ_MUL(DEFAULT, (uint8_t*)&g_DefaultData, sizeof(g_DefaultData));
  
  //û��δ��ɱ�־   
  /*************************************�����б�־Ҳ����***********************************************/
  
}



/*
********************************************************************************
�������ƣ�void RCC_Config(void)    
�������ܣ�ʵ�ִ������ĳ�ʼ��
��ڲ������� 
���ڲ�������
********************************************************************************
*/
void RCC_Config(void)
{
  //    RCC_DeInit();
  //    RCC_HSEConfig(RCC_HSE_ON);
  //    while (RCC_WaitForHSEStartUp()==ERROR);
  //    RCC_HCLKConfig(RCC_SYSCLK_Div1);
  //    RCC_PCLK2Config(RCC_HCLK_Div1);
  //    RCC_PCLK1Config(RCC_HCLK_Div2);
  //    RCC_ADCCLKConfig(RCC_PCLK2_Div6);
  //    FLASH_SetLatency(FLASH_Latency_2);
  //    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
  //    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
  //    RCC_PLLCmd(ENABLE);
  //
  //    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
  //    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
  // 
  //    while (RCC_GetSYSCLKSource() != 0x08);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO 
			|RCC_APB2Periph_GPIOA 
			|RCC_APB2Periph_GPIOB
			|RCC_APB2Periph_GPIOC
			|RCC_APB2Periph_GPIOD
			|RCC_APB2Periph_GPIOE
			|RCC_APB2Periph_ADC1, 
			 ENABLE);
  
  
}

void Delay_Nus(uint32_t t)  
{  
  while(t--)
  {
    nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
    nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
    nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
    nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
    nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
    nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
    
  }
}  

/*
********************************************************************************
�������ƣ�void Delay10us(int32u m)   
�������ܣ�ʵ����ʱ10us
��ڲ�����m  
���ڲ�������
********************************************************************************
*/
void Delay10us(uint32_t m)        
{
  uint32_t j;
  uint32_t i;
  for(i=0; i<m; i++)
  {
    for(j=0; j<60; j++)
    {
      
      __no_operation();
    }
  }
}
/*
********************************************************************************
�������ƣ�void  Delayms(int32u m)    
�������ܣ�ʵ����ʱ1ms
��ڲ�����m  
���ڲ�������
********************************************************************************
*/
void Delayms(uint32_t m)       
{
  uint32_t i;   
  for(i=0; i<m; i++)
  {
    Delay10us(100);
  }
}


