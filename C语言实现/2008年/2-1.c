#include <stdio.h>
#define MAXSIZE 10

int Check(int d[], int e[], int n);

int main()
{
    int d1[4] = {1, 3, 2, 5}, e1[4] = {2, 5, 1, 3};
    int d2[4] = {1, 3, 2, 5}, e2[4] = {2, 5, 3, 1};
    printf("%d\n", Check(d1, e1, 4));
    printf("%d\n", Check(d2, e2, 4));
    return 0;
}

int Check(int d[], int e[], int n)
{
    int flag = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if( (d[i] > d[i + 1] && e[i] < e[i + 1]) || (d[i] < d[i + 1] && e[i] > e[i + 1]))       //若有不不满足趋势的情况，退出
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

//int Check(int d[], int e[], int n)                     //方法二
//{
//    int k1, k2;
//    for (int i = 1; i < n ; i ++)
//    {
//        k1 = d[i] - d[i - 1];
//        k2 = e[i] - e[i - 1];
//        if (k1 * k2 < 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
