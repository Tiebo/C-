#include<stdio.h>
#include<stdlib.h>

typedef struct _link{
    int n;
    struct _link *next;
}Link;

Link* Attach(int n,Link* rear)
{
    Link *t=(Link*)malloc(sizeof(Link));
    t->n=n; t->next=NULL;
    rear->next=t;
    rear=t;
    return rear;
}
void del(Link *head,int k)
{

    Link *p=head,*t;
    for(int i=1;i<k-1;i++) {
        p=p->next;
    }
    t=p->next;
    p->next=p->next->next;
    t=NULL;
}
int main()
{
    Link *head=(Link *)malloc(sizeof(Link));
    Link *rear=(Link *)malloc(sizeof(Link));

    int n;
    scanf("%d",&n);

    head->next=rear;
    rear->next=NULL;
    rear->n=1;

    for(int i=2; i<=n; i++)
        rear=Attach(i,rear);
    head=head->next;
    rear->next=head;

    int k=1;
    while(head->next!=head)
    {
        if(k%2==0)
        {
            head->next=head->next->next;
            k=1;
        }
        else
            k++;
        head=head->next;
    }
    printf("%d\n",head->n);
}