#include <stdio.h>

//int getBits(int x, int p, int n)
//{
//    int ans = 0;
//    for(int mask = (1 << p), i = 0; i < n; i++, mask >>= 1)
//        ans |= (x & mask);
//    return ans >> (p - n + 1);
//}

int getBits(int x, int p, int n)                //K&R P39
{
    return (x >> (p+1-n) & ~(~0 << n));
}

void Print_Bit(int x)
{
    if(x)
    {
        Print_Bit(x/2);
        printf("%d", x % 2);
    }
}

int main()
{
    Print_Bit(getBits(106, 6, 4));
    return 0;
}

