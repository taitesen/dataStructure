#include "../include/stack.h"
#include <malloc.h>

Stack_node *top = NULL;

void Push(char character) {
    Stack_node *temp = malloc(sizeof(Stack_node));
    if (temp == NULL) return;
    temp->data = character;
    temp->link = top;
    top = temp;
}

char Pop() {
    Stack_node *temp = top;
    if (temp == NULL) {
        fprintf(stderr, "The stack is empty\n");
        return '\0';
    }
    char val = temp->data;
    top = temp->link;
    free(temp);
    return val;
}
