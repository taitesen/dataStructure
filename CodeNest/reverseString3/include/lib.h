#ifndef STACK_H
#define STACK_H

#define SIZE 10
#define RESIZE_FACTOR 2
#include <stddef.h>
typedef struct Stack {
        char *character;
        size_t size;
        int index;
} Stack;

Stack *init_stack(void);
void Resize(Stack *);
void Push(char character, Stack *);
char Pop(Stack *);
void clean_stack(Stack *);

#endif // STCAK_H
