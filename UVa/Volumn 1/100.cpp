#include <iostream>
#include <algorithm>
using namespace std;

int conjecture(unsigned long long k)
{
    int cycle = 0;
    while (k != 1)
    {
        if (k % 2)
        {
            k = 3 * k + 1;
        }
        else
        {
            k /= 2;
        }
        cycle++;
    }
    cycle++;
    return cycle;
}
int main()
{
    int i, j;
    bool s = false;
    while (cin >> i >> j)
    {
        if (i > j)
        {
            swap(i, j);
            s = true;
        }
        int max_cycle = conjecture(i);

        for (int k = i + 1; k <= j; k++)
        {
            max_cycle = max(max_cycle, conjecture(k));
        }

        if (s)
            cout << j << " " << i << " " << max_cycle << endl;
        else
            cout << i << " " << j << " " << max_cycle << endl;
        
        s = false;
    }
    return 0;
}