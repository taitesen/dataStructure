/*
Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLINE 120

int getlen(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE] = {0};

    while((len = getlen(line, MAXLINE)) > 0) {
        if(len > 80)
            printf("%s", line);
    }
    return 0;
}

int getlen(char line[], int maxline) {
    int c, i = 0;
    for (; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
