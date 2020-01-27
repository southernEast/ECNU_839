//ABDH###E#I##CF##G##
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef struct tnode
{
    char data;
    struct tnode *lchild, *rchild;
}Tree;

Tree *Create(void);
void Pre_Order(Tree* T);
int Get_Breadth1(Tree* T);
int Get_Height1(Tree* T);
int Get_Height2(Tree* T);
int Get_Breadth2(Tree* T);

int main()
{
    Tree *T =Create();
    Pre_Order(T);
    printf("\nHeight1:\t%d", Get_Height1(T));
    printf("\nHeight2:\t%d", Get_Height2(T));
    printf("\nBreadth1:\t%d", Get_Breadth1(T));
    printf("\nBreadth2:\t%d", Get_Breadth2(T));


    return 0;
}

int Get_Height1(Tree *T)                             // 树的高度递归解法
{
    if(!T)
        return -1;
    else
    {
        int left, right;
        left = Get_Height1(T->lchild);
        right = Get_Height1(T->rchild);
        return left > right ? ++left : ++right;
    }
}
int Get_Height2(Tree* T)                            // 树的高度非递归解法
{
    if(!T)
        return -1;
    Tree *Queue[MAXSIZE];
    int front, rear, last, level = -1;
    front = rear = -1;
    Queue[++rear] = T;
    last = rear;
    while(front < rear)
    {
        T = Queue[++front];
        if(T->lchild)
            Queue[++rear] = T->lchild;
        if(T->rchild)
            Queue[++rear] = T->rchild;
        if(last == front)
        {
            last = rear;
            level++;
        }

    }
    return level;
}

int Get_Breadth1(Tree *T)                                // 树的宽度不设置层次数组解法
{
    Tree *Queue[MAXSIZE];
    int front, rear, last, maxBd, cnt;
    front = rear = -1;
    cnt = 0;
    Queue[++rear] = T;
    last = rear;
    maxBd = 1;


    while(front < rear)
    {

        T = Queue[++front];
        if(T->lchild)
        {
            Queue[++rear] = T->lchild;
            cnt++;
        }
        if(T->rchild)
        {
            Queue[++rear] = T->rchild;
            cnt++;
        }
        if(front == last)
        {
            if(maxBd < cnt)
            {
                maxBd = cnt;
            }
            last = rear;
            cnt = 0;
        }
    }

    return maxBd;
}

int Get_Breadth2(Tree* T)                               // 树的宽度设置层次数组解法
{
    if(!T)
        return 0;
    Tree *Queue[MAXSIZE];
    int front, rear, index[MAXSIZE], num;
    front = rear = -1;

    Queue[++rear] = T;
    index[rear] = 1;
    while(front < rear)
    {
        T = Queue[++front];
        num = index[front];
        if(T->lchild)
        {
            Queue[++rear] = T->lchild;
            index[rear] = num + 1;
        }
        if(T->rchild)
        {
            Queue[++rear] = T->rchild;
            index[rear] = num + 1;
        }
    }

    int max = 0, cnt = 1, last = index[0];
    for(int i = 1; i <= rear; i++)
    {
        if(index[i] == last)
            cnt++;
        else
        {
            last = index[i];
            if(cnt > max)
                max = cnt;
            cnt = 1;
        }
    }
    return max;
}

Tree *Create(void)
{
    Tree *T;
    char data;

    scanf("%c", &data);
    if(data == '#')
        T = NULL;
    else
    {
        T = (Tree *)malloc(sizeof(Tree));
        T->data = data;
        T->lchild = Create();
        T->rchild = Create();
    }
    return T;
}

void Pre_Order(Tree *T)
{
    if(T)
    {
        printf("%c ", T->data);
        Pre_Order(T->lchild);
        Pre_Order(T->rchild);
    }
}
