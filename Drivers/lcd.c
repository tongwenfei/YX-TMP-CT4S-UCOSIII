//----------------------------------------------------
//
//  ����΢����T8000������TFTҺ����ʾģ����ʾ����-V1.0
//           ��Ӧ��Һ����ʾ������T8000��
//
//    �������ļ���Ӧ���ֲ��и����ܳ����Ӧ����ʾ
// ʹ��ʱҪ�ȸ���ʹ�û����޸Ľӿڵ�ַ���źŶ˿ڶ���
//
//    
//         ����������΢�Ƽ��������޹�˾
//      Shenzhen TOPWAY Technology Co.,Ltd.
//
//       by Guo Qiang           2009-02-20
//
//----------------------------------------------------
#include <lcd.h>
#include <string.h>







static u8 data_exchange(u8 data)
{
  u8 temp=0;
  for(u8 i=0;i<8;i++)
  {
    if(data&0x80)temp|=(1<<i);
    data<<=1;
    
  }
  return  temp;
}
void DATAOUT(uint8_t x)     
{ 
  uint8_t temp=(((x>>1)&0x7f)|0x80);
//  GPIOD->BRR=0Xff;
 // GPIOD->BSRR=temp;
 GPIOD->ODR=(((GPIOD->ODR&0xff00))|temp);
  temp=(x&1);
  PCout(12)=temp; 
}



//-----------------------------------
// IO Roution
//-----------------------------------
void SdCmd(uint8_t Command)   //send command
{
  
  uint8_t temp=data_exchange(Command);
  CLR_LCD_A1();                 // init all control signal
  DATAOUT (temp);
  CLR_LCD_CS();                // enable the access
  CLR_LCD_WR();
  SET_LCD_WR();
  SET_LCD_CS();                // disable the access
}

void CmdEnd()               //send command
{
  uint8_t temp=data_exchange(1);
  SET_LCD_A1();                 // init all control signal
  DATAOUT (temp);
  CLR_LCD_CS();                // enable the access
  CLR_LCD_WR();
  SET_LCD_WR();
  SET_LCD_CS();                // disable the access
}

void WritePKG(uint8_t *pkg) // send a command package
{
  uint8_t i;
  
  for(i=*pkg;i;i--)
    SdCmd(*(++pkg));
  CmdEnd();
  //  Delayms(2);
}



//-----------------------------------
// Set the color
//-----------------------------------
void SetFgColor(uint16_t color)
{
  uint8_t Buffer[4];
  
  Buffer[0]=3;
  Buffer[1]=0x20;
  Buffer[2]=color;
  Buffer[3]=color>>8;
  WritePKG(Buffer);
}

void SetFontFgColor(uint16_t color)
{
  uint8_t Buffer[4];
  
  Buffer[0]=3;
  Buffer[1]=0x14;
  Buffer[2]=color;
  Buffer[3]=color>>8;
  WritePKG(Buffer);
  
}

void SetFontBgColor(uint16_t color)
{
  uint8_t Buffer[4];
  
  Buffer[0]=3;
  Buffer[1]=0x15;
  Buffer[2]=color;
  Buffer[3]=color>>8;
  WritePKG(Buffer);
}

void Clear_LCD(uint16_t  x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
  SetFgColor(0);     
  Fill_Rect(x1,y1,x2,y2);  
  SetFontFgColor(BLUE);   
  SetFontBgColor(BLACK);
  
  
}

//-----------------------------------
// String Routine
//-----------------------------------
void PrintASCII(uint16_t X, uint16_t Y, uint8_t *pstr) // max 64 byte in the string
{  
  uint8_t TempData[3], Buffer[6], NoOfChar;
  if ((X%4)!=0) return;
  //    uint16_t NoOfChar;
  TempData[0]=2;      // use internal 8x8 font
  TempData[1]=0x10;
  TempData[2]=0x00;
  WritePKG(TempData);
  
  Buffer[0]=5;        // set the location
  Buffer[1]=0x12;
  Buffer[2]=X;
  Buffer[3]=X>>8;
  Buffer[4]=Y;
  Buffer[5]=Y>>8;
  WritePKG(Buffer);
  
  NoOfChar=strlen((char*)pstr); // send the string
  SdCmd(0x17);
  SdCmd(NoOfChar);
  while(*pstr>0)
  {
    SdCmd(*pstr++);
  }
  CmdEnd();
  Delayms(1); 
} 

