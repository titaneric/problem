#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define seqn 50

void swap(int array[][5], int x1, int y1, int x2, int y2)
{
    int t = array[x1][y1];
    array[x1][y1] = array[x2][y2];
    array[x2][y2] = t;
}
int main()
{
    int puzzle[5][5];
    int e_i, e_j;
    char c;
    int kase = 0;
    while ((c = getchar()) != 'Z')
    {
        /* code */
        ungetc(c, stdin);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                puzzle[i][j] = getchar();
                // putchar(puzzle[i][j]);
                if (puzzle[i][j] == ' ')
                {
                    e_i = i;
                    e_j = j;
                }
            }
            getchar(); // line break
        }
        int error = 0;
        while ((c = getchar()) != '0')
        {
            if (isspace(c))
                continue;
            if (c == 'A')
            {
                if (e_i == 0)
                {
                    error = 1;
                    break;
                }
                swap(puzzle, e_i, e_j, --e_i, e_j);
            }
            else if (c == 'B')
            {
                if (e_i == 4)
                {
                    error = 1;
                    break;
                }
                swap(puzzle, e_i, e_j, ++e_i, e_j);
            }
            else if (c == 'L')
            {
                if (e_j == 0)
                {
                    error = 1;
                    break;
                }
                swap(puzzle, e_i, e_j, e_i, --e_j);
            }
            else if (c == 'R')
            {
                if (e_j == 4)
                {
                    error = 1;
                    break;
                }
                swap(puzzle, e_i, e_j, e_i, ++e_j);
            }
        }
        // eat rest of input
        if (error)
            while ((c = getchar()))
                ;

        if (getchar() == 'Z')
            break;

        kase++;
        if (kase > 1)
            putchar('\n');
        printf("Puzzle #%d:\n", kase);
        if (error)
            printf("This puzzle has no final configuration.\n");
        else
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    putchar(puzzle[i][j]);
                    if (j < 4)
                        putchar(' ');
                }
                putchar('\n');
            }
    }
    return 0;
}