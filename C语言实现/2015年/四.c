//1 2 2 4 2 1 3 1

#include <stdio.h>
#include <stdlib.h>
struct Lnode
{
	int data;
	struct Lnode *next;
};
typedef struct Lnode Link;

void RemoveDuplicntes(Link *head);
void Print(Link *head);
void Create(Link *head, int n);

int main()
{
    Link *head = (Link *)malloc(sizeof(struct Lnode));
    Create(head, 8);
    Print(head);
    RemoveDuplicntes(head);
    Print(head);
    return 0;
}

void Create(Link *head, int n)                          //创建n个结点的链表，带头结点
{
    int data;
    while(n--)
    {
        Link *p = (Link *)malloc(sizeof(struct Lnode));
        scanf("%d", &data);
        p->data = data;
        p->next = NULL;
        head->next = p;
        head = head->next;
    }
}

void Print(Link *head)                                  //输出链表
{
    while(head->next)
    {
        printf("%d ", head->next->data);
        head = head->next;
    }
    putchar('\n');
}

void RemoveDuplicntes(Link *head)                       //删除链表
{
    Link *current = head->next;                         //标记当前比较的结点
    Link *post, *t;                                     // post标记当前比较结点的后续结点，t用于删除结点
    while(current)                                      //当前待比较结点记录
    {
        post = current;
        while(post->next)                               //后续比较结点记录
        {
            if(current->data == post->next->data)       //相等则删除
            {
                t = post->next;
                post->next = t->next;
                free(t);
            }
            else                                        //注意：只有在不相等的时候才执行此语句，否则会多跳过结点！！
                post = post->next;
        }
        current = current->next;
    }
}

//void RemoveDuplicntes(Link *head)
//{
//    Link *curr,*prev,*tmp;
//    curr=head->next;
//    while(curr)
//    {
//        tmp=curr->next;
//        prev=curr;
//        while(tmp)
//        {
//            if(tmp->data == curr->data)
//            {
//                prev->next=tmp->next;
//                free(tmp);
//                tmp=prev;
//            }
//            prev = tmp;
//            tmp=tmp->next;
//        }
//        curr=curr->next;
//    }
//}
