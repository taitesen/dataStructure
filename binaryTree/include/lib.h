#ifndef _BI_TREE_H
#define _BI_TREE_H

#include <stdbool.h>

typedef struct Bst{
    int data;
    struct Bst *left;
    struct Bst *right;
}Bst;

Bst *getNewNode(int);
Bst *insert(Bst *, int);
bool search(Bst *, int);
int minVal(Bst *, int);
int maxVal(Bst *, int);
int findHeight(Bst *);

#endif // _BI_TREE_H
