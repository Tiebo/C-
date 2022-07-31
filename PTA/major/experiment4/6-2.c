#include<stdio.h>
#include<string.h>
void strcopy(char *str1,char *str2,int m);
int main()
{ int i,m;
 char *p1,*p2,str1[80],str2[80];
 p1=str1; p2=str2;
 gets(p1); 
 scanf("%d",&m);
 strcopy(str1,str2,m);
 puts(p1);puts(p2);
 return 0;
}

void strcopy(char *str1,char *str2,int m)
{
    int k=0;
    for(int i=m-1;i<strlen(str1);i++)
    {
        str2[k++]=str1[i];
    }
}