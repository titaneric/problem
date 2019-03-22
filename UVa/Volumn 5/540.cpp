#include <cstdio>
#include <queue>
#include <map>
using namespace std;
const int maxTeamSize = 1005;

int main()
{
    int teamSize, kase = 0;
    while (scanf("%d", &teamSize) == 1 && teamSize)
    {
        printf("Scenario #%d\n", ++kase);
        map<int, int> team_dict;
        for (int i = 0; i < teamSize; i++)
        {
            int teamNum, member;
            scanf("%d", &teamNum);
            for (int k = 0; k < teamNum; k++)
            {
                scanf("%d", &member);
                team_dict[member] = i;
            }
        }
        queue<int> totalQueue, teamQueue[maxTeamSize];
        while (true)
        {
            char command[10];
            scanf("%s", command);
            if (command[0] == 'S')
                break;
            else if (command[0] == 'D')
            {
                int t = totalQueue.front();
                printf("%d\n", teamQueue[t].front());
                teamQueue[t].pop();
                if (teamQueue[t].empty())
                {
                    totalQueue.pop();
                }
            }
            else if (command[0] == 'E')
            {
                int member;
                scanf("%d", &member);
                int t = team_dict[member];
                if (teamQueue[t].empty())
                    totalQueue.push(t);
                teamQueue[t].push(member);
            }
        }
        printf("\n");
    }
    return 0;
}
