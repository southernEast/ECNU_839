#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef struct node
{
    char data;
    struct node *lchild, *rchild;
}Tree;

Tree *Create(void);
void Post_Order(Tree *T);
void Pre_Order(Tree* T);
void Ancestor(Tree* T, char x);
int Ancestor1(Tree* T, char x);

char s[] = "ABD##E##C##";
char *p = s;

int main()
{
    Tree *T = Create();
    Post_Order(T);
//    Pre_Order(T);
    putchar('\n');
//    Ancestor(T, 'E');
    Ancestor1(T, 'D');
}

Tree *Create(void)
{

    if(*p)
    {
        Tree *T;
        if(*p == '#')
        {
            T = NULL;
//            p++;
        }
        else
        {
            T = (Tree *)malloc(sizeof(Tree));
            T->data = *p;
            p++;
            T->lchild = Create();
            p++;
            T->rchild = Create();
        }
        return T;
    }
}

void Ancestor(Tree *T, char x)                          //后序遍历非递归
{
    Tree *Stack[MAXSIZE], *last = NULL;
    int top = -1;
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
            if(T->rchild && T->rchild != last)
            {
                T = T->rchild;
                Stack[++top] = T;
                T = T->lchild;
            }
            else
            {

                if(T->data == x)
                    break;
                top--;
                last = T;
                T = NULL;
            }
        }
    }
    for(int i = 0; i < top; i++)
        printf("%c ", Stack[i]->data);


}

int Ancestor1(Tree* T, char x)
{
    if(T == NULL)
        return 0;
    else if( (T->lchild && T->lchild->data == x) || (T->rchild && T->rchild->data == x) )
    {
        printf("%c ", T->data);
        return 1;
    }
    else if(Ancestor1(T->lchild, x) || Ancestor1(T->rchild, x))
    {
        printf("%c ", T->data);
        return 1;
    }
    else
        return 0;
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
void Post_Order(Tree* T)
{
    if(T)
    {
        Post_Order(T->lchild);
        Post_Order(T->rchild);
        printf("%c ", T->data);
    }
}
