#include <stdio.h>

void matrixInvert(int **a, int n);

int main()
{
    int a[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    matrixInvert(a, 3);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        putchar('\n');
    }
    return 0;
}

void matrixInvert(int **a, int n)
{
    int temp;

    for(int i = 0; i < n; i ++)
    {
        for(int j = i; j < n; j ++)                             // !! j = i, j若是等于0,相当于交换两次! 等于i才是遍历半个数组
        {
            temp = *((int *)a + n * i + j);
            *((int *)a + n * i + j) = *((int *)a + n * j + i);
            *((int *)a + n * j + i) = temp;
        }
    }
}
//
//void matrixInvert(int **a, int n)                                 // 方法二
//{
//    int temp;
//    int (*x)[n] = a;
//    for(int i = 0; i < n; i ++)
//    {
//        for(int j = i; j < n; j ++)
//        {
//            temp = x[i][j];
//            x[i][j] = x[j][i];
//            x[j][i] = temp;
//        }
//    }
//}
