#include <iostream>
#include <string>
#include <vector>

#define maxLen 105
using namespace std;

vector<int> sum(maxLen);
int main()
{

    string line;
    while (cin >> line)
    {
        if (line == "0")
        {
            break;
        }
        for (int i = 0; i < line.size(); i++)
        {
            int sum_idx = maxLen - 1 - i;
            int s = sum[sum_idx] + (line[line.size() - 1 - i] - '0');
            auto div_result = div(s, 10);
            sum[sum_idx] = div_result.rem;
            sum[sum_idx - 1] += div_result.quot;
        }
    }
    int i = 0;
    while (i < maxLen && sum[i] == 0)
    {
        i++;
    }
    for (; i < maxLen; i++)
    {
        cout << sum[i];
    }
    cout << endl;

    return 0;
}