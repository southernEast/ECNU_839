#include <stdio.h>
#include <stdlib.h>
#define N 1000

struct DataType
{
    int acctNum;
    char name[10];
    float balance;
};

int main()
{
    int i;
    struct DataType record = { 0, "asd", 0.0 };
    FILE *cfp;

    if ((cfp = fopen("file.txt", "wb")) == NULL)
        printf("File could not be opened.\n");
    else
    {
        for (i = 0; i < N; i++)
            fwrite(&record, sizeof(struct DataType), 1, cfp);
//            fprintf(cfp, "%d %s %f\n", record.acctNum, record.name, record.balance);
        fclose(cfp);
    }

//    //查看写入结果
//    struct DataType ans;
//    cfp = fopen("file.txt", "rb");
//    for(int i = 0; i < N; i++)
//    {
//        fread(&ans, sizeof(struct DataType), 1, cfp);
//        printf("%d %s %f\n", ans.acctNum, ans.name, ans.balance);
//    }

}
