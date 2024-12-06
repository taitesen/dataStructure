#ifndef STACK_H
#define STACK_H

typedef struct Stack_node {
        char data;
        struct Stack_node *link;
} Stack_node;

extern Stack_node *top;

void Push(char);
char Pop(void);

#endif // STACK_H
