#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2)
    {

        int dividend = a;
        vector<int> decimal;
        map<int, int> remain_dict;
        int cycle;

        while (true)
        {
            div_t div_result = div(dividend, b);
            decimal.push_back(div_result.quot);

            auto find_rem_iter = remain_dict.find(div_result.rem);
            if (find_rem_iter != remain_dict.end())
            {
                cycle = decimal.size() - find_rem_iter->second;
                break;
            }
            remain_dict[div_result.rem] = decimal.size();

            dividend = div_result.rem * 10;
        }

        int non_rep = decimal.size() - 1 - cycle;

        // first quoient
        printf("%d/%d = %d.", a, b, decimal[0]);

        int i, cnt = 0;
        // non repetition decimal part
        for (i = 1; i < 1 + non_rep; i++)
        {
            printf("%d", decimal[i]);
            cnt++;
        }

        // repetition decimal part
        printf("(");
        for (i = 1 + non_rep; i < decimal.size(); i++)
        {
            printf("%d", decimal[i]);
            cnt++;

            if (cnt == 50 && decimal.size() != 51)
            {
                printf("...");
                break;
            }
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", cycle);
    }
    return 0;
}