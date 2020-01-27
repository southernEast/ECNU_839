#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
char * ui2hex(unsigned n, char *s);

int main()
{
    char s[15];
    printf("%s", ui2hex(15, s));
    return 1;
}

char *ui2hex(unsigned n, char* s)
{
    char hex[17] = {"0123456789ABCDEF"};
    char temp[40];
    int i = 0, j;
    while(n > 0)
    {
        temp[i++] = hex[n % 16];
        n /= 16;
    }
    i--;
    for(j = 0; i >= 0; j++, i--)
        s[j] = temp[i];
    s[j] = '\0';
    return s;
}

//char * ui2hex(unsigned n, char *s)
//{
//    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
//    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//    char *ans_c = (char *)malloc(11 * sizeof(char));
//    s = (char *)malloc(11 * sizeof(char));          //unsigned 转换成16进制最大为8位 4个字节
//    int i = 0, j = 0;                               //i标记ans_c, j标记ans
//
//    s[j++] = '0', s[j++] = 'x';
//    while(n)
//    {
//        ans_c[i++] = hex[n % 16];                   //除16取余法
//        n /= 16;
//    }
//    --i;                                            //减去多加的1
//    for( ; i >= 0; j ++)                            //将ans_s中字符反序储存
//    {
//        s[j] = ans_c[i--];
//    }
//    s[j] = '\0';                                    //结尾加'\0'记号标记字符串结束
//
//    return s;
//}

//char *ui2hex(unsigned n, char *s)
//{
//    // 32bit unsigned int
//    // convert to
//    // "0x00000000" end with \0
//    // so length=11
//    s=(char *)malloc(sizeof(char)*11);
//    s[0] = '0';
//    s[1] = 'x';
//    int sLen = 2;
//    int digit;
//    for (int i=28; i>=0; i-=4, sLen++)
//    {
//
//        digit = (n & (0x0f<<i)) >> i;
//        if (digit < 10)
//        {
//            s[sLen] = '0' + digit;
//        }
//        else
//        {
//            s[sLen] = 'A' + digit - 10;
//        }
//    }
//    s[sLen] = '\0';
//    return s;
//}
