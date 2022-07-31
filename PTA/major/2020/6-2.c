//约瑟夫问题
#include <stdio.h>
#define L 2000
//指针p指向的一维数组有n个元素，然后按照数字m进行报数出列。
void yuesefu(int *p, int n, int m);
int main()
{
    int a[L];
    int M, N;
    scanf("%d%d", &N, &M);
    yuesefu(a, N, M);
}

void yuesefu(int *p, int n, int m)
{
    int count = 0, k = 0, i = 0, a[n];
    for (int i = 0; i < n; i++)
        p[i] = i + 1;
    for (; k < n; i++)
    {
        if (i + 1 > n)
            i = 0;
        if (p[i] == 0)
        {
            i++;
            continue;
        }
        count++;
        if (count == m)
        {
            a[k++] = p[i];
            p[i] = 0;
            count = 0;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}