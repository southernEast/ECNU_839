/****                       Caution!!!                       ****/
/****看似简单的题更容易出错，谨记**操作二维数组时的注意事项****/
/****                       Caution!!!                       ****/
#include <stdio.h>

void matrixAdd(int **a, int **b, int **c, int row, int col);

int main()
{
    int a[4][4] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };
    int b[4][4] = {
        {2, 3, 4, 6},
        {2, 3, 4, 5},
        {2, 3, 4, 5},
        {2, 3, 4, 5}
    };
    int c[4][4] = {0};
    matrixAdd(a, b, c, 4, 4);
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            printf("%d ", c[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

void matrixAdd(int **a, int **b, int **c, int row, int col)                                     // 方法一
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            *((int *)c + i * col + j) = *((int *)a + i * col + j) + *((int *)b + i * col + j);
        }   // c指向的地址为 &c[0]，强制转换后为 &c[0][0],此时才可进行一维数组内部元素的操作
    }
}

//void matrixAdd(int **a, int **b, int **c, int row, int col)                                     // 方法二
//{
//    int (*m)[col] = a;                                                                          //a, b, c指向的地址分别为 &a[0], &b[0], &c[0]
//    int (*n)[col] = b;                                                                          //故先转换为数组的指针，再进行操作
//    int (*ans)[col] = c;
//    for(int i = 0; i < row; ++i)
//    {
//        for(int j = 0; j < col; ++j)
//        {
//            ans[i][j] = m[i][j] + n[i][j];
//        }
//    }
//}

