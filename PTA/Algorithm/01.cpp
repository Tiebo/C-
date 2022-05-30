#include<iostream>

using namespace std;

const int N=10e5+10;
int Data[N];
int add[N];
int Next[N];

int main()
{
    int head,k,data;
    scanf("%d %d %d",&head,&data,&k);
    
    while(k--)
    {
        int tempadd,tempdata,tempnext;
        scanf("%d %d %d",&tempadd,&tempdata,&tempnext);
        Data[tempadd]=tempdata;
        Next[tempadd]=tempnext;
    }
    int idx=0;
    while(head!=-1)
    {
        add[idx++]=head;
        head=Next[head];
    }
    
    for(int i=0;i<idx-idx%k;i+=k)
    {
        for(int j=0;j<k/2;j++)
        {
            int t=add[j];
            add[j]=add[k+i-j-1];
            add[k+i-j-1]=t;
        }
    }
    for(int i=0;i<idx-1;i++)
    {
        printf("%05d %d %05d",add[i],Data[add[i]],Next[add[i]]);
    }
    return 0;
}