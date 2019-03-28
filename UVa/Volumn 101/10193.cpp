#include <iostream>
#include <string>

using namespace std;

long long bin2int(string bin)
{
    long long n = 0;
    long long base = 1;
    for (int i = 0; i < bin.size(); i++, base *= 2)
    {
        n += (bin[bin.size() - 1 - i] - '0') * base;
    }
    return n;
}

long long gcd(long long num1, long long num2)
{
    if (num2 > num1)
    {
        swap(num1, num2);
    }
    if (num2 == 0)
    {
        return num1;
    }
    while (num2 != 0)
    {
        long long tmp = num2;
        num2 = num1 % num2;
        num1 = tmp;
    }
    return num1;
}
int main()
{
    int kase;
    cin >> kase;
    for (int k = 0; k < kase; k++)
    {
        string pair1, pair2;
        cin >> pair1 >> pair2;

        long long num1 = bin2int(pair1);
        long long num2 = bin2int(pair2);

        cout << "Pair #" << k + 1 << ": ";
        if (gcd(num1, num2) != 1)
        {
            cout << "All you need is love!\n";
        }
        else
        {
            cout << "Love is not all you need!\n";
        }
    }
    return 0;
}
