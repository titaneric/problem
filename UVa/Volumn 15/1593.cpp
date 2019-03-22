#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    vector<vector<string>> token_table;
    map<int, int> col_width_dict;
    string line, token;

    while (getline(cin, line))
    {
        stringstream ss(line);
        int col = 0;
        vector<string> row_token;
        while (ss >> token)
        {
            // find the maximum column width
            auto iter = col_width_dict.find(col);
            if (iter == col_width_dict.end())
            {
                col_width_dict[col] = token.size();
            }
            else
            {
                col_width_dict[col] = max(col_width_dict[col], (int)token.size());
            }
            col++;
            row_token.push_back(token);
        }
        col = 0;
        token_table.push_back(row_token);
    }
    for (vector<string> &row_token : token_table)
    {
        int k;
        for (k = 0; k < row_token.size() - 1; k++)
        {
            string token = row_token[k];
            cout << token;
            // at least one space
            for (int i = 0; i <= col_width_dict[k] - token.size(); i++)
            {
                cout << " ";
            }
        }
        cout << row_token[k] << endl;
    }

    return 0;
}