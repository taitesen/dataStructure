#ifndef REVERSE_STRING_H
#define REVERSE_STRING_H
typedef struct Node {
        char character;
        struct Node *next;
} Node;

typedef struct Linklist {
        Node *head;

        void (*Push)(struct Linklist *, char);
        void (*Pop)(struct Linklist *);
} Linklist;

Node *createNode(char);
void push_op(Linklist *, char);
void pop_op(Linklist *);
void initLinklist(Linklist *);

#endif // REVERSE_STRING_H
