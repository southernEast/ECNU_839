#include <stdio.h>
#define L 128

typedef struct
{
    int length;
    char value[L];
}LNUM;

int add(LNUM a, LNUM b, LNUM *c);
int add2(LNUM a, LNUM b, LNUM* c);

int main()
{
    LNUM a = {
        {128},
        {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        }
    };

    LNUM b = {
        {128},
        {
            1, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9,
        }
    };

    LNUM c = { 0 };
    for (int i = 0; i < a.length; i ++)
    {
        printf("%d", a.value[128 - a.length + i]);
    }

    printf("\r\n+\r\n");

    for (int i = 0; i < b.length; i ++)
    {
        printf("%d", b.value[128 - b.length + i]);
    }

    printf("\r\n=\r\n");

    if (add(a, b, &c) == 0)
    {
        for (int i = 0; i < c.length; i ++)
        {
            printf("%d", c.value[128 - c.length + i]);
        }
    }
    else
    {
        printf("Overflow!\r\n");
    }

    putchar('\n');
    if (add2(a, b, &c) == 0)
    {
        for (int i = 0; i < c.length; i ++)
        {
            printf("%d", c.value[128 - c.length + i]);
        }
    }
    else
    {
        printf("Overflow!\r\n");
    }


    return 0;
}

int add(LNUM a, LNUM b, LNUM *c)
{
    int i, temp, ad = 0;
    for(i = 1; i <= a.length || i <= b.length; i++)         //i <= L 也可
    {
        temp = a.value[L - i] + b.value[L - i] + c->value[L - i];   //a + b + 进位信息
        if(temp > 9)
        {
            ad = temp / 10;                 //储存一次计算进位的结果
            // ad = temp - 9;
            if(i + 1 > L)
                return 1;                   //有进位的时候判断是否超出范围
        }
        c->value[L - i] = temp % 10;        //计算结果的个位数据
        c->value[L - i - 1] = ad;           //储存进位数据，为下一次计算做准备
    }
    c->length = i - 1;                      //减去最后i++多加的1

    return 0;
}

int add2(LNUM a, LNUM b, LNUM* c)
{
    int i, temp, cflag = 0;
    for(i = 1; i <= a.length || i <= b.length; i++)
    {
        temp = a.value[L - i] + b.value[L - i] + cflag;
        if(temp > 9)
        {
            cflag = 1;
            temp %= 10;
        }
        else
            cflag = 0;
        c->value[L - i] = temp;
    }
    if(i > L && cflag)
        return 1;
    if(cflag)
    {
        c->value[L - i] = 1;
        c->length = i;
    }
    else
        c->length = i - 1;
    return 0;
}
