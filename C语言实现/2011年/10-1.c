#include <stdio.h>
#include <stdlib.h>

unsigned char* i2ba(int n, unsigned char *s);

int main()
{
    unsigned char s[4];
    i2ba(-2, s);
    for(int i = 0; i < 4; i++)
        printf("%d ", s[i]);

    return 0;
}

unsigned char * i2ba(int n, unsigned char* s)
{
    for(int i = 0, mask = 0xFF, bit = 0; i < 4; i++, bit += 8)
    {
        s[i] = (n >> bit) & mask;
    }

    return s;
}

//unsigned char* i2ba(int n, unsigned char* s)
//{
//
//    s[0] = n & 0xff;
//    s[1] = (n >> 8) & 0xff;
//    s[2] = (n >> 16) & 0xff;
//    s[3] = (n >> 24) & 0xff;
//
//    return s;
//}
