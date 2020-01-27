#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int*)b;
}

void solve(FILE **fin, FILE **fout)
{
    int a[1000], b[1000], c[1000], i, bi, ci, N;
    fscanf(*fin, "%d", &N);
    for(bi = ci = i = 0; i < N; i++)
    {
        fscanf(*fin, "%d", a+i);
        if(a[i] % 2 != 0)
            b[bi++] = a[i];
        else
            c[ci++] = a[i];
    }
    qsort(b, bi, sizeof(b[0]), cmp);
    qsort(c, ci, sizeof(c[0]), cmp);
    for(bi = i = 0; i < N; i++)
        fprintf(*fout, "%d ", a[i] % 2 != 0 ? b[bi++] : c[--ci]);
}

int main(int argc, char **argv)
{
    int i,t;
    FILE *fin = fopen(argv[1], "r"), *fout = fopen(argv[2], "w");
    fscanf(fin, "%d\n", &t);
    for(i = 0; i < t; i++)
    {
        fprintf(fout, "\nCase #%d: ", i+1);
        solve(&fin, &fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
