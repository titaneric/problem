#include <iostream>

using namespace std;
int main()
{
    int kase;
    while (cin >> kase && kase != -1)
    {
        for (int k = 0; k < kase; k++)
        {
            int D, I;
            cin >> D >> I;

            int ans = 1 << (D - 1);

            --I;

            for (int i = (D - 2); i >= 0; --i)
            {
                auto div_result = div(I, 2);
                ans |= div_result.rem << i;
                I = div_result.quot;
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}