/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			mainmenu.c
 *Description：     	       主界面设计
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/******************************** 其他 函数定义********************************/

/*
********************************************************************************
函数名称：void Display_Batter(uint8_t flag)
函数功能：电池显示
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_Batter(uint8_t flag)
{
    if(Batter_flag == 1)
    {
         //判断是否有电源，决定是充电还是电池供电
         if(flag == 1)
         {
            //空电量
            if(Batter_add_flag0 == 1)    
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("5",109,0,16,16,NORMAL);              //显示电池电流为0
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("6",109,0,16,16,NORMAL);              //显示电池电量为1
                }
                else if(Batter_add == 3)
                {
                    LCD_Picture("7",109,0,16,16,NORMAL);              //显示电池电量为2
                }
                else if(Batter_add == 4)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //显示电池电量为3 
                }
                else if(Batter_add == 5)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //显示电池电量为4
                }
            }
            //有一格电量，进入第二电量
            else if(Batter_add_flag1 == 1)
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("6",109,0,16,16,NORMAL);              //显示电池电量为1
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("7",109,0,16,16,NORMAL);              //显示电池电量为2
                }
                else if(Batter_add == 3)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //显示电池电量为3
                }
                else if(Batter_add == 4)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //显示电池电量为4 
                }
            }
            //有二格电量，进入第三电量
            else if(Batter_add_flag2 == 1)
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("7",109,0,16,16,NORMAL);              //显示电池电量为2
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //显示电池电量为3
                }
                else if(Batter_add == 3)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //显示电池电量为4
                }
            }
            //有三格电量，进入第四电量
            else if(Batter_add_flag3 == 1)
            {
                if(Batter_add == 1)
                {
                    LCD_Picture("8",109,0,16,16,NORMAL);              //显示电池电量为3
                }
                else if(Batter_add == 2)
                {
                    LCD_Picture("9",109,0,16,16,NORMAL);              //显示电池电量为4
                }
            }
            //为满格电量
            else if(Batter_add_flag4 == 1)
            {
                LCD_Picture("9",109,0,16,16,NORMAL);              //显示电池电量为4
            } 
         }
         else
         {
            if((g_Power.pc0_adc10_battery > 12))                  //每一格电量为0.6v
            {
                LCD_Picture("9",109,0,16,16,NORMAL);              //显示电池电量为4  
            }
            else if((g_Power.pc0_adc10_battery > 11.8) && (g_Power.pc0_adc10_battery <= 12))
            {
                LCD_Picture("8",109,0,16,16,NORMAL);              //显示电池电量为3
            }
            else if((g_Power.pc0_adc10_battery > 11.2) && (g_Power.pc0_adc10_battery <= 11.8))
            {                                     
                LCD_Picture("7",109,0,16,16,NORMAL);              //显示电池电量为2
            }
            //留点余量
            else if((g_Power.pc0_adc10_battery > 10.6) && (g_Power.pc0_adc10_battery <= 11.2))
            {
                LCD_Picture("6",109,0,16,16,NORMAL);              //显示电池电流为1
            }
            else if((g_Power.pc0_adc10_battery <= 10.6))
            {
                LCD_Picture("5",109,0,16,16,NORMAL);              //显示电池电流为0
            }
         }
    }
    else
    {
        LCD_Picture("0",109,0,16,16,NORMAL);                      //清掉电池显示
    }
}  

/*
********************************************************************************
函数名称：void Display_Power(uint8_t flag)
函数功能：电源显示
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_Power(uint8_t flag)
{
    //有无电源供电
    if(flag == 1)
    {
        LCD_ASCII("^",100,0,7,16,MOVEUP);           //显示插头图片
    }
    else
    {
        LCD_ASCII("_",100,0,7,16,MOVEUP);           //不显示插头图片
    }
}
  

/******************************* 主界面 函数定义*******************************/

/*
********************************************************************************
函数名称：void Display_MainMenu(void)
函数功能：主菜单显示
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_MainMenu(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
        LCD_String("主菜单",45,0,13,16,MOVEUP);         //显示主菜单字符
        LCD_Picture("1",9,2,16,16,NORMAL);              //显示设置图片
        LCD_Picture("2",76,2,16,16,NORMAL);             //显示采样图片
        LCD_Picture("3",9,4,16,16,NORMAL);              //显示查询图片 
        LCD_Picture("4",76,4,16,16,NORMAL);             //显示维护图片
        
        LCD_HoriStraightLine(6,1,2);                    //显示第二行分割线
        
        flag1 = 1;
    }
    if(g_UserChoose == 0)
    {
        //实现设置反显，其他正常 
        LCD_String("设置",27,2,13,16,INVERSER);     //显示设置反显字符
        LCD_String("采样",94,2,13,16,NORMAL);       //显示采样字符
        LCD_String("查询",27,4,13,16,NORMAL);       //显示查询字符
        LCD_String("维护",94,4,13,16,NORMAL);       //显示维护字符
    }
    else if(g_UserChoose == 1)
    { 
        LCD_String("设置",27,2,13,16,NORMAL);       //显示设置字符
        LCD_String("采样",94,2,13,16,INVERSER);     //显示采样反显字符
        LCD_String("查询",27,4,13,16,NORMAL);       //显示查询字符
        LCD_String("维护",94,4,13,16,NORMAL);       //显示维护字符
    }
    else if(g_UserChoose == 2)
    {  
        LCD_String("设置",27,2,13,16,NORMAL);       //显示设置字符
        LCD_String("采样",94,2,13,16,NORMAL);       //显示采样字符
        LCD_String("查询",27,4,13,16,INVERSER);     //显示查询反显字符
        LCD_String("维护",94,4,13,16,NORMAL);       //显示维护字符
    }
    else if(g_UserChoose == 3)
    {      
        LCD_String("设置",27,2,13,16,NORMAL);       //显示设置字符
        LCD_String("采样",94,2,13,16,NORMAL);       //显示采样字符
        LCD_String("查询",27,4,13,16,NORMAL);       //显示查询字符
        LCD_String("维护",94,4,13,16,INVERSER);     //显示维护反显字符
    }
    Display_TimeValue();
}

/*
********************************************************************************
函数名称：void Display_TimeValue(void)
函数功能：显示时间值
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_TimeValue(void)
{
    char str[10]={10};  
     //年
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.year);
    LCD_ASCII((uint8_t*)str,4,6,7,16,MOVEDOWN);
    //月
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.month);
    LCD_ASCII((uint8_t*)str,25,6,7,16,MOVEDOWN);
    //日
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.day);
    LCD_ASCII((uint8_t*)str,46,6,7,16,MOVEDOWN);
    
    //时
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
    LCD_ASCII((uint8_t*)str,67,6,7,16,MOVEDOWN);
    //分
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
    LCD_ASCII((uint8_t*)str,88,6,7,16,MOVEDOWN);
     //秒
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
    LCD_ASCII((uint8_t*)str,109,6,7,16,MOVEDOWN);
}

/****************************** 设置界面 函数定义******************************/

/*
********************************************************************************
函数名称：void Display_SetMenu1(void)
函数功能：设置菜单1显示
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_SetMenu1(void)
{
    if(g_UserChoose < 3)
    {
        //防止反复刷重复的界面
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("设置",50,0,13,16,MOVEUP);           //显示设置字符
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/2界面字符
            LCD_String("时间设置",37,2,13,16,NORMAL);       //显示时间设置字符
            LCD_String("通讯设置",37,4,13,16,NORMAL);       //显示通讯设置字符
            LCD_String("加热设置",37,6,13,16,NORMAL);       //显示加热设置字符
            flag1 = 1;
            flag2 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("设置",50,0,13,16,MOVEUP);           //显示设置字符
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            LCD_String("恢复出厂设置",37,2,13,16,NORMAL);   //显示恢复出厂设置字符 
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/**************** 设置界面1子菜单定义  设置时间*******************/

/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetTime(void)
函数功能：设置菜单1子菜单 设置时间
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetTime(void)
{
    char str[10]={0};
    
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
        LCD_String("时间设置",38,0,13,16,MOVEUP);       //显示时间设置字符
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //显示1/1界面字符
        LCD_String("日期",30,2,13,16,NORMAL);           //显示日期字符     
        LCD_String("时间",30,4,13,16,NORMAL);           //显示时间字符
        
        flag1 = 1;
    }
    
    //年
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.year);
    LCD_ASCII((uint8_t*)str,60,2,7,16,NORMAL);
    //月
    sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.month);
    LCD_ASCII((uint8_t*)str,81,2,7,16,NORMAL);
    //日
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.day);
    LCD_ASCII((uint8_t*)str,102,2,7,16,NORMAL);
    
    //时
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
    LCD_ASCII((uint8_t*)str,60,4,7,16,NORMAL);
    //分
    sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
    LCD_ASCII((uint8_t*)str,81,4,7,16,NORMAL);
     //秒
    sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
    LCD_ASCII((uint8_t*)str,102,4,7,16,NORMAL);
    
    LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//清除上一个坐标
        s_olderchoose = g_UserChoose;     
    }      
}

/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetTime_YMD(void)
函数功能：实现年月日时间设置
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetTime_YMD(void)
{
    SYSTEM_RTC rtc_oldtime;
    rtc_oldtime = g_RTCTime;                                   //复制时间一遍
    int8_t year_ten = rtc_oldtime.year / 10;                    //获得年的十位数据
    int8_t year_one = rtc_oldtime.year % 10;                    //获得年的个位数据
    int8_t month_ten = rtc_oldtime.month / 10;                   //获得月的十位数据
    int8_t month_one = rtc_oldtime.month % 10;                   //获得月的个位数据
    int8_t day_ten = rtc_oldtime.day / 10;                     //获得日的十位数据
    int8_t day_one = rtc_oldtime.day % 10;                     //获得日的个位数据
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
                //年
                sprintf(str,"%02d-\0", (uint8_t)year);
                LCD_ASCII((uint8_t*)str,60,2,7,16,NORMAL);
                //月
                sprintf(str,"%02d-\0", (uint8_t)month);
                LCD_ASCII((uint8_t*)str,81,2,7,16,NORMAL);
                //日
                sprintf(str,"%02d\0", (uint8_t)day);
                LCD_ASCII((uint8_t*)str,102,2,7,16,NORMAL);
                return;
            }
            else if(*key == KEY_CAL)
            {
                //年
                sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.year);
                LCD_ASCII((uint8_t*)str,60,2,7,16,NORMAL);
                //月
                sprintf(str,"%02d-\0", (uint8_t)g_RTCTime.month);
                LCD_ASCII((uint8_t*)str,81,2,7,16,NORMAL);
                //日
                sprintf(str,"%02d\0", (uint8_t)g_RTCTime.day);
                LCD_ASCII((uint8_t*)str,102,2,7,16,NORMAL);
                return; 
            }
        }
    }
}

