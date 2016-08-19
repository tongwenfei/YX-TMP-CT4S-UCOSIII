
/*******************************************************************************
 *CopyRight Reserved:	         universtar S&T 
 *Filename：			  ads1248.c
 *Description：     	         ads1248驱动
 *Date:
 *Author:		        
*******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "ads1248.h"
#include "include.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

#define ADS1248_CS_PORT		GPIOD // GPIOE	 //片选脚所在端口     // GPIOD
#define ADS1248_RST_PORT	GPIOD // GPIOA  //其它脚所在端口      // GPIOD
#define ADS1248_DRDY_PORT	GPIOB // GPIOE   	              // GPIOB
#define ADS1248_START_PORT      GPIOD // GPIOE	                      // GPIOD
#define ADS1248_DO_PORT		GPIOB // GPIOE	                      // GPIOB
#define ADS1248_SCK_PORT        GPIOE // GPIOE                        // GPIOE
#define ADS1248_DIN_PORT        GPIOE // GPIOE	                      // GPIOE


#define ADS1248_SCK		GPIO_Pin_14	//GPIO_Pin_8             //     GPIO_Pin_14
#define ADS1248_DO		GPIO_Pin_10	//GPIO_Pin_10            //     GPIO_Pin_10
#define ADS1248_DIN		GPIO_Pin_15	//GPIO_Pin_9             //     GPIO_Pin_15

#define ADS1248_RST		GPIO_Pin_9	//GPIO_Pin_1             //     GPIO_Pin_9
#define ADS1248_START	        GPIO_Pin_10     //GPIO_Pin_13            //     GPIO_Pin_10
#define ADS1248_CS		GPIO_Pin_11	//GPIO_Pin_12            //     GPIO_Pin_11
#define ADS1248_READY		GPIO_Pin_11     //GPIO_Pin_11            //     GPIO_Pin_11

#define RCC_APB2Periph_ADS1248_CS_PORT		RCC_APB2Periph_GPIOD         //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOD
#define RCC_APB2Periph_ADS1248_RST_PORT		RCC_APB2Periph_GPIOD	     //RCC_APB2Periph_GPIOA             //  RCC_APB2Periph_GPIOD
#define RCC_APB2Periph_ADS1248_DRDY_PORT        RCC_APB2Periph_GPIOB        //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOB
#define RCC_APB2Periph_ADS1248_PORT		RCC_APB2Periph_GPIOE        //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOE
#define RCC_APB2Periph_ADS1248_SCK_PORT		RCC_APB2Periph_GPIOE        //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOE

#define ADS1248_CS_H()			ADS1248_CS_PORT->BSRR = ADS1248_CS
#define ADS1248_CS_L()			ADS1248_CS_PORT->BRR = ADS1248_CS

#define ADS1248_SCK_H()                 ADS1248_SCK_PORT->BSRR = ADS1248_SCK
#define ADS1248_SCK_L()                 ADS1248_SCK_PORT->BRR = ADS1248_SCK

#define ADS1248_MOSI_H()                ADS1248_DIN_PORT->BSRR = ADS1248_DIN
#define ADS1248_MOSI_L()                ADS1248_DIN_PORT->BRR = ADS1248_DIN


#define ADS1248_RST_H()			ADS1248_RST_PORT->BSRR = ADS1248_RST
#define ADS1248_RST_L()			ADS1248_RST_PORT->BRR = ADS1248_RST

#define ADS1248_START_H()	        ADS1248_START_PORT->BSRR = ADS1248_START
#define ADS1248_START_L()	        ADS1248_START_PORT->BRR = ADS1248_START

#define ADS1248_READY_PIN()		 GPIO_ReadInputDataBit(ADS1248_DRDY_PORT, ADS1248_READY)           //低电平表示READY

#define ADS1248_DO_PIN()                GPIO_ReadInputDataBit(ADS1248_DO_PORT, ADS1248_DO)  // ADS1248_PORT->IDR & ADS1248_DO




#define ADS1248_2_CS_PORT		GPIOE // GPIOE	 //片选脚所在端口     // GPIOD
#define ADS1248_2_RST_PORT	GPIOA // GPIOA  //其它脚所在端口      // GPIOD
#define ADS1248_2_DRDY_PORT	GPIOE // GPIOE   	              // GPIOB
#define ADS1248_2_START_PORT      GPIOE // GPIOE	                      // GPIOD
#define ADS1248_2_DO_PORT		GPIOE // GPIOE	                      // GPIOB
#define ADS1248_2_SCK_PORT        GPIOE // GPIOE                        // GPIOE
#define ADS1248_2_DIN_PORT        GPIOE // GPIOE	                      // GPIOE


#define ADS1248_2_SCK		GPIO_Pin_8	//GPIO_Pin_8             //     GPIO_Pin_14
#define ADS1248_2_DO		GPIO_Pin_10	//GPIO_Pin_10            //     GPIO_Pin_10
#define ADS1248_2_DIN		GPIO_Pin_9	//GPIO_Pin_9             //     GPIO_Pin_15

#define ADS1248_2_RST		GPIO_Pin_1	//GPIO_Pin_1             //     GPIO_Pin_9
#define ADS1248_2_START	        GPIO_Pin_13     //GPIO_Pin_13            //     GPIO_Pin_10
#define ADS1248_2_CS		GPIO_Pin_12	//GPIO_Pin_12            //     GPIO_Pin_11
#define ADS1248_2_READY		GPIO_Pin_11     //GPIO_Pin_11            //     GPIO_Pin_11

#define RCC_APB2Periph_ADS1248_2_CS_PORT		RCC_APB2Periph_GPIOE         //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOD
#define RCC_APB2Periph_ADS1248_2_RST_PORT		RCC_APB2Periph_GPIOA	     //RCC_APB2Periph_GPIOA             //  RCC_APB2Periph_GPIOD
#define RCC_APB2Periph_ADS1248_2_DRDY_PORT        RCC_APB2Periph_GPIOE        //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOB
#define RCC_APB2Periph_ADS1248_2_PORT		RCC_APB2Periph_GPIOE        //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOE
#define RCC_APB2Periph_ADS1248_2_SCK_PORT		RCC_APB2Periph_GPIOE        //RCC_APB2Periph_GPIOE             //  RCC_APB2Periph_GPIOE


#define ADS1248_2_CS_H()			ADS1248_2_CS_PORT->BSRR = ADS1248_2_CS
#define ADS1248_2_CS_L()			ADS1248_2_CS_PORT->BRR = ADS1248_2_CS

#define ADS1248_2_SCK_H()                 ADS1248_2_SCK_PORT->BSRR = ADS1248_2_SCK
#define ADS1248_2_SCK_L()                 ADS1248_2_SCK_PORT->BRR = ADS1248_2_SCK

#define ADS1248_2_MOSI_H()                ADS1248_2_DIN_PORT->BSRR = ADS1248_2_DIN
#define ADS1248_2_MOSI_L()                ADS1248_2_DIN_PORT->BRR = ADS1248_2_DIN


#define ADS1248_2_RST_H()			ADS1248_2_RST_PORT->BSRR = ADS1248_2_RST
#define ADS1248_2_RST_L()			ADS1248_2_RST_PORT->BRR = ADS1248_2_RST

#define ADS1248_2_START_H()	        ADS1248_2_START_PORT->BSRR = ADS1248_2_START
#define ADS1248_2_START_L()	        ADS1248_2_START_PORT->BRR = ADS1248_2_START

#define ADS1248_2_READY_PIN()		 GPIO_ReadInputDataBit(ADS1248_2_DRDY_PORT, ADS1248_2_READY)           //低电平表示READY

#define ADS1248_2_DO_PIN()                GPIO_ReadInputDataBit(ADS1248_2_DO_PORT, ADS1248_2_DO)  // ADS1248_2_PORT->IDR & ADS1248_2_DO


/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
const float pt100_table[1001] =                                                   //PT100 0-100度对应的电阻值，0.1度间隔
{
    100.0000, 100.0391, 100.0782, 100.1172, 100.1563, 100.1954, 100.2345, 100.2736, 100.3126, 100.3517,
    100.3908, 100.4298, 100.4689, 100.5080, 100.5470, 100.5861, 100.6252, 100.6642, 100.7033, 100.7424,
    100.7814, 100.8205, 100.8595, 100.8986, 100.9377, 100.9767, 101.0158, 101.0548, 101.0939, 101.1329,
    101.1720, 101.2110, 101.2501, 101.2891, 101.3282, 101.3672, 101.4062, 101.4453, 101.4843, 101.5234,
    101.5624, 101.6014, 101.6405, 101.6795, 101.7185, 101.7576, 101.7966, 101.8356, 101.8747, 101.9137,
    101.9527, 101.9917, 102.0308, 102.0698, 102.1088, 102.1478, 102.1868, 102.2259, 102.2649, 102.3039,
    102.3429, 102.3819, 102.4209, 102.4599, 102.4989, 102.5380, 102.5770, 102.6160, 102.6550, 102.6940,
    102.7330, 102.7720, 102.8110, 102.8500, 102.8890, 102.9280, 102.9670, 103.0060, 103.0450, 103.0840,
    103.1229, 103.1619, 103.2009, 103.2399, 103.2789, 103.3179, 103.3569, 103.3958, 103.4348, 103.4738,
    103.5128, 103.5518, 103.5907, 103.6297, 103.6687, 103.7077, 103.7466, 103.7856, 103.8246, 103.8636,
    103.9025, 103.9415, 103.9805, 104.0194, 104.0584, 104.0973, 104.1363, 104.1753, 104.2142, 104.2532,
    104.2921, 104.3311, 104.3701, 104.4090, 104.4480, 104.4869, 104.5259, 104.5648, 104.6038, 104.6427,
    104.6816, 104.7206, 104.7595, 104.7985, 104.8374, 104.8764, 104.9153, 104.9542, 104.9932, 105.0321,
    105.0710, 105.1100, 105.1489, 105.1878, 105.2268, 105.2657, 105.3046, 105.3435, 105.3825, 105.4214,
    105.4603, 105.4992, 105.5381, 105.5771, 105.6160, 105.6549, 105.6938, 105.7327, 105.7716, 105.8105,
    105.8495, 105.8884, 105.9273, 105.9662, 106.0051, 106.0440, 106.0829, 106.1218, 106.1607, 106.1996,
    106.2385, 106.2774, 106.3163, 106.3552, 106.3941, 106.4330, 106.4719, 106.5108, 106.5496, 106.5885,
    106.6274, 106.6663, 106.7052, 106.7441, 106.7830, 106.8218, 106.8607, 106.8996, 106.9385, 106.9774,
    107.0162, 107.0551, 107.0940, 107.1328, 107.1717, 107.2106, 107.2495, 107.2883, 107.3272, 107.3661,
    107.4049, 107.4438, 107.4826, 107.5215, 107.5604, 107.5992, 107.6381, 107.6769, 107.7158, 107.7546,
    107.7935, 107.8324, 107.8712, 107.9101, 107.9489, 107.9877, 108.0266, 108.0654, 108.1043, 108.1431,
    108.1820, 108.2208, 108.2596, 108.2985, 108.3373, 108.3762, 108.4150, 108.4538, 108.4926, 108.5315,
    108.5703, 108.6091, 108.6480, 108.6868, 108.7256, 108.7644, 108.8033, 108.8421, 108.8809, 108.9197,
    108.9585, 108.9974, 109.0362, 109.0750, 109.1138, 109.1526, 109.1914, 109.2302, 109.2690, 109.3078,
    109.3467, 109.3855, 109.4243, 109.4631, 109.5019, 109.5407, 109.5795, 109.6183, 109.6571, 109.6959,
    109.7347, 109.7734, 109.8122, 109.8510, 109.8898, 109.9286, 109.9674, 110.0062, 110.0450, 110.0838,
    110.1225, 110.1613, 110.2001, 110.2389, 110.2777, 110.3164, 110.3552, 110.3940, 110.4328, 110.4715,
    110.5103, 110.5491, 110.5879, 110.6266, 110.6654, 110.7042, 110.7429, 110.7817, 110.8204, 110.8592,
    110.8980, 110.9367, 110.9755, 111.0142, 111.0530, 111.0917, 111.1305, 111.1693, 111.2080, 111.2468,
    111.2855, 111.3242, 111.3630, 111.4017, 111.4405, 111.4792, 111.5180, 111.5567, 111.5954, 111.6342,
    111.6729, 111.7117, 111.7504, 111.7891, 111.8279, 111.8666, 111.9053, 111.9441, 111.9828, 112.0215,
    112.0602, 112.0990, 112.1377, 112.1764, 112.2151, 112.2538, 112.2926, 112.3313, 112.3700, 112.4087,
    112.4474, 112.4861, 112.5248, 112.5636, 112.6023, 112.6410, 112.6797, 112.7184, 112.7571, 112.7958,
    112.8345, 112.8732, 112.9119, 112.9506, 112.9893, 113.0280, 113.0667, 113.1054, 113.1441, 113.1828,
    113.2215, 113.2602, 113.2988, 113.3375, 113.3762, 113.4149, 113.4536, 113.4923, 113.5309, 113.5696,
    113.6083, 113.6470, 113.6857, 113.7243, 113.7630, 113.8017, 113.8404, 113.8790, 113.9177, 113.9564,
    113.9950, 114.0337, 114.0724, 114.1110, 114.1497, 114.1884, 114.2270, 114.2657, 114.3043, 114.3430,
    114.3817, 114.4203, 114.4590, 114.4976, 114.5363, 114.5749, 114.6136, 114.6522, 114.6909, 114.7295,
    114.7681, 114.8068, 114.8454, 114.8841, 114.9227, 114.9614, 115.0000, 115.0386, 115.0773, 115.1159,
    115.1545, 115.1932, 115.2318, 115.2704, 115.3091, 115.3477, 115.3863, 115.4249, 115.4636, 115.5022,
    115.5408, 115.5794, 115.6180, 115.6567, 115.6953, 115.7339, 115.7725, 115.8111, 115.8497, 115.8883,
    115.9270, 115.9656, 116.0042, 116.0428, 116.0814, 116.1200, 116.1586, 116.1972, 116.2358, 116.2744,
    116.3130, 116.3516, 116.3902, 116.4288, 116.4674, 116.5060, 116.5446, 116.5831, 116.6217, 116.6603,
    116.6989, 116.7375, 116.7761, 116.8147, 116.8532, 116.8918, 116.9304, 116.9690, 117.0076, 117.0461,
    117.0847, 117.1233, 117.1619, 117.2004, 117.2390, 117.2776, 117.3161, 117.3547, 117.3933, 117.4318,
    117.4704, 117.5090, 117.5475, 117.5861, 117.6247, 117.6632, 117.7018, 117.7403, 117.7789, 117.8174,
    117.8560, 117.8945, 117.9331, 117.9716, 118.0102, 118.0487, 118.0873, 118.1258, 118.1644, 118.2029,
    118.2414, 118.2800, 118.3185, 118.3571, 118.3956, 118.4341, 118.4727, 118.5112, 118.5497, 118.5883,
    118.6268, 118.6653, 118.7038, 118.7424, 118.7809, 118.8194, 118.8579, 118.8965, 118.9350, 118.9735,
    119.0120, 119.0505, 119.0890, 119.1276, 119.1661, 119.2046, 119.2431, 119.2816, 119.3201, 119.3586,
    119.3971, 119.4356, 119.4741, 119.5126, 119.5511, 119.5896, 119.6281, 119.6666, 119.7051, 119.7436,
    119.7821, 119.8206, 119.8591, 119.8976, 119.9361, 119.9746, 120.0131, 120.0516, 120.0900, 120.1285,
    120.1670, 120.2055, 120.2440, 120.2824, 120.3209, 120.3594, 120.3979, 120.4364, 120.4748, 120.5133,
    120.5518, 120.5902, 120.6287, 120.6672, 120.7056, 120.7441, 120.7826, 120.8210, 120.8595, 120.8980,
    120.9364, 120.9749, 121.0133, 121.0518, 121.0902, 121.1287, 121.1672, 121.2056, 121.2441, 121.2825,
    121.3210, 121.3594, 121.3978, 121.4363, 121.4747, 121.5132, 121.5516, 121.5901, 121.6285, 121.6669,
    121.7054, 121.7438, 121.7822, 121.8207, 121.8591, 121.8975, 121.9360, 121.9744, 122.0128, 122.0513,
    122.0897, 122.1281, 122.1665, 122.2049, 122.2434, 122.2818, 122.3202, 122.3586, 122.3970, 122.4355,
    122.4739, 122.5123, 122.5507, 122.5891, 122.6275, 122.6659, 122.7043, 122.7427, 122.7811, 122.8195,
    122.8579, 122.8963, 122.9347, 122.9731, 123.0115, 123.0499, 123.0883, 123.1267, 123.1651, 123.2035,
    123.2419, 123.2803, 123.3187, 123.3571, 123.3955, 123.4338, 123.4722, 123.5106, 123.5490, 123.5874,
    123.6257, 123.6641, 123.7025, 123.7409, 123.7792, 123.8176, 123.8560, 123.8944, 123.9327, 123.9711,
    124.0095, 124.0478, 124.0862, 124.1246, 124.1629, 124.2013, 124.2396, 124.2780, 124.3164, 124.3547,
    124.3931, 124.4314, 124.4698, 124.5081, 124.5465, 124.5848, 124.6232, 124.6615, 124.6999, 124.7382,
    124.7766, 124.8149, 124.8533, 124.8916, 124.9299, 124.9683, 125.0066, 125.0450, 125.0833, 125.1216,
    125.1600, 125.1983, 125.2366, 125.2749, 125.3133, 125.3516, 125.3899, 125.4283, 125.4666, 125.5049,
    125.5432, 125.5815, 125.6199, 125.6582, 125.6965, 125.7348, 125.7731, 125.8114, 125.8497, 125.8881,
    125.9264, 125.9647, 126.0030, 126.0413, 126.0796, 126.1179, 126.1562, 126.1945, 126.2328, 126.2711,
    126.3094, 126.3477, 126.3860, 126.4243, 126.4626, 126.5009, 126.5392, 126.5775, 126.6157, 126.6540,
    126.6923, 126.7306, 126.7689, 126.8072, 126.8455, 126.8837, 126.9220, 126.9603, 126.9986, 127.0368,
    127.0751, 127.1134, 127.1517, 127.1899, 127.2282, 127.2665, 127.3048, 127.3430, 127.3813, 127.4195,
    127.4578, 127.4961, 127.5343, 127.5726, 127.6109, 127.6491, 127.6874, 127.7256, 127.7639, 127.8021,
    127.8404, 127.8786, 127.9169, 127.9551, 127.9934, 128.0316, 128.0699, 128.1081, 128.1464, 128.1846,
    128.2228, 128.2611, 128.2993, 128.3376, 128.3758, 128.4140, 128.4523, 128.4905, 128.5287, 128.5670,
    128.6052, 128.6434, 128.6816, 128.7199, 128.7581, 128.7963, 128.8345, 128.8728, 128.9110, 128.9492,
    128.9874, 129.0256, 129.0638, 129.1021, 129.1403, 129.1785, 129.2167, 129.2549, 129.2931, 129.3313,
    129.3695, 129.4077, 129.4459, 129.4841, 129.5223, 129.5605, 129.5987, 129.6369, 129.6751, 129.7133,
    129.7515, 129.7897, 129.8279, 129.8661, 129.9043, 129.9425, 129.9807, 130.0188, 130.0570, 130.0952,
    130.1334, 130.1716, 130.2098, 130.2479, 130.2861, 130.3243, 130.3625, 130.4006, 130.4388, 130.4770,
    130.5152, 130.5533, 130.5915, 130.6297, 130.6678, 130.7060, 130.7442, 130.7823, 130.8205, 130.8586,
    130.8968, 130.9350, 130.9731, 131.0113, 131.0494, 131.0876, 131.1257, 131.1639, 131.2020, 131.2402,
    131.2783, 131.3165, 131.3546, 131.3928, 131.4309, 131.4691, 131.5072, 131.5453, 131.5835, 131.6216,
    131.6597, 131.6979, 131.7360, 131.7742, 131.8123, 131.8504, 131.8885, 131.9267, 131.9648, 132.0029,
    132.0411, 132.0792, 132.1173, 132.1554, 132.1935, 132.2317, 132.2698, 132.3079, 132.3460, 132.3841,
    132.4222, 132.4603, 132.4985, 132.5366, 132.5747, 132.6128, 132.6509, 132.6890, 132.7271, 132.7652,
    132.8033, 132.8414, 132.8795, 132.9176, 132.9557, 132.9938, 133.0319, 133.0700, 133.1081, 133.1462,
    133.1843, 133.2224, 133.2604, 133.2985, 133.3366, 133.3747, 133.4128, 133.4509, 133.4889, 133.5270,
    133.5651, 133.6032, 133.6413, 133.6793, 133.7174, 133.7555, 133.7935, 133.8316, 133.8697, 133.9078,
    133.9458, 133.9839, 134.0220, 134.0600, 134.0981, 134.1361, 134.1742, 134.2123, 134.2503, 134.2884,
    134.3264, 134.3645, 134.4025, 134.4406, 134.4786, 134.5167, 134.5547, 134.5928, 134.6308, 134.6689,
    134.7069, 134.7450, 134.7830, 134.8211, 134.8591, 134.8971, 134.9352, 134.9732, 135.0112, 135.0493,
    135.0873, 135.1253, 135.1634, 135.2014, 135.2394, 135.2774, 135.3155, 135.3535, 135.3915, 135.4295,
    135.4676, 135.5056, 135.5436, 135.5816, 135.6196, 135.6577, 135.6957, 135.7337, 135.7717, 135.8097,
    135.8477, 135.8857, 135.9237, 135.9617, 135.9997, 136.0377, 136.0757, 136.1137, 136.1517, 136.1897,
    136.2277, 136.2657, 136.3037, 136.3417, 136.3797, 136.4177, 136.4557, 136.4937, 136.5317, 136.5697,
    136.6077, 136.6456, 136.6836, 136.7216, 136.7596, 136.7976, 136.8355, 136.8735, 136.9115, 136.9495,
    136.9875, 137.0254, 137.0634, 137.1014, 137.1393, 137.1773, 137.2153, 137.2532, 137.2912, 137.3292,
    137.3671, 137.4051, 137.4431, 137.4810, 137.5190, 137.5569, 137.5949, 137.6329, 137.6708, 137.7088,
    137.7467, 137.7847, 137.8226, 137.8606, 137.8985, 137.9365, 137.9744, 138.0123, 138.0503, 138.0882,
    138.1262, 138.1641, 138.2020, 138.2400, 138.2779, 138.3158, 138.3538, 138.3917, 138.4296, 138.4676,
    138.5055
};





/*const float pt100_table[301] =        //0 - 300 ^C, 1度间隔 
 { 
    100.00, 100.39, 100.78, 101.17, 101.56, 101.95, 102.34, 102.73, 103.12, 103.51,
    103.90, 104.29, 104.68, 105.07, 105.46, 105.85, 106.24, 106.63, 107.02, 107.40,
    107.79, 108.18, 108.57, 108.96, 109.35, 109.73, 110.12, 110.51, 110.90, 111.28,
    111.67, 112.06, 112.45, 112.83, 113.22, 113.61, 113.99, 114.38, 114.77, 115.15,
    115.54, 115.93, 116.31, 116.70, 117.08, 117.47, 117.85, 118.24, 118.62, 119.01,
    119.40, 119.78, 120.16, 120.55, 120.93, 121.32, 121.70, 122.09, 122.47, 122.86,
    123.24, 123.62, 124.01, 124.39, 124.77, 125.16, 125.54, 125.92, 126.31, 126.69,
    127.07, 127.45, 127.84, 128.22, 128.60, 128.98, 129.37, 129.75, 130.13, 130.51,
    130.89, 131.27, 131.66, 132.04, 132.42, 132.80, 133.18, 133.56, 133.94, 134.32,
    134.70, 135.08, 135.46, 135.84, 136.22, 136.60, 136.98, 137.36, 137.74, 138.12,
    138.50, 138.88, 139.26, 139.64, 140.02, 140.39, 140.77, 141.15, 141.53, 141.91,
    142.29, 142.66, 143.04, 143.42, 143.80, 144.17, 144.55, 144.93, 145.31, 145.68,
    146.06, 146.44, 146.81, 147.19, 147.57, 147.94, 148.32, 148.70, 149.07, 149.45,
    149.82, 150.20, 150.57, 150.95, 151.33, 151.70, 152.08, 152.45, 152.83, 153.20,
    153.58, 153.95, 154.32, 154.70, 155.07, 155.45, 155.82, 156.19, 156.57, 156.94,
    157.31, 157.69, 158.06, 158.43, 158.81, 159.18, 159.55, 159.93, 160.30, 160.67,
    161.04, 161.42, 161.79, 162.16, 162.53, 162.90, 163.27, 163.65, 164.02, 164.39,
    164.76, 165.13, 165.50, 165.87, 166.14, 166.61, 166.98, 167.35, 167.72, 168.09,
    168.46, 168.83, 169.20, 169.57, 169.94, 170.31, 170.68, 171.05, 171.42, 171.79,
    172.16, 172.53, 172.90, 173.26, 173.63, 174.00, 174.37, 174.74, 175.10, 175.47,
    175.84, 176.21, 176.57, 176.94, 177.31, 177.68, 178.04, 178.41, 178.78, 179.14,
    179.51, 179.88, 180.24, 180.61, 180.97, 181.34, 181.71, 182.07, 182.44, 182.80,
    183.17, 183.53, 183.90, 184.26, 184.63, 184.99, 185.36, 185.72, 186.09, 186.45,
    186.82, 187.18, 187.54, 187.91, 188.27, 188.63, 189.00, 189.36, 189.72, 190.09,
    190.45, 190.81, 191.18, 191.54, 191.90, 192.26, 192.63, 192.99, 193.35, 193.71,
    194.07, 194.44, 194.80, 195.16, 195.52, 195.88, 196.24, 196.60, 196.96, 197.33,
    197.69, 198.05, 198.41, 198.77, 199.13, 199.49, 199.85, 200.21, 200.57, 200.93,
    201.29, 201.65, 202.01, 202.36, 202.72, 203.08, 203.44, 203.80, 204.16, 204.52,
    204.88, 205.23, 205.59, 205.95, 206.31, 206.67, 207.02, 207.38, 207.74, 208.10,
    208.45, 208.81, 209.17, 209.52, 209.88, 210.24, 210.59, 210.95, 211.31, 211.66,
    212.02
 };
*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* @Function Name: ADS1248_Init
* @Description  : ADS1248初始化
* @param		: void
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_Init(void)
{
    ADS1248_Config(); // 配置SPI,GPIO和RCC

    ADS1248_RST_L();
    ADS1248_START_L();
    ADS1248_Delay(4000);
    ADS1248_RST_H();
    ADS1248_START_H(); 
    ADS1248_Delay(20000);
    ADS1248_CS_L();

    /********                            *************************************/
    /*    检测传感器完毕，取消Burnout Current，       设置外部REF1为参考源   */
    /************************************************************************/
    
    ADS1248_SetBurnoutCurrentAndInputChannel(CURRENT_OFF, P_AIN0, N_AIN1);	                //关闭检测电流,设置传感器通道1
    ADS1248_SetPGAGainAndDataRate(PGAGain_4, DataRate_2000);					// 设置PGA倍数和传输速率
    ADS1248_SetReference(REF_Inter_AlwaysOn, SELT_REF1);					// 设置外部REF1为参考源,内部基准打开电流源才会生效
	 	
    ADS1248_Delay(10000);													                 // 等待基准源稳定
    ADS1248_SetIDAC(IDAC1_IEXT1, IDAC2_IEXT2, IMAG_1500);				         // 设置电流源为1.5mA	

    ADS1248_START_L(); 
    
     ADS1248_2_START_L();
    ADS1248_2_Delay(4000);
    ADS1248_2_RST_H();
    ADS1248_2_START_H(); 
    ADS1248_2_Delay(20000);
    ADS1248_2_CS_L();

    /********                            *************************************/
    /*    检测传感器完毕，取消Burnout Current，       设置外部REF1为参考源   */
    /************************************************************************/
    
    ADS1248_2_SetBurnoutCurrentAndInputChannel(CURRENT_OFF, P_AIN0, N_AIN1);	                //关闭检测电流,设置传感器通道1
    ADS1248_2_SetPGAGainAndDataRate(PGAGain_4, DataRate_2000);					// 设置PGA倍数和传输速率
    ADS1248_2_SetReference(REF_Inter_AlwaysOn, SELT_REF1);					// 设置外部REF1为参考源,内部基准打开电流源才会生效
	 	
    ADS1248_2_Delay(10000);													                 // 等待基准源稳定
    ADS1248_2_SetIDAC(IDAC1_IEXT1, IDAC2_IEXT2, IMAG_1500);				         // 设置电流源为1.5mA	

    ADS1248_2_START_L(); 
          
}

