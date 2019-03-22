#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;

    while (cin >> n && n)
    {
        while (true)
        {

            vector<int> target(n + 1);
            cin >> target[1];
            if (target[1] == 0)
                break;
            for (int i = 2; i <= n; i++)
            {
                cin >> target[i];
            }
            int A = 1, B = 1;
            stack<int> s;
            int possible = true;

            while (B <= n)
            {
                if (target[B] == A)
                {
                    A++;
                    B++;
                }
                else if (!s.empty() && s.top() == target[B])
                {
                    s.pop();
                    B++;
                }
                else if (A <= n)
                {
                    s.push(A++);
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cout << endl;
    }

    return 0;
}