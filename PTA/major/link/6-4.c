#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition of ListNode
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode LinkNode;
/*
head为链表头指针；val为需要删除的值。
 函数返回值为删除val后的链表的头指针。
*/
struct ListNode *removeElements(struct ListNode *head, int val);

/* 创建链表，细节不表 */
LinkNode *buildList()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int i = 0;
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->next = NULL;
    while (n--)
    {
        LinkNode *temp = (LinkNode *)malloc(sizeof(LinkNode));
        temp->val = arr[i];
        temp->next = NULL;
        LinkNode *rear;
        for (rear = p; rear->next; rear = rear->next)
            ;
        rear->next = temp;
        i++;
    }
    return p->next;
}
/* 打印链表，细节不表 */
void printList(struct ListNode *head)
{
    printf("%d", head->val);
    for (struct ListNode *p = head->next; p; p = p->next)
    {
        printf(" %d", p->val);
    }
}

int main()
{
    int val;
    struct ListNode *head = buildList();
    scanf("%d", &val);
    head = removeElements(head, val);
    printList(head);

    return 0;
}

struct ListNode *removeElements(struct ListNode *head, int val)
{
    typedef struct ListNode LinkNode;
    while (head && head->val == val)
        head = head->next;
    LinkNode *p = head, *temp = head;
    while (p)
    {
        if (p->val == val)
        {
            while (temp->next != p)
                temp = temp->next;
            temp->next = p->next;
            p->next = NULL;
            free(p);
            p = temp->next;
        }
        else
            p = p->next;
    }
    return head;
}
// 1 2 3 4 5 6
