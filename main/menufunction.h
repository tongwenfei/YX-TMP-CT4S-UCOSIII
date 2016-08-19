/*******************************************************************************
 *CopyRight Reserved:	
 *Filename：			mainmenu.h
 *Description：     	       主界面设计
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __MAINMENU_H__
#define __MAINMENU_H__



/*********************************函数部分*************************************/

/************************* 其他 函数定义***********************/
//电池显示
extern void Display_Batter(uint8_t flag);
//电源显示
extern void Display_Power(uint8_t flag);


/************************* 主界面 函数定义***********************/
extern void Display_MainMenu(void);
extern void Display_TimeValue(void);


/*********************** 设置界面 函数定义***********************/
extern void Display_SetMenu1(void);

//设置界面1子菜单-时间设置
extern void Display_SetMenu1_SubSetTime(void);
//设置界面1子菜单-时间设置(年月日设置)
extern void Display_SetMenu1_SubSetTime_YMD(void);
//设置界面1子菜单-时间设置(时分秒设置)
extern void Display_SetMenu1_SubSetTime_HMS(void);

//设置界面1子菜单-通讯设置
extern void Display_SetMenu1_SubSetCommunication1(void);
//设置界面1子菜单-通讯设置(波特率设置)
extern void Display_SetMenu1_SubSetCommunication1_BAUD(void);
//设置界面1子菜单-通讯设置(数据位设置)
extern void Display_SetMenu1_SubSetCommunication1_DATABITS(void);
//设置界面1子菜单-通讯设置(校验位设置)
extern void Display_SetMenu1_SubSetCommunication1_PARITYBIT(void);
//设置界面1子菜单-通讯设置(停止位设置)
extern void Display_SetMenu1_SubSetCommunication1_STOPBIT(void);

//设置界面1子菜单-加热控制
extern void Display_SetMenu1_SubSetHeat(void); 
//设置界面1子菜单-加热控制(开关控制)
extern void Display_SetMenu1_SubSetHeat_HEATCONT(void);
//设置界面1子菜单-加热控制(温度设置)
extern void Display_SetMenu1_SubSetHeat_HEAT_TEMP(void);
//设置是否恢复出厂设置和已恢复出厂设置
extern void Display_SetMenu2_SubSetDefault(void);


/********************** 采样界面 函数定义************************/

extern void Display_SamplingMenu(void);

//采样子界面 预调流量定义
extern void Display_SamplingMenu_SubPreset(void);
//采样子界面 预调流量定义(流量A设置)
extern void Display_SamplingMenu_SubPreset_SAMPLING_A(void);
//采样子界面 预调流量定义(流量B设置)
extern void Display_SamplingMenu_SubPreset_SAMPLING_B(void);
//采样子界面 预调流量定义(流量启动)
extern void Display_SamplingMenu_SubPreset_FLOW_START(void);

//采样子界面 定时采样定义
extern void Display_SamplingMenu_SubTiming1(void);
//采样子界面 定时采样定义(通道A起始时间设置)
extern void Display_SamplingMenu_SubTiming1_START_A(void);
//采样子界面 定时采样定义(通道B起始时间设置)
extern void Display_SamplingMenu_SubTiming1_START_B(void);
//采样子界面 定时采样定义(通道A采集时间设置)
extern void Display_SamplingMenu_SubTiming1_SAMPLING_A(void);
//采样子界面 定时采样定义(通道B采集时间设置)
extern void Display_SamplingMenu_SubTiming1_SAMPLING_B(void);
//采样子界面 定时采样的启动子界面 (等待采样)
extern void Display_SamplingMenu_SubTiming_SubWait(void);

//定时采样界面（采样进行中。。。）
extern void Display_SamplingMenu_SubTiming_SubWait_SubUnderWay(void);
//立即采样界面（采样进行中。。。）
extern void Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay(void);

//采样子界面 采样继续的子界面 
extern void Display_SamplingMenu_SubContinue(void);

//采样子界面 立即采样的子界面 
extern void Display_SamplingMenu_SubImmediately(void);
//采样子界面 立即采样的子界面 (采集时间设置)
extern void Display_SamplingMenu_SubImmediately_IMMEDIATELY_A(void);
//采样子界面 立即采样的子界面 (采集时间设置)
extern void Display_SamplingMenu_SubImmediately_IMMEDIATELY_B(void);



/********************** 查询界面 函数定义************************/
extern void Display_SeekMenu1(void);
//查询界面（文件编号设置）
extern void Display_SeekMenu1_FILE_NUMBER(void);
//查询界面（文件上翻）
extern void Display_SeekMenu1_UPTURN(void);
//查询界面（文件下翻）
extern void Display_SeekMenu1_DOWNTURN(void);

//查询界面子菜单-文件详细
extern void Display_SeekMenu2_SubFile1(void);
//查询界面子菜单-文件清零
extern void Display_SeekMenu2_SubFileClear(void);

/********************** 维护界面 函数定义************************/
extern void Display_MaintainMenu(void);

//维护界面子菜单-电压信息
extern void Display_MaintainMenu_SubDisplayVoltage1(void);
//维护界面子菜单-温度气压
extern void Display_MaintainMenu_SubDisplayTemperaturePressure1(void);
//维护界面子菜单-版本信息
extern void Display_MaintainMenu_SubDisplayVersions(void);

#endif