/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetTime_HMS(void)
函数功能：实现时分秒时间设置
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetTime_HMS(void)
{
    SYSTEM_RTC rtc_oldtime;
    rtc_oldtime = g_RTCTime;                                   //复制时间一遍
    int8_t hour_ten = rtc_oldtime.hour / 10;                    //获得时的十位数据
    int8_t hour_one = rtc_oldtime.hour % 10;                    //获得时的个位数据
    int8_t minute_ten = rtc_oldtime.minute / 10;                //获得分的十位数据
    int8_t minute_one = rtc_oldtime.minute % 10;                //获得分的个位数据
    int8_t second_ten = rtc_oldtime.second / 10;                //获得秒的十位数据
    int8_t second_one = rtc_oldtime.second % 10;                //获得秒的个位数据
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
/**************** 设置界面1子菜单定义  设置通讯1*******************/

/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetCommunication1(void)
函数功能：设置菜单1子菜单 设置通讯1
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1(void)
{
    uint32_t baud_rate = 0;         //波特率
    uint8_t data_bits = 0;          //数据位
    uint8_t parity_bit = 0;         //校验位
    uint8_t stop_bit = 0;           //停止位
    char str[10];
    if(g_UserChoose < 3)
    {
        //防止反复刷重复的界面
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("通讯设置",38,0,13,16,MOVEUP);       //显示通讯设置字符
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/2界面字符
            LCD_String("波特率",30,2,13,16,NORMAL);         //显示波特率字符
            LCD_ASCII(":",69,2,7,16,NORMAL);                //显示波特率值
            FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);
            //波特率为三位
            if(baud_rate < 1000)
            {
                sprintf(str,"%3d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            //波特率为四位
            else if(baud_rate < 10000)
            {
                sprintf(str,"%4d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            //波特率五位
            else if(baud_rate < 100000)
            {
                sprintf(str,"%5d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            //波特率六位
            else if(baud_rate < 1000000)
            {
                sprintf(str,"%6d\0",baud_rate);
                LCD_ASCII((uint8_t*)str,76,2,7,16,NORMAL);
            }
            LCD_String("数据位",30,4,13,16,NORMAL);         //显示数据位字符
            LCD_ASCII(":",69,4,7,16,NORMAL);               //显示数据位值字符
            FM24C64_READ_MUL(DATA_BITS,(uint8_t*)&data_bits,1);
            sprintf(str,"%1d\0",data_bits);
            LCD_ASCII((uint8_t*)str,76,4,7,16,NORMAL);
            
            LCD_String("校验位",30,6,13,16,NORMAL);         //显示校验位字符
            LCD_ASCII(":",69,6,7,16,NORMAL);                //显示校验位值字符
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
            
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("通讯设置",38,0,13,16,MOVEUP);       //显示通讯设置字符
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            LCD_String("停止位",30,2,13,16,NORMAL);         //显示停止位字符
            LCD_ASCII(":",69,2,7,16,NORMAL);               //显示停止位值字符
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
        
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetCommunication1_BAUD(void)
函数功能：设置菜单1子菜单 设置通讯1-波特率设置
          300/600/1200/2400/4800/9600/19200/38400/43000/56000/115200 
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_BAUD(void)
{
    uint32_t old_baud_rate = 0;     //存放老的波特率
    uint8_t *key;
    char str[10];
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //波特率
    uint8_t data_bits = 0;          //数据位
    uint8_t parity_bit = 0;         //校验位
    uint8_t stop_bit = 0;           //停止位
     
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //波特率
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //数据位
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //校验位
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //停止位
    
    old_baud_rate = baud_rate;
    //波特率为三位
    if(baud_rate < 1000)
    {
        sprintf(str,"%3d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    //波特率为四位
    else if(baud_rate < 10000)
    {
        sprintf(str,"%4d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    //波特率五位
    else if(baud_rate < 100000)
    {
        sprintf(str,"%5d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    //波特率六位
    else if(baud_rate < 1000000)
    {
        sprintf(str,"%6d\0",baud_rate);
        LCD_ASCII((uint8_t*)str,76,2,7,16,INVERSER);
    }
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
            /********************实现串口的初始化********************/
            /*波特率*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*数据位*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*停止位*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*校验位*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //初始化串口
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
函数名称：void Display_SetMenu1_SubSetCommunication1_DATABITS(void)
函数功能：设置菜单1子菜单 设置通讯1-数据位设置
          5/6/7/8
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_DATABITS(void)
{
    uint8_t old_data_bits = 0;     //存放老的数据位数
    uint8_t *key;
    char str[10];
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //波特率
    uint8_t data_bits = 0;          //数据位
    uint8_t parity_bit = 0;         //校验位
    uint8_t stop_bit = 0;           //停止位
    
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //波特率
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //数据位
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //校验位
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //停止位
      
    old_data_bits = data_bits;
    //数据位进行反显
    sprintf(str,"%1d\0",data_bits);
    LCD_ASCII((uint8_t*)str,76,4,7,16,INVERSER);

    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
            /********************实现串口的初始化********************/
            /*波特率*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*数据位*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*停止位*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*校验位*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //初始化串口
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
函数名称：void Display_SetMenu1_SubSetCommunication1_PARITYBIT(void)
函数功能：设置菜单1子菜单 设置通讯1-校验位设置
          None/Odd/Even/Mark/Space
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_PARITYBIT(void)
{
    uint8_t old_parity_bit = 0;     //存放老的校验位
    uint8_t *key;
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //波特率
    uint8_t data_bits = 0;          //数据位
    uint8_t parity_bit = 0;         //校验位
    uint8_t stop_bit = 0;           //停止位
    
      
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //波特率
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //数据位
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //校验位
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //停止位
    
    old_parity_bit = parity_bit;
    //数据位进行反显
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
            //校验位进行反显
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
             /********************实现串口的初始化********************/
            /*波特率*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*数据位*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*停止位*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*校验位*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //初始化串口
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
函数名称：void Display_SetMenu1_SubSetCommunication1_STOPBIT(void)
函数功能：设置菜单1子菜单 设置通讯1-停止位设置
          1/1.5/2  分别对于的标志为：1，2，3
入口参数：无
出口参数：无
******************************************************************
*/
void Display_SetMenu1_SubSetCommunication1_STOPBIT(void)
{
    uint8_t old_stop_bit = 0;     //存放老的校验位
    uint8_t *key;
    USART_InitTypeDef USART_InitStructure;
    
    uint32_t baud_rate = 0;         //波特率
    uint8_t data_bits = 0;          //数据位
    uint8_t parity_bit = 0;         //校验位
    uint8_t stop_bit = 0;           //停止位
    
    FM24C64_READ_MUL(BAUD_RATE, (uint8_t*)&baud_rate, 4);         //波特率
    FM24C64_READ_MUL(DATA_BITS, (uint8_t*)&data_bits, 1);         //数据位
    FM24C64_READ_MUL(PARITY_BIT, (uint8_t*)&parity_bit, 1);       //校验位
    FM24C64_READ_MUL(STOP_BIT, (uint8_t*)&stop_bit, 1);           //停止位
    
    old_stop_bit = stop_bit;
    //数据位进行反显
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
             /********************实现串口的初始化********************/
            /*波特率*/
            USART_InitStructure.USART_BaudRate = baud_rate;
            /*数据位*/
            if(data_bits == 8)           { USART_InitStructure.USART_WordLength = USART_WordLength_8b; }
            else if(data_bits == 9)      { USART_InitStructure.USART_WordLength = USART_WordLength_9b; }
            /*停止位*/
            if(stop_bit == 1)            { USART_InitStructure.USART_StopBits = USART_StopBits_1;      }
            else if(stop_bit == 2)       { USART_InitStructure.USART_StopBits = USART_StopBits_1_5;    }
            else if(stop_bit == 3)       { USART_InitStructure.USART_StopBits = USART_StopBits_2;      }
            /*校验位*/
            if(parity_bit == 1)          { USART_InitStructure.USART_Parity = USART_Parity_No;         }
            else if(parity_bit == 2)     { USART_InitStructure.USART_Parity = USART_Parity_Odd;        }
            else if(parity_bit == 3)     { USART_InitStructure.USART_Parity = USART_Parity_Even;       }
            
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
            //初始化串口
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

/**************** 设置界面1子菜单定义  加热控制*******************/
/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetHeat(void) 
函数功能：设置菜单1子菜单 加热控制
入口参数：无
出口参数：无
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
            //加热控制
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("加热设置",38,0,13,16,MOVEUP);       //显示加热设置字符
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/1界面字符
            LCD_String("加热控制",30,2,13,16,NORMAL);       //显示加热控制字符
            LCD_ASCII("[",86,2,7,16,NORMAL);                //显示[字符
            FM24C64_READ_MUL(HEAT_CONT,(uint8_t*)&heat_con,1);
            if(heat_con == 2)
            {
                LCD_String("打开",93,2,13,16,NORMAL);
            }
            else
            {
                LCD_String("关闭",93,2,13,16,NORMAL);
            }
            LCD_ASCII("]",119,2,7,16,NORMAL);               //显示]字符
            
            //温度设置
            LCD_String("温度设置",30,4,13,16,NORMAL);       //显示温度设置字符
            LCD_ASCII("[",86,4,7,16,NORMAL);                //显示[字符
            
            FM24C64_READ_MUL(HEAT_TEMP,(uint8_t*)&heat_temp,1);
            sprintf(str,"%02d\0", (uint8_t)heat_temp);
            LCD_ASCII((uint8_t*)str,93,4,7,16,NORMAL);
            
            LCD_String("℃",107,4,13,16,NORMAL);            //显示摄氏度字符
            LCD_ASCII("]",119,4,7,16,NORMAL);               //显示]字符
            
            //加热区
            LCD_String("加热区",30,6,13,16,NORMAL);         //显示加热区字符
            LCD_ASCII(":",69,6,7,16,NORMAL);                //显示:字符
            
            if(g_Temperature.DQ3_exist == 0)
            {
                LCDClrWin(76,6,127,7);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",104,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
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
                LCDClrWin(76,6,127,7);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",104,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                    }
                }
            }
        }
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            //第二页
            LCDClrWin(0,0,127,7);                           //清变动区域
            //加热控制
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("加热设置",38,0,13,16,MOVEUP);       //显示加热设置字符
            //功率值
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            LCD_String("功率值",30,2,13,16,NORMAL);           //显示气压字符
            LCD_ASCII(":",69,2,7,16,NORMAL);                //显示:字符
            
            LCDClrWin(76,2,127,3);                               //清页显示变动部分
            Float2Str(Pid.Value*100,tab4,2);
            sprintf((char*)(tab4),"%s%\0",tab4);
            LCD_ASCII(tab4,76,2,7,16,NORMAL);
            
            flag1 = 0;
            flag2 = 1;
        }   
        //功率值转换
        ad2++;
        if(ad2 > 100)
        {
            ad2 = 0;
            LCDClrWin(76,2,127,3);                               //清页显示变动部分
            Float2Str(Pid.Value*100,tab4,2);
            sprintf((char*)(tab4),"%s%\0",tab4);
            LCD_ASCII(tab4,76,2,7,16,NORMAL);
        }
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        } 
    }
}

/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetHeat_HEATCONT(void) 
函数功能：设置菜单1子菜单 加热控制(控制开关)
入口参数：无
出口参数：无
******************************************************************
*/    
void Display_SetMenu1_SubSetHeat_HEATCONT(void)  
{
    uint8_t heat_con = 0;           //温度控制
    uint8_t old_heat_con = 0;     //存放老的校验位
    uint8_t *key;
    
    FM24C64_READ_MUL(HEAT_CONT,(uint8_t*)&heat_con,1);
    old_heat_con = heat_con;
    
    //数据位进行反显
    if(heat_con == 1)
    {
        LCD_String("关闭",93,2,13,16,INVERSER);
    }
    else if(heat_con == 2)
    {
        LCD_String("打开",93,2,13,16,INVERSER);
    }

    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_UP)
        {
            if(heat_con == 1)
            {
                heat_con = 2;
                LCD_String("打开",93,2,13,16,INVERSER);
            }
            else if(heat_con == 2)
            {
                heat_con = 1;
                LCD_String("关闭",93,2,13,16,INVERSER);
            }
        }
        else if(*key == KEY_DOWN)
        {
            if(heat_con == 1)
            {
                heat_con = 2;
                LCD_String("打开",93,2,13,16,INVERSER);
            }
            else if(heat_con == 2)
            {
                heat_con = 1;
                LCD_String("关闭",93,2,13,16,INVERSER);
            }
        }
        else if(*key == KEY_ENTER)
        {
            if(heat_con == 1)
            {
                LCD_String("关闭",93,2,13,16,NORMAL);
                Pid.Value = 0;
                PWM_Configuration(Pid.Value);               //PWM通过PID值进行脉宽调整
                PD2_FAN_OFF();                              //关闭风扇
                Pid.SumError = 0;
            }
            else if(heat_con == 2)
            {
                LCD_String("打开",93,2,13,16,NORMAL);
                PD2_FAN_ON();                       //打开风扇
                PWM_Configuration(1);               //PWM通过PID值进行脉宽调整
            }
            FM24C64_WRITE_MUL(HEAT_CONT,(uint8_t*)&heat_con,1);
            return;
        }
        else if(*key == KEY_CAL)
        {
            if(old_heat_con == 1)
            {
                LCD_String("关闭",93,2,13,16,NORMAL);
            }
            else if(old_heat_con == 2)
            {
                LCD_String("打开",93,2,13,16,NORMAL);
            }
            return;
        }
    }  
}

/*
******************************************************************
函数名称：void Display_SetMenu1_SubSetHeat_HEAT_TEMP(void) 
函数功能：设置菜单1子菜单 加热控制(温度设置开关)
入口参数：无
出口参数：无
******************************************************************
*/    
void Display_SetMenu1_SubSetHeat_HEAT_TEMP(void)  
{
    uint8_t heat_temp = 0;           //温度设置
    uint8_t old_heat_temp = 0;       //存放老的温度设置值
    int8_t heat_temp_ten = 0;       //温度的十位
    int8_t heat_temp_one = 0;       //温度的个位
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(HEAT_TEMP,(uint8_t*)&heat_temp,1);
    old_heat_temp = heat_temp;
    
    heat_temp_ten = heat_temp / 10;
    heat_temp_one = heat_temp % 10;
    
    //数据位进行反显
    if(heat_temp_ten == 0)              {LCD_ASCII("0",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 1)         {LCD_ASCII("1",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 2)         {LCD_ASCII("2",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 3)         {LCD_ASCII("3",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 4)         {LCD_ASCII("4",93,4,7,16,INVERSER);}
    else if(heat_temp_ten == 5)         {LCD_ASCII("5",93,4,7,16,INVERSER);}
    
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
            //写入PID设置中
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

/**************** 设置界面2子菜单定义  恢复出厂设置*******************/
/*
******************************************************************
函数名称：void Display_SetMenu2_SubSetDefault(void)
函数功能：设置菜单2子菜单 恢复出厂设置
入口参数：无
出口参数：无
******************************************************************
*/    
void Display_SetMenu2_SubSetDefault(void)
{
    uint8_t *key;
    LCDClrWin(0,2,127,3);                                //清六、七行屏
    LCD_String("确认恢复出厂设置",9,2,13,16,NORMAL);     //显示确认恢复出厂设置字符
    LCD_ASCII("?",113,2,7,16,NORMAL);                    //显示？字符
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        switch(*key)
        {
            case KEY_ENTER:
                Target_Init();                                       //恢复出厂设置参数
                LCDClrWin(0,2,127,3);                                //清六、七行屏
                LCD_String("已恢复出厂设置",16,2,13,16,NORMAL);      //显示已恢复出厂设置字符
                LCD_ASCII("!",107,2,7,16,NORMAL);                    //显示!字符
                while(1)
                {
                    //显示电池
                    Display_Batter(Power_flag);
                    //显示电源
                    Display_Power(Power_flag);
                    
                    key = OSMboxAccept(KEYMbox);
                    switch(*key)
                    {
                        case KEY_CAL:
                        case KEY_ENTER:
                            LCDClrWin(0,2,127,3);                                //清六、七行屏
                            LCD_String("恢复出厂设置",37,2,13,16,NORMAL);   //显示恢复出厂设置字符 
                            return;
                        default: break;
                    }
                }
            case KEY_CAL:
                LCDClrWin(0,2,127,3);   
                LCD_String("恢复出厂设置",37,2,13,16,NORMAL);   //显示恢复出厂设置字符 
                return;
            default: break;
        }
        
    }
}

/****************************** 采样界面 函数定义******************************/

/*
********************************************************************************
函数名称：void Display_SamplingMenu(void)
函数功能：采样界面菜单显示
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_SamplingMenu(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
        LCD_String("采样",50,0,13,16,MOVEUP);           //显示采样字符
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //显示1/1界面字符
        LCD_String("预调流量",37,2,13,16,NORMAL);       //显示预调流量字符
        LCD_String("定时采样",37,4,13,16,NORMAL);       //显示定时采样字符
        LCD_String("立即采样",37,6,13,16,NORMAL);       //显示立即采样字符
        
        flag1 = 1;
    }
    
    LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//清除上一个坐标
        s_olderchoose = g_UserChoose;     
    }
}

/******************* 采样子界面 预调流量定义*****************/

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubPreset(void)
函数功能：采样子界面 预调流量定义
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubPreset(void)
{
    float sampling_a = 0.0;
    float sampling_b = 0.0;
    uint8_t str[10];
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
        LCD_String("预调流量",38,0,13,16,MOVEUP);       //显示预调流量字符
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //显示1/1界面字符
    
        LCD_String("流量",24,2,13,16,NORMAL);           //显示流量字符
        LCD_ASCII("A",50,2,7,16,NORMAL);                //显示A字符
        LCD_ASCII(":",57,2,7,16,NORMAL);                //显示:字符
        
        FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
        Float2Str(sampling_a,str,2);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            
        LCD_ASCII("L/min",92,2,7,16,NORMAL);            //显示温度值字符
        
        LCD_String("流量",24,4,13,16,NORMAL);           //显示流量字符
        LCD_ASCII("B",50,4,7,16,NORMAL);                //显示B字符
        LCD_ASCII(":",57,4,7,16,NORMAL);                //显示:字符
        
        FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
        Float2Str(sampling_b,str,2);
        LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
          
        LCD_ASCII("L/min",92,4,7,16,NORMAL);            //显示单位值字符
        
        LCD_String("启动调节",24,6,13,16,NORMAL);       //启动调节字符
        
        flag1 = 1;
    }
    
    LCD_ASCII("-->",1,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(1,2*(s_olderchoose+1),22,2*(s_olderchoose+1)+1);//清除上一个坐标
        s_olderchoose = g_UserChoose;     
    }

}

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubPreset_SAMPLING_A(void)
函数功能：采样子界面 预调流量定义(流量A设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubPreset_SAMPLING_A(void)
{
    float sampling_a = 0.0;       //流量A  
    int8_t sampling_a_hundred = 0; //放大100倍后的百位
    int8_t sampling_a_ten = 0;     //放大100倍后的十位
    int8_t sampling_a_one = 0;     //放大100倍后的个位
    float old_sampling_a = 0.0;   //保存老的流量值
    uint8_t add = 1;
    uint8_t str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    old_sampling_a = sampling_a;
    sampling_a = sampling_a * 100;       //把小数位变成整数
    sampling_a_hundred = ((int8_t)sampling_a / 100);   //取百位
    sampling_a_ten = ((int8_t)sampling_a / 10 % 10);   //取十位
    sampling_a_one = ((int8_t)sampling_a % 10);        //取个位
    
    //数据位进行反显
    if(sampling_a_hundred == 0)              {LCD_ASCII("0",64,2,7,16,INVERSER);}
    else if(sampling_a_hundred == 1)         {LCD_ASCII("1",64,2,7,16,INVERSER);}

    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
函数名称：void Display_SamplingMenu_SubPreset_SAMPLING_B(void)
函数功能：采样子界面 预调流量定义(流量B设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubPreset_SAMPLING_B(void)
{
    float sampling_b = 0.0;       //流量B  
    int8_t sampling_b_hundred = 0; //放大100倍后的百位
    int8_t sampling_b_ten = 0;     //放大100倍后的十位
    int8_t sampling_b_one = 0;     //放大100倍后的个位
    float old_sampling_b = 0.0;   //保存老的流量值
    uint8_t add = 1;
    uint8_t str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    old_sampling_b = sampling_b;
    sampling_b = sampling_b * 100;       //把小数位变成整数
    sampling_b_hundred = ((int8_t)sampling_b / 100);   //取百位
    sampling_b_ten = ((int8_t)sampling_b / 10 % 10);   //取十位
    sampling_b_one = ((int8_t)sampling_b % 10);        //取个位
    
    //数据位进行反显
    if(sampling_b_hundred == 0)              {LCD_ASCII("0",64,4,7,16,INVERSER);}
    else if(sampling_b_hundred == 1)         {LCD_ASCII("1",64,4,7,16,INVERSER);}

    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
函数名称：void Display_SamplingMenu_SubPreset_FLOW_START(void)
函数功能：采样子界面 预调流量定义(流量启动)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubPreset_FLOW_START(void)
{
    uint8_t *key;
    float sampling_a = 0.0;
    float sampling_b = 0.0;
    
    LCDClrWin(24,6,127,7);                                //清六、七行屏
    LCD_String("流量调节中",24,6,13,16,NORMAL);          //显示流量调节中字符
    LCD_ASCII("...",89,6,7,16,NORMAL);                   //显示。。。字符
            
    /******************************读取采样的流量设定值**************************************/
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    
    if(sampling_a <= 0.001)
    {
        MOTOR_A_OFF();                              //关闭气泵A
    }
    else
    {
        MOTOR_A_ON();                               //打开气泵A
    }
    if(sampling_b <= 0.001)
    {
        MOTOR_B_OFF();                              //关闭气泵B
    }
    else
    {
        MOTOR_B_ON();                               //打开气泵B
    }
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if((*key == KEY_ENTER) || (*key == KEY_CAL))
        {
            MOTOR_A_OFF();                                         //关闭气泵A
            MOTOR_B_OFF();                                         //关闭气泵B
            LCDClrWin(24,6,127,7); 
            LCD_String("启动调节",24,6,13,16,NORMAL);       //启动调节字符
            return;
        }
    }
}

/******************* 采样子界面 定时采样定义*****************/

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubTiming1(void)
函数功能：采样子界面 定时采样定义1
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubTiming1(void)
{
    char str[10];
    uint8_t start_hour_a = 0;           //起始小时时间
    uint8_t start_minute_a = 0;          //起始分钟时间
    uint8_t start_second_a = 0;          //起始秒钟时间
    
    uint8_t start_hour_b = 0;           //起始小时时间
    uint8_t start_minute_b = 0;          //起始分钟时间
    uint8_t start_second_b = 0;          //起始秒钟时间
    
    uint8_t sampling_hour_a = 0;         //采样设置小时时间
    uint8_t sampling_minute_a = 0;       //采样设置分钟时间
    uint8_t sampling_second_a = 0;       //采样设置秒钟时间
    
    uint8_t sampling_hour_b = 0;         //采样设置小时时间
    uint8_t sampling_minute_b = 0;       //采样设置分钟时间
    uint8_t sampling_second_b = 0;       //采样设置秒钟时间
    
    if(g_UserChoose < 2)
    {
        //防止反复刷重复的界面
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("定时采样",38,0,13,16,MOVEUP);       //显示定时采样字符
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/1界面字符
        
            LCD_String("当前时间",8,2,13,16,NORMAL);        //显示当前时间字符
            
            /*通道A起始时间*/
            LCD_String("起始",25,4,13,16,NORMAL);           //显示起始字符
            LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
            //时
            FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
            sprintf(str,"%02d:\0",(uint8_t)start_hour_a);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //分
            FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
            sprintf(str,"%02d:\0",(uint8_t)start_minute_a);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //秒
            FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
            sprintf(str,"%02d\0", (uint8_t)start_second_a);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            /*通道B起始时间*/
            LCD_String("起始",25,6,13,16,NORMAL);           //显示起始字符
            LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
            //时
            FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
            sprintf(str,"%02d:\0",(uint8_t)start_hour_b);
            LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
            //分
            FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
            sprintf(str,"%02d:\0",(uint8_t)start_minute_b);
            LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
             //秒
            FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
            sprintf(str,"%02d\0", (uint8_t)start_second_b);
            LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
            
            flag1 = 1;
            flag2 = 0;
        }
        //时
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
        //分
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
        LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
         //秒
        sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
        LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
        
        LCD_ASCII("-->",3,2*(g_UserChoose+2),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(3,2*(s_olderchoose+2),24,2*(s_olderchoose+2)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("定时采样",38,0,13,16,MOVEUP);       //显示定时采样字符
            //第二页
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            
            /*通道A采集时间*/
            LCD_String("采时",25,2,13,16,NORMAL);           //显示采时字符
            LCD_ASCII("A",51,2,7,16,NORMAL);                //显示A字符
            //时
            FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_hour_a);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //分
            FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_minute_a);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //秒
            FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
            sprintf(str,"%02d\0", (uint8_t)sampling_second_a);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*通道B采集时间*/
            LCD_String("采时",25,4,13,16,NORMAL);           //显示采时字符
            LCD_ASCII("B",51,4,7,16,NORMAL);                //显示B字符
            //时
            FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_hour_b);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //分
            FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
            sprintf(str,"%02d:\0",(uint8_t)sampling_minute_b);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //秒
            FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
            sprintf(str,"%02d\0", (uint8_t)sampling_second_b);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            LCD_String("启动采样",25,6,13,16,NORMAL);       //启动调节字符
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",3,2*(g_UserChoose-1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 1)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(3,2*(s_olderchoose-1),24,2*(s_olderchoose-1)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubTiming1_START_A(void)
函数功能：采样子界面 定时采样定义1(通道A起始时间设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_START_A(void)
{
    uint8_t start_hour_a = 0;         //起始小时时间00
    uint8_t start_minute_a = 0;       //起始分钟时间00
    uint8_t start_second_a = 0;       //起始秒钟时间00
    
    uint8_t old_start_hour_a = 0;         //起始小时时间00
    uint8_t old_start_minute_a = 0;       //起始分钟时间00
    uint8_t old_start_second_a = 0;       //起始秒钟时间00
     //时分秒
    FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
    FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
    FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
    
    old_start_hour_a = start_hour_a;
    old_start_minute_a = start_minute_a;
    old_start_second_a = start_second_a;
    
    int8_t hour_ten = start_hour_a / 10;                    //获得时的十位数据
    int8_t hour_one = start_hour_a % 10;                    //获得时的个位数据
    int8_t minute_ten = start_minute_a / 10;                //获得分的十位数据
    int8_t minute_one = start_minute_a % 10;                //获得分的个位数据
    int8_t second_ten = start_second_a / 10;                //获得秒的十位数据
    int8_t second_one = start_second_a % 10;                //获得秒的个位数据

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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
函数名称：void Display_SamplingMenu_SubTiming1_START_B(void)
函数功能：采样子界面 定时采样定义1(通道B起始时间设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_START_B(void)
{
    uint8_t start_hour_b = 0;         //起始小时时间00
    uint8_t start_minute_b = 0;       //起始分钟时间00
    uint8_t start_second_b = 0;       //起始秒钟时间00
    
    uint8_t old_start_hour_b = 0;         //起始小时时间00
    uint8_t old_start_minute_b = 0;       //起始分钟时间00
    uint8_t old_start_second_b = 0;       //起始秒钟时间00
     //时分秒
    FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
    FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
    FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
    
    old_start_hour_b = start_hour_b;
    old_start_minute_b = start_minute_b;
    old_start_second_b = start_second_b;
    
    int8_t hour_ten = start_hour_b / 10;                    //获得时的十位数据
    int8_t hour_one = start_hour_b % 10;                    //获得时的个位数据
    int8_t minute_ten = start_minute_b / 10;                //获得分的十位数据
    int8_t minute_one = start_minute_b % 10;                //获得分的个位数据
    int8_t second_ten = start_second_b / 10;                //获得秒的十位数据
    int8_t second_one = start_second_b % 10;                //获得秒的个位数据

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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
函数名称：void Display_SamplingMenu_SubTiming1_SAMPLING_A(void)
函数功能：采样子界面 定时采样定义1(A通道采集时间设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_SAMPLING_A(void)
{
    uint8_t sampling_hour_a = 0;         //采样设置小时时间00
    uint8_t sampling_minute_a = 0;       //采样设置分钟时间00
    uint8_t sampling_second_a = 0;       //采样设置秒钟时间00
    
    uint8_t old_sampling_hour_a = 0;         //采样设置小时时间00
    uint8_t old_sampling_minute_a = 0;       //采样设置分钟时间00
    uint8_t old_sampling_second_a = 0;       //采样设置秒钟时间00
     //时分秒
    FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
    
    old_sampling_hour_a = sampling_hour_a;
    old_sampling_minute_a = sampling_minute_a;
    old_sampling_second_a = sampling_second_a;
    
    int8_t hour_ten = sampling_hour_a / 10;                    //获得时的十位数据
    int8_t hour_one = sampling_hour_a % 10;                    //获得时的个位数据
    int8_t minute_ten = sampling_minute_a / 10;                //获得分的十位数据
    int8_t minute_one = sampling_minute_a % 10;                //获得分的个位数据
    int8_t second_ten = sampling_second_a / 10;                //获得秒的十位数据
    int8_t second_one = sampling_second_a % 10;                //获得秒的个位数据
    
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
函数名称：void Display_SamplingMenu_SubTiming1_SAMPLING_B(void)
函数功能：采样子界面 定时采样定义1(B通道采集时间设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubTiming1_SAMPLING_B(void)
{
    uint8_t sampling_hour_b = 0;         //采样设置小时时间00
    uint8_t sampling_minute_b = 0;       //采样设置分钟时间00
    uint8_t sampling_second_b = 0;       //采样设置秒钟时间00
    
    uint8_t old_sampling_hour_b = 0;         //采样设置小时时间00
    uint8_t old_sampling_minute_b = 0;       //采样设置分钟时间00
    uint8_t old_sampling_second_b = 0;       //采样设置秒钟时间00
     //时分秒
    FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
    
    old_sampling_hour_b = sampling_hour_b;
    old_sampling_minute_b = sampling_minute_b;
    old_sampling_second_b = sampling_second_b;
    
    int8_t hour_ten = sampling_hour_b / 10;                    //获得时的十位数据
    int8_t hour_one = sampling_hour_b % 10;                    //获得时的个位数据
    int8_t minute_ten = sampling_minute_b / 10;                //获得分的十位数据
    int8_t minute_one = sampling_minute_b % 10;                //获得分的个位数据
    int8_t second_ten = sampling_second_b / 10;                //获得秒的十位数据
    int8_t second_one = sampling_second_b % 10;                //获得秒的个位数据
    
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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

/********** 采样子界面 定时采样的子界面 等待采样定义*********/

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubTiming_SubWait(void)
函数功能：采样子界面 定时采样的子界面 等待采样定义
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubTiming_SubWait(void)
{
    char str[10];
    
    uint8_t start_hour = 0;              //起始小时时间
    uint8_t start_minute = 0;            //起始分钟时间
    uint8_t start_second = 0;            //起始秒钟时间
    
    uint8_t start_hour_a = 0;            //起始a小时时间
    uint8_t start_minute_a = 0;          //起始a分钟时间
    uint8_t start_second_a = 0;          //起始a秒钟时间
    
    uint8_t start_hour_b = 0;            //起始b小时时间
    uint8_t start_minute_b = 0;          //起始b分钟时间
    uint8_t start_second_b = 0;          //起始b秒钟时间
    
    uint8_t sampling_hour_a = 0;
    uint8_t sampling_minute_a = 0;
    uint8_t sampling_second_a = 0;
    
    uint8_t sampling_hour_b = 0;
    uint8_t sampling_minute_b = 0;
    uint8_t sampling_second_b = 0;
    
    uint8_t *key;
    
    LCDClrWin(0,2,127,7);                               //清全屏
    LCD_String("等待采样时刻",0,0,13,16,MOVEUP);    //显示等待采样时刻字符
    LCD_ASCII("...",78,0,7,16,MOVEUP);              //显示。。。字符
    
    LCD_String("当前时间",8,2,13,16,NORMAL);           //显示当前字符
    
    LCD_String("起始",25,4,13,16,NORMAL);           //显示设定字符
    LCD_ASCII("A",51,4,7,16,NORMAL);              //显示A字符
    
    LCD_String("起始",25,6,13,16,NORMAL);           //显示设定字符
    LCD_ASCII("B",51,6,7,16,NORMAL);              //显示A字符
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_CAL)
        {
            flag2 = 0;                             //恢复先前的界面
            return;
        }
        
        /********************当前时间********************/
        //时
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
        //分
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
        LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
         //秒
        sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
        LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
        
        /********************起始时间********************/
        
        //通道A起始时间
        //时
        FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
        sprintf(str,"%02d:\0",(uint8_t)start_hour_a);
        LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
        //分
        FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
        sprintf(str,"%02d:\0",(uint8_t)start_minute_a);
        LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
         //秒
        FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
        sprintf(str,"%02d\0", (uint8_t)start_second_a);
        LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
        
        //通道B起始时间
        FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
        sprintf(str,"%02d:\0",(uint8_t)start_hour_b);
        LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
        //分
        FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
        sprintf(str,"%02d:\0",(uint8_t)start_minute_b);
        LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
         //秒
        FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
        sprintf(str,"%02d\0", (uint8_t)start_second_b);
        LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
        
        start_hour = g_RTCTime.hour;
        start_minute = g_RTCTime.minute;
        start_second = g_RTCTime.second;
        
        /******************************读取定时采样A的设定时间**************************************/
        FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
        FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
        FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
        
        /******************************读取定时采样B的设定时间**************************************/
        FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
        FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
        FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
        
        
        /*判断定时器使能的条件*/
        if(((sampling_hour_a*3600 + sampling_minute_a*60 + sampling_second_a) == 0) || ((start_hour_a*3600 + start_minute_a*60 + start_second_a) < (start_hour*3600 + start_minute*60 + start_second)))
        {
            g_TimeEnableDisable_A = 0;                      //通道A使能采样标准
        }
        else
        {
            g_TimeEnableDisable_A = 1;                      //通道A使能采样标准
        }
        if(((sampling_hour_b*3600 + sampling_minute_b*60 + sampling_second_b) == 0) || ((start_hour_b*3600 + start_minute_b*60 + start_second_b) < (start_hour*3600 + start_minute*60 + start_second)))
        {
            g_TimeEnableDisable_B = 0;                      //通道B使能采样标准
        }
        else
        {
            g_TimeEnableDisable_B = 1;                      //通道B使能采样标准
        }

        //检测通道A定时采样时间是否已到
        if((start_hour == start_hour_a) && (start_minute == start_minute_a) && (start_second == start_second_a))
        {
            g_TimeFlag_A = 1;
        }
        else
        {
            g_TimeFlag_A = 0;
        }
        
        //检测通道B定时采样时间是否已到
        if((start_hour == start_hour_b) && (start_minute == start_minute_b) && (start_second == start_second_b))
        {
            g_TimeFlag_B = 1;
        }
        else
        {
            g_TimeFlag_B = 0;
        }
        /********************时间相等时,进入采样进行中界面********************/
        if(g_TimeFlag_A || g_TimeFlag_B)
        {
            Display_SamplingMenu_SubTiming_SubWait_SubUnderWay();
            return;
        }  
    }
}

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubTiming_SubWait(void)
函数功能：采样子界面 定时采样的子界面 (定时采样采样中。。。)
入口参数：无
出口参数：无
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
    uint8_t fla1 = 0;                                          //为初次显示初始化标志1
    uint8_t fla2 = 0;                                          //为初次显示初始化标志2
    uint8_t fla3 = 0;                                          //为初次显示初始化标志3
    uint8_t fla4 = 0;                                          //为初次显示初始化标志4
    uint8_t fla5 = 0;                                          //为初次显示初始化标志4
    uint8_t *key;
    uint8_t tab1[10];
    uint8_t tab2[10];
    uint8_t tab3[10];
    uint8_t tab4[10];
    char str[10];
    uint8_t str1[10];
    
    uint8_t start_hour = 0;             //等待采样时刻，启动采样时间
    uint8_t start_minute = 0;
    uint8_t start_second = 0;
        
    uint8_t sampling_hour_a = 0;
    uint8_t sampling_minute_a = 0;
    uint8_t sampling_second_a = 0;
    
    uint8_t sampling_hour_b = 0;
    uint8_t sampling_minute_b = 0;
    uint8_t sampling_second_b = 0;
    
    uint8_t start_hour_a = 0;            //起始a小时时间
    uint8_t start_minute_a = 0;          //起始a分钟时间
    uint8_t start_second_a = 0;          //起始a秒钟时间
    
    uint8_t start_hour_b = 0;            //起始b小时时间
    uint8_t start_minute_b = 0;          //起始b分钟时间
    uint8_t start_second_b = 0;          //起始b秒钟时间
    
    uint8_t timer_hour_a = 0;
    uint8_t timer_minute_a = 0;
    uint8_t timer_second_a = 0;
    
    uint8_t timer_hour_b = 0;
    uint8_t timer_minute_b = 0;
    uint8_t timer_second_b = 0;
    
    float sampling_a = 0.0;
    float sampling_b = 0.0;
    
    /*********************************读取通道A的起始时间**************************************/  
    FM24C64_READ_MUL(START_HOUR_A,(uint8_t*)&start_hour_a,1);
    FM24C64_READ_MUL(START_MINUTE_A,(uint8_t*)&start_minute_a,1);
    FM24C64_READ_MUL(START_SECOND_A,(uint8_t*)&start_second_a,1);
    
    /*********************************读取通道B的起始时间**************************************/  
    FM24C64_READ_MUL(START_HOUR_B,(uint8_t*)&start_hour_b,1);
    FM24C64_READ_MUL(START_MINUTE_B,(uint8_t*)&start_minute_b,1);
    FM24C64_READ_MUL(START_SECOND_B,(uint8_t*)&start_second_b,1);
    
    /******************************读取定时采样A的设定时间**************************************/
    FM24C64_READ_MUL(SAMPLING_HOUR_A,(uint8_t*)&sampling_hour_a,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_A,(uint8_t*)&sampling_minute_a,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_A,(uint8_t*)&sampling_second_a,1);
    
    /******************************读取定时采样B的设定时间**************************************/
    FM24C64_READ_MUL(SAMPLING_HOUR_B,(uint8_t*)&sampling_hour_b,1);
    FM24C64_READ_MUL(SAMPLING_MINUTE_B,(uint8_t*)&sampling_minute_b,1);
    FM24C64_READ_MUL(SAMPLING_SECOND_B,(uint8_t*)&sampling_second_b,1);
    
    /******************************读取采样的流量设定值**************************************/
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    
    /*********************************显示初始的第一界面**************************************/
    LCDClrWin(0,0,127,7);                           //清全屏
    LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
    LCD_String("采样中",0,0,13,16,MOVEUP);          //显示采样中字符
    LCD_ASCII("...",39,0,7,16,MOVEUP);              //显示。。。字符
    LCD_ASCII("1/5",70,0,7,16,MOVEUP);              //显示1/4界面字符
    
    
    /***************通过流量判断哪个通道关闭或打开*******************/
    if(sampling_a <= 0.001)
    {
        MOTOR_A_OFF();                              //关闭气泵A
    }
    else
    {
        if(g_TimeFlag_A == 0)
        {
            MOTOR_A_OFF();                           //关闭气泵A
        }
        else
        {
            MOTOR_A_ON();                            //打开气泵A
        }
    }
    if(sampling_b <= 0.001)
    {
        MOTOR_B_OFF();                               //关闭气泵B
    }
    else
    {
        if(g_TimeFlag_B == 0)
        {
            MOTOR_B_OFF();                           //关闭气泵A
        }
        else
        {
            MOTOR_B_ON();                            //打开气泵A
        }
    }
//    TIM_Cmd(TIM2, ENABLE);	                     //开启定时器2
    PCF8563_TIE_EnableDisable(1);           //PCF8563定时器使能
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        /*************************************电量不足提示界面**************************************/
        if((g_Power.pc0_adc10_battery <= 10.4) && (Power_flag == 0))
        {
            uint8_t i = 0;
            /*关闭采样，气泵和定时器*/
            MOTOR_A_OFF();                                  //关闭气泵A
            MOTOR_B_OFF();                                  //关闭气泵B
//            TIM_Cmd(TIM2, DISABLE);	                    //关闭定时器2
            PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //保存定时器状态
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //保存定时器状态
            
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //定时器使能或失能
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //定时器使能或失能
            
            g_TimeEnableDisable_A = 0;
            g_TimeEnableDisable_B = 0;
            
            g_TimeFlag_A = 0;                               //关闭通道A时间计数
            g_TimeFlag_B = 0;                               //关闭通道B时间计数
            
            /*显示等待供电界面*/
            LCDClrWin(0,0,127,7);                           //清屏
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            
            //显示电池
            Display_Batter(Power_flag);
            //显示电源
            Display_Power(Power_flag);
            
            LCD_String("等待供电",0,0,13,16,MOVEUP);        //显示等待供电字符
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //显示。。。字符
        
            LCD_String("电量不足",34,2,13,16,NORMAL);       //显示电量不足字符
            LCD_ASCII(",",86,2,7,16,NORMAL);                //显示,字符
            LCD_String("已停止采样",34,4,13,16,NORMAL);     //显示已停止采样字符
            LCD_ASCII("!",99,4,7,16,NORMAL);                //显示！字符
            
            /*蜂鸣器响进行提示*/
            for(i = 0; i < 7; i++)
            {
                BEEP_ON();
                OSTimeDly(10);
                BEEP_OFF();
                OSTimeDly(10);
            }
            while(1)
            {
                //显示电池
                Display_Batter(Power_flag);
                //显示电源
                Display_Power(Power_flag);
                
                /*************************************读取按键进行是否切换**************************************/
                key = OSMboxAccept(KEYMbox);
                if((*key == KEY_ENTER) || (*key == KEY_CAL))
                {
                    flag2 = 0;                                      //重新刷界面标志
                    
                    FM24C64_WRITE_BYTE(UNFINISHED_FLAG,2);          //写入未完成标志，为定时采样
                    /*保存通道A的当前时间*/
                    FM24C64_WRITE_BYTE(TIMER_HOUR_A,Timer_hour_A);      //写入采样的小时值
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_A,Timer_minute_A);  //写入采样的分钟值
                    FM24C64_WRITE_BYTE(TIMER_SECOND_A,Timer_second_A);  //写入采样的秒钟值
                    /*保存通道B的当前时间*/
                    FM24C64_WRITE_BYTE(TIMER_HOUR_B,Timer_hour_B);      //写入采样的小时值
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_B,Timer_minute_B);  //写入采样的分钟值
                    FM24C64_WRITE_BYTE(TIMER_SECOND_B,Timer_second_B);  //写入采样的秒钟值
                    /*************************************把计数值清零***********************************************/
                    Timer_hour_A = 0;
                    Timer_minute_A = 0;
                    Timer_second_A = 0;
                    
                    Timer_hour_B = 0;
                    Timer_minute_B = 0;
                    Timer_second_B = 0;
                    g_t_count = 0;                                //定时计数值清零
                    return;
                }
                /*重新进行了电压供应*/
                if((g_Power.pc0_adc10_battery > 11) || (Power_flag == 1))
                {
                    /*********************************恢复采样中。。。界面**************************************/
                    LCDClrWin(0,0,127,7);                           //清全屏
                    LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                    LCD_String("采样中",0,0,13,16,MOVEUP);          //显示采样中字符
                    LCD_ASCII("...",39,0,7,16,MOVEUP);              //显示。。。字符
                    //返回第一界面
                    fla1 = 0;
                    add_new = 1;                                   //恢复初始状态
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //恢复定时器状态
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //恢复定时器状态
                    
                    //判断采样状态
                    if(sampling_a <= 0.001)
                    {
                        MOTOR_A_OFF();                              //关闭气泵A
                    }
                    else
                    {
                        if(g_TimeFlag_A == 0)
                        {
                            MOTOR_A_OFF();                              //关闭气泵A
                        }
                        else
                        {
                            MOTOR_A_ON();                               //打开气泵A
                        }
                    }
                    if(sampling_b <= 0.001)
                    {
                        MOTOR_B_OFF();                              //关闭气泵B
                    }
                    else
                    {
                        if(g_TimeFlag_B == 0)
                        {
                            MOTOR_B_OFF();                              //关闭气泵A
                        }
                        else
                        {
                            MOTOR_B_ON();                               //打开气泵A
                        }
                    }
//                    TIM_Cmd(TIM2, ENABLE);	                   //打开定时器2
                    PCF8563_TIE_EnableDisable(1);           //PCF8563定时器使能
                    g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //定时器使能或失能
                    g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //定时器使能或失能
                    break;
                }
            }
        }
        /*赋值进行计算*/
        timer_hour_a = Timer_hour_A;
        timer_minute_a = Timer_minute_A;
        timer_second_a = Timer_second_A;
        
        timer_hour_b = Timer_hour_B;
        timer_minute_b = Timer_minute_B;
        timer_second_b = Timer_second_B;
        /******************************蜂鸣器控制**************************************/
        if(((sampling_hour_a*3600 + sampling_minute_a*60 + sampling_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) >= 1) && ((sampling_hour_a*3600 + sampling_minute_a*60 + sampling_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) <= 3)
           || ((sampling_hour_b*3600 + sampling_minute_b*60 + sampling_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) >= 1) && ((sampling_hour_b*3600 + sampling_minute_b*60 + sampling_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) <= 3))
        {
            BEEP_ON();
            OSTimeDly(10);
            BEEP_OFF();
            OSTimeDly(10);
        }
        
        /******************************通道A通道B是否都采样，等待采样时刻**************************************/
        start_hour = g_RTCTime.hour;
        start_minute = g_RTCTime.minute;
        start_second = g_RTCTime.second;
        
        //检测通道A定时采样时间是否已到
        if(((start_hour == start_hour_a) && (start_minute == start_minute_a) && (start_second == start_second_a) && (g_TimeFlag_A == 0) && (g_TimeEnableDisable_A == 1))
           || (((start_hour_a*3600 + start_minute_a*60 + start_second_a) < (start_hour*3600 + start_minute*60 + start_second)) && (g_TimeFlag_A == 0) && (g_TimeEnableDisable_A == 1)))
        {
            g_TimeFlag_A = 1;
            MOTOR_A_ON();                                  //关闭气泵B
        }
        
        //检测通道B定时采样时间是否已到
        if(((start_hour == start_hour_b) && (start_minute == start_minute_b) && (start_second == start_second_b) && (g_TimeFlag_B == 0) && (g_TimeEnableDisable_B == 1))
          || (((start_hour_b*3600 + start_minute_b*60 + start_second_b) < (start_hour*3600 + start_minute*60 + start_second)) && (g_TimeFlag_B == 0) && (g_TimeEnableDisable_B == 1)))
        {
            g_TimeFlag_B = 1;
            MOTOR_B_ON();                                  //关闭气泵B
        }
        
        /******************************通道A读取时间是否和设定值相等**************************************/
        if((Timer_hour_A == sampling_hour_a) && (Timer_minute_A == sampling_minute_a) && (Timer_second_A >= sampling_second_a))
        {
            BEEP_OFF();
            MOTOR_A_OFF();                                  //关闭气泵A
            g_TimeFlag_A = 0;                               //通道A完成
            g_TimeEnableDisable_A = 0;                      //通道A失能采样标准
        }
        
        /******************************通道B读取时间是否和设定值相等**************************************/
        if((Timer_hour_B == sampling_hour_b) && (Timer_minute_B == sampling_minute_b) && (Timer_second_B >= sampling_second_b))
        {
            BEEP_OFF();
            MOTOR_B_OFF();                                  //关闭气泵B
            g_TimeFlag_B = 0;                               //通道B完成
            g_TimeEnableDisable_B = 0;                      //通道B失能采样标准  
        }
        
        /******************************通道A和通道B都采样完成**************************************/
        if((g_TimeFlag_A == 0) && (g_TimeFlag_B == 0) && (g_TimeEnableDisable_A == 0) && (g_TimeEnableDisable_B == 0))
        {      
//            TIM_Cmd(TIM2, DISABLE);	                    //关闭定时器2
            PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
            FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //写入完成标志
            
            /*************************************赋值计算***********************************************/
            timer_hour_a = Timer_hour_A;
            timer_minute_a = Timer_minute_A;
            timer_second_a = Timer_second_A;
            
            timer_hour_b = Timer_hour_B;
            timer_minute_b = Timer_minute_B;
            timer_second_b = Timer_second_B;
            
            /*************************************把计数值清零***********************************************/
            Timer_hour_A = 0;
            Timer_minute_A = 0;
            Timer_second_A = 0;
            
            Timer_hour_B = 0;
            Timer_minute_B = 0;
            Timer_second_B = 0;
            
            g_t_count = 0;
            
            /*************************************把所有标志也清零***********************************************/
            g_TimeEnableDisable_A = 0;
            g_TimeEnableDisable_B = 0;
            
            g_TimeFlag_A = 0;                               //关闭通道A时间计数
            g_TimeFlag_B = 0;                               //关闭通道B时间计数
            
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //保存定时器状态
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //保存定时器状态
            
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //定时器使能或失能
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //定时器使能或失能
            
            
            LCDClrWin(0,0,127,7);                           //清全屏
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("采样完毕",0,0,13,16,MOVEUP);        //显示采样完毕字符
            LCD_ASCII("!",52,0,7,16,MOVEUP);                //显示!字符
            
            
            LCD_String("是否保存采样数据",8,2,13,16,NORMAL);//显示保存采样数据字符
            LCD_ASCII("?",112,2,7,16,NORMAL);                //显示?字符
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);              //显示(1)符号
            LCD_String("是",58,4,13,16,NORMAL);             //显示是字符
            LCD_ASCII("(2)",37,6,7,16,NORMAL);              //显示(2)符号
            LCD_String("否",58,6,13,16,NORMAL);             //显示是字符
            
            while(1)
            {
                //显示电池
                Display_Batter(Power_flag);
                //显示电源
                Display_Power(Power_flag);
                
                /*************************************读取按键进行是否切换**************************************/
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
                        LCDClrWin(0,2,127,7);                                           //清全屏
                        LCD_String("保存位置",20,2,13,16,NORMAL);                       //显示保存采样数据字符
                        LCD_ASCII("[",72,2,7,16,NORMAL);                                //显示[字符
                        FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //读出现在存储了多少个文件
                        storage_number++;
                        sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                        LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                        LCD_ASCII("]",100,2,7,16,NORMAL);                               //显示]字符
                        
                        /**********************************存储数据************************************/
                        //存储区编号
                        g_StorageData.number = storage_number;       
                        //当前时间
                        g_StorageData.now_year = g_RTCTime.year;                //设定当前时间---年
                        g_StorageData.now_month = g_RTCTime.month;              //设定当前时间---月
                        g_StorageData.now_day = g_RTCTime.day;                  //设定当前时间---日
                        g_StorageData.now_hour = g_RTCTime.hour;                //设定当前时间---时
                        g_StorageData.now_minute = g_RTCTime.minute;            //设定当前时间---分
                        g_StorageData.now_second = g_RTCTime.second;            //设定当前时间---秒
                        //设定A的采集时间
                        g_StorageData.sampling_hour_a = timer_hour_a;               //设定的采集时间---时
                        g_StorageData.sampling_minute_a = timer_minute_a;           //设定的采集时间---分
                        g_StorageData.sampling_second_a = timer_second_a;           //设定的采集时间---秒
                        //设定B的采集时间
                        g_StorageData.sampling_hour_b = timer_hour_b;               //设定的采集时间---时
                        g_StorageData.sampling_minute_b = timer_minute_b;           //设定的采集时间---分
                        g_StorageData.sampling_second_b = timer_second_b;           //设定的采集时间---秒
                        //通道电压值
                        g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //检测的电压A值,放大100倍存储
                        g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //检测的电压B值,放大100倍存储
                        //气压值
                        g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //检测的气压值,放大100倍存储
                        //温度值
                        //加热区
                        if(g_Temperature.DQ3_exist == 0)
                        {
                            g_StorageData.heattemp = 0xffff;                                  //未检测到温度传感器
                        }
                        else
                        {
                            g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //检测的加热区温度值,放大100倍存储
                        }
                        //通道A
                        if(g_Temperature.DQ1_exist == 0)
                        {
                            g_StorageData.temp_A = 0xffff;                                  //未检测到温度传感器
                        }
                        else
                        {
                            g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //检测的通道A温度值,放大100倍存储
                        }
                        //通道B
                        if(g_Temperature.DQ2_exist == 0)
                        {
                            g_StorageData.temp_B = 0xffff;                                  //未检测到温度传感器
                        }
                        else
                        {
                            g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //检测的通道B温度值,放大100倍存储
                        }
                        //流量值
                        g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //通道A流量值
                        g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //通道B流量值
                        //采样体积值
                        g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//通道A体积
                        g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//通道B体积
                        //采样标况体积值
                        g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//通道A标况体积
                        g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//通道B标况体积
                          
                        FM24C64_Data_Storage(storage_number,1);
                     
                        /*************************************程序返回***********************************************/
                        LCDClrWin(20,4,106,5);                                     //清部分屏
                        LCD_String("保存数据",20,4,13,16,NORMAL);                  //显示保存采样数据字符
                        LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //显示...字符
                        while(1)
                        {
                            //显示电池
                            Display_Batter(Power_flag);
                            //显示电源
                            Display_Power(Power_flag);
                            
                            key = OSMboxAccept(KEYMbox);
                            if((*key == KEY_CAL) || (*key == KEY_ENTER))
                            {
                                //返回前一界面，清全屏
                                LCDClrWin(0,0,127,7);                           //清部分屏
                                LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                                LCD_String("定时采样",38,0,13,16,MOVEUP);       //显示定时采样字符
                                flag2 = 0;                                      //重新刷界面标志
                                return;
                            }
                        } 
                    }
                    else
                    {
                        //返回前一界面，清全屏
                        LCDClrWin(0,0,127,7);                           //清部分屏
                        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                        LCD_String("定时采样",38,0,13,16,MOVEUP);       //显示定时采样字符
                        flag2 = 0;                                      //重新刷界面标志
                        return;
                    }
                }
                /*********************显示箭头指针部分***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//显示箭头符号
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//清除上一个坐标
                    judge_old = judge_new;     
                }
            } 
        }
        /*************************************读取按键设置部分**************************************/
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
            MOTOR_A_OFF();                                  //关闭气泵A
            MOTOR_B_OFF();                                  //关闭气泵B
//            TIM_Cmd(TIM2, DISABLE);	                    //关闭定时器2
            PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
            
            LCDClrWin(0,0,127,7);                           //清页显示变动部分
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("采样暂停",0,0,13,16,MOVEUP);        //显示采样暂停字符
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //显示。。。字符
            
            LCD_String("是否结束采样",6,2,13,16,NORMAL);    //显示是否结束采样字符
            LCD_ASCII("?",84,2,7,16,NORMAL);                //显示?字符
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);          //显示(1)符号
            LCD_String("是",58,4,13,16,NORMAL);         //显示是字符
            LCD_ASCII("(2)",37,6,7,16,NORMAL);          //显示(2)符号
            LCD_String("否",58,6,13,16,NORMAL);         //显示是字符
            while(1)
            {
                //显示电池
                Display_Batter(Power_flag);
                //显示电源
                Display_Power(Power_flag);
                
                /*************************************读取按键进行是否切换**************************************/
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
                        FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //写入完成标志
                        /*************************************把计数值清零***********************************************/
                        Timer_hour_A = 0;
                        Timer_minute_A = 0;
                        Timer_second_A = 0;
                        
                        Timer_hour_B = 0;
                        Timer_minute_B = 0;
                        Timer_second_B = 0;
                        g_t_count = 0;
                        
                        /*************************************把所有标志也清零***********************************************/
                        g_TimeEnableDisable_A = 0;
                        g_TimeEnableDisable_B = 0;
                        
                        g_TimeFlag_A = 0;                               //关闭通道A时间计数
                        g_TimeFlag_B = 0;                               //关闭通道B时间计数
                        
                        FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //保存定时器状态
                        FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //保存定时器状态
                        
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //定时器使能或失能
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //定时器使能或失能
                        
                        LCDClrWin(0,2,127,7);                           //清第部分屏
                        LCD_String("是否保存采样数据",8,2,13,16,NORMAL);//显示保存采样数据字符
                        LCD_ASCII("?",112,2,7,16,NORMAL);                //显示?字符
                        
                        LCD_ASCII("(1)",37,4,7,16,NORMAL);              //显示(1)符号
                        LCD_String("是",58,4,13,16,NORMAL);             //显示是字符
                        LCD_ASCII("(2)",37,6,7,16,NORMAL);              //显示(2)符号
                        LCD_String("否",58,6,13,16,NORMAL);             //显示是字符
                        while(1)
                        {
                            //显示电池
                            Display_Batter(Power_flag);
                            //显示电源
                            Display_Power(Power_flag);
                            
                            /*************************************读取按键进行是否切换**************************************/
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
                                    LCDClrWin(0,2,127,7);                                           //清全屏
                                    LCD_String("保存位置",20,2,13,16,NORMAL);                       //显示保存采样数据字符
                                    LCD_ASCII("[",72,2,7,16,NORMAL);                                //显示[字符
                                    FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //读出现在存储了多少个文件
                                    storage_number++;
                                    sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                                    LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                                    LCD_ASCII("]",100,2,7,16,NORMAL);                               //显示]字符
                                    
                                    /**********************************存储数据************************************/
                                    //存储区编号
                                    g_StorageData.number = storage_number;       
                                    //当前时间
                                    g_StorageData.now_year = g_RTCTime.year;                //设定当前时间---年
                                    g_StorageData.now_month = g_RTCTime.month;              //设定当前时间---月
                                    g_StorageData.now_day = g_RTCTime.day;                  //设定当前时间---日
                                    g_StorageData.now_hour = g_RTCTime.hour;                //设定当前时间---时
                                    g_StorageData.now_minute = g_RTCTime.minute;            //设定当前时间---分
                                    g_StorageData.now_second = g_RTCTime.second;            //设定当前时间---秒
                                    //设定A的采集时间
                                    g_StorageData.sampling_hour_a = timer_hour_a;               //设定的采集时间---时
                                    g_StorageData.sampling_minute_a = timer_minute_a;           //设定的采集时间---分
                                    g_StorageData.sampling_second_a = timer_second_a;           //设定的采集时间---秒
                                    //设定B的采集时间
                                    g_StorageData.sampling_hour_b = timer_hour_b;               //设定的采集时间---时
                                    g_StorageData.sampling_minute_b = timer_minute_b;           //设定的采集时间---分
                                    g_StorageData.sampling_second_b = timer_second_b;           //设定的采集时间---秒
                                    //通道电压值
                                    g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //检测的电压A值,放大100倍存储
                                    g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //检测的电压B值,放大100倍存储
                                    //气压值
                                    g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //检测的气压值,放大100倍存储
                                    //温度值
                                    //加热区
                                    if(g_Temperature.DQ3_exist == 0)
                                    {
                                        g_StorageData.heattemp = 0xffff;                                  //未检测到温度传感器
                                    }
                                    else
                                    {
                                        g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //检测的加热区温度值,放大100倍存储
                                    }
                                    //通道A
                                    if(g_Temperature.DQ1_exist == 0)
                                    {
                                        g_StorageData.temp_A = 0xffff;                                  //未检测到温度传感器
                                    }
                                    else
                                    {
                                        g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //检测的通道A温度值,放大100倍存储
                                    }
                                    //通道B
                                    if(g_Temperature.DQ2_exist == 0)
                                    {
                                        g_StorageData.temp_B = 0xffff;                                  //未检测到温度传感器
                                    }
                                    else
                                    {
                                        g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //检测的通道B温度值,放大100倍存储
                                    }
                                    //流量值
                                    g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //通道A流量值
                                    g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //通道B流量值
                                    //采样体积值
                                    g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//通道A体积
                                    g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//通道B体积
                                    //采样标况体积值
                                    g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//通道A标况体积
                                    g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//通道B标况体积
                                       
                                    FM24C64_Data_Storage(storage_number,1);
                                    /*************************************程序返回***********************************************/
                                    LCDClrWin(20,4,106,5);                                     //清部分屏
                                    LCD_String("保存数据",20,4,13,16,NORMAL);                  //显示保存采样数据字符
                                    LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //显示...字符
                                    while(1)
                                    {
                                        //显示电池
                                        Display_Batter(Power_flag);
                                        //显示电源
                                        Display_Power(Power_flag);
                                        
                                        key = OSMboxAccept(KEYMbox);
                                        if((*key == KEY_CAL) || (*key == KEY_ENTER))
                                        {
                                            //返回前一界面，清全屏
                                            LCDClrWin(0,0,127,7);                           //清部分屏
                                            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                                            LCD_String("定时采样",38,0,13,16,MOVEUP);       //显示定时采样字符
                                            flag2 = 0;                                      //重新刷界面标志
                                            return;
                                        }
                                    } 
                                }
                                else
                                {
                                    //返回前一界面，清全屏
                                    LCDClrWin(0,0,127,7);                           //清部分屏
                                    LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                                    LCD_String("定时采样",38,0,13,16,MOVEUP);       //显示定时采样字符
                                    flag2 = 0;                                      //重新刷界面标志
                                    return;
                                }
                            }
                            /*********************显示箭头指针部分***********************/
                            LCD_ASCII("-->",6,2*(judge_new1+1),7,16,NORMAL);//显示箭头符号
                            if (judge_old1 != judge_new1)
                            {	
                                LCDClrWin(6,2*(judge_old1+1),28,2*(judge_old1+1)+1);//清除上一个坐标
                                judge_old1 = judge_new1;     
                            }
                        }
                    }
                    else
                    {
                        /*********************************显示初始的第一界面**************************************/
                        LCDClrWin(0,0,127,7);                           //清全屏
                        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                        LCD_String("采样中",0,0,13,16,MOVEUP);          //显示采样中字符
                        LCD_ASCII("...",39,0,7,16,MOVEUP);              //显示。。。字符
                        //返回第一界面
                        fla1 = 0;
                        add_new = 1;                                   //恢复初始状态
                        //判断采样状态
                        if(sampling_a <= 0.001)
                        {
                            MOTOR_A_OFF();                              //关闭气泵A
                        }
                        else
                        {
                            if(g_TimeFlag_A == 0)
                            {
                                MOTOR_A_OFF();                              //关闭气泵A
                            }
                            else
                            {
                                MOTOR_A_ON();                               //打开气泵A
                            }
                        }
                        if(sampling_b <= 0.001)
                        {
                            MOTOR_B_OFF();                              //关闭气泵B
                        }
                        else
                        {
                            if(g_TimeFlag_B == 0)
                            {
                                MOTOR_B_OFF();                              //关闭气泵A
                            }
                            else
                            {
                                MOTOR_B_ON();                               //打开气泵A
                            }
                        }
//                        TIM_Cmd(TIM2, ENABLE);	                       //打开定时器2
                        PCF8563_TIE_EnableDisable(1);           //PCF8563定时器使能
                        break;
                    }
                }
                /*********************显示箭头指针部分***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//显示箭头符号
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//清除上一个坐标
                    judge_old = judge_new;     
                }
            }
        }
         
        /*********************************变动数据扫描部分*************************************/
        if(add_new <= 3)
        {
            if(fla1 == 0)
            {
                //第一页不变字符部分
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                LCD_ASCII("1/5",70,0,7,16,MOVEUP);              //显示1/4界面字符
                LCD_String("当",25,2,13,16,NORMAL);             //显示当前字符
                LCD_String("前",47,2,13,16,NORMAL);             //显示当前字符
                
                /*********************通道A起始时间打印***********************/
                LCD_String("起始",25,4,13,16,NORMAL);           //显示设定字符
                LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
                //时
                sprintf(str,"%02d:\0",(uint8_t)start_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                //分
                sprintf(str,"%02d:\0",(uint8_t)start_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                 //秒
                sprintf(str,"%02d\0", (uint8_t)start_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                
                /*********************通道B起始时间打印***********************/
                LCD_String("起始",25,6,13,16,NORMAL);           //显示计时字符
                LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
                //时
                sprintf(str,"%02d:\0",(uint8_t)start_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                //分
                sprintf(str,"%02d:\0",(uint8_t)start_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                 //秒
                sprintf(str,"%02d\0", (uint8_t)start_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                
                fla1 = 1;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            /*********************当前时间读取***********************/
            //时
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //分
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //秒
            sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************显示箭头指针部分***********************/
            
            LCD_ASCII("-->",3,2*add_new,7,16,NORMAL);//显示箭头符号
            if (add_old != add_new)
            {	
                LCDClrWin(3,2*add_old,24,2*add_old+1);//清除上一个坐标
                add_old = add_new;     
            }
        }
        else if((add_new >= 4) && (add_new <= 6))
        {
            if(fla2 == 0)
            {
                //第二页
                LCD_ASCII("2/5",70,0,7,16,MOVEUP);              //显示2/4界面字符
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                
                /*********************通道A采集时间打印***********************/
                LCD_String("采时",25,2,13,16,NORMAL);           //显示设定字符
                LCD_ASCII("A",51,2,7,16,NORMAL);                //显示A字符
                //时
                sprintf(str,"%02d:\0",(uint8_t)sampling_hour_a);
                LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
                //分
                sprintf(str,"%02d:\0",(uint8_t)sampling_minute_a);
                LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
                 //秒
                sprintf(str,"%02d\0", (uint8_t)sampling_second_a);
                LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                
                /*********************通道B采集时间打印***********************/
                LCD_String("采时",25,4,13,16,NORMAL);           //显示计时字符
                LCD_ASCII("B",51,4,7,16,NORMAL);                //显示B字符
                //时
                sprintf(str,"%02d:\0",(uint8_t)sampling_hour_b);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                //分
                sprintf(str,"%02d:\0",(uint8_t)sampling_minute_b);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                 //秒
                sprintf(str,"%02d\0", (uint8_t)sampling_second_b);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                
                /*********************通道A计时时间打印***********************/
                LCD_String("计时",25,6,13,16,NORMAL);           //显示计时字符
                LCD_ASCII("A",51,6,7,16,NORMAL);                //显示B字符
                
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 1;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            /*********************计数时间读取***********************/
            //时
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_A);
            LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
            //分
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_A);
            LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
             //秒
            sprintf(str,"%02d\0", (uint8_t)Timer_second_A);
            LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
            
            /*********************显示箭头指针部分***********************/
            LCD_ASCII("-->",3,2*(add_new-3),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 3)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-3),24,2*(add_old-3)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 7) && (add_new <= 9))
        {
            if(fla3 == 0)
            {
                //第三页
                LCD_ASCII("3/5",70,0,7,16,MOVEUP);              //显示2/4界面字符
                LCDClrWin(0,2,127,7);   
                
                /*********************通道B计时时间打印***********************/
                LCD_String("计时",25,2,13,16,NORMAL);           //显示计时字符
                LCD_ASCII("B",51,2,7,16,NORMAL);                //显示B字符
                
                /*********************通道A流量打印***********************/
                LCD_String("流量",25,4,13,16,NORMAL);           //显示流量字符
                LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
                LCD_ASCII(":",58,4,7,16,NORMAL);                //显示:字符
                LCD_ASCII("L/min",92,4,7,16,NORMAL);            //显示温度值字符
                
                /*********************通道B流量打印***********************/
                LCD_String("流量",25,6,13,16,NORMAL);           //显示流量字符
                LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
                LCD_ASCII(":",58,6,7,16,NORMAL);                //显示:字符
                LCD_ASCII("L/min",92,6,7,16,NORMAL);            //显示单位值字符
                
                Float2Str(sampling_a,str1,2);
                LCD_ASCII((uint8_t*)str1,64,4,7,16,NORMAL);
                
                Float2Str(sampling_b,str1,2);
                LCD_ASCII((uint8_t*)str1,64,6,7,16,NORMAL);
                
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 1;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            
            /*********************计数时间读取***********************/
            //时
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_B);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //分
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_B);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //秒
            sprintf(str,"%02d\0", (uint8_t)Timer_second_B);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************显示箭头指针部分***********************/
            LCD_ASCII("-->",3,2*(add_new-6),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 6)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-6),24,2*(add_old-6)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 10) && (add_new <= 12))
        {
            if(fla4 == 0)
            {
                //第四页
                LCD_ASCII("4/5",70,0,7,16,MOVEUP);              //显示2/4界面字符
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                
                LCD_String("电压",30,2,13,16,NORMAL);           //显示电压字符
                LCD_ASCII("A",56,2,7,16,NORMAL);                //显示A字符
                LCD_ASCII(":",63,2,7,16,NORMAL);                //显示:字符
                
                LCD_String("电压",30,4,13,16,NORMAL);           //显示电压字符
                LCD_ASCII("B",56,4,7,16,NORMAL);                //显示B字符
                LCD_ASCII(":",63,4,7,16,NORMAL);                //显示:字符
                
                //气泵A电压
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,70,2,7,16,NORMAL);               //气泵A电压
                
                //气泵B电压
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,70,4,7,16,NORMAL);               //气泵B电压
                
                
                LCD_String("气压",30,6,13,16,NORMAL);           //显示气压字符
                LCD_ASCII(":",56,6,7,16,NORMAL);                //显示:字符
                
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 1;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            /*********************电压值***********************/
            ad++;  
            if(ad == 50)
            {
                //气泵A电压
                LCDClrWin(70,2,127,3);                           //清页显示变动部分
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,70,2,7,16,NORMAL);               //气泵A电压
                
                //气泵B电压
                LCDClrWin(70,4,127,5);                           //清页显示变动部分
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,70,4,7,16,NORMAL);               //气泵B电压
                
                ad = 0;
            }
            
            /*********************气压值***********************/
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
            
            /*********************显示箭头指针部分***********************/
            
            LCD_ASCII("-->",6,2*(add_new-9),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 9)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-9),28,2*(add_old-9)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 13) && (add_new <= 15))
        {
            if(fla5 == 0)
            {
                //第五页
                LCD_ASCII("5/5",70,0,7,16,MOVEUP);              //显示3/4界面字符
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                LCD_String("加热区",30,2,13,16,NORMAL);         //显示加热区字符
                LCD_ASCII(":",69,2,7,16,NORMAL);                //显示:字符
                
                LCD_String("温度",30,4,13,16,NORMAL);           //显示温度字符
                LCD_ASCII("A",56,4,7,16,NORMAL);                //显示A字符
                LCD_ASCII(":",69,4,7,16,NORMAL);                //显示:字符
                
                LCD_String("温度",30,6,13,16,NORMAL);           //显示温度字符
                LCD_ASCII("B",56,6,7,16,NORMAL);                //显示B字符
                LCD_ASCII(":",69,6,7,16,NORMAL);                //显示:字符
                
                //加热区
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,2,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道A温度
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,4,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道B温度
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",107,6,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 1;                                          //为初次显示初始化标志5
            }
            /*********************加热温度***********************/
            //加热温度
            ad1++;
            if(ad1 > 50)
            {
                ad1 = 0;
                //加热区
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,2,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道A温度
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,4,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道B温度
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",107,6,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
            }
            
            /*********************显示箭头指针部分***********************/
            LCD_ASCII("-->",6,2*(add_new-12),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 12)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-12),28,2*(add_old-12)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
    }     
}

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay(void)
函数功能：采样子界面 立即采样的子界面 （立即采样中。。。界面）
入口参数：无
出口参数：无
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
    uint8_t fla1 = 0;                                          //为初次显示初始化标志1
    uint8_t fla2 = 0;                                          //为初次显示初始化标志2
    uint8_t fla3 = 0;                                          //为初次显示初始化标志3
    uint8_t fla4 = 0;                                          //为初次显示初始化标志4
    uint8_t fla5 = 0;                                          //为初次显示初始化标志5
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
    
    /******************************读取A立即采样的设定时间**************************************/
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_A,(uint8_t*)&immediately_hour_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_A,(uint8_t*)&immediately_minute_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_A,(uint8_t*)&immediately_second_a,1);
    
    /******************************读取B立即采样的设定时间**************************************/
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_B,(uint8_t*)&immediately_hour_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_B,(uint8_t*)&immediately_minute_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_B,(uint8_t*)&immediately_second_b,1);
    
    /******************************读取采样的流量设定值**************************************/
    FM24C64_READ_MUL(SAMPLING_A,(uint8_t*)&sampling_a,4);
    FM24C64_READ_MUL(SAMPLING_B,(uint8_t*)&sampling_b,4);
    
    /*********************************显示初始的第一界面**************************************/
    LCDClrWin(0,0,127,7);                           //清全屏
    LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
    LCD_String("采样中",0,0,13,16,MOVEUP);          //显示采样中字符
    LCD_ASCII("...",39,0,7,16,MOVEUP);              //显示。。。字符
    LCD_ASCII("1/4",70,0,7,16,MOVEUP);              //显示1/4界面字符
    
    /*********************************打开时间控制标志**************************************/
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
    
    //通过流量判断哪个通道关闭或打开
    if(sampling_a <= 0.001)
    {
        MOTOR_A_OFF();                              //关闭气泵A
    }
    else
    {
        if(g_TimeFlag_A == 0)
        {
            MOTOR_A_OFF();                           //关闭气泵A
        }
        else
        {
            MOTOR_A_ON();                            //打开气泵A
        }
    }
    if(sampling_b <= 0.001)
    {
        MOTOR_B_OFF();                               //关闭气泵B
    }
    else
    {
        if(g_TimeFlag_B == 0)
        {
            MOTOR_B_OFF();                           //关闭气泵A
        }
        else
        {
            MOTOR_B_ON();                            //打开气泵A
        }
    }
//    TIM_Cmd(TIM2, ENABLE);	                    //开启定时器2
    PCF8563_TIE_EnableDisable(1);           //PCF8563定时器使能
    
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        /*************************************电量不足提示界面**************************************/
        if((g_Power.pc0_adc10_battery <= 10.4) && (Power_flag == 0))
        {
            uint8_t i = 0;
            /*关闭采样，气泵和定时器*/
            MOTOR_A_OFF();                                  //关闭气泵A
            MOTOR_B_OFF();                                  //关闭气泵B
//            TIM_Cmd(TIM2, DISABLE);	                    //关闭定时器2
            PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //保存定时器状态
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //保存定时器状态
            
            g_TimeFlag_A = 0;                               //关闭通道A时间计数
            g_TimeFlag_B = 0;                               //关闭通道B时间计数
            
            /*显示等待供电界面*/
            LCDClrWin(0,0,127,7);                           //清屏
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            
            //显示电池
            Display_Batter(Power_flag);
            //显示电源
            Display_Power(Power_flag);
            
            LCD_String("等待供电",0,0,13,16,MOVEUP);        //显示等待供电字符
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //显示。。。字符
        
            LCD_String("电量不足",34,2,13,16,NORMAL);       //显示电量不足字符
            LCD_ASCII(",",86,2,7,16,NORMAL);                //显示,字符
            LCD_String("已停止采样",34,4,13,16,NORMAL);     //显示已停止采样字符
            LCD_ASCII("!",99,4,7,16,NORMAL);                //显示！字符
            
            /*蜂鸣器响进行提示*/
            for(i = 0; i < 7; i++)
            {
                BEEP_ON();
                OSTimeDly(10);
                BEEP_OFF();
                OSTimeDly(10);
            }
            while(1)
            {
                //显示电池
                Display_Batter(Power_flag);
                //显示电源
                Display_Power(Power_flag);
                
                /*************************************读取按键进行是否切换**************************************/
                key = OSMboxAccept(KEYMbox);
                if((*key == KEY_ENTER) || (*key == KEY_CAL))
                {
                    //返回前一界面，清全屏
                    LCDClrWin(0,0,127,7);                           //清全屏
                    flag2 = 0;                                      //重新刷界面标志
                    FM24C64_WRITE_BYTE(UNFINISHED_FLAG,1);          //写入未完成标志
                    FM24C64_WRITE_BYTE(TIMER_HOUR_A,Timer_hour_A);      //写入采样的小时值
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_A,Timer_minute_A);  //写入采样的分钟值
                    FM24C64_WRITE_BYTE(TIMER_SECOND_A,Timer_second_A);  //写入采样的秒钟值
                    FM24C64_WRITE_BYTE(TIMER_HOUR_B,Timer_hour_B);      //写入采样的小时值
                    FM24C64_WRITE_BYTE(TIMER_MINUTE_B,Timer_minute_B);  //写入采样的分钟值
                    FM24C64_WRITE_BYTE(TIMER_SECOND_B,Timer_second_B);  //写入采样的秒钟值
                    /*************************************把计数值清零***********************************************/
                    Timer_hour_A = 0;
                    Timer_minute_A = 0;
                    Timer_second_A = 0;
                    Timer_hour_B = 0;
                    Timer_minute_B = 0;
                    Timer_second_B = 0;
                    g_t_count = 0;                                //定时计数值清零
                    return;
                }
                /*重新进行了电压供应*/
                if((g_Power.pc0_adc10_battery > 11) || (Power_flag == 1))
                {
                    /*********************************恢复采样中。。。界面**************************************/
                    LCDClrWin(0,0,127,7);                           //清全屏
                    LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                    LCD_String("采样中",0,0,13,16,MOVEUP);          //显示采样中字符
                    LCD_ASCII("...",39,0,7,16,MOVEUP);              //显示。。。字符
                    //返回第一界面
                    fla1 = 0;
                    add_new = 1;                                   //恢复初始状态
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //恢复定时器状态
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //恢复定时器状态
                    
                    //判断采样状态
                    if(sampling_a <= 0.001)
                    {
                        MOTOR_A_OFF();                              //关闭气泵A
                    }
                    else
                    {
                        if(g_TimeFlag_A == 0)
                        {
                            MOTOR_A_OFF();                           //关闭气泵A
                        }
                        else
                        {
                            MOTOR_A_ON();                            //打开气泵A
                        }
                    }
                    if(sampling_b <= 0.001)
                    {
                        MOTOR_B_OFF();                               //关闭气泵B
                    }
                    else
                    {
                        if(g_TimeFlag_B == 0)
                        {
                            MOTOR_B_OFF();                           //关闭气泵A
                        }
                        else
                        {
                            MOTOR_B_ON();                            //打开气泵A
                        }
                    }
//                    TIM_Cmd(TIM2, ENABLE);	                   //打开定时器2
                    PCF8563_TIE_EnableDisable(1);           //PCF8563定时器使能
                    break;
                }
            }
        }
        /*赋值进行计算*/
        timer_hour_a = Timer_hour_A;
        timer_minute_a = Timer_minute_A;
        timer_second_a = Timer_second_A;
        
        timer_hour_b = Timer_hour_B;
        timer_minute_b = Timer_minute_B;
        timer_second_b = Timer_second_B;
        /******************************蜂鸣器控制**************************************/
        if(((immediately_hour_a*3600 + immediately_minute_a*60 + immediately_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) >= 1) && ((immediately_hour_a*3600 + immediately_minute_a*60 + immediately_second_a) - (timer_hour_a*3600 + timer_minute_a*60 + timer_second_a) <= 3)
           || ((immediately_hour_b*3600 + immediately_minute_b*60 + immediately_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) >= 1) && ((immediately_hour_b*3600 + immediately_minute_b*60 + immediately_second_b) - (timer_hour_b*3600 + timer_minute_b*60 + timer_second_b) <= 3))
        {
            BEEP_ON();
            OSTimeDly(10);
            BEEP_OFF();
            OSTimeDly(10);
        }
        /******************************通道A读取时间是否和设定值相等**************************************/
        if((Timer_hour_A == immediately_hour_a) && (Timer_minute_A == immediately_minute_a) && (Timer_second_A >= immediately_second_a))
        {
            BEEP_OFF();
            MOTOR_A_OFF();                                  //关闭气泵A
            g_TimeFlag_A = 0;                               //通道A完成     
        }
        
        /******************************通道B读取时间是否和设定值相等**************************************/
        if((Timer_hour_B == immediately_hour_b) && (Timer_minute_B == immediately_minute_b) && (Timer_second_B >= immediately_second_b))
        {
            BEEP_OFF();
            MOTOR_B_OFF();                                  //关闭气泵B
            g_TimeFlag_B = 0;                               //通道B完成    
        }
        /******************************读取时间是否和设定值相等**************************************/
        if((g_TimeFlag_A == 0) && ( g_TimeFlag_B == 0))
        {
//            TIM_Cmd(TIM2, DISABLE);	                    //关闭定时器2
            PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
            FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //写入完成标志

            /*赋值进行计算*/
            timer_hour_a = Timer_hour_A;
            timer_minute_a = Timer_minute_A;
            timer_second_a = Timer_second_A;
            
            timer_hour_b = Timer_hour_B;
            timer_minute_b = Timer_minute_B;
            timer_second_b = Timer_second_B;
              
            /*************************************把计数值清零***********************************************/
            Timer_hour_A = 0;
            Timer_minute_A = 0;
            Timer_second_A = 0;
            
            Timer_hour_B = 0;
            Timer_minute_B = 0;
            Timer_second_B = 0;
            g_t_count = 0;
            
            /*************************************把所有标志也清零***********************************************/
            g_TimeEnableDisable_A = 0;
            g_TimeEnableDisable_B = 0;
            
            g_TimeFlag_A = 0;                               //关闭通道A时间计数
            g_TimeFlag_B = 0;                               //关闭通道B时间计数
            
            FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //保存定时器状态
            FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //保存定时器状态
            
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //定时器使能或失能
            FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //定时器使能或失能
            
            LCDClrWin(0,0,127,7);                           //清全屏
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("采样完毕",0,0,13,16,MOVEUP);        //显示采样完毕字符
            LCD_ASCII("!",52,0,7,16,MOVEUP);                //显示!字符
            
            
            LCD_String("是否保存采样数据",8,2,13,16,NORMAL);//显示保存采样数据字符
            LCD_ASCII("?",112,2,7,16,NORMAL);                //显示?字符
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);              //显示(1)符号
            LCD_String("是",58,4,13,16,NORMAL);             //显示是字符
            LCD_ASCII("(2)",37,6,7,16,NORMAL);              //显示(2)符号
            LCD_String("否",58,6,13,16,NORMAL);             //显示是字符
            
            while(1)
            {
                //显示电池
                Display_Batter(Power_flag);
                //显示电源
                Display_Power(Power_flag);
                
                /*************************************读取按键进行是否切换**************************************/
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
                        LCDClrWin(0,2,127,7);                                           //清全屏
                        LCD_String("保存位置",20,2,13,16,NORMAL);                       //显示保存采样数据字符
                        LCD_ASCII("[",72,2,7,16,NORMAL);                                //显示[字符
                        FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //读出现在存储了多少个文件
                        storage_number++;
                        sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                        LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                        LCD_ASCII("]",100,2,7,16,NORMAL);                               //显示]字符
                        
                        /**********************************存储数据************************************/
                        //存储区编号
                        g_StorageData.number = storage_number;       
                        //当前时间
                        g_StorageData.now_year = g_RTCTime.year;                //设定当前时间---年
                        g_StorageData.now_month = g_RTCTime.month;              //设定当前时间---月
                        g_StorageData.now_day = g_RTCTime.day;                  //设定当前时间---日
                        g_StorageData.now_hour = g_RTCTime.hour;                //设定当前时间---时
                        g_StorageData.now_minute = g_RTCTime.minute;            //设定当前时间---分
                        g_StorageData.now_second = g_RTCTime.second;            //设定当前时间---秒
                        //设定的采集时间
                        g_StorageData.sampling_hour_a = timer_hour_a;               //设定的采集时间---时
                        g_StorageData.sampling_minute_a = timer_minute_a;           //设定的采集时间---分
                        g_StorageData.sampling_second_a = timer_second_a;           //设定的采集时间---秒
                        
                        g_StorageData.sampling_hour_b = timer_hour_b;               //设定的采集时间---时
                        g_StorageData.sampling_minute_b = timer_minute_b;           //设定的采集时间---分
                        g_StorageData.sampling_second_b = timer_second_b;           //设定的采集时间---秒
                        //通道电压值
                        g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //检测的电压A值,放大100倍存储
                        g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //检测的电压B值,放大100倍存储
                        //气压值
                        g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //检测的气压值,放大100倍存储
                        //温度值
                        //加热区
                        if(g_Temperature.DQ3_exist == 0)
                        {
                            g_StorageData.heattemp = 0xffff;                                  //未检测到温度传感器
                        }
                        else
                        {
                            g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //检测的加热区温度值,放大100倍存储
                        }
                        //通道A
                        if(g_Temperature.DQ1_exist == 0)
                        {
                            g_StorageData.temp_A = 0xffff;                                  //未检测到温度传感器
                        }
                        else
                        {
                            g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //检测的通道A温度值,放大100倍存储
                        }
                        //通道B
                        if(g_Temperature.DQ2_exist == 0)
                        {
                            g_StorageData.temp_B = 0xffff;                                  //未检测到温度传感器
                        }
                        else
                        {
                            g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //检测的通道B温度值,放大100倍存储
                        }
                        //流量值
                        g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //通道A流量值
                        g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //通道B流量值
                        //采样体积值
                        g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//通道A体积
                        g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//通道B体积
                        //采样标况体积值
                        g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//通道A标况体积
                        g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//通道B标况体积
                          
                        FM24C64_Data_Storage(storage_number,1);//保存数据
                     
                        /*************************************程序返回***********************************************/
                        LCDClrWin(20,4,106,5);                                     //清部分屏
                        LCD_String("保存数据",20,4,13,16,NORMAL);                  //显示保存采样数据字符
                        LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //显示...字符
                        while(1)
                        {
                            //显示电池
                            Display_Batter(Power_flag);
                            //显示电源
                            Display_Power(Power_flag);
                            
                            key = OSMboxAccept(KEYMbox);
                            if((*key == KEY_CAL) || (*key == KEY_ENTER))
                            {
                                //返回前一界面，清全屏
                                LCDClrWin(0,0,127,7);                           //清全屏
                                flag2 = 0;                                      //重新刷界面标志
                                return;
                            }
                        } 
                    }
                    else
                    {
                        //返回前一界面，清全屏
                        LCDClrWin(0,0,127,7);                           //清全屏
                        flag2 = 0;                                      //重新刷界面标志
                        return;
                    }
                }
                /*********************显示箭头指针部分***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//显示箭头符号
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//清除上一个坐标
                    judge_old = judge_new;     
                }
            } 
        }
        /*************************************读取按键设置部分**************************************/
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
            MOTOR_A_OFF();                                  //关闭气泵A
            MOTOR_B_OFF();                                  //关闭气泵B
//            TIM_Cmd(TIM2, DISABLE);	                    //关闭定时器2
            PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
            
            LCDClrWin(0,0,127,7);                           //清页显示变动部分
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("采样暂停",0,0,13,16,MOVEUP);        //显示采样暂停字符
            LCD_ASCII("...",52,0,7,16,MOVEUP);              //显示。。。字符
            
            LCD_String("是否结束采样",6,2,13,16,NORMAL);    //显示是否结束采样字符
            LCD_ASCII("?",84,2,7,16,NORMAL);                //显示?字符
            
            LCD_ASCII("(1)",37,4,7,16,NORMAL);          //显示(1)符号
            LCD_String("是",58,4,13,16,NORMAL);         //显示是字符
            LCD_ASCII("(2)",37,6,7,16,NORMAL);          //显示(2)符号
            LCD_String("否",58,6,13,16,NORMAL);         //显示是字符
            while(1)
            {
                //显示电池
                Display_Batter(Power_flag);
                //显示电源
                Display_Power(Power_flag);
                
                /*************************************读取按键进行是否切换**************************************/
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
                        FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);          //写入完成标志
                        /*************************************把计数值清零***********************************************/
                        Timer_hour_A = 0;
                        Timer_minute_A = 0;
                        Timer_second_A = 0;
                        
                        Timer_hour_B = 0;
                        Timer_minute_B = 0;
                        Timer_second_B = 0;
                        
                        g_t_count = 0;
                        
                        /*************************************把所有标志也清零***********************************************/
                        g_TimeEnableDisable_A = 0;
                        g_TimeEnableDisable_B = 0;
                        
                        g_TimeFlag_A = 0;                               //关闭通道A时间计数
                        g_TimeFlag_B = 0;                               //关闭通道B时间计数
                        
                        FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //保存定时器状态
                        FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //保存定时器状态
                        
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //定时器使能或失能
                        FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //定时器使能或失能
                        
                        LCDClrWin(0,2,127,7);                           //清第部分屏
                        LCD_String("是否保存采样数据",8,2,13,16,NORMAL);//显示保存采样数据字符
                        LCD_ASCII("?",112,2,7,16,NORMAL);                //显示?字符
                        
                        LCD_ASCII("(1)",37,4,7,16,NORMAL);              //显示(1)符号
                        LCD_String("是",58,4,13,16,NORMAL);             //显示是字符
                        LCD_ASCII("(2)",37,6,7,16,NORMAL);              //显示(2)符号
                        LCD_String("否",58,6,13,16,NORMAL);             //显示是字符
                        while(1)
                        {
                            //显示电池
                            Display_Batter(Power_flag);
                            //显示电源
                            Display_Power(Power_flag);
                            
                            /*************************************读取按键进行是否切换**************************************/
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
                                    LCDClrWin(0,2,127,7);                                           //清全屏
                                    LCD_String("保存位置",20,2,13,16,NORMAL);                       //显示保存采样数据字符
                                    LCD_ASCII("[",72,2,7,16,NORMAL);                                //显示[字符
                                    FM24C64_READ_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);   //读出现在存储了多少个文件
                                    storage_number++;
                                    sprintf(str,"%03d\0", (uint8_t)storage_number);                   
                                    LCD_ASCII((uint8_t*)str,79,2,7,16,NORMAL);
                                    LCD_ASCII("]",100,2,7,16,NORMAL);                               //显示]字符
                                    
                                    /**********************************存储数据************************************/
                                    //存储区编号
                                    g_StorageData.number = storage_number;       
                                    //当前时间
                                    g_StorageData.now_year = g_RTCTime.year;                //设定当前时间---年
                                    g_StorageData.now_month = g_RTCTime.month;              //设定当前时间---月
                                    g_StorageData.now_day = g_RTCTime.day;                  //设定当前时间---日
                                    g_StorageData.now_hour = g_RTCTime.hour;                //设定当前时间---时
                                    g_StorageData.now_minute = g_RTCTime.minute;            //设定当前时间---分
                                    g_StorageData.now_second = g_RTCTime.second;            //设定当前时间---秒
                                    //设定的采集时间
                                    g_StorageData.sampling_hour_a = timer_hour_a;               //设定的采集时间---时
                                    g_StorageData.sampling_minute_a = timer_minute_a;           //设定的采集时间---分
                                    g_StorageData.sampling_second_a = timer_second_a;           //设定的采集时间---秒
                                    
                                    g_StorageData.sampling_hour_b = timer_hour_b;               //设定的采集时间---时
                                    g_StorageData.sampling_minute_b = timer_minute_b;           //设定的采集时间---分
                                    g_StorageData.sampling_second_b = timer_second_b;           //设定的采集时间---秒
                                    //通道电压值
                                    g_StorageData.voltage_A = (uint16_t)(g_Power.pb1_adc9_motor1*100);      //检测的电压A值,放大100倍存储
                                    g_StorageData.voltage_B = (uint16_t)(g_Power.pc1_adc11_motor2*100);     //检测的电压B值,放大100倍存储
                                    //气压值
                                    g_StorageData.pressure = (uint16_t)(g_Pressure*100);                    //检测的气压值,放大100倍存储
                                    //温度值
                                    //加热区
                                    if(g_Temperature.DQ3_exist == 0)
                                    {
                                        g_StorageData.heattemp = 0xffff;                                  //未检测到温度传感器
                                    }
                                    else
                                    {
                                        g_StorageData.heattemp = (uint16_t)(g_Temperature.DQ3_TEMP*100);   //检测的加热区温度值,放大100倍存储
                                    }
                                    //通道A
                                    if(g_Temperature.DQ1_exist == 0)
                                    {
                                        g_StorageData.temp_A = 0xffff;                                  //未检测到温度传感器
                                    }
                                    else
                                    {
                                        g_StorageData.temp_A = (uint16_t)(g_Temperature.DQ1_TEMP*100);     //检测的通道A温度值,放大100倍存储
                                    }
                                    //通道B
                                    if(g_Temperature.DQ2_exist == 0)
                                    {
                                        g_StorageData.temp_B = 0xffff;                                  //未检测到温度传感器
                                    }
                                    else
                                    {
                                        g_StorageData.temp_B = (uint16_t)(g_Temperature.DQ2_TEMP*100);     //检测的通道B温度值,放大100倍存储
                                    }
                                    //流量值
                                    g_StorageData.flow_A = (uint16_t)(sampling_a*100);                      //通道A流量值
                                    g_StorageData.flow_B = (uint16_t)(sampling_b*100);                      //通道B流量值
                                    //采样体积值
                                    g_StorageData.volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60));//通道A体积
                                    g_StorageData.volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60));//通道B体积
                                    //采样标况体积值
                                    g_StorageData.standard_volume_A = (sampling_a*(((float)timer_hour_a*3600+(float)timer_minute_a*60+(float)timer_second_a)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ1_TEMP))));//通道A标况体积
                                    g_StorageData.standard_volume_B = (sampling_b*(((float)timer_hour_b*3600+(float)timer_minute_b*60+(float)timer_second_b)/60))*(sqrt(((273.15+20)*g_Pressure)/(101.325*(273.15+g_Temperature.DQ2_TEMP))));//通道B标况体积
                                      
                                    FM24C64_Data_Storage(storage_number,1);//保存数据
                                 
                                    /*************************************程序返回***********************************************/
                                    LCDClrWin(20,4,106,5);                                     //清部分屏
                                    LCD_String("保存数据",20,4,13,16,NORMAL);                  //显示保存采样数据字符
                                    LCD_ASCII(":OK!",72,4,7,16,NORMAL);                        //显示...字符
                                    while(1)
                                    {
                                        //显示电池
                                        Display_Batter(Power_flag);
                                        //显示电源
                                        Display_Power(Power_flag);
                                        
                                        key = OSMboxAccept(KEYMbox);
                                        if((*key == KEY_CAL) || (*key == KEY_ENTER))
                                        {
                                            //返回前一界面，清全屏
                                            LCDClrWin(0,0,127,7);                           //清全屏
                                            flag2 = 0;                                      //重新刷界面标志
                                            return;
                                        }
                                    } 
                                }
                                else
                                {
                                    //返回前一界面，清全屏
                                    LCDClrWin(0,0,127,7);                           //清全屏
                                    flag2 = 0;                                      //重新刷界面标志
                                    return;
                                }
                            }
                            /*********************显示箭头指针部分***********************/
                            LCD_ASCII("-->",6,2*(judge_new1+1),7,16,NORMAL);//显示箭头符号
                            if (judge_old1 != judge_new1)
                            {	
                                LCDClrWin(6,2*(judge_old1+1),28,2*(judge_old1+1)+1);//清除上一个坐标
                                judge_old1 = judge_new1;     
                            }
                        }
                    }
                    else
                    {
                        /*********************************显示初始的第一界面**************************************/
                        LCDClrWin(0,0,127,7);                           //清全屏
                        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                        LCD_String("采样中",0,0,13,16,MOVEUP);          //显示采样中字符
                        LCD_ASCII("...",39,0,7,16,MOVEUP);              //显示。。。字符
                        //返回第一界面
                        fla1 = 0;
                        add_new = 1;                                   //恢复初始状态
                        //判断采样状态
                        if(sampling_a <= 0.001)
                        {
                            MOTOR_A_OFF();                              //关闭气泵A
                        }
                        else
                        {
                            if(g_TimeFlag_A == 0)
                            {
                                MOTOR_A_OFF();                           //关闭气泵A
                            }
                            else
                            {
                                MOTOR_A_ON();                            //打开气泵A
                            }
                        }
                        if(sampling_b <= 0.001)
                        {
                            MOTOR_B_OFF();                               //关闭气泵B
                        }
                        else
                        {
                            if(g_TimeFlag_B == 0)
                            {
                                MOTOR_B_OFF();                           //关闭气泵A
                            }
                            else
                            {
                                MOTOR_B_ON();                            //打开气泵A
                            }
                        }
//                        TIM_Cmd(TIM2, ENABLE);	                       //打开定时器2
                        PCF8563_TIE_EnableDisable(1);           //PCF8563定时器使能
                        break;
                    }
                }
                /*********************显示箭头指针部分***********************/
                LCD_ASCII("-->",6,2*(judge_new+1),7,16,NORMAL);//显示箭头符号
                if (judge_old != judge_new)
                {	
                    LCDClrWin(6,2*(judge_old+1),28,2*(judge_old+1)+1);//清除上一个坐标
                    judge_old = judge_new;     
                }
            }
        }
         
        /*********************************变动数据扫描部分*************************************/
        if(add_new <= 3)
        {
            if(fla1 == 0)
            {
                //第一页不变字符部分
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                LCD_ASCII("1/5",70,0,7,16,MOVEUP);              //显示1/4界面字符
                LCD_String("当",25,2,13,16,NORMAL);             //显示当前字符
                LCD_String("前",47,2,13,16,NORMAL);             //显示当前字符
                /*********************通道A采集时间打印***********************/
                LCD_String("采时",25,4,13,16,NORMAL);           //显示设定字符
                LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
                //时
                sprintf(str,"%02d:\0",(uint8_t)immediately_hour_a);
                LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                //分
                sprintf(str,"%02d:\0",(uint8_t)immediately_minute_a);
                LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                 //秒
                sprintf(str,"%02d\0", (uint8_t)immediately_second_a);
                LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                
                /*********************通道B采集时间打印***********************/
                LCD_String("采时",25,6,13,16,NORMAL);           //显示计时字符
                LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
                //时
                sprintf(str,"%02d:\0",(uint8_t)immediately_hour_b);
                LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                //分
                sprintf(str,"%02d:\0",(uint8_t)immediately_minute_b);
                LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                 //秒
                sprintf(str,"%02d\0", (uint8_t)immediately_second_b);
                LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                
                fla1 = 1;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            /*********************当前时间读取***********************/
            //时
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //分
            sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //秒
            sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************显示箭头指针部分***********************/
            
            LCD_ASCII("-->",3,2*add_new,7,16,NORMAL);//显示箭头符号
            if (add_old != add_new)
            {	
                LCDClrWin(3,2*add_old,24,2*add_old+1);//清除上一个坐标
                add_old = add_new;     
            }
        }
        else if((add_new >= 4) && (add_new <= 6))
        {
            if(fla2 == 0)
            {
                //第二页
                LCD_ASCII("2/5",70,0,7,16,MOVEUP);              //显示2/4界面字符
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                /*********************通道A计时时间打印***********************/
                LCD_String("计时",25,2,13,16,NORMAL);           //显示流量字符
                LCD_ASCII("A",51,2,7,16,NORMAL);                //显示A字符
                
                /*********************通道B计时时间打印***********************/
                LCD_String("计时",25,4,13,16,NORMAL);           //显示流量字符
                LCD_ASCII("B",51,4,7,16,NORMAL);                //显示A字符
                
                /*********************通道A流量打印***********************/
                LCD_String("流量",25,6,13,16,NORMAL);           //显示流量字符
                LCD_ASCII("A",51,6,7,16,NORMAL);                //显示A字符
                LCD_ASCII(":",58,6,7,16,NORMAL);                //显示:字符
                LCD_ASCII("L/min",92,6,7,16,NORMAL);            //显示温度值字符
                
                Float2Str(sampling_a,str1,2);
                LCD_ASCII((uint8_t*)str1,64,6,7,16,NORMAL);
                
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 1;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            /*********************计数时间读取***********************/
            //时
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_A);
            LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
            //分
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_A);
            LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
             //秒
            sprintf(str,"%02d\0", (uint8_t)Timer_second_A);
            LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
            
            /*********************计数时间读取***********************/
            //时
            sprintf(str,"%02d:\0",(uint8_t)Timer_hour_B);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //分
            sprintf(str,"%02d:\0",(uint8_t)Timer_minute_B);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //秒
            sprintf(str,"%02d\0", (uint8_t)Timer_second_B);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            /*********************显示箭头指针部分***********************/
            LCD_ASCII("-->",3,2*(add_new-3),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 3)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-3),24,2*(add_old-3)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 7) && (add_new <= 9))
        {
            if(fla3 == 0)
            {
                //第三页
                LCD_ASCII("3/5",70,0,7,16,MOVEUP);              //显示2/4界面字符
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                
                /*********************通道B流量打印***********************/
                LCD_String("流量",25,2,13,16,NORMAL);           //显示流量字符
                LCD_ASCII("B",51,2,7,16,NORMAL);                //显示B字符
                LCD_ASCII(":",58,2,7,16,NORMAL);                //显示:字符
                LCD_ASCII("L/min",92,2,7,16,NORMAL);            //显示单位值字符

                LCD_String("电压",25,4,13,16,NORMAL);           //显示电压字符
                LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
                LCD_ASCII(":",58,4,7,16,NORMAL);                //显示:字符
                
                LCD_String("电压",25,6,13,16,NORMAL);           //显示电压字符
                LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
                LCD_ASCII(":",58,6,7,16,NORMAL);                //显示:字符
                
                //流量B
                Float2Str(sampling_b,str1,2);
                LCD_ASCII((uint8_t*)str1,64,2,7,16,NORMAL);
                
                //气泵A电压
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,64,4,7,16,NORMAL);               //气泵A电压
                
                //气泵B电压
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,64,6,7,16,NORMAL);               //气泵B电压
                
                
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 1;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            /*********************电压值***********************/
            if(ad == 50)
            {
                //气泵A电压
                LCDClrWin(64,4,127,3);                           //清页显示变动部分
                Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
                sprintf((char*)(tab3),"%sV\0",tab3);
                LCD_ASCII(tab3,64,4,7,16,NORMAL);               //气泵A电压
                
                //气泵B电压
                LCDClrWin(64,6,127,5);                           //清页显示变动部分
                Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
                sprintf((char*)(tab4),"%sV\0",tab4);
                LCD_ASCII(tab4,64,6,7,16,NORMAL);               //气泵B电压
                ad = 0;
            }
            ad++;  
            /*********************显示箭头指针部分***********************/
            
            LCD_ASCII("-->",3,2*(add_new-6),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 6)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(3,2*(add_old-6),24,2*(add_old-6)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
        else if((add_new >= 10) && (add_new <= 12))
        {
            if(fla4 == 0)
            {
                //第四页
                LCD_ASCII("4/5",70,0,7,16,MOVEUP);              //显示3/4界面字符
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                LCD_String("加热区",30,2,13,16,NORMAL);         //显示加热区字符
                LCD_ASCII(":",69,2,7,16,NORMAL);                //显示:字符
                
                LCD_String("温度",30,4,13,16,NORMAL);           //显示温度字符
                LCD_ASCII("A",58,4,7,16,NORMAL);                //显示A字符
                LCD_ASCII(":",69,4,7,16,NORMAL);                //显示:字符
                
                LCD_String("温度",30,6,13,16,NORMAL);           //显示温度字符
                LCD_ASCII("B",58,6,7,16,NORMAL);                //显示B字符
                LCD_ASCII(":",69,6,7,16,NORMAL);                //显示:字符
                
                //加热区
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,2,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道A温度
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,4,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道B温度
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",107,6,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 1;                                          //为初次显示初始化标志4
                fla5 = 0;                                          //为初次显示初始化标志5
            }
            /*********************加热温度***********************/
            //加热温度
            ad1++;
            if(ad1 > 50)
            {
                ad1 = 0;
                //加热区
                if(g_Temperature.DQ3_exist == 0)
                {
                    LCDClrWin(76,2,127,3);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 0)
                    {
                        if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        }
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ3_TEMP < 10)
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,2,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,2,127,3);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                            LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道A温度
                if(g_Temperature.DQ1_exist == 0)
                {
                    LCDClrWin(76,4,127,5);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 0)
                    {
                        if(g_Temperature.DQ1_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        }
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ1_TEMP < 10)
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",104,4,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,4,127,5);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                            LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
                //通道B温度
                if(g_Temperature.DQ2_exist == 0)
                {
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 0)
                    {
                        if(g_Temperature.DQ2_TEMP <= (-10))                 //调整温度的显示字符
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                        }
                        else
                        {
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        }
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        if(g_Temperature.DQ2_TEMP < 10)
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",107,6,13,16,NORMAL);                //显示℃字符
                        }
                        else
                        {
                            LCDClrWin(76,6,127,7);                               //清页显示变动部分
                            Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                            LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                            LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                        }
                    }
                }
            }
            /*********************显示箭头指针部分***********************/
            LCD_ASCII("-->",6,2*(add_new-9),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 9)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-9),28,2*(add_old-9)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
        else if((add_new > 12) && (add_new <= 13))
        {
            if(fla5 == 0)
            {
                LCD_ASCII("5/5",70,0,7,16,MOVEUP);              //显示3/4界面字符
                LCDClrWin(0,2,127,7);                           //清页显示变动部分
                
                LCD_String("气压",30,2,13,16,NORMAL);           //显示气压字符
                LCD_ASCII(":",56,2,7,16,NORMAL);                //显示:字符
                fla1 = 0;                                          //为初次显示初始化标志1
                fla2 = 0;                                          //为初次显示初始化标志2
                fla3 = 0;                                          //为初次显示初始化标志3
                fla4 = 0;                                          //为初次显示初始化标志4
                fla5 = 1;                                          //为初次显示初始化标志5
            }
            /*********************气压值***********************/
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
            
            /*********************显示箭头指针部分***********************/
            LCD_ASCII("-->",6,2*(add_new-12),7,16,NORMAL);                     //显示箭头符号
            if (add_old != add_new)
            {	
                if(add_old == 12)                                              //第二页开始不需要清光标
                {
                    add_old = add_new;     
                }
                else
                {
                    LCDClrWin(6,2*(add_old-12),28,2*(add_old-12)+1);            //清除上一个坐标
                    add_old = add_new;   
                }
            }
        }
    }     
}




