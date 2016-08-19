/*******************************************************************************
 *CopyRight Reserved:	
 *Filename£º			key.h
 *Description£º     	        ¾ØÕó¼üÅÌÇý¶¯
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __KEY_H__
#define __KEY_H__
void Key_Init(void);
void TIM7_Init(u16 arr,u16 psc);
uint8_t Key_Scan(void);
uint8_t Get_KeyVaule(void);
#endif