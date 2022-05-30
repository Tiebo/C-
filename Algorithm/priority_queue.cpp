#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue <int> q;

    int a[10]={5,3,4,7,1,2,4,8,2,5};
    for(int i=0; i<10;i++)
        q.push(a[i]);
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
}