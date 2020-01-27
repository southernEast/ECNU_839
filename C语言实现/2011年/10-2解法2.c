#include <stdio.h>
#include <stdlib.h>

int maxBlock(int **a, int h, int w);
int visit(int** a, int* set, int i, int j, int h, int w);

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

int maxBlock(int** a, int h, int w)
{
    int *set = (int *)malloc(sizeof(int) * h * w);
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            *(set + i * w + j) = 0;                     //初始化标记数组

    int (*m)[w] = a, max = 0, temp = 0;
    for(int i = 0; i < h; i++)                          //遍历矩阵
    {
        for(int j = 0; j < w; j++)
        {
            if(m[i][j] == 1 && *(set + i * w + j) == 0 )//矩阵元素为1且尚未访问
            {
                temp = visit(a, set, i, j, h, w);
                printf("%d ", temp);
                if(temp > max)
                    max = temp;
            }
        }
    }

    free(set);
    return max;
}

int visit(int **a, int *set, int i, int j, int h, int w)//访问矩阵元素并返回计数的个数
{
    int cnt = 1, (*m)[w] = a;
    *(set + i * w + j) = 1;
    if(i - 1 >= 0 && *(set + (i - 1) * w + j) == 0 && m[i - 1][j] == 1)
    {
        cnt += visit(a, set, i - 1, j, h, w);
    }
    if(i + 1 < h && *(set + (i + 1) * w + j) == 0 && m[i + 1][j] == 1)
    {
        cnt += visit(a, set, i + 1, j, h, w);
    }
    if(j - 1 >= 0 && *(set + i * w + j - 1) == 0 && m[i][j - 1] == 1)
    {
        cnt += visit(a, set, i, j - 1, h, w);
    }
    if(j + 1 < w && *(set + i * w + j + 1) == 0 && m[i][j + 1] == 1)
    {
        cnt += visit(a, set, i, j + 1, h, w);
    }
    return cnt;
}
