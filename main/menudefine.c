/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			menudefine.c
 *Description��     	        �˵����涨��
 *Date:
 *Author:		
*******************************************************************************/

#include"include.h"

/*********************************�������鶨��*********************************/

//���˵���������	
struct MenuItem MainMenu[4];	           

/***********************���ò�������***********************/
//��������
struct MenuItem SetMenu[4];

//������������--ʱ������
struct MenuItem TimeMenu[2];

//������������--ͨѶ����
struct MenuItem CommunicationMenu[4]; 

//������������--��������
struct MenuItem HeatMenu[4]; 


/***********************������������***********************/
//����
struct MenuItem SamplingMenu[3];            //�����˵���������	

//������������--Ԥ������
struct MenuItem PresetMenu[3];

//������������--��ʱ����
struct MenuItem TimingMenu[5];

//������������--��������
struct MenuItem ImmediatelyMenu[3];


/***********************��ѯ��������***********************/
//��ѯ
struct MenuItem SeekMenu[5];	            //��ѯ�˵���������	
//��ѯ�Ӳ˵�--�ļ���ϸ
struct MenuItem FileMenu[15];

/***********************ά����������***********************/
//ά��
struct MenuItem MaintainMenu[3];            //ά����������
//ά������--��ѹ��Ϣ
struct MenuItem VoltageMenu[4];
//ά������--�¶���ѹ
struct MenuItem TemperaturePressureMenu[4];
//ά������--�汾��Ϣ
struct MenuItem VersionsMenu[1];



/******************************* ������ ��������*******************************/


/*
********************************************************************************
�������ƣ�void NullFuntion(void)
�������ܣ��޹���
��ڲ�������
���ڲ�������
********************************************************************************
*/
void NullFuntion(void)
{
}

/*
********************************************************************************
�������ƣ�void MainMenuInit(void)
�������ܣ����˵���ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void MainMenuInit(void)
{
    //����
    MainMenu[0].ID=mainmenu;                              //��ǰ�˵�ID��
    MainMenu[0].MenuCount=4;                              //�˵�����4
    MainMenu[0].MenuState=0;                              //��״̬
    MainMenu[0].ChildrenMenus=SetMenu;                    //�Ӳ˵����ò���
    MainMenu[0].ParentMenus=0;                            //���˵�Ϊ0
    MainMenu[0].Subs=NullFuntion;                         //�޺���
    
    //����
    MainMenu[1].ID=mainmenu;                              //��ǰ�˵�ID��
    MainMenu[1].MenuCount=4;                              //�˵�����4
    MainMenu[1].MenuState=0;                              //��״̬
    MainMenu[1].ChildrenMenus=SamplingMenu;               //�Ӳ˵����ò���    
    MainMenu[1].ParentMenus=0;                            //���˵�Ϊ0
    MainMenu[1].Subs=NullFuntion;                         //�޺���
    
    //��ѯ
    MainMenu[2].ID=mainmenu;                              //��ǰ�˵�ID��
    MainMenu[2].MenuCount=4;                              //�˵�����4
    MainMenu[2].MenuState=0;                              //��״̬
    MainMenu[2].ChildrenMenus=SeekMenu;                   //�Ӳ˵���ѯ���� 
    MainMenu[2].ParentMenus=0;                            //���˵�Ϊ0
    MainMenu[2].Subs=NullFuntion;                         //�޺���
    
    //ά��
    MainMenu[3].ID=mainmenu;                              //��ǰ�˵�ID��
    MainMenu[3].MenuCount=4;                              //�˵�����4
    MainMenu[3].MenuState=0;                              //��״̬
    MainMenu[3].ChildrenMenus=MaintainMenu;               //�Ӳ˵�ά������ 
    MainMenu[3].ParentMenus=0;                            //���˵�Ϊ0
    MainMenu[3].Subs=NullFuntion;                         //�޺���
}


/*****************************************************���ò˵�ȫ����������**********************************************************/

