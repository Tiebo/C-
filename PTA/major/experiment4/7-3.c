#include<stdio.h>
int main()
{
    int hh,mm,ss;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    int n;
    scanf("%d",&n);
    if(ss>=60-n){
        mm++;
        if(mm>=60){
            hh++;
            if(hh==24){
                hh=0;
            }
            mm-=60;
        }
        ss=ss+n-60;
    }
    else{
        ss+=n;
    }
    printf("%02d:%02d:%02d\n",hh,mm,ss);
    return 0;
}