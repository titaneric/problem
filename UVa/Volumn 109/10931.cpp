#include <iostream>
#include <bitset>
#include <string>

using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        bitset<32> bin(n);
        string str_bin = bin.to_string<char, std::string::traits_type, std::string::allocator_type>();
        size_t pos = str_bin.find('1');
        str_bin = str_bin.substr(pos);
        cout << "The parity of " << str_bin << " is ";

        cout << bin.count() << " (mod 2)." << endl;
    }
}