#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
// vector<int> split(string str)
// {
//     vector<int> vec;

//     istringstream ss(str);

//     string token;
//     while (getline(ss, token, ' '))
//     {
//         vec.push_back(stoi(token));
//     }
//     return vec;
// }

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> split_result(num);
        for (int i = 0; i < num; i++)
        {
            cin >> split_result[i];
        }
        bool is_jolly = true;

        if (split_result.size() > 1)
        {
            vector<bool> check(num);

            for (int i = 1; i < split_result.size(); i++)
            {
                int diff = abs(split_result[i] - split_result[i - 1]);
                if (diff > (split_result.size() - 1) || diff < 1)
                {
                    is_jolly = false;
                    break;
                }
                else if (check[diff])
                {
                    is_jolly = false;
                    break;
                }
                else
                {
                    check[diff] = true;
                }
            }
        }
        if (is_jolly)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
}