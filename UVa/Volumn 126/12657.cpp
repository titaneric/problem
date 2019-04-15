#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int prev;
    int next;

public:
    ListNode() : prev(0), next(0) {}
};
vector<ListNode> initList(int box_num)
{
    vector<ListNode> box(box_num + 1);
    for (int i = 1; i <= box_num; i++)
    {
        box[i].prev = i - 1;
        box[i].next = (i + 1) % (box_num + 1);
    }
    // head
    box[0].prev = box_num, box[0].next = 1;
    return box;
}
void link(vector<ListNode> &box, int left, int right)
{
    box[left].next = right;
    box[right].prev = left;
}
void swapNode(vector<ListNode> &box, int left, int right)
{
    int left_prev = box[left].prev, left_next = box[left].next;
    int right_prev = box[right].prev, right_next = box[right].next;

    // Link left_prev and right
    link(box, left_prev, right);
    // Link right_next and left
    link(box, left, right_next);

    if (left_next == right)
    {
        // Link left and right
        link(box, right, left);
    }
    else
    {
        // Link right and left_next
        link(box, right, left_next);
        // Link left and right_prev
        link(box, right_prev, left);
    }
}
void insertNode(vector<ListNode> &box, int target, int dest, bool put_right)
{
    int dest_prev = box[dest].prev, dest_next = box[dest].next;
    int target_prev = box[target].prev, target_next = box[target].next;

    // unlink target
    link(box, target_prev, target_next);

    if (put_right)
    {
        // link dest and target
        link(box, dest, target);
        // link dest_next and target
        link(box, target, dest_next);
    }
    else
    {
        // link dest and target
        link(box, target, dest);
        // link dest_next and target
        link(box, dest_prev, target);
    }
}
int main()
{
    int kase = 1;

    int box_num, query_num;
    while (cin >> box_num >> query_num)
    {

        vector<ListNode> box = initList(box_num);

        bool reverse = false;
        int op;
        int X, Y;
        for (int i = 0; i < query_num; i++)
        {
            cin >> op;
            if (op == 4)
            {
                reverse = !reverse;
                continue;
            }
            cin >> X >> Y;
            if (op == 3 && box[Y].next == X)
                swap(X, Y);

            if (op != 3 && reverse)
                op = 3 - op;

            if (op == 3)
            {
                swapNode(box, X, Y);
            }
            else if (op == 1 && box[Y].prev != X)
            {
                insertNode(box, X, Y, false);
            }
            else if (op == 2 && box[Y].next != X)
            {
                insertNode(box, X, Y, true);
            }
        }

        // find head
        int pos = 0;
        long long sum = 0;
        for (int i = 1; i <= box_num; i++)
        {
            pos = box[pos].next;
            if (i % 2)
                sum += pos;
        }

        long long total_sum = (long long)box_num * (box_num + 1) / 2;
        if (reverse && box_num % 2 == 0)
        {
            sum = total_sum - sum;
        }

        cout << "Case " << kase++ << ": " << sum << endl;
    }
    return 0;
}