//高精度减法
#include<iostream>
#include<vector>

using namespace std;

vector<int> subtract(vector<int> &v1, vector<int> &v2)
{
    if(v1.size()<v2.size()) return(v2,v1);

    int t=0;
    vector<int> v3;
    for(int i=0;i<v1.size();i++)
    {
        t+=v1[i];
        if(i<v2.size())
        {
            t-=v2[i];
        }
        v3.push_back(abs(t));
        if(t<0)
            t=-1;
    }
}

int main()
{
    string a,b;
    cin>>a>>b;
    vector<int> v1,v2;

    for(int i=a.size()-1;i>=0;i--)    v1.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)    v2.push_back(b[i]-'0');

    auto v3=subtract(v1,v2);

    for(int i=v3.size()-1;i>=0;i--)     cout<<v3[i];
    cout<<endl;
    return 0;
}