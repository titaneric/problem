#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool valid_access(vector<vector<char>> &oil, int i, int j)
{
    int row = oil.size();
    int col = oil[0].size();
    return i >= 0 && i < row && j >= 0 && j < col;
}
bool non_visited(vector<vector<char>> &oil, vector<vector<int>> &index, int i, int j)
{
    return index[i][j] == 0 && oil[i][j] == '@';
}
void DFS(vector<vector<char>> &oil, vector<vector<int>> &index, int i, int j, int idx)
{
    if (!valid_access(oil, i, j))
        return;
    if (!non_visited(oil, index, i, j))
        return;
    index[i][j] = idx;
    for (int r = -1; r <= 1; r++)
    {
        for (int c = -1; c <= 1; c++)
        {
            DFS(oil, index, i + r, j + c, idx);
        }
    }
}
int main()
{

    int row, col;
    while (cin >> row >> col && row && col)
    {
        vector<vector<char>> oil(row);
        vector<vector<int>> index(row);

        vector<int> zero_row(col);

        for (int i = 0; i < row; i++)
        {
            vector<char> tmp_row(col);
            for (int j = 0; j < col; j++)
            {
                cin >> tmp_row[j];
            }
            oil[i] = tmp_row;
            index[i] = zero_row;
        }

        int idx = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (non_visited(oil, index, i, j))
                {
                    DFS(oil, index, i, j, ++idx);
                }
            }
        }

        cout << idx << endl;
    }
    return 0;
}
