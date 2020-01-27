#include <stdio.h>

main()
{
    int d[9]; 
    int i, j, k; 
    int *p[3], *q;
    for (i = 0; i < 9; ++i)
        d[i] = i + 1;       // d[0]=1 d[1]=2 ... d[8]=9
    for (i = 0; i < 3; ++i)
        p[i] = d + 3*i;     
    for (k = 0; k < 3; ++k) 
    {
        for (i = 0; i < 3; ++i) 
        {
            for (j = 0; j < 3; ++j)
                printf("%3d", p[i][j]);
            printf("\n");
        }
        printf("\n");
        for (q = p[2], j = 1; j >= 0; --j)
            p[j + 1] = p[j]; // 后面的行的指针等于前面的行的指针
        p[0] = q;
    }
}