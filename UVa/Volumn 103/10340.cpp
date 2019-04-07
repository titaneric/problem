#include <iostream>
#include <string>

using namespace std;
int main()
{

    string target, ref;
    while (cin >> target >> ref)
    {

        string r = ref;
        bool is_subsequence = true;
        for (auto c : target)
        {
            size_t pos = r.find_first_of(c);
            if (pos != string::npos)
            {
                r = r.substr(pos + 1);
            }
            else
            {
                is_subsequence = false;
                break;
            }
        }
        if (is_subsequence)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
