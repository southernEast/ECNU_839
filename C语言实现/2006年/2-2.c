#include <stdio.h>
#include <string.h>

int Reduce(char s[]);
int Reduce1(char s[]);

int main()
{
    char str[] = "Press***12225";
    int k = Reduce1(str);
    printf("%s\n%d", str, k);
    return 0;
}

int Reduce(char s[])
{
    char *p = s;
    int cnt = 0;
    while(*(p + 1))
    {
        if(strncmp(p, p + 1, 1) == 0)
        {
            strcpy(p, p + 1);
            cnt++;
            continue;               //找到重复字符，返回位置，继续寻找
        }
        p++;
    }
    return cnt;
}

int Reduce1(char s[])
{
    int cnt = 0, i = 1, k = 0;      //k记录新的字符串字符地址，i为原字符串标记位置
    while(s[i])
    {
        if(s[i] == s[k])            //若相等，则跳过这个字符
        {
            i++;
            cnt++;
        }
        else                        //否则，拷贝，注意是k是先++
            s[++k] = s[i++];
    }
    s[++k] = '\0';
    return cnt;
}
