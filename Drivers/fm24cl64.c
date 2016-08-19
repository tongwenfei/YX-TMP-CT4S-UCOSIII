/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			FM24CL64.c
 *Description��     	        ʵ�ֶ�����Ķ�д
 *Date:
 *Author:		
*******************************************************************************/

#include "include.h"


//��������
#define     FM24CL64_Addr     0xae    //����������IIC�����еĴӵ�ַ��Ӳ����CSBΪ�ߣ�ȡ��Ϊ��


/****************************** FM24CL64B-G ��������*****************************/


/*
********************************************************************************
�������ƣ�void EE_I2C_Start(void) 
�������ܣ�I2C��ʼ�ź�
��ڲ�������
���ڲ�������
********************************************************************************
*/
void EE_I2C_Start(void) 
{ 
    FM24_SDA_OUT();        
    FM24_SET_SDA();
    FM24_SET_SCL();
    Delay_Nus(1);
    FM24_CLR_SDA();
    Delay_Nus(1);
    FM24_CLR_SCL();    
} 

/*
********************************************************************************
�������ƣ�void EE_I2C_Stop(void)  
�������ܣ�I2Cֹͣ�ź�
��ڲ�������
���ڲ�������
********************************************************************************
*/
void EE_I2C_Stop(void) 
{ 
    FM24_SDA_OUT(); 
    FM24_CLR_SDA();
    FM24_SET_SCL();
    Delay_Nus(1);
    FM24_SET_SDA();
    Delay_Nus(1);
} 

/*
********************************************************************************
�������ƣ�void EE_I2C_SendACK(uint8_t ack) 
�������ܣ�I2C����Ӧ���ź�
��ڲ�����(0:ACK 1:NAK)
���ڲ�������
********************************************************************************
*/
void EE_I2C_SendACK(uint8_t ack)  
{ 
    FM24_SDA_OUT(); 
    if(ack == 1)
    {
        FM24_SET_SDA(); 
    }
    if(ack == 0)
    {
        FM24_CLR_SDA(); 
    }
    FM24_SET_SCL();
    Delay_Nus(1);
    FM24_CLR_SCL();
    Delay_Nus(1);
} 

/*
********************************************************************************
�������ƣ�uint8_t EE_I2C_RecvACK(void)
�������ܣ�I2C����Ӧ���ź�
��ڲ�������
���ڲ���������Ӧ���ź�
********************************************************************************
*/
uint8_t EE_I2C_RecvACK(void)
{
    uint16_t rn = 0;
    FM24_CLR_SCL();                    //����ʱ����
    FM24_SDA_IN();
    FM24_SET_SCL();                   //����ʱ����
    Delay_Nus(1);                   //��ʱ
    while(FM24_GET_SDA())
    {
        rn++;
        if(rn>1000)	  
        {
          return 1; 
        }
    }
    FM24_CLR_SCL();                   //����ʱ����
    Delay_Nus(1);                  //��ʱ
    return 0;
}
/*
********************************************************************************
�������ƣ�void EE_I2C_SendByte(uchar dat)
�������ܣ�I2Cд��1�ֽ�����
��ڲ�����д�������
���ڲ�������
********************************************************************************
*/
void EE_I2C_SendByte(uint8_t dat)
{
    uint8_t Rn = 8;
    FM24_SDA_OUT(); 
    while(Rn--)
    {
        FM24_CLR_SCL();
        Delay_Nus(1); 
        if (dat & 0x80)
        {
            FM24_SET_SDA();
        }
        else
        {
            FM24_CLR_SDA();
        }
        dat <<= 1;  
        FM24_SET_SCL();
        Delay_Nus(1);
    }
    EE_I2C_RecvACK();
}

