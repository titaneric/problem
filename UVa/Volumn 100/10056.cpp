#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int total;
    cin >> total;

    for (int i = 0; i < total; i++)
    {
        int player_num;
        double win_prob;
        int player;
        cin >> player_num >> win_prob >> player;

        const double kase = 50;
        double partial = 0.0;
        for (double k = 0; k < kase; k++)
        {
            partial += pow((1 - win_prob), k * player_num + player - 1);
        }
        double prob = win_prob;

        printf("%.4f\n", prob * partial);
    }
    return 0;
}