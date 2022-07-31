#include <stdio.h>
#include <string.h>

#define MAXB 10

void Shift(char s[]);

void GetString(char s[]); /* 实现细节在此不表 */

int main()
{
    char s[MAXB];

    GetString(s);
    Shift(s);
    printf("%s\n", s);

    return 0;
}
void Shift(char s[])
{

    int i, len;
    char b[3];
    len = strlen(s); /*计算字符串长度n作为循环的终止条件*/
    for (i = 0; i < 3; i++)
    {
        b[i] = s[i]; /*将前3个字母赋给数组b*/
    }
    for (i = 3; i < len; i++)
    {
        s[i - 3] = s[i]; /*将s数组中除前三个字母之外的其他字母向前移动三个单位*/
    }
    for (i = 0; i < 3; i++)
    {
        s[len - 3 + i] = b[i]; /*将数组b中的字母赋给s数组的倒数前三个字母*/
    }
}
void GetString(char s[])
{
    gets(s);
}