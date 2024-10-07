#ifndef _LINKLIST_QUEUE
#define _LINKLIST_QUEUE

// Strucuter of queue node
typedef struct Node {
        int data;
        struct Node *next;
} QueueNode;

extern QueueNode *front;
extern QueueNode *rear;

// Function prototype
QueueNode *getNewNode(int);
void Enque(int);
void Deque(void);
void Front(void);
int isEmpty(void);

#endif //_LINKLIST_QUEUE
