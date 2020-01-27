#include <stdio.h>

int T(int n);

int cnt =0;                                         //统计次数

int main()
{
    int ans = T(10);
    printf("%d %d\n", ans, cnt);
    return 0;
}

//int T(int n)                                        //递归算法
//{
//
//    if(n == 0)
//        return 0;
//    else if(n == 1 || n == 2)
//        return 1;
//    else
//    {
//        cnt += 2;
//        printf("T(%d)+T(%d)+T(%d):%3d\n", n - 1, n - 2, n - 3, cnt);
//        return T(n - 1) + T(n - 2) + T(n - 3);
//    }
//}

//int T(int n)                                       //非递归算法
//{
//    int sum = 0, t1, t2, t3;
//    if(n == 0)
//        sum = 0;
//    else if(n == 1 || n == 2)
//        sum = 1;
//    else
//    {
//        t1 = 1;
//        t2 = 1;
//        t3 = 0;
//        sum = 0;
//        for(int i = 3; i <= n; i++)
//        {
//            sum = t1 + t2 + t3;
//            t3 = t2;
//            t2 = t1;
//            t1 = sum;
//            cnt += 2;
//        }
//    }
//    return sum;
//}

int T(int n)
{
    int n0, n1, n2, s = 2;
    n0 = 1;
    n1 = 1;
    n2 = 0;
    while(n > 2)
    {
        s = n0 + n1 + n2;
        n2 = n1;
        n1 = n0;
        n0 = s;
        n--;
        cnt += 2;
    }
    return s;
}
