#include <iostream>
using namespace std;
int main()
{
    int i,j,n,gender,max=0;
    cin>>n;
    int difference[n]={0};
    for(i=1;i<n;i++){
        cin>>gender;
        if(gender)//boy+1
        difference[i]=difference[i-1]+1;
        else//girl-1
        difference[i]=difference[i-1]-1;
    }
    for(i=0;i<=n-max;i++){
        for(j=n;j>=i;j--){
            if(difference[j]==difference[i]){
                if(j-i>max)
                max=j-i;
            }
        }
    }
    cout<<""<<max;
    return 0;
}