/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			gui.c
 *Description：     	      界面操作，实现界面和按键的结合 
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/************************************ 函数定义 ********************************/

/*
********************************************************************************
函数名称：void ShowMenu(void)
函数功能：界面显示函数
入口参数：无
出口参数：无
********************************************************************************
*/
void ShowMenu(void)
{	
    //判断电池是否有电或是否接电源
    if((g_Power.pc0_adc10_battery > 11) || (Power_flag == 1))
    { 
        if(FM24C64_READ_BYTE(UNFINISHED_FLAG) != 0)     //检测是否有未完成的采样    
        { 
            Display_SamplingMenu_SubContinue();         //采样继续界面
        }
    }
    switch (PMenu->ID)
    {    
        case mainmenu:
            Display_MainMenu();
            break;
            
        /************************设置部分*************************/
        case setmenu:
            Display_SetMenu1();
            break;
            
        /***************设置部分--子功能****************/    
        case timemenu:
            Display_SetMenu1_SubSetTime();
            break;
            
        case communicationmenu:
            Display_SetMenu1_SubSetCommunication1();
            break;
            
        case heatmenu:
            Display_SetMenu1_SubSetHeat();
            break;         
            
            
        /************************采样部分*************************/
        case samplingmenu:
            Display_SamplingMenu();
            break;
            
        /***************采样部分--子功能****************/    
        case presetmenu:
            Display_SamplingMenu_SubPreset();
            break;
            
        case timingmenu:
            Display_SamplingMenu_SubTiming1();
            break;
            
        case immediatelymenu:
            Display_SamplingMenu_SubImmediately();
            break;
            
            
       /************************查询部分*************************/
        case seekmenu:
            Display_SeekMenu1();
            break;
            
            
        /************************维护部分*************************/
        case maintainmenu:
            Display_MaintainMenu();
            break;
            
        /***************维护部分--子功能****************/    
        case voltagemenu:
            Display_MaintainMenu_SubDisplayVoltage1();
            break;
            
        case temperaturepressuremenu:
            Display_MaintainMenu_SubDisplayTemperaturePressure1();
            break;
            
        case versionsmenu:
            Display_MaintainMenu_SubDisplayVersions();
            break;
            
        default: break;
    }	
    //显示电池
    Display_Batter(Power_flag);
    //显示电源
    Display_Power(Power_flag);
}

/*
********************************************************************************
函数名称：void GUI_Init(void)
函数功能：进行初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void GUI_Init(void)
{
    g_UserChoose = 0;
    PMenu=MainMenu;                             //主界面显示
    MenuInit();                                 //初始化界面定义
    Display_MainMenu();                         //显示主界面
}

/*
********************************************************************************
函数名称：void KEY_GUI_Scan(uint8_t key)
函数功能：实现按键值扫描
入口参数：无
出口参数：无
********************************************************************************
*/
void KEY_GUI_Scan(uint8_t key)
{
    uint8_t i = 0;
    if(key == KEY_UP)
    {
        if((PMenu->ID) == mainmenu)
        {
            if(g_UserChoose == 0)
            {  
                g_UserChoose = 2;
            }
            else if(g_UserChoose == 1)
            {
               g_UserChoose = 3; 
            }
            else if(g_UserChoose == 2)
            {
               g_UserChoose = 0; 
            }
            else if(g_UserChoose == 3)
            {
               g_UserChoose = 1; 
            }
        }
        else
        {
            if((PMenu->MenuCount > 0) && (g_UserChoose > 0))
            {
                g_UserChoose--;     
            }
            else if(PMenu->MenuCount > 0)
            {
                g_UserChoose = PMenu->MenuCount - 1;            //如果箭头在顶端，则赋予最底端值
            }        
        } 
    }
    else if(key == KEY_DOWN)
    {
        if((PMenu->ID) == mainmenu)
        {
            if(g_UserChoose == 0)
            {  
                g_UserChoose = 2;
            }
            else if(g_UserChoose == 1)
            {
               g_UserChoose = 3; 
            }
            else if(g_UserChoose == 2)
            {
               g_UserChoose = 0; 
            }
            else if(g_UserChoose == 3)
            {
               g_UserChoose = 1; 
            }
        }
        else
        {
            if(g_UserChoose < (PMenu->MenuCount-1))
            {
                g_UserChoose++;                               //如果箭头在顶端，则赋予最底端值
            }
            else
            {
                g_UserChoose = 0;
            }        
        }
    }
    else if(key == KEY_LEFT)
    {
        if((PMenu->ID) == mainmenu)
        {
            if(g_UserChoose == 0)
            {  
                g_UserChoose = 1;
            }
            else if(g_UserChoose == 1)
            {
               g_UserChoose = 0; 
            }
            else if(g_UserChoose == 2)
            {
               g_UserChoose = 3; 
            }
            else if(g_UserChoose == 3)
            {
               g_UserChoose = 2; 
            }
        }
    }
    else if(key == KEY_RIGHT)
    {
        if((PMenu->ID) == mainmenu)
        {
            if(g_UserChoose == 0)
            {  
                g_UserChoose = 1;
            }
            else if(g_UserChoose == 1)
            {
               g_UserChoose = 0; 
            }
            else if(g_UserChoose == 2)
            {
               g_UserChoose = 3; 
            }
            else if(g_UserChoose == 3)
            {
               g_UserChoose = 2; 
            }
         }
    }
    else if(key == KEY_ENTER)
    {
        if((PMenu[g_UserChoose].Subs) != NullFuntion) 
        {
            (*PMenu[g_UserChoose].Subs)();                      //跳到相关函数处
        }
        else if (PMenu[g_UserChoose].ChildrenMenus != NULL)
        {
            for(i = 0; i < PMenu->MenuCount; i++)
            {
                PMenu[i].MenuState = g_UserChoose;              //保存当前状态的按键值状态
            }
            PMenu = PMenu[g_UserChoose].ChildrenMenus;          //获得子菜单
            LCDClrWin(0,0,127,7);                               //清全屏
            g_UserChoose = PMenu->MenuState;                    //恢复下一个界面的按键值
            s_olderchoose = 0;                                  //翻页设置老按键值为0
            flag1 = 0;                                          //为初次显示初始化标志1
            flag2 = 0;                                          //为初次显示初始化标志2
            flag3 = 0;                                          //为初次显示初始化标志3
            flag4 = 0;                                          //为初次显示初始化标志4
            flag5 = 0;                                          //为初次显示初始化标志5
        }  
    }
    else if(key == KEY_CAL)
    {
        if(PMenu->ParentMenus != NULL)
        {
            for(i = 0; i < PMenu->MenuCount; i++)
            {
                PMenu[i].MenuState = g_UserChoose;              //保存当前状态的按键值状态
            }
            PMenu = PMenu->ParentMenus;
            LCDClrWin(0,0,127,7);                               //清全屏
            g_UserChoose = PMenu->MenuState;                    //恢复下一个界面的按键值
            s_olderchoose = 0;                                  //翻页设置老按键值为0
            flag1 = 0;                                          //为初次显示初始化标志1
            flag2 = 0;                                          //为初次显示初始化标志2
            flag3 = 0;                                          //为初次显示初始化标志3
            flag4 = 0;                                          //为初次显示初始化标志4
            flag5 = 0;                                          //为初次显示初始化标志5
        }
    }
    ShowMenu();
}