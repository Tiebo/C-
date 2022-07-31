#include <stdio.h>
#include <string.h>
int main()
{
    int i, n;
    char str1[10], str2[10], max[10];
    scanf("%s", str1);
    for (i = 0; i<strlen(str1); i++)
        max[i] = str1[i];
    for (i = 1; i < 5; i++)
    {
        scanf("%s", str2);
        if (strcmp(max, str2)<0)
        {
            for (int j = 0; j<10; j++)
                max[j] = str2[j];
        }
    }
    printf("Max is: %s\n", max);
    return 0;
}