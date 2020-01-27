#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 100
int MCNuggets(int n);
int MCNuggets1(int n);
int main()
{
    srand( time(0) );
    for(int i = 0; i < 20; i++)
    {
        int temp = rand() % 200;
        printf("%d %d\n", MCNuggets(temp), MCNuggets1(temp));
    }


    return 0;
}

int MCNuggets1(int n)                                // 暴力穷举法
{
    for(int a = 0; a <= n / 6; a++)
        for(int b = 0; b <= n / 9; b++)
            for(int c = 0; c <= n / 20; c++)
            {
                if(6 * a + 9 * b + 20 *c == n)
                {
//                    printf("%d*6 + %d*9 + %d*20 = %d\n", a, b, c, n);
                    return 1;
                }
            }
    return 0;
}

int MCNuggets(int n)
{
  int buckets[MAXN];
  int i;
  for(i=0;i < MAXN;i++)
  buckets[i]=0;
  buckets[6]=1;
  buckets[9]=1;
  buckets[20]=1;
  for(i=6;i < MAXN;i++)
  {
    if(buckets[i]==1)
    {
      if(i+6 < MAXN)  buckets[i+6]=1;
      if(i+9 < MAXN)  buckets[i+9]=1;
      if(i+20 < MAXN)  buckets[i+20]=1;
    }
  }
  if(n < MAXN)
    return buckets[n];
  else
    return 1;
}

//int MCNuggets(int n)                                // 带脑子的穷举法
//{
//    int i, j, k;
//    for(i = 0; ; ++i)                               //for(i = 0; 20 * i <=n; ++i)
//    {
//        for(j = 0; 9 * j <= n; ++j)
//        {
//            for(k = 0; 6 * k <= n; k++)
//            {
//                if(i * 20 + j * 9 + k * 6 == n)
//                    return 1;
//                else if(i * 20 + j * 9 + k * 6 < n)
//                {
//                    printf("%d\n", i * 20 + j * 9 + k * 6);
//                    continue;
//                }
//                else if(i * 20 + j * 9 + k * 6 > n)
//                    return 0;
//            }
//        }
//    }
////    return 0;
//}



