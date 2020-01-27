//32
#include <stdio.h>

int max(int a, int b, int c)
{
    a = a > b ? a : b;
    return a > c ? a : c;
}

int f(int *p, int c1, int c2, int c3)
{
    if(c1 < 0 || c2 < 0 || c3 < 0)
        return 0;
    int temp = max(f(p, c1 - 1, c2, c3), f(p, c1, c2 - 1, c3), f(p, c1, c2, c3 - 1) + p[c1 + c2 *2 + c3 *3]);
    printf("(%d, %d, %d): %d\n", c1, c2, c3, temp);
    return temp;
}

int main()
{
    int p[] = {6, 10, 14, 2, 8, 8, 18, 5, 17};
    printf("%d\n", f(p, 1, 2, 1));
    return 0;
}
