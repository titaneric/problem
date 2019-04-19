#include <iostream>
#include <tuple>
#include <string>
#include <utility>
#include <queue>
#include <map>
#include <vector>

using namespace std;

class State
{
public:
    pair<int, int> coords;
    int face;
    State(pair<int, int> coords, int face) : coords(coords), face(face) {}
    State() {}
};
string direction = "NESW"; // clock-wise
string turns = "FLR";

pair<int, int> move_dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getDirectionID(char dir)
{
    return (int)direction.find(dir);
}

int getTurnsID(char turn)
{
    return (int)turns.find(turn);
}

State walk(State &state, int turn)
{
    int dir = state.face;
    // turn left
    if (turn == 1)
        dir = (dir + 3) % 4;
    // turn right
    if (turn == 2)
        dir = (dir + 1) % 4;

    return State(make_pair(state.coords.first + move_dir[dir].first, state.coords.second + move_dir[dir].second), dir);
}

void print(State &terminal, State &source, map<tuple<int, int, int>, int> &dis, map<tuple<int, int, int>, State> &parent)
{
    vector<State> path;
    State u = terminal;
    while (true)
    {
        path.push_back(u);
        auto key = make_tuple(u.coords.first, u.coords.second, u.face);
        if (dis[key] == 0)
            break;
        u = parent[key];
    }

    path.push_back(source);

    int cnt = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        // first coords in each line
        if (cnt % 10 == 0)
            cout << " ";
        cout << " (" << path[i].coords.first << "," << path[i].coords.second << ")";
        if (++cnt % 10 == 0)
            cout << endl;
    }
    if (path.size() % 10 != 0)
        cout << endl;
}
void BFS(map<pair<int, int>, bool> &valid_coords, map<pair<int, int>, map<pair<int, int>, bool>> &valid_move, State &source, pair<int, int> &dest)
{
    queue<State> q;

    map<tuple<int, int, int>, int> dis;
    map<tuple<int, int, int>, State> parent;

    // from source walk 1 unit toward its face
    State cur_state = walk(source, 0);

    // mark as source
    dis[make_tuple(cur_state.coords.first, cur_state.coords.second, cur_state.face)] = 0;

    q.push(cur_state);

    while (!q.empty())
    {
        cur_state = q.front();
        q.pop();

        if (cur_state.coords == dest)
        {
            print(cur_state, source, dis, parent);
            return;
        }

        for (int turn = 0; turn < turns.size(); turn++)
        {
            State attempt_pos = walk(cur_state, turn);
            auto key = make_tuple(attempt_pos.coords.first, attempt_pos.coords.second, attempt_pos.face);
            if (valid_move[make_pair(cur_state.coords.first, cur_state.coords.second)][make_pair(cur_state.face, turn)] && valid_coords.find(make_pair(attempt_pos.coords.first, attempt_pos.coords.second)) != valid_coords.end() && dis.find(key) == dis.end())
            {
                dis[key] = dis[make_tuple(cur_state.coords.first, cur_state.coords.second, cur_state.face)] + 1;
                parent[key] = cur_state;
                q.push(attempt_pos);
            }
        }
    }

    cout << "  No Solution Possible\n";
}

int main()
{

    string name;
    while (cin >> name && name != "END")
    {
        pair<int, int> source;
        pair<int, int> dest;
        char face;

        cin >> source.first >> source.second >> face;
        cin >> dest.first >> dest.second;

        State s(source, getDirectionID(face));

        // key: (row, col), (dir, turn)
        map<pair<int, int>, map<pair<int, int>, bool>> valid_move;
        map<pair<int, int>, bool> valid_coords;

        valid_coords[source] = true;
        valid_coords[dest] = true;

        pair<int, int> point;
        while (cin >> point.first && point.first)
        {
            cin >> point.second;
            string p;
            while (cin >> p && p != "*")
            {
                int dir = getDirectionID(p[0]);
                for (int i = 1; i < p.size(); i++)
                {
                    auto k = make_pair(point.first, point.second);
                    int turn = getTurnsID(p[i]);
                    valid_move[k][make_pair(dir, turn)] = true;
                    valid_coords[k] = true;
                }
            }
        }
        cout << name << endl;
        BFS(valid_coords, valid_move, s, dest);
    }
    return 0;
}