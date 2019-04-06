#include <iostream>

using namespace std;
int main()
{

    int row, col;
    while (cin >> row >> col)
    {
        int cut = (row - 1) + row * (col - 1);
        cout << cut << endl;
    }

    return 0;
}