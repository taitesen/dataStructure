#include "../include/lib.h"
#include <malloc.h>
#include <stdio.h>

QueueNode *front = NULL;
QueueNode *rear = NULL;
int count = 0;

QueueNode *getNewNode(int data) {
    QueueNode *temp = malloc(sizeof(QueueNode));
    if (temp == NULL) return NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void Enque(int data) {
    QueueNode *node = getNewNode(data);
    if (node == NULL) return;
    if (count == 0) {
        rear = node;
        front = node;
    } else {
        rear->next = node;
        rear = node;
    }
    count++;
}

void Deque() {
    if (count == 0) {
        fprintf(stderr, "The queue is empty\n");
        return;
    }
    QueueNode *temp = front;
    front = temp->next;
    free(temp);
    count--;
    if (count == 0) {
        rear = NULL;
        front = NULL;
    }
}

void Front() {
    if (isEmpty()) {
        fprintf(stderr, "The queue is empty\n");
        return;
    }
    printf("The front of the queue: %d\n", front->data);
}

int isEmpty() { return count == 0; }
