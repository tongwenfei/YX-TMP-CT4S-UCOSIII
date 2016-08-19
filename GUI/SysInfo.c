#include "SysInfo.h"
const unsigned char Instrument_ID[]={"�����ͺţ�YX-TMP-CT4S"};
const unsigned char SW_Version[]={"����汾��V1.0.0"};
const unsigned char HW_Version[]={"Ӳ���汾��V1.0.0"};
const unsigned char Channel_N[]={"ͨ��������4ͨ��"};
const unsigned char Flow_Range[]={"������Χ����0-1000��ml/min"};
const unsigned char Storage[]={"�洢������64K"};
void Disp_Sys_Info(void)
{ 
  Clear_LCD(0,0,320,240);
  PrintGB(112,4,"ϵͳ��Ϣ");
    Fill_Rect(0,25,320,26);
  Show_Str(32,35,(u8*)Instrument_ID);
  
  Show_Str(32,60,(u8*)Channel_N);
  
  Show_Str(32,85,(u8*)Flow_Range);
  
  Show_Str(32,110,(u8*)Storage);
 
  Show_Str(32,135,(u8*)HW_Version);
  
  Show_Str(32,160,(u8*)SW_Version);
  Show_Str(32,185,"���ǿƼ���չ(����)���޹�˾");
  SetFontFgColor(BLACK);   
  SetFontBgColor(BLUE);
  Show_Str(260,210,"����");
  SetFontFgColor(BLUE);   
  SetFontBgColor(BLACK);
}
void Sys_Exit(void)
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
    Info_flag=0;
    state_disp=1;
    Main_flag=1;
    Disp_MainWindow();
    return;
  }
}