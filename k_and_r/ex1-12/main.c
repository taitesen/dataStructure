/*
Write a program that prints its input one word per line
*/
#include <stdio.h>

typedef enum state_t { IN, OUT } state_t;

int main() {
    int c;
    state_t state = IN;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {       // TRUE; c reads character
            if (state == IN) { // TRUE; c is reading of the character of a word
                putchar(c);
            } else if (state == OUT) { // TRUE; c is reading the first character of a word
                state = IN;
                putchar(c);
            }
        } else if (state == IN) { // TRUE; c reads one of ' ' or '\n' or '\t'
            state = OUT;
            putchar('\n');
            continue;
        } else if (state == OUT) { // TRUE; c reads again one of ' ' or '\n' or '\t'
            continue;
        }
    }
    return 0;
}
