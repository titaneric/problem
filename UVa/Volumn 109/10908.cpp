#include <iostream>
#include <vector>

using namespace std;

bool validAccess(int M, int N, int x, int y)
{
    return (x >= 0 && x < M) && (y >= 0 && y < N);
}
bool testSquare(vector<vector<char>> &grid, int x, int y, int len)
{
    int M = grid.size();
    int N = grid[0].size();
    int item = grid[x][y];
    for (int i = -len; i <= len; i++)
    {
        for (int j = -len; j <= len; j++)
        {
            if (!validAccess(M, N, x + i, y + j))
                return false;
            if (grid[x + i][y + j] != item)
                return false;
        }
    }
    return true;
}

int main()
{
    int kase;
    cin >> kase;
    for (int k = 0; k < kase; k++)
    {

        int M, N, Q;

        cin >> M >> N >> Q;

        vector<vector<char>> grid(M);
        for (int i = 0; i < M; i++)
        {
            vector<char> row(N);
            for (int j = 0; j < N; j++)
            {
                cin >> row[j];
            }
            grid[i] = row;
        }

        cout << M << " " << N << " " << Q << endl;
        int x, y;
        for (int i = 0; i < Q; i++)
        {
            cin >> x >> y;

            int len = 1;

            while (true)
            {
                if (!testSquare(grid, x, y, len))
                {
                    break;
                }
                len++;
            }
            cout << 2 * len - 1 << endl;
        }
    }
    return 0;
}