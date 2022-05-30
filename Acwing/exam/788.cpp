#include<iostream>

using namespace std;

const int N=10e5+10;
int con=0,n;
int a[N];

void merge(int a[],int l,int r)
{
    if(l>=r)    return;
    
    int mid=( l+r )>>1;
    
    merge(a,l,mid);
    merge(a,mid+1,r);
    
    if(l<r && a[l]<a[r])    con++;
}

int main()
{
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    
    merge(a,0,n-1);
    
    cout<<con;
}