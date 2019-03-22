#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int init;
    long long day;

    while (cin >> init >> day)
    {
        long long b = (2 * init - 1);
        long long c = -2 * day;

        int k = ceil((-b + sqrt(b * b - 4 * c)) / 2);

        cout << init + (k - 1) << endl;
    }
    return 0;
}