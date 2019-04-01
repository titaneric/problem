#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;
int main()
{

    int rnd;
    string target, guess;
    while (cin >> rnd && rnd != -1)
    {
        cout << "Round " << rnd << endl;

        cin >> target >> guess;
        map<char, int> status;

        set<char> target_set;
        set<char> guess_set;

        for (auto c : target)
        {
            target_set.insert(c);
            status[c] = 1;
        }

        bool winlose = false;
        int wrong = 0;
        for (auto g : guess)
        {
            auto it = status.find(g);
            if (it != status.end())
            {
                if (status[g] == 1)
                    guess_set.insert(g);
            }
            else
            {
                status[g] = 2;
                wrong++;
            }

            if (guess_set.size() == target_set.size())
            {
                winlose = true;
                cout << "You win.\n";
                break;
            }
            if (wrong == 7)
            {
                winlose = true;
                cout << "You lose.\n";
                break;
            }
        }
        if (!winlose)
        {
            cout << "You chickened out.\n";
        }
    }
    return 0;
}