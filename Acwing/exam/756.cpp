// 756. 蛇形矩阵
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int res[105][105];

    memset(res, 0, sizeof(res));
    int x = 0, y = 0, d = 1;
    for (int i = 1; i <= n * m; i++)
    {
        res[x][y] = i;
        int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0};

        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m || res[a][b])
        {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }

        x = a, y = b;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}