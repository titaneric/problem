#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
void printVector(vector<int> &vec)
{
    int i = 0;
    for (; i < vec.size() - 1; i++)
    {
        cout << vec[i] << " ";
    }
    cout << vec[i] << endl;
}
vector<int> split(string &line)
{
    vector<int> result;
    istringstream ss(line);
    string pancake;
    while (getline(ss, pancake, ' '))
    {
        result.push_back(stoi(pancake));
    }
    return result;
}
int main()
{
    string line;

    while (getline(cin, line))
    {

        vector<int> pancakes = split(line);
        vector<int> copy_pancakes(pancakes);

        vector<int> operation_list;
        auto finished_idx = pancakes.size();

        while (finished_idx > 1)
        {
            int max_idx = 0;
            int max_val = 0;
            for (int i = 0; i < finished_idx; i++)
            {
                if (pancakes[i] > max_val)
                {
                    max_val = pancakes[i];
                    max_idx = i;
                }
            }

            if (max_idx != (finished_idx - 1))
            {
                // put maximum to first one
                if (max_idx != 0)
                {
                    operation_list.push_back(pancakes.size() - max_idx);
                    reverse(pancakes.begin(), pancakes.begin() + max_idx + 1);
                }
                // put maximum to its position
                operation_list.push_back(pancakes.size() - finished_idx + 1);
                reverse(pancakes.begin(), pancakes.begin() + finished_idx);
            }
            finished_idx--;
        }
        operation_list.push_back(0);

        printVector(copy_pancakes);
        printVector(operation_list);
    }
    return 0;
}