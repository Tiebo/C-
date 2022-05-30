//单调栈
#include<iostream>
using namespace std;

int const N=100010;
int stk[N],tt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        while(tt && stk[tt]>=x)  tt--;
        if(!tt) cout<<-1<<" ";
        else    cout<<stk[tt]<<" ";
        stk[++tt]=x;
    }
    return 0;
}