/*
********************************************************************************
�������ƣ�uint8_t EE_I2C_RecvByte (void)
�������ܣ�I2C�����ֽ�����
��ڲ�������
���ڲ��������ؽ��յ�����
********************************************************************************
*/
uint8_t EE_I2C_RecvByte(void)
{
    uint8_t Rn=8,dat=0;
    FM24_SET_SDA();
    FM24_SDA_IN();
    while(Rn--)
    {
        dat <<= 1;
        FM24_CLR_SCL(); 
        Delay_Nus(1);
        FM24_SET_SCL();
        Delay_Nus(1);
        if(FM24_GET_SDA())
        {
            dat++;
        }
    }
    FM24_CLR_SCL(); 
    return dat;
}

/*
********************************************************************************
�������ƣ�void FM24C64_WRITE_BYTE (uint16_t addr,uint8_t data)
�������ܣ���̶���ַд��̶�����  ������EEPROM������дʱ�����������Ҫע�⣩
��ڲ�����addr-��ַ��0~8191 data-Ҫд�������
���ڲ�������
********************************************************************************
*/
void FM24C64_WRITE_BYTE (uint16_t addr,uint8_t data)
{ 
    uint8_t SlaveADDR; 
    
    //�����ٽ�״̬
    OSIntEnter();							//�����ж�
    
    SlaveADDR = (uint8_t)(addr >> 8);	         //��д��λ
    EE_I2C_Start();
    EE_I2C_SendByte(FM24CL64_Addr); 
    
    EE_I2C_SendByte (SlaveADDR);                 //д��λ��ַ
    EE_I2C_SendByte ((uint8_t)addr);               //д��λ��ַ
    
    EE_I2C_SendByte (data);                      //д������
    EE_I2C_Stop(); 
    
    //�˳��ٽ�״̬
    OSIntEnter();							//�����ж�
}

/*
********************************************************************************
�������ƣ�void FM24C64_WRITE_MUL(uint16_t StartAddr, uint8_t *RdData, uint16_t Numbers)
�������ܣ����ַд�����ݣ�����EEPROM������дʱ�����������Ҫע�⣩
��ڲ�����StartAddr��������ʼ��ַ0~8191  *RdData��Ҫд������ݵ�ַ   Numbers�����ݸ��� 
���ڲ�������
********************************************************************************
*/
void FM24C64_WRITE_MUL(uint16_t StartAddr, uint8_t *RdData, uint16_t Numbers)
{ 
    uint8_t SlaveADDR;
    
    //�����ٽ�״̬
    OSIntEnter();							//�����ж�
    
    SlaveADDR = (uint8_t)(StartAddr >> 8);
    EE_I2C_Start();
    EE_I2C_SendByte(FM24CL64_Addr);         // E2PROM Ƭѡ
    EE_I2C_SendByte(SlaveADDR);                  //д��8λ��ַ
    EE_I2C_SendByte(StartAddr);                  //д��8λ��ַ
    while(Numbers--)
    {
        EE_I2C_SendByte(*RdData);
        RdData++;
    }
    EE_I2C_Stop();  
    //�˳��ٽ�״̬
    OSIntEnter();							//�����ж�
}
/*
********************************************************************************
�������ƣ�uint8_t FM24C64_READ_BYTE (uint16_t addr)
�������ܣ���̶���ַ�������ݣ�ѡ���ַ�������
��ڲ�����addr�������ĵ�ַ
���ڲ��������ض�ȡ��ַ������
********************************************************************************
*/
uint8_t FM24C64_READ_BYTE (uint16_t addr)
{ 
    uint8_t SlaveADDR,DATA_R;
    
    //�����ٽ�״̬
    OSIntEnter();							//�����ж�
    
    SlaveADDR = (uint8_t)(addr >> 8);
    EE_I2C_Start();
    EE_I2C_SendByte(FM24CL64_Addr);
    EE_I2C_SendByte(SlaveADDR);
    EE_I2C_SendByte(addr);

    EE_I2C_Start ();
    EE_I2C_SendByte (FM24CL64_Addr+1);
    DATA_R = EE_I2C_RecvByte();
    EE_I2C_SendACK(1);
    EE_I2C_Stop();
    //�˳��ٽ�״̬
    OSIntEnter();							//�����ж�
    
    return DATA_R;
}

