#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    string line;

    while (getline(cin, line))
    {
        list<char> result;
        list<char>::iterator it = result.begin();

        for (auto c : line)
        {
            if (c == '[')
            {
                it = result.begin();
            }
            else if (c == ']')
            {
                it = result.end();
            }
            else
            {
                result.insert(it, c);
            }
        }

        for (auto c : result)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}