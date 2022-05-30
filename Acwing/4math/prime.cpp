// 试除法
#include <iostream>

using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false; 
    }
    return true;
}
int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        isprime(x) ? printf("Yes\n") : printf("No\n");
    }
}