/*******************************************************************************
* @Function Name: ADS1248_Config
* @Description  : SPI和GPIO初始化
* @param		: void
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_Config(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;
	
    /* Configure SPI pins: SCK,and MOSI */
    GPIO_InitStructure.GPIO_Pin = ADS1248_SCK ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADS1248_SCK_PORT, &GPIO_InitStructure);	
    
    GPIO_InitStructure.GPIO_Pin = ADS1248_DIN ;
    GPIO_Init(ADS1248_DIN_PORT, &GPIO_InitStructure);
    
     /* Configure ADS1248 Control Pins:, START */
    GPIO_InitStructure.GPIO_Pin = ADS1248_RST ;
    GPIO_Init(ADS1248_RST_PORT, &GPIO_InitStructure);
    
    /* Configure ADS1248 Control Pins: START */
       GPIO_InitStructure.GPIO_Pin = ADS1248_START;
    GPIO_Init(ADS1248_START_PORT, &GPIO_InitStructure);

    /* Configure I/O for ADS1248 Chip select */
    GPIO_InitStructure.GPIO_Pin = ADS1248_CS;
    GPIO_Init(ADS1248_CS_PORT, &GPIO_InitStructure);
	
     /* Configure SPI pins: MISO */
 	  GPIO_InitStructure.GPIO_Pin = ADS1248_DO  ;
 	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 	  GPIO_Init(ADS1248_DO_PORT, &GPIO_InitStructure);

    /* Configure ADS1248 Status Pins: READY */
    GPIO_InitStructure.GPIO_Pin =  ADS1248_READY;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(ADS1248_DRDY_PORT, &GPIO_InitStructure);

    /* Deselect the FLASH: Chip Select high */
      ADS1248_CS_H(); 
      
      
      
        GPIO_InitStructure.GPIO_Pin = ADS1248_2_SCK ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADS1248_2_SCK_PORT, &GPIO_InitStructure);	
    
    GPIO_InitStructure.GPIO_Pin = ADS1248_2_DIN ;
    GPIO_Init(ADS1248_2_DIN_PORT, &GPIO_InitStructure);
    
     /* Configure ADS1248_2 Control Pins:, START */
    GPIO_InitStructure.GPIO_Pin = ADS1248_2_RST ;
    GPIO_Init(ADS1248_2_RST_PORT, &GPIO_InitStructure);
    
    /* Configure ADS1248_2 Control Pins: START */
       GPIO_InitStructure.GPIO_Pin = ADS1248_2_START;
    GPIO_Init(ADS1248_2_START_PORT, &GPIO_InitStructure);

    /* Configure I/O for ADS1248_2 Chip select */
    GPIO_InitStructure.GPIO_Pin = ADS1248_2_CS;
    GPIO_Init(ADS1248_2_CS_PORT, &GPIO_InitStructure);
	
     /* Configure SPI pins: MISO */
 	  GPIO_InitStructure.GPIO_Pin = ADS1248_2_DO  ;
 	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 	  GPIO_Init(ADS1248_2_DO_PORT, &GPIO_InitStructure);

    /* Configure ADS1248_2 Status Pins: READY */
    GPIO_InitStructure.GPIO_Pin =  ADS1248_2_READY;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(ADS1248_2_DRDY_PORT, &GPIO_InitStructure);

    /* Deselect the FLASH: Chip Select high */
      ADS1248_2_CS_H(); 

}

