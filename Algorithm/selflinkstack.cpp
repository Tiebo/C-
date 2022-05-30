#include <iostream>
#include <cstdlib>
typedef struct _LinkStack
{
    int Data;
    struct _LinkStack *next;
} Stack;
Stack *CreateStack()
{
    Stack *S;
    S = (Stack *)malloc(sizeof(Stack));
    S->next = NULL;
    return S;
}
int IsEmpty(Stack *S)
{
    return (S->next == NULL ? 1 : 0);
}
void Push(int num, Stack *s) //压入元素
{
    Stack *t = (Stack *)malloc(sizeof(Stack));
    t->Data = num;
    t->next = s->next;
    s->next = t;
}
int top(Stack *s) //返回栈顶元素
{
    return (s->next->Data);
}
void Pop(Stack *s) //弹出栈顶元素
{
    if (IsEmpty(s))
    {
        printf("堆栈空");
        return;
    }
    Stack *t = s->next;
    s->next=t->next;
    free(t);
    t=NULL;
}
int main()
{
    Stack *s;
    s = CreateStack();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        Push(i, s);
    while (!IsEmpty(s))
    printf("%d ", top(s)),Pop(s);
    return 0;
}