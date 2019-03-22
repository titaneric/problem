#include <iostream>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;
int main()
{
    int total;
    scanf("%d", &total);

    while (total--)
    {

        int n, m;
        scanf("%d%d", &n, &m);

        queue<int> task_queue;
        queue<int> pos_queue;
        array<int, 10> priority_cnt = {};

        int x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            task_queue.push(x);
            pos_queue.push(i);
            priority_cnt[x]++;
        }

        int delta = 0;
        int task, pos;
        while (true)
        {
            task = task_queue.front();
            task_queue.pop();

            pos = pos_queue.front();
            pos_queue.pop();

            bool can_pop = all_of(priority_cnt.begin() + task + 1, priority_cnt.end(), [](int t) { return t == 0; });
            if (can_pop)
            {
                delta++;
                if (pos == m)
                {
                    printf("%d\n", delta);
                    break;
                }
                priority_cnt[task]--;
            }
            else
            {
                task_queue.push(task);
                pos_queue.push(pos);
            }
        }
    }
    return 0;
}