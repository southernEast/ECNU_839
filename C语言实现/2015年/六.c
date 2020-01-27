#include <stdio.h>

void Reverse(int A[], int n)
{
    int i, j, temp;
    i = 0, j = n - 1;
    while(i < j)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++, j--;
    }
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    Reverse(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
