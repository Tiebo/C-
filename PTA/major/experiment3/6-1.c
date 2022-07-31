#include <stdio.h>
#include <math.h>
int isprime(int x)
{
    if(x<2)    return 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
void sort(int *a)
{
    for(int i = 0; i <10;i++)
    {
        for(int j = 1; j < 10; j++)
        {
            if(a[j]<a[j-1])
            {
                int temp=a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int a[10],b[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a);
    for(int i=0;i<10;i++)
    {
        if(isprime(a[i]))
            printf("%4d",a[i]);
    }
    return 0;
