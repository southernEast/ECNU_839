#include <stdio.h>
//#include <string.h>

void Delete(char* str, char ch);

int main()
{
    char str[] = {"all for you , my dear"};
    puts(str);
    Delete(str, 'a');
    puts(str);
    return 0;
}

void Delete(char *str, char ch)
{
    int i = 0, k = 0;
    while(str[k] != '\0')
    {
        if(str[k] != ch)
            str[i++] = str[k++];
        else
            k++;
    }
    str[i] = '\0';
}
