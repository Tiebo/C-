// 二进制中1的个数
#include <iostream>
using namespace std;
int main()
{
    int n, x, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (x)
        {
            s += x & 1;
            x >>= 1;
        }
        cout << s << " ";
        s = 0;
    }
}