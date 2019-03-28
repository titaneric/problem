#include <iostream>
#include <vector>

using namespace std;
int main()
{

    long long m, n;

    while (cin >> n >> m)
    {

        bool success = false;
        vector<long long> num_vec = {n};
        if (m != 0)
        {
            while (true)
            {
                if (n % m == 0)
                {
                    n /= m;
                    if (num_vec[num_vec.size() - 1] > n)
                    {
                        num_vec.push_back(n);
                        if (n == 1)
                        {
                            success = true;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (success)
        {
            int i = 0;
            for (; i < num_vec.size() - 1; i++)
            {
                cout << num_vec[i] << " ";
            }
            cout << num_vec[i] << endl;
        }
        else
        {
            cout << "Boring!\n";
        }
    }
    return 0;
}