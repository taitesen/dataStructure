#include <stdlib.h>
#include <stdio.h>
#include "insert.h"
#include "linklist.h"

Node *HEAD = NULL;

Node *getNewNode(int data) {
    Node *temp = malloc(sizeof(Node));
    if(!temp) return NULL;

    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

void displayList() {
    Node *current = HEAD;
    while(current) { // same as current != NULL
        printf("%d", current->data);
        if(current->next) printf(", ");
    }
    printf("\n");
}

void insertLast(int data) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    if(HEAD == NULL) { // if HEAD is false
        HEAD = temp;
        return;
    }

    Node *current = HEAD;
    while(current->next) current = current->next;
    current->next = temp;
    temp->prev = current;
}

void insertFirst(int data) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    if(!HEAD) { // if HEAD is not true, same as if HEAD is false
        HEAD = temp;
        return;
    }

    temp->next = HEAD;
    HEAD->prev = temp;
}

void insertAtPosition(int data, int position) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    if(position == 1) {
        if(!HEAD) {
            HEAD = temp;
            return;
        }
        temp->next = HEAD;
        HEAD->prev = temp;
        HEAD = temp; // updating HEAD
        return;
    }

    Node *current = HEAD;
    for(int i = 1; i < (position - 1); ++i) {
        if(!current) break;
        current = current->next;
    }

    if(!current) {
        fprintf(stderr, "Position out of bound\n");
        free(temp);
        return;
    }

    // Case 1: inserting at the end/tail of a list(when current is the last node)
    if(current->next == NULL) {
        current->next = temp;
        temp->prev = current;
        return;
    }

    // Case 2: inserting between current and current->next
    temp->next = current->next;
    temp->prev = current;
    current->next->prev = temp;
    current->next = temp;
}

void insertAfterData(int dataToBeInserted, int indexData) {
    // handle the empty list case
    if(HEAD == NULL) {
        fprintf(stdout, "Cannot insert after %d, the list is empty\n", indexData);
        return;
    }

    Node *temp = getNewNode(dataToBeInserted);
    if(!temp) return;

    // finding node containing indexData
    Node *current = HEAD;
    while(current != NULL) {
        if(current->data == indexData) break;
        current = current->next;
    }

    // if indexData is not found
    if(current == NULL) {
        fprintf(stderr, "%d not found in a linklist\n", indexData);
        free(temp);
        return;
    }

    // Case 1: if we have to insert between (current and current->next)
    if(current->next != NULL) {
        temp->next = current->next;
        temp->prev = current;
        current->next->prev = temp;
        current->next = temp;
        return;
    }

    // Case 2: if we have to insert at the tail (current->next == NULL)
    current->next = temp;
    temp->prev = current;
}
