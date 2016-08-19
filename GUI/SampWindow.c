#include "SampWindow.h"
#include "CH_SetWindow.h"
#include "CH_image.h"
uint8_t samp_subselet=1,lastsamp_subselet=3,CH_subselet=1,lastCH_subselet=3;
bool start=true;

uint16_t pwm_test=550;

void Disp_SampWindow(void)
{
  uint8_t temp_buf[8];
  samp_subselet=1;
  Uart_flag=0;
  lastsamp_subselet=3;
  //sprintf((char*)temp_buf,"%.1f",PT100_Temp[0]);
  Clear_LCD(0,27,320,240);
  Draw_Line(30,27,30,240);
  Draw_Line(290,27,290,240);
  switch(CH_subselet)
  {
  case 1:
    {
    	sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[0].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	  sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[0].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[0])
	{
	   PrintGB(120,95,"Ԥ�������");
	    sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[0]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
	   sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[0]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);
  	
  	PrintGB_NUM(240,95,"min");
	}
    }break;
     case 2:
    {
      sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[1].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	   sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[1].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[1])
	{
	   PrintGB(120,95,"Ԥ�������");
  	  sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[1]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
  	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[1]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"min");
	}
    }break;
     case 3:
    {
      sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[2].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	   sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[2].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[2])
	{
	   PrintGB(120,95,"Ԥ�������");
  	  sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[2]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
  	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[2]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"min");
	}
    }break;
     case 4:
    {
      sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[3].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	   sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[3].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[3])
	{
	   PrintGB(120,95,"Ԥ�������");
  	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[3]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[3]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);PrintGB_NUM(196,95,"1000");
  	PrintGB_NUM(240,95,"min");
	}
    }break;
  }
  PrintGB_ROW(8,35,"��������");
  
  if(start) PrintGB(52,213,"�ɼ�״̬��������");
  else  PrintGB(52,213,"�ɼ�״̬����ͣ��");
  PrintGB_NUM(8,99,"..");
  
  Show_Str(4,114,"19%");
  Draw_Rect(5,135,25,235);
  Fill_Rect(5,216,25,235);
  LCD_Invert(1);    
  if(start)
  {
    PrintGB_ROW(300,33,"��ͣ");
    
  }
  else 
  {
    PrintGB_ROW(300,33,"����");
    
  }
  LCD_Invert(0); 
  Draw_Rect(298,31,317,66);
  PrintGB_ROW(300,75,"����");
  Draw_Rect(298,73,317,108);
  PrintGB_ROW(300,117,"��¼");
  Draw_Rect(298,115,317,150);
  PrintGB_ROW(300,159,"����");
  Draw_Rect(298,157,317,192);
  PrintGB_ROW(300,201,"����");
  Draw_Rect(298,199,317,234);
  Draw_Pic(35,35,115,115,(u8*)gImage_CH1,length(gImage_CH1));
  Draw_Circle(75,75,40);
  
  PrintGB(120,35,"Ԥ���ٶȣ�");  
  //PrintGB_NUM(196,35,"81");
  PrintGB_NUM(232,35,"ml/min");
  //Draw_Pic(155,35,175,55,(u8*)gImage_triangle_lf,length(gImage_triangle_lf));
  //Draw_Pic(268,35,288,55,(u8*)gImage_triangle_rf,length(gImage_triangle_rf));
  
  PrintGB(120,65,"Ԥ���¶ȣ�");
  sprintf((char*)temp_buf,"%.1f",TempPID_struct.SetPoint);
  Clear_LCD(196,65,228,81);
  PrintGB_NUM(196,65,temp_buf);
  PrintGB(236,65,"��");
  //Draw_Pic(155,65,175,85,(u8*)gImage_triangle_lf,length(gImage_triangle_lf));
  //Draw_Pic(268,65,288,85,(u8*)gImage_triangle_rf,length(gImage_triangle_rf));
  

  //Draw_Pic(155,95,175,115,(u8*)gImage_triangle_lf,length(gImage_triangle_lf));
  //Draw_Pic(268,95,288,115,(u8*)gImage_triangle_re,length(gImage_triangle_re));
  
  PrintGB(52,125,"ʵʱ�¶ȣ�");
  //  PrintGB_NUM(132,125,temp_buf);
  PrintGB(180,125,"��");
  
  
  PrintGB(52,147,"ʵʱ�ٶȣ�");
  
  PrintGB(52,169,"�ɼ�ʱ�䣺");
  //Show_Str(132,169,"00ʱ02��23��"); 
  
  PrintGB(52,191,"�ۼ������");
  PrintGB_NUM(132,191,"190 ml");
  
}
extern float curr_data;
void Samp_Select(void)
{
  uint8_t temp_buf[15]={0};
  uint8_t *key;
  OS_MSG_SIZE size;
  OS_ERR err;
  key=OSQPend((OS_Q*			)&KEY_Msg,   
	      (OS_TICK			)0,
	      (OS_OPT			)OS_OPT_PEND_NON_BLOCKING,
	      (OS_MSG_SIZE*		)&size,		
	      (CPU_TS*			)0,
	      (OS_ERR*			)&err);
  uint32_t Definite_Sec=Definite_Count[0]/10;
  if(Uart_flag<7)Uart_flag++;
  else Uart_flag=0;
  sprintf((char*)temp_buf,"%.1f",PT100_Temp[0]);
  //Clear_LCD(132,125,164,141);
  PrintGB_NUM(132,125,temp_buf);
 switch(CH_subselet)
  {
  case 1:
    {
    	sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[0].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	  sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[0].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[0])
	{
	   PrintGB(120,95,"Ԥ�������");
	    sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[0]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
	   sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[0]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);
  	
  	PrintGB_NUM(240,95,"min");
	}
    }break;
     case 2:
    {
      sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[1].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	   sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[1].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[1])
	{
	   PrintGB(120,95,"Ԥ�������");
  	  sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[1]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
  	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[1]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"min");
	}
    }break;
     case 3:
    {
      sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[2].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	   sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[2].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[2])
	{
	   PrintGB(120,95,"Ԥ�������");
  	  sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[2]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
  	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[2]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"min");
	}
    }break;
     case 4:
    {
      sprintf((char*)temp_buf,"%04d",(uint16_t)FlowPID_struct[3].Flow_Value);//ʵʱ�ٶ�
 	 PrintGB_NUM(132,147,temp_buf);
	   sprintf((char*)temp_buf,"%04d",(uint16_t)(FlowPID_struct[3].SetPoint*1000));//Ԥ���ٶ�
  	//Clear_LCD(196,35,228,51);
  	PrintGB_NUM(196,35,temp_buf);
	if(Sampling_Mode.isFixed_Volume[3])
	{
	   PrintGB(120,95,"Ԥ�������");
  	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Flow_Volume[3]));//Ԥ�����
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"ml ");
	}
	else
	{
	   PrintGB(120,95,"��ʱʱ�䣺");
	sprintf((char*)temp_buf,"%05d",(uint16_t)(Sampling_Mode.Definite_Time[3]));//��ʱʱ��
  	PrintGB_NUM(196,95,temp_buf);
  	PrintGB_NUM(240,95,"min");
	}
    }break;
  }
  sprintf((char*)temp_buf,"%.1f",TempPID_struct.SetPoint);
  //Clear_LCD(196,65,228,81);
  PrintGB_NUM(196,65,temp_buf);
  sprintf((char*)temp_buf,"%04d",(uint16_t)(300+200*FlowPID_struct[0].Clac_Value));
  PrintGB_NUM(240,213,temp_buf);
  sprintf((char*)temp_buf,"%.2f",curr_data);
  PrintGB_NUM(240,190,temp_buf);
  sprintf((char*)temp_buf,"%.4f",FlowPID_struct[0].Value);
  PrintGB_NUM(240,170,temp_buf);
  sprintf((char*)temp_buf,"%02dʱ%02d��%02d��",Definite_Sec/3600,(Definite_Sec/60)%60,Definite_Sec%60);
  Show_Str(132,169,temp_buf);
  //memset(temp_buf,0,15);
  if(*key==1)
  {
    CH_subselet=1;
  }
  else if(*key==2)
  {
    CH_subselet=2;
  }
  else if(*key==3)
  {
    CH_subselet=3;
  }
  else if(*key==5)
  {
    CH_subselet=4;
  }
  else if(*key==4)
  {
    if(samp_subselet>1)samp_subselet--;
    else samp_subselet=5;
  }
  else if(*key==8)
  {
    if(samp_subselet<5)samp_subselet++;
    else samp_subselet=1;
  }
  else if(*key==12)
  {
    if(CH_subselet>1)CH_subselet--;
    else CH_subselet=4;
    
    if(pwm_test>250)pwm_test-=2;
    //TIM_SetCompare4(TIM3,pwm_test);
  }
  else if(*key==16)
  {
    if(CH_subselet<4)CH_subselet++;
    else CH_subselet=1;
    
    if(pwm_test<1000)pwm_test+=2;
    //TIM_SetCompare4(TIM3,pwm_test);
  }
  
  else if(*key==13)
  {
    
    Exit_flag=0;
    state_disp=1;
    Main_flag=1;
    Disp_MainWindow();
    return;
  }
  if(Uart_flag>1)
  {
    if(*key==15)
    {
      switch(samp_subselet)
      {
      case 1:
	{
	  start=(start?false:true);
	  LCD_Invert(1); 
	  if(start)PrintGB_ROW(300,33,"��ͣ");
	  else PrintGB_ROW(300,33,"����");
	  LCD_Invert(0); 
	  if(start) 
	  {
	    TIM6_Start();
	      PrintGB(52,213,"�ɼ�״̬��������");
	  }
	  else  
	  {
	    TIM6_Pause();
	    PrintGB(52,213,"�ɼ�״̬����ͣ��");
	  }
	}break;
      case 2:
	{
	  Exit_flag=0;
	  Channel_flag=1;
	  Main_flag=0;
	  state_disp=0;
	  Disp_SetWindow();
	  return;
	}break;
      case 3:
	{
	  Exit_flag=0;
	  Data_Flag=1;
	  Main_flag=0;
	  state_disp=0;
	  Disp_Data();
	  return;
	}break;
      case 4:
	{
	  Exit_flag=0;
	  Help_flag=1;
	  state_disp=0;
	  Disp_HelpWindows();
	  return;
	}break;
      case 5:
	{
	  Exit_flag=0;
	  state_disp=1;
	  Main_flag=1;
	  Disp_MainWindow();
	  return;
	}break;
      }
    }
  }
  if(lastsamp_subselet!=samp_subselet)
  {
    switch(samp_subselet)
    {
    case 1:
      {
	LCD_Invert(1); 
	if(start)PrintGB_ROW(300,33,"��ͣ");
	else PrintGB_ROW(300,33,"����");
	LCD_Invert(0); 
	PrintGB_ROW(300,75,"����");
	PrintGB_ROW(300,117,"��¼");
	PrintGB_ROW(300,159,"����");
	PrintGB_ROW(300,201,"����");
      }break;
    case 2:
      {
	if(start)PrintGB_ROW(300,33,"��ͣ");
	else PrintGB_ROW(300,33,"����");
	LCD_Invert(1); 
	PrintGB_ROW(300,75,"����");
	LCD_Invert(0);
	PrintGB_ROW(300,117,"��¼");
	PrintGB_ROW(300,159,"����");
	PrintGB_ROW(300,201,"����");
      }break;
    case 3:
      {
	if(start)PrintGB_ROW(300,33,"��ͣ");
	else PrintGB_ROW(300,33,"����");
	PrintGB_ROW(300,75,"����");
	LCD_Invert(1);
	PrintGB_ROW(300,117,"��¼");
	LCD_Invert(0);
	PrintGB_ROW(300,159,"����");
	PrintGB_ROW(300,201,"����");
      }break;
    case 4:
      {
	if(start)PrintGB_ROW(300,33,"��ͣ");
	else PrintGB_ROW(300,33,"����");
	PrintGB_ROW(300,75,"����");
	PrintGB_ROW(300,117,"��¼");
	LCD_Invert(1);    
	PrintGB_ROW(300,159,"����");
	LCD_Invert(0);
	PrintGB_ROW(300,201,"����");
      }break;
    case 5:
      {
	if(start)PrintGB_ROW(300,33,"��ͣ");
	else PrintGB_ROW(300,33,"����");
	PrintGB_ROW(300,75,"����");
	PrintGB_ROW(300,117,"��¼");
	PrintGB_ROW(300,159,"����");
	LCD_Invert(1);  
	PrintGB_ROW(300,201,"����");
	LCD_Invert(0);
      }break;
      
    }
  }
  if(lastCH_subselet!=CH_subselet)
  {
    switch(CH_subselet)
    {
    case 1:
      {
	Clear_LCD(52,60,100,90);
	Draw_Pic(35,35,115,115,(u8*)gImage_CH1,length(gImage_CH1));
      }break;
    case 2:
      {
	Clear_LCD(52,60,100,90);
	Draw_Pic(35,35,115,115,(u8*)gImage_CH2,length(gImage_CH2));
      }break;
    case 3:
      {
	Clear_LCD(52,60,100,90);
	Draw_Pic(35,35,115,115,(u8*)gImage_CH3,length(gImage_CH3));
      }break;
    case 4:
      {
	Clear_LCD(52,60,100,90);
	Draw_Pic(35,35,115,115,(u8*)gImage_CH4,length(gImage_CH4));
      }break;
    }
  }
  lastsamp_subselet=samp_subselet;
  lastCH_subselet=CH_subselet;
  
}
void Disp_HelpWindows(void)
{
  
  Clear_LCD(0,0,320,240);
  PrintGB(144,4,"����");
  Fill_Rect(0,25,320,26);
  Show_Str(0,35,"1.������ʾ�˵��£����ϡ��͡��¡���ѡ���");
  Show_Str(16,51,"Ӧѡ���ȷ��������");
  Show_Str(0,86,"2.���������а��¡���ͣ��������ͣ��������");
  Show_Str(16,102,"ͣ״̬�°��¡�������������ʼ����");
  Show_Str(0,137,"3.������ʾ�˵��£����󡱺͡��ҡ����л�ͨ");
  Show_Str(16,153,"������ʾ������Ϣ");
  Show_Str(0,188,"4.������ʾ�˵��£��������֡�1-4��������");
  Show_Str(16,204,"�л�����Ӧͨ��������ʾ������Ϣ");
  
}
void Exit_HelpWindows(void)
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
    Exit_flag=1;
    Help_flag=0;
    Main_flag=0;
    state_disp=1;
    Disp_SampWindow();
    return;
  }
}