/*
********************************************************************************
�������ƣ�void SetMenuInit(void)
�������ܣ����ò˵���ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void SetMenuInit(void)
{
    //ʱ������
    SetMenu[0].ID=setmenu;                               //���ò˵�ID��
    SetMenu[0].MenuCount=4;                              //�˵�����6
    SetMenu[0].MenuState=0;                              //��״̬
    SetMenu[0].ChildrenMenus=TimeMenu;                   //ʱ��˵����ò���
    SetMenu[0].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SetMenu[0].Subs=NullFuntion;                         //�޺���
    
    //ͨѶ����
    SetMenu[1].ID=setmenu;                               //���ò˵�ID��
    SetMenu[1].MenuCount=4;                              //�˵�����6
    SetMenu[1].MenuState=0;                              //��״̬
    SetMenu[1].ChildrenMenus=CommunicationMenu;          //ͨѶ���ò���
    SetMenu[1].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SetMenu[1].Subs=NullFuntion;                         //�޺���
    
    //��������
    SetMenu[2].ID=setmenu;                               //���ò˵�ID��
    SetMenu[2].MenuCount=4;                              //�˵�����6
    SetMenu[2].MenuState=0;                              //��״̬
    SetMenu[2].ChildrenMenus=HeatMenu;                   //���Ȳ˵����ò���
    SetMenu[2].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SetMenu[2].Subs=NullFuntion;                         //�޺���
    
     //�ָ���������
    SetMenu[3].ID=setmenu;                               //���ò˵�ID��
    SetMenu[3].MenuCount=4;                              //�˵�����6
    SetMenu[3].MenuState=0;                              //��״̬
    SetMenu[3].ChildrenMenus=0;                          //0
    SetMenu[3].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SetMenu[3].Subs=Display_SetMenu2_SubSetDefault;      //�޺���
}

/*
********************************************************************************
�������ƣ�void TimeMenuInit(void)
�������ܣ�ʱ�����ó�ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void TimeMenuInit(void)
{
    //����
    TimeMenu[0].ID=timemenu;                              //ʱ������ID��
    TimeMenu[0].MenuCount=2;                              //�˵�����2
    TimeMenu[0].MenuState=0;                              //��״̬
    TimeMenu[0].ChildrenMenus=0;                          //0
    TimeMenu[0].ParentMenus=SetMenu;                      //���˵�Ϊsetmenu
    TimeMenu[0].Subs=Display_SetMenu1_SubSetTime_YMD;     //�Ӳ˵�����ʱ������
    
    //ʱ��
    TimeMenu[1].ID=timemenu;                              //ʱ������ID��
    TimeMenu[1].MenuCount=2;                              //�˵�����2
    TimeMenu[1].MenuState=0;                              //��״̬
    TimeMenu[1].ChildrenMenus=0;                          //0
    TimeMenu[1].ParentMenus=SetMenu;                      //���˵�Ϊsetmenu
    TimeMenu[1].Subs=Display_SetMenu1_SubSetTime_HMS;     //�Ӳ˵�����ʱ������
}

/*
********************************************************************************
�������ƣ�void CommunicationMenuInit(void)
�������ܣ�ͨѶ���ó�ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void CommunicationMenuInit(void)
{
    //������
    CommunicationMenu[0].ID=communicationmenu;                     //���ò˵�ID��
    CommunicationMenu[0].MenuCount=4;                              //�˵�����4
    CommunicationMenu[0].MenuState=0;                              //��״̬
    CommunicationMenu[0].ChildrenMenus=0;                          //0
    CommunicationMenu[0].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    CommunicationMenu[0].Subs=Display_SetMenu1_SubSetCommunication1_BAUD;//�Ӳ˵���������������
    
    //����λ
    CommunicationMenu[1].ID=communicationmenu;                     //���ò˵�ID��
    CommunicationMenu[1].MenuCount=4;                              //�˵�����4
    CommunicationMenu[1].MenuState=0;                              //��״̬
    CommunicationMenu[1].ChildrenMenus=0;                          //0
    CommunicationMenu[1].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    CommunicationMenu[1].Subs=Display_SetMenu1_SubSetCommunication1_DATABITS;//�Ӳ˵���������λ����
    
    //У��λ
    CommunicationMenu[2].ID=communicationmenu;                     //���ò˵�ID��
    CommunicationMenu[2].MenuCount=4;                              //�˵�����6
    CommunicationMenu[2].MenuState=0;                              //��״̬
    CommunicationMenu[2].ChildrenMenus=0;                          //0
    CommunicationMenu[2].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    CommunicationMenu[2].Subs=Display_SetMenu1_SubSetCommunication1_PARITYBIT;//�Ӳ˵�����У��λ����
    
    //ֹͣλ
    CommunicationMenu[3].ID=communicationmenu;                     //���ò˵�ID��
    CommunicationMenu[3].MenuCount=4;                              //�˵�����6
    CommunicationMenu[3].MenuState=0;                              //��״̬
    CommunicationMenu[3].ChildrenMenus=0;                          //0
    CommunicationMenu[3].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    CommunicationMenu[3].Subs=Display_SetMenu1_SubSetCommunication1_STOPBIT;//�Ӳ˵�����ֹͣλ����
}

/*
********************************************************************************
�������ƣ�void HeatMenuInit(void)
�������ܣ��������ó�ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void HeatMenuInit(void)
{
    //���ȿ���
    HeatMenu[0].ID=heatmenu;                              //���Ȳ˵�ID��
    HeatMenu[0].MenuCount=4;                              //�˵�����4
    HeatMenu[0].MenuState=0;                              //��״̬
    HeatMenu[0].ChildrenMenus=0;                          //0
    HeatMenu[0].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    HeatMenu[0].Subs=Display_SetMenu1_SubSetHeat_HEATCONT;//�Ӳ˵���������
    
    //�¶�����
    HeatMenu[1].ID=heatmenu;                              //���Ȳ˵�ID��
    HeatMenu[1].MenuCount=4;                              //�˵�����4
    HeatMenu[1].MenuState=0;                              //��״̬
    HeatMenu[1].ChildrenMenus=0;                          //0
    HeatMenu[1].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    HeatMenu[1].Subs=Display_SetMenu1_SubSetHeat_HEAT_TEMP;//�Ӳ˵���������
    
    //������
    HeatMenu[2].ID=heatmenu;                              //���Ȳ˵�ID��
    HeatMenu[2].MenuCount=4;                              //�˵�����4
    HeatMenu[2].MenuState=0;                              //��״̬
    HeatMenu[2].ChildrenMenus=0;                          //0
    HeatMenu[2].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    HeatMenu[2].Subs=NullFuntion;                         //�Ӳ˵���������
    
    //���ȹ���
    HeatMenu[3].ID=heatmenu;                              //���Ȳ˵�ID��
    HeatMenu[3].MenuCount=4;                              //�˵�����4
    HeatMenu[3].MenuState=0;                              //��״̬
    HeatMenu[3].ChildrenMenus=0;                          //0
    HeatMenu[3].ParentMenus=SetMenu;                      //���˵�ΪSetMenu
    HeatMenu[3].Subs=NullFuntion;                         //�Ӳ˵���������
}


/*****************************************************�����˵�ȫ����������**********************************************************/

