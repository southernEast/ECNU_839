#include <stdio.h>
#include <stdarg.h>

void MyPrintf(char *s, ...);
void tenTobi(int n);

int main()
{

    MyPrintf("(8):%o \n(ch):%c \n(bi):%b \nhex:%x", 15, '5', 7, 15);
    return 0;
}

void MyPrintf(char *s, ...)
{
    va_list ap;
    int intValue;
    char charValue;
    char *p = s;

    va_start(ap, s);
    while(*p)
    {
        if(*p != '%')
        {
            putchar(*p);
        }
        else
        {
            switch(*++p)
            {
            case 'd':
                intValue = va_arg(ap, int);
                printf("%d", intValue);
                break;
            case 'c':
                charValue = va_arg(ap, int);            //va_arg()不接受char
                printf("%c", charValue);
                break;
            case 'o':
                intValue = va_arg(ap, int);
                printf("%o", intValue);
                break;
            case 'x':
                intValue = va_arg(ap, int);
                printf("%x", intValue);
                break;
            case 'b':
                intValue = va_arg(ap, int);
                tenTobi(intValue);
                break;
            }
        }
        ++p;
    }
    va_end(ap);
}

void tenTobi(int n)                                 //递归形式十进制转二进制
{
    if(n != 0)
    {
        tenTobi(n / 2);
        printf("%d", n % 2);
    }
}
//
//void tenTobi(int n)                             //数组形式十进制转二进制
//{
//    int temp[32] = {0};
//    int i = 0;
//
//    while(n != 0)
//    {
//        temp[i++] = n % 2;
//        n /= 2;
//    }
//    while(i > 0)
//        printf("%d", temp[--i]);
//}
