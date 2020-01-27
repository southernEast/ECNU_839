#include <stdio.h>

int maxBlock(int **a, int h, int w);
int findEntity(int **a, int h, int w, int i, int j);

int main()
{
    int a[5][10] = {
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1}
    };
    printf("\nmax = %d", maxBlock(a, 5, 10));
    return 0;
}

int maxBlock(int **a, int h, int w)
{
    int max = 0, sum = 0;
    int (*p)[w] = a;
    for(int i = 0; i < h; ++ i)
    {
        for(int j = 0; j < w; ++ j)
        {
            if( p[i][j] == 1)                           // Caution!! 为真的意思是非零即真 包括-1
            {
                sum = findEntity(a, h, w, i, j);
                printf("%d ", sum);
                if(max < sum)
                    max = sum;
            }
        }
    }
    return max;
}

int findEntity(int **a, int h, int w, int i, int j)
{
    int sum = 1;
    int (*p)[w] = a;

    p[i][j] = -1;
    if(i >= 0)
    {
        if(p[i - 1][j] == 1)
            sum += findEntity(a, h, w, i - 1, j);
    }
    if(j >= 0)
    {
        if(p[i][j - 1] == 1)
            sum += findEntity(a, h, w, i, j - 1);
    }
    if(i < h - 1)
    {
        if(p[i + 1][j] == 1)
            sum += findEntity(a, h, w, i + 1, j);
    }
    if(j < w - 1)
    {
        if(p[i][j + 1] == 1)
            sum += findEntity(a, h, w, i, j + 1);
    }
    return sum;
}
