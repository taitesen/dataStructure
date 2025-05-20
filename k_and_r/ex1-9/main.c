/*
Write a program to copy its input to its output, replacing each of string of one
or more blanks by a single blanks
*/
#include <stdio.h>

int main() {
    int c;
    int in_space = 0; // set to 1 everytime it encounter spaces

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!in_space) {
                in_space = 1;
                putchar(c);
            }
        } else {
            putchar(c);
            in_space = 0;
        }
    }
    return 0;
}
