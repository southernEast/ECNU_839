#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 500
void Print(int A[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%2d ", A[i]);
    putchar('\n');
}
void Sort(int A[], int n)
{
    int i = 0, j = n - 1, temp = A[i];
    while(i < j)
    {
        while(i < j && A[j] % 2 == 0)
            j--;
        if(i < j)
            A[i] = A[j];
        while(i < j && A[i] % 2 != 0)
            i++;
        if(i < j)
            A[j] = A[i];
    }
    A[i] = temp;
}

int main()
{
    int A[MAXSIZE] = {0};
    srand(time(0));
    for(int i = 0; i < MAXSIZE; i++)
        A[i] = rand() % 100;
    Print(A, MAXSIZE);
    Sort(A, MAXSIZE);
    Print(A, MAXSIZE);

    return 0;
}
