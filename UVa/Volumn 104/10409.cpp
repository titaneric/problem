#include <iostream>
#include <string>
#include <map>

using namespace std;

class Dice
{
  public:
    int top;
    int bottom;
    int north;
    int south;
    int west;
    int east;

  public:
    Dice(int t, int n, int w)
    {
        top = t;
        north = n;
        west = w;
        bottom = 7 - top;
        south = 7 - north;
        east = 7 - west;
    }

  public:
    void turn_north()
    {
        int tmp_north = north;
        north = top;
        top = south;
        south = bottom;
        bottom = tmp_north;
    }
    void turn_south()
    {
        int tmp_south = south;
        south = top;
        top = north;
        north = bottom;
        bottom = tmp_south;
    }
    void turn_west()
    {
        int tmp_west = west;
        west = top;
        top = east;
        east = bottom;
        bottom = tmp_west;
    }
    void turn_east()
    {
        int tmp_east = east;
        east = top;
        top = west;
        west = bottom;
        bottom = tmp_east;
    }
};
int main()
{

    int n;
    while (cin >> n && n)
    {
        string command;
        Dice dice(1, 2, 3);
        for (int i = 0; i < n; i++)
        {
            cin >> command;
            switch (command[0])
            {
            case 'n':
                dice.turn_north();
                break;
            case 's':
                dice.turn_south();
                break;
            case 'w':
                dice.turn_west();
                break;
            case 'e':
                dice.turn_east();
                break;
            default:
                break;
            }
        }
        cout << dice.top << endl;
    }
    return 0;
}