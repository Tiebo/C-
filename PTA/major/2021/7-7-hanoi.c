//汉诺塔
#include<stdio.h>
void hanoi(int i,char a,char b,char c)
{
    if(i==1)    printf("%c-->%c\n",a,b);
    else
    {
        hanoi(i-1,a,c,b);
        printf("%c-->%c\n",a,b);
        hanoi(i-1,c,b,a);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'a','b','c');
    return 0;
}