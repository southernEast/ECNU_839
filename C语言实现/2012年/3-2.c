/****** 本题十六进制和八进制转换可直接使用printf函数 ******/
/******         但二进制转换输出需要自己编写函数     ******/
#include <stdio.h>

void tenTotwo(unsigned value);
void PRINT(char fmt[], unsigned value);

int main()
{
//    char fmt[] = "Dec：\t%u\nHex：\t%x\nBin：\t%b\n";
    PRINT("Dec：\t%u\nHex：\t%x\nBin：\t%b\nOtc:\t%o", 1312);
//    puts(fmt);
    return 0;
}

void PRINT(char fmt[], unsigned value)
{
    while(*fmt)
    {
        if(*fmt == '%')
        {
            switch(*++fmt)
            {
            case 'b':
                tenTotwo(value);
                break;
            case 'u':
                printf("%u", value);
                break;
            case 'x':
                printf("%x", value);
                break;
            case 'o':
                printf("%o", value);
                break;
            }
        }                                   //记住测试'%'和"%x"后的边界输出情况
        else
        {
            putchar(*fmt);
        }
        fmt++;
    }
}

void tenTotwo(unsigned value)
{
    if(value)
    {
        tenTotwo(value / 2);
        printf("%d", value % 2);
    }
}

//void tenTotwo(unsigned value)
//{
//    for(int i = 1; i <= 32; i++ )
//    {
//        unsigned temp = value >> (32 - i);
//        if(temp != 0)                               // 第一个不为零的最高位到达时，输出整个二进制数
//        {
//            while(i <= 32)
//            {
//                i++;
//                printf("%d", temp & 1);
//                temp = value >> (32 - i);
//            }
//        }
//    }
//}
