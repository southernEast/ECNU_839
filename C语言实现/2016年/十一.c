#include <stdio.h>
#include <stdlib.h>
#define MAXVERTEX 20
#define VERTEX 6                            //6个顶点

int visited[MAXVERTEX] = {0};               //标记访问数组

typedef struct node AdjNode;
struct node
{
    int data;
    struct node *next;
};
typedef struct Vnode
{
    AdjNode *FirstEdge;

}AdjList[MAXVERTEX];
typedef struct Granode Graph;
struct Granode
{
    int vertex, edge;
    AdjList G;
};
typedef struct Enode
{
    int v1, v2;
}Edge;                                          //邻接表表示法

typedef struct qnode
{
    int parent, data;
}Queue;

Graph *Create_Graph(int VertexNum);             //建立空的邻接表
void Insert_Edge(Graph* Gra, Edge E);           //插入边
void DFS(Graph* Gra, int v, int* vNum, int* eNum);
int Is_Tree1(Graph* Gra, int vertex);
int Is_Tree2(Graph* Gra, int vertex);

int main()
{
    Graph *Gra = Create_Graph(VERTEX);
    Edge E[5] =
    {
        {1, 3},
        {3, 2},
        {2, 5},
        {3, 6},
        {6, 4},             //P213 图7.4.3 (e)
    };
    for(int i = 0; i < 5; i++)
        Insert_Edge(Gra, E[i]);
    printf("%d %d", Is_Tree1(Gra, VERTEX), Is_Tree2(Gra, VERTEX));

    return 0;
}

Graph *Create_Graph(int VertexNum)
{
    Graph *Gra = (Graph *)malloc(sizeof(Graph));
    Gra->edge = 0;
    Gra->vertex = VertexNum;
    for(int i = 0; i <= VertexNum; i++)
        Gra->G[i].FirstEdge = NULL;

    return Gra;
}

void Insert_Edge(Graph *Gra, Edge E)               //无向图
{
    AdjNode *New = (AdjNode *)malloc(sizeof(AdjNode));
    New->data = E.v2;
    New->next = Gra->G[E.v1].FirstEdge;
    Gra->G[E.v1].FirstEdge = New;
    New = (AdjNode *)malloc(sizeof(AdjNode));
    New->data = E.v1;
    New->next = Gra->G[E.v2].FirstEdge;
    Gra->G[E.v2].FirstEdge = New;

    Gra->edge += 2;
}

void DFS(Graph *Gra, int v, int *vNum, int *eNum)
{
    ++*vNum;
    visited[v] = 1;
    AdjNode *p = Gra->G[v].FirstEdge;
    while(p)
    {
        ++*eNum;
        if(!visited[p->data])
            DFS(Gra, p->data, vNum, eNum);
        p = p->next;
    }
}

// 无向图G是一棵树的条件是：G必须是无回路连通图或是有n-1条边的连通图


// 采用后一个条件，DFS遍历图，统计访问到的边数和顶点数，检测是否满足n个顶点，n-1条边且图是连通的
int Is_Tree1(Graph *Gra, int vertex)
{
    for(int i = 0; i < MAXVERTEX; i++)
        visited[i] = 0;
    int vNum = 0, eNum = 0;

    DFS(Gra, 1, &vNum, &eNum);
    if(eNum == 2 * (vNum - 1) && vNum == vertex)
        return 1;
    else
        return 0;
}


// 采用前一个条件，BFS遍历图，Queue保存当前结点和父邻结点的信息，检测是否存在回路是否连通
int Is_Tree2(Graph* Gra, int vertex)
{
    int visited[MAXVERTEX] = {0};
    Queue Q[MAXVERTEX];
    int front, rear, vNum = 0;
    front = rear = -1;

    Q[++rear].data = 1;                     //从顶点1开始
    Q[rear].parent = -1;
    visited[1] = 1;
    ++vNum;
    while(front < rear)
    {
        int u = Q[++front].data;
        int parent = Q[front].parent;
        AdjNode *p = Gra->G[u].FirstEdge;
        while(p)
        {
            if(p->data == parent)               // 父邻结点跳过
                p = p->next;
            else if(visited[p->data] == 1)      // 存在回路
                return 0;
            else
            {
                Q[++rear].data = p->data;
                Q[rear].parent = u;
                visited[p->data] = 1;
                ++vNum;
                p = p->next;
            }
        }
    }

    if(vNum == vertex)                          // 判断连通
        return 1;
    else
        return 0;
}
