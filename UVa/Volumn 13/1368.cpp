#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int m, n;
        cin >> m >> n;

        vector<string> seqs(m);

        for (int i = 0; i < m; i++)
        {
            cin >> seqs[i];
        }
        string DNA(n, '.');
        char candidate;
        for (int i = 0; i < n; i++)
        {
            map<char, int> bucket;
            vector<int> freq;
            for (int j = 0; j < m; j++)
            {
                bucket[seqs[j][i]]++;
            }

            for (auto b : bucket)
            {
                freq.push_back(b.second);
            }

            int max_freq = *max_element(freq.begin(), freq.end());

            for (auto b : bucket)
            {
                if (b.second == max_freq)
                {
                    candidate = b.first;
                    break;
                }
            }
            DNA[i] = candidate;
        }

        int dis = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (seqs[i][j] != DNA[j])
                    dis++;
            }
        }

        cout << DNA << endl;
        cout << dis << endl;
    }
    return 0;
}
