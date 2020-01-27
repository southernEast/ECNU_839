#include <stdio.h>

void find101(int n);

int main()
{
    find101(4);
    return 0;
}

void find101(int n)
{
    int count = 0, flag = 1;
    for(int i = 0; i < (1 << n); i ++)
    {
        flag = 1;                                   // 开始检测前标志位清零
        for(int mask = 0x07 , judge = 0x05; mask < (1 << n); mask <<= 1, judge <<= 1)
        {

            if((i & mask) == judge)                 //  Caution: !!!  & 的括号!!! 不能忘 &优先级低于!=
            {                                       // Caution!! 判断条件应改为等于101则标记，而不是不等于101则退出
//                printf("%d ", i);                 // 因为如果仅仅是当前位不等于101，其他位仍然有可能等于101
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            count++;
    }
    printf("%d", count);
}
