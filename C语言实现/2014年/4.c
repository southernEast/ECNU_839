#include <stdio.h>
#include <string.h>

int split(char *s, char ch, char (*temp)[1000]);

int main()
{
    char s[1000] = {"This paper introduces several ways to realize wind speed and wind direction instrument,as well as the methods of measuring wind speed and wind direction by ultrasonic wave at home and abroad,and introduces their respective advantages and disadvantages, and their corresponding accuracy problems."};
    char temp[1000][1000];
    int cnt;

    cnt = split(s, ',', temp);
    for(int i = 0; i < cnt; i++)
        printf("%s\n", *(temp + i));
    printf("%d", cnt);
    return 0;
}

int split(char *s, char ch, char (*temp)[1000])     //temp返回分组后的字符串数组，函数返回分组组数
{
    int cnt = 0, i = 0;
    int length = strlen(s), index = 0;

    while(index < length)                           // 字符串数组下标操作形式，此为方法一
    {
        if(s[index] == ch)
        {
            cnt++;
            index++;
            temp++;
            (*temp)[i] == '\0';
            i = 0;
        }
        else
            (*temp)[i++] = s[index++];

    }
    return cnt;
}

//int split(char *s, char ch, char (*temp)[1000])     //temp返回分组后的字符串数组，函数返回分组组数
//{
//    int cnt = 0;
//    char *start = s;                                //start标记待拷贝的字符串起始位置，此为方法二
//
//    while(*s)                                       //循环往下走，直到遇到'\0'表示字符串结束
//    {
//        if(*s == ch)
//        {
//            cnt++;
//            *s = '\0';                              //待拷贝的字符串最后一位置'\0'，以便strcat()函数使用
//            strcat(*temp, start);
//            temp++;
//            *s = ch;                                //改变的'\0'位复位为原来的字符
//            start = s + 1;                          //start指向下一次待拷贝的首字符
//        }
//        s++;
//    }
//    return cnt;
//}
