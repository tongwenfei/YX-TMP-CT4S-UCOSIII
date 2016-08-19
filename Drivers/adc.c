/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			ADC.h
 *Description��     	       ʵ��ADת�� 
 *Date:
 *Author:		
*******************************************************************************/

#include "adc.h"


//�����ȡ�Ĳ���ֵ
//#define     POWER_10V           0        //10V��Դ��ѹ
#define     POWER_12V          1        //12V��Դ��ѹ     //��ص�ѹ
#define     POWER_15V          2        //15V��Դ��ѹ


#define     Channel_Num     2       //ͨ����
#define     Sample_Num      30      //��Ʒ��




//ADC�궨�岿��


//#define     PC0_ADC10_10V         GPIO_Pin_0        //PC0
#define     PC1_ADC11_12V         GPIO_Pin_1        //PC1
#define     PC2_ADC12_15V         GPIO_Pin_2        //PC2

//����4��ͨ����ÿ��30������
static uint16_t ADC_ConvertedValue[Sample_Num][Channel_Num];

/****************************** ADC��������*****************************/

/*
********************************************************************************
�������ƣ�void ADC_DMA_Config(void)
�������ܣ�ʵ��ADC����DMA������
��ڲ�������
���ڲ�������
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
     DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;           //�����ַ����
     DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                    //�ڴ��ַ����
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
�������ƣ�void ADC1_GPIO_Configuration(void)
�������ܣ�ʵ��ADC���ŵ�����
��ڲ�������
���ڲ�������
********************************************************************************
*/
void ADC1_GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
       
    //PC0/PC1/PC2 
    GPIO_InitStructure.GPIO_Pin = /*PC0_ADC10_10V | */PC1_ADC11_12V|PC2_ADC12_15V;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //ģ����������
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/*
********************************************************************************
�������ƣ�void ADC1_Configuration(void)
�������ܣ�ʵ��ADC���ŵ�����
��ڲ�������
���ڲ�������
********************************************************************************
*/
void ADC1_Configuration(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    
    ADC_DeInit(ADC1); 
    
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                          //ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
    ADC_InitStructure.ADC_ScanConvMode =ENABLE;                                //ģ��ת��������ɨ��ģʽ
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;                          //ģ��ת������������ת��ģʽ
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;         //�ⲿ����ת���ر�
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;                      //ADC�����Ҷ���
    ADC_InitStructure.ADC_NbrOfChannel = 2;                                     //˳����й���ת����ADCͨ������Ŀ
    ADC_Init(ADC1, &ADC_InitStructure);                                         //����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���
   
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);                                           //12MHZ ����ܳ���14MHZ
    //����ָ��ADC�Ĺ�����ͨ�����������ǵ�ת��˳��Ͳ���ʱ��
    //ADC1,ADCͨ��x,�������˳��ֵΪy,����ʱ��Ϊ239.5����
  
    //ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_239Cycles5 );
    ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_239Cycles5 );
    ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 2, ADC_SampleTime_239Cycles5 );

    ADC_DMACmd(ADC1, ENABLE);
    ADC_Cmd(ADC1, ENABLE);
    ADC_ResetCalibration(ADC1);                                                 //��λָ����ADC1��У׼�Ĵ���
    while(ADC_GetResetCalibrationStatus(ADC1));                                 //��ȡADC1��λУ׼�Ĵ�����״̬,����״̬��ȴ�
    ADC_StartCalibration(ADC1);                                                 //��ʼָ��ADC1��У׼״̬ 
    while(ADC_GetCalibrationStatus(ADC1));                                      //��ȡָ��ADC1��У׼����,����״̬��ȴ�
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);                                      //ʹ�ܻ���ʧ��ָ����ADC�����ת����������
}

/*
********************************************************************************
�������ƣ�void ADC1_Init(void)
�������ܣ�ʵ��ADC1��ʼ��
��ڲ�������
���ڲ�������
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
�������ƣ�SYSTEM_POWER ReadADCAverageValue(void)
�������ܣ�ʵ��ADC1ֵ�Ķ�ȡ
��ڲ�������
���ڲ�������
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
    //����
    for(i = 0; i < Channel_Num; i++)		
    {
        for (j = 1; j < Sample_Num; j++)
        {
            for (k = 0; k < (Sample_Num-j); k++)
            {
                //��С��������
                if (ADC_ConvertedValue[k][i] > ADC_ConvertedValue[k+1][i])
                {
                    tmp = ADC_ConvertedValue[k][i];
                    ADC_ConvertedValue[k][i] = ADC_ConvertedValue[k+1][i];
                    ADC_ConvertedValue[k+1][i] = tmp;
                }
            }
        }
    }
    //ȡ�м�10λ���   
    for(j = 0; j < Sample_Num/3; j++)	
    {
       // val0 = (uint32_t)val0 + ADC_ConvertedValue[j+Sample_Num/3][0];
        val1 = (uint32_t)val1 + ADC_ConvertedValue[j+Sample_Num/3][0];
        val2 = (uint32_t)val2 + ADC_ConvertedValue[j+Sample_Num/3][1];
    }
    //��ƽ������ѹֵ�����ݵ�·�����ѹ�õ�ʵ�ʵ�ѹ��
   // power.pc0_adc10_power = (((val0 / 10) * 2.5) / 4096) *0/ 4.7 * (4.7 + 27);   //Ӳ��δ��������
    power.pc1_adc11_batter = (((val1 / 10) * 2.486) / 4096) / 10 *  (10 + 27); 
    power.pc2_adc12_power = (((val2 / 10) * 2.486) / 4096) / 4.7 *  (4.7 + 27); 
    
    return power; 
}