/*
********************************************************************************
�������ƣ�void SamplingMenuInit(void)
�������ܣ������˵���ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void SamplingMenuInit(void)
{
    //Ԥ������
    SamplingMenu[0].ID=samplingmenu;                          //�����˵�ID��
    SamplingMenu[0].MenuCount=3;                              //�˵�����3
    SamplingMenu[0].MenuState=0;                              //��״̬
    SamplingMenu[0].ChildrenMenus=PresetMenu;                 //Ԥ����������
    SamplingMenu[0].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SamplingMenu[0].Subs=NullFuntion;                         //�Ӳ˵���������
    
    //��ʱ����
    SamplingMenu[1].ID=samplingmenu;                          //�����˵�ID��
    SamplingMenu[1].MenuCount=3;                              //�˵�����3
    SamplingMenu[1].MenuState=0;                              //��״̬
    SamplingMenu[1].ChildrenMenus=TimingMenu;                 //��ʱ��������
    SamplingMenu[1].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SamplingMenu[1].Subs=NullFuntion;                         //�Ӳ˵���������
    
    //��������
    SamplingMenu[2].ID=samplingmenu;                          //�����˵�ID��
    SamplingMenu[2].MenuCount=3;                              //�˵�����3
    SamplingMenu[2].MenuState=0;                              //��״̬
    SamplingMenu[2].ChildrenMenus=ImmediatelyMenu;            //����������������
    SamplingMenu[2].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SamplingMenu[2].Subs=NullFuntion;                         //�Ӳ˵���������
}

/*
********************************************************************************
�������ƣ�void PresetMenuInit(void)
�������ܣ�Ԥ��������ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void PresetMenuInit(void)
{
    //����Aֵ����
    PresetMenu[0].ID=presetmenu;                            //�����˵�ID��
    PresetMenu[0].MenuCount=3;                              //�˵�����3
    PresetMenu[0].MenuState=0;                              //��״̬
    PresetMenu[0].ChildrenMenus=0;                          //Ԥ����������
    PresetMenu[0].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    PresetMenu[0].Subs=Display_SamplingMenu_SubPreset_SAMPLING_A;//�Ӳ˵���������
    
    //����Bֵ����
    PresetMenu[1].ID=presetmenu;                            //�����˵�ID��
    PresetMenu[1].MenuCount=3;                              //�˵�����2
    PresetMenu[1].MenuState=0;                              //��״̬
    PresetMenu[1].ChildrenMenus=0;                          //��ʱ��������
    PresetMenu[1].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    PresetMenu[1].Subs=Display_SamplingMenu_SubPreset_SAMPLING_B;//�Ӳ˵���������  
    
    //��������
    PresetMenu[2].ID=presetmenu;                            //�����˵�ID��
    PresetMenu[2].MenuCount=3;                              //�˵�����3
    PresetMenu[2].MenuState=0;                              //��״̬
    PresetMenu[2].ChildrenMenus=0;                          //��ʱ��������
    PresetMenu[2].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    PresetMenu[2].Subs=Display_SamplingMenu_SubPreset_FLOW_START;//�Ӳ˵���������  
}

/*
********************************************************************************
�������ƣ�void TimingMenuInit(void)
�������ܣ���ʱ������ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void TimingMenuInit(void)
{    
    //��ʼA
    TimingMenu[0].ID=timingmenu;                            //��ʱ����ID��
    TimingMenu[0].MenuCount=5;                              //�˵�����3
    TimingMenu[0].MenuState=0;                              //��״̬
    TimingMenu[0].ChildrenMenus=0;                          //��ʱ��������
    TimingMenu[0].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    TimingMenu[0].Subs=Display_SamplingMenu_SubTiming1_START_A;//�Ӳ˵���������  
    
    //��ʼB
    TimingMenu[1].ID=timingmenu;                            //��ʱ����ID��
    TimingMenu[1].MenuCount=5;                              //�˵�����3
    TimingMenu[1].MenuState=0;                              //��״̬
    TimingMenu[1].ChildrenMenus=0;                          //��ʱ��������
    TimingMenu[1].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    TimingMenu[1].Subs=Display_SamplingMenu_SubTiming1_START_B;//�Ӳ˵���������  
    
    //��ʱA
    TimingMenu[2].ID=timingmenu;                            //��ʱ����ID��
    TimingMenu[2].MenuCount=5;                              //�˵�����3
    TimingMenu[2].MenuState=0;                              //��״̬
    TimingMenu[2].ChildrenMenus=0;                          //��ʱ��������
    TimingMenu[2].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    TimingMenu[2].Subs=Display_SamplingMenu_SubTiming1_SAMPLING_A;//�Ӳ˵���������  
    
    //��ʱB
    TimingMenu[3].ID=timingmenu;                            //��ʱ����ID��
    TimingMenu[3].MenuCount=5;                              //�˵�����3
    TimingMenu[3].MenuState=0;                              //��״̬
    TimingMenu[3].ChildrenMenus=0;                          //��ʱ��������
    TimingMenu[3].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    TimingMenu[3].Subs=Display_SamplingMenu_SubTiming1_SAMPLING_B;//�Ӳ˵���������  
    
    //��������
    TimingMenu[4].ID=timingmenu;                            //��ʱ����ID��
    TimingMenu[4].MenuCount=5;                              //�˵�����3
    TimingMenu[4].MenuState=0;                              //��״̬
    TimingMenu[4].ChildrenMenus=0;                          //�����в�������
    TimingMenu[4].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    TimingMenu[4].Subs=Display_SamplingMenu_SubTiming_SubWait; //�ȴ���������
}

/*
********************************************************************************
�������ƣ�void ImmediatelyMenuInit(void)
�������ܣ�����������ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void ImmediatelyMenuInit(void)
{ 
    //��ʱA
    ImmediatelyMenu[0].ID=immediatelymenu;                       //��������ID��
    ImmediatelyMenu[0].MenuCount=3;                              //�˵�����3
    ImmediatelyMenu[0].MenuState=0;                              //��״̬
    ImmediatelyMenu[0].ChildrenMenus=0;                          //0
    ImmediatelyMenu[0].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    ImmediatelyMenu[0].Subs=Display_SamplingMenu_SubImmediately_IMMEDIATELY_A;//�Ӳ˵���������  
    
    //��ʱB
    ImmediatelyMenu[1].ID=immediatelymenu;                       //��������ID��
    ImmediatelyMenu[1].MenuCount=3;                              //�˵�����3
    ImmediatelyMenu[1].MenuState=0;                              //��״̬
    ImmediatelyMenu[1].ChildrenMenus=0;                          //0
    ImmediatelyMenu[1].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    ImmediatelyMenu[1].Subs=Display_SamplingMenu_SubImmediately_IMMEDIATELY_B;//�Ӳ˵���������  
    
    //��������
    ImmediatelyMenu[2].ID=immediatelymenu;                       //��������ID��
    ImmediatelyMenu[2].MenuCount=3;                              //�˵�����3
    ImmediatelyMenu[2].MenuState=0;                              //��״̬
    ImmediatelyMenu[2].ChildrenMenus=0;                          //0
    ImmediatelyMenu[2].ParentMenus=SamplingMenu;                 //���˵�ΪSamplingMenu
    ImmediatelyMenu[2].Subs=Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay;//�Ӳ˵��������� 
}

/*****************************************************��ѯ�˵�ȫ����������**********************************************************/

