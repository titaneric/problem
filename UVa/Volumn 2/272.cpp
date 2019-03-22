#include <stdio.h>

int main() {
    int chr, quote = 1;
    while((chr = getchar()) != EOF) {
        if (chr == '"') {
            printf("%s", quote ? "``": "''");
            quote = !quote;
        } else {
            printf("%c", chr);
        }
    }




    return 0;
}