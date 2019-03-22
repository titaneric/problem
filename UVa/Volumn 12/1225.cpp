#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getDigit(int num, int digit[10])
{
    while (num > 0)
    {
        /* code */
        digit[num % 10]++;
        num /= 10;
    }
}

int main()
{
    int total;
    scanf("%d", &total);
    for (int k = 0; k < total; k++)
    {
        int maxn;
        scanf("%d", &maxn);
        int num[10] = {0};
        for (int i = 1; i <= maxn; i++)
        {
            getDigit(i, num);
        }
        for (int i = 0; i < 9; i++)
        {
            printf("%d ", num[i]);
        }
        printf("%d", num[9]);
        printf("\n");
    }

    return 0;
}
