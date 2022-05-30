#include<iostream>
using namespace std;

const int N=100;
int e[N],ne[N],idx,head;

void Add(int x)
{
    if(head==-1)
    {
        e[idx]=x;
        ne[idx]=head;
        head=idx++;
    }
    else
    {
        int i;
        e[idx]=x,ne[idx]=-1;
        for(i=head;ne[i]!=-1;i=ne[i]);
        ne[i]=idx++;
    }
}
void reprint(int head)
{
    int p=ne[head],t;
    while(ne[p]!=-1)
    {
        for( t=p;ne[ne[t]]!=-1;t=ne[t]);
        cout<<e[ne[t]]<<" ";
        ne[t]=-1;
    }
}
int main()
{
    int n;
    cin>>n;
    head=-1;
    idx=0;
    while(n--)
    {
        int x;
        cin>>x;
        Add(x);
    }
    reprint(head);
    return 0;
}