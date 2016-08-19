/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			menudefine.c
 *Description：     	        菜单界面定义
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/*********************************界面数组定义*********************************/

//主菜单参数设置	
struct MenuItem MainMenu[4];	           

/***********************设置参数设置***********************/
//参数设置
struct MenuItem SetMenu[4];

//参数设置子项--时间设置
struct MenuItem TimeMenu[2];

//参数设置子项--通讯设置
struct MenuItem CommunicationMenu[4]; 

//参数设置子项--加热设置
struct MenuItem HeatMenu[4]; 


/***********************采样参数设置***********************/
//采样
struct MenuItem SamplingMenu[3];            //采样菜单参数设置	

//采样设置子项--预调流量
struct MenuItem PresetMenu[3];

//采样设置子项--定时采样
struct MenuItem TimingMenu[5];

//采样设置子项--立即采样
struct MenuItem ImmediatelyMenu[3];


/***********************查询参数设置***********************/
//查询
struct MenuItem SeekMenu[5];	            //查询菜单参数设置	
//查询子菜单--文件详细
struct MenuItem FileMenu[15];

/***********************维护参数设置***********************/
//维护
struct MenuItem MaintainMenu[3];            //维护参数设置
//维护子项--电压信息
struct MenuItem VoltageMenu[4];
//维护子项--温度气压
struct MenuItem TemperaturePressureMenu[4];
//维护子项--版本信息
struct MenuItem VersionsMenu[1];



/******************************* 主界面 函数定义*******************************/


/*
********************************************************************************
函数名称：void NullFuntion(void)
函数功能：无功能
入口参数：无
出口参数：无
********************************************************************************
*/
void NullFuntion(void)
{
}

/*
********************************************************************************
函数名称：void MainMenuInit(void)
函数功能：主菜单初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void MainMenuInit(void)
{
    //设置
    MainMenu[0].ID=mainmenu;                              //当前菜单ID号
    MainMenu[0].MenuCount=4;                              //菜单计数4
    MainMenu[0].MenuState=0;                              //无状态
    MainMenu[0].ChildrenMenus=SetMenu;                    //子菜单设置参数
    MainMenu[0].ParentMenus=0;                            //父菜单为0
    MainMenu[0].Subs=NullFuntion;                         //无函数
    
    //采样
    MainMenu[1].ID=mainmenu;                              //当前菜单ID号
    MainMenu[1].MenuCount=4;                              //菜单计数4
    MainMenu[1].MenuState=0;                              //无状态
    MainMenu[1].ChildrenMenus=SamplingMenu;               //子菜单设置参数    
    MainMenu[1].ParentMenus=0;                            //父菜单为0
    MainMenu[1].Subs=NullFuntion;                         //无函数
    
    //查询
    MainMenu[2].ID=mainmenu;                              //当前菜单ID号
    MainMenu[2].MenuCount=4;                              //菜单计数4
    MainMenu[2].MenuState=0;                              //无状态
    MainMenu[2].ChildrenMenus=SeekMenu;                   //子菜单查询参数 
    MainMenu[2].ParentMenus=0;                            //父菜单为0
    MainMenu[2].Subs=NullFuntion;                         //无函数
    
    //维护
    MainMenu[3].ID=mainmenu;                              //当前菜单ID号
    MainMenu[3].MenuCount=4;                              //菜单计数4
    MainMenu[3].MenuState=0;                              //无状态
    MainMenu[3].ChildrenMenus=MaintainMenu;               //子菜单维护参数 
    MainMenu[3].ParentMenus=0;                            //父菜单为0
    MainMenu[3].Subs=NullFuntion;                         //无函数
}


/*****************************************************设置菜单全部参数定义**********************************************************/

