#include<stdio.h>
#include<string.h>
int getWordNum(char ar1[],char ch) ;
int main()
{ 
    char string[81],c,n; 
    gets(string);                           
    c=getchar();
    n=getWordNum(string,c);
    printf("%d",n); 
    return 0;
}

int getWordNum(char ar1[],char ch)
{
    char t[82];
    t[0]=' ';t[1]='\0';
    strcat(t,ar1);
    int con=0;
    for(int i=1;i<strlen(t);i++)
    {
        if((ch==t[i]||ch==t[i]+32||ch==t[i]-32)&&t[i-1]==' ')
            con++;
    }
    return con;
}