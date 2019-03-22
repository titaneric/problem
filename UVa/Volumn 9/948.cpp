#include <iostream>
#include <vector>

using namespace std;
const int maxN = 100000000;

vector<int> fibo()
{
    vector<int> result = {1, 2};
    int pre2 = 1;
    int pre = 2;
    int cur = pre + pre2;
    while (cur < maxN)
    {
        cur = pre + pre2;
        result.push_back(cur);
        pre2 = pre;
        pre = cur;
    }
    return result;
}
int main()
{
    vector<int> result = fibo();

    int kase;
    cin >> kase;

    for (int i = 0; i < kase; i++)
    {

        int n;
        cin >> n;
        int cn = n;
        vector<char> fibo_n;
        bool first = false;
        for (auto it = result.rbegin(); it != result.rend(); it++)
        {
            if (*it <= n)
            {
                // cout << *it << endl;
                if (!first)
                {
                    first = true;
                }
                fibo_n.push_back('1');
                n -= *it;
            }
            else if (first)
            {
                fibo_n.push_back('0');
            }
        }
        cout << cn << " = ";
        for (auto c : fibo_n)
        {
            cout << c;
        }
        cout << " (fib)" << endl;
    }
    return 0;
}