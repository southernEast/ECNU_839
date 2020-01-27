#include <stdio.h>
#include <math.h>
#define MAXSIZE 10

//int htoi(char *s)
//{
//    char *p = s;
//    int buf[MAXSIZE] = {0}, i = 0;
//    int ans = 0;
//    if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
//        p += 2;
//    while(*p)
//    {
//        if(*p >= '0' && *p <= '9')
//            buf[i++] = (*p - '0');
//        else if(*p >= 'a' && *p <= 'f')
//            buf[i++] = (*p - 'a' + 10);
//        else
//            buf[i++] = (*p - 'A' + 10);
//        p++;
//    }
//    --i;
//    int k = 0;
//    while(i >= 0)
//    {
//        int temp = 1;
//        for(int j = 0; j < k; j++)
//            temp *= 16;
//        ans += buf[i] * temp;
//        i--;
//        k++;
//    }
//
//    return ans;
//}

int htoi(char *s)
{
    if(s[1]!='\0')
    {
        //skip '0x'
        if(s[1]=='x' || s[1]=='X')
            s=s+2;
    }
    int i,sum=0;
    for(i=0;s[i];i++)
    {
        if('0'<=s[i] && s[i]<='9')
            sum=sum*16+(s[i]-'0');
        if('a'<=s[i] && s[i]<='f')
            sum=sum*16+10+(s[i]-'a');
        if('A'<=s[i] && s[i]<='F')
            sum=sum*16+10+(s[i]-'A');
    }
    return sum;
}

int main()
{
    printf("%d ", htoi("0xa") );
    return 0;
}
