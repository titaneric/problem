#include <iostream>

using namespace std;

int main()
{

    long long num1;
    long long num2;

    while (cin >> num1 >> num2)
    {
        if (num1 == 0 && num2 == 0)
            break;
        int result = 0;
        int carry = 0;

        while (num1 && num2)
        {
            int digit1 = num1 % 10;
            int digit2 = num2 % 10;

            int add = digit1 + digit2 + carry;
            if (add >= 10)
            {
                result += 1;
            }

            carry = (add / 10);
            num1 /= 10;
            num2 /= 10;
        }

        while (num1)
        {
            int digit1 = num1 % 10;
            int add = digit1 + carry;
            if (add >= 10)
            {
                result += 1;
            }

            carry = (add / 10);
            num1 /= 10;
        }

        while (num2)
        {
            int digit2 = num2 % 10;
            int add = digit2 + carry;
            if (add >= 10)
            {
                result += 1;
            }

            carry = (add / 10);
            num2 /= 10;
        }

        if (result == 0)
            cout << "No carry operation.\n";
        else if (result == 1)
            cout << result << " carry operation.\n";
        else
            cout << result << " carry operations.\n";
    }
    return 0;
}