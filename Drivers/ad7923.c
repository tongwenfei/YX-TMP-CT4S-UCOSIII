/*
*CopyRight Reserved:	宇星科技
*Filename：		ad7923.c
*Description：     	ad7923底层驱动         
*Date:
*Author:				heshenghui
*/


#include "include.h"
inline static void  AD7923Delay(void)        
{    
  nop();
  nop();
  nop();
  nop();
  nop();
  nop();
    nop();
  nop();
  nop();
  nop();
  nop();
  nop();
}
/*
*** 入口：	        无
*** 出口：		无
*** 功能描述：		初始化
*/
void AD7923_Init(void)
{ GPIO_InitTypeDef GPIO_InitStructure;


GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;             
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(AD_PORT, &GPIO_InitStructure);

GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;             
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(AD_PORT, &GPIO_InitStructure);

GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;             
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(AD2_PORT, &GPIO_InitStructure);

GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;             
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(AD2_PORT, &GPIO_InitStructure);
}
/*
*** 入口：	        add:寄存器地址
0-3
*** 出口：		无
*** 功能描述：		写寄存器
*/
void AD7923_W_REG(uint8_t add)
{
#if OS_CRITICAL_METHOD == 3                      
  
#endif
  uint16_t tmp=0;
  uint8_t i;
  if(add>3) return;
  
  tmp=add<<6;
  tmp |= bit0+bit4+bit5+bit11;
  tmp &=~(bit1+bit3+bit10);
  tmp=tmp<<4;
  
  GPIO_ResetBits(AD_PORT, AD_CS);
   CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态
    							//进入中断
  for(i=0;i<16;i++)
  {
    if (tmp&0x8000) 
      GPIO_SetBits(AD_PORT,AD_MOSI);
    else 
      GPIO_ResetBits(AD_PORT, AD_MOSI);
    
    GPIO_ResetBits(AD_PORT,AD_SCK);
    AD7923Delay();
    GPIO_SetBits(AD_PORT, AD_SCK);
    tmp <<= 1;
  }
  OSIntExit(); //退出临界状态
  GPIO_SetBits(AD_PORT, AD_CS);
  GPIO_ResetBits(AD_PORT, AD_MOSI);
}
/*
*** 入口：	        无
*** 出口：			无
*** 功能描述：		读寄存器
*/
uint16_t AD7923_R_REG(void)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
  
#endif
  uint8_t i;
  uint16_t tmp=0;
  GPIO_ResetBits(AD_PORT, AD_CS);
   CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态
  for(i=0;i<16;i++)
  {	    
    
    tmp <<=1;
    if (GPIO_ReadInputDataBit(AD_PORT,AD_MISO)) 
      tmp++;
    GPIO_ResetBits(AD_PORT, AD_SCK);
    AD7923Delay();
    GPIO_SetBits(AD_PORT, AD_SCK);
  }
  OSIntExit(); //退出临界状态
  GPIO_SetBits(AD_PORT, AD_CS);
  return tmp;	
}



/*
*** 入口：	        add:寄存器地址
0-3
*** 出口：		无
*** 功能描述：		写寄存器
*/
void AD7923_2_W_REG(uint8_t add)
{
#if OS_CRITICAL_METHOD == 3                      
  
#endif
  uint16_t tmp=0;
  uint8_t i;
  if(add>3) return;
  
  tmp=add<<6;
  tmp |= bit0+bit4+bit5+bit11;
  tmp &=~(bit1+bit3+bit10);
  tmp=tmp<<4;
  
  GPIO_ResetBits(AD2_PORT, AD2_CS);
  CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态
  for(i=0;i<16;i++)
  {
    if (tmp&0x8000) 
      GPIO_SetBits(AD2_PORT,AD2_MOSI);
    else 
      GPIO_ResetBits(AD2_PORT, AD2_MOSI);
    
    GPIO_ResetBits(AD2_PORT,AD2_SCK);
    AD7923Delay();
    GPIO_SetBits(AD2_PORT, AD2_SCK);
    tmp <<= 1;
  }
   OSIntExit(); //退出临界状态
  GPIO_SetBits(AD2_PORT, AD2_CS);
  GPIO_ResetBits(AD2_PORT, AD2_MOSI);
}
/*
*** 入口：	        无
*** 出口：			无
*** 功能描述：		读寄存器
*/
uint16_t AD7923_2_R_REG(void)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
  
#endif
  uint8_t i;
  uint16_t tmp=0;
  GPIO_ResetBits(AD2_PORT, AD2_CS);
  CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态
  for(i=0;i<16;i++)
  {	    
    
    tmp <<=1;
    if (GPIO_ReadInputDataBit(AD2_PORT,AD2_MISO)) 
      tmp++;
    GPIO_ResetBits(AD2_PORT, AD2_SCK);
    AD7923Delay();
    GPIO_SetBits(AD2_PORT, AD2_SCK);
  }
   OSIntExit(); //退出临界状态
  GPIO_SetBits(AD2_PORT, AD2_CS);
  return tmp;	
}


uint16_t ADC1_GetValue(uint8_t ch)
{
  uint16_t i=0;
  
  
  AD7923_W_REG(ch);
  i=AD7923_R_REG();
  
  return i;
}
uint16_t ADC2_GetValue(uint8_t ch)
{
  uint16_t i=0;
  
  
  AD7923_2_W_REG(ch);
  i=AD7923_2_R_REG();
  return i;
}
uint16_t Get_AverageValue(uint16_t *data,uint8_t ch)
{
  uint16_t temp=0;
  uint32_t Average_data=0;
  for(uint8_t i=0;i<30;i++)
  {
    data[i]=ADC1_GetValue(ch);
    
  }
  for (uint8_t i = 0; i < 30; i++)
  {
    for (uint8_t j = i; j < 30; j++)
    {
      if (data[i] > data[j])
      {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
  for(uint8_t i=0;i<10;i++)
  {
    Average_data+=data[10+i];
  }
  return (Average_data/10);
}


uint16_t value_buf[12]={0};
uint8_t FilterI=0,first_num=0;
uint16_t Filter(void) 
{
  uint32_t sum=0;
  value_buf[FilterI++]=ADC1_GetValue(2)-0x2000;
  first_num+=1;
  if(first_num>=12)
  {
    first_num=12;
  if(FilterI==12)
    FilterI=0; //先进先出，再求平均值
  for(uint8_t count=0;count<12;count++)
    sum+=value_buf[count];
  
  }
  else
  {
    for(uint8_t count=0;count<first_num;count++)
    sum+=value_buf[count];
    
  }
  return (uint16_t)(sum/first_num);
}
uint16_t Get_AverageValue2(uint16_t *data,uint8_t ch)
{
  uint16_t temp=0;
  uint32_t Average_data=0;
  for(uint8_t i=0;i<30;i++)
  {
    data[i]=ADC2_GetValue(ch);
    
  }
  for (uint8_t i = 0; i < 30; i++)
  {
    for (uint8_t j = i; j < 30; j++)
    {
      if (data[i] > data[j])
      {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
  for(uint8_t i=0;i<10;i++)
  {
    Average_data+=data[10+i];
  }
  return (Average_data/10);
}