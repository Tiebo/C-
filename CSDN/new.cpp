//new的用法
#include<iostream>
using namespace std;
struct Test1{
    string name;
    int age;
    struct  Test1 *next;
};

class Test2{
    public://定义属性
    string name;
    int age=0;
    Test2 *next=NULL;

    public://定义方法->四种初始化方法
        Test2(){}
        Test2(string name){
            this->name=name;
        }
        Test2(int age){
            this->age=age;
        }
        Test2(string name,int age){
            this->name=name;
            this->age=age;
        }
};

int main()
{
    int *a=new int(5);//输出:5
    cout<<*a<<" "<<endl;

    int *b=new int[5]{0};
    for(int i=0;i<5;i++)
        cout<<b[i]<<" ";//输出: 0 0 0 0 0
    cout<<endl;

    int *c=new int[5]{0,1,2,3,4};
    for(int i=0;i<5;i++)
        cout<<c[i]<<" ";//输出: 0 1 2 3 4
    cout<<endl;


    Test1 *d=new Test1();//自动初始化 name="",age=0,next=NULL; 
    d->name="xiaoming",d->age=18,d->next=NULL;//赋值
    cout<<"name:"<<d->name<<" age:"<<d->age<<" next:"<<d->next<<endl;

    Test2 *e=new Test2();
    cout<<e->name<<"+"<<e->age<<endl;//输出:+0

    string name="xiaoming";
    int age=18;

    Test2 *f=new Test2(name);
    cout<<f->name<<"+"<<f->age<<endl;//输出:xiaoming+0

    Test2 *g=new Test2(age);
    cout<<g->name<<"+"<<g->age<<endl;//输出:+18;

    Test2 *h=new Test2(name,age);
    cout<<h->name<<"+"<<h->age<<endl;//输出:xiaoming+18;
}
