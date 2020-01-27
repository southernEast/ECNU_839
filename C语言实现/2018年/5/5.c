#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1200
#define MAXSIZE 20

struct Node
{
    char *name;                                                     //学生名字
    int number;                                                     //学号
    int score;                                                      //分数
};
typedef struct Node Lnode;

int cmp(const void *a, const void *b);

int main(int argc, char *argv[])
{
    FILE *fin1 = fopen(argv[1], "r");                               //班级信息文件1
    FILE *fin2 = fopen(argv[2], "r");                               //班级信息文件2
    FILE *fout = fopen(argv[3], "w");                               //输出结果文件
    int number, score;
    char name[MAXSIZE];                                             //学生名字缓存

    Lnode * data = (Lnode *)malloc(N * sizeof(Lnode));
    int i = 0;

    // document 1
    while(fscanf(fin1, "%s %d %d", name, &number, &score) != EOF)   //输入文件每一行以空格隔开
    {
        data[i].name = (char *)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(data[i].name, name);                                 //转存至data
        data[i].number = number;
        data[i].score = score;
        i++;
    }
    //document 2
    while(fscanf(fin2, "%s %d %d", name, &number, &score) != EOF)
    {
        data[i].name = (char *)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(data[i].name, name);
        data[i].number = number;
        data[i].score = score;
        i++;
    }

    qsort(data, i, sizeof(Lnode), cmp);

    for(int j = 0; j < i; j ++)                                     //输出
    {
        fprintf(fout, "%d %s %d\n", data[j].score, data[j].name, data[j].number);
    }

    fclose(fin1);
    fclose(fin2);
    fclose(fout);
    return 0;
}

int cmp(const void *a, const void *b)
{
    Lnode *m = (Lnode *)a;
    Lnode *n = (Lnode *)b;
    if(m->score != n->score)                                        //先比较成绩
        return n->score - m->score;
    else                                                            //成绩相同，比较学号
        return m->number - n->number;
}
