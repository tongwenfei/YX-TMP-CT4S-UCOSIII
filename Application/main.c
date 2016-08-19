
#include "delay.h"
#include "sys.h"

#include "include.h"
/************************************************
ALIENTEKս��STM32������UCOSʵ��
��4-1 UCOSIII UCOSIII��ֲ
����֧�֣�www.openedv.com
�Ա����̣�http://eboard.taobao.com 
��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
������������ӿƼ����޹�˾  
���ߣ�����ԭ�� @ALIENTEK
************************************************/

//UCOSIII���������ȼ��û�������ʹ�ã�ALIENTEK
//����Щ���ȼ��������UCOSIII��5��ϵͳ�ڲ�����
//���ȼ�0���жϷ������������� OS_IntQTask()
//���ȼ�1��ʱ�ӽ������� OS_TickTask()
//���ȼ�2����ʱ���� OS_TmrTask()
//���ȼ�OS_CFG_PRIO_MAX-2��ͳ������ OS_StatTask()
//���ȼ�OS_CFG_PRIO_MAX-1���������� OS_IdleTask()
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK



//������ƿ�
OS_TCB StartTaskTCB;
//�����ջ	
static CPU_STK START_TASK_STK[START_STK_SIZE];
#define KEYMSG_Q_NUM	1	//������Ϣ���е�����
OS_Q KEY_Msg;				//����һ����Ϣ���У����ڰ�����Ϣ���ݣ�ģ����Ϣ����
OS_TMR	tmr1;	//����һ����ʱ��

//������
void start_task(void *p_arg);






int main(void)
{
  OS_ERR err;
  CPU_SR_ALLOC();
  uint8_t def = 0;
  delay_init();       //��ʱ��ʼ��
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�жϷ�������
  RCC_Config();
  LED_Init();         //LED��ʼ��   
  Pump_IOinit();
  PUMP4_ON();
  PUMP3_OFF();
  PUMP2_OFF();
  PUMP1_OFF();
  LCD_Init();
  FM24C64_Init();             //�����ʼ��
  Ds1302_GPIO_Init();
  FM24C64_READ_MUL(DEFAULT,(uint8_t*)&def,1);
  if(def != 0xA5)
  {
    Target_Init();              //ʵ��Ŀ����������ֵ
//    def = 0xA5;
//    FM24C64_WRITE_MUL(DEFAULT,(uint8_t*)&def,1);
  }
  for(uint8_t i=0;i<6;i++)
  {
    PassWd_last[i]=i+1;
  }
  
  ADS1248_Init();
  
  def=DS1302_Check();
  if(def!=0) Ds1302_Time_Init();
  def=DS18B20_Init();
  ADC1_Init();
  AD7923_Init();
  MS561101BA_Init();
  Key_Init();
  Flow_PWM_Init();
  TEM_PWM_Init();
  TIM6_Int_Init(7199,999);
  
  //  eMBInit(MB_RTU, 0x0A, 0, 115200, MB_PAR_NONE);
  //  eMBEnable();	
  Disp_MainWindow();
  //PassWd_SetDisp();
  WDOG_Init();                //��ʼ�����Ź�
  Feed_Dog();                 //����ι��
  OSInit(&err);		//��ʼ��UCOSIII
  OS_CRITICAL_ENTER();//�����ٽ���
  //������ʼ����
  OSTaskCreate((OS_TCB 	* )&StartTaskTCB,		//������ƿ�
	       (CPU_CHAR	* )"start task", 		//��������
	       (OS_TASK_PTR )start_task, 			//������
	       (void		* )0,					//���ݸ��������Ĳ���
	       (OS_PRIO	  )START_TASK_PRIO,     //�������ȼ�
	       (CPU_STK   * )&START_TASK_STK[0],	//�����ջ����ַ
	       (CPU_STK_SIZE)START_STK_SIZE/10,	//�����ջ�����λ
	       (CPU_STK_SIZE)START_STK_SIZE,		//�����ջ��С
	       (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
	       (OS_TICK	  )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
	       (void   	* )0,					//�û�����Ĵ洢��
	       (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
	       (OS_ERR 	* )&err);				//��Ÿú�������ʱ�ķ���ֵ
  OS_CRITICAL_EXIT();	//�˳��ٽ���	 
  OSStart(&err);  //����UCOSIII
  while(1);
}

//��ʼ������
void start_task(void *p_arg)
{
  OS_ERR err;
  CPU_SR_ALLOC();
  p_arg = p_arg;
  
  CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
  OSStatTaskCPUUsageInit(&err);  	//ͳ������                
#endif
  
#ifdef CPU_CFG_INT_DIS_MEAS_EN		//���ʹ���˲����жϹر�ʱ��
  CPU_IntDisMeasMaxCurReset();	
#endif
  
#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //��ʹ��ʱ��Ƭ��ת��ʱ��
  //ʹ��ʱ��Ƭ��ת���ȹ���,ʱ��Ƭ����Ϊ1��ϵͳʱ�ӽ��ģ���1*5=5ms
  OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif		
  
  OS_CRITICAL_ENTER();	//�����ٽ���
  
  //������Ϣ����KEY_Msg
  OSQCreate ((OS_Q*		)&KEY_Msg,	//��Ϣ����
	     (CPU_CHAR*	)"KEY Msg",	//��Ϣ��������
	     (OS_MSG_QTY	)KEYMSG_Q_NUM,	//��Ϣ���г��ȣ���������Ϊ1
	     (OS_ERR*	)&err);		//������
  //������ʱ��1
  OSTmrCreate((OS_TMR		*)&tmr1,		//��ʱ��1
	      (CPU_CHAR	*)"tmr1",		//��ʱ������
	      (OS_TICK	 )0,			//0ms
	      (OS_TICK	 )3000,          //3000*10=30000ms
	      (OS_OPT		 )OS_OPT_TMR_PERIODIC, //����ģʽ
	      (OS_TMR_CALLBACK_PTR)tmr1_callback,//��ʱ��1�ص�����
	      (void	    *)0,			//����Ϊ0
	      (OS_ERR	    *)&err);		//���صĴ�����
  //����LED0����
  CreateMainTask();
  CreateTempTask();
  CreateGUITask();
  CreateTempPressTask();
  CreateRTCTask();
  CreateKeyTask();
  CreateBATTERTask();
  CreateFlowControlTask();
  CreateTempControlTask();
  CreateUsartTask();
  OS_TaskSuspend((OS_TCB*)&StartTaskTCB,&err);		//����ʼ����			 
  OS_CRITICAL_EXIT();	//�����ٽ���
}



//��ʱ��1�Ļص�����
void tmr1_callback(void *p_tmr,void *p_arg)
{

	CLR_LCD_LED();
	
	
}