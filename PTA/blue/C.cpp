#include<iostream>
#include<math.h>

using namespace std;

bool isprime(int num)
{
    if(num<2)   return false;
    for(int i=2;i<=num/i;i++)
    {
        if(num%i==0) return false;
    }
    return true;
}
int main()
{
    int n,cont=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(!isprime(i))  continue;
        for(int j=i;j<n;j++)
        {
            if(isprime(j)&&i+j==n)
            {
                cont++;
                cout<<i<<" + "<<j<<" = "<<n<<"\n";
            }
        }
    }

    return 0;
}