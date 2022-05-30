//模拟栈
#include<iostream>

using namespace std;

const int N=10e6+10;
int s[N];

int main()
{
    int top=-1,m;
    string op;
    cin>>m;
    while(m--)
    {
        cin>>op;
        if(op=="push")
        {
            int x;
            cin>>x;
            s[++top]=x;
        }
        else if(op=="pop")
            top--;
        else if(op=="empty")
            cout<<(top==-1?"YES":"NO")<<endl;
        else if(op=="query")
            cout<<s[top]<<endl;
    }
    return 0;
}