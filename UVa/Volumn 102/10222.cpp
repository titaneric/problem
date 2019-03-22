#include <iostream>
#include <string>

using namespace std;

string keyboard_seq = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main()
{
    string sentence;
    while (getline(cin, sentence))
    {
        for (const char &c : sentence)
        {

            size_t pos = keyboard_seq.find(tolower(c));
            if (pos != string::npos)
                putchar(keyboard_seq[pos - 2]);
            else
                putchar(c);
        }
        printf("\n");
    }

    return 0;
}