#include <stdio.h>
#include <math.h>

int isprime(int m);
int Goldbach(int n);

int main()
{
    int a = 4107356, n;
    printf("%d ", Goldbach(a));
    return 0;
}

int Goldbach(int n)
{
//    for(int i = 2; i < n; i++)
//    {
//        if(isprime(i) && isprime(n - i))
//        {
//            printf("%d = %d + %d\n", n, i, n - 1);
//            break;
//        }
//    }
    for(int i = 2; i < n; i++)
        if(isprime(i) && isprime(n - i))
            return 1;
    return 0;
}

int isprime(int m)                  //遍历所有可能
{
    int flag = 1;
    for(int i = 2; i < m; i ++)
    {
        if(m % i == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

//int isprime(int m)                  //遍历所有可能 简单改进
//{
//    int flag = 1;
//    for(int i = 2; i <= sqrt(m); i ++)
//    {
//        if(m % i == 0)
//        {
//            flag = 0;
//            break;
//        }
//    }
//
//    return flag;
//}
