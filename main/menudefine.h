/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			menudefine.h
 *Description：     	        菜单界面定义
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __MENUDEFINE_H__
#define __MENUDEFINE_H__




/*********************************定义各菜单句柄ID号***************************/

enum MenuID
{
    mainmenu = 1,                            //主菜单
    
    /*设置菜单全部ID*/
    setmenu,                                 
    timemenu,
    communicationmenu,
    heatmenu,
    
    /*采样菜单全部ID*/
    samplingmenu,
    presetmenu,
    timingmenu,
    immediatelymenu,
    
    /*查询菜单全部ID*/
    seekmenu,
    
    /*维护菜单全部ID*/
    maintainmenu,
    voltagemenu,
    temperaturepressuremenu,
    versionsmenu,
};

/*********************************定义界面结构体*******************************/

struct MenuItem 
{ 	
    enum MenuID ID;                         //定义当前界面ID号    
    uint8_t MenuCount;                        //定义当前功能的个数
    uint8_t MenuState;                        //记录当前的页面状态
    struct MenuItem *ChildrenMenus;         //定义当前界面的子菜单
    struct MenuItem *ParentMenus;           //定义当前界面的父菜单
    void (*Subs)();                         //定义当前界面子功能进去后的界面函数或实现的功能
}; 

/*********************************界面数组定义*********************************/

//主菜单参数设置	
extern struct MenuItem MainMenu[4];	           

/***********************设置参数设置***********************/
//参数设置
extern struct MenuItem SetMenu[4];

//参数设置子项--时间设置
extern struct MenuItem TimeMenu[2];

//参数设置子项--通讯设置
extern struct MenuItem CommunicationMenu[4]; 

//参数设置子项--加热设置
extern struct MenuItem HeatMenu[4]; 


/***********************采样参数设置***********************/
//采样
extern struct MenuItem SamplingMenu[3];            //采样菜单参数设置	

//采样设置子项--预调流量
extern struct MenuItem PresetMenu[3];

//采样设置子项--定时采样
extern struct MenuItem TimingMenu[5];

//采样设置子项--立即采样
extern struct MenuItem ImmediatelyMenu[3];


/***********************查询参数设置***********************/
//查询
extern struct MenuItem SeekMenu[5];	            //查询菜单参数设置	

/***********************维护参数设置***********************/
//维护
extern struct MenuItem MaintainMenu[3];            //维护参数设置
//维护子项--电压信息
extern struct MenuItem VoltageMenu[4];
//维护子项--温度气压
extern struct MenuItem TemperaturePressureMenu[4];
//维护子项--版本信息
extern struct MenuItem VersionsMenu[1];



/*********************************函数部分*************************************/
//界面菜单初始化
extern void MenuInit(void);
extern void NullFuntion(void);
#endif