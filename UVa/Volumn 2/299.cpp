#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int n;
        cin >> n;

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    swap(vec[j], vec[j + 1]);
                    cnt += 1;
                }
            }
        }

        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }
    return 0;
}