/*
********************************************************************************
函数名称：void SetMenuInit(void)
函数功能：设置菜单初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void SetMenuInit(void)
{
    //时间设置
    SetMenu[0].ID=setmenu;                               //设置菜单ID号
    SetMenu[0].MenuCount=4;                              //菜单计数6
    SetMenu[0].MenuState=0;                              //无状态
    SetMenu[0].ChildrenMenus=TimeMenu;                   //时间菜单设置参数
    SetMenu[0].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SetMenu[0].Subs=NullFuntion;                         //无函数
    
    //通讯设置
    SetMenu[1].ID=setmenu;                               //设置菜单ID号
    SetMenu[1].MenuCount=4;                              //菜单计数6
    SetMenu[1].MenuState=0;                              //无状态
    SetMenu[1].ChildrenMenus=CommunicationMenu;          //通讯设置参数
    SetMenu[1].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SetMenu[1].Subs=NullFuntion;                         //无函数
    
    //加热设置
    SetMenu[2].ID=setmenu;                               //设置菜单ID号
    SetMenu[2].MenuCount=4;                              //菜单计数6
    SetMenu[2].MenuState=0;                              //无状态
    SetMenu[2].ChildrenMenus=HeatMenu;                   //加热菜单设置参数
    SetMenu[2].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SetMenu[2].Subs=NullFuntion;                         //无函数
    
     //恢复出厂设置
    SetMenu[3].ID=setmenu;                               //设置菜单ID号
    SetMenu[3].MenuCount=4;                              //菜单计数6
    SetMenu[3].MenuState=0;                              //无状态
    SetMenu[3].ChildrenMenus=0;                          //0
    SetMenu[3].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SetMenu[3].Subs=Display_SetMenu2_SubSetDefault;      //无函数
}

/*
********************************************************************************
函数名称：void TimeMenuInit(void)
函数功能：时间设置初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void TimeMenuInit(void)
{
    //日期
    TimeMenu[0].ID=timemenu;                              //时间设置ID号
    TimeMenu[0].MenuCount=2;                              //菜单计数2
    TimeMenu[0].MenuState=0;                              //无状态
    TimeMenu[0].ChildrenMenus=0;                          //0
    TimeMenu[0].ParentMenus=SetMenu;                      //父菜单为setmenu
    TimeMenu[0].Subs=Display_SetMenu1_SubSetTime_YMD;     //子菜单函数时间设置
    
    //时间
    TimeMenu[1].ID=timemenu;                              //时间设置ID号
    TimeMenu[1].MenuCount=2;                              //菜单计数2
    TimeMenu[1].MenuState=0;                              //无状态
    TimeMenu[1].ChildrenMenus=0;                          //0
    TimeMenu[1].ParentMenus=SetMenu;                      //父菜单为setmenu
    TimeMenu[1].Subs=Display_SetMenu1_SubSetTime_HMS;     //子菜单函数时间设置
}

/*
********************************************************************************
函数名称：void CommunicationMenuInit(void)
函数功能：通讯设置初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void CommunicationMenuInit(void)
{
    //波特率
    CommunicationMenu[0].ID=communicationmenu;                     //设置菜单ID号
    CommunicationMenu[0].MenuCount=4;                              //菜单计数4
    CommunicationMenu[0].MenuState=0;                              //无状态
    CommunicationMenu[0].ChildrenMenus=0;                          //0
    CommunicationMenu[0].ParentMenus=SetMenu;                      //父菜单为SetMenu
    CommunicationMenu[0].Subs=Display_SetMenu1_SubSetCommunication1_BAUD;//子菜单函数波特率设置
    
    //数据位
    CommunicationMenu[1].ID=communicationmenu;                     //设置菜单ID号
    CommunicationMenu[1].MenuCount=4;                              //菜单计数4
    CommunicationMenu[1].MenuState=0;                              //无状态
    CommunicationMenu[1].ChildrenMenus=0;                          //0
    CommunicationMenu[1].ParentMenus=SetMenu;                      //父菜单为SetMenu
    CommunicationMenu[1].Subs=Display_SetMenu1_SubSetCommunication1_DATABITS;//子菜单函数数据位设置
    
    //校验位
    CommunicationMenu[2].ID=communicationmenu;                     //设置菜单ID号
    CommunicationMenu[2].MenuCount=4;                              //菜单计数6
    CommunicationMenu[2].MenuState=0;                              //无状态
    CommunicationMenu[2].ChildrenMenus=0;                          //0
    CommunicationMenu[2].ParentMenus=SetMenu;                      //父菜单为SetMenu
    CommunicationMenu[2].Subs=Display_SetMenu1_SubSetCommunication1_PARITYBIT;//子菜单函数校验位设置
    
    //停止位
    CommunicationMenu[3].ID=communicationmenu;                     //设置菜单ID号
    CommunicationMenu[3].MenuCount=4;                              //菜单计数6
    CommunicationMenu[3].MenuState=0;                              //无状态
    CommunicationMenu[3].ChildrenMenus=0;                          //0
    CommunicationMenu[3].ParentMenus=SetMenu;                      //父菜单为SetMenu
    CommunicationMenu[3].Subs=Display_SetMenu1_SubSetCommunication1_STOPBIT;//子菜单函数停止位设置
}

/*
********************************************************************************
函数名称：void HeatMenuInit(void)
函数功能：加热设置初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void HeatMenuInit(void)
{
    //加热控制
    HeatMenu[0].ID=heatmenu;                              //加热菜单ID号
    HeatMenu[0].MenuCount=4;                              //菜单计数4
    HeatMenu[0].MenuState=0;                              //无状态
    HeatMenu[0].ChildrenMenus=0;                          //0
    HeatMenu[0].ParentMenus=SetMenu;                      //父菜单为SetMenu
    HeatMenu[0].Subs=Display_SetMenu1_SubSetHeat_HEATCONT;//子菜单函数设置
    
    //温度设置
    HeatMenu[1].ID=heatmenu;                              //加热菜单ID号
    HeatMenu[1].MenuCount=4;                              //菜单计数4
    HeatMenu[1].MenuState=0;                              //无状态
    HeatMenu[1].ChildrenMenus=0;                          //0
    HeatMenu[1].ParentMenus=SetMenu;                      //父菜单为SetMenu
    HeatMenu[1].Subs=Display_SetMenu1_SubSetHeat_HEAT_TEMP;//子菜单函数设置
    
    //加热区
    HeatMenu[2].ID=heatmenu;                              //加热菜单ID号
    HeatMenu[2].MenuCount=4;                              //菜单计数4
    HeatMenu[2].MenuState=0;                              //无状态
    HeatMenu[2].ChildrenMenus=0;                          //0
    HeatMenu[2].ParentMenus=SetMenu;                      //父菜单为SetMenu
    HeatMenu[2].Subs=NullFuntion;                         //子菜单函数设置
    
    //加热功率
    HeatMenu[3].ID=heatmenu;                              //加热菜单ID号
    HeatMenu[3].MenuCount=4;                              //菜单计数4
    HeatMenu[3].MenuState=0;                              //无状态
    HeatMenu[3].ChildrenMenus=0;                          //0
    HeatMenu[3].ParentMenus=SetMenu;                      //父菜单为SetMenu
    HeatMenu[3].Subs=NullFuntion;                         //子菜单函数设置
}


/*****************************************************采样菜单全部参数定义**********************************************************/

