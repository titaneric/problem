#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
string encodeSeq(vector<int> seq)
{
    int i = seq.size();
    stringstream ss;
    while (i--)
    {
        ss << seq[i] << "|";
    }
    return ss.str();
}
int main()
{
    int total;
    scanf("%d", &total);
    for (int k = 0; k < total; k++)
    {
        int size;
        scanf("%d", &size);
        set<string> seq_history;
        vector<int> seq;
        seq.resize(size);

        for (int i = 0; i < size; i++)
        {
            scanf("%d", &seq[i]);
        }
        string encode_str = encodeSeq(seq);
        seq_history.insert(encode_str);

        bool isLoop = false;

        while (true)
        {
            int first_item = seq[0];
            for (int i = 0; i < size - 1; i++)
            {
                seq[i] = abs(seq[i] - seq[(i + 1) % size]);
            }
            seq[size - 1] = abs(seq[size - 1] - first_item);
            if (all_of(seq.begin(), seq.end(), [](int i) { return !i; }))
            {
                break;
            }
            encode_str = encodeSeq(seq);
            if (seq_history.find(encode_str) != seq_history.end())
            {
                isLoop = true;
                break;
            }
            else
            {
                seq_history.insert(encode_str);
            }
        }
        if (isLoop)
        {
            printf("LOOP\n");
        }
        else
        {
            printf("ZERO\n");
        }
    }

    return 0;
}