#include <stdio.h>

long long Calcute(int n, int k);

int main()
{
    printf("%lld", Calcute(50,25));
    return 0;
}

long long Calcute(int n, int k)
{
    long long matrix[51][51];
    if(n < 1 || n > 50)
    {
        printf("Please input n between 1 and 50!\n");
        return 0;
    }
    if(k < 1 || k > n)
    {
        printf("Please input k between 1 and n!\n");
        return 0;
    }
    for(int i = 0; i <= n; ++i)
    {
        matrix[i][0] = 1;
        matrix[i][i] = 1;
        for(int j = 1; j < i; ++j)
        {
            matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
        }
    }

    return matrix[n][k];
}
