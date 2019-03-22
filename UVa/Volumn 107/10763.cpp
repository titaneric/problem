#include <iostream>
#include <map>
#include <utility>

using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        map<pair<int, int>, int> exchange_dict;
        int a, b, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            pair<int, int> exchange_pair = (a > b) ? make_pair(b, a) : make_pair(a, b);
            auto iter = exchange_dict.find(exchange_pair);
            if (iter != exchange_dict.end() && !exchange_dict[exchange_pair])
            {

                exchange_dict[exchange_pair] = ++cnt;
                // cout << exchange_pair.first << ", " << exchange_pair.second << ":" << cnt << endl;
            }
            else
            {
                exchange_dict[exchange_pair] = 0;
            }
        }
        if (n % 2)
        {
            printf("NO\n");
        }
        else
        {
            if (cnt == (n / 2))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}