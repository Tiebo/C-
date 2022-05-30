#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> s;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 5)
        {
            s.push(a[i]);
        }
        else
        {
            for (int j = 0; a[i] != 5; j++)
            {
                if (s.empty())
                {
                    cout << "false" << endl;
                    return 0;
                }
                a[i] -= s.top();
                s.pop();
            }
        }
    }
    cout << "true" << endl;
    return 0;
}