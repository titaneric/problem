#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{

    int n;
    string row;
    while (cin >> n && n)
    {
        getline(cin, row);
        int max_cnt = 0;
        vector<int> image(n);
        for (int i = 0; i < n; i++)
        {
            getline(cin, row);
            int cnt = count(row.begin(), row.end(), 'X');
            max_cnt = max(max_cnt, cnt);
            image[i] = cnt;
        }

        int total_space = 0;
        for (auto c : image)
        {
            total_space += (max_cnt - c);
        }
        cout << total_space << endl;
    }

    return 0;
}