/*******************************************************************************
* @Function Name: ADS1248_ReadByte
* @Description  : Reads a byte from the SPI Device
* @param		: void
* @retval	   	: u8 Byte Read from the SPI Device
* @date		   	: 2014/10/04
*******************************************************************************/
u8 ADS1248_ReadByte(void)
{
    return (ADS1248_WriteByte(ADS_NOP));
}

/*******************************************************************************
* @Function Name: ADS1248_WriteByte
* @Description  : Sends a byte through the SPI interface and return the byte received from the SPI bus.
* @param		: u8 data byte to send
* @retval	   	: u8 The value of the received byte
* @date		   	: 2014/10/04
*******************************************************************************/
u8 ADS1248_WriteByte(u8 data)

{
   unsigned char bit_ctr;
   unsigned char temp = 0;
 CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态
    							//进入中断
   for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
   	{
        
        ADS1248_SCK_L();
   	if(data & 0x80)
	 ADS1248_MOSI_H();  // MOSI =1;       
   	else 
	 ADS1248_MOSI_L();  //MOSI=0;
		 
	data = (data << 1);                  // shift next bit into MSB..
		
	ADS1248_SCK_H();    //SCK = 1;                      // Set SCK high..
		
	temp = temp<<1;
	if(ADS1248_DO_PIN())
	  temp++;

	 //data |= ADS1248_DO_PIN() ;       		  // capture current MISO bit	
	ADS1248_SCK_L();     //SCK = 0;            		  // ..then set SCK low again
   	}
   OSIntExit(); //退出临界状态
    return(temp);         

}

