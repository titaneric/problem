#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {

        int day;
        cin >> day;

        int party_num;
        cin >> party_num;
        vector<int> party(party_num);
        for (int i = 0; i < party_num; i++)
        {
            cin >> party[i];
        }

        vector<bool> days(day + 1);
        for (auto p : party)
        {
            int d = p;
            while (d <= day)
            {
                days[d] = true;
                d += p;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= day; i++)
        {
            int w = i % 7;
            if (days[i] && (w != 0) && (w != 6))
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}