// 1 2 4 3 0
// 无头结点情况
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}NODE;

NODE* Insert(NODE *head, NODE *p);

int main()
{
    NODE *head = NULL;
    int data[] = {1, 2, 4, 3, 0};
    NODE *p;

    for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->next = NULL;
        p->data = data[i];
        head = Insert(head, p);
    }
    p = head;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}

NODE* Insert(NODE *head, NODE *p)
{
    if(!head)
        head = p;
    else if(head->data > p->data)
    {
        p->next = head;
        head = p;
    }
    else
    {
        NODE *q = head;
        while(q->next && q->next->data < p->data)
            q = q->next;
        p->next = q->next;
        q->next = p;
    }

    return head;
}