/*******************************************************************************
* @Function Name: ADS1248_SetIDAC
* @Description  :
* @param		: u8 idac1
* @param		: u8 idac2
* @param		: u8 idacImage
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_SetIDAC(u8 idac1, u8 idac2, u8 idacImage)
{
    ADS1248_WriteByte(ADS_WREG | ADS_IDAC0);
    ADS1248_WriteByte(0x01);
    ADS1248_WriteByte(idacImage);
    ADS1248_WriteByte(idac1 | idac2);
}

/*******************************************************************************
* @Function Name: ADS1248_SetPGAGainAndDataRate
* @Description  : Set PGA gain and data rate (SPS)
* @param		: u8 pgaGain
* @param		: u8 dataRate
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_SetPGAGainAndDataRate(u8 pgaGain, u8 dataRate)
{
    ADS1248_WriteByte(ADS_WREG | ADS_SYS0);
    ADS1248_WriteByte(0x00);
    ADS1248_WriteByte(pgaGain | dataRate);
}

/*******************************************************************************
* @Function Name: ADS1248_SetBurnoutCurrentAndInputChannel
* @Description  :
* @param		: u8 positiveChannel
* @param		: u8 negativeChannel
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_SetBurnoutCurrentAndInputChannel(u8 burnoutCurrent, u8 positiveChannel, u8 negativeChannel)
{
    ADS1248_WriteByte(ADS_WREG | ADS_MUX0);
    ADS1248_WriteByte(0x00);
    ADS1248_WriteByte(burnoutCurrent | positiveChannel | negativeChannel);
}

/*******************************************************************************
* @Function Name: ADS1248_SetReference
* @Description  :
* @param		: u8 interVrefOnOff
* @param		: u8 refSelected
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_SetReference(u8 interVrefOnOff, u8 refSelected)
{
    ADS1248_WriteByte(ADS_WREG | ADS_MUX1);
    ADS1248_WriteByte(0x00);
    ADS1248_WriteByte(interVrefOnOff | refSelected);
}

/*******************************************************************************
* @Function Name: ADS1248_ReadREG
* @Description  : 读取寄存器的第byteToRead个字节
* @param		: u8 regName
* @param		: u8 byteToRead
* @retval	   	: u8
* @date		   	: 2014/10/05
*******************************************************************************/
u8 ADS1248_ReadREG(u8 regName, u8 byteToRead)
{
    ADS1248_WriteByte(ADS_RREG | regName);

    if(byteToRead == 1)
    {
        ADS1248_WriteByte(0x00);
    }
    else if(byteToRead == 2)
    {
        ADS1248_WriteByte(0x01);
        ADS1248_ReadByte();
    }

    return ADS1248_ReadByte();
}

