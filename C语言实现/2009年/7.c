//4 2 1 9999 9999 3 9999 9999 6 5 9999 9999 7 9999 9999
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 50

typedef struct node
{
    int data;
    struct node *lchild, *rchild;
}Tree;

Tree *Get_Node(Tree* T, int k);
Tree *Create(void);
int Judge(Tree* T, int x, int y, int z);
bool isAncestor(Tree* T, int x, int y, int z);
void PreOrder(Tree* xNode, Tree* yNode, Tree* zNode);
int Post_Order(Tree* T, int x, int y, int z);

int main()
{
    Tree *T = Create();
    int x, y, z;
    x = 2, y = 1, z = 3;
    printf("%d\n", Judge(T, x, y, z) );
    printf("%d\n", isAncestor(T, x, y, z) );
    printf("%d\n", Post_Order(T, x, y, z) );
    return 0;
}

/**思想： 在值为x的结点的子树中分别查找值为y和z的结点**/
int Judge(Tree *T, int x, int y, int z)
{
    Tree *xNode, *yNode, *zNode;
    xNode = Get_Node(T, x);                                     
    yNode = Get_Node(xNode, y);                 //在x的子树中分别查找值为y和z的结点
    zNode = Get_Node(xNode, z);
    if(yNode && zNode)                          //xNode 和 zNode都不空则存在
        return 1;
    else
        return 0;
}

Tree *Get_Node(Tree *T, int k)                  //在T的子树中查找值为k的结点
{
    Tree *L, *R;
    if(T)
    {
        if(T->data == k)
            return T;
        else
        {
            L = Get_Node(T->lchild, k);         
            if(L)                               //左子树中查找到
                return L;
            R = Get_Node(T->rchild, k);
            if(R)                               //右子树中查找到
                return R;
        }
    }
    return NULL;
}

Tree *Create(void)
{
    Tree *T;
    int data;
    scanf("%d", &data);
    if(data == 9999)
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

//其他方法
bool findY = false, findZ = false;
bool isAncestor(Tree *T, int x, int y, int z)
{
    Tree *xNode, *yNode, *zNode;
    xNode = Get_Node(T, x);
    yNode = Get_Node(T, y);
    zNode = Get_Node(T, z);
    PreOrder(xNode, yNode, zNode);
    if(findY && findZ)
        return true;
    else
        return false;

}

void PreOrder(Tree *xNode, Tree *yNode, Tree *zNode)
{
    if(yNode == xNode)
        findY = true;
    if(zNode == xNode)
        findZ = true;
    if(xNode->lchild)
        PreOrder(xNode->lchild, yNode, zNode);
    if(xNode->rchild)
        PreOrder(xNode->rchild, yNode, zNode);
}

/**思想： 对树T进行后序非递归遍历， 当遍历到某结点时，栈中所有元素即为该结点的祖先**/
int Post_Order(Tree *T, int x, int y, int z)            
{
    Tree *Stack[MAXSIZE], *temp[MAXSIZE], *last = NULL;
    int top = -1, i;
    while(T || top != -1)
    {
        if(T)
        {
            Stack[++top] = T;
            T = T->lchild;
        }
        else
        {
            T = Stack[top];
            if(T->rchild && last != T->rchild)
            {
                T = T->rchild;
                Stack[++top] = T;
                T = T->lchild;
            }
            else
            {
                top--;
                last = T;
                if(T->data == y)
                {
                    for(i = 0; i <= top; i++)
                        temp[i] = Stack[i];
                }
                if(T->data == z)
                    break;
                T = NULL;
            }
        }
    }
    int flag = 0;
    for(int j = 0; j <= i; j++)
    {
        if(temp[j]->data == x)
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
        return 0;
    for(int j = 0; j <= top; j++)
        if(Stack[j]->data == x)
            return 1;
    return 0;
}
