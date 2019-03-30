#include <iostream>
using namespace std;
class Point
{
  public:
    double x, y;
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
    Point operator-(const Point &p)
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator+(const Point &p)
    {
        return Point(p.x + x, p.y + y);
    }
    bool operator==(const Point &p)
    {
        return p.x == x && p.y == y;
    }
    Point operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }
};
int main()
{
    Point a, b, c, d;

    while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y)
    {
        Point first = a, second = b, third, fouth;
        if (a == c)
        {
            first = b;
            second = a;
            third = d;
        }
        else if (a == d)
        {
            first = b;
            second = a;
            third = c;
        }
        else if (b == c)
        {
            third = d;
        }
        else if (b == d)
        {
            third = c;
        }
        fouth = first - (second - third);
        printf("%.3f %.3f\n", fouth.x, fouth.y);
    }

    return 0;
}