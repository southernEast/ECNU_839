#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bitGerationN(int d, int s, int n);

int main()
{
    printf("%X", bitGerationN(0x0F, 0, 2));
    return 0;
}

//int bitGerationN(int d, int s, int n)                                       // s位开始共n位
//{
//    for(int mask = (1 << s), cnt = 0; cnt < n; mask <<= 1, cnt ++)          // mask < (1 << (s + n))
//    {
//        d = (d ^ mask);
//    }
//    return d;
//}

//int bitGerationN(int d, int s, int n)           // s to n
//{
//    for(int mask = (1 << s); mask <= (1 << n); mask <<= 1)
//    {
//        d = d ^ mask;
//    }
//    return d;
//}

int bitGerationN(int d, int s, int n)
{
    for(int mask = 1, i = 0; i < 32; mask <<= 1, i++)
    {

        if(i >= s && i <= n)
        {
            d ^= mask;
        }
    }
    return d;
}

//int bitGerationN(int d, int s, int n)
//{
//    int mask = ~(~0 << n) << (s + 1 - n);
//    return d ^ mask;
//}
