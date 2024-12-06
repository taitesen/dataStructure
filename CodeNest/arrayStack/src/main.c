#include "../include/stack.h"
#include <stdio.h>

int main() {
    Stack_dt *my_stack = InitializeStack();
    Push(my_stack, "fist");
    Push(my_stack, "second");
    Push(my_stack, "third");
    printf("Top element: %s\n", Peek(my_stack));
    printf("Size: %d\n", Size(my_stack));
    Pop(my_stack);
    Pop(my_stack);
    printf("Top element: %s\n", Peek(my_stack));
    printf("Size: %d\n", Size(my_stack));
    Pop(my_stack);
    printf("Top element: %s\n", Peek(my_stack));
    printf("Size: %d\n", Size(my_stack));
    return 0;
}
