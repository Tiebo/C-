#include <stdio.h>
#include <string.h>
#define MAXS 20

void zip( char *p );
void ReadString( char *s ) /* 由裁判实现，略去不表 */
{
    gets(s);
}
int main()
{
    char s[MAXS];
    
    ReadString(s);
    zip(s);
    printf("%s\n", s);
    
    return 0;
}

void zip( char *p )
{
    int num=1,k=0,i=0;
    char a[MAXS];
    while(p[i]!='\0')
    {
        if(p[i]==p[i+1])    num++;
        else
        {
            if(num!=1)
            {
                if(num<10)  a[k++]='0'+num;
                else
                a[k++]=num/10+'0',a[k++]=num%10+'0';
                a[k++]=p[i];
            }
            else    a[k++]=p[i];
            num=1;
        }
        i++;
    }
    a[k]='\0';
    strcpy(p,a);
}
