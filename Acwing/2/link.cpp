//单链表(插入，删除)
#include <iostream>

using namespace std;

const int N = 100010;
int head, ne[N], e[N], idx;

void init()
{
    head = -1;
    idx = 0;
}
//将x插入到头节点
void Add_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}
//将x插入到下标是k的点后面
void Add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}
//将下标是k的点后面的点删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int m;
    cin >> m;
    init();

    while (m--)
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            Add_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            Add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);
    return 0;
}