#include  <stdio.h>
#include <string.h>
void fun (char  *s, char  *t);
int main()
{  char   s[100], t[100];
  scanf("%s", s);
  fun(s, t);
  printf("The result is: %s\n", t);
  return 0;
}


void fun (char  *s, char  *t)
{
    int k=0;
    for(int i=0; i<strlen(s); i++)
    {
        t[k++]=s[i];
    }
    for(int i=strlen(t)-1; i>=0; i--)
    {
        t[k++]=t[i];
    }
}
