#include<stdio.h>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=-1)
	{
		int p=0;
		for(int i=2;i<=n;i++)
			p=(p+m)%i;
		printf("%d\n",p+1);
	}
	return 0;
}
