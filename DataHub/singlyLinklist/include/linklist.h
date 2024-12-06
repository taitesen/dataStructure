#ifndef LINKLIST_BASE_H
#define LINKLIST_BASE_H

typedef struct Node {
    int data;
    struct Node *next;
}Node;

extern Node *HEAD;

Node *getNewNode(int data);
void displayList();

#endif // LINKLIST_BASE_H
