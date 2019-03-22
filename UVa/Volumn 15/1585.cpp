#include <stdio.h>
#include <string.h>
#define maxn 85

int main()
{
    char str[maxn];
    int total;
    scanf("%d", &total);
    for (int k = 0; k < total; k++)
    {
        scanf("%s", str);
        int n = strlen(str);
        int score = 0;
        int o = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'O')
            {
                o++;
                score += o;
            }
            else
            {
                o = 0;
            }
        }
        printf("%d\n", score);
    }

    return 0;
}