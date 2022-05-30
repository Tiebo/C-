#include<iostream>
#define endl "\0"
using namespace std;

typedef struct _Stack{
    int Data[10];
    int top;
}Stack;
Stack* CreatStack()
{
    Stack *s=new Stack();
    s->top=-1;
    return s;
}
bool isfull(Stack *s)
{
    return (s->top==sizeof(s->Data)/sizeof(s->Data[0])-1);
}
void push(Stack *s,int num)
{
    if(isfull(s))
    {
        printf("stack is full\n");
        return;
    }
    s->Data[++(s->top)] = num;
}
bool isempty(Stack *s)
{
    return (s->top==-1);
}
void pop(Stack *s)
{
    if(isempty(s))
    {
        printf("stack is empty\n");
        return ;
    }
    s->Data[(s->top)--] = 0;
}
int top(Stack *s)
{
    return s->Data[s->top];
}
int main()
{
    Stack *s;
    s=CreatStack();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        push(s,i);
    pop(s);
    cout<<top(s)<<endl;
}