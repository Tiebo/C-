#include "stdio.h"
#include<string.h>
void delnum(char *s);
int main ()
{ char item[80];
gets(item);
 delnum(item);
 printf("%s\n",item);
 return 0;
}

void delnum(char *s)
{
    char t[strlen(s)];
    int k=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]<='9'&&s[i]>='0')
            continue;
        t[k++] = s[i];
    }
    t[k] = '\0';
    strcpy(s,t);
}
