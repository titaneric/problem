#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<char, int> f1, pair<char, int> f2)
{
    return (f1.second < f2.second) || ((f1.second == f2.second) && (f1.first > f2.first));
}
int main()
{
    int kase = 0;
    string line;
    while (getline(cin, line))
    {
        if (kase++) cout << endl;
        map<char, int> freq_dict;
        for (auto c : line)
        {
            if (32 <= int(c) && int(c) < 127)
            {
                auto it = freq_dict.find(c);
                if (it != freq_dict.end())
                {
                    it->second += 1;
                }
                else
                {
                    freq_dict[c] = 1;
                }
            }
        }

        vector<pair<char, int>> freq_vec;
        for (auto it : freq_dict)
        {
            freq_vec.push_back(make_pair(it.first, it.second));
        }

        sort(freq_vec.begin(), freq_vec.end(), comp);

        for (auto it : freq_vec)
        {
            cout << (int)it.first << " " << it.second << endl;
        }
    }
    return 0;
}