//绝对素数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isPrime(int n); //判断n是否是素数，如果是返回1，不是素数返回0
int rev(int x);     //将参数x反转，如x实123，则返回321

int main()
{
    int n, m; //原始的数据是n，反转之后是m
    scanf("%d", &n);
    m = rev(n);

    //如果用户输入的数是素数，反转后也是素数
    if (isPrime(n) != 0 && isPrime(m) != 0)
        printf("%d==>%d: Yes", n, m);
    else
        printf("%d==>%d: No", n, m);

    return 0;
}

int isPrime(int n)
{
    int m = sqrt(n), i;
    for (i = 2; i < m; i++)
    {
        if (n % i == 0)
            break;
    }
    if (i == m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int rev(int n)
{
    int m = 0;
    while (n)
    {
        m = n % 10 + m * 10;
        n /= 10;
    }
    return m;
}