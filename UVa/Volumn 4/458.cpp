#include <iostream>
#include <string>

using namespace std;
int main()
{

    string line;
    while (getline(cin, line))
    {
        auto linebreak_pos = line.find_last_not_of("\n");
        if (linebreak_pos != string::npos)
        {
            line.erase(linebreak_pos + 1);
        }
        auto linewind_pos = line.find_last_not_of("\r\n");
        if (linewind_pos != string::npos)
        {
            line.erase(linewind_pos + 1);
        }

        for (auto c : line)
        {
            putchar(c - 7);
        }
        putchar('\n');
    }

    return 0;
}