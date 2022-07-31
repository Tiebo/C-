#include<stdio.h>
int Add(int num,int count)
{
    if(num==1) 
    return count;
    count++;
    return Add(num%2==0?num/2:num*3+1,count);
}
int main()
{
    int x,count=0;
    scanf("%d",&x);
    int con=Add(x,count);
    printf("%d\n",con);
    return 0;
}