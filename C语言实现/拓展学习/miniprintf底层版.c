#include <stdio.h>
#include <stdarg.h>

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

void miniprintf(const char *fmt, ...)
{
    const char *p;
    int i;
    unsigned u;
    char *s;
    va_list argp;
    va_start(argp, fmt);

    for(p = fmt; *p != '\0'; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
            case 'c':
                i = va_arg(argp, int);
                putchar(i);
                break;

            case 'd':
                i = va_arg(argp, int);
                if(i < 0){
                    i = -i;
                    putchar('-');
                }
                fputs(baseconv(i, 10), stdout);
                break;

            case 'o':
                u = va_arg(argp, unsigned int);
                fputs(baseconv(u, 8), stdout);
                break;

            case 's':
                s = va_arg(argp, char *);
                fputs(s, stdout);
                break;

            case 'u':
                u = va_arg(argp, unsigned int);
                fputs(baseconv(u, 10), stdout);
                break;

            case 'x':
                u = va_arg(argp, unsigned int);
                fputs(baseconv(u, 16), stdout);
                break;

            case '%':
                putchar('%');
                break;
        }
    }

    va_end(argp);
}

int main()
{
    int num = 10;
    char c = 'q';
    char *s = "Hello";
    miniprintf("%%10: %d\n%%16: %d\n%c %s", num, num, c, s);
}
