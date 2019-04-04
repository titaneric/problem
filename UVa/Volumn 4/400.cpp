#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#define maxcol 60
using namespace std;
int main()
{

    int num;
    while (cin >> num)
    {

        int maxN = 0;
        vector<string> files(num);
        for (int i = 0; i < num; i++)
        {
            cin >> files[i];
            maxN = max(maxN, int(files[i].size()));
        }

        int cols = (maxcol - maxN) / (maxN + 2) + 1;
        int rows = (num - 1) / cols + 1;

        for (int i = 0; i < maxcol; i++)
        {
            putchar('-');
        }
        putchar('\n');

        sort(files.begin(), files.end());

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int i = c * rows + r;
                if (i < num)
                {
                    int width = (c == cols - 1) ? maxN : maxN + 2;
                    cout << left << setw(width) << files[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}