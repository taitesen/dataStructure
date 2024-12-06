#include "deletion.h"
#include "insertion.h"
#include "linklist.h"
#include "position.h"
#include "reverse.h"
#include <malloc.h>
#include <stdlib.h>

Node *HEAD = NULL;

Node *getNewNode(int data) {
    Node *temp = malloc(sizeof(Node));
    if(temp == NULL) return NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void displayList() {
    printf("\nList of data\n");
    Node *current = HEAD;
    while(current != NULL) {
        printf("%d", current->data);
        if(current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("\n");
}

// Position.h ################################################################
void pointToLastNode(Node *temp) {
    temp = HEAD;
    while(temp->next != NULL) {
        temp = temp->next;
    }
}

void pointToSecondLastNode(Node *temp) {
    temp = HEAD;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
}

void pointToNodeWithXData(Node *temp, int data) {
    temp = HEAD;
    while(temp != NULL) {
        if(temp->data == data) break;
        temp = temp->next;
    }
}

void pointToNodeBeforeXData(Node *temp, int data) {
    temp = HEAD;
    while(temp->next != NULL) {
        if(temp->next->data == data) break;
        temp = temp->next;
    }
}

void pointToPosition(Node *temp, int position) {
    temp = HEAD;
    for(int i = 1; i < position && temp != NULL; ++i) {
        temp = temp->next;
    }
}
//################################################################## position.h

// insertion.h ################################################################
void insertAtBegin(int data) {
    Node *temp = getNewNode(data);
    if(temp == NULL) return;
    // if(!temp) return; can also mean the same thing
    // it is like: if temp is false vs if temp is not true
    temp->next = HEAD;
    HEAD = temp;
}

void insertAtEnd(int data) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    if(HEAD == NULL) {
        HEAD = temp;
        return;
    }

    Node *current = HEAD;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    /* here temp->next already points to NULL from the function getNewNode(..)
    if not, we have to explicitly have to make temp->next = NULL; */
}

void insertAfterPosition(int data, int position) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    Node *current = HEAD;
    for(int i = 1; i < position && current != NULL; ++i) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

void insertAtPosition(int data, int position) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    Node *current = HEAD;
    for(int i = 1; i < (position - 1) && current->next != NULL; ++i) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

void insertAfterXData(int data, int XData) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    Node *current = HEAD;
    while(current) {
        if(current->data == XData) break;
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
}

void insertBeforeXData(int data, int XData) {
    Node *temp = getNewNode(data);
    if(!temp) return;

    Node *current = HEAD;
    while(current) {
        if(current->next->data == XData) break;
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
}
//################################################################# insertion.h

//deletion.h #################################################################
void deleteFirstNode() {
    Node *current = HEAD;
    HEAD = HEAD->next;
    free(current);
}

void deleteAnOnlyNode() {
    Node *current = HEAD;
    HEAD = HEAD->next;
    free(current);
}

void deleteNodeAtPosition(int position) {
    Node *current = HEAD;
    for(int i = 1; i < (position - 1) && current != NULL; ++i) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

void deleteLastNode() {
    Node *current = HEAD;
    while(current->next->next != NULL) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = NULL;
    free(temp);
}
//################################################################## deletion.h

// reverse.h ##################################################################
void reverse() {
    printf("\nAfter reversing\n");
    Node *prev, *next, *current;
    prev = NULL;
    current = HEAD;
    while(current != NULL) {
        next = current->next; // save the next node
        current->next = prev; // reverse the current node's pointer
        prev = current;       // move prev's to the current pointer
        current = next;       // move to the next node
    }
    HEAD = prev;              // update the head to point to the new front
}
// ################################################################## reverse.h
