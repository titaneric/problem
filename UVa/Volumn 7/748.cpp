#include <iostream>
#include <vector>
#include <string>

using namespace std;

int toInteger(char chr)
{
    return chr - '0';
}
string getProduct(string num1, string num2)
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
    string product_str(product.size(), '0');
    for (int i = 0; i < product.size(); i++)
    {
        product_str[i] = '0' + product[i];
    }
    return product_str;
}
vector<int> getPower(string base, int power)
{
    string result = "1";
    for (int i = 0; i < power; i++)
    {
        result = getProduct(base, result);
    }
    vector<int> result_vec(result.size());
    for (int i = 0; i < result.size(); i++)
    {
        result_vec[i] = toInteger(result[i]);
    }
    return result_vec;
}
int main()
{
    string base;
    int power;
    while (cin >> base >> power)
    {
        size_t dot_pos = base.find('.');
        if (dot_pos != string::npos)
            base.erase(dot_pos, 1);
        int decimal_len = int(6 - 1 - dot_pos) * power;
        vector<int> product = getPower(base, power);
        int i = 0;
        while (i < product.size() - decimal_len && product[i] == 0)
        {
            i++;
        }
        int begin = i;

        i = product.size() - 1;
        while (i > -1 && product[i] == 0)
        {
            i--;
        }

        int end = i;
        for (int k = begin; k <= end; k++)
        {
            if (k == product.size() - decimal_len)
                cout << ".";

            cout << product[k];
        }
        cout << endl;
    }
    return 0;
}
