#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 40

typedef struct adjnode
{
    int data;
    struct adjnode *next;
}AdjNode;
typedef struct gnode
{
    AdjNode *G[MAXSIZE];
    int vertex, edge;
}Graph;
typedef struct enode
{
    int v1, v2;

}Edge;

Graph *Create(int n);
void Insert_Edge(Graph* Gra, Edge E);
void DFS(Graph* Gra, int v);
void DFS_Non(Graph* Gra, int v);
void DFS3(Graph* g, int v);

int main()
{
    Edge E[] =
    {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4},
        {4, 2},
        {3, 5}
    };
    int n = sizeof(E) / sizeof(E[0]);
    Graph *Gra = Create(6);
    for(int i = 0; i < n; i++)
        Insert_Edge(Gra, E[i]);
    DFS(Gra, 0);
    putchar('\n');
    DFS_Non(Gra, 0);
    putchar('\n');
    DFS3(Gra, 0);

    return 0;
}

Graph *Create(int n)
{
    Graph *Gra = (Graph *)malloc(sizeof(Graph));
    for(int i = 0; i < n; i++)
    {
        Gra->G[i] = NULL;
    }
    Gra->edge = 0;
    Gra->vertex = n;

    return Gra;
}

void Insert_Edge(Graph *Gra, Edge E)
{
    AdjNode *t = (AdjNode *)malloc(sizeof(AdjNode));
    t->data = E.v2;
    Gra->edge++;
    t->next = Gra->G[E.v1];
    Gra->G[E.v1] = t;
}

int visited[MAXSIZE] = {0};
void DFS(Graph *Gra, int v)
{
    visited[v] = 1;
    printf("%d ", v);
    AdjNode *p = Gra->G[v];
    while(p)
    {
        if(!visited[p->data])
            DFS(Gra, p->data);
        p = p->next;
    }
}

void DFS_Non(Graph *Gra, int v)
{
    int Stack[MAXSIZE], top = -1;
    int visited[MAXSIZE] = {0};
    AdjNode *p;

    Stack[++top] = v;
    visited[v] = 1;
    while(top != -1)
    {
        v = Stack[top--];
        printf("%d ", v);
        p = Gra->G[v];
        while(p)
        {
            if(!visited[p->data])
            {
                Stack[++top] = p->data;
                visited[p->data] = 1;
            }
            p = p->next;
        }
    }
}
void DFS3(Graph *g, int v)
{
  int visited[MAXSIZE] = {0};
  int Stack[MAXSIZE], top = -1;
  AdjNode *p;
  Stack[++top] = v;
  while(top != -1)
  {
    v = Stack[top--];
    visited[v] = 1;
    printf("%d ", v);
    p = g->G[v];
    while(p)
    {
      if (visited[p->data] == 0)
      {
        Stack[++top] = p->data;
      }
      p = p->next;
    }
  }
}
