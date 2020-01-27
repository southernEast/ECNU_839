#include <stdio.h>
int f(int n)
{
    int k, c;
    if (n <= 1)
    {
        printf("%d\n", n);
        return (n);
    }
    k = n/2;
    c = f(n-n/2);
    printf("%d\n", k);
    return (k+c);
}

int main()
{
    printf("f=%d\n", f(8));
//    printf("%d", 3/2);
    return 0;
}