/*******************************************************************************
* @Function Name: ADS1248_ReadADC
* @Description  : 返回有符号数值
* @param		: void
* @retval	   	: s32
* @date		   	: 2014/10/04
*******************************************************************************/
s32 ADS1248_ReadADC(void)
{
    u8 temp[3];
    s32 adcVal = 0;
    u32 wait_time = 0;
    
    
    wait_time =  300;                                                 //限时等待 防死机
   
    while(ADS1248_READY_PIN() && (wait_time--) )                     //DRDY引脚高电平表示数据没准备好
    {
   		;
           }                                                        
    if(wait_time == 0)                                               //超时报错
     {
           ;
         }

    ADS1248_WriteByte(ADS_RDATA);
    
    							//进入中断                                            /* 读取数据期间禁止任务调度     */
    temp[0] = ADS1248_ReadByte();
    temp[1] = ADS1248_ReadByte();
    temp[2] = ADS1248_ReadByte();
        
    							//进入中断

    adcVal = (s32)(temp[0] << 24) + (temp[1] << 16) + (temp[2] << 8); // 左移8位，放大256倍识别正负号

    return (adcVal >> 8);                                             // 右移8位恢复原值
}

/*******************************************************************************
* @Function Name: ADS1248_ResToTemp
* @Description  : 二分法查表，将PT100的电阻值转为对应温度0-100
* @param		: float resistance
* @retval	   	       : float
* @date		   	: 2014/10/06
*******************************************************************************/
float ADS1248_ResToTemp(float resistance)
{
    u16 low = 0;
    u16 mid = sizeof(pt100_table) / sizeof(pt100_table[0]) / 2;
    u16 high = sizeof(pt100_table) / sizeof(pt100_table[0]) - 1;

    if((resistance < pt100_table[0]) || (resistance > pt100_table[high]))
    {
        return 0;      // 超限，不做特殊处理  返回0度
    }

    while(high >= low)
    {
        mid = (high + low) / 2;

        if(resistance >= pt100_table[mid])
        {
            if(resistance < pt100_table[mid + 1])
            {
                return (0.1 * mid + (resistance - pt100_table[mid]) * 0.1 / ((pt100_table[mid + 1]) - pt100_table[mid]));
                //return ( mid + (resistance - pt100_table[mid]) / ((pt100_table[mid + 1]) - pt100_table[mid]));
            }
            else
            {
                low = mid + 1;
            }
        }
        else if(resistance < pt100_table[mid])
        {
            high = mid - 1;
        }
    }

    return -1; // 查找失败，不做特殊处理
}

