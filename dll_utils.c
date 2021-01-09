#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

int remove_data_from_dll_by_data_ptr(dll_t *my_list, void *app_data) {
    
    /*
     * Don't check the actual application data content.
     * We have a pointer to the application data, which is on
     * the dll.
     */

    /*
     * iterate through the list until we're pointing to a node on the
     * list that has the same address as that of the app_data pointer.
     */

    dll_node_t *current_node;
    
    current_node = my_list->head;
    while (current_node && (current_node->data != app_data)) {
        current_node = current_node->right;
    }

    return (current_node) ? 0 : -1;
} 


int is_dll_empty(dll_t *my_list) {
    return (my_list) ? 0 : -1;
}


/*
 * Free a node, (but not application data),
 */
void drain_dll(dll_t *my_list) {

    dll_node_t *current_node;

    current_node = my_list->head;

    /*
     * In this state, the list can be empty, or not-empty
     */
    if (!current_node) {
        return;
    }

    /*
     * In this state, the list is not-empty.
     * We consider two states:
     *  The state where the list has one and only one node, or the list has more than one node.
     */

    /*
     * while there is more than one node in the list.
     * set the head of the list to point to the second node
     * free the first node.
     */
    while (current_node->right) {
        my_list->head = current_node->right;	/* set the head to point to the second node */
        free(current_node);			/* free the memory occupied by the struct that was the first node on the list */
        current_node = my_list->head;   	/* update our iterator (current_node */
    }

    /*
     * In this state, the list has only one node, pointed to by the head.
     */
    if (current_node->right) {
        fprintf(stderr, "Err, there should only be node in this list. Somehow, I'm pointing to a node...\n");
        return;
    }

    free(my_list->head);
    my_list->head = NULL;
    return;   
}
