#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare1(const void *a, const void *b)
{
    return atoi(*(char(*)[80])b) - atoi(*(char(*)[80])a);
}

int compare2(const void *a, const void *b)
{
    char (*x)[80] = a, (*y)[80] = b;
    int diff = strlen(x) - strlen(y);
    return diff ? diff : strcmp(x, y);
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    char a[100][80];
    int i, cnt = 0;
    while (fscanf(fp, "%s", a[cnt]) == 1)
    {
        printf("%s ", a[cnt++]);
    }
    printf("\n");
    qsort(a, cnt, sizeof(char[80]), compare1);
    for (i = 0; i < cnt; i ++)
    {
        printf("%s ", a[i]);
    }
    printf("\n");
    qsort(a, cnt, sizeof(char[80]), compare2);
    for (i = 0; i < cnt; i ++)
    {
        printf("%s ",a[i]);
    }
    printf("\n");
    return 0;
}
