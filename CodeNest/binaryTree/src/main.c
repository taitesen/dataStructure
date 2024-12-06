#include "../include/lib.h"
#include <stdio.h>

int main() {
    Bst *root = NULL;
    root = insert(root, 50);
    root = insert(root, 12);
    root = insert(root, 38);
    root = insert(root, 8);
    root = insert(root, 16);
    root = insert(root, 44);

    printf("The height of a tree is %d\n", findHeight(root));
    printf("Range are from %d to %d\n", minVal(root), maxVal(root));
    printf("Search the availability of a number: ");
    int input;
    scanf("%d", &input);
    if(search(root, input))
        printf("%d is found\n", input);
    else
        printf("%d is not found\n", input);

    return 0;
}
