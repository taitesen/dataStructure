#ifndef LINKLIST_POSITIONING_H
#define LINKLIST_POSITIONING_H

#include "linklist.h"
void pointToLastNode(Node *temp);
/* This will make temp points to NULL at the end of a loop
##########################################################
Node *temp = HEAD;
while(temp != NULL) {
    temp = temp->next;
}
##########################################################
## 1. Pointers to a last node
##########################################################
Node *temp = HEAD;
while(temp->link != NULL) {
    temp = temp->link;
}
########################################################*/


void pointToSecondLastNode(Node *temp);
/* 2. Pointers to a second last node
##########################################################
Node *temp = HEAD;
while(temp->link->link != NULL) {
    temp = temp->link;
}
########################################################*/

void pointToNodeWithXData(Node *temp, int data);
/* 3. Pointers to a node with particular info/data
##########################################################
When the loop stops `temp` will point to a `Node` which
contains 'x' data.
##########################################################
Node *temp = HEAD;
while(temp != NULL) {
    if(temp->data == x) {
        break;
    }
    temp = temp->next;
}
########################################################*/


void pointToNodeBeforeXData(Node *temp, int data);
/* 4. Pointers to a predecessor of a node with particular info
##########################################################
After the loop the `temp` will points to a `Node` before
a `Node` which contains 'x' data.
##########################################################
Node *temp = HEAD;
while(temp->next != NULL) {
    if(temp->next->data == x) {
        break;
    }
    temp = temp->next;
}
########################################################*/

void pointToPosition(Node *temp, int position);
/* 5. Finding pointers to a node at a particular position
##########################################################
After the loop the `temp` will point to 'x' position
##########################################################
Node *temp = HEAD;
for(int i = 1; i < position && temp != NULL; ++i) {
    temp = temp->next;
}
########################################################*/

#endif // LINKLIST_POSITIONING_H