/*
********************************************************************************
�������ƣ�void FM24C64_READ_MUL(uint16_t StartAddr, uint8_t *RdData, uint16_t Numbers)
�������ܣ��ӹ̶���ַ�����������
��ڲ�����StartAddr-��ʼ��ַ��RdData-���ݴ�Ż�����
���ڲ�������
********************************************************************************
*/
void FM24C64_READ_MUL(uint16_t StartAddr, uint8_t *RdData, uint16_t Numbers)
{ 
    uint8_t SlaveADDR;
    
    //�����ٽ�״̬
    OSIntEnter();							//�����ж�
    
    SlaveADDR=(uint8_t)(StartAddr >> 8);
    EE_I2C_Start();
    EE_I2C_SendByte(FM24CL64_Addr);                //Ƭѡ
    EE_I2C_SendByte(SlaveADDR);  
    EE_I2C_SendByte(StartAddr);                         //ROM�׵�ַ(0-1FFF)
    
    EE_I2C_Start();
    EE_I2C_SendByte(FM24CL64_Addr+1);              //��
    while(Numbers>1)
    {   
        *RdData =EE_I2C_RecvByte();
        EE_I2C_SendACK(0);                              //Ӧ��
        Numbers--;   
        RdData++;
    }    
    *RdData =EE_I2C_RecvByte();
    EE_I2C_SendACK(1);                                  //��Ӧ��
    EE_I2C_Stop ();
    //�˳��ٽ�״̬
    OSIntEnter();							//�����ж�
}

/*
********************************************************************************
�������ƣ�uint8_t FM24C64_Check(void)
�������ܣ�ʵ��FM24CL64�ļ��
��ڲ�������
���ڲ�����1����ȷ   0������
********************************************************************************
*/
uint8_t FM24C64_Check(void)
{
    uint16_t ADDRESS;
    uint8_t j,DATAW = 0x55;
    uint8_t DATAR = 0; 
    for(ADDRESS = 0; ADDRESS < 8192; ADDRESS++)
    {
        for(j=0;j<2;j++)                                    //д0xaa��0x55
        {
            FM24C64_WRITE_BYTE(ADDRESS,DATAW);              //д��0x55
            DATAR=FM24C64_READ_BYTE(ADDRESS);               //����0x55
            if(DATAR!=DATAW)                                //д��Ͷ����Ĳ���ͬ
            {
                return 0;
            }
            DATAW = ~DATAW;                                 //ȡ��д��0xaa���ٱȽ�
        }
    }   
    return 1;  
}
/*
********************************************************************************
�������ƣ�void FM24C64_Init(void)
�������ܣ�ʵ��SCL�ĳ�ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void FM24C64_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//����GPIOC����ʱ��
  
  /*	��ʼ��GPIOC	*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //������� 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}


/*
********************************************************************************
�������ƣ�void FM24C64_Data_Storage(uint8_t storage_number,uint8_t type)
�������ܣ�����������200�����ݴ洢
��ڲ�����storage_number��1~200    type:  0,Ϊ��������1Ϊд����
���ڲ�������
********************************************************************************
*/
void FM24C64_Data_Storage(uint8_t storage_number,uint8_t type)
{   
  
    if(type == 1)
    {

       if(storage_number > 80)
       {
            storage_number = 1;
        }
        FM24C64_WRITE_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);         //д�����ڴ洢�˶��ٸ��ļ�
        
       
        
        //����洢�����
        FM24C64_WRITE_MUL((STORAGE_START + ((storage_number-1)*100)), (uint8_t*)&g_StorageData, sizeof(g_StorageData));       //�洢�����

    }
    else
    {
        //����洢�����
        FM24C64_READ_MUL((STORAGE_START + ((storage_number-1)*100)), (uint8_t*)&g_StorageData, sizeof(g_StorageData));       //�洢�����
    }

}