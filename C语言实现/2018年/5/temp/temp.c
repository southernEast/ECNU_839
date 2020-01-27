#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define MAXSIZE 3000
//两个班的成绩分别存放在两个班的成绩分别存放在两个文件当中。 每个文件有多行，
//每行都是由空格分隔的学号、姓名和成绩。现在要将两个班的成绩合并到一起进行排序
//按照成绩从高到低，如果相同则按学号由小到大排序。将结果输出一个文件当中。两个
//输入文件名与输出文件名使用命令行参数指定。

typedef struct node
{
    int number;
    int score;
    char name[MAX];
}Data;

int cmp(const void *a, const void *b);

int main(int argc, char *argv[])
{
    FILE *fin1, *fin2, *fout;
    if((fin1 = fopen(argv[1], "r")) == NULL)
        exit(0);
    if((fin2 = fopen(argv[2], "r")) == NULL)
        exit(0);
    Data classes[MAXSIZE];
    int i = 0;

    while(fscanf(fin1, "%d %s %d", &classes[i].number, classes[i].name, &classes[i++].score) == 3)
        ;
    while(fscanf(fin2, "%d %s %d", &classes[i].number, classes[i].name, &classes[i++].score) == 3)
        ;
    qsort(classes, i, sizeof(classes[0]), cmp);
    fout = fopen(argv[3], "w");
    for(int k = 0; k < i; k++)
        fprintf(fout, "%d\t%s\t%d\n", classes[k].number, classes[k].name, classes[k].score);
    fclose(fin1);
    fclose(fin2);
    fclose(fout);

    return 0;
}

int cmp(const void *a, const void *b)
{
    Data *m = (Data *)a, *n = (Data *)b;
    if(m->score != n->score)
        return n->score - m->score;
    else
        return m->number - n->number;
}
