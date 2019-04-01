#include <iostream>
#include <string>
#include <regex>
#include <iterator>

using namespace std;
regex word("([A-Za-z]+)");
int main()
{
    string line;

    while (getline(cin, line))
    {
        auto words_begin = sregex_iterator(line.begin(), line.end(), word);
        auto words_end = sregex_iterator();
        cout << distance(words_begin, words_end) << endl;
        // for(auto it = words_begin;it!=words_end;it++)
        // {
        //     cout << it->str() << endl;
        // }
    }

    return 0;
}
