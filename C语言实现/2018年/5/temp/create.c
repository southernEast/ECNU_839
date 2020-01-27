#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    FILE *fout1, *fout2;
    fout1 = fopen("class1.in", "w");
    fout2 = fopen("class2.in", "w");
    srand(time(0));
    for(int i = 0; i < 1000; i++)
    {
        fprintf(fout1, "%d %s %d\n", rand() % 10000, "test", rand() % 100);
        fprintf(fout2, "%d %s %d\n", rand() % 10000, "test", rand() % 100);
    }
    fclose(fout1);
    fclose(fout2);
    return 0;
}
