#include <iostream>
#include <string>
#include <set>

using namespace std;
int main()
{
    string word;
    set<string> dict;
    while (cin >> word)
    {
        dict.insert(word);
    }

    for (const string &word : dict)
    {
        for (int i = 1; i < word.size(); i++)
        {
            string front = word.substr(0, i);
            string last = word.substr(i);
            // cout << front << "|" << last << endl;
            if (dict.find(front) != dict.end() && dict.find(last) != dict.end())
            {
                cout << word << endl;
                break;
            }
        }
    }

    return 0;
}