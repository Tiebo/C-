#include<iostream>

using namespace std;
//声明结构体，即链表节点
typedef struct _Link{
    int Data;
    struct _Link *next;
}Link;
//创建一个带头节点的链表
Link *CreatLink()
{
    Link *head=(Link *)malloc(sizeof(Link));
    head->next=NULL;
    return head;
}
//向链表尾端插入元素
void Attach(Link **rear, int num)
{
    //声明一个节点用来存放要插入的元素
    Link *temp=(Link *)malloc(sizeof(Link));
    temp->Data=num;
    temp->next=NULL;
    //让新节点链接上原尾节点
    (*rear)->next=temp;
    //尾节点更新为现链表尾端
    (*rear)=temp;
}
//往第k个数后面插入值
void AddNode(Link *L,int k,int num)
{
    //声明新节点来存放数值
    Link *P=(Link *)malloc(sizeof(Link));
    P->Data=num;
    //插入到第k个数后面，因为有头节点，所以要循环k次
    for(int i=0;i<k;i++)
        L=L->next;
    //链接上新节点
    P->next=L->next;
    L->next=P;
}
//遍历链表
void printN(Link *L)
{
    for(Link *p=L->next;p;p=p->next)
    {
        cout<<p->Data<<" ";
    }
    cout<<"\n";
}
//删除值为num的节点
void Delete(Link *L,int num)
{
    for(Link *p=L;p->next;p=p->next)
    {
        //查询值
        if(p->next->Data==num)
        {
            //删除节点
            Link *temp=p->next;
            p->next=temp->next;
            temp->next=NULL;
            //释放被删除的节点
            free(temp);
            temp=NULL;
            //可以选择结束循环
            // break;
            p=L;
        }
    }
}
//删除第k个数
void Deletek(Link *L,int k)
{
    Link *p=L;
    for(int i=0;i<k&&p;i++)
        p=p->next;
    if(!p)   printf("Invalid!");
    else{
        Link *temp=p->next;
        p->next=temp->next;
        temp->next=NULL;
        free(temp);
        temp=NULL;
    }
}
int size(Link *L)
{
    int con=0;
    for(Link *p=L->next;p;p=p->next)
        con++;
    return con;
}
void reverse(Link *L)
{
    //1 2 3 4 5     5  1  2   3  4       5-4-1 2 3
    Link *p=L,*temp,*prev;
    L=L->next;
    prev=NULL;
    while(L)
    {
        temp=L->next;
        L->next=prev;
        prev=L;
        L=temp;
    }
    p->next=prev;
}
int main()
{
    //创建链表
    Link *L,*rear;
    L=CreatLink();
    rear=L;
    int n,num;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        //传入指针的地址，用来改变rear经过函数操作后主函数的rear
        Attach(&rear,num);
    }
    cout<<"此时链表为: ";
    printN(L);
    cout<<"逆转后链表为：";
    reverse(L);
    printN(L);
    // int k;
    // cin>>k>>num;
    // AddNode(L,k,num);
    // printN(L);
    //删除值为num的节点
    //cin>>num;
    //Delete(k,num);
    //删除第k+1的数
    //k=k+1;
    // Deletek(L,k);
    cout<<"链表的长度为"<<size(L);
    return 0;
}