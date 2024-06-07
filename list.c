#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "struct.h"

List* create_list() {
    List* list = malloc(sizeof(List));
    if (!list) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

void add_after(Node* current, int x) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->num = x;
    new_node->next = current->next;
    new_node->prev = current;
    if (current->next) {
        current->next->prev = new_node;
    }
    current->next = new_node;
}

void add_before(List* list, Node* current, int x) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->num = x;
    new_node->prev = current->prev;
    new_node->next = current;
    if (current->prev) {
        current->prev->next = new_node;
    } else {
        list->head = new_node;
    }
    current->prev = new_node;
}

void delete_node(List* list, Node* current) {
    if (!current) return;

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    if (current->next) {
        current->next->prev = current->prev;
    }
    free(current);
}

Node* move_next(Node* current) {
    return current ? current->next : NULL;
}

Node* move_prev(Node* current) {
    return current ? current->prev : NULL;
}

void print_list(List* list) {
    Node* current = list->head;
    while (current) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

void free_list(List* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

List* copy_list(List* list) {
    List* new_list = create_list();
    if (!list->head) {
        return new_list;
    }

    Node* current = list->head;
    Node* new_current = malloc(sizeof(Node));
    if (!new_current) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_current->num = current->num;
    new_current->prev = NULL;
    new_list->head = new_current;

    Node* prev_new = new_current;
    current = current->next;

    while (current) {
        new_current = malloc(sizeof(Node));
        if (!new_current) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        new_current->num = current->num;
        new_current->prev = prev_new;
        prev_new->next = new_current;
        prev_new = new_current;
        current = current->next;
    }
    prev_new->next = NULL;
    return new_list;
}

int get_current_value(Node* current) {
    return current ? current->num : -1;
}
