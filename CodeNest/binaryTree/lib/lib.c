#include "../include/lib.h"
#include <malloc.h>

#define max(x,y) ((x) > (y) ? (x) : (y))

Bst *getNewNode(int data) {
    Bst *temp = malloc(sizeof(Bst));
    if(!temp) return NULL;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Bst *insert(Bst *root, int data) {
    if(root == NULL)
        root = getNewNode(data);
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

bool search(Bst *root, int data) {
    if(!root) return false;
    if(root->data == data) return true;
    else if(data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

int minVal(Bst *root) {
    if(!root) return -1;
    while(root->left)
        root = root->left;
    return root->data;
}

int maxVal(Bst *root) {
    if(!root) return -1;
    while(root->right)
        root = root->right;
    return root->data;
}

int findHeight(Bst *root) {
    if(!root) return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}
