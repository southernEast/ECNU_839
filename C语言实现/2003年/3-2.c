#include <stdio.h>

int value9(int d[][8], int n, int i, int j, int *v);

int main()
{
    int d[4][8] =
    {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {2, 4, 6, 8, 10, 12, 14, 16},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {2, 4, 6, 8, 10, 12, 14, 16}
    };
    int ans = 0, state;                         //state 记录函数返回状态 ans 为最终结果

    for(int i = 0; i < 4; i++)                  //显示矩阵
    {
        for(int j = 0; j < 8; j++)
            printf("%4d", d[i][j]);
        putchar('\n');
    }
    state = value9(d, 4, 2, 3, &ans);
    printf("\nans = %3d  %d\n", ans, state);

    return 0;
}

int value9(int d[][8], int n, int i, int j, int *v)
{
    i--;
    j--;
    if(i < 0 || j < 0 || (j + 3 > 8) || (i + 3 > n))    //判断边界条件，不符则返回0
        return 0;
    for(int m = i; m < i + 3; m++)                      //3*3矩阵计算
    {
        for(int n = j; n < j + 3; n++)
            *v += d[m][n];
    }
    return 1;
}
