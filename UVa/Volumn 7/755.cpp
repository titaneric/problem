#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
map<char, char> alpha_dict = {
    {'A', '2'},
    {'B', '2'},
    {'C', '2'},

    {'D', '3'},
    {'E', '3'},
    {'F', '3'},

    {'G', '4'},
    {'H', '4'},
    {'I', '4'},

    {'J', '5'},
    {'K', '5'},
    {'L', '5'},

    {'M', '6'},
    {'N', '6'},
    {'O', '6'},

    {'P', '7'},
    {'R', '7'},
    {'S', '7'},

    {'T', '8'},
    {'U', '8'},
    {'V', '8'},

    {'W', '9'},
    {'X', '9'},
    {'Y', '9'}

};
string standardize(string &phone_num)
{
    auto ed = remove(phone_num.begin(), phone_num.end(), '-');
    for (auto it = phone_num.begin(); it != ed; ++it)
    {
        if (isalpha(*it))
        {
            *it = alpha_dict[*it];
        }
    }
    return phone_num.substr(0, 3) + '-' + phone_num.substr(3, 4);
}
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int num;
        cin >> num;
        string phone;

        map<string, int> freq;
        for (int i = 0; i < num; i++)
        {
            cin >> phone;
            freq[standardize(phone)]++;
        }

        if (freq.size() == num)
        {
            cout << "No duplicates.\n";
        }
        else
        {
            for (auto f : freq)
            {
                if (f.second > 1)
                    cout << f.first << " " << f.second << endl;
            }
        }
        if (k != (kase - 1))
        {
            cout << endl;
        }
    }
    return 0;
}
