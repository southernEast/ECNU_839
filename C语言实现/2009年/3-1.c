#include <stdio.h>

void natural12binary(int n);

int main()
{
    natural12binary(100);
    return 0;
}

void natural12binary(int n)
{
    if(n)
    {
        natural12binary(n / 2);
        printf("%d", n % 2);
    }
}
