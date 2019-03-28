#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define maxN 1000000

void primeTable(vector<bool> &table)
{
    vector<int> prime;
    for (int i = 2; i < maxN; i++)
    {
        bool is_prime = true;
        for (int p = 0; p < prime.size() && prime[p] < 1000; p++)
        {
            if (i % prime[p] == 0)
            {
                table[i] = false;
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            table[i] = true;
            prime.push_back(i);
        }
    }
}
int main()
{
    vector<bool> prime_table(maxN);
    primeTable(prime_table);

    string n;
    while (cin >> n)
    {
        int int_n = stoi(n);
        if (prime_table[int_n])
        {
            string rev_n(n);
            reverse_copy(n.begin(), n.end(), rev_n.begin());

            int rev_int_n = stoi(rev_n);
            if (prime_table[rev_int_n] && n != rev_n)
            {
                cout << n << " is emirp.\n";
            }
            else
            {
                cout << n << " is prime.\n";
            }
        }
        else
        {
            cout << n << " is not prime.\n";
        }
    }
    return 0;
}