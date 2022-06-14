//2n皇后问题
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;
char g[N][N];
int res, n;
bool row[N * N], dig[N * N], udig[N * N];
bool wrow[N * N], wdig[N * N], wudig[N * N];

void white_dfs(int u)
{
    if (u == n)
    {
        res++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!wrow[i] && !wdig[u + i] && !wudig[n - u + i] && g[u][i] == '1')
        {
            wrow[i] = wdig[u + i] = wudig[n - u + i] = true;
            g[u][i] = 'wQ';
            white_dfs(u + 1);
            wrow[i] = wdig[u + i] = wudig[n - u + i] = false;
            g[u][i] = '1';
        }
    }
}
void black_dfs(int u)
{
    if (u == n)
    {
        white_dfs(0);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!row[i] && !dig[u + i] && !udig[n - u + i] && g[u][i] == '1')
        {
            row[i] = dig[u + i] = udig[n - u + i] = true;
            g[u][i] = 'bQ';
            black_dfs(u + 1);
            row[i] = dig[u + i] = udig[n - u + i] = false;
            g[u][i] = '1';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    black_dfs(0);
    cout << res;

    return 0;
}