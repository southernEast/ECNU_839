#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20

void Solve(char* s);
int Operate(char* buf, int num, int isX, int isRight);

int main()
{
    char s[] = {"6x-x=x+4"};
    Solve(s);
    return 0;
}

void Solve(char *s)
{
    int nNum, xNum, isRight;
    char buf[MAXSIZE] = {0}, x;
    nNum = xNum = isRight = 0;

    for( ; *s; s++)
    {
        if((*s >= '0' && *s <= '9') || *s == '+' || *s == '-')
        {
            if(*s == '+' || *s == '-')
                nNum = Operate(buf, nNum, 0, isRight);
            strncat(buf, s, 1);                                 //注意不管是否进行了运算都要拷贝，此程序将运算符好看作正负号进行计算
        }
        if(*s == '=')
        {
            nNum = Operate(buf, nNum, 0, isRight);              //计算等式右边前先将左边进行运算
            isRight = 1;
        }
        if(*s >= 'a' && *s <= 'z')
        {
            x = *s;
            xNum = Operate(buf, xNum, 1, isRight);
        }
    }
    nNum = Operate(buf, nNum, 0, isRight);                      //最后结束时数字运算
    printf("%c = %.3f", x, (float)nNum / (float)xNum);
}

int Operate(char *buf, int num, int isX, int isRight)
{
    int op = atoi(buf);                                         //atoi()函数："+1" -> 1 "-1" -> -1 "+" -> 0  "-" -> 0 遇到空字符停止转换

    if(!isX)
    {
        if(!isRight)
            num -= op;
        else
            num += op;
    }
    else
    {
        if(op == 0)                                             //如果是单个字母的情况如x或-x
        {
            if(buf[0] == '-')
                op = -1;
            else
                op = 1;
        }
        if(!isRight)
            num += op;
        else
            num -= op;
    }
    memset(buf, 0, MAXSIZE);                                    //记得清空缓存数组

    return num;
}
