#include <iostream>

using namespace std;
int main()
{

    int N;
    while (cin >> N)
    {
        int factor3 = 1;
        int t = 1;
        while (factor3 <= N)
        {
            factor3 = t * 3;
            t++;
        }
        int max_cola = N;
        for (int borrow = 0; borrow <= factor3 - N; borrow++)
        {
            int bottle = N;
            int total = borrow + N;
            int empty = 0;
            while (total >= 3)
            {
                int exchange = total / 3;
                empty = total % 3;
                bottle += exchange;
                total = exchange + empty;
            }
            if (bottle > max_cola && total >= borrow)
            {
                max_cola = bottle;
            }
        }

        cout << max_cola << endl;
    }
    return 0;
}