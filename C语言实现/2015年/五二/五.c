#include <stdio.h>
#include <string.h>
#define MAXSIZE 36

int main()
{
    FILE *fp = fopen("dataIN.txt", "r");
    int n, data[MAXSIZE][MAXSIZE] = {0}, mark[MAXSIZE + 1], flag = 1;
    fscanf(fp, "%d", &n);
    for(int i = 0; i < n * n; i++)
    {
        for(int j = 0; j < n * n; j++)
            fscanf(fp, "%d", &data[i][j]);
    }
    fclose(fp);

    for(int i = 0; flag == 1 && i < n * n; i++)          //row
    {
        memset(mark, 0, MAXSIZE + 1);
        for(int j = 0; j < n * n; j++)
            mark[ data[i][j] ]++;
        for(int j = 1; j <= n * n; j++)
        {
            if(mark[j] != 1)
                flag = 0;
        }
    }
    for(int j = 0; flag == 1 && j < n * n; j++)         //col
    {
        memset(mark, 0, MAXSIZE + 1);
        for(int i = 0; i < n * n; i++)
            mark[ data[i][j] ]++;
        for(int i = 1; i <= n * n; i++)
        {
            if(mark[i] != 1)
                flag = 0;
        }
    }
    for(int i = 0; flag == 1 && i < n * n; i += n)      //matrix
    {
        for(int j = 0; flag == 1 && j < n * n; j += n)
        {
            memset(mark, 0, MAXSIZE + 1);
            for(int k = 0; k < n; k++)
            {
                for(int l = 0; l < n; l++)
                {
                    mark[ data[i + k][j + l] ]++;
                }
            }
            for(int k = 1; k <= n * n; k++)
            {
                if(mark[k] != 1)
                    flag = 0;
            }
        }
    }

//    for(int i = 0; i < n * n; i++)
//    {
//        for(int j = 0; j < n * n; j++)
//            printf("%d ", data[i][j]);
//        putchar('\n');
//    }
    if(flag == 1)
        printf("Yes");
    else
        printf("No");

    return 0;
}
