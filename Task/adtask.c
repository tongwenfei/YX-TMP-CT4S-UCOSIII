 /*
 *CopyRight Reserved:	宇星科技
 *Filename：		adtask.c
 *Description：     	AD采集任务         
 *Date:
 *Author:				
*/

#include "include.h"





//#define FULLVAL 4096	//满量程值
//#define REFVOF 2.5		//参考值
////#define RES		10000	//电阻值
////#define PT1000	3.85	
////#define PHT25	0.0245
//
//static uint16_t AdValue[ADVALUE_CNT]={0};
//static float Vol_Value[ADCHANAL];
////static float Vol_ValueTmp[ADCHANAL][ADVALUE_CNT];
////static float Met_Value[1];
////static float Met_TValue[1]; 
////static uint8_t ValueCnt;
//
//void AD_ValueManage(void)
//{
//	uint8_t i,j,channel;
//	uint16_t tmp,data;
//	float averageval=0;
//	float Val;
////	float a1,a2,a3,a4; 
////	float b1,b2,b3,b4;
////	float vol0,vol1,vol2,vol3;
////        float add_a,add_b;
//        
//       
//	for(channel=0;i<ADCHANAL;channel++)		//排序
//	{
//	//对每个通道的30个数字量从小到大的排序
//            for (i=0;i<ADVALUE_CNT;i++)
//            {
//                AD7923_W_REG(channel);
//                data = AD7923_R_REG();
//                AdValue[i] = data;
//                OSTimeDly(2);
//                AdValue[i]&=0x0FFF;
//            }
//            for(i=0;i<ADVALUE_CNT;i++)
//            {
//              for(j=1;j<ADVALUE_CNT-1;j++)
//              {
//                if(AdValue[j]>AdValue[j+1])
//                {
//                  tmp=AdValue[j];
//                  AdValue[j]=AdValue[j+1];
//                  AdValue[j+1]=tmp;
//                }
//              }
//            }
//            for(i=0;i<ADVALUE_CNT/3;i++)
//            {
//              averageval+=AdValue[i+(ADVALUE_CNT/3)];
//            }
//            averageval/=(ADVALUE_CNT/3.0);
//            averageval/=FULLVAL;
//            averageval*=REFVOF;
//            Vol_Value[channel]=averageval;
//            averageval=0;
//            
//            
//	}
//
//      //  发送邮箱电压值Vol_Value模拟量值
//        if(Raw_Flag == 1)
//        {
//            OSMboxPost(Vol_ValueMbox, Vol_Value);
//            Raw_Flag = 0;
//        }
//	Val = Vol_Value[0]*1000;
//	
//}
void ADTask(void*pdata)
{
    pdata=pdata;
    while(1)
    {	
       
       OSTimeDly(100);/*挂起1000ms*/
    }
}

void CreateADTask(void)
{
    uint8_t  err;

    err =
    OSTaskCreateExt(  ADTask,
                      (void *)0,
                      &ADTaskStk[TASK_AD_STK_SIZE-1],
                      ADTaskPrio,
                      'a',
                      &ADTaskStk[0],
                      TASK_AD_STK_SIZE,
                      (void *)0,
                      OS_TASK_OPT_STK_CHK+OS_TASK_OPT_STK_CLR);

    while (err != OS_NO_ERR);
}






















