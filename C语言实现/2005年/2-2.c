#include <stdio.h>

main()
{
    int c;
    if((c = getchar()) != '0')
    {
        main();
        printf("%c", c);
    }
}
