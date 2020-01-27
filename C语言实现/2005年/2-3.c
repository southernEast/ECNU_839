#include <stdio.h>

int main()
{
    int i, j;
    printf("*****\n");
    for (i = 0; i < 3; i ++)
    {
        j = 3;
        switch(i)
        {
        case 0:
            while(j)
            {
                case 1:
                    printf("i=%d, ", i);
                case 2:
                    printf("j=%d, ", j); j--;
                efaultd:
                    ;
            }
//        case 3:
//            printf("test\n");
        }
        printf("---\n");
    }
    return 1;
}
