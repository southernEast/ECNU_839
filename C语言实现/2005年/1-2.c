#include <stdio.h>
#include <string.h>

void sign_on(char str[], char *password)
{
    int a = 0;
    while ((strcmp(str, password) != 0) && a++ < 10)
    {
        printf("Enter password please:");
//        printf("%d\n", a);
        gets(str);
    }
}

int main()
{
    char pwd[]  = { "7788" };
    char str[] = { "5566" };
    sign_on(str, pwd);
}
