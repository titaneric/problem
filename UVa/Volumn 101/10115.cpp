#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

void trim(string &line)
{
    if (!line.empty() && line[line.size() - 1] == '\r')
    {
        line.erase(line.size() - 1);
    }
}
int main()
{
    string target_str, replace_str;
    int rule_num;
    while (cin >> rule_num && rule_num)
    {
        getline(cin, target_str);

        vector<pair<string, string>> rule(rule_num);

        for (int i = 0; i < rule_num; i++)
        {
            getline(cin, target_str);
            getline(cin, replace_str);
            trim(target_str);
            trim(replace_str);
            rule[i] = {target_str, replace_str};
        }

        getline(cin, target_str);
        trim(target_str);

        for (auto r : rule)
        {
            auto it = target_str.find(r.first);
            while (it != string::npos)
            {
                target_str.replace(it, r.first.size(), r.second);
                it = target_str.find(r.first);
            }
        }

        cout << target_str << endl;
    }
    return 0;
}