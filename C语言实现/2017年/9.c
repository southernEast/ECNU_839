//654##3##1##
//654##3##1#0##
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef char ElemType;
typedef struct Lnode Tree;
struct Lnode
{
    ElemType data;
    Tree *lchild, *rchild;
};


Tree *Create_Tree(void);                //PreOrder '#' to attach NULL node
void Pre_Order(Tree *T);
int Judge(Tree* T);
int Judge_Heap(Tree* T, int* n);

int main()
{
    Tree *T = Create_Tree();
    Pre_Order(T);
    putchar('\n');
    int n = 0;
    printf("%d %d", Judge(T), Judge_Heap(T, &n));

    return 0;
}

Tree *Create_Tree(void)              //PreOrder '#' to attach NULL node
{
    ElemType data;
    Tree *T;
    scanf("%c", &data);
    if(data == '#')
        T = NULL;
    else
    {
        T = (Tree *)malloc(sizeof(Tree));
        T->data = data;
        T->lchild = Create_Tree();
        T->rchild = Create_Tree();
    }
    return T;
}



void Pre_Order(Tree *T)
{
    if(T)
    {
        printf("%c", T->data);
        Pre_Order(T->lchild);
        Pre_Order(T->rchild);
    }
}

/*判断完全二叉树思想：采用层次遍历，将所有结点加入队列，
包括空结点。当遇到空结点时，查看后面是否有非空结点，若
有，则不是完全二叉树*/

int Judge(Tree *T)                  //不仅要判断结点大小关系，而且要判断完全二叉树
{
    if(!T)
        return 1;
    Tree *Queue[MAXSIZE];
    int front, rear;
    front = rear = -1;
    Queue[++rear] = T;
    while(front != rear)
    {
        T = Queue[++front];
        if(T)
        {
            if(T->lchild && T->lchild->data > T->data)      //结点大小关系不满足
                return 0;
            if(T->rchild && T->rchild->data > T->data)
                return 0;
            Queue[++rear] = T->lchild;
            Queue[++rear] = T->rchild;
        }
        else
        {
            while(front != rear)
            {
                T = Queue[++front];
                if(T)                                       //不是完全二叉树
                    return 0;
            }
        }
    }

    return 1;
}

int Judge_Heap(Tree *T, int *n)
{
    int a = 1, b = 1;
    int n1 = 0, n2 = 0;
    if(T)
    {
        if(T->lchild)
            a = (T->data >= T->lchild->data) && Judge_Heap(T->rchild, &n1);
        if(T->rchild && a)
            b = (T->data >= T->rchild->data) && Judge_Heap(T->rchild, &n2);
        if(n1 < n2)
            a = b = 0;
        *n = n1 + n2 + 1;
    }
    else
        *n = 0;
    return a && b;
}
