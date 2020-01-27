#include <stdio.h>
int f(int d[], int n)
{
// d: 1 3 5 7 9 11 13
// ~  0 1 2 3 4 5  6
    int k, v;
    if (n == 0)
        return 0;
    if (n == 1)
    {
        printf("%d\n", d[0]);
        return(d[0]);
    }
    v = f(d+1, n-2);    //f(d[1], 5); f(d[2], 3); f(d[3], 1); f(d[4], 0);
    k = d[0] < d[n-1]?d[0]:d[n-1];  // min(d[0], d[n-1])
    printf("%d\n", k);
    return k+v;
}

int main()
{
    int d[] = { 1 ,3, 5, 7, 9, 11, 13 };
    printf("\nf=%d\n", f(d, 7));
    return 0;
}
