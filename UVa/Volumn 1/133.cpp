#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int findNext(vector<int> &queue, int pos, int direction)
{
    while (true)
    {
        pos = (pos + direction + queue.size()) % queue.size();
        if (queue[pos] != 0)
            break;
    }
    return pos;
}
int go(vector<int> &queue, int pos, int direction, int time)
{
    if (queue[pos] == 0)
        pos = findNext(queue, pos, direction);

    for (int i = 0; i < time - 1; i++)
    {
        pos = findNext(queue, pos, direction);
    }
    return pos;
}
int main()
{

    int n, k, m;
    while (cin >> n >> k >> m && n && k && m)
    {
        vector<int> queue(n);
        for (int i = 0; i < n; i++)
        {
            queue[i] = i + 1;
        }

        int left = n;

        int p1 = 0, p2 = n - 1;
        while (left)
        {
            p1 = go(queue, p1, 1, k);
            p2 = go(queue, p2, -1, m);

            cout << setw(3) << queue[p1];
            left--;

            if (p1 != p2)
            {
                cout << setw(3) << queue[p2];
                left--;
            }
            queue[p1] = 0;
            queue[p2] = 0;
            if (left)
                cout << ",";
        }
        cout << endl;
    }
    return 0;
}
