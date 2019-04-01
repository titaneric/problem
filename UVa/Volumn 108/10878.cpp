#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char ascii2chr(string ascii)
{
    int val = 0;
    int p = 1;
    for (int i = 0; i < 7; i++, p *= 2)
    {
        if (ascii[7 - 1 - i] == 'o')
        {
            val += p;
        }
    }
    char chr = val;
    return chr;
}
int main()
{

    string line;
    bool start;
    while (getline(cin, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1);
        }
        if (line[0] == '|')
        {
            string high = line.substr(2, 4);
            string low = line.substr(line.find('.') + 1, 3);

            string bin = high + low;
            cout << ascii2chr(bin);
        }
    }

    return 0;
}