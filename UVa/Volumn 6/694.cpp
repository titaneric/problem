#include <iostream>

using namespace std;
int main()
{
    int kase = 1;

    int A, L;
    while (cin >> A >> L && A > 0 && L > 0)
    {

        int copyA = A;
        int term = 1;
        while (A != 1)
        {
            if (A % 2) // odd
            {
                if (A <= ((L - 1) / 3))
                {
                    A = 3 * A + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                A /= 2;
            }
            term++;
        }

        cout << "Case " << kase++ << ": A = " << copyA << ", limit = " << L << ", number of terms = " << term << endl;
    }
    return 0;
}