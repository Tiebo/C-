#include <stdio.h>
#include <stdlib.h>

/* 单链表结点类型定义 */
typedef struct LNode
{
    int data;
    struct LNode *next;
} LinkNode;

/* 从尾到头打印单链表 */
void printListFromTail2Head(LinkNode* head);

/* 创建单链表,细节不表 */
LinkNode* buildList(int* arr, int n)
{
    int i=0;
    LinkNode *p=(LinkNode*)malloc(sizeof(LinkNode));
    p->next=NULL;
    while(n--)
    {
        LinkNode *temp=(LinkNode*)malloc(sizeof(LinkNode));
        temp->data=arr[i];
        temp->next=NULL;
        LinkNode *rear;
        for(rear=p;rear->next;rear=rear->next);
        rear->next=temp;
        i++;
    }
    return p->next;
}

int main(void)
{
    int n, i;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    LinkNode* head = buildList(arr, n);
    printListFromTail2Head(head);
    printf("\n");

    free(arr);

    return 0;
}

void printListFromTail2Head(LinkNode* head)
{
    LinkNode* t,*p=head;
    while(p->next)
    {
        for(t=p;t->next->next;t=t->next);
        printf("%d ",t->next->data);
        LinkNode* temp;
        temp=t->next;
        t->next=NULL;
        free(temp);
    }
    printf("%d ",p->data);
}