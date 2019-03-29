#include <iostream>
#include <map>
#include <string>

using namespace std;
int main()
{
    int kase;
    cin >> kase;

    string tree;
    getline(cin, tree); // \n of kase
    getline(cin, tree); // empty line

    for (int k = 0; k < kase; k++)
    {
        map<string, int> obs;
        int cnt = 0;
        while (getline(cin, tree))
        {
            tree.erase(tree.find_last_not_of("\r\n") + 1);
            tree.erase(tree.find_last_not_of("\n") + 1);
            if (tree.size() == 0)
                break;
            auto it = obs.find(tree);
            if (it != obs.end())
            {
                it->second += 1;
            }
            else
            {
                obs[tree] = 1;
            }
            cnt++;
        }
        for (auto it : obs)
        {
            printf("%s %.4f\n", it.first.c_str(), it.second * 100.0 / cnt);
        }
        if (k != (kase - 1))
        {
            cout << endl;
        }
    }
    return 0;
}