#include <stdio.h>
#include <string.h>
// input: 37592087, 5

// 78029573
// 7802573
// 702573
// 02573
// 0253
// 023
// printf:320
// delete the max number in the char
void del(char a[])
{
    int i, col, max;
    for(max = a[0], col = 0, i = 1; a[i]; i++)  //注意'0'不会被判断为0
        if (a[i] > max)
            max = a[i], col = i;
    for(i = col; a[i] = a[i + 1]; i ++); // this isn't a error, the judgement position will always return the a[i+1] until a[i]=NULL (because a is a very long string)
}

main()
{
    char a[20]; long n; int i,s;
    printf("scanf(\"%%ld,%%d\", &n, &s):"); scanf("%ld,%d", &n, &s);
    for (i = 0; n; i++)
    {
        a[i] = n%10 + '0';
        n/=10;                          // 数组a中所存的为字符形式的数字：'7' '8' '0' '2' '9' '5' '7' '3'
    }
    a[i] = n;                           // 此处0为数字0，用于接下来循环结束的判断，与数组a中字符数字不同,作用类同于'\0'
    for (i = 0; i < s; i ++)
        del(a);
    n = strlen(a);
    // printf("%d\n", n);
    for (i = n-1; i >=0; i--)
        printf("%c", a[i]);
    printf("\n");
}