/*
*******************************************************
函数名称：void Display_SamplingMenu_SubContinue(void)
函数功能：采样子界面 采样继续的子界面 
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubContinue(void)
{
    uint8_t *key;
    uint8_t judge_new1 = 1;
    uint8_t judge_old1 = 1;
    char str[10];
    
    LCDClrWin(0,0,127,7);                           //清页显示变动部分
    LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
    LCD_String("采样继续",0,0,13,16,MOVEUP);        //显示采样继续字符
    LCD_ASCII("...",52,0,7,16,MOVEUP);              //显示。。。字符
    
    LCD_String("是否继续上次采样",6,2,13,16,NORMAL);//显示是否继续上次采样字符
    LCD_ASCII("?",110,2,7,16,NORMAL);               //显示?字符
    LCD_ASCII("-->",6,4,7,16,NORMAL);               //显示箭头符号
    LCD_ASCII("(1)",37,4,7,16,NORMAL);              //显示(1)符号
    LCD_String("是",58,4,13,16,NORMAL);             //显示是字符
    LCD_ASCII("(2)",37,6,7,16,NORMAL);              //显示(2)符号
    LCD_String("否",58,6,13,16,NORMAL);             //显示是字符
    
    /*未完成定时显示部分*/
    g_Unfinish_Flag = 1;                         //未完成标志
    Timer_second = 30;                           //进行30s倒计时 
