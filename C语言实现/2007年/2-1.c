#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4];
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(int [4]));                //含4个int元素的一维数组
    printf("%d\n", sizeof(int *[4]));               //含4个int*元素的一维数组
    printf("%d\n", sizeof(int (*)[4]));             //一个指向4个int*元素的指针
    printf("%d\n", sizeof(int (*)()));              //一个返回值为int的函数指针

//    int b[5][4];
//    for(int i = 0; i < 5; i++)
//    {
//        for(int j = 0; j < 4; j++)
//            b[i][j] = j;
//    }
//    int (*p)[4] = b;
//    for(int i = 0; i < 5; i++)
//    {
//        for(int j = 0; j < 4; j++)
//            printf("%d ", p[i][j]);
//        putchar('\n');
//    }

    return 0;
}
