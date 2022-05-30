#include<iostream>

using namespace std;

int main()
{
    int cont=1;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>0;j/=10){
            if(j%10==0)
                cont++;
        }
    }
    cout<<cont;
}