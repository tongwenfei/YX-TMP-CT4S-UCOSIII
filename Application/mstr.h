/*
 *CopyRight Reserved:	宇星科技
 *Filename：			mstr.h
 *Description：   		字符串函数         
 *Data:
 *Author:				heshenghui
*/


#ifndef __MSTR_C__
#define __MSTR_C__

/*------------------字符串长度------------------*/
extern uint16_t StrLen(const uint8_t *str);

/*------------------字符串连接------------------*/
extern uint16_t StrCat(uint8_t *str1,const uint8_t *str2);

/*------------------字符串比较------------------*/
extern int8_t StrCmp(const uint8_t *str1,const uint8_t *str2,uint16_t maxlen);

/*------------------字符串复制------------------*/
extern uint16_t StrCpy(const uint8_t *str1,uint8_t *str2);

/*----------------16位有符号整数转字符串：去掉高位0------------------*/
extern uint8_t int16_t2Str(int16_t value,uint8_t *str);

/*----------------16位无符号整数转字符串：指定数字位数，高位不足补0------------------*/
extern uint8_t uint16_t2Str(uint16_t value,uint8_t *str,uint8_t num);

/*----------------32位有符号整数转字符串：去掉高位0------------------*/
extern uint8_t int32_t2Str(int32_t value,uint8_t *str);

/*----------------32位无符号整数转字符串：指定数字位数，高位不足补0------------------*/
extern uint8_t uint32_t2Str(uint32_t value,uint8_t *str,uint8_t num);

/*----------------浮点数转字符串：指定小数位数，小数末位不足补0------------------*/
extern uint8_t Float2Str(float value,uint8_t *str,uint8_t dot);

/*----------------二进制字符串------------------*/
extern uint8_t Bin2Str(uint8_t bin,uint8_t *str);

/*----------------十六进制字符串------------------*/
extern uint8_t Hex2Str(uint8_t hex,uint8_t *str);


/*------------------字符串转换成16bit无符号整数------------------*/
extern uint16_t Str2uint16_t(const uint8_t *str);

/*------------------字符串转换成16bit有符号整数------------------*/
extern int16_t Str2int16_t(const uint8_t *str);

/*------------------字符串转换成32bit无符号整数------------------*/
extern uint32_t Str2uint32_t(const uint8_t *str);

/*------------------字符串转换成32bit有符号整数------------------*/
extern int32_t Str2int32_t(const uint8_t *str);

/*------------------字符串转换成浮点数------------------*/
extern float Str2Float(const uint8_t *str);

extern uint8_t Float2StrExt(float value,uint8_t *str,uint8_t dot,uint8_t intlen);

#endif  /* __MSTR_C */











