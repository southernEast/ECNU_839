#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20

typedef struct adjnode
{
    int data;
    struct adjnode *next;
}AdjNode;
typedef struct adjlist
{
    AdjNode *first;
    int Vex;
}AdjList[MAXVEX];
typedef struct graph
{
    AdjList G;
    int vertex, edge;
}Graph;
typedef struct edge
{
    int v1, v2;
}Edge;

Graph *Create(int vexNum);
void Insert_Edge(Graph* Gra, Edge E);
void DFS(Graph* Gra, int v);
int Find_Path(Graph* Gra, int v1, int v2, int k);
int Find_Path2(Graph* Gra, int v1, int v2, int k, int path[]);
void Print_Path(int path[], int k);

int visited[MAXVEX] = {0};

int main()
{
    Graph *Gra = Create(6);
    Edge E[] =
    {
        {1, 2},
        {3, 2},
        {4, 1},
        {2, 5},
        {5, 4},
        {4, 3},
    };
    int n = sizeof(E) / sizeof(E[0]);
    for(int i = 0; i < n; i++)
        Insert_Edge(Gra, E[i]);
//    DFS(Gra, 5);
    printf("%d \n", Find_Path(Gra, 3, 4, 3));
    for(int i = 0; i < 6; i++)
        printf("%d %d\n", i, visited[i]);

    for(int i = 0; i < MAXVEX; i++)
        visited[i] = 0;
    int path[MAXVEX] = {0};
    printf("%d", Find_Path2(Gra, 3, 4, 3, path) );

    return 0;
}

Graph *Create(int vexNum)
{
    Graph *Gra = (Graph*)malloc(sizeof(Graph));
    Gra->edge = 0;
    Gra->vertex = vexNum;
    for(int i = 0; i < vexNum; i++)
    {
        Gra->G[i].first = NULL;
        Gra->G[i].Vex = i;
    }

    return Gra;
}

void Insert_Edge(Graph *Gra, Edge E)
{
    AdjNode *New = (AdjNode *)malloc(sizeof(AdjNode));      //无向图
    New->data = E.v2;
    New->next = Gra->G[E.v1].first;
    Gra->G[E.v1].first = New;
    Gra->edge++;
    New = (AdjNode *)malloc(sizeof(AdjNode));
    New->data = E.v1;
    New->next = Gra->G[E.v2].first;
    Gra->G[E.v2].first = New;
    Gra->edge++;
}


void DFS(Graph* Gra, int v)
{
    AdjNode *p = Gra->G[v].first;
    visited[v] = 1;
    printf("%d ", Gra->G[v].Vex);
    while(p)
    {
        if(!visited[p->data])
        {
            DFS(Gra, p->data);
        }
        p = p->next;
    }
}

int Find_Path(Graph *Gra, int v1, int v2, int k)                    // 类似DFS，查找v1到v2路径长度为k的路径是否存在
{
    if(v1 == v2 && k == 0)                                          // 找到该路径
        return 1;
    else if(k > 0)                                                  // 仍有距离，继续递归
    {
        visited[v1] = 1;
        AdjNode *p = Gra->G[v1].first;
        while(p)                                                    // 以当前顶点为起始顶点进行DFS
        {
            if(!visited[p->data] && Find_Path(Gra, p->data, v2, k - 1))     // 未访问的顶点进行访问，同时判断是否存在
                return 1;
            p = p->next;

        }
        visited[v1] = 0;                                            // 退出本次递归的时候清除标记，给下次访问做准备
    }
    return 0;
}

int Find_Path2(Graph* Gra, int v1, int v2, int k, int path[])       // 带路径数组的方法
{
    if(v1 == v2 && k == 0)
    {
        path[k] = v1;
        Print_Path(path, k);
        return 1;
    }
    else if(k > 0)
    {
        visited[v1] = 1;
        AdjNode *p = Gra->G[v1].first;
        path[k] = v1;
        while(p)
        {
            if(!visited[p->data] && Find_Path2(Gra, p->data, v2, k - 1, path))
                return 1;
            p = p->next;
        }
        visited[v1] = 0;
    }
    return 0;
}

void Print_Path(int path[], int k)                                  // 此时k指针是逆序的，先找到最后位置再输出
{
    while(path[k] != 0)
        k++;
    --k;
    while(k >= 0)
        printf("%d ", path[k--]);
    putchar('\n');
}
