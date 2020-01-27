#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 80

typedef struct node
{
    char name[80];
    double sum;
}Data;

int main(int argc, char *argv[])
{
    FILE *fin, *fout;
    if((fin = fopen(argv[1], "r")) == NULL)
        exit(0);
    Data buf[MAXSIZE];
    int i = 0;
    char name[80];
    double sum;

    if(fscanf(fin, "%s %lf", name, &sum) == 2)						//处理首行信息  注意double %lf
    {
        strcpy(buf[i].name, name);
        buf[i].sum = sum;
    }
    while(fscanf(fin, "%s %lf", name, &sum) == 2)					//后续
    {
        if(strcmp(buf[i].name, name) == 0)							//同种商品，相加
            buf[i].sum += sum;
        else														//不同商品，创建新类
        {
            i++;
            strcpy(buf[i].name, name);
            buf[i].sum = sum;
        }
    }
    fclose(fin);

    if((fout = fopen(argv[2], "w")) == NULL)
        exit(0);
    for(int k = 0; k <= i; k++)										//double 输出可%f
        fprintf(fout, "%s %.2f\n", buf[k].name, buf[k].sum);
    fclose(fout);

    return 0;
}
