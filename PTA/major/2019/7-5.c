#include<stdio.h>
#include<string.h>
void swap(int *x,int *y)
{
    int temp=*y;
    *y=*x;
    *x=temp;
}
void sort(int *len,int n)
 {   for(int i=0;i<n-1;i++)
        for(int j=1;j<=n;j++)
            if(len[j]<len[j-1])
                swap(&len[j], &len[j-1]);
}
int main()
{
    char a[101][101];
    int n;
    scanf("%d",&n);
    int len[n+1];
    for(int i=0;i<=n;i++){
        gets(*(a+i));
        len[i]=strlen(*(a+i));
    }
    sort(len,n);
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(len[i]==strlen(*(a+j)))
                puts(*(a+j));
        }
    }
    return 0;
}