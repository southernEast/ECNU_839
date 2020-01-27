//1 4 5
//1 2 3 4 5
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}List;

List *Create_List(int n);
void Print_List(List* head);
int Inclusion(List* A, List* B);

int main()
{
    List *A, *B;
    A = Create_List(3);
    B = Create_List(5);
    Print_List(A);
    Print_List(B);
    printf("%d ", Inclusion(A, B));

    return 0;
}

List *Create_List(int n)        //带头结点
{
    List *head = (List *)malloc(sizeof(List)), *temp, *p;
    p = head;
    int data;

    while(n--)
    {
        temp = (List *)malloc(sizeof(List));
        scanf("%d", &data);
        temp->data = data;
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }

    return head;
}

void Print_List(List *head)
{
    while(head->next)
    {
        printf("%d ", head->next->data);
        head = head->next;
    }
    putchar('\n');
}

int Inclusion(List *A, List *B)
{
    List *pa = A->next, *pb = B->next;
    if(!pa)
        return 1;
    while(pb && pa->data >= pb->data)                   // pa->data >= pb->data 可省，不过会有多余的步骤
    {
        if(pa->data == pb->data)
            return Inclusion(pa, pb);
        else
            pb = pb->next;
    }

    return 0;
}
