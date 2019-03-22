#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 105

char str1[maxn];
char str2[maxn];
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    while (scanf("%s%s", str1, str2) == 2)
    {
        int cnt1[26] = {0};
        int cnt2[26] = {0};

        for (int i = 0; i < strlen(str1); i++)
        {
            cnt1[str1[i] - 'A']++;
            cnt2[str2[i] - 'A']++;
        }

        qsort(cnt1, 26, sizeof(int), compare);
        qsort(cnt2, 26, sizeof(int), compare);
        int no = 0;
        for (int i = 0; i < 26; i++)
        {
            // printf("%d%d\n", cnt1[i], cnt2[i]);
            if (cnt1[i] != cnt2[i])
            {
                no = 1;
                break;
            }
        }
        if (no)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}