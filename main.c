#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "struct.h"

#define MAX_LISTS 10

int main() {
    List* lists[MAX_LISTS];
    int num_lists = 0;
    List* current_list = NULL;
    Node* current_node = NULL;

    while (1) {
        printf("1. Create new list\n");
        printf("2. Select list\n");
        printf("3. Create copy\n");
        printf("4. Delete the list\n");
        printf("5. Add after\n");
        printf("6. Add before\n");
        printf("7. Delete current\n");
        printf("8. Go next\n");
        printf("9. Go prev\n");
        printf("10. Print current\n");
        printf("11. Print the list\n");
        printf("12. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int list_index, element;

        switch (choice) {
            case 1:
                if (num_lists >= MAX_LISTS) {
                    printf("Maximum number of lists reached (%d).\n", MAX_LISTS);
                    break;
                }
                lists[num_lists] = create_list();
                if (current_list == NULL) {
                    current_list = lists[num_lists];
                }
                printf("New list created at index %d.\n", num_lists);
                num_lists++;
                break;
            case 2:
                printf("Enter the index of the list to select: ");
                scanf("%d", &list_index);
                if (list_index >= 0 && list_index < num_lists) {
                    current_list = lists[list_index];
                    current_node = current_list->head;
                } else {
                    printf("Invalid list index.\n");
                }
                break;
            case 3:
                if (current_list != NULL) {
                    if (num_lists >= MAX_LISTS) {
                        printf("Maximum number of lists reached (%d).\n", MAX_LISTS);
                        break;
                    }
                    lists[num_lists] = copy_list(current_list);
                    current_list = lists[num_lists];
                    current_node = current_list->head;
                    printf("Copy of the current list created at index %d.\n", num_lists);
                    num_lists++;
                } else {
                    printf("No list selected.\n");
                }
                break;
            case 4:
                if (current_list != NULL) {
                    free_list(current_list);
                    for (int i = list_index; i < num_lists - 1; i++) {
                        lists[i] = lists[i + 1];
                    }
                    num_lists--;
                    current_list = NULL;
                    current_node = NULL;
                    printf("List deleted.\n");
                } else {
                    printf("No list selected.\n");
                }
                break;
            case 5:
                if (current_node != NULL) {
                    printf("Enter value to add after: ");
                    scanf("%d", &element);
                    add_after(current_node, element);
                } else {
                    printf("No node selected.\n");
                }
                break;
            case 6:
                if (current_node != NULL) {
                    printf("Enter value to add before: ");
                    scanf("%d", &element);
                    add_before(current_list, current_node, element);
                } else {
                    printf("No node selected.\n");
                }
                break;
            case 7:
                if (current_node != NULL) {
                    Node* next_node = current_node->next ? current_node->next : current_node->prev;
                    delete_node(current_list, current_node);
                    current_node = next_node;
                } else {
                    printf("No node selected.\n");
                }
                break;
            case 8:
                if (current_node != NULL) {
                    current_node = move_next(current_node);
                } else {
                    printf("No node selected.\n");
                }
                break;
            case 9:
                if (current_node != NULL) {
                    current_node = move_prev(current_node);
                } else {
                    printf("No node selected.\n");
                }
                break;
            case 10:
                if (current_node != NULL) {
                    printf("Current value: %d\n", get_current_value(current_node));
                } else {
                    printf("No node selected.\n");
                }
                break;
            case 11:
                if (current_list != NULL) {
                    printf("List elements:\n");
                    print_list(current_list);
                } else {
                    printf("No list selected.\n");
                }
                break;
            case 12:
                for (int i = 0; i < num_lists; i++) {
                    free_list(lists[i]);
                }
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
