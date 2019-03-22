#include <stdio.h>
#include <string.h>
#define maxn 100005
int ans[maxn];

int main() {
    int total, upper_bound;
    memset(ans, 0, sizeof(ans));
    for(int m = 1;m < maxn; m++)
    {
        int x = m, y = m;
        // get digit
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        if (!ans[y] || m < ans[y]) {
            ans[y] = m;
        }
    }
    scanf("%d", &total);
    while(total--){
        scanf("%d", &upper_bound);
        printf("%d\n", ans[upper_bound]);
    }




    return 0;
}

