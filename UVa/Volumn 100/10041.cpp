#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int size;
        cin >> size;
        vector<int> relatives(size);

        int distance = 0;

        for (int i = 0; i < size; i++)
        {
            cin >> relatives[i];
        }

        int min_distance = 500 * 30000;
        int min_ele = *min_element(relatives.begin(), relatives.end());
        int max_ele = *max_element(relatives.begin(), relatives.end());

        for (int street = min_ele; street <= max_ele; street++)
        {
            int dis = 0;
            for (int i = 0; i < size; i++)
            {
                dis += abs(relatives[i] - street);
            }
            min_distance = min(min_distance, dis);
        }

        cout << min_distance << endl;
    }

    return 0;
}