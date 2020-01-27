#include <stdio.h>

long Count_Find(int n, long a);

int main()
{

    printf("%ld", Count_Find(3, 1));
    return 0;
}

long Count_Find(int n, long a)
{
    if(n == 0)
        return a;
    else
        Count_Find(n - 1, 2 * (a + 1));
}
