#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,count=0,i;
    cin>>n;
    float a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    if(n==1){cout<<"1";return 0;}
    sort(a,a+n);
    for(i=1;i<n;i++)
    {   
        if(a[i]+a[i-1]<=3&&a[i-1]!=4){
            a[i]=4;a[i-1]=4;
            count++;
        }
        if(a[i]+a[i-1]>3&&a[i-1]!=4)
            break;
    }
    if(count==0||n==0){cout<<""<<n;}
    else{
    count=n-i+count+1;
    cout<<""<<count;
    }
    return 0;
}