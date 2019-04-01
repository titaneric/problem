#include <cstdio>
#include <iostream>
#include <string>
#include <regex>
#include <utility>
#include <map>

using namespace std;

string concept = "([PUI])";
string real = "[+-]?(\\d*\\.\\d+|\\d+)";
string prefix = "([mkM])";
string unit = "([WVA])";
string datafield = "%s=%s%s?%s";

regex data_reg;

// ref from https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
void initRegex()
{
    size_t size = snprintf(nullptr, 0, datafield.c_str(), concept.c_str(), real.c_str(), prefix.c_str(), unit.c_str()) + 1; // Extra space for '\0'
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, datafield.c_str(), concept.c_str(), real.c_str(), prefix.c_str(), unit.c_str());
    string reg = string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    data_reg = reg;
}

pair<char, double> parse_inst(string &inst)
{
    auto equal_pos = inst.find('=');
    string num = inst.substr(equal_pos + 1);
    double val;

    char prefix = num[num.size() - 2];
    if (prefix == 'M')
    {
        num = num.substr(0, num.size() - 2);
        val = stod(num) * 1000000;
    }
    else if (prefix == 'k')
    {
        num = num.substr(0, num.size() - 2);
        val = stod(num) * 1000;
    }
    else if (prefix == 'm')
    {
        num = num.substr(0, num.size() - 2);
        val = stod(num) / 1000;
    }
    else
    {
        num = num.substr(0, num.size() - 1);
        val = stod(num);
    }
    return make_pair(inst[0], val);
}

int main()
{
    initRegex();
    int kase;
    cin >> kase;

    string line;
    getline(cin, line);

    for (int k = 0; k < kase; k++)
    {
        getline(cin, line);

        auto words_begin =
            std::sregex_iterator(line.begin(), line.end(), data_reg);
        auto words_end = std::sregex_iterator();

        string target = "PUI";
        map<char, double> phy_dict; // P = UI
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            std::string match_str = match.str();

            auto p = parse_inst(match_str);
            phy_dict[p.first] = p.second;
            target.erase(target.find(p.first), 1);
        }
        printf("Problem #%d\n", k + 1);
        if (target == "P")
        {
            printf("P=%.2fW\n\n", phy_dict['U'] * phy_dict['I']);
        }
        else if (target == "U")
        {
            printf("U=%.2fV\n\n", phy_dict['P'] / phy_dict['I']);
        }
        else if (target == "I")
        {
            printf("I=%.2fA\n\n", phy_dict['P'] / phy_dict['U']);
        }
    }
    return 0;
}
