#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include"struct.h"
Node* add_after(Node* current, int x);
Node* add_before(Node* current, int x);
Node* elem_delete(Node* current);
Node* move_next(Node* current);
Node* move_prev(Node* current);
void print_list(Node* head);
void free_list(Node* head);
#endif // LIST_H_INCLUDED
