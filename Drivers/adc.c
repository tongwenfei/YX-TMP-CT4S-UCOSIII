/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			ADC.h
 *Description：     	       实现AD转换 
 *Date:
 *Author:		
*******************************************************************************/

#include "adc.h"


//定义读取的测量值
//#define     POWER_10V           0        //10V电源电压
#define     POWER_12V          1        //12V电源电压     //电池电压
#define     POWER_15V          2        //15V电源电压


#define     Channel_Num     2       //通道数
#define     Sample_Num      30      //样品数




//ADC宏定义部分


//#define     PC0_ADC10_10V         GPIO_Pin_0        //PC0
#define     PC1_ADC11_12V         GPIO_Pin_1        //PC1
#define     PC2_ADC12_15V         GPIO_Pin_2        //PC2

//定义4组通道，每组30个数据
static uint16_t ADC_ConvertedValue[Sample_Num][Channel_Num];

/****************************** ADC函数定义*****************************/

/*
********************************************************************************
函数名称：void ADC_DMA_Config(void)
函数功能：实现ADC引脚DMA的配置
入口参数：无
出口参数：无
********************************************************************************
*/
void ADC_DMA_Config(void)
{
     DMA_InitTypeDef DMA_InitStructure;
                   
     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
     DMA_DeInit(DMA1_Channel1);
     
     DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
     DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADC_ConvertedValue;
     DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
     DMA_InitStructure.DMA_BufferSize = Sample_Num*Channel_Num;
     DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;           //外设地址不变
     DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                    //内存地址递增
     DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
     DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
     DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
     DMA_InitStructure.DMA_Priority = DMA_Priority_High;
     DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
     DMA_Init(DMA1_Channel1, &DMA_InitStructure);
     DMA_Cmd(DMA1_Channel1,ENABLE);
}

/*
********************************************************************************
函数名称：void ADC1_GPIO_Configuration(void)
函数功能：实现ADC引脚的配置
入口参数：无
出口参数：无
********************************************************************************
*/
void ADC1_GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
       
    //PC0/PC1/PC2 
    GPIO_InitStructure.GPIO_Pin = /*PC0_ADC10_10V | */PC1_ADC11_12V|PC2_ADC12_15V;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //模拟输入引脚
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/*
********************************************************************************
函数名称：void ADC1_Configuration(void)
函数功能：实现ADC引脚的配置
入口参数：无
出口参数：无
********************************************************************************
*/
void ADC1_Configuration(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    
    ADC_DeInit(ADC1); 
    
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                          //ADC工作模式:ADC1和ADC2工作在独立模式
    ADC_InitStructure.ADC_ScanConvMode =ENABLE;                                //模数转换工作在扫描模式
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;                          //模数转换工作在连续转换模式
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;         //外部触发转换关闭
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;                      //ADC数据右对齐
    ADC_InitStructure.ADC_NbrOfChannel = 2;                                     //顺序进行规则转换的ADC通道的数目
    ADC_Init(ADC1, &ADC_InitStructure);                                         //根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器
   
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);                                           //12MHZ 最大不能超过14MHZ
    //设置指定ADC的规则组通道，设置它们的转化顺序和采样时间
    //ADC1,ADC通道x,规则采样顺序值为y,采样时间为239.5周期
  
    //ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_239Cycles5 );
    ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_239Cycles5 );
    ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 2, ADC_SampleTime_239Cycles5 );

    ADC_DMACmd(ADC1, ENABLE);
    ADC_Cmd(ADC1, ENABLE);
    ADC_ResetCalibration(ADC1);                                                 //复位指定的ADC1的校准寄存器
    while(ADC_GetResetCalibrationStatus(ADC1));                                 //获取ADC1复位校准寄存器的状态,设置状态则等待
    ADC_StartCalibration(ADC1);                                                 //开始指定ADC1的校准状态 
    while(ADC_GetCalibrationStatus(ADC1));                                      //获取指定ADC1的校准程序,设置状态则等待
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);                                      //使能或者失能指定的ADC的软件转换启动功能
}

/*
********************************************************************************
函数名称：void ADC1_Init(void)
函数功能：实现ADC1初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void ADC1_Init(void)
{
    ADC1_GPIO_Configuration();
    ADC_DMA_Config();
    ADC1_Configuration();
}

/*
********************************************************************************
函数名称：SYSTEM_POWER ReadADCAverageValue(void)
函数功能：实现ADC1值的读取
入口参数：无
出口参数：无
********************************************************************************
*/
SYSTEM_POWER ReadADCAverageValue(void)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t k = 0;
    uint32_t tmp = 0;
   // float val0 = 0;
    float val1 = 0;
    float val2 = 0;
    
    SYSTEM_POWER power;
    //排序
    for(i = 0; i < Channel_Num; i++)		
    {
        for (j = 1; j < Sample_Num; j++)
        {
            for (k = 0; k < (Sample_Num-j); k++)
            {
                //从小到大排序
                if (ADC_ConvertedValue[k][i] > ADC_ConvertedValue[k+1][i])
                {
                    tmp = ADC_ConvertedValue[k][i];
                    ADC_ConvertedValue[k][i] = ADC_ConvertedValue[k+1][i];
                    ADC_ConvertedValue[k+1][i] = tmp;
                }
            }
        }
    }
    //取中间10位求和   
    for(j = 0; j < Sample_Num/3; j++)	
    {
       // val0 = (uint32_t)val0 + ADC_ConvertedValue[j+Sample_Num/3][0];
        val1 = (uint32_t)val1 + ADC_ConvertedValue[j+Sample_Num/3][0];
        val2 = (uint32_t)val2 + ADC_ConvertedValue[j+Sample_Num/3][1];
    }
    //求平均出电压值（根据电路电阻分压得到实际电压）
   // power.pc0_adc10_power = (((val0 / 10) * 2.5) / 4096) *0/ 4.7 * (4.7 + 27);   //硬件未连接无用
    power.pc1_adc11_batter = (((val1 / 10) * 2.486) / 4096) / 10 *  (10 + 27); 
    power.pc2_adc12_power = (((val2 / 10) * 2.486) / 4096) / 4.7 *  (4.7 + 27); 
    
    return power; 
}