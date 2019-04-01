#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int>> direction = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}};
bool valid_access(vector<vector<char>> &table, int i, int j)
{
    int r = table.size();
    int c = table[0].size();

    return (i >= 0) && (i < r) && (j >= 0) && (j < c);
}
string locate_string(vector<vector<char>> &table, string &query, int i, int j, int si, int sj)
{
    string str = "";
    int m = i;
    int n = j;
    int c = 0;
    for (; valid_access(table, m, n) && c < query.size(); m += si, n += sj, c++)
    {
        str += table[m][n];
    }
    return str;
}
bool find_query(vector<vector<char>> &table, string &query, int i, int j)
{
    for (int d = 0; d < 8; d++)
    {
        string s = locate_string(table, query, i, j, direction[d].first, direction[d].second);
        if (s == query)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<char>> table(r);

        char chr;
        for (int i = 0; i < r; i++)
        {
            vector<char> row(c);
            for (int j = 0; j < c; j++)
            {
                cin >> chr;
                row[j] = tolower(chr);
            }
            table[i] = row;
        }

        int query_num;
        cin >> query_num;

        string query;
        for (int i = 0; i < query_num; i++)
        {
            cin >> query;
            if (!query.empty() && query[query.size() - 1] == '\r')
            {
                query.erase(query.size() - 1);
            }
            transform(query.begin(), query.end(), query.begin(), ::tolower);

            bool terminated = false;
            for (int i = 0; i < r && !terminated; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (table[i][j] == query[0] && find_query(table, query, i, j))
                    {
                        cout << i + 1 << " " << j + 1 << endl;
                        terminated = true;
                        break;
                    }
                }
            }
        }

        if (k != (kase - 1))
        {
            cout << endl;
        }
    }
    return 0;
}