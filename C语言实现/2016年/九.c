//123##5##4##
//1 2 3 5 4
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Lnode Tree;
struct Lnode
{
    ElemType data;
    Tree *lchild, *rchild;
};

Tree *Create_Tree(void);              //PreOrder '#' to attach NULL node
void Pre_Order(Tree *T);
void Leaf_Link(Tree* T, Tree** head, Tree** pre);

int main()
{
    Tree *T;
    T = Create_Tree();
    puts("Pre Order:");
    Pre_Order(T);
    putchar('\n');

    Tree *head = NULL, *pre = NULL;
    Leaf_Link(T, &head, &pre);
    puts("Leaf node:");
    while(head)
    {
        printf("%c ", head->data);
        head = head->rchild;
    }

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
        printf("%c ", T->data);
        Pre_Order(T->lchild);
        Pre_Order(T->rchild);
    }
}

void Leaf_Link(Tree *T, Tree **head, Tree **pre)                    // head为叶子结点链表的首结点 pre为工作结点的前一个结点
{
    if(T)
    {
        if(!T->lchild && !T->rchild)
        {
            if(*head == NULL)
            {
                *head = T;
                *pre = T;
            }
            else
            {
                (*pre)->rchild = T;
                *pre = T;
            }
        }
        Leaf_Link(T->lchild, head, pre);
        Leaf_Link(T->rchild, head, pre);
    }
}

