#include <iostream>
#include <vector>
#include <string>

using namespace std;

int toInteger(char chr)
{
    return chr - '0';
}
int main()
{
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        vector<int> product(num1.size() + num2.size());
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                int product_idx = (num1.size() - 1 - i) + (num2.size() - 1 - j) + 1;
                int p = toInteger(num1[num1.size() - 1 - i]) * toInteger(num2[num2.size() - 1 - j]);
                auto result = div(p + product[product_idx], 10);
                product[product_idx] = result.rem;
                product[product_idx - 1] += result.quot;
            }
        }
        int i = 0;
        while (i < product.size() - 1 && product[i] == 0)
        {
            i++;
        }
        for (; i < product.size(); i++)
        {
            cout << product[i];
        }
        cout << endl;
    }
    return 0;
}
