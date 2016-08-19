/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			MS561101BA.h
 *Description：     	        板底层绝压测量驱动 
 *Date:
 *Author:		
*******************************************************************************/

#include "include.h"


//I2C控制IO口定义
#define     SCL_GPIO_Pin     GPIO_Pin_12        //IIC时钟SCL引脚定义  PB12
#define     SDA_GPIO_Pin     GPIO_Pin_13        //IIC数据SDA引脚定义  PB13



//命令设置
#define     MS561101BA_SlaveAddress     0xee   //定义器件在IIC总线中的从地址，硬件上CSB为高，取反为低
#define     MS561101BA_RST              0x1E    //定义复位指令

//D1数字压力，数据位控制
#define     MS561101BA_D1_OSR_256       0x40     
#define     MS561101BA_D1_OSR_512       0x42 
#define     MS561101BA_D1_OSR_1024      0x44 
#define     MS561101BA_D1_OSR_2048      0x46 
#define     MS561101BA_D1_OSR_4096      0x48 

//D2数字温度，数据位控制
#define     MS561101BA_D2_OSR_256       0x50 
#define     MS561101BA_D2_OSR_512       0x52 
#define     MS561101BA_D2_OSR_1024      0x54 
#define     MS561101BA_D2_OSR_2048      0x56 
#define     MS561101BA_D2_OSR_4096      0x58 

//ADC读取和PROM读取
#define     MS561101BA_ADC_RD           0x00     //AD值读取
#define     MS561101BA_PROM_RD          0xA0     //PROM读取
#define     MS561101BA_PROM_CRC         0xAE     //CRC校验读取


/****************************** MS561101BA 函数定义*****************************/

//定义全局隐藏变量
static uint16_t Cal_C[8];	                         //用于存放PROM中的8组数据
static uint32_t D1_Pres,D2_Temp;	                 //存放压力和温度
static float dT,TEMP;                            
static double OFF_,SENS;
static float Pressure;				 //大气压
static float OFF2,SENS2,T2;	         //温度校验值

/*
********************************************************************************
函数名称：void SCL_OUT(void)
函数功能：SCL为开漏输出模式
入口参数：无
出口参数：无
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
函数名称：void MS561101BA_RESET(void)
函数功能：MS561101BA气压芯片复位操作
入口参数：无
出口参数：无
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
函数名称：void MS561101BA_PROM_READ(void)
函数功能：MS561101BA气压芯片PROM读取
入口参数：无
出口参数：无
********************************************************************************
*/
void MS561101BA_PROM_READ(void)
{
    uint8_t d1 = 0,d2 = 0,i = 0;                                      
    for(i = 0;i < 8; i++)
    {
        EE_I2C_Start();
        EE_I2C_SendByte(MS561101BA_SlaveAddress);
        EE_I2C_SendByte((MS561101BA_PROM_RD+i*2));             //读取出7个数据，校验未读出
    
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
函数名称：int64u MS561101BA_DO_CONVERSION(uint8_t command)
函数功能：MS561101BA气压芯片气压和温度的24位值的读取
入口参数：command：读取的数据位数设定，并启动转换
出口参数：返回ADC的转换结果
********************************************************************************
*/
uint32_t MS561101BA_DO_CONVERSION(uint8_t command)
{
    uint32_t conversion=0;
    uint8_t conv1,conv2,conv3; 
    
    CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态
    							//进入中断
    //设定转换的数据位启动转换
    EE_I2C_Start();
    EE_I2C_SendByte(MS561101BA_SlaveAddress);
    EE_I2C_SendByte(command);
    EE_I2C_Stop();
     OSIntExit(); //退出临界状态
    							//进入中断
    
    Delayms(10);
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态//进入临界状态
    							//进入中断
    //ADC值读取
    EE_I2C_Start();
    EE_I2C_SendByte(MS561101BA_SlaveAddress);
    EE_I2C_SendByte(0);
    
    //I2C从MS5611-01BA读取数据
    EE_I2C_Start();
    EE_I2C_SendByte(MS561101BA_SlaveAddress+1);
    conv1=EE_I2C_RecvByte();
    EE_I2C_SendACK(0);
    conv2=EE_I2C_RecvByte();
    EE_I2C_SendACK(0);
    conv3=EE_I2C_RecvByte();
    EE_I2C_SendACK(1);
    EE_I2C_Stop();
     
   						//进入中断
    
    conversion=conv1*65535+conv2*256+conv3;
    OSIntExit(); //退出临界状态
    
    return conversion;
}

/*
********************************************************************************
函数名称：void MS561101BA_getTemperature(uint8_t OSR_Temp)
函数功能：MS561101BA温度值转换
入口参数：OSR_Temp：温度位数指令
出口参数：无
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
函数名称：float MS561101BA_getPressure(uint8_t OSR_Pres)
函数功能：MS561101BA气压值转换
入口参数：OSR_Pres：气压转换位数指令
出口参数：返回气压值
********************************************************************************
*/
float MS561101BA_getPressure(uint8_t OSR_Pres)
{
    D1_Pres= MS561101BA_DO_CONVERSION(OSR_Pres);
    OFF_ = (uint32_t)Cal_C[2]*65536+((uint32_t)Cal_C[4]*dT)/128;
    SENS = (uint32_t)Cal_C[1]*32768+((uint32_t)Cal_C[3]*dT)/256;
    
    if(TEMP < 2000)
    {
        // 在20℃下二阶温度补偿
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
    return Pressure;                                        //得到bar值
}
/*
********************************************************************************
函数名称：void MS561101BA_Init(void)
函数功能：MS561101BA初始化，实现复位和prom读取
入口参数：无
出口参数：无
********************************************************************************
*/
void MS561101BA_Init(void)
{
    SCL_OUT();
    MS561101BA_RESET();                                //芯片复位
    MS561101BA_PROM_READ();                            //读取PROM值
}

/*
********************************************************************************
函数名称：void MS561101BA_Pressure_Read(void)
函数功能：MS561101BA气压值读取
入口参数：无
出口参数：为kpa气压值
********************************************************************************
*/
float MS561101BA_Pressure_Read(void)
{
    float Pre = 0;
    //MS561101BA_getTemperature(MS561101BA_D2_OSR_4096);       //必须要运行温度后续才能补偿气压
    Pre = MS561101BA_getPressure(MS561101BA_D1_OSR_4096);
    Pre = Pre / 1000;                                        //输出kbar
    return Pre;
}

/*
********************************************************************************
函数名称：float MS561101BA_Temperature_Read(void)
函数功能：MS561101BA温度值读取
入口参数：无
出口参数：℃温度值
********************************************************************************
*/
float MS561101BA_Temperature_Read(void)
{
    float temp = 0;
    temp = MS561101BA_getTemperature(MS561101BA_D2_OSR_4096);
    temp = temp / 100;                                        //输出温度值
    return temp;
}
