/*****   核心思想：                         *****/
/*****   任何一元一次方程都可以转换为      *****/
/*****   ax = b的形式（a、b为常数）        *****/
/*****   然后用x = b / a进行求解           *****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateAns(char *s);
int opreate(char *buf, int sum, int right, int mod);

int main()
{
    char s[80] = {"6a-5+1=2-2a"};
//    printf("%d\n", calculateAns("6x-x=-x"));
//    printf("%d", atoi("+"));                                   // atoi()函数："+1" -> 1 "-1" -> -1 "+" -> 0  "-" -> 0 遇到空字符停止转换
    calculateAns("6x-x=x+4");
    calculateAns(s);
    return 0;
}

int calculateAns(char *s)
{
    char ans_c;
    char buf[80] = {0};
    int right = 0;
    int xSum = 0, nSum = 0;
    while(*s)                                                   // 遍历整个表达式
    {
        if( (*s >= '0' && *s <= '9') || *s == '-' || *s == '+')
        {
            if(*s == '+' || *s == '-')                          // 遇到'+'或'-'进行求值
                nSum = opreate(buf, nSum, right, 1);
            strncat(buf, s, 1);                                 // 是数字则拷贝进buf缓存
        }
        if(*s == '=')                                           // 遇到'='说明左等式已访问完毕，right标志位置1，同时将左等式求值
        {
            nSum = opreate(buf, nSum, right, 1);
            right = 1;
        }
        if(*s >= 'a' && *s <= 'z')                              // 若为a-z中的任一字母，说明为未知数
        {                                                       // ans_c标记未知数，并将未知数的系数进行求值
            ans_c = *s;
            xSum = opreate(buf, xSum, right, 0);
        }
        s++;                                                    // 继续访问表达式的下一个位
    }
    nSum = opreate(buf, nSum, right, 1);                        // 最后结束的时候没有符号，但对于最后一个数字也要进行求值
                                                                // 未知数部分不需要，因为在遇到任何字母都会对系数进行求值
    printf("%c = %.3f\n", ans_c, (float)nSum / (float)xSum);
    return 1;

}

int opreate(char *buf, int sum, int right, int mod)
{
    int op = atoi(buf);
    if(mod == 1)                                                // mod = 1 ：数字求值 mod = 0 ：字母求值
    {
        if(right)                                               // right 为判断等式左右的标志位
            sum += op;                                          // 数字和左边为减法，右边为加法
        else
            sum -= op;

    }
    if(mod == 0)
    {
        if(op == 0)
        {
            if(buf[0] == '-')                                   // 为'x'或'-x'的情况设置op的运算值
                op = -1;
            else
                op = 1;
        }
        if(right)                                               // 系数和左边为加法，右边为减法
            sum -= op;
        else
            sum += op;
    }
    memset(buf, 0, 80);                                         // 缓存区清空
    return sum;
}

