//高精度加法
#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &v1, vector<int> &v2)
{
    vector<int> v3;
    for (int i = 0, t = 0; i < v1.size() || i < v2.size() || t; i++)
    {
        if (i < v1.size())
            t += v1[i];
        if (i < v2.size())
            t += v2[i];
        v3.push_back(t % 10);
        t /= 10;
    }
    return v3;
}

int main()
{
    string a, b;
    cin >> a >> b;

    vector<int> v1, v2;
    for (int i = a.size() - 1; i >= 0; i--)
        v1.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        v2.push_back(b[i] - '0');

    auto v3 = add(v1, v2);

    for (int i = v3.size() - 1; i >= 0; i--)
        cout << v3[i];

    return 0;
}