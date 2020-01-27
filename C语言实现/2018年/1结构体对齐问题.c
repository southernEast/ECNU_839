#include <stdio.h>
#include <stddef.h>

typedef struct testnode1
{
    char a;
    int b;
    char c;
}Test1;
typedef struct testnode2
{
    int a;
    char b;
    char c;
}Test2;

int main()
{
    printf("%d %d\n", sizeof(Test1), sizeof(Test2));                    //12 8
    printf("%d %d", offsetof(Test1, c), offsetof(Test2, c));            //8 5
}
