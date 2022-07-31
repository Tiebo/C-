//约瑟夫环问题
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int pos=0,n,m;
    scanf("%d %d",&n,&m);
    for(int i=2;i<n+1;i++)
    {
        pos=(pos+m)%i;
        printf("%d ",pos);
    }
    printf("%d",pos+1);
}