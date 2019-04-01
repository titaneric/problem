#include <iostream>
#include <string>

using namespace std;

int toSum(string num)
{
    int s = 0;
    for (auto n : num)
    {
        s += (n - '0');
    }
    return s;
}
int main()
{

    string inst;
    while (getline(cin, inst))
    {

        if (!inst.empty() && inst[inst.size() - 1] == '\r')
        {
            inst.erase(inst.size() - 1);
        }

        string num_buffer = "";
        for (auto c : inst)
        {
            if (isdigit(c))
            {
                num_buffer += c;
            }
            else if (c != '!' && num_buffer.size())
            {
                int repetition = toSum(num_buffer);
                num_buffer = "";
                char chr;
                if (c == 'b')
                {
                    chr = ' ';
                }
                else
                {
                    chr = c;
                }
                for (int i = 0; i < repetition; i++)
                {
                    cout << chr;
                }
            }
            else if (c == '!')
            {
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
