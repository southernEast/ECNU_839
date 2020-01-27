#include <stdio.h>

void sort(int *p, int n);
void sort1(int* p, int n);
void sort2(int* p, int n);

int main()
{
    int a[] = {2, 5, 1, 0, 8, 4, 10, 9, 0, 11};
    sort1(a, sizeof(a) / sizeof(int));
    for(int i = 0; i < (sizeof(a) / sizeof(int)); i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void sort(int *p, int n)
{
    int Min = 0xFFFF, index = 0;
    for(int i = 0; i < n; i++)
    {
        if(Min > p[i])
        {
            Min = p[i];
            index = i;
        }
    }
    p[index] = *p;
    *p = Min;
    if(--n > 0)
        sort(p + 1, n);
}

//void sort2(int *p, int n)
//{
//    int max = n - 1, temp;
//    for(int i = 0; i < n -  1; i++)
//    {
//        if(p[max] < p[i])
//            max = i;
//    }
//    temp = p[max];
//    p[max] = p[n - 1];
//    p[n - 1] = temp;
//    if(--n > 0)
//        sort2(p, n);
//}

//蔡子经思想
void sort1(int *p, int n)
{
    int k = n - 1, temp, i;
    for(i = 0; i < n - 1; i++)
    {
        if(p[i] > p[k])
            k = i;
    }
    temp = p[k];
    p[k] = p[i];
    p[i] = temp;
    if(--n > 0)
        sort1(p, n);
}
