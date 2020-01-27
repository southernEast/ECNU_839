#include <stdio.h>

typedef enum {red, yellow, blue} colour;

void holland(colour** pc, int n);
colour inspect(colour const *pc);
void swap(colour** pc, int a, int b);
void holland1(colour** pc, int n);

int main()
{
    colour c[3] = {red, yellow, blue};
    colour *pc[8] =
    {
        c + 1, c + 0, c + 0, c + 2, c + 1, c + 2, c + 0, c + 2
    };
    holland1(pc, 8);
    for(int i = 0; i < 8; i++)
        printf("%d ", inspect(pc[i]));
    return 0;
}

//void holland(colour **pc, int n)
//{
//    int Min, index = 0;                         //选择排序
//    for(int i = 0; i < n; i++)
//    {
//        Min = inspect(pc[i]);
//        for(int j = i + 1; j < n; j++)
//        {
//            if(Min > inspect(pc[j]))
//            {
//                Min = inspect(pc[j]);
//                index = j;
//            }
//        }
//        swap(pc, i, index);
//    }
//}

void holland(colour** pc, int n)
{
    int flag;
    for(int i = n - 1; i > 0; i--)              //冒泡排序
    {
        flag = 0;
        for(int j = 0; j < i; j++)
        {
            if(inspect(pc[j]) > inspect(pc[j + 1]))
            {
                swap(pc, j, j+1);
                flag = 1;
            }
        }
        if(!flag)
            break;
    }
}

colour inspect(colour const *pc)
{
    return *pc;
}

void swap(colour **pc, int a, int b)
{
    colour *temp = pc[b];
    pc[b] = pc[a];
    pc[a] = temp;

}

//王道 快速排序
void holland1(colour** pc, int n)
{
    int i = 0, j = 0, k = n - 1;        // i前面全为红色，k后面全为蓝色
    while(j < k)
    {
        switch( inspect(pc[j]) )
        {
        case red:
            swap(pc, i, j);
            i++, j++;
            break;
        case yellow:
            j++;
            break;
        case blue:                      // 没有j++防止交换后仍为蓝色
            swap(pc, j, k);
            k--;
            break;
        }
    }
}
