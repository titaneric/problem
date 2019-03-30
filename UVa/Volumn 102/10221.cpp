#include <iostream>
#include <cmath>
#include <string>

#define PI 2*acos(0)
using namespace std;

int main()
{

    double s, degree;
    string unit;

    while (cin >> s >> degree >> unit)
    {
        if (degree > 180)
        {
            degree = 360 - degree;
        }
        if (unit[0] == 'm')
        {
            degree /= 60;
        }

        double r = 6440 + s;
        double rad = degree * PI / 180;

        printf("%.6f %.6f\n", r * rad, 2 * r * sin(rad / 2));
    }
}
