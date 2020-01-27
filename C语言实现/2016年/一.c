#include <stdio.h>

int cmp(int *a, int *b)
{
    return *b - *a;
}
void swap(int *a, int *b, int (*cmp)(int *a, int *b))
{
    if(cmp(a, b) < 0)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int a = 0, b = 1;
    swap(&a, &b, cmp);
    printf("%d %d", a, b);

    return 0;
}
