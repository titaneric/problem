#include <stdio.h>

char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
int main()
{
    int chr;

    while ((chr = getchar()) != EOF)
    {
        /* find chr index */
        int i;
        for (i = 1; keyboard[i] && keyboard[i] != chr; i++)
            ;
        if (keyboard[i])
            putchar(keyboard[i - 1]);
        else
            putchar(chr);
    }

    return 0;
}