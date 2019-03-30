#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Composer
{
  private:
    map<char, vector<int>> sax = {
        {'c', {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}},
        {'d', {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'e', {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'f', {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'g', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'a', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'b', {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
        {'C', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'D', {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'E', {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'F', {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'G', {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'A', {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'B', {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}}};
    string song;
    vector<int> finger;

  public:
    vector<int> press;
    Composer(string song) : finger(vector<int>(10)),
                            press(vector<int>(10)),
                            song(song)
    {
        compose();
    };
    void compose()
    {
        for (auto c : song)
        {
            if (sax.find(c) != sax.end())
            {
                for (int i = 0; i < 10; i++)
                {
                    if (finger[i] == 0 && finger[i] != sax[c][i])
                    {
                        press[i] += 1;
                    }
                }
                finger = sax[c];
            }
        }
    }
};
int main()
{
    int kase;
    cin >> kase;
    string song;
    getline(cin, song);

    for (int k = 0; k < kase; k++)
    {
        getline(cin, song);

        Composer composer(song);
        int i = 0;
        for (; i < 9; i++)
        {
            cout << composer.press[i] << " ";
        }
        cout << composer.press[9] << endl;
    }
    return 0;
}
