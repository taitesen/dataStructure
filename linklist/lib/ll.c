#include "../include/ll.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

Node *head = NULL;

void InsertAtBegin(char *message) {
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation for Node failed\n");
        return;
    }
    temp->data = malloc(strlen(message) + 1);
    if (temp->data == NULL) {
        fprintf(stderr, "Memory allocation for Node->data failed\n");
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
        fprintf(stderr, "Memory allocation for Node failed\n");
        return;
    }
    temp->data = malloc(strlen(message) + 1);
    if (temp->data == NULL) {
        fprintf(stderr, "Memory allocation for Node->data failed\n");
        free(temp);
        return;
    }
    strcpy(temp->data, message);
    temp->next = NULL;

    Node *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = temp;
}

void InsertAtPos(char *message, int position) {
    if (position < 1) {
        fprintf(stderr, "Invalid Position");
        return;
    }
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation for Node failed\n");
        return;
    }
    temp->data = malloc(strlen(message) + 1);
    if (temp->data == NULL) {
        fprintf(stderr, "Memory allocation for Node->data failed\n");
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
        fprintf(stderr, "Position out of bound\n");
        free(temp->data);
        free(temp);
        return;
    }
    temp->next = current->next;
    current->next = temp;
}

void Delete(int position) {
    if (position < 1 || head == NULL) {
        fprintf(stderr, "Nothing to delete\n");
        return;
    }

    if (position == 1) {
        Node *del = head;
        head = del->next;
        free(del->data);
        free(del);
        return;
    }

    Node *current = head;
    for (int i = 1; i < (position - 1); ++i)
        current = current->next;

    if (current == NULL) {
        fprintf(stderr, "Out of bound\n");
        return;
    }

    Node *Del = current->next;
    current->next = Del->next;
    free(Del->data);
    free(Del);
}

void Update(char *message, int position) {
    if (position < 1 || head == NULL) {
        fprintf(stderr, "Nothing to be updated\n");
        return;
    }
    Node *current = head;
    for (int i = 1; i < position; ++i)
        current = current->next;

    if (current == NULL) {
        fprintf(stderr, "Out of bound\n");
        return;
    }
    strcpy(current->data, message);
}

void Show() {
    Node *temp = head;
    printf(" ");
    while (temp != NULL) {
        printf("%s", temp->data);
        temp = temp->next;
        if (temp != NULL)
            printf("\n ");
    }
    printf("\n");
}

void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
