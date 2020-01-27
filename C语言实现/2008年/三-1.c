#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode *List;
struct Lnode
{
    int data;
    List next;
};

List Print_List(List L);
List Create_List(int n);
List New_Node(int data);
void Delete_Dup(List L);

int main()
{
    List A;
    int n;
    scanf("%d", &n);
    A = Create_List(n);
    Print_List(A);
    Delete_Dup(A);
    Print_List(A);

    return 0;
}

List Create_List(int n)
{
    int data;
    List L = (List)malloc(sizeof(struct Lnode));
    List p = L;
    while(n--)
    {
        scanf("%d", &data);
        p->next = New_Node(data);
        p = p->next;
    }

    return L;
}

List New_Node(int data)
{
    List L = (List)malloc(sizeof(struct Lnode));
    L->data = data;
    L->next = NULL;
    return L;
}

List Print_List(List L)
{
    List p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Delete_Dup(List L)
{
    List p = L->next, q, t;
    while(p)
    {
        q = p;
        while(q->next)
        {
            if(q->next->data == p->data)
            {
                t = q->next;
                q->next = t->next;
                free(t);
            }
            else
                q = q->next;
        }
        p = p->next;
    }
}
