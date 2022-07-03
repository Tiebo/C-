// 4274. 后缀表达式
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 25;
string v[N];
int lc[N], rc[N];
bool isparent[N];
int n;

void dfs(int root)
{
    cout << '(';
    //如果是叶节点则直接输出
    if (lc[root] == -1 && rc[root] == -1)
        cout << v[root];
    //如果有左儿子并且有右儿子，后序遍历
    else if (lc[root] != -1 && rc[root] != -1)
    {
        dfs(lc[root]);
        dfs(rc[root]);
        cout << v[root];
    }
    //如果只有右儿子,先输出在遍历(根为负号的情况)
    else
    {
        cout << v[root];
        dfs(rc[root]);
    }
    cout << ')';
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> lc[i] >> rc[i];
        if (lc[i] != -1)
            isparent[lc[i]] = true;
        if (rc[i] != -1)
            isparent[rc[i]] = true;
    }
    int root;
    for (int i = 1; i <= n; i++)
        if (!isparent[i])
            root = i;

    dfs(root);

    return 0;
}