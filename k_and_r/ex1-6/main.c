/*
Verify that the expression `getchar() != EOF` is 0 or 1.
*/

#include <stdio.h>

int main() {
    int c;
    printf("Enter Ctrl+d for EOF\n");
    while (1) {
        c = getchar();
        int result = c != EOF;
        printf("Value of c != EOF: %d\n", result);

        if (c == EOF)
            break;
    }
    return 0;
}
