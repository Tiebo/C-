//口算练习题（普及-）
#include <iostream>//cin & cout
#include <cstring>//memset & strlen
#include <cstdio>//sscanf & sprintf
using namespace std;
int main()
{
    char op;
    int n, a, b;
    char s[100], t[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t[0] >= '0' && t[0] <= '9')
        {
            sscanf(t, "%d", &a);
            cin >> b;
        }
        else
            op = t[0], cin >> a >> b;
        memset(s,0,sizeof(s));
        if (op == 'a' || op == ' ')
            sprintf(s, "%d+%d=%d", a, b, a + b);
        else if (op == 'b')
            sprintf(s, "%d-%d=%d", a, b, a - b);
        else if (op == 'c')
            sprintf(s, "%d*%d=%d", a, b, a * b);
        cout << s <<'\n'<<strlen(s)<<'\n';
    }
    return 0;
}