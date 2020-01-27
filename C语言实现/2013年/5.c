#include <stdio.h>
#include <string.h>

int isRight(char *s);

int main()
{
    printf("%d", isRight("123456789123456783"));
    return 0;
}

int isRight(char *s)
{
    int temp[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
//    char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    char check[] = {"10X98765432"};
//    char *check = "10X98765432";
    int ans = 0;

    if(strlen(s) != 18)                         //判断总串长
        return 0;
    for(int i = 0; i < 17; ++i)                 //检测前17位
    {
        if(s[i] < '0' || s[i] > '9')
            return 0;
        ans += (s[i] - '0') * temp[i];
    }
    if(check[ans % 11] == s[17])                //检测第18位
        return 1;
    else
        return 0;


}
