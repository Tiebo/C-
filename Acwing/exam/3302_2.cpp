//表达式求值
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

stack<char> op;
stack<int> num;

void eval()
{
    int b = num.top();num.pop();
    int a = num.top();num.pop();
    char c = op.top();op.pop();

    int x = 0;
    if (c == '+')       x = a + b;
    else if (c == '-')  x = a - b;
    else if (c == '*')  x = a * b;
    else if (c == '/')  x = a / b;              

    num.push(x);
}

int main()
{
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if (isdigit(c))
        {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';

            i = j - 1;
            num.push(x);
        }
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(')
                eval();

            op.pop();
        }
        else
        {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while (op.size())
        eval();

    cout << num.top() << endl;

    return 0;
}