//    TIM_Cmd(TIM2, ENABLE);	                 //使能定时器2
    PCF8563_TIE_EnableDisable(1);           //PCF8563定时器使能
    while(1)
    {
        /*显示30s倒计时部分*/
        sprintf(str,"%02d\0", (uint8_t)Timer_second);
        LCD_ASCII((uint8_t*)str,102,6,7,16,NORMAL);
        
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        /*************************************读取按键进行是否切换**************************************/
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
//            TIM_Cmd(TIM2, DISABLE);	                 //使能定时器2
            PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
            g_Unfinish_Flag = 0;                         //停止倒计时
            
            if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 1)     //检测是否有未完成的采样，为立即采样未完成的采样      
            { 
                PMenu = ImmediatelyMenu;                        //直接进入立即采样指针
                g_UserChoose = 2;                               //锁定为第二界面
                Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //读出采样的小时值
                Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //读出采样的分钟值
                Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //读出采样的秒钟值
                
                Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //读出采样的小时值
                Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //读出采样的分钟值
                Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //读出采样的秒钟值
                
                g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //恢复定时器状态
                g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //恢复定时器状态
                
                g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //定时器使能或失能
                g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //定时器使能或失能
                
                Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay();
                return;
            }
            else if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 2)//检测是否有未完成的采样，为定时采样未完成的采样
            {
                PMenu = TimingMenu;                        //直接进入定时采样指针
                g_UserChoose = 2;                               //锁定为第二界面
                Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //读出采样的小时值
                Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //读出采样的分钟值
                Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //读出采样的秒钟值
                
                Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //读出采样的小时值
                Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //读出采样的分钟值
                Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //读出采样的秒钟值
                
                g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //恢复定时器状态
                g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //恢复定时器状态
                
                g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //定时器使能或失能
                g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //定时器使能或失能
                
                Display_SamplingMenu_SubTiming_SubWait_SubUnderWay();
                return;
            }
        }
        else if(*key == KEY_ENTER)
        {
            if(judge_new1 == 1)
            {
//                TIM_Cmd(TIM2, DISABLE);	                     //使能定时器2
                PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
                g_Unfinish_Flag = 0;                         //停止倒计时
                Timer_second = 0;                            //清零
                
                if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 1)     //检测是否有未完成的采样，为立即采样未完成的采样      
                { 
                    PMenu = ImmediatelyMenu;                        //直接进入立即采样指针
                    g_UserChoose = 2;                               //锁定为第二界面
                    Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //读出采样的小时值
                    Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //读出采样的分钟值
                    Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //读出采样的秒钟值
                    
                    Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //读出采样的小时值
                    Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //读出采样的分钟值
                    Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //读出采样的秒钟值
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //恢复定时器状态
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //恢复定时器状态
                    
                    g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //定时器使能或失能
                    g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //定时器使能或失能
                    
                    Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay();
                    return;
                }
                else if(FM24C64_READ_BYTE(UNFINISHED_FLAG) == 2)//检测是否有未完成的采样，为定时采样未完成的采样
                {
                    PMenu = TimingMenu;                        //直接进入定时采样指针
                    g_UserChoose = 2;                               //锁定为第二界面
                    Timer_hour_A = FM24C64_READ_BYTE(TIMER_HOUR_A);      //读出采样的小时值
                    Timer_minute_A = FM24C64_READ_BYTE(TIMER_MINUTE_A);  //读出采样的分钟值
                    Timer_second_A = FM24C64_READ_BYTE(TIMER_SECOND_A);  //读出采样的秒钟值
                
                    Timer_hour_B = FM24C64_READ_BYTE(TIMER_HOUR_B);      //读出采样的小时值
                    Timer_minute_B = FM24C64_READ_BYTE(TIMER_MINUTE_B);  //读出采样的分钟值
                    Timer_second_B = FM24C64_READ_BYTE(TIMER_SECOND_B);  //读出采样的秒钟值
                    
                    g_TimeFlag_A = FM24C64_READ_BYTE(TIMER_FLAG_A);  //恢复定时器状态
                    g_TimeFlag_B = FM24C64_READ_BYTE(TIMER_FLAG_B);  //恢复定时器状态
                    
                    g_TimeEnableDisable_A = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_A);  //定时器使能或失能
                    g_TimeEnableDisable_B = FM24C64_READ_BYTE(TIMER_ENABLE_DISABLE_B);  //定时器使能或失能
                    
                    Display_SamplingMenu_SubTiming_SubWait_SubUnderWay();
                    return;
                }
            }
            else
            {
//                TIM_Cmd(TIM2, DISABLE);	                              //使能定时器2
                PCF8563_TIE_EnableDisable(0);           //PCF8563定时器失能
                g_Unfinish_Flag = 0;                                  //停止倒计时
                Timer_second = 0;                                     //清零
                g_TimeFlag_A = 0;
                g_TimeFlag_B = 0;
                g_TimeEnableDisable_A = 0;
                g_TimeEnableDisable_B = 0;
                FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_A,g_TimeEnableDisable_A);  //定时器使能或失能
                FM24C64_WRITE_BYTE(TIMER_ENABLE_DISABLE_B,g_TimeEnableDisable_B);  //定时器使能或失能
                FM24C64_WRITE_BYTE(TIMER_FLAG_A,g_TimeFlag_A);  //恢复定时器状态
                FM24C64_WRITE_BYTE(TIMER_FLAG_B,g_TimeFlag_B);  //恢复定时器状态
                FM24C64_WRITE_BYTE(UNFINISHED_FLAG,0);           //写入完成标志
                //返回前一界面，清全屏
                LCDClrWin(0,0,127,7);                               //清全屏
                /*返回相关界面标志清零*/
                flag1 = 0;                                          //为初次显示初始化标志1
                flag2 = 0;                                          //为初次显示初始化标志2
                flag3 = 0;                                          //为初次显示初始化标志3
                flag4 = 0;                                          //为初次显示初始化标志4
                flag5 = 0;                                          //为初次显示初始化标志5
                return;
            }
        }
        /*********************显示箭头指针部分***********************/
        LCD_ASCII("-->",6,2*(judge_new1+1),7,16,NORMAL);//显示箭头符号
        if (judge_old1 != judge_new1)
        {	
            LCDClrWin(6,2*(judge_old1+1),28,2*(judge_old1+1)+1);//清除上一个坐标
            judge_old1 = judge_new1;     
        }
    }
}

