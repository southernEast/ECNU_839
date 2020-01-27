#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10000

typedef struct msgNode MSG;
struct msgNode
{
    int number;
    char name[10];
    int score;
};

int cmp(const void *a, const void *b);

int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    if( (fin = fopen(argv[1], "r") ) == NULL || (fout = fopen(argv[2], "w") ) == NULL )
        exit(0);

    MSG tempBuff[MAXSIZE];
    MSG inBuff[MAXSIZE / 100];
    int randTemp, randNum[MAXSIZE / 100];
    int i = 0, j = 0;

    while(i < MAXSIZE && fscanf(fin, "%d %s %d", &tempBuff[i].number, tempBuff[i].name, &tempBuff[i].score) == 3)
        i++;
    fclose(fin);
    for( ; j < i / 100; j++)
    {
        int flag;
        do
        {
            randTemp = rand() % 1000;							// 取随机数，若有重复的，则继续取
            flag = 1;
            for(int k = 0; k < j; ++ k)
            {
                if(randNum[k] == randTemp)
                    flag = 0;
            }
        }while(! flag);
        randNum[j] = randTemp;
//        memcpy(&inBuff[j], &tempBuff[randNum[j]], sizeof(struct msgNode));
        inBuff[j] = tempBuff[randTemp];
    }
    qsort(inBuff, j, sizeof(MSG), cmp);
    for(int k = 0; k < j; ++k)
        fprintf(fout, "%d %s %d\n", inBuff[k].number, inBuff[k].name, inBuff[k].score);


    fclose(fout);
    return 0;
}

int cmp(const void *a, const void *b)
{
    MSG *m = (MSG *)a;
    MSG *n = (MSG *)b;
    return m->number - n->number;						// MSG*为指针形式 使用-> 记得要加括号
}
