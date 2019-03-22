#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int main()
{
    string word;
    map<string, int> freq_dict;
    vector<string> words;
    vector<string> ans;
    while (cin >> word)
    {
        if (word[0] == '#') break;
        words.push_back(word);

        string normal_word;
        normal_word.resize(word.length());
        transform(word.begin(), word.end(), normal_word.begin(), ::tolower);
        sort(normal_word.begin(), normal_word.end());

        if (freq_dict.find(normal_word) == freq_dict.end())
        {
            freq_dict[normal_word] = 0;
        }
        freq_dict[normal_word]++;
    }
    for(auto word: words)
    {
        string normal_word;
        normal_word.resize(word.length());
        transform(word.begin(), word.end(), normal_word.begin(), ::tolower);
        sort(normal_word.begin(), normal_word.end());

        if (freq_dict[normal_word] == 1)
        {
            ans.push_back(word);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto a: ans)
    {
        cout << a << endl;
    }

    return 0;
}