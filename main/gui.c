/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			gui.c
 *Description��     	      ���������ʵ�ֽ���Ͱ����Ľ�� 
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/************************************ �������� ********************************/

/*
********************************************************************************
�������ƣ�void ShowMenu(void)
�������ܣ�������ʾ����
��ڲ�������
���ڲ�������
********************************************************************************
*/
void ShowMenu(void)
{	
    //�жϵ���Ƿ��е���Ƿ�ӵ�Դ
    if((g_Power.pc0_adc10_battery > 11) || (Power_flag == 1))
    { 
        if(FM24C64_READ_BYTE(UNFINISHED_FLAG) != 0)     //����Ƿ���δ��ɵĲ���    
        { 
            Display_SamplingMenu_SubContinue();         //������������
        }
    }
    switch (PMenu->ID)
    {    
        case mainmenu:
            Display_MainMenu();
            break;
            
        /************************���ò���*************************/
        case setmenu:
            Display_SetMenu1();
            break;
            
        /***************���ò���--�ӹ���****************/    
        case timemenu:
            Display_SetMenu1_SubSetTime();
            break;
            
        case communicationmenu:
            Display_SetMenu1_SubSetCommunication1();
            break;
            
        case heatmenu:
            Display_SetMenu1_SubSetHeat();
            break;         
            
            
        /************************��������*************************/
        case samplingmenu:
            Display_SamplingMenu();
            break;
            
        /***************��������--�ӹ���****************/    
        case presetmenu:
            Display_SamplingMenu_SubPreset();
            break;
            
        case timingmenu:
            Display_SamplingMenu_SubTiming1();
            break;
            
        case immediatelymenu:
            Display_SamplingMenu_SubImmediately();
            break;
            
            
       /************************��ѯ����*************************/
        case seekmenu:
            Display_SeekMenu1();
            break;
            
            
        /************************ά������*************************/
        case maintainmenu:
            Display_MaintainMenu();
            break;
            
        /***************ά������--�ӹ���****************/    
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
    //��ʾ���
    Display_Batter(Power_flag);
    //��ʾ��Դ
    Display_Power(Power_flag);
}

/*
********************************************************************************
�������ƣ�void GUI_Init(void)
�������ܣ����г�ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void GUI_Init(void)
{
    g_UserChoose = 0;
    PMenu=MainMenu;                             //��������ʾ
    MenuInit();                                 //��ʼ�����涨��
    Display_MainMenu();                         //��ʾ������
}

/*
********************************************************************************
�������ƣ�void KEY_GUI_Scan(uint8_t key)
�������ܣ�ʵ�ְ���ֵɨ��
��ڲ�������
���ڲ�������
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
                g_UserChoose = PMenu->MenuCount - 1;            //�����ͷ�ڶ��ˣ�������׶�ֵ
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
                g_UserChoose++;                               //�����ͷ�ڶ��ˣ�������׶�ֵ
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
            (*PMenu[g_UserChoose].Subs)();                      //������غ�����
        }
        else if (PMenu[g_UserChoose].ChildrenMenus != NULL)
        {
            for(i = 0; i < PMenu->MenuCount; i++)
            {
                PMenu[i].MenuState = g_UserChoose;              //���浱ǰ״̬�İ���ֵ״̬
            }
            PMenu = PMenu[g_UserChoose].ChildrenMenus;          //����Ӳ˵�
            LCDClrWin(0,0,127,7);                               //��ȫ��
            g_UserChoose = PMenu->MenuState;                    //�ָ���һ������İ���ֵ
            s_olderchoose = 0;                                  //��ҳ�����ϰ���ֵΪ0
            flag1 = 0;                                          //Ϊ������ʾ��ʼ����־1
            flag2 = 0;                                          //Ϊ������ʾ��ʼ����־2
            flag3 = 0;                                          //Ϊ������ʾ��ʼ����־3
            flag4 = 0;                                          //Ϊ������ʾ��ʼ����־4
            flag5 = 0;                                          //Ϊ������ʾ��ʼ����־5
        }  
    }
    else if(key == KEY_CAL)
    {
        if(PMenu->ParentMenus != NULL)
        {
            for(i = 0; i < PMenu->MenuCount; i++)
            {
                PMenu[i].MenuState = g_UserChoose;              //���浱ǰ״̬�İ���ֵ״̬
            }
            PMenu = PMenu->ParentMenus;
            LCDClrWin(0,0,127,7);                               //��ȫ��
            g_UserChoose = PMenu->MenuState;                    //�ָ���һ������İ���ֵ
            s_olderchoose = 0;                                  //��ҳ�����ϰ���ֵΪ0
            flag1 = 0;                                          //Ϊ������ʾ��ʼ����־1
            flag2 = 0;                                          //Ϊ������ʾ��ʼ����־2
            flag3 = 0;                                          //Ϊ������ʾ��ʼ����־3
            flag4 = 0;                                          //Ϊ������ʾ��ʼ����־4
            flag5 = 0;                                          //Ϊ������ʾ��ʼ����־5
        }
    }
    ShowMenu();
}