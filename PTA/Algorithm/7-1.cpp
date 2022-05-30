//最大子序列和
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],thissum=0,maxsum=0;;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        thissum=thissum+a[i];
        if(thissum<0)
            thissum=0;
        else if(thissum>maxsum)
        {
            maxsum=thissum;
        }
    }
    cout<<maxsum<<endl;
    return 0;
}
    