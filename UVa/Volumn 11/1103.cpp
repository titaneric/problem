#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <string>

using namespace std;

map<char, string> hex_dict = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'a', "1010"},
    {'b', "1011"},
    {'c', "1100"},
    {'d', "1101"},
    {'e', "1110"},
    {'f', "1111"}};

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};
map<int, char> symbol_dict = {
    {1, 'A'},
    {3, 'J'},
    {5, 'D'},
    {4, 'S'},
    {0, 'W'},
    {2, 'K'}};
bool valid_access(vector<vector<int>> &graph, int i, int j)
{
    int row = graph.size();
    int col = graph[0].size();
    return i >= 0 && i < row && j >= 0 && j < col;
}
bool valid_access(vector<vector<char>> &graph, int i, int j)
{
    int row = graph.size();
    int col = graph[0].size();
    return i >= 0 && i < row && j >= 0 && j < col;
}
bool non_visited(vector<vector<int>> &graph, vector<vector<int>> &index, int i, int j, int target)
{
    return index[i][j] == 0 && graph[i][j] == target;
}
bool non_visited(vector<vector<char>> &graph, vector<vector<int>> &index, int i, int j, char target)
{
    return index[i][j] == 0 && graph[i][j] == target;
}
void DFS(vector<vector<int>> &graph, vector<vector<int>> &index, int i, int j, int idx, int target)
{
    if (!valid_access(graph, i, j))
        return;
    if (!non_visited(graph, index, i, j, target))
        return;
    index[i][j] = idx;
    for (auto d : dir)
    {
        DFS(graph, index, i + d.first, j + d.second, idx, target);
    }
}
void DFS(vector<vector<char>> &graph, vector<vector<int>> &index, int i, int j, int idx, char target)
{
    if (!valid_access(graph, i, j))
        return;
    if (!non_visited(graph, index, i, j, target))
        return;
    index[i][j] = idx;
    for (auto d : dir)
    {
        DFS(graph, index, i + d.first, j + d.second, idx, target);
    }
}
int main()
{
    int kase = 1;
    int row, col;
    while (cin >> row >> col && row && col)
    {
        vector<vector<char>> graph(row);
        vector<vector<int>> index(row);

        vector<int> zero_row(col * 4);

        for (int i = 0; i < row; i++)
        {
            vector<char> tmp_row(col * 4);
            char hex;
            for (int j = 0; j < col; j++)
            {
                cin >> hex;
                copy(hex_dict[hex].begin(), hex_dict[hex].end(), tmp_row.begin() + j * 4);
            }
            graph[i] = tmp_row;
            index[i] = zero_row;
        }

        int idx = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col * 4; j++)
            {
                if (non_visited(graph, index, i, j, '1'))
                {
                    DFS(graph, index, i, j, ++idx, '1');
                }
            }
        }

        zero_row = vector<int>(4 * col + 2);
        vector<char> ans_vec;
        for (int order = 1; order <= idx; order++)
        {
            // augment graph by 2 row;
            vector<vector<int>> copy_graph(row + 2);
            vector<vector<int>> copy_index(row + 2);
            int hole_num = 0;

            copy_graph[0] = zero_row;
            copy_index[0] = zero_row;
            copy_graph[row + 1] = zero_row;
            copy_index[row + 1] = zero_row;

            // replace all non-i to zero
            for (int i = 0; i < row; i++)
            {
                // augment col by 2 pixel
                vector<int> tmp_row(4 * col + 2);
                copy(index[i].begin(), index[i].end(), tmp_row.begin() + 1);
                for (int j = 0; j < col * 4; j++)
                {
                    if (index[i][j] != order)
                        tmp_row[j + 1] = 0;
                }
                copy_graph[i + 1] = tmp_row;
                copy_index[i + 1] = zero_row;
            }

            // count the hole
            for (int i = 0; i < row + 2; i++)
            {
                for (int j = 0; j < col * 4; j++)
                {
                    if (non_visited(copy_graph, copy_index, i, j, 0))
                    {
                        DFS(copy_graph, copy_index, i, j, ++hole_num, 0);
                    }
                }
            }
            ans_vec.push_back(symbol_dict[hole_num - 1]);
        }

        sort(ans_vec.begin(), ans_vec.end());
        cout << "Case " << kase++ << ": ";
        for (auto s : ans_vec)
        {
            cout << s;
        }
        cout << endl;
    }
    return 0;
}
