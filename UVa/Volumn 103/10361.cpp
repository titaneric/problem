#include <iostream>
#include <vector>
#include <string>

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
    int kase;
    string line1;
    string line2;

    cin >> kase;
    getline(cin, line1);
    for (int k = 0; k < kase; k++)
    {

        getline(cin, line1);
        getline(cin, line2);

        trim(line1);
        trim(line2);

        vector<string> token;

        string buffer = "";
        bool split = false;
        for (auto c : line1)
        {
            if (c == '<')
            {
                token.push_back(buffer);
                buffer = "";
            }
            else if (c == '>')
            {
                token.push_back(buffer);
                buffer = "";
            }
            else
            {
                buffer += c;
            }
        }
        token.push_back(buffer);

        for (auto s : token)
        {
            cout << s;
        }
        cout << endl;

        auto dot_pos = line2.find_last_not_of("...");
        line2 = line2.substr(0, dot_pos + 1) + token[3] + token[2] + token[1] + token[4];

        cout << line2 << endl;
    }
    return 0;
}