/*
********************************************************************************
函数名称：void SamplingMenuInit(void)
函数功能：采样菜单初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void SamplingMenuInit(void)
{
    //预调流量
    SamplingMenu[0].ID=samplingmenu;                          //采样菜单ID号
    SamplingMenu[0].MenuCount=3;                              //菜单计数3
    SamplingMenu[0].MenuState=0;                              //无状态
    SamplingMenu[0].ChildrenMenus=PresetMenu;                 //预调流量参数
    SamplingMenu[0].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SamplingMenu[0].Subs=NullFuntion;                         //子菜单函数设置
    
    //定时采样
    SamplingMenu[1].ID=samplingmenu;                          //采样菜单ID号
    SamplingMenu[1].MenuCount=3;                              //菜单计数3
    SamplingMenu[1].MenuState=0;                              //无状态
    SamplingMenu[1].ChildrenMenus=TimingMenu;                 //定时参数设置
    SamplingMenu[1].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SamplingMenu[1].Subs=NullFuntion;                         //子菜单函数设置
    
    //立即采样
    SamplingMenu[2].ID=samplingmenu;                          //采样菜单ID号
    SamplingMenu[2].MenuCount=3;                              //菜单计数3
    SamplingMenu[2].MenuState=0;                              //无状态
    SamplingMenu[2].ChildrenMenus=ImmediatelyMenu;            //立即采样参数设置
    SamplingMenu[2].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SamplingMenu[2].Subs=NullFuntion;                         //子菜单函数设置
}

/*
********************************************************************************
函数名称：void PresetMenuInit(void)
函数功能：预调流量初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void PresetMenuInit(void)
{
    //流量A值设置
    PresetMenu[0].ID=presetmenu;                            //采样菜单ID号
    PresetMenu[0].MenuCount=3;                              //菜单计数3
    PresetMenu[0].MenuState=0;                              //无状态
    PresetMenu[0].ChildrenMenus=0;                          //预调流量参数
    PresetMenu[0].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    PresetMenu[0].Subs=Display_SamplingMenu_SubPreset_SAMPLING_A;//子菜单函数设置
    
    //流量B值设置
    PresetMenu[1].ID=presetmenu;                            //采样菜单ID号
    PresetMenu[1].MenuCount=3;                              //菜单计数2
    PresetMenu[1].MenuState=0;                              //无状态
    PresetMenu[1].ChildrenMenus=0;                          //定时参数设置
    PresetMenu[1].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    PresetMenu[1].Subs=Display_SamplingMenu_SubPreset_SAMPLING_B;//子菜单函数设置  
    
    //启动调节
    PresetMenu[2].ID=presetmenu;                            //采样菜单ID号
    PresetMenu[2].MenuCount=3;                              //菜单计数3
    PresetMenu[2].MenuState=0;                              //无状态
    PresetMenu[2].ChildrenMenus=0;                          //定时参数设置
    PresetMenu[2].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    PresetMenu[2].Subs=Display_SamplingMenu_SubPreset_FLOW_START;//子菜单函数设置  
}

/*
********************************************************************************
函数名称：void TimingMenuInit(void)
函数功能：定时采样初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void TimingMenuInit(void)
{    
    //起始A
    TimingMenu[0].ID=timingmenu;                            //定时采样ID号
    TimingMenu[0].MenuCount=5;                              //菜单计数3
    TimingMenu[0].MenuState=0;                              //无状态
    TimingMenu[0].ChildrenMenus=0;                          //定时参数设置
    TimingMenu[0].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    TimingMenu[0].Subs=Display_SamplingMenu_SubTiming1_START_A;//子菜单函数设置  
    
    //起始B
    TimingMenu[1].ID=timingmenu;                            //定时采样ID号
    TimingMenu[1].MenuCount=5;                              //菜单计数3
    TimingMenu[1].MenuState=0;                              //无状态
    TimingMenu[1].ChildrenMenus=0;                          //定时参数设置
    TimingMenu[1].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    TimingMenu[1].Subs=Display_SamplingMenu_SubTiming1_START_B;//子菜单函数设置  
    
    //采时A
    TimingMenu[2].ID=timingmenu;                            //定时采样ID号
    TimingMenu[2].MenuCount=5;                              //菜单计数3
    TimingMenu[2].MenuState=0;                              //无状态
    TimingMenu[2].ChildrenMenus=0;                          //定时参数设置
    TimingMenu[2].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    TimingMenu[2].Subs=Display_SamplingMenu_SubTiming1_SAMPLING_A;//子菜单函数设置  
    
    //采时B
    TimingMenu[3].ID=timingmenu;                            //定时采样ID号
    TimingMenu[3].MenuCount=5;                              //菜单计数3
    TimingMenu[3].MenuState=0;                              //无状态
    TimingMenu[3].ChildrenMenus=0;                          //定时参数设置
    TimingMenu[3].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    TimingMenu[3].Subs=Display_SamplingMenu_SubTiming1_SAMPLING_B;//子菜单函数设置  
    
    //启动采样
    TimingMenu[4].ID=timingmenu;                            //定时采样ID号
    TimingMenu[4].MenuCount=5;                              //菜单计数3
    TimingMenu[4].MenuState=0;                              //无状态
    TimingMenu[4].ChildrenMenus=0;                          //采样中参数设置
    TimingMenu[4].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    TimingMenu[4].Subs=Display_SamplingMenu_SubTiming_SubWait; //等待采样函数
}

/*
********************************************************************************
函数名称：void ImmediatelyMenuInit(void)
函数功能：立即采样初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void ImmediatelyMenuInit(void)
{ 
    //采时A
    ImmediatelyMenu[0].ID=immediatelymenu;                       //立即采样ID号
    ImmediatelyMenu[0].MenuCount=3;                              //菜单计数3
    ImmediatelyMenu[0].MenuState=0;                              //无状态
    ImmediatelyMenu[0].ChildrenMenus=0;                          //0
    ImmediatelyMenu[0].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    ImmediatelyMenu[0].Subs=Display_SamplingMenu_SubImmediately_IMMEDIATELY_A;//子菜单函数设置  
    
    //采时B
    ImmediatelyMenu[1].ID=immediatelymenu;                       //立即采样ID号
    ImmediatelyMenu[1].MenuCount=3;                              //菜单计数3
    ImmediatelyMenu[1].MenuState=0;                              //无状态
    ImmediatelyMenu[1].ChildrenMenus=0;                          //0
    ImmediatelyMenu[1].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    ImmediatelyMenu[1].Subs=Display_SamplingMenu_SubImmediately_IMMEDIATELY_B;//子菜单函数设置  
    
    //启动采样
    ImmediatelyMenu[2].ID=immediatelymenu;                       //立即采样ID号
    ImmediatelyMenu[2].MenuCount=3;                              //菜单计数3
    ImmediatelyMenu[2].MenuState=0;                              //无状态
    ImmediatelyMenu[2].ChildrenMenus=0;                          //0
    ImmediatelyMenu[2].ParentMenus=SamplingMenu;                 //父菜单为SamplingMenu
    ImmediatelyMenu[2].Subs=Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay;//子菜单函数设置 
}

/*****************************************************查询菜单全部参数定义**********************************************************/

