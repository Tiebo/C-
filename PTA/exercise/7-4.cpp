#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, count = 0, i;
    cin >> n;
    float a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    sort(a, a + n);
    for (i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[i - 1] <= 3 && a[j] && a[i])
            {
                a[i] = a[i] + a[j];
                a[j] = 0;
                count++;
            }
        }
    }
    cout << "" << n - count;
    return 0;
}