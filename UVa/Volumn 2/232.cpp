#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printWord(vector<vector<char>> &puzzle, vector<vector<int>> &init, int posx, int posy, int dirx, int diry)
{
    int x = posx, y = posy;
    while (init[x][y] != -1)
    {
        putchar(puzzle[x][y]);
        init[x][y] = -1;
        x += dirx;
        y += diry;
    }
}
int main()
{
    int kase = 0;
    int row, col;
    while (cin >> row && row)
    {
        cin >> col;

        if (kase)
            cout << endl;

        cout << "puzzle #" << ++kase << ":" << endl;

        vector<vector<char>> puzzle(row);
        for (int i = 0; i < row; i++)
        {
            vector<char> row_puzzle(col);
            for (int j = 0; j < col; j++)
            {
                cin >> row_puzzle[j];
            }
            puzzle[i] = row_puzzle;
        }

        vector<vector<int>> init(row + 1);

        int cnt = 1;
        for (int i = 0; i < row; i++)
        {
            vector<int> row_puzzle(col + 1);
            for (int j = 0; j < col; j++)
            {
                bool eligible = false;
                if ((i == 0 || j == 0) && puzzle[i][j] != '*')
                {
                    eligible = true;
                }
                else if ((j > 0) && (puzzle[i][j] != '*') && (puzzle[i][j - 1] == '*'))
                {
                    eligible = true;
                }
                else if ((i > 0) && (puzzle[i][j] != '*') && (puzzle[i - 1][j] == '*'))
                {
                    eligible = true;
                }
                else if (puzzle[i][j] == '*')
                {
                    row_puzzle[j] = -1;
                }
                if (eligible)
                {
                    row_puzzle[j] = cnt;
                    cnt++;
                }
            }
            row_puzzle[col] = -1;
            init[i] = row_puzzle;
        }
        vector<int> row_puzzle(col + 1);
        for (int i = 0; i < col + 1; i++)
        {
            row_puzzle[i] = -1;
        }
        init[row] = row_puzzle;

        vector<vector<int>> copy_init = init;

        // Across
        cout << "Across\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (init[i][j] > 0)
                {
                    cout << setw(3) << init[i][j] << ".";
                    printWord(puzzle, init, i, j, 0, 1);
                    cout << endl;
                }
            }
        }

        // Down
        cout << "Down\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (copy_init[i][j] > 0)
                {
                    cout << setw(3) << copy_init[i][j] << ".";
                    printWord(puzzle, copy_init, i, j, 1, 0);
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
