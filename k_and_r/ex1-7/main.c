/*
Write a program to print the value of EOF.
*/

#include <stdio.h>

int main() {
    int c;
    printf("To see the value of EOF: Enter Ctrl+d\n");
    while ((c = getchar()) != EOF) {
    }
    if (c == EOF)
        printf("Value of EOF: %d\n", c);
    return 0;
}
