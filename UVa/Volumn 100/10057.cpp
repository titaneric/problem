#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{

    int n;
    while (cin >> n)
    {
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());
        int mid, cnt, diff;
        if (n % 2)
        {
            mid = vec[n / 2];
            cnt = count(vec.begin(), vec.end(), mid);
            diff = 1;
        }
        else
        {
            int left_mid = vec[n / 2 - 1];
            int right_mid = vec[n / 2];
            mid = left_mid;
            cnt = count(vec.begin(), vec.end(), left_mid);
            if (left_mid != right_mid)
                cnt += count(vec.begin(), vec.end(), right_mid);
            diff = right_mid - left_mid + 1;
        }
        cout << mid << " " << cnt << " " << diff << endl;
    }
    return 0;
}