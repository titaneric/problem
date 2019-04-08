#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class TeamScore
{
  public:
    string team;
    string lower;
    int point;

    int win_num;
    int lose_num;
    int tie_num;

    int goal_self;
    int goal_against;

    int match_num;

  public:
    TeamScore() : team(""), lower(""), point(0), win_num(0), tie_num(0), lose_num(0), goal_self(0), goal_against(0), match_num(0) {}
    TeamScore(string team) : team(team), lower(team), point(0), win_num(0), tie_num(0), lose_num(0), goal_self(0), goal_against(0), match_num(0)
    {
        transform(team.begin(), team.end(), lower.begin(), ::tolower);
    }

  public:
    void updateStat(int self, int against)
    {
        if (self > against)
        {
            win_num++;
            point += 3;
        }
        else if (self == against)
        {
            tie_num++;
            point++;
        }
        else
        {
            lose_num++;
        }

        match_num++;
        goal_self += self;
        goal_against += against;
    }
};
bool comp(const TeamScore &t1, const TeamScore &t2)
{
    int t1_goal_diff = t1.goal_self - t1.goal_against;
    int t2_goal_diff = t2.goal_self - t2.goal_against;

    if (t1.point != t2.point)
    {
        return t1.point > t2.point;
    }
    else
    {
        if (t1.win_num != t2.win_num)
        {
            return t1.win_num > t2.win_num;
        }
        else
        {
            if (t1_goal_diff != t2_goal_diff)
            {
                return t1_goal_diff > t2_goal_diff;
            }
            else
            {
                if (t1.goal_self != t2.goal_self)
                {
                    return t1.goal_self > t2.goal_self;
                }
                else
                {
                    if (t1.match_num != t2.match_num)
                    {
                        return t1.match_num < t2.match_num;
                    }
                    else
                    {
                        return t1.lower < t2.lower;
                    }
                }
            }
        }
    }
}
void removeCarr(string &line)
{
    if (line.size() && line[line.size() - 1] == '\r')
    {
        line.erase(line.size() - 1);
    }
}
void parseMatch(string match, string &team1, int &score1, string &team2, int &score2)
{
    auto first_sharp = match.find('#');
    auto second_sharp = match.find_last_of('#');
    auto first_at = match.find('@');

    team1 = match.substr(0, first_sharp);
    score1 = stoi(match.substr(first_sharp + 1, first_at - first_sharp - 1));
    score2 = stoi(match.substr(first_at + 1, second_sharp - first_at - 1));
    team2 = match.substr(second_sharp + 1);

    // cout << team1 << ":" << score1 << endl;
    // cout << team2 << ":" << score2 << endl;
}
int main()
{
    int kase;
    cin >> kase;

    string tounament_name;
    getline(cin, tounament_name); // \n

    for (int k = 0; k < kase; k++)
    {
        getline(cin, tounament_name);
        removeCarr(tounament_name);

        int team_num;
        cin >> team_num;
        string team;
        getline(cin, team); // \n

        vector<TeamScore> teams(team_num);
        map<string, int> teams_index;
        for (int i = 0; i < team_num; i++)
        {
            getline(cin, team);
            removeCarr(team);
            teams[i] = TeamScore(team);
            teams_index[team] = i;
        }

        int match_num;
        cin >> match_num;
        string match;
        getline(cin, match); // \n
        string team1, team2;
        int score1, score2;
        for (int i = 0; i < match_num; i++)
        {
            getline(cin, match);
            removeCarr(match);
            parseMatch(match, team1, score1, team2, score2);

            teams[teams_index[team1]].updateStat(score1, score2);
            teams[teams_index[team2]].updateStat(score2, score1);
        }

        sort(teams.begin(), teams.end(), comp);

        cout << tounament_name << endl;
        for (int i = 0; i < teams.size(); i++)
        {
            cout << i + 1 << ") ";
            cout << teams[i].team << " " << teams[i].point << "p, ";
            cout << teams[i].match_num << "g ";
            cout << "(" << teams[i].win_num << "-" << teams[i].tie_num << "-" << teams[i].lose_num << "), ";
            cout << teams[i].goal_self - teams[i].goal_against << "gd ";
            cout << "(" << teams[i].goal_self << "-" << teams[i].goal_against << ")";
            cout << endl;
        }

        if (k != (kase - 1))
            cout << endl;
    }

    return 0;
}
