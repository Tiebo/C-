#include <iostream>
using namespace std;

const int N = 10e6 + 10;
int a[N], q[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && q[hh]<i - k + 1)
            hh++;
        while(hh <= tt && a[q[tt]]>=a[i])   tt--;
        q[++tt]=i;

        if(i >= k - 1)  cout<<a[q[hh]]<<" ";
    }
    puts("");
    for(int i=0;i<n;i++)
    {
        if(hh <= tt && q[hh]<i-k+1)
            hh++;
        while(hh<=tt && a[q[tt]<=a[i]])     tt--;
        q[++tt]=i;

        if(i >= k - 1)  cout<<a[q[hh]]<<" ";
    }
    puts("");
    return 0;
}