/*******************************************************************************
* @Function Name: ADS1248_Delay
* @Description  : 延时 一次循环约1us
* @param		: vu32 nCount
* @retval	   	: void
* @date		   	: 2014/10/08
*******************************************************************************/
void ADS1248_Delay(vu32 nCount)
{
    u32 i, j;

    for(i = 0; i < nCount; i++)
    {
        for(j = 0; j < 10; j++);
    }
}

/*******************************************************************************
* @Function Name: ADS1248_StartConvert
* @Description  : 
* @param		: void 
* @retval	   	: void 
* @date		   	: 2014/10/16 
*******************************************************************************/
void ADS1248_StartConvert(void)
{
	ADS1248_START_H();
	
}

/*******************************************************************************
* @Function Name: ADS1248_StopConvert
* @Description  : 
* @param		: void 
* @retval	   	: void 
* @date		   	: 2014/10/16 
*******************************************************************************/
void ADS1248_StopConvert(void)
{
	ADS1248_START_L();
}

/*******************************************************************************
* @Function Name: ADS1248_GetSensors
* @Description  : 返回在线的传感器，bit0:第1路,bit1:第2路,bit2:第3路,bit3:第4路，
* @param		: void
* @retval	   	: u8
* @date		   	: 2014/10/15
*******************************************************************************/
u8 ADS1248_GetSensors(void)
{
   // return g_onlineSensor;
  return 1;
}


