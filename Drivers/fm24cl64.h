/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			FM24CL64.h
 *Description：     	        实现对铁电的读写
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __FM24CL64_H__
#define __FM24CL64_H__

/**********************函数部分*****************************/
#define FM24_SDA_IN()        {GPIOB->CRH &= 0xff0ffffF;GPIOB->CRH |= (8<<20);}
#define FM24_SDA_OUT()       {GPIOB->CRH &= 0xff0ffffF;GPIOB->CRH |= (3<<20);}
#define FM24_SET_SDA()       (PBout(13)=1)
#define FM24_CLR_SDA()       (PBout(13)=0)
#define FM24_GET_SDA()        PBin(13)
#define FM24_SET_SCL()       (PBout(12)=1)
#define FM24_CLR_SCL()       (PBout(12)=0)
void EE_I2C_Start(void) ;
void EE_I2C_Stop(void) ;
void EE_I2C_SendACK(uint8_t ack)  ;
uint8_t EE_I2C_RecvACK(void);
void EE_I2C_SendByte(uint8_t dat);
uint8_t EE_I2C_RecvByte(void);
extern void FM24C64_Init(void);
extern uint8_t FM24C64_Check(void);
extern void FM24C64_WRITE_BYTE (uint16_t addr,uint8_t data);
extern uint8_t FM24C64_READ_BYTE (uint16_t addr);
extern void FM24C64_WRITE_MUL(uint16_t StartAddr, uint8_t *RdData, uint16_t Numbers);
extern void FM24C64_READ_MUL(uint16_t StartAddr, uint8_t *RdData, uint16_t Numbers);

#endif