void PrintGB(uint16_t X, uint16_t Y, uint8_t *pstr) // max 64 byte in the string
{  
  uint8_t Buffer[6];
  uint16_t NoOfChar;
  if ((X%4)!=0) return;
  Buffer[0]=2;        // use internal 16x16 font ext-ROM
  Buffer[1]=0x10;
  Buffer[2]=0x04;
  WritePKG(Buffer);
  
  Buffer[0]=5;        // set the location
  Buffer[1]=0x12;
  Buffer[2]=X;
  Buffer[3]=X>>8;
  Buffer[4]=Y;
  Buffer[5]=Y>>8;
  WritePKG(Buffer);
  
  NoOfChar=strlen((char*)pstr); // send the string
  
  
  SdCmd(0x17);
  SdCmd(NoOfChar/2);
  
  
  while(*pstr>0)
  {
    SdCmd(*pstr++);
    
  }
  CmdEnd();
  Delayms(5);//��֤��Ч����ʾ����ʱ��
} 
void PrintGB_ROW(uint16_t X, uint16_t Y, uint8_t *pstr) // ������ʾ����
{  
  uint8_t Buffer[6],i=0;
  uint16_t NoOfChar;
  if ((X%4)!=0) return;
  NoOfChar=strlen((char*)pstr); // send the string
  while(i<NoOfChar)
  {
    Buffer[0]=2;        // use internal 16x16 font ext-ROM
    Buffer[1]=0x10;
    Buffer[2]=0x04;
    WritePKG(Buffer);
    
    Buffer[0]=5;        // set the location
    Buffer[1]=0x12;
    Buffer[2]=X;
    Buffer[3]=X>>8;
    Buffer[4]=Y;
    Buffer[5]=Y>>8;
    WritePKG(Buffer);
    
    SdCmd(0x16);
    SdCmd(pstr[i]);
    SdCmd(pstr[i+1]);
    CmdEnd();
    Y=Y+16;
    i=i+2;
    Delay_Nus(100);
  }
  
} 
void PrintGB_NUM(uint16_t X, uint16_t Y, uint8_t *pstr) // ��ʾ8*16��ASCII
{  
  uint8_t Buffer[6];
  
  if ((X%4)!=0) return;
  
  while(*pstr>0)
  {
    Buffer[0]=2;        // use internal 16x16 font ext-ROM
    Buffer[1]=0x10;
    Buffer[2]=0x04;
    WritePKG(Buffer);
    
    Buffer[0]=5;        // set the location
    Buffer[1]=0x12;
    Buffer[2]=X;
    Buffer[3]=X>>8;
    Buffer[4]=Y;
    Buffer[5]=Y>>8;
    WritePKG(Buffer);
    
    SdCmd(0x16);
    SdCmd(*pstr++);
    //SdCmd(pstr[i+1]);
    CmdEnd();
    X=X+8;
    
    Delay_Nus(100);
  }
  
} 
void Show_Str(uint16_t X, uint16_t Y, uint8_t *pstr) // ��Ӣ�Ļ����ʾ
{
  uint8_t Buffer[6];
  if ((X%4)!=0) return;
  while(*pstr>0)
  {
    if(*pstr>0x80)
    { 
      Buffer[0]=2;        // use internal 16x16 font ext-ROM
      Buffer[1]=0x10;
      Buffer[2]=0x04;
      WritePKG(Buffer);
      
      Buffer[0]=5;        // set the location
      Buffer[1]=0x12;
      Buffer[2]=X;
      Buffer[3]=X>>8;
      Buffer[4]=Y;
      Buffer[5]=Y>>8;
      WritePKG(Buffer);
      
      SdCmd(0x16);
      SdCmd(*pstr++);
      SdCmd(*pstr++);
      CmdEnd();
      X=X+16;
      Delay_Nus(120);
    }
    else
    {
      Buffer[0]=2;        // use internal 16x16 font ext-ROM
      Buffer[1]=0x10;
      Buffer[2]=0x04;
      WritePKG(Buffer);
      
      Buffer[0]=5;        // set the location
      Buffer[1]=0x12;
      Buffer[2]=X;
      Buffer[3]=X>>8;
      Buffer[4]=Y;
      Buffer[5]=Y>>8;
      WritePKG(Buffer);
      
      SdCmd(0x16);
      SdCmd(*pstr++);
      CmdEnd();
      X=X+8;
      Delay_Nus(120);
    }
  }
}
//------------------------------------------------
// Drawing Shape
//------------------------------------------------
void Draw_Dot(uint16_t X,uint16_t Y)
{
  uint8_t Buffer[6];
  
  Buffer[0]=5;
  Buffer[1]=0x23;
  Buffer[2]=X;
  Buffer[3]=X>>8;
  Buffer[4]=Y;
  Buffer[5]=Y>>8;
  WritePKG(Buffer);
  Delay_Nus(18);
  
}

void Draw_Line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
  uint8_t Buffer[10];
  
  Buffer[0]=9;
  Buffer[1]=0x24;
  Buffer[2]=x1;
  Buffer[3]=x1>>8;
  Buffer[4]=y1;
  Buffer[5]=y1>>8;
  Buffer[6]=x2;
  Buffer[7]=x2>>8;
  Buffer[8]=y2;
  Buffer[9]=y2>>8;
  WritePKG(Buffer);
  Delayms(5);
}

void Draw_Rect(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
  uint8_t Buffer[10];
  
  Buffer[0]=9;
  Buffer[1]=0x26;
  Buffer[2]=x1;
  Buffer[3]=x1>>8;
  Buffer[4]=y1;
  Buffer[5]=y1>>8;
  Buffer[6]=x2;
  Buffer[7]=x2>>8;
  Buffer[8]=y2;
  Buffer[9]=y2>>8;
  WritePKG(Buffer);
  Delayms(5);
}

