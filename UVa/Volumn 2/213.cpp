#include <iostream>
#include <map>
#include <string>

using namespace std;

char readChar()
{
    char ch;
    while (true)
    {
        ch = getchar();
        if (ch != '\n' && ch != '\r')
            return ch;
    }
}

int readInt(int len)
{
    int v = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = readChar();
        v = 2 * v + (ch - '0');
    }
    return v;
}

bool readHeader(map<int, map<int, char>> &header_map)
{
    string header;
    if (!getline(cin, header))
        return false;

    if (header.size() && header[header.size() - 1] == '\r')
    {
        header.erase(header.size() - 1);
    }

    int len = 1;
    int v = 0;
    for (auto h : header)
    {
        header_map[len][v] = h;
        v++;
        if (v == (1 << len) - 1)
        {
            v = 0;
            len++;
        }
    }
    return true;
}
int main()
{
    string linebreak;
    while (true)
    {
        map<int, map<int, char>> header_map;
        if (!readHeader(header_map))
            break;

        // for (auto h : header_map)
        // {
        //     for (auto c : h.second)
        //     {
        //         cout << h.first << "," << c.first << ":" << c.second << endl;
        //     }
        // }
        while (true)
        {
            int len = readInt(3);
            if (len == 0)
            {
                getline(cin, linebreak);
                break;
            }
            while (true)
            {
                int v = readInt(len);
                if (v == (1 << len) - 1)
                    break;
                putchar(header_map[len][v]);
            }
        }
        putchar('\n');

    }
    return 0;
}