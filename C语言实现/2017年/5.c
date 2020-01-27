#include <stdio.h>

char * hit(int s, char *c);
void Output_Hex(int x);

int main()
{
    char c[10] = {0};
    hit(77, c);
    putchar('\n');
    Output_Hex(77);
    return 0;
}

char * hit(int s, char *c)
{
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
    '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int i = 0;

    while(s != 0)
    {
        c[i++] = hex[s % 16];
        s /= 16;
    }
    while(i > 0)
        printf("%c", c[--i]);
    return c;
}

void Output_Hex(int x)
{
    if(x)
    {
        Output_Hex(x / 16);
        printf("%c", x % 16 > 9 ? x % 16 - 10 + 'A' : x % 16 + '0');
    }
}
