#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{

    string num;
    string num_copy;

    while (cin >> num)
    {
        if (num == "0")
            break;

        num_copy = num;

        while (num.size() > 1)
        {
            int odd_sum = 0;
            for (int i = 0; i < num.size(); i += 2)
            {
                odd_sum += (num[i] - '0');
            }

            int even_sum = 0;
            for (int i = 1; i < num.size(); i += 2)
            {
                even_sum += (num[i] - '0');
            }

            stringstream ss;
            ss << abs(odd_sum - even_sum);
            num = ss.str();
        }
        if (num == "0")
        {
            cout << num_copy << " is a multiple of 11.\n";
        }
        else
        {
            cout << num_copy << " is not a multiple of 11.\n";
        }
    }
    return 0;
}