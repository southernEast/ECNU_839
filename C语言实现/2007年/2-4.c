#include <stdio.h>
#include <string.h>

char *s(char **p, char *pn);
int main(int argc, char *argv[])   // argument input HZ0755 AB BJ01
{
    char i, *r = NULL, *a[] = { "BJ01", "SH02-1", "C", "HZ0755", 0 };
    for (i = 1; i < argc; i ++)
    {
        r = s(a, argv[i]);
        if (r) printf("founded %s\n", r);
        else printf("unfounded %s\n", argv[i]);
    }
    return 0;
}

char *s(char **p, char *pn)
{
    for (; *p; ++p) // simply find string in "string array"
        if (!strcmp(*p, pn))
            return *p;
    return (*p);
}

// output:
//founded HZ0755
//unfounded AB
//founded BJ01
