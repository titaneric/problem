#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    int kase = 1;
    string line;
    vector<string> decode;
    while (getline(cin, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1);
        }
        if (line != "9")
        {
            decode.push_back(line);
        }
        else
        {
            bool imme_decode = true;
            for (int i = 0; i < decode.size(); i++)
            {
                for (int j = 0; j < decode.size(); j++)
                {
                    if (i != j && decode[i].find(decode[j]) == 0)
                    {
                        imme_decode = false;
                        break;
                    }
                }
            }
            cout << "Set " << kase++ << " is ";
            if (!imme_decode)
            {
                cout << "not ";
            }
            cout << "immediately decodable\n";
            decode.clear();
        }
    }

    return 0;
}