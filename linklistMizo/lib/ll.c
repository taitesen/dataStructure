#include "../include/ll.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

Node *head = NULL;

int CountNode() {
    int i = 0;
    if (head == NULL)
        return i;

    Node *current = head;
    while (current != NULL) {
        current = current->next;
        i += 1;
    }
    return i;
}

void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void InsertAtBegin(char *message) {
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL) {
        return;
    }
    temp->data = malloc(strlen(message) + 1);
    if (temp->data == NULL) {
        free(temp);
        return;
    }
    strcpy(temp->data, message);
    temp->next = head;
    head = temp;
}

void InsertAtEnd(char *message) {
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL) {
        return;
    }
    temp->data = malloc(sizeof(Node));
    if (temp->data == NULL) {
        free(temp);
        return;
    }
    strcpy(temp->data, message);
    if (head == NULL) {
        temp->next = head;
        head = temp;
        return;
    }

    temp->next = NULL;
    Node *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = temp;
}

void InsertAtPos(char *message, int position) {
    if (position < 1) {
        return;
    }
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL) {
        return;
    }
    temp->data = malloc(strlen(message) + 1);
    if (temp->data == NULL) {
        free(temp);
        return;
    }
    strcpy(temp->data, message);

    if (position == 1) {
        temp->next = head;
        head = temp;
        return;
    }

    Node *current = head;
    for (int i = 1; i < (position - 1); ++i)
        current = current->next;
    if (current == NULL) {
        free(temp->data);
        free(temp);
        return;
    }
    temp->next = current->next;
    current->next = temp;
}

void Delete(int position) {
    if (position < 1 || head == NULL) {
        return;
    }
    if (position == 1) {
        Node *deltur = head;
        head = deltur->next;
        free(deltur->data);
        free(deltur);
        return;
    }
    Node *current = head;
    for (int i = 1; i < (position - 1); ++i) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    Node *del = current->next;
    current->next = del->next;
    free(del->data);
    free(del);
    return;
}

void UpdateAtPos(char *message, int position) {
    if (head == NULL) {
        return;
    }
    InsertAtPos(message, position);
    Delete(position + 1);
}

void Show() {
    int i = 1;
    Node *current = head;
    while (current != NULL) {
        printf("%d. %s\n", i, current->data);
        current = current->next;
        ++i;
    }
}
