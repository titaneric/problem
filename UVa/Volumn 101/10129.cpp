#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>

using namespace std;

void DFS(char source, map<char, vector<pair<char, string>>> &adj_list, map<char, int> &visited, int &m)
{
    if (visited[source])
        return;

    visited[source] = true;
    m++;

    for (auto neighbor : adj_list[source])
    {
        DFS(neighbor.first, adj_list, visited, m);
    }
}

bool isConnected(map<char, vector<pair<char, string>>> &adj_list, int m)
{
    map<char, int> visited;
    for (auto node : adj_list)
    {
        for (auto neighbor : node.second)
        {
            visited[neighbor.first] = 0;
        }
    }

    for (auto node : adj_list)
    {
        int visited_num = 0;
        map<char, int> copy_visted = visited;
        DFS(node.first, adj_list, copy_visted, visited_num);
        if (visited_num == m)
        {
            return true;
        }
    }

    return false;
}

bool isEulerian(map<char, vector<pair<char, string>>> &adj_list)
{
    // pair: <in, out>
    map<char, pair<int, int>> degree;

    for (auto node : adj_list)
    {
        degree[node.first].second = node.second.size();
        for (auto out : node.second)
        {
            degree[out.first].first++;
        }
    }

    int equal_degree_num = 0;

    char source = '\0', dest = '\0';
    for (auto node : degree)
    {
        int in = node.second.first;
        int out = node.second.second;

        if (in == out)
        {
            equal_degree_num++;
        }
        else
        {
            // source
            if (out == (in + 1) && source == '\0')
            {
                source = node.first;
            }
            // dest
            else if (in == (out + 1) && dest == '\0')
            {
                dest = node.first;
            }
            else
            {
                return false;
            }
        }
    }

    if (equal_degree_num == degree.size())
        return true;

    if (source != '\0' && dest != '\0')
        return true;

    return false;
}
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int n;
        cin >> n;
        map<char, vector<pair<char, string>>> adj_list;
        set<char> vertices;

        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;

            char head = word[0];
            char tail = word[word.size() - 1];
            adj_list[head].push_back(make_pair(tail, word));
            vertices.insert(head);
            vertices.insert(tail);
        }

        if (isConnected(adj_list, vertices.size()) && isEulerian(adj_list))
        {
            cout << "Ordering is possible.\n";
        }
        else
        {
            cout << "The door cannot be opened.\n";
        }
    }
    return 0;
}