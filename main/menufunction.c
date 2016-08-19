/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			mainmenu.c
 *Description��     	       ���������
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/******************************** ���� ��������********************************/

/*
********************************************************************************
�������ƣ�void Display_Batter(uint8_t flag)
�������ܣ������ʾ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_Batter(uint8_t flag)
{
    if(Batter_flag == 1)
    {
         //�ж��Ƿ��е�Դ�������ǳ�绹�ǵ�ع���
         if(flag == 1)
         {
            //�յ���
            if(Batter_add_flag0 == 1)    
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("5",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ0
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("6",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ1
                }
                else if(Batter_add == 3)
                {
                    LCD_Picture("7",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ2
                }
                else if(Batter_add == 4)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ3 
                }
                else if(Batter_add == 5)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ4
                }
            }
            //��һ�����������ڶ�����
            else if(Batter_add_flag1 == 1)
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("6",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ1
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("7",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ2
                }
                else if(Batter_add == 3)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ3
                }
                else if(Batter_add == 4)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ4 
                }
            }
            //�ж�������������������
            else if(Batter_add_flag2 == 1)
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("7",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ2
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ3
                }
                else if(Batter_add == 3)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ4
                }
            }
            //�����������������ĵ���
            else if(Batter_add_flag3 == 1)
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ3
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ4
                }
            }
            //Ϊ�������
            else if(Batter_add_flag4 == 1)
            {
                LCD_Picture("9",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ4
            } 
         }
         else
         {
            if((g_Power.pc0_adc10_battery > 12))                  //ÿһ�����Ϊ0.6v
            {
                LCD_Picture("9",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ4  
            }
            else if((g_Power.pc0_adc10_battery > 11.8) && (g_Power.pc0_adc10_battery <= 12))
            {
                LCD_Picture("8",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ3
            }
            else if((g_Power.pc0_adc10_battery > 11.2) && (g_Power.pc0_adc10_battery <= 11.8))
            {                                     
                LCD_Picture("7",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ2
            }
            //��������
            else if((g_Power.pc0_adc10_battery > 10.6) && (g_Power.pc0_adc10_battery <= 11.2))
            {
                LCD_Picture("6",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ1
            }
            else if((g_Power.pc0_adc10_battery <= 10.6))
            {
                LCD_Picture("5",109,0,16,16,NORMAL);              //��ʾ��ص���Ϊ0
            }
         }
    }
    else
    {
        LCD_Picture("0",109,0,16,16,NORMAL);                      //��������ʾ
    }
}  

/*
********************************************************************************
�������ƣ�void Display_Power(uint8_t flag)
�������ܣ���Դ��ʾ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_Power(uint8_t flag)
{
    //���޵�Դ����
    if(flag == 1)
    {
        LCD_ASCII("^",100,0,7,16,MOVEUP);           //��ʾ��ͷͼƬ
    }
    else
    {
        LCD_ASCII("_",100,0,7,16,MOVEUP);           //����ʾ��ͷͼƬ
    }
}
  

/******************************* ������ ��������*******************************/

/*
********************************************************************************
�������ƣ�void Display_MainMenu(void)
�������ܣ����˵���ʾ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_MainMenu(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
        LCD_String("���˵�",45,0,13,16,MOVEUP);         //��ʾ���˵��ַ�
        LCD_Picture("1",9,2,16,16,NORMAL);              //��ʾ����ͼƬ
        LCD_Picture("2",76,2,16,16,NORMAL);             //��ʾ����ͼƬ
        LCD_Picture("3",9,4,16,16,NORMAL);              //��ʾ��ѯͼƬ 
        LCD_Picture("4",76,4,16,16,NORMAL);             //��ʾά��ͼƬ
        
        LCD_HoriStraightLine(6,1,2);                    //��ʾ�ڶ��зָ���
        
        flag1 = 1;
    }
    if(g_UserChoose == 0)
    {
        //ʵ�����÷��ԣ��������� 
        LCD_String("����",27,2,13,16,INVERSER);     //��ʾ���÷����ַ�
        LCD_String("����",94,2,13,16,NORMAL);       //��ʾ�����ַ�
        LCD_String("��ѯ",27,4,13,16,NORMAL);       //��ʾ��ѯ�ַ�
        LCD_String("ά��",94,4,13,16,NORMAL);       //��ʾά���ַ�
    }
    else if(g_UserChoose == 1)
    { 
        LCD_String("����",27,2,13,16,NORMAL);       //��ʾ�����ַ�
        LCD_String("����",94,2,13,16,INVERSER);     //��ʾ���������ַ�
        LCD_String("��ѯ",27,4,13,16,NORMAL);       //��ʾ��ѯ�ַ�
        LCD_String("ά��",94,4,13,16,NORMAL);       //��ʾά���ַ�
    }
    else if(g_UserChoose == 2)
    {  
        LCD_String("����",27,2,13,16,NORMAL);       //��ʾ�����ַ�
        LCD_String("����",94,2,13,16,NORMAL);       //��ʾ�����ַ�
        LCD_String("��ѯ",27,4,13,16,INVERSER);     //��ʾ��ѯ�����ַ�
        LCD_String("ά��",94,4,13,16,NORMAL);       //��ʾά���ַ�
    }
    else if(g_UserChoose == 3)
    {      
        LCD_String("����",27,2,13,16,NORMAL);       //��ʾ�����ַ�
        LCD_String("����",94,2,13,16,NORMAL);       //��ʾ�����ַ�
        LCD_String("��ѯ",27,4,13,16,NORMAL);       //��ʾ��ѯ�ַ�
        LCD_String("ά��",94,4,13,16,INVERSER);     //��ʾά�������ַ�
    }
    Display_TimeValue();
}

/*
********************************************************************************
�������ƣ�void Display_TimeValue(void)
�������ܣ���ʾʱ��ֵ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_TimeValue(void)
{
    char str[10]={10};  
     //��
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.year);
    LCD_ASCII((uint8_t*)str,4,6,7,16,MOVEDOWN);
    //��
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.month);
    LCD_ASCII((uint8_t*)str,25,6,7,16,MOVEDOWN);
    //��
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.day);
    LCD_ASCII((uint8_t*)str,46,6,7,16,MOVEDOWN);
    
    //ʱ
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
    LCD_ASCII((uint8_t*)str,67,6,7,16,MOVEDOWN);
    //��
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
    LCD_ASCII((uint8_t*)str,88,6,7,16,MOVEDOWN);
     //��
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
    LCD_ASCII((uint8_t*)str,109,6,7,16,MOVEDOWN);
}

/****************************** ���ý��� ��������******************************/

