//最小块的最大节点值
#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010, M=2*N;

int h[N], e[M], ne[M], idx;
int n;
int ans=N;
bool st[N];

void Add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//返回以u为根的字数中点的数量大小
int dfs(int u)
{
    st[u] = true;

    int res = 0, sum = 0;//子树孩子数量的大小，当前子树大小

    for (int i = h[u];i != -1;i = ne[i]) {
        int j = e[i];

        if (!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }

    res = max(res, n - sum - 1);
    ans = min(ans, res);
    return sum + 1;
}

int main()
{
    scanf("%d", &n);

    memset(h, -1, sizeof(h));
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        Add(x, y);Add(y, x);
    }

    dfs(1);

    printf("%d",ans);

    return 0;
}