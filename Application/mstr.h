/*
 *CopyRight Reserved:	���ǿƼ�
 *Filename��			mstr.h
 *Description��   		�ַ�������         
 *Data:
 *Author:				heshenghui
*/


#ifndef __MSTR_C__
#define __MSTR_C__

/*------------------�ַ�������------------------*/
extern uint16_t StrLen(const uint8_t *str);

/*------------------�ַ�������------------------*/
extern uint16_t StrCat(uint8_t *str1,const uint8_t *str2);

/*------------------�ַ����Ƚ�------------------*/
extern int8_t StrCmp(const uint8_t *str1,const uint8_t *str2,uint16_t maxlen);

/*------------------�ַ�������------------------*/
extern uint16_t StrCpy(const uint8_t *str1,uint8_t *str2);

/*----------------16λ�з�������ת�ַ�����ȥ����λ0------------------*/
extern uint8_t int16_t2Str(int16_t value,uint8_t *str);

/*----------------16λ�޷�������ת�ַ�����ָ������λ������λ���㲹0------------------*/
extern uint8_t uint16_t2Str(uint16_t value,uint8_t *str,uint8_t num);

/*----------------32λ�з�������ת�ַ�����ȥ����λ0------------------*/
extern uint8_t int32_t2Str(int32_t value,uint8_t *str);

/*----------------32λ�޷�������ת�ַ�����ָ������λ������λ���㲹0------------------*/
extern uint8_t uint32_t2Str(uint32_t value,uint8_t *str,uint8_t num);

/*----------------������ת�ַ�����ָ��С��λ����С��ĩλ���㲹0------------------*/
extern uint8_t Float2Str(float value,uint8_t *str,uint8_t dot);

/*----------------�������ַ���------------------*/
extern uint8_t Bin2Str(uint8_t bin,uint8_t *str);

/*----------------ʮ�������ַ���------------------*/
extern uint8_t Hex2Str(uint8_t hex,uint8_t *str);


/*------------------�ַ���ת����16bit�޷�������------------------*/
extern uint16_t Str2uint16_t(const uint8_t *str);

/*------------------�ַ���ת����16bit�з�������------------------*/
extern int16_t Str2int16_t(const uint8_t *str);

/*------------------�ַ���ת����32bit�޷�������------------------*/
extern uint32_t Str2uint32_t(const uint8_t *str);

/*------------------�ַ���ת����32bit�з�������------------------*/
extern int32_t Str2int32_t(const uint8_t *str);

/*------------------�ַ���ת���ɸ�����------------------*/
extern float Str2Float(const uint8_t *str);

extern uint8_t Float2StrExt(float value,uint8_t *str,uint8_t dot,uint8_t intlen);

#endif  /* __MSTR_C */











