#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    string a, b;
    while (getline(cin, a) && getline(cin, b))
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0, j = 0; i < a.size() && j < b.size();)
        {
            if (a[i] == b[j])
            {
                printf("%c", a[i]);
                i++;
                j++;
            }
            else if (a[i] > b[j])
                j++;
            else
                i++;
        }
        printf("\n");
    }

    return 0;
}