#include "../include/stack.h"
#include <stdio.h>
#include <string.h>

void Reverse(char *arr);

int main() {
    char C[50];
    printf("Enter a string: ");
    scanf("%s", C);
    Reverse(C);
    printf("The reverse string is: %s\n", C);
    return 0;
}

void Reverse(char *arr) {
    int size = strlen(arr);
    for (int i = 0; i < size; ++i) {
        Push(arr[i]);
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = Pop();
    }
}
