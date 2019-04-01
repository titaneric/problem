#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isDelimit(char c)
{
    return c == ' ' || !isalpha(c);
}
bool delimit(string str, int b, int e)
{
    if (b >= 1 && e <= str.size() - 2)
    {
        char pre = str[b - 1];
        char post = str[e];
        return isDelimit(pre) && isDelimit(post);
    }
    else if (b == 0)
    {
        return isDelimit(str[e]);
    }
    else if (e == str.size() - 1)
    {
        return isDelimit(str[b - 1]);
    }
}
int keyword_num(string str, string key)
{
    int n = 0;

    for (int i = 0; i < str.size() - key.size(); i++)
    {
        if (str.substr(i, key.size()) == key && delimit(str, i, i + key.size()))
        {
            n++;
        }
    }
    return n;
}
int main()
{
    int kase = 1;
    int key_num, excuse_num;
    while (cin >> key_num >> excuse_num)
    {

        vector<string> key(key_num);
        for (int i = 0; i < key_num; i++)
        {
            cin >> key[i];
        }
        vector<string> excuse(excuse_num);
        vector<int> key_cnt(excuse_num);

        string line;
        getline(cin, line);

        int max_num = 0;
        for (int i = 0; i < excuse_num; i++)
        {
            getline(cin, line);
            excuse[i] = line;
            string lower_excuse(line);
            transform(line.begin(), line.end(), lower_excuse.begin(), ::tolower);

            for (auto k : key)
            {
                key_cnt[i] += keyword_num(lower_excuse, k);
            }
            max_num = max(max_num, key_cnt[i]);
        }
        cout << "Excuse Set #" << kase++ << endl;
        for (int i = 0; i < excuse_num; i++)
        {
            if (key_cnt[i] == max_num)
            {
                cout << excuse[i] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}