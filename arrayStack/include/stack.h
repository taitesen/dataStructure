#ifndef STACK_H
#define STACK_H

#define SIZE 10
#define RESIZE_FACTOR 2
typedef struct Stack_dt {
        char **data;
        int size;
        int index;
} Stack_dt;

Stack_dt *InitializeStack(void);
void ResizeStack(Stack_dt *);
void Push(Stack_dt *, char *);
void Pop(Stack_dt *);
char *Peek(const Stack_dt *);
int isEmpty(const Stack_dt *);
int Size(const Stack_dt *);
#endif // STACK_H
