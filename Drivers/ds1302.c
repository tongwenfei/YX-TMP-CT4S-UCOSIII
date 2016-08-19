/*******************************************************************************
*CopyRight Reserved:	
*Filename��			DS1302.c
*Description��     	        ʵ�ֶ�ʵʱʱ�ӵĶ�д
*Date:
*Author:		
*******************************************************************************/
#include "ds1302.h"

Time_Typedef TimeValue = {16,4,19,2,11,27,25};
u8 ascii_time[7] = {0}; 	//����ascii��ʽ����

u8 bcd_time[7] = {0};		//����bcd������

static u8 AsciiToBcd(u8 asciiData)
{
  u8 bcdData = 0;
  bcdData = (((asciiData/10)<<4)|((asciiData%10)));
  return bcdData;
}
static u8 BcdToAscii(u8 bcdData)
{
  u8 asciiData = 0;
  asciiData = (((bcdData&0xf0)>>4)*10 + (bcdData&0x0f));
  return asciiData;
}

//IO�ڳ�ʼ��
void Ds1302_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOB, ENABLE);
  
  //RST
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0|GPIO_Pin_1;	   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  
  //CLK
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_9;	   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  
}

//��ȡһ���ֽڵ�ʱ��
u8 Ds1302_ReadByte(void)
{
  u8 i = 0, dat = 0;
  DS1302_DAT_INPUT();
  delay_us(5);
  for(i = 0; i <8; i++)
  {
    dat >>= 1;
    if(DS1302_DATIN == 1)dat |= 0x80;
    DS1302_CLK = 1;
    delay_us(2);
    DS1302_CLK = 0;
    delay_us(2);
  }
  return dat;
}

//д��һ���ֽڵ�ʱ��
void Ds1302_WriteByte(u8 dat)
{
  u8 i = 0, data = dat;
  DS1302_DAT_OUTPUT(); 
  DS1302_CLK = 0;
  delay_us(2);
  for(i = 0; i < 8; i++)
  {
    DS1302_DATOUT = data&0x01;
    delay_us(2);
    DS1302_CLK = 1;
    delay_us(2);
    DS1302_CLK = 0;
    data >>= 1;
  }
}

//д��һ���Ĵ���
void Ds1302_Write(u8 address,u8 dat)
{
  DS1302_RST = 0;
  DS1302_CLK = 0;
  DS1302_RST = 1;
  Ds1302_WriteByte(address);
  Ds1302_WriteByte(dat);
  DS1302_CLK = 1;
  DS1302_RST = 0;
}

//����д��ʱ��
void Ds1302_Write_Time_Singel(u8 address,u8 dat)
{
  DS1302_WP_Disable();	//ȡ��д����
  Ds1302_Write(address,dat);
  DS1302_WP_Enable();	//��д����
}

//һ���������ʱ�����
//start��ǰʱ�����л���ֹͣ
void Ds1302_Time_Init(void)
{
  Ds1302_GPIO_Init();
  DS1302_WP_Disable();		//ȡ��д����
  Ds1302_Write((0xc0|0x3c),0x55) ;
  Ds1302_Write(Address_second,(AsciiToBcd(TimeValue.second)|1));
  Ds1302_Write(Address_minute,AsciiToBcd(TimeValue.minute));
  Ds1302_Write(Address_hour,AsciiToBcd(TimeValue.hour));
  Ds1302_Write(Address_date,AsciiToBcd(TimeValue.date));
  Ds1302_Write(Address_month,AsciiToBcd(TimeValue.month));
  Ds1302_Write(Address_week,AsciiToBcd(TimeValue.week));
  Ds1302_Write(Address_year,AsciiToBcd(TimeValue.year));
  DS1302_WP_Enable();	//��д����
}


//��ȡһ���ֽ�
u8 Ds1302_Read(u8 address)
{
  u8 data = 0;
  DS1302_RST = 0;
  DS1302_CLK = 0;
  DS1302_RST = 1;
  Ds1302_WriteByte(address|0x01); //��ȡ��ַ��Ҫ��0x01������Ϊ���1
  data = Ds1302_ReadByte();
  DS1302_CLK = 1;
  DS1302_RST = 0;
  return data;
}