/*
********************************************************************************
函数名称：void SeekMenuInit(void)
函数功能：查询菜单初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void SeekMenuInit(void)
{
    //文件号
    SeekMenu[0].ID=seekmenu;                              //查询ID号
    SeekMenu[0].MenuCount=5;                              //菜单计数5
    SeekMenu[0].MenuState=0;                              //无状态
    SeekMenu[0].ChildrenMenus=0;                          //0
    SeekMenu[0].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SeekMenu[0].Subs=Display_SeekMenu1_FILE_NUMBER;       //子菜单函数设置
    
    //文件上翻
    SeekMenu[1].ID=seekmenu;                              //查询ID号
    SeekMenu[1].MenuCount=5;                              //菜单计数5
    SeekMenu[1].MenuState=0;                              //无状态
    SeekMenu[1].ChildrenMenus=0;                          //0
    SeekMenu[1].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SeekMenu[1].Subs=Display_SeekMenu1_UPTURN;            //子菜单函数设置  
    
    //文件下翻
    SeekMenu[2].ID=seekmenu;                              //查询ID号
    SeekMenu[2].MenuCount=5;                              //菜单计数5
    SeekMenu[2].MenuState=0;                              //无状态
    SeekMenu[2].ChildrenMenus=0;                          //0
    SeekMenu[2].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SeekMenu[2].Subs=Display_SeekMenu1_DOWNTURN;          //子菜单函数设置 
    
    //文件详细
    SeekMenu[3].ID=seekmenu;                              //查询ID号
    SeekMenu[3].MenuCount=5;                              //菜单计数5
    SeekMenu[3].MenuState=0;                              //无状态
    SeekMenu[3].ChildrenMenus=0;                          //文件详细
    SeekMenu[3].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SeekMenu[3].Subs=Display_SeekMenu2_SubFile1;          //子菜单文件详细函数设置  
    
    //文件清零
    SeekMenu[4].ID=seekmenu;                              //查询ID号
    SeekMenu[4].MenuCount=5;                              //菜单计数5
    SeekMenu[4].MenuState=0;                              //无状态
    SeekMenu[4].ChildrenMenus=0;                          //为0
    SeekMenu[4].ParentMenus=MainMenu;                     //父菜单为MainMenu
    SeekMenu[4].Subs=Display_SeekMenu2_SubFileClear;      //子菜单文件详细函数设置  

}

/*****************************************************维护菜单全部参数定义**********************************************************/

