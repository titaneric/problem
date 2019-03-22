#include <iostream>
#include <string>

using namespace std;
int main()
{
    string num;

    while (cin >> num)
    {
        if (num == "0")
        {
            break;
        }
        int sum = 0;
        for (auto c : num)
        {
            sum += (c - '0');
        }
        // cout << sum << endl;
        int deg = 1;
        while (sum >= 10)
        {
            int tmp = sum;
            int new_sum = 0;
            while (tmp)
            {
                new_sum += (tmp % 10);
                tmp /= 10;
            }
            sum = new_sum;
            deg += 1;
            // cout << sum << endl;
        }

        // cout << sum << endl;
        if (sum == 9)
        {
            cout << num << " is a multiple of 9 and has 9-degree " << deg << ".\n";
        }
        else
        {
            cout << num << " is not a multiple of 9.\n";
        }
    }
    return 0;
}