/******************* 采样子界面 立即采样定义*****************/
/*
*******************************************************
函数名称：void Display_SamplingMenu_SubImmediately(void)
函数功能：采样子界面 立即采样的子界面 
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubImmediately(void)
{
    char str[10];
    uint8_t immediately_hour_a = 0;         //立即采样设置小时时间00
    uint8_t immediately_minute_a = 0;       //立即采样设置分钟时间00
    uint8_t immediately_second_a = 0;       //立即采样设置秒钟时间00
    
    uint8_t immediately_hour_b = 0;         //立即采样设置小时时间00
    uint8_t immediately_minute_b = 0;       //立即采样设置分钟时间00
    uint8_t immediately_second_b = 0;       //立即采样设置秒钟时间00
    if(g_UserChoose < 2)
    {
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("立即采样",38,0,13,16,MOVEUP);       //显示立即采样字符
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/2界面字符
        
            LCD_String("当前时间",8,2,13,16,NORMAL);        //显示当前字符
            
            /*通道A采集时间*/
            LCD_String("采时",25,4,13,16,NORMAL);           //显示采时字符
            LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
            
            //时
            FM24C64_READ_MUL(IMMEDIATELY_HOUR_A,(uint8_t*)&immediately_hour_a,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_hour_a);
            LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
            //分
            FM24C64_READ_MUL(IMMEDIATELY_MINUTE_A,(uint8_t*)&immediately_minute_a,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_minute_a);
            LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
             //秒
            FM24C64_READ_MUL(IMMEDIATELY_SECOND_A,(uint8_t*)&immediately_second_a,1);
            sprintf(str,"%02d\0", (uint8_t)immediately_second_a);
            LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
            
            /*通道B采集时间*/
            LCD_String("采时",25,6,13,16,NORMAL);           //显示采时字符
            LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
            
            //时
            FM24C64_READ_MUL(IMMEDIATELY_HOUR_B,(uint8_t*)&immediately_hour_b,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_hour_b);
            LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
            //分
            FM24C64_READ_MUL(IMMEDIATELY_MINUTE_B,(uint8_t*)&immediately_minute_b,1);
            sprintf(str,"%02d:\0",(uint8_t)immediately_minute_b);
            LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
             //秒
            FM24C64_READ_MUL(IMMEDIATELY_SECOND_B,(uint8_t*)&immediately_second_b,1);
            sprintf(str,"%02d\0", (uint8_t)immediately_second_b);
            LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
            
            flag1 = 1;
            flag2 = 0;
        }
        //时
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.hour);
        LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
        //分
        sprintf(str,"%02d:\0", (uint8_t)g_RTCTime.minute);
        LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
         //秒
        sprintf(str,"%02d\0", (uint8_t)g_RTCTime.second);
        LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
        
        LCD_ASCII("-->",3,2*(g_UserChoose+2),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(3,2*(s_olderchoose+2),24,2*(s_olderchoose+2)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("立即采样",38,0,13,16,MOVEUP);       //显示定时采样字符
            //第二页
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            
            LCD_String("启动采样",38,2,13,16,NORMAL);       //启动调节字符
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",12,2*(g_UserChoose-1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 1)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(12,2*(s_olderchoose-1),33,2*(s_olderchoose-1)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
*******************************************************
函数名称：void Display_SamplingMenu_SubImmediately_IMMEDIATELY_A(void)
函数功能：采样子界面 立即采样的子界面 (立即采样采集时间设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubImmediately_IMMEDIATELY_A(void)
{
    uint8_t immediately_hour_a = 0;         //立即采样设置小时时间00
    uint8_t immediately_minute_a = 0;       //立即采样设置分钟时间00
    uint8_t immediately_second_a = 0;       //立即采样设置秒钟时间00
    
    uint8_t old_immediately_hour_a = 0;         //采样设置小时时间00
    uint8_t old_immediately_minute_a = 0;       //采样设置分钟时间00
    uint8_t old_immediately_second_a = 0;       //采样设置秒钟时间00
     //时分秒
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_A,(uint8_t*)&immediately_hour_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_A,(uint8_t*)&immediately_minute_a,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_A,(uint8_t*)&immediately_second_a,1);
    
    old_immediately_hour_a = immediately_hour_a;
    old_immediately_minute_a = immediately_minute_a;
    old_immediately_second_a = immediately_second_a;
    
    int8_t hour_ten = immediately_hour_a / 10;                    //获得时的十位数据
    int8_t hour_one = immediately_hour_a % 10;                    //获得时的个位数据
    int8_t minute_ten = immediately_minute_a / 10;                //获得分的十位数据
    int8_t minute_one = immediately_minute_a % 10;                //获得分的个位数据
    int8_t second_ten = immediately_second_a / 10;                //获得秒的十位数据
    int8_t second_one = immediately_second_a % 10;                //获得秒的个位数据
    
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
函数名称：void Display_SamplingMenu_SubImmediately_IMMEDIATELY(void)
函数功能：采样子界面 立即采样的子界面 (立即采样采集时间设置)
入口参数：无
出口参数：无
*******************************************************
*/
void Display_SamplingMenu_SubImmediately_IMMEDIATELY_B(void)
{
    uint8_t immediately_hour_b = 0;         //立即采样设置小时时间00
    uint8_t immediately_minute_b = 0;       //立即采样设置分钟时间00
    uint8_t immediately_second_b = 0;       //立即采样设置秒钟时间00
    
    uint8_t old_immediately_hour_b = 0;         //采样设置小时时间00
    uint8_t old_immediately_minute_b = 0;       //采样设置分钟时间00
    uint8_t old_immediately_second_b = 0;       //采样设置秒钟时间00
     //时分秒
    FM24C64_READ_MUL(IMMEDIATELY_HOUR_B,(uint8_t*)&immediately_hour_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_MINUTE_B,(uint8_t*)&immediately_minute_b,1);
    FM24C64_READ_MUL(IMMEDIATELY_SECOND_B,(uint8_t*)&immediately_second_b,1);
    
    old_immediately_hour_b = immediately_hour_b;
    old_immediately_minute_b = immediately_minute_b;
    old_immediately_second_b = immediately_second_b;
    
    int8_t hour_ten = immediately_hour_b / 10;                    //获得时的十位数据
    int8_t hour_one = immediately_hour_b % 10;                    //获得时的个位数据
    int8_t minute_ten = immediately_minute_b / 10;                //获得分的十位数据
    int8_t minute_one = immediately_minute_b % 10;                //获得分的个位数据
    int8_t second_ten = immediately_second_b / 10;                //获得秒的十位数据
    int8_t second_one = immediately_second_b % 10;                //获得秒的个位数据
    
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
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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

/****************************** 查询界面 函数定义******************************/

/*
********************************************************************************
函数名称：void Display_SeekMenu1(void)
函数功能：查询界面菜单显示1
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_SeekMenu1(void)
{
    uint8_t file_number = 0;
    char str[10];
    if(g_UserChoose < 3)
    {
        //防止反复刷重复的界面
        if(flag1 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("查询",50,0,13,16,MOVEUP);           //显示查询字符
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/2界面字符
            LCD_String("文件号",37,2,13,16,NORMAL);         //显示文件号字符
            LCD_ASCII("[",76,2,7,16,NORMAL);                //显示[字符
            
            FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1); 
            sprintf(str,"%03d\0", (uint8_t)file_number);
            LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);         //显示编号数值
            
            LCD_ASCII("]",104,2,7,16,NORMAL);               //显示]字符
            LCD_String("文件上翻",37,4,13,16,NORMAL);       //显示文件上翻字符
            LCD_String("文件下翻",37,6,13,16,NORMAL);       //显示文件下翻字符
            flag1 = 1;
            flag2 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
        if(flag2 == 0)
        {
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("查询",50,0,13,16,MOVEUP);           //显示查询字符
            //第二页
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            LCD_String("文件详细",37,2,13,16,NORMAL);       //显示文件详细字符
            LCD_String("文件清零",37,4,13,16,NORMAL);       //文件清零
            flag2 = 1;
            flag1 = 0;
        }
        
        LCD_ASCII("-->",7,2*(g_UserChoose-2),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(7,2*(s_olderchoose-2),28,2*(s_olderchoose-2)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        }
    }
}

/*
********************************************************************************
函数名称：void Display_SeekMenu1_FILE_NUMBER(void)
函数功能：查询界面菜单显示1--(文件编号设置)
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_SeekMenu1_FILE_NUMBER(void)
{
    uint8_t file_number = 0;         //文件号设置
    uint8_t old_file_number = 0;     //存放老的文件号
    
    int8_t file_number_hundred = 0;   //文件号的百位
    int8_t file_number_ten = 0;       //文件号的十位
    int8_t file_number_one = 0;       //文件号的个位
    uint8_t add = 1;
    char str[10];
    uint8_t *key;
    
    FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    old_file_number = file_number;
    
    file_number_hundred = file_number / 100;
    file_number_ten = file_number / 10 % 10;
    file_number_one = file_number % 10;
    
    //数据位进行反显
    if(file_number_hundred == 0)              {LCD_ASCII("0",83,2,7,16,INVERSER);}
    else if(file_number_hundred == 1)         {LCD_ASCII("1",83,2,7,16,INVERSER);}
    else if(file_number_hundred == 2)         {LCD_ASCII("2",83,2,7,16,INVERSER);}

    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
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
函数名称：void Display_SeekMenu1_UPTURN(void)
函数功能：查询界面菜单显示1--(文件上翻)
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_SeekMenu1_UPTURN(void)
{
    uint8_t file_number = 0;         //文件号设置
    
    char str[10];
    
    FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    
    LCD_String("文件上翻",37,4,13,16,INVERSER);       //反显文件上翻字符
    
    file_number++;
    if(file_number > 180)
    {
        file_number = 1;
    }
    
    sprintf(str,"%03d\0", (uint8_t)file_number);
    LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);
    FM24C64_WRITE_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    OSTimeDly(10);
    LCD_String("文件上翻",37,4,13,16,NORMAL);       //反显文件上翻字符
    return;
}

/*
********************************************************************************
函数名称：void Display_SeekMenu1_DOWNTURN(void)
函数功能：查询界面菜单显示1--(文件下翻)
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_SeekMenu1_DOWNTURN(void)
{
    int32_t file_number = 0;         //文件号设置

    char str[10];
    
    FM24C64_READ_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    
    LCD_String("文件下翻",37,6,13,16,INVERSER);       //反显文件上翻字符
    
    file_number--;
    if(file_number <= 0)
    {
        file_number = 180;
    }
    
    sprintf(str,"%03d\0", (uint8_t)file_number);
    LCD_ASCII((uint8_t*)str,83,2,7,16,NORMAL);
    FM24C64_WRITE_MUL(FILE_NUMBER,(uint8_t*)&file_number,1);
    OSTimeDly(10);
    LCD_String("文件下翻",37,6,13,16,NORMAL);       //反显文件上翻字符
    return;
}

/**************** 查询子界面 文件详细查询*******************/

/*
************************************************
函数名称：void Display_SeekMenu2_SubFile1(void)
函数功能：查询子界面 文件详细查询显示1
入口参数：无
出口参数：无
************************************************
*/
void Display_SeekMenu2_SubFile1(void)
{
    uint8_t file_number = 0;
    uint8_t number = 0;
    uint8_t key_new = 1;
    uint8_t key_old = 1;
    
    uint8_t fla1 = 0;                                          //为初次显示初始化标志1
    uint8_t fla2 = 0;                                          //为初次显示初始化标志2
    uint8_t fla3 = 0;                                          //为初次显示初始化标志3
    uint8_t fla4 = 0;                                          //为初次显示初始化标志4
    uint8_t fla5 = 0;                                          //为初次显示初始化标志5
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
    FM24C64_READ_MUL((STORAGE_START + (file_number-1)*43), (uint8_t*)&number, 1);       //读取存储区编号
    
    //此空间没有存储数据
    if(number == 0)
    {
        LCDClrWin(0,2,127,7);                           //清部分屏
        LCD_String("文件为空",34,2,13,16,NORMAL);       //显示文件字符
        LCD_ASCII("!",86,2,7,16,NORMAL);                //显示[字符
        while(1)
        {
            //显示电池
            Display_Batter(Power_flag);
            //显示电源
            Display_Power(Power_flag);
            
            key = OSMboxAccept(KEYMbox);
            if((*key == KEY_CAL) || (*key == KEY_ENTER))
            {
                LCDClrWin(0,0,127,7);                           //清全屏
                LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                LCD_String("查询",50,0,13,16,MOVEUP);           //显示查询字符
                LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示1/2界面字符   
                flag2 = 0;
                return;
            }
        }
    }
    //要读的数据空间和
    else if(number == file_number)
    {
        /***********************************读出数据***************************************/
        FM24C64_Data_Storage(file_number,0);//读取数据
        LCDClrWin(0,0,127,7);                           //清全屏
        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
        LCD_String("文件",34,0,13,16,MOVEUP);           //显示文件字符
        LCD_ASCII("[",60,0,7,16,MOVEUP);                //显示[字符
        sprintf(str,"%03d\0", (uint8_t)file_number);
        LCD_ASCII((uint8_t*)str,67,0,7,16,MOVEUP);         //显示编号数值
        LCD_ASCII("]",88,0,7,16,MOVEUP);                //显示]字符
        while(1)
        {
            //显示电池
            Display_Batter(Power_flag);
            //显示电源
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
                LCDClrWin(0,0,127,7);                           //清全屏
                LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
                LCD_String("查询",50,0,13,16,MOVEUP);           //显示查询字符
                LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示1/2界面字符   
                flag2 = 0;
                return;
            }
            if(key_new <= 3)
            {
                if(fla1 == 0)
                {
                    //第一页
                    LCDClrWin(0,2,127,7);                           //清页显示变动部分
                    LCD_ASCII("1/6",7,0,7,16,MOVEUP);               //显示2/5界面字符
                    LCD_String("日",25,2,13,16,NORMAL);             //显示当前字符
                    LCD_String("期",47,2,13,16,NORMAL);             //显示当前字符
                    LCD_String("时",25,4,13,16,NORMAL);             //显示当前字符
                    LCD_String("间",47,4,13,16,NORMAL);             //显示当前字符
                    LCD_String("采时",25,6,13,16,NORMAL);           //显示采时字符
                    LCD_ASCII("A",51,6,7,16,NORMAL);
                    /*********************当前时间读取***********************/
                    //年
                    sprintf(str,"%02d-\0", (uint8_t)g_StorageData.now_year);
                    LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
                    //月
                    sprintf(str,"%02d-\0", (uint8_t)g_StorageData.now_month);
                    LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
                     //日
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.now_day);
                    LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                    //时
                    sprintf(str,"%02d:\0", (uint8_t)g_StorageData.now_hour);
                    LCD_ASCII((uint8_t*)str,64,4,7,16,NORMAL);
                    //分
                    sprintf(str,"%02d:\0", (uint8_t)g_StorageData.now_minute);
                    LCD_ASCII((uint8_t*)str,85,4,7,16,NORMAL);
                     //秒
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.now_second);
                    LCD_ASCII((uint8_t*)str,106,4,7,16,NORMAL);
                    
                    /*********************采集时间读取***********************/
                    //时
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_hour_a);
                    LCD_ASCII((uint8_t*)str,64,6,7,16,NORMAL);
                    //分
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_minute_a);
                    LCD_ASCII((uint8_t*)str,85,6,7,16,NORMAL);
                     //秒
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.sampling_second_a);
                    LCD_ASCII((uint8_t*)str,106,6,7,16,NORMAL);
                      
                    fla1 = 1;
                    fla2 = 0;
                    fla3 = 0;
                    fla4 = 0;
                    fla5 = 0;
                    fla6 = 0;
                }  
                
                LCD_ASCII("-->",3,2*key_new,7,16,NORMAL);//显示箭头符号
                if (key_old != key_new)
                {	
                    LCDClrWin(3,2*key_old,24,2*key_old+1);//清除上一个坐标
                    key_old = key_new;     
                }
            }
            
            else if((key_new >= 4) && (key_new <= 6))
            {
                if(fla2 == 0)
                {
                    //第二页
                    LCDClrWin(0,2,127,7);                           //清页显示变动部分
                    LCD_ASCII("2/6",7,0,7,16,MOVEUP);               //显示2/5界面字符
                    
                    LCD_String("采时",25,2,13,16,NORMAL);           //显示采时字符
                    LCD_ASCII("B",51,2,7,16,NORMAL);
                    
                    LCD_String("电压",25,4,13,16,NORMAL);           //显示电压字符
                    LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
                    LCD_ASCII(":",58,4,7,16,NORMAL);                //显示:字符
                    
                    LCD_String("电压",25,6,13,16,NORMAL);           //显示电压字符
                    LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
                    LCD_ASCII(":",58,6,7,16,NORMAL);                //显示:字符
                                        
                    /*********************采集时间读取***********************/
                    //时
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_hour_b);
                    LCD_ASCII((uint8_t*)str,64,2,7,16,NORMAL);
                    //分
                    sprintf(str,"%02d:\0",(uint8_t)g_StorageData.sampling_minute_b);
                    LCD_ASCII((uint8_t*)str,85,2,7,16,NORMAL);
                     //秒
                    sprintf(str,"%02d\0", (uint8_t)g_StorageData.sampling_second_b);
                    LCD_ASCII((uint8_t*)str,106,2,7,16,NORMAL);
                    
                    //气泵A电压
                    Float2Str(((float)g_StorageData.voltage_A/100),tab1,2);
                    sprintf((char*)(tab1),"%sV\0",tab1);
                    LCD_ASCII(tab1,65,4,7,16,NORMAL);                   //气泵A电压
                    
                    //气泵B电压
                    Float2Str(((float)g_StorageData.voltage_B/100),tab2,2);
                    sprintf((char*)(tab2),"%sV\0",tab2);
                    LCD_ASCII(tab2,65,6,7,16,NORMAL);                   //气泵B电压
                    
                    fla1 = 0;
                    fla2 = 1;
                    fla3 = 0;
                    fla4 = 0;
                    fla5 = 0;
                    fla6 = 0;
                }
                LCD_ASCII("-->",3,2*(key_new-3),7,16,NORMAL);//显示箭头符号
                if (key_old != key_new)
                {	
                    if(key_old == 3)                          //第二页开始不需要清光标
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(3,2*(key_old-3),24,2*(key_old-3)+1);//清除上一个坐标
                        key_old = key_new;   
                    }
                } 
            }
            else if((key_new >= 7) && (key_new <= 9))
            {
                if(fla3 == 0)
                {
                    //第三页
                    LCD_ASCII("3/6",7,0,7,16,MOVEUP);               //显示3/5界面字符
                    LCDClrWin(0,2,127,7);                           //清页显示变动部分
                    LCD_String("加热区",30,2,13,16,NORMAL);         //显示加热区字符
                    LCD_ASCII(":",69,2,7,16,NORMAL);                //显示:字符
                    
                    LCD_String("温度",30,4,13,16,NORMAL);           //显示温度字符
                    LCD_ASCII("A",58,4,7,16,NORMAL);                //显示A字符
                    LCD_ASCII(":",69,4,7,16,NORMAL);                //显示:字符
                    
                    
                    LCD_String("温度",30,6,13,16,NORMAL);           //显示温度字符
                    LCD_ASCII("B",58,6,7,16,NORMAL);                //显示B字符
                    LCD_ASCII(":",69,6,7,16,NORMAL);                //显示:字符
                    
                    
                    /***********************温度***********************/
                    //加热温度
                    if(g_StorageData.heattemp == 0xffff)
                    {
                        LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //显示:字符
                    }
                    else
                    {
                        Float2Str(((float)g_StorageData.heattemp/100),tab4,2);
                        LCD_ASCII(tab4,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",111,2,13,16,NORMAL);            //显示℃字符
                    }
                    //通道A温度
                    if(g_StorageData.temp_A == 0xffff)
                    {
                        LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符  
                    }
                    else
                    {
                        Float2Str(((float)g_StorageData.temp_A/100),tab5,2);
                        LCD_ASCII(tab5,76,4,7,16,NORMAL);                   //通道A温度
                        LCD_String("℃",111,4,13,16,NORMAL);            //显示℃字符
                    }
                    //通道B温度
                    if(g_StorageData.temp_B == 0xffff)
                    {
                        LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符  
                    }
                    else
                    {
                        Float2Str(((float)g_StorageData.temp_B/100),tab6,2);
                        LCD_ASCII(tab6,76,6,7,16,NORMAL);                   //通道B温度
                        LCD_String("℃",111,6,13,16,NORMAL);            //显示℃字符
                    }  
                    fla1 = 0;
                    fla2 = 0;
                    fla3 = 1;
                    fla4 = 0;
                    fla5 = 0;
                    fla6 = 0;
                }
                LCD_ASCII("-->",6,2*(key_new-6),7,16,NORMAL);//显示箭头符号
                if (key_old != key_new)
                {	
                    if(key_old == 6)                          //第二页开始不需要清光标
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(6,2*(key_old-6),27,2*(key_old-6)+1);//清除上一个坐标
                        key_old = key_new;   
                    }
                } 
            }
            else if((key_new >= 10) && (key_new <= 12))
            {
                if(fla4 == 0)
                {
                    //第四页
                    LCD_ASCII("4/6",7,0,7,16,MOVEUP);               //显示4/5界面字符
                    LCDClrWin(0,2,127,7);                           //清页显示变动部分
                    LCD_String("气",25,2,13,16,NORMAL);           //显示气压字符
                    LCD_String("压",45,2,13,16,NORMAL);           //显示气压字符
                    LCD_ASCII(":",58,2,7,16,NORMAL);                //显示:字符
                    
                    LCD_String("流量",25,4,13,16,NORMAL);           //显示流量字符
                    LCD_ASCII("A",51,4,7,16,NORMAL);                //显示A字符
                    LCD_ASCII(":",58,4,7,16,NORMAL);                //显示:字符
                    LCD_ASCII("L/min",92,4,7,16,NORMAL);            //显示温度值字符
                    
                    LCD_String("流量",25,6,13,16,NORMAL);           //显示流量字符
                    LCD_ASCII("B",51,6,7,16,NORMAL);                //显示B字符
                    LCD_ASCII(":",58,6,7,16,NORMAL);                //显示:字符
                    LCD_ASCII("L/min",92,6,7,16,NORMAL);            //显示单位值字符
                    
                    //流量值读取
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
                //气压值
                /*********************气压值***********************/
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
                
                LCD_ASCII("-->",1,2*(key_new-9),7,16,NORMAL);//显示箭头符号
                if (key_old != key_new)
                {	
                    if(key_old == 9)                          //第二页开始不需要清光标
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(1,2*(key_old-9),22,2*(key_old-9)+1);//清除上一个坐标
                        key_old = key_new;   
                    }
                }
            }
            else if((key_new >= 13) && (key_new <= 15))
            {
                if(fla5 == 0)
                {
                    //第五页
                    LCD_ASCII("5/6",7,0,7,16,MOVEUP);               //显示5/5界面字符
                    LCDClrWin(0,2,127,7);                           //清页显示变动部分
                    
                    LCD_String("体积",30,2,13,16,NORMAL);           //显示体积字符
                    LCD_ASCII("A",56,2,7,16,NORMAL);                //显示A字符
                    LCD_ASCII(":",63,2,7,16,NORMAL);                //显示:字符
                    
                    LCD_String("体积",30,4,13,16,NORMAL);           //显示体积字符
                    LCD_ASCII("B",56,4,7,16,NORMAL);                //显示B字符
                    LCD_ASCII(":",63,4,7,16,NORMAL);                //显示:字符
                    
                    LCD_String("标况",30,6,13,16,NORMAL);           //显示标况字符
                    LCD_ASCII("A",56,6,7,16,NORMAL);                //显示B字符
                    LCD_ASCII(":",63,6,7,16,NORMAL);                //显示:字符
                    
                    //体积A读取
                    Float2Str(g_StorageData.volume_A,str1,2);
                    sprintf((char*)(str1),"%sL\0",str1);
                    LCD_ASCII((uint8_t*)str1,70,2,7,16,NORMAL);
                    
                    //体积B读取
                    Float2Str(g_StorageData.volume_B,str1,2);
                    sprintf((char*)(str1),"%sL\0",str1);
                    LCD_ASCII((uint8_t*)str1,70,4,7,16,NORMAL);
                    
                    //标况A读取
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
                
                LCD_ASCII("-->",6,2*(key_new-12),7,16,NORMAL);//显示箭头符号
                if (key_old != key_new)
                {	
                    if(key_old == 12)                          //第二页开始不需要清光标
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(6,2*(key_old-12),27,2*(key_old-12)+1);//清除上一个坐标
                        key_old = key_new;   
                    }
                }
            }
            else if(key_new == 16)
            {
                if(fla6 == 0)
                {
                    //第五页
                    LCD_ASCII("6/6",7,0,7,16,MOVEUP);               //显示5/5界面字符
                    LCDClrWin(0,2,127,7);                           //清页显示变动部分
                        
                    LCD_String("标况",30,2,13,16,NORMAL);           //显示标况字符
                    LCD_ASCII("B",56,2,7,16,NORMAL);                //显示B字符
                    LCD_ASCII(":",63,2,7,16,NORMAL);                //显示:字符
                    
                    //标况B读取
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
                LCD_ASCII("-->",6,2*(key_new-15),7,16,NORMAL);//显示箭头符号
                if (key_old != key_new)
                {	
                    if(key_old == 15)                          //第二页开始不需要清光标
                    {
                        key_old = key_new;     
                    }
                    else
                    {
                        LCDClrWin(6,2*(key_old-15),27,2*(key_old-15)+1);//清除上一个坐标
                        key_old = key_new;   
                    }
                }
            }
        } 
    }
}

