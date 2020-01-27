#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 9999
typedef struct msgNode MSG;
struct msgNode
{
    int number;
    char name[10];
    int score;
};

int main()
{
    FILE * fp = fopen("students.txt", "w");
    MSG buff;
    int randNum[MAXSIZE], randTemp, flag = 1;

    srand(time(0));
    for(int i = 0; i < MAXSIZE; i++)
    {
        do
        {
            randTemp = rand() % 999999;
            flag = 1;
            for(int i = 0; i < MAXSIZE; i++)
            {
                if(randNum[i] == randTemp)
                {
                    flag = 0;
                    break;
                }
            }
        }while(!flag);
        randNum[i] = randTemp;
        buff = (MSG){
            randTemp,
            "bei",
            rand() % 100
        };
        fprintf(fp, "%d %s %d\n", buff.number, buff.name, buff.score);
    }
    fclose(fp);

    return 0;
}
