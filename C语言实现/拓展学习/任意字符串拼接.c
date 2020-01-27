#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char *vstrcat(const char *first, ...)
{
    size_t len;
    char *buf;
    va_list argp;
    char *p;

    if(first == NULL)
        return NULL;

    len = strlen(first);

    va_start(argp, first);

    while((p = va_arg(argp, char *)) != NULL)
        len += strlen(p);

    va_end(argp);

    buf = malloc(len + 1);

//    if(buf == NULL);
//        return NULL;

    strcpy(buf, first);

    va_start(argp, first);

    while((p = va_arg(argp, char *)) != NULL)
        strcat(buf, p);

    va_end(argp);

    return buf;
}

int main()
{
    char *s = vstrcat("Hello,", "world", (char *)NULL);
    printf("%s", s);

    return 0;
}
