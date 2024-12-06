#ifndef STACK_H
#define STACK_H

#define INIT_SIZE 10
#define RESIZE_FACTOR 2

typedef struct {
        char **data;
        int size;
        int top;
} Stack_node;

Stack_node *Initialize_stack(void);

#endif // STACK_H
