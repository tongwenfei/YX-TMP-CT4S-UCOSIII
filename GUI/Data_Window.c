#include "Data_Window.h"
#include "Data_image.h"
void Disp_Data(void)
{
  Clear_LCD(0,0,320,240);
  PrintGB(112,4,"���ݲ�ѯ");
    Fill_Rect(0,25,320,26);
  Show_Str(16,30,"�������");
  Show_Str(220,30,"ҳ��23/133");
  Draw_Rect(82,28,186,46);
  Show_Str(88,30,"160323170547");
  Draw_Rect(16,50,304,210);
  Draw_Line(276,50,276,210);
  Draw_Line(34,50,34,210);
  Draw_Line(16,70,276,70);
  Draw_Line(16,90,276,90);
  Draw_Line(16,110,276,110);
  Draw_Line(16,130,276,130);
  Draw_Line(16,150,276,150);
  Draw_Line(16,170,276,170);
  Draw_Line(16,190,276,190);
  Draw_Line(140,50,140,210);
  Draw_Line(158,50,158,210);
  Show_Str(72,220,"��һҳ");
  Show_Str(140,220,"��һҳ");
  Show_Str(240,220,"����");
  Draw_Rect(280,68,300,192);
  Fill_Rect(282,95,298,98);
  Draw_Pic(280,54,300,68,(u8*)gImage_triangle_up,length(gImage_triangle_up)) ;
  Draw_Pic(280,192,300,206,(u8*)gImage_triangle_down,length(gImage_triangle_down)) ;
}
void Data_Select(void)
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
    
   
    Data_Flag=0;
    state_disp=1;
    Main_flag=1;
    Disp_MainWindow();
    return;
  }
}
void Disp_DetailWindow(void)
{
  Clear_LCD(0,0,320,240);
  Show_Str(76,4,"���:");
  Draw_Rect(115,2,221,22);
  Show_Str(120,4,"160323170547");
  Fill_Rect(0,24,320,26);
  Draw_Rect(2,30,318,216);
  Draw_Line(2,50,318,50); 
  Draw_Line(2,70,318,70);
  Draw_Line(2,90,318,90);
  Draw_Line(2,110,318,110);
  Draw_Line(2,130,318,130);
  Draw_Line(2,150,318,150);
  Draw_Line(2,170,318,170);
  Draw_Line(2,190,318,190);
  
  Draw_Line(68,30,68,216);
  Draw_Line(162,30,162,216);
  Draw_Line(228,30,228,216);
  
  
  Show_Str(48,220,"��һ��");
  Draw_Rect(46,218,96,236);
  Show_Str(148,220,"��һ��");
  Draw_Rect(146,218,196,236);
  Show_Str(252,220,"����");
  Draw_Rect(250,218,284,236);
  
  Show_Str(4,32,"ʵʱ����");
  Show_Str(4,52,"Ԥ������");
  Show_Str(4,72,"ʵʱ�¶�");
  Show_Str(4,92,"Ԥ���¶�");
  Show_Str(4,112,"�ۼ�ʵ��");
  Show_Str(4,132,"�ۼƱ���");
  Show_Str(4,152,"Ԥ�����");
  Show_Str(4,172,"����ģʽ");
  Show_Str(4,195,"����ʱ��");
  
  Show_Str(164,32,"������ѹ");
  Show_Str(164,52,"�����¶�");
  Show_Str(164,72,"��������");
  Show_Str(164,92,"����ʱ��");
  Show_Str(164,112,"Ԥ��ʱ��");
  Show_Str(164,132,"����״̬");
  Show_Str(164,152,"����״̬");
  Show_Str(164,172,"������ʽ");
  //Show_Str(164,195,"����ʱ��");  
  Disp_DetailSubWindow();
}
void Disp_DetailSubWindow(void)
{
 
  uint8_t temp[15],pres[15],time1[10],time2[12],PT1[16],PT2[16];     //�������¶Ⱥ���ѹ���ݣ����ӵ��ⲿ������ʱ����Ϊ�ⲿʵʱ����
  

  sprintf((char*)temp,"  %.1f��",Ambience_Temp);
  sprintf((char*)pres,"%.2fkPa",MS5611_Press);
   sprintf((char*)PT1,"  %.2f��",PT100_Temp[0]);
  sprintf((char*)PT2,"  %.2f��",PT100_Temp[1]);
  sprintf((char*)time1,"%02d:%02d:%02d",TimeValue.hour,TimeValue.minute,TimeValue.second);
  sprintf((char*)time2,"%4d-%02d-%02d",(TimeValue.year+2000),TimeValue.month,TimeValue.date);
   Show_Str(80,32,"0ml/min");
   Show_Str(80,52,"80ml/min");
   Show_Str(80,72,PT1);
   Show_Str(80,92,PT2);
   Show_Str(80,112,"190ml");
   Show_Str(80,132,"187ml");
   Show_Str(80,152,"1000ml");
   Show_Str(80,172,"���ݻ�");

   

   PrintASCII(88,192,time1);
   PrintASCII(80,204,time2);
   Show_Str(240,32,pres);
   Show_Str(240,52,temp);
   Show_Str(240,72,"19%");
   Show_Str(240,92,"00H02M23S");
   Show_Str(240,112,"--------");
   Show_Str(240,132,"��ͣ��");
   Show_Str(240,152,"--------");
   Show_Str(240,172,"�ֶ�");
   
}
void Disp_DetailSubTime(void)
{
  uint8_t temp[15],pres[15],time1[10],time2[12],PT1[16],PT2[16];     //�������¶Ⱥ���ѹ���ݣ����ӵ��ⲿ������ʱ����Ϊ�ⲿʵʱ����
  sprintf((char*)temp,"  %.1f��",Ambience_Temp);
  sprintf((char*)PT1,"  %.2f��",PT100_Temp[0]);
  sprintf((char*)PT2,"  %.2f��",PT100_Temp[1]);
  sprintf((char*)pres,"%.2fkPa",MS5611_Press);
  sprintf((char*)time1,"%02d:%02d:%02d",TimeValue.hour,TimeValue.minute,TimeValue.second);
  sprintf((char*)time2,"%4d-%02d-%02d",(TimeValue.year+2000),TimeValue.month,TimeValue.date);
   PrintASCII(88,192,time1);
   PrintASCII(80,204,time2);
   Show_Str(240,32,pres);
   Show_Str(240,52,temp);
   Show_Str(80,72,PT1);
   Show_Str(80,92,PT2);
}