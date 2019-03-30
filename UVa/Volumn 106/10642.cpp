#include <iostream>

using namespace std;
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        long step = 0;

        int x = x1;
        int y = y1;
        while ((x + y) != (x2 + y2))
        {
            int lx = (x + y);

            step += (lx - x) + 1;

            x = 0;
            y = lx + 1;
        }
        step += (x2 - x);
        cout << "Case " << k + 1 << ": " << step << endl;
    }
    return 0;
}