#include<stdio.h>
#include<math.h>
int main()
{
    float x, y,r;
    scanf("%f %f %f",&x,&y,&r);
    float x0,y0,dis;
    scanf("%f %f",&x0,&y0);
    dis=(x0-x)*(x0-x)+(y-y0)*(y-y0);
    if(sqrt(dis)<=r)
        printf("in the circle");
    else
        printf("outside the circle");
    return 0;
}