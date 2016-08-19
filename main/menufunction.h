/*******************************************************************************
 *CopyRight Reserved:	
 *Filename��			mainmenu.h
 *Description��     	       ���������
 *Date:
 *Author:		
*******************************************************************************/

#ifndef __MAINMENU_H__
#define __MAINMENU_H__



/*********************************��������*************************************/

/************************* ���� ��������***********************/
//�����ʾ
extern void Display_Batter(uint8_t flag);
//��Դ��ʾ
extern void Display_Power(uint8_t flag);


/************************* ������ ��������***********************/
extern void Display_MainMenu(void);
extern void Display_TimeValue(void);


/*********************** ���ý��� ��������***********************/
extern void Display_SetMenu1(void);

//���ý���1�Ӳ˵�-ʱ������
extern void Display_SetMenu1_SubSetTime(void);
//���ý���1�Ӳ˵�-ʱ������(����������)
extern void Display_SetMenu1_SubSetTime_YMD(void);
//���ý���1�Ӳ˵�-ʱ������(ʱ��������)
extern void Display_SetMenu1_SubSetTime_HMS(void);

//���ý���1�Ӳ˵�-ͨѶ����
extern void Display_SetMenu1_SubSetCommunication1(void);
//���ý���1�Ӳ˵�-ͨѶ����(����������)
extern void Display_SetMenu1_SubSetCommunication1_BAUD(void);
//���ý���1�Ӳ˵�-ͨѶ����(����λ����)
extern void Display_SetMenu1_SubSetCommunication1_DATABITS(void);
//���ý���1�Ӳ˵�-ͨѶ����(У��λ����)
extern void Display_SetMenu1_SubSetCommunication1_PARITYBIT(void);
//���ý���1�Ӳ˵�-ͨѶ����(ֹͣλ����)
extern void Display_SetMenu1_SubSetCommunication1_STOPBIT(void);

//���ý���1�Ӳ˵�-���ȿ���
extern void Display_SetMenu1_SubSetHeat(void); 
//���ý���1�Ӳ˵�-���ȿ���(���ؿ���)
extern void Display_SetMenu1_SubSetHeat_HEATCONT(void);
//���ý���1�Ӳ˵�-���ȿ���(�¶�����)
extern void Display_SetMenu1_SubSetHeat_HEAT_TEMP(void);
//�����Ƿ�ָ��������ú��ѻָ���������
extern void Display_SetMenu2_SubSetDefault(void);


/********************** �������� ��������************************/

extern void Display_SamplingMenu(void);

//�����ӽ��� Ԥ����������
extern void Display_SamplingMenu_SubPreset(void);
//�����ӽ��� Ԥ����������(����A����)
extern void Display_SamplingMenu_SubPreset_SAMPLING_A(void);
//�����ӽ��� Ԥ����������(����B����)
extern void Display_SamplingMenu_SubPreset_SAMPLING_B(void);
//�����ӽ��� Ԥ����������(��������)
extern void Display_SamplingMenu_SubPreset_FLOW_START(void);

//�����ӽ��� ��ʱ��������
extern void Display_SamplingMenu_SubTiming1(void);
//�����ӽ��� ��ʱ��������(ͨ��A��ʼʱ������)
extern void Display_SamplingMenu_SubTiming1_START_A(void);
//�����ӽ��� ��ʱ��������(ͨ��B��ʼʱ������)
extern void Display_SamplingMenu_SubTiming1_START_B(void);
//�����ӽ��� ��ʱ��������(ͨ��A�ɼ�ʱ������)
extern void Display_SamplingMenu_SubTiming1_SAMPLING_A(void);
//�����ӽ��� ��ʱ��������(ͨ��B�ɼ�ʱ������)
extern void Display_SamplingMenu_SubTiming1_SAMPLING_B(void);
//�����ӽ��� ��ʱ�����������ӽ��� (�ȴ�����)
extern void Display_SamplingMenu_SubTiming_SubWait(void);

//��ʱ�������棨���������С�������
extern void Display_SamplingMenu_SubTiming_SubWait_SubUnderWay(void);
//�����������棨���������С�������
extern void Display_SamplingMenu_SubImmediately_SubWait_SubUnderWay(void);

//�����ӽ��� �����������ӽ��� 
extern void Display_SamplingMenu_SubContinue(void);

//�����ӽ��� �����������ӽ��� 
extern void Display_SamplingMenu_SubImmediately(void);
//�����ӽ��� �����������ӽ��� (�ɼ�ʱ������)
extern void Display_SamplingMenu_SubImmediately_IMMEDIATELY_A(void);
//�����ӽ��� �����������ӽ��� (�ɼ�ʱ������)
extern void Display_SamplingMenu_SubImmediately_IMMEDIATELY_B(void);



/********************** ��ѯ���� ��������************************/
extern void Display_SeekMenu1(void);
//��ѯ���棨�ļ�������ã�
extern void Display_SeekMenu1_FILE_NUMBER(void);
//��ѯ���棨�ļ��Ϸ���
extern void Display_SeekMenu1_UPTURN(void);
//��ѯ���棨�ļ��·���
extern void Display_SeekMenu1_DOWNTURN(void);

//��ѯ�����Ӳ˵�-�ļ���ϸ
extern void Display_SeekMenu2_SubFile1(void);
//��ѯ�����Ӳ˵�-�ļ�����
extern void Display_SeekMenu2_SubFileClear(void);

/********************** ά������ ��������************************/
extern void Display_MaintainMenu(void);

//ά�������Ӳ˵�-��ѹ��Ϣ
extern void Display_MaintainMenu_SubDisplayVoltage1(void);
//ά�������Ӳ˵�-�¶���ѹ
extern void Display_MaintainMenu_SubDisplayTemperaturePressure1(void);
//ά�������Ӳ˵�-�汾��Ϣ
extern void Display_MaintainMenu_SubDisplayVersions(void);

#endif