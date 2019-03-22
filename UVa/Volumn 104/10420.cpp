#include <iostream>
#include <map>
#include <string>

using namespace std;

string getCountry(string line)
{
    string country = "";
    int i = 0;
    while (i < line.size())
    {
        if (line[i] != ' ')
        {
            country += line[i];
        }
        else
            break;
        i++;
    }
    return country;
}
int main()
{

    int kase;
    cin >> kase;

    map<string, int> country_dict;

    string line;
    getline(cin, line);

    for (int i = 0; i < kase; i++)
    {
        getline(cin, line);
        string country = getCountry(line);
        // cout << country << endl;

        auto it = country_dict.find(country);

        if (it != country_dict.end())
        {
            it->second = it->second + 1;
        }
        else
        {
            country_dict[country] = 1;
        }
    }

    for (auto it : country_dict)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}