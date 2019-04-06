#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
// ref from http://blog.tobygameac.com/2013/08/uva-10785-mad-numerologist.html
char consonant[21] = {
    'J',
    'S',
    'B',
    'K',
    'T',
    'C',
    'L',
    'D',
    'M',
    'V',
    'N',
    'W',
    'F',
    'X',
    'G',
    'P',
    'Y',
    'H',
    'Q',
    'Z',
    'R',
};

char vowel[5] = {'A', 'U', 'E', 'O', 'I'};
int main()
{
    int kase;
    cin >> kase;

    for (int k = 0; k < kase; k++)
    {
        int len;
        cin >> len;

        string vowel_candidate = "";
        string consonant_candidate = "";
        map<char, int> cnt;

        int vi = 0;
        int ci = 0;

        for (int i = 1; i <= len; i++)
        {
            if (i % 2) // odd
            {
                vowel_candidate += vowel[vi];
                cnt[vowel[vi]]++;
                if (cnt[vowel[vi]] == 21)
                {
                    vi++;
                }
            }
            else
            {
                consonant_candidate += consonant[ci];
                cnt[consonant[ci]]++;
                if (cnt[consonant[ci]] == 5)
                {
                    ci++;
                }
            }
        }

        sort(consonant_candidate.begin(), consonant_candidate.end());
        sort(vowel_candidate.begin(), vowel_candidate.end());

        cout << "Case " << k + 1 << ": ";
        for (int i = 1; i <= len; i++)
        {
            if (i % 2)
            {
                putchar(vowel_candidate[i / 2]);
            }
            else
            {
                putchar(consonant_candidate[i / 2 - 1]);
            }
        }
        cout << endl;
    }

    return 0;
}
