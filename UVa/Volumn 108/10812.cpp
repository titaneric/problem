#include <iostream>

using namespace std;

int main()
{
    int kase;
    cin >> kase;

    long long s, d;
    for (int i = 0; i < kase; i++)
    {
        cin >> s >> d;
        long long a = (s + d) / 2;
        long long b = s - a;
        if ((a >= 0 && b >= 0) && (a + b == s) && (a - b == d))
        {
            cout << a << " " << b << endl;
        }
        else
        {
            cout << "impossible\n";
        }
    }

    return 0;
}