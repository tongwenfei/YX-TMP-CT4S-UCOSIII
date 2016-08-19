 /*
 *CopyRight Reserved:	宇星科技
 *Filename：		ad7923.h
 *Description：     	ad7923.c头文件        
 *Date:
 *Author:				heshenghui
*/

#include "include.h"
#ifndef AD7923_H
#define AD7923_H
//FLOW_ADC
#define AD_SCK		GPIO_Pin_15
#define AD_MOSI		GPIO_Pin_14
#define AD_MISO		GPIO_Pin_12
#define AD_CS		GPIO_Pin_13
#define AD_PORT         GPIOD

//CURRENT_ADC
#define AD2_SCK		GPIO_Pin_11  
#define AD2_MOSI	GPIO_Pin_10          //ADC2_CS和DIN画反
#define AD2_MISO	GPIO_Pin_12
#define AD2_CS		GPIO_Pin_9
#define AD2_PORT         GPIOA
 typedef struct
{
  uint16_t Flow_ADC[4];
}FLOW_ADC_STRUCT;
typedef struct
{
  uint16_t Current_ADC[4];
}CURRENT_ADC_STRUCT;

void AD7923_Init(void);
void AD7923_W_REG(uint8_t add);
uint16_t AD7923_R_REG(void);
uint16_t ADC1_GetValue(uint8_t ch);
uint16_t ADC2_GetValue(uint8_t ch);
uint16_t Get_AverageValue(uint16_t *data,uint8_t ch);
uint16_t Get_AverageValue2(uint16_t *data,uint8_t ch);
  

uint16_t Filter(void) ;
#endif/*AD7923_H*/









