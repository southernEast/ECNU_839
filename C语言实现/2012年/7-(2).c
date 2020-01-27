#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef int ElemType;

typedef struct anode
{
    ElemType data;
    struct anode *next;
}AdjNode;

typedef struct gnode
{
    AdjNode *AdjList[MAXSIZE];
    int vertex, edge;
}Graph;

typedef struct enode
{
    ElemType v1, v2;
}Edge;

Graph *Create_Null(int n);
void Insert_Edge(Graph* G, Edge E[], int n);
void DFS(Graph* G, int visited[], int v);
int Judge(Graph* G);

int main()
{
    Edge E[] =
    {
        {1, 2},
        {1, 3},
        {1, 4},
//        {2, 5},
//        {2, 6},
        {5, 6},
        {4, 5},
        {3, 4},                 // 参考6-(2)图
    };
    int n = sizeof(E) / sizeof(E[0]);
    Graph *G = Create_Null(7);
    Insert_Edge(G, E, n);
//    DFS(G, 4);
    printf("%d ", Judge(G));

    return 0;
}

int Judge(Graph *G)
{
    int visited[MAXSIZE] = {0};
    DFS(G, visited, 1);
    putchar('\n');
    for(int i = 1; i <G->vertex; i++)
        if(visited[i] == 0)
            return 0;
    return 1;

}

//int visited[MAXSIZE] = {0};
void DFS(Graph *G, int visited[], int v)
{
    AdjNode *p;
    printf("%d ", v);
    visited[v] = 1;
    p = G->AdjList[v];
    while(p)
    {
        if(!visited[p->data])
            DFS(G, visited, p->data);
        p = p->next;
    }
}

Graph *Create_Null(int n)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->vertex = n;
    G->edge = 0;
    for(int i = 0; i < n; i++)
        G->AdjList[i] = NULL;
    return G;
}

void Insert_Edge(Graph *G, Edge E[], int n)
{
    AdjNode *p, *q;

    for(int i = 0; i < n; i++)
    {
        p = (AdjNode *)malloc(sizeof(AdjNode));         //无向图
        p->data = E[i].v2;
        p->next = G->AdjList[ E[i].v1 ];
        G->AdjList[ E[i].v1 ] = p;
        q = (AdjNode *)malloc(sizeof(AdjNode));
        q->data = E[i].v1;
        q->next = G->AdjList[ E[i].v2 ];
        G->AdjList[ E[i].v2 ] = q;
        G->edge += 2;
    }
}
