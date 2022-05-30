//走迷宫
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int n, m;
const int N = 105;
int g[N][N];  //存储图
int d[N][N];  //存储节点(x,y)到起点的距离
PII q[N * N]; //辅助队列，或者用stl

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};
    //初始化距离
    memset(d, -1, sizeof(d));
    d[0][0] = 0;

    //从上方开始顺时针旋转四个方向
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    //队列不空则一直循环
    while (hh <= tt)
    {
        //取出队头
        auto t = q[hh++];
        //尝试四种走法
        for (int i = 0; i < 4; i++)
        {
            //得到新坐标(x,y)
            int x = t.first + dx[i], y = t.second + dy[i];
            //新坐标不能出界，并且路要可走-->g[x][y]==0，并且要是第一次被访问
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                //新坐标离起点的距离为原坐标的距离加一
                //只走了一步
                d[x][y] = d[t.first][t.second] + 1;
                //把移动后得到的坐标入队
                q[++tt] = {x, y};
            }
        }
    }

    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}