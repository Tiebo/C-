//前缀和
#include <iostream>
using namespace std;

const int N = 10e5 + 10;
int m, n, a[N], s[N];

int main()
{
    int l, r;
    scanf("%d %d", &n, &m);
    s[0] = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    while (m--)
    {
        scanf("%d %d", l, r);
        cout << s[r] - s[l - 1] << "\n";
    }
    return 0;
}