#include "../include/lib.h"
#include <stdio.h>
#include <string.h>

void Reverse(char *arr, Linklist *test);

int main() {
    Linklist list;
    initLinklist(&list);

    char string[100];
    printf("Enter a string: ");
    scanf("%99s", string);
    printf("The reverse string is: ");
    Reverse(string, &list);
    return 0;
}

void Reverse(char *arr, Linklist *test) {
    size_t size = strlen(arr);
    for (size_t i = 0; i < size; ++i) {
        test->Push(test, arr[i]);
    }
    for (size_t i = 0; i < size; ++i) {
        test->Pop(test);
    }
    printf("\n");
}
