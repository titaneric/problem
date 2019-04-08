#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

class Coord
{
  public:
    int x;
    int y;
    int z;

  public:
    Coord(int x, int y, int z) : x(x), y(y), z(z) {}
    double distance(Coord &ref)
    {
        double x_diff = double(x - ref.x);
        double y_diff = double(y - ref.y);
        double z_diff = double(z - ref.z);
        return sqrt(x_diff * x_diff +
                    y_diff * y_diff +
                    z_diff * z_diff);
    }
};

int main()
{
    vector<Coord> coord_vec;
    int x, y, z;
    int cnt[10] = {0};
    while (cin >> x >> y >> z)
    {
        if (x == 0 && y == 0 && z == 0)
            break;
        coord_vec.push_back(Coord(x, y, z));
    }
    for (int i = 0; i < coord_vec.size(); i++)
    {
        int min_distance = numeric_limits<int>::max();
        for (int j = 0; j < coord_vec.size(); j++)
        {
            if (i == j)
                continue;
            int dis = int(floor(coord_vec[i].distance(coord_vec[j])));
            min_distance = min(dis, min_distance);
        }
        if (min_distance >= 0 && min_distance <= 9)
        {
            cnt[min_distance] += 1;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << setw(4) << cnt[i];
    }
    cout << endl;
    return 0;
}