/*******************************************************************************
* @Function Name: ADS1248_2_ReadByte
* @Description  : Reads a byte from the SPI Device
* @param		: void
* @retval	   	: u8 Byte Read from the SPI Device
* @date		   	: 2014/10/04
*******************************************************************************/
u8 ADS1248_2_ReadByte(void)
{
    return (ADS1248_2_WriteByte(ADS_NOP));
}

/*******************************************************************************
* @Function Name: ADS1248_2_WriteByte
* @Description  : Sends a byte through the SPI interface and return the byte received from the SPI bus.
* @param		: u8 data byte to send
* @retval	   	: u8 The value of the received byte
* @date		   	: 2014/10/04
*******************************************************************************/
u8 ADS1248_2_WriteByte(u8 data)

{
   unsigned char bit_ctr;
   unsigned char temp = 0;
 CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();
    OSIntEnter();                                               /* Tell uC/OS-III that we are starting an ISR           */
    CPU_CRITICAL_EXIT();//进入临界状态
    							//进入中断
   for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
   	{
        
        ADS1248_2_SCK_L();
   	if(data & 0x80)
	 ADS1248_2_MOSI_H();  // MOSI =1;       
   	else 
	 ADS1248_2_MOSI_L();  //MOSI=0;
		 
	data = (data << 1);                  // shift next bit into MSB..
		
	ADS1248_2_SCK_H();    //SCK = 1;                      // Set SCK high..
		
	temp = temp<<1;
	if(ADS1248_2_DO_PIN())
	  temp++;

	 //data |= ADS1248_2_DO_PIN() ;       		  // capture current MISO bit	
	ADS1248_2_SCK_L();     //SCK = 0;            		  // ..then set SCK low again
   	}
   OSIntExit(); //退出临界状态
    return(temp);         

}

