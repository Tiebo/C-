#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n,k,m,x;
    cin>>n>>k>>m;
    int s[k];
    stack<int> stk;

    for(int j=0;j<m;j++){
        int i=0;
        for(int j=0;j<k;j++)    cin>>s[j];
        for(auto x : s)
        {
            stk.push(x);
            while(stk.size() && stk.top()==s[i])
            {
                stk.pop();
                i++;
            }
        }
        if(stk.size())
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        while(stk.size())   stk.pop();
    }
    return 0;
}