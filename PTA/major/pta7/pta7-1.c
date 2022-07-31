#include <stdio.h>
void mov(int *x, int n, int m)
{
    int i = 0;
    for (i = 0; i < m; i++)
    {
        int temp = x[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            x[j] = x[j - 1];
        }
        x[0] = temp;
    }
}
int main()
{
    int i, n, m, *x;
    scanf("%d %d", &n, &m);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    x = a;
    mov(x, n, m);
    printf("After move: %d", x[0]);
    for (i = 1; i < n; i++)
        printf(" %d", x[i]);
    return 0;
}