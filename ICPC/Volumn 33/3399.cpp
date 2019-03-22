#include <iostream>

using namespace std;

const int maxn = 2000, n = 10000;
int prime[maxn] = {n + 1};
int total = 0;

bool isPrime(int num)
{
    for (int i = 0; i < total; i++)
    {
        if (num % prime[i] == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            prime[total++] = i;
        }
    }

    int m;
    while (cin >> m && m != 0)
    {
        int ans = 0;
        for (int i = 0; prime[i] <= m; i++)
        {
            // cout << prime[i] << endl;
            int cnt = 0;
            for (int j = i; j < total && cnt < m; j++)
            {
                cnt += prime[j];
            }
            if (cnt == m)
            {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}