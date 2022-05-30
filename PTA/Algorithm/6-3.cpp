#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
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
int Length(List L)
{
    List p=L;
    int n=0;
    while(p)
    {
        n++;
        p=p->Next;
    }
    return n;
}