//带头结点的链式表操作集
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if (flag == false)
            printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
        {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (flag == false)
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if (flag == false)
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if (flag == true)
        printf("Wrong Answer\n");
    flag = Delete(L, P);
    if (flag == true)
        printf("Wrong Answer\n");
    for (P = L->Next; P; P = P->Next)
        printf("%d ", P->Data);
    return 0;
}
List MakeEmpty()
{
    List link = (List)malloc(sizeof(struct LNode));
    link->Next = NULL;
    return link;
}
Position Find(List L, ElementType X)
{
    List p=L;
    while(p->Next!=NULL&&p->Data!=X)
    {
        p=p->Next;
    }
    if(p->Data==X)
            return p;
    else return ERROR;
}
bool Insert(List L, ElementType X, Position P)
{
    List t = L;
    while (t && t->Next != P)
        t = t->Next;
    if(!t)  {printf("Wrong Position for Insertion\n");return false;}
    List temp=(List)malloc(sizeof(struct LNode));
    temp->Data=X;
    temp->Next=t->Next;
    t->Next=temp;
    return true;
}
bool Delete(List L, Position P)
{
    List t=L;
    while(t&&t->Next!=P)
    {
        t=t->Next;
    }
    if(!t) {printf("Wrong Position for Deletion\n");return false;}
    List temp=t->Next;
    t->Next=temp->Next;
    temp->Next=NULL;
    free(temp);
    return true;
}