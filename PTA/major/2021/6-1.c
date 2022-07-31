
#include <stdio.h>
#include <string.h>

void CHG(char *s);

int main()
{

 char   s[100], t[100];
  scanf("%s", s);
  CHG(s);
  printf("%s", s);

  return 0;

}


void CHG(char *s)
{
    int len=strlen(s);
    char c=s[0];
    for(int i=0; i<len; i++)
    {
        s[i]=s[i+1];
    }
    s[len-1]=c;
    int k=len-1;
    for(int i=0; i<len/2; i++)
    {
        int temp=s[k];
        s[k--]=s[i];
        s[i]=temp;
    }
}
