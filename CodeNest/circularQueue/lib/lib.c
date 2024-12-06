#include "../include/lib.h"
#include <malloc.h>

Queue *initQ() {
    Queue *temp = malloc(sizeof(Queue));
    if (temp == NULL) return NULL;
    temp->data = malloc(sizeof(int) * SIZE);
    if (temp->data == NULL) {
        free(temp);
        return NULL;
    }
    temp->front = 0;
    temp->rear = -1;
    temp->count = 0;
    return temp;
}

void Enque(Queue *queue, int data) {
    // if the queue is full, it will not enque, but abort this function
    if (queue->count == SIZE) {
        fprintf(stderr, "The queue is full\n");
        return;
    }
    // if the queue is not full.
    // Update the rear index add new assign data in the queue
    queue->rear = (queue->rear + 1) % SIZE;
    queue->data[queue->rear] = data;
    queue->count++;
}

int Deque(Queue *queue) {
    // if the queue is empty, there is nothing to dequeu, and will abort
    if (queue->count == 0) {
        fprintf(stderr, "The queue is empty\n");
        return -1;
    }
    // Get the data at front index and update the front index
    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % SIZE;
    queue->count--;
    return data;
}

void Front(Queue *queue) {
    if (queue->count == 0) {
        fprintf(stderr, "The queue is empty\n");
        return;
    }
    printf("%d", queue->data[queue->front]);
}

void FreeQueue(Queue *queue) {
    if (queue) {
        free(queue->data); // free the data array
        free(queue);       // free the queue structure
    }
}
