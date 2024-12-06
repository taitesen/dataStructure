#include "../include/lib.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

Node *createNode(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->character = data;
    newNode->next = NULL;
    return newNode;
}

void push_op(Linklist *list, char data) {
    Node *newNode = createNode(data);
    if (!newNode) return;
    newNode->next = list->head;
    list->head = newNode;
}

void pop_op(Linklist *list) {
    if (list->head == NULL) {
        printf("The stack is empty\n");
        return;
    }
    Node *current = list->head;
    list->head = current->next;
    printf("%c", current->character);
    free(current);
}

void initLinklist(Linklist *list) {
    list->head = NULL;
    list->Push = push_op;
    list->Pop = pop_op;
}
