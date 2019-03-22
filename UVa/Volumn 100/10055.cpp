#include <iostream>

using namespace std;
int main()
{
    long long out, opponent;

    while (cin >> out >> opponent)
    {
        long long result = out - opponent;
        if (result > 0)
            cout << result << endl;
        else
            cout << -result << endl;
    }

    return 0;
}