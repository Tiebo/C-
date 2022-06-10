#include <stdio.h>
#include <stdlib.h>
#define MVNum 100

int visited[MVNum];

typedef struct
{
    char vexs[MVNum];       //顶点向量
    int arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum, arcnum;     //顶点数，边数
} AMGraph;

int DFS(AMGraph G, int v);  //以v为起点遍历图G（v所在的连通分量）
int DFSTraverse(AMGraph G); //遍历图G

int LocateVex(AMGraph G, char u) //查询顶点u的下标
{
    int i, count;
    for (i = 0; i < G.vexnum; ++i)
        if (u == G.vexs[i])
            return i;
    return -1;
}

void CreateUDG(AMGraph &G)
{
    int i = 0, j, count;
    char v1, v2;
    v1 = getchar();
    while (v1 != '#')
    {
        G.vexs[i] = v1;
        i++;
        v1 = getchar();
    }
    G.vexnum = i;
    for (i = 0; i < G.vexnum; ++i) //初始化邻接矩阵，所有元素均为0
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = 0;
    scanf("\n%c %c", &v1, &v2);
    while (v1 != '#' && v2 != '#')
    {
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = 1;
        G.arcs[j][i] = 1;
        scanf("\n%c %c", &v1, &v2);
    }
}
int main()
{
    AMGraph G;
    CreateUDG(G);
    printf("%d", DFSTraverse(G));
    return 0;
}

int DFS(AMGraph G, int v) //以v为起点遍历图G（v所在的连通分量）
{
    int con = 1;
    visited[v] = 1;
    for (int i = 0; i < G.vexnum; i++)
    {
        int j = G.arcs[v][i];
        if (!visited[j] && G.vexs[j]!='#')
        {
            con++;
            DFS(G, j);
        }
    }
    return con;
}
int DFSTraverse(AMGraph G)
{
    int con = 0;
    int v;
    for (v = 0; v < G.vexnum; ++v)
        visited[v] = 0;
    for (v = 0; v < G.vexnum; ++v)
        if (!visited[v])
            con+=DFS(G, v);
    return con;
}