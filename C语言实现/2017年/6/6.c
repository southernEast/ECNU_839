#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
typedef double ElemType;

struct Node
{
    ElemType x1, y1;
    ElemType x2, y2;
    ElemType distant;                                             //与原点距离
    ElemType length;                                              //对角线长度
    ElemType area;                                                //矩形面积
};
typedef struct Node Lnode;

int cmp(const void *a, const void *b);

int main()
{
    FILE *fin = fopen("data.in", "r");
    FILE *fout = fopen("data.out", "w");
    ElemType x1, y1, x2, y2;
    int j = 0;
    Lnode * data = (Lnode *)malloc(N * sizeof(Lnode));

    while(fscanf(fin, "%lf %lf %lf %lf", &x1, &y1, &x2, &y2) == 4) //double浮点数录入 采用%lf的格式！！
    {
        if(x1 != x2 && y1 != y2)                                //两点未重合则写入      浮点数比较 有待学习！！
        {
            if(x1 < x2 && y1 < y2)                              //找出较小点
            {
                data[j].x1 = x1;
                data[j].y1 = y1;
                data[j].x2 = x2;
                data[j].y2 = y2;
            }
            else
            {
                data[j].x1 = x2;
                data[j].y1 = y2;
                data[j].x2 = x1;
                data[j].y2 = y1;
            }
            data[j].distant = sqrt(data[j].x1 * data[j].x1 + data[j].y1 * data[j].y1);  //计算左下角点到原点距离
            data[j].length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));       //对角线长度
            data[j].area = (x2 - x1) * (y2 - y1);                                       //面积
            j++;
        }
    }

    qsort(data, j, sizeof(Lnode), cmp);

    for(int i = 0; i < j; i++)
    {
        fprintf(fout, "%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", data[i].x1, data[i].y1,
                data[i].x2, data[i].y2, data[i].area, data[i].distant, data[i].length); //test
//        fprintf(fout, "%f\t%f\t%f\t%f\n", data[i].x1, data[i].y1, data[i].x2, data[i].y2);

    }

    fclose(fin);
    fclose(fout);

    return 0;
}

int cmp(const void *a, const void *b)
{
    Lnode *m = (Lnode *)a;
    Lnode *n = (Lnode *)b;
    if(m->area != n->area)                                              //先比较面积
        return (m->area - n->area);
    else if(m->distant != n->distant)                                   //再比较距离
        return (m->distant - n->distant);
    else if(m->length != n->length)                                     //比较对角线长度
        return (m->length - n->length);
    else                                                                //最后按照右边顶点大小
        return (m->y2 - n->y2);
}
