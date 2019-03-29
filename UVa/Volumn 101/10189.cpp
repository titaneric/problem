#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    int r, c;
    int kase = 0;
    while (cin >> r >> c && r && c)
    {
        if (kase)
        {
            putchar('\n');
        }

        cout << "Field #" << ++kase << ":\n";
        vector<vector<char>> place(r + 2);

        vector<char> line(c + 2, '.');
        for (int i = 0; i < place.size(); i++)
        {
            place[i] = line;
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> place[i + 1][j + 1];
            }
        }

        vector<vector<int>> hint(r);

        for (int i = 1; i <= r; i++)
        {
            vector<int> row(c);
            for (int j = 1; j <= c; j++)
            {
                if (place[i][j] == '*')
                {
                    row[j - 1] = -1;
                }
                else
                {
                    vector<char> adjacent;
                    for (int m = -1; m < 2; m++)
                    {
                        for (int n = -1; n < 2; n++)
                        {
                            if (m == 0 && n == 0)
                                continue;
                            adjacent.push_back(place[i + m][j + n]);
                        }
                    }
                    row[j - 1] = count(adjacent.begin(), adjacent.end(), '*');
                }
            }
            hint[i - 1] = row;
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hint[i][j] == -1)
                {
                    putchar('*');
                }
                else
                {
                    cout << hint[i][j];
                }
            }
            putchar('\n');
        }
    }
    return 0;
}