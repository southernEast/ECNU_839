#include <stdio.h>

int test (unsigned bits)
{
    unsigned i, mask = 1 << 15, count = 0;
    for (i = 0; i < 16; i++, bits <<=1)
    {
        if ((bits & mask) == mask)
        {
            count ++;
        }
    }
    return (count % 2? 0:1);                   //小心！ 若是奇数个1则返回0，偶数个1则返回1
}

int main()
{
    unsigned x1 = 0x01, x2 = 0x03;
    printf("%x:%d\n", x1, test(x1));
    printf("%x:%d\n", x2, test(x2));
    return 0;
}
