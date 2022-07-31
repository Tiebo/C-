#include<stdio.h>
#include<math.h>
int main()
{
    struct cor{
        int x,y;
    }z1,z2;
    scanf("%d %d %d %d",&z1.x,&z1.y,&z2.x,&z2.y);
    float dis=pow(z1.x-z2.x,2)+pow(z1.y-z2.y,2);
    printf("distance = %.2f",sqrt(dis));
    return 0;
}