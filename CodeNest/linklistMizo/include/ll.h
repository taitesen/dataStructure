#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node {
        char *data;
        struct Node *next;
} Node;

extern Node *head;

void InsertAtBegin(char *message);
void InsertAtEnd(char *message);
void InsertAtPos(char *message, int position);
void UpdateAtPos(char *message, int position);
void Delete(int position);
void Show(void);
void ClearBuffer(void);
int CountNode(void);

#endif // LINKLIST_H
