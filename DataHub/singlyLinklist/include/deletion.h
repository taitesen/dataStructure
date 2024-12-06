#ifndef LINKLIST_DELETION_H
#define LINKLIST_DELETION_H

void deleteFirstNode();
/* How to delete a first Node #################################################
deleteFirstNode() {
    Node *current = HEAD;
    HEAD = HEAD->next;
    free(current);
}
#############################################################################*/

void deleteAnOnlyNode();
/* How to delete an only Node #################################################
// Same as deleteFirstNode
deleteAnOnlyNode() {
    Node *current = HEAD;
    HEAD = NULL; // or HEAD = HEAD->link;
    free(current);
}
#############################################################################*/

void deleteNodeAtPosition(int position);
/* How to delete a Node at a given position ###################################
deleteNodeAtPosition(int position) {
    Node *current = HEAD;
    // `current` will have to point to (position - 1)th position
    for(int i = 1; i < (position - 1) && current != NULL; ++i) {
        current = current->next;
    }
    // the (position)th position will be assigned to temp
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}
#############################################################################*/

void deleteLastNode();
/* How to delete the last Node ################################################
deleteLastNode() {
    Node *current = HEAD;
    // `current` will have to point to second last Node
    while(curent->next->next != NULL) {
        current = current->next;
    }
    // temp will point to the last Node
    Node *temp = current->next;

    current->next = NULL;
    free(temp);
}
#############################################################################*/
#endif // LINKLIST_DELETION_H
