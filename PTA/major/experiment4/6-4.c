#include <stdio.h>
#include <string.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;
    
    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

char *search(char *s, char *t)
{
    int i,j,n;
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == t[0]){
            n=i;
            for(j=0;j<strlen(t);j++)
            {
                if(s[i++]!=t[j])break;
            }
            if(j==strlen(t)){
                return s+n;
            }
        }
    }
    return NULL;
}

void ReadString( char s[] )
{
    gets(s);
}