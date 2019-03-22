#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;
int main()
{
    int total;
    scanf("%d", &total);

    while (total--)
    {

        int pointNum;
        scanf("%d", &pointNum);

        vector<int> x_axis(pointNum);
        vector<int> y_axis(pointNum);

        for (int i = 0; i < pointNum; i++)
        {
            scanf("%d%d", &x_axis[i], &y_axis[i]);
        }

        auto iter = minmax_element(x_axis.begin(), x_axis.end());
        int lMax = *iter.first;
        int rMax = *iter.second;
        double mid = (lMax + rMax) / 2.0;
        int non_mid_points_num = count_if(x_axis.begin(), x_axis.end(), [mid](int x) { return x != mid; });

        set<pair<int, int>> diff_dict;
        int cnt = 0;

        for (int i = 0; i < pointNum; i++)
        {
            if (x_axis[i] == mid)
                continue;
            int x_diff = abs(int((x_axis[i] - mid) * 2));
            pair<int, int> point_pair = make_pair(x_diff, y_axis[i]);
            auto iter = diff_dict.find(point_pair);
            if (iter == diff_dict.end())
                diff_dict.insert(point_pair);
            else
                cnt++;
        }
        if ((2 * cnt) == non_mid_points_num)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}