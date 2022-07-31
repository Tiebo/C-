#include<stdio.h>
#include<string.h>
void deletepri(char *a,char eg)
{
    int i;
    for(i=0;i<strlen(a);i++)
    {
        if(*(a+i) == eg)
        continue;
        printf("%c",*(a+i));
    }
}
int main()
{
    char eg='a',str[100];
    scanf("%s",str);
    deletepri(str,eg);
    return 0;
}