/*
********************************************************************************
�������ƣ�void SeekMenuInit(void)
�������ܣ���ѯ�˵���ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void SeekMenuInit(void)
{
    //�ļ���
    SeekMenu[0].ID=seekmenu;                              //��ѯID��
    SeekMenu[0].MenuCount=5;                              //�˵�����5
    SeekMenu[0].MenuState=0;                              //��״̬
    SeekMenu[0].ChildrenMenus=0;                          //0
    SeekMenu[0].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SeekMenu[0].Subs=Display_SeekMenu1_FILE_NUMBER;       //�Ӳ˵���������
    
    //�ļ��Ϸ�
    SeekMenu[1].ID=seekmenu;                              //��ѯID��
    SeekMenu[1].MenuCount=5;                              //�˵�����5
    SeekMenu[1].MenuState=0;                              //��״̬
    SeekMenu[1].ChildrenMenus=0;                          //0
    SeekMenu[1].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SeekMenu[1].Subs=Display_SeekMenu1_UPTURN;            //�Ӳ˵���������  
    
    //�ļ��·�
    SeekMenu[2].ID=seekmenu;                              //��ѯID��
    SeekMenu[2].MenuCount=5;                              //�˵�����5
    SeekMenu[2].MenuState=0;                              //��״̬
    SeekMenu[2].ChildrenMenus=0;                          //0
    SeekMenu[2].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SeekMenu[2].Subs=Display_SeekMenu1_DOWNTURN;          //�Ӳ˵��������� 
    
    //�ļ���ϸ
    SeekMenu[3].ID=seekmenu;                              //��ѯID��
    SeekMenu[3].MenuCount=5;                              //�˵�����5
    SeekMenu[3].MenuState=0;                              //��״̬
    SeekMenu[3].ChildrenMenus=0;                          //�ļ���ϸ
    SeekMenu[3].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SeekMenu[3].Subs=Display_SeekMenu2_SubFile1;          //�Ӳ˵��ļ���ϸ��������  
    
    //�ļ�����
    SeekMenu[4].ID=seekmenu;                              //��ѯID��
    SeekMenu[4].MenuCount=5;                              //�˵�����5
    SeekMenu[4].MenuState=0;                              //��״̬
    SeekMenu[4].ChildrenMenus=0;                          //Ϊ0
    SeekMenu[4].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    SeekMenu[4].Subs=Display_SeekMenu2_SubFileClear;      //�Ӳ˵��ļ���ϸ��������  

}

/*****************************************************ά���˵�ȫ����������**********************************************************/

