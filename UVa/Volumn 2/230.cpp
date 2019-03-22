#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
string parseBook(string &line)
{
    size_t first = line.find_first_of('\"');
    size_t second = line.find_last_of('\"');
    return line.substr(first + 1, second - first - 1);
}
pair<string, string> parseLine(string &line)
{
    string book = parseBook(line);
    size_t by = line.find("by") + 3;
    string author = line.substr(by);
    return make_pair(author, book);
}
bool comp(const pair<string, string> &b1, const pair<string, string> &b2)
{
    return (b1.first < b2.first) || ((b1.first == b2.first) && (b1.second < b2.second));
}
int main()
{
    string line;
    char c;
    vector<pair<string, string>> shelf;
    unordered_map<string, string> book_dict;
    vector<pair<string, string>> return_queue;
    while (getline(cin, line) && line[0] != 'E')
    {
        pair<string, string> book = parseLine(line);
        book_dict[book.second] = book.first;
        shelf.push_back(book);
    }

    sort(shelf.begin(), shelf.end(), comp);

    while (getline(cin, line) && line[0] != 'E')
    {
        if (line[0] == 'B')
        {
            string book_name = parseBook(line);
            auto pos = lower_bound(shelf.begin(), shelf.end(), make_pair(book_dict[book_name], book_name), comp);
            shelf.erase(pos);
        }
        else if (line[0] == 'R')
        {
            string book_name = parseBook(line);
            return_queue.push_back(make_pair(book_dict[book_name], book_name));
        }
        else if (line[0] == 'S')
        {
            sort(return_queue.begin(), return_queue.end(), comp);
            queue<pair<string, string>> q(deque<pair<string, string>>(return_queue.begin(), return_queue.end()));
            while (!q.empty())
            {
                pair<string, string> book = q.front();
                q.pop();
                auto pos = lower_bound(shelf.begin(), shelf.end(), book, comp);
                if (pos != shelf.begin())
                {
                    size_t index = pos - shelf.begin();
                    printf("Put \"%s\" after \"%s\"\n", book.second.c_str(), shelf[index - 1].second.c_str());
                } else{
                    printf("Put \"%s\" first\n", book.second.c_str());
                }
                shelf.insert(pos, book);
            }
            return_queue.clear();
            printf("END\n");
        }
    }

    return 0;
}