/*
 *CopyRight Reserved:	宇星科技
 *Filename：			mstr.c
 *Description：   		字符串函数         
 *Data:
 *Author:				heshenghui
*/

#include "include.h"
/*------------------字符串长度------------------*/
uint16_t StrLen(const uint8_t *str)
{
	uint16_t len=0;
	while (str[len]) len++;
	return(len);
}
/*------------------字符串连接------------------*/
uint16_t StrCat(uint8_t *str1,const uint8_t *str2)
{
	uint16_t i=0,j=0;
	while(str1[i]) i++;
	while(str2[j]) str1[i++]=str2[j++];
	str1[i]='\0';
	return(i);
}
/*------------------字符串复制------------------*/
uint16_t StrCpy(const uint8_t *str1,uint8_t *str2)
{
	uint16_t i=0;
	while(str1[i])
	{
		str2[i]=str1[i];
		i++;
	}
	str2[i]='\0';
	return(i);
}
/*------------------字符串比较------------------*/
int8_t StrCmp(const uint8_t *str1,const uint8_t *str2,uint16_t maxlen)
{
	uint16_t i=0;
	while(i<maxlen)
	{
		if (str1[i]<str2[i]) return(-1);
		else if (str1[i]>str2[i]) return(1);
		else if (str1[i]==0) return(0);
		i++;
	}
	return(0);
}
/*------------------字符串转换成16bit无符号整数------------------*/
uint16_t Str2uint16_t(const uint8_t *str)
{
	uint8_t i,j=0;
	uint16_t value=0;
	while(j<5&&str[j]>='0'&&str[j]<='9') j++;
	if (j)
	{
		uint8_t k;
		uint16_t tmp;
		for (i=0;i<j;i++)
		{
			tmp=str[i]-'0';
			if (tmp)
			{
				for (k=j-i-1;k!=0;k--) tmp*=10;
				value+=tmp;
			}
		}
	}
	return(value);
}
/*------------------字符串转换成16bit有符号整数------------------*/
int16_t Str2int16_t(const uint8_t *str)
{
	int16_t value;
	if (str[0]=='-')
	{
		value=Str2uint16_t(&str[1]);
		value=-value;
	}
	else if (str[0]=='+')
	{
		value=Str2uint16_t(&str[1]);
	}
	else value=Str2uint16_t(&str[0]);
	return(value);
}
/*------------------字符串转换成32bit无符号整数------------------*/
uint32_t Str2uint32_t(const uint8_t *str)
{
	uint8_t i,j=0;
	uint32_t value=0;
	while(j<10&&str[j]>='0'&&str[j]<='9') j++;
	if (j)
	{
		uint8_t k;
		uint32_t tmp;
		for (i=0;i<j;i++)
		{
			tmp=str[i]-'0';
			if (tmp)
			{
				for (k=j-i-1;k!=0;k--) tmp*=10;
				value+=tmp;
			}
		}
	}
	return(value);
}
/*------------------字符串转换成32bit有符号整数------------------*/
int32_t Str2int32_t(const uint8_t *str)
{
	int32_t value;
	if (str[0]=='-')
	{
		value=Str2uint32_t(&str[1]);
		value=-value;
	}
	else if (str[0]=='+')
	{
		value=Str2uint32_t(&str[1]);
	}
	else value=Str2uint32_t(&str[0]);
	return(value);
}
/*------------------字符串转换成浮点数------------------*/
float Str2Float(const uint8_t *str)
{
	uint8_t i=0;
	uint8_t dot=0;
	float value=0;
	while(i<16&&((str[i]>='0'&&str[i]<='9')||str[i]=='+'||str[i]=='-')) i++;
	if (str[i]=='.')
	{
		i++;
		value=Str2uint32_t(&str[i]);
		while(i<16&&str[i]>='0'&&str[i]<='9') {dot++;i++;}
		while(dot--) value/=10;
	}
	if (i)
	{
		if (str[0]=='-')
		{
			value+=Str2uint32_t(&str[1]);
			value=-value;
		}
		else if (str[0]=='+')
		{
			value+=Str2uint32_t(&str[1]);
		}
		else value+=Str2uint32_t(&str[0]);
	}
	return(value);
}