/*
********************************************************************************
�������ƣ�void MaintainMenuInit(void)
�������ܣ�ά���˵���ʼ��
��ڲ�������
���ڲ�������
********************************************************************************
*/
void MaintainMenuInit(void)
{
    //��ѹ��Ϣ
    MaintainMenu[0].ID=maintainmenu;                          //ά��ID��
    MaintainMenu[0].MenuCount=3;                              //�˵�����3
    MaintainMenu[0].MenuState=0;                              //��״̬
    MaintainMenu[0].ChildrenMenus=VoltageMenu;                //��ѹ��Ϣ
    MaintainMenu[0].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    MaintainMenu[0].Subs=NullFuntion;                         //�Ӳ˵���������
    
    //�¶���ѹ
    MaintainMenu[1].ID=maintainmenu;                          //ά��ID��
    MaintainMenu[1].MenuCount=3;                              //�˵�����3
    MaintainMenu[1].MenuState=0;                              //��״̬
    MaintainMenu[1].ChildrenMenus=TemperaturePressureMenu;    //�¶���ѹ
    MaintainMenu[1].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    MaintainMenu[1].Subs=NullFuntion;                         //�Ӳ˵���������  
    
    //�汾��Ϣ
    MaintainMenu[2].ID=maintainmenu;                          //ά��ID��
    MaintainMenu[2].MenuCount=3;                              //�˵�����3
    MaintainMenu[2].MenuState=0;                              //��״̬
    MaintainMenu[2].ChildrenMenus=VersionsMenu;               //0
    MaintainMenu[2].ParentMenus=MainMenu;                     //���˵�ΪMainMenu
    MaintainMenu[2].Subs=NullFuntion;                         //�Ӳ˵��������� 
}

