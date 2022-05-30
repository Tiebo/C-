//模拟单链表
#include <iostream>
using namespace std;

const int N = 100010;
int e[N], ne[N], idx, head;

void inti()
{
    head = -1;
    idx = 0;
}
void addhead(int n)
{
    e[idx] = n, ne[idx] = head, head = idx ++ ;
}
void add(int k, int n)
{
    e[idx] = n;
    ne[idx] = ne[k];
    ne[k] = idx++;
}
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int n, k, x;
    char op;
    cin >> n;
    inti();
    while (n--)
    {
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            addhead(x);
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
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    cout << endl;
    return 0;
}