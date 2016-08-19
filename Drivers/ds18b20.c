/*
********************************************************************************
*CopyRight Reserved:	���ǿƼ�
*Filename��		ds18b20.c
*Description��     DS18B20�ײ�����     
*Date:
*Author:		Wenfei Tong
********************************************************************************
*/
#include "include.h" 
 uint8_t Cal_CRC(uint8_t *ptr,uint32_t len)
{
  uint8_t DATA=0,i;
  while(len--)
  {
    DATA^=*ptr++;
    for(i=0;i<8;i++)
    {
      if(DATA&0x01)DATA=(DATA>>1)^0x8C;
      else DATA>>=1;
    }
  }
  return DATA;
}


//��λDS18B20
void DS18B20_Rst(void)	   
{                 
	DS18B20_IO_OUT(); 	//SET PA8 OUTPUT
    DS18B20_DQ_OUT=0; 	//����DQ
    Delay_Nus(750);    	//����750us
    DS18B20_DQ_OUT=1; 	//DQ=1 
	Delay_Nus(15);     	//15US
}
//�ȴ�DS18B20�Ļ�Ӧ
//����1:δ��⵽DS18B20�Ĵ���
//����0:����
uint8_t DS18B20_Check(void) 	   
{   
	uint8_t retry=0;
	DS18B20_IO_IN();	//SET PA8 INPUT	 
    while (DS18B20_DQ_IN&&retry<200)
	{
		retry++;
		Delay_Nus(1);
	};	 
	if(retry>=200)return 1;
	else retry=0;
    while (!DS18B20_DQ_IN&&retry<240)
	{
		retry++;
		Delay_Nus(1);
	};
	if(retry>=240)return 1;	    
	return 0;
}
//��DS18B20��ȡһ��λ
//����ֵ��1/0
uint8_t DS18B20_Read_Bit(void) 	 
{
    uint8_t data;
    
	DS18B20_IO_OUT();	//SET PA8 OUTPUT
    DS18B20_DQ_OUT=0; 
	Delay_Nus(2);
    DS18B20_DQ_OUT=1; 
	DS18B20_IO_IN();	//SET PA8 INPUT
	Delay_Nus(12);
	if(DS18B20_DQ_IN)data=1;
    else data=0;	 
    Delay_Nus(50);           
    return data;
}
//��DS18B20��ȡһ���ֽ�
//����ֵ������������
uint8_t DS18B20_Read_Byte(void)     
{        
    uint8_t i,j,dat;
    dat=0;
    CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();
	for (i=1;i<=8;i++) 
	{
        j=DS18B20_Read_Bit();
        dat=(j<<7)|(dat>>1);
        }
         OSIntExit(); 
    return dat;
}
//дһ���ֽڵ�DS18B20
//dat��Ҫд����ֽ�
void DS18B20_Write_Byte(uint8_t dat)     
 {             
    uint8_t j;
    uint8_t testb;
	DS18B20_IO_OUT();	//SET PA8 OUTPUT;
    for (j=1;j<=8;j++) 
	{
        testb=dat&0x01;
        dat=dat>>1;
        if (testb) 
        {
            DS18B20_DQ_OUT=0;	// Write 1
            Delay_Nus(2);                            
            DS18B20_DQ_OUT=1;
            Delay_Nus(60);             
        }
        else 
        {
            DS18B20_DQ_OUT=0;	// Write 0
            Delay_Nus(60);             
            DS18B20_DQ_OUT=1;
            Delay_Nus(2);                          
        }
    }
}
//��ʼ�¶�ת��
void DS18B20_Start(void) 
{   						               
    DS18B20_Rst();	   
	DS18B20_Check();	 
    DS18B20_Write_Byte(0xcc);	// skip rom
    DS18B20_Write_Byte(0x44);	// convert
} 

//��ʼ��DS18B20��IO�� DQ ͬʱ���DS�Ĵ���
//����1:������
//����0:����    	 
uint8_t DS18B20_Init(void)
{
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				//PORTA.8 �������
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);

 	GPIO_SetBits(GPIOA,GPIO_Pin_8);    //���1

	DS18B20_Rst();

	return DS18B20_Check();
}  
//��ds18b20�õ��¶�ֵ
//���ȣ�0.1C
//����ֵ���¶�ֵ  
float DS18B20_Get_Temp(void)
{

  float value=0;
  uint8_t ptr[9]={0},i=0;
    DS18B20_Start ();  			// ds1820 start convert
    DS18B20_Rst();
    DS18B20_Check();	 
    DS18B20_Write_Byte(0xcc);	// skip rom
    DS18B20_Write_Byte(0xbe);	// convert	        
    for(i=0;i<9;i++)
  {
    *(ptr+i)=DS18B20_Read_Byte();
  }

  //�˳��ٽ�״̬
  
  if(*(ptr+8)==Cal_CRC(ptr,8))
  {
    if(ptr[1] & 0x80)
    {
      ptr[0]= (~ptr[0] ) + 1;         //Ϊ���¶ȣ�ȡ��
      
      ptr[1] &= 0x07;
      ptr[1] = (~ptr[1] ) + 1;
      value = (-1)*(ptr[1]*16 + ptr[0]*0.0625);
    }
    else
    {
      value = ptr[1]*16 + ptr[0]*0.0625;
    }
    return  value;
    
  }
  else return -1111;
}



 
