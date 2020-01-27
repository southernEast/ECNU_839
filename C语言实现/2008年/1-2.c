#include <stdio.h>

int f(int a, int b)
{
 int s, t;
 if(a < b) { printf("%d\n", a); return(a); }
 s = b + 1;
 t = f(a/b, s);
 printf("%d\n", a%b);
 return(t + a%b);
}

int main()
{
    printf("k = %d", f(21,2));
    return 0;
}
