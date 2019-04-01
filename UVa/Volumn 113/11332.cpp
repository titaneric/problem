#include <iostream>

using namespace std;
int main()
{

    long long num;
    while (cin >> num && num)
    {

        while (num >= 10)
        {
            long long tmp = num;
            long long sum = 0;
            while (tmp)
            {
                sum += tmp % 10;
                tmp /= 10;
            }
            num = sum;
        }
        cout << num << endl;
    }

    return 0;
}