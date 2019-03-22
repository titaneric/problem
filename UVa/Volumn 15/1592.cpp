#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;
vector<string> splitString(string target)
{
    vector<string> result;
    stringstream ss(target);
    string buf;
    while (getline(ss, buf, ','))
    {
        result.push_back(buf);
    }
    return result;
}
int main()
{
    int colNum, rowNum;
    while (cin >> rowNum >> colNum)
    {

        vector<vector<string>> table;
        string target;
        table.resize(rowNum);
        getline(cin, target); // \n
        for (int i = 0; i < rowNum; i++)
        {
            getline(cin, target);
            // cout << target << endl;
            table[i] = splitString(target);
        }

        bool isPNF = true;
        for (int c1 = 0; c1 < colNum; c1++)
        {
            for (int c2 = c1 + 1; c2 < colNum; c2++)
            {
                map<pair<string, string>, int> cols_dict;
                for (int r = 0; r < rowNum; r++)
                {
                    pair<string, string> cols_key = make_pair(table[r][c1], table[r][c2]);
                    if (!cols_dict.count(cols_key))
                    {
                        cols_dict[cols_key] = r;
                    }
                    else
                    {
                        cout << "NO\n";
                        isPNF = false;
                        // row
                        printf("%d %d\n", cols_dict[cols_key] + 1, r + 1);
                        // col
                        printf("%d %d\n", c1 + 1, c2 + 1);
                        break;
                    }
                }
                if (!isPNF)
                    break;
            }
            if (!isPNF)
                break;
        }
        if (isPNF)
        {
            cout << "YES\n";
        }
    }
    return 0;
}
