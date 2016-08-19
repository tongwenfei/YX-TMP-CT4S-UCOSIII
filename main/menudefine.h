/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			menudefine.h
 *Description��     	        �˵����涨��
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __MENUDEFINE_H__
#define __MENUDEFINE_H__




/*********************************������˵����ID��***************************/

enum MenuID
{
    mainmenu = 1,                            //���˵�
    
    /*���ò˵�ȫ��ID*/
    setmenu,                                 
    timemenu,
    communicationmenu,
    heatmenu,
    
    /*�����˵�ȫ��ID*/
    samplingmenu,
    presetmenu,
    timingmenu,
    immediatelymenu,
    
    /*��ѯ�˵�ȫ��ID*/
    seekmenu,
    
    /*ά���˵�ȫ��ID*/
    maintainmenu,
    voltagemenu,
    temperaturepressuremenu,
    versionsmenu,
};

/*********************************�������ṹ��*******************************/

struct MenuItem 
{ 	
    enum MenuID ID;                         //���嵱ǰ����ID��    
    uint8_t MenuCount;                        //���嵱ǰ���ܵĸ���
    uint8_t MenuState;                        //��¼��ǰ��ҳ��״̬
    struct MenuItem *ChildrenMenus;         //���嵱ǰ������Ӳ˵�
    struct MenuItem *ParentMenus;           //���嵱ǰ����ĸ��˵�
    void (*Subs)();                         //���嵱ǰ�����ӹ��ܽ�ȥ��Ľ��溯����ʵ�ֵĹ���
}; 

/*********************************�������鶨��*********************************/

//���˵���������	
extern struct MenuItem MainMenu[4];	           

/***********************���ò�������***********************/
//��������
extern struct MenuItem SetMenu[4];

//������������--ʱ������
extern struct MenuItem TimeMenu[2];

//������������--ͨѶ����
extern struct MenuItem CommunicationMenu[4]; 

//������������--��������
extern struct MenuItem HeatMenu[4]; 


/***********************������������***********************/
//����
extern struct MenuItem SamplingMenu[3];            //�����˵���������	

//������������--Ԥ������
extern struct MenuItem PresetMenu[3];

//������������--��ʱ����
extern struct MenuItem TimingMenu[5];

//������������--��������
extern struct MenuItem ImmediatelyMenu[3];


/***********************��ѯ��������***********************/
//��ѯ
extern struct MenuItem SeekMenu[5];	            //��ѯ�˵���������	

/***********************ά����������***********************/
//ά��
extern struct MenuItem MaintainMenu[3];            //ά����������
//ά������--��ѹ��Ϣ
extern struct MenuItem VoltageMenu[4];
//ά������--�¶���ѹ
extern struct MenuItem TemperaturePressureMenu[4];
//ά������--�汾��Ϣ
extern struct MenuItem VersionsMenu[1];



/*********************************��������*************************************/
//����˵���ʼ��
extern void MenuInit(void);
extern void NullFuntion(void);
#endif