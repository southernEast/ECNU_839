#include <stdio.h>

void Task(void)
{
    for(int i = 0; i <999; i++)
    {
        for(int j = 0; j < 999; j++)
        {
            for(int k = 0; k < 99; k++);
        }
    }
}

int main()
{
    int lotsa = 100;
    for(int i = 0; i < lotsa; i++){
        printf("\r%3d%%", (int)(100L * i / lotsa));     //百分比等待
//        printf("\b%c", "|/-\\"[i%4]);                   //旋转棒等待
        fflush(stdout);
        Task();

    }
    printf("\nDone\n");

    return 0;
}
