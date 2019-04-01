#include <iostream>
#include <string>

using namespace std;
int main()
{

    string line;
    while (getline(cin, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1);
        }
        for (auto c : line)
        {
            putchar(c - 7);
        }
        putchar('\n');
    }

    return 0;
}