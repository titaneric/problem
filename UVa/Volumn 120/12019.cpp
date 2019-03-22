#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int main()
{
    int month, date;
    int total;
    cin >> total;

    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    vector<pair<int, int>> ref = {{1, 10}, {2, 21}, {4, 4}, {6, 6}, {8, 8}, {10, 10}, {12, 12}};
    for (int t = 0; t < total; t++)
    {
        cin >> month >> date;

        // Mon
        int day = 0;

        int k = 0;
        for (int i = 0; i < 7; i++)
        {
            if ((ref[i].first <= month) || (ref[i].first == month) && (ref[i].second <= date))
            {
                k = i;
            }
            else
            {
                break;
            }
        }

        // Jan
        if (month == ref[k].first && date < ref[k].second)
        {
            int day_diff = (ref[k].second - date) % 7;

            cout << days[(28 + day - day_diff) % 7] << endl;
        }
        else
        {
            // cout << ref[k].first << "/" << ref[k].second << endl;
            int day_diff = 0;
            if (ref[k].first != month)
            {
                day_diff += months[ref[k].first - 1] - ref[k].second;
                for (int i = ref[k].first; i < month - 1; i++)
                {
                    day_diff += months[i];
                }
                day_diff += date;
            }
            else
            {
                day_diff += (date - ref[k].second);
            }
            cout << days[(day + day_diff) % 7] << endl;
        }
    }

    return 0;
}