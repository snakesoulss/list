#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "struct.h"

int main() {
    Node* head = malloc(sizeof(Node));
    if (!head) {
        printf("Failed to create list\n");
        return 1;
    }
    head->next = head;
    head->prev = head;
    head->flag = 0;

    int choice, value;

    while (1) {
        printf("1. Add after\n2. Add before\n3. Delete current\n4. Go next\n5. Go prev\n6. Print current\n7. Print the list\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add after: ");
                scanf("%d", &value);
                head = add_after(head, value);
                printf("\n");
                break;
            case 2:
                printf("Enter value to add before: ");
                scanf("%d", &value);
                head = add_before(head, value);
                printf("\n");
                break;
            case 3:
                head = elem_delete(head);
                printf("\n");
                break;
            case 4:
                head = move_next(head);
                printf("\n");
                break;
            case 5:
                head = move_prev(head);
                printf("\n");
                break;
            case 6:
                printf("Current value: %d\n", head->num);
                printf("\n");
                break;
            case 7:
                print_list(head);
                printf("\n");
                break;
            case 8:
                free_list(head);
                printf("\n");
                return 0;
            default:
                printf("Invalid choice\n");
                printf("\n");
        }
    }

    return 0;
}
