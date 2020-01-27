#include <stdio.h>
//#include <string.h>

typedef struct
{
    int x;
    int y;
}POINT;

POINT Go(POINT p0, char steps[]);

int main()
{
    POINT p0 = {-4, 1}, p1;
    char steps[] = {"E2N3E7"};
    p1 = Go(p0, steps);
    printf("(%d,%d)", p1.x, p1.y);
    return 0;
}

POINT Go(POINT p0, char steps[])
{
    char *p = steps;
    POINT ans_p = p0;
    while(*p)                               //未到'\0'时，则命令字符串未结束
    {
        switch(*p)                          //根据当前命令字符串选择相应的方向
        {
            case 'E':
                p++;                        //字符串中，方向指令的下一个字符为移动距离
                ans_p.x += (*p - '0');
                break;
            case 'W':
                p++;
                ans_p.x -= (*p - '0');
                break;
            case 'N':
                p++;
                ans_p.y += (*p - '0');
                break;
            case 'S':
                p++;
                ans_p.y -= (*p - '0');
                break;
        }
        p++;
    }
    return ans_p;
}

//POINT Go(POINT p0, char steps[])                    //方法二 使用字符串数组进行控制
//{
//    int sLen = strlen(steps);
//
//    for (int i = 1; i < sLen; i+=2)
//    {
//        switch (steps[i - 1])
//        {
//        case 'N':
//            p0.y += (steps[i] - '0');
//            break;
//        case 'S':
//            p0.y -= (steps[i] - '0');
//            break;
//        case 'W':
//            p0.x -= (steps[i] - '0');
//            break;
//        case 'E':
//            p0.x += (steps[i] - '0');
//            break;
//        }
//    }
//
//    return p0;
//}
