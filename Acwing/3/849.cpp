#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;


const int N = 1.5 * 10e5 + 10;
int e[N], ne[N], h[N], idx;
int w[N];
int dist[N];
bool st[N];
int n, m;

int dijkstra(int ori, int end)
{
    memset(dist, 0x3f, sizeof (dist));//距离初始化为无穷大
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;//小根堆
    heap.push({0, 1});//插入距离和节点编号

    while (heap.size())
    {
        auto t = heap.top();//取距离源点最近的点
        heap.pop();

        int ver = t.second, distance = t.first;//ver:节点编号，distance:源点距离ver 的距离

        if (st[ver]) continue;//如果距离已经确定，则跳过该点
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])//更新ver所指向的节点距离
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});//距离变小，则入堆
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int main()
{
    cin >> n >> m;

    memset(h,-1,sizeof(h));

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra(1, n);

    return 0;
}