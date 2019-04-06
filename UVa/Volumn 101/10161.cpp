#include <iostream>
#include <cmath>
#include <utility>

using namespace std;
pair<long long, long long> findDiagonalIndex(long long time)
{
    long long delta = 2;
    long long diagonal = 1;
    long long idx = 1;
    while (true)
    {
        if (time >= (diagonal - (idx - 1)) && time <= (diagonal + (idx - 1)))
            break;
        diagonal += delta;
        idx++;
        delta += 2;
    }
    return make_pair(diagonal, idx);
}
int main()
{

    long long time;
    while (cin >> time && time)
    {

        pair<long, long> coord;
        auto p = findDiagonalIndex(time);
        long long diff = abs(time - p.first);
        if (p.second % 2) // odd index
        {
            if (time > p.first) // left grow
            {
                coord = make_pair(p.second, p.second - diff);
            }
            else // top grow
            {
                coord = make_pair(p.second - diff, p.second);
            }
        }
        else
        {
            if (time > p.first) // bottom grow
            {
                coord = make_pair(p.second - diff, p.second);
            }
            else // right grow
            {
                coord = make_pair(p.second, p.second - diff);
            }
        }
        cout << coord.second << " " << coord.first << endl;
    }
    return 0;
}