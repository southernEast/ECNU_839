/*** 有数组的实现方法 ***/
#include <stdio.h>

void F10to16(int n);

int main()
{
    F10to16(555);
    return 0;
}

void F10to16(int n)
{
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
    '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char ans[100], i = 0;
    while(n)                                    //边界条件为 n ！= 0
    {
        ans[i++] = hex[n % 16];                 //取低位
        n /= 16;                                //为下次做准备
    }
    for(int j = i - 1; j >= 0; j--)             //倒序输出
        printf("%c", ans[j]);
}
