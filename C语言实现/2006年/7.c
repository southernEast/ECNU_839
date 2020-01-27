//输入数据：1 2 6 999 999 999 999 7 999 999 999 999 999 999 3 8 999 999 999 999 9 999 999 999 999 999 999 4 11 999 999 999 999 999 999 999 5 12 999 999 999 999 999 999 999
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30
#define END 999

typedef struct node
{
    int data;
    struct node *child[4];
}Tree;

Tree *Create(void);
void Pre_Order(Tree* T);
void Transform(Tree* t, int r[][12]);
void Print_Matrix(int r[][12]);

int main()
{
    int r[12][12] = {0};
    Tree *t = Create();
    Pre_Order(t);
    putchar('\n');
    Print_Matrix(r);
    Transform(t, r);
    Print_Matrix(r);

    return 0;
}

void Print_Matrix(int r[][12])
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
            printf("%d ", r[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void Pre_Order(Tree *T)
{
    if(T)
    {
        printf("%d ", T->data);
        for(int i = 0; i < 4; i++)
            Pre_Order(T->child[i]);
    }
}

Tree *Create(void)
{
    int data;
    Tree *T;
    scanf("%d", &data);
    if(data == END)
        T = NULL;
    else
    {
        T = (Tree *)malloc(sizeof(Tree));
        T->data = data;
        for(int i = 0; i < 4; i++)
            T->child[i] = Create();
    }

    return T;
}

void Transform(Tree *t, int r[][12])                            //层次遍历转换图
{
    Tree *Stack[MAXSIZE];
    int top = -1;
    Stack[++top] = t;
    while(top != -1)
    {
        t = Stack[top--];
        for(int i = 0; i < 4; i++)
        {
            if(t->child[i])
            {
                Stack[++top] = t->child[i];
                r[t->data - 1][t->child[i]->data - 1] = 1;      //无向图
                r[t->child[i]->data - 1][t->data - 1] = 1;
            }
        }
    }
}
