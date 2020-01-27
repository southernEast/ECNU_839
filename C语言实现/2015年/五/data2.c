#include <stdio.h>
#define MAXN 6
#define MAXRANGE 36
int main(void)
{
    FILE *fp;
    int RANGE,ORDER;
    int i,j,k1,k2;
    int judgeFlag=1;
    int sudoku[MAXRANGE][MAXRANGE];
    char bucket[MAXN*MAXN];

    fp=fopen("dataIn.txt","r");
    fscanf(fp,"%d",&ORDER);
    RANGE=ORDER*ORDER;
    for(i=0;i<RANGE;i++)
        for(j=0;j<RANGE;j++)
            fscanf(fp,"%d",&sudoku[i][j]);

    for(i=0;judgeFlag==1 && i<RANGE;i++)
    {
        for(j=0;j<=RANGE;j++)
            bucket[j]=0;
        for(j=0;j<RANGE;j++)
            bucket[sudoku[i][j]]+=1;
        for(j=1;j<=RANGE;j++)
            if(bucket[j]!=1){
                judgeFlag=0;
                break;
            }
    }

    for(j=0;judgeFlag==1 && j<RANGE;j++)
    {
        for(i=0;i<RANGE+1;i++)
            bucket[i]=0;
        for(i=0;i<RANGE;i++)
            bucket[sudoku[i][j]]+=1;
        for(i=1;i<=RANGE;i++)
            if(bucket[i]!=1){
                judgeFlag=0;
                break;
            }
    }

    for(k1=0;judgeFlag==1 && k1<RANGE;k1+=ORDER)
    {
        for(k2=0;judgeFlag==1 && k2<RANGE;k2+=ORDER)
        {
            for(i=0;i<RANGE+1;i++)
                bucket[i]=0;

            for(i=0;i<ORDER;i++)
                for(j=0;j<ORDER;j++)
                    bucket[sudoku[k1+i][k2+j]]++;

            for(i=1;i<=ORDER;i++)
                if(bucket[i]!=1)
                {
                    judgeFlag=0;
                    break;
                }
        }
    }
    if(judgeFlag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
