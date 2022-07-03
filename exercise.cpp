#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2 * 10e5 + 10;
int a[N], n, f[N];

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        int ans = 0;
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++)
            cin >> a[i], f[i] = 2;
        for (int i = 3; i <= n; i++)
        {
            if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
                f[i] = max(f[i], f[i - 1] + 1);
            ans = max(ans, f[i]);
        }
        printf("Case #%d: %d\n", i, ans);
    }
}