/*******************************************************************************
* @Function Name: ADS1248_2_SetIDAC
* @Description  :
* @param		: u8 idac1
* @param		: u8 idac2
* @param		: u8 idacImage
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_2_SetIDAC(u8 idac1, u8 idac2, u8 idacImage)
{
    ADS1248_2_WriteByte(ADS_WREG | ADS_IDAC0);
    ADS1248_2_WriteByte(0x01);
    ADS1248_2_WriteByte(idacImage);
    ADS1248_2_WriteByte(idac1 | idac2);
}

/*******************************************************************************
* @Function Name: ADS1248_2_SetPGAGainAndDataRate
* @Description  : Set PGA gain and data rate (SPS)
* @param		: u8 pgaGain
* @param		: u8 dataRate
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_2_SetPGAGainAndDataRate(u8 pgaGain, u8 dataRate)
{
    ADS1248_2_WriteByte(ADS_WREG | ADS_SYS0);
    ADS1248_2_WriteByte(0x00);
    ADS1248_2_WriteByte(pgaGain | dataRate);
}

/*******************************************************************************
* @Function Name: ADS1248_2_SetBurnoutCurrentAndInputChannel
* @Description  :
* @param		: u8 positiveChannel
* @param		: u8 negativeChannel
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_2_SetBurnoutCurrentAndInputChannel(u8 burnoutCurrent, u8 positiveChannel, u8 negativeChannel)
{
    ADS1248_2_WriteByte(ADS_WREG | ADS_MUX0);
    ADS1248_2_WriteByte(0x00);
    ADS1248_2_WriteByte(burnoutCurrent | positiveChannel | negativeChannel);
}

/*******************************************************************************
* @Function Name: ADS1248_2_SetReference
* @Description  :
* @param		: u8 interVrefOnOff
* @param		: u8 refSelected
* @retval	   	: void
* @date		   	: 2014/10/04
*******************************************************************************/
void ADS1248_2_SetReference(u8 interVrefOnOff, u8 refSelected)
{
    ADS1248_2_WriteByte(ADS_WREG | ADS_MUX1);
    ADS1248_2_WriteByte(0x00);
    ADS1248_2_WriteByte(interVrefOnOff | refSelected);
}

/*******************************************************************************
* @Function Name: ADS1248_2_ReadREG
* @Description  : 读取寄存器的第byteToRead个字节
* @param		: u8 regName
* @param		: u8 byteToRead
* @retval	   	: u8
* @date		   	: 2014/10/05
*******************************************************************************/
u8 ADS1248_2_ReadREG(u8 regName, u8 byteToRead)
{
    ADS1248_2_WriteByte(ADS_RREG | regName);

    if(byteToRead == 1)
    {
        ADS1248_2_WriteByte(0x00);
    }
    else if(byteToRead == 2)
    {
        ADS1248_2_WriteByte(0x01);
        ADS1248_2_ReadByte();
    }

    return ADS1248_2_ReadByte();
}

/*******************************************************************************
* @Function Name: ADS1248_2_ReadADC
* @Description  : 返回有符号数值
* @param		: void
* @retval	   	: s32
* @date		   	: 2014/10/04
*******************************************************************************/
s32 ADS1248_2_ReadADC(void)
{
    u8 temp[3];
    s32 adcVal = 0;
    u32 wait_time = 0;
    
    
    wait_time =  300;                                                 //限时等待 防死机
   
    while(ADS1248_2_READY_PIN() && (wait_time--) )                     //DRDY引脚高电平表示数据没准备好
    {
   		;
           }                                                        
    if(wait_time == 0)                                               //超时报错
     {
           ;
         }

    ADS1248_2_WriteByte(ADS_RDATA);
    
    							//进入中断                                            /* 读取数据期间禁止任务调度     */
    temp[0] = ADS1248_2_ReadByte();
    temp[1] = ADS1248_2_ReadByte();
    temp[2] = ADS1248_2_ReadByte();
        
    							//进入中断

    adcVal = (s32)(temp[0] << 24) + (temp[1] << 16) + (temp[2] << 8); // 左移8位，放大256倍识别正负号

    return (adcVal >> 8);                                             // 右移8位恢复原值
}

/*******************************************************************************
* @Function Name: ADS1248_2_ResToTemp
* @Description  : 二分法查表，将PT100的电阻值转为对应温度0-100
* @param		: float resistance
* @retval	   	       : float
* @date		   	: 2014/10/06
*******************************************************************************/
float ADS1248_2_ResToTemp(float resistance)
{
    u16 low = 0;
    u16 mid = sizeof(pt100_table) / sizeof(pt100_table[0]) / 2;
    u16 high = sizeof(pt100_table) / sizeof(pt100_table[0]) - 1;

    if((resistance < pt100_table[0]) || (resistance > pt100_table[high]))
    {
        return 0;      // 超限，不做特殊处理  返回0度
    }

    while(high >= low)
    {
        mid = (high + low) / 2;

        if(resistance >= pt100_table[mid])
        {
            if(resistance < pt100_table[mid + 1])
            {
                return (0.1 * mid + (resistance - pt100_table[mid]) * 0.1 / ((pt100_table[mid + 1]) - pt100_table[mid]));
                //return ( mid + (resistance - pt100_table[mid]) / ((pt100_table[mid + 1]) - pt100_table[mid]));
            }
            else
            {
                low = mid + 1;
            }
        }
        else if(resistance < pt100_table[mid])
        {
            high = mid - 1;
        }
    }

    return -1; // 查找失败，不做特殊处理
}

/*******************************************************************************
* @Function Name: ADS1248_2_Delay
* @Description  : 延时 一次循环约1us
* @param		: vu32 nCount
* @retval	   	: void
* @date		   	: 2014/10/08
*******************************************************************************/
void ADS1248_2_Delay(vu32 nCount)
{
    u32 i, j;

    for(i = 0; i < nCount; i++)
    {
        for(j = 0; j < 10; j++);
    }
}

/*******************************************************************************
* @Function Name: ADS1248_2_StartConvert
* @Description  : 
* @param		: void 
* @retval	   	: void 
* @date		   	: 2014/10/16 
*******************************************************************************/
void ADS1248_2_StartConvert(void)
{
	ADS1248_2_START_H();
	
}

/*******************************************************************************
* @Function Name: ADS1248_2_StopConvert
* @Description  : 
* @param		: void 
* @retval	   	: void 
* @date		   	: 2014/10/16 
*******************************************************************************/
void ADS1248_2_StopConvert(void)
{
	ADS1248_2_START_L();
}

/*******************************************************************************
* @Function Name: ADS1248_2_GetSensors
* @Description  : 返回在线的传感器，bit0:第1路,bit1:第2路,bit2:第3路,bit3:第4路，
* @param		: void
* @retval	   	: u8
* @date		   	: 2014/10/15
*******************************************************************************/
u8 ADS1248_2_GetSensors(void)
{
   // return g_onlineSensor;
  return 1;
}




/*****************************************END OF FILE**********************************/