/*
********************************************************************************
函数名称：void MaintainMenuInit(void)
函数功能：维护菜单初始化
入口参数：无
出口参数：无
********************************************************************************
*/
void MaintainMenuInit(void)
{
    //电压信息
    MaintainMenu[0].ID=maintainmenu;                          //维护ID号
    MaintainMenu[0].MenuCount=3;                              //菜单计数3
    MaintainMenu[0].MenuState=0;                              //无状态
    MaintainMenu[0].ChildrenMenus=VoltageMenu;                //电压信息
    MaintainMenu[0].ParentMenus=MainMenu;                     //父菜单为MainMenu
    MaintainMenu[0].Subs=NullFuntion;                         //子菜单函数设置
    
    //温度气压
    MaintainMenu[1].ID=maintainmenu;                          //维护ID号
    MaintainMenu[1].MenuCount=3;                              //菜单计数3
    MaintainMenu[1].MenuState=0;                              //无状态
    MaintainMenu[1].ChildrenMenus=TemperaturePressureMenu;    //温度气压
    MaintainMenu[1].ParentMenus=MainMenu;                     //父菜单为MainMenu
    MaintainMenu[1].Subs=NullFuntion;                         //子菜单函数设置  
    
    //版本信息
    MaintainMenu[2].ID=maintainmenu;                          //维护ID号
    MaintainMenu[2].MenuCount=3;                              //菜单计数3
    MaintainMenu[2].MenuState=0;                              //无状态
    MaintainMenu[2].ChildrenMenus=VersionsMenu;               //0
    MaintainMenu[2].ParentMenus=MainMenu;                     //父菜单为MainMenu
    MaintainMenu[2].Subs=NullFuntion;                         //子菜单函数设置 
}

