#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
}
bool isBox(vector<pair<int, int>> &box)
{
    for (int i = 0; i <= 2; i++)
    {
        if (box[2 * i] != box[2 * i + 1])
        {
            return false;
        }
    }

    if (box[0].first != box[2].first || box[0].second != box[4].first || box[2].second != box[4].second)
    {
        return false;
    }
    return true;
}
int main()
{

    int first, second;
    while (cin >> first >> second)
    {
        vector<pair<int, int>> box(6);
        if (first > second)
        {
            swap(first, second);
        }
        auto p = make_pair(first, second);
        box[0] = p;

        for (int i = 1; i < 6; i++)
        {
            cin >> first >> second;
            if (first > second)
            {
                swap(first, second);
            }
            auto p = make_pair(first, second);
            box[i] = p;
        }

        sort(box.begin(), box.end(), comp);

        if (isBox(box))
        {
            cout << "POSSIBLE\n";
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
