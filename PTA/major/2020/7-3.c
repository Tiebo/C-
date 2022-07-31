//循环结构-计算PI
#include<stdio.h>
#include<math.h>
int main()
{
    double PI=0,num,i=0;
    int n=0;
    scanf("%d", &n);
    num=pow(0.1,n);
    double m=1/(2*i-1);
    for( i=1;fabs(m)>num;i++)
    {
        m=1/(2*i-1);
        PI+=m*pow(-1,i-1);
    }
    printf("%.0lf\n%.9lf",i-1,4*PI);
    return 0;
}