/*
********************************************************************************
�������ƣ�void Display_SetMenu1(void)
�������ܣ����ò˵�1��ʾ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_SetMenu1(void)
{
    if(g_UserChoose < 3)
    {
        //��ֹ����ˢ�ظ��Ľ���
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("����",50,0,13,16,MOVEUP);           //��ʾ�����ַ�
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�
            LCD_String("ʱ������",37,2,13,16,NORMAL);       //��ʾʱ�������ַ�
            LCD_String("ͨѶ����",37,4,13,16,NORMAL);       //��ʾͨѶ�����ַ�
            LCD_String("��������",37,6,13,16,NORMAL);       //��ʾ���������ַ�
            flag1 = 1;
            flag2 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("����",50,0,13,16,MOVEUP);           //��ʾ�����ַ�
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            LCD_String("�ָ���������",37,2,13,16,NORMAL);   //��ʾ�ָ����������ַ� 
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/**************** ���ý���1�Ӳ˵�����  ����ʱ��*******************/

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetTime(void)
�������ܣ����ò˵�1�Ӳ˵� ����ʱ��
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetTime(void)
{
    char str[10]={0};
    
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
        LCD_String("ʱ������",38,0,13,16,MOVEUP);       //��ʾʱ�������ַ�
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //��ʾ1/1�����ַ�
        LCD_String("����",30,2,13,16,NORMAL);           //��ʾ�����ַ�     
        LCD_String("ʱ��",30,4,13,16,NORMAL);           //��ʾʱ���ַ�
        
        flag1 = 1;
    }
    
    //��
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.year);
    LCD_ASCII((uint8_t*)str,60,2,7,16,NORMAL);
    //��
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.month);
    LCD_ASCII((uint8_t*)str,81,2,7,16,NORMAL);
    //��
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.day);
    LCD_ASCII((uint8_t*)str,102,2,7,16,NORMAL);
    
    //ʱ
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
    LCD_ASCII((uint8_t*)str,60,4,7,16,NORMAL);
    //��
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
    LCD_ASCII((uint8_t*)str,81,4,7,16,NORMAL);
     //��
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
    LCD_ASCII((uint8_t*)str,102,4,7,16,NORMAL);
    
    LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//�����һ������
        s_olderchoose = g_UserChoose;     
    }      
}

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetTime_YMD(void)
�������ܣ�ʵ��������ʱ������
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetTime_YMD(void)
{
    SYSTEM_RTC rtc_oldtime;
    rtc_oldtime = g_RTCTime;                                   //����ʱ��һ��
    int8_t year_ten = rtc_oldtime.year / 10;                    //������ʮλ����
    int8_t year_one = rtc_oldtime.year % 10;                    //�����ĸ�λ����
    int8_t month_ten = rtc_oldtime.month / 10;                   //����µ�ʮλ����
    int8_t month_one = rtc_oldtime.month % 10;                   //����µĸ�λ����
    int8_t day_ten = rtc_oldtime.day / 10;                     //����յ�ʮλ����
    int8_t day_one = rtc_oldtime.day % 10;                     //����յĸ�λ����
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    if(year_ten == 0)          {LCD_ASCII("0",60,2,7,16,INVERSER);}
    else if(year_ten == 1)     {LCD_ASCII("1",60,2,7,16,INVERSER);}
    else if(year_ten == 2)     {LCD_ASCII("2",60,2,7,16,INVERSER);}
    else if(year_ten == 3)     {LCD_ASCII("3",60,2,7,16,INVERSER);}
    else if(year_ten == 4)     {LCD_ASCII("4",60,2,7,16,INVERSER);}
    else if(year_ten == 5)     {LCD_ASCII("5",60,2,7,16,INVERSER);}
    else if(year_ten == 6)     {LCD_ASCII("6",60,2,7,16,INVERSER);}
    else if(year_ten == 7)     {LCD_ASCII("7",60,2,7,16,INVERSER);}
    else if(year_ten == 8)     {LCD_ASCII("8",60,2,7,16,INVERSER);}
    else if(year_ten == 9)     {LCD_ASCII("9",60,2,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    year_ten++;
                    if(year_ten == 10)
                    {
                        year_ten = 0;
                    }
                    if(year_ten == 0)          {LCD_ASCII("0",60,2,7,16,INVERSER);}
                    else if(year_ten == 1)     {LCD_ASCII("1",60,2,7,16,INVERSER);}
                    else if(year_ten == 2)     {LCD_ASCII("2",60,2,7,16,INVERSER);}
                    else if(year_ten == 3)     {LCD_ASCII("3",60,2,7,16,INVERSER);}
                    else if(year_ten == 4)     {LCD_ASCII("4",60,2,7,16,INVERSER);}
                    else if(year_ten == 5)     {LCD_ASCII("5",60,2,7,16,INVERSER);}
                    else if(year_ten == 6)     {LCD_ASCII("6",60,2,7,16,INVERSER);}
                    else if(year_ten == 7)     {LCD_ASCII("7",60,2,7,16,INVERSER);}
                    else if(year_ten == 8)     {LCD_ASCII("8",60,2,7,16,INVERSER);}
                    else if(year_ten == 9)     {LCD_ASCII("9",60,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    year_one++;
                    if(year_one == 10)
                    {
                        year_one = 0;
                    }
                    if(year_one == 0)          {LCD_ASCII("0",67,2,7,16,INVERSER);}
                    else if(year_one == 1)     {LCD_ASCII("1",67,2,7,16,INVERSER);}
                    else if(year_one == 2)     {LCD_ASCII("2",67,2,7,16,INVERSER);}
                    else if(year_one == 3)     {LCD_ASCII("3",67,2,7,16,INVERSER);}
                    else if(year_one == 4)     {LCD_ASCII("4",67,2,7,16,INVERSER);}
                    else if(year_one == 5)     {LCD_ASCII("5",67,2,7,16,INVERSER);}
                    else if(year_one == 6)     {LCD_ASCII("6",67,2,7,16,INVERSER);}
                    else if(year_one == 7)     {LCD_ASCII("7",67,2,7,16,INVERSER);}
                    else if(year_one == 8)     {LCD_ASCII("8",67,2,7,16,INVERSER);}
                    else if(year_one == 9)     {LCD_ASCII("9",67,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    month_ten++;
                    if(month_ten == 2)
                    {
                        month_ten = 0;
                    }
                    if(month_ten == 0)          {LCD_ASCII("0",81,2,7,16,INVERSER);}
                    else if(month_ten == 1)     {LCD_ASCII("1",81,2,7,16,INVERSER);}
                    else if(month_ten == 2)     {LCD_ASCII("2",81,2,7,16,INVERSER);}
                    else if(month_ten == 3)     {LCD_ASCII("3",81,2,7,16,INVERSER);}
                    else if(month_ten == 4)     {LCD_ASCII("4",81,2,7,16,INVERSER);}
                    else if(month_ten == 5)     {LCD_ASCII("5",81,2,7,16,INVERSER);}
                    else if(month_ten == 6)     {LCD_ASCII("6",81,2,7,16,INVERSER);}
                    else if(month_ten == 7)     {LCD_ASCII("7",81,2,7,16,INVERSER);}
                    else if(month_ten == 8)     {LCD_ASCII("8",81,2,7,16,INVERSER);}
                    else if(month_ten == 9)     {LCD_ASCII("9",81,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    month_one++;
                    if(month_one == 10)
                    {
                        month_one = 0;
                    }
                    if(month_one == 0)          {LCD_ASCII("0",88,2,7,16,INVERSER);}
                    else if(month_one == 1)     {LCD_ASCII("1",88,2,7,16,INVERSER);}
                    else if(month_one == 2)     {LCD_ASCII("2",88,2,7,16,INVERSER);}
                    else if(month_one == 3)     {LCD_ASCII("3",88,2,7,16,INVERSER);}
                    else if(month_one == 4)     {LCD_ASCII("4",88,2,7,16,INVERSER);}
                    else if(month_one == 5)     {LCD_ASCII("5",88,2,7,16,INVERSER);}
                    else if(month_one == 6)     {LCD_ASCII("6",88,2,7,16,INVERSER);}
                    else if(month_one == 7)     {LCD_ASCII("7",88,2,7,16,INVERSER);}
                    else if(month_one == 8)     {LCD_ASCII("8",88,2,7,16,INVERSER);}
                    else if(month_one == 9)     {LCD_ASCII("9",88,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    day_ten++;
                    if(day_ten == 4)
                    {
                        day_ten = 0;
                    }
                    if(day_ten == 0)          {LCD_ASCII("0",102,2,7,16,INVERSER);}
                    else if(day_ten == 1)     {LCD_ASCII("1",102,2,7,16,INVERSER);}
                    else if(day_ten == 2)     {LCD_ASCII("2",102,2,7,16,INVERSER);}
                    else if(day_ten == 3)     {LCD_ASCII("3",102,2,7,16,INVERSER);}
                    else if(day_ten == 4)     {LCD_ASCII("4",102,2,7,16,INVERSER);}
                    else if(day_ten == 5)     {LCD_ASCII("5",102,2,7,16,INVERSER);}
                    else if(day_ten == 6)     {LCD_ASCII("6",102,2,7,16,INVERSER);}
                    else if(day_ten == 7)     {LCD_ASCII("7",102,2,7,16,INVERSER);}
                    else if(day_ten == 8)     {LCD_ASCII("8",102,2,7,16,INVERSER);}
                    else if(day_ten == 9)     {LCD_ASCII("9",102,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    day_one++;
                    if(day_one == 10)
                    {
                        day_one = 0;
                    }
                    if(day_one == 0)          {LCD_ASCII("0",109,2,7,16,INVERSER);}
                    else if(day_one == 1)     {LCD_ASCII("1",109,2,7,16,INVERSER);}
                    else if(day_one == 2)     {LCD_ASCII("2",109,2,7,16,INVERSER);}
                    else if(day_one == 3)     {LCD_ASCII("3",109,2,7,16,INVERSER);}
                    else if(day_one == 4)     {LCD_ASCII("4",109,2,7,16,INVERSER);}
                    else if(day_one == 5)     {LCD_ASCII("5",109,2,7,16,INVERSER);}
                    else if(day_one == 6)     {LCD_ASCII("6",109,2,7,16,INVERSER);}
                    else if(day_one == 7)     {LCD_ASCII("7",109,2,7,16,INVERSER);}
                    else if(day_one == 8)     {LCD_ASCII("8",109,2,7,16,INVERSER);}
                    else if(day_one == 9)     {LCD_ASCII("9",109,2,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    year_ten--;
                    if(year_ten < 0)
                    {
                        year_ten = 9;
                    }
                    if(year_ten == 0)          {LCD_ASCII("0",60,2,7,16,INVERSER);}
                    else if(year_ten == 1)     {LCD_ASCII("1",60,2,7,16,INVERSER);}
                    else if(year_ten == 2)     {LCD_ASCII("2",60,2,7,16,INVERSER);}
                    else if(year_ten == 3)     {LCD_ASCII("3",60,2,7,16,INVERSER);}
                    else if(year_ten == 4)     {LCD_ASCII("4",60,2,7,16,INVERSER);}
                    else if(year_ten == 5)     {LCD_ASCII("5",60,2,7,16,INVERSER);}
                    else if(year_ten == 6)     {LCD_ASCII("6",60,2,7,16,INVERSER);}
                    else if(year_ten == 7)     {LCD_ASCII("7",60,2,7,16,INVERSER);}
                    else if(year_ten == 8)     {LCD_ASCII("8",60,2,7,16,INVERSER);}
                    else if(year_ten == 9)     {LCD_ASCII("9",60,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    year_one--;
                    if(year_one < 0)
                    {
                        year_one = 9;
                    }
                    if(year_one == 0)          {LCD_ASCII("0",67,2,7,16,INVERSER);}
                    else if(year_one == 1)     {LCD_ASCII("1",67,2,7,16,INVERSER);}
                    else if(year_one == 2)     {LCD_ASCII("2",67,2,7,16,INVERSER);}
                    else if(year_one == 3)     {LCD_ASCII("3",67,2,7,16,INVERSER);}
                    else if(year_one == 4)     {LCD_ASCII("4",67,2,7,16,INVERSER);}
                    else if(year_one == 5)     {LCD_ASCII("5",67,2,7,16,INVERSER);}
                    else if(year_one == 6)     {LCD_ASCII("6",67,2,7,16,INVERSER);}
                    else if(year_one == 7)     {LCD_ASCII("7",67,2,7,16,INVERSER);}
                    else if(year_one == 8)     {LCD_ASCII("8",67,2,7,16,INVERSER);}
                    else if(year_one == 9)     {LCD_ASCII("9",67,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    month_ten--;
                    if(month_ten < 0)
                    {
                        month_ten = 1;
                    }
                    if(month_ten == 0)          {LCD_ASCII("0",81,2,7,16,INVERSER);}
                    else if(month_ten == 1)     {LCD_ASCII("1",81,2,7,16,INVERSER);}
                    else if(month_ten == 2)     {LCD_ASCII("2",81,2,7,16,INVERSER);}
                    else if(month_ten == 3)     {LCD_ASCII("3",81,2,7,16,INVERSER);}
                    else if(month_ten == 4)     {LCD_ASCII("4",81,2,7,16,INVERSER);}
                    else if(month_ten == 5)     {LCD_ASCII("5",81,2,7,16,INVERSER);}
                    else if(month_ten == 6)     {LCD_ASCII("6",81,2,7,16,INVERSER);}
                    else if(month_ten == 7)     {LCD_ASCII("7",81,2,7,16,INVERSER);}
                    else if(month_ten == 8)     {LCD_ASCII("8",81,2,7,16,INVERSER);}
                    else if(month_ten == 9)     {LCD_ASCII("9",81,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    month_one--;
                    if(month_one < 0)
                    {
                        month_one = 9;
                    }
                    if(month_one == 0)          {LCD_ASCII("0",88,2,7,16,INVERSER);}
                    else if(month_one == 1)     {LCD_ASCII("1",88,2,7,16,INVERSER);}
                    else if(month_one == 2)     {LCD_ASCII("2",88,2,7,16,INVERSER);}
                    else if(month_one == 3)     {LCD_ASCII("3",88,2,7,16,INVERSER);}
                    else if(month_one == 4)     {LCD_ASCII("4",88,2,7,16,INVERSER);}
                    else if(month_one == 5)     {LCD_ASCII("5",88,2,7,16,INVERSER);}
                    else if(month_one == 6)     {LCD_ASCII("6",88,2,7,16,INVERSER);}
                    else if(month_one == 7)     {LCD_ASCII("7",88,2,7,16,INVERSER);}
                    else if(month_one == 8)     {LCD_ASCII("8",88,2,7,16,INVERSER);}
                    else if(month_one == 9)     {LCD_ASCII("9",88,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    day_ten--;
                    if(day_ten < 0)
                    {
                        day_ten = 3;
                    }
                    if(day_ten == 0)          {LCD_ASCII("0",102,2,7,16,INVERSER);}
                    else if(day_ten == 1)     {LCD_ASCII("1",102,2,7,16,INVERSER);}
                    else if(day_ten == 2)     {LCD_ASCII("2",102,2,7,16,INVERSER);}
                    else if(day_ten == 3)     {LCD_ASCII("3",102,2,7,16,INVERSER);}
                    else if(day_ten == 4)     {LCD_ASCII("4",102,2,7,16,INVERSER);}
                    else if(day_ten == 5)     {LCD_ASCII("5",102,2,7,16,INVERSER);}
                    else if(day_ten == 6)     {LCD_ASCII("6",102,2,7,16,INVERSER);}
                    else if(day_ten == 7)     {LCD_ASCII("7",102,2,7,16,INVERSER);}
                    else if(day_ten == 8)     {LCD_ASCII("8",102,2,7,16,INVERSER);}
                    else if(day_ten == 9)     {LCD_ASCII("9",102,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    day_one--;
                    if(day_one < 0)
                    {
                        day_one = 9;
                    }
                    if(day_one == 0)          {LCD_ASCII("0",109,2,7,16,INVERSER);}
                    else if(day_one == 1)     {LCD_ASCII("1",109,2,7,16,INVERSER);}
                    else if(day_one == 2)     {LCD_ASCII("2",109,2,7,16,INVERSER);}
                    else if(day_one == 3)     {LCD_ASCII("3",109,2,7,16,INVERSER);}
                    else if(day_one == 4)     {LCD_ASCII("4",109,2,7,16,INVERSER);}
                    else if(day_one == 5)     {LCD_ASCII("5",109,2,7,16,INVERSER);}
                    else if(day_one == 6)     {LCD_ASCII("6",109,2,7,16,INVERSER);}
                    else if(day_one == 7)     {LCD_ASCII("7",109,2,7,16,INVERSER);}
                    else if(day_one == 8)     {LCD_ASCII("8",109,2,7,16,INVERSER);}
                    else if(day_one == 9)     {LCD_ASCII("9",109,2,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(year_one == 0)          {LCD_ASCII("0",67,2,7,16,NORMAL);}
                    else if(year_one == 1)     {LCD_ASCII("1",67,2,7,16,NORMAL);}
                    else if(year_one == 2)     {LCD_ASCII("2",67,2,7,16,NORMAL);}
                    else if(year_one == 3)     {LCD_ASCII("3",67,2,7,16,NORMAL);}
                    else if(year_one == 4)     {LCD_ASCII("4",67,2,7,16,NORMAL);}
                    else if(year_one == 5)     {LCD_ASCII("5",67,2,7,16,NORMAL);}
                    else if(year_one == 6)     {LCD_ASCII("6",67,2,7,16,NORMAL);}
                    else if(year_one == 7)     {LCD_ASCII("7",67,2,7,16,NORMAL);}
                    else if(year_one == 8)     {LCD_ASCII("8",67,2,7,16,NORMAL);}
                    else if(year_one == 9)     {LCD_ASCII("9",67,2,7,16,NORMAL);}
                    
                    if(year_ten == 0)          {LCD_ASCII("0",60,2,7,16,INVERSER);}
                    else if(year_ten == 1)     {LCD_ASCII("1",60,2,7,16,INVERSER);}
                    else if(year_ten == 2)     {LCD_ASCII("2",60,2,7,16,INVERSER);}
                    else if(year_ten == 3)     {LCD_ASCII("3",60,2,7,16,INVERSER);}
                    else if(year_ten == 4)     {LCD_ASCII("4",60,2,7,16,INVERSER);}
                    else if(year_ten == 5)     {LCD_ASCII("5",60,2,7,16,INVERSER);}
                    else if(year_ten == 6)     {LCD_ASCII("6",60,2,7,16,INVERSER);}
                    else if(year_ten == 7)     {LCD_ASCII("7",60,2,7,16,INVERSER);}
                    else if(year_ten == 8)     {LCD_ASCII("8",60,2,7,16,INVERSER);}
                    else if(year_ten == 9)     {LCD_ASCII("9",60,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(month_ten == 0)          {LCD_ASCII("0",81,2,7,16,NORMAL);}
                    else if(month_ten == 1)     {LCD_ASCII("1",81,2,7,16,NORMAL);}
                    else if(month_ten == 2)     {LCD_ASCII("2",81,2,7,16,NORMAL);}
                    else if(month_ten == 3)     {LCD_ASCII("3",81,2,7,16,NORMAL);}
                    else if(month_ten == 4)     {LCD_ASCII("4",81,2,7,16,NORMAL);}
                    else if(month_ten == 5)     {LCD_ASCII("5",81,2,7,16,NORMAL);}
                    else if(month_ten == 6)     {LCD_ASCII("6",81,2,7,16,NORMAL);}
                    else if(month_ten == 7)     {LCD_ASCII("7",81,2,7,16,NORMAL);}
                    else if(month_ten == 8)     {LCD_ASCII("8",81,2,7,16,NORMAL);}
                    else if(month_ten == 9)     {LCD_ASCII("9",81,2,7,16,NORMAL);}
                  
                    if(year_one == 0)          {LCD_ASCII("0",67,2,7,16,INVERSER);}
                    else if(year_one == 1)     {LCD_ASCII("1",67,2,7,16,INVERSER);}
                    else if(year_one == 2)     {LCD_ASCII("2",67,2,7,16,INVERSER);}
                    else if(year_one == 3)     {LCD_ASCII("3",67,2,7,16,INVERSER);}
                    else if(year_one == 4)     {LCD_ASCII("4",67,2,7,16,INVERSER);}
                    else if(year_one == 5)     {LCD_ASCII("5",67,2,7,16,INVERSER);}
                    else if(year_one == 6)     {LCD_ASCII("6",67,2,7,16,INVERSER);}
                    else if(year_one == 7)     {LCD_ASCII("7",67,2,7,16,INVERSER);}
                    else if(year_one == 8)     {LCD_ASCII("8",67,2,7,16,INVERSER);}
                    else if(year_one == 9)     {LCD_ASCII("9",67,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(month_one == 0)          {LCD_ASCII("0",88,2,7,16,NORMAL);}
                    else if(month_one == 1)     {LCD_ASCII("1",88,2,7,16,NORMAL);}
                    else if(month_one == 2)     {LCD_ASCII("2",88,2,7,16,NORMAL);}
                    else if(month_one == 3)     {LCD_ASCII("3",88,2,7,16,NORMAL);}
                    else if(month_one == 4)     {LCD_ASCII("4",88,2,7,16,NORMAL);}
                    else if(month_one == 5)     {LCD_ASCII("5",88,2,7,16,NORMAL);}
                    else if(month_one == 6)     {LCD_ASCII("6",88,2,7,16,NORMAL);}
                    else if(month_one == 7)     {LCD_ASCII("7",88,2,7,16,NORMAL);}
                    else if(month_one == 8)     {LCD_ASCII("8",88,2,7,16,NORMAL);}
                    else if(month_one == 9)     {LCD_ASCII("9",88,2,7,16,NORMAL);}
                  
                    if(month_ten == 0)          {LCD_ASCII("0",81,2,7,16,INVERSER);}
                    else if(month_ten == 1)     {LCD_ASCII("1",81,2,7,16,INVERSER);}
                    else if(month_ten == 2)     {LCD_ASCII("2",81,2,7,16,INVERSER);}
                    else if(month_ten == 3)     {LCD_ASCII("3",81,2,7,16,INVERSER);}
                    else if(month_ten == 4)     {LCD_ASCII("4",81,2,7,16,INVERSER);}
                    else if(month_ten == 5)     {LCD_ASCII("5",81,2,7,16,INVERSER);}
                    else if(month_ten == 6)     {LCD_ASCII("6",81,2,7,16,INVERSER);}
                    else if(month_ten == 7)     {LCD_ASCII("7",81,2,7,16,INVERSER);}
                    else if(month_ten == 8)     {LCD_ASCII("8",81,2,7,16,INVERSER);}
                    else if(month_ten == 9)     {LCD_ASCII("9",81,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(day_ten == 0)          {LCD_ASCII("0",102,2,7,16,NORMAL);}
                    else if(day_ten == 1)     {LCD_ASCII("1",102,2,7,16,NORMAL);}
                    else if(day_ten == 2)     {LCD_ASCII("2",102,2,7,16,NORMAL);}
                    else if(day_ten == 3)     {LCD_ASCII("3",102,2,7,16,NORMAL);}
                    else if(day_ten == 4)     {LCD_ASCII("4",102,2,7,16,NORMAL);}
                    else if(day_ten == 5)     {LCD_ASCII("5",102,2,7,16,NORMAL);}
                    else if(day_ten == 6)     {LCD_ASCII("6",102,2,7,16,NORMAL);}
                    else if(day_ten == 7)     {LCD_ASCII("7",102,2,7,16,NORMAL);}
                    else if(day_ten == 8)     {LCD_ASCII("8",102,2,7,16,NORMAL);}
                    else if(day_ten == 9)     {LCD_ASCII("9",102,2,7,16,NORMAL);}
                  
                    if(month_one == 0)          {LCD_ASCII("0",88,2,7,16,INVERSER);}
                    else if(month_one == 1)     {LCD_ASCII("1",88,2,7,16,INVERSER);}
                    else if(month_one == 2)     {LCD_ASCII("2",88,2,7,16,INVERSER);}
                    else if(month_one == 3)     {LCD_ASCII("3",88,2,7,16,INVERSER);}
                    else if(month_one == 4)     {LCD_ASCII("4",88,2,7,16,INVERSER);}
                    else if(month_one == 5)     {LCD_ASCII("5",88,2,7,16,INVERSER);}
                    else if(month_one == 6)     {LCD_ASCII("6",88,2,7,16,INVERSER);}
                    else if(month_one == 7)     {LCD_ASCII("7",88,2,7,16,INVERSER);}
                    else if(month_one == 8)     {LCD_ASCII("8",88,2,7,16,INVERSER);}
                    else if(month_one == 9)     {LCD_ASCII("9",88,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(day_one == 0)          {LCD_ASCII("0",109,2,7,16,NORMAL);}
                    else if(day_one == 1)     {LCD_ASCII("1",109,2,7,16,NORMAL);}
                    else if(day_one == 2)     {LCD_ASCII("2",109,2,7,16,NORMAL);}
                    else if(day_one == 3)     {LCD_ASCII("3",109,2,7,16,NORMAL);}
                    else if(day_one == 4)     {LCD_ASCII("4",109,2,7,16,NORMAL);}
                    else if(day_one == 5)     {LCD_ASCII("5",109,2,7,16,NORMAL);}
                    else if(day_one == 6)     {LCD_ASCII("6",109,2,7,16,NORMAL);}
                    else if(day_one == 7)     {LCD_ASCII("7",109,2,7,16,NORMAL);}
                    else if(day_one == 8)     {LCD_ASCII("8",109,2,7,16,NORMAL);}
                    else if(day_one == 9)     {LCD_ASCII("9",109,2,7,16,NORMAL);}
                  
                    if(day_ten == 0)          {LCD_ASCII("0",102,2,7,16,INVERSER);}
                    else if(day_ten == 1)     {LCD_ASCII("1",102,2,7,16,INVERSER);}
                    else if(day_ten == 2)     {LCD_ASCII("2",102,2,7,16,INVERSER);}
                    else if(day_ten == 3)     {LCD_ASCII("3",102,2,7,16,INVERSER);}
                    else if(day_ten == 4)     {LCD_ASCII("4",102,2,7,16,INVERSER);}
                    else if(day_ten == 5)     {LCD_ASCII("5",102,2,7,16,INVERSER);}
                    else if(day_ten == 6)     {LCD_ASCII("6",102,2,7,16,INVERSER);}
                    else if(day_ten == 7)     {LCD_ASCII("7",102,2,7,16,INVERSER);}
                    else if(day_ten == 8)     {LCD_ASCII("8",102,2,7,16,INVERSER);}
                    else if(day_ten == 9)     {LCD_ASCII("9",102,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(year_ten == 0)          {LCD_ASCII("0",60,2,7,16,NORMAL);}
                    else if(year_ten == 1)     {LCD_ASCII("1",60,2,7,16,NORMAL);}
                    else if(year_ten == 2)     {LCD_ASCII("2",60,2,7,16,NORMAL);}
                    else if(year_ten == 3)     {LCD_ASCII("3",60,2,7,16,NORMAL);}
                    else if(year_ten == 4)     {LCD_ASCII("4",60,2,7,16,NORMAL);}
                    else if(year_ten == 5)     {LCD_ASCII("5",60,2,7,16,NORMAL);}
                    else if(year_ten == 6)     {LCD_ASCII("6",60,2,7,16,NORMAL);}
                    else if(year_ten == 7)     {LCD_ASCII("7",60,2,7,16,NORMAL);}
                    else if(year_ten == 8)     {LCD_ASCII("8",60,2,7,16,NORMAL);}
                    else if(year_ten == 9)     {LCD_ASCII("9",60,2,7,16,NORMAL);}
                    
                    if(day_one == 0)          {LCD_ASCII("0",109,2,7,16,INVERSER);}
                    else if(day_one == 1)     {LCD_ASCII("1",109,2,7,16,INVERSER);}
                    else if(day_one == 2)     {LCD_ASCII("2",109,2,7,16,INVERSER);}
                    else if(day_one == 3)     {LCD_ASCII("3",109,2,7,16,INVERSER);}
                    else if(day_one == 4)     {LCD_ASCII("4",109,2,7,16,INVERSER);}
                    else if(day_one == 5)     {LCD_ASCII("5",109,2,7,16,INVERSER);}
                    else if(day_one == 6)     {LCD_ASCII("6",109,2,7,16,INVERSER);}
                    else if(day_one == 7)     {LCD_ASCII("7",109,2,7,16,INVERSER);}
                    else if(day_one == 8)     {LCD_ASCII("8",109,2,7,16,INVERSER);}
                    else if(day_one == 9)     {LCD_ASCII("9",109,2,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(day_one == 0)          {LCD_ASCII("0",109,2,7,16,NORMAL);}
                    else if(day_one == 1)     {LCD_ASCII("1",109,2,7,16,NORMAL);}
                    else if(day_one == 2)     {LCD_ASCII("2",109,2,7,16,NORMAL);}
                    else if(day_one == 3)     {LCD_ASCII("3",109,2,7,16,NORMAL);}
                    else if(day_one == 4)     {LCD_ASCII("4",109,2,7,16,NORMAL);}
                    else if(day_one == 5)     {LCD_ASCII("5",109,2,7,16,NORMAL);}
                    else if(day_one == 6)     {LCD_ASCII("6",109,2,7,16,NORMAL);}
                    else if(day_one == 7)     {LCD_ASCII("7",109,2,7,16,NORMAL);}
                    else if(day_one == 8)     {LCD_ASCII("8",109,2,7,16,NORMAL);}
                    else if(day_one == 9)     {LCD_ASCII("9",109,2,7,16,NORMAL);}
                    
                    if(year_ten == 0)          {LCD_ASCII("0",60,2,7,16,INVERSER);}
                    else if(year_ten == 1)     {LCD_ASCII("1",60,2,7,16,INVERSER);}
                    else if(year_ten == 2)     {LCD_ASCII("2",60,2,7,16,INVERSER);}
                    else if(year_ten == 3)     {LCD_ASCII("3",60,2,7,16,INVERSER);}
                    else if(year_ten == 4)     {LCD_ASCII("4",60,2,7,16,INVERSER);}
                    else if(year_ten == 5)     {LCD_ASCII("5",60,2,7,16,INVERSER);}
                    else if(year_ten == 6)     {LCD_ASCII("6",60,2,7,16,INVERSER);}
                    else if(year_ten == 7)     {LCD_ASCII("7",60,2,7,16,INVERSER);}
                    else if(year_ten == 8)     {LCD_ASCII("8",60,2,7,16,INVERSER);}
                    else if(year_ten == 9)     {LCD_ASCII("9",60,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(year_ten == 0)          {LCD_ASCII("0",60,2,7,16,NORMAL);}
                    else if(year_ten == 1)     {LCD_ASCII("1",60,2,7,16,NORMAL);}
                    else if(year_ten == 2)     {LCD_ASCII("2",60,2,7,16,NORMAL);}
                    else if(year_ten == 3)     {LCD_ASCII("3",60,2,7,16,NORMAL);}
                    else if(year_ten == 4)     {LCD_ASCII("4",60,2,7,16,NORMAL);}
                    else if(year_ten == 5)     {LCD_ASCII("5",60,2,7,16,NORMAL);}
                    else if(year_ten == 6)     {LCD_ASCII("6",60,2,7,16,NORMAL);}
                    else if(year_ten == 7)     {LCD_ASCII("7",60,2,7,16,NORMAL);}
                    else if(year_ten == 8)     {LCD_ASCII("8",60,2,7,16,NORMAL);}
                    else if(year_ten == 9)     {LCD_ASCII("9",60,2,7,16,NORMAL);}
                    
                    if(year_one == 0)          {LCD_ASCII("0",67,2,7,16,INVERSER);}
                    else if(year_one == 1)     {LCD_ASCII("1",67,2,7,16,INVERSER);}
                    else if(year_one == 2)     {LCD_ASCII("2",67,2,7,16,INVERSER);}
                    else if(year_one == 3)     {LCD_ASCII("3",67,2,7,16,INVERSER);}
                    else if(year_one == 4)     {LCD_ASCII("4",67,2,7,16,INVERSER);}
                    else if(year_one == 5)     {LCD_ASCII("5",67,2,7,16,INVERSER);}
                    else if(year_one == 6)     {LCD_ASCII("6",67,2,7,16,INVERSER);}
                    else if(year_one == 7)     {LCD_ASCII("7",67,2,7,16,INVERSER);}
                    else if(year_one == 8)     {LCD_ASCII("8",67,2,7,16,INVERSER);}
                    else if(year_one == 9)     {LCD_ASCII("9",67,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(year_one == 0)          {LCD_ASCII("0",67,2,7,16,NORMAL);}
                    else if(year_one == 1)     {LCD_ASCII("1",67,2,7,16,NORMAL);}
                    else if(year_one == 2)     {LCD_ASCII("2",67,2,7,16,NORMAL);}
                    else if(year_one == 3)     {LCD_ASCII("3",67,2,7,16,NORMAL);}
                    else if(year_one == 4)     {LCD_ASCII("4",67,2,7,16,NORMAL);}
                    else if(year_one == 5)     {LCD_ASCII("5",67,2,7,16,NORMAL);}
                    else if(year_one == 6)     {LCD_ASCII("6",67,2,7,16,NORMAL);}
                    else if(year_one == 7)     {LCD_ASCII("7",67,2,7,16,NORMAL);}
                    else if(year_one == 8)     {LCD_ASCII("8",67,2,7,16,NORMAL);}
                    else if(year_one == 9)     {LCD_ASCII("9",67,2,7,16,NORMAL);}
                    
                    if(month_ten == 0)          {LCD_ASCII("0",81,2,7,16,INVERSER);}
                    else if(month_ten == 1)     {LCD_ASCII("1",81,2,7,16,INVERSER);}
                    else if(month_ten == 2)     {LCD_ASCII("2",81,2,7,16,INVERSER);}
                    else if(month_ten == 3)     {LCD_ASCII("3",81,2,7,16,INVERSER);}
                    else if(month_ten == 4)     {LCD_ASCII("4",81,2,7,16,INVERSER);}
                    else if(month_ten == 5)     {LCD_ASCII("5",81,2,7,16,INVERSER);}
                    else if(month_ten == 6)     {LCD_ASCII("6",81,2,7,16,INVERSER);}
                    else if(month_ten == 7)     {LCD_ASCII("7",81,2,7,16,INVERSER);}
                    else if(month_ten == 8)     {LCD_ASCII("8",81,2,7,16,INVERSER);}
                    else if(month_ten == 9)     {LCD_ASCII("9",81,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(month_ten == 0)          {LCD_ASCII("0",81,2,7,16,NORMAL);}
                    else if(month_ten == 1)     {LCD_ASCII("1",81,2,7,16,NORMAL);}
                    else if(month_ten == 2)     {LCD_ASCII("2",81,2,7,16,NORMAL);}
                    else if(month_ten == 3)     {LCD_ASCII("3",81,2,7,16,NORMAL);}
                    else if(month_ten == 4)     {LCD_ASCII("4",81,2,7,16,NORMAL);}
                    else if(month_ten == 5)     {LCD_ASCII("5",81,2,7,16,NORMAL);}
                    else if(month_ten == 6)     {LCD_ASCII("6",81,2,7,16,NORMAL);}
                    else if(month_ten == 7)     {LCD_ASCII("7",81,2,7,16,NORMAL);}
                    else if(month_ten == 8)     {LCD_ASCII("8",81,2,7,16,NORMAL);}
                    else if(month_ten == 9)     {LCD_ASCII("9",81,2,7,16,NORMAL);}
                    
                    if(month_one == 0)          {LCD_ASCII("0",88,2,7,16,INVERSER);}
                    else if(month_one == 1)     {LCD_ASCII("1",88,2,7,16,INVERSER);}
                    else if(month_one == 2)     {LCD_ASCII("2",88,2,7,16,INVERSER);}
                    else if(month_one == 3)     {LCD_ASCII("3",88,2,7,16,INVERSER);}
                    else if(month_one == 4)     {LCD_ASCII("4",88,2,7,16,INVERSER);}
                    else if(month_one == 5)     {LCD_ASCII("5",88,2,7,16,INVERSER);}
                    else if(month_one == 6)     {LCD_ASCII("6",88,2,7,16,INVERSER);}
                    else if(month_one == 7)     {LCD_ASCII("7",88,2,7,16,INVERSER);}
                    else if(month_one == 8)     {LCD_ASCII("8",88,2,7,16,INVERSER);}
                    else if(month_one == 9)     {LCD_ASCII("9",88,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(month_one == 0)          {LCD_ASCII("0",88,2,7,16,NORMAL);}
                    else if(month_one == 1)     {LCD_ASCII("1",88,2,7,16,NORMAL);}
                    else if(month_one == 2)     {LCD_ASCII("2",88,2,7,16,NORMAL);}
                    else if(month_one == 3)     {LCD_ASCII("3",88,2,7,16,NORMAL);}
                    else if(month_one == 4)     {LCD_ASCII("4",88,2,7,16,NORMAL);}
                    else if(month_one == 5)     {LCD_ASCII("5",88,2,7,16,NORMAL);}
                    else if(month_one == 6)     {LCD_ASCII("6",88,2,7,16,NORMAL);}
                    else if(month_one == 7)     {LCD_ASCII("7",88,2,7,16,NORMAL);}
                    else if(month_one == 8)     {LCD_ASCII("8",88,2,7,16,NORMAL);}
                    else if(month_one == 9)     {LCD_ASCII("9",88,2,7,16,NORMAL);}
                    
                    if(day_ten == 0)          {LCD_ASCII("0",102,2,7,16,INVERSER);}
                    else if(day_ten == 1)     {LCD_ASCII("1",102,2,7,16,INVERSER);}
                    else if(day_ten == 2)     {LCD_ASCII("2",102,2,7,16,INVERSER);}
                    else if(day_ten == 3)     {LCD_ASCII("3",102,2,7,16,INVERSER);}
                    else if(day_ten == 4)     {LCD_ASCII("4",102,2,7,16,INVERSER);}
                    else if(day_ten == 5)     {LCD_ASCII("5",102,2,7,16,INVERSER);}
                    else if(day_ten == 6)     {LCD_ASCII("6",102,2,7,16,INVERSER);}
                    else if(day_ten == 7)     {LCD_ASCII("7",102,2,7,16,INVERSER);}
                    else if(day_ten == 8)     {LCD_ASCII("8",102,2,7,16,INVERSER);}
                    else if(day_ten == 9)     {LCD_ASCII("9",102,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(day_ten == 0)          {LCD_ASCII("0",102,2,7,16,NORMAL);}
                    else if(day_ten == 1)     {LCD_ASCII("1",102,2,7,16,NORMAL);}
                    else if(day_ten == 2)     {LCD_ASCII("2",102,2,7,16,NORMAL);}
                    else if(day_ten == 3)     {LCD_ASCII("3",102,2,7,16,NORMAL);}
                    else if(day_ten == 4)     {LCD_ASCII("4",102,2,7,16,NORMAL);}
                    else if(day_ten == 5)     {LCD_ASCII("5",102,2,7,16,NORMAL);}
                    else if(day_ten == 6)     {LCD_ASCII("6",102,2,7,16,NORMAL);}
                    else if(day_ten == 7)     {LCD_ASCII("7",102,2,7,16,NORMAL);}
                    else if(day_ten == 8)     {LCD_ASCII("8",102,2,7,16,NORMAL);}
                    else if(day_ten == 9)     {LCD_ASCII("9",102,2,7,16,NORMAL);}
                    
                    if(day_one == 0)          {LCD_ASCII("0",109,2,7,16,INVERSER);}
                    else if(day_one == 1)     {LCD_ASCII("1",109,2,7,16,INVERSER);}
                    else if(day_one == 2)     {LCD_ASCII("2",109,2,7,16,INVERSER);}
                    else if(day_one == 3)     {LCD_ASCII("3",109,2,7,16,INVERSER);}
                    else if(day_one == 4)     {LCD_ASCII("4",109,2,7,16,INVERSER);}
                    else if(day_one == 5)     {LCD_ASCII("5",109,2,7,16,INVERSER);}
                    else if(day_one == 6)     {LCD_ASCII("6",109,2,7,16,INVERSER);}
                    else if(day_one == 7)     {LCD_ASCII("7",109,2,7,16,INVERSER);}
                    else if(day_one == 8)     {LCD_ASCII("8",109,2,7,16,INVERSER);}
                    else if(day_one == 9)     {LCD_ASCII("9",109,2,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                year = (year_ten * 10 + year_one);
                month = (month_ten * 10 + month_one);
                day = (day_ten * 10 + day_one);
                PCF8563_Setting_Date(year,month,day);
                //��
                sprintf(str,"%02d-\0", (uint8_t)year);
                LCD_ASCII((uint8_t*)str,60,2,7,16,NORMAL);
                //��
                sprintf(str,"%02d-\0", (uint8_t)month);
                LCD_ASCII((uint8_t*)str,81,2,7,16,NORMAL);
                //��
                sprintf(str,"%02d\0", (uint8_t)day);
                LCD_ASCII((uint8_t*)str,102,2,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                //��
                sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.year);
                LCD_ASCII((uint8_t*)str,60,2,7,16,NORMAL);
                //��
                sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.month);
                LCD_ASCII((uint8_t*)str,81,2,7,16,NORMAL);
                //��
                sprintf(str,"%02d\0", (uint8_t)g_RTCTime.day);
                LCD_ASCII((uint8_t*)str,102,2,7,16,NORMAL);
                return; 
            }
        }
    }
}

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetTime_HMS(void)
�������ܣ�ʵ��ʱ����ʱ������
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetTime_HMS(void)
{
    SYSTEM_RTC rtc_oldtime;
    rtc_oldtime = g_RTCTime;                                   //����ʱ��һ��
    int8_t hour_ten = rtc_oldtime.hour / 10;                    //���ʱ��ʮλ����
    int8_t hour_one = rtc_oldtime.hour % 10;                    //���ʱ�ĸ�λ����
    int8_t minute_ten = rtc_oldtime.minute / 10;                //��÷ֵ�ʮλ����
    int8_t minute_one = rtc_oldtime.minute % 10;                //��÷ֵĸ�λ����
    int8_t second_ten = rtc_oldtime.second / 10;                //������ʮλ����
    int8_t second_one = rtc_oldtime.second % 10;                //�����ĸ�λ����
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    if(hour_ten == 0)          {LCD_ASCII("0",60,4,7,16,INVERSER);}
    else if(hour_ten == 1)     {LCD_ASCII("1",60,4,7,16,INVERSER);}
    else if(hour_ten == 2)     {LCD_ASCII("2",60,4,7,16,INVERSER);}
    else if(hour_ten == 3)     {LCD_ASCII("3",60,4,7,16,INVERSER);}
    else if(hour_ten == 4)     {LCD_ASCII("4",60,4,7,16,INVERSER);}
    else if(hour_ten == 5)     {LCD_ASCII("5",60,4,7,16,INVERSER);}
    else if(hour_ten == 6)     {LCD_ASCII("6",60,4,7,16,INVERSER);}
    else if(hour_ten == 7)     {LCD_ASCII("7",60,4,7,16,INVERSER);}
    else if(hour_ten == 8)     {LCD_ASCII("8",60,4,7,16,INVERSER);}
    else if(hour_ten == 9)     {LCD_ASCII("9",60,4,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    hour_ten++;
                    if(hour_ten == 3)
                    {
                        hour_ten = 0;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",60,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",60,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",60,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",60,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",60,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",60,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",60,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",60,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",60,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",60,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one++;
                    if(hour_one == 10)
                    {
                        hour_one = 0;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",67,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",67,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",67,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",67,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",67,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",67,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",67,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",67,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",67,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",67,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten++;
                    if(minute_ten == 6)
                    {
                        minute_ten = 0;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",81,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",81,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",81,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",81,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",81,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",81,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",81,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",81,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",81,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",81,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one++;
                    if(minute_one == 10)
                    {
                        minute_one = 0;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",88,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",88,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",88,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",88,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",88,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",88,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",88,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",88,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",88,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",88,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten++;
                    if(second_ten == 6)
                    {
                        second_ten = 0;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",102,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",102,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",102,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",102,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",102,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",102,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",102,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",102,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",102,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",102,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one++;
                    if(second_one == 10)
                    {
                        second_one = 0;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",109,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",109,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",109,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",109,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",109,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",109,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",109,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",109,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",109,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",109,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    hour_ten--;
                    if(hour_ten < 0)
                    {
                        hour_ten = 2;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",60,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",60,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",60,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",60,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",60,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",60,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",60,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",60,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",60,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",60,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one--;
                    if(hour_one < 0)
                    {
                        hour_one = 9;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",67,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",67,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",67,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",67,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",67,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",67,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",67,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",67,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",67,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",67,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten--;
                    if(minute_ten < 0)
                    {
                        minute_ten = 5;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",81,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",81,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",81,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",81,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",81,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",81,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",81,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",81,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",81,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",81,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one--;
                    if(minute_one < 0)
                    {
                        minute_one = 9;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",88,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",88,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",88,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",88,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",88,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",88,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",88,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",88,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",88,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",88,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten--;
                    if(second_ten < 0)
                    {
                        second_ten = 5;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",102,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",102,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",102,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",102,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",102,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",102,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",102,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",102,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",102,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",102,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one--;
                    if(second_one < 0)
                    {
                        second_one = 9;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",109,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",109,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",109,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",109,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",109,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",109,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",109,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",109,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",109,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",109,4,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",67,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",67,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",67,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",67,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",67,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",67,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",67,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",67,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",67,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",67,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",60,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",60,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",60,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",60,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",60,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",60,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",60,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",60,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",60,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",60,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",81,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",81,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",81,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",81,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",81,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",81,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",81,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",81,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",81,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",81,4,7,16,NORMAL);}
                  
                    if(hour_one == 0)          {LCD_ASCII("0",67,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",67,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",67,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",67,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",67,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",67,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",67,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",67,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",67,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",67,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",88,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",88,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",88,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",88,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",88,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",88,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",88,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",88,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",88,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",88,4,7,16,NORMAL);}
                  
                    if(minute_ten == 0)          {LCD_ASCII("0",81,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",81,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",81,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",81,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",81,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",81,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",81,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",81,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",81,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",81,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",102,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",102,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",102,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",102,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",102,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",102,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",102,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",102,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",102,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",102,4,7,16,NORMAL);}
                  
                    if(minute_one == 0)          {LCD_ASCII("0",88,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",88,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",88,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",88,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",88,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",88,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",88,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",88,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",88,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",88,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(second_one == 0)          {LCD_ASCII("0",109,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",109,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",109,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",109,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",109,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",109,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",109,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",109,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",109,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",109,4,7,16,NORMAL);}
                  
                    if(second_ten == 0)          {LCD_ASCII("0",102,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",102,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",102,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",102,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",102,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",102,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",102,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",102,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",102,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",102,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",60,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",60,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",60,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",60,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",60,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",60,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",60,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",60,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",60,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",60,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",109,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",109,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",109,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",109,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",109,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",109,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",109,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",109,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",109,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",109,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(second_one == 0)          {LCD_ASCII("0",109,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",109,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",109,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",109,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",109,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",109,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",109,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",109,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",109,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",109,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",60,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",60,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",60,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",60,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",60,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",60,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",60,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",60,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",60,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",60,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",60,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",60,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",60,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",60,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",60,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",60,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",60,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",60,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",60,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",60,4,7,16,NORMAL);}
                    
                    if(hour_one == 0)          {LCD_ASCII("0",67,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",67,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",67,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",67,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",67,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",67,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",67,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",67,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",67,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",67,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",67,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",67,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",67,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",67,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",67,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",67,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",67,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",67,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",67,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",67,4,7,16,NORMAL);}
                    
                    if(minute_ten == 0)          {LCD_ASCII("0",81,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",81,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",81,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",81,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",81,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",81,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",81,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",81,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",81,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",81,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",81,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",81,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",81,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",81,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",81,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",81,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",81,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",81,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",81,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",81,4,7,16,NORMAL);}
                    
                    if(minute_one == 0)          {LCD_ASCII("0",88,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",88,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",88,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",88,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",88,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",88,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",88,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",88,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",88,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",88,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",88,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",88,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",88,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",88,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",88,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",88,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",88,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",88,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",88,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",88,4,7,16,NORMAL);}
                    
                    if(second_ten == 0)          {LCD_ASCII("0",102,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",102,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",102,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",102,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",102,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",102,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",102,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",102,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",102,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",102,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",102,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",102,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",102,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",102,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",102,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",102,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",102,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",102,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",102,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",102,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",109,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",109,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",109,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",109,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",109,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",109,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",109,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",109,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",109,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",109,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                hour = (hour_ten * 10 + hour_one);
                minute = (minute_ten * 10 + minute_one);
                second = (second_ten * 10 + second_one);
                PCF8563_Setting_Time(hour,minute,second);

                sprintf(str,"%02d:\0", (uint8_t)hour);
                LCD_ASCII((uint8_t*)str,60,4,7,16,NORMAL);

                sprintf(str,"%02d:\0", (uint8_t)minute);
                LCD_ASCII((uint8_t*)str,81,4,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)second);
                LCD_ASCII((uint8_t*)str,102,4,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {

                sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
                LCD_ASCII((uint8_t*)str,60,4,7,16,NORMAL);

                sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
                LCD_ASCII((uint8_t*)str,81,4,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
                LCD_ASCII((uint8_t*)str,102,4,7,16,NORMAL);
                return; 
            }
        }
    }
}
/**************** ���ý���1�Ӳ˵�����  ����ͨѶ1*******************/

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetCommunication1(void)
�������ܣ����ò˵�1�Ӳ˵� ����ͨѶ1
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1(void)
{
    uint32_t baud_rate = 0;         //������
    uint8_t data_bits = 0;          //����λ
    uint8_t parity_bit = 0;         //У��λ
    uint8_t stop_bit = 0;           //ֹͣλ
    char str[10];
    if(g_UserChoose < 3)
    {
        //��ֹ����ˢ�ظ��Ľ���
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("ͨѶ����",38,0,13,16,MOVEUP);       //��ʾͨѶ�����ַ�
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�
            LCD_String("������",30,2,13,16,NORMAL);         //��ʾ�������ַ�
            LCD_ASCII(":",69,2,7,16,NORMAL);                //��ʾ������ֵ
            FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);
            //������Ϊ��λ
            if(baud_rate < 1000)
            {
                sprintf(str,"%3d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            //������Ϊ��λ
            else if(baud_rate < 10000)
            {
                sprintf(str,"%4d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            //��������λ
            else if(baud_rate < 100000)
            {
                sprintf(str,"%5d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            //��������λ
            else if(baud_rate < 1000000)
            {
                sprintf(str,"%6d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            LCD_String("����λ",30,4,13,16,NORMAL);         //��ʾ����λ�ַ�
            LCD_ASCII(":",69,4,7,16,NORMAL);               //��ʾ����λֵ�ַ�
            FM24C64_READ_MUL(DATA_BITS,(uint8_t*)&data_bits,1);
            sprintf(str,"%1d\0",data_bits);
            LCD_ASCII((uint8_t*)str,76,4,7,16,NORMAL);
            
            LCD_String("У��λ",30,6,13,16,NORMAL);         //��ʾУ��λ�ַ�
            LCD_ASCII(":",69,6,7,16,NORMAL);                //��ʾУ��λֵ�ַ�
            FM24C64_READ_MUL(PARITY_BIT,(uint8_t*)&parity_bit,1);
            if(parity_bit == 1)
            {
                LCD_ASCII("None",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 2)
            {
                LCD_ASCII("Odd",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 3)
            {
                LCD_ASCII("Even",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 4)
            {
                LCD_ASCII("Mark",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 5)
            {
                LCD_ASCII("Space",76,6,7,16,NORMAL);
            }
         
            flag1 = 1;
            flag2 = 0;
        }
            
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("ͨѶ����",38,0,13,16,MOVEUP);       //��ʾͨѶ�����ַ�
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            LCD_String("ֹͣλ",30,2,13,16,NORMAL);         //��ʾֹͣλ�ַ�
            LCD_ASCII(":",69,2,7,16,NORMAL);               //��ʾֹͣλֵ�ַ�
            FM24C64_READ_MUL(STOP_BIT,(uint8_t*)&stop_bit,1);
            if(stop_bit == 1)
            {
                LCD_ASCII("1",76,2,7,16,NORMAL);
            }
            else if(stop_bit == 2)
            {
                LCD_ASCII("1.5",76,2,7,16,NORMAL);
            }
            else if(stop_bit == 3)
            {
                LCD_ASCII("2",76,2,7,16,NORMAL);
            }
                    
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetCommunication1_BAUD(void)
�������ܣ����ò˵�1�Ӳ˵� ����ͨѶ1-����������
          300/600/1200/2400/4800/9600/19200/38400/43000/56000/115200 
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_BAUD(void)
{
    uint32_t old_baud_rate = 0;     //����ϵĲ�����
    uint8_t *key;
    char str[10];
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //������
    uint8_t data_bits = 0;          //����λ
    uint8_t parity_bit = 0;         //У��λ
    uint8_t stop_bit = 0;           //ֹͣλ
     
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //������
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //����λ
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //У��λ
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //ֹͣλ
    
    old_baud_rate = baud_rate;
    //������Ϊ��λ
    if(baud_rate < 1000)
    {
        sprintf(str,"%3d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    //������Ϊ��λ
    else if(baud_rate < 10000)
    {
        sprintf(str,"%4d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    //��������λ
    else if(baud_rate < 100000)
    {
        sprintf(str,"%5d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    //��������λ
    else if(baud_rate < 1000000)
    {
        sprintf(str,"%6d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(baud_rate == 300)
            {
                baud_rate = 600;
                sprintf(str,"%3d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 600)
            {
                baud_rate = 1200;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 1200)
            {
                baud_rate = 2400;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 2400)
            {
                baud_rate = 4800;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 4800)
            {
                baud_rate = 9600;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 9600)
            {
                baud_rate = 19200;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 19200)
            {
                baud_rate = 38400;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 38400)
            {
                baud_rate = 43000;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 43000)
            {
                baud_rate = 56000;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 56000)
            {
                baud_rate = 115200;
                sprintf(str,"%6d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 115200)
            {
                baud_rate = 300;
                sprintf(str,"%3d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
        }
        else if(*key == KEY_DOWN)
        {
            if(baud_rate == 300)
            {
                baud_rate = 115200;
                sprintf(str,"%6d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 600)
            {
                baud_rate = 300;
                sprintf(str,"%3d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 1200)
            {
                baud_rate = 600;
                sprintf(str,"%3d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 2400)
            {
                baud_rate = 1200;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 4800)
            {
                baud_rate = 2400;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 9600)
            {
                baud_rate = 4800;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 19200)
            {
                baud_rate = 9600;
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 38400)
            {
                baud_rate = 19200;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 43000)
            {
                baud_rate = 38400;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 56000)
            {
                baud_rate = 43000;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
            else if(baud_rate == 115200)
            {
                baud_rate = 56000;
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
            }
        }
        else if(*key == KEY_ENTER)
        {
            if(baud_rate == 300)
            {
                sprintf(str,"%3d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 600)
            {
                sprintf(str,"%3d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 1200)
            {
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 2400)
            {
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 4800)
            {
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 9600)
            {
                sprintf(str,"%4d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 19200)
            {
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 38400)
            {
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 43000)
            {
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 56000)
            {
                sprintf(str,"%5d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(baud_rate == 115200)
            {
                sprintf(str,"%6d\0",baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            FM24C64_WRITE_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);
            /********************ʵ�ִ��ڵĳ�ʼ��********************/
            /*������*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*����λ*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*ֹͣλ*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*У��λ*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //��ʼ������
            USART_Init(USART1, &USART_InitStructure);                           
            return;
        }
        else if(*key == KEY_CAL)
        {
            if(old_baud_rate == 300)
            {
                sprintf(str,"%3d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 600)
            {
                sprintf(str,"%3d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 1200)
            {
                sprintf(str,"%4d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 2400)
            {
                sprintf(str,"%4d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 4800)
            {
                sprintf(str,"%4d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 9600)
            {
                sprintf(str,"%4d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 19200)
            {
                sprintf(str,"%5d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 38400)
            {
                sprintf(str,"%5d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 43000)
            {
                sprintf(str,"%5d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 56000)
            {
                sprintf(str,"%5d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            else if(old_baud_rate == 115200)
            {
                sprintf(str,"%6d\0",old_baud_rate);
                LCDClrWin(76,2,118,3);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            return;
        }
    }   
}
/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetCommunication1_DATABITS(void)
�������ܣ����ò˵�1�Ӳ˵� ����ͨѶ1-����λ����
          5/6/7/8
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_DATABITS(void)
{
    uint8_t old_data_bits = 0;     //����ϵ�����λ��
    uint8_t *key;
    char str[10];
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //������
    uint8_t data_bits = 0;          //����λ
    uint8_t parity_bit = 0;         //У��λ
    uint8_t stop_bit = 0;           //ֹͣλ
    
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //������
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //����λ
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //У��λ
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //ֹͣλ
      
    old_data_bits = data_bits;
    //����λ���з���
    sprintf(str,"%1d\0",data_bits);
    LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);

    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(data_bits == 5)
            {
                data_bits = 6;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
            else if(data_bits == 6)
            {
                data_bits = 7;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
            else if(data_bits == 7)
            {
                data_bits = 8;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
            else if(data_bits == 8)
            {
                data_bits = 5;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
        }
        else if(*key == KEY_DOWN)
        {
            if(data_bits == 5)
            {
                data_bits = 8;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
            else if(data_bits == 8)
            {
                data_bits = 7;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
            else if(data_bits == 7)
            {
                data_bits = 6;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
            else if(data_bits == 6)
            {
                data_bits = 5;
                sprintf(str,"%1d\0",data_bits);
                LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);
            }
        }
        else if(*key == KEY_ENTER)
        {
            sprintf(str,"%1d\0",data_bits);
            LCD_ASCII((uint8_t*)str,76,4,7,16,NORMAL);
            FM24C64_WRITE_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);
            /********************ʵ�ִ��ڵĳ�ʼ��********************/
            /*������*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*����λ*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*ֹͣλ*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*У��λ*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //��ʼ������
            USART_Init(USART1, &USART_InitStructure);   
            return;
        }
        else if(*key == KEY_CAL)
        {
            sprintf(str,"%1d\0",old_data_bits);
            LCD_ASCII((uint8_t*)str,76,4,7,16,NORMAL);
            return;
        }
    }
}

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetCommunication1_PARITYBIT(void)
�������ܣ����ò˵�1�Ӳ˵� ����ͨѶ1-У��λ����
          None/Odd/Even/Mark/Space
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_PARITYBIT(void)
{
    uint8_t old_parity_bit = 0;     //����ϵ�У��λ
    uint8_t *key;
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //������
    uint8_t data_bits = 0;          //����λ
    uint8_t parity_bit = 0;         //У��λ
    uint8_t stop_bit = 0;           //ֹͣλ
    
      
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //������
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //����λ
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //У��λ
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //ֹͣλ
    
    old_parity_bit = parity_bit;
    //����λ���з���
    if(parity_bit == 1)
    {
        LCD_ASCII("None",76,6,7,16,INVERSER);
    }
    else if(parity_bit == 2)
    {
        LCD_ASCII("Odd",76,6,7,16,INVERSER);
    }
    else if(parity_bit == 3)
    {
        LCD_ASCII("Even",76,6,7,16,INVERSER);
    }
    else if(parity_bit == 4)
    {
        LCD_ASCII("Mark",76,6,7,16,INVERSER);
    }
    else if(parity_bit == 5)
    {
        LCD_ASCII("Space",76,6,7,16,INVERSER);
    }

    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(parity_bit == 1)
            {
                parity_bit = 2;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Odd",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 2)
            {
                parity_bit = 3;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Even",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 3)
            {
                parity_bit = 4;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Mark",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 4)
            {
                parity_bit = 5;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Space",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 5)
            {
                parity_bit = 1;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("None",76,6,7,16,INVERSER);
            }
        }
        else if(*key == KEY_DOWN)
        {
            if(parity_bit == 1)
            {
                parity_bit = 5;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Space",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 2)
            {
                parity_bit = 1;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("None",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 3)
            {
                parity_bit = 2;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Odd",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 4)
            {
                parity_bit = 3;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Even",76,6,7,16,INVERSER);
            }
            else if(parity_bit == 5)
            {
                parity_bit = 4;
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Mark",76,6,7,16,INVERSER);
            }
        }
        else if(*key == KEY_ENTER)
        {
            //У��λ���з���
            if(parity_bit == 1)
            {
                LCD_ASCII("None",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 2)
            {
                LCD_ASCII("Odd",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 3)
            {
                LCD_ASCII("Even",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 4)
            {
                LCD_ASCII("Mark",76,6,7,16,NORMAL);
            }
            else if(parity_bit == 5)
            {
                LCD_ASCII("Space",76,6,7,16,NORMAL);
            }
            FM24C64_WRITE_MUL(PARITY_BIT,(uint8_t*)&parity_bit,1);
             /********************ʵ�ִ��ڵĳ�ʼ��********************/
            /*������*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*����λ*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*ֹͣλ*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*У��λ*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //��ʼ������
            USART_Init(USART1, &USART_InitStructure);  
            return;
        }
        else if(*key == KEY_CAL)
        {
            if(old_parity_bit == 1)
            {
                LCDClrWin(76,6,111,7);
                LCD_ASCII("None",76,6,7,16,NORMAL);
            }
            else if(old_parity_bit == 2)
            {
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Odd",76,6,7,16,NORMAL);
            }
            else if(old_parity_bit == 3)
            {
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Even",76,6,7,16,NORMAL);
            }
            else if(old_parity_bit == 4)
            {
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Mark",76,6,7,16,NORMAL);
            }
            else if(old_parity_bit == 5)
            {
                LCDClrWin(76,6,111,7);
                LCD_ASCII("Space",76,6,7,16,NORMAL);
            }
            return;
        }
    }
}

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetCommunication1_STOPBIT(void)
�������ܣ����ò˵�1�Ӳ˵� ����ͨѶ1-ֹͣλ����
          1/1.5/2  �ֱ���ڵı�־Ϊ��1��2��3
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_STOPBIT(void)
{
    uint8_t old_stop_bit = 0;     //����ϵ�У��λ
    uint8_t *key;
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //������
    uint8_t data_bits = 0;          //����λ
    uint8_t parity_bit = 0;         //У��λ
    uint8_t stop_bit = 0;           //ֹͣλ
    
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //������
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //����λ
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //У��λ
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //ֹͣλ
    
    old_stop_bit = stop_bit;
    //����λ���з���
    if(stop_bit == 1)
    {
        LCD_ASCII("1",76,2,7,16,INVERSER);
    }
    else if(stop_bit == 2)
    {
        LCD_ASCII("1.5",76,2,7,16,INVERSER);
    }
    else if(stop_bit == 3)
    {
        LCD_ASCII("2",76,2,7,16,INVERSER);
    }

    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(stop_bit == 1)
            {
                stop_bit = 2;
                LCDClrWin(76,2,97,3);
                LCD_ASCII("1.5",76,2,7,16,INVERSER);
            }
            else if(stop_bit == 2)
            {
                stop_bit = 3;
                LCDClrWin(76,2,97,3);
                LCD_ASCII("2",76,2,7,16,INVERSER);
            }
            else if(stop_bit == 3)
            {
                stop_bit = 1;
                LCDClrWin(76,2,97,3);
                LCD_ASCII("1",76,2,7,16,INVERSER);
            }
        }
        else if(*key == KEY_DOWN)
        {
            if(stop_bit == 1)
            {
                stop_bit = 3;
                LCDClrWin(76,2,97,3);
                LCD_ASCII("2",76,2,7,16,INVERSER);
            }
            else if(stop_bit == 2)
            {
                stop_bit = 1;
                LCDClrWin(76,2,97,3);
                LCD_ASCII("1",76,2,7,16,INVERSER);
            }
            else if(stop_bit == 3)
            {
                stop_bit = 2;
                LCDClrWin(76,2,97,3);
                LCD_ASCII("1.5",76,2,7,16,INVERSER);
            }
        }
        else if(*key == KEY_ENTER)
        {
            if(stop_bit == 1)
            {
                LCD_ASCII("1",76,2,7,16,NORMAL);
            }
            else if(stop_bit == 2)
            {
                LCD_ASCII("1.5",76,2,7,16,NORMAL);
            }
            else if(stop_bit == 3)
            {
                LCD_ASCII("2",76,2,7,16,NORMAL);
            }
            FM24C64_WRITE_MUL(STOP_BIT,(uint8_t*)&stop_bit,1);
             /********************ʵ�ִ��ڵĳ�ʼ��********************/
            /*������*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*����λ*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*ֹͣλ*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*У��λ*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //��ʼ������
            USART_Init(USART1, &USART_InitStructure);  
            return;
        }
        else if(*key == KEY_CAL)
        {
            if(old_stop_bit == 1)
            {
                LCDClrWin(76,2,97,3);
                LCD_ASCII("1",76,2,7,16,NORMAL);
            }
            else if(old_stop_bit == 2)
            {
                LCDClrWin(76,2,97,3);
                LCD_ASCII("1.5",76,2,7,16,NORMAL);
            }
            else if(old_stop_bit == 3)
            {
                LCDClrWin(76,2,97,3);
                LCD_ASCII("2",76,2,7,16,NORMAL);
            }
            return;
        }
    }
}

/**************** ���ý���1�Ӳ˵�����  ���ȿ���*******************/
/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetHeat(void) 
�������ܣ����ò˵�1�Ӳ˵� ���ȿ���
��ڲ�������
���ڲ�������
******************************************************************
*/    
void Display_SetMenu1_SubSetHeat(void)  
{
    uint8_t heat_con = 0;
    uint8_t heat_temp = 0;
    char str[10];
    uint8_t tab3[10];
    uint8_t tab4[10];
    static uint8_t ad1 = 0;
    static uint8_t ad2 = 0;
    
    if(g_UserChoose <= 2)
    {
        if(flag1 == 0)
        {
            //���ȿ���
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��������",38,0,13,16,MOVEUP);       //��ʾ���������ַ�
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/1�����ַ�
            LCD_String("���ȿ���",30,2,13,16,NORMAL);       //��ʾ���ȿ����ַ�
            LCD_ASCII("[",86,2,7,16,NORMAL);                //��ʾ[�ַ�
            FM24C64_READ_MUL(HEAT_CONT,(uint8_t*)&heat_con,1);
            if(heat_con == 2)
            {
                LCD_String("��",93,2,13,16,NORMAL);
            }
            else
            {
                LCD_String("�ر�",93,2,13,16,NORMAL);
            }
            LCD_ASCII("]",119,2,7,16,NORMAL);               //��ʾ]�ַ�
            
            //�¶�����
            LCD_String("�¶�����",30,4,13,16,NORMAL);       //��ʾ�¶������ַ�
            LCD_ASCII("[",86,4,7,16,NORMAL);                //��ʾ[�ַ�
            
            FM24C64_READ_MUL(HEAT_TEMP,(uint8_t*)&heat_temp,1);
            sprintf(str,"%02d\0", (uint8_t)heat_temp);
            LCD_ASCII((uint8_t*)str,93,4,7,16,NORMAL);
            
            LCD_String("��",107,4,13,16,NORMAL);            //��ʾ���϶��ַ�
            LCD_ASCII("]",119,4,7,16,NORMAL);               //��ʾ]�ַ�
            
            //������
            LCD_String("������",30,6,13,16,NORMAL);         //��ʾ�������ַ�
            LCD_ASCII(":",69,6,7,16,NORMAL);                //��ʾ:�ַ�
            
            if(g_Temperature.DQ3_exist == 0)
            {
                LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",104,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
            flag1 = 1;
            flag2 = 0;
        }
        ad1++;
        if(ad1 > 100)
        {
            ad1 = 0;
            if(g_Temperature.DQ3_exist == 0)
            {
                LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",104,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
        }
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            //�ڶ�ҳ
            LCDClrWin(0,0,127,7);                           //��䶯����
            //���ȿ���
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��������",38,0,13,16,MOVEUP);       //��ʾ���������ַ�
            //����ֵ
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            LCD_String("����ֵ",30,2,13,16,NORMAL);           //��ʾ��ѹ�ַ�
            LCD_ASCII(":",69,2,7,16,NORMAL);                //��ʾ:�ַ�
            
            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
            Float2Str(Pid.Value*100,tab4,2);
            sprintf((char*)(tab4),"%s%\0",tab4);
            LCD_ASCII(tab4,76,2,7,16,NORMAL);
            
            flag1 = 0;
            flag2 = 1;
        }   
        //����ֵת��
        ad2++;
        if(ad2 > 100)
        {
            ad2 = 0;
            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
            Float2Str(Pid.Value*100,tab4,2);
            sprintf((char*)(tab4),"%s%\0",tab4);
            LCD_ASCII(tab4,76,2,7,16,NORMAL);
        }
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        } 
    }
}

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetHeat_HEATCONT(void) 
�������ܣ����ò˵�1�Ӳ˵� ���ȿ���(���ƿ���)
��ڲ�������
���ڲ�������
******************************************************************
*/    
void Display_SetMenu1_SubSetHeat_HEATCONT(void)  
{
    uint8_t heat_con = 0;           //�¶ȿ���
    uint8_t old_heat_con = 0;     //����ϵ�У��λ
    uint8_t *key;
    
    FM24C64_READ_MUL(HEAT_CONT,(uint8_t*)&heat_con,1);
    old_heat_con = heat_con;
    
    //����λ���з���
    if(heat_con == 1)
    {
        LCD_String("�ر�",93,2,13,16,INVERSER);
    }
    else if(heat_con == 2)
    {
        LCD_String("��",93,2,13,16,INVERSER);
    }

    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(heat_con == 1)
            {
                heat_con = 2;
                LCD_String("��",93,2,13,16,INVERSER);
            }
            else if(heat_con == 2)
            {
                heat_con = 1;
                LCD_String("�ر�",93,2,13,16,INVERSER);
            }
        }
        else if(*key == KEY_DOWN)
        {
            if(heat_con == 1)
            {
                heat_con = 2;
                LCD_String("��",93,2,13,16,INVERSER);
            }
            else if(heat_con == 2)
            {
                heat_con = 1;
                LCD_String("�ر�",93,2,13,16,INVERSER);
            }
        }
        else if(*key == KEY_ENTER)
        {
            if(heat_con == 1)
            {
                LCD_String("�ر�",93,2,13,16,NORMAL);
                Pid.Value = 0;
                PWM_Configuration(Pid.Value);               //PWMͨ��PIDֵ�����������
                PD2_FAN_OFF();                              //�رշ���
                Pid.SumError = 0;
            }
            else if(heat_con == 2)
            {
                LCD_String("��",93,2,13,16,NORMAL);
                PD2_FAN_ON();                       //�򿪷���
                PWM_Configuration(1);               //PWMͨ��PIDֵ�����������
            }
            FM24C64_WRITE_MUL(HEAT_CONT,(uint8_t*)&heat_con,1);
            return;
        }
        else if(*key == KEY_CAL)
        {
            if(old_heat_con == 1)
            {
                LCD_String("�ر�",93,2,13,16,NORMAL);
            }
            else if(old_heat_con == 2)
            {
                LCD_String("��",93,2,13,16,NORMAL);
            }
            return;
        }
    }  
}

/*
******************************************************************
�������ƣ�void Display_SetMenu1_SubSetHeat_HEAT_TEMP(void) 
�������ܣ����ò˵�1�Ӳ˵� ���ȿ���(�¶����ÿ���)
��ڲ�������
���ڲ�������
******************************************************************
*/    
void Display_SetMenu1_SubSetHeat_HEAT_TEMP(void)  
{
    uint8_t heat_temp = 0;           //�¶�����
    uint8_t old_heat_temp = 0;       //����ϵ��¶�����ֵ
    int8_t heat_temp_ten = 0;       //�¶ȵ�ʮλ
    int8_t heat_temp_one = 0;       //�¶ȵĸ�λ
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(HEAT_TEMP,(uint8_t*)&heat_temp,1);
    old_heat_temp = heat_temp;
    
    heat_temp_ten = heat_temp / 10;
    heat_temp_one = heat_temp % 10;
    
    //����λ���з���
    if(heat_temp_ten == 0)              {LCD_ASCII("0",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 1)         {LCD_ASCII("1",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 2)         {LCD_ASCII("2",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 3)         {LCD_ASCII("3",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 4)         {LCD_ASCII("4",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 5)         {LCD_ASCII("5",93,4,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(add == 1)
            {
                heat_temp_ten++;
                if(heat_temp_ten == 6)
                {
                    heat_temp_ten = 0;
                }
                if(heat_temp_ten == 0)           {LCD_ASCII("0",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 1)      {LCD_ASCII("1",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 2)      {LCD_ASCII("2",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 3)      {LCD_ASCII("3",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 4)      {LCD_ASCII("4",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 5)      {LCD_ASCII("5",93,4,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                heat_temp_one++;
                if(heat_temp_one == 10)
                {
                    heat_temp_one = 0;
                }
                if(heat_temp_one == 0)           {LCD_ASCII("0",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 1)      {LCD_ASCII("1",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 2)      {LCD_ASCII("2",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 3)      {LCD_ASCII("3",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 4)      {LCD_ASCII("4",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 5)      {LCD_ASCII("5",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 6)      {LCD_ASCII("6",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 7)      {LCD_ASCII("7",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 8)      {LCD_ASCII("8",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 9)      {LCD_ASCII("9",100,4,7,16,INVERSER);}
            }
            
        }
        else if(*key == KEY_DOWN)
        {
            if(add == 1)
            {
                heat_temp_ten--;
                if(heat_temp_ten < 0)
                {
                    heat_temp_ten = 5;
                }
                if(heat_temp_ten == 0)           {LCD_ASCII("0",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 1)      {LCD_ASCII("1",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 2)      {LCD_ASCII("2",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 3)      {LCD_ASCII("3",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 4)      {LCD_ASCII("4",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 5)      {LCD_ASCII("5",93,4,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                heat_temp_one--;
                if(heat_temp_one < 0)
                {
                    heat_temp_one = 9;
                }
                if(heat_temp_one == 0)           {LCD_ASCII("0",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 1)      {LCD_ASCII("1",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 2)      {LCD_ASCII("2",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 3)      {LCD_ASCII("3",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 4)      {LCD_ASCII("4",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 5)      {LCD_ASCII("5",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 6)      {LCD_ASCII("6",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 7)      {LCD_ASCII("7",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 8)      {LCD_ASCII("8",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 9)      {LCD_ASCII("9",100,4,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_LEFT)
        {
            add--;
            if(add == 0)
            {
                add = 2;
            }
            if(add == 1)
            {   
                if(heat_temp_one == 0)           {LCD_ASCII("0",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 1)      {LCD_ASCII("1",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 2)      {LCD_ASCII("2",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 3)      {LCD_ASCII("3",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 4)      {LCD_ASCII("4",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 5)      {LCD_ASCII("5",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 6)      {LCD_ASCII("6",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 7)      {LCD_ASCII("7",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 8)      {LCD_ASCII("8",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 9)      {LCD_ASCII("9",100,4,7,16,NORMAL);}
                
                if(heat_temp_ten == 0)           {LCD_ASCII("0",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 1)      {LCD_ASCII("1",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 2)      {LCD_ASCII("2",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 3)      {LCD_ASCII("3",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 4)      {LCD_ASCII("4",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 5)      {LCD_ASCII("5",93,4,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                if(heat_temp_ten == 0)           {LCD_ASCII("0",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 1)      {LCD_ASCII("1",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 2)      {LCD_ASCII("2",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 3)      {LCD_ASCII("3",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 4)      {LCD_ASCII("4",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 5)      {LCD_ASCII("5",93,4,7,16,NORMAL);}
                
                if(heat_temp_one == 0)           {LCD_ASCII("0",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 1)      {LCD_ASCII("1",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 2)      {LCD_ASCII("2",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 3)      {LCD_ASCII("3",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 4)      {LCD_ASCII("4",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 5)      {LCD_ASCII("5",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 6)      {LCD_ASCII("6",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 7)      {LCD_ASCII("7",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 8)      {LCD_ASCII("8",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 9)      {LCD_ASCII("9",100,4,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_RIGHT)
        {
            add++;
            if(add == 3)
            {
                add = 1;
            }
            if(add == 1)
            {
                if(heat_temp_ten == 0)           {LCD_ASCII("0",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 1)      {LCD_ASCII("1",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 2)      {LCD_ASCII("2",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 3)      {LCD_ASCII("3",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 4)      {LCD_ASCII("4",93,4,7,16,INVERSER);}
                else if(heat_temp_ten == 5)      {LCD_ASCII("5",93,4,7,16,INVERSER);}
                
                if(heat_temp_one == 0)           {LCD_ASCII("0",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 1)      {LCD_ASCII("1",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 2)      {LCD_ASCII("2",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 3)      {LCD_ASCII("3",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 4)      {LCD_ASCII("4",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 5)      {LCD_ASCII("5",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 6)      {LCD_ASCII("6",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 7)      {LCD_ASCII("7",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 8)      {LCD_ASCII("8",100,4,7,16,NORMAL);}
                else if(heat_temp_one == 9)      {LCD_ASCII("9",100,4,7,16,NORMAL);}
            }
            else if(add == 2)
            {
                if(heat_temp_ten == 0)           {LCD_ASCII("0",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 1)      {LCD_ASCII("1",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 2)      {LCD_ASCII("2",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 3)      {LCD_ASCII("3",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 4)      {LCD_ASCII("4",93,4,7,16,NORMAL);}
                else if(heat_temp_ten == 5)      {LCD_ASCII("5",93,4,7,16,NORMAL);}
                
                if(heat_temp_one == 0)           {LCD_ASCII("0",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 1)      {LCD_ASCII("1",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 2)      {LCD_ASCII("2",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 3)      {LCD_ASCII("3",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 4)      {LCD_ASCII("4",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 5)      {LCD_ASCII("5",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 6)      {LCD_ASCII("6",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 7)      {LCD_ASCII("7",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 8)      {LCD_ASCII("8",100,4,7,16,INVERSER);}
                else if(heat_temp_one == 9)      {LCD_ASCII("9",100,4,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_ENTER)
        {
            heat_temp = (heat_temp_ten * 10 + heat_temp_one);
            if(heat_temp >= 50)
            {
                heat_temp = 50;
            }
            if(heat_temp <= 0)
            {
                heat_temp = 0;
            }
            sprintf(str,"%02d\0", (uint8_t)heat_temp);
            LCD_ASCII((uint8_t*)str,93,4,7,16,NORMAL);
            FM24C64_WRITE_MUL(HEAT_TEMP,(uint8_t*)&heat_temp,1);
            //д��PID������
            Pid.SetPoint = heat_temp;
            Pid.SumError = 0;
            return;
        }
        else if(*key == KEY_CAL)
        {
            sprintf(str,"%02d\0", (uint8_t)old_heat_temp);
            LCD_ASCII((uint8_t*)str,93,4,7,16,NORMAL);
            return;
        }
    }  
}

/**************** ���ý���2�Ӳ˵�����  �ָ���������*******************/
/*
******************************************************************
�������ƣ�void Display_SetMenu2_SubSetDefault(void)
�������ܣ����ò˵�2�Ӳ˵� �ָ���������
��ڲ�������
���ڲ�������
******************************************************************
*/    
void Display_SetMenu2_SubSetDefault(void)
{
    uint8_t *key;
    LCDClrWin(0,2,127,3);                                //������������
    LCD_String("ȷ�ϻָ���������",9,2,13,16,NORMAL);     //��ʾȷ�ϻָ����������ַ�
    LCD_ASCII("?",113,2,7,16,NORMAL);                    //��ʾ���ַ�
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        switch(*key)
        {
            case KEY_ENTER:
                Target_Init();                                       //�ָ��������ò���
                LCDClrWin(0,2,127,3);                                //������������
                LCD_String("�ѻָ���������",16,2,13,16,NORMAL);      //��ʾ�ѻָ����������ַ�
                LCD_ASCII("!",107,2,7,16,NORMAL);                    //��ʾ!�ַ�
                while(1)
                {
                    //��ʾ���
                    Display_Batter(Power_flag);
                    //��ʾ��Դ
                    Display_Power(Power_flag);
                    
                    key = OSMboxAccept(KEYMbox);
                    switch(*key)
                    {
                        case KEY_CAL:
                        case KEY_ENTER:
                            LCDClrWin(0,2,127,3);                                //������������
                            LCD_String("�ָ���������",37,2,13,16,NORMAL);   //��ʾ�ָ����������ַ� 
                            return;
                        default: break;
                    }
                }
            case KEY_CAL:
                LCDClrWin(0,2,127,3);   
                LCD_String("�ָ���������",37,2,13,16,NORMAL);   //��ʾ�ָ����������ַ� 
                return;
            default: break;
        }
        
    }
}

/****************************** �������� ��������******************************/

/*
********************************************************************************
�������ƣ�void Display_SamplingMenu(void)
�������ܣ���������˵���ʾ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_SamplingMenu(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
        LCD_String("����",50,0,13,16,MOVEUP);           //��ʾ�����ַ�
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //��ʾ1/1�����ַ�
        LCD_String("Ԥ������",37,2,13,16,NORMAL);       //��ʾԤ�������ַ�
        LCD_String("��ʱ����",37,4,13,16,NORMAL);       //��ʾ��ʱ�����ַ�
        LCD_String("��������",37,6,13,16,NORMAL);       //��ʾ���������ַ�
        
        flag1 = 1;
    }
    
    LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//�����һ������
        s_olderchoose = g_UserChoose;     
    }
}

/******************* �����ӽ��� Ԥ����������*****************/

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubPreset(void)
�������ܣ������ӽ��� Ԥ����������
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubPreset(void)
{
    float sampling_a = 0.0;
    float sampling_b = 0.0;
    uint8_t str[10];
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
        LCD_String("Ԥ������",38,0,13,16,MOVEUP);       //��ʾԤ�������ַ�
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //��ʾ1/1�����ַ�
    
        LCD_String("����",24,2,13,16,NORMAL);           //��ʾ�����ַ�
        LCD_ASCII("A",50,2,7,16,NORMAL);                //��ʾA�ַ�
        LCD_ASCII(":",57,2,7,16,NORMAL);                //��ʾ:�ַ�
        
        FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
        Float2Str(sampling_a,str,2);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            
        LCD_ASCII("L/min",92,2,7,16,NORMAL);            //��ʾ�¶�ֵ�ַ�
        
        LCD_String("����",24,4,13,16,NORMAL);           //��ʾ�����ַ�
        LCD_ASCII("B",50,4,7,16,NORMAL);                //��ʾB�ַ�
        LCD_ASCII(":",57,4,7,16,NORMAL);                //��ʾ:�ַ�
        
        FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
        Float2Str(sampling_b,str,2);
        LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
          
        LCD_ASCII("L/min",92,4,7,16,NORMAL);            //��ʾ��λֵ�ַ�
        
        LCD_String("��������",24,6,13,16,NORMAL);       //���������ַ�
        
        flag1 = 1;
    }
    
    LCD_ASCII("-->",1,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(1,2*(s_olderchoose+1),22,2*(s_olderchoose+1)+1);//�����һ������
        s_olderchoose = g_UserChoose;     
    }

}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubPreset_SAMPLING_A(void)
�������ܣ������ӽ��� Ԥ����������(����A����)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubPreset_SAMPLING_A(void)
{
    float sampling_a = 0.0;       //����A  
    int8_t sampling_a_hundred = 0; //�Ŵ�100����İ�λ
    int8_t sampling_a_ten = 0;     //�Ŵ�100�����ʮλ
    int8_t sampling_a_one = 0;     //�Ŵ�100����ĸ�λ
    float old_sampling_a = 0.0;   //�����ϵ�����ֵ
    uint8_t add = 1;
    uint8_t str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    old_sampling_a = sampling_a;
    sampling_a = sampling_a * 100;       //��С��λ�������
    sampling_a_hundred = ((int8_t)sampling_a / 100);   //ȡ��λ
    sampling_a_ten = ((int8_t)sampling_a / 10 % 10);   //ȡʮλ
    sampling_a_one = ((int8_t)sampling_a % 10);        //ȡ��λ
    
    //����λ���з���
    if(sampling_a_hundred == 0)              {LCD_ASCII("0",64,2,7,16,INVERSER);}
    else if(sampling_a_hundred == 1)         {LCD_ASCII("1",64,2,7,16,INVERSER);}

    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(add == 1)
            {
                sampling_a_hundred++;
                if(sampling_a_hundred == 2)
                {
                    sampling_a_hundred = 0;
                }
                if(sampling_a_hundred == 0)           {LCD_ASCII("0",64,2,7,16,INVERSER);}
                else if(sampling_a_hundred == 1)      {LCD_ASCII("1",64,2,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                sampling_a_ten++;
                if(sampling_a_ten == 10)
                {
                    sampling_a_ten = 0;
                }
                if(sampling_a_ten == 0)           {LCD_ASCII("0",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 1)      {LCD_ASCII("1",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 2)      {LCD_ASCII("2",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 3)      {LCD_ASCII("3",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 4)      {LCD_ASCII("4",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 5)      {LCD_ASCII("5",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 6)      {LCD_ASCII("6",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 7)      {LCD_ASCII("7",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 8)      {LCD_ASCII("8",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 9)      {LCD_ASCII("9",78,2,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                sampling_a_one++;
                if(sampling_a_one == 10)
                {
                    sampling_a_one = 0;
                }
                if(sampling_a_one == 0)           {LCD_ASCII("0",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 1)      {LCD_ASCII("1",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 2)      {LCD_ASCII("2",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 3)      {LCD_ASCII("3",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 4)      {LCD_ASCII("4",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 5)      {LCD_ASCII("5",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 6)      {LCD_ASCII("6",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 7)      {LCD_ASCII("7",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 8)      {LCD_ASCII("8",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 9)      {LCD_ASCII("9",85,2,7,16,INVERSER);}
            }
            
        }
        else if(*key == KEY_DOWN)
        {
            if(add == 1)
            {
                sampling_a_hundred--;
                if(sampling_a_hundred < 0)
                {
                    sampling_a_hundred = 1;
                }
                if(sampling_a_hundred == 0)           {LCD_ASCII("0",64,2,7,16,INVERSER);}
                else if(sampling_a_hundred == 1)      {LCD_ASCII("1",64,2,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                sampling_a_ten--;
                if(sampling_a_ten < 0)
                {
                    sampling_a_ten = 9;
                }
                if(sampling_a_ten == 0)           {LCD_ASCII("0",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 1)      {LCD_ASCII("1",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 2)      {LCD_ASCII("2",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 3)      {LCD_ASCII("3",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 4)      {LCD_ASCII("4",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 5)      {LCD_ASCII("5",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 6)      {LCD_ASCII("6",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 7)      {LCD_ASCII("7",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 8)      {LCD_ASCII("8",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 9)      {LCD_ASCII("9",78,2,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                sampling_a_one--;
                if(sampling_a_one < 0)
                {
                    sampling_a_one = 9;
                }
                if(sampling_a_one == 0)           {LCD_ASCII("0",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 1)      {LCD_ASCII("1",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 2)      {LCD_ASCII("2",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 3)      {LCD_ASCII("3",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 4)      {LCD_ASCII("4",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 5)      {LCD_ASCII("5",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 6)      {LCD_ASCII("6",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 7)      {LCD_ASCII("7",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 8)      {LCD_ASCII("8",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 9)      {LCD_ASCII("9",85,2,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_LEFT)
        {
            add--;
            if(add == 0)
            {
                add = 3;
            }
            if(add == 1)
            {   
                if(sampling_a_ten == 0)           {LCD_ASCII("0",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 1)      {LCD_ASCII("1",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 2)      {LCD_ASCII("2",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 3)      {LCD_ASCII("3",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 4)      {LCD_ASCII("4",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 5)      {LCD_ASCII("5",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 6)      {LCD_ASCII("6",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 7)      {LCD_ASCII("7",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 8)      {LCD_ASCII("8",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 9)      {LCD_ASCII("9",78,2,7,16,NORMAL);}
                
                if(sampling_a_hundred == 0)           {LCD_ASCII("0",64,2,7,16,INVERSER);}
                else if(sampling_a_hundred == 1)      {LCD_ASCII("1",64,2,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                if(sampling_a_ten == 0)           {LCD_ASCII("0",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 1)      {LCD_ASCII("1",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 2)      {LCD_ASCII("2",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 3)      {LCD_ASCII("3",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 4)      {LCD_ASCII("4",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 5)      {LCD_ASCII("5",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 6)      {LCD_ASCII("6",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 7)      {LCD_ASCII("7",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 8)      {LCD_ASCII("8",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 9)      {LCD_ASCII("9",78,2,7,16,INVERSER);}
                
                if(sampling_a_one == 0)           {LCD_ASCII("0",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 1)      {LCD_ASCII("1",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 2)      {LCD_ASCII("2",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 3)      {LCD_ASCII("3",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 4)      {LCD_ASCII("4",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 5)      {LCD_ASCII("5",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 6)      {LCD_ASCII("6",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 7)      {LCD_ASCII("7",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 8)      {LCD_ASCII("8",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 9)      {LCD_ASCII("9",85,2,7,16,NORMAL);}
            }
            else if(add == 3)
            {
                if(sampling_a_hundred == 0)           {LCD_ASCII("0",64,2,7,16,NORMAL);}
                else if(sampling_a_hundred == 1)      {LCD_ASCII("1",64,2,7,16,NORMAL);}
                
                if(sampling_a_one == 0)           {LCD_ASCII("0",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 1)      {LCD_ASCII("1",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 2)      {LCD_ASCII("2",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 3)      {LCD_ASCII("3",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 4)      {LCD_ASCII("4",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 5)      {LCD_ASCII("5",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 6)      {LCD_ASCII("6",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 7)      {LCD_ASCII("7",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 8)      {LCD_ASCII("8",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 9)      {LCD_ASCII("9",85,2,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_RIGHT)
        {
            add++;
            if(add == 4)
            {
                add = 1;
            }
            if(add == 1)
            {
                if(sampling_a_one == 0)           {LCD_ASCII("0",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 1)      {LCD_ASCII("1",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 2)      {LCD_ASCII("2",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 3)      {LCD_ASCII("3",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 4)      {LCD_ASCII("4",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 5)      {LCD_ASCII("5",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 6)      {LCD_ASCII("6",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 7)      {LCD_ASCII("7",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 8)      {LCD_ASCII("8",85,2,7,16,NORMAL);}
                else if(sampling_a_one == 9)      {LCD_ASCII("9",85,2,7,16,NORMAL);}
                
                if(sampling_a_hundred == 0)           {LCD_ASCII("0",64,2,7,16,INVERSER);}
                else if(sampling_a_hundred == 1)      {LCD_ASCII("1",64,2,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                if(sampling_a_hundred == 0)           {LCD_ASCII("0",64,2,7,16,NORMAL);}
                else if(sampling_a_hundred == 1)      {LCD_ASCII("1",64,2,7,16,NORMAL);}
                
                if(sampling_a_ten == 0)           {LCD_ASCII("0",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 1)      {LCD_ASCII("1",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 2)      {LCD_ASCII("2",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 3)      {LCD_ASCII("3",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 4)      {LCD_ASCII("4",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 5)      {LCD_ASCII("5",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 6)      {LCD_ASCII("6",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 7)      {LCD_ASCII("7",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 8)      {LCD_ASCII("8",78,2,7,16,INVERSER);}
                else if(sampling_a_ten == 9)      {LCD_ASCII("9",78,2,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                if(sampling_a_ten == 0)           {LCD_ASCII("0",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 1)      {LCD_ASCII("1",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 2)      {LCD_ASCII("2",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 3)      {LCD_ASCII("3",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 4)      {LCD_ASCII("4",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 5)      {LCD_ASCII("5",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 6)      {LCD_ASCII("6",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 7)      {LCD_ASCII("7",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 8)      {LCD_ASCII("8",78,2,7,16,NORMAL);}
                else if(sampling_a_ten == 9)      {LCD_ASCII("9",78,2,7,16,NORMAL);}
                
                if(sampling_a_one == 0)           {LCD_ASCII("0",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 1)      {LCD_ASCII("1",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 2)      {LCD_ASCII("2",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 3)      {LCD_ASCII("3",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 4)      {LCD_ASCII("4",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 5)      {LCD_ASCII("5",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 6)      {LCD_ASCII("6",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 7)      {LCD_ASCII("7",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 8)      {LCD_ASCII("8",85,2,7,16,INVERSER);}
                else if(sampling_a_one == 9)      {LCD_ASCII("9",85,2,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_ENTER)
        {
            sampling_a = ((float)sampling_a_hundred * 100 + (float)sampling_a_ten * 10 + (float)sampling_a_one) / 100;
            if(sampling_a > 1.00)
            {
                sampling_a = 1.0;
            }
            Float2Str(sampling_a,str,2);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            FM24C64_WRITE_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
            return;
        }
        else if(*key == KEY_CAL)
        {
            Float2Str(old_sampling_a,str,2);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            return;
        }
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubPreset_SAMPLING_B(void)
�������ܣ������ӽ��� Ԥ����������(����B����)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubPreset_SAMPLING_B(void)
{
    float sampling_b = 0.0;       //����B  
    int8_t sampling_b_hundred = 0; //�Ŵ�100����İ�λ
    int8_t sampling_b_ten = 0;     //�Ŵ�100�����ʮλ
    int8_t sampling_b_one = 0;     //�Ŵ�100����ĸ�λ
    float old_sampling_b = 0.0;   //�����ϵ�����ֵ
    uint8_t add = 1;
    uint8_t str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    old_sampling_b = sampling_b;
    sampling_b = sampling_b * 100;       //��С��λ�������
    sampling_b_hundred = ((int8_t)sampling_b / 100);   //ȡ��λ
    sampling_b_ten = ((int8_t)sampling_b / 10 % 10);   //ȡʮλ
    sampling_b_one = ((int8_t)sampling_b % 10);        //ȡ��λ
    
    //����λ���з���
    if(sampling_b_hundred == 0)              {LCD_ASCII("0",64,4,7,16,INVERSER);}
    else if(sampling_b_hundred == 1)         {LCD_ASCII("1",64,4,7,16,INVERSER);}

    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(add == 1)
            {
                sampling_b_hundred++;
                if(sampling_b_hundred == 2)
                {
                    sampling_b_hundred = 0;
                }
                if(sampling_b_hundred == 0)           {LCD_ASCII("0",64,4,7,16,INVERSER);}
                else if(sampling_b_hundred == 1)      {LCD_ASCII("1",64,4,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                sampling_b_ten++;
                if(sampling_b_ten == 10)
                {
                    sampling_b_ten = 0;
                }
                if(sampling_b_ten == 0)           {LCD_ASCII("0",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 1)      {LCD_ASCII("1",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 2)      {LCD_ASCII("2",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 3)      {LCD_ASCII("3",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 4)      {LCD_ASCII("4",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 5)      {LCD_ASCII("5",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 6)      {LCD_ASCII("6",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 7)      {LCD_ASCII("7",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 8)      {LCD_ASCII("8",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 9)      {LCD_ASCII("9",78,4,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                sampling_b_one++;
                if(sampling_b_one == 10)
                {
                    sampling_b_one = 0;
                }
                if(sampling_b_one == 0)           {LCD_ASCII("0",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 1)      {LCD_ASCII("1",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 2)      {LCD_ASCII("2",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 3)      {LCD_ASCII("3",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 4)      {LCD_ASCII("4",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 5)      {LCD_ASCII("5",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 6)      {LCD_ASCII("6",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 7)      {LCD_ASCII("7",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 8)      {LCD_ASCII("8",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 9)      {LCD_ASCII("9",85,4,7,16,INVERSER);}
            }
            
        }
        else if(*key == KEY_DOWN)
        {
            if(add == 1)
            {
                sampling_b_hundred--;
                if(sampling_b_hundred < 0)
                {
                    sampling_b_hundred = 1;
                }
                if(sampling_b_hundred == 0)           {LCD_ASCII("0",64,4,7,16,INVERSER);}
                else if(sampling_b_hundred == 1)      {LCD_ASCII("1",64,4,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                sampling_b_ten--;
                if(sampling_b_ten < 0)
                {
                    sampling_b_ten = 9;
                }
                if(sampling_b_ten == 0)           {LCD_ASCII("0",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 1)      {LCD_ASCII("1",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 2)      {LCD_ASCII("2",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 3)      {LCD_ASCII("3",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 4)      {LCD_ASCII("4",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 5)      {LCD_ASCII("5",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 6)      {LCD_ASCII("6",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 7)      {LCD_ASCII("7",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 8)      {LCD_ASCII("8",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 9)      {LCD_ASCII("9",78,4,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                sampling_b_one--;
                if(sampling_b_one < 0)
                {
                    sampling_b_one = 9;
                }
                if(sampling_b_one == 0)           {LCD_ASCII("0",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 1)      {LCD_ASCII("1",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 2)      {LCD_ASCII("2",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 3)      {LCD_ASCII("3",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 4)      {LCD_ASCII("4",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 5)      {LCD_ASCII("5",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 6)      {LCD_ASCII("6",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 7)      {LCD_ASCII("7",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 8)      {LCD_ASCII("8",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 9)      {LCD_ASCII("9",85,4,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_LEFT)
        {
            add--;
            if(add == 0)
            {
                add = 3;
            }
            if(add == 1)
            {   
                if(sampling_b_ten == 0)           {LCD_ASCII("0",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 1)      {LCD_ASCII("1",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 2)      {LCD_ASCII("2",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 3)      {LCD_ASCII("3",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 4)      {LCD_ASCII("4",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 5)      {LCD_ASCII("5",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 6)      {LCD_ASCII("6",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 7)      {LCD_ASCII("7",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 8)      {LCD_ASCII("8",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 9)      {LCD_ASCII("9",78,4,7,16,NORMAL);}
                
                if(sampling_b_hundred == 0)           {LCD_ASCII("0",64,4,7,16,INVERSER);}
                else if(sampling_b_hundred == 1)      {LCD_ASCII("1",64,4,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                if(sampling_b_ten == 0)           {LCD_ASCII("0",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 1)      {LCD_ASCII("1",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 2)      {LCD_ASCII("2",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 3)      {LCD_ASCII("3",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 4)      {LCD_ASCII("4",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 5)      {LCD_ASCII("5",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 6)      {LCD_ASCII("6",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 7)      {LCD_ASCII("7",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 8)      {LCD_ASCII("8",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 9)      {LCD_ASCII("9",78,4,7,16,INVERSER);}
                
                if(sampling_b_one == 0)           {LCD_ASCII("0",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 1)      {LCD_ASCII("1",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 2)      {LCD_ASCII("2",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 3)      {LCD_ASCII("3",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 4)      {LCD_ASCII("4",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 5)      {LCD_ASCII("5",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 6)      {LCD_ASCII("6",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 7)      {LCD_ASCII("7",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 8)      {LCD_ASCII("8",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 9)      {LCD_ASCII("9",85,4,7,16,NORMAL);}
            }
            else if(add == 3)
            {
                if(sampling_b_hundred == 0)           {LCD_ASCII("0",64,4,7,16,NORMAL);}
                else if(sampling_b_hundred == 1)      {LCD_ASCII("1",64,4,7,16,NORMAL);}
                
                if(sampling_b_one == 0)           {LCD_ASCII("0",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 1)      {LCD_ASCII("1",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 2)      {LCD_ASCII("2",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 3)      {LCD_ASCII("3",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 4)      {LCD_ASCII("4",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 5)      {LCD_ASCII("5",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 6)      {LCD_ASCII("6",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 7)      {LCD_ASCII("7",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 8)      {LCD_ASCII("8",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 9)      {LCD_ASCII("9",85,4,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_RIGHT)
        {
            add++;
            if(add == 4)
            {
                add = 1;
            }
            if(add == 1)
            {
                if(sampling_b_one == 0)           {LCD_ASCII("0",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 1)      {LCD_ASCII("1",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 2)      {LCD_ASCII("2",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 3)      {LCD_ASCII("3",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 4)      {LCD_ASCII("4",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 5)      {LCD_ASCII("5",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 6)      {LCD_ASCII("6",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 7)      {LCD_ASCII("7",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 8)      {LCD_ASCII("8",85,4,7,16,NORMAL);}
                else if(sampling_b_one == 9)      {LCD_ASCII("9",85,4,7,16,NORMAL);}
                
                if(sampling_b_hundred == 0)           {LCD_ASCII("0",64,4,7,16,INVERSER);}
                else if(sampling_b_hundred == 1)      {LCD_ASCII("1",64,4,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                if(sampling_b_hundred == 0)           {LCD_ASCII("0",64,4,7,16,NORMAL);}
                else if(sampling_b_hundred == 1)      {LCD_ASCII("1",64,4,7,16,NORMAL);}
                
                if(sampling_b_ten == 0)           {LCD_ASCII("0",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 1)      {LCD_ASCII("1",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 2)      {LCD_ASCII("2",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 3)      {LCD_ASCII("3",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 4)      {LCD_ASCII("4",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 5)      {LCD_ASCII("5",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 6)      {LCD_ASCII("6",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 7)      {LCD_ASCII("7",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 8)      {LCD_ASCII("8",78,4,7,16,INVERSER);}
                else if(sampling_b_ten == 9)      {LCD_ASCII("9",78,4,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                if(sampling_b_ten == 0)           {LCD_ASCII("0",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 1)      {LCD_ASCII("1",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 2)      {LCD_ASCII("2",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 3)      {LCD_ASCII("3",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 4)      {LCD_ASCII("4",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 5)      {LCD_ASCII("5",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 6)      {LCD_ASCII("6",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 7)      {LCD_ASCII("7",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 8)      {LCD_ASCII("8",78,4,7,16,NORMAL);}
                else if(sampling_b_ten == 9)      {LCD_ASCII("9",78,4,7,16,NORMAL);}
                
                if(sampling_b_one == 0)           {LCD_ASCII("0",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 1)      {LCD_ASCII("1",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 2)      {LCD_ASCII("2",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 3)      {LCD_ASCII("3",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 4)      {LCD_ASCII("4",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 5)      {LCD_ASCII("5",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 6)      {LCD_ASCII("6",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 7)      {LCD_ASCII("7",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 8)      {LCD_ASCII("8",85,4,7,16,INVERSER);}
                else if(sampling_b_one == 9)      {LCD_ASCII("9",85,4,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_ENTER)
        {
            sampling_b = ((float)sampling_b_hundred * 100 + (float)sampling_b_ten * 10 + (float)sampling_b_one) / 100;
            if(sampling_b > 1.00)
            {
                sampling_b = 1.0;
            }
            Float2Str(sampling_b,str,2);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            FM24C64_WRITE_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
            return;
        }
        else if(*key == KEY_CAL)
        {
            Float2Str(old_sampling_b,str,2);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            return;
        }
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubPreset_FLOW_START(void)
�������ܣ������ӽ��� Ԥ����������(��������)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubPreset_FLOW_START(void)
{
    uint8_t *key;
    float sampling_a = 0.0;
    float sampling_b = 0.0;
    
    LCDClrWin(24,6,127,7);                                //������������
    LCD_String("����������",24,6,13,16,NORMAL);          //��ʾ�����������ַ�
    LCD_ASCII("...",89,6,7,16,NORMAL);                   //��ʾ�������ַ�
            
    /******************************��ȡ�����������趨ֵ**************************************/
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    
    if(sampling_a <= 0.001)
    {
        MOTOR_A_OFF();                              //�ر�����A
    }
    else
    {
        MOTOR_A_ON();                               //������A
    }
    if(sampling_b <= 0.001)
    {
        MOTOR_B_OFF();                              //�ر�����B
    }
    else
    {
        MOTOR_B_ON();                               //������B
    }
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if((*key == KEY_ENTER) || (*key == KEY_CAL))
        {
            MOTOR_A_OFF();                                         //�ر�����A
            MOTOR_B_OFF();                                         //�ر�����B
            LCDClrWin(24,6,127,7); 
            LCD_String("��������",24,6,13,16,NORMAL);       //���������ַ�
            return;
        }
    }
}

/******************* �����ӽ��� ��ʱ��������*****************/

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubTiming1(void)
�������ܣ������ӽ��� ��ʱ��������1
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubTiming1(void)
{
    char str[10];
    uint8_t start_hour_a = 0;           //��ʼСʱʱ��
    uint8_t start_minute_a = 0;          //��ʼ����ʱ��
    uint8_t start_second_a = 0;          //��ʼ����ʱ��
    
    uint8_t start_hour_b = 0;           //��ʼСʱʱ��
    uint8_t start_minute_b = 0;          //��ʼ����ʱ��
    uint8_t start_second_b = 0;          //��ʼ����ʱ��
    
    uint8_t sampling_hour_a = 0;         //��������Сʱʱ��
    uint8_t sampling_minute_a = 0;       //�������÷���ʱ��
    uint8_t sampling_second_a = 0;       //������������ʱ��
    
    uint8_t sampling_hour_b = 0;         //��������Сʱʱ��
    uint8_t sampling_minute_b = 0;       //�������÷���ʱ��
    uint8_t sampling_second_b = 0;       //������������ʱ��
    
    if(g_UserChoose < 2)
    {
        //��ֹ����ˢ�ظ��Ľ���
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��ʱ����",38,0,13,16,MOVEUP);       //��ʾ��ʱ�����ַ�
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/1�����ַ�
        
            LCD_String("��ǰʱ��",8,2,13,16,NORMAL);        //��ʾ��ǰʱ���ַ�
            
            /*ͨ��A��ʼʱ��*/
            LCD_String("��ʼ",25,4,13,16,NORMAL);           //��ʾ��ʼ�ַ�
            LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
            //ʱ
            FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
            sprintf(str,"%02d:\0",(uint8_t)start_hour_a);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //��
            FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
            sprintf(str,"%02d:\0",(uint8_t)start_minute_a);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //��
            FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
            sprintf(str,"%02d\0", (uint8_t)start_second_a);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            /*ͨ��B��ʼʱ��*/
            LCD_String("��ʼ",25,6,13,16,NORMAL);           //��ʾ��ʼ�ַ�
            LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
            //ʱ
            FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
            sprintf(str,"%02d:\0",(uint8_t)start_hour_b);
            LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
            //��
            FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
            sprintf(str,"%02d:\0",(uint8_t)start_minute_b);
            LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
             //��
            FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
            sprintf(str,"%02d\0", (uint8_t)start_second_b);
            LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
            
            flag1 = 1;
            flag2 = 0;
        }
        //ʱ
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
        //��
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
        LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
         //��
        sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
        LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
        
        LCD_ASCII("-->",3,2*(g_UserChoose+2),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(3,2*(s_olderchoose+2),24,2*(s_olderchoose+2)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��ʱ����",38,0,13,16,MOVEUP);       //��ʾ��ʱ�����ַ�
            //�ڶ�ҳ
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            
            /*ͨ��A�ɼ�ʱ��*/
            LCD_String("��ʱ",25,2,13,16,NORMAL);           //��ʾ��ʱ�ַ�
            LCD_ASCII("A",51,2,7,16,NORMAL);                //��ʾA�ַ�
            //ʱ
            FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_hour_a);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //��
            FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_minute_a);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //��
            FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
            sprintf(str,"%02d\0", (uint8_t)sampling_second_a);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*ͨ��B�ɼ�ʱ��*/
            LCD_String("��ʱ",25,4,13,16,NORMAL);           //��ʾ��ʱ�ַ�
            LCD_ASCII("B",51,4,7,16,NORMAL);                //��ʾB�ַ�
            //ʱ
            FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_hour_b);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //��
            FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_minute_b);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //��
            FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
            sprintf(str,"%02d\0", (uint8_t)sampling_second_b);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            LCD_String("��������",25,6,13,16,NORMAL);       //���������ַ�
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",3,2*(g_UserChoose-1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 1)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(3,2*(s_olderchoose-1),24,2*(s_olderchoose-1)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubTiming1_START_A(void)
�������ܣ������ӽ��� ��ʱ��������1(ͨ��A��ʼʱ������)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_START_A(void)
{
    uint8_t start_hour_a = 0;         //��ʼСʱʱ��00
    uint8_t start_minute_a = 0;       //��ʼ����ʱ��00
    uint8_t start_second_a = 0;       //��ʼ����ʱ��00
    
    uint8_t old_start_hour_a = 0;         //��ʼСʱʱ��00
    uint8_t old_start_minute_a = 0;       //��ʼ����ʱ��00
    uint8_t old_start_second_a = 0;       //��ʼ����ʱ��00
     //ʱ����
    FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
    FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
    FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
    
    old_start_hour_a = start_hour_a;
    old_start_minute_a = start_minute_a;
    old_start_second_a = start_second_a;
    
    int8_t hour_ten = start_hour_a / 10;                    //���ʱ��ʮλ����
    int8_t hour_one = start_hour_a % 10;                    //���ʱ�ĸ�λ����
    int8_t minute_ten = start_minute_a / 10;                //��÷ֵ�ʮλ����
    int8_t minute_one = start_minute_a % 10;                //��÷ֵĸ�λ����
    int8_t second_ten = start_second_a / 10;                //������ʮλ����
    int8_t second_one = start_second_a % 10;                //�����ĸ�λ����

    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    hour_ten++;
                    if(hour_ten == 3)
                    {
                        hour_ten = 0;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one++;
                    if(hour_one == 10)
                    {
                        hour_one = 0;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten++;
                    if(minute_ten == 6)
                    {
                        minute_ten = 0;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one++;
                    if(minute_one == 10)
                    {
                        minute_one = 0;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten++;
                    if(second_ten == 6)
                    {
                        second_ten = 0;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one++;
                    if(second_one == 10)
                    {
                        second_one = 0;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    hour_ten--;
                    if(hour_ten < 0)
                    {
                        hour_ten = 2;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one--;
                    if(hour_one < 0)
                    {
                        hour_one = 9;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten--;
                    if(minute_ten < 0)
                    {
                        minute_ten = 5;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one--;
                    if(minute_one < 0)
                    {
                        minute_one = 9;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten--;
                    if(second_ten < 0)
                    {
                        second_ten = 5;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one--;
                    if(second_one < 0)
                    {
                        second_one = 9;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,NORMAL);}
                  
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,NORMAL);}
                  
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,NORMAL);}
                  
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,NORMAL);}
                  
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,NORMAL);}
                    
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,NORMAL);}
                    
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,NORMAL);}
                    
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,NORMAL);}
                    
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                start_hour_a = (hour_ten * 10 + hour_one);
                start_minute_a = (minute_ten * 10 + minute_one);
                start_second_a = (second_ten * 10 + second_one);
                
                if(start_hour_a >= 24)
                {
                    start_hour_a = 0;
                    start_minute_a = 0; 
                    start_second_a = 0;
                }
                
                FM24C64_WRITE_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
                FM24C64_WRITE_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
                FM24C64_WRITE_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
                
                sprintf(str,"%02d:\0", (uint8_t)start_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)start_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)start_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                sprintf(str,"%02d:\0", (uint8_t)old_start_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)old_start_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                
                sprintf(str,"%02d\0", (uint8_t)old_start_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                return; 
            }
        }
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubTiming1_START_B(void)
�������ܣ������ӽ��� ��ʱ��������1(ͨ��B��ʼʱ������)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_START_B(void)
{
    uint8_t start_hour_b = 0;         //��ʼСʱʱ��00
    uint8_t start_minute_b = 0;       //��ʼ����ʱ��00
    uint8_t start_second_b = 0;       //��ʼ����ʱ��00
    
    uint8_t old_start_hour_b = 0;         //��ʼСʱʱ��00
    uint8_t old_start_minute_b = 0;       //��ʼ����ʱ��00
    uint8_t old_start_second_b = 0;       //��ʼ����ʱ��00
     //ʱ����
    FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
    FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
    FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
    
    old_start_hour_b = start_hour_b;
    old_start_minute_b = start_minute_b;
    old_start_second_b = start_second_b;
    
    int8_t hour_ten = start_hour_b / 10;                    //���ʱ��ʮλ����
    int8_t hour_one = start_hour_b % 10;                    //���ʱ�ĸ�λ����
    int8_t minute_ten = start_minute_b / 10;                //��÷ֵ�ʮλ����
    int8_t minute_one = start_minute_b % 10;                //��÷ֵĸ�λ����
    int8_t second_ten = start_second_b / 10;                //������ʮλ����
    int8_t second_one = start_second_b % 10;                //�����ĸ�λ����

    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    hour_ten++;
                    if(hour_ten == 3)
                    {
                        hour_ten = 0;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one++;
                    if(hour_one == 10)
                    {
                        hour_one = 0;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten++;
                    if(minute_ten == 6)
                    {
                        minute_ten = 0;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one++;
                    if(minute_one == 10)
                    {
                        minute_one = 0;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten++;
                    if(second_ten == 6)
                    {
                        second_ten = 0;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one++;
                    if(second_one == 10)
                    {
                        second_one = 0;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    hour_ten--;
                    if(hour_ten < 0)
                    {
                        hour_ten = 2;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one--;
                    if(hour_one < 0)
                    {
                        hour_one = 9;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten--;
                    if(minute_ten < 0)
                    {
                        minute_ten = 5;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one--;
                    if(minute_one < 0)
                    {
                        minute_one = 9;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten--;
                    if(second_ten < 0)
                    {
                        second_ten = 5;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one--;
                    if(second_one < 0)
                    {
                        second_one = 9;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,NORMAL);}
                  
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,NORMAL);}
                  
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,NORMAL);}
                  
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,NORMAL);}
                  
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,NORMAL);}
                    
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,NORMAL);}
                    
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,NORMAL);}
                    
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,NORMAL);}
                    
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                start_hour_b = (hour_ten * 10 + hour_one);
                start_minute_b = (minute_ten * 10 + minute_one);
                start_second_b = (second_ten * 10 + second_one);
                
                if(start_hour_b >= 24)
                {
                    start_hour_b = 0;
                    start_minute_b = 0; 
                    start_second_b = 0;
                }
                
                FM24C64_WRITE_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
                FM24C64_WRITE_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
                FM24C64_WRITE_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
                
                sprintf(str,"%02d:\0", (uint8_t)start_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)start_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)start_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                sprintf(str,"%02d:\0", (uint8_t)old_start_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)old_start_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                
                sprintf(str,"%02d\0", (uint8_t)old_start_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                return; 
            }
        }
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubTiming1_SAMPLING_A(void)
�������ܣ������ӽ��� ��ʱ��������1(Aͨ���ɼ�ʱ������)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_SAMPLING_A(void)
{
    uint8_t sampling_hour_a = 0;         //��������Сʱʱ��00
    uint8_t sampling_minute_a = 0;       //�������÷���ʱ��00
    uint8_t sampling_second_a = 0;       //������������ʱ��00
    
    uint8_t old_sampling_hour_a = 0;         //��������Сʱʱ��00
    uint8_t old_sampling_minute_a = 0;       //�������÷���ʱ��00
    uint8_t old_sampling_second_a = 0;       //������������ʱ��00
     //ʱ����
    FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
    
    old_sampling_hour_a = sampling_hour_a;
    old_sampling_minute_a = sampling_minute_a;
    old_sampling_second_a = sampling_second_a;
    
    int8_t hour_ten = sampling_hour_a / 10;                    //���ʱ��ʮλ����
    int8_t hour_one = sampling_hour_a % 10;                    //���ʱ�ĸ�λ����
    int8_t minute_ten = sampling_minute_a / 10;                //��÷ֵ�ʮλ����
    int8_t minute_one = sampling_minute_a % 10;                //��÷ֵĸ�λ����
    int8_t second_ten = sampling_second_a / 10;                //������ʮλ����
    int8_t second_one = sampling_second_a % 10;                //�����ĸ�λ����
    
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    if(hour_ten == 0)          {LCD_ASCII("0",64,2,7,16,INVERSER);}
    else if(hour_ten == 1)     {LCD_ASCII("1",64,2,7,16,INVERSER);}
    else if(hour_ten == 2)     {LCD_ASCII("2",64,2,7,16,INVERSER);}
    else if(hour_ten == 3)     {LCD_ASCII("3",64,2,7,16,INVERSER);}
    else if(hour_ten == 4)     {LCD_ASCII("4",64,2,7,16,INVERSER);}
    else if(hour_ten == 5)     {LCD_ASCII("5",64,2,7,16,INVERSER);}
    else if(hour_ten == 6)     {LCD_ASCII("6",64,2,7,16,INVERSER);}
    else if(hour_ten == 7)     {LCD_ASCII("7",64,2,7,16,INVERSER);}
    else if(hour_ten == 8)     {LCD_ASCII("8",64,2,7,16,INVERSER);}
    else if(hour_ten == 9)     {LCD_ASCII("9",64,2,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    hour_ten++;
                    if(hour_ten == 10)
                    {
                        hour_ten = 0;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,2,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,2,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,2,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,2,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,2,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,2,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,2,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,2,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,2,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one++;
                    if(hour_one == 10)
                    {
                        hour_one = 0;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,2,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,2,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,2,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,2,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,2,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,2,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,2,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,2,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,2,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten++;
                    if(minute_ten == 6)
                    {
                        minute_ten = 0;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,2,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,2,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,2,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,2,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,2,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,2,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,2,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,2,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,2,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one++;
                    if(minute_one == 10)
                    {
                        minute_one = 0;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,2,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,2,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,2,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,2,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,2,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,2,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,2,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,2,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,2,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten++;
                    if(second_ten == 6)
                    {
                        second_ten = 0;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,2,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,2,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,2,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,2,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,2,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,2,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,2,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,2,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,2,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one++;
                    if(second_one == 10)
                    {
                        second_one = 0;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,2,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,2,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,2,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,2,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,2,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,2,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,2,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,2,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,2,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,2,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    hour_ten--;
                    if(hour_ten < 0)
                    {
                        hour_ten = 9;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,2,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,2,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,2,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,2,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,2,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,2,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,2,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,2,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,2,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one--;
                    if(hour_one < 0)
                    {
                        hour_one = 9;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,2,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,2,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,2,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,2,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,2,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,2,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,2,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,2,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,2,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten--;
                    if(minute_ten < 0)
                    {
                        minute_ten = 5;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,2,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,2,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,2,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,2,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,2,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,2,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,2,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,2,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,2,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one--;
                    if(minute_one < 0)
                    {
                        minute_one = 9;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,2,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,2,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,2,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,2,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,2,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,2,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,2,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,2,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,2,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten--;
                    if(second_ten < 0)
                    {
                        second_ten = 5;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,2,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,2,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,2,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,2,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,2,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,2,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,2,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,2,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,2,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one--;
                    if(second_one < 0)
                    {
                        second_one = 9;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,2,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,2,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,2,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,2,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,2,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,2,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,2,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,2,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,2,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,2,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,2,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,2,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,2,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,2,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,2,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,2,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,2,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,2,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,2,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,2,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,2,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,2,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,2,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,2,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,2,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,2,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,2,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,2,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,2,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,2,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,2,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,2,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,2,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,2,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,2,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,2,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,2,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,2,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,2,7,16,NORMAL);}
                  
                    if(hour_one == 0)          {LCD_ASCII("0",71,2,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,2,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,2,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,2,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,2,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,2,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,2,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,2,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,2,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,2,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,2,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,2,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,2,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,2,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,2,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,2,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,2,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,2,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,2,7,16,NORMAL);}
                  
                    if(minute_ten == 0)          {LCD_ASCII("0",85,2,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,2,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,2,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,2,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,2,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,2,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,2,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,2,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,2,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,2,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,2,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,2,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,2,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,2,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,2,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,2,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,2,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,2,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,2,7,16,NORMAL);}
                  
                    if(minute_one == 0)          {LCD_ASCII("0",92,2,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,2,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,2,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,2,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,2,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,2,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,2,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,2,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,2,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,2,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,2,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,2,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,2,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,2,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,2,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,2,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,2,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,2,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,2,7,16,NORMAL);}
                  
                    if(second_ten == 0)          {LCD_ASCII("0",106,2,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,2,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,2,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,2,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,2,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,2,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,2,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,2,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,2,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,2,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,2,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,2,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,2,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,2,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,2,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,2,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,2,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,2,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,2,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,2,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,2,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,2,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,2,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,2,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,2,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,2,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,2,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,2,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,2,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,2,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,2,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,2,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,2,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,2,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,2,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,2,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,2,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,2,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,2,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,2,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,2,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,2,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,2,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,2,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,2,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,2,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,2,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,2,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,2,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,2,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,2,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,2,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,2,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,2,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,2,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,2,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,2,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,2,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,2,7,16,NORMAL);}
                    
                    if(hour_one == 0)          {LCD_ASCII("0",71,2,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,2,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,2,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,2,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,2,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,2,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,2,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,2,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,2,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,2,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,2,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,2,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,2,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,2,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,2,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,2,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,2,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,2,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,2,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,2,7,16,NORMAL);}
                    
                    if(minute_ten == 0)          {LCD_ASCII("0",85,2,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,2,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,2,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,2,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,2,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,2,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,2,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,2,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,2,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,2,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,2,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,2,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,2,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,2,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,2,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,2,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,2,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,2,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,2,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,2,7,16,NORMAL);}
                    
                    if(minute_one == 0)          {LCD_ASCII("0",92,2,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,2,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,2,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,2,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,2,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,2,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,2,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,2,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,2,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,2,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,2,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,2,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,2,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,2,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,2,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,2,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,2,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,2,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,2,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,2,7,16,NORMAL);}
                    
                    if(second_ten == 0)          {LCD_ASCII("0",106,2,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,2,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,2,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,2,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,2,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,2,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,2,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,2,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,2,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,2,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,2,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,2,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,2,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,2,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,2,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,2,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,2,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,2,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,2,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,2,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,2,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,2,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,2,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,2,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,2,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,2,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,2,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,2,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,2,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,2,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                sampling_hour_a = (hour_ten * 10 + hour_one);
                sampling_minute_a = (minute_ten * 10 + minute_one);
                sampling_second_a = (second_ten * 10 + second_one);
                
                FM24C64_WRITE_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
                FM24C64_WRITE_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
                FM24C64_WRITE_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
                
                sprintf(str,"%02d:\0", (uint8_t)sampling_hour_a);
                LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)sampling_minute_a);
                LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)sampling_second_a);
                LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                sprintf(str,"%02d:\0", (uint8_t)old_sampling_hour_a);
                LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);

                sprintf(str,"%02d:\0", (uint8_t)old_sampling_minute_a);
                LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)old_sampling_second_a);
                LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                return; 
            }
        }
    } 
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubTiming1_SAMPLING_B(void)
�������ܣ������ӽ��� ��ʱ��������1(Bͨ���ɼ�ʱ������)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_SAMPLING_B(void)
{
    uint8_t sampling_hour_b = 0;         //��������Сʱʱ��00
    uint8_t sampling_minute_b = 0;       //�������÷���ʱ��00
    uint8_t sampling_second_b = 0;       //������������ʱ��00
    
    uint8_t old_sampling_hour_b = 0;         //��������Сʱʱ��00
    uint8_t old_sampling_minute_b = 0;       //�������÷���ʱ��00
    uint8_t old_sampling_second_b = 0;       //������������ʱ��00
     //ʱ����
    FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
    
    old_sampling_hour_b = sampling_hour_b;
    old_sampling_minute_b = sampling_minute_b;
    old_sampling_second_b = sampling_second_b;
    
    int8_t hour_ten = sampling_hour_b / 10;                    //���ʱ��ʮλ����
    int8_t hour_one = sampling_hour_b % 10;                    //���ʱ�ĸ�λ����
    int8_t minute_ten = sampling_minute_b / 10;                //��÷ֵ�ʮλ����
    int8_t minute_one = sampling_minute_b % 10;                //��÷ֵĸ�λ����
    int8_t second_ten = sampling_second_b / 10;                //������ʮλ����
    int8_t second_one = sampling_second_b % 10;                //�����ĸ�λ����
    
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    hour_ten++;
                    if(hour_ten == 10)
                    {
                        hour_ten = 0;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one++;
                    if(hour_one == 10)
                    {
                        hour_one = 0;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten++;
                    if(minute_ten == 6)
                    {
                        minute_ten = 0;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one++;
                    if(minute_one == 10)
                    {
                        minute_one = 0;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten++;
                    if(second_ten == 6)
                    {
                        second_ten = 0;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one++;
                    if(second_one == 10)
                    {
                        second_one = 0;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    hour_ten--;
                    if(hour_ten < 0)
                    {
                        hour_ten = 9;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one--;
                    if(hour_one < 0)
                    {
                        hour_one = 9;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten--;
                    if(minute_ten < 0)
                    {
                        minute_ten = 5;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one--;
                    if(minute_one < 0)
                    {
                        minute_one = 9;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten--;
                    if(second_ten < 0)
                    {
                        second_ten = 5;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one--;
                    if(second_one < 0)
                    {
                        second_one = 9;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,NORMAL);}
                  
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,NORMAL);}
                  
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,NORMAL);}
                  
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,NORMAL);}
                  
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,NORMAL);}
                    
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,NORMAL);}
                    
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,NORMAL);}
                    
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,NORMAL);}
                    
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                sampling_hour_b = (hour_ten * 10 + hour_one);
                sampling_minute_b = (minute_ten * 10 + minute_one);
                sampling_second_b = (second_ten * 10 + second_one);
                
                FM24C64_WRITE_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
                FM24C64_WRITE_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
                FM24C64_WRITE_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
                
                sprintf(str,"%02d:\0", (uint8_t)sampling_hour_b);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)sampling_minute_b);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)sampling_second_b);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                sprintf(str,"%02d:\0", (uint8_t)old_sampling_hour_b);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);

                sprintf(str,"%02d:\0", (uint8_t)old_sampling_minute_b);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)old_sampling_second_b);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                return; 
            }
        }
    } 
}

/********** �����ӽ��� ��ʱ�������ӽ��� �ȴ���������*********/

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubTiming_SubWait(void)
�������ܣ������ӽ��� ��ʱ�������ӽ��� �ȴ���������
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubTiming_SubWait(void)
{
    char str[10];
    
    uint8_t start_hour = 0;              //��ʼСʱʱ��
    uint8_t start_minute = 0;            //��ʼ����ʱ��
    uint8_t start_second = 0;            //��ʼ����ʱ��
    
    uint8_t start_hour_a = 0;            //��ʼaСʱʱ��
    uint8_t start_minute_a = 0;          //��ʼa����ʱ��
    uint8_t start_second_a = 0;          //��ʼa����ʱ��
    
    uint8_t start_hour_b = 0;            //��ʼbСʱʱ��
    uint8_t start_minute_b = 0;          //��ʼb����ʱ��
    uint8_t start_second_b = 0;          //��ʼb����ʱ��
    
    uint8_t sampling_hour_a = 0;
    uint8_t sampling_minute_a = 0;
    uint8_t sampling_second_a = 0;
    
    uint8_t sampling_hour_b = 0;
    uint8_t sampling_minute_b = 0;
    uint8_t sampling_second_b = 0;
    
    uint8_t *key;
    
    LCDClrWin(0,2,127,7);                               //��ȫ��
    LCD_String("�ȴ�����ʱ��",0,0,13,16,MOVEUP);    //��ʾ�ȴ�����ʱ���ַ�
    LCD_ASCII("...",78,0,7,16,MOVEUP);              //��ʾ�������ַ�
    
    LCD_String("��ǰʱ��",8,2,13,16,NORMAL);           //��ʾ��ǰ�ַ�
    
    LCD_String("��ʼ",25,4,13,16,NORMAL);           //��ʾ�趨�ַ�
    LCD_ASCII("A",51,4,7,16,NORMAL);              //��ʾA�ַ�
    
    LCD_String("��ʼ",25,6,13,16,NORMAL);           //��ʾ�趨�ַ�
    LCD_ASCII("B",51,6,7,16,NORMAL);              //��ʾA�ַ�
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_CAL)
        {
            flag2 = 0;                             //�ָ���ǰ�Ľ���
            return;
        }
        
        /********************��ǰʱ��********************/
        //ʱ
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
        //��
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
        LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
         //��
        sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
        LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
        
        /********************��ʼʱ��********************/
        
        //ͨ��A��ʼʱ��
        //ʱ
        FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
        sprintf(str,"%02d:\0",(uint8_t)start_hour_a);
        LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
        //��
        FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
        sprintf(str,"%02d:\0",(uint8_t)start_minute_a);
        LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
         //��
        FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
        sprintf(str,"%02d\0", (uint8_t)start_second_a);
        LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
        
        //ͨ��B��ʼʱ��
        FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
        sprintf(str,"%02d:\0",(uint8_t)start_hour_b);
        LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
        //��
        FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
        sprintf(str,"%02d:\0",(uint8_t)start_minute_b);
        LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
         //��
        FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
        sprintf(str,"%02d\0", (uint8_t)start_second_b);
        LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
        
        start_hour = g_RTCTime.hour;
        start_minute = g_RTCTime.minute;
        start_second = g_RTCTime.second;
        
        /******************************��ȡ��ʱ����A���趨ʱ��**************************************/
        FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
        FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
        FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
        
        /******************************��ȡ��ʱ����B���趨ʱ��**************************************/
        FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
        FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
        FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
        
        
        /*�ж϶�ʱ��ʹ�ܵ�����*/
        if(((sampling_hour_a*3600 + sampling_minute_a*60 + sampling_second_a) == 0) || ((start_hour_a*3600 + start_minute_a*60 + start_second_a) < (start_hour*3600 + start_minute*60 + start_second)))
        {
            g_TimeEnableDisable_A = 0;                      //ͨ��Aʹ�ܲ�����׼
        }
        else
        {
            g_TimeEnableDisable_A = 1;                      //ͨ��Aʹ�ܲ�����׼
        }
        if(((sampling_hour_b*3600 + sampling_minute_b*60 + sampling_second_b) == 0) || ((start_hour_b*3600 + start_minute_b*60 + start_second_b) < (start_hour*3600 + start_minute*60 + start_second)))
        {
            g_TimeEnableDisable_B = 0;                      //ͨ��Bʹ�ܲ�����׼
        }
        else
        {
            g_TimeEnableDisable_B = 1;                      //ͨ��Bʹ�ܲ�����׼
        }

        //���ͨ��A��ʱ����ʱ���Ƿ��ѵ�
        if((start_hour == start_hour_a) && (start_minute == start_minute_a) && (start_second == start_second_a))
        {
            g_TimeFlag_A = 1;
        }
        else
        {
            g_TimeFlag_A = 0;
        }
        
        //���ͨ��B��ʱ����ʱ���Ƿ��ѵ�
        if((start_hour == start_hour_b) && (start_minute == start_minute_b) && (start_second == start_second_b))
        {
            g_TimeFlag_B = 1;
        }
        else
        {
            g_TimeFlag_B = 0;
        }
        /********************ʱ�����ʱ,������������н���********************/
        if(g_TimeFlag_A || g_TimeFlag_B)
        {
            Display_SamplingMenu_SubTiming_SubWait_SubUnderWay();
            return;
        }  
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubTiming_SubWait(void)
�������ܣ������ӽ��� ��ʱ�������ӽ��� (��ʱ���������С�����)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubTiming_SubWait_SubUnderWay(void)
{
    int8_t add_new = 1;
    int8_t add_old = 1;
    int8_t judge_new = 1;
    int8_t judge_old = 1;
    int8_t judge_new1 = 1;
    int8_t judge_old1 = 1;
    uint8_t storage_number = 0;
    uint8_t ad = 0;
    uint8_t ad1 = 0;
    uint8_t fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
    uint8_t fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
    uint8_t fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
    uint8_t fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
    uint8_t fla5 = 0;                                          //Ϊ������ʾ��ʼ����־4
    uint8_t *key;
    uint8_t tab1[10];
    uint8_t tab2[10];
    uint8_t tab3[10];
    uint8_t tab4[10];
    char str[10];
    uint8_t str1[10];
    
    uint8_t start_hour = 0;             //�ȴ�����ʱ�̣���������ʱ��
    uint8_t start_minute = 0;
    uint8_t start_second = 0;
        
    uint8_t sampling_hour_a = 0;
    uint8_t sampling_minute_a = 0;
    uint8_t sampling_second_a = 0;
    
    uint8_t sampling_hour_b = 0;
    uint8_t sampling_minute_b = 0;
    uint8_t sampling_second_b = 0;
    
    uint8_t start_hour_a = 0;            //��ʼaСʱʱ��
    uint8_t start_minute_a = 0;          //��ʼa����ʱ��
    uint8_t start_second_a = 0;          //��ʼa����ʱ��
    
    uint8_t start_hour_b = 0;            //��ʼbСʱʱ��
    uint8_t start_minute_b = 0;          //��ʼb����ʱ��
    uint8_t start_second_b = 0;          //��ʼb����ʱ��
    
    uint8_t timer_hour_a = 0;
    uint8_t timer_minute_a = 0;
    uint8_t timer_second_a = 0;
    
    uint8_t timer_hour_b = 0;
    uint8_t timer_minute_b = 0;
    uint8_t timer_second_b = 0;
    
    float sampling_a = 0.0;
    float sampling_b = 0.0;
    
    /*********************************��ȡͨ��A����ʼʱ��**************************************/  
    FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
    FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
    FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
    
    /*********************************��ȡͨ��B����ʼʱ��**************************************/  
    FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
    FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
    FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
    
    /******************************��ȡ��ʱ����A���趨ʱ��**************************************/
    FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
    
    /******************************��ȡ��ʱ����B���趨ʱ��**************************************/
    FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
    
    /******************************��ȡ�����������趨ֵ**************************************/
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    
    /*********************************��ʾ��ʼ�ĵ�һ����**************************************/
    LCDClrWin(0,0,127,7);                           //��ȫ��
    LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
    LCD_String("������",0,0,13,16,MOVEUP);          //��ʾ�������ַ�
    LCD_ASCII("...",39,0,7,16,MOVEUP);              //��ʾ�������ַ�
    LCD_ASCII("1/5",70,0,7,16,MOVEUP);              //��ʾ1/4�����ַ�
    
    
    /***************ͨ�������ж��ĸ�ͨ���رջ��*******************/
    if(sampling_a <= 0.001)
    {
        MOTOR_A_OFF();                              //�ر�����A
    }
    else
    {
        if(g_TimeFlag_A == 0)
        {
            MOTOR_A_OFF();                           //�ر�����A
        }
        else
        {
            MOTOR_A_ON();                            //������A
        }
    }
    if(sampling_b <= 0.001)
    {
        MOTOR_B_OFF();                               //�ر�����B
    }
    else
    {
        if(g_TimeFlag_B == 0)
        {
            MOTOR_B_OFF();                           //�ر�����A
        }
        else
        {
            MOTOR_B_ON();                            //������A
        }
    }
//    TIM_Cmd(TIM2, ENABLE);	                     //������ʱ��2
    PCF8563_TIE_EnableDisable(1);           //PCF8563��ʱ��ʹ��
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        /*************************************����������ʾ����**************************************/
        if((g_Power.pc0_adc10_battery <= 10.4) && (Power_flag == 0))
        {
            uint8_t i = 0;
            /*�رղ��������úͶ�ʱ��*/
            MOTOR_A_OFF();                                  //�ر�����A
            MOTOR_B_OFF();                                  //�ر�����B
//            TIM_Cmd(TIM2, DISABLE);	                    //�رն�ʱ��2
            PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //���涨ʱ��״̬
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //���涨ʱ��״̬
            
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //��ʱ��ʹ�ܻ�ʧ��
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //��ʱ��ʹ�ܻ�ʧ��
            
            g_TimeEnableDisable_A = 0;
            g_TimeEnableDisable_B = 0;
            
            g_TimeFlag_A = 0;                               //�ر�ͨ��Aʱ�����
            g_TimeFlag_B = 0;                               //�ر�ͨ��Bʱ�����
            
            /*��ʾ�ȴ��������*/
            LCDClrWin(0,0,127,7);                           //����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            
            //��ʾ���
            Display_Batter(Power_flag);
            //��ʾ��Դ
            Display_Power(Power_flag);
            
            LCD_String("�ȴ�����",0,0,13,16,MOVEUP);        //��ʾ�ȴ������ַ�
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //��ʾ�������ַ�
        
            LCD_String("��������",34,2,13,16,NORMAL);       //��ʾ���������ַ�
            LCD_ASCII(",",86,2,7,16,NORMAL);                //��ʾ,�ַ�
            LCD_String("��ֹͣ����",34,4,13,16,NORMAL);     //��ʾ��ֹͣ�����ַ�
            LCD_ASCII("!",99,4,7,16,NORMAL);                //��ʾ���ַ�
            
            /*�������������ʾ*/
            for(i = 0; i < 7; i++)
            {
                BEEP_ON();
                OSTimeDly(10);
                BEEP_OFF();
                OSTimeDly(10);
            }
            while(1)
            {
                //��ʾ���
                Display_Batter(Power_flag);
                //��ʾ��Դ
                Display_Power(Power_flag);
                
                /*************************************��ȡ���������Ƿ��л�**************************************/
                key = OSMboxAccept(KEYMbox);
                if((*key == KEY_ENTER) || (*key == KEY_CAL))
                {
                    flag2 = 0;                                      //����ˢ�����־
                    
                    FM24C64_WRITE_BYTE(UNFINISHED_FLAG,2);          //д��δ��ɱ�־��Ϊ��ʱ����
                    /*����ͨ��A�ĵ�ǰʱ��*/
                    FM24C64_WRITE_BYTE(TIMER_HOUR_A,Timer_hour_A);      //д�������Сʱֵ
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_A,Timer_minute_A);  //д������ķ���ֵ
                    FM24C64_WRITE_BYTE(TIMER_SECOND_A,Timer_second_A);  //д�����������ֵ
                    /*����ͨ��B�ĵ�ǰʱ��*/
                    FM24C64_WRITE_BYTE(TIMER_HOUR_B,Timer_hour_B);      //д�������Сʱֵ
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_B,Timer_minute_B);  //д������ķ���ֵ
                    FM24C64_WRITE_BYTE(TIMER_SECOND_B,Timer_second_B);  //д�����������ֵ
                    /*************************************�Ѽ���ֵ����***********************************************/
                    Timer_hour_A = 0;
                    Timer_minute_A = 0;
                    Timer_second_A = 0;
                    
                    Timer_hour_B = 0;
                    Timer_minute_B = 0;
                    Timer_second_B = 0;
                    g_t_count = 0;                                //��ʱ����ֵ����
                    return;
                }
                /*���½����˵�ѹ��Ӧ*/
                if((g_Power.pc0_adc10_battery > 11) || (Power_flag == 1))
                {
                    /*********************************�ָ������С���������**************************************/
                    LCDClrWin(0,0,127,7);                           //��ȫ��
                    LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                    LCD_String("������",0,0,13,16,MOVEUP);          //��ʾ�������ַ�
                    LCD_ASCII("...",39,0,7,16,MOVEUP);              //��ʾ�������ַ�
                    //���ص�һ����
                    fla1 = 0;
                    add_new = 1;                                   //�ָ���ʼ״̬
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //�ָ���ʱ��״̬
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //�ָ���ʱ��״̬
                    
                    //�жϲ���״̬
                    if(sampling_a <= 0.001)
                    {
                        MOTOR_A_OFF();                              //�ر�����A
                    }
                    else
                    {
                        if(g_TimeFlag_A == 0)
                        {
                            MOTOR_A_OFF();                              //�ر�����A
                        }
                        else
                        {
                            MOTOR_A_ON();                               //������A
                        }
                    }
                    if(sampling_b <= 0.001)
                    {
                        MOTOR_B_OFF();                              //�ر�����B
                    }
                    else
                    {
                        if(g_TimeFlag_B == 0)
                        {
                            MOTOR_B_OFF();                              //�ر�����A
                        }
                        else
                        {
                            MOTOR_B_ON();                               //������A
                        }
                    }
//                    TIM_Cmd(TIM2, ENABLE);	                   //�򿪶�ʱ��2
                    PCF8563_TIE_EnableDisable(1);           //PCF8563��ʱ��ʹ��
                    g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //��ʱ��ʹ�ܻ�ʧ��
                    g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //��ʱ��ʹ�ܻ�ʧ��
                    break;
                }
            }
        }
        /*��ֵ���м���*/
        timer_hour_a = Timer_hour_A;
        timer_minute_a = Timer_minute_A;
        timer_second_a = Timer_second_A;
        
        timer_hour_b = Timer_hour_B;
        timer_minute_b = Timer_minute_B;
        timer_second_b = Timer_second_B;
        /******************************����������**************************************/
        if(((sampling_hour_a*3600 + sampling_minute_a*60 + sampling_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) >= 1) && ((sampling_hour_a*3600 + sampling_minute_a*60 + sampling_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) <= 3)
           || ((sampling_hour_b*3600 + sampling_minute_b*60 + sampling_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) >= 1) && ((sampling_hour_b*3600 + sampling_minute_b*60 + sampling_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) <= 3))
        {
            BEEP_ON();
            OSTimeDly(10);
            BEEP_OFF();
            OSTimeDly(10);
        }
        
        /******************************ͨ��Aͨ��B�Ƿ񶼲������ȴ�����ʱ��**************************************/
        start_hour = g_RTCTime.hour;
        start_minute = g_RTCTime.minute;
        start_second = g_RTCTime.second;
        
        //���ͨ��A��ʱ����ʱ���Ƿ��ѵ�
        if(((start_hour == start_hour_a) && (start_minute == start_minute_a) && (start_second == start_second_a) && (g_TimeFlag_A == 0) && (g_TimeEnableDisable_A == 1))
           || (((start_hour_a*3600 + start_minute_a*60 + start_second_a) < (start_hour*3600 + start_minute*60 + start_second)) && (g_TimeFlag_A == 0) && (g_TimeEnableDisable_A == 1)))
        {
            g_TimeFlag_A = 1;
            MOTOR_A_ON();                                  //�ر�����B
        }
        
        //���ͨ��B��ʱ����ʱ���Ƿ��ѵ�
        if(((start_hour == start_hour_b) && (start_minute == start_minute_b) && (start_second == start_second_b) && (g_TimeFlag_B == 0) && (g_TimeEnableDisable_B == 1))
          || (((start_hour_b*3600 + start_minute_b*60 + start_second_b) < (start_hour*3600 + start_minute*60 + start_second)) && (g_TimeFlag_B == 0) && (g_TimeEnableDisable_B == 1)))
        {
            g_TimeFlag_B = 1;
            MOTOR_B_ON();                                  //�ر�����B
        }
        
        /******************************ͨ��A��ȡʱ���Ƿ���趨ֵ���**************************************/
        if((Timer_hour_A == sampling_hour_a) && (Timer_minute_A == sampling_minute_a) && (Timer_second_A >= sampling_second_a))
        {
            BEEP_OFF();
            MOTOR_A_OFF();                                  //�ر�����A
            g_TimeFlag_A = 0;                               //ͨ��A���
            g_TimeEnableDisable_A = 0;                      //ͨ��Aʧ�ܲ�����׼
        }
        
        /******************************ͨ��B��ȡʱ���Ƿ���趨ֵ���**************************************/
        if((Timer_hour_B == sampling_hour_b) && (Timer_minute_B == sampling_minute_b) && (Timer_second_B >= sampling_second_b))
        {
            BEEP_OFF();
            MOTOR_B_OFF();                                  //�ر�����B
            g_TimeFlag_B = 0;                               //ͨ��B���
            g_TimeEnableDisable_B = 0;                      //ͨ��Bʧ�ܲ�����׼  
        }
        
        /******************************ͨ��A��ͨ��B���������**************************************/
        if((g_TimeFlag_A == 0) && (g_TimeFlag_B == 0) && (g_TimeEnableDisable_A == 0) && (g_TimeEnableDisable_B == 0))
        {      
//            TIM_Cmd(TIM2, DISABLE);	                    //�رն�ʱ��2
            PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
            FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //д����ɱ�־
            
            /*************************************��ֵ����***********************************************/
            timer_hour_a = Timer_hour_A;
            timer_minute_a = Timer_minute_A;
            timer_second_a = Timer_second_A;
            
            timer_hour_b = Timer_hour_B;
            timer_minute_b = Timer_minute_B;
            timer_second_b = Timer_second_B;
            
            /*************************************�Ѽ���ֵ����***********************************************/
            Timer_hour_A = 0;
            Timer_minute_A = 0;
            Timer_second_A = 0;
            
            Timer_hour_B = 0;
            Timer_minute_B = 0;
            Timer_second_B = 0;
            
            g_t_count = 0;
            
            /*************************************�����б�־Ҳ����***********************************************/
            g_TimeEnableDisable_A = 0;
            g_TimeEnableDisable_B = 0;
            
            g_TimeFlag_A = 0;                               //�ر�ͨ��Aʱ�����
            g_TimeFlag_B = 0;                               //�ر�ͨ��Bʱ�����
            
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //���涨ʱ��״̬
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //���涨ʱ��״̬
            
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //��ʱ��ʹ�ܻ�ʧ��
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //��ʱ��ʹ�ܻ�ʧ��
            
            
            LCDClrWin(0,0,127,7);                           //��ȫ��
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("�������",0,0,13,16,MOVEUP);        //��ʾ��������ַ�
            LCD_ASCII("!",52,0,7,16,MOVEUP);                //��ʾ!�ַ�
            
            
            LCD_String("�Ƿ񱣴��������",8,2,13,16,NORMAL);//��ʾ������������ַ�
            LCD_ASCII("?",112,2,7,16,NORMAL);                //��ʾ?�ַ�
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);              //��ʾ(1)����
            LCD_String("��",58,4,13,16,NORMAL);             //��ʾ���ַ�
            LCD_ASCII("(2)",37,6,7,16,NORMAL);              //��ʾ(2)����
            LCD_String("��",58,6,13,16,NORMAL);             //��ʾ���ַ�
            
            while(1)
            {
                //��ʾ���
                Display_Batter(Power_flag);
                //��ʾ��Դ
                Display_Power(Power_flag);
                
                /*************************************��ȡ���������Ƿ��л�**************************************/
                key = OSMboxAccept(KEYMbox);
                if(*key == KEY_DOWN)
                {
                    judge_new++;
                    if(judge_new >= 3)
                    {
                        judge_new = 1;
                    }
                }
                else if(*key == KEY_UP)
                {
                    judge_new--;
                    if(judge_new <= 0)
                    {
                        judge_new = 2;
                    }
                }
                else if(*key == KEY_ENTER)
                {
                    if(judge_new == 1)
                    {
                        LCDClrWin(0,2,127,7);                                           //��ȫ��
                        LCD_String("����λ��",20,2,13,16,NORMAL);                       //��ʾ������������ַ�
                        LCD_ASCII("[",72,2,7,16,NORMAL);                                //��ʾ[�ַ�
                        FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //�������ڴ洢�˶��ٸ��ļ�
                        storage_number++;
                        sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                        LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                        LCD_ASCII("]",100,2,7,16,NORMAL);                               //��ʾ]�ַ�
                        
                        /**********************************�洢����************************************/
                        //�洢�����
                        g_StorageData.number = storage_number;       
                        //��ǰʱ��
                        g_StorageData.now_year = g_RTCTime.year;                //�趨��ǰʱ��---��
                        g_StorageData.now_month = g_RTCTime.month;              //�趨��ǰʱ��---��
                        g_StorageData.now_day = g_RTCTime.day;                  //�趨��ǰʱ��---��
                        g_StorageData.now_hour = g_RTCTime.hour;                //�趨��ǰʱ��---ʱ
                        g_StorageData.now_minute = g_RTCTime.minute;            //�趨��ǰʱ��---��
                        g_StorageData.now_second = g_RTCTime.second;            //�趨��ǰʱ��---��
                        //�趨A�Ĳɼ�ʱ��
                        g_StorageData.sampling_hour_a = timer_hour_a;               //�趨�Ĳɼ�ʱ��---ʱ
                        g_StorageData.sampling_minute_a = timer_minute_a;           //�趨�Ĳɼ�ʱ��---��
                        g_StorageData.sampling_second_a = timer_second_a;           //�趨�Ĳɼ�ʱ��---��
                        //�趨B�Ĳɼ�ʱ��
                        g_StorageData.sampling_hour_b = timer_hour_b;               //�趨�Ĳɼ�ʱ��---ʱ
                        g_StorageData.sampling_minute_b = timer_minute_b;           //�趨�Ĳɼ�ʱ��---��
                        g_StorageData.sampling_second_b = timer_second_b;           //�趨�Ĳɼ�ʱ��---��
                        //ͨ����ѹֵ
                        g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //���ĵ�ѹAֵ,�Ŵ�100���洢
                        g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //���ĵ�ѹBֵ,�Ŵ�100���洢
                        //��ѹֵ
                        g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //������ѹֵ,�Ŵ�100���洢
                        //�¶�ֵ
                        //������
                        if(g_Temperature.DQ3_exist == 0)
                        {
                            g_StorageData.heattemp = 0xffff;                                  //δ��⵽�¶ȴ�����
                        }
                        else
                        {
                            g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //���ļ������¶�ֵ,�Ŵ�100���洢
                        }
                        //ͨ��A
                        if(g_Temperature.DQ1_exist == 0)
                        {
                            g_StorageData.temp_A = 0xffff;                                  //δ��⵽�¶ȴ�����
                        }
                        else
                        {
                            g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //����ͨ��A�¶�ֵ,�Ŵ�100���洢
                        }
                        //ͨ��B
                        if(g_Temperature.DQ2_exist == 0)
                        {
                            g_StorageData.temp_B = 0xffff;                                  //δ��⵽�¶ȴ�����
                        }
                        else
                        {
                            g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //����ͨ��B�¶�ֵ,�Ŵ�100���洢
                        }
                        //����ֵ
                        g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //ͨ��A����ֵ
                        g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //ͨ��B����ֵ
                        //�������ֵ
                        g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//ͨ��A���
                        g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//ͨ��B���
                        //����������ֵ
                        g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//ͨ��A������
                        g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//ͨ��B������
                          
                        FM24C64_Data_Storage(storage_number,1);
                     
                        /*************************************���򷵻�***********************************************/
                        LCDClrWin(20,4,106,5);                                     //�岿����
                        LCD_String("��������",20,4,13,16,NORMAL);                  //��ʾ������������ַ�
                        LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //��ʾ...�ַ�
                        while(1)
                        {
                            //��ʾ���
                            Display_Batter(Power_flag);
                            //��ʾ��Դ
                            Display_Power(Power_flag);
                            
                            key = OSMboxAccept(KEYMbox);
                            if((*key == KEY_CAL) || (*key == KEY_ENTER))
                            {
                                //����ǰһ���棬��ȫ��
                                LCDClrWin(0,0,127,7);                           //�岿����
                                LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                                LCD_String("��ʱ����",38,0,13,16,MOVEUP);       //��ʾ��ʱ�����ַ�
                                flag2 = 0;                                      //����ˢ�����־
                                return;
                            }
                        } 
                    }
                    else
                    {
                        //����ǰһ���棬��ȫ��
                        LCDClrWin(0,0,127,7);                           //�岿����
                        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                        LCD_String("��ʱ����",38,0,13,16,MOVEUP);       //��ʾ��ʱ�����ַ�
                        flag2 = 0;                                      //����ˢ�����־
                        return;
                    }
                }
                /*********************��ʾ��ͷָ�벿��***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//��ʾ��ͷ����
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//�����һ������
                    judge_old = judge_new;     
                }
            } 
        }
        /*************************************��ȡ�������ò���**************************************/
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_DOWN)
        {
            add_new++;
            if(add_new >= 16)
            {
                add_new = 1;
            }
        }
        else if(*key == KEY_UP)
        {
            add_new--;
            if(add_new <= 0)
            {
                add_new = 15;
            }
        }
        else if(*key == KEY_CAL)
        {
            MOTOR_A_OFF();                                  //�ر�����A
            MOTOR_B_OFF();                                  //�ر�����B
//            TIM_Cmd(TIM2, DISABLE);	                    //�رն�ʱ��2
            PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
            
            LCDClrWin(0,0,127,7);                           //��ҳ��ʾ�䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("������ͣ",0,0,13,16,MOVEUP);        //��ʾ������ͣ�ַ�
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //��ʾ�������ַ�
            
            LCD_String("�Ƿ��������",6,2,13,16,NORMAL);    //��ʾ�Ƿ���������ַ�
            LCD_ASCII("?",84,2,7,16,NORMAL);                //��ʾ?�ַ�
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);          //��ʾ(1)����
            LCD_String("��",58,4,13,16,NORMAL);         //��ʾ���ַ�
            LCD_ASCII("(2)",37,6,7,16,NORMAL);          //��ʾ(2)����
            LCD_String("��",58,6,13,16,NORMAL);         //��ʾ���ַ�
            while(1)
            {
                //��ʾ���
                Display_Batter(Power_flag);
                //��ʾ��Դ
                Display_Power(Power_flag);
                
                /*************************************��ȡ���������Ƿ��л�**************************************/
                key = OSMboxAccept(KEYMbox);
                if(*key == KEY_DOWN)
                {
                    judge_new++;
                    if(judge_new == 3)
                    {
                        judge_new = 1;
                    }
                }
                else if(*key == KEY_UP)
                {
                    judge_new--;
                    if(judge_new == 0)
                    {
                        judge_new = 2;
                    }
                }
                else if(*key == KEY_ENTER)
                {
                    if(judge_new == 1)
                    {
                        timer_hour_a = Timer_hour_A;
                        timer_minute_a = Timer_minute_A;
                        timer_second_a = Timer_second_A;
                        timer_hour_b = Timer_hour_B;
                        timer_minute_b = Timer_minute_B;
                        timer_second_b = Timer_second_B;
                        FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //д����ɱ�־
                        /*************************************�Ѽ���ֵ����***********************************************/
                        Timer_hour_A = 0;
                        Timer_minute_A = 0;
                        Timer_second_A = 0;
                        
                        Timer_hour_B = 0;
                        Timer_minute_B = 0;
                        Timer_second_B = 0;
                        g_t_count = 0;
                        
                        /*************************************�����б�־Ҳ����***********************************************/
                        g_TimeEnableDisable_A = 0;
                        g_TimeEnableDisable_B = 0;
                        
                        g_TimeFlag_A = 0;                               //�ر�ͨ��Aʱ�����
                        g_TimeFlag_B = 0;                               //�ر�ͨ��Bʱ�����
                        
                        FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //���涨ʱ��״̬
                        FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //���涨ʱ��״̬
                        
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //��ʱ��ʹ�ܻ�ʧ��
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //��ʱ��ʹ�ܻ�ʧ��
                        
                        LCDClrWin(0,2,127,7);                           //��ڲ�����
                        LCD_String("�Ƿ񱣴��������",8,2,13,16,NORMAL);//��ʾ������������ַ�
                        LCD_ASCII("?",112,2,7,16,NORMAL);                //��ʾ?�ַ�
                        
                        LCD_ASCII("(1)",37,4,7,16,NORMAL);              //��ʾ(1)����
                        LCD_String("��",58,4,13,16,NORMAL);             //��ʾ���ַ�
                        LCD_ASCII("(2)",37,6,7,16,NORMAL);              //��ʾ(2)����
                        LCD_String("��",58,6,13,16,NORMAL);             //��ʾ���ַ�
                        while(1)
                        {
                            //��ʾ���
                            Display_Batter(Power_flag);
                            //��ʾ��Դ
                            Display_Power(Power_flag);
                            
                            /*************************************��ȡ���������Ƿ��л�**************************************/
                            key = OSMboxAccept(KEYMbox);
                            if(*key == KEY_DOWN)
                            {
                                judge_new1++;
                                if(judge_new1 >= 3)
                                {
                                    judge_new1 = 1;
                                }
                            }
                            else if(*key == KEY_UP)
                            {
                                judge_new1--;
                                if(judge_new1 <= 0)
                                {
                                    judge_new1 = 2;
                                }
                            }
                            else if(*key == KEY_ENTER)
                            {
                                if(judge_new1 == 1)
                                {
                                    LCDClrWin(0,2,127,7);                                           //��ȫ��
                                    LCD_String("����λ��",20,2,13,16,NORMAL);                       //��ʾ������������ַ�
                                    LCD_ASCII("[",72,2,7,16,NORMAL);                                //��ʾ[�ַ�
                                    FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //�������ڴ洢�˶��ٸ��ļ�
                                    storage_number++;
                                    sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                                    LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                                    LCD_ASCII("]",100,2,7,16,NORMAL);                               //��ʾ]�ַ�
                                    
                                    /**********************************�洢����************************************/
                                    //�洢�����
                                    g_StorageData.number = storage_number;       
                                    //��ǰʱ��
                                    g_StorageData.now_year = g_RTCTime.year;                //�趨��ǰʱ��---��
                                    g_StorageData.now_month = g_RTCTime.month;              //�趨��ǰʱ��---��
                                    g_StorageData.now_day = g_RTCTime.day;                  //�趨��ǰʱ��---��
                                    g_StorageData.now_hour = g_RTCTime.hour;                //�趨��ǰʱ��---ʱ
                                    g_StorageData.now_minute = g_RTCTime.minute;            //�趨��ǰʱ��---��
                                    g_StorageData.now_second = g_RTCTime.second;            //�趨��ǰʱ��---��
                                    //�趨A�Ĳɼ�ʱ��
                                    g_StorageData.sampling_hour_a = timer_hour_a;               //�趨�Ĳɼ�ʱ��---ʱ
                                    g_StorageData.sampling_minute_a = timer_minute_a;           //�趨�Ĳɼ�ʱ��---��
                                    g_StorageData.sampling_second_a = timer_second_a;           //�趨�Ĳɼ�ʱ��---��
                                    //�趨B�Ĳɼ�ʱ��
                                    g_StorageData.sampling_hour_b = timer_hour_b;               //�趨�Ĳɼ�ʱ��---ʱ
                                    g_StorageData.sampling_minute_b = timer_minute_b;           //�趨�Ĳɼ�ʱ��---��
                                    g_StorageData.sampling_second_b = timer_second_b;           //�趨�Ĳɼ�ʱ��---��
                                    //ͨ����ѹֵ
                                    g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //���ĵ�ѹAֵ,�Ŵ�100���洢
                                    g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //���ĵ�ѹBֵ,�Ŵ�100���洢
                                    //��ѹֵ
                                    g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //������ѹֵ,�Ŵ�100���洢
                                    //�¶�ֵ
                                    //������
                                    if(g_Temperature.DQ3_exist == 0)
                                    {
                                        g_StorageData.heattemp = 0xffff;                                  //δ��⵽�¶ȴ�����
                                    }
                                    else
                                    {
                                        g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //���ļ������¶�ֵ,�Ŵ�100���洢
                                    }
                                    //ͨ��A
                                    if(g_Temperature.DQ1_exist == 0)
                                    {
                                        g_StorageData.temp_A = 0xffff;                                  //δ��⵽�¶ȴ�����
                                    }
                                    else
                                    {
                                        g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //����ͨ��A�¶�ֵ,�Ŵ�100���洢
                                    }
                                    //ͨ��B
                                    if(g_Temperature.DQ2_exist == 0)
                                    {
                                        g_StorageData.temp_B = 0xffff;                                  //δ��⵽�¶ȴ�����
                                    }
                                    else
                                    {
                                        g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //����ͨ��B�¶�ֵ,�Ŵ�100���洢
                                    }
                                    //����ֵ
                                    g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //ͨ��A����ֵ
                                    g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //ͨ��B����ֵ
                                    //�������ֵ
                                    g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//ͨ��A���
                                    g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//ͨ��B���
                                    //����������ֵ
                                    g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//ͨ��A������
                                    g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//ͨ��B������
                                       
                                    FM24C64_Data_Storage(storage_number,1);
                                    /*************************************���򷵻�***********************************************/
                                    LCDClrWin(20,4,106,5);                                     //�岿����
                                    LCD_String("��������",20,4,13,16,NORMAL);                  //��ʾ������������ַ�
                                    LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //��ʾ...�ַ�
                                    while(1)
                                    {
                                        //��ʾ���
                                        Display_Batter(Power_flag);
                                        //��ʾ��Դ
                                        Display_Power(Power_flag);
                                        
                                        key = OSMboxAccept(KEYMbox);
                                        if((*key == KEY_CAL) || (*key == KEY_ENTER))
                                        {
                                            //����ǰһ���棬��ȫ��
                                            LCDClrWin(0,0,127,7);                           //�岿����
                                            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                                            LCD_String("��ʱ����",38,0,13,16,MOVEUP);       //��ʾ��ʱ�����ַ�
                                            flag2 = 0;                                      //����ˢ�����־
                                            return;
                                        }
                                    } 
                                }
                                else
                                {
                                    //����ǰһ���棬��ȫ��
                                    LCDClrWin(0,0,127,7);                           //�岿����
                                    LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                                    LCD_String("��ʱ����",38,0,13,16,MOVEUP);       //��ʾ��ʱ�����ַ�
                                    flag2 = 0;                                      //����ˢ�����־
                                    return;
                                }
                            }
                            /*********************��ʾ��ͷָ�벿��***********************/
                            LCD_ASCII("-->",6,2*(judge_new1+1),7,16,NORMAL);//��ʾ��ͷ����
                            if (judge_old1 != judge_new1)
                            {	
                                LCDClrWin(6,2*(judge_old1+1),28,2*(judge_old1+1)+1);//�����һ������
                                judge_old1 = judge_new1;     
                            }
                        }
                    }
                    else
                    {
                        /*********************************��ʾ��ʼ�ĵ�һ����**************************************/
                        LCDClrWin(0,0,127,7);                           //��ȫ��
                        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                        LCD_String("������",0,0,13,16,MOVEUP);          //��ʾ�������ַ�
                        LCD_ASCII("...",39,0,7,16,MOVEUP);              //��ʾ�������ַ�
                        //���ص�һ����
                        fla1 = 0;
                        add_new = 1;                                   //�ָ���ʼ״̬
                        //�жϲ���״̬
                        if(sampling_a <= 0.001)
                        {
                            MOTOR_A_OFF();                              //�ر�����A
                        }
                        else
                        {
                            if(g_TimeFlag_A == 0)
                            {
                                MOTOR_A_OFF();                              //�ر�����A
                            }
                            else
                            {
                                MOTOR_A_ON();                               //������A
                            }
                        }
                        if(sampling_b <= 0.001)
                        {
                            MOTOR_B_OFF();                              //�ر�����B
                        }
                        else
                        {
                            if(g_TimeFlag_B == 0)
                            {
                                MOTOR_B_OFF();                              //�ر�����A
                            }
                            else
                            {
                                MOTOR_B_ON();                               //������A
                            }
                        }
//                        TIM_Cmd(TIM2, ENABLE);	                       //�򿪶�ʱ��2
                        PCF8563_TIE_EnableDisable(1);           //PCF8563��ʱ��ʹ��
                        break;
                    }
                }
                /*********************��ʾ��ͷָ�벿��***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//��ʾ��ͷ����
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//�����һ������
                    judge_old = judge_new;     
                }
            }
        }
         
        /*********************************�䶯����ɨ�貿��*************************************/
        if(add_new <= 3)
        {
            if(fla1 == 0)
            {
                //��һҳ�����ַ�����
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                LCD_ASCII("1/5",70,0,7,16,MOVEUP);              //��ʾ1/4�����ַ�
                LCD_String("��",25,2,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                LCD_String("ǰ",47,2,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                
                /*********************ͨ��A��ʼʱ���ӡ***********************/
                LCD_String("��ʼ",25,4,13,16,NORMAL);           //��ʾ�趨�ַ�
                LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
                //ʱ
                sprintf(str,"%02d:\0",(uint8_t)start_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                //��
                sprintf(str,"%02d:\0",(uint8_t)start_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                 //��
                sprintf(str,"%02d\0", (uint8_t)start_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                
                /*********************ͨ��B��ʼʱ���ӡ***********************/
                LCD_String("��ʼ",25,6,13,16,NORMAL);           //��ʾ��ʱ�ַ�
                LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
                //ʱ
                sprintf(str,"%02d:\0",(uint8_t)start_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                //��
                sprintf(str,"%02d:\0",(uint8_t)start_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                 //��
                sprintf(str,"%02d\0", (uint8_t)start_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                
                fla1 = 1;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************��ǰʱ���ȡ***********************/
            //ʱ
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //��
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //��
            sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************��ʾ��ͷָ�벿��***********************/
            
            LCD_ASCII("-->",3,2*add_new,7,16,NORMAL);//��ʾ��ͷ����
            if (add_old != add_new)
            {	
                LCDClrWin(3,2*add_old,24,2*add_old+1);//�����һ������
                add_old = add_new;     
            }
        }
        else if((add_new >= 4) && (add_new <= 6))
        {
            if(fla2 == 0)
            {
                //�ڶ�ҳ
                LCD_ASCII("2/5",70,0,7,16,MOVEUP);              //��ʾ2/4�����ַ�
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                
                /*********************ͨ��A�ɼ�ʱ���ӡ***********************/
                LCD_String("��ʱ",25,2,13,16,NORMAL);           //��ʾ�趨�ַ�
                LCD_ASCII("A",51,2,7,16,NORMAL);                //��ʾA�ַ�
                //ʱ
                sprintf(str,"%02d:\0",(uint8_t)sampling_hour_a);
                LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
                //��
                sprintf(str,"%02d:\0",(uint8_t)sampling_minute_a);
                LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
                 //��
                sprintf(str,"%02d\0", (uint8_t)sampling_second_a);
                LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                
                /*********************ͨ��B�ɼ�ʱ���ӡ***********************/
                LCD_String("��ʱ",25,4,13,16,NORMAL);           //��ʾ��ʱ�ַ�
                LCD_ASCII("B",51,4,7,16,NORMAL);                //��ʾB�ַ�
                //ʱ
                sprintf(str,"%02d:\0",(uint8_t)sampling_hour_b);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                //��
                sprintf(str,"%02d:\0",(uint8_t)sampling_minute_b);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                 //��
                sprintf(str,"%02d\0", (uint8_t)sampling_second_b);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                
                /*********************ͨ��A��ʱʱ���ӡ***********************/
                LCD_String("��ʱ",25,6,13,16,NORMAL);           //��ʾ��ʱ�ַ�
                LCD_ASCII("A",51,6,7,16,NORMAL);                //��ʾB�ַ�
                
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 1;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************����ʱ���ȡ***********************/
            //ʱ
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_A);
            LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
            //��
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_A);
            LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
             //��
            sprintf(str,"%02d\0", (uint8_t)Timer_second_A);
            LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
            
            /*********************��ʾ��ͷָ�벿��***********************/
            LCD_ASCII("-->",3,2*(add_new-3),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 3)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-3),24,2*(add_old-3)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 7) && (add_new <= 9))
        {
            if(fla3 == 0)
            {
                //����ҳ
                LCD_ASCII("3/5",70,0,7,16,MOVEUP);              //��ʾ2/4�����ַ�
                LCDClrWin(0,2,127,7);   
                
                /*********************ͨ��B��ʱʱ���ӡ***********************/
                LCD_String("��ʱ",25,2,13,16,NORMAL);           //��ʾ��ʱ�ַ�
                LCD_ASCII("B",51,2,7,16,NORMAL);                //��ʾB�ַ�
                
                /*********************ͨ��A������ӡ***********************/
                LCD_String("����",25,4,13,16,NORMAL);           //��ʾ�����ַ�
                LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
                LCD_ASCII(":",58,4,7,16,NORMAL);                //��ʾ:�ַ�
                LCD_ASCII("L/min",92,4,7,16,NORMAL);            //��ʾ�¶�ֵ�ַ�
                
                /*********************ͨ��B������ӡ***********************/
                LCD_String("����",25,6,13,16,NORMAL);           //��ʾ�����ַ�
                LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
                LCD_ASCII(":",58,6,7,16,NORMAL);                //��ʾ:�ַ�
                LCD_ASCII("L/min",92,6,7,16,NORMAL);            //��ʾ��λֵ�ַ�
                
                Float2Str(sampling_a,str1,2);
                LCD_ASCII((uint8_t*)str1,64,4,7,16,NORMAL);
                
                Float2Str(sampling_b,str1,2);
                LCD_ASCII((uint8_t*)str1,64,6,7,16,NORMAL);
                
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 1;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            
            /*********************����ʱ���ȡ***********************/
            //ʱ
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_B);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //��
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_B);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //��
            sprintf(str,"%02d\0", (uint8_t)Timer_second_B);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************��ʾ��ͷָ�벿��***********************/
            LCD_ASCII("-->",3,2*(add_new-6),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 6)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-6),24,2*(add_old-6)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 10) && (add_new <= 12))
        {
            if(fla4 == 0)
            {
                //����ҳ
                LCD_ASCII("4/5",70,0,7,16,MOVEUP);              //��ʾ2/4�����ַ�
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                
                LCD_String("��ѹ",30,2,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                LCD_ASCII("A",56,2,7,16,NORMAL);                //��ʾA�ַ�
                LCD_ASCII(":",63,2,7,16,NORMAL);                //��ʾ:�ַ�
                
                LCD_String("��ѹ",30,4,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                LCD_ASCII("B",56,4,7,16,NORMAL);                //��ʾB�ַ�
                LCD_ASCII(":",63,4,7,16,NORMAL);                //��ʾ:�ַ�
                
                //����A��ѹ
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,70,2,7,16,NORMAL);               //����A��ѹ
                
                //����B��ѹ
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,70,4,7,16,NORMAL);               //����B��ѹ
                
                
                LCD_String("��ѹ",30,6,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                LCD_ASCII(":",56,6,7,16,NORMAL);                //��ʾ:�ַ�
                
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 1;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************��ѹֵ***********************/
            ad++;  
            if(ad == 50)
            {
                //����A��ѹ
                LCDClrWin(70,2,127,3);                           //��ҳ��ʾ�䶯����
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,70,2,7,16,NORMAL);               //����A��ѹ
                
                //����B��ѹ
                LCDClrWin(70,4,127,5);                           //��ҳ��ʾ�䶯����
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,70,4,7,16,NORMAL);               //����B��ѹ
                
                ad = 0;
            }
            
            /*********************��ѹֵ***********************/
            if(g_Pressure >= 100)
            {
                Float2Str(g_Pressure,tab4,2);
            }
            else
            {
                Float2Str(g_Pressure,tab4,3);
            }
            LCD_ASCII(tab4,63,6,7,16,NORMAL);
            LCD_ASCII("kPa",105,6,7,16,NORMAL);  
            
            /*********************��ʾ��ͷָ�벿��***********************/
            
            LCD_ASCII("-->",6,2*(add_new-9),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 9)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-9),28,2*(add_old-9)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 13) && (add_new <= 15))
        {
            if(fla5 == 0)
            {
                //����ҳ
                LCD_ASCII("5/5",70,0,7,16,MOVEUP);              //��ʾ3/4�����ַ�
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                LCD_String("������",30,2,13,16,NORMAL);         //��ʾ�������ַ�
                LCD_ASCII(":",69,2,7,16,NORMAL);                //��ʾ:�ַ�
                
                LCD_String("�¶�",30,4,13,16,NORMAL);           //��ʾ�¶��ַ�
                LCD_ASCII("A",56,4,7,16,NORMAL);                //��ʾA�ַ�
                LCD_ASCII(":",69,4,7,16,NORMAL);                //��ʾ:�ַ�
                
                LCD_String("�¶�",30,6,13,16,NORMAL);           //��ʾ�¶��ַ�
                LCD_ASCII("B",56,6,7,16,NORMAL);                //��ʾB�ַ�
                LCD_ASCII(":",69,6,7,16,NORMAL);                //��ʾ:�ַ�
                
                //������
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��A�¶�
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��B�¶�
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",107,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 1;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************�����¶�***********************/
            //�����¶�
            ad1++;
            if(ad1 > 50)
            {
                ad1 = 0;
                //������
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��A�¶�
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��B�¶�
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",107,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
            }
            
            /*********************��ʾ��ͷָ�벿��***********************/
            LCD_ASCII("-->",6,2*(add_new-12),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 12)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-12),28,2*(add_old-12)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
    }     
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay(void)
�������ܣ������ӽ��� �����������ӽ��� �����������С��������棩
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay(void)
{
    int8_t add_new = 1;
    int8_t add_old = 1;
    int8_t judge_new = 1;
    int8_t judge_old = 1;
    int8_t judge_new1 = 1;
    int8_t judge_old1 = 1;
    uint8_t storage_number = 0;
    uint8_t ad = 0;
    uint8_t ad1 = 0;
    uint8_t fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
    uint8_t fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
    uint8_t fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
    uint8_t fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
    uint8_t fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
    uint8_t *key;
    uint8_t tab1[10];
    uint8_t tab2[10];
    uint8_t tab3[10];
    uint8_t tab4[10];
    char str[10];
    uint8_t str1[10];
    
    uint8_t immediately_hour_a = 0;
    uint8_t immediately_minute_a = 0;
    uint8_t immediately_second_a = 0;
    
    uint8_t immediately_hour_b = 0;
    uint8_t immediately_minute_b = 0;
    uint8_t immediately_second_b = 0;

    uint8_t timer_hour_a = 0;
    uint8_t timer_minute_a = 0;
    uint8_t timer_second_a = 0;
    
    uint8_t timer_hour_b = 0;
    uint8_t timer_minute_b = 0;
    uint8_t timer_second_b = 0;
    
    float sampling_a = 0.0;
    float sampling_b = 0.0;
    
    /******************************��ȡA�����������趨ʱ��**************************************/
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_A,(uint8_t*)&immediately_hour_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_A,(uint8_t*)&immediately_minute_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_A,(uint8_t*)&immediately_second_a,1);
    
    /******************************��ȡB�����������趨ʱ��**************************************/
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_B,(uint8_t*)&immediately_hour_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_B,(uint8_t*)&immediately_minute_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_B,(uint8_t*)&immediately_second_b,1);
    
    /******************************��ȡ�����������趨ֵ**************************************/
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    
    /*********************************��ʾ��ʼ�ĵ�һ����**************************************/
    LCDClrWin(0,0,127,7);                           //��ȫ��
    LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
    LCD_String("������",0,0,13,16,MOVEUP);          //��ʾ�������ַ�
    LCD_ASCII("...",39,0,7,16,MOVEUP);              //��ʾ�������ַ�
    LCD_ASCII("1/4",70,0,7,16,MOVEUP);              //��ʾ1/4�����ַ�
    
    /*********************************��ʱ����Ʊ�־**************************************/
    if((immediately_hour_a*3600 + immediately_minute_a*60 + immediately_second_a) == 0)
    {
        g_TimeFlag_A = 0;
    }
    else
    {
        g_TimeFlag_A = 1;
    }
    if((immediately_hour_b*3600 + immediately_minute_b*60 + immediately_second_b) == 0)
    {
        g_TimeFlag_B = 0;
    }
    else
    {
        g_TimeFlag_B = 1;
    }
    
    //ͨ�������ж��ĸ�ͨ���رջ��
    if(sampling_a <= 0.001)
    {
        MOTOR_A_OFF();                              //�ر�����A
    }
    else
    {
        if(g_TimeFlag_A == 0)
        {
            MOTOR_A_OFF();                           //�ر�����A
        }
        else
        {
            MOTOR_A_ON();                            //������A
        }
    }
    if(sampling_b <= 0.001)
    {
        MOTOR_B_OFF();                               //�ر�����B
    }
    else
    {
        if(g_TimeFlag_B == 0)
        {
            MOTOR_B_OFF();                           //�ر�����A
        }
        else
        {
            MOTOR_B_ON();                            //������A
        }
    }
//    TIM_Cmd(TIM2, ENABLE);	                    //������ʱ��2
    PCF8563_TIE_EnableDisable(1);           //PCF8563��ʱ��ʹ��
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        /*************************************����������ʾ����**************************************/
        if((g_Power.pc0_adc10_battery <= 10.4) && (Power_flag == 0))
        {
            uint8_t i = 0;
            /*�رղ��������úͶ�ʱ��*/
            MOTOR_A_OFF();                                  //�ر�����A
            MOTOR_B_OFF();                                  //�ر�����B
//            TIM_Cmd(TIM2, DISABLE);	                    //�رն�ʱ��2
            PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //���涨ʱ��״̬
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //���涨ʱ��״̬
            
            g_TimeFlag_A = 0;                               //�ر�ͨ��Aʱ�����
            g_TimeFlag_B = 0;                               //�ر�ͨ��Bʱ�����
            
            /*��ʾ�ȴ��������*/
            LCDClrWin(0,0,127,7);                           //����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            
            //��ʾ���
            Display_Batter(Power_flag);
            //��ʾ��Դ
            Display_Power(Power_flag);
            
            LCD_String("�ȴ�����",0,0,13,16,MOVEUP);        //��ʾ�ȴ������ַ�
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //��ʾ�������ַ�
        
            LCD_String("��������",34,2,13,16,NORMAL);       //��ʾ���������ַ�
            LCD_ASCII(",",86,2,7,16,NORMAL);                //��ʾ,�ַ�
            LCD_String("��ֹͣ����",34,4,13,16,NORMAL);     //��ʾ��ֹͣ�����ַ�
            LCD_ASCII("!",99,4,7,16,NORMAL);                //��ʾ���ַ�
            
            /*�������������ʾ*/
            for(i = 0; i < 7; i++)
            {
                BEEP_ON();
                OSTimeDly(10);
                BEEP_OFF();
                OSTimeDly(10);
            }
            while(1)
            {
                //��ʾ���
                Display_Batter(Power_flag);
                //��ʾ��Դ
                Display_Power(Power_flag);
                
                /*************************************��ȡ���������Ƿ��л�**************************************/
                key = OSMboxAccept(KEYMbox);
                if((*key == KEY_ENTER) || (*key == KEY_CAL))
                {
                    //����ǰһ���棬��ȫ��
                    LCDClrWin(0,0,127,7);                           //��ȫ��
                    flag2 = 0;                                      //����ˢ�����־
                    FM24C64_WRITE_BYTE(UNFINISHED_FLAG,1);          //д��δ��ɱ�־
                    FM24C64_WRITE_BYTE(TIMER_HOUR_A,Timer_hour_A);      //д�������Сʱֵ
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_A,Timer_minute_A);  //д������ķ���ֵ
                    FM24C64_WRITE_BYTE(TIMER_SECOND_A,Timer_second_A);  //д�����������ֵ
                    FM24C64_WRITE_BYTE(TIMER_HOUR_B,Timer_hour_B);      //д�������Сʱֵ
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_B,Timer_minute_B);  //д������ķ���ֵ
                    FM24C64_WRITE_BYTE(TIMER_SECOND_B,Timer_second_B);  //д�����������ֵ
                    /*************************************�Ѽ���ֵ����***********************************************/
                    Timer_hour_A = 0;
                    Timer_minute_A = 0;
                    Timer_second_A = 0;
                    Timer_hour_B = 0;
                    Timer_minute_B = 0;
                    Timer_second_B = 0;
                    g_t_count = 0;                                //��ʱ����ֵ����
                    return;
                }
                /*���½����˵�ѹ��Ӧ*/
                if((g_Power.pc0_adc10_battery > 11) || (Power_flag == 1))
                {
                    /*********************************�ָ������С���������**************************************/
                    LCDClrWin(0,0,127,7);                           //��ȫ��
                    LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                    LCD_String("������",0,0,13,16,MOVEUP);          //��ʾ�������ַ�
                    LCD_ASCII("...",39,0,7,16,MOVEUP);              //��ʾ�������ַ�
                    //���ص�һ����
                    fla1 = 0;
                    add_new = 1;                                   //�ָ���ʼ״̬
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //�ָ���ʱ��״̬
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //�ָ���ʱ��״̬
                    
                    //�жϲ���״̬
                    if(sampling_a <= 0.001)
                    {
                        MOTOR_A_OFF();                              //�ر�����A
                    }
                    else
                    {
                        if(g_TimeFlag_A == 0)
                        {
                            MOTOR_A_OFF();                           //�ر�����A
                        }
                        else
                        {
                            MOTOR_A_ON();                            //������A
                        }
                    }
                    if(sampling_b <= 0.001)
                    {
                        MOTOR_B_OFF();                               //�ر�����B
                    }
                    else
                    {
                        if(g_TimeFlag_B == 0)
                        {
                            MOTOR_B_OFF();                           //�ر�����A
                        }
                        else
                        {
                            MOTOR_B_ON();                            //������A
                        }
                    }
//                    TIM_Cmd(TIM2, ENABLE);	                   //�򿪶�ʱ��2
                    PCF8563_TIE_EnableDisable(1);           //PCF8563��ʱ��ʹ��
                    break;
                }
            }
        }
        /*��ֵ���м���*/
        timer_hour_a = Timer_hour_A;
        timer_minute_a = Timer_minute_A;
        timer_second_a = Timer_second_A;
        
        timer_hour_b = Timer_hour_B;
        timer_minute_b = Timer_minute_B;
        timer_second_b = Timer_second_B;
        /******************************����������**************************************/
        if(((immediately_hour_a*3600 + immediately_minute_a*60 + immediately_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) >= 1) && ((immediately_hour_a*3600 + immediately_minute_a*60 + immediately_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) <= 3)
           || ((immediately_hour_b*3600 + immediately_minute_b*60 + immediately_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) >= 1) && ((immediately_hour_b*3600 + immediately_minute_b*60 + immediately_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) <= 3))
        {
            BEEP_ON();
            OSTimeDly(10);
            BEEP_OFF();
            OSTimeDly(10);
        }
        /******************************ͨ��A��ȡʱ���Ƿ���趨ֵ���**************************************/
        if((Timer_hour_A == immediately_hour_a) && (Timer_minute_A == immediately_minute_a) && (Timer_second_A >= immediately_second_a))
        {
            BEEP_OFF();
            MOTOR_A_OFF();                                  //�ر�����A
            g_TimeFlag_A = 0;                               //ͨ��A���     
        }
        
        /******************************ͨ��B��ȡʱ���Ƿ���趨ֵ���**************************************/
        if((Timer_hour_B == immediately_hour_b) && (Timer_minute_B == immediately_minute_b) && (Timer_second_B >= immediately_second_b))
        {
            BEEP_OFF();
            MOTOR_B_OFF();                                  //�ر�����B
            g_TimeFlag_B = 0;                               //ͨ��B���    
        }
        /******************************��ȡʱ���Ƿ���趨ֵ���**************************************/
        if((g_TimeFlag_A == 0) && ( g_TimeFlag_B == 0))
        {
//            TIM_Cmd(TIM2, DISABLE);	                    //�رն�ʱ��2
            PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
            FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //д����ɱ�־

            /*��ֵ���м���*/
            timer_hour_a = Timer_hour_A;
            timer_minute_a = Timer_minute_A;
            timer_second_a = Timer_second_A;
            
            timer_hour_b = Timer_hour_B;
            timer_minute_b = Timer_minute_B;
            timer_second_b = Timer_second_B;
              
            /*************************************�Ѽ���ֵ����***********************************************/
            Timer_hour_A = 0;
            Timer_minute_A = 0;
            Timer_second_A = 0;
            
            Timer_hour_B = 0;
            Timer_minute_B = 0;
            Timer_second_B = 0;
            g_t_count = 0;
            
            /*************************************�����б�־Ҳ����***********************************************/
            g_TimeEnableDisable_A = 0;
            g_TimeEnableDisable_B = 0;
            
            g_TimeFlag_A = 0;                               //�ر�ͨ��Aʱ�����
            g_TimeFlag_B = 0;                               //�ر�ͨ��Bʱ�����
            
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //���涨ʱ��״̬
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //���涨ʱ��״̬
            
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //��ʱ��ʹ�ܻ�ʧ��
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //��ʱ��ʹ�ܻ�ʧ��
            
            LCDClrWin(0,0,127,7);                           //��ȫ��
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("�������",0,0,13,16,MOVEUP);        //��ʾ��������ַ�
            LCD_ASCII("!",52,0,7,16,MOVEUP);                //��ʾ!�ַ�
            
            
            LCD_String("�Ƿ񱣴��������",8,2,13,16,NORMAL);//��ʾ������������ַ�
            LCD_ASCII("?",112,2,7,16,NORMAL);                //��ʾ?�ַ�
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);              //��ʾ(1)����
            LCD_String("��",58,4,13,16,NORMAL);             //��ʾ���ַ�
            LCD_ASCII("(2)",37,6,7,16,NORMAL);              //��ʾ(2)����
            LCD_String("��",58,6,13,16,NORMAL);             //��ʾ���ַ�
            
            while(1)
            {
                //��ʾ���
                Display_Batter(Power_flag);
                //��ʾ��Դ
                Display_Power(Power_flag);
                
                /*************************************��ȡ���������Ƿ��л�**************************************/
                key = OSMboxAccept(KEYMbox);
                if(*key == KEY_DOWN)
                {
                    judge_new++;
                    if(judge_new >= 3)
                    {
                        judge_new = 1;
                    }
                }
                else if(*key == KEY_UP)
                {
                    judge_new--;
                    if(judge_new <= 0)
                    {
                        judge_new = 2;
                    }
                }
                else if(*key == KEY_ENTER)
                {
                    if(judge_new == 1)
                    {
                        LCDClrWin(0,2,127,7);                                           //��ȫ��
                        LCD_String("����λ��",20,2,13,16,NORMAL);                       //��ʾ������������ַ�
                        LCD_ASCII("[",72,2,7,16,NORMAL);                                //��ʾ[�ַ�
                        FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //�������ڴ洢�˶��ٸ��ļ�
                        storage_number++;
                        sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                        LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                        LCD_ASCII("]",100,2,7,16,NORMAL);                               //��ʾ]�ַ�
                        
                        /**********************************�洢����************************************/
                        //�洢�����
                        g_StorageData.number = storage_number;       
                        //��ǰʱ��
                        g_StorageData.now_year = g_RTCTime.year;                //�趨��ǰʱ��---��
                        g_StorageData.now_month = g_RTCTime.month;              //�趨��ǰʱ��---��
                        g_StorageData.now_day = g_RTCTime.day;                  //�趨��ǰʱ��---��
                        g_StorageData.now_hour = g_RTCTime.hour;                //�趨��ǰʱ��---ʱ
                        g_StorageData.now_minute = g_RTCTime.minute;            //�趨��ǰʱ��---��
                        g_StorageData.now_second = g_RTCTime.second;            //�趨��ǰʱ��---��
                        //�趨�Ĳɼ�ʱ��
                        g_StorageData.sampling_hour_a = timer_hour_a;               //�趨�Ĳɼ�ʱ��---ʱ
                        g_StorageData.sampling_minute_a = timer_minute_a;           //�趨�Ĳɼ�ʱ��---��
                        g_StorageData.sampling_second_a = timer_second_a;           //�趨�Ĳɼ�ʱ��---��
                        
                        g_StorageData.sampling_hour_b = timer_hour_b;               //�趨�Ĳɼ�ʱ��---ʱ
                        g_StorageData.sampling_minute_b = timer_minute_b;           //�趨�Ĳɼ�ʱ��---��
                        g_StorageData.sampling_second_b = timer_second_b;           //�趨�Ĳɼ�ʱ��---��
                        //ͨ����ѹֵ
                        g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //���ĵ�ѹAֵ,�Ŵ�100���洢
                        g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //���ĵ�ѹBֵ,�Ŵ�100���洢
                        //��ѹֵ
                        g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //������ѹֵ,�Ŵ�100���洢
                        //�¶�ֵ
                        //������
                        if(g_Temperature.DQ3_exist == 0)
                        {
                            g_StorageData.heattemp = 0xffff;                                  //δ��⵽�¶ȴ�����
                        }
                        else
                        {
                            g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //���ļ������¶�ֵ,�Ŵ�100���洢
                        }
                        //ͨ��A
                        if(g_Temperature.DQ1_exist == 0)
                        {
                            g_StorageData.temp_A = 0xffff;                                  //δ��⵽�¶ȴ�����
                        }
                        else
                        {
                            g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //����ͨ��A�¶�ֵ,�Ŵ�100���洢
                        }
                        //ͨ��B
                        if(g_Temperature.DQ2_exist == 0)
                        {
                            g_StorageData.temp_B = 0xffff;                                  //δ��⵽�¶ȴ�����
                        }
                        else
                        {
                            g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //����ͨ��B�¶�ֵ,�Ŵ�100���洢
                        }
                        //����ֵ
                        g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //ͨ��A����ֵ
                        g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //ͨ��B����ֵ
                        //�������ֵ
                        g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//ͨ��A���
                        g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//ͨ��B���
                        //����������ֵ
                        g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//ͨ��A������
                        g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//ͨ��B������
                          
                        FM24C64_Data_Storage(storage_number,1);//��������
                     
                        /*************************************���򷵻�***********************************************/
                        LCDClrWin(20,4,106,5);                                     //�岿����
                        LCD_String("��������",20,4,13,16,NORMAL);                  //��ʾ������������ַ�
                        LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //��ʾ...�ַ�
                        while(1)
                        {
                            //��ʾ���
                            Display_Batter(Power_flag);
                            //��ʾ��Դ
                            Display_Power(Power_flag);
                            
                            key = OSMboxAccept(KEYMbox);
                            if((*key == KEY_CAL) || (*key == KEY_ENTER))
                            {
                                //����ǰһ���棬��ȫ��
                                LCDClrWin(0,0,127,7);                           //��ȫ��
                                flag2 = 0;                                      //����ˢ�����־
                                return;
                            }
                        } 
                    }
                    else
                    {
                        //����ǰһ���棬��ȫ��
                        LCDClrWin(0,0,127,7);                           //��ȫ��
                        flag2 = 0;                                      //����ˢ�����־
                        return;
                    }
                }
                /*********************��ʾ��ͷָ�벿��***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//��ʾ��ͷ����
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//�����һ������
                    judge_old = judge_new;     
                }
            } 
        }
        /*************************************��ȡ�������ò���**************************************/
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_DOWN)
        {
            add_new++;
            if(add_new >= 14)
            {
                add_new = 1;
            }
        }
        else if(*key == KEY_UP)
        {
            add_new--;
            if(add_new <= 0)
            {
                add_new = 13;
            }
        }
        else if(*key == KEY_CAL)
        {
            MOTOR_A_OFF();                                  //�ر�����A
            MOTOR_B_OFF();                                  //�ر�����B
//            TIM_Cmd(TIM2, DISABLE);	                    //�رն�ʱ��2
            PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
            
            LCDClrWin(0,0,127,7);                           //��ҳ��ʾ�䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("������ͣ",0,0,13,16,MOVEUP);        //��ʾ������ͣ�ַ�
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //��ʾ�������ַ�
            
            LCD_String("�Ƿ��������",6,2,13,16,NORMAL);    //��ʾ�Ƿ���������ַ�
            LCD_ASCII("?",84,2,7,16,NORMAL);                //��ʾ?�ַ�
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);          //��ʾ(1)����
            LCD_String("��",58,4,13,16,NORMAL);         //��ʾ���ַ�
            LCD_ASCII("(2)",37,6,7,16,NORMAL);          //��ʾ(2)����
            LCD_String("��",58,6,13,16,NORMAL);         //��ʾ���ַ�
            while(1)
            {
                //��ʾ���
                Display_Batter(Power_flag);
                //��ʾ��Դ
                Display_Power(Power_flag);
                
                /*************************************��ȡ���������Ƿ��л�**************************************/
                key = OSMboxAccept(KEYMbox);
                if(*key == KEY_DOWN)
                {
                    judge_new++;
                    if(judge_new >= 3)
                    {
                        judge_new = 1;
                    }
                }
                else if(*key == KEY_UP)
                {
                    judge_new--;
                    if(judge_new <= 0)
                    {
                        judge_new = 2;
                    }
                }
                else if(*key == KEY_ENTER)
                {
                    if(judge_new == 1)
                    {
                        timer_hour_a = Timer_hour_A;
                        timer_minute_a = Timer_minute_A;
                        timer_second_a = Timer_second_A;
                        timer_hour_b = Timer_hour_B;
                        timer_minute_b = Timer_minute_B;
                        timer_second_b = Timer_second_B;
                        FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //д����ɱ�־
                        /*************************************�Ѽ���ֵ����***********************************************/
                        Timer_hour_A = 0;
                        Timer_minute_A = 0;
                        Timer_second_A = 0;
                        
                        Timer_hour_B = 0;
                        Timer_minute_B = 0;
                        Timer_second_B = 0;
                        
                        g_t_count = 0;
                        
                        /*************************************�����б�־Ҳ����***********************************************/
                        g_TimeEnableDisable_A = 0;
                        g_TimeEnableDisable_B = 0;
                        
                        g_TimeFlag_A = 0;                               //�ر�ͨ��Aʱ�����
                        g_TimeFlag_B = 0;                               //�ر�ͨ��Bʱ�����
                        
                        FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //���涨ʱ��״̬
                        FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //���涨ʱ��״̬
                        
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //��ʱ��ʹ�ܻ�ʧ��
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //��ʱ��ʹ�ܻ�ʧ��
                        
                        LCDClrWin(0,2,127,7);                           //��ڲ�����
                        LCD_String("�Ƿ񱣴��������",8,2,13,16,NORMAL);//��ʾ������������ַ�
                        LCD_ASCII("?",112,2,7,16,NORMAL);                //��ʾ?�ַ�
                        
                        LCD_ASCII("(1)",37,4,7,16,NORMAL);              //��ʾ(1)����
                        LCD_String("��",58,4,13,16,NORMAL);             //��ʾ���ַ�
                        LCD_ASCII("(2)",37,6,7,16,NORMAL);              //��ʾ(2)����
                        LCD_String("��",58,6,13,16,NORMAL);             //��ʾ���ַ�
                        while(1)
                        {
                            //��ʾ���
                            Display_Batter(Power_flag);
                            //��ʾ��Դ
                            Display_Power(Power_flag);
                            
                            /*************************************��ȡ���������Ƿ��л�**************************************/
                            key = OSMboxAccept(KEYMbox);
                            if(*key == KEY_DOWN)
                            {
                                judge_new1++;
                                if(judge_new1 >= 3)
                                {
                                    judge_new1 = 1;
                                }
                            }
                            else if(*key == KEY_UP)
                            {
                                judge_new1--;
                                if(judge_new1 <= 0)
                                {
                                    judge_new1 = 2;
                                }
                            }
                            else if(*key == KEY_ENTER)
                            {
                                if(judge_new1 == 1)
                                {
                                    LCDClrWin(0,2,127,7);                                           //��ȫ��
                                    LCD_String("����λ��",20,2,13,16,NORMAL);                       //��ʾ������������ַ�
                                    LCD_ASCII("[",72,2,7,16,NORMAL);                                //��ʾ[�ַ�
                                    FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //�������ڴ洢�˶��ٸ��ļ�
                                    storage_number++;
                                    sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                                    LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                                    LCD_ASCII("]",100,2,7,16,NORMAL);                               //��ʾ]�ַ�
                                    
                                    /**********************************�洢����************************************/
                                    //�洢�����
                                    g_StorageData.number = storage_number;       
                                    //��ǰʱ��
                                    g_StorageData.now_year = g_RTCTime.year;                //�趨��ǰʱ��---��
                                    g_StorageData.now_month = g_RTCTime.month;              //�趨��ǰʱ��---��
                                    g_StorageData.now_day = g_RTCTime.day;                  //�趨��ǰʱ��---��
                                    g_StorageData.now_hour = g_RTCTime.hour;                //�趨��ǰʱ��---ʱ
                                    g_StorageData.now_minute = g_RTCTime.minute;            //�趨��ǰʱ��---��
                                    g_StorageData.now_second = g_RTCTime.second;            //�趨��ǰʱ��---��
                                    //�趨�Ĳɼ�ʱ��
                                    g_StorageData.sampling_hour_a = timer_hour_a;               //�趨�Ĳɼ�ʱ��---ʱ
                                    g_StorageData.sampling_minute_a = timer_minute_a;           //�趨�Ĳɼ�ʱ��---��
                                    g_StorageData.sampling_second_a = timer_second_a;           //�趨�Ĳɼ�ʱ��---��
                                    
                                    g_StorageData.sampling_hour_b = timer_hour_b;               //�趨�Ĳɼ�ʱ��---ʱ
                                    g_StorageData.sampling_minute_b = timer_minute_b;           //�趨�Ĳɼ�ʱ��---��
                                    g_StorageData.sampling_second_b = timer_second_b;           //�趨�Ĳɼ�ʱ��---��
                                    //ͨ����ѹֵ
                                    g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //���ĵ�ѹAֵ,�Ŵ�100���洢
                                    g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //���ĵ�ѹBֵ,�Ŵ�100���洢
                                    //��ѹֵ
                                    g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //������ѹֵ,�Ŵ�100���洢
                                    //�¶�ֵ
                                    //������
                                    if(g_Temperature.DQ3_exist == 0)
                                    {
                                        g_StorageData.heattemp = 0xffff;                                  //δ��⵽�¶ȴ�����
                                    }
                                    else
                                    {
                                        g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //���ļ������¶�ֵ,�Ŵ�100���洢
                                    }
                                    //ͨ��A
                                    if(g_Temperature.DQ1_exist == 0)
                                    {
                                        g_StorageData.temp_A = 0xffff;                                  //δ��⵽�¶ȴ�����
                                    }
                                    else
                                    {
                                        g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //����ͨ��A�¶�ֵ,�Ŵ�100���洢
                                    }
                                    //ͨ��B
                                    if(g_Temperature.DQ2_exist == 0)
                                    {
                                        g_StorageData.temp_B = 0xffff;                                  //δ��⵽�¶ȴ�����
                                    }
                                    else
                                    {
                                        g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //����ͨ��B�¶�ֵ,�Ŵ�100���洢
                                    }
                                    //����ֵ
                                    g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //ͨ��A����ֵ
                                    g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //ͨ��B����ֵ
                                    //�������ֵ
                                    g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//ͨ��A���
                                    g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//ͨ��B���
                                    //����������ֵ
                                    g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//ͨ��A������
                                    g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//ͨ��B������
                                      
                                    FM24C64_Data_Storage(storage_number,1);//��������
                                 
                                    /*************************************���򷵻�***********************************************/
                                    LCDClrWin(20,4,106,5);                                     //�岿����
                                    LCD_String("��������",20,4,13,16,NORMAL);                  //��ʾ������������ַ�
                                    LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //��ʾ...�ַ�
                                    while(1)
                                    {
                                        //��ʾ���
                                        Display_Batter(Power_flag);
                                        //��ʾ��Դ
                                        Display_Power(Power_flag);
                                        
                                        key = OSMboxAccept(KEYMbox);
                                        if((*key == KEY_CAL) || (*key == KEY_ENTER))
                                        {
                                            //����ǰһ���棬��ȫ��
                                            LCDClrWin(0,0,127,7);                           //��ȫ��
                                            flag2 = 0;                                      //����ˢ�����־
                                            return;
                                        }
                                    } 
                                }
                                else
                                {
                                    //����ǰһ���棬��ȫ��
                                    LCDClrWin(0,0,127,7);                           //��ȫ��
                                    flag2 = 0;                                      //����ˢ�����־
                                    return;
                                }
                            }
                            /*********************��ʾ��ͷָ�벿��***********************/
                            LCD_ASCII("-->",6,2*(judge_new1+1),7,16,NORMAL);//��ʾ��ͷ����
                            if (judge_old1 != judge_new1)
                            {	
                                LCDClrWin(6,2*(judge_old1+1),28,2*(judge_old1+1)+1);//�����һ������
                                judge_old1 = judge_new1;     
                            }
                        }
                    }
                    else
                    {
                        /*********************************��ʾ��ʼ�ĵ�һ����**************************************/
                        LCDClrWin(0,0,127,7);                           //��ȫ��
                        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                        LCD_String("������",0,0,13,16,MOVEUP);          //��ʾ�������ַ�
                        LCD_ASCII("...",39,0,7,16,MOVEUP);              //��ʾ�������ַ�
                        //���ص�һ����
                        fla1 = 0;
                        add_new = 1;                                   //�ָ���ʼ״̬
                        //�жϲ���״̬
                        if(sampling_a <= 0.001)
                        {
                            MOTOR_A_OFF();                              //�ر�����A
                        }
                        else
                        {
                            if(g_TimeFlag_A == 0)
                            {
                                MOTOR_A_OFF();                           //�ر�����A
                            }
                            else
                            {
                                MOTOR_A_ON();                            //������A
                            }
                        }
                        if(sampling_b <= 0.001)
                        {
                            MOTOR_B_OFF();                               //�ر�����B
                        }
                        else
                        {
                            if(g_TimeFlag_B == 0)
                            {
                                MOTOR_B_OFF();                           //�ر�����A
                            }
                            else
                            {
                                MOTOR_B_ON();                            //������A
                            }
                        }
//                        TIM_Cmd(TIM2, ENABLE);	                       //�򿪶�ʱ��2
                        PCF8563_TIE_EnableDisable(1);           //PCF8563��ʱ��ʹ��
                        break;
                    }
                }
                /*********************��ʾ��ͷָ�벿��***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//��ʾ��ͷ����
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//�����һ������
                    judge_old = judge_new;     
                }
            }
        }
         
        /*********************************�䶯����ɨ�貿��*************************************/
        if(add_new <= 3)
        {
            if(fla1 == 0)
            {
                //��һҳ�����ַ�����
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                LCD_ASCII("1/5",70,0,7,16,MOVEUP);              //��ʾ1/4�����ַ�
                LCD_String("��",25,2,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                LCD_String("ǰ",47,2,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                /*********************ͨ��A�ɼ�ʱ���ӡ***********************/
                LCD_String("��ʱ",25,4,13,16,NORMAL);           //��ʾ�趨�ַ�
                LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
                //ʱ
                sprintf(str,"%02d:\0",(uint8_t)immediately_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                //��
                sprintf(str,"%02d:\0",(uint8_t)immediately_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                 //��
                sprintf(str,"%02d\0", (uint8_t)immediately_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                
                /*********************ͨ��B�ɼ�ʱ���ӡ***********************/
                LCD_String("��ʱ",25,6,13,16,NORMAL);           //��ʾ��ʱ�ַ�
                LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
                //ʱ
                sprintf(str,"%02d:\0",(uint8_t)immediately_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                //��
                sprintf(str,"%02d:\0",(uint8_t)immediately_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                 //��
                sprintf(str,"%02d\0", (uint8_t)immediately_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                
                fla1 = 1;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************��ǰʱ���ȡ***********************/
            //ʱ
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //��
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //��
            sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************��ʾ��ͷָ�벿��***********************/
            
            LCD_ASCII("-->",3,2*add_new,7,16,NORMAL);//��ʾ��ͷ����
            if (add_old != add_new)
            {	
                LCDClrWin(3,2*add_old,24,2*add_old+1);//�����һ������
                add_old = add_new;     
            }
        }
        else if((add_new >= 4) && (add_new <= 6))
        {
            if(fla2 == 0)
            {
                //�ڶ�ҳ
                LCD_ASCII("2/5",70,0,7,16,MOVEUP);              //��ʾ2/4�����ַ�
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                /*********************ͨ��A��ʱʱ���ӡ***********************/
                LCD_String("��ʱ",25,2,13,16,NORMAL);           //��ʾ�����ַ�
                LCD_ASCII("A",51,2,7,16,NORMAL);                //��ʾA�ַ�
                
                /*********************ͨ��B��ʱʱ���ӡ***********************/
                LCD_String("��ʱ",25,4,13,16,NORMAL);           //��ʾ�����ַ�
                LCD_ASCII("B",51,4,7,16,NORMAL);                //��ʾA�ַ�
                
                /*********************ͨ��A������ӡ***********************/
                LCD_String("����",25,6,13,16,NORMAL);           //��ʾ�����ַ�
                LCD_ASCII("A",51,6,7,16,NORMAL);                //��ʾA�ַ�
                LCD_ASCII(":",58,6,7,16,NORMAL);                //��ʾ:�ַ�
                LCD_ASCII("L/min",92,6,7,16,NORMAL);            //��ʾ�¶�ֵ�ַ�
                
                Float2Str(sampling_a,str1,2);
                LCD_ASCII((uint8_t*)str1,64,6,7,16,NORMAL);
                
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 1;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************����ʱ���ȡ***********************/
            //ʱ
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_A);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //��
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_A);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //��
            sprintf(str,"%02d\0", (uint8_t)Timer_second_A);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************����ʱ���ȡ***********************/
            //ʱ
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_B);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //��
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_B);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //��
            sprintf(str,"%02d\0", (uint8_t)Timer_second_B);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            /*********************��ʾ��ͷָ�벿��***********************/
            LCD_ASCII("-->",3,2*(add_new-3),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 3)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-3),24,2*(add_old-3)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 7) && (add_new <= 9))
        {
            if(fla3 == 0)
            {
                //����ҳ
                LCD_ASCII("3/5",70,0,7,16,MOVEUP);              //��ʾ2/4�����ַ�
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                
                /*********************ͨ��B������ӡ***********************/
                LCD_String("����",25,2,13,16,NORMAL);           //��ʾ�����ַ�
                LCD_ASCII("B",51,2,7,16,NORMAL);                //��ʾB�ַ�
                LCD_ASCII(":",58,2,7,16,NORMAL);                //��ʾ:�ַ�
                LCD_ASCII("L/min",92,2,7,16,NORMAL);            //��ʾ��λֵ�ַ�

                LCD_String("��ѹ",25,4,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
                LCD_ASCII(":",58,4,7,16,NORMAL);                //��ʾ:�ַ�
                
                LCD_String("��ѹ",25,6,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
                LCD_ASCII(":",58,6,7,16,NORMAL);                //��ʾ:�ַ�
                
                //����B
                Float2Str(sampling_b,str1,2);
                LCD_ASCII((uint8_t*)str1,64,2,7,16,NORMAL);
                
                //����A��ѹ
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,64,4,7,16,NORMAL);               //����A��ѹ
                
                //����B��ѹ
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,64,6,7,16,NORMAL);               //����B��ѹ
                
                
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 1;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************��ѹֵ***********************/
            if(ad == 50)
            {
                //����A��ѹ
                LCDClrWin(64,4,127,3);                           //��ҳ��ʾ�䶯����
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,64,4,7,16,NORMAL);               //����A��ѹ
                
                //����B��ѹ
                LCDClrWin(64,6,127,5);                           //��ҳ��ʾ�䶯����
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,64,6,7,16,NORMAL);               //����B��ѹ
                ad = 0;
            }
            ad++;  
            /*********************��ʾ��ͷָ�벿��***********************/
            
            LCD_ASCII("-->",3,2*(add_new-6),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 6)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-6),24,2*(add_old-6)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 10) && (add_new <= 12))
        {
            if(fla4 == 0)
            {
                //����ҳ
                LCD_ASCII("4/5",70,0,7,16,MOVEUP);              //��ʾ3/4�����ַ�
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                LCD_String("������",30,2,13,16,NORMAL);         //��ʾ�������ַ�
                LCD_ASCII(":",69,2,7,16,NORMAL);                //��ʾ:�ַ�
                
                LCD_String("�¶�",30,4,13,16,NORMAL);           //��ʾ�¶��ַ�
                LCD_ASCII("A",58,4,7,16,NORMAL);                //��ʾA�ַ�
                LCD_ASCII(":",69,4,7,16,NORMAL);                //��ʾ:�ַ�
                
                LCD_String("�¶�",30,6,13,16,NORMAL);           //��ʾ�¶��ַ�
                LCD_ASCII("B",58,6,7,16,NORMAL);                //��ʾB�ַ�
                LCD_ASCII(":",69,6,7,16,NORMAL);                //��ʾ:�ַ�
                
                //������
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��A�¶�
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��B�¶�
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",107,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 1;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************�����¶�***********************/
            //�����¶�
            ad1++;
            if(ad1 > 50)
            {
                ad1 = 0;
                //������
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��A�¶�
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",104,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
                //ͨ��B�¶�
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",107,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                            LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                        }
                    }
                }
            }
            /*********************��ʾ��ͷָ�벿��***********************/
            LCD_ASCII("-->",6,2*(add_new-9),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 9)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-9),28,2*(add_old-9)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
        else if((add_new > 12) && (add_new <= 13))
        {
            if(fla5 == 0)
            {
                LCD_ASCII("5/5",70,0,7,16,MOVEUP);              //��ʾ3/4�����ַ�
                LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                
                LCD_String("��ѹ",30,2,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                LCD_ASCII(":",56,2,7,16,NORMAL);                //��ʾ:�ַ�
                fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                fla5 = 1;                                          //Ϊ������ʾ��ʼ����־5
            }
            /*********************��ѹֵ***********************/
            if(g_Pressure >= 100)
            {
                Float2Str(g_Pressure,tab4,2);
            }
            else
            {
                Float2Str(g_Pressure,tab4,3);
            }
            LCD_ASCII(tab4,63,2,7,16,NORMAL);
            LCD_ASCII("kPa",105,2,7,16,NORMAL); 
            
            /*********************��ʾ��ͷָ�벿��***********************/
            LCD_ASCII("-->",6,2*(add_new-12),7,16,NORMAL);                     //��ʾ��ͷ����
            if (add_old != add_new)
            {	
                if(add_old == 12)                                              //�ڶ�ҳ��ʼ����Ҫ����
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-12),28,2*(add_old-12)+1);            //�����һ������
                    add_old = add_new;   
                }
            }
        }
    }     
}




/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubContinue(void)
�������ܣ������ӽ��� �����������ӽ��� 
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubContinue(void)
{
    uint8_t *key;
    uint8_t judge_new1 = 1;
    uint8_t judge_old1 = 1;
    char str[10];
    
    LCDClrWin(0,0,127,7);                           //��ҳ��ʾ�䶯����
    LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
    LCD_String("��������",0,0,13,16,MOVEUP);        //��ʾ���������ַ�
    LCD_ASCII("...",52,0,7,16,MOVEUP);              //��ʾ�������ַ�
    
    LCD_String("�Ƿ�����ϴβ���",6,2,13,16,NORMAL);//��ʾ�Ƿ�����ϴβ����ַ�
    LCD_ASCII("?",110,2,7,16,NORMAL);               //��ʾ?�ַ�
    LCD_ASCII("-->",6,4,7,16,NORMAL);               //��ʾ��ͷ����
    LCD_ASCII("(1)",37,4,7,16,NORMAL);              //��ʾ(1)����
    LCD_String("��",58,4,13,16,NORMAL);             //��ʾ���ַ�
    LCD_ASCII("(2)",37,6,7,16,NORMAL);              //��ʾ(2)����
    LCD_String("��",58,6,13,16,NORMAL);             //��ʾ���ַ�
    
    /*δ��ɶ�ʱ��ʾ����*/
    g_Unfinish_Flag = 1;                         //δ��ɱ�־
    Timer_second = 30;                           //����30s����ʱ 
//    TIM_Cmd(TIM2, ENABLE);	                 //ʹ�ܶ�ʱ��2
    PCF8563_TIE_EnableDisable(1);           //PCF8563��ʱ��ʹ��
    while(1)
    {
        /*��ʾ30s����ʱ����*/
        sprintf(str,"%02d\0", (uint8_t)Timer_second);
        LCD_ASCII((uint8_t*)str,102,6,7,16,NORMAL);
        
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        /*************************************��ȡ���������Ƿ��л�**************************************/
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_DOWN)
        {
            judge_new1++;
            if(judge_new1 == 3)
            {
                judge_new1 = 1;
            }
        }
        else if(*key == KEY_UP)
        {
            judge_new1--;
            if(judge_new1 == 0)
            {
                judge_new1 = 2;
            }
        }
        else if(Timer_second <= 0)
        {
//            TIM_Cmd(TIM2, DISABLE);	                 //ʹ�ܶ�ʱ��2
            PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
            g_Unfinish_Flag = 0;                         //ֹͣ����ʱ
            
            if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 1)     //����Ƿ���δ��ɵĲ�����Ϊ��������δ��ɵĲ���      
            { 
                PMenu = ImmediatelyMenu;                        //ֱ�ӽ�����������ָ��
                g_UserChoose = 2;                               //����Ϊ�ڶ�����
                Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //����������Сʱֵ
                Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //���������ķ���ֵ
                Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //��������������ֵ
                
                Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //����������Сʱֵ
                Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //���������ķ���ֵ
                Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //��������������ֵ
                
                g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //�ָ���ʱ��״̬
                g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //�ָ���ʱ��״̬
                
                g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //��ʱ��ʹ�ܻ�ʧ��
                g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //��ʱ��ʹ�ܻ�ʧ��
                
                Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay();
                return;
            }
            else if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 2)//����Ƿ���δ��ɵĲ�����Ϊ��ʱ����δ��ɵĲ���
            {
                PMenu = TimingMenu;                        //ֱ�ӽ��붨ʱ����ָ��
                g_UserChoose = 2;                               //����Ϊ�ڶ�����
                Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //����������Сʱֵ
                Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //���������ķ���ֵ
                Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //��������������ֵ
                
                Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //����������Сʱֵ
                Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //���������ķ���ֵ
                Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //��������������ֵ
                
                g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //�ָ���ʱ��״̬
                g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //�ָ���ʱ��״̬
                
                g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //��ʱ��ʹ�ܻ�ʧ��
                g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //��ʱ��ʹ�ܻ�ʧ��
                
                Display_SamplingMenu_SubTiming_SubWait_SubUnderWay();
                return;
            }
        }
        else if(*key == KEY_ENTER)
        {
            if(judge_new1 == 1)
            {
//                TIM_Cmd(TIM2, DISABLE);	                     //ʹ�ܶ�ʱ��2
                PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
                g_Unfinish_Flag = 0;                         //ֹͣ����ʱ
                Timer_second = 0;                            //����
                
                if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 1)     //����Ƿ���δ��ɵĲ�����Ϊ��������δ��ɵĲ���      
                { 
                    PMenu = ImmediatelyMenu;                        //ֱ�ӽ�����������ָ��
                    g_UserChoose = 2;                               //����Ϊ�ڶ�����
                    Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //����������Сʱֵ
                    Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //���������ķ���ֵ
                    Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //��������������ֵ
                    
                    Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //����������Сʱֵ
                    Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //���������ķ���ֵ
                    Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //��������������ֵ
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //�ָ���ʱ��״̬
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //�ָ���ʱ��״̬
                    
                    g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //��ʱ��ʹ�ܻ�ʧ��
                    g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //��ʱ��ʹ�ܻ�ʧ��
                    
                    Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay();
                    return;
                }
                else if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 2)//����Ƿ���δ��ɵĲ�����Ϊ��ʱ����δ��ɵĲ���
                {
                    PMenu = TimingMenu;                        //ֱ�ӽ��붨ʱ����ָ��
                    g_UserChoose = 2;                               //����Ϊ�ڶ�����
                    Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //����������Сʱֵ
                    Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //���������ķ���ֵ
                    Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //��������������ֵ
                
                    Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //����������Сʱֵ
                    Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //���������ķ���ֵ
                    Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //��������������ֵ
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //�ָ���ʱ��״̬
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //�ָ���ʱ��״̬
                    
                    g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //��ʱ��ʹ�ܻ�ʧ��
                    g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //��ʱ��ʹ�ܻ�ʧ��
                    
                    Display_SamplingMenu_SubTiming_SubWait_SubUnderWay();
                    return;
                }
            }
            else
            {
//                TIM_Cmd(TIM2, DISABLE);	                              //ʹ�ܶ�ʱ��2
                PCF8563_TIE_EnableDisable(0);           //PCF8563��ʱ��ʧ��
                g_Unfinish_Flag = 0;                                  //ֹͣ����ʱ
                Timer_second = 0;                                     //����
                g_TimeFlag_A = 0;
                g_TimeFlag_B = 0;
                g_TimeEnableDisable_A = 0;
                g_TimeEnableDisable_B = 0;
                FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //��ʱ��ʹ�ܻ�ʧ��
                FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //��ʱ��ʹ�ܻ�ʧ��
                FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //�ָ���ʱ��״̬
                FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //�ָ���ʱ��״̬
                FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);           //д����ɱ�־
                //����ǰһ���棬��ȫ��
                LCDClrWin(0,0,127,7);                               //��ȫ��
                /*������ؽ����־����*/
                flag1 = 0;                                          //Ϊ������ʾ��ʼ����־1
                flag2 = 0;                                          //Ϊ������ʾ��ʼ����־2
                flag3 = 0;                                          //Ϊ������ʾ��ʼ����־3
                flag4 = 0;                                          //Ϊ������ʾ��ʼ����־4
                flag5 = 0;                                          //Ϊ������ʾ��ʼ����־5
                return;
            }
        }
        /*********************��ʾ��ͷָ�벿��***********************/
        LCD_ASCII("-->",6,2*(judge_new1+1),7,16,NORMAL);//��ʾ��ͷ����
        if (judge_old1 != judge_new1)
        {	
            LCDClrWin(6,2*(judge_old1+1),28,2*(judge_old1+1)+1);//�����һ������
            judge_old1 = judge_new1;     
        }
    }
}

/******************* �����ӽ��� ������������*****************/
/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubImmediately(void)
�������ܣ������ӽ��� �����������ӽ��� 
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubImmediately(void)
{
    char str[10];
    uint8_t immediately_hour_a = 0;         //������������Сʱʱ��00
    uint8_t immediately_minute_a = 0;       //�����������÷���ʱ��00
    uint8_t immediately_second_a = 0;       //����������������ʱ��00
    
    uint8_t immediately_hour_b = 0;         //������������Сʱʱ��00
    uint8_t immediately_minute_b = 0;       //�����������÷���ʱ��00
    uint8_t immediately_second_b = 0;       //����������������ʱ��00
    if(g_UserChoose < 2)
    {
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��������",38,0,13,16,MOVEUP);       //��ʾ���������ַ�
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�
        
            LCD_String("��ǰʱ��",8,2,13,16,NORMAL);        //��ʾ��ǰ�ַ�
            
            /*ͨ��A�ɼ�ʱ��*/
            LCD_String("��ʱ",25,4,13,16,NORMAL);           //��ʾ��ʱ�ַ�
            LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
            
            //ʱ
            FM24C64_READ_MUL(IMMEDIATELY_HOUR_A,(uint8_t*)&immediately_hour_a,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_hour_a);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //��
            FM24C64_READ_MUL(IMMEDIATELY_MINUTE_A,(uint8_t*)&immediately_minute_a,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_minute_a);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //��
            FM24C64_READ_MUL(IMMEDIATELY_SECOND_A,(uint8_t*)&immediately_second_a,1);
            sprintf(str,"%02d\0", (uint8_t)immediately_second_a);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            /*ͨ��B�ɼ�ʱ��*/
            LCD_String("��ʱ",25,6,13,16,NORMAL);           //��ʾ��ʱ�ַ�
            LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
            
            //ʱ
            FM24C64_READ_MUL(IMMEDIATELY_HOUR_B,(uint8_t*)&immediately_hour_b,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_hour_b);
            LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
            //��
            FM24C64_READ_MUL(IMMEDIATELY_MINUTE_B,(uint8_t*)&immediately_minute_b,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_minute_b);
            LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
             //��
            FM24C64_READ_MUL(IMMEDIATELY_SECOND_B,(uint8_t*)&immediately_second_b,1);
            sprintf(str,"%02d\0", (uint8_t)immediately_second_b);
            LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
            
            flag1 = 1;
            flag2 = 0;
        }
        //ʱ
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
        //��
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
        LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
         //��
        sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
        LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
        
        LCD_ASCII("-->",3,2*(g_UserChoose+2),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(3,2*(s_olderchoose+2),24,2*(s_olderchoose+2)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��������",38,0,13,16,MOVEUP);       //��ʾ��ʱ�����ַ�
            //�ڶ�ҳ
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            
            LCD_String("��������",38,2,13,16,NORMAL);       //���������ַ�
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",12,2*(g_UserChoose-1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 1)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(12,2*(s_olderchoose-1),33,2*(s_olderchoose-1)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubImmediately_IMMEDIATELY_A(void)
�������ܣ������ӽ��� �����������ӽ��� (���������ɼ�ʱ������)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubImmediately_IMMEDIATELY_A(void)
{
    uint8_t immediately_hour_a = 0;         //������������Сʱʱ��00
    uint8_t immediately_minute_a = 0;       //�����������÷���ʱ��00
    uint8_t immediately_second_a = 0;       //����������������ʱ��00
    
    uint8_t old_immediately_hour_a = 0;         //��������Сʱʱ��00
    uint8_t old_immediately_minute_a = 0;       //�������÷���ʱ��00
    uint8_t old_immediately_second_a = 0;       //������������ʱ��00
     //ʱ����
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_A,(uint8_t*)&immediately_hour_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_A,(uint8_t*)&immediately_minute_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_A,(uint8_t*)&immediately_second_a,1);
    
    old_immediately_hour_a = immediately_hour_a;
    old_immediately_minute_a = immediately_minute_a;
    old_immediately_second_a = immediately_second_a;
    
    int8_t hour_ten = immediately_hour_a / 10;                    //���ʱ��ʮλ����
    int8_t hour_one = immediately_hour_a % 10;                    //���ʱ�ĸ�λ����
    int8_t minute_ten = immediately_minute_a / 10;                //��÷ֵ�ʮλ����
    int8_t minute_one = immediately_minute_a % 10;                //��÷ֵĸ�λ����
    int8_t second_ten = immediately_second_a / 10;                //������ʮλ����
    int8_t second_one = immediately_second_a % 10;                //�����ĸ�λ����
    
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    hour_ten++;
                    if(hour_ten == 10)
                    {
                        hour_ten = 0;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one++;
                    if(hour_one == 10)
                    {
                        hour_one = 0;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten++;
                    if(minute_ten == 6)
                    {
                        minute_ten = 0;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one++;
                    if(minute_one == 10)
                    {
                        minute_one = 0;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten++;
                    if(second_ten == 6)
                    {
                        second_ten = 0;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one++;
                    if(second_one == 10)
                    {
                        second_one = 0;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    hour_ten--;
                    if(hour_ten < 0)
                    {
                        hour_ten = 9;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one--;
                    if(hour_one < 0)
                    {
                        hour_one = 9;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten--;
                    if(minute_ten < 0)
                    {
                        minute_ten = 5;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one--;
                    if(minute_one < 0)
                    {
                        minute_one = 9;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten--;
                    if(second_ten < 0)
                    {
                        second_ten = 5;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one--;
                    if(second_one < 0)
                    {
                        second_one = 9;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,NORMAL);}
                  
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,NORMAL);}
                  
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,NORMAL);}
                  
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,NORMAL);}
                  
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,4,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,4,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,4,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,4,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,4,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,4,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,4,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,4,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,4,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,4,7,16,NORMAL);}
                    
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,4,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,4,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,4,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,4,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,4,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,4,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,4,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,4,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,4,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,4,7,16,NORMAL);}
                    
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,4,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,4,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,4,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,4,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,4,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,4,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,4,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,4,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,4,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,4,7,16,NORMAL);}
                    
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,4,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,4,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,4,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,4,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,4,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,4,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,4,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,4,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,4,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,4,7,16,NORMAL);}
                    
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,4,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,4,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,4,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,4,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,4,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,4,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,4,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,4,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,4,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,4,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,4,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,4,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,4,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,4,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,4,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,4,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,4,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,4,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,4,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,4,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                immediately_hour_a = (hour_ten * 10 + hour_one);
                immediately_minute_a = (minute_ten * 10 + minute_one);
                immediately_second_a = (second_ten * 10 + second_one);
                
                FM24C64_WRITE_MUL(IMMEDIATELY_HOUR_A,(uint8_t*)&immediately_hour_a,1);
                FM24C64_WRITE_MUL(IMMEDIATELY_MINUTE_A,(uint8_t*)&immediately_minute_a,1);
                FM24C64_WRITE_MUL(IMMEDIATELY_SECOND_A,(uint8_t*)&immediately_second_a,1);
                
                sprintf(str,"%02d:\0", (uint8_t)immediately_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)immediately_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)immediately_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                sprintf(str,"%02d:\0", (uint8_t)old_immediately_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)old_immediately_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                
                sprintf(str,"%02d\0", (uint8_t)old_immediately_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                return; 
            }
        }
    }
}

/*
*******************************************************
�������ƣ�void Display_SamplingMenu_SubImmediately_IMMEDIATELY(void)
�������ܣ������ӽ��� �����������ӽ��� (���������ɼ�ʱ������)
��ڲ�������
���ڲ�������
*******************************************************
*/
void Display_SamplingMenu_SubImmediately_IMMEDIATELY_B(void)
{
    uint8_t immediately_hour_b = 0;         //������������Сʱʱ��00
    uint8_t immediately_minute_b = 0;       //�����������÷���ʱ��00
    uint8_t immediately_second_b = 0;       //����������������ʱ��00
    
    uint8_t old_immediately_hour_b = 0;         //��������Сʱʱ��00
    uint8_t old_immediately_minute_b = 0;       //�������÷���ʱ��00
    uint8_t old_immediately_second_b = 0;       //������������ʱ��00
     //ʱ����
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_B,(uint8_t*)&immediately_hour_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_B,(uint8_t*)&immediately_minute_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_B,(uint8_t*)&immediately_second_b,1);
    
    old_immediately_hour_b = immediately_hour_b;
    old_immediately_minute_b = immediately_minute_b;
    old_immediately_second_b = immediately_second_b;
    
    int8_t hour_ten = immediately_hour_b / 10;                    //���ʱ��ʮλ����
    int8_t hour_one = immediately_hour_b % 10;                    //���ʱ�ĸ�λ����
    int8_t minute_ten = immediately_minute_b / 10;                //��÷ֵ�ʮλ����
    int8_t minute_one = immediately_minute_b % 10;                //��÷ֵĸ�λ����
    int8_t second_ten = immediately_second_b / 10;                //������ʮλ����
    int8_t second_one = immediately_second_b % 10;                //�����ĸ�λ����
    
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
 if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
    
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        {
            if(*key == KEY_UP)
            {
                if(add == 1)
                {
                    hour_ten++;
                    if(hour_ten == 10)
                    {
                        hour_ten = 0;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one++;
                    if(hour_one == 10)
                    {
                        hour_one = 0;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten++;
                    if(minute_ten == 6)
                    {
                        minute_ten = 0;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one++;
                    if(minute_one == 10)
                    {
                        minute_one = 0;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten++;
                    if(second_ten == 6)
                    {
                        second_ten = 0;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one++;
                    if(second_one == 10)
                    {
                        second_one = 0;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_DOWN)
            {
                if(add == 1)
                {
                    hour_ten--;
                    if(hour_ten < 0)
                    {
                        hour_ten = 9;
                    }
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    hour_one--;
                    if(hour_one < 0)
                    {
                        hour_one = 9;
                    }
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    minute_ten--;
                    if(minute_ten < 0)
                    {
                        minute_ten = 5;
                    }
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    minute_one--;
                    if(minute_one < 0)
                    {
                        minute_one = 9;
                    }
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    second_ten--;
                    if(second_ten < 0)
                    {
                        second_ten = 5;
                    }
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    second_one--;
                    if(second_one < 0)
                    {
                        second_one = 9;
                    }
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                } 
            }
            else if(*key == KEY_LEFT)
            {
                add--;
                if(add == 0)
                {
                    add = 6;
                }
                if(add == 1)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,NORMAL);}
                  
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,NORMAL);}
                  
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,NORMAL);}
                  
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,NORMAL);}
                  
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_RIGHT)
            {
                add++;
                if(add == 7)
                {
                    add = 1;
                }
                if(add == 1)
                {
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,NORMAL);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,NORMAL);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,NORMAL);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,NORMAL);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,NORMAL);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,NORMAL);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,NORMAL);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,NORMAL);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,NORMAL);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,NORMAL);}
                    
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,INVERSER);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,INVERSER);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,INVERSER);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,INVERSER);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,INVERSER);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,INVERSER);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,INVERSER);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,INVERSER);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,INVERSER);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,INVERSER);}
                }
                else if(add == 2)
                {
                    if(hour_ten == 0)          {LCD_ASCII("0",64,6,7,16,NORMAL);}
                    else if(hour_ten == 1)     {LCD_ASCII("1",64,6,7,16,NORMAL);}
                    else if(hour_ten == 2)     {LCD_ASCII("2",64,6,7,16,NORMAL);}
                    else if(hour_ten == 3)     {LCD_ASCII("3",64,6,7,16,NORMAL);}
                    else if(hour_ten == 4)     {LCD_ASCII("4",64,6,7,16,NORMAL);}
                    else if(hour_ten == 5)     {LCD_ASCII("5",64,6,7,16,NORMAL);}
                    else if(hour_ten == 6)     {LCD_ASCII("6",64,6,7,16,NORMAL);}
                    else if(hour_ten == 7)     {LCD_ASCII("7",64,6,7,16,NORMAL);}
                    else if(hour_ten == 8)     {LCD_ASCII("8",64,6,7,16,NORMAL);}
                    else if(hour_ten == 9)     {LCD_ASCII("9",64,6,7,16,NORMAL);}
                    
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,INVERSER);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,INVERSER);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,INVERSER);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,INVERSER);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,INVERSER);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,INVERSER);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,INVERSER);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,INVERSER);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,INVERSER);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,INVERSER);}
                }
                else if(add == 3)
                {
                    if(hour_one == 0)          {LCD_ASCII("0",71,6,7,16,NORMAL);}
                    else if(hour_one == 1)     {LCD_ASCII("1",71,6,7,16,NORMAL);}
                    else if(hour_one == 2)     {LCD_ASCII("2",71,6,7,16,NORMAL);}
                    else if(hour_one == 3)     {LCD_ASCII("3",71,6,7,16,NORMAL);}
                    else if(hour_one == 4)     {LCD_ASCII("4",71,6,7,16,NORMAL);}
                    else if(hour_one == 5)     {LCD_ASCII("5",71,6,7,16,NORMAL);}
                    else if(hour_one == 6)     {LCD_ASCII("6",71,6,7,16,NORMAL);}
                    else if(hour_one == 7)     {LCD_ASCII("7",71,6,7,16,NORMAL);}
                    else if(hour_one == 8)     {LCD_ASCII("8",71,6,7,16,NORMAL);}
                    else if(hour_one == 9)     {LCD_ASCII("9",71,6,7,16,NORMAL);}
                    
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,INVERSER);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,INVERSER);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,INVERSER);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,INVERSER);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,INVERSER);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,INVERSER);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,INVERSER);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,INVERSER);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,INVERSER);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,INVERSER);}
                }
                else if(add == 4)
                {
                    if(minute_ten == 0)          {LCD_ASCII("0",85,6,7,16,NORMAL);}
                    else if(minute_ten == 1)     {LCD_ASCII("1",85,6,7,16,NORMAL);}
                    else if(minute_ten == 2)     {LCD_ASCII("2",85,6,7,16,NORMAL);}
                    else if(minute_ten == 3)     {LCD_ASCII("3",85,6,7,16,NORMAL);}
                    else if(minute_ten == 4)     {LCD_ASCII("4",85,6,7,16,NORMAL);}
                    else if(minute_ten == 5)     {LCD_ASCII("5",85,6,7,16,NORMAL);}
                    else if(minute_ten == 6)     {LCD_ASCII("6",85,6,7,16,NORMAL);}
                    else if(minute_ten == 7)     {LCD_ASCII("7",85,6,7,16,NORMAL);}
                    else if(minute_ten == 8)     {LCD_ASCII("8",85,6,7,16,NORMAL);}
                    else if(minute_ten == 9)     {LCD_ASCII("9",85,6,7,16,NORMAL);}
                    
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,INVERSER);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,INVERSER);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,INVERSER);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,INVERSER);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,INVERSER);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,INVERSER);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,INVERSER);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,INVERSER);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,INVERSER);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,INVERSER);}
                }
                else if(add == 5)
                {
                    if(minute_one == 0)          {LCD_ASCII("0",92,6,7,16,NORMAL);}
                    else if(minute_one == 1)     {LCD_ASCII("1",92,6,7,16,NORMAL);}
                    else if(minute_one == 2)     {LCD_ASCII("2",92,6,7,16,NORMAL);}
                    else if(minute_one == 3)     {LCD_ASCII("3",92,6,7,16,NORMAL);}
                    else if(minute_one == 4)     {LCD_ASCII("4",92,6,7,16,NORMAL);}
                    else if(minute_one == 5)     {LCD_ASCII("5",92,6,7,16,NORMAL);}
                    else if(minute_one == 6)     {LCD_ASCII("6",92,6,7,16,NORMAL);}
                    else if(minute_one == 7)     {LCD_ASCII("7",92,6,7,16,NORMAL);}
                    else if(minute_one == 8)     {LCD_ASCII("8",92,6,7,16,NORMAL);}
                    else if(minute_one == 9)     {LCD_ASCII("9",92,6,7,16,NORMAL);}
                    
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,INVERSER);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,INVERSER);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,INVERSER);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,INVERSER);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,INVERSER);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,INVERSER);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,INVERSER);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,INVERSER);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,INVERSER);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,INVERSER);}
                }
                else if(add == 6)
                {
                    if(second_ten == 0)          {LCD_ASCII("0",106,6,7,16,NORMAL);}
                    else if(second_ten == 1)     {LCD_ASCII("1",106,6,7,16,NORMAL);}
                    else if(second_ten == 2)     {LCD_ASCII("2",106,6,7,16,NORMAL);}
                    else if(second_ten == 3)     {LCD_ASCII("3",106,6,7,16,NORMAL);}
                    else if(second_ten == 4)     {LCD_ASCII("4",106,6,7,16,NORMAL);}
                    else if(second_ten == 5)     {LCD_ASCII("5",106,6,7,16,NORMAL);}
                    else if(second_ten == 6)     {LCD_ASCII("6",106,6,7,16,NORMAL);}
                    else if(second_ten == 7)     {LCD_ASCII("7",106,6,7,16,NORMAL);}
                    else if(second_ten == 8)     {LCD_ASCII("8",106,6,7,16,NORMAL);}
                    else if(second_ten == 9)     {LCD_ASCII("9",106,6,7,16,NORMAL);}
                    
                    if(second_one == 0)          {LCD_ASCII("0",113,6,7,16,INVERSER);}
                    else if(second_one == 1)     {LCD_ASCII("1",113,6,7,16,INVERSER);}
                    else if(second_one == 2)     {LCD_ASCII("2",113,6,7,16,INVERSER);}
                    else if(second_one == 3)     {LCD_ASCII("3",113,6,7,16,INVERSER);}
                    else if(second_one == 4)     {LCD_ASCII("4",113,6,7,16,INVERSER);}
                    else if(second_one == 5)     {LCD_ASCII("5",113,6,7,16,INVERSER);}
                    else if(second_one == 6)     {LCD_ASCII("6",113,6,7,16,INVERSER);}
                    else if(second_one == 7)     {LCD_ASCII("7",113,6,7,16,INVERSER);}
                    else if(second_one == 8)     {LCD_ASCII("8",113,6,7,16,INVERSER);}
                    else if(second_one == 9)     {LCD_ASCII("9",113,6,7,16,INVERSER);}
                }
            }
            else if(*key == KEY_ENTER)
            {
                immediately_hour_b = (hour_ten * 10 + hour_one);
                immediately_minute_b = (minute_ten * 10 + minute_one);
                immediately_second_b = (second_ten * 10 + second_one);
                
                FM24C64_WRITE_MUL(IMMEDIATELY_HOUR_B,(uint8_t*)&immediately_hour_b,1);
                FM24C64_WRITE_MUL(IMMEDIATELY_MINUTE_B,(uint8_t*)&immediately_minute_b,1);
                FM24C64_WRITE_MUL(IMMEDIATELY_SECOND_B,(uint8_t*)&immediately_second_b,1);
                
                sprintf(str,"%02d:\0", (uint8_t)immediately_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)immediately_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);

                sprintf(str,"%02d\0", (uint8_t)immediately_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                sprintf(str,"%02d:\0", (uint8_t)old_immediately_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                
                sprintf(str,"%02d:\0", (uint8_t)old_immediately_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                
                sprintf(str,"%02d\0", (uint8_t)old_immediately_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                return; 
            }
        }
    }
}

/****************************** ��ѯ���� ��������******************************/

/*
********************************************************************************
�������ƣ�void Display_SeekMenu1(void)
�������ܣ���ѯ����˵���ʾ1
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_SeekMenu1(void)
{
    uint8_t file_number = 0;
    char str[10];
    if(g_UserChoose < 3)
    {
        //��ֹ����ˢ�ظ��Ľ���
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��ѯ",50,0,13,16,MOVEUP);           //��ʾ��ѯ�ַ�
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�
            LCD_String("�ļ���",37,2,13,16,NORMAL);         //��ʾ�ļ����ַ�
            LCD_ASCII("[",76,2,7,16,NORMAL);                //��ʾ[�ַ�
            
            FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1); 
            sprintf(str,"%03d\0", (uint8_t)file_number);
            LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);         //��ʾ�����ֵ
            
            LCD_ASCII("]",104,2,7,16,NORMAL);               //��ʾ]�ַ�
            LCD_String("�ļ��Ϸ�",37,4,13,16,NORMAL);       //��ʾ�ļ��Ϸ��ַ�
            LCD_String("�ļ��·�",37,6,13,16,NORMAL);       //��ʾ�ļ��·��ַ�
            flag1 = 1;
            flag2 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��ѯ",50,0,13,16,MOVEUP);           //��ʾ��ѯ�ַ�
            //�ڶ�ҳ
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            LCD_String("�ļ���ϸ",37,2,13,16,NORMAL);       //��ʾ�ļ���ϸ�ַ�
            LCD_String("�ļ�����",37,4,13,16,NORMAL);       //�ļ�����
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
********************************************************************************
�������ƣ�void Display_SeekMenu1_FILE_NUMBER(void)
�������ܣ���ѯ����˵���ʾ1--(�ļ��������)
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_SeekMenu1_FILE_NUMBER(void)
{
    uint8_t file_number = 0;         //�ļ�������
    uint8_t old_file_number = 0;     //����ϵ��ļ���
    
    int8_t file_number_hundred = 0;   //�ļ��ŵİ�λ
    int8_t file_number_ten = 0;       //�ļ��ŵ�ʮλ
    int8_t file_number_one = 0;       //�ļ��ŵĸ�λ
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    old_file_number = file_number;
    
    file_number_hundred = file_number / 100;
    file_number_ten = file_number / 10 % 10;
    file_number_one = file_number % 10;
    
    //����λ���з���
    if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,INVERSER);}
    else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,INVERSER);}
    else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,INVERSER);}

    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(add == 1)
            {
                file_number_hundred++;
                if(file_number_hundred == 2)
                {
                    file_number_hundred = 0;
                }
                if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                file_number_ten++;
                if(file_number_ten == 10)
                {
                    file_number_ten = 0;
                }
                if(file_number_ten == 0)           {LCD_ASCII("0",90,2,7,16,INVERSER);}
                else if(file_number_ten == 1)      {LCD_ASCII("1",90,2,7,16,INVERSER);}
                else if(file_number_ten == 2)      {LCD_ASCII("2",90,2,7,16,INVERSER);}
                else if(file_number_ten == 3)      {LCD_ASCII("3",90,2,7,16,INVERSER);}
                else if(file_number_ten == 4)      {LCD_ASCII("4",90,2,7,16,INVERSER);}
                else if(file_number_ten == 5)      {LCD_ASCII("5",90,2,7,16,INVERSER);}
                else if(file_number_ten == 6)      {LCD_ASCII("6",90,2,7,16,INVERSER);}
                else if(file_number_ten == 7)      {LCD_ASCII("7",90,2,7,16,INVERSER);}
                else if(file_number_ten == 8)      {LCD_ASCII("8",90,2,7,16,INVERSER);}
                else if(file_number_ten == 9)      {LCD_ASCII("9",90,2,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                file_number_one++;
                if(file_number_one == 10)
                {
                    file_number_one = 0;
                }
                if(file_number_one == 0)           {LCD_ASCII("0",97,2,7,16,INVERSER);}
                else if(file_number_one == 1)      {LCD_ASCII("1",97,2,7,16,INVERSER);}
                else if(file_number_one == 2)      {LCD_ASCII("2",97,2,7,16,INVERSER);}
                else if(file_number_one == 3)      {LCD_ASCII("3",97,2,7,16,INVERSER);}
                else if(file_number_one == 4)      {LCD_ASCII("4",97,2,7,16,INVERSER);}
                else if(file_number_one == 5)      {LCD_ASCII("5",97,2,7,16,INVERSER);}
                else if(file_number_one == 6)      {LCD_ASCII("6",97,2,7,16,INVERSER);}
                else if(file_number_one == 7)      {LCD_ASCII("7",97,2,7,16,INVERSER);}
                else if(file_number_one == 8)      {LCD_ASCII("8",97,2,7,16,INVERSER);}
                else if(file_number_one == 9)      {LCD_ASCII("9",97,2,7,16,INVERSER);}
            }    
        }
        else if(*key == KEY_DOWN)
        {
            if(add == 1)
            {
                file_number_hundred--;
                if(file_number_hundred < 0)
                {
                    file_number_hundred = 1;
                }
                if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                file_number_ten--;
                if(file_number_ten < 0)
                {
                    file_number_ten = 9;
                }
                if(file_number_ten == 0)           {LCD_ASCII("0",90,2,7,16,INVERSER);}
                else if(file_number_ten == 1)      {LCD_ASCII("1",90,2,7,16,INVERSER);}
                else if(file_number_ten == 2)      {LCD_ASCII("2",90,2,7,16,INVERSER);}
                else if(file_number_ten == 3)      {LCD_ASCII("3",90,2,7,16,INVERSER);}
                else if(file_number_ten == 4)      {LCD_ASCII("4",90,2,7,16,INVERSER);}
                else if(file_number_ten == 5)      {LCD_ASCII("5",90,2,7,16,INVERSER);}
                else if(file_number_ten == 6)      {LCD_ASCII("6",90,2,7,16,INVERSER);}
                else if(file_number_ten == 7)      {LCD_ASCII("7",90,2,7,16,INVERSER);}
                else if(file_number_ten == 8)      {LCD_ASCII("8",90,2,7,16,INVERSER);}
                else if(file_number_ten == 9)      {LCD_ASCII("9",90,2,7,16,INVERSER);}
            }
            else if(add == 3)
            {
                file_number_one--;
                if(file_number_one < 0)
                {
                    file_number_one = 9;
                }
                if(file_number_one == 0)           {LCD_ASCII("0",97,2,7,16,INVERSER);}
                else if(file_number_one == 1)      {LCD_ASCII("1",97,2,7,16,INVERSER);}
                else if(file_number_one == 2)      {LCD_ASCII("2",97,2,7,16,INVERSER);}
                else if(file_number_one == 3)      {LCD_ASCII("3",97,2,7,16,INVERSER);}
                else if(file_number_one == 4)      {LCD_ASCII("4",97,2,7,16,INVERSER);}
                else if(file_number_one == 5)      {LCD_ASCII("5",97,2,7,16,INVERSER);}
                else if(file_number_one == 6)      {LCD_ASCII("6",97,2,7,16,INVERSER);}
                else if(file_number_one == 7)      {LCD_ASCII("7",97,2,7,16,INVERSER);}
                else if(file_number_one == 8)      {LCD_ASCII("8",97,2,7,16,INVERSER);}
                else if(file_number_one == 9)      {LCD_ASCII("9",97,2,7,16,INVERSER);}
            } 
        }
        else if(*key == KEY_LEFT)
        {
            add--;
            if(add == 0)
            {
                add = 3;
            }
            if(add == 1)
            {   
                if(file_number_ten == 0)           {LCD_ASCII("0",90,2,7,16,NORMAL);}
                else if(file_number_ten == 1)      {LCD_ASCII("1",90,2,7,16,NORMAL);}
                else if(file_number_ten == 2)      {LCD_ASCII("2",90,2,7,16,NORMAL);}
                else if(file_number_ten == 3)      {LCD_ASCII("3",90,2,7,16,NORMAL);}
                else if(file_number_ten == 4)      {LCD_ASCII("4",90,2,7,16,NORMAL);}
                else if(file_number_ten == 5)      {LCD_ASCII("5",90,2,7,16,NORMAL);}
                else if(file_number_ten == 6)      {LCD_ASCII("6",90,2,7,16,NORMAL);}
                else if(file_number_ten == 7)      {LCD_ASCII("7",90,2,7,16,NORMAL);}
                else if(file_number_ten == 8)      {LCD_ASCII("8",90,2,7,16,NORMAL);}
                else if(file_number_ten == 9)      {LCD_ASCII("9",90,2,7,16,NORMAL);}
                
                if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,INVERSER);}
            }
            else if(add == 2)
            {
                if(file_number_ten == 0)           {LCD_ASCII("0",90,2,7,16,INVERSER);}
                else if(file_number_ten == 1)      {LCD_ASCII("1",90,2,7,16,INVERSER);}
                else if(file_number_ten == 2)      {LCD_ASCII("2",90,2,7,16,INVERSER);}
                else if(file_number_ten == 3)      {LCD_ASCII("3",90,2,7,16,INVERSER);}
                else if(file_number_ten == 4)      {LCD_ASCII("4",90,2,7,16,INVERSER);}
                else if(file_number_ten == 5)      {LCD_ASCII("5",90,2,7,16,INVERSER);}
                else if(file_number_ten == 6)      {LCD_ASCII("6",90,2,7,16,INVERSER);}
                else if(file_number_ten == 7)      {LCD_ASCII("7",90,2,7,16,INVERSER);}
                else if(file_number_ten == 8)      {LCD_ASCII("8",90,2,7,16,INVERSER);}
                else if(file_number_ten == 9)      {LCD_ASCII("9",90,2,7,16,INVERSER);}
                
                if(file_number_one == 0)           {LCD_ASCII("0",97,2,7,16,NORMAL);}
                else if(file_number_one == 1)      {LCD_ASCII("1",97,2,7,16,NORMAL);}
                else if(file_number_one == 2)      {LCD_ASCII("2",97,2,7,16,NORMAL);}
                else if(file_number_one == 3)      {LCD_ASCII("3",97,2,7,16,NORMAL);}
                else if(file_number_one == 4)      {LCD_ASCII("4",97,2,7,16,NORMAL);}
                else if(file_number_one == 5)      {LCD_ASCII("5",97,2,7,16,NORMAL);}
                else if(file_number_one == 6)      {LCD_ASCII("6",97,2,7,16,NORMAL);}
                else if(file_number_one == 7)      {LCD_ASCII("7",97,2,7,16,NORMAL);}
                else if(file_number_one == 8)      {LCD_ASCII("8",97,2,7,16,NORMAL);}
                else if(file_number_one == 9)      {LCD_ASCII("9",97,2,7,16,NORMAL);}
            }
            else if(add == 3)
            {
                if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,NORMAL);}
                else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,NORMAL);}
                else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,NORMAL);}
                
                if(file_number_one == 0)           {LCD_ASCII("0",97,2,7,16,INVERSER);}
                else if(file_number_one == 1)      {LCD_ASCII("1",97,2,7,16,INVERSER);}
                else if(file_number_one == 2)      {LCD_ASCII("2",97,2,7,16,INVERSER);}
                else if(file_number_one == 3)      {LCD_ASCII("3",97,2,7,16,INVERSER);}
                else if(file_number_one == 4)      {LCD_ASCII("4",97,2,7,16,INVERSER);}
                else if(file_number_one == 5)      {LCD_ASCII("5",97,2,7,16,INVERSER);}
                else if(file_number_one == 6)      {LCD_ASCII("6",97,2,7,16,INVERSER);}
                else if(file_number_one == 7)      {LCD_ASCII("7",97,2,7,16,INVERSER);}
                else if(file_number_one == 8)      {LCD_ASCII("8",97,2,7,16,INVERSER);}
                else if(file_number_one == 9)      {LCD_ASCII("9",97,2,7,16,INVERSER);}
            }
        }
        else if(*key == KEY_RIGHT)
        {
            add++;
            if(add == 4)
            {
                add = 1;
            }
            if(add == 1)
            {   
                if(file_number_one == 0)           {LCD_ASCII("0",97,2,7,16,NORMAL);}
                else if(file_number_one == 1)      {LCD_ASCII("1",97,2,7,16,NORMAL);}
                else if(file_number_one == 2)      {LCD_ASCII("2",97,2,7,16,NORMAL);}
                else if(file_number_one == 3)      {LCD_ASCII("3",97,2,7,16,NORMAL);}
                else if(file_number_one == 4)      {LCD_ASCII("4",97,2,7,16,NORMAL);}
                else if(file_number_one == 5)      {LCD_ASCII("5",97,2,7,16,NORMAL);}
                else if(file_number_one == 6)      {LCD_ASCII("6",97,2,7,16,NORMAL);}
                else if(file_number_one == 7)      {LCD_ASCII("7",97,2,7,16,NORMAL);}
                else if(file_number_one == 8)      {LCD_ASCII("8",97,2,7,16,NORMAL);}
                else if(file_number_one == 9)      {LCD_ASCII("9",97,2,7,16,NORMAL);}
                
                if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,INVERSER);}
                else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,INVERSER);}
                
            }
            else if(add == 2)
            {
                if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,NORMAL);}
                else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,NORMAL);}
                else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,NORMAL);}
                
                if(file_number_ten == 0)           {LCD_ASCII("0",90,2,7,16,INVERSER);}
                else if(file_number_ten == 1)      {LCD_ASCII("1",90,2,7,16,INVERSER);}
                else if(file_number_ten == 2)      {LCD_ASCII("2",90,2,7,16,INVERSER);}
                else if(file_number_ten == 3)      {LCD_ASCII("3",90,2,7,16,INVERSER);}
                else if(file_number_ten == 4)      {LCD_ASCII("4",90,2,7,16,INVERSER);}
                else if(file_number_ten == 5)      {LCD_ASCII("5",90,2,7,16,INVERSER);}
                else if(file_number_ten == 6)      {LCD_ASCII("6",90,2,7,16,INVERSER);}
                else if(file_number_ten == 7)      {LCD_ASCII("7",90,2,7,16,INVERSER);}
                else if(file_number_ten == 8)      {LCD_ASCII("8",90,2,7,16,INVERSER);}
                else if(file_number_ten == 9)      {LCD_ASCII("9",90,2,7,16,INVERSER);}
            }
            else if(add == 3)
            { 
                if(file_number_one == 0)           {LCD_ASCII("0",97,2,7,16,INVERSER);}
                else if(file_number_one == 1)      {LCD_ASCII("1",97,2,7,16,INVERSER);}
                else if(file_number_one == 2)      {LCD_ASCII("2",97,2,7,16,INVERSER);}
                else if(file_number_one == 3)      {LCD_ASCII("3",97,2,7,16,INVERSER);}
                else if(file_number_one == 4)      {LCD_ASCII("4",97,2,7,16,INVERSER);}
                else if(file_number_one == 5)      {LCD_ASCII("5",97,2,7,16,INVERSER);}
                else if(file_number_one == 6)      {LCD_ASCII("6",97,2,7,16,INVERSER);}
                else if(file_number_one == 7)      {LCD_ASCII("7",97,2,7,16,INVERSER);}
                else if(file_number_one == 8)      {LCD_ASCII("8",97,2,7,16,INVERSER);}
                else if(file_number_one == 9)      {LCD_ASCII("9",97,2,7,16,INVERSER);}
                
                if(file_number_ten == 0)           {LCD_ASCII("0",90,2,7,16,NORMAL);}
                else if(file_number_ten == 1)      {LCD_ASCII("1",90,2,7,16,NORMAL);}
                else if(file_number_ten == 2)      {LCD_ASCII("2",90,2,7,16,NORMAL);}
                else if(file_number_ten == 3)      {LCD_ASCII("3",90,2,7,16,NORMAL);}
                else if(file_number_ten == 4)      {LCD_ASCII("4",90,2,7,16,NORMAL);}
                else if(file_number_ten == 5)      {LCD_ASCII("5",90,2,7,16,NORMAL);}
                else if(file_number_ten == 6)      {LCD_ASCII("6",90,2,7,16,NORMAL);}
                else if(file_number_ten == 7)      {LCD_ASCII("7",90,2,7,16,NORMAL);}
                else if(file_number_ten == 8)      {LCD_ASCII("8",90,2,7,16,NORMAL);}
                else if(file_number_ten == 9)      {LCD_ASCII("9",90,2,7,16,NORMAL);}
            }
        }
        else if(*key == KEY_ENTER)
        {
            
            file_number = (file_number_hundred*100 + file_number_ten*10 + file_number_one);
            if(file_number > 180)
            {
                file_number = 180;
            }
            if(file_number <= 0)
            {
                file_number = 1;
            }
            sprintf(str,"%03d\0", (uint8_t)file_number);
            LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);
            FM24C64_WRITE_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
            return;
        }
        else if(*key == KEY_CAL)
        {
            sprintf(str,"%03d\0", (uint8_t)old_file_number);
            LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);
            return;
        }
    }   
}

/*
********************************************************************************
�������ƣ�void Display_SeekMenu1_UPTURN(void)
�������ܣ���ѯ����˵���ʾ1--(�ļ��Ϸ�)
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_SeekMenu1_UPTURN(void)
{
    uint8_t file_number = 0;         //�ļ�������
    
    char str[10];
    
    FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    
    LCD_String("�ļ��Ϸ�",37,4,13,16,INVERSER);       //�����ļ��Ϸ��ַ�
    
    file_number++;
    if(file_number > 180)
    {
        file_number = 1;
    }
    
    sprintf(str,"%03d\0", (uint8_t)file_number);
    LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);
    FM24C64_WRITE_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    OSTimeDly(10);
    LCD_String("�ļ��Ϸ�",37,4,13,16,NORMAL);       //�����ļ��Ϸ��ַ�
    return;
}

/*
********************************************************************************
�������ƣ�void Display_SeekMenu1_DOWNTURN(void)
�������ܣ���ѯ����˵���ʾ1--(�ļ��·�)
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_SeekMenu1_DOWNTURN(void)
{
    int32_t file_number = 0;         //�ļ�������

    char str[10];
    
    FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    
    LCD_String("�ļ��·�",37,6,13,16,INVERSER);       //�����ļ��Ϸ��ַ�
    
    file_number--;
    if(file_number <= 0)
    {
        file_number = 180;
    }
    
    sprintf(str,"%03d\0", (uint8_t)file_number);
    LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);
    FM24C64_WRITE_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    OSTimeDly(10);
    LCD_String("�ļ��·�",37,6,13,16,NORMAL);       //�����ļ��Ϸ��ַ�
    return;
}

/**************** ��ѯ�ӽ��� �ļ���ϸ��ѯ*******************/

/*
************************************************
�������ƣ�void Display_SeekMenu2_SubFile1(void)
�������ܣ���ѯ�ӽ��� �ļ���ϸ��ѯ��ʾ1
��ڲ�������
���ڲ�������
************************************************
*/
void Display_SeekMenu2_SubFile1(void)
{
    uint8_t file_number = 0;
    uint8_t number = 0;
    uint8_t key_new = 1;
    uint8_t key_old = 1;
    
    uint8_t fla1 = 0;                                          //Ϊ������ʾ��ʼ����־1
    uint8_t fla2 = 0;                                          //Ϊ������ʾ��ʼ����־2
    uint8_t fla3 = 0;                                          //Ϊ������ʾ��ʼ����־3
    uint8_t fla4 = 0;                                          //Ϊ������ʾ��ʼ����־4
    uint8_t fla5 = 0;                                          //Ϊ������ʾ��ʼ����־5
    uint8_t fla6 = 0;
    
    uint8_t tab1[10];
    uint8_t tab2[10];
    uint8_t tab3[10];
    uint8_t tab4[10];
    uint8_t tab5[10];
    uint8_t tab6[10];
    
    uint8_t *key;
    char str[10];
    uint8_t str1[10];
    
    FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1); 
    FM24C64_READ_MUL((STORAGE_START + (file_number-1)*43), (uint8_t*)&number, 1);       //��ȡ�洢�����
    
    //�˿ռ�û�д洢����
    if(number == 0)
    {
        LCDClrWin(0,2,127,7);                           //�岿����
        LCD_String("�ļ�Ϊ��",34,2,13,16,NORMAL);       //��ʾ�ļ��ַ�
        LCD_ASCII("!",86,2,7,16,NORMAL);                //��ʾ[�ַ�
        while(1)
        {
            //��ʾ���
            Display_Batter(Power_flag);
            //��ʾ��Դ
            Display_Power(Power_flag);
            
            key = OSMboxAccept(KEYMbox);
            if((*key == KEY_CAL) || (*key == KEY_ENTER))
            {
                LCDClrWin(0,0,127,7);                           //��ȫ��
                LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                LCD_String("��ѯ",50,0,13,16,MOVEUP);           //��ʾ��ѯ�ַ�
                LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�   
                flag2 = 0;
                return;
            }
        }
    }
    //Ҫ�������ݿռ��
    else if(number == file_number)
    {
        /***********************************��������***************************************/
        FM24C64_Data_Storage(file_number,0);//��ȡ����
        LCDClrWin(0,0,127,7);                           //��ȫ��
        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
        LCD_String("�ļ�",34,0,13,16,MOVEUP);           //��ʾ�ļ��ַ�
        LCD_ASCII("[",60,0,7,16,MOVEUP);                //��ʾ[�ַ�
        sprintf(str,"%03d\0", (uint8_t)file_number);
        LCD_ASCII((uint8_t*)str,67,0,7,16,MOVEUP);         //��ʾ�����ֵ
        LCD_ASCII("]",88,0,7,16,MOVEUP);                //��ʾ]�ַ�
        while(1)
        {
            //��ʾ���
            Display_Batter(Power_flag);
            //��ʾ��Դ
            Display_Power(Power_flag);
            
            key = OSMboxAccept(KEYMbox);
            if(*key == KEY_DOWN)
            {
                key_new++;
                if(key_new == 17)
                {
                    key_new = 1;
                }
            }
            else if(*key == KEY_UP)
            {
                key_new--;
                if(key_new == 0)
                {
                    key_new = 16;
                }
            }
            else if(*key == KEY_CAL)
            {
                LCDClrWin(0,0,127,7);                           //��ȫ��
                LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
                LCD_String("��ѯ",50,0,13,16,MOVEUP);           //��ʾ��ѯ�ַ�
                LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�   
                flag2 = 0;
                return;
            }
            if(key_new <= 3)
            {
                if(fla1 == 0)
                {
                    //��һҳ
                    LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                    LCD_ASCII("1/6",7,0,7,16,MOVEUP);               //��ʾ2/5�����ַ�
                    LCD_String("��",25,2,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                    LCD_String("��",47,2,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                    LCD_String("ʱ",25,4,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                    LCD_String("��",47,4,13,16,NORMAL);             //��ʾ��ǰ�ַ�
                    LCD_String("��ʱ",25,6,13,16,NORMAL);           //��ʾ��ʱ�ַ�
                    LCD_ASCII("A",51,6,7,16,NORMAL);
                    /*********************��ǰʱ���ȡ***********************/
                    //��
                    sprintf(str,"%02d-\0", (uint8_t)g_StorageData.now_year);
                    LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
                    //��
                    sprintf(str,"%02d-\0", (uint8_t)g_StorageData.now_month);
                    LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
                     //��
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.now_day);
                    LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                    //ʱ
                    sprintf(str,"%02d:\0", (uint8_t)g_StorageData.now_hour);
                    LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                    //��
                    sprintf(str,"%02d:\0", (uint8_t)g_StorageData.now_minute);
                    LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                     //��
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.now_second);
                    LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                    
                    /*********************�ɼ�ʱ���ȡ***********************/
                    //ʱ
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_hour_a);
                    LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                    //��
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_minute_a);
                    LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                     //��
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.sampling_second_a);
                    LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                      
                    fla1 = 1;
                    fla2 = 0;
                    fla3 = 0;
                    fla4 = 0;
                    fla5 = 0;
                    fla6 = 0;
                }  
                
                LCD_ASCII("-->",3,2*key_new,7,16,NORMAL);//��ʾ��ͷ����
                if (key_old != key_new)
                {	
                    LCDClrWin(3,2*key_old,24,2*key_old+1);//�����һ������
                    key_old = key_new;     
                }
            }
            
            else if((key_new >= 4) && (key_new <= 6))
            {
                if(fla2 == 0)
                {
                    //�ڶ�ҳ
                    LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                    LCD_ASCII("2/6",7,0,7,16,MOVEUP);               //��ʾ2/5�����ַ�
                    
                    LCD_String("��ʱ",25,2,13,16,NORMAL);           //��ʾ��ʱ�ַ�
                    LCD_ASCII("B",51,2,7,16,NORMAL);
                    
                    LCD_String("��ѹ",25,4,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                    LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
                    LCD_ASCII(":",58,4,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    LCD_String("��ѹ",25,6,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                    LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
                    LCD_ASCII(":",58,6,7,16,NORMAL);                //��ʾ:�ַ�
                                        
                    /*********************�ɼ�ʱ���ȡ***********************/
                    //ʱ
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_hour_b);
                    LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
                    //��
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_minute_b);
                    LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
                     //��
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.sampling_second_b);
                    LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                    
                    //����A��ѹ
                    Float2Str(((float)g_StorageData.voltage_A/100),tab1,2);
                    sprintf((char*)(tab1),"%sV\0",tab1);
                    LCD_ASCII(tab1,65,4,7,16,NORMAL);                   //����A��ѹ
                    
                    //����B��ѹ
                    Float2Str(((float)g_StorageData.voltage_B/100),tab2,2);
                    sprintf((char*)(tab2),"%sV\0",tab2);
                    LCD_ASCII(tab2,65,6,7,16,NORMAL);                   //����B��ѹ
                    
                    fla1 = 0;
                    fla2 = 1;
                    fla3 = 0;
                    fla4 = 0;
                    fla5 = 0;
                    fla6 = 0;
                }
                LCD_ASCII("-->",3,2*(key_new-3),7,16,NORMAL);//��ʾ��ͷ����
                if (key_old != key_new)
                {	
                    if(key_old == 3)                          //�ڶ�ҳ��ʼ����Ҫ����
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(3,2*(key_old-3),24,2*(key_old-3)+1);//�����һ������
                        key_old = key_new;   
                    }
                } 
            }
            else if((key_new >= 7) && (key_new <= 9))
            {
                if(fla3 == 0)
                {
                    //����ҳ
                    LCD_ASCII("3/6",7,0,7,16,MOVEUP);               //��ʾ3/5�����ַ�
                    LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                    LCD_String("������",30,2,13,16,NORMAL);         //��ʾ�������ַ�
                    LCD_ASCII(":",69,2,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    LCD_String("�¶�",30,4,13,16,NORMAL);           //��ʾ�¶��ַ�
                    LCD_ASCII("A",58,4,7,16,NORMAL);                //��ʾA�ַ�
                    LCD_ASCII(":",69,4,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    
                    LCD_String("�¶�",30,6,13,16,NORMAL);           //��ʾ�¶��ַ�
                    LCD_ASCII("B",58,6,7,16,NORMAL);                //��ʾB�ַ�
                    LCD_ASCII(":",69,6,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    
                    /***********************�¶�***********************/
                    //�����¶�
                    if(g_StorageData.heattemp == 0xffff)
                    {
                        LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //��ʾ:�ַ�
                    }
                    else
                    {
                        Float2Str(((float)g_StorageData.heattemp/100),tab4,2);
                        LCD_ASCII(tab4,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",111,2,13,16,NORMAL);            //��ʾ���ַ�
                    }
                    //ͨ��A�¶�
                    if(g_StorageData.temp_A == 0xffff)
                    {
                        LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�  
                    }
                    else
                    {
                        Float2Str(((float)g_StorageData.temp_A/100),tab5,2);
                        LCD_ASCII(tab5,76,4,7,16,NORMAL);                   //ͨ��A�¶�
                        LCD_String("��",111,4,13,16,NORMAL);            //��ʾ���ַ�
                    }
                    //ͨ��B�¶�
                    if(g_StorageData.temp_B == 0xffff)
                    {
                        LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�  
                    }
                    else
                    {
                        Float2Str(((float)g_StorageData.temp_B/100),tab6,2);
                        LCD_ASCII(tab6,76,6,7,16,NORMAL);                   //ͨ��B�¶�
                        LCD_String("��",111,6,13,16,NORMAL);            //��ʾ���ַ�
                    }  
                    fla1 = 0;
                    fla2 = 0;
                    fla3 = 1;
                    fla4 = 0;
                    fla5 = 0;
                    fla6 = 0;
                }
                LCD_ASCII("-->",6,2*(key_new-6),7,16,NORMAL);//��ʾ��ͷ����
                if (key_old != key_new)
                {	
                    if(key_old == 6)                          //�ڶ�ҳ��ʼ����Ҫ����
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(6,2*(key_old-6),27,2*(key_old-6)+1);//�����һ������
                        key_old = key_new;   
                    }
                } 
            }
            else if((key_new >= 10) && (key_new <= 12))
            {
                if(fla4 == 0)
                {
                    //����ҳ
                    LCD_ASCII("4/6",7,0,7,16,MOVEUP);               //��ʾ4/5�����ַ�
                    LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                    LCD_String("��",25,2,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                    LCD_String("ѹ",45,2,13,16,NORMAL);           //��ʾ��ѹ�ַ�
                    LCD_ASCII(":",58,2,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    LCD_String("����",25,4,13,16,NORMAL);           //��ʾ�����ַ�
                    LCD_ASCII("A",51,4,7,16,NORMAL);                //��ʾA�ַ�
                    LCD_ASCII(":",58,4,7,16,NORMAL);                //��ʾ:�ַ�
                    LCD_ASCII("L/min",92,4,7,16,NORMAL);            //��ʾ�¶�ֵ�ַ�
                    
                    LCD_String("����",25,6,13,16,NORMAL);           //��ʾ�����ַ�
                    LCD_ASCII("B",51,6,7,16,NORMAL);                //��ʾB�ַ�
                    LCD_ASCII(":",58,6,7,16,NORMAL);                //��ʾ:�ַ�
                    LCD_ASCII("L/min",92,6,7,16,NORMAL);            //��ʾ��λֵ�ַ�
                    
                    //����ֵ��ȡ
                    Float2Str(((float)g_StorageData.flow_A/100),str1,2);
                    LCD_ASCII((uint8_t*)str1,64,4,7,16,NORMAL);
                    
                    Float2Str(((float)g_StorageData.flow_B/100),str1,2);
                    LCD_ASCII((uint8_t*)str1,64,6,7,16,NORMAL);
                                           
                    fla1 = 0;
                    fla2 = 0;
                    fla3 = 0;
                    fla4 = 1;
                    fla5 = 0;
                    fla6 = 0;
                }
                //��ѹֵ
                /*********************��ѹֵ***********************/
                if(((float)g_StorageData.pressure/100) >= 100)
                {
                    Float2Str(((float)g_StorageData.pressure/100),tab3,2);
                }
                else
                {
                    Float2Str(((float)g_StorageData.pressure/100),tab3,3);
                }
                LCD_ASCII(tab3,63,2,7,16,NORMAL);
                LCD_ASCII("kPa",105,2,7,16,NORMAL);
                
                LCD_ASCII("-->",1,2*(key_new-9),7,16,NORMAL);//��ʾ��ͷ����
                if (key_old != key_new)
                {	
                    if(key_old == 9)                          //�ڶ�ҳ��ʼ����Ҫ����
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(1,2*(key_old-9),22,2*(key_old-9)+1);//�����һ������
                        key_old = key_new;   
                    }
                }
            }
            else if((key_new >= 13) && (key_new <= 15))
            {
                if(fla5 == 0)
                {
                    //����ҳ
                    LCD_ASCII("5/6",7,0,7,16,MOVEUP);               //��ʾ5/5�����ַ�
                    LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                    
                    LCD_String("���",30,2,13,16,NORMAL);           //��ʾ����ַ�
                    LCD_ASCII("A",56,2,7,16,NORMAL);                //��ʾA�ַ�
                    LCD_ASCII(":",63,2,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    LCD_String("���",30,4,13,16,NORMAL);           //��ʾ����ַ�
                    LCD_ASCII("B",56,4,7,16,NORMAL);                //��ʾB�ַ�
                    LCD_ASCII(":",63,4,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    LCD_String("���",30,6,13,16,NORMAL);           //��ʾ����ַ�
                    LCD_ASCII("A",56,6,7,16,NORMAL);                //��ʾB�ַ�
                    LCD_ASCII(":",63,6,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    //���A��ȡ
                    Float2Str(g_StorageData.volume_A,str1,2);
                    sprintf((char*)(str1),"%sL\0",str1);
                    LCD_ASCII((uint8_t*)str1,70,2,7,16,NORMAL);
                    
                    //���B��ȡ
                    Float2Str(g_StorageData.volume_B,str1,2);
                    sprintf((char*)(str1),"%sL\0",str1);
                    LCD_ASCII((uint8_t*)str1,70,4,7,16,NORMAL);
                    
                    //���A��ȡ
                    Float2Str(g_StorageData.standard_volume_A,str1,2);
                    sprintf((char*)(str1),"%sL\0",str1);
                    LCD_ASCII((uint8_t*)str1,70,6,7,16,NORMAL);

                    fla1 = 0;
                    fla2 = 0;
                    fla3 = 0;
                    fla4 = 0;
                    fla5 = 1;
                    fla6 = 0;
                }
                
                LCD_ASCII("-->",6,2*(key_new-12),7,16,NORMAL);//��ʾ��ͷ����
                if (key_old != key_new)
                {	
                    if(key_old == 12)                          //�ڶ�ҳ��ʼ����Ҫ����
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(6,2*(key_old-12),27,2*(key_old-12)+1);//�����һ������
                        key_old = key_new;   
                    }
                }
            }
            else if(key_new == 16)
            {
                if(fla6 == 0)
                {
                    //����ҳ
                    LCD_ASCII("6/6",7,0,7,16,MOVEUP);               //��ʾ5/5�����ַ�
                    LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
                        
                    LCD_String("���",30,2,13,16,NORMAL);           //��ʾ����ַ�
                    LCD_ASCII("B",56,2,7,16,NORMAL);                //��ʾB�ַ�
                    LCD_ASCII(":",63,2,7,16,NORMAL);                //��ʾ:�ַ�
                    
                    //���B��ȡ
                    Float2Str(g_StorageData.standard_volume_B,str1,2);
                    sprintf((char*)(str1),"%sL\0",str1);
                    LCD_ASCII((uint8_t*)str1,70,2,7,16,NORMAL);
                    
                    fla1 = 0;
                    fla2 = 0;
                    fla3 = 0;
                    fla4 = 0;
                    fla5 = 0;
                    fla6 = 1;
                }
                LCD_ASCII("-->",6,2*(key_new-15),7,16,NORMAL);//��ʾ��ͷ����
                if (key_old != key_new)
                {	
                    if(key_old == 15)                          //�ڶ�ҳ��ʼ����Ҫ����
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(6,2*(key_old-15),27,2*(key_old-15)+1);//�����һ������
                        key_old = key_new;   
                    }
                }
            }
        } 
    }
}

/*
************************************************
�������ƣ�void Display_SeekMenu2_SubFileClear(void)
�������ܣ���ѯ�ӽ��� �ļ��������
��ڲ�������
���ڲ�������
************************************************
*/
void Display_SeekMenu2_SubFileClear(void)
{
    uint8_t dat = 0;
    uint8_t storage_number = 0;
    uint8_t *key;
    uint32_t address = 0;
    
    LCDClrWin(0,4,127,5);                           //��һ��
    LCD_String("ȷ���ļ�����",21,4,13,16,NORMAL);           
    LCD_ASCII("?",99,4,7,16,NORMAL);                //��ʾ�����ַ�   
    while(1)
    {
        //��ʾ���
        Display_Batter(Power_flag);
        //��ʾ��Դ
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_ENTER)
        {
            LCDClrWin(0,4,127,5);                           //��һ��
            LCD_String("�ļ�������",28,4,13,16,NORMAL);    
            LCD_ASCII("...",93,4,7,16,NORMAL);                //��ʾ�����ַ�   
            for(address = STORAGE_START; address < (8000+STORAGE_START); address++)
            {
                FM24C64_WRITE_BYTE(address,0);                  //д��0x0
                dat = FM24C64_READ_BYTE(address);               //����0x0
                if(dat != 0)                                    //д��Ͷ����Ĳ���ͬ
                {
                    LCDClrWin(0,4,127,5);                           //��һ��
                    LCD_String("�ļ�����ʧ��",21,4,13,16,NORMAL);  
                    LCD_ASCII("!",99,4,7,16,NORMAL);                //��ʾ�����ַ� 
                    while(1)
                    {
                        //��ʾ���
                        Display_Batter(Power_flag);
                        //��ʾ��Դ
                        Display_Power(Power_flag);
                        
                        key = OSMboxAccept(KEYMbox);
                        if((*key == KEY_ENTER) || ((*key == KEY_CAL)))
                        { 
                            flag2 = 0;
                            return;
                        }
                    }
                }
            }  
            FM24C64_WRITE_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);  //д�����ڴ洢�˶��ٸ��ļ�,�洢����������
            LCDClrWin(0,4,127,5);                           //��һ��
            LCD_String("�ļ�������",28,4,13,16,NORMAL);  
            LCD_ASCII("!",93,4,7,16,NORMAL);                //��ʾ�����ַ� 
            while(1)
            {
                //��ʾ���
                Display_Batter(Power_flag);
                //��ʾ��Դ
                Display_Power(Power_flag);
                
                key = OSMboxAccept(KEYMbox);
                if((*key == KEY_ENTER) || ((*key == KEY_CAL)))
                { 
                    flag2 = 0;
                    return;
                }
            }
        }
        else if(*key == KEY_CAL)
        {
            flag2 = 0;
            return;
        }
    }
}

/****************************** ά������ ��������******************************/

/*
********************************************************************************
�������ƣ�void Display_MaintainMenu(void)
�������ܣ�ά������˵���ʾ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void Display_MaintainMenu(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
        LCD_String("ά��",50,0,13,16,MOVEUP);           //��ʾά���ַ�
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //��ʾ1/1�����ַ�
        LCD_String("��ѹ��Ϣ",37,2,13,16,NORMAL);       //��ʾ��ѹ��Ϣ�ַ�
        LCD_String("�¶���ѹ",37,4,13,16,NORMAL);       //��ʾ�¶���ѹ�ַ�
        LCD_String("�汾��Ϣ",37,6,13,16,NORMAL);       //��ʾ�汾��Ϣ�ַ�
        
        flag1 = 1;
    }
    
    LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//�����һ������
        s_olderchoose = g_UserChoose;     
    }
}

/******************** ά�������ӽ��� ��ѹ��Ϣ**********************/

/*
******************************************************************
�������ƣ�void Display_MainTainMenu_SubDisplayVoltage1(void)
�������ܣ�ά�������Ӳ˵� -��ѹ��Ϣ1
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_MaintainMenu_SubDisplayVoltage1(void)
{
    uint8_t tab1[10];
    uint8_t tab2[10];
    uint8_t tab3[10];
    uint8_t tab4[10];
    
    float batter_value = 0; 
    static uint32_t ad = 0;
    
    if(g_UserChoose <= 2)
    {
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��ѹ��Ϣ",38,0,13,16,MOVEUP);       //��ʾ��ѹ��Ϣ�ַ�
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�
            LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
            
            LCD_String("���ص�ѹ",25,2,13,16,NORMAL);       //��ʾ���ص�ѹ�ַ�
            LCD_ASCII(":",77,2,7,16,NORMAL);                //��ʾ:�ַ�
            LCD_String("��ص�ѹ",25,4,13,16,NORMAL);       //��ʾ��ص�ѹ�ַ�
            LCD_ASCII(":",77,4,7,16,NORMAL);                //��ʾ:�ַ�
            LCD_String("��",25,6,13,16,NORMAL);             //��ʾ���ַ�
            LCD_ASCII("A",41,6,7,16,NORMAL);                //��ʾA�ַ�
            LCD_String("��ѹ",51,6,13,16,NORMAL);           //��ʾ��ѹ�ַ�
            LCD_ASCII(":",77,6,7,16,NORMAL);                //��ʾ:�ַ�
            
            //��Դ��ѹ
            LCDClrWin(84,2,127,3);                               //��ҳ��ʾ�䶯����
            Float2Str(g_Power.pb0_adc8_power,tab1,2);
            sprintf((char*)(tab1),"%sV\0",tab1);
            LCD_ASCII(tab1,84,2,7,16,NORMAL);                   //��Դ��ѹ
            //��ص�ѹ
            if(Batter_flag == 0)
            {
                 batter_value = 0;
            }
            else
            {
                batter_value = g_Power.pc0_adc10_battery;
            }
            LCDClrWin(84,4,127,5);
            Float2Str(batter_value,tab2,2);
            sprintf((char*)(tab2),"%sV\0",tab2);
            LCD_ASCII(tab2,84,4,7,16,NORMAL);                   //��ص�ѹ
            //����A��ѹ
            LCDClrWin(84,6,127,7);
            Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
            sprintf((char*)(tab3),"%sV\0",tab3);
            LCD_ASCII(tab3,84,6,7,16,NORMAL);                   //����A��ѹ
            
            flag1 = 1;
            flag2 = 0;
        }
        
        //���ڵ�ѹɨ��������࣬���������ӻ���ʾ
        if(ad > 100)
        {
            //��Դ��ѹ
            LCDClrWin(84,2,127,3);                               //��ҳ��ʾ�䶯����
            Float2Str(g_Power.pb0_adc8_power,tab1,2);
            sprintf((char*)(tab1),"%sV\0",tab1);
            LCD_ASCII(tab1,84,2,7,16,NORMAL);                   //��Դ��ѹ
            //��ص�ѹ
            if(Batter_flag == 0)
            {
                 batter_value = 0;
            }
            else
            {
                batter_value = g_Power.pc0_adc10_battery;
            }
            LCDClrWin(84,4,127,5);
            Float2Str(batter_value,tab2,2);
            sprintf((char*)(tab2),"%sV\0",tab2);
            LCD_ASCII(tab2,84,4,7,16,NORMAL);                   //��ص�ѹ
            //����A��ѹ
            LCDClrWin(84,6,127,7);
            Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
            sprintf((char*)(tab3),"%sV\0",tab3);
            LCD_ASCII(tab3,84,6,7,16,NORMAL);                   //����A��ѹ
            
            ad = 0;
        }
        ad++;
        
        LCD_ASCII("-->",2,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(2,2*(s_olderchoose+1),23,2*(s_olderchoose+1)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
         if(flag2 == 0)
        {
            //�ڶ�ҳ
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("��ѹ��Ϣ",38,0,13,16,MOVEUP);       //��ʾ��ѹ��Ϣ�ַ�
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            LCD_String("��",25,2,13,16,NORMAL);             //��ʾ���ַ�
            LCD_ASCII("B",41,2,7,16,NORMAL);                //��ʾB�ַ�
            LCD_String("��ѹ",51,2,13,16,NORMAL);           //��ʾ��ѹ�ַ�
            LCD_ASCII(":",77,2,7,16,NORMAL);                //��ʾ:�ַ�
            //����B��ѹ
            Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
            sprintf((char*)(tab4),"%sV\0",tab4);
            LCD_ASCII(tab4,84,2,7,16,NORMAL);                   //����A��ѹ
            
            flag1 = 0;
            flag2 = 1;
        }  
        if(ad > 100)
        {
            //����B��ѹ
            Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
            sprintf((char*)(tab4),"%sV\0",tab4);
            LCD_ASCII(tab4,84,2,7,16,NORMAL);                   //����A��ѹ
            ad = 0;
        }
        ad++;
        
        LCD_ASCII("-->",2,2*(g_UserChoose-2),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(2,2*(s_olderchoose-2),23,2*(s_olderchoose-2)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        } 
    }
}


/******************** ά�������ӽ��� �¶���Ϣ**********************/

/*
******************************************************************
�������ƣ�void Display_MainTainMenu_SubDisplayTemperaturePressure1(void)
�������ܣ�ά�������Ӳ˵� -�¶���ѹ
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_MaintainMenu_SubDisplayTemperaturePressure1(void)
{
    uint8_t tab1[10];
    uint8_t tab2[10];
    uint8_t tab3[10];
    uint8_t tab4[10];
    uint8_t tab5[10];
    static uint32_t ad1 = 0;
    
    if(g_UserChoose <= 2)
    {
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("�¶���ѹ",38,0,13,16,MOVEUP);       //��ʾ�¶���ѹ�ַ�
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //��ʾ1/2�����ַ�
            
            LCDClrWin(0,2,127,7);                           //��ҳ��ʾ�䶯����
            
            LCD_String("������",29,2,13,16,NORMAL);         //��ʾ�������ַ�
            LCD_ASCII(":",68,2,7,16,NORMAL);                //��ʾ:�ַ�
            
            LCD_String("ͨ��",29,4,13,16,NORMAL);           //��ʾͨ���ַ�
            LCD_ASCII("A",58,4,7,16,NORMAL);                //��ʾA�ַ�
            LCD_ASCII(":",68,4,7,16,NORMAL);                //��ʾ:�ַ�
    
            LCD_String("ͨ��",29,6,13,16,NORMAL);           //��ʾͨ���ַ�
            LCD_ASCII("B",58,6,7,16,NORMAL);                //��ʾB�ַ�
            LCD_ASCII(":",68,6,7,16,NORMAL);                //��ʾ:�ַ�
            
            //������
            if(g_Temperature.DQ3_exist == 0)
            {
                LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",104,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
            //ͨ��A�¶�
            if(g_Temperature.DQ1_exist == 0)
            {
                LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ1_TEMP < 0)
                {
                    if(g_Temperature.DQ1_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                    }
                    LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 10)
                    {
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",104,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
            //ͨ��B�¶�
            if(g_Temperature.DQ2_exist == 0)
            {
                LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ2_TEMP < 0)
                {
                    if(g_Temperature.DQ2_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                    }
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",107,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
            flag1 = 1;
            flag2 = 0;
        }
        
        //�����¶�
        ad1++;
        if(ad1 > 100)
        {
            ad1 = 0;
            //������
            if(g_Temperature.DQ3_exist == 0)
            {
                LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",104,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,2,127,3);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,2,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
            //ͨ��A�¶�
            if(g_Temperature.DQ1_exist == 0)
            {
                LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ1_TEMP < 0)
                {
                    if(g_Temperature.DQ1_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                    }
                    LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 10)
                    {
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",104,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
            //ͨ��B�¶�
            if(g_Temperature.DQ2_exist == 0)
            {
                LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //��ʾ:�ַ�
            }
            else
            {
                if(g_Temperature.DQ2_TEMP < 0)
                {
                    if(g_Temperature.DQ2_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                    }
                    LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                    LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                    LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",107,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //��ҳ��ʾ�䶯����
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //�����¶�
                        LCD_String("��",112,6,13,16,NORMAL);                //��ʾ���ַ�
                    }
                }
            }
        }
        LCD_ASCII("-->",6,2*(g_UserChoose+1),7,16,NORMAL);//��ʾ��ͷ����
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(6,2*(s_olderchoose+1),27,2*(s_olderchoose+1)+1);//�����һ������
            s_olderchoose = g_UserChoose;     
        }
        
    }
    else
    {
        if(flag2 == 0)
        {
            //�ڶ�ҳ
            LCDClrWin(0,0,127,7);                           //��䶯����
            LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
            LCD_String("�¶���ѹ",38,0,13,16,MOVEUP);       //��ʾ�¶���ѹ�ַ�
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //��ʾ2/2�����ַ�
            LCD_String("��ѹ",29,2,13,16,NORMAL);           //��ʾ��ѹ�ַ�
            LCD_ASCII(":",55,2,7,16,NORMAL);                //��ʾ:�ַ�
            flag1 = 0;
            flag2 = 1;
        }    
        //��ѹֵ��ȡ
        if(g_Pressure >= 100)
        {
            Float2Str(g_Pressure,tab4,2);
        }
        else
        {
            Float2Str(g_Pressure,tab4,3);
        }
        LCD_ASCII(tab4,62,2,7,16,NORMAL);
        LCD_ASCII("kPa",105,2,7,16,NORMAL);
        LCD_ASCII("-->",6,2*(g_UserChoose-2),7,16,NORMAL);//��ʾ��ͷ����
        
        /*��ʾ��ѹоƬ��ȡ���¶�ֵ��������������*/
//        if(g_TEMP == 0)
//            {
//                LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
//                LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //��ʾ:�ַ�
//            }
//            else
//            {
//                if(g_TEMP < 0)
//                {
//                    if(g_TEMP <= (-10))                 //�����¶ȵ���ʾ�ַ�
//                    {
//                        Float2Str(g_TEMP,tab5,1);
//                    }
//                    else
//                    {
//                        Float2Str(g_TEMP,tab5,2);
//                    }
//                    LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
//                    LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //�����¶�
//                    LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
//                }
//                else
//                {
//                    if(g_TEMP < 10)
//                    {
//                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
//                        Float2Str(g_TEMP,tab5,2);
//                        LCD_ASCII(tab5,76,4,7,16,NORMAL);                   //�����¶�
//                        LCD_String("��",104,4,13,16,NORMAL);                //��ʾ���ַ�
//                    }
//                    else
//                    {
//                        LCDClrWin(76,4,127,5);                               //��ҳ��ʾ�䶯����
//                        Float2Str(g_TEMP,tab5,2);
//                        LCD_ASCII(tab5,76,4,7,16,NORMAL);                   //�����¶�
//                        LCD_String("��",112,4,13,16,NORMAL);                //��ʾ���ַ�
//                    }
//                }
//            }
        
        
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //�ڶ�ҳ��ʼ����Ҫ����
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(6,2*(s_olderchoose-2),27,2*(s_olderchoose-2)+1);//�����һ������
                s_olderchoose = g_UserChoose;   
            }
        } 
    }
}

/******************** ά�������ӽ��� �汾��Ϣ**********************/

/*
******************************************************************
�������ƣ�void Display_MainTainMenu_SubDisplayVersions(void)
�������ܣ�ά�������Ӳ˵� -�汾��Ϣ
��ڲ�������
���ڲ�������
******************************************************************
*/
void Display_MaintainMenu_SubDisplayVersions(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //��ʾ��һ�зָ���
        LCD_String("�汾��Ϣ",38,0,13,16,MOVEUP);       //��ʾ�汾��Ϣ�ַ�
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //��ʾ1/1�����ַ�
        
        LCD_String("�汾��",21,2,13,16,NORMAL);         //��ʾ�汾���ַ�
        LCD_ASCII("[",66,2,7,16,NORMAL);                //��ʾ[�ַ�
        LCD_ASCII("V2.3",73,2,7,16,NORMAL);             //��ʾV1.0�ַ�
        LCD_ASCII("]",101,2,7,16,NORMAL);               //��ʾ]�ַ�
        
        LCD_String("���ǿƼ�",19,4,13,16,NORMAL);       //��ʾ���ǿƼ��ַ�
        LCD_ASCII("(",71,4,7,16,NORMAL);                //��ʾ(�ַ�
        LCD_String("����",78,4,13,16,NORMAL);           //��ʾ�����ַ�
        LCD_ASCII(")",104,4,7,16,NORMAL);               //��ʾ)�ַ�
        LCD_ASCII("www.szusst.cn",19,6,7,16,NORMAL);    //��ʾwww.szusst.cn�ַ�
        flag1 = 1;
    }
}