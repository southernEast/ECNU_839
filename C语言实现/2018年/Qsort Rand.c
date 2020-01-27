//rand number vertion
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXSIZE 20

int cmp(const void* a, const void* b);
void swap(void* left, void* right, int size);
void Qsort(void* base, int num, int size, int(* cmp)(const void* a, const void* b));
void sort(void* base, int left, int right, int size, int(* cmp)(const void* a, const void* b));

int main()
{
    int A[MAXSIZE];
    srand(time(0));
    for(int i = 0; i < MAXSIZE; i++)
    {
        A[i] = rand() % MAXSIZE;
        printf("%3d ", A[i]);
    }
    putchar('\n');
    Qsort(A, MAXSIZE, sizeof(A[0]), cmp);
    for(int i = 0; i < MAXSIZE; i++)
        printf("%3d ", A[i]);

    return 0;
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

void swap(void *left, void *right, int size)
{
    for(int i = 0; size > 0; i++, size--)
    {
        char temp = *((char *)left + i);
        *((char *)left + i) = *((char *)right + i);
        *((char *)right + i) = temp;
    }
}

void Qsort(void *base, int num, int size, int (*cmp)(const void *a, const void *b))
{
    sort(base, 0, num - 1, size, cmp);
}

void sort(void *base, int left, int right, int size, int (*cmp)(const void *a, const void *b) )
{
    if(left >= right)
        return ;
    void *pleft, *plast, *pmid;
    int last, i;

    pleft = base + left * size;
    pmid = pleft + (right - left) / 2 * size;
    swap(pleft, pmid, size);
    last = left;
    plast = (char *)base + left * size;
    for(i = left + 1; i <= right; i++)
    {
        void *pi = base + i * size;
        if(cmp(pi, pleft) < 0)
        {
            ++last;
            plast = base + last * size;
            swap(plast, pi, size);
        }
    }
    swap(plast, pleft, size);
    sort(base, left, last - 1, size, cmp);
    sort(base, last + 1, right, size, cmp);

}
