#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;
map<char, pair<int, int>> direction_dict = {
    {'A', {-1, 0}},
    {'B', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}};
bool valid_access(int r, int c)
{
    return ((r >= 0) && (r < 5)) && ((c >= 0) && (c < 5));
}
int main()
{
    int kase = 0;
    char inst;
    string linebreak;
    bool is_terminated = false;
    while ((inst = getchar()) && inst != 'Z' && !is_terminated)
    {
        if (kase)
            cout << endl;
        ungetc(inst, stdin);

        cout << "Puzzle #" << ++kase << ":\n";
        string puz;
        int initx = -1, inity = -1;
        char puzzle[5][5];
        for (int i = 0; i < 5; i++)
        {
            getline(cin, puz);
            // cout << puz << endl;
            if (puz.size() && puz[puz.size() - 1] == '\r')
            {
                puz.erase(puz.size() - 1);
            }
            if (puz.size() < 5)
            {
                puz += ' ';
            }
            for (int j = 0; j < 5; j++)
            {
                puzzle[i][j] = puz[j];
                // cout << puzzle[i][j] << endl;
                if (puzzle[i][j] == ' ')
                {
                    initx = i;
                    inity = j;
                }
            }
        }

        bool invalid = false;
        while ((inst = getchar()) && inst != '0')
        {
            if (isspace(inst))
                continue;
            if (direction_dict.find(inst) == direction_dict.end())
            {
                invalid = true;
                break;
            }
            
            auto dir = direction_dict[inst];
            int target_x = initx + dir.first;
            int target_y = inity + dir.second;
            // cout << inst << ":";
            // cout << initx << ","<<inity <<"->";
            // cout << target_x <<","<<target_y<<endl;
            if (valid_access(target_x, target_y))
            {
                swap(puzzle[initx][inity], puzzle[target_x][target_y]);
                initx = target_x;
                inity = target_y;
            }
            else
            {
                invalid = true;
                break;
            }
        }
        if (invalid)
            while ((inst = getchar()) && inst != '0')
                ;
        getline(cin, linebreak);
        if ((inst = getchar()) == 'Z')
            is_terminated = true;
        else
        {
            ungetc(inst, stdin);
        }
        

        if (invalid)
        {
            cout << "This puzzle has no final configuration.\n";
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                int j = 0;
                for (; j < 4; j++)
                {
                    cout << puzzle[i][j] << " ";
                }
                cout << puzzle[i][j] << endl;
            }
        }
    }
    return 0;
}