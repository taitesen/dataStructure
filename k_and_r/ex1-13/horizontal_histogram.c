#include <stdio.h>

int main() {
    int c, count = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            count++;
            continue;
        } else if (count > 0) {
            while (count > 0) {
                printf("█");
                count--;
            }
            putchar('\n');
        }
    }

    if (count > 0) {
        while (count > 0) {
            printf("█");
            count--;
        }
    }
    putchar('\n');
    return 0;
}
