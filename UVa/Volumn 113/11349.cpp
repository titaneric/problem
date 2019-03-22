#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int kase;
    cin >> kase;
    string line;
    getline(cin, line);
    for (int k = 0; k < kase; k++)
    {
        getline(cin, line);
        size_t pos = line.find("=");
        int n = stoi(line.substr(pos + 1));

        bool non_negative = false;
        vector<long long> matrix(n * n);
        for (int i = 0; i < n * n; i++)
        {
            cin >> matrix[i];
            if (matrix[i] < 0)
            {
                non_negative = true;
            }
        }
        getline(cin, line);
        cout << "Test #" << k + 1 << ": ";
        if (non_negative)
        {
            cout << "Non-symmetric.\n";
        }
        else
        {
            bool is_palindrome = true;
            for (int i = 0; i < matrix.size() / 2; i++)
            {
                if (matrix[i] != matrix[matrix.size() - 1 - i])
                {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome)
            {
                cout << "Symmetric.\n";
            }
            else
            {
                cout << "Non-symmetric.\n";
            }
        }
    }

    return 0;
}