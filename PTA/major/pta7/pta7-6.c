#include<stdio.h>
    struct students {
        char num[6];
        char name[10];
        int scores;
    };
int main()
{
    int N;
    float aver=0;
    scanf("%d", &N);
    struct students stu[N];
    for(int i=0; i<N; i++)
    {  
        scanf("%s %s %d",stu[i].num, stu[i].name,&stu[i].scores);
        aver+=stu[i].scores;
        stu[i].num[5]='\0';
    }
    aver/=N;
    printf("%.2f\n",aver);
    for(int i=0; i<N; i++)
    {
        if(aver>stu[i].scores)
        printf("%s %s\n",stu[i].name,stu[i].num);
    }
    return 0;
}