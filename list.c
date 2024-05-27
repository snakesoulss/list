#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "struct.h"

Node* add_after(Node* current, int x) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->num = x;
    new_node->flag = 1;
    new_node->next = current->next;
    new_node->prev = current;
    current->next->prev = new_node;
    current->next = new_node;
    if (!current->flag) {
        return new_node->next;
    }
    return current->next;
}


Node* add_before(Node* current, int x) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->num = x;
    new_node->flag = 1;
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
    if (!current->flag) {
        return new_node->prev;
    }
    return current->prev;
}

Node* elem_delete(Node* current) {
    if (current->flag == 0) {
        return current;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    Node* next_node = current->next;
    free(current);
    if (!next_node->flag) {
        return next_node->next;
    }
    return next_node;
}

Node* move_next(Node* current) {
    current = current->next;
    if (!current->flag) {
        current = current->next;
    }
    return current;
}

Node* move_prev(Node* current) {
    current = current->prev;
    if (!current->flag) {
        current = current->prev;
    }
    return current;
}

void print_list(Node* head) {
    Node* current = head;
    do {
        if (current->flag) {
            printf("%d ", current->num);
        }
        current = current->next;
    } while (current != head);
    printf("\n");
}

void free_list(Node* head) {
    Node* current = head;
    while (current->next != head) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(current); // Free the last node
}
