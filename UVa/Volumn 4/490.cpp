#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> articles;
    string line;
    int max_len = 0;
    while (getline(cin, line))
    {
        string tmp = line;//line.substr(0, line.size() - 1);
        articles.push_back(tmp);
        max_len = max(max_len, (int)tmp.size());
    }

    reverse(articles.begin(), articles.end());

    for (int k = 0; k < max_len; k++)
    {
        for (int i = 0; i < articles.size(); i++)
        {
            if (k < articles[i].size())
            {
                cout << articles[i][k];
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}