#include <stdio.h>

int g(int d[], int n, int i)
{
    int k;
    if (i >= n -1)
    {
        if (i == n-1)
        {
            printf("*%3d", d[i]);
            return (i+1);
        }
    }
    if (d[i] > d[i + 1])
    {
        k = g(d, n, i+1);
        printf("*%3d", d[i]);
    }
    else
    {
        printf("*%3d", d[i]);
        return (i);
    }
    return (k);
}


void f(int d[], int n, int i)
{
    int j, k; // k未初始化
    if (i >= n -1)
    {
        return ;
    }
    for (j = i; j < n-1 && d[j] <= d[j+1]; ++j)
    {
        printf("#%3d", d[j]);
    }
    if (j >= n)
    {
        return ;
    }
    printf("#%3d\n", d[j]);
    if (j < n - 1)
    {
        k = g(d, n, j);
        printf("\n");
    }
//    printf("&%d&\n", k);              //最后一次k未初始化 没有赋值
    if (k < n -1)
    {
        f(d, n, k);
    }
}

int main()
{
    int v[] = { 1, 3, 7, 6, 5, 7, 8, 9 };
    f(v, 8, 0);

    return 0;
}
