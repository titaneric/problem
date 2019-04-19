#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

bool DFS(int source, map<int, set<int>> &adj_list, map<int, int> &status, vector<int> &result, int &t)
{
    status[source] = -1;
    for (auto v : adj_list[source])
    {
        // cycle
        if (status[v] < 0)
            return false;
        if (status[v] == 0 && !DFS(v, adj_list, status, result, t))
            return false;
    }
    status[source] = 1;

    result[--t] = source;
    return true;
}
bool topoSort(map<int, set<int>> &adj_list, int num_point, vector<int> &result, int &t)
{
    map<int, int> status;
    for (int i = 1; i <= num_point; i++)
    {
        status[i] = 0;
    }

    for (int i = 1; i <= num_point; i++)
    {
        if (status[i] == 0)
        {
            if (!DFS(i, adj_list, status, result, t))
                return false;
        }
    }

    return true;
}
int main()
{

    int num_point, num_edge;

    while (cin >> num_point >> num_edge && num_point)
    {
        map<int, set<int>> adj_list;
        vector<int> result(num_point);
        int t = num_point;

        for (int i = 0; i < num_edge; i++)
        {
            int head, tail;
            cin >> head >> tail;

            adj_list[head].insert(tail);
        }
        topoSort(adj_list, num_point, result, t);

        int i = 0;
        for (; i < result.size() - 1; i++)
            cout << result[i] << " ";
        cout << result[i] << endl;
    }
    return 0;
}
