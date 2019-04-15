#include <iostream>

using namespace std;

bool isEqual(int &weight_sum)
{
    int weight_left, weight_right;
    int dis_left, dis_right;
    cin >> weight_left >> dis_left >> weight_right >> dis_right;
    bool left_equal = true, right_equal = true;

    if (weight_left == 0)
    {
        left_equal = isEqual(weight_left);
    }
    if (weight_right == 0)
    {
        right_equal = isEqual(weight_right);
    }

    weight_sum = weight_left + weight_right;

    return left_equal && right_equal && (weight_left * dis_left == weight_right * dis_right);
}
int main()
{

    int kase, weight = 0;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        if (isEqual(weight))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        if (k != (kase - 1))
            cout << endl;
    }

    return 0;
}