#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>
#include <utility>
#include <string>

using namespace std;
int valid_access(const string &array_name, int index, bool access, map<string, int> &array_dict, map<pair<string, int>, int> &value_dict)
{
    auto array_iter = array_dict.find(array_name);
    if (array_iter != array_dict.end()) // check array existence
    {
        // cout << index << ":" << array_iter->second << endl;
        if (index < array_iter->second) //check boundary
        {
            if (access)
                return array_iter->second;
            pair<string, int> key = make_pair(array_name, index);
            auto value_iter = value_dict.find(key);
            if (value_iter != value_dict.end()) // check value
            {
                return value_iter->second;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}
int parseInst(const string &inst, map<string, int> &array_dict, map<pair<string, int>, int> &value_dict)
{
    stack<string> parse_stack;
    int i = 0;
    while (i < inst.size())
    {
        if (isdigit(inst[i]))
        {
            stringstream ss;
            string buf;
            while (i < inst.size() && isdigit(inst[i]))
            {
                ss << inst[i];
                i++;
            }
            ss >> buf;
            parse_stack.push(buf);
            // cout << "Push " << parse_stack.top() << " to stack" << endl;
        }
        else if (inst[i] == ']')
        {
            int index = stoi(parse_stack.top());
            parse_stack.pop();
            parse_stack.pop(); // pop [

            if (!parse_stack.empty())
            {
                string array_name = parse_stack.top();
                parse_stack.pop();
                // printf("Access %s[%d]\n", array_name.c_str(), index);
                int value = valid_access(array_name, index, false, array_dict, value_dict);
                if (value != -1)
                {
                    parse_stack.push(to_string(value));
                    i++;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return index;
            }
        }
        else
        {
            string buf(1, inst[i]);
            parse_stack.push(buf);
            i++;
        }
    }
    return stoi(parse_stack.top());
}
int main()
{
    while (true)
    {
        string inst;
        cin >> inst;
        if (inst == ".")
            break;

        vector<string> inst_vec;
        map<string, int> array_dict;
        map<pair<string, int>, int> value_dict;

        while (true)
        {
            inst_vec.push_back(inst);
            cin >> inst;
            if (inst == ".")
                break;
        }

        int lino = 0;
        bool bug = false;
        for (const string &inst : inst_vec)
        {
            // cout << inst << endl;
            lino++;
            // declaration
            size_t pos = inst.find('=');
            if (pos == string::npos)
            {
                string array_name = inst.substr(0, 1);
                int size = parseInst(inst.substr(1), array_dict, value_dict);
                if (size != -1)
                {
                    array_dict[array_name] = size;
                }
                else
                {
                    printf("%d\n", lino);
                    bug = true;
                    break;
                }
            }
            else
            {
                string l_value = inst.substr(0, pos - 1);
                string assigned_array_name = l_value.substr(0, 1);
                int array_index = parseInst(l_value.substr(1), array_dict, value_dict);
                // printf("Assign %s[%d] to ", assigned_array_name.c_str(), array_index);
                if (array_index != -1 && valid_access(assigned_array_name, array_index, true, array_dict, value_dict) != -1)
                {
                    string r_value = inst.substr(pos + 1);
                    int value = parseInst(r_value, array_dict, value_dict);
                    if (value != -1)
                    {
                        // printf("%d\n", value);
                        value_dict[make_pair(assigned_array_name, array_index)] = value;
                    }
                    else
                    {
                        printf("%d\n", lino);
                        bug = true;
                        break;
                    }
                }
                else
                {
                    printf("%d\n", lino);
                    bug = true;
                    break;
                }
            }
        }
        if (!bug)
        {
            printf("0\n");
        }
    }
    return 0;
}