//模拟队列
#include <iostream>

using namespace std;

const int M = 10e5 + 10;
int  Q[M], hh = 0, rr = -1;

int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        string op;
        int x;
        cin>>op;
        if(op=="push")
        {
            cin>>x;
            Q[++rr] = x;
        }
        else if(op=="pop")  hh++;
        else if(op=="empty")    cout<<(hh<=rr ? "NO" : "YES")<<"\n";
        else cout<<Q[hh]<<"\n";
    }
    return 0;
}