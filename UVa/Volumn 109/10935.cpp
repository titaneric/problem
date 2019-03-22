#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {

        queue<int> deck;

        if (n == 1)
        {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                deck.push(i);
            }
            printf("Discarded cards: ");
            while (true)
            {
                if (deck.size() > 2)
                    printf("%d, ", deck.front());
                else
                {
                    printf("%d\n", deck.front());
                    deck.pop();

                    printf("Remaining card: %d\n", deck.front());
                    break;
                }

                deck.pop();

                int front = deck.front();
                deck.pop();
                deck.push(front);
            }
        }
    }

    return 0;
}