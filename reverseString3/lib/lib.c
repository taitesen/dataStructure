#include "../include/lib.h"
#include <malloc.h>

Stack *init_stack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    if (newStack == NULL) return NULL;
    newStack->size = SIZE;
    newStack->character = malloc(sizeof(char) * newStack->size);
    newStack->index = -1;
    return newStack;
}

void Resize(Stack *stack) {
    stack->size *= RESIZE_FACTOR;
    char *new_character = malloc(sizeof(char) * stack->size);
    for (int i = 0; i < stack->index; ++i) {
        new_character[i] = stack->character[i];
    }
    free(stack->character);
    stack->character = new_character;
}

void Push(char character, Stack *stack) {
    if (stack->index > (int)stack->size)
        Resize(stack);
    stack->character[++stack->index] = character;
}

char Pop(Stack *stack) {
    if (stack->index < 0) {
        fprintf(stderr, "The stack is empty\n");
        return '\0';
    }
    return stack->character[stack->index--];
}

void clean_stack(Stack *stack) {
    free(stack->character);
    free(stack);
}
