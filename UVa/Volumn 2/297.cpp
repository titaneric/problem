#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<pair<int, int>> getDirection(int width)
{
    return {{width / 2, 0},
            {0, 0},
            {0, width / 2},
            {width / 2, width / 2}};
}
void draw(vector<vector<bool>> &pixel, string &inst, size_t &p, int row, int col, int width, int &count)
{
    char node = inst[p++];
    if (node == 'p')
    {
        for (auto d : getDirection(width))
        {
            draw(pixel, inst, p, row + d.first, col + d.second, width / 2, count);
        }
    }
    else if (node == 'f')
    {
        for (int i = row; i < row + width; i++)
        {
            for (int j = col; j < col + width; j++)
            {
                if (!pixel[i][j])
                {
                    pixel[i][j] = true;
                    count++;
                }
            }
        }
    }
}
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        vector<vector<bool>> pixels(32, vector<bool>(32, false));
        int count = 0;

        string inst;
        for (int i = 0; i < 2; i++)
        {
            cin >> inst;
            size_t p = 0;
            draw(pixels, inst, p, 0, 0, 32, count);
        }

        cout << "There are " << count << " black pixels.\n";
    }
    return 0;
}