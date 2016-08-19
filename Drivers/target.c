/*******************************************************************************
*CopyRight Reserved:	
*Filename：			target.c
*Description：     	        实现目标板的初始化
*Date:
*Author:		
*******************************************************************************/

#include "include.h"
/*
********************************************************************************
函数名称：void BAT_STATE_Init(void)  
函数功能：充电状态检测初始化
入口参数：无 
出口参数：无
********************************************************************************
*/
void BAT_STATE_Init(void)
{ 
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = GPIO_Pin_8;	
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//最高输出频率50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_IPU;  	//推挽输出
  GPIO_Init(GPIOD, &gpio_init); 
  
}

Charge_State Charge_Detect(void)
{
  
  if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_8)==1)return DISCHARGE;
  else return CHARGING;
}









/*
********************************************************************************
函数名称：void LED_Init(void)  
函数功能：实现LED灯的初始化
入口参数：无 
出口参数：无
********************************************************************************
*/
void LED_Init(void)
{ 
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = PC13_LED;	
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//最高输出频率50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_Out_PP;  	//推挽输出
  GPIO_Init(GPIOC, &gpio_init); 
  
}
/*
********************************************************************************
函数名称：void Pump_IOinit(void)  
函数功能：实现气泵IO的初始化
入口参数：无 
出口参数：无
********************************************************************************
*/
void Pump_IOinit(void)
{
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;	
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//最高输出频率50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_Out_PP;  	//推挽输出
  GPIO_Init(GPIOE, &gpio_init); 
  GPIO_ResetBits(GPIOE,GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5);
}
/*
********************************************************************************
函数名称：void WDOG_Init(void)
函数功能：实现看门狗的初始化
入口参数：无 
出口参数：无
********************************************************************************
*/
void WDOG_Init(void)
{
  GPIO_InitTypeDef  gpio_init;
  gpio_init.GPIO_Pin   = WDOG_WDI;		
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;	//最高输出频率50HZ
  gpio_init.GPIO_Mode  = GPIO_Mode_Out_PP;  	//推挽输出
  GPIO_Init(GPIOE, &gpio_init);
}
/*
********************************************************************************
函数名称：void Feed_Dog(void)
函数功能：进行喂狗操作
入口参数：无 
出口参数：无
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
函数名称：void Target_Init(void)  
函数功能：实现目标板初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void Target_Init(void)       
{
  
  const uint8_t char_buf[16]={"YX-TMP-CT4S"};
  const uint8_t password_buf[]={1,2,3,4,5,6}; 
  TimeValue.hour= 0;        //起始小时时间12
  TimeValue.minute= 0;       //起始分钟时间00
  TimeValue.second= 0;       //起始秒钟时间00
  
  
  TimeValue.year = 16;        //起始年份
  TimeValue.month = 1;       //起始月份
  TimeValue.date = 1;       //起始日期
  TimeValue.week=5;         //星期
  
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
  // Ds1302_Set_Time(&TimeValue); //时间设置
  FM24C64_WRITE_MUL(DEFAULT, (uint8_t*)&g_DefaultData, sizeof(g_DefaultData));
  //  memset(&g_DefaultData,0,sizeof(g_DefaultData));
  //  FM24C64_READ_MUL(DEFAULT, (uint8_t*)&g_DefaultData, sizeof(g_DefaultData));
  
  //没有未完成标志   
  /*************************************把所有标志也清零***********************************************/
  
}



/*
********************************************************************************
函数名称：void RCC_Config(void)    
函数功能：实现处理器的初始化
入口参数：无 
出口参数：无
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
函数名称：void Delay10us(int32u m)   
函数功能：实现延时10us
入口参数：m  
出口参数：无
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
函数名称：void  Delayms(int32u m)    
函数功能：实现延时1ms
入口参数：m  
出口参数：无
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


