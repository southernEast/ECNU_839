#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZEA 10
#define SIZEB 5
void Merge(int* A, int n, int* B, int m);
void Print(int const* A, int n);
int cmp(const void* a, const void* b);

int main(int argc, char const *argv[])
{
	int A[SIZEA] = {0};
	int B[SIZEB] = {0};
	srand(time(0));
	for(int i = 0; i < SIZEA; i++)
        A[i] = rand() % 100;
    for(int i = 0; i < SIZEB; i++)
        B[i] = rand() % 100;                 //初始化

    qsort(A, SIZEA, sizeof(A[0]), cmp);
	qsort(B, SIZEB, sizeof(B[0]), cmp);
	printf("Before sort,\n");
    printf("Array A:\n");
	Print(A, SIZEA);
    printf("Array B:\n");
	Print(B, SIZEB);                           //有序数组AB

	printf("After sort:\n");
	Merge(A, SIZEA, B, SIZEB);
	Print(A, SIZEA + SIZEB);
	return 0;
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

void Print(int const *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d\t", A[i]);

	}
	printf("\n");
}

//void Merge(int *A, int n, int *B, int m)
//{
//    int i, j, k;
//    i = j = k = 0;
//    while(i < (n + k) && j < m)
//    {
//        if(A[i] < B[j])
//            i++;
//        else
//        {
//            for(int s = n + k; s > i; s--)
//                A[s] = A[s - 1];
//            A[i++] = B[j++];
//            k++;
//        }
//    }
//    if(j < m)
//        A[i++] = B[j++];
//}

void  Merge(int *A, int n, int *B, int m)
{
	int i = n - 1, j = m - 1, t = m + n - 1;
	while(i >= 0 && j >= 0)
	{
		if(A[i] >= B[j])
		{
			A[t] = A[i];
			i--;
		}
		else
		{
			A[t] = B[j];
			j--;
		}
		t--;
	}
	while(j >= 0)
        A[t--] = B[j--];
//    while(i >= 0)                                     //A若有剩余可直接保留在原位，故可省
//        A[t--] = A[i--];

}

