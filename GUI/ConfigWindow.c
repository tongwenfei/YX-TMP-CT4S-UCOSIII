#include "ConfigWindow.h"
Time_Typedef Time_Set_Vaule;
uint8_t Config_Num=1,Time_Set_Num=1,Uart_Set_Num=1,uart_cnt=0,uart_parity_cnt=0;
uint32_t Uart_Baud_Save=115200,Uart_Bits_Save=8,Uart_Stop_Save=1,Uart_Parity_Save=0;
const uint32_t Uart_Baud[]={1200,2400,4800,9600,14400,19200,38400,56000,115200,128000,256000};
const uint8_t Uart_Bits[]={8,9};
const uint8_t Uart_Stop[]={1,2};
bool isUart_8Bits=true,isUart_1Stop=true;
void Disp_ConfigWindow(void)
{
  Clear_LCD(0,0,320,240);
  Config_Num=1;
  Uart_flag=0;
  PrintGB(112,4,"硬件设置");
  Fill_Rect(0,25,320,26);
  LCD_Invert(1);
  Show_Str(100,35,"1.时间设置");
  LCD_Invert(0);
  Show_Str(100,70,"2.串口设置");
  Show_Str(100,105,"3.参数校准");
  Show_Str(100,140,"4.清空采样数据");
  Show_Str(100,175,"5.恢复出厂设置");
  Show_Str(100,210,"6.系统升级");
  //Disp_TimeSetWindow();
}
void Config_Select(void)
{
   uint8_t *key;
  OS_MSG_SIZE size;
  OS_ERR err;
  key=OSQPend((OS_Q*			)&KEY_Msg,   
	      (OS_TICK			)0,
	      (OS_OPT			)OS_OPT_PEND_NON_BLOCKING,
	      (OS_MSG_SIZE*		)&size,		
	      (CPU_TS*			)0,
	      (OS_ERR*			)&err);
  if(Uart_flag<7)Uart_flag++;
  else Uart_flag=0;
  if(Updata_flag==0)
  {
    if(*key==4)
    {
      if(Config_Num>1)
	Config_Num--;
      else Config_Num=6;
    }
    if(*key==8)
    {
      if(Config_Num<6)
	Config_Num++;
      else Config_Num=1;
    }
    if(*key==13)
    {
      Config_Num=1;
      HW_flag=0;
      state_disp=1;
      Main_flag=1;
      Disp_MainWindow();
      return;
    }
    //  if(*key==15)
    //  {
    //    switch(Config_Num)
    //    {
    //    case 1:
    //      {
    //        Time_flag=1;
    //        Disp_TimeSetWindow();
    //      }break;
    //    case 2:
    //      {
    //        Time_flag=2;
    //      }break;
    //    case 3:
    //      {
    //        Time_flag=3;
    //      }break;
    //    case 4:
    //      {
    //        Time_flag=4;
    //        
    //      }break;
    //    case 5:
    //      {
    //        Time_flag=5;
    //      }break;
    //    case 6:
    //      {
    //        Time_flag=6;
    //      }break;
    //    }
    //  }
    
    switch(Config_Num)
    {
    case 1:
      {
	LCD_Invert(1);
	Show_Str(100,35,"1.时间设置");
	LCD_Invert(0);
	Show_Str(100,70,"2.串口设置");
	Show_Str(100,105,"3.参数校准");
	Show_Str(100,140,"4.清空采样数据");
	Show_Str(100,175,"5.恢复出厂设置");
	Show_Str(100,210,"6.系统升级");
	
      }break;
    case 2:
      {
	
	Show_Str(100,35,"1.时间设置");
	
	LCD_Invert(1);
	Show_Str(100,70,"2.串口设置");
	LCD_Invert(0);
	Show_Str(100,105,"3.参数校准");
	Show_Str(100,140,"4.清空采样数据");
	Show_Str(100,175,"5.恢复出厂设置");
	Show_Str(100,210,"6.系统升级");
      }break;
    case 3:
      {
	
	Show_Str(100,35,"1.时间设置");
	
	Show_Str(100,70,"2.串口设置");
	LCD_Invert(1);
	Show_Str(100,105,"3.参数校准");
	LCD_Invert(0);
	Show_Str(100,140,"4.清空采样数据");
	Show_Str(100,175,"5.恢复出厂设置");
	Show_Str(100,210,"6.系统升级");
      }break;
    case 4:
      {
	
	Show_Str(100,35,"1.时间设置");
	LCD_Invert(0);
	Show_Str(100,70,"2.串口设置");
	Show_Str(100,105,"3.参数校准");
	LCD_Invert(1);
	Show_Str(100,140,"4.清空采样数据");
	LCD_Invert(0);
	Show_Str(100,175,"5.恢复出厂设置");
	Show_Str(100,210,"6.系统升级");
      }break;
    case 5:
      {
	
	Show_Str(100,35,"1.时间设置");
	
	Show_Str(100,70,"2.串口设置");
	Show_Str(100,105,"3.参数校准");
	Show_Str(100,140,"4.清空采样数据");
	LCD_Invert(1);
	Show_Str(100,175,"5.恢复出厂设置");
	LCD_Invert(0);
	Show_Str(100,210,"6.系统升级");
      }break;
    case 6:
      {
	
	Show_Str(100,35,"1.时间设置");
	
	Show_Str(100,70,"2.串口设置");
	Show_Str(100,105,"3.参数校准");
	Show_Str(100,140,"4.清空采样数据");
	Show_Str(100,175,"5.恢复出厂设置");
	LCD_Invert(1);
	Show_Str(100,210,"6.系统升级");
	LCD_Invert(0);
      }break;
    }
  }
}

