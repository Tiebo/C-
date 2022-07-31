#include <stdio.h>
#define MAXB 10

struct student
{
    int num;
    char name[20];
    int score;
    char grade;
};

int set_grade(struct student *p, int n);

int main()
{
    struct student stu[MAXB], *ptr;
    int n, i, count;

    ptr = stu;
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
    }
    count = set_grade(ptr, n);
    printf("The count for failed (<60): %d\n", count);
    printf("The grades:\n");
    for (i = 0; i < n; i++)
        printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
    return 0;
}

int set_grade(struct student *p, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int num = (p + i)->score;
        if (num < 60)
        {
            (p + i)->grade = 'D';
            cnt++;
        }
        else if (num >= 60 && num < 70)
            (p + i)->grade = 'C';
        else if (num >= 70 && num < 85)
            (p + i)->grade = 'B';
        else if (num >= 85 && num <= 100)
            (p + i)->grade = 'A';
    }
    return cnt;
}