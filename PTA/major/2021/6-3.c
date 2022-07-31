#include <stdio.h>

typedef struct
{
    char hour, minute, second;
} MYTIME;

int IsValidTime(int hour, int minute, int second);
void TimeSet(MYTIME *time, int hour, int minute, int second);

int main()
{
    MYTIME a = {12, 15, 30};
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    TimeSet(&a, h, m, s);
    printf("%d %d %d\n", a.hour, a.minute, a.second);
    return 0;
}
void TimeSet(MYTIME *time, int hour, int minute, int second)
{
    if(hour<24&&hour>=0&&minute<60&&minute>=0&&second<60&&second>=0){
        time->hour=hour,time->minute=minute,time->second=second;
    }
    else{
        printf("不正确的参数!\n");
    }
}
