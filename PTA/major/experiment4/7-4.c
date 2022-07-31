#include<stdio.h>
typedef struct infor{
    char name[15];
    int date;
    char number[20];
}in;
void sort(in* info,int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(info[j].date < info[j-1].date)
            {
                in temp=info[j];
                info[j] = info[j-1];
                info[j-1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    in info[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %s", info[i].name, &info[i].date,info[i].number);
    }
    sort(info,n);
    for(int i = 0; i < n; i++)
    {
        printf("%s %d %s\n", info[i].name, info[i].date,info[i].number);
    }
}