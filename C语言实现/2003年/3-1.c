//p12/p25
//No.12/No.25
//p12/p25
//2
#include <stdio.h>
#include <string.h>

int Replace(char s[], char ch, char str[], char t[]);

int main()
{
    char str1[] = "p12/p25";
    char str2[20] = "";
    int n;

    puts(str1);
    n = Replace(str1, 'p', "No.", str2);
    puts(str2);
    puts(str1);
    printf("%d", n);
    return 0;
}
//
//int Replace(char s[], char ch, char str[], char t[])
//{
//    int cnt = 0;
//    char *p = s, *q = s;                //p标记源字符串操作位置，q标记待拷贝字符串位置
//    while(*p)
//    {
//        if(*p == ch)
//        {
//            *p = '\0';                  //标记源字符串结束点，用作strcat拷贝记号
//            strcat(t, q);               //拷贝ch前的字符串至t[]中
//            strcat(t, str);             //拷贝str字符串至t[]中
//            q = p + 1;                  //标记下一段的开始
//            *p = ch;                    //恢复源字符串
//            cnt++;
//        }
//        p++;
//    }
//    strcat(t, q);                       //将末尾字符串添加
//    return cnt;
//}

int Replace(char s[], char ch, char str[], char t[])              //解法二
{
    int cnt, lenS, lenStr, k, i;
    cnt = k = i = 0;
    lenS = strlen(s);
    lenStr = strlen(str);
    while(i < lenS)
    {
        if(s[i] == ch)
        {
            for(int j = 0; j < lenStr; j++)
                t[k++] = str[j];
            i++;
            cnt++;
        }
        else
            t[k++] = s[i++];
    }
    t[k] = '\0';
    return cnt;
}
