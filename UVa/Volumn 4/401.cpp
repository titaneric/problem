#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char *ref = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome", "a regular palindrome",
                     "a mirrored string", "a mirrored palindrome"};

char getMirror(char chr)
{
    if (isalpha(chr))
        return ref[chr - 'A'];
    return ref[chr - '0' + 25];
}
int main()
{
    char str[30];
    while (scanf("%s", str) == 1)
    {
        /* code */
        int len = strlen(str);
        int i;
        int isPalindrome = 1, isMirrored = 1;
        for (i = 0; i < (len + 1) / 2; i++)
        {
            if (str[i] != str[len - 1 - i])
                isPalindrome = 0;
            if (getMirror(str[i]) != str[len - 1 - i])
                isMirrored = 0;
        }
        printf("%s -- is %s.\n\n", str, msg[isMirrored * 2 + isPalindrome]);
    }

    return 0;
}