/*
********************************************************************************
�������ƣ�void VoltageMenuInit(void)
�������ܣ�ά���˵�����--��ѹ��Ϣ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void VoltageMenuInit(void)
{
    //���ص�ѹ
    VoltageMenu[0].ID=voltagemenu;                           //��ѹ��ϢID��
    VoltageMenu[0].MenuCount=4;                              //�˵�����4
    VoltageMenu[0].MenuState=0;                              //��״̬
    VoltageMenu[0].ChildrenMenus=0;                          //0
    VoltageMenu[0].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    VoltageMenu[0].Subs=NullFuntion;                         //�Ӳ˵���������
    
    //��ص�ѹ
    VoltageMenu[1].ID=voltagemenu;                           //��ѹ��ϢID��
    VoltageMenu[1].MenuCount=4;                              //�˵�����4
    VoltageMenu[1].MenuState=0;                              //��״̬
    VoltageMenu[1].ChildrenMenus=0;                          //0
    VoltageMenu[1].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    VoltageMenu[1].Subs=NullFuntion;                         //�Ӳ˵���������  
    
    //��A��ѹ
    VoltageMenu[2].ID=voltagemenu;                           //��ѹ��ϢID��
    VoltageMenu[2].MenuCount=4;                              //�˵�����4
    VoltageMenu[2].MenuState=0;                              //��״̬
    VoltageMenu[2].ChildrenMenus=0;                          //0
    VoltageMenu[2].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    VoltageMenu[2].Subs=NullFuntion;                         //�Ӳ˵��������� 
    
    //��B��ѹ
    VoltageMenu[3].ID=voltagemenu;                           //��ѹ��ϢID��
    VoltageMenu[3].MenuCount=4;                              //�˵�����4
    VoltageMenu[3].MenuState=0;                              //��״̬
    VoltageMenu[3].ChildrenMenus=0;                          //0
    VoltageMenu[3].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    VoltageMenu[3].Subs=NullFuntion;                         //�Ӳ˵��������� 
}

/*
********************************************************************************
�������ƣ�void TemperaturePressureMenuInit(void)
�������ܣ�ά���˵�����--�¶���ѹ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void TemperaturePressureMenuInit(void)
{
    //������
    TemperaturePressureMenu[0].ID=temperaturepressuremenu;               //�¶���ѹID��
    TemperaturePressureMenu[0].MenuCount=4;                              //�˵�����4
    TemperaturePressureMenu[0].MenuState=0;                              //��״̬
    TemperaturePressureMenu[0].ChildrenMenus=0;                          //��ѹ��Ϣ
    TemperaturePressureMenu[0].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    TemperaturePressureMenu[0].Subs=NullFuntion;                         //�Ӳ˵���������
    
    //ͨ��A
    TemperaturePressureMenu[1].ID=temperaturepressuremenu;               //�¶���ѹID��
    TemperaturePressureMenu[1].MenuCount=4;                              //�˵�����4
    TemperaturePressureMenu[1].MenuState=0;                              //��״̬
    TemperaturePressureMenu[1].ChildrenMenus=0;                          //0
    TemperaturePressureMenu[1].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    TemperaturePressureMenu[1].Subs=NullFuntion;                         //�Ӳ˵���������  
    
    //ͨ��B
    TemperaturePressureMenu[2].ID=temperaturepressuremenu;               //�¶���ѹID��
    TemperaturePressureMenu[2].MenuCount=4;                              //�˵�����4
    TemperaturePressureMenu[2].MenuState=0;                              //��״̬
    TemperaturePressureMenu[2].ChildrenMenus=0;                          //0
    TemperaturePressureMenu[2].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    TemperaturePressureMenu[2].Subs=NullFuntion;                         //�Ӳ˵��������� 
    
    //��ѹ
    TemperaturePressureMenu[3].ID=temperaturepressuremenu;               //�¶���ѹID��
    TemperaturePressureMenu[3].MenuCount=4;                              //�˵�����4
    TemperaturePressureMenu[3].MenuState=0;                              //��״̬
    TemperaturePressureMenu[3].ChildrenMenus=0;                          //0
    TemperaturePressureMenu[3].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    TemperaturePressureMenu[3].Subs=NullFuntion;                         //�Ӳ˵��������� 
}

/*
********************************************************************************
�������ƣ�void VersionsMenuInit(void)
�������ܣ�ά���˵�����--�汾��Ϣ
��ڲ�������
���ڲ�������
********************************************************************************
*/
void VersionsMenuInit(void)
{
    VersionsMenu[0].ID=versionsmenu;                          //�¶���ѹID��
    VersionsMenu[0].MenuCount=0;                              //�˵�����4
    VersionsMenu[0].MenuState=0;                              //��״̬
    VersionsMenu[0].ChildrenMenus=0;                          //��ѹ��Ϣ
    VersionsMenu[0].ParentMenus=MaintainMenu;                 //���˵�ΪMaintainMenu
    VersionsMenu[0].Subs=NullFuntion;                         //�Ӳ˵���������
}

/*
********************************************************************************
�������ƣ�void MenuInit(void)
�������ܣ���ʼ������˵�
��ڲ�������
���ڲ�������
********************************************************************************
*/
void MenuInit(void)
{
    //���˵���ʼ��
    MainMenuInit();
/***********************���ò�����������***********************/
    //���ý����ʼ��
    SetMenuInit();
    //���ý�������--ʱ������
    TimeMenuInit();
    //���ý�������--ͨѶ����
    CommunicationMenuInit();
    //���ý�������--��������
    HeatMenuInit();
/***********************���ò�����������***********************/
    //������ʼ��
    SamplingMenuInit();
    //������������--Ԥ������
    PresetMenuInit();
    //������������--��ʱ����
    TimingMenuInit();
    //������������--��������
    ImmediatelyMenuInit();
/***********************��ѯ������������***********************/
    //��ѯ��ʼ��
    SeekMenuInit();
/***********************ά��������������***********************/
    //ά����ʼ��
    MaintainMenuInit();
    //ά������--��ѹ��ʾ
    VoltageMenuInit();
    //ά������--�¶���ѹ
    TemperaturePressureMenuInit();
    //ά������--�汾��Ϣ
    VersionsMenuInit();
}