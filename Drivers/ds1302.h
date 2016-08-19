/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			Ds1302.h
 *Description��     	        ʵ�ֶ�ʵʱʱ�ӵĶ�д
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __DS1302_H
#define __DS1302_H
#include "include.h"


extern u8 ascii_time[7];     //����ascii��ʽ����

extern u8 bcd_time[7];       //����bcd������


#define DS1302_RST      PEout(1)
#define DS1302_CLK      PBout(9)
#define DS1302_DATIN    PEin(0)
#define DS1302_DATOUT   PEout(0)

#define DS1302_DAT_INPUT()     {GPIOE->CRL &= 0XFFFFFFF0;GPIOE->CRL|=8;}
#define DS1302_DAT_OUTPUT()    {GPIOE->CRL &= 0XFFFFFFF0;GPIOE->CRL|=3;}


/******************************************************************************
                                 ����ʱ��ṹ
******************************************************************************/

typedef struct
{
	uint16_t year;	//��
	uint8_t month;	//��
	uint8_t date;	//��
	uint8_t week;	//����
	uint8_t hour;	//Сʱ
	uint8_t minute;	//����
	uint8_t second;	//���� 
}Time_Typedef;

extern Time_Typedef TimeValue;	//����ʱ�����ݻ���

#define test_data				0x55	//�������������DS1302�Ƿ�������������ã����Ը�������ֵ

/******************************************************************************
                                ������������
******************************************************************************/

#define Clock_Address_Bass		0x80	//����ַ

#define Address_year			(Clock_Address_Bass | 0x0c)	//��
#define Address_month			(Clock_Address_Bass | 0x08)	//��
#define Address_date			(Clock_Address_Bass | 0x06)	//��
#define Address_week			(Clock_Address_Bass | 0x0a)	//����
#define Address_hour			(Clock_Address_Bass | 0x04)	//Сʱ
#define Address_minute			(Clock_Address_Bass | 0x02)	//����
#define Address_second			(Clock_Address_Bass | 0x00)	//��

#define Clock_Burst				(Clock_Address_Bass | 0x3e)	//ʱ����λ

//д�����Ĵ���
#define Address_WP				(Clock_Address_Bass | 0x0e)	//д����

#define WP_Enable				0x80	//��д����
#define WP_Disable				0x00	//�ر�д����

/******************************************************************************
��Դ����Ĵ���λ����
    bit7  bit6  bit5  bit4  bit3  bit2  bit1  bit0
	TCS3  TCS2  TCS1  TCS0   DS1   DS0   RS1   RS0

	TCSx����������Сѡ��ֵΪ0xa0ʱ�򿪳�磬����ֵʱ�رգ�DS1302Ĭ���ǹرյ�
	DSx������VCC1��VCC2֮��Ķ����ܴ���������0x01ʱΪ����һֻ�����ܣ�0x10ʱΪ������ֻ�����ܣ�0x00��0x11ʱ�رճ�繦��
	RSx���������������С��0x00Ϊ��·���رճ�繦�ܣ�0x01Ϊ2K��0x10Ϊ4K��0x11Ϊ8K
******************************************************************************/
//������Ĵ����ṹ
typedef struct
{
	uint8_t TCSx;	//��翪��
	uint8_t DSx;	//����������
	uint8_t RSx;	//�������� 
}Charge_Typedef;

extern Charge_Typedef ChargeValue;	//������Ĵ���

//��Դ����
#define Trickle_Charger_Address	(Clock_Address_Bass | 0x10)	//�����Դ������Դ����ʱ�������ø����õ�س��

#define Open_Trickle_Charge		0x0a
#define Close_Trickle_Charge	0x00	//����Ϊ����ֵҲ����

#define One_Diode				0x01
#define Two_Diode				0x10
#define None_Diode				0x00	//or 0x11���Ͽ��������رճ�繦��

#define Resistor_For2K			0x01
#define Resistor_For4K			0x10
#define Resistor_For8K			0x11
#define None_Resistor			0x00	//�Ͽ������������貢�رճ�繦��


//RAM��ַ
#define RAM_Address_Bass		0xc0	//����ַ

#define RAM_Address0			(RAM_Address_Bass | 0x00)	//RAM��ַ = ����ַ + ��ַƫ����
#define RAM_Address1			(RAM_Address_Bass | 0x02)
#define RAM_Address2			(RAM_Address_Bass | 0x04)
#define RAM_Address3			(RAM_Address_Bass | 0x06)
#define RAM_Address4			(RAM_Address_Bass | 0x08)
#define RAM_Address5			(RAM_Address_Bass | 0x0a)
#define RAM_Address6			(RAM_Address_Bass | 0x0c)
#define RAM_Address7			(RAM_Address_Bass | 0x0e)

#define RAM_Address8			(RAM_Address_Bass | 0x10)
#define RAM_Address9			(RAM_Address_Bass | 0x12)
#define RAM_Address10			(RAM_Address_Bass | 0x14)
#define RAM_Address11			(RAM_Address_Bass | 0x16)
#define RAM_Address12			(RAM_Address_Bass | 0x18)
#define RAM_Address13			(RAM_Address_Bass | 0x1a)
#define RAM_Address14			(RAM_Address_Bass | 0x1c)
#define RAM_Address15			(RAM_Address_Bass | 0x1e)

#define RAM_Address16			(RAM_Address_Bass | 0x20)
#define RAM_Address17			(RAM_Address_Bass | 0x22)
#define RAM_Address18			(RAM_Address_Bass | 0x24)
#define RAM_Address19			(RAM_Address_Bass | 0x26)
#define RAM_Address20			(RAM_Address_Bass | 0x28)
#define RAM_Address21			(RAM_Address_Bass | 0x2a)
#define RAM_Address22			(RAM_Address_Bass | 0x2c)
#define RAM_Address23			(RAM_Address_Bass | 0x2e)

#define RAM_Address24			(RAM_Address_Bass | 0x32)
#define RAM_Address25			(RAM_Address_Bass | 0x34)
#define RAM_Address26			(RAM_Address_Bass | 0x36)
#define RAM_Address27			(RAM_Address_Bass | 0x38)
#define RAM_Address28			(RAM_Address_Bass | 0x3a)
#define RAM_Address29			(RAM_Address_Bass | 0x3c)

#define RAM_BURST				(RAM_Address_Bass | 0x3e)


//д��Ϊ00������ʱ��
#define DS1302_Start_Second()	(Ds1302_Write(Address_second,0x00))

//д��������
#define	DS1302_WP_Enable()		(Ds1302_Write(Address_WP,WP_Enable))	//��д����
#define	DS1302_WP_Disable()		(Ds1302_Write(Address_WP,WP_Disable))	//�ر�д����

//�رճ�繦�ܣ�����ֱ�ӵ���
#define DS1302_Disable_Charge()	(Ds1302_Write(Trickle_Charger_Address,0x00))

/******************************************************************************
                                 �ⲿ���ܺ���
******************************************************************************/



void Ds1302_GPIO_Init(void);
void Ds1302_Time_Init(void);
void Ds1302_Read_Time(void);
  u8 DS1302_Check(void);
void Ds1302_Set_Time(Time_Typedef *time);
void Ds1302_Write(u8 address,u8 dat);

#endif






