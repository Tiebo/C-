//字符串-复制
#include <stdio.h>
#include <string.h>
#define MAXN 100

//从t指向的字符串中，复制从第m个字符起到s中 
void strmcpy( char *t, int m, char *s );

int main()
{
    char t[MAXN], s[MAXN];
    int m;
    scanf("%d\n", &m);
    scanf("%s",t);
    strmcpy( t, m, s );
    printf("%s\n", s);
    return 0;
}

void strmcpy( char *t, int m, char *s )
{
	int i=m-1,j=0; 
    if(m>strlen(t)) {s[0]='\0';return;}
    while(t[i]!='\0')
    {
        s[j++]=t[i++];
    }
    s[j]='\0';
}