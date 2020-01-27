// 1 2 4 3 0
// 有头结点情况
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
    NODE *head = (NODE *)malloc(sizeof(NODE));
    int data[] = {1, 2, 4, 3, 0};
    head->next = NULL;
    NODE *p;

    for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->next = NULL;
        p->data = data[i];
        head = Insert(head, p);
    }
    p = head;
    while(p->next)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    return 0;
}

NODE* Insert(NODE *head, NODE *p)
{
    NODE *q = head;

    while(q->next && q->next->data < p->data)     // 简化版
        q = q->next;
    p->next = q->next;
    q->next = p;
//    if(!q->next)                                // 空表情况
//    {
//        p->next = q->next;
//        q->next = p;
//    }
//    else
//    {
//        while(q->next)
//        {
//            if(q->next->data < p->data)         // 单链表中查找第一个不小于待插入元素
//                q = q->next;
//            else
//                break;
//        }
//        p->next = q->next;                      // 插在该元素前
//        q->next = p;
//
//    }

    return head;
}

