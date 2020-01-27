#include <stdio.h>
#include <stdlib.h>

int Find_Most(int const *a, int n, int *ans);

int main()
{
    int ans = 0, num, a[] = {1, 2, 3, 4, 0, 1, 0, 3, 3, 0, 4, 4, 0,};
    num = Find_Most(a, sizeof(a) / sizeof(a[0]), &ans);
    printf("The number is %d.\nOccourence of number is %d.", num, ans);
    return 0;
}

int Find_Most(int const *a, int n, int *ans)
{
    int max = 0, *cnt, count = 0, num = 0;
    for(int i = 0; i < n; i++ )         //找到最大数 为初始化计数数组做准备
    {
        if(max < a[i])
            max = a[i];
    }
    cnt = (int *)malloc((max + 1) * sizeof(int));
    for(int i = 0; i < max + 1; i++)   //初始化计数数组
        cnt[i] = 0;
    for(int i = 0; i < n; i++)         //进行计数
        cnt[a[i]]++;
    for(int i = 0; i < max + 1; i++)   //在计数数组中找到最大数
    {
        if(count < cnt[i])
        {
            count = cnt[i];
            num = i;
        }
    }
    *ans = count;

    return num;
}
