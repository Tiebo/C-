#include<iostream>
using namespace std;

const int N=100010;
int a[N],tt;
int main()
{
    tt=-1;
    string op;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>op;
        if(op=="push")
        {
            int x;
            cin>>x;
            a[++tt]=x;
        }
        else if(op=="query")
            cout<<a[tt]<<endl;
        else if(op=="pop")
            tt--;
        else if(op=="empty")
        {
            cout<<(tt==-1?"YES":"NO")<<endl;
        }
    }
    return 0;
}