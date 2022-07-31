#include<stdio.h>
#include<math.h>
int f(int n)
{
    int x=n;
    for (int i = 1; i < n; i++)
    {
        x*=i;
    }
    return x;
}
int main()
{
    int n;
    double x,y=0;
    scanf("%lf %d",&x,&n);
    for (int i=1,k=0; i<=2*n; i+=2,k++){
        y+=pow(x,i)/f(i)*pow(-1,k);
    }
    printf("%.4lf",y);
    return 0;
}