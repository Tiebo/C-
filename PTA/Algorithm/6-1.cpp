//单链表逆转
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse( List L )
{
    List temp,prev;
    prev=NULL;
    while(L)
    {
        temp=L->Next;
        L->Next=prev;
        prev=L;
        L=temp;
    }
    return prev;
}

List Read()  
{  
    List head = NULL;  
    List current;  
    List prev = NULL;  
    int len = 0;  
    scanf("%d", &len);  
    if (len == 0)   return NULL;  
    
    while (len--)   
    {  
        current = (List)malloc(sizeof(struct Node));  
        if (head == NULL)  
            head = current;  
        else  
        prev->Next = current;  
        current->Next = NULL;  
        scanf("%d", &current->Data);  
        prev = current; 
    }  
    return head;  
}  
  
void Print(List L)  
{  
    List p = L;  
    if (p == NULL)  
        printf("NULL");  
    else  
        printf("\n");  
    while (p!=NULL) {  
        printf("%d ", p->Data);  
        p = p->Next;  
    }  
} 
