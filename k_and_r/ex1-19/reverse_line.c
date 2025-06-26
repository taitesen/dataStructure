/*
Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time
*/

/*
--> what are you into
--> otni uoy era tahw ---> reversing a whole line
*/

#include <stdio.h>

#define MAX_L 100

int get_line(char string[], int max_l);
char *reverse(char string[], int len);

int main() {
    int len = 0;
    char line[MAX_L] = {0};

    printf("Reversing the whole line:\n");
    len = 0;
    while ((len = get_line(line, MAX_L)) > 0) {
        printf("%s\n", reverse(line, len));
    }

    return 0;
}

int get_line(char string[], int max_l) {
    int c, i = 0;
    for (; i < max_l - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;
    // if (i == 0 && c == EOF)
    //     return i;
    if (c == '\n')
        string[i] = '\0';
    return i;
}

char *reverse(char string[], int len) {
    int end = (len % 2) ? (len - 1) / 2 : len / 2;
    char temp;
    for (int i = 0; i < end; ++i) {
        temp = string[i];
        string[i] = string[(len - 1) - i];
        string[(len - 1) - i] = temp;
    }
    return string;
}
