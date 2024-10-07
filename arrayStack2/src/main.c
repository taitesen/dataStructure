#include "../include/util.h"
#include <stdio.h>

int main() {
    Init_stack();
    Push("Lalenkawli");
    Push("Ruth");

    printf("The element that is being pop out of a stack is: ");
    printf("\"%s\"", Pop());
    printf(". The current element at the top of the stack is: \"");
    Peek();
    printf("\".\n");

    Clean_stack();
    return 0;
}
