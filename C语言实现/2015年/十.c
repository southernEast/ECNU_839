//124##5##36##7##
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct tnode Tree;
struct tnode                            //标准形式存储结构
{
    ElemType data;
    Tree *lchild, *rchild;
};
typedef struct node NODE;
struct node                             //扩充形式存储结构
{
    ElemType data;
    NODE *lchild, *rchild, *parent;
};


Tree *Create_Tree(void);                //PreOrder '#' to attach NULL node
void Pre_Order(Tree *T);
NODE *Transform(Tree* T);
void Change(Tree* T1, NODE* T2);
// NODE *Change(Tree* T1, NODE* T2);
void Travel(NODE* T);

int main()
{
    Tree *T;
    T = Create_Tree();
    Pre_Order(T);
    putchar('\n');
    NODE *T2 = Transform(T);
    Travel(T2);

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


NODE *Transform(Tree *T)                            //创建扩充形式存储结构的根结点
{
    NODE *Root = (NODE *)malloc(sizeof(NODE));
    Root->data = T->data;
    Root->parent = NULL;
    Change(T, Root);
    return Root;
}

void Change(Tree *T1, NODE *T2)                     //进行左右子树的递归创建
{
    NODE *temp;
    if(T1->lchild)
    {
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = T1->lchild->data;
        T2->lchild = temp;
        temp->parent = T2;
        Change(T1->lchild, temp);
    }
    else
    {
        T2->lchild = NULL;
    }
    if(T1->rchild)
    {
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = T1->rchild->data;
        T2->rchild = temp;
        temp->parent = T2;
        Change(T1->rchild, temp);
    }
    else
    {
        T2->rchild = NULL;
    }
}

void Travel(NODE *T)
{
    if(T)
    {
        if(T->parent)
            printf("(%c parent:%c) ",T->data, T->parent->data);
        else
            printf("%c ", T->data);
        Travel(T->lchild);
        Travel(T->rchild);
    }
}

/*方法二*/

// NODE *Transform(Tree *T)                            //创建扩充形式存储结构的根结点
// {
//     NODE *T2 = Change(T, NULL);
//     return T2;
// }

// NODE * Change(Tree *T1, NODE *T2)                     //进行左右子树的递归创建
// {
//     if(T1)
//     {
//         NODE *temp = (NODE *)malloc(sizeof(NODE));
//         temp->data = T1->data;
//         temp->parent = T2;
//         temp->lchild = Change(T1->lchild, temp);
//         temp->rchild = Change(T1->rchild, temp);
//         return temp;
//     }
//     else
//         return NULL;
// }
