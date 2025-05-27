/*
Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blanks lines.
*/
#include <stdio.h>

#define MAX 20

typedef enum state_t { IN, OUT } state_t;

char getword(char string[], int max);

int main() {
    char string[MAX] = {0};
    char delimitter;
    while ((delimitter = getword(string, MAX)) != EOF) {
        if (delimitter == ' ' || delimitter == '\t') {
            printf("%s ", string);
        } else if (delimitter == '\n') {
            printf("%s\n", string);
        }
    }
    return 0;
}

char getword(char string[], int max) {
    int c, i = 0;
    state_t state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (state == OUT) {
                state = IN;
                i = 0;
            }
            if (i < max - 1) {
                string[i++] = c;
            }
        } else if (state == IN) {
            break;
        }
    }

    if (i == 0 && c == EOF) {
        return EOF;
    }
    string[i] = '\0';
    return c;
}
