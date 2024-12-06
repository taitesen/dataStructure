#include "../include/init.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

void Resize() {
    int new_size = stack->size * RESIZE_FACTOR;
    char **new_data = realloc(stack->data, new_size * sizeof(char *));
    if (new_data == NULL) {
        fprintf(stderr, "Stack not resizeable\n");
        return;
    }
    free(stack->data);
    stack->data = new_data;
    stack->size = new_size;
}

void Push(char *string) {
    if (stack->top >= stack->size - 1)
        Resize();
    stack->data[++stack->top] = strdup(string);
}

char *Pop() {
    if (stack == NULL) {
        fprintf(stderr, "The stack is not initialized\n");
        return NULL;
    }
    if (stack->top == -1) {
        fprintf(stderr, "The stack is empty\n");
        return NULL;
    }
    char *val = stack->data[stack->top];
    if (val == NULL) {
        fprintf(stderr, "Unexpected NULL value in a stack\n");
        return NULL;
    }
    stack->data[stack->top] = NULL;
    stack->top--;
    return val;
}

void Peek() {
    if (stack->top == -1) {
        fprintf(stderr, "The stack is empty\n");
        return;
    }
    printf("%s", stack->data[stack->top]);
}
