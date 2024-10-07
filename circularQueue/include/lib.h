#ifndef _CIRCULAR_QUEUE_H
#define _CIRCULAR_QUEUE_H

#define SIZE 3 // Define the size of the queue
typedef struct {
        int *data; // Array to hold the queue element
        int rear;  // Index of the rear of the queue
        int front; // Index of the front of the queue
        int count; // Count the number of element in the queue
} Queue;

Queue *initQ(void);
void Enque(Queue *, int);
int Deque(Queue *);
void Front(Queue *);
void FreeQueue(Queue *);
#endif //_CIRCULAR_QUEUE_H
