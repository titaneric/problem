#include <stdio.h>
#include <string.h>
#define maxn 1010
int main() {
    int n, answer[maxn], guess[maxn];
    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        printf("Game %d:\n", ++kase);
        for(int i=0;i<n;i++) scanf("%d", &answer[i]);
        for(;;) {
            int A = 0, B = 0;
            for(int i=0;i<n;i++) {
                scanf("%d", &guess[i]);
                if (answer[i] == guess[i]) A++;
            }
            if(!guess[0]) break;
            for(int digit=1;digit<=9;digit++){
                int ans_cnt = 0, guess_cnt = 0;
                for(int i=0;i<n;i++) {
                    if(answer[i] == digit) ans_cnt++;
                    if(guess[i] == digit) guess_cnt++;
                }
                B += (ans_cnt < guess_cnt) ? ans_cnt: guess_cnt;
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }



    return 0;
}