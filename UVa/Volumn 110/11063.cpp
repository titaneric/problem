#include <iostream>
#include <vector>
#include <set>

using namespace std;
int main()
{
    int kase = 1;

    int num;
    while (cin >> num)
    {

        vector<int> vec(num);
        for (int i = 0; i < num; i++)
        {
            cin >> vec[i];
        }

        bool negative = false;
        int ascending = true;

        int pre = vec[0];
        set<int> add_history;
        for (int i = 0; i < num; i++)
        {
            int cur = vec[i];

            if (i != 0 && pre >= cur)
            {
                ascending = false;
                break;
            }
            if (cur <= 0)
            {
                negative = true;
                break;
            }
            for (int j = i; j < num; j++)
            {
                int sum = cur + vec[j];
                // cout << sum << " ";
                add_history.insert(sum);
            }
            pre = cur;
        }
        // cout << endl;
        int size = (1 + num) * num / 2;
        cout << "Case #" << kase << ": ";
        if (ascending && !negative && size == add_history.size())
        {
            cout << "It is a B2-Sequence.\n\n";
        }
        else
        {
            cout << "It is not a B2-Sequence.\n\n";
        }
        kase++;
    }
    return 0;
}