/*----------------16位有符号整数转字符串：去掉高位0------------------*/
uint8_t int16_t2Str(int16_t value,uint8_t *str)
{
	uint8_t returnval=1;
	uint8_t str_tmp[7];
	uint8_t i=5;
	if (value==0)
	{
		str_tmp[0]='0';
		str_tmp[1]='\0';
	}
	else if (value<0)
	{
		value=-value;
		for (i=0;i<5;i++)
		{
			str_tmp[5-i]=(uint8_t)(value%10)+'0';
			value/=10;
			if (value==0) break;
		}
		if (i<5) i++;
		str_tmp[5-i]='-';
		str_tmp[6]='\0';
		returnval=i+1;
	}
	else
	{
		for (i=0;i<5;i++)
		{
			str_tmp[5-i]=(uint8_t)(value%10)+'0';
			value/=10;
			if (value==0) break;
		}
		if (i==5) i--;
		str_tmp[6]='\0';
		returnval=i+1;
	}
	StrCpy(&str_tmp[5-i],str);
	return(returnval);
}
/*----------------16位无符号整数转字符串：指定数字位数，高位不足补0------------------*/
uint8_t uint16_t2Str(uint16_t value,uint8_t *str,uint8_t num)
{
	uint8_t str_tmp[6]={'0','0','0','0','0','\0'};
	uint8_t i;
	for (i=0;i<5;i++)
	{
		str_tmp[4-i]=(uint8_t)(value%10)+'0';
		value/=10;
		if (value==0) break;
	}
	if (i<5) i++;
	if (num<i) num=i;
	else if (num>5) num=5;
	StrCpy(&str_tmp[5-num],str);
	return(num);
}
/*----------------32位有符号整数转字符串：去掉高位0------------------*/
uint8_t int32_t2Str(int32_t value,uint8_t *str)
{
	uint8_t returnval=1;
	uint8_t str_tmp[12];
	uint8_t i=10;
	if (value==0)
	{
		str_tmp[0]='0';
		str_tmp[1]='\0';
	}
	else if (value<0)
	{
		value=-value;
		for (i=0;i<10;i++)
		{
			str_tmp[10-i]=(uint8_t)(value%10)+'0';
			value/=10;
			if (value==0) break;
		}
		if (i<10) i++;
		str_tmp[10-i]='-';
		str_tmp[11]='\0';
		returnval=i+1;
	}
	else
	{
		for (i=0;i<10;i++)
		{
			str_tmp[10-i]=(uint8_t)(value%10)+'0';
			value/=10;
			if (value==0) break;
		}
		if (i==10) i--;
		str_tmp[11]='\0';
		returnval=i+1;
	}
	StrCpy(&str_tmp[10-i],str);
	return(returnval);
}
/*----------------32位无符号整数转字符串：指定数字位数，高位不足补0------------------*/
uint8_t uint32_t2Str(uint32_t value,uint8_t *str,uint8_t num)
{
	uint8_t str_tmp[11]={'0','0','0','0','0','0','0','0','0','0','\0'};
	uint8_t i;
	for (i=0;i<10;i++)
	{
		str_tmp[9-i]=(uint8_t)(value%10)+'0';
		value/=10;
		if (value==0) break;
	}
	if (i<10) i++;
	if (num<i) num=i;
	else if (num>10) num=10;
	StrCpy(&str_tmp[10-num],str);
	return(num);
}
/*----------------浮点数转字符串：指定小数位数，小数末位不足补0------------------*/
uint8_t Float2Str(float value,uint8_t *str,uint8_t dot)
{
	uint8_t returnval;
	int32_t high,low;
	uint8_t i,cnt,sign=0;		   
	//uint8_t num;

	uint8_t str_tmp[19]={'-','0','0','0','0','0','0','0','0','0','0','.','0','0','0','0','0','0','\0'};
	if (value<0)
	{
		value=-value;
		sign=1;
	}
	high=(int32_t)value;//取整数部分
	value-=high;/*取小数部分*/
	value*=1000000L;/*取6位小数*/
	low=(int32_t)value;//取小数部分
	for (i=0;i<10;i++)
	{
		str_tmp[10-i]=(uint8_t)(high%10)+'0';
		high/=10;
		if (high==0) break;
	}
	cnt=i;
	if (i<10) cnt++;
	for (i=0;i<6;i++)
	{
		str_tmp[17-i]=(uint8_t)(low%10)+'0';
		low/=10;
		if (low==0) break;
	}
//sunlis添加判断4舍5入程序，保证打印出来的浮点数精确度       
//	//
//    if(str_tmp[12+dot]>'4')
//    {
//      if(str_tmp[11+dot]+1<='9')
//      {
//        str_tmp[11+dot]+=1;            
//      }
//      else
//      {
//        str_tmp[11+dot]='0';
//        if(str_tmp[10+dot]+1<='9')
//        {
//          str_tmp[10+dot]+=1;
//        }
//        else
//        {
//          str_tmp[10+dot]='0';
//          if(str_tmp[9+dot]+1<='9')
//          {
//            str_tmp[9+dot]+=1;
//          }
//          else
//          {
//            str_tmp[9+dot]='0';
//            if(str_tmp[7+dot]+1<='9')
//            {
//              str_tmp[7+dot]+=1;
//            }
//            else
//            {
//              str_tmp[7+dot]='0';
//              if(str_tmp[6+dot]+1<='9')
//              {
//                str_tmp[6+dot]+=1;
//              }
//              else
//              {
//                for(num=0;num<19;num++)
//                {
//                  str_tmp[num]='0';
//                }
//              }
//            }
//          }
//        }
//      }
//    }
	if (dot==0)
	{
		returnval=11;
		str_tmp[returnval]='\0';
	}
	else if (dot<=6)
	{
		returnval=12+dot;
		str_tmp[returnval]='\0';
	}
	else
	{
		returnval=18;
		str_tmp[returnval]='\0';
	}
	if (sign)
	{
		cnt=10-cnt;
		str_tmp[cnt]='-';
		StrCpy(&str_tmp[cnt],str);
		returnval-=cnt;
	}
	else
	{
		cnt=11-cnt;
		StrCpy(&str_tmp[cnt],str);
		returnval-=cnt;
	}
	return(returnval);
}
/*******************************************************************************
**浮点数转字符串：指定小数位数，小数末位不足补0
**sunlis--            指定显示的长度，不足的补0
**value--            浮点型变量
**str--             输出的字符串指针
**dot--              小数位数
**intlen--             指定整数位数长度
**author--          sunlis
*******************************************************************************/