void Fill_Rect(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
  uint8_t Buffer[10];
  
  Buffer[0]=9;
  Buffer[1]=0x27;
  Buffer[2]=x1;
  Buffer[3]=x1>>8;
  Buffer[4]=y1;
  Buffer[5]=y1>>8;
  Buffer[6]=x2;
  Buffer[7]=x2>>8;
  Buffer[8]=y2;
  Buffer[9]=y2>>8;
  WritePKG(Buffer);
  Delayms(5);
}

void Draw_Circle(uint16_t X,uint16_t Y, uint8_t R)
{
  uint8_t Buffer[7];
  
  Buffer[0]=6;
  Buffer[1]=0x28;
  Buffer[2]=X;
  Buffer[3]=X>>8;
  Buffer[4]=Y;
  Buffer[5]=Y>>8;
  Buffer[6]=R;
  WritePKG(Buffer);
  Delayms(20);
}

void Fill_Circle(uint16_t x,uint16_t y,uint8_t r)
{
  uint8_t Buffer[7];
  
  Buffer[0]=6;
  Buffer[1]=0x29;
  Buffer[2]=x;
  Buffer[3]=x>>8;
  Buffer[4]=y;
  Buffer[5]=y>>8;
  Buffer[6]=r;
  WritePKG(Buffer);
  Delayms(20);
}
/*
��ָ������һ����ɫͼ
sx��sy������꣬ex��ey�յ����꣬*picͼƬ����ָ�룬lenͼƬ���ݳ���
*/
void Draw_Pic(u16 sx,u16 sy,u16 ex,u16 ey,u8 *pic,u16 len)
{  							  
  u16 temp,t1,t;
  u16 x0=sx;
  ;
  //���ô���		   
  
  for(t=0;t<len;t++)
  {   
    temp=pic[t];					
    for(t1=0;t1<8;t1++)
    {			    
      if(!(temp&0x80))
        Draw_Dot(sx,sy);
      temp<<=1;
      sx++;
      if(sx>=320)return;		//��������
      if(sx>=ex)
      {
        sx=x0;
        sy++;
        if(sy>=ey)return;	//��������
        break;
      }
    }  	 
  }  	    	   	 	  
}   













uint8_t  Set_F500[]={4,0x83,0x00,0xf5,0x00};  // Reg[f500]=00 (internal MCS0 cycle pulse width)
uint8_t  Set_F504[]={4,0x83,0x04,0xf5,0x04};  // Reg[f504]=44 (internal MCS1 pulse sidth)
uint8_t  Set_F505[]={4,0x83,0x05,0xf5,0x80};  // Reg[f505]=80 (internal MCS1 memory accessing setting)

uint8_t  Set_F6C4[]={4,0x83,0xc4,0xf6,0x10};  // Reg[f505]=80 Set Memory Clock Divide
uint8_t  Set_F080[]={4,0x83,0x80,0xf0,0xfc};  // Reg[f080]=fc,bc,b4 (16bpp TFT) ok
uint8_t  Set_F088[]={4,0x83,0x88,0xf0,0x50};
uint8_t  Set_F089[]={4,0x83,0x89,0xf0,0xfa};
uint8_t  Set_F08E[]={4,0x83,0x8e,0xf0,0x32};  // Reg[f08e]=32 (set pixel clock and LCD_ON)
uint8_t  Set_8F[]={7,0x8f,0x69,0x45,0x61,0x67,0x6c,0x65};


static void LCD_GPIO_Init(void)
{	
  
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /*	��ʼ��GPIOC	*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6 | GPIO_Pin_7|GPIO_Pin_8 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //������� 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12  ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //������� 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1 | GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //������� 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  SET_LCD_CS();
  SET_LCD_WR();
  CLR_LCD_A1();
  
  
}
void LCD_Init(void)
{
  LCD_GPIO_Init();
  CLR_LCD_RST(); Delayms(20);
  SET_LCD_RST(); Delayms(800);
  SET_LCD_LED();
  SET_LCD_RD();
  DATAOUT(0xff);    // init all the port
  SET_LCD_CS();
  SET_LCD_RST();
  CLR_LCD_A1();;
  SET_LCD_WR();
  
  
  
  // execute all the setting in above
  // WritePKG(Set_F500);
  WritePKG(Set_F504);
  
  WritePKG(Set_F505);
  
  WritePKG(Set_F6C4);
  
  
  //WritePKG(Set_F080);
  WritePKG(Set_F088);
  
  WritePKG(Set_F089);
  
  WritePKG(Set_F08E);
  
  WritePKG(Set_8F);
  Clear_LCD(0,0,320,240);
  //OSTimeDly(100);
  
  
}
void LCD_Invert(uint8_t Invert )
{
  if(Invert==0)
  {
    SetFgColor(0);
    SetFontFgColor(BLUE); 
    SetFontBgColor(BLACK);
    
  }
  else
  {
    SetFgColor(0);
    SetFontFgColor(BLACK); 
    SetFontBgColor(BLUE);
    
  }
  
}


