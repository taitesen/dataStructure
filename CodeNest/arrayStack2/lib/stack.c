#include "../include/stack.h"
#include <malloc.h>
#include <stdio.h>

Stack_node *Initialize_stack() {
    Stack_node *stack = malloc(sizeof(Stack_node));
    if (stack == NULL) return NULL;
    stack->size = INIT_SIZE;
    stack->data = (char **)malloc(stack->size * sizeof(char *));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    stack->top = -1;
    return stack;
}
