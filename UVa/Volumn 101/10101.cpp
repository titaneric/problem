#include <iostream>
#include <map>
#include <string>

using namespace std;
int countDigit(unsigned long long num)
{
    int digit = 0;
    while (num)
    {
        digit++;
        num /= 10;
    }
    return digit;
}
int main()
{
    map<int, string> num_dict;
    num_dict[7] = "kuti";
    num_dict[5] = "lakh";
    num_dict[3] = "hajar";
    num_dict[2] = "shata";

    int power[4] = {10000000, 100000, 1000, 100};

    int total = 0;
    unsigned long long num;
    while (cin >> num)
    {
        printf("%4d. ", ++total);
        if (!num)
        {
            cout << num << endl;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (num >= power[i])
                {
                    unsigned long long quo = num / power[i];

                    for (int j = 0; j < 4; j++)
                    {
                        if (quo >= power[j])
                        {
                            unsigned long long quo_pre = quo / power[j];
                            cout << quo_pre << " " << num_dict[countDigit(power[j]) - 1];

                            unsigned long long quo_post = quo % power[j];
                            quo = quo_post;

                            if (quo_post)
                            {
                                cout << " ";
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    if (quo)
                        cout << quo;
                    cout << " " << num_dict[countDigit(power[i]) - 1];

                    unsigned long long remain = num % power[i];
                    num = remain;

                    if (remain)
                    {
                        cout << " ";
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (num)
                cout << num;
            cout << endl;
        }
    }
    return 0;
}