uint8_t Float2StrExt(float value,uint8_t *str,uint8_t dot,uint8_t intlen)
{
	uint8_t returnval;
	int32_t high,low;
	uint8_t i,cnt,sign=0;
	//uint8_t num;
	uint8_t str_tmp[19]={'-','0','0','0','0','0','0','0','0','0','0','.','0','0','0','0','0','0','\0'};
	if (value<0)
	{
		value=-value;
		sign=1;
	}
	high=(int32_t)value;
	value-=high;            //取小数部分
	value*=1000000L;        //取6位小数
	low=(int32_t)value;
	for (i=0;i<10;i++)
	{
		str_tmp[10-i]=(uint8_t)(high%10)+'0';
		high/=10;
		if (high==0) break;
	}
	cnt=i;
	if (i<10) cnt++;
	for (i=0;i<6;i++)
	{
		str_tmp[17-i]=(uint8_t)(low%10)+'0';
		low/=10;
		if (low==0) break;
	}
//sunlis添加判断4舍5入程序，保证打印出来的浮点数精确度       
//    if(str_tmp[12+dot]>'4')
//    {
//      if(str_tmp[11+dot]+1<='9')
//      {
//        str_tmp[11+dot]+=1;            
//      }
//      else
//      {
//        str_tmp[11+dot]='0';
//        if(str_tmp[10+dot]+1<='9')
//        {
//          str_tmp[10+dot]+=1;
//        }
//        else
//        {
//          str_tmp[10+dot]='0';
//          if(str_tmp[9+dot]+1<='9')
//          {
//            str_tmp[9+dot]+=1;
//          }
//          else
//          {
//            str_tmp[9+dot]='0';
//            if(str_tmp[7+dot]+1<='9')
//            {
//              str_tmp[7+dot]+=1;
//            }
//            else
//            {
//              str_tmp[7+dot]='0';
//              if(str_tmp[6+dot]+1<='9')
//              {
//                str_tmp[6+dot]+=1;
//              }
//              else
//              {
//                for(num=0;num<19;num++)
//                {
//                  str_tmp[num]='0';
//                }
//              }
//            }
//          }
//        }
//      }
//    }
	if (dot==0)
	{
		returnval=11;
		str_tmp[returnval]='\0';
	}
	else if (dot<=6)
	{
		returnval=12+dot;
		str_tmp[returnval]='\0';
	}
	else
	{
		returnval=18;
		str_tmp[returnval]='\0';
	}
	if (sign)//sunlis负数的情况下
	{
          
            cnt=10-cnt;
            if(intlen<=cnt)
            {
              str_tmp[cnt]='-';
              StrCpy(&str_tmp[cnt],str);
              returnval-=cnt;
            }
            else
            {
              str_tmp[11-intlen]='-';
              StrCpy(&str_tmp[11-intlen],str);
              returnval-=(11-intlen);              
            }
		
	}
	else//sunlis正数的情况下
	{
          if(intlen<=cnt)
          {
            cnt=11-cnt;
            StrCpy(&str_tmp[cnt],str);
            returnval-=cnt;
          }
          else
          {
            intlen=11-intlen;
            StrCpy(&str_tmp[intlen],str);
            returnval-=intlen;
          }
            
	}
	return(returnval);
}




/*----------------二进制字符串------------------*/
uint8_t Bin2Str(uint8_t bin,uint8_t *str)
{
	uint8_t i;
	uint8_t bit_on=0x80;
	for (i=0;i<8;i++)
	{
		if (((bit_on>>i)&bin)==0)	str[i]='0';
		else str[i]='1';
	}
	str[8]='\0';
	return(8);
}
/*----------------十六进制字符串------------------*/
uint8_t Hex2Str(uint8_t hex,uint8_t *str)
{
	uint8_t high;
	high=hex&0xf0;
	high>>=4;
	if (high>9) str[0]='A'+high-10;
	else str[0]='0'+high;
	high=hex&0x0f;
	if (high>9) str[1]='A'+high-10;
	else str[1]='0'+high;
	str[2]='\0';
	return(2);
}


