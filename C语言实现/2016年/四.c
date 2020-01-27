//5 123 124 011 185 222
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10

typedef struct node
{
    char *data;
    struct node *next;
}NODE;

NODE *sortLinkedList(NODE* h);
void PrintList(NODE* h);
NODE *newNode(void);
NODE *CreateLinkedList(void);

int main()
{
    NODE *h = CreateLinkedList();
    PrintList(h);
    h = sortLinkedList(h);
    PrintList(h);

    return 0;
}

NODE *sortLinkedList(NODE *h)                           //基于冒泡排序
{
    if(!h)
        return NULL;
    NODE *current, *end = NULL;
    int flag = 1;

    while(flag == 1)
    {
        flag = 0;
        current = h;
        while(current->next != end)
        {
            if(strcmp(current->data, current->next->data) > 0)
            {
                char *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                flag = 1;
            }
            current = current->next;
        }
        end = current;
    }

    return h;
}

void PrintList(NODE *h)
{
    while(h)
    {
        printf("%s ", h->data);
        h = h->next;
    }
    putchar('\n');
}

NODE* newNode(void)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->next = NULL;
    return node;
}


NODE* CreateLinkedList(void)                                //不带头结点的单链表
{
    NODE *prenode = newNode();
    NODE *h = prenode, *node = NULL;
    char *temp;
    int n;
    scanf("%d", &n);
    temp = (char *)malloc(MAXSIZE * sizeof(char));
    scanf("%s", temp);
    prenode->data = temp;
    for (int i = 1; i<n; ++i)
    {
        node = newNode();
        temp = (char *)malloc(MAXSIZE * sizeof(char));
        scanf("%s", temp);
        node->data = temp;
        prenode->next = node;
        prenode = node;
        node = node->next;
    }
    return h;
}
