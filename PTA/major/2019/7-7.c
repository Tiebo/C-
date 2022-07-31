#include<stdio.h>
#include<string.h>
int main()
{
    int flag = 0,con=0;
    char c[100],eng[30];
    gets(c);
    gets(eng);
    int len=strlen(eng);
    eng[len]='#';eng[len+1]='\0';
    for(int i = 0; i <strlen(c);i++)
    {
        if(c[i]==' ') 
            continue;
        int k=i;
        for(int j = 0; j < len+1; j++)
        {
            if(j==len) break;
            if(eng[j]!=c[k]){
                flag=0;
                i+=len-1;
                break;
            }
            flag = 1;
            k++;
        }
        if(flag&&c[k]==' ')
            con++;
    }
    printf("%d\n",con);
    return 0;
}