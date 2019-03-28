#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cost(36);
vector<int> convertBase(long long num, int base)
{
    vector<int> based_num;
    while (num)
    {
        based_num.push_back(num % base);
        num /= base;
    }
    return based_num;
}
int sumOfCost(vector<int> based_num)
{
    int sum = 0;
    for (auto c : based_num)
    {
        sum += cost[c];
    }
    return sum;
}

int main()
{
    int kase;
    cin >> kase;
    for (int k = 0; k < kase; k++)
    {
        cout << "Case " << k + 1 << ":\n";
        for (int i = 0; i < 36; i++)
        {
            cin >> cost[i];
        }

        int query_num;
        cin >> query_num;

        long long query;
        for (int i = 0; i < query_num; i++)
        {
            cin >> query;
            vector<int> sum_vec(37);
            for (int base = 2; base <= 36; base++)
            {
                vector<int> based_num = convertBase(query, base);
                int cost_sum = sumOfCost(based_num);
                sum_vec[base] = cost_sum;
            }
            cout << "Cheapest base(s) for number " << query;
            cout << ": ";
            auto min_ele = min_element(sum_vec.begin() + 2, sum_vec.end());
            vector<int> min_elems;
            for (int base = 2; base <= 36; base++)
            {
                if (sum_vec[base] == *min_ele)
                {
                    min_elems.push_back(base);
                }
            }
            int m = 0;
            for (; m < min_elems.size() - 1; m++)
            {
                cout << min_elems[m] << " ";
            }
            cout << min_elems[m] << endl;
        }
        if (k != (kase - 1))
            cout << endl;
    }
    return 0;
}