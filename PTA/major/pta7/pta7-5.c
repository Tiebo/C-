#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    typedef struct tag
    {
        char name[10];
        float wage, vary, pay;
    } information;
    information member[N];
    float real[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", &member[i].name, &member[i].wage, &member[i].vary, &member[i].pay);
        real[i] = member[i].wage + member[i].vary - member[i].pay;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%s %.2f\n", &member[i].name, real[i]);
    }

    return 0;
}