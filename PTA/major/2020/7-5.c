//结构体-时间计算
#include<stdio.h>
struct _Time{
    int hh;
    int mm;
}Time1,Time2;
int main()
{
    scanf("%d  %d  %d  %d", &Time1.hh, &Time1.mm, &Time2.hh,&Time2.mm);
    int time=Time2.hh*60+Time2.mm-Time1.hh*60-Time1.mm;
    printf("%d",time);
    return 0;
}