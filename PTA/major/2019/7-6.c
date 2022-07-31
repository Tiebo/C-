#include<stdio.h>
int main()
{
    int n,sum=0;
    scanf("%d", &n);
    char c[n];
    getchar();
    gets(c);
    for(int i = 0; i < n; i++)
    {
        if(c[i] >='0'&&c[i]<='9')
            sum+=c[i]-'0';
    }
    printf("%d\n",sum);
    return 0;
}