/*
********************************************************************************
函数名称：void VoltageMenuInit(void)
函数功能：维护菜单子项--电压信息
入口参数：无
出口参数：无
********************************************************************************
*/
void VoltageMenuInit(void)
{
    //开关电压
    VoltageMenu[0].ID=voltagemenu;                           //电压信息ID号
    VoltageMenu[0].MenuCount=4;                              //菜单计数4
    VoltageMenu[0].MenuState=0;                              //无状态
    VoltageMenu[0].ChildrenMenus=0;                          //0
    VoltageMenu[0].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    VoltageMenu[0].Subs=NullFuntion;                         //子菜单函数设置
    
    //电池电压
    VoltageMenu[1].ID=voltagemenu;                           //电压信息ID号
    VoltageMenu[1].MenuCount=4;                              //菜单计数4
    VoltageMenu[1].MenuState=0;                              //无状态
    VoltageMenu[1].ChildrenMenus=0;                          //0
    VoltageMenu[1].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    VoltageMenu[1].Subs=NullFuntion;                         //子菜单函数设置  
    
    //泵A电压
    VoltageMenu[2].ID=voltagemenu;                           //电压信息ID号
    VoltageMenu[2].MenuCount=4;                              //菜单计数4
    VoltageMenu[2].MenuState=0;                              //无状态
    VoltageMenu[2].ChildrenMenus=0;                          //0
    VoltageMenu[2].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    VoltageMenu[2].Subs=NullFuntion;                         //子菜单函数设置 
    
    //泵B电压
    VoltageMenu[3].ID=voltagemenu;                           //电压信息ID号
    VoltageMenu[3].MenuCount=4;                              //菜单计数4
    VoltageMenu[3].MenuState=0;                              //无状态
    VoltageMenu[3].ChildrenMenus=0;                          //0
    VoltageMenu[3].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    VoltageMenu[3].Subs=NullFuntion;                         //子菜单函数设置 
}

