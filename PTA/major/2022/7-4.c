//国王的金币
#include<stdio.h>
int main()
{
    int a[1000]={0},i,j,day=1;
    int n;
    scanf("%d",&n);
    for(i=-1;day<=n;)
	{
		j=day;
		while(j)
		{
			a[++i]=day;
			j--;
		}
		day++;
	}
	int sum=0,k=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}
	printf("%d",sum);
    return 0;
}