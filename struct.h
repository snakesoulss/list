#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
typedef struct Node {
    int num;
    int flag;
    struct Node* next;
    struct Node* prev;
} Node;
#endif // STRUCT_H_INCLUDED
