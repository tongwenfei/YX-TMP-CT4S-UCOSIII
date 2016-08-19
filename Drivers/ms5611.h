/*******************************************************************************
 *CopyRight Reserved:	
 *Filename£º			MS561101BA.h
 *Description£º     	        °åµ×²ã¾øÑ¹²âÁ¿Çý¶¯ 
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __MS5611_H__
#define __MS5611_H__

#define SDA_IN()        {GPIOB->CRH &= 0xff0ffffF;GPIOB->CRH |= (8<<20);}
#define SDA_OUT()       {GPIOB->CRH &= 0xff0ffffF;GPIOB->CRH |= (0x3<<20);}
#define SDA_HIGH()       (PBout(13)=1)
#define SDA_LOW()       (PBout(13)=0)
#define SDA()        PBin(13)
#define SCL_HIGH()       (PBout(12)=1)
#define SCL_LOW()       (PBout(12)=0)
/**********************º¯Êý²¿·Ö*****************************/

extern void MS561101BA_Init(void);
extern float MS561101BA_Pressure_Read(void);
extern float MS561101BA_Temperature_Read(void);




#endif