//链式表操作集
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

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR)
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
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

Position Find(List L, ElementType X)
{
    List p = L;
    while (p && p->Data != X)
        p = p->Next;
    return p ? ((p->Data == X) ? p : ERROR) : ERROR;
}
List Insert(List L, ElementType X, Position P)
{
    if (L == NULL)
    {
        L = (List)malloc(sizeof(struct LNode));
        L->Data = X;
        L->Next = NULL;
        return L;
    }
    List t = L;
    while ((t && t->Next != P)&&t!=P)
        t = t->Next;
    if (!t)
    {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
    List temp = (List)malloc(sizeof(struct LNode));
    temp->Data = X;
    temp->Next = t->Next;
    t->Next = temp;
    return L;
}
List Delete(List L, Position P)
{
    List t=L;
    if(P==t)    {L=L->Next;free(t);return L;}
    while(t!=NULL&&t->Next!=P) 
        t = t->Next;
    if(t==NULL)     {printf("Wrong Position for Deletion\n");return ERROR;}
    List temp=t->Next;
    t->Next=temp->Next;
    temp->Next=NULL;
    free(temp);
    return L;
}