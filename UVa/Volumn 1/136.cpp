#include <queue>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const vector<int> factors = {2, 3, 5};
int main()
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    set<long long> exist_set;

    pq.push(1);
    exist_set.insert(1);

    for (int i = 1;; i++)
    {
        long long cur_num = pq.top();
        pq.pop();
        if (i == 1500)
        {
            cout << "The 1500'th ugly number is " << cur_num << ".\n";
            break;
        }
        for (const long long &factor : factors)
        {
            long long candidate = cur_num * factor;
            if (exist_set.find(candidate) == exist_set.end())
            {
                pq.push(candidate);
                exist_set.insert(candidate);
            }
        }
    }

    return 0;
}
