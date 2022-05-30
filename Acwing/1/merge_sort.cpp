#include <iostream>

using namespace std;

const int N = 10e6 + 10;
int q[N], tem[N];

void mergesort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;//划分区间

    mergesort(q, l, mid);//递归左边
    mergesort(q, mid + 1, r);//递归右边

    int k = 0, i = l, j = mid + 1;//k用来计数，i作为左区间起点，j作为右区间起点
    while (i <= mid && j <= r)//将小的存入tem中
        if (q[i] <= q[j])
            tem[k++] = q[i++];
        else
            tem[k++] = q[j++];
    while (i <= mid)//如果左区间未遍历完，全部存入tem
        tem[k++] = q[i++];
    while (j <= r)//如果右区间未遍历完，全部存入tem
        tem[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)//替换q中的值
        q[i] = tem[j];
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    mergesort(q, 0, n - 1);

    for (int i=0; i < n; i++)
        printf("%d ", q[i]);
}