#include <stdio.h>
#include <string.h>
#define  N  80
int fun(char *str)
{
    int i,n;
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        if(str[i]!=str[n-1-i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{ 
    char  s[N] ;
    gets(s) ;
    puts(s) ;
  if(fun(s)) printf("Yes\n") ;
  else       printf("No\n") ;
}