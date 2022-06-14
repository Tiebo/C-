#include <iostream>
#include <cstring>
#include <queue>

//图中点的层次
using namespace std;

const int N = 100010;

int e[N], ne[N], h[N], idx; //模拟链表
int n, m;
queue<int> q; //bfs辅助队列
int d[N]; //记录走过的距离

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs()
{
    memset(d, -1, sizeof(d));
    q.push(1);
    d[1] = 0;

    while (q.size()) {
        int t = q.front();
        q.pop();
        //遍历t的所有邻接
        for (int i = h[t];i != -1;i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }

    }
    return d[n];
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs();

    return 0;
}