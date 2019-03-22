#include <iostream>

using namespace std;

int main()
{

    int kase;
    cin >> kase;

    for (int i = 0; i < kase; i++)
    {

        int a, b;
        cin >> a >> b;

        if (a % 2 == 0)
        {
            a += 1;
        }

        if (b % 2 == 0)
        {
            b -= 1;
        }

        int n = (b - a) / 2 + 1;

        cout << "Case " << i + 1 << ": " << (a + b) * n / 2 << endl;
    }

    return 0;
}