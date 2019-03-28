#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

bool comp(int a, int b, int m)
{
    int moda = a % m;
    int modb = b % m;

    bool odd_a = abs(a % 2) == 1;
    bool odd_b = abs(b % 2) == 1;

    if (moda == modb)
    {
        // two odd number
        if (odd_a && odd_b)
        {
            return a > b;
        }
        // two even number
        else if (!odd_a && !odd_b)
        {
            return a < b;
        }
        // a is odd
        else if (odd_a && !odd_b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return moda < modb;
    }
}
int main()
{

    int N, M;
    while (cin >> N >> M && N && M)
    {
        vector<int> vec(N);
        for (int i = 0; i < N; i++)
        {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end(), bind(comp, _1, _2, M));
        cout << N << " " << M << endl;
        for (auto n : vec)
        {
            cout << n << endl;
        }
    }
    cout << "0 0\n";
    return 0;
}
