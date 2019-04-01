#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int, char> density_map = {
    {0, ' '}, {1, '.'}, {2, 'x'}, {3, 'W'}};
void printVec(vector<int> &vec)
{
    int i = 1;
    for (; i < vec.size() - 2; i++)
    {
        cout << density_map[vec[i]];
    }
    cout << density_map[vec[i]] << endl;
}
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int DNA[10];
        for (int i = 0; i < 10; i++)
        {
            cin >> DNA[i];
        }

        vector<int> dishes(42);
        vector<int> previous(42);

        dishes[20] = 1;

        for (int d = 0; d < 50; d++)
        {
            printVec(dishes);
            previous = dishes;
            for (int i = 1; i <= 40; i++)
            {
                int K = previous[i] + previous[i - 1] + previous[i + 1];
                dishes[i] = DNA[K];
            }
        }

        if (k != (kase - 1))
        {
            cout << endl;
        }
    }
    return 0;
}