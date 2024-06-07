#ifndef STRUCT_H
#define STRUCT_H

typedef struct Node {
    int num;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
} List;

#endif // STRUCT_H
