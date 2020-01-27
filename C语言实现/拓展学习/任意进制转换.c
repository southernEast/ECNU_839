#include <stdio.h>
#include <stdlib.h>

/**decimal to 2-16**/
char *baseconv(unsigned int num, int base)
{
    static char buf[33];
//    char *buf = (char *)malloc(sizeof(char) * 33);
    char *p;

    if(base < 2 || base > 16)
        return NULL;

    p = &buf[sizeof(buf) - 1];
    *p = '\0';

    do{
        *--p = "0123456789abcdef"[num % base];
        num /= base;
    }while(num != 0);

    return p;
}

int main()
{
    printf("%s", baseconv(10, 2));
    return 0;
}
