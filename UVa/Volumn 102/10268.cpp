#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

vector<long long> split(string poly)
{
    vector<long long> result;
    // istringstream ss(poly);
    // string token;

    // while (getline(ss, token, ' '))
    // {
    //     result.push_back(stoll(token));
    // }
    regex rgx("\\s+");
    sregex_token_iterator iter(poly.begin(), poly.end(), rgx, -1);
    sregex_token_iterator end;
    for (; iter != end; ++iter)
    {
        result.push_back(stoll(*iter));
    }
    return result;
}
int main()
{

    long long x;
    string poly;
    while (cin >> x && getline(cin, poly) && getline(cin, poly))
    {
        vector<long long> result = split(poly);

        long long ans = 0;
        long long xpow = 1;

        for (int i = result.size() - 2; i >= 0; i--, xpow *= x)
        {
            long long p = (long long)result.size() - i - 1;
            ans += p * result[i] * xpow;
        }

        cout << ans << endl;
    }
    return 0;
}