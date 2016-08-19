/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			MS561101BA.h
 *Description��     	        ��ײ��ѹ�������� 
 *Date:
 *Author:		
*******************************************************************************/

#include "include.h"


//I2C����IO�ڶ���
#define     SCL_GPIO_Pin     GPIO_Pin_12        //IICʱ��SCL���Ŷ���  PB12
#define     SDA_GPIO_Pin     GPIO_Pin_13        //IIC����SDA���Ŷ���  PB13



//��������
#define     MS561101BA_SlaveAddress     0xee   //����������IIC�����еĴӵ�ַ��Ӳ����CSBΪ�ߣ�ȡ��Ϊ��
#define     MS561101BA_RST              0x1E    //���帴λָ��

//D1����ѹ��������λ����
#define     MS561101BA_D1_OSR_256       0x40     
#define     MS561101BA_D1_OSR_512       0x42 
#define     MS561101BA_D1_OSR_1024      0x44 
#define     MS561101BA_D1_OSR_2048      0x46 
#define     MS561101BA_D1_OSR_4096      0x48 

//D2�����¶ȣ�����λ����
#define     MS561101BA_D2_OSR_256       0x50 
#define     MS561101BA_D2_OSR_512       0x52 
#define     MS561101BA_D2_OSR_1024      0x54 
#define     MS561101BA_D2_OSR_2048      0x56 
#define     MS561101BA_D2_OSR_4096      0x58 

//ADC��ȡ��PROM��ȡ
#define     MS561101BA_ADC_RD           0x00     //ADֵ��ȡ
#define     MS561101BA_PROM_RD          0xA0     //PROM��ȡ
#define     MS561101BA_PROM_CRC         0xAE     //CRCУ���ȡ


/****************************** MS561101BA ��������*****************************/

//����ȫ�����ر���
static uint16_t Cal_C[8];	                         //���ڴ��PROM�е�8������
static uint32_t D1_Pres,D2_Temp;	                 //���ѹ�����¶�
static float dT,TEMP;                            
static double OFF_,SENS;
static float Pressure;				 //����ѹ
static float OFF2,SENS2,T2;	         //�¶�У��ֵ

/*
********************************************************************************
�������ƣ�void SCL_OUT(void)
�������ܣ�SCLΪ��©���ģʽ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void SCL_OUT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = SCL_GPIO_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

}

/*
********************************************************************************
�������ƣ�void MS561101BA_RESET(void)
�������ܣ�MS561101BA��ѹоƬ��λ����
��ڲ�������
���ڲ�������
********************************************************************************
*/
void MS561101BA_RESET(void)
{	
    EE_I2C_Start();
    EE_I2C_SendByte(MS561101BA_SlaveAddress);
    EE_I2C_SendByte(MS561101BA_RST);
    EE_I2C_Stop();
}

/*
********************************************************************************
�������ƣ�void MS561101BA_PROM_READ(void)
�������ܣ�MS561101BA��ѹоƬPROM��ȡ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void MS561101BA_PROM_READ(void)
{
    uint8_t d1 = 0,d2 = 0,i = 0;                                      
    for(i = 0;i < 8; i++)
    {
        EE_I2C_Start();
        EE_I2C_SendByte(MS561101BA_SlaveAddress);
        EE_I2C_SendByte((MS561101BA_PROM_RD+i*2));             //��ȡ��7�����ݣ�У��δ����
    
        EE_I2C_Start();
        EE_I2C_SendByte(MS561101BA_SlaveAddress+1);
        d1=EE_I2C_RecvByte();
        EE_I2C_SendACK(0);
        d2=EE_I2C_RecvByte();
        EE_I2C_SendACK(1);
        EE_I2C_Stop();
        Delayms(5);
        
        Cal_C[i]=((uint16_t)d1 << 8) | d2;                    
    }
}

/*
********************************************************************************
�������ƣ�int64u MS561101BA_DO_CONVERSION(uint8_t command)
�������ܣ�MS561101BA��ѹоƬ��ѹ���¶ȵ�24λֵ�Ķ�ȡ
��ڲ�����command����ȡ������λ���趨��������ת��
���ڲ���������ADC��ת�����
********************************************************************************
*/
uint32_t MS561101BA_DO_CONVERSION(uint8_t command)
{
    uint32_t conversion=0;
    uint8_t conv1,conv2,conv3; 
    
    CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//�����ٽ�״̬
    							//�����ж�
    //�趨ת��������λ����ת��
    EE_I2C_Start();
    EE_I2C_SendByte(MS561101BA_SlaveAddress);
    EE_I2C_SendByte(command);
    EE_I2C_Stop();
     OSIntExit(); //�˳��ٽ�״̬
    							//�����ж�
    
    Delayms(10);
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//�����ٽ�״̬//�����ٽ�״̬
    							//�����ж�
    //ADCֵ��ȡ
    EE_I2C_Start();
    EE_I2C_SendByte(MS561101BA_SlaveAddress);
    EE_I2C_SendByte(0);
    
    //I2C��MS5611-01BA��ȡ����
    EE_I2C_Start();
    EE_I2C_SendByte(MS561101BA_SlaveAddress+1);
    conv1=EE_I2C_RecvByte();
    EE_I2C_SendACK(0);
    conv2=EE_I2C_RecvByte();
    EE_I2C_SendACK(0);
    conv3=EE_I2C_RecvByte();
    EE_I2C_SendACK(1);
    EE_I2C_Stop();
     
   						//�����ж�
    
    conversion=conv1*65535+conv2*256+conv3;
    OSIntExit(); //�˳��ٽ�״̬
    
    return conversion;
}

