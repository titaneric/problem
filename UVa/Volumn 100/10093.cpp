#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    string num;

    while (getline(cin, num))
    {
        int sum = 0;
        int max_digit = 1;
        for (auto c : num)
        {
            int digit = 0;
            if (isdigit(c))
            {
                digit = (c - '0');
            }
            else if (isupper(c))
            {
                digit = (10 + c - 'A');
            }
            else if (islower(c))
            {
                digit = (10 + 26 + c - 'a');
            }
            max_digit = max(max_digit, digit);
            sum += digit;
        }
        // cout << sum << "," << max_digit << endl;

        int i = max_digit;
        for (; i < 62; i++)
        {
            if (sum % i == 0)
            {
                cout << i + 1 << endl;
                break;
            }
        }
        if (i == 62)
        {
            cout << "such number is impossible!\n";
        }
    }
    return 0;
}