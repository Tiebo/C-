#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;
int g[N][N];
int dist[N];
int n;
int path[N];
bool st[N];

void init()
{
    // A B C D E F G H I  J  K  L   M  N
    // 1 2 3 4 5 6 7 8 9 10 11 12  13 14
    memset(g, 0x3f, sizeof(g));
    g[1][2] = 1;
    g[2][1] = 1;
    g[1][3] = 1;
    g[3][1] = 1;
    g[1][4] = 3;
    g[4][1] = 3;
    g[3][5] = 1;
    g[5][3] = 1;
    g[5][6] = 1;
    g[6][5] = 1;
    g[2][7] = 2;
    g[7][2] = 2;
    g[4][13] = 3;
    g[13][4] = 3;
    g[13][14] = 5;
    g[14][13] = 5;
    g[14][11] = 6;
    g[11][14] = 6;
    g[6][9] = 2;
    g[9][6] = 2;
    g[9][12] = 3;
    g[12][9] = 3;
    g[12][11] = 2;
    g[11][12] = 2;
    g[7][10] = 5;
    g[10][7] = 5;
    g[10][12] = 2;
    g[12][10] = 2;
    n = 14;
}

int dijkstra(int ori, int end)
{
    //初始化全部距离为无穷，初始点ori距离为0
    memset(dist, 0x3f, sizeof(dist));
    memset(path, -1, sizeof(path));
    path[ori] = 0;
    dist[ori] = 0;
    //循环n-1次
    for (int i = 0; i < n - 1; i++)
    {
        //每次从还没被确定最短路的集合中找到距离源点最近的点
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        //比较，然后更新该点的最短路径
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] > dist[t] + g[t][j])
            {
                dist[j] = dist[t] + g[t][j];
                path[j] = t;
            }
        }
        st[t] = true;
    }
    //如果未得到最短路
    if (dist[end] == 0x3f3f3f3f)
        return -1;
    return dist[end];
}

int main()
{
    init();

    char ori, end;
    printf("请输入你的起点与终点:\n");
    scanf("%c %c", &ori, &end);
    int a = ori - 64, b = end - 64;
    int res = dijkstra(b, a);

    if (res == -1)
        printf("该点不可达！\n");
    else
    {
        printf("经过的路径为：%c", a + 64);
        for (int i = path[a]; path[i] != -1; i = path[i])
            printf("->%c", i + 64);
        printf("\n距离为：%d\n", res);
    }

    return 0;
}
