#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int G = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                G += gcd(j, i);
            }
        }
        cout << G << endl;
    }

    return 0;
}