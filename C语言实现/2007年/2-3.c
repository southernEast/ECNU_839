#include<stdio.h>
void abc(int **a, int m, int n) // **a错误，应改为 (*a)[3] 或 a[][3]
{
    int i, j;
    for (i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            *(*(a+i)+j)=a[j][i]*2;
}

//void abc(int **a, int m, int n) // 也可以使用
//{
//    int i, j;
//    int (*b)[3] = a;
//    for (i = 0; i < m; i++)
//        for(j = 0; j < n; j++)
//            *(*(b+i)+j)=b[j][i]*2;
//}

main()
{
    int i, j, a[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    abc(a, 3, 3);
    for(i=0; i < 3; i++)
    {
        for (j = 0; j < 3; j ++)
            printf("%d ", *(*(a+i)+j));
        printf("\n");
    }
}
