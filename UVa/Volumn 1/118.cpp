#include <iostream>
#include <string>
#include <set>
#include <map>
#include <tuple>

using namespace std;
int upper_left_x, upper_left_y;
set<tuple<int, int>> prohibit_area;

bool valid_pos(int x, int y)
{
    return (x >= 0) && (x <= upper_left_x) && (y >= 0) && (y <= upper_left_y);
}
class Robot
{
  public:
    int x, y;
    char face;

  private:
    string direction = "NESW";
    map<char, pair<int, int>> move_dict = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}};
    int op;

  public:
    Robot(int init_x, int init_y, char face) : x(init_x),
                                               y(init_y),
                                               face(face)
    {
        op = int(direction.find(face));
    };
    bool move(char inst)
    {
        if (inst == 'R')
        {
            op = (op + 1 + 4) % 4;
            face = direction[op];
            return true;
        }
        else if (inst == 'L')
        {
            op = (op - 1 + 4) % 4;
            face = direction[op];
            return true;
        }
        else
        {
            int new_x = x + move_dict[face].first;
            int new_y = y + move_dict[face].second;
            if (!valid_pos(new_x, new_y))
            {
                if (prohibit_area.find(make_tuple(x, y)) != prohibit_area.end())
                {
                    return true;
                }
                return false;
            }
            x = new_x;
            y = new_y;
            return true;
        }
    }
};
int main()
{

    cin >> upper_left_x >> upper_left_y;

    int init_x, init_y;
    char face;
    string seq;

    while (cin >> init_x >> init_y >> face >> seq)
    {
        Robot robot(init_x, init_y, face);

        bool lost = false;
        for (auto inst : seq)
        {
            // cout << robot.x << ", " << robot.y << robot.face;
            // cout << ":" << inst << "->";
            if (!robot.move(inst))
            {
                prohibit_area.insert(make_tuple(robot.x, robot.y));
                lost = true;
                break;
            }
            // cout << robot.x << ", " << robot.y << robot.face << endl;
        }

        cout << robot.x << " " << robot.y << " " << robot.face;
        if (lost)
            cout << " LOST";
        cout << endl;
    }
    return 0;
}