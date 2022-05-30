#include <iostream>
using namespace std;

const int N = 100010;
int e[N], r[N], l[N], idx;

void inti()
{
    idx = 2;
    r[0] = 1, l[1] = 0;
}
//在节点a的右边插入一个数x
void insert(int a, int x)
{
    //声明新节点储存x
    e[idx] = x;
    //让新节点的左指针指向a
    l[idx] = a;
    //让新节点的右指针指向a的右指针指向的节点
    r[idx] = r[a];
    //让a右指针指向的节点的左指针从指向a改为指向新节点
    l[r[a]] = idx;
    //让a右指针指向新节点
    r[a] = idx;
    //开辟新空间
    idx++;
}
//删除节点a
void remove(int a)
{
    //让a右边的节点指向a左边的节点
    l[r[a]] = l[a];
    //让a左边的节点指向a右边的节点
    r[l[a]] = r[a];
}
int main()
{
    int n;
    cin >> n;
    inti();
    while (n--)
    {
        int x, k;
        string op;
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            insert(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << ' ';
    cout << endl;
    return 0;
}