// n-皇后问题
#include <iostream>

using namespace std;

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        //保证下一个皇后不在同列，同主副对角线
        if (!col[i] && !dg[i + u] && !udg[n - u + i])
        {
            col[i] = dg[i + u] = udg[n - u + i] = true;
            g[u][i] = 'Q';
            //递归下一行
            dfs(u + 1);
            //回溯
            col[i] = dg[i + u] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    //初始化
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}