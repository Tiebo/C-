#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;

vi Add(vi &a,vi &b)
{
    if(a.size()<b.size()) return(Add(b,a));

    vi c;
    int t=0;
    for(int i=0;i<a.size();i++)
    {
        t+=a[i];
        if(i<b.size())     t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t)   c.push_back(t);
    return c;
}
int main()
{
    string A,B;
    cin>>A>>B;
    vi a,b,c;
    for(int i=A.size()-1;i>=0;i--)
        a.push_back(A[i]-'0');
    for(int i=B.size()-1;i>=0;i--)
        b.push_back(B[i]-'0');
    c=Add(a,b);
    for (int i = c.size() - 1; i >= 0; i -- ) cout << c[i];
        cout << endl;
    return 0;
}