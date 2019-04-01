#include <iostream>

using namespace std;
int main()
{

    int kase;
    cin >> kase;
    for (int k = 0; k < kase; k++)
    {
        int farmers;
        cin >> farmers;

        long long area, animals, deg;
        long long money = 0;
        for (int f = 0; f < farmers; f++)
        {
            cin >> area >> animals >> deg;
            if (animals != 0)
            {
                money += area * deg;
            }
        }
        cout << money << endl;
    }

    return 0;
}