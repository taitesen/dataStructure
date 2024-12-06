#ifndef LINKLIST_INSERTION_H
#define LINKLIST_INSERTION_H
/* PRE-REQUISITE
Understands `Node *getNewNode(int data)` first.
*/

void insertAtBegin(int data);
/* 1. Insertion in the beginning #############################################
How to insert a node at the beginning of a linklist when it is not empty.
insertAtBegin(int data) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    // The order of below lines of code is important!
    temp->next = HEAD;
    HEAD = temp;
}
############################################################################*/

void insertWhenEmpty(int data);
/* 2. Insertion in an empty list #############################################
How to insert a Node in an empty linklist
insertWhenEmpty(int data) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    // Insertion in an empty list & inserting at the beginning are same for
    // singly linklist, but will differ in doubly linklist
    temp->next = HEAD;
    HEAD = temp;
}
############################################################################*/

void insertAtEnd(int data);
/* 3. Insertion at the end ###################################################
How to insert a Node at the end of a linklist
insertAtEnd(int data) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    // first make `current` point to the last Node in a linklist
    Node *current = HEAD;
    while(current->link != NULL) current = current->next;

    // Then make `current->next` point to `temp`
    current->next = temp;

    // Then make `temp->next` point to NULL, as it is the new last Node
    temp->next = NULL;
}
############################################################################*/

void insertAfterPosition(int data, int position);
/* 4. Insertion after a specified node in a Linklist #########################
How to insert a node after a given specific positions.
insertAfterPosition(int data, int position) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    Node *current = HEAD;
    // after the loop current will point to exactly at given position
    for(int i = 1; i < position && current != NULL; ++I) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}
############################################################################*/

void insertBeforePosition(int data, int position);
/* 5. Insertion before a specified node in a Linklist ########################
How to insert a node before a given specific positions
insertBeforePosition(int data, int position) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    Node *current = HEAD;
    // After the loop current will point to a node just before the given position
    for(int i = 1; i < (position - 1) && current->next != NULL; ++i) {
        temp = temp->next;
    }
    temp->next = current->next;
    current->next = temp;
}
############################################################################*/

void insertAtPosition(int data, int position);
/* 6. Insertion at a specified position in a Linklist ########################
Insertion at a specified position is same as insertion before a specified node
insertAtPosition(int data, int position) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    Node *current = HEAD;
    for(int i = 1; i < (position - 1) && current->next != NULL; ++i) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}
############################################################################*/

void insertAfterXData(int data, int XData);
/* 7. Insertion at a node after a node which contains XData ##################
We are goind to insert data after XData in a linklist.
After the loop exit, the current will point to a node which contains XData
insertAfterXData(int data, int XData) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    Node *current = HEAD;
    while(current->next != NULL) {
        if(current->data == XData) break;
        current = current->next;
    }
}
############################################################################*/

void insertBeforeXData(int data, int XData);
/* 7. Insertion at a node before a node which contains XData ##################
We are going to insert data before XData in a linklist.
After the loop exit, the `current` will point to a node before a node which
contains XData
insertBeforeXData(int data, int XData) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;

    Node *current = HEAD;
    while(current != NULL) {
        if(current->next->data == XData) break;
        current = current->next;
    }
}
############################################################################*/
#endif // LINKLIST_INSERTION_H
