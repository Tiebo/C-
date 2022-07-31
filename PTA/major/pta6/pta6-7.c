//指定位置输出字符串
#include <stdio.h>
#include <string.h>
#define MAXB 10

char *match(char *s, char ch1, char ch2);

int main()
{
    char str[MAXB], ch_start, ch_end, *p;
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}
char *match(char *s, char ch1, char ch2)
{
    char *p;
    int j, i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ch1)
            break;
    }
    p = &s[i];
    for (j = i; j < strlen(s); j++)
    {
        printf("%c", s[j]);
        if (s[j] == ch2)
            break;
    }
    printf("\n");
    return p;
}