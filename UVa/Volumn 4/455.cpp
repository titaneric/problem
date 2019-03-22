#include <stdio.h>
#include <string.h>
#define maxn 85
int main()
{
    int total;
    scanf("%d", &total);
    for (int k = 0; k < total; k++)
    {
        char str[maxn];
        scanf("%s", str);

        int factor[maxn] = {0};
        int cnt = 0;
        int n = strlen(str);
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                factor[cnt++] = i;
            }
        }
        int minimum_cycle = 1;
        for (int i = 0; i < cnt; i++)
        {
            int cycle = factor[i];
            char previous[maxn];
            memcpy(previous, str, cycle);

            int iter = cycle;
            int isPeriodic = 1;
            while (iter < n)
            {
                /* code */
                char substr[maxn];
                memcpy(substr, str + iter, cycle);
                // printf("%s: %s\n", previous, substr);
                if (memcmp(previous, substr, cycle))
                {
                    isPeriodic = 0;
                    break;
                }
                iter += cycle;
            }
            if (!isPeriodic)
                continue;
            else
            {
                minimum_cycle = cycle;
                break;
            }
        }
        if (k == (total - 1))
        {
            printf("%d\n", minimum_cycle);
        }
        else
        {

            printf("%d\n\n", minimum_cycle);
        }
    }

    return 0;
}