void Ds1302_Set_Time(Time_Typedef *time)
{
  DS1302_WP_Disable();		//ȡ��д����
  Ds1302_Write(Address_second,(AsciiToBcd(time->second)|1));
  Ds1302_Write(Address_minute,AsciiToBcd(time->minute));
  Ds1302_Write(Address_hour,AsciiToBcd(time->hour));
  Ds1302_Write(Address_date,AsciiToBcd(time->date));
  Ds1302_Write(Address_month,AsciiToBcd(time->month));
  Ds1302_Write(Address_week,AsciiToBcd(time->week));
  Ds1302_Write(Address_year,AsciiToBcd(time->year));
  DS1302_WP_Enable();	//��д����
}
//��ȡʱ���ʱ��Ĭ����ʱ��������
void Ds1302_Read_Time(void)
{
  TimeValue.second = BcdToAscii(Ds1302_Read(Address_second));  //��
  TimeValue.minute = BcdToAscii(Ds1302_Read(Address_minute));  //��
  TimeValue.hour = BcdToAscii(Ds1302_Read(Address_hour));	//Сʱ
  TimeValue.date = BcdToAscii(Ds1302_Read(Address_date)); //��
  TimeValue.month = BcdToAscii(Ds1302_Read(Address_month)); //��
  TimeValue.week = BcdToAscii(Ds1302_Read(Address_week));	//���ڼ�
  TimeValue.year = BcdToAscii(Ds1302_Read(Address_year)); //��
}

u8 DS1302_Check(void)
{
  u8 test_value;
  
  
  test_value = Ds1302_Read(RAM_Address29 + 1);	//�������һ��RAM��ַ�������
  
  if(0x55 == test_value)	//�ж������Ƿ��
  {
    return 0;	//�豸���������ǵ�һ���ϵ�
  }
  else return 1;	//���ǵ�һ���ϵ�����豸�쳣		
  
  
}

/******************************************************************************
* Function Name --> ����Դ�Ա��õ�س������
* Description   --> ������õ�ؽӵ��ǿɳ���﮵�ػ��������ɳ���ص�ʱ��
*                   ���Դ�DS1302�ĳ���·������������Ե�ؽ��г�磬��Ļ���ص��鷳
* Input         --> *CHG_dat���Ĵ�������ָ��
* Output        --> none
* Reaturn       --> none
******************************************************************************/
void DS1302_Charge_Manage(Charge_Typedef* CHG_dat)
{
	u8 CHG_Value;

    CHG_Value = (CHG_dat->TCSx << 4) | (CHG_dat->DSx << 2) | CHG_dat->RSx;  

	DS1302_WP_Disable();	//ȡ��д����
	Ds1302_Write(Trickle_Charger_Address,CHG_Value);
	DS1302_WP_Enable();	//��д����
}

 /******************************************************************************
* Function Name --> DS1302���õ�RAM��д����
* Description   --> none
* Input         --> *pBuff����д���ݴ����
*                   WRadd����д��ʼ��ַ����Χ��RAM_Address0 ~ RAM_Address28֮�䣬���һλ��ַ��������;
*                   num����д�ֽ����ݵ���������Χ��1 ~ 28֮��
*                   RW����д�ж�λ��0x00Ϊд������0x01Ϊ������
* Output        --> none
* Reaturn       --> none
******************************************************************************/
void DS1302_RAM_WriteRead_Data(u8* pBuff,u8 WRadd,u8 num,u8 RW)
{															 
	u8 i;	

	if(WRadd == RAM_Address29)	return;	//Ҫд�����ݵ�RAM��ַ�����һ����ֱ���˳�
										//��Ϊ���һ���ֽ����������DS1302��
	if(RW == 0x00)	//д���ݲ���
	{
		for(i = 0;i < num;i++)
		{
			DS1302_WP_Disable();	//ȡ��д����
			Ds1302_Write(WRadd+(i<<1),pBuff[i]);
			DS1302_WP_Enable();	//��д����
		}
	}
	else
	{
		for(i = 0;i < num;i++)
		{
			DS1302_WP_Disable();	//ȡ��д����
			pBuff[i] = Ds1302_Read(WRadd+1+(i<<1));
			DS1302_WP_Enable();	//��д����
		}
	}
}