/*
********************************************************************************
�������ƣ�void MS561101BA_getTemperature(uint8_t OSR_Temp)
�������ܣ�MS561101BA�¶�ֵת��
��ڲ�����OSR_Temp���¶�λ��ָ��
���ڲ�������
********************************************************************************
*/
float MS561101BA_getTemperature(uint8_t OSR_Temp)
{
    D2_Temp = MS561101BA_DO_CONVERSION(OSR_Temp);
    dT = (float)(D2_Temp - (((uint32_t)Cal_C[5]) << 8));
    TEMP = 2000+dT*((uint32_t)Cal_C[6])/8388608;
    return TEMP;

}

/*
********************************************************************************
�������ƣ�float MS561101BA_getPressure(uint8_t OSR_Pres)
�������ܣ�MS561101BA��ѹֵת��
��ڲ�����OSR_Pres����ѹת��λ��ָ��
���ڲ�����������ѹֵ
********************************************************************************
*/
float MS561101BA_getPressure(uint8_t OSR_Pres)
{
    D1_Pres= MS561101BA_DO_CONVERSION(OSR_Pres);
    OFF_ = (uint32_t)Cal_C[2]*65536+((uint32_t)Cal_C[4]*dT)/128;
    SENS = (uint32_t)Cal_C[1]*32768+((uint32_t)Cal_C[3]*dT)/256;
    
    if(TEMP < 2000)
    {
        // ��20���¶����¶Ȳ���
        T2 = (dT*dT) / 0x80000000;
        OFF2 = 2.5*(TEMP - 2000)*(TEMP - 2000);
        SENS2 = 1.25*(TEMP - 2000)*(TEMP - 2000);
        if(TEMP < (-1500))
        {
            OFF2 = OFF2 + 7*(TEMP+1500)*(TEMP+1500);
            SENS2 = SENS2 + 11*(TEMP+1500)*(TEMP+1500)/2;
        }
        TEMP = TEMP - T2;
        OFF_ = OFF_ - OFF2;
        SENS = SENS - SENS2;	
    }
    
    Pressure=(D1_Pres*SENS/2097152-OFF_)/32768;
    return Pressure;                                        //�õ�barֵ
}
/*
********************************************************************************
�������ƣ�void MS561101BA_Init(void)
�������ܣ�MS561101BA��ʼ����ʵ�ָ�λ��prom��ȡ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void MS561101BA_Init(void)
{
    SCL_OUT();
    MS561101BA_RESET();                                //оƬ��λ
    MS561101BA_PROM_READ();                            //��ȡPROMֵ
}

/*
********************************************************************************
�������ƣ�void MS561101BA_Pressure_Read(void)
�������ܣ�MS561101BA��ѹֵ��ȡ
��ڲ�������
���ڲ�����Ϊkpa��ѹֵ
********************************************************************************
*/
float MS561101BA_Pressure_Read(void)
{
    float Pre = 0;
    //MS561101BA_getTemperature(MS561101BA_D2_OSR_4096);       //����Ҫ�����¶Ⱥ������ܲ�����ѹ
    Pre = MS561101BA_getPressure(MS561101BA_D1_OSR_4096);
    Pre = Pre / 1000;                                        //���kbar
    return Pre;
}

/*
********************************************************************************
�������ƣ�float MS561101BA_Temperature_Read(void)
�������ܣ�MS561101BA�¶�ֵ��ȡ
��ڲ�������
���ڲ��������¶�ֵ
********************************************************************************
*/
float MS561101BA_Temperature_Read(void)
{
    float temp = 0;
    temp = MS561101BA_getTemperature(MS561101BA_D2_OSR_4096);
    temp = temp / 100;                                        //����¶�ֵ
    return temp;
}
