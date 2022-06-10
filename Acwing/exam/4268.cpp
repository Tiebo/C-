#include <iostream>

using namespace std;

bool isprime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int x;
    cin >> x;
    if (isprime(x) && (isprime(x + 6) || isprime(x - 6)))
    {
        if (isprime(x - 6))
            cout << "Yes\n"
                 << x - 6;
        else
            cout << "Yes\n"
                 << x + 6;
    }
    else if (!isprime(x) || (!isprime(x + 6) && !isprime(x - 6)))
    {
        int i = x;
        while (1)
        {
            if (isprime(i) && (isprime(i + 6) || isprime(i - 6)))
            {
                cout << "No\n"
                     << i;
                break;
            }
            i++;
        }
    }
}