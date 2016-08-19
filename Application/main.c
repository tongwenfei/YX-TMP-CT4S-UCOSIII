
#include "delay.h"
#include "sys.h"

#include "include.h"
/************************************************
ALIENTEK战舰STM32开发板UCOS实验
例4-1 UCOSIII UCOSIII移植
技术支持：www.openedv.com
淘宝店铺：http://eboard.taobao.com 
关注微信公众平台微信号："正点原子"，免费获取STM32资料。
广州市星翼电子科技有限公司  
作者：正点原子 @ALIENTEK
************************************************/

//UCOSIII中以下优先级用户程序不能使用，ALIENTEK
//将这些优先级分配给了UCOSIII的5个系统内部任务
//优先级0：中断服务服务管理任务 OS_IntQTask()
//优先级1：时钟节拍任务 OS_TickTask()
//优先级2：定时任务 OS_TmrTask()
//优先级OS_CFG_PRIO_MAX-2：统计任务 OS_StatTask()
//优先级OS_CFG_PRIO_MAX-1：空闲任务 OS_IdleTask()
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK



//任务控制块
OS_TCB StartTaskTCB;
//任务堆栈	
static CPU_STK START_TASK_STK[START_STK_SIZE];
#define KEYMSG_Q_NUM	1	//按键消息队列的数量
OS_Q KEY_Msg;				//定义一个消息队列，用于按键消息传递，模拟消息邮箱
OS_TMR	tmr1;	//定义一个定时器

//任务函数
void start_task(void *p_arg);






int main(void)
{
  OS_ERR err;
  CPU_SR_ALLOC();
  uint8_t def = 0;
  delay_init();       //延时初始化
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //中断分组配置
  RCC_Config();
  LED_Init();         //LED初始化   
  Pump_IOinit();
  PUMP4_ON();
  PUMP3_OFF();
  PUMP2_OFF();
  PUMP1_OFF();
  LCD_Init();
  FM24C64_Init();             //铁电初始化
  Ds1302_GPIO_Init();
  FM24C64_READ_MUL(DEFAULT,(uint8_t*)&def,1);
  if(def != 0xA5)
  {
    Target_Init();              //实现目标板出厂设置值
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
  WDOG_Init();                //初始化看门狗
  Feed_Dog();                 //进行喂狗
  OSInit(&err);		//初始化UCOSIII
  OS_CRITICAL_ENTER();//进入临界区
  //创建开始任务
  OSTaskCreate((OS_TCB 	* )&StartTaskTCB,		//任务控制块
	       (CPU_CHAR	* )"start task", 		//任务名字
	       (OS_TASK_PTR )start_task, 			//任务函数
	       (void		* )0,					//传递给任务函数的参数
	       (OS_PRIO	  )START_TASK_PRIO,     //任务优先级
	       (CPU_STK   * )&START_TASK_STK[0],	//任务堆栈基地址
	       (CPU_STK_SIZE)START_STK_SIZE/10,	//任务堆栈深度限位
	       (CPU_STK_SIZE)START_STK_SIZE,		//任务堆栈大小
	       (OS_MSG_QTY  )0,					//任务内部消息队列能够接收的最大消息数目,为0时禁止接收消息
	       (OS_TICK	  )0,					//当使能时间片轮转时的时间片长度，为0时为默认长度，
	       (void   	* )0,					//用户补充的存储区
	       (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //任务选项
	       (OS_ERR 	* )&err);				//存放该函数错误时的返回值
  OS_CRITICAL_EXIT();	//退出临界区	 
  OSStart(&err);  //开启UCOSIII
  while(1);
}

//开始任务函数
void start_task(void *p_arg)
{
  OS_ERR err;
  CPU_SR_ALLOC();
  p_arg = p_arg;
  
  CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
  OSStatTaskCPUUsageInit(&err);  	//统计任务                
#endif
  
#ifdef CPU_CFG_INT_DIS_MEAS_EN		//如果使能了测量中断关闭时间
  CPU_IntDisMeasMaxCurReset();	
#endif
  
#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //当使用时间片轮转的时候
  //使能时间片轮转调度功能,时间片长度为1个系统时钟节拍，既1*5=5ms
  OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif		
  
  OS_CRITICAL_ENTER();	//进入临界区
  
  //创建消息队列KEY_Msg
  OSQCreate ((OS_Q*		)&KEY_Msg,	//消息队列
	     (CPU_CHAR*	)"KEY Msg",	//消息队列名称
	     (OS_MSG_QTY	)KEYMSG_Q_NUM,	//消息队列长度，这里设置为1
	     (OS_ERR*	)&err);		//错误码
  //创建定时器1
  OSTmrCreate((OS_TMR		*)&tmr1,		//定时器1
	      (CPU_CHAR	*)"tmr1",		//定时器名字
	      (OS_TICK	 )0,			//0ms
	      (OS_TICK	 )3000,          //3000*10=30000ms
	      (OS_OPT		 )OS_OPT_TMR_PERIODIC, //周期模式
	      (OS_TMR_CALLBACK_PTR)tmr1_callback,//定时器1回调函数
	      (void	    *)0,			//参数为0
	      (OS_ERR	    *)&err);		//返回的错误码
  //创建LED0任务
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
  OS_TaskSuspend((OS_TCB*)&StartTaskTCB,&err);		//挂起开始任务			 
  OS_CRITICAL_EXIT();	//进入临界区
}



//定时器1的回调函数
void tmr1_callback(void *p_tmr,void *p_arg)
{

	CLR_LCD_LED();
	
	
}