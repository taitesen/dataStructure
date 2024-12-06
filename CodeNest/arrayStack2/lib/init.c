#include "../include/init.h"
#include <malloc.h>
#include <stdio.h>

Stack_node *stack;

void Init_stack() {
    stack = Initialize_stack();
    if (stack == NULL) {
        fprintf(stderr, "Stack initialization failed\n");
        return;
    }
}

void Clean_stack() {
    while (stack->top != -1) {
        free(stack->data[stack->top]);
        stack->data[stack->top] = NULL;
        stack->top--;
    }
}
