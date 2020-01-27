// 3 2ab1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Print(char a[], int n, int m)
{
    char *buf = (char *)malloc(n * sizeof(char));
    for(int select = 0; select < (1 << n); select++)
    {
        int cnt = 0;
        memset(buf, 0, n);                              //缓存数组清空
        for(int mask = 1, i = 0; mask < (1 << n); mask <<= 1, i++)
        {
            if((select & mask) == mask)                 //选中该字符
            {
                buf[cnt++] = a[i];
            }
        }
        if(cnt == m)
        {
            printf("%s\n", buf);
        }
    }
    free(buf);
}

int main()
{
    int n, m;
    char a[] = {"ab1"};
    n = sizeof(a) / sizeof(a[0]) - 1;
    m = 2;
    Print(a, n, m);

    return 0;
}
