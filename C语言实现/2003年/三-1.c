#include <stdio.h>

void Shift_Down(int A[], int i, int n);
void Create_Heap(int A[], int n);
void Heap_Insert(int A[], int *n, int x);

int main()
{
    int A[8] = {1, 2, 5, 0, 8, 9, 4};
    int n = 7;
    Create_Heap(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    putchar('\n');

    Heap_Insert(A, &n, 10);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}

void Shift_Down(int A[], int i, int n)              // 调整成大根堆
{
    int temp = A[i];
    while((i = i * 2 + 1) < n)
    {
        if(A[i + 1] > A[i])
            i++;
        if(A[i] > temp)
            A[(i - 1) / 2] = A[i];
        else
            break;
    }
    A[(i - 1) / 2] = temp;
}

void Create_Heap(int A[], int n)                    // 从下往上开始调整
{
    for(int i = (n - 1) / 2; i >= 0; i--)
    {
        Shift_Down(A, i, n);
    }
}

void Heap_Insert(int A[], int *n, int x)
{
    int i = *n;
    while(i > 0 && A[(i - 1) / 2] < x)
    {
        A[i] = A[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    A[i] = x;
    (*n)++;

}
