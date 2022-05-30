/*
stack<int> q;	//以int型为例
int x;
q.push(x);		//将x压入栈顶
q.top();		//返回栈顶的元素
q.pop();		//删除栈顶的元素
q.size();		//返回栈中元素的个数
q.empty();		//检查栈是否为空,若为空返回true,否则返回false
*/
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i <n;i++){
        cin>>a[i];
        s.push(a[i]);
    }
    while(!s.empty())
    {
        cout<<"q.top="<<s.top()<<endl;
        s.pop();
    }
    return 0;
}