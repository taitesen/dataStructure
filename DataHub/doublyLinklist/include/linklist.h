#ifndef LINKLIST_STRUCTURE_H
#define LINKLIST_STRUCTURE_H

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}Node;

Node *getNewNode(int data);
void displayList(void);
#endif // LINKLIST_STRUCTURE_H
