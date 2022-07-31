#include <stdio.h>
int divi(int m, int n)
{
    int p;
    for (int i = 1; i <= (m < n ? m : n); i++)
    {
        if (m % i == 0 && n % i == 0)
        {
            p = i;
        }
    }
    return p;
}
int mult(int m, int n)
{
    int p;
    for (int i = (m > n ? m : n);; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            p = i;
            break;
        }
    }
    return p;
}
int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    printf("%d %d", divi(M, N),mult(M, N));
}