#include "../include/stack.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

Stack_dt *InitializeStack() {
    Stack_dt *temp = malloc(sizeof(Stack_dt));
    if (temp == NULL)
        return NULL;
    temp->size = SIZE;
    temp->index = -1;
    temp->data = (char **)malloc(temp->size * sizeof(char *));
    if (temp->data == NULL) {
        free(temp);
        return NULL;
    }
    return temp;
}

void ResizeStack(Stack_dt *stack) {
    if (stack->index < stack->size - 1) {
        printf("The stack is not full yet\n");
        return;
    }
    int new_size = stack->size * RESIZE_FACTOR;
    char **new_data = (char **)malloc(new_size * sizeof(char *));
    if (new_data == NULL)
        return;
    new_data = stack->data;
    free(stack->data);
    stack->data = new_data;
    stack->size = new_size;
}

void Push(Stack_dt *stack, char *message) {
    if (stack->index >= stack->size - 1) {
        ResizeStack(stack);
    }
    stack->data[++stack->index] = strdup(message);
}

void Pop(Stack_dt *stack) {
    if (stack->index == -1) {
        printf("The stack is empty\n");
        return;
    }
    char *temp = stack->data[stack->index];
    if (temp != NULL) {
        free(temp);
        stack->data[stack->index] = NULL;
    }
    stack->index--;
}

char *Peek(const Stack_dt *stack) {
    if (stack->index == -1) {
        printf("The stack is empty\n");
        return NULL;
    }
    char *val = stack->data[stack->index];
    return val;
}

int isEmpty(const Stack_dt *stack) { return stack->index == -1; }

int Size(const Stack_dt *stack) {
    if (stack->index == -1) {
        printf("The stack is empty\n");
        return 0;
    }
    return stack->index + 1;
}
