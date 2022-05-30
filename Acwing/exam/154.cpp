//滑动窗口
#include<iostream>
#include<algorithm>
using namespace std;

void Maxmove(int a[],int n,int k)
{
    int l=0,r=l+2,b[n];
    for(int i=0;i<n;i++)
    {
        int j=l,k=0;
        l=i,r=l+2;
        while(j<=r)
        {

            b[k++]=a[j];
            j++;
        }
        sort(b,b+k);
        printf("%d ",b[k-1]);
    }
}
void Minmove(int a[],int n,int k)
{

}
int main()
{
    int n,k;
    cin>>n,k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    Maxmove(a,n,k);
    Minmove(a,n,k);
    return 0;
}