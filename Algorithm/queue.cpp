#include<iostream>

using namespace std;

typedef struct _Queue{
    int *Data;
    int front,rear,MaxSize;
}Queue;

Queue* CreatQueue(int MaxSize)
{
    Queue *Q=(Queue*)malloc(sizeof(Queue));
    Q->Data=(int*)malloc(sizeof(int)*MaxSize);
    Q->front=Q->rear=0;
    Q->MaxSize=MaxSize;
    return Q;
}
bool isfull(Queue *Q)
{
    return((Q->rear+1)%(Q->MaxSize)==Q->front);
}
void AddQ(Queue *Q,int item)
{
    if(isfull(Q))   {printf("queue is full\n"); return;}
    Q->Data[Q->rear]=item;
    Q->rear=(Q->rear+1)%(Q->MaxSize);
}
bool isempty(Queue *Q)
{   
    return(Q->front==Q->rear);
}
void DeleteQ(Queue *Q)
{   
    if(isempty(Q))  {printf("queue is empty\n");return;}
    else
    {
        Q->front=(Q->front+1)%(Q->MaxSize);
    }
}
int main()
{
    Queue *Q;
    int MaxSize;
    scanf("%d",&MaxSize);
    Q=CreatQueue(MaxSize);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        AddQ(Q,i+1);
    }
    for(int i=0;i<2;i++)
        DeleteQ(Q);
    AddQ(Q,6),AddQ(Q,7);
    for(int i=Q->front;i!=Q->rear;i=(i+1)%(Q->MaxSize))
        printf("%d ",Q->Data[i]);
    return 0;
}
