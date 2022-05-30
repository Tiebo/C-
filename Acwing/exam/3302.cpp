//表达式求值
#include <iostream>

using namespace std;

const int N = 100010;
int num[N], ntt = -1, ott = -1;
char op[N];

void eval()
{
    //取出数值并运算 顺序不能变！！！
    int b = num[ntt--];
    int a = num[ntt--];
    char c = op[ott--];
    //做运算
    int x = 0;
    if (c == '+')       x = a + b;
    else if (c == '-')  x = a - b;
    else if (c == '*')  x = a * b;
    else if (c == '/')  x = a / b;

    num[++ntt] = x; //结果压入值栈
}

int prop(char c)
{
    int pr;
    switch (c)
    {
    case '+':pr = 1;break;
    case '-':pr = 1;break;
    case '*':pr = 2;break;
    case '/':pr = 2;break;
    default:pr = 0;
    }
    return pr;
}

int main()
{
    //读入字符串
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i]; //得到当前字符

        if (isdigit(c)) //如果c是数字，就读入然后存入栈中
        {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            i = j - 1; //因为循环结束后会执行一次j++,所以应该把j-1赋给i
            num[++ntt] = x;
        }
        else if (c == '(')
            op[++ott] = c;
        else if (c == ')')
        {
            while (op[ott] != '(')
                eval();
            ott--;
        }
        else
        {
            while (ott != -1 && op[ott] != '(' && prop(op[ott]) >= prop(c)) // op的优先级要高于c中top的优先级
                eval();
            op[++ott] = c; //把当前运算符入栈
        }
    }

    while (ott != -1)
        eval();
    cout << num[ntt] << endl;
    return 0;
}