#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k,count=0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    if(n==0||k==0) {cout<<"0";return 0;}
    // for (int i = 0; i < n; i++){
    //     int min=i;
    //     for (int j = i+1; j < n; j++){
    //         if(a[min]>a[j])
    //             min=j;
    //     }
    //     int temp=a[i];
    //     a[i]=a[min];
    //     a[min]=temp;
    // }
    sort(a,a+n);
    int minlen=a[n-1];
    for (int i = 0; i <= n-k; i++)
    {
        int j;
        j=a[i+k-1]-a[i]+1;
        minlen=min(j,minlen);
    }
    cout<<""<<minlen;
    return 0;
}