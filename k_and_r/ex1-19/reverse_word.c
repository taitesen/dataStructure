/*
Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time
*/

/*
--> what are you into
--> tahw era uoy otni ---> reversing by each word
*/

#include <stdio.h>

#define MAX_W 20

typedef enum state_t { IN, OUT } state_t;

char get_word(char string[], int max_w, int *len);
char *reverse(char string[], int len);

int main() {
    int len = 0;
    char delimiter;
    char word[MAX_W] = {0};

    printf("Reversing word by word:\n");
    while ((delimiter = get_word(word, MAX_W, &len)) != EOF) {
        if (delimiter == ' ' || delimiter == '\t') {
            printf("%s ", reverse(word, len));
        } else if (delimiter == '\n') {
            printf("%s\n", reverse(word, len));
        }
    }

    return 0;
}

char get_word(char string[], int max_w, int *len) {
    int c, i = 0;
    state_t state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (state == OUT) {
                state = IN;
                i = 0;
            }
            if (i < max_w - 1) {
                string[i++] = c;
            }
        } else if (state == IN) {
            break;
        }
    }
    if (i == 0 && c == EOF)
        return EOF;
    string[i] = '\0';
    *len = i;
    return c;
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
