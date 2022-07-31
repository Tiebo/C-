#include <stdio.h>
#define MAXN 10

int FindArrayMax( int a[], int n );

int main()
{
    int i, n;
    int a[MAXN];
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ){
        scanf("%d", &a[i]);
    }

    printf("%d\n", FindArrayMax(a, n));
        
    return 0;
}

int FindArrayMax(int a[],int n)
{
    int i,j;
    for( i = 0; i <n;i++)
    {
        for( j = 1; j < n; j++)
        {
            if(a[j]<a[j-1])
            {
                int temp=a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    return a[i-1];
}