void Config_Enter(void)
{
   uint8_t *key;
  OS_MSG_SIZE size;
  OS_ERR err;
  key=OSQPend((OS_Q*			)&KEY_Msg,   
	      (OS_TICK			)0,
	      (OS_OPT			)OS_OPT_PEND_NON_BLOCKING,
	      (OS_MSG_SIZE*		)&size,		
	      (CPU_TS*			)0,
	      (OS_ERR*			)&err);
  if(Uart_flag>3)
  {
    if(*key==15)
    {
      switch(Config_Num)
      {
      case 1:
	{
	  HW_flag=0;
	  Time_flag=1;
	  Disp_TimeSetWindow();
	}break;
      case 2:
	{
	  HW_flag=0;
	  Time_flag=2;
	  Disp_BaudSetWindow();
	}break;
      case 3:
	{
	  Time_flag=3;
	}break;
      case 4:
	{
	  Time_flag=4;
	  
	}break;
      case 5:
	{
	  Time_flag=5;
	}break;
      case 6:
	{
	  Time_flag=6;
	}break;
      }
    }
  }
}
void ConfigSub_Select(void)
{
   uint8_t *key;
  OS_MSG_SIZE size;
  OS_ERR err;
  key=OSQPend((OS_Q*			)&KEY_Msg,   
	      (OS_TICK			)0,
	      (OS_OPT			)OS_OPT_PEND_NON_BLOCKING,
	      (OS_MSG_SIZE*		)&size,		
	      (CPU_TS*			)0,
	      (OS_ERR*			)&err);
  if(*key==13)
  {
    
    HW_flag=1;
    Time_flag=0;
    Clear_LCD(0,0,320,240);
    PrintGB(112,4,"硬件设置");
    Fill_Rect(0,25,320,26);
    return;
  }
  switch(Time_flag)
  {
    uint8_t time1[8];
  case 1:
    {
      if(*key==12)
      {
	if(Time_Set_Num>1)Time_Set_Num--;
	else Time_Set_Num=8;
      }
      else if(*key==16)
      {
	if(Time_Set_Num<8)Time_Set_Num++;
	else Time_Set_Num=1;
      }
      
      switch(Time_Set_Num)
      {
      case 1:
	{
	  if(*key==4)
	  {
	    if(Time_Set_Vaule.hour>0)Time_Set_Vaule.hour--;
	    else Time_Set_Vaule.hour=0;
	  }
	  else if(*key==8)
	  {
	    if(Time_Set_Vaule.hour<23)Time_Set_Vaule.hour++;
	    else Time_Set_Vaule.hour=23;
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  LCD_Invert(1);
	  Show_Str(116,89,time1);
	  LCD_Invert(0);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  Show_Str(156,89,time1);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  Show_Str(196,89,time1);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  Show_Str(116,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  Show_Str(172,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  Show_Str(212,149,time1);
	  
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 2:
	{
	  if(*key==4)
	  {
	    if(Time_Set_Vaule.minute>0)Time_Set_Vaule.minute--;
	    else Time_Set_Vaule.minute=0;
	  }
	  else if(*key==8)
	  {
	    if(Time_Set_Vaule.minute<59)Time_Set_Vaule.minute++;
	    else Time_Set_Vaule.minute=59;
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  Show_Str(116,89,time1);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  LCD_Invert(1);
	  Show_Str(156,89,time1);
	  LCD_Invert(0);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  Show_Str(196,89,time1);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  Show_Str(116,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  Show_Str(172,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  Show_Str(212,149,time1);
	  
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 3:
	{
	  if(*key==4)
	  {
	    if(Time_Set_Vaule.second>0)Time_Set_Vaule.second--;
	    else Time_Set_Vaule.second=0;
	  }
	  else if(*key==8)
	  {
	    if(Time_Set_Vaule.second<59)Time_Set_Vaule.second++;
	    else Time_Set_Vaule.second=59;
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  
	  Show_Str(116,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  Show_Str(156,89,time1);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  LCD_Invert(1);
	  Show_Str(196,89,time1);
	  LCD_Invert(0);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  Show_Str(116,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  Show_Str(172,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  Show_Str(212,149,time1);
	  
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 4:
	{
	  if(*key==4)
	  {
	    if(Time_Set_Vaule.year>0)Time_Set_Vaule.year--;
	    else Time_Set_Vaule.year=0;
	  }
	  else if(*key==8)
	  {
	    if(Time_Set_Vaule.year<99)Time_Set_Vaule.year++;
	    else Time_Set_Vaule.year=99;
	  }
	  if((Time_Set_Vaule.year!=0)&&((Time_Set_Vaule.year%4)!=0)&&(Time_Set_Vaule.month==2))
	  {
	    if(Time_Set_Vaule.date==29)Time_Set_Vaule.date=28;
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  
	  Show_Str(116,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  
	  Show_Str(156,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  Show_Str(196,89,time1);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  LCD_Invert(1);
	  Show_Str(116,149,time1);
	  LCD_Invert(0);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  Show_Str(172,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  Show_Str(212,149,time1);
	  
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 5:
	{
	  if(*key==4)
	  {
	    if(Time_Set_Vaule.month>1)Time_Set_Vaule.month--;
	    else Time_Set_Vaule.month=1;
	  }
	  else if(*key==8)
	  {
	    if(Time_Set_Vaule.month<12)Time_Set_Vaule.month++;
	    else Time_Set_Vaule.month=12;
	  }
	  if((Time_Set_Vaule.year!=0)&&((Time_Set_Vaule.year%4)!=0)&&(Time_Set_Vaule.month==2))
	  {
	    if(Time_Set_Vaule.date==29)Time_Set_Vaule.date=28;
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  
	  Show_Str(116,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  
	  Show_Str(156,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  Show_Str(196,89,time1);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  Show_Str(116,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  LCD_Invert(1);
	  Show_Str(172,149,time1);
	  LCD_Invert(0);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  Show_Str(212,149,time1);
	  
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 6:
	{
	  if(*key==4)
	  {
	    
	    if(Time_Set_Vaule.date>1)Time_Set_Vaule.date--;
	    else Time_Set_Vaule.date=1;
	    
	  }
	  else if(*key==8)
	  {
	    if((Time_Set_Vaule.month==1)||(Time_Set_Vaule.month==3)||(Time_Set_Vaule.month==5)||(Time_Set_Vaule.month==7)||(Time_Set_Vaule.month==8)||(Time_Set_Vaule.month==10)||(Time_Set_Vaule.month==12))
	    {
	      if(Time_Set_Vaule.date<31)Time_Set_Vaule.date++;
	      else Time_Set_Vaule.date=31;
	    }
	    else if((Time_Set_Vaule.month==4)||(Time_Set_Vaule.month==6)||(Time_Set_Vaule.month==9)||(Time_Set_Vaule.month==11))
	    {
	      if(Time_Set_Vaule.date<30)Time_Set_Vaule.date++;
	      else Time_Set_Vaule.date=30;
	    }
	    else if(Time_Set_Vaule.month==2)
	    {
	      if((Time_Set_Vaule.year==0)||((Time_Set_Vaule.year%4)==0))
	      {
		if(Time_Set_Vaule.date<29)Time_Set_Vaule.date++;
		else Time_Set_Vaule.date=29;
	      }
	      else
	      {
		if(Time_Set_Vaule.date<28)Time_Set_Vaule.date++;
		else Time_Set_Vaule.date=28;
	      }
	    }
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  
	  Show_Str(116,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  Show_Str(156,89,time1);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  Show_Str(196,89,time1);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  Show_Str(116,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  
	  Show_Str(172,149,time1);
	  
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  LCD_Invert(1);
	  Show_Str(212,149,time1);
	  LCD_Invert(0);
	  
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 7:
	{
	  if(*key==15)
	  {
	    
	    HW_flag=1;
	    Time_flag=0;
	    Clear_LCD(0,0,320,240);
	    PrintGB(112,4,"硬件设置");
	    Fill_Rect(0,25,320,26);
	    return;
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  
	  Show_Str(116,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  Show_Str(156,89,time1);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  Show_Str(196,89,time1);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  Show_Str(116,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  Show_Str(172,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  Show_Str(212,149,time1);
	  LCD_Invert(1);
	  Show_Str(80,200,"取消");
	  LCD_Invert(0);
	  Show_Str(188,200,"确定");
	}break;
      case 8:
	{
	  if(*key==15)
	  {
	    Ds1302_Set_Time(&Time_Set_Vaule);
	    Clear_LCD(0,0,320,240);
	    Draw_Rect(64,80,256,160);
	    Show_Str(100,120,"时间修改成功");
	    Delayms(500);
	    HW_flag=1;
	    Time_flag=0;
	    Clear_LCD(0,0,320,240);
	    PrintGB(112,4,"硬件设置");
	    Fill_Rect(0,25,320,26);
	    return;
	  }
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.hour);
	  
	  Show_Str(116,89,time1);
	  
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.minute);
	  Show_Str(156,89,time1);
	  sprintf((char*)time1,"%02d",Time_Set_Vaule.second);
	  Show_Str(196,89,time1);
	  
	  sprintf((char*)time1,"%04d",(Time_Set_Vaule.year+2000));
	  Show_Str(116,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.month));
	  Show_Str(172,149,time1);
	  sprintf((char*)time1,"%02d",(Time_Set_Vaule.date));
	  Show_Str(212,149,time1);
	  
	  Show_Str(80,200,"取消");
	  LCD_Invert(1);
	  Show_Str(188,200,"确定");
	  LCD_Invert(0);
	}break;
      }
      
    }break;
  case 2:
    {
      if(*key==12)
      {
	if(Uart_Set_Num>1)Uart_Set_Num--;
	else Uart_Set_Num=6;
      }
      else if(*key==16)
      {
	if(Uart_Set_Num<6)Uart_Set_Num++;
	else Uart_Set_Num=1;
      }
      switch(Uart_Set_Num)
      {
      case 1:
	{
	  if(*key==4)
	  {
	    if(uart_cnt>0)uart_cnt--;
	    
	    Uart_Baud_Save=Uart_Baud[uart_cnt];
	  }
	  else if(*key==8)
	  {
	    if(uart_cnt<10)uart_cnt++;
	    
	    Uart_Baud_Save=Uart_Baud[uart_cnt];
	  }
	  sprintf((char*)time1,"%06d",Uart_Baud_Save);
	  LCD_Invert(1);
	  Show_Str(120,50,time1);
	  LCD_Invert(0);
	  sprintf((char*)time1,"%d",Uart_Bits_Save);
	  Show_Str(120,90,time1);
	  sprintf((char*)time1,"%d",Uart_Stop_Save);
	  Show_Str(120,130,time1);
	  switch(Uart_Parity_Save)
	  {
	  case 0:
	    {
	      Show_Str(120,170,"NONE");
	    }break;
	  case 1:
	    {
	      Show_Str(120,170,"ODD ");
	    }break;
	  case 2:
	    {
	      Show_Str(120,170,"EVEN");
	    }break;
	  }
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 2:
	{
	  if(*key==4)
	  {
	    if(isUart_8Bits)
	    {
	      isUart_8Bits=false;
	      Uart_Bits_Save=Uart_Bits[1];
	    }
	  
	  }
	  else if(*key==8)
	  {
	    if(!isUart_8Bits)
	    {
	      isUart_8Bits=false;
	      Uart_Bits_Save=Uart_Bits[0];
	    }
	    
	  }
	  
	  sprintf((char*)time1,"%06d",Uart_Baud_Save);
	  
	  Show_Str(120,50,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Bits_Save);
	  LCD_Invert(1);
	  Show_Str(120,90,time1);
	  LCD_Invert(0);
	  sprintf((char*)time1,"%d",Uart_Stop_Save);
	  Show_Str(120,130,time1);
	  switch(Uart_Parity_Save)
	  {
	  case 0:
	    {
	      Show_Str(120,170,"NONE");
	    }break;
	  case 1:
	    {
	      Show_Str(120,170,"ODD ");
	    }break;
	  case 2:
	    {
	      Show_Str(120,170,"EVEN");
	    }break;
	  }
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 3:
	{
	  if(*key==4)
	  {
	    if(isUart_1Stop)
	    {
	      isUart_1Stop=false;
	      Uart_Stop_Save=Uart_Stop[1];
	    }
	  }
	  else if(*key==8)
	  {
	    if(!isUart_1Stop)
	    {
	      isUart_1Stop=true;
	      Uart_Stop_Save=Uart_Stop[0];
	    }
	   
	  }
	  sprintf((char*)time1,"%06d",Uart_Baud_Save);
	  
	  Show_Str(120,50,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Bits_Save);
	  
	  Show_Str(120,90,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Stop_Save);
	  LCD_Invert(1);
	  Show_Str(120,130,time1);
	  LCD_Invert(0);
	  switch(Uart_Parity_Save)
	  {
	  case 0:
	    {
	      Show_Str(120,170,"NONE");
	    }break;
	  case 1:
	    {
	      Show_Str(120,170,"ODD ");
	    }break;
	  case 2:
	    {
	      Show_Str(120,170,"EVEN");
	    }break;
	  }
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 4:
	{
	  if(*key==4)
	  {
	    if(uart_parity_cnt>0)uart_parity_cnt--;
	    Uart_Parity_Save=uart_parity_cnt;
	  }
	  else if(*key==8)
	  {
	    if(uart_parity_cnt<2)uart_parity_cnt++;
	    Uart_Parity_Save=uart_parity_cnt;
	  }
	  
	  
	  sprintf((char*)time1,"%06d",Uart_Baud_Save);
	  
	  Show_Str(120,50,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Bits_Save);
	  
	  Show_Str(120,90,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Stop_Save);
	  
	  Show_Str(120,130,time1);
	  
	  LCD_Invert(1);
	  switch(Uart_Parity_Save)
	  {
	  case 0:
	    {
	      Show_Str(120,170,"NONE");
	    }break;
	  case 1:
	    {
	      Show_Str(120,170,"ODD ");
	    }break;
	  case 2:
	    {
	      Show_Str(120,170,"EVEN");
	    }break;
	  }
	  LCD_Invert(0);
	  Show_Str(80,200,"取消");
	  Show_Str(188,200,"确定");
	}break;
      case 5:
	{
	  sprintf((char*)time1,"%06d",Uart_Baud_Save);
	  
	  Show_Str(120,50,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Bits_Save);
	  
	  Show_Str(120,90,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Stop_Save);
	  
	  Show_Str(120,130,time1);
	  
	  
	  switch(Uart_Parity_Save)
	  {
	  case 0:
	    {
	      Show_Str(120,170,"NONE");
	    }break;
	  case 1:
	    {
	      Show_Str(120,170,"ODD ");
	    }break;
	  case 2:
	    {
	      Show_Str(120,170,"EVEN");
	    }break;
	  }
	  
	  LCD_Invert(1);
	  Show_Str(80,200,"取消");
	  LCD_Invert(0);
	  Show_Str(188,200,"确定");
	}break;
      case 6:
	{
	  sprintf((char*)time1,"%06d",Uart_Baud_Save);
	  
	  Show_Str(120,50,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Bits_Save);
	  
	  Show_Str(120,90,time1);
	  
	  sprintf((char*)time1,"%d",Uart_Stop_Save);
	  
	  Show_Str(120,130,time1);
	  
	  
	  switch(Uart_Parity_Save)
	  {
	  case 0:
	    {
	      Show_Str(120,170,"NONE");
	    }break;
	  case 1:
	    {
	      Show_Str(120,170,"ODD ");
	    }break;
	  case 2:
	    {
	      Show_Str(120,170,"EVEN");
	    }break;
	  }
	  
	  
	  Show_Str(80,200,"取消");
	  
	  LCD_Invert(1);
	  Show_Str(188,200,"确定");
	  LCD_Invert(0);
	}break;
      }
    }break;
  }
}
void Disp_TimeSetWindow(void)
{
  uint8_t time1[6];
  memcpy(&Time_Set_Vaule,&TimeValue,sizeof(TimeValue));
  Time_Set_Num=1;
  //  sprintf((char*)time1,"%02d : %02d : %02d",TimeValue.hour,TimeValue.minute,TimeValue.second);
  //  sprintf((char*)time2,"%4d - %02d - %02d",(TimeValue.year+2000),TimeValue.month,TimeValue.date);
  Clear_LCD(0,0,320,240);
  Fill_Rect(0,25,320,26);
  Show_Str(108,4,"系统时间设置");
  Show_Str(80,90,"时间");
  Show_Str(80,150,"日期"); 
  sprintf((char*)time1,"%02d",TimeValue.hour);
  LCD_Invert(1);
  Show_Str(116,89,time1);
  LCD_Invert(0);
  Show_Str(140,89,":");
  sprintf((char*)time1,"%02d",TimeValue.minute);
  Show_Str(156,89,time1);
  Show_Str(180,89,":");
  sprintf((char*)time1,"%02d",TimeValue.second);
  Show_Str(196,89,time1);
  
  Draw_Rect(114,87,133,106);
  Draw_Rect(154,87,173,106);
  Draw_Rect(194,87,213,106);
  sprintf((char*)time1,"%04d",(TimeValue.year+2000));
  Show_Str(116,149,time1);
  Show_Str(156,149,"-");
  sprintf((char*)time1,"%02d",(TimeValue.month));
  Show_Str(172,149,time1);
  Show_Str(196,149,"-");
  sprintf((char*)time1,"%02d",(TimeValue.date));
  Show_Str(212,149,time1);
  Draw_Rect(114,147,149,166);
  Draw_Rect(170,147,189,166);
  Draw_Rect(210,147,229,166);
  
  Show_Str(80,200,"取消");
  Draw_Rect(78,198,113,217);  
  Draw_Rect(186,198,221,217);
  Show_Str(188,200,"确定");
  
  
}
void Disp_BaudSetWindow(void)
{
  uint8_t temp[8];
  Clear_LCD(0,0,320,240);
  Fill_Rect(0,25,320,26);
  Show_Str(104,4,"串口设置"); 
  
  sprintf((char*)temp,"%06d",Uart_Baud_Save);
  Show_Str(60,50,"波特率");
  LCD_Invert(1);
  Show_Str(120,50,temp);
  LCD_Invert(0);
  Draw_Rect(118,48,169,67);
  sprintf((char*)temp,"%d",Uart_Bits_Save);
  Show_Str(60,90,"数据位");
  Show_Str(120,90,temp);
  Draw_Rect(118,88,129,107);
  sprintf((char*)temp,"%d",Uart_Stop_Save);
  Show_Str(60,130,"停止位");
  Show_Str(120,130,temp);
  Draw_Rect(118,128,129,147);
  
  switch(Uart_Parity_Save)
  {
  case 0:
    {
      Show_Str(120,170,"NONE");
    }break;
  case 1:
    {
      Show_Str(120,170,"ODD ");
    }break;
  case 2:
    {
      Show_Str(120,170,"EVEN");
    }
  }
  Show_Str(72,170,"校验");
  
  Draw_Rect(118,168,153,187);
  
  
  
  
  Show_Str(80,200,"取消");
  Draw_Rect(78,198,113,217);  
  Draw_Rect(186,198,221,217);
  Show_Str(188,200,"确定");
}