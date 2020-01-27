/********用二进制位进行穷举法的核心思想********/
#include <stdio.h>
//0101111100
int main()
{
    int a = (1 << 1) + (1 << 2) + (1 << 3) + (1 << 5) + (1 << 8);                   //移位运算符优先级低于加法运算符
    int b = (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6) + (1 << 7);
    int c = (1 << 0) + (1 << 2) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 8) + (1 << 9);
    int correcta, correctb, correctc;
    int ans = 0;

    for(ans = 0; ans < (1 << 10); ans ++)                       //穷举所有可能从全0到全1
    {
        correcta = correctb = correctc = 0;
        for(int mask = 1; mask < (1 << 10); mask <<= 1)
        {
            if((a & mask) == (ans & mask))                      //&的优先级低于==
                correcta++;
            if((b & mask) == (ans & mask))
                correctb++;
            if((c & mask) == (ans & mask))
                correctc++;
        }
        if(correcta == 7 && correctb == 7 && correctc == 7)
            break;
    }
    printf("%d\n", ans);
    for(int mask = (1 << 9); mask > 0; mask >>= 1)              // T F 形式输出结果
    {
        if(ans & mask)
            putchar('T');
        else
            putchar('F');
    }
    return 0;
}
