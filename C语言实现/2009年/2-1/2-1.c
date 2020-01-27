#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81
#define N 10

int compare1(const void* a, const void *b)
{
    return strlen(*(char(*)[LEN])b) - strlen(*(char(*)[LEN])a);		// 强制转换成合适类型，在C中可选
}

int compare2(const void* a, const void *b)
{
    return strcmp(*(char(*)[LEN])a, *(char(*)[LEN])b);				// 强制转换成合适类型，在C中可选
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    char s[N][LEN];
    int i, cnt = 0;
    while (fscanf(fp, "%s", s[cnt]) == 1)
    {
        printf("%s ", s[cnt++]);
    }
    printf("\n");
    qsort(s, cnt, sizeof(char[LEN]), compare1);
    for (i = 0; i < cnt; i ++)
    {
        printf("%s ", s[i]);
    }
    printf("\n");
    qsort(s, cnt, sizeof(char[LEN]), compare2);         // '#' 的 ASCII码为23 '+'的 ASCII码为2B 故'+' 应在后
    for (i = 0; i < cnt; i ++)
    {
        printf("%s ", s[i]);
    }
    printf("\n");
    return 0;
}
