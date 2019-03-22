#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int n, q;
    int kase = 0;
    vector<int> marble;
    while (scanf("%d%d", &n, &q) == 2 && n)
    {
        printf("CASE# %d:\n", ++kase);
        marble.resize(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &marble[i]);
        }
        sort(marble.begin(), marble.end());
        // printf("%d\n", marble.size());
        for (int i = 0; i < q; i++)
        {
            int target;
            scanf("%d", &target);
            int index = lower_bound(marble.begin(), marble.end(), target) - marble.begin();
            if (marble[index] == target)
                printf("%d found at %d\n", target, index + 1);
            else
                printf("%d not found\n", target);
        }
    }
}