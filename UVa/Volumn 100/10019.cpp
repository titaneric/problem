#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    int kase;
    cin >> kase;

    for (int i = 0; i < kase; i++)
    {
        int M;
        cin >> M;

        bitset<32> binary(M);
        int b1 = binary.count();

        int cnt_dict[10] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2};

        int b2 = 0;
        string str_M = to_string(M);
        for (auto c : str_M)
        {
            b2 += cnt_dict[c - '0'];
        }

        cout << b1 << " " << b2 << endl;
    }

    return 0;
}