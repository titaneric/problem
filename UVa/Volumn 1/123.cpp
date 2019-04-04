#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

class KWIC
{
  public:
    string line;
    string keyword;
    int index;
    int input_seq;

  public:
    KWIC(string line, string keyword, int index, int input_seq) : line(line), keyword(keyword), index(index), input_seq(input_seq) {}
};
bool comp(KWIC k1, KWIC k2)
{
    if (k1.keyword != k2.keyword)
    {
        return (k1.keyword < k2.keyword);
    }
    else
    {
        if (k1.input_seq != k2.input_seq)
        {
            return (k1.input_seq < k2.input_seq);
        }
        else
        {
            return (k1.index < k2.index);
        }
        
    }   
}
vector<string> split(string &line)
{
    vector<string> result;
    istringstream ss(line);
    string token;
    while (getline(ss, token, ' '))
    {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        result.push_back(token);
    }
    return result;
}
string join(vector<string> list)
{
    string result = "";
    int i = 0;
    for (; i < list.size() - 1; i++)
    {
        result += list[i] + " ";
    }
    result += list[i] + "\n";
    return result;
}
int main()
{
    vector<string> keywords;
    vector<vector<string>> titles;

    string line;
    while (cin >> line)
    {
        if (line == "::")
            break;
        keywords.push_back(line);
    }
    while (getline(cin, line))
    {
        if (line.size() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1);
        }
        titles.push_back(split(line));
    }

    set<KWIC, decltype(&comp)> kwic(&comp);
    for (int i = 0; i < titles.size(); i++)
    {
        vector<string> title = titles[i];
        for (int t = 0; t < title.size(); t++)
        {
            string token = title[t];
            vector<string> new_title = title;
            auto it = find(keywords.begin(), keywords.end(), token);

            if (it == keywords.end())
            {
                transform(token.begin(), token.end(), token.begin(), ::toupper);
                new_title[t] = token;
                KWIC k(join(new_title), token, t, i);
                kwic.insert(k);
            }
        }
    }
    for (auto k : kwic)
    {
        cout << k.line;
    }
    return 0;
}
