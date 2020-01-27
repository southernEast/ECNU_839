#include <stdio.h>

int main()
{
    int v[16], i, j,s = 0;
    for(i = 0; i < 16; i ++)
        v[i] = 2 * i + 1;
    i = 0;
    while(i <= 10)
    {
        for(j = 0; j <= i; j++)
            if(j % 2 == 0)
                s += v[j];
            else
                s -= v[j];
        i++;
    }
    printf("%d %d %d", i, j, s);
}
