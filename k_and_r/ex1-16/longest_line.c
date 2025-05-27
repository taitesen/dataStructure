/*
Revise the routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text
*/
#include <stdio.h>

#define MAXLINE 100

int getlen(char line[], int maxlen);
void copy(char to[], char from[]);

int main() {
    int len;
    int max = 0;
    char line[MAXLINE] = {0};
    char longest[MAXLINE] = {0};

    while ((len = getlen(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);

    return 0;
}

int getlen(char line[], int maxlen) {
    int c, i = 0;
    for (; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
