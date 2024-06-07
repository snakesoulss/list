#ifndef LIST_H
#define LIST_H
#include "struct.h"

List* create_list();
void add_after(Node* current, int x);
void add_before(List* list, Node* current, int x);
void delete_node(List* list, Node* current);
Node* move_next(Node* current);
Node* move_prev(Node* current);
void print_list(List* list);
void free_list(List* list);
List* copy_list(List* list);
int get_current_value(Node* current);

#endif // LIST_H
