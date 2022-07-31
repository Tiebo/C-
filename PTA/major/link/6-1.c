#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList Create();/* 细节在此不表 */

LinkList MinP( LinkList L);

int main()
{
    LinkList L,p;
    ElemType e;
    L = Create();
    p = MinP(L);
    if(p)
        printf("%d\n", p->data);
    else
        printf("NULL");
    return 0;
}

LinkList MinP(LinkList L)
{
    if(!L->next)  return NULL;
    ElemType min=L->next->data;
    L=L->next;
    LinkList p=L,pmin=L;
    for(;p;p=p->next)
    {
        if(min>p->data){
            min=p->data;
            pmin=p;
        }
    }
    return pmin;
}