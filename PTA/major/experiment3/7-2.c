#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num, a[20][20], cout = 0, sum = 0, i, j;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
        for (j = 0; j < num; j++)
        {
            scanf("%d", &a[i][j]);          //对数组进行输入
            if (i == j || i + j == num - 1) //累加的条件
            {
                if (a[i][j] != 0)
                    cout += 1; //记录非零的数字
                sum += a[i][j];
            }
        } //累加
    printf("sum = %d, count = %d.\n", sum, cout);
    return 0;
}