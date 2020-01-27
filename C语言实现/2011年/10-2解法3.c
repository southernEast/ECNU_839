#include <stdio.h>
#include <stdlib.h>

int maxBlock(int **a, int h, int w);
int Scan(int** a, int* mark, int h, int w, int i, int j, int cnt);

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
    int *mark = (int *)malloc(h * w * sizeof(int));

    for(int i = 0; i < h; i++)                                      //注意 int型数组清零不能使用memset()函数
    {
        for(int j = 0; j < w; j++)
            mark[i * w + j] = 0;
    }

    int cnt = 0, maxcnt = 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(*((int *)a + i * w + j) == 1 && mark[i * w + j] == 0)
            {
                cnt = Scan(a, mark, h, w, i, j, 0);
                printf("%d\n", cnt);
                if(cnt > maxcnt)
                    maxcnt = cnt;
            }
        }
    }

    return maxcnt;
}

int Scan(int **a, int *mark, int h, int w, int i, int j, int cnt)
{
    mark[i * w + j] = 1;

    if(i - 1 >= 0 && *((int *)a + (i - 1) * w + j) == 1 && mark[(i - 1) * w + j] == 0 )
        cnt = Scan(a, mark, h, w, i - 1, j, cnt);                                           //此处cnt为更新采用=而不是+=

    if(i + 1 < h && *((int *)a + (i + 1) * w + j) == 1 && mark[(i + 1) * w + j] == 0 )
        cnt = Scan(a, mark, h, w, i + 1, j, cnt);

    if(j - 1 >= 0 && *((int *)a + i * w + j - 1) == 1 && mark[i * w + j - 1] == 0 )
        cnt = Scan(a, mark, h, w, i, j - 1, cnt);

    if(j + 1 < w && *((int *)a + i * w + j + 1) == 1 && mark[i * w + j + 1] == 0 )
        cnt = Scan(a, mark, h, w, i, j + 1, cnt);

    return cnt + 1;
}
