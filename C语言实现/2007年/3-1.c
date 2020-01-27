/****** 十进制数转换成十六进制数方法为除16取余法 ******/
/****** 每次对待转换的数进行除法，所得的商作为下 ******/
/****** 一次计算准备，所得余数作为16进制数的低位 ******/
#include <stdio.h>

void F10to16(int n);

int main()
{
    F10to16(5555);
    return 0;
}

void F10to16(int n)
{
    char hex[16] = {"0123456789ABCDEF"};
    if(n != 0)
    {
        F10to16(n / 16);
        printf("%c", hex[n % 16]);
    }
}

//void F10to16(int n)
//{
//    if(n != 0)
//    {
//        F10to16(n / 16);
//        printf("%X", n % 16);
//    }
//}
