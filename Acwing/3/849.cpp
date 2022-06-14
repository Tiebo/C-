// Dijkstra求最短路 I
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int n, m;
int g[N][N];
bool st[N];
int dist[N];

int dijkstra(int ori, int end)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[ori] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        if (t == end)
            break;

        st[t] = true;
    }
    if (dist[end] == 0x3f3f3f3f)
        return -1;
    return dist[end];
}

int main()
{
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra(1, n);
}