/*
********************************************************************************
函数名称：void TemperaturePressureMenuInit(void)
函数功能：维护菜单子项--温度气压
入口参数：无
出口参数：无
********************************************************************************
*/
void TemperaturePressureMenuInit(void)
{
    //加热区
    TemperaturePressureMenu[0].ID=temperaturepressuremenu;               //温度气压ID号
    TemperaturePressureMenu[0].MenuCount=4;                              //菜单计数4
    TemperaturePressureMenu[0].MenuState=0;                              //无状态
    TemperaturePressureMenu[0].ChildrenMenus=0;                          //电压信息
    TemperaturePressureMenu[0].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    TemperaturePressureMenu[0].Subs=NullFuntion;                         //子菜单函数设置
    
    //通道A
    TemperaturePressureMenu[1].ID=temperaturepressuremenu;               //温度气压ID号
    TemperaturePressureMenu[1].MenuCount=4;                              //菜单计数4
    TemperaturePressureMenu[1].MenuState=0;                              //无状态
    TemperaturePressureMenu[1].ChildrenMenus=0;                          //0
    TemperaturePressureMenu[1].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    TemperaturePressureMenu[1].Subs=NullFuntion;                         //子菜单函数设置  
    
    //通道B
    TemperaturePressureMenu[2].ID=temperaturepressuremenu;               //温度气压ID号
    TemperaturePressureMenu[2].MenuCount=4;                              //菜单计数4
    TemperaturePressureMenu[2].MenuState=0;                              //无状态
    TemperaturePressureMenu[2].ChildrenMenus=0;                          //0
    TemperaturePressureMenu[2].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    TemperaturePressureMenu[2].Subs=NullFuntion;                         //子菜单函数设置 
    
    //气压
    TemperaturePressureMenu[3].ID=temperaturepressuremenu;               //温度气压ID号
    TemperaturePressureMenu[3].MenuCount=4;                              //菜单计数4
    TemperaturePressureMenu[3].MenuState=0;                              //无状态
    TemperaturePressureMenu[3].ChildrenMenus=0;                          //0
    TemperaturePressureMenu[3].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    TemperaturePressureMenu[3].Subs=NullFuntion;                         //子菜单函数设置 
}

/*
********************************************************************************
函数名称：void VersionsMenuInit(void)
函数功能：维护菜单子项--版本信息
入口参数：无
出口参数：无
********************************************************************************
*/
void VersionsMenuInit(void)
{
    VersionsMenu[0].ID=versionsmenu;                          //温度气压ID号
    VersionsMenu[0].MenuCount=0;                              //菜单计数4
    VersionsMenu[0].MenuState=0;                              //无状态
    VersionsMenu[0].ChildrenMenus=0;                          //电压信息
    VersionsMenu[0].ParentMenus=MaintainMenu;                 //父菜单为MaintainMenu
    VersionsMenu[0].Subs=NullFuntion;                         //子菜单函数设置
}

/*
********************************************************************************
函数名称：void MenuInit(void)
函数功能：初始化界面菜单
入口参数：无
出口参数：无
********************************************************************************
*/
void MenuInit(void)
{
    //主菜单初始化
    MainMenuInit();
/***********************设置参数函数定义***********************/
    //设置界面初始化
    SetMenuInit();
    //设置界面子项--时间设置
    TimeMenuInit();
    //设置界面子项--通讯设置
    CommunicationMenuInit();
    //设置界面子项--加热设置
    HeatMenuInit();
/***********************设置参数函数定义***********************/
    //采样初始化
    SamplingMenuInit();
    //采样界面子项--预调流量
    PresetMenuInit();
    //采样界面子项--定时采样
    TimingMenuInit();
    //采样界面子项--立即采样
    ImmediatelyMenuInit();
/***********************查询参数函数定义***********************/
    //查询初始化
    SeekMenuInit();
/***********************维护参数函数定义***********************/
    //维护初始化
    MaintainMenuInit();
    //维护子项--电压显示
    VoltageMenuInit();
    //维护子项--温度气压
    TemperaturePressureMenuInit();
    //维护子项--版本信息
    VersionsMenuInit();
}