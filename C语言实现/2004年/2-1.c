//5 4 [2]
//8 6 [2]
#include <stdio.h>
#define MAX_INT 32767
#define N 6 // 应为6

int main()
{
    int d[N+1], i, j, k, c;
    for (i = 0; i < N; ++i)
    {
        printf("Input:");
        scanf("%d", d+i);   // 1 2 5 4 8 6
        if (d[i] <= 0)      // 无意义
        {
            d[i] = MAX_INT;
            break;
        }
    }
    k = i + 1;
    for (i = 0; i < k-1; ++i)
    {
        if (d[i] < d[i + 1])
            continue;
        for (c = 0, j = i; j < k-1; ++j)
        {
            if (d[j] >= d[j+1])
            {
                printf("%d ", d[j]);
                ++c;
            }
            else
            {
                i = j;
                printf("%d [%d]\n", d[j], c + 1);
                break;
            }
        }
    }

    return 1;
}
