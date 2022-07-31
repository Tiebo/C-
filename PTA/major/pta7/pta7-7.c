#include <stdio.h>
typedef struct _students
{
    char num[10];
    char name[15];
    int math, chinese, english;
} students;
int main()
{
    int N;
    scanf("%d", &N);
    students stu[N];
    int all[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %d %d %d", stu[i].num, stu[i].name,
              &stu[i].math, &stu[i].chinese, &stu[i].english);
        stu[i].num[5] = '\0';
        all[i] = stu[i].math + stu[i].chinese + stu[i].english;
    }
    int max = 0, k = 0;
    for (int i = 0; i < N; i++)
    {
        if (max < all[i])
        {
            max = all[i];
            k = i;
        }
    }
    printf("%s %s %d", stu[k].name, stu[k].num, max);
    return 0;
}