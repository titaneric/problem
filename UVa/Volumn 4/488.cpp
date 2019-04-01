#include <iostream>

using namespace std;
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int amp, freq;
        cin >> amp >> freq;

        for (int i = 0; i < freq; i++)
        {
            for (int j = 1; j <= amp; j++)
            {
                for (int m = 0; m < j; m++)
                {
                    cout << j;
                }
                cout << endl;
            }
            for (int j = (amp - 1); j >= 1; j--)
            {
                for (int m = 0; m < j; m++)
                {
                    cout << j;
                }
                cout << endl;
            }
            if (!(k == (kase - 1) && i == (freq - 1)))
                cout << endl;
        }
    }
    return 0;
}