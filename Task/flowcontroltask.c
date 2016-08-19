/*
*********************************************************************************************************
*                                               
* File        : FlowControlTask.c
* By          : Wenfei Tong
* Version     : V1.0
* Date        : 03-08-2016
* Description :
* ---------------
*   温度控制任务函数,温度范围(15℃~30℃)由PWM控制
*********************************************************************************************************
*/
#include "include.h"

//任务控制块
OS_TCB FlowControlTaskTCB;
//任务堆栈	
CPU_STK FLOWCONTROL_TASK_STK[FLOWCONTROL_STK_SIZE];
//任务函数
void FlowControlTask(void *pdata);


void FlowControlTask(void *pdata)
{
  OS_ERR err;
  pdata=pdata;
  
  //FlowPID_struct[0].SetPoint=0.9;
  while(1)
  {
    //    uint16_t test[30]={0};
    //    FlowPID_struct[0].Value=(Get_AverageValue(test,2)-0X2000)*0.0012255859375;
    //    FlowPID_struct[0].Value=Filter()*0.0012255859375;
    if((FlowPID_struct[0].Value>4.915)&&(FlowPID_struct[0].Value<=4.94))
      FlowPID_struct[0].Flow_Value = (38289.43695978339*pow(FlowPID_struct[0].Value,2)-375397.2397233210*FlowPID_struct[0].Value+921060.4041674514);
    else if((FlowPID_struct[0].Value>4.832)&&(FlowPID_struct[0].Value<=4.915))
      FlowPID_struct[0].Flow_Value = (-138164.4782931292*pow(FlowPID_struct[0].Value,3)+2021812.446291739*pow(FlowPID_struct[0].Value,2)-9860696.264736360*FlowPID_struct[0].Value+16029543.10844155);
    else if((FlowPID_struct[0].Value>4.73)&&(FlowPID_struct[0].Value<=4.832))
      FlowPID_struct[0].Flow_Value =( 17325.51716526674*pow(FlowPID_struct[0].Value,3)-244291.0671146709*pow(FlowPID_struct[0].Value,2)+1148615.582939287*FlowPID_struct[0].Value-1800124.696902751);
    else if((FlowPID_struct[0].Value>4.496)&&(FlowPID_struct[0].Value<=4.73))
      FlowPID_struct[0].Flow_Value =(652.1107036428587*pow(FlowPID_struct[0].Value,2)-5568.136041032466*FlowPID_struct[0].Value+12526.50639682489);
    else if((FlowPID_struct[0].Value>4.205)&&(FlowPID_struct[0].Value<=4.496))
      FlowPID_struct[0].Flow_Value =(156.3761061422076*pow(FlowPID_struct[0].Value,2)-1012.317980007233*FlowPID_struct[0].Value+2064.308272887827);
    else if((FlowPID_struct[0].Value>3.931)&&(FlowPID_struct[0].Value<=4.205))
      FlowPID_struct[0].Flow_Value =(107.3551802146552*pow(FlowPID_struct[0].Value,2)-612.5647074520942*FlowPID_struct[0].Value+1249.559576404703);
    //    if(FlowPID_struct[0].Value>3.9)
    //      FlowPID_struct[0].Flow_Value = 685.0583472335688*pow(FlowPID_struct[0].Value,3)-8748.443977280202*pow(FlowPID_struct[0].Value,2)+37485.35818681649*FlowPID_struct[0].Value-53290.98286582800;
    //FlowPID_struct[0].Flow_Value = 735.3239025222749*pow(FlowPID_struct[0].Value,3)-9523.253738516354*pow(FlowPID_struct[0].Value,2)+41358.26026963404*FlowPID_struct[0].Value-59600.49812224984;
    else
      FlowPID_struct[0].Flow_Value=-12.808801571473056*pow(FlowPID_struct[0].Value,3)+148.0938925902762*pow(FlowPID_struct[0].Value,2)-303.5480580298680*FlowPID_struct[0].Value+174.7906656438154;
    //    if(FlowPID_struct[0].Value>4.18)
    //   FlowPID_struct[0].Flow_Value = 716.7709*FlowPID_struct[0].Value*FlowPID_struct[0].Value*FlowPID_struct[0].Value-9373.1*FlowPID_struct[0].Value*FlowPID_struct[0].Value+41236*FlowPID_struct[0].Value-60442;
    //    else
    //      FlowPID_struct[0].Flow_Value=0.4921*FlowPID_struct[0].Value*FlowPID_struct[0].Value*FlowPID_struct[0].Value+39.8796*FlowPID_struct[0].Value*FlowPID_struct[0].Value-60.2861*FlowPID_struct[0].Value+20.0716;
    if((FlowPID_struct[0].Flow_Value>(FlowPID_struct[0].SetPoint*1000+5))||(FlowPID_struct[0].Flow_Value<(FlowPID_struct[0].SetPoint*1000-5)))
      FlowPID_struct[0].Clac_Value= Flow_PID_Calculation(&FlowPID_struct[0],FlowPID_struct[0].Flow_Value/1000);
    
    //    if(num<10)num++;
    //    else num=10;
    //    if(num==6)
    //    {
    //    test_vaule=500;
    //    if(test_vaule>680)
    //  pwm_temp=test_vaule*test_vaule*3.7052/10000-test_vaule*0.4127+584.6853;
    //  else pwm_temp=test_vaule*test_vaule*test_vaule*1.6854/10000000-test_vaule*test_vaule*1.3724/10000+test_vaule*0.0857+430.0270;
    ////  if(test_vaule>680)
    ////  pwm_temp=test_vaule*test_vaule*4.9866/10000-test_vaule*0.6069+658.6567;
    ////  else pwm_temp=test_vaule*test_vaule*3.3204/100000+test_vaule*0.0308+437.4598;
    //    TIM_SetCompare1(TIM3,pwm_temp);
    //    }
    
    //    if(key_vaule==1)
    //    {
    //    if(test_vaule<1000)
    //    test_vaule+=100;
    //    }
    //    if(key_vaule==2)
    //    {
    //      if(test_vaule>100)
    //      test_vaule-=100;
    //    }    
    //    
    //     if(test_vaule>680)
    //  pwm_temp=test_vaule*test_vaule*3.7052/10000-test_vaule*0.4127+584.6853;
    //  else pwm_temp=test_vaule*test_vaule*test_vaule*1.6854/10000000-test_vaule*test_vaule*1.3724/10000+test_vaule*0.0857+430.0270;
    //  TIM_SetCompare1(TIM3,pwm_temp);
    //    if(key_vaule==1)
    //    {
    //    if(FlowPID_struct[0].SetPoint<1)
    //    FlowPID_struct[0].SetPoint+=0.1;
    //    }
    //    if(key_vaule==2)
    //    {
    //      if(FlowPID_struct[0].SetPoint>0.1)
    //      FlowPID_struct[0].SetPoint-=0.1;
    //    }
    
    TIM_SetCompare4(TIM3,(uint16_t)(300+200*FlowPID_struct[0].Clac_Value));
    
    
    
    OSTimeDlyHMSM(0,0,0,500,OS_OPT_TIME_HMSM_STRICT,&err); //延时500ms
  }
}

void CreateFlowControlTask(void)
{
  OS_ERR err;
  OSTaskCreate((OS_TCB 	  *)&FlowControlTaskTCB,		//任务控制块
	       (CPU_CHAR  *)"FlowControl Task", 		//任务名字
	       (OS_TASK_PTR)FlowControlTask, 			//任务函数
	       (void      *)0,					//传递给任务函数的参数
	       (OS_PRIO     )FLOWCONTROL_TASK_PRIO,     //任务优先级
	       (CPU_STK   * )&FLOWCONTROL_TASK_STK[0],	//任务堆栈基地址
	       (CPU_STK_SIZE)FLOWCONTROL_STK_SIZE/10,	//任务堆栈深度限位
	       (CPU_STK_SIZE)FLOWCONTROL_STK_SIZE,		//任务堆栈大小
	       (OS_MSG_QTY  )0,					//任务内部消息队列能够接收的最大消息数目,为0时禁止接收消息
	       (OS_TICK	    )0,					//当使能时间片轮转时的时间片长度，为0时为默认长度，
	       (void      *)0,					//用户补充的存储区
	       (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //任务选项
	       (OS_ERR     *)&err);	
}