//选择结构-计算邮费
#include<stdio.h>
#include<math.h>
int main()
{
    float price = 0;
    int m;
    scanf("%d", &m);
    if(m<=1000)
        printf("8.00");
    else
        printf("%.2f",ceil(1.0*(m-1000)/500)*4.56+8);
}