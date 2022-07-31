#include<stdio.h>
int main()
{
    int n, y;
    scanf("%d", &n);
    switch(n){
        case 0:
            y=4;
            break;
        case -2:
        case 2:
            y=1;
            break;
        case 7:
            y=7;
            break;  
        default :
            y=0;
            break;
    }
    printf("%d\n", y);
    return 0;
}