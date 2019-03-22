#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAXB = 100001;

vector<int> sqr_accu;

void calc_sqr()
{
    int k = 0;
    for (int i = 0; i < ceil(sqrt(MAXB)); i++)
    {
        for (; k < (i + 1) * (i + 1); k++)
        {
            sqr_accu.push_back(i);
        }
    }
}
int main()
{
    calc_sqr();
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        cout << sqr_accu[b] - sqr_accu[a - 1] << endl;
    }

    return 0;
}