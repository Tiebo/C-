//表达式求值
#include <iostream>
#include <cmath>
#include "MyStack.h"
using namespace std;

stack<double> num; //创建数值栈
stack<char> op;    //创建字符栈

void eval();                              //取出num与op进行运算
int prop(char c);                         //得到运算符优先级
void judge(const string &str, int &i);    //根据字符判断进行哪一步操作
void ReadNumber(const string str, int &i); //根据字符串读入数值
bool isNumber(const string &str, int &i); //判断是否为数字
bool isNegative(const string &str,const int &i);//判断是否为负数

int main()
{
  //读入字符串
  string str;
  printf("请输入中缀表达式：\n");
  getline(cin, str);

  printf("操作数栈栈顶元素变化：\n");
  for (int i = 0; i < str.size(); i++)
    judge(str, i);

  while (!op.empty())
    eval();

  printf("表达式的结果为：%.2lf ", num.top());

  return 0;
}

void eval()
{
  //取出数值并运算 顺序不能变！！！
  double b = num.top();num.pop();
  double a = num.top();num.pop();
  char c = op.top();op.pop();
  //做运算
  double x = 0;
  if (c == '+')       x = a + b;
  else if (c == '-')  x = a - b;
  else if (c == '*')  x = a * b;
  else if (c == '/')  x = a / b;
  else if (c == '^')  x = pow(a, b);
  else if (c == '%')  x = (int)a % (int)b;

  num.push(x);                  //结果压入值栈
  printf("%.2lf\n", num.top()); //栈顶元素变化
}
int prop(char c)
{
  int pr;
  switch (c)
  {
  case '+': pr = 1;break;
  case '-': pr = 1;break;
  case '*': pr = 2;break;
  case '/': pr = 2;break;
  case '%': pr = 2;break;
  case '^': pr = 3;break;
  default:  pr = 0; //括号的优先级为0
  }
  return pr;
}
bool isNegative(const string &str,const int &i)
{
  //判断是否为负数
  if (i == 0 && str[i] == '-' && isdigit(str[i + 1]))
    return true;
  else if (str[i] == '-' && !isdigit(str[i - 1]) && isdigit(str[i + 1]))
    return true;

  return false;
}
void ReadNumber(const string str, int &i)
{
  //j与k用来计数，flag用来得到负数
  int j = i, k = 1, flag = 1;
  double x = 0;
  //判断是否为负
  if (isNegative(str, i))
    flag = -1, j++;

  while (j < str.size() && (isdigit(str[j]) || str[j] == '.'))
  {
    if (isdigit(str[j]))
      x = x * 10 + flag * (str[j++] - '0');//读入整数
    else if (str[j] == '.')
    {
      j++;
      x = x + pow(10, -(k++)) * (double)(str[j++] - '0'); //读入小数
    }
  }
  i = j - 1; //因为循环结束后会执行一次j++,所以应该把j-1赋给i
  num.push(x);
  printf("%.2lf\n", num.top());
}
void judge(const string &str, int &i)
{
  char c = str[i]; //得到当前字符

  if (c == ' '){return;} //特判空格

  if (isNegative(str, i) || isdigit(str[i])) //如果c是数字，就读入然后存入栈中
      ReadNumber(str, i);
  else if (c == '(') //如果读入左括号，直接压入字符栈
      op.push(c);
  else if (c == ')') //如果读入右括号，不断运算直至遇到匹配的左括号
  {
    while (op.top() != '(')
      eval();
    op.pop();
  }
  else
  {
    // op的优先级要高于c中top的优先级
    while (!op.empty() && op.top() != '(' && prop(op.top()) > prop(c))
      eval();
    op.push(c); //把当前运算符入栈
  }
}