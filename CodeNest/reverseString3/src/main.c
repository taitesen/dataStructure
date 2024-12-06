#include "../include/lib.h"
#include <stdio.h>
#include <string.h>

void Reverse(char *string, Stack *stack);

int main(int argc, char *argv[]) {
    Stack *my_stack = init_stack();
    if (argc > 1) {
        Reverse(argv[1], my_stack);
    } else {
        fprintf(stderr, "String is not provided.\n");
    }
    return 0;
}

void Reverse(char *string, Stack *stack) {
    for (size_t i = 0; i < strlen(string); ++i) {
        Push(string[i], stack);
    }
    for (size_t i = 0; i < strlen(string); ++i) {
        printf("%c", Pop(stack));
    }
    printf("\n");
}
