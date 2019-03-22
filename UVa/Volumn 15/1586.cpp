#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxn 85
#define maxC 10

int quantity(const char *str)
{
    // char substr[maxC];
    int i = 0;
    // int num = 0;
    int n = strlen(str);
    while (i < n && isdigit(str[i]))
    {
        /* code */
        i++;
    }

    // printf("func: %s\n", str);
    // memcpy(des, str, i);
    return i;
}
int main()
{
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++)
    {

        char str[maxn];
        scanf("%s", str);
        int n = strlen(str);
        double mole = 0.0;
        for (int i = 0; i < n;)
        {
            if (str[i] == 'C' || str[i] == 'H' || str[i] == 'N' || str[i] == 'O')
            {
                int c = quantity(str + i + 1);
                int true_cnt;
                int cur_i = i;
                if (!c)
                {
                    true_cnt = 1;
                    i++;
                }
                else
                {
                    char num[maxC];
                    memcpy(num, str + i + 1, c);
                    // printf("%s", num);
                    true_cnt = atoi(num);
                    i += (c + 1);
                }
                // printf("%c: %d\n", str[cur_i], true_cnt);
                switch (str[cur_i])
                {
                case 'C' /* constant-expression */:
                    /* code */
                    mole += 12.01 * true_cnt;
                    break;
                case 'H':
                    mole += 1.008 * true_cnt;
                    break;
                case 'O':
                    mole += 16.00 * true_cnt;
                    break;
                case 'N':
                    mole += 14.01 * true_cnt;
                    break;
                default:
                    break;
                }
            }
        }
        printf("%.3f\n", mole);
    }
    return 0;
}