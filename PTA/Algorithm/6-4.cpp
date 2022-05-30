#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}
List Read()
{
    List L=(List)malloc(sizeof(struct LNode));
    List rear;
    rear=L;
    L->Next=NULL;
    int x;
    scanf("%d",&x);
    if(x==-1)   return NULL;
    while(x!=-1){
        List p=(List)malloc(sizeof(struct LNode));
        p->Data=x;
        p->Next=NULL;
        rear->Next=p;
        rear=p;
        scanf("%d", &x);
    }
    L=L->Next;
    return L;
}
ElementType FindKth( List L, int K )
{
    if(!L)  return ERROR;
    List p=L;
    int i;
    for(i=1;i<K;i++)
    {
        if(p->Next==NULL)       
            break;
        p=p->Next;
    }
    return i==K?p->Data:ERROR;
}
