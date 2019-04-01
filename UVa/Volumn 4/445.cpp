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

        auto lb_pos = inst.find_last_not_of("\n");
        if (lb_pos != string::npos)
        {
            inst.erase(lb_pos + 1);
        }
        auto lbwin_pos = inst.find_last_not_of("\r\n");
        if (lbwin_pos != string::npos)
        {
            inst.erase(lbwin_pos + 1);
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
