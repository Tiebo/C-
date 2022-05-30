//优先队列
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > q;

    int n;
    cin>>n;
    string pstr[n];
    while(n--)
    {
        string op;
        cin>>op;
        if(op=="PUT")
        {
            string str;
            cin>>str;
            int x;
            cin>>x;
            pstr[x]=str;
            q.push(x);
        }
        else if(op=="GET")
        {
            if(q.empty())   cout<<"EMPTY QUEUE!"<<endl;
            else
            {
                cout<<pstr[q.top()]<<endl;
                q.pop();
            }
                
        }
    }
}