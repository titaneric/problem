#include <iostream>

using namespace std;

int main()
{

    char chr;

    while (cin >> chr)
    {
        int n;
        bool illegal = false;
        if (isdigit(chr))
        {
            n = chr - '0' + 1;
        }
        else if (isupper(chr))
        {
            n = 10 + chr - 'A' + 1;
        }
        else if (chr != 'z')
        {
            n = 10 + 26 + chr - 'a' + 1;
        }
        else
        {
            illegal = true;
        }
        if (!illegal)
        {
            cout << n << endl;
        }
        else
        {
            cout << "such number is impossible!\n";
        }
    }
    return 0;
}