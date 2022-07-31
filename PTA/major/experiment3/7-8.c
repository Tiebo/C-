#include<stdio.h>
int main()
{
    char c[20],d[20];
    gets(c);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        d[i]=c[i];
    }
    puts(d);
    return 0;
}