/*
************************************************
函数名称：void Display_SeekMenu2_SubFileClear(void)
函数功能：查询子界面 文件清零操作
入口参数：无
出口参数：无
************************************************
*/
void Display_SeekMenu2_SubFileClear(void)
{
    uint8_t dat = 0;
    uint8_t storage_number = 0;
    uint8_t *key;
    uint32_t address = 0;
    
    LCDClrWin(0,4,127,5);                           //清一行
    LCD_String("确认文件清零",21,4,13,16,NORMAL);           
    LCD_ASCII("?",99,4,7,16,NORMAL);                //显示界面字符   
    while(1)
    {
        //显示电池
        Display_Batter(Power_flag);
        //显示电源
        Display_Power(Power_flag);
        
        key = OSMboxAccept(KEYMbox);
        if(*key == KEY_ENTER)
        {
            LCDClrWin(0,4,127,5);                           //清一行
            LCD_String("文件清零中",28,4,13,16,NORMAL);    
            LCD_ASCII("...",93,4,7,16,NORMAL);                //显示界面字符   
            for(address = STORAGE_START; address < (8000+STORAGE_START); address++)
            {
                FM24C64_WRITE_BYTE(address,0);                  //写入0x0
                dat = FM24C64_READ_BYTE(address);               //读出0x0
                if(dat != 0)                                    //写入和读出的不相同
                {
                    LCDClrWin(0,4,127,5);                           //清一行
                    LCD_String("文件清零失败",21,4,13,16,NORMAL);  
                    LCD_ASCII("!",99,4,7,16,NORMAL);                //显示界面字符 
                    while(1)
                    {
                        //显示电池
                        Display_Batter(Power_flag);
                        //显示电源
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
            FM24C64_WRITE_MUL(STORAGE_NUMBER, (uint8_t*)&storage_number, 1);  //写入现在存储了多少个文件,存储区个数清零
            LCDClrWin(0,4,127,5);                           //清一行
            LCD_String("文件已清零",28,4,13,16,NORMAL);  
            LCD_ASCII("!",93,4,7,16,NORMAL);                //显示界面字符 
            while(1)
            {
                //显示电池
                Display_Batter(Power_flag);
                //显示电源
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

/****************************** 维护界面 函数定义******************************/

/*
********************************************************************************
函数名称：void Display_MaintainMenu(void)
函数功能：维护界面菜单显示
入口参数：无
出口参数：无
********************************************************************************
*/
void Display_MaintainMenu(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
        LCD_String("维护",50,0,13,16,MOVEUP);           //显示维护字符
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //显示1/1界面字符
        LCD_String("电压信息",37,2,13,16,NORMAL);       //显示电压信息字符
        LCD_String("温度气压",37,4,13,16,NORMAL);       //显示温度气压字符
        LCD_String("版本信息",37,6,13,16,NORMAL);       //显示版本信息字符
        
        flag1 = 1;
    }
    
    LCD_ASCII("-->",7,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
    if (s_olderchoose != g_UserChoose)
    {	
        LCDClrWin(7,2*(s_olderchoose+1),28,2*(s_olderchoose+1)+1);//清除上一个坐标
        s_olderchoose = g_UserChoose;     
    }
}

/******************** 维护界面子界面 电压信息**********************/

/*
******************************************************************
函数名称：void Display_MainTainMenu_SubDisplayVoltage1(void)
函数功能：维护界面子菜单 -电压信息1
入口参数：无
出口参数：无
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
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("电压信息",38,0,13,16,MOVEUP);       //显示电压信息字符
            
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/2界面字符
            LCDClrWin(0,2,127,7);                           //清页显示变动部分
            
            LCD_String("开关电压",25,2,13,16,NORMAL);       //显示开关电压字符
            LCD_ASCII(":",77,2,7,16,NORMAL);                //显示:字符
            LCD_String("电池电压",25,4,13,16,NORMAL);       //显示电池电压字符
            LCD_ASCII(":",77,4,7,16,NORMAL);                //显示:字符
            LCD_String("泵",25,6,13,16,NORMAL);             //显示泵字符
            LCD_ASCII("A",41,6,7,16,NORMAL);                //显示A字符
            LCD_String("电压",51,6,13,16,NORMAL);           //显示电压字符
            LCD_ASCII(":",77,6,7,16,NORMAL);                //显示:字符
            
            //电源电压
            LCDClrWin(84,2,127,3);                               //清页显示变动部分
            Float2Str(g_Power.pb0_adc8_power,tab1,2);
            sprintf((char*)(tab1),"%sV\0",tab1);
            LCD_ASCII(tab1,84,2,7,16,NORMAL);                   //电源电压
            //电池电压
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
            LCD_ASCII(tab2,84,4,7,16,NORMAL);                   //电池电压
            //气泵A电压
            LCDClrWin(84,6,127,7);
            Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
            sprintf((char*)(tab3),"%sV\0",tab3);
            LCD_ASCII(tab3,84,6,7,16,NORMAL);                   //气泵A电压
            
            flag1 = 1;
            flag2 = 0;
        }
        
        //由于电压扫描次数过多，所以这里延缓显示
        if(ad > 100)
        {
            //电源电压
            LCDClrWin(84,2,127,3);                               //清页显示变动部分
            Float2Str(g_Power.pb0_adc8_power,tab1,2);
            sprintf((char*)(tab1),"%sV\0",tab1);
            LCD_ASCII(tab1,84,2,7,16,NORMAL);                   //电源电压
            //电池电压
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
            LCD_ASCII(tab2,84,4,7,16,NORMAL);                   //电池电压
            //气泵A电压
            LCDClrWin(84,6,127,7);
            Float2Str(g_Power.pb1_adc9_motor1,tab3,2);
            sprintf((char*)(tab3),"%sV\0",tab3);
            LCD_ASCII(tab3,84,6,7,16,NORMAL);                   //气泵A电压
            
            ad = 0;
        }
        ad++;
        
        LCD_ASCII("-->",2,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(2,2*(s_olderchoose+1),23,2*(s_olderchoose+1)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
    }
    else
    {
         if(flag2 == 0)
        {
            //第二页
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("电压信息",38,0,13,16,MOVEUP);       //显示电压信息字符
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            LCD_String("泵",25,2,13,16,NORMAL);             //显示泵字符
            LCD_ASCII("B",41,2,7,16,NORMAL);                //显示B字符
            LCD_String("电压",51,2,13,16,NORMAL);           //显示电压字符
            LCD_ASCII(":",77,2,7,16,NORMAL);                //显示:字符
            //气泵B电压
            Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
            sprintf((char*)(tab4),"%sV\0",tab4);
            LCD_ASCII(tab4,84,2,7,16,NORMAL);                   //气泵A电压
            
            flag1 = 0;
            flag2 = 1;
        }  
        if(ad > 100)
        {
            //气泵B电压
            Float2Str(g_Power.pc1_adc11_motor2,tab4,2);
            sprintf((char*)(tab4),"%sV\0",tab4);
            LCD_ASCII(tab4,84,2,7,16,NORMAL);                   //气泵A电压
            ad = 0;
        }
        ad++;
        
        LCD_ASCII("-->",2,2*(g_UserChoose-2),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(2,2*(s_olderchoose-2),23,2*(s_olderchoose-2)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        } 
    }
}


/******************** 维护界面子界面 温度信息**********************/

/*
******************************************************************
函数名称：void Display_MainTainMenu_SubDisplayTemperaturePressure1(void)
函数功能：维护界面子菜单 -温度气压
入口参数：无
出口参数：无
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
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("温度气压",38,0,13,16,MOVEUP);       //显示温度气压字符
            LCD_ASCII("1/2",7,0,7,16,MOVEUP);               //显示1/2界面字符
            
            LCDClrWin(0,2,127,7);                           //清页显示变动部分
            
            LCD_String("加热区",29,2,13,16,NORMAL);         //显示加热区字符
            LCD_ASCII(":",68,2,7,16,NORMAL);                //显示:字符
            
            LCD_String("通道",29,4,13,16,NORMAL);           //显示通道字符
            LCD_ASCII("A",58,4,7,16,NORMAL);                //显示A字符
            LCD_ASCII(":",68,4,7,16,NORMAL);                //显示:字符
    
            LCD_String("通道",29,6,13,16,NORMAL);           //显示通道字符
            LCD_ASCII("B",58,6,7,16,NORMAL);                //显示B字符
            LCD_ASCII(":",68,6,7,16,NORMAL);                //显示:字符
            
            //加热区
            if(g_Temperature.DQ3_exist == 0)
            {
                LCDClrWin(76,2,127,3);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,2,127,3);                               //清页显示变动部分
                    LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",104,2,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                    }
                }
            }
            //通道A温度
            if(g_Temperature.DQ1_exist == 0)
            {
                LCDClrWin(76,4,127,5);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ1_TEMP < 0)
                {
                    if(g_Temperature.DQ1_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                    }
                    LCDClrWin(76,4,127,5);                               //清页显示变动部分
                    LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 10)
                    {
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",104,4,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                    }
                }
            }
            //通道B温度
            if(g_Temperature.DQ2_exist == 0)
            {
                LCDClrWin(76,6,127,7);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ2_TEMP < 0)
                {
                    if(g_Temperature.DQ2_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                    }
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",107,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                    }
                }
            }
            flag1 = 1;
            flag2 = 0;
        }
        
        //加热温度
        ad1++;
        if(ad1 > 100)
        {
            ad1 = 0;
            //加热区
            if(g_Temperature.DQ3_exist == 0)
            {
                LCDClrWin(76,2,127,3);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,2,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ3_TEMP < 0)
                {
                    if(g_Temperature.DQ3_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                    }
                    LCDClrWin(76,2,127,3);                               //清页显示变动部分
                    LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ3_TEMP < 10)
                    {
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",104,2,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,2,127,3);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ3_TEMP,tab3,2);
                        LCD_ASCII(tab3,76,2,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,2,13,16,NORMAL);                //显示℃字符
                    }
                }
            }
            //通道A温度
            if(g_Temperature.DQ1_exist == 0)
            {
                LCDClrWin(76,4,127,5);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ1_TEMP < 0)
                {
                    if(g_Temperature.DQ1_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                    }
                    LCDClrWin(76,4,127,5);                               //清页显示变动部分
                    LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ1_TEMP < 10)
                    {
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",104,4,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ1_TEMP,tab1,2);
                        LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
                    }
                }
            }
            //通道B温度
            if(g_Temperature.DQ2_exist == 0)
            {
                LCDClrWin(76,6,127,7);                               //清页显示变动部分
                LCD_ASCII("FALSE",76,6,7,16,NORMAL);                //显示:字符
            }
            else
            {
                if(g_Temperature.DQ2_TEMP < 0)
                {
                    if(g_Temperature.DQ2_TEMP <= (-10))                 //调整温度的显示字符
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,1);
                    }
                    else
                    {
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                    }
                    LCDClrWin(76,6,127,7);                               //清页显示变动部分
                    LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                    LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                }
                else
                {
                    if(g_Temperature.DQ2_TEMP < 10)
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",107,6,13,16,NORMAL);                //显示℃字符
                    }
                    else
                    {
                        LCDClrWin(76,6,127,7);                               //清页显示变动部分
                        Float2Str(g_Temperature.DQ2_TEMP,tab2,2);
                        LCD_ASCII(tab2,76,6,7,16,NORMAL);                   //加热温度
                        LCD_String("℃",112,6,13,16,NORMAL);                //显示℃字符
                    }
                }
            }
        }
        LCD_ASCII("-->",6,2*(g_UserChoose+1),7,16,NORMAL);//显示箭头符号
        if (s_olderchoose != g_UserChoose)
        {	
            LCDClrWin(6,2*(s_olderchoose+1),27,2*(s_olderchoose+1)+1);//清除上一个坐标
            s_olderchoose = g_UserChoose;     
        }
        
    }
    else
    {
        if(flag2 == 0)
        {
            //第二页
            LCDClrWin(0,0,127,7);                           //清变动区域
            LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
            LCD_String("温度气压",38,0,13,16,MOVEUP);       //显示温度气压字符
            
            LCD_ASCII("2/2",7,0,7,16,MOVEUP);               //显示2/2界面字符
            LCD_String("气压",29,2,13,16,NORMAL);           //显示气压字符
            LCD_ASCII(":",55,2,7,16,NORMAL);                //显示:字符
            flag1 = 0;
            flag2 = 1;
        }    
        //气压值读取
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
        LCD_ASCII("-->",6,2*(g_UserChoose-2),7,16,NORMAL);//显示箭头符号
        
        /*显示气压芯片读取的温度值————测试用*/
//        if(g_TEMP == 0)
//            {
//                LCDClrWin(76,4,127,5);                               //清页显示变动部分
//                LCD_ASCII("FALSE",76,4,7,16,NORMAL);                //显示:字符
//            }
//            else
//            {
//                if(g_TEMP < 0)
//                {
//                    if(g_TEMP <= (-10))                 //调整温度的显示字符
//                    {
//                        Float2Str(g_TEMP,tab5,1);
//                    }
//                    else
//                    {
//                        Float2Str(g_TEMP,tab5,2);
//                    }
//                    LCDClrWin(76,4,127,5);                               //清页显示变动部分
//                    LCD_ASCII(tab1,76,4,7,16,NORMAL);                   //加热温度
//                    LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
//                }
//                else
//                {
//                    if(g_TEMP < 10)
//                    {
//                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
//                        Float2Str(g_TEMP,tab5,2);
//                        LCD_ASCII(tab5,76,4,7,16,NORMAL);                   //加热温度
//                        LCD_String("℃",104,4,13,16,NORMAL);                //显示℃字符
//                    }
//                    else
//                    {
//                        LCDClrWin(76,4,127,5);                               //清页显示变动部分
//                        Float2Str(g_TEMP,tab5,2);
//                        LCD_ASCII(tab5,76,4,7,16,NORMAL);                   //加热温度
//                        LCD_String("℃",112,4,13,16,NORMAL);                //显示℃字符
//                    }
//                }
//            }
        
        
        if (s_olderchoose != g_UserChoose)
        {	
            if(s_olderchoose == 2)                          //第二页开始不需要清光标
            {
                s_olderchoose = g_UserChoose;     
            }
            else
            {
                LCDClrWin(6,2*(s_olderchoose-2),27,2*(s_olderchoose-2)+1);//清除上一个坐标
                s_olderchoose = g_UserChoose;   
            }
        } 
    }
}

/******************** 维护界面子界面 版本信息**********************/

/*
******************************************************************
函数名称：void Display_MainTainMenu_SubDisplayVersions(void)
函数功能：维护界面子菜单 -版本信息
入口参数：无
出口参数：无
******************************************************************
*/
void Display_MaintainMenu_SubDisplayVersions(void)
{
    if(flag1 == 0)
    {
        LCD_HoriStraightLine(1,1,6);                    //显示第一行分割线
        LCD_String("版本信息",38,0,13,16,MOVEUP);       //显示版本信息字符
        
        LCD_ASCII("1/1",7,0,7,16,MOVEUP);               //显示1/1界面字符
        
        LCD_String("版本号",21,2,13,16,NORMAL);         //显示版本号字符
        LCD_ASCII("[",66,2,7,16,NORMAL);                //显示[字符
        LCD_ASCII("V2.3",73,2,7,16,NORMAL);             //显示V1.0字符
        LCD_ASCII("]",101,2,7,16,NORMAL);               //显示]字符
        
        LCD_String("宇星科技",19,4,13,16,NORMAL);       //显示宇星科技字符
        LCD_ASCII("(",71,4,7,16,NORMAL);                //显示(字符
        LCD_String("深圳",78,4,13,16,NORMAL);           //显示深圳字符
        LCD_ASCII(")",104,4,7,16,NORMAL);               //显示)字符
        LCD_ASCII("www.szusst.cn",19,6,7,16,NORMAL);    //显示www.szusst.cn字符
        flag1 = 1;
    }
}