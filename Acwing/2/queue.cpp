#include <iostream>

using namespace std;

const int M = 10e5 + 10;
typedef struct _Queue {
    int  Data[M], hh, rr;
}Queue;

void inti(Queue* Q);
void push(Queue* Q, int x);
void pop(Queue* Q);
void empty(Queue* Q);
int query(Queue* Q);
void printQ(Queue* Q);

int main()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    int n;
    cin >> n;
    inti(Q);
    for (int i = 0;i < n;i++) {
        push(Q, i + 1);
    }
    pop(Q);
    empty(Q);
    cout << query(Q) << endl;
    printQ(Q);
    return 0;
}

void inti(Queue* Q)
{
    Q->hh = 0;
    Q->rr = -1;
}
void push(Queue* Q, int x)
{
    Q->Data[++(Q->rr)] = x;
}
void pop(Queue* Q)
{
    Q->hh++;
}
void empty(Queue* Q)
{
    cout << (Q->hh <= Q->rr ? "NO" : "Yes") << endl;
}
int query(Queue* Q)
{
    return Q->Data[Q->hh];
}
void printQ(Queue* Q)
{
    for (int i = Q->hh;i <= Q->rr;i++) {
        cout << Q->Data[i] << " ";
    }
}