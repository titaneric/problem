#include <iostream>
#include <cstring>

#define maxn 200
using namespace std;

int sum[maxn];
void buildTree(int pos)
{
    int val;
    cin >> val;
    if (val == -1)
        return;
    sum[pos] += val;
    buildTree(pos - 1); // left tree
    buildTree(pos + 1); // right tree
}
bool readTree()
{
    int val;
    cin >> val;
    if (val == -1)
        return false;
    memset(sum, 0, sizeof(sum));
    int pos = maxn / 2;
    sum[pos] = val;
    buildTree(pos - 1);
    buildTree(pos + 1);
    return true;
}
int main()
{
    int kase = 1;
    while (readTree())
    {
        int pos = 0;
        while (sum[pos] == 0)
            pos++;
        cout << "Case " << kase++ << ":\n";

        cout << sum[pos++];
        while (sum[pos] != 0)
            cout << " " << sum[pos++];

        cout << endl
             << endl;
    }
    return 0;
}