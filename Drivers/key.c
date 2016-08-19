/*******************************************************************************
*CopyRight Reserved:	
*Filename：			key.c
*Description：     	        矩阵键盘驱动
*Date:
*Author:		
*******************************************************************************/
#include "include.h"
//const uint8_t key_tab[]={11,22,44,88,
//                   10,20,40,80,
//                   9 ,18,36,72,
//                   13,26,52,104
//};//物理按键
const uint8_t key_tab[]={
88,44,80,22,
40,72,36,10,
104,52,26,20,
18,13,9,11
};//贴膜按键
void Key_Init(void)
{ 
    GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				//PORTA.8 推挽输出
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
        
       
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;				//PORTA.8 推挽输出
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
        
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;				//PORTA.8 推挽输出
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
        
        

//        GPIOA->CRL&=0x0000FFFF;
//        GPIOA->CRL|=0x88880000;
//        GPIOB->CRL&=0xFFFFFF00;
//        GPIOB->CRL|=0x33;
//        GPIOC->CRL&=0xFF00FFFF;
//        GPIOC->CRL|=0x330000;
//        GPIO_ResetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
         GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);
         GPIO_SetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5);
        
        
        
        
        
}
void Key_Col_Init(void)
{ 
    GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				//PORTA.8 推挽输出
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
        
       
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;				//PORTA.8 推挽输出
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
        
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;				//PORTA.8 推挽输出
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
  
//        GPIOA->CRL&=0x0000FFFF;
//        GPIOA->CRL|=0x33330000;
//        GPIOB->CRL&=0xFFFFFF00;
//        GPIOB->CRL|=0x88;
//        GPIOC->CRL&=0xFF00FFFF;
//        GPIOC->CRL|=0x880000;
//        GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);
         //GPIO_ResetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5);
       GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
        
        
        
         
}




uint8_t Key_Scan(void)
{
  uint8_t row=0,col=0,temp=0;
   Key_Init();
   delay_ms(5);
  row=(GPIO_ReadInputData(GPIOA)>>4)&0x0f;
  if(row!=0)
  {
    Key_Col_Init();
    delay_ms(5);

    col=(GPIO_ReadInputData(GPIOB)&0x03)|((GPIO_ReadInputData(GPIOC)>>2)&0X0C);
    //col=((PBin(1))|((PBin(0))<<1)|(PCin(5)<<2)|(PCin(4)<<3));
    
  }
  temp=(col+1)*row;
  for(uint8_t i=0;i<16;i++)
  {
    if(temp==key_tab[i])return i+1;
  }
  return 0;
}
uint8_t Get_KeyVaule(void)
{
  static uint16_t last_key=0;
  static uint8_t cnt_press=0;
  static uint8_t cnt_release=0;
  uint16_t key=Key_Scan();           /*?ì2aμ±?°°′?ü*/

  if (key==0)
  {
    if (cnt_press)                      /*?-à′óD°′?ü?òêí·?ê±Dèòa??êyêí·?*/
    {
      if (cnt_release<2) cnt_release++;
      else cnt_press=0;
    }
  }
  else if (last_key!=key)               /*óDD?°′?ü*/
  {
    last_key=key;
    cnt_press=0;
    cnt_release=0;
  }
  else
  {
    if (cnt_release) cnt_release=0;
    cnt_press++;
    if (cnt_press==3)                   /*á?D?3′??ì2aμ??àí?°′?ü*/
    {
      return(key);
    }
    else if (cnt_press>=48)             /*á?D?48′??-?·?ì2aμ?°′?üò??±?′êí·?*/
    {
      cnt_press=47;
      return(key);
    }
  }	
  return(0);
}