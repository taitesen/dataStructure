/*
Write a program to count blanks, tabs, and newlines
*/

#include <stdio.h>
int main() {
    int c;
    int newlines = 0, tabs = 0, blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newlines++;
        else
            continue;
    }
    printf("Number of blank: %d\n", blanks);
    printf("Number of tabs: %d\n", tabs);
    printf("Number of newline: %d\n", newlines);
    return 0;
}
