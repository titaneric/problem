#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

bool comp(pair<char, int>p1, pair<char, int>p2)
{
    return (p1.second > p2.second) || ((p1.second == p2.second) && (p1.first < p2.first));
}
int main()
{
    int total;

    cin >> total;

    string line;
    getline(cin, line);

    map<char, int> alpha_dict;
    for (int i = 0; i < total; i++)
    {
        getline(cin, line);
        for (int k = 0; k < line.size(); k++)
        {
            if (isalpha(line[k]))
            {
                char upper = toupper(line[k]);
                auto it = alpha_dict.find(upper);
                if (it != alpha_dict.end())
                {
                    it->second = it->second + 1;
                }
                else
                {
                    alpha_dict[upper] = 1;
                }
            }
        }
    }

    vector<pair<char, int>> alpha_list;
    for(auto it: alpha_dict)
    {
        alpha_list.push_back(make_pair(it.first, it.second));
    }

    sort(alpha_list.begin(), alpha_list.end(